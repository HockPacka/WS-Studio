"""Distribution of the light header words and which DPs are populated per light type."""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
DPS = [0x10, 0x28, 0x40, 0x58, 0x70, 0x88, 0xA0, 0xB8, 0xD0, 0xE8, 0x100, 0x118, 0x130, 0x148, 0x160, 0x178]
types = collections.Counter()
use = collections.defaultdict(collections.Counter)
w4 = collections.defaultdict(collections.Counter)
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(p, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, 0x318)
    if not c or o + H + c * 0x190 > len(b):
        continue
    for k in range(c):
        e = o + H + k * 0x190
        t, bone, w2, w3, w4_ = struct.unpack_from('<HHHHH', b, e)
        types[t] += 1
        w4[t][(w2, w3)] += 1
        for d in DPS:
            if struct.unpack_from('<Q', b, e + d)[0]:
                use[t][d] += 1
print('types', sorted(types.items()))
for t in sorted(types):
    print('type', t, 'n', types[t], 'dp use', {'%X' % d: v for d, v in sorted(use[t].items())}, 'w2,w3', w4[t].most_common(3))
