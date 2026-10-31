#!/usr/bin/env python3
"""Lists WoW ItemDisplayInfo rows with armor section textures and extracts the BLP files of one display from the client MPQs.
usage: wow_item_textures.py list [min_sections]
       wow_item_textures.py extract <ItemDisplayInfo id> <output dir> [M|F]
Sections: 0 ArmUpper, 1 ArmLower, 2 Hand, 3 TorsoUpper, 4 TorsoLower, 5 LegUpper, 6 LegLower, 7 Foot (textures are columns 15..22 of ItemDisplayInfo.dbc)."""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ws_content_output import ClientArchive, DEFAULT_CLIENT

DIRS = ['ArmUpperTexture', 'ArmLowerTexture', 'HandTexture', 'TorsoUpperTexture', 'TorsoLowerTexture', 'LegUpperTexture', 'LegLowerTexture', 'FootTexture']


def rows():
    arc = ClientArchive(os.path.join(DEFAULT_CLIENT, 'Data'))
    d = arc.get('DBFilesClient\\ItemDisplayInfo.dbc')
    magic, rc, fc, rs, ss = struct.unpack_from('<4s4I', d, 0)
    strs = d[20 + rc * rs:]

    def s(o):
        return strs[o:strs.index(b'\0', o)].decode('latin-1') if o else ''
    out = []
    for i in range(rc):
        r = struct.unpack_from('<%dI' % fc, d, 20 + i * rs)
        out.append((r[0], [s(r[15 + k]) for k in range(8)], s(r[1]), s(r[3])))
    return arc, out


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        return 2
    arc, table = rows()
    if sys.argv[1] == 'list':
        need = int(sys.argv[2]) if len(sys.argv) > 2 else 4
        for ident, tex, model, mtex in table:
            if sum(1 for t in tex if t) >= need:
                print(ident, [i for i, t in enumerate(tex) if t], [t for t in tex if t][:2])
        return 0
    ident = int(sys.argv[2])
    out = sys.argv[3]
    sex = sys.argv[4] if len(sys.argv) > 4 else 'M'
    row = next(r for r in table if r[0] == ident)
    os.makedirs(out, exist_ok=True)
    for sec, name in enumerate(row[1]):
        if not name:
            continue
        for deco in ('U', sex):
            path = 'Item\\TextureComponents\\%s\\%s_%s.blp' % (DIRS[sec], name, deco)
            try:
                data = arc.get(path)
            except FileNotFoundError:
                continue
            dst = os.path.join(out, 'sec%d.blp' % sec)
            open(dst, 'wb').write(data)
            print('section', sec, path, len(data), 'bytes ->', dst)
            break
        else:
            print('section', sec, name, 'not found')
    return 0


if __name__ == '__main__':
    sys.exit(main())
