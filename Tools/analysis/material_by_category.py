"""Distribution of material/description enum fields per model category (path based)."""
import collections
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

step = int(sys.argv[1]) if len(sys.argv) > 1 else 10
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
FIELDS = {'m+08': (0, 0x08), 'm+0C': (0, 0x0C), 'm+10': (0, 0x10), 'm+14': (0, 0x14), 'd+08': (1, 0x08), 'd+0C': (1, 0x0C), 'd+10': (1, 0x10), 'd+14': (1, 0x14),
          'd+124': (1, 0x124), 'd+120': (1, 0x120)}
tab = {k: collections.defaultdict(collections.Counter) for k in FIELDS}
tex_type = collections.defaultdict(collections.Counter)
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        cat = f.path.replace('\\', '/').split('/')
        cat = cat[1] if len(cat) > 1 else '?'
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        tc, to = struct.unpack_from('<QQ', b, 0x1C0)
        ta = to + 0x630
        ttypes = [b[ta + k * 0x20 + 2] for k in range(tc)]
        mc, mo = struct.unpack_from('<QQ', b, 0x1F0)
        ma = mo + 0x630
        db = a16(ma + mc * 0x30)
        for k in range(mc):
            r = ma + k * 0x30
            for nm, (kind, off) in FIELDS.items():
                if kind == 0:
                    tab[nm][cat][struct.unpack_from('<I', b, r + off)[0]] += 1
            dc, do = struct.unpack_from('<QQ', b, r + 0x20)
            for j in range(dc):
                e = db + do + j * 0x128
                for nm, (kind, off) in FIELDS.items():
                    if kind == 1:
                        tab[nm][cat][struct.unpack_from('<I', b, e + off)[0]] += 1
                t0, t1 = struct.unpack_from('<2H', b, e)
                if t0 < len(ttypes):
                    tex_type['tex0'][ttypes[t0]] += 1
                if t1 < len(ttypes):
                    tex_type['tex1'][ttypes[t1]] += 1
cats = ['FX', 'Creature', 'Character', 'Prop', 'Structure', 'Item', 'Mount', 'Cinematics', 'UI', 'Terrain']
for nm in FIELDS:
    print('== %s' % nm)
    for c in cats:
        if c in tab[nm]:
            tot = sum(tab[nm][c].values())
            print('   %-11s n=%-6d %s' % (c, tot, ', '.join('%d:%d%%' % (v, 100 * n // tot) for v, n in tab[nm][c].most_common(6))))
print('texture type of the referenced textures', {k: dict(v) for k, v in tex_type.items()})
