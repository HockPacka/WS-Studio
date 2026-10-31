"""Lists the placements (pORP records) of models whose path contains a text, with their tint / scale fields (docs/area_format.md).
usage: prop_tints.py <map folder with .area files> <text> [limit]
"""
import glob
import os
import struct
import sys


def main():
    folder, text = sys.argv[1], sys.argv[2].lower()
    limit = int(sys.argv[3]) if len(sys.argv) > 3 else 40
    needle = text.encode('utf-16le')
    shown = 0

    for f in sorted(glob.glob(os.path.join(folder, '*.area'))):
        b = open(f, 'rb').read()

        if needle not in b.lower().replace(b'\x00', b'\x00') and needle.upper() not in b:
            pass

        pos = 8

        while pos + 8 <= len(b):
            tag = b[pos:pos + 4]
            size = struct.unpack_from('<I', b, pos + 4)[0]

            if tag in (b'PROp', b'pORP', b'PORP'):
                d = b[pos + 8:pos + 8 + size]
                n = struct.unpack_from('<I', d, 0)[0]

                for k in range(n):
                    r = d[8 + k * 104:8 + (k + 1) * 104]

                    if len(r) < 104:
                        break

                    off = struct.unpack_from('<I', r, 16)[0]
                    name = ''
                    o = off

                    while o + 2 <= len(d) and d[o:o + 2] != b'\0\0':
                        name += chr(d[o])
                        o += 2

                    if text in name.lower():
                        tint = struct.unpack_from('<I', r, 76)[0]
                        scale = struct.unpack_from('<f', r, 24)[0]
                        print('%s %-45s tint %08x scale %.3f rec[60..104] %s' % (os.path.basename(f), name.split(chr(92))[-1][:45], tint, scale, r[60:104].hex()))
                        shown += 1

                        if shown >= limit:
                            return

            pos += 8 + size


if __name__ == '__main__':
    main()
