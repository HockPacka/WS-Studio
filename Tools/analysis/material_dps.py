"""Values of the animated parameters (DPs) inside material descriptions (0x128 B). usage: material_dps.py [every-nth-file]"""
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

POS = (0x18, 0x30, 0x48, 0x60, 0x78, 0x90, 0xA8, 0xC0, 0xD8, 0xF0, 0x108)
step = int(sys.argv[1]) if len(sys.argv) > 1 else 10
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
vals = collections.defaultdict(collections.Counter)
nkeys = collections.defaultdict(collections.Counter)
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
            dc, do = struct.unpack_from('<QQ', b, r + 0x20)
            dbase = db + do
            nb = a16(dbase + dc * 0x128)
            for j in range(dc):
                e = dbase + j * 0x128
                for q, pos in enumerate(POS):
                    cc, ko, vo = struct.unpack_from('<QQQ', b, e + pos)
                    if not cc:
                        continue
                    nkeys[q][min(cc, 6)] += 1
                    st = 12 if q == 10 else 4
                    raw = b[nb + vo: nb + vo + st]
                    if len(raw) < st:
                        continue
                    if st == 4:
                        fl = struct.unpack('<f', raw)[0]
                        h = struct.unpack('<2e', raw)
                        vals[q][('rgba%s' % tuple([tuple(raw)])) if False else 'f=%.4g|h=%.3g,%.3g|b=%s' % (fl, h[0], h[1], raw.hex())] += 1
                    else:
                        vals[q]['f3=%s' % (tuple(round(x, 3) for x in struct.unpack('<3f', raw)),)] += 1
for q in range(11):
    if q in nkeys:
        print('DP %2d @%03X keycount %s' % (q, POS[q], dict(nkeys[q].most_common(4))))
        for v, c in vals[q].most_common(6):
            print('        %6d  %s' % (c, v))
