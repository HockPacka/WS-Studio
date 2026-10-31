"""Dump the raw 0x20-byte texture entries of an .m3 to find where modelTextureId lives"""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
path = sys.argv[1]
f = fs[path.replace('\\', '/')]
i, _ = fs.data.blocks[f.sha1]
o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a:
    a.seek(o)
    b = inflate(f, a.read(bs))
H = 0x630
tc, to = struct.unpack_from('<QQ', b, 0x1C0)
ta = to + H
nb = a16(ta + tc * 0x20)
for k in range(tc):
    e = b[ta + k * 0x20: ta + k * 0x20 + 16]
    nc, no = struct.unpack_from('<QQ', b, ta + k * 0x20 + 16)
    nm = b[no + nb: no + nb + nc * 2].decode('utf-16le').rstrip('\0')
    print(k, e.hex(' ', 2), nm[-48:])
mc, mo = struct.unpack_from('<QQ', b, 0x1F0)
ma = mo + H
db = a16(ma + mc * 0x30)
print('materials', mc)
for k in range(mc):
    r = ma + k * 0x30
    dc, do = struct.unpack_from('<QQ', b, r + 0x20)
    print(k, 'hdr', b[r:r + 0x20].hex(' ', 4), 'descs', dc)
    for d in range(dc):
        p = do + db + d * 0x128
        print('    desc', d, b[p:p + 0x18].hex(' ', 2))
