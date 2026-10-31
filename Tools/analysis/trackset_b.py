"""Which clips contain keys of the secondary track set (1,3,5,7)? names from ModelSequence"""
import bisect
import collections
import csv
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'blender_addon', 'wildstar_m3'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, ROOT  # noqa: E402
import m3  # noqa: E402

names = {int(r['ID']): r['description'] for r in csv.DictReader(open(os.path.join(ROOT, 'extracted', 'tables_csv', 'ModelSequence.csv'), encoding='utf-8'))}
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3') and ('Character' in f.path or 'Creature' in f.path))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
withB = collections.Counter()
total = collections.Counter()
with open(fs.data.name, 'rb') as a:
    for f in files[::int(sys.argv[1]) if len(sys.argv) > 1 else 15]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        mo = m3.read_model(inflate(f, a.read(bs)))
        A = sorted({t for b in mo.bones for tr in (b.scale, b.rotation, b.translation) if tr for t in tr.times})
        B = sorted({t for b in mo.bones for tr in (b.scale2, b.rotation2, b.translation2) if tr for t in tr.times})
        if not B:
            continue
        for c in mo.clips:
            nm = names.get(c.anim_id, str(c.anim_id))
            total[nm] += 1
            k = bisect.bisect_left(B, c.start)
            if k < len(B) and B[k] <= c.end:
                withB[nm] += 1
print('clips (by name) that contain secondary-set keys, models with B tracks only:')
for nm, c in withB.most_common(30):
    print('%-34s %5d of %5d' % (nm, c, total[nm]))
