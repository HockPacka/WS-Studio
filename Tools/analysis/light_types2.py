import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
ex = collections.defaultdict(list)
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', 'Art', 'Light', '**', '*.m3'), recursive=True)):
    b = open(p, 'rb').read()
    c, o = struct.unpack_from('<QQ', b, 0x318)
    for k in range(c):
        t = struct.unpack_from('<H', b, o + H + k * 0x190)[0]
        if len(ex[t]) < 8:
            ex[t].append(os.path.basename(p))
for t in sorted(ex):
    print(t, ex[t])
