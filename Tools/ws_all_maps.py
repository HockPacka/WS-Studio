#!/usr/bin/env python3
"""Registers EVERY WildStar map as WoW map(s) and builds the teleports (offline output, see ws_content_output.py; --server installs on the AzerothCore folder).

Per map folder in ClientData/Map the tiles are cut into WoW windows of 64 x 64 tiles: a map that fits into one window gets exactly one (origin = its first tile, directory
"WS_<Map>_o<BB>_<AA>", Area3/AdtBuilder.cpp ParseWildStarMapName), bigger maps get a grid of 64-tile windows (Western / Eastern / NewCentral keep their legacy names and ids).
Outputs
  client  WoWOverride/World/Maps/<dir>/<dir>.wdt, WoWOverride/DBFilesClient/Map.dbc (every WildStar window, ids from 5000)
  server  game_tele rows (ids from 905001, names "ws_..."), merged Map.dbc, a Lua table for the addon (Interface/AddOns/WildStarTeleport/TeleportData.lua)
Teleports: one per window (a cell near the middle of its busiest tile) and one per zone of MapZone.csv (nearest cell to the centre of the zone).
usage: ws_all_maps.py [--install-client] [--server "<AzerothCore folder>"] [--rescan]
"""
import argparse
import csv
import json
import multiprocessing
import os
import re
import shutil
import hashlib
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import area_reader as A  # noqa: E402
import ws_text  # noqa: E402
from ws_content_output import DEFAULT_CLIENT, Output, add_output_arguments, reject_server_install  # noqa: E402
from ws_map_setup import Dbc  # noqa: E402

LEGACY = {'Western': 5000, 'Eastern': 5100, 'NewCentral': 5200}   # id = base + wx + 2 * wy
FIRST_ID = 6000
TELE_BASE = 905000
KS = 33.333332 / 32.0


def cell_zone(blocks):
    z = blocks.get(28)

    if not z or len(z) != 16:
        return 0

    ids = struct.unpack('<4I', z)
    counts = [0, 0, 0, 0]

    for v in blocks.get(16, b''):
        counts[(v >> 3) & 3] += 1

    best = -1

    for k in range(4):
        if ids[k] and (best < 0 or counts[k] > counts[best]):
            best = k

    return ids[best] if best >= 0 else 0


