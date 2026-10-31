#!/usr/bin/env python3
"""WorldMapArea.dbc rows for the WildStar maps (offline: output goes to the staging directory, see ws_content_output.py).

The pictures are NOT converted here: the client builds the 12 tiles of "Interface\\WorldMap\\WS_<folder>\\WS_<folder><n>.blp" from the original
ClientData\\UI\\Maps\\<folder>\\UI_CRB_Revealed[_0].tex when the world map asks for them (Model3/TexToBlp.cpp, cached in WildStarContent\\Cache).

Placement (approximate, calibrate with --margin / --shift-x / --shift-y / --flip-x / --flip-y and run again): the rectangle of a zone map is centred on the
bounding box of the zone's cells (bit 28 ids incl. all child zones) inside the WoW window of the map, enlarged by --margin; the 1002 x 668 frame is 3:2.
usage: ws_worldmap.py [--map Western] [--map-id 5000] [--install-client]
"""
import argparse
import csv
import json
import os
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ws_content_output import Output, add_output_arguments, reject_server_install  # noqa: E402
from ws_map_setup import Dbc, DEFAULT_CLIENT  # noqa: E402

AREA_BASE = 50000     # = kAreaIdBase (Area3/AdtBuilder.h)
ROW_BASE = 900000     # WorldMapArea ids
CELL = 33.333332      # one WildStar cell = one WoW chunk


def f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def world(gx, gz):
    """cell centre -> WoW (X north, Y west) for the window starting at tile 0 (see Area3/AdtBuilder.h)"""
    return 17066.666 - (1023 - gz) * CELL - CELL / 2, 17066.666 - (1023 - gx) * CELL - CELL / 2


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--map', default='Western')
    ap.add_argument('--map-id', type=int, default=5000)
    ap.add_argument('--continent-id', type=int, default=8, help='MapContinent id of the map in MapZone.csv (Western 8, Eastern 6)')
    ap.add_argument('--margin', type=float, default=1.25)
    ap.add_argument('--shift-x', type=float, default=0.0, help='metres, north')
    ap.add_argument('--shift-y', type=float, default=0.0, help='metres, west')
    ap.add_argument('--flip-x', action='store_true')
    ap.add_argument('--flip-y', action='store_true')
    ap.add_argument('--min-cells', type=int, default=30)
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap, a)
    out = Output(a)

    cells_json = os.path.join(out.root, 'cache', 'cells_%s.json' % a.map)

    if not os.path.exists(cells_json):
        os.makedirs(os.path.dirname(cells_json), exist_ok=True)
        subprocess.run([sys.executable, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ws_zone_cells.py'), a.client, a.map, cells_json], check=True)

    cells = json.load(open(cells_json))
    zones = list(csv.DictReader(open(os.path.join(a.client, 'tables_csv', 'WorldZone.csv'), encoding='utf-8')))
    parent = {int(z['ID']): int(z['parentZoneId']) for z in zones}
    children = {}

    for zid, par in parent.items():
        children.setdefault(par, []).append(zid)

    def subtree(z):
        seen, todo = set(), [z]

        while todo:
            c = todo.pop()

            if c in seen:
                continue

            seen.add(c)
            todo += children.get(c, [])

        return seen

    def bbox(zone_ids):
        pts = []

        for zid in zone_ids:
            pts += [(gx, gz) for gx, gz in cells.get(str(zid), []) if gx < 1024 and gz < 1024]   # the WoW window holds tiles 0..63

        if len(pts) < a.min_cells:
            return None

        xs = [p[0] for p in pts]
        zs = [p[1] for p in pts]
        return min(xs), max(xs), min(zs), max(zs), len(pts)

    def rect(b):
        x0, x1, z0, z1, _ = b
        xn0, yw0 = world(x0, z0)
        xn1, yw1 = world(x1, z1)
        cx, cy = (xn0 + xn1) / 2 + a.shift_x, (yw0 + yw1) / 2 + a.shift_y
        side = max(abs(xn1 - xn0), abs(yw1 - yw0)) + CELL
        height = side * a.margin
        width = height * 1.5
        left, right = cy + width / 2, cy - width / 2
        top, bottom = cx + height / 2, cx - height / 2

        if a.flip_y:
            left, right = right, left

        if a.flip_x:
            top, bottom = bottom, top

        return left, right, top, bottom

    dbc = Dbc(out.original_dbc('WorldMapArea'))
    dbc.recs = [r for r in dbc.recs if not (ROW_BASE <= r[0] < ROW_BASE + 100000)]
    mapzones = [m for m in csv.DictReader(open(os.path.join(a.client, 'tables_csv', 'MapZone.csv'), encoding='utf-8'))
                if m['folder'] and int(m['mapContinentId']) == a.continent_id and int(m['worldZoneId'])]

    # continent row: every zone cell of the window
    allb = bbox([int(z) for z in cells])
    cont_folder = {8: 'WesternContinent', 6: 'EasternContinent'}.get(a.continent_id)
    cont_id = ROW_BASE + 90000 + a.continent_id
    added = 0

    if allb and cont_folder:
        l, r, t, b = rect(allb)
        dbc.recs.append([cont_id, a.map_id, 0, dbc.add_string('WS_' + cont_folder), f2u(l), f2u(r), f2u(t), f2u(b), 0xFFFFFFFF, 0, 0])
        added += 1

    seen = set()

    for m in mapzones:
        wz = int(m['worldZoneId'])

        if wz in seen:
            continue

        b = bbox(subtree(wz))

        if not b:
            continue

        seen.add(wz)
        l, r, t, bt = rect(b)
        dbc.recs.append([ROW_BASE + int(m['ID']), a.map_id, AREA_BASE + wz, dbc.add_string('WS_' + m['folder']), f2u(l), f2u(r), f2u(t), f2u(bt), 0xFFFFFFFF, 0, cont_id if allb and cont_folder else 0])
        added += 1

    rel = 'WoWOverride/DBFilesClient/WorldMapArea.dbc'
    dbc.save(out.client_path(rel))
    out.install_client_file(rel)
    print('WorldMapArea.dbc: %d original rows + %d WildStar map rows (map %d)' % (len(dbc.recs) - added, added, a.map_id))
    out.finish('worldmap')


if __name__ == '__main__':
    main()
