#!/usr/bin/env python3
"""Generate WildStar creature model DBCs and an AzerothCore SQL draft offline.

Each original M3 receives a CreatureModelData/CreatureDisplayInfo development
ID at BASE + model-list index. Original DBCs come from client MPQs. Outputs
stay under --output unless --install-client is explicitly selected. SQL is
never executed and no server directory is accessed.
Usage: ws_npc_patch.py [--client PATH] [--output PATH] [--entry 4000000] [--no-sql]
"""
import argparse
import os
import re
import shutil
import struct
import subprocess
import sys
from ws_content_output import DEFAULT_CLIENT, Output, add_output_arguments, reject_server_install

BASE = 200000
PLAYER_MODEL = re.compile(r'^art\\character\\([a-z]+)\\(male|female)\\\1_[mf]\.m3$')   # Art\Character\<Race>\<Male|Female>\<Race>_<M|F>.m3
DEFAULT_SERVER = None  # legacy CLI compatibility; generation never accesses a server


def model_list(client):
    root = os.path.join(client, 'ClientData')
    out = []
    for d, _dirs, files in os.walk(root):
        for f in files:
            if f.lower().endswith('.m3'):
                out.append(os.path.relpath(os.path.join(d, f), root).replace('/', '\\'))
    out.sort(key=lambda p: p.encode('mbcs', 'replace'))
    return out


def _table(client, name):
    import csv
    with open(os.path.join(client, 'tables_csv', name + '.csv'), newline='', encoding='utf-8') as f:
        return list(csv.DictReader(f))


def variant_list(client):
    """Display variants of the NPC models: Creature2DisplayInfo (~d<id>) and Creature2ModelInfo (~i<id>) rows that select mesh groups (modelMeshIdNN)
    or replace textures (assetTextureNN / modelTextureIdNN) of their model. Rows with the same effect share one variant.
    Returns (variants, by_row): variants = sorted list of dicts {key, base (model path), kind, row, suffix}; by_row[(kind, row id)] = index in variants.
    Display id of variants[k] = BASE + len(model_list) + k (the model ids come first, see main())."""
    models = model_list(client)
    known = {m.lower(): m for m in models}
    found = {}
    by_row = {}
    for kind, name, nasset in (('d', 'Creature2DisplayInfo', 6), ('i', 'Creature2ModelInfo', 2)):
        for r in _table(client, name):
            path = (r.get('assetPath') or '').replace('/', '\\')
            if not path or path.lower() not in known or path.lower().startswith('art\\character\\'):
                continue
            meshes = tuple(int(r['modelMeshId%02d' % k]) for k in range(16) if int(r.get('modelMeshId%02d' % k) or 0) > 0)
            fmt = '%s%02d' if kind == 'd' else '%s%d'
            textures = []
            for k in range(nasset):
                asset = (r.get(fmt % ('assetTexture', k)) or '').strip()
                tid = int(r.get(fmt % ('modelTextureId', k)) or 0)
                if asset and 0 < tid < 0xFFFF:
                    textures.append((tid, asset.lower()))
            if not meshes and not textures:
                continue
            key = (path.lower(), meshes, tuple(sorted(textures)))
            found.setdefault(key, {'key': key, 'base': known[path.lower()], 'kind': kind, 'row': int(r['ID'])})
            by_row[(kind, int(r['ID']))] = key
    variants = [found[k] for k in sorted(found)]
    index = {v['key']: i for i, v in enumerate(variants)}
    for v in variants:
        v['suffix'] = '~%s%d' % (v['kind'], v['row'])
    return variants, {row: index[key] for row, key in by_row.items()}


def display_count(client):
    """number of display ids owned by the generator: one per model + one per variant"""
    return len(model_list(client)) + len(variant_list(client)[0])


