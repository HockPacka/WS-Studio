"""Inspect the 0x490 block (collision-like mesh: header, float3 vertices, index array, 0x14-byte tree nodes)"""
import struct
import sys

f = sys.argv[1] if len(sys.argv) > 1 else 'extracted/ClientData/Art/FX/3D/Esper_Axes_BLU/Channel_Axes/AxesDisolve_BLU_02.m3'
b = open(f, 'rb').read()
H = 0x630
c, o = struct.unpack_from('<QQ', b, 0x490)
e = o + H
base = (e + 0x40 + 15) & ~15
aps = [struct.unpack_from('<QQ', b, e + q) for q in (0, 0x10, 0x20, 0x30)]
print(aps)
rec = base + aps[0][1]
print('hdr', b[rec:rec + 16].hex(' ', 4))
a20 = base + aps[2][1]
print('u32', struct.unpack_from('<48I', b, a20))
print('u16', struct.unpack_from('<48H', b, a20))
a30 = base + aps[3][1]
for i in range(min(aps[3][0], 60)):
    print(i, struct.unpack_from('<f4I', b, a30 + i * 20))
v = base + aps[1][1]
xs = [struct.unpack_from('<3f', b, v + i * 12) for i in range(aps[1][0])]
print('vert bbox', [round(min(p[k] for p in xs), 3) for k in range(3)], [round(max(p[k] for p in xs), 3) for k in range(3)])
gc, go = struct.unpack_from('<QQ', b, 0x250)
print('bounds hdr', struct.unpack_from('<6f', b, 0x1A0 - 0x30) if False else '')
print('u32 max', max(struct.unpack_from('<%dI' % aps[2][0], b, a20)), 'values', aps[2][0])
