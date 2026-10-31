"""Which models carry 0x2B8 / 0x308 / 0x318 / 0x570 / 0x588 blocks (category histogram) plus a few full records. usage: probe2b8.py slot"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

slot = int(sys.argv[1], 16)
cat = collections.Counter()
shown = 0
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c:
        continue
    rel = os.path.relpath(f, os.path.join(vb.ROOT, 'extracted', 'ClientData')).split(os.sep)
    cat['/'.join(rel[:2]) if rel[0] == 'Art' else rel[0]] += 1
    nb = struct.unpack_from('<Q', b, 0x180)[0]
    if shown < 6 and c >= 2:
        shown += 1
        es = vb.SPEC[slot][0]
        print(os.sep.join(rel), 'bones', nb, 'count', c)
        for k in range(min(c, 4)):
            print('   ', b[o + vb.H + k * es: o + vb.H + k * es + min(es, 0x28)].hex(' ', 4))
print(cat.most_common(25))
