"""Dumps the material sets, textures, materials and sector sub meshes of a FEDI model (.i3), see docs/i3_dgn_format.md.
usage: i3_materials.py <model.i3> [set index]
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import i3_reader as r  # noqa: E402

H = 0x170


def al(x):
    return (x + 15) & ~15


def slot(b, o):
    return struct.unpack_from('<IxxxxQ', b, o)


def main():
    p = sys.argv[1]
    only = int(sys.argv[2]) if len(sys.argv) > 2 else 0
    b = open(p, 'rb').read()
    m = r.parse_idef(b)
    print('sectors', m['sectors'], 'names', m['names'])
    cnt, off = slot(b, 0x40)
    arr = H + off
    child = arr + al(cnt * 0x58)
    print('material sets', cnt)

    for si in range(cnt):
        if si != only:
            continue
        rr = arr + si * 0x58
        nc, no = slot(b, rr + 8)
        print('set', si, b[child + no:child + no + nc * 2].decode('utf-16le').rstrip('\0'))
        c2, o2 = slot(b, rr + 0x18)
        a2 = child + o2
        ch2 = a2 + al(c2 * 0x28)
        tc, to = slot(b, rr + 0x38)
        ta = child + to
        sb = ta + tc * 0x20

        for t in range(tc):
            c, o = slot(b, ta + t * 0x20 + 0x10)
            e = struct.unpack_from('<HHIf', b, ta + t * 0x20)
            name = b[sb + o:sb + o + c * 2].decode('utf-16le').rstrip('\0')
            print('  tex %2d %s %s' % (t, e, name.split(chr(92))[-1]))

        for q in range(c2):
            qq = a2 + q * 0x28
            c3, o3 = slot(b, qq + 0x18)
            print('  pass', q, 'mats', c3, 'hdr', struct.unpack_from('<6I', b, qq))

            for k in range(c3):
                mr = ch2 + o3 + k * 0x128
                print('    mat', k, struct.unpack_from('<16H', b, mr), 'slots', [struct.unpack_from('<I', b, mr + 0x18 + s * 0x18)[0] for s in range(10)])

    base = p[:-3]
    for s in m['sectors']:
        sp = base + '.' + s + '.i3'
        if not os.path.exists(sp):
            continue
        sb2 = open(sp, 'rb').read()
        sh = r.parse(sb2)
        c, o, _ = sh['arrays']['submesh']

        for i in range(c):
            rec = struct.unpack_from('<7I', sb2, r.HEADER + o + i * 28)
            print('sub', s, i, rec, 'material hi', rec[5] >> 8, 'lo', rec[5] & 255)


if __name__ == '__main__':
    main()
