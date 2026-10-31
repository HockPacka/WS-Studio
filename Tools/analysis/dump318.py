"""Typed dump of 0x318 (light) elements.  usage: dump318.py model.m3"""
import struct
import sys

HERE = __file__
b = open(sys.argv[1], 'rb').read()
H = 0x630
c, o = struct.unpack_from('<QQ', b, 0x318)
a = o + H
base = (a + c * 0x190 + 15) & ~15
DP = [(0x10, 2), (0x28, 2), (0x40, 2), (0x58, 4), (0x70, 4), (0x88, 2), (0xA0, 2), (0xB8, 2), (0xD0, 2), (0xE8, 2), (0x100, 2), (0x118, 2),
      (0x130, 2), (0x148, 2), (0x160, 2), (0x178, 2)]
for k in range(c):
    e = a + k * 0x190
    print('light', k, 'head', b[e:e + 0x10].hex(' ', 2))
    for off, vs in DP:
        n, ko, vo = struct.unpack_from('<QQQ', b, e + off)
        if not n:
            continue
        keys = struct.unpack_from('<%dI' % min(n, 6), b, base + ko)
        raw = [b[base + vo + i * vs: base + vo + (i + 1) * vs] for i in range(min(n, 6))]
        if vs == 2:
            vals = ['%.4g' % struct.unpack('<e', r)[0] for r in raw]
        else:
            vals = [r.hex() for r in raw]
        print('   +%03X n=%d keys %s vals %s' % (off, n, keys, vals))
