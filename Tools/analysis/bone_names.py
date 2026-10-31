"""Print the bone names for bone indices referenced by a block.  usage: bone_names.py model.m3 idx[,idx...]"""
import csv
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
names = {}
with open(os.path.join(ROOT, 'extracted', 'tables_csv', 'ModelBone.csv'), encoding='utf-8') as f:
    for r in csv.DictReader(f):
        names[int(r['ID'])] = r.get('EnumName') or r.get('description') or str(r)
b = open(sys.argv[1], 'rb').read()
c, o = struct.unpack_from('<QQ', b, 0x180)
for s in sys.argv[2].split(','):
    i = int(s, 0)
    if i < c:
        bid = struct.unpack_from('<H', b, o + 0x630 + i * 0x160)[0]
        print(i, 'bone id', bid, names.get(bid))
    else:
        print(i, 'out of range', c)
