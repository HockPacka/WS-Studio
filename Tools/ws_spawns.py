#!/usr/bin/env python3
"""Phase 1: WildStar NPC spawns (NexusForever.WorldDatabase) -> AzerothCore SQL, offline (staging directory, see ws_content_output.py; no server access).

Only NonPlayer entities (type 0) whose creature has an M3 model are converted (creature -> Creature2ModelInfo / Creature2DisplayInfo assetPath -> display id
200000 + index in the sorted model list, the numbering of ws_npc_patch.py). Everything else is counted in the report (docs/ws_spawns_report.md in the staging dir).

IDs (own namespace): creature_template.entry = ENTRY_BASE + Creature2 id, creature.guid = GUID_BASE + running number.
Map ids: <MAP_BASE of the map> + window x + 2 * window y (a WoW map holds 64 x 64 tiles, see Area3/AdtBuilder.h): Western 5000.., Eastern 5100.., NewCentral 5200..
Coordinates (see Area3/AdtBuilder.h): X(north) = 17066.666 + kScale * (z - 32768 * wy), Y(west) = 17066.666 + kScale * (x - 32768 * wx), Z = kScale * y + 1600,
window wx = floor(x / 32768 + 1), wy = floor(z / 32768 + 1).
usage: ws_spawns.py [--db NexusForever.WorldDatabase] [--entry-base 4100000] [--guid-base 4100000] [--with-dbcs] [--install-client]
"""
import argparse
import collections
import csv
import glob
import math
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ws_text  # noqa: E402
from ws_content_output import DEFAULT_CLIENT, Output, add_output_arguments, reject_server_install  # noqa: E402
import ws_npc_patch  # noqa: E402

K_SCALE = 33.333332 / 32.0
Z_OFFSET = 1600.0
WINDOW = 32768.0
MAP_BASE = {'Western': 5000, 'Eastern': 5100, 'NewCentral': 5200}
DISPLAY_BASE = ws_npc_patch.BASE

ENTITY = re.compile(r'^\s+\(@GUID\+(\d+), (\d+), (\d+), (@WORLD|\d+), (\d+), (-?[\d.]+), (-?[\d.]+), (-?[\d.]+), (-?[\d.]+), (-?[\d.]+), (-?[\d.]+), (\d+), (\d+), (\d+), (\d+)\)', re.M)
STAT = re.compile(r'^\s+\(@GUID\+(\d+), (\d+), (-?[\d.]+)\)', re.M)


def table(client, name, key='ID'):
    return {int(r[key]): r for r in csv.DictReader(open(os.path.join(client, 'tables_csv', name), encoding='utf-8'))}


def faction_of(name):
    """WildStar faction -> WoW faction template (heuristic from the faction name): 35 friendly to all, 14 hostile monster, 7 neutral creature"""
    n = (name or '').lower()

    if any(k in n for k in ('hates', 'aggressive', 'strain', 'hostile', 'enemy')):
        return 14

    if any(k in n for k in ('critter', 'neutral')):
        return 7

    return 35


