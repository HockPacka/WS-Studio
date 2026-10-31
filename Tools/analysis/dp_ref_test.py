"""For the u16 values of a DP field of a rare block: which array of the same model do they index (after masking flag bits)?
usage: dp_ref_test.py slot(hex) field-offset(hex) [mask(hex)] [every-nth-file]"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
slot = int(sys.argv[1], 16)
foff = int(sys.argv[2], 16)
mask = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0xFFFF
step = int(sys.argv[4]) if len(sys.argv) > 4 else 1
es = vb.SPEC[slot][0]
ARR = {0x10: 'clips', 0x80: 'ap080', 0xF0: 'ap0F0', 0x180: 'bones', 0x1C0: 'textures', 0x1E0: 'ap1E0', 0x1F0: 'materials', 0x200: 'ap200',
       0x250: 'geometry', 0x260: 'ap260', 0x280: 'attach', 0x2B8: 'ap2B8', 0x2C8: 'sounds', 0x2F8: 'emitters', 0x308: 'ap308', 0x318: 'lights',
       0x328: 'cameras', 0x560: 'ap560', 0x598: 'ap598'}
tot = 0
below = collections.Counter()
exact = collections.Counter()
hist = collections.Counter()
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c or o + H + c * es > len(b):
        continue
    counts = {n: struct.unpack_from('<Q', b, off)[0] for off, n in ARR.items()}
    base = vb.a16(o + H + c * es)
    mx = -1
    for k in range(c):
        n, ko, vo = struct.unpack_from('<QQQ', b, o + H + k * es + foff)
        for i in range(n):
            v = struct.unpack_from('<H', b, base + vo + i * 2)[0] & mask
            hist[v >> 12] += 1
            tot += 1
            mx = max(mx, v)
            for nm, cn in counts.items():
                if v < cn:
                    below[nm] += 1
    for nm, cn in counts.items():
        if mx == cn - 1:
            exact[nm] += 1
print('values', tot, 'top nibble hist', sorted(hist.items()))
print(', '.join('%s %.0f%%' % (n, 100.0 * v / max(tot, 1)) for n, v in below.most_common(5)), '| max==count-1:', exact.most_common(4))
