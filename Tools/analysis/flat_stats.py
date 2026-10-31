"""Value statistics for flat header arrays.  usage: flat_stats.py slot(hex) elemsize [every-nth-file]"""
import collections
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

slot = int(sys.argv[1], 16)
es = int(sys.argv[2])
step = int(sys.argv[3]) if len(sys.argv) > 3 else 1
cols = collections.defaultdict(collections.Counter)
nm = ne = 0
ex = []
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c or o + vb.H + c * es > len(b):
        continue
    nm += 1
    ne += c
    if len(ex) < 4:
        ex.append((os.path.relpath(f, vb.ROOT), c, b[o + vb.H:o + vb.H + min(c, 4) * es].hex(' ', 4)))
    if es == 2:
        cols[0].update(struct.unpack_from('<%dH' % c, b, o + vb.H))
        continue
    for k in range(c):
        for w in range(0, es - 3, 4):
            cols[w][struct.unpack_from('<I', b, o + vb.H + k * es + w)[0]] += 1
print('slot %03X: %d models %d elements' % (slot, nm, ne))
for w in sorted(cols):
    cc = cols[w]
    print('  +%02X distinct %d  top %s' % (w, len(cc), ', '.join('%#x:%d' % kv for kv in cc.most_common(8))))
for e in ex:
    print(e)
