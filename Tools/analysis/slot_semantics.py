"""Cross-check unknown M3 header arrays against game tables (ids of VisualEffect / ModelEvent / ModelAttachment / ModelBone ...)."""
import collections
import csv
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
import halon  # noqa: E402
from validate_formats import inflate, PATCH, ROOT  # noqa: E402

T = os.path.join(ROOT, 'extracted', 'tables_csv')


def ids(name, col='ID'):
    return {int(r[col]) for r in csv.DictReader(open(os.path.join(T, name + '.csv'), encoding='utf-8'))}


tables = {n: ids(n) for n in ('VisualEffect', 'ModelEvent', 'ModelAttachment', 'ModelBone', 'ModelBoneSet', 'ModelPose', 'ModelCamera',
                              'Spell4Visual', 'ModelSkinFX', 'ModelMesh', 'ModelCluster', 'ModelSequence')}
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
H = 0x630
want = {0x2C8: (8, 'ap2c8'), 0x280: (8, 'ap280'), 0x1D0: (2, 'u16'), 0x210: (2, 'u16'), 0x270: (2, 'u16'), 0x338: (2, 'u16'),
        0x200: (4, 'pair'), 0x260: (4, 'pair'), 0x2B8: (0x28, 'blob'), 0x4A0: (4, 'u32')}
vals = collections.defaultdict(list)
n = 0
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
with open(fs.data.name, 'rb') as a:
    for f in files[::7]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        nb = struct.unpack_from('<Q', b, 0x180)[0]
        for off, (es, kind) in want.items():
            c, ao = struct.unpack_from('<QQ', b, off)
            if not c:
                continue
            base = ao + H
            for k in range(min(c, 400)):
                p = base + k * es
                if kind == 'ap2c8':
                    vals['2C8 u16@0'].append(struct.unpack_from('<H', b, p)[0])
                    vals['2C8 u16@2'].append(struct.unpack_from('<H', b, p + 2)[0])
                    vals['2C8 u32@4'].append(struct.unpack_from('<I', b, p + 4)[0])
                elif kind == 'ap280':
                    vals['280 u16@0'].append(struct.unpack_from('<H', b, p)[0])
                    vals['280 u16@2'].append(struct.unpack_from('<H', b, p + 2)[0])
                    vals['280 u32@4'].append(struct.unpack_from('<I', b, p + 4)[0])
                elif kind == 'u16':
                    vals['%X u16 (bones=%s)' % (off, 'n')].append(struct.unpack_from('<h', b, p)[0])
                    vals['%X max/bones' % off].append((struct.unpack_from('<h', b, p)[0], nb))
                elif kind == 'pair':
                    vals['%X u16@0' % off].append(struct.unpack_from('<H', b, p)[0])
                    vals['%X u16@2' % off].append(struct.unpack_from('<H', b, p + 2)[0])
        n += 1
        if n >= 3000:
            break


def overlap(name, values):
    s = {v for v in values}
    return '%d distinct, %.0f%% inside' % (len(s), 100.0 * len(s & tables[name]) / max(1, len(s))) if s else '-'


print('models sampled', n)
for k in ('2C8 u32@4',):
    for t in ('VisualEffect', 'Spell4Visual', 'ModelEvent'):
        print(k, 'vs', t, overlap(t, vals[k]))
for k in ('280 u16@0', '280 u16@2', '280 u32@4'):
    print(k, 'range', min(vals[k]), max(vals[k]), 'top', collections.Counter(vals[k]).most_common(5))
    for t in ('ModelEvent', 'ModelAttachment', 'ModelBone', 'ModelCamera', 'ModelPose'):
        print('    vs', t, overlap(t, vals[k]))
for k in ('200 u16@0', '200 u16@2', '260 u16@0', '260 u16@2'):
    if vals[k]:
        print(k, 'range', min(vals[k]), max(vals[k]), 'top', collections.Counter(vals[k]).most_common(4))
        for t in ('ModelPose', 'ModelSequence', 'ModelSkinFX', 'ModelMesh'):
            print('    vs', t, overlap(t, vals[k]))
for off in (0x1D0, 0x210, 0x270, 0x338):
    mm = vals['%X max/bones' % off]
    if mm:
        print('%X' % off, 'values range', min(v for v, _ in mm), max(v for v, _ in mm), '| fraction values < boneCount:', round(sum(1 for v, nb in mm if v < nb) / len(mm), 3))
