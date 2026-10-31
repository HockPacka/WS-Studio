"""Typed dump of 0x560 elements with texture names.  usage: dump560.py model.m3"""
import struct
import sys

b = open(sys.argv[1], 'rb').read()
H = 0x630


def a16(x):
    return (x + 15) & ~15


tc, to = struct.unpack_from('<QQ', b, 0x1C0)
ta = to + H
nb = a16(ta + tc * 0x20)
texnames = []
for i in range(tc):
    mid, typ = struct.unpack_from('<HB', b, ta + i * 0x20)
    c, o = struct.unpack_from('<QQ', b, ta + i * 0x20 + 16)
    texnames.append('%d(type%d)%s' % (mid, typ, b[nb + o: nb + o + c * 2].decode('utf-16le').rstrip('\0').split('\\')[-1][-28:]))
print('textures', texnames)
mc = struct.unpack_from('<Q', b, 0x1F0)[0]
print('materials', mc, 'bones', struct.unpack_from('<Q', b, 0x180)[0], 'emitters', struct.unpack_from('<Q', b, 0x2F8)[0])
c, o = struct.unpack_from('<QQ', b, 0x560)
a = o + H
base = a16(a + c * 0xA0)
for k in range(c):
    e = a + k * 0xA0
    print('el', k, 'u16:', struct.unpack_from('<12H', b, e), 'tail', b[e + 0x18:e + 0x28].hex(' ', 4))
    for off, vs, nm in ((0x28, 2, 'alpha'), (0x40, 2, 'dp40'), (0x58, 4, 's4a'), (0x70, 4, 's4b'), (0x88, 4, 's4c')):
        n, ko, vo = struct.unpack_from('<QQQ', b, e + off)
        if n:
            keys = struct.unpack_from('<%dI' % min(n, 8), b, base + ko)
            vals = [b[base + vo + i * vs: base + vo + (i + 1) * vs] for i in range(min(n, 8))]
            print('    %s n=%d keys %s vals %s' % (nm, n, keys, [struct.unpack('<e', v)[0] if vs == 2 and nm == 'alpha' else v.hex() for v in vals]))
