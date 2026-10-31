"""Print header scalar region as float rows + geometry vertex bounds for comparison. usage: header_floats.py model.m3"""
import struct
import sys

b = open(sys.argv[1], 'rb').read()
for a in range(0x380, 0x520, 16):
    print('%03X' % a, ' '.join('%11.4f' % x for x in struct.unpack_from('<4f', b, a)), ' ', b[a:a + 16].hex(' ', 4))
for a in (0x5B8, 0x5D8, 0x5E8, 0x5F8, 0x608, 0x618, 0x628):
    print('%03X' % a, ' '.join('%11.4f' % x for x in struct.unpack_from('<4f', b, a)))
H = 0x630
gc, go = struct.unpack_from('<QQ', b, 0x250)
ga = go + H
gb = (ga + gc * 0xC8 + 15) & ~15
mn = [1e9] * 3
mx = [-1e9] * 3
for g in range(gc):
    e = ga + g * 0xC8
    vc = struct.unpack_from('<I', b, e + 0x18)[0]
    vs = struct.unpack_from('<H', b, e + 0x1C)[0]
    types = list(b[e + 0x20:e + 0x2B])
    pos = list(b[e + 0x2B:e + 0x36])
    n, o = struct.unpack_from('<QQ', b, e + 0x38)
    base = gb + o
    for i in range(vc):
        p = base + i * vs + pos[0]
        if types[0] == 1:
            v = struct.unpack_from('<3f', b, p)
        else:
            v = [x / 1024.0 for x in struct.unpack_from('<3h', b, p)]
        for k in range(3):
            mn[k] = min(mn[k], v[k])
            mx[k] = max(mx[k], v[k])
print('vertex bounds', [round(x, 4) for x in mn], [round(x, 4) for x in mx])
