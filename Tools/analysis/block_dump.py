"""Dump slot contents of a few models using the validate_blocks specs. usage: block_dump.py slot(hex) [n-models] [every-nth-file] [skip]"""
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H


def hexs(b, a, n, es):
    return ' | '.join(b[a + i * es:a + (i + 1) * es].hex(' ', 4) for i in range(n))


def dump(b, addr, count, es, fields, ind, maxel=2):
    base = vb.a16(addr + count * es)
    for k in range(min(count, maxel)):
        e = addr + k * es
        print('%s[%d] raw %s' % (ind, k, b[e:e + es].hex(' ', 4)[:200]))
        for off, kind, arg in fields:
            if kind == 'ap':
                c, o = struct.unpack_from('<QQ', b, e + off)
                print('%s  +%02X ap count %d off %#x' % (ind, off, c, o))
                if c and isinstance(arg, tuple):
                    dump(b, base + o, c, arg[0], arg[1], ind + '    ')
                elif c:
                    print('%s     %s' % (ind, hexs(b, base + o, min(c, 6), arg)))
            else:
                c, ko, vo = struct.unpack_from('<QQQ', b, e + off)
                if not c:
                    continue
                print('%s  +%02X dp count %d keys %s' % (ind, off, c, struct.unpack_from('<%dI' % min(c, 6), b, base + ko)))
                print('%s     vals %s' % (ind, hexs(b, base + vo, min(c, 6), arg)))


if __name__ == '__main__':
    slot = int(sys.argv[1], 16)
    n = int(sys.argv[2]) if len(sys.argv) > 2 else 3
    step = int(sys.argv[3]) if len(sys.argv) > 3 else 97
    skip = int(sys.argv[4]) if len(sys.argv) > 4 else 0
    files = sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))
    shown = 0
    for f in files[skip::step]:
        b = open(f, 'rb').read()
        if b[:4] != b'LDOM':
            continue
        if slot in vb.SPEC:
            c, o = struct.unpack_from('<QQ', b, slot)
            if not c:
                continue
            print('==', os.path.relpath(f, vb.ROOT), 'count', c, 'off', hex(o), 'size', len(b))
            es, fields = vb.SPEC[slot]
            dump(b, o + H, c, es, fields, '  ')
        else:
            c, o, v = struct.unpack_from('<QQQ', b, slot)
            if not c:
                continue
            print('==', os.path.relpath(f, vb.ROOT), 'count', c, 'off', hex(o), hex(v), 'size', len(b))
            print('   ', b[o + H:o + H + 64].hex(' ', 4))
        shown += 1
        if shown >= n:
            break
