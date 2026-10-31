"""Header word relation of the 0x490 collision block + 0x4A0 ids vs ModelSequence."""
import collections
import csv
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

H = vb.H
seq = set()
with open(os.path.join(vb.ROOT, 'extracted', 'tables_csv', 'ModelSequence.csv'), encoding='utf-8') as f:
    for r in csv.DictReader(f):
        seq.add(int(r['ID']))
rel = collections.Counter()
ex = []
a4 = collections.Counter()
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(p, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, 0x4A0)
    for i in range(c if o + H + c * 4 <= len(b) else 0):
        a, v = struct.unpack_from('<HH', b, o + H + i * 4)
        a4['id in ModelSequence' if a in seq else 'id unknown'] += 1
        a4['variant %d' % v] += 1
    c, o = struct.unpack_from('<QQ', b, 0x490)
    if not c:
        continue
    base = vb.a16(o + H + c * 0x40)
    e = o + H
    (nh, oh), (nv, ov), (ni, oi), (nn, on) = [struct.unpack_from('<QQ', b, e + q) for q in (0, 0x10, 0x20, 0x30)]
    if not nv or nh != 1:
        rel['nh=%d nv=%d' % (nh, nv) if nh != 1 else 'empty'] += 1
        continue
    h = struct.unpack_from('<IIIHH', b, base + oh)
    if h[2] == ni:
        rel['h2==ni'] += 1
    elif h[2] == ni // 3:
        rel['h2==ni/3'] += 1
    elif h[2] == nv:
        rel['h2==nv'] += 1
    else:
        rel['other'] += 1
        if len(ex) < 6:
            ex.append((os.path.basename(p), h, nv, ni, nn))
    rel['h3=%#x' % h[3]] += 1
    rel['h0=%d' % h[0]] += 1
    rel['h1=%d' % h[1]] += 1
print(rel.most_common(30))
print(ex)
print(a4)
