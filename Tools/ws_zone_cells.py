"""Collects, per WorldZone id, the global cell grid (gx = 16 * BB + cell x, gz = 16 * AA + cell y) of every cell of a WildStar map and writes it to a json file.
A cell's zone is the same as in Area3/AdtBuilder.cpp CellZone() (bit 28 ids, bit 16 picks the most used slot).
usage: ws_zone_cells.py <client> <Map> <out.json>
"""
import glob
import json
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import area_reader as A  # noqa: E402


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


def main():
    client, name, out = sys.argv[1:4]
    zones = {}
    pat = re.compile(r'\.([0-9a-f]{2})([0-9a-f]{2})\.area$')

    for f in sorted(glob.glob(os.path.join(client, 'ClientData', 'Map', name, '*.area'))):
        m = pat.search(f)

        if not m or '_Low' in f:
            continue

        aa, bb = int(m.group(1), 16), int(m.group(2), 16)
        a = A.read_area(open(f, 'rb').read())

        for cname, size, data, pos in a['chunks']:
            if cname not in ('CHNK', 'KNHC'):
                continue

            for idx, flags, cell in A.read_chnk(data, a['compressed']):
                _, blocks, _ = A.split_cell(cell)
                z = blocks.get(28)

                if z and len(z) == 16:
                    gx = 16 * bb + idx % 16
                    gz = 16 * aa + idx // 16

                    for zid in set(struct.unpack('<4I', z)):
                        if zid:
                            zones.setdefault(str(zid), []).append((gx, gz))

    json.dump(zones, open(out, 'w'))
    print(name, len(zones), 'zones', sum(len(v) for v in zones.values()), 'cells')


if __name__ == '__main__':
    main()
