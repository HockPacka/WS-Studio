"""Which bones do the header u16 fields 0x348 / 0x368 / 0x580 point at (ModelBone names)?"""
import collections
import csv
import glob
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
import validate_blocks as vb  # noqa: E402

names = {}
with open(os.path.join(vb.ROOT, 'extracted', 'tables_csv', 'ModelBone.csv'), encoding='utf-8') as f:
    for r in csv.DictReader(f):
        names[int(r['ID'])] = r['XSIName']
res = collections.defaultdict(collections.Counter)
eq = collections.Counter()
for p in sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True)):
    b = open(p, 'rb').read()
    if b[:4] != b'LDOM':
        continue
    nb, ob = struct.unpack_from('<QQ', b, 0x180)
    for slot in (0x348, 0x368, 0x580):
        v = struct.unpack_from('<H', b, slot)[0]
        if v == 0xFFFF:
            res[slot]['none'] += 1
        elif v < nb:
            bid = struct.unpack_from('<H', b, ob + 0x630 + v * 0x160)[0]
            res[slot][names.get(bid, 'id%d' % bid)] += 1
        else:
            res[slot]['out of range'] += 1
    eq['0x388==0x38C' if b[0x388:0x38C] == b[0x38C:0x390] else '0x388!=0x38C'] += 1
for s in res:
    print('%03X' % s, res[s].most_common(12))
print(eq)