def bounds(client, rel):
    """WoW axis bounds (x forward, y left, z up) from the m3 header volume at 0x390: WildStar (x, y, z) -> WoW (z, x, y)"""
    race = race_bounds(client).get(rel.lower().replace('/', '\\'))
    if race:
        return race
    with open(os.path.join(client, 'ClientData', rel), 'rb') as f:
        h = f.read(0x3D0)
    if len(h) < 0x3D0 or h[:4] != b'LDOM':
        return None
    mn = struct.unpack_from('<3f', h, 0x390)
    mx = struct.unpack_from('<3f', h, 0x3A0)
    lo = [min(mn[2], mx[2]), min(mn[0], mx[0]), min(mn[1], mx[1])]
    hi = [max(mn[2], mx[2]), max(mn[0], mx[0]), max(mn[1], mx[1])]
    return lo, hi


_RACE_BOUNDS = {}


def race_bounds(client):
    """Bounds of the playable race models from their bind pose vertices (character_cli --bounds). The header volume contains animation excursions (Mechari 8 m tall),
    which made the collision height, the camera and the selection box of players wrong. The width is the model depth (arms are spread in the bind pose)."""
    if not _RACE_BOUNDS:
        exe = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'wowdecomp', 'build', 'x64', 'bin', 'Release', 'character_cli.exe')
        if os.path.exists(exe):
            text = subprocess.run([exe, '--bounds'], cwd=client, capture_output=True, text=True).stdout
            for line in text.splitlines():
                p = line.split('\t')
                if len(p) == 7:
                    v = [float(x) for x in p[1:]]
                    half = min((v[3] - v[0]) * 0.5, 0.6)
                    _RACE_BOUNDS[p[0].lower()] = ([v[0], -half, 0.0], [v[3], half, v[5]])
        _RACE_BOUNDS.setdefault('', None)
    return _RACE_BOUNDS


class Dbc:
    def __init__(self, path):
        b = path if isinstance(path, bytes) else open(path, 'rb').read()
        magic, self.rc, self.fc, self.rs, ss = struct.unpack_from('<4s4I', b, 0)
        assert magic == b'WDBC' and self.rs == self.fc * 4
        self.recs = [list(struct.unpack_from('<%dI' % self.fc, b, 20 + i * self.rs)) for i in range(self.rc)]
        self.strings = bytearray(b[20 + self.rc * self.rs:20 + self.rc * self.rs + ss])

    def add_string(self, s):
        off = len(self.strings)
        self.strings += s.encode('latin-1') + b'\0'
        return off

    def save(self, path):
        out = bytearray(struct.pack('<4s4I', b'WDBC', len(self.recs), self.fc, self.rs, len(self.strings)))
        for r in self.recs:
            out += struct.pack('<%dI' % self.fc, *r)
        out += self.strings
        os.makedirs(os.path.dirname(path), exist_ok=True)
        open(path, 'wb').write(out)


