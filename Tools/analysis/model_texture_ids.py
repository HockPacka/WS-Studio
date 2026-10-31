"""Verify: the u16 at offset 0 of every m3 texture entry is the 'model texture id' that Creature2DisplayInfo.modelTextureIdNN /
ItemDisplay.modelTextureIdXXNN refer to when they override textures (assetTextureNN)."""
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
from validate_formats import inflate, PATCH, ROOT, a16  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
H = 0x630


def textures(path):
    try:
        f = fs[path.replace('\\', '/')]
    except FileNotFoundError:
        return None
    i, _ = fs.data.blocks[f.sha1]
    o, bs = fs.data.fs[i]
    with open(fs.data.name, 'rb') as a:
        a.seek(o)
        b = inflate(f, a.read(bs))
    tc, to = struct.unpack_from('<QQ', b, 0x1C0)
    ta = to + H
    return [(struct.unpack_from('<H', b, ta + k * 0x20)[0], b[ta + k * 0x20 + 2]) for k in range(tc)]


def check(csvname, model_col, tex_prefix, id_prefix, slots, limit):
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'extracted', 'tables_csv', csvname + '.csv'), encoding='utf-8')))
    cache = {}
    res = collections.Counter()
    seen = set()
    for r in rows:
        mp = r[model_col]
        if not mp or mp in seen:
            continue
        seen.add(mp)
        if len(seen) > limit:
            break
        for k in slots:
            t = r.get('%s%s' % (tex_prefix, k), '')
            mid = r.get('%s%s' % (id_prefix, k), '')
            if not t or not mid or mid == '0':
                continue
            if mp not in cache:
                cache[mp] = textures(mp)
            tl = cache[mp]
            if tl is None:
                res['m3 missing'] += 1
                continue
            hit = [ty for (i, ty) in tl if i == int(mid)]
            res['id found' if hit else 'id NOT found'] += 1
            if hit:
                res['type %d for slot %s' % (hit[0], k)] += 1
    return res


print('Creature2DisplayInfo', dict(check('Creature2DisplayInfo', 'assetPath', 'assetTexture', 'modelTextureId',
                                         ['00', '01', '02', '03', '04', '05'], 600)))
print('ItemDisplay objectModel', dict(check('ItemDisplay', 'objectModel', 'objectTexture', 'modelTextureIdObject', ['0', '1'], 400)))
