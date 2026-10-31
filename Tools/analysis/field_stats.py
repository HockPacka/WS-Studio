"""Statistical field map of the elements of unknown M3 header arrays.
For every 4-byte position inside an element: share of zeros, int/float plausibility, distinct values, top values.
usage: field_stats.py <slot hex> <elem size hex> [every-nth-file] [max elements per file]"""
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
import m3walk  # noqa: E402
from validate_formats import inflate, PATCH  # noqa: E402

slot, es = int(sys.argv[1], 16), int(sys.argv[2], 16)
step = int(sys.argv[3]) if len(sys.argv) > 3 else 20
maxel = int(sys.argv[4]) if len(sys.argv) > 4 else 40
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
vals = collections.defaultdict(collections.Counter)
n = 0
models = 0
with open(fs.data.name, 'rb') as a:
    for f in files[::step]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, slot)
        if not c or off + 0x630 + c * es > len(b):
            continue
        models += 1
        for k in range(min(c, maxel)):
            e = off + 0x630 + k * es
            n += 1
            for p in range(0, es - 3, 4):
                vals[p][struct.unpack_from('<I', b, e + p)[0]] += 1
print('slot 0x%X elem 0x%X: %d elements from %d models' % (slot, es, n, models))
for p in sorted(vals):
    cnt = vals[p]
    tot = sum(cnt.values())
    zero = cnt.get(0, 0) / tot

    def isfloat(v):
        if v == 0:
            return False
        x = struct.unpack('<f', struct.pack('<I', v))[0]
        return math.isfinite(x) and 1e-6 < abs(x) < 1e7 and (v >> 23) & 0xFF not in (0,)
    fl = sum(c for v, c in cnt.items() if isfloat(v)) / tot
    small = sum(c for v, c in cnt.items() if v < 0x10000) / tot
    top = ', '.join('%s:%d%%' % (('%d' % v) if v < 0x10000 else ('%.4g' % struct.unpack('<f', struct.pack('<I', v))[0] if isfloat(v) else '0x%X' % v), 100 * c // tot) for v, c in cnt.most_common(4))
    kind = 'ZERO' if zero > 0.995 else ('FLOAT' if fl > 0.7 else ('INT' if small > 0.9 else 'MIX'))
    print('+0x%03X %-5s distinct %-6d zero %3d%% float %3d%%  %s' % (p, kind, len(cnt), zero * 100, fl * 100, top))