def f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--server', default=DEFAULT_SERVER)
    ap.add_argument('--entry', type=int, default=4000000)
    ap.add_argument('--apply', action='store_true', help='also run the generated SQL against the server database (default: only write the .sql files)')
    ap.add_argument('--include', action='append', default=None, help='only these models (case-insensitive substring of the path); default: two test models. Use --include "" for all models')
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap,a)
    output=Output(a)

    models = model_list(a.client)
    print(len(models), 'models')

    md = Dbc(output.original_dbc('CreatureModelData'))
    di = Dbc(output.original_dbc('CreatureDisplayInfo'))
    assert md.fc == 28 and di.fc == 16
    md_t = list(md.recs[-1])
    di_t = list(di.recs[-1])

    includes = a.include if a.include is not None else ['prp_bag_backpack_000.m3', r'Art\Character\Aurin\Female\Aurin_F.m3', r'Art\Creature\StemDragon\StemDragon.m3', r'Art\Creature\Boulderback\Boulderback.m3']
    skipped = 0
    used = 0
    first_display = None
    variants, _ = variant_list(a.client)
    tasks = [(BASE + i, rel, rel) for i, rel in enumerate(models)]
    tasks += [(BASE + len(models) + k, v['base'], v['base'][:-3] + v['suffix'] + '.m3') for k, v in enumerate(variants)]
    for did, rel, model_name in tasks:
        if not any(t.lower() in rel.lower() for t in includes):
            continue
        used += 1
        if first_display is None:
            first_display = did
        bb = bounds(a.client, rel)
        if bb is None:
            skipped += 1
            lo, hi = [-0.5, -0.5, 0.0], [0.5, 0.5, 1.0]
        else:
            lo, hi = bb
        r = list(md_t)
        r[0] = did
        # playable race models get the flags of the stock player models (Human 0x804): the client only builds a player's customised appearance
        # (CGUnit_C::InitializeExtendedDisplay -> CharacterComponent) for models with flag 0x4, otherwise it shows the plain base model
        r[1] = 0x804 if PLAYER_MODEL.match(rel.lower().replace('/', '\\')) else 0
        r[2] = md.add_string('WS\\' + model_name)
        r[3] = 3                                   # size class
        # WildStar races are up to 3.6 m tall (Mechari, Draken, Granok); with that collision height the camera (collision height - 0.17) sits far above the head and doors
        # are too small. Playable race models are scaled down to at most 2.4 m (WoW tauren size); the client multiplies the collision volume with this scale.
        scale = 1.0
        if PLAYER_MODEL.match(rel.lower().replace('/', '\\')) and bb is not None and hi[2] > 2.4:
            scale = round(2.4 / hi[2], 3)
        r[4] = f2u(scale)                          # model scale
        r[13] = 0                                  # sound data
        r[14] = f2u(max(0.3, max(hi[1] - lo[1], hi[0] - lo[0]) * 0.5))  # collision width
        r[15] = f2u(max(0.5, hi[2] - lo[2]))                              # collision height
        r[16] = f2u(0.0)                           # mount height
        for k in range(3):
            r[17 + k] = f2u(lo[k])
            r[20 + k] = f2u(hi[k])
        md.recs.append(r)
        d = list(di_t)
        d[0] = did
        d[1] = did                                 # model data id
        d[2] = 0
        d[3] = 0
        d[4] = f2u(1.0)
        d[5] = 255
        for k in (6, 7, 8, 9):
            d[k] = 0
        di.recs.append(d)

    for name,dbc in [('CreatureModelData',md),('CreatureDisplayInfo',di)]:
        rel='WoWOverride/DBFilesClient/'+name+'.dbc'
        dbc.save(output.client_path(rel));output.install_client_file(rel)
    print('DBCs written (%d new rows of %d models + %d display variants, %d without readable bounds), display id = %d + global index (variants after the models)' % (used, len(models), len(variants), skipped, BASE))

    content = output.adapter_path('sql')
    os.makedirs(content, exist_ok=True)
    sql = os.path.join(content, 'ws_npc_spawner.world.sql')
    uninstall = os.path.join(content, 'ws_npc_spawner.uninstall.world.sql')
    e = a.entry
    with open(sql, 'w', encoding='utf-8') as f:
        f.write('-- generic WildStar model NPC used by the in-game spawner (.npc add %d, then .npc set model <display id>)\n' % e)
        f.write('-- AzerothCore adapter only. INSERT fails on occupied IDs; do not overwrite another plugin.\n')
        f.write("INSERT INTO `creature_template` (`entry`, `name`, `subname`, `minlevel`, `maxlevel`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `unit_class`, `type`, `flags_extra`) "
                "VALUES (%d, 'WS Model', 'WildStar', 1, 1, 35, 0, 1, 1.14286, 1, 7, 2);\n" % e)
        f.write('INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`) VALUES (%d, 0, %d, 1, 1);\n' % (e, first_display or BASE))
    with open(uninstall, 'w', encoding='utf-8') as f:
        f.write('-- removes everything ws_npc_spawner.world.sql added (WildStar namespace: creature entry %d)\n' % e)
        f.write("DELETE m FROM `creature_template_model` m JOIN `creature_template` t ON t.`entry`=m.`CreatureID` WHERE t.`entry`=%d AND t.`name`='WS Model' AND t.`subname`='WildStar' AND m.`Idx`=0 AND m.`CreatureDisplayID`=%d;\n" % (e,first_display or BASE))
        f.write("DELETE FROM `creature_template` WHERE `entry`=%d AND `name`='WS Model' AND `subname`='WildStar';\n" % e)
    print('wrote', sql)
    print('wrote', uninstall)

    output.finish('models')


if __name__ == '__main__':
    sys.exit(main())