def parse_db(db):
    """yields (file, world, [(local id, type, creature, area, x, y, z, rx, ry, rz, display, outfit, f1, f2, stats{})])"""
    for f in sorted(glob.glob(os.path.join(db, '**', '*.sql'), recursive=True)):
        text = open(f, encoding='utf-8', errors='replace').read()
        world = re.search(r'SET @WORLD = (\d+)', text)
        world = int(world.group(1)) if world else None
        blocks = re.split(r'(?m)^SET @GUID = .*$', text)[1:]
        rows = []

        for b in blocks:
            ents = {}

            for m in ENTITY.finditer(b):
                g = m.groups()
                ents[int(g[0])] = [int(g[1]), int(g[2]), int(g[4])] + [float(v) for v in g[5:11]] + [int(g[11]), int(g[12]), int(g[13]), int(g[14])] + [{}]

            for m in STAT.finditer(b):
                e = ents.get(int(m.group(1)))

                if e is not None:
                    e[-1][int(m.group(2))] = float(m.group(3))

            rows += list(ents.values())

        yield f, world, rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--db', default=os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'NexusForever.WorldDatabase'))
    ap.add_argument('--entry-base', type=int, default=4100000)
    ap.add_argument('--guid-base', type=int, default=4100000)
    ap.add_argument('--id-column', default='id', help="column of the creature table that holds the template entry ('id' on older AzerothCore, 'id1' on current)")
    ap.add_argument('--with-dbcs', action='store_true', help='also run ws_npc_patch.py for all models (CreatureModelData / CreatureDisplayInfo)')
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap, a)
    out = Output(a)

    text = ws_text.load(os.path.join(a.client, 'ClientDataEN', 'en-US.bin'))
    c2 = table(a.client, 'Creature2.csv')
    mi = table(a.client, 'Creature2ModelInfo.csv')
    di = table(a.client, 'Creature2DisplayInfo.csv')
    fac = table(a.client, 'Faction2.csv')
    worlds = table(a.client, 'World.csv')

    models = ws_npc_patch.model_list(a.client)
    index = {m.lower(): i for i, m in enumerate(models)}
    print(len(models), 'models on disk')
    variants, by_row = ws_npc_patch.variant_list(a.client)
    groups = collections.defaultdict(list)

    for e in csv.DictReader(open(os.path.join(a.client, 'tables_csv', 'Creature2DisplayGroupEntry.csv'), encoding='utf-8')):
        groups[int(e['creature2DisplayGroupId'])].append((int(e['creature2DisplayInfoId']), float(e['weight'] or 1)))

    def display_of(kind, row, path):
        """display id of a model path: the variant that carries the row's mesh selection / texture overrides, else the plain model display"""
        k = by_row.get((kind, row))

        if k is not None:
            return DISPLAY_BASE + len(models) + k

        i = index.get(path.lower().replace('/', '\\'))
        return None if i is None else DISPLAY_BASE + i

    def resolve(c, entity_display, creature):
        """Creature2 -> displays: the entity's own display row, else the creature's display group (Creature2DisplayGroupEntry -> Creature2DisplayInfo,
        every entry is a model of creature_template_model with its weight), else Creature2ModelInfo. Returns ([(display id, scale, weight)], reason)."""
        base = float(c['modelScale'] or 1.0)
        rows = []

        if entity_display and entity_display['assetPath']:
            rows = [(entity_display, 1.0)]
        else:
            for did, weight in groups.get(int(c['creature2DisplayGroupId'] or 0), []):
                row = di.get(did)

                if row and row['assetPath']:
                    rows.append((row, weight))

        out = []

        for row, weight in rows:
            did = display_of('d', int(row['ID']), row['assetPath'])

            if did is not None:
                out.append((did, base * float(row['scale'] or 1.0), weight))

        if out:
            return out, ''

        m = mi.get(int(c['creature2ModelInfoId']))

        if not m or not m['assetPath']:
            return [], 'skipped: no model path (race + outfit humanoid)'

        did = display_of('i', int(m['ID']), m['assetPath'])

        if did is None:
            return [], 'skipped: model file not found'

        return [(did, base * float(m['scale'] or 1.0), 1.0)], ''


    stats = collections.Counter()
    templates = {}      # creature2 id -> dict
    spawns = []         # (creature id, map id, x, y, z, orientation)
    maps = collections.Counter()
    levels = collections.defaultdict(list)
    missing_model = collections.Counter()

    for f, world, rows in parse_db(a.db):
        wname = os.path.basename(worlds.get(world, {}).get('assetPath', '').replace('\\', '/'))

        for r in rows:
            etype, creature, area, x, y, z, rx, ry, rz, display, outfit, f1, f2, st = r
            stats['entities'] += 1

            if etype != 0:
                stats['skipped: entity type %d (not an NPC)' % etype] += 1
                continue

            c = c2.get(creature)

            if not c:
                stats['skipped: unknown creature'] += 1
                continue

            shown, why = resolve(c, di.get(display), creature)

            if not shown:
                stats[why] += 1
                missing_model[why] += 1
                continue

            if wname not in MAP_BASE:
                stats['skipped: world %s (%s) has no map id' % (world, wname)] += 1
                continue

            wx = int(math.floor(x / WINDOW + 1))
            wy = int(math.floor(z / WINDOW + 1))

            if not (0 <= wx <= 1 and 0 <= wy <= 1):
                stats['skipped: position outside the map windows'] += 1
                continue

            map_id = MAP_BASE[wname] + wx + 2 * wy
            px = 17066.666 + K_SCALE * (z - WINDOW * wy)
            py = 17066.666 + K_SCALE * (x - WINDOW * wx)
            pz = K_SCALE * y + Z_OFFSET
            facing = rx % (2 * math.pi)
            spawns.append((creature, map_id, px, py, pz, facing))
            maps[map_id] += 1
            levels[creature].append(int(st.get(10, 1)))
            tpl = templates.setdefault(creature, {'shown': shown, 'faction': faction_of(text.get(int(fac.get(f1, {}).get('localizedTextIdName', 0)), '')), 'wsfaction': f1})
            stats['converted'] += 1

    # ---- SQL
    sqld = out.adapter_path('sql')
    os.makedirs(sqld, exist_ok=True)
    esc = lambda s: s.replace('\\', '\\\\').replace("'", "''")
    with open(os.path.join(sqld, 'ws_creatures.world.sql'), 'w', encoding='utf-8') as f:
        f.write('-- WildStar NPC spawns (NexusForever.WorldDatabase), phase 1: %d spawns of %d creatures. AzerothCore adapter only; plain INSERT, fails on occupied IDs.\n' % (len(spawns), len(templates)))
        f.write('-- creature_template.entry = %d + Creature2 id, creature.guid = %d + n, display id = %d + model index, display variants after the models (ws_npc_patch.py), map id = see ws_map_setup.py windows\n' % (a.entry_base, a.guid_base, DISPLAY_BASE))

        for cid in sorted(templates):
            t = templates[cid]
            lv = sorted(levels[cid])
            level = max(1, min(80, lv[len(lv) // 2]))
            name = text.get(int(c2[cid]['localizedTextIdName']), '').strip() or c2[cid]['description'] or 'WS %d' % cid
            e = a.entry_base + cid
            f.write("INSERT INTO `creature_template` (`entry`, `name`, `subname`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `unit_class`, `type`, `flags_extra`) "
                    "VALUES (%d, '%s', 'WildStar', %d, %d, %d, 0, 1, 1.14286, 1, 0, 0);\n" % (e, esc(name), level, level, t['faction']))
            for n, (did, scale, weight) in enumerate(t['shown']):
                f.write('INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`) VALUES (%d, %d, %d, %.4f, %.2f);\n' % (e, n, did, scale, weight))

        f.write('INSERT INTO `creature` (`guid`, `%s`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `MovementType`) VALUES\n' % a.id_column)
        rows = ['(%d, %d, %d, 1, 1, %.3f, %.3f, %.3f, %.4f, 300, 0)' % (a.guid_base + i, a.entry_base + s[0], s[1], s[2], s[3], s[4], s[5]) for i, s in enumerate(spawns)]
        f.write(',\n'.join(rows) + ';\n')

    # creature_model_info: AzerothCore refuses to spawn a creature whose display id has no row ("has no model ... can't load")
    display_ids = sorted({d[0] for t in templates.values() for d in t['shown']})
    with open(os.path.join(sqld, 'ws_creature_model_info.world.sql'), 'w', encoding='utf-8') as f:
        f.write('-- creature_model_info rows for the %d WildStar display ids (radius from the model volume, combat reach = max(1.5, radius))\n' % len(display_ids))
        vals = []

        for did in display_ids:
            slot = did - DISPLAY_BASE
            bb = ws_npc_patch.bounds(a.client, models[slot] if slot < len(models) else variants[slot - len(models)]['base'])
            radius = 0.5 if bb is None else max(0.3, max(bb[1][1] - bb[0][1], bb[1][0] - bb[0][0]) * 0.5)
            vals.append('(%d, %.3f, %.3f, 2, 0, 0)' % (did, radius, max(1.5, radius)))

        f.write('INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `Gender`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES\n' + ',\n'.join(vals) + ';\n')

    with open(os.path.join(sqld, 'ws_creatures.uninstall.world.sql'), 'w', encoding='utf-8') as f:
        f.write('-- removes the WildStar NPC spawns of ws_creatures.world.sql (own ID ranges and subname only)\n')
        f.write('DELETE FROM `creature` WHERE `guid` BETWEEN %d AND %d;\n' % (a.guid_base, a.guid_base + len(spawns)))
        f.write("DELETE m FROM `creature_template_model` m JOIN `creature_template` t ON t.`entry` = m.`CreatureID` WHERE t.`entry` BETWEEN %d AND %d AND t.`subname` = 'WildStar';\n" % (a.entry_base, a.entry_base + 100000))
        f.write("DELETE FROM `creature_template` WHERE `entry` BETWEEN %d AND %d AND `subname` = 'WildStar';\n" % (a.entry_base, a.entry_base + 100000))
        f.write('DELETE FROM `creature_model_info` WHERE `DisplayID` BETWEEN %d AND %d;\n' % (DISPLAY_BASE, DISPLAY_BASE + 100000))

    # ---- report
    report = ['# WildStar NPC spawns, phase 1', '']
    report += ['| result | count |', '|---|---|'] + ['| %s | %d |' % (k, v) for k, v in sorted(stats.items(), key=lambda kv: -kv[1])]
    report += ['', '## Maps (window of the WoW map holding the spawns)', '', '| map id | spawns | create with |', '|---|---|---|']

    for mid, n in sorted(maps.items()):
        name = [k for k, v in MAP_BASE.items() if v <= mid < v + 4][0]
        w = mid - MAP_BASE[name]
        report.append('| %d | %d | `ws_map_setup.py %s --window %d %d --id %d` |' % (mid, n, name, w % 2, w // 2, mid))

    report += ['', '## Lost in this conversion', '',
               '- humanoids (race + outfit), colour shift and skin colour data of the display info, entity spline paths, stats other than level, vendor/quest/gossip data',
               '- WildStar factions are reduced to 35 (friendly), 14 (hostile) or 7 (neutral) by name',
               '- orientation = WildStar yaw (RX) unchanged; spawn height = kScale * y + 1600', '']
    rp = os.path.join(out.root, 'ws_spawns_report.md')
    open(rp, 'w', encoding='utf-8').write('\n'.join(report))
    print('\n'.join(report))
    print('SQL:', sqld)

    if a.with_dbcs:
        cmd = [sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ws_npc_patch.py'), '--client', a.client, '--output', str(out.root), '--include', '']

        if a.install_client:
            cmd.append('--install-client')

        subprocess.run(cmd, check=True)

    out.finish('spawns')


if __name__ == '__main__':
    main()