def scan_map(args):
    """-> (map, {(BB,AA): [cells, bestIdx, bestRaw]}, {zone: [gx, gz, raw, ...] sampled})"""
    client, name, watch = args
    folder = os.path.join(client, 'ClientData', 'Map', name)
    pat = re.compile(r'^%s\.([0-9a-f]{2})([0-9a-f]{2})\.area$' % re.escape(name))
    tiles = {}
    zones = {}

    for f in sorted(os.listdir(folder)):
        m = pat.match(f)

        if not m:
            continue

        aa, bb = int(m.group(1), 16), int(m.group(2), 16)
        best = (999, -1, 0)
        n = 0

        try:
            a = A.read_area(open(os.path.join(folder, f), 'rb').read())
        except Exception:
            continue

        for cname, size, data, pos in a['chunks']:
            if cname not in ('CHNK', 'KNHC'):
                continue

            for idx, flags, cell in A.read_chnk(data, a['compressed']):
                _, blocks, _ = A.split_cell(cell)
                n += 1
                raw = -1

                if 0 in blocks and len(blocks[0]) >= 722:
                    raw = struct.unpack_from('<H', blocks[0], (9 * 19 + 9) * 2)[0]

                if 0 <= raw < 40000:
                    d = abs(idx % 16 - 8) + abs(idx // 16 - 8)

                    if d < best[0]:
                        best = (d, idx, raw)

                    z = cell_zone(blocks)

                    if z in watch:
                        lst = zones.setdefault(z, [])

                        if len(lst) < 3 * 4000:
                            lst += [16 * bb + idx % 16, 16 * aa + idx // 16, raw]

        tiles[(bb, aa)] = [n, best[1], best[2]]

    return name, tiles, zones


def humanize(name):
    return re.sub(r'(?<=[a-z0-9])(?=[A-Z])', ' ', name)


def sanitize(text, limit=40):
    s = re.sub(r'[^A-Za-z0-9]+', '_', text).strip('_').lower()
    return s[:limit] or 'x'


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--server', help='AzerothCore folder: merges Map.dbc (backup) and runs the game_tele SQL against acore_world')
    ap.add_argument('--rescan', action='store_true')
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap, argparse.Namespace(server=None, apply=False))
    out = Output(a)
    tables = os.path.join(a.client, 'tables_csv')

    def load(name, key='ID'):
        return {int(r[key]): r for r in csv.DictReader(open(os.path.join(tables, name), encoding='utf-8'))}

    text = ws_text.load(os.path.join(a.client, 'ClientDataEN', 'en-US.bin'))
    wzone = load('WorldZone.csv')
    mapzone = [r for r in csv.DictReader(open(os.path.join(tables, 'MapZone.csv'), encoding='utf-8')) if r['folder'] and int(r['worldZoneId'])]
    cont = load('MapContinent.csv')
    world_name = {}

    for r in csv.DictReader(open(os.path.join(tables, 'World.csv'), encoding='utf-8')):
        d = r['assetPath'].replace('\\', '/').split('/')[-1]
        t = text.get(int(r['localizedTextIdName'] or 0), '').strip()

        if t and d not in world_name:
            world_name[d] = t

    # zones to watch: every zone of MapZone and its descendants -> the MapZone roots that contain it
    children = {}

    for zid, r in wzone.items():
        children.setdefault(int(r['parentZoneId']), []).append(zid)

    watch = {}
    roots = {}

    for mz in mapzone:
        root = int(mz['worldZoneId'])
        todo, seen = [root], set()

        while todo:
            z = todo.pop()

            if z in seen:
                continue

            seen.add(z)
            watch.setdefault(z, set()).add(root)
            todo += children.get(z, [])

    cache = os.path.join(out.root, 'cache', 'all_maps_scan.json')

    if os.path.exists(cache) and not a.rescan:
        raw = json.load(open(cache))
        scans = {m: ({tuple(map(int, k.split(','))): v for k, v in t.items()}, {int(k): v for k, v in z.items()}) for m, (t, z) in raw.items()}
    else:
        maps = sorted(d for d in os.listdir(os.path.join(a.client, 'ClientData', 'Map')) if os.path.isdir(os.path.join(a.client, 'ClientData', 'Map', d)))
        keys = frozenset(watch)

        with multiprocessing.Pool(min(6, os.cpu_count() or 2)) as pool:
            scans = {}

            for name, tiles, zones in pool.imap_unordered(scan_map, [(a.client, m, keys) for m in maps]):
                if tiles:
                    scans[name] = (tiles, zones)
                    print('scanned %-40s %5d tiles' % (name, len(tiles)), flush=True)

        os.makedirs(os.path.dirname(cache), exist_ok=True)
        json.dump({m: ({'%d,%d' % k: v for k, v in t.items()}, z) for m, (t, z) in scans.items()}, open(cache, 'w'))

    # ---- windows
    windows = []   # dict(map, bb, aa, dir, id, tiles{...})
    next_id = FIRST_ID

    for name in sorted(scans):
        tiles = scans[name][0]
        bbs = [k[0] for k in tiles]
        aas = [k[1] for k in tiles]

        if name in LEGACY or max(bbs) - min(bbs) >= 64 or max(aas) - min(aas) >= 64:
            groups = {}

            for (bb, aa), v in tiles.items():
                groups.setdefault((bb // 64, aa // 64), {})[(bb, aa)] = v

            for (wx, wy), t in sorted(groups.items(), key=lambda kv: (kv[0][1], kv[0][0])):
                if name in LEGACY:
                    wid = LEGACY[name] + wx + 2 * wy
                    d = 'WS_' + name + ('' if (wx, wy) == (0, 0) else '_%d_%d' % (wx, wy))
                else:
                    wid = next_id
                    next_id += 1
                    d = 'WS_%s_o%d_%d' % (name, 64 * wx, 64 * wy)

                windows.append(dict(map=name, bb=64 * wx, aa=64 * wy, dir=d, id=wid, tiles=t, grid=True))
        else:
            ob, oa = min(bbs), min(aas)
            windows.append(dict(map=name, bb=ob, aa=oa, dir='WS_%s_o%d_%d' % (name, ob, oa), id=next_id, tiles=tiles, grid=False))
            next_id += 1

    print(len(windows), 'windows of', len(scans), 'maps')

    def window_of(name, bb, aa):
        for w in windows:
            if w['map'] == name and (bb, aa) in w['tiles']:
                return w

    def position(w, gx, gz, raw):
        gxl, gzl = gx - 16 * w['bb'], gz - 16 * w['aa']
        y_west = 17066.666 - (1023 - gxl) * 33.333332 - 16.667
        x_north = 17066.666 - (1023 - gzl) * 33.333332 - 16.667
        z = KS * (raw / 8.0 - 2048.0) + 1600.0 + 5.0
        return x_north, y_west, z

    # ---- WDT + Map.dbc rows
    dbc = Dbc(out.original_dbc('Map'))
    dbc.recs = [r for r in dbc.recs if r[0] < 5000]
    tpl = [r for r in dbc.recs if r[0] == 0][0]

    for w in windows:
        main = bytearray(4096 * 8)

        for (bb, aa) in w['tiles']:
            tx, ty = 63 - (bb - w['bb']), 63 - (aa - w['aa'])

            if 0 <= tx < 64 and 0 <= ty < 64:
                struct.pack_into('<II', main, (64 * ty + tx) * 8, 1, 0)

        wdt = struct.pack('<4sI', b'REVM', 4) + struct.pack('<I', 18)
        wdt += struct.pack('<4sI', b'DHPM', 32) + struct.pack('<8I', 6, 0, 0, 0, 0, 0, 0, 0)
        wdt += struct.pack('<4sI', b'NIAM', len(main)) + bytes(main)
        rel = 'WoWOverride/World/Maps/%s/%s.wdt' % (w['dir'], w['dir'])
        path = out.client_path(rel)
        open(path, 'wb').write(wdt)
        out.install_client_file(rel)
        row = list(tpl)
        row[0] = w['id']
        row[1] = dbc.add_string(w['dir'])

        for i in range(5, 22):
            row[i] = 0

        label = world_name.get(w['map']) or humanize(w['map'])
        w['label'] = label
        row[5] = dbc.add_string('WildStar ' + label + ('' if not w['grid'] else ' (%d,%d)' % (w['bb'] // 64, w['aa'] // 64)))
        row[21] = 0xFFFFFFFF
        dbc.recs.append(row)

    rel = 'WoWOverride/DBFilesClient/Map.dbc'
    dbc.save(out.client_path(rel))
    out.install_client_file(rel)

    # ---- teleports
    teles = []   # (name, label, category, map id, x, y, z)
    used = set()

    def unique(base):
        n = base
        k = 2

        while n in used:
            n = '%s_%d' % (base, k)
            k += 1

        used.add(n)
        return n

    for w in windows:
        t = w['tiles']
        best = max(t.items(), key=lambda kv: kv[1][0])[0] if t else None
        # the tile nearest to the centre of the window's tiles that has a usable cell
        cx = sum(k[0] for k in t) / len(t)
        cy = sum(k[1] for k in t) / len(t)
        cand = sorted((k for k, v in t.items() if v[1] >= 0), key=lambda k: (k[0] - cx) ** 2 + (k[1] - cy) ** 2)

        if not cand:
            continue

        bb, aa = cand[0]
        _, idx, raw = t[(bb, aa)]
        gx, gz = 16 * bb + idx % 16, 16 * aa + idx // 16
        x, y, z = position(w, gx, gz, raw)
        suffix = '' if not w['grid'] else '_%d_%d' % (w['bb'] // 64, w['aa'] // 64)
        teles.append((unique('ws_' + sanitize(w['map']) + suffix), w['label'] + (' (window %d,%d)' % (w['bb'] // 64, w['aa'] // 64) if w['grid'] else ''), w['label'], w['id'], x, y, z))

    for mz in mapzone:
        cont_row = cont.get(int(mz['mapContinentId']))

        if not cont_row:
            continue

        mapname = cont_row['assetPath'].replace('\\', '/').split('/')[-1]

        if mapname not in scans:
            continue

        root = int(mz['worldZoneId'])
        pts = []

        for z, lst in scans[mapname][1].items():
            if root in watch.get(z, ()):
                pts += [lst[i:i + 3] for i in range(0, len(lst), 3)]

        if not pts:
            continue

        mx = sum(p[0] for p in pts) / len(pts)
        mzz = sum(p[1] for p in pts) / len(pts)
        gx, gz, raw = min(pts, key=lambda p: (p[0] - mx) ** 2 + (p[1] - mzz) ** 2)
        w = window_of(mapname, gx // 16, gz // 16)

        if not w:
            continue

        x, y, z = position(w, gx, gz, raw)
        zname = text.get(int(mz['localizedTextIdName']), '').strip() or mz['folder']
        label = zname + ('' if w['map'] in ('Western', 'Eastern', 'NewCentral') else ' - ' + (world_name.get(w['map']) or humanize(w['map'])))
        teles.append((unique('ws_' + sanitize(zname)), label, world_name.get(w['map']) or humanize(w['map']), w['id'], x, y, z))

    # ---- SQL + addon data
    sqld = out.adapter_path('sql')
    os.makedirs(sqld, exist_ok=True)
    esc = lambda s: s.replace("'", "''")
    sql = os.path.join(sqld, 'ws_teleports.world.sql')
    ids = list(range(TELE_BASE + 1, TELE_BASE + 1 + len(teles)))

    with open(sql, 'w', encoding='utf-8') as f:
        f.write('-- WildStar teleports (.tele <name>); game_tele ids %d..%d belong to the WildStar namespace\n' % (ids[0], ids[-1]))
        f.write('DELETE FROM `game_tele` WHERE `id` BETWEEN %d AND %d;\n' % (TELE_BASE + 1, TELE_BASE + 20000))
        f.write('INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES\n')
        f.write(',\n'.join("(%d, %.3f, %.3f, %.3f, 0, %d, '%s')" % (i, t[4], t[5], t[6], t[3], esc(t[0])) for i, t in zip(ids, teles)) + ';\n')

    with open(os.path.join(sqld, 'ws_teleports.uninstall.world.sql'), 'w', encoding='utf-8') as f:
        f.write('DELETE FROM `game_tele` WHERE `id` BETWEEN %d AND %d;\n' % (TELE_BASE + 1, TELE_BASE + 20000))

    lua_rel = 'Interface/AddOns/WildStarTeleport/TeleportData.lua'
    lua = out.client_path(lua_rel)
    NL = chr(10)

    with open(lua, 'w', encoding='utf-8', newline='\n') as f:
        f.write('-- generated by tools/ws_all_maps.py: { tele name, label, map / category }' + NL + 'WildStarTeleportData = {' + NL)

        for t in sorted(teles, key=lambda t: (t[2].lower(), t[1].lower())):
            f.write('\t{ "%s", "%s", "%s" },' % (t[0], t[1].replace('"', "'"), t[2].replace('"', "'")) + NL)

        f.write('}' + NL)

    out.install_client_file(lua_rel)
    print('%d teleports -> %s' % (len(teles), sql))

    if a.server:
        d = os.path.join(a.server, 'Data', 'dbc', 'Map.dbc')
        srv = Dbc(d)
        raw = open(d, 'rb').read()
        backup = d + '.bak_ws_' + hashlib.sha256(raw).hexdigest()[:12]

        if not os.path.exists(backup):
            open(backup, 'wb').write(raw)

        srv.recs = [r for r in srv.recs if r[0] < 5000]

        for w, r in zip(windows, [r for r in dbc.recs if r[0] >= 5000]):
            row = list(r)
            row[1] = srv.add_string(w['dir'])
            label = 'WildStar ' + w['label'] + ('' if not w['grid'] else ' (%d,%d)' % (w['bb'] // 64, w['aa'] // 64))
            row[5] = srv.add_string(label)
            srv.recs.append(row)

        srv.save(d)
        print('server Map.dbc: %d WildStar rows (backup %s)' % (len(windows), os.path.basename(backup)))
        mysql = os.path.join(a.server, 'mysql', 'bin', 'mysql.exe')
        r = subprocess.run([mysql, '-uacore', '-pacore', '-h127.0.0.1', '-P3306', 'acore_world', '-e', 'source ' + sql.replace(chr(92), '/')], capture_output=True, text=True)
        print('mysql exit', r.returncode, (r.stderr or '').replace('mysql: [Warning] Using a password on the command line interface can be insecure.', '').strip())

    out.finish('all-maps')


if __name__ == '__main__':
    main()
