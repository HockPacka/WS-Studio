"""0x490 multi-record headers"""
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
shown = 0
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::7]:
    b = open(p, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, 0x490)
    if not c:
        continue
    base = vb.a16(o + H + c * 0x40)
    e = o + H
    (nh, oh), (nv, ov), (ni, oi), (nn, on) = [struct.unpack_from('<QQ', b, e + q) for q in (0, 0x10, 0x20, 0x30)]
    if nh < 2:
        continue
    print(os.path.basename(p), 'nh', nh, 'nv', nv, 'ni', ni, 'nn', nn)
    for i in range(nh):
        print('   ', struct.unpack_from('<IIIHH', b, base + oh + i * 16))
    shown += 1
    if shown > 6:
        break
