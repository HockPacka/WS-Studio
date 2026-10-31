"""List nested offsets of 0x2F8 elements in order to reveal blob sizes."""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
path = sys.argv[1]
f = fs[path.replace(chr(92), '/')]
i, _ = fs.data.blocks[f.sha1]
o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a:
    a.seek(o)
    b = inflate(f, a.read(bs))
c, off = struct.unpack_from('<QQ', b, 0x2F8)
es = 0xA0
addr = off + 0x630
base = a16(addr + c * es)
print('count', c, 'base 0x%X' % base, 'file', len(b))
rows = []
for k in range(min(c, int(sys.argv[2]) if len(sys.argv) > 2 else 12)):
    e = addr + k * es
    t = struct.unpack_from('<I', b, e + 4)[0]
    dps = []
    for p in (0x20, 0x38, 0x50):
        cc, ko, vo = struct.unpack_from('<QQQ', b, e + p)
        dps.append((cc, ko, vo))
    blob = struct.unpack_from('<Q', b, e + 0x90)[0]
    rows.append((k, t, dps, blob))
    print('el %2d type %d id %04x  dp20 %s dp38 %s dp50 %s blob 0x%X' % (k, t, struct.unpack_from('<H', b, e)[0], dps[0], dps[1], dps[2], blob))
offs = sorted({x for r in rows for d in r[2] for x in d[1:] if d[0]} | {r[3] for r in rows})
print('sorted nested offsets', [hex(x) for x in offs][:40])
print('diffs', [offs[i + 1] - offs[i] for i in range(min(40, len(offs) - 1))])
