"""Field statistics of M3 materials (0x30 B) and material descriptions (0x140 B).  usage: material_stats.py [every-nth-file]"""
import collections
import math
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

step = int(sys.argv[1]) if len(sys.argv) > 1 else 15
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
mat = collections.defaultdict(collections.Counter)
desc = collections.defaultdict(collections.Counter)
ndesc = collections.Counter()
nm = nd = 0
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        mc, mo = struct.unpack_from('<QQ', b, 0x1F0)
        ma = mo + 0x630
        db = a16(ma + mc * 0x30)
        for k in range(mc):
            r = ma + k * 0x30
            nm += 1
            for p in range(0, 0x20, 4):
                mat[p][struct.unpack_from('<I', b, r + p)[0]] += 1
            dc, do = struct.unpack_from('<QQ', b, r + 0x20)
            ndesc[dc] += 1
            for j in range(dc):
                e = db + do + j * 0x128
                nd += 1
                for p in range(0, 0x18, 4):
                    desc[p][struct.unpack_from('<I', b, e + p)[0]] += 1
                for p in range(0x120, 0x128, 4):
                    desc[p][struct.unpack_from('<I', b, e + p)[0]] += 1
                for q, pos in enumerate((0x18, 0x30, 0x48, 0x60, 0x78, 0x90, 0xA8, 0xC0, 0xD8, 0xF0, 0x108)):
                    cc, ko, vo = struct.unpack_from('<QQQ', b, e + pos)
                    desc[('dp', q)][min(cc, 9)] += 1
                    if cc == 1 and q != 5:
                        raw = b[db + do + j * 0x128 + 0 : 0]  # placeholder
                        nbase = a16(db + do + j * 0x128 + 0x128)


def isfloat(v):
    if v == 0:
        return False
    x = struct.unpack('<f', struct.pack('<I', v))[0]
    return math.isfinite(x) and 1e-6 < abs(x) < 1e7 and (v >> 23) & 0xFF != 0


def show(title, table, total, keys):
    print('=== %s (%d elements)' % (title, total))
    for p in keys:
        cnt = table[p]
        if isinstance(p, tuple):
            print('  DP %-2d count dist %s' % (p[1], dict(cnt.most_common(5))))
            continue
        top = ', '.join('%s:%d%%' % (('%d' % v if v < 0x10000 else ('%.4g' % struct.unpack('<f', struct.pack('<I', v))[0] if isfloat(v) else '0x%X' % v)), 100 * c // total) for v, c in cnt.most_common(5))
        print('  +0x%03X distinct %-5d %s' % (p, len(cnt), top))


print('descriptions per material', dict(ndesc.most_common(6)))
show('material', mat, nm, sorted(mat))
show('description', desc, nd, [k for k in sorted(desc, key=lambda x: (isinstance(x, tuple), x if not isinstance(x, tuple) else x[1]))])
