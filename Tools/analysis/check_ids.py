"""Test which game table the ids of a flat M3 array belong to.  usage: check_ids.py slot elemsize word-offset [every-nth-file]"""
import csv
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

slot = int(sys.argv[1], 16)
es = int(sys.argv[2])
woff = int(sys.argv[3], 0)
step = int(sys.argv[4]) if len(sys.argv) > 4 else 1
tabdir = os.path.join(vb.ROOT, 'extracted', 'tables_csv')
tables = {}
for fn in os.listdir(tabdir):
    if not fn.endswith('.csv'):
        continue
    with open(os.path.join(tabdir, fn), encoding='utf-8', errors='replace') as f:
        r = csv.reader(f)
        hdr = next(r, None)
        if not hdr or hdr[0].lower() != 'id':
            continue
        ids = set()
        for row in r:
            try:
                ids.add(int(row[0]))
            except (ValueError, IndexError):
                pass
        tables[fn[:-4]] = ids
vals = []
for f in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]:
    b = open(f, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    c, o = struct.unpack_from('<QQ', b, slot)
    if not c or o + vb.H + c * es > len(b):
        continue
    for k in range(c):
        vals.append(struct.unpack_from('<I', b, o + vb.H + k * es + woff)[0])
vs = set(vals)
print(len(vals), 'values', len(vs), 'distinct')
res = sorted(((len(vs & ids) / len(vs), n, len(ids)) for n, ids in tables.items()), reverse=True)[:8]
for fr, n, sz in res:
    print('%-32s %.3f of %d ids' % (n, fr, sz))
