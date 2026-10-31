"""Test how Creature2DisplayInfo.modelTextureIdNN relates to the textures array inside the .m3"""
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

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))


def get(path):
    f = fs[path.replace('\\', '/')]
    i, _ = fs.data.blocks[f.sha1]
    o, bs = fs.data.fs[i]
    with open(fs.data.name, 'rb') as a:
        a.seek(o)
        return inflate(f, a.read(bs))


rows = list(csv.DictReader(open(os.path.join(ROOT, 'extracted', 'tables_csv', 'Creature2DisplayInfo.csv'), encoding='utf-8')))
cache = {}
diffs = collections.Counter()
types = collections.Counter()
seen = set()
n = 0
for r in rows:
    ap = r['assetPath']
    if not ap or ap in seen:
        continue
    seen.add(ap)
    for k in range(6):
        t = r['assetTexture0%d' % k]
        mid = r['modelTextureId0%d' % k]
        if not t or not mid or mid == '0':
            continue
        if ap not in cache:
            try:
                cache[ap] = m3.read_model(get(ap)).textures
            except Exception:
                cache[ap] = None
        tl = cache[ap]
        if not tl:
            break
        names = [x[0].lower() for x in tl]
        if t.lower() in names:
            i = names.index(t.lower())
            diffs[(k, i - int(mid))] += 1
            types[(k, tl[i][1])] += 1
    n += 1
    if n > 500:
        break
print('models checked', n)
print('slot k, (textureIndex - modelTextureId):', sorted(diffs.items(), key=lambda x: -x[1])[:12])
print('slot k, m3 texture type of the replaced slot:', sorted(types.items(), key=lambda x: -x[1])[:8])
