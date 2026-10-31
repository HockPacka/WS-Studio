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
path, k = sys.argv[1], int(sys.argv[2])
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
f = fs[path.replace(chr(92), '/')]
i, _ = fs.data.blocks[f.sha1]
o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a:
    a.seek(o)
    b = inflate(f, a.read(bs))
c, off = struct.unpack_from('<QQ', b, 0x2F8)
addr = off + 0x630
base = a16(addr + c * 0xA0)
e = addr + k * 0xA0
blob = base + struct.unpack_from('<Q', b, e + 0x90)[0]
print('blob at 0x%X' % blob)
for p in range(lo, hi, 16):
    dw = struct.unpack_from('<4I', b, blob + p)
    fl = struct.unpack_from('<4f', b, blob + p)
    print('+0x%04X  %08x %08x %08x %08x   %s' % (p, *dw, ' '.join('%.4g' % x if abs(x) < 1e7 and (abs(x) > 1e-6 or x == 0) else '-' for x in fl)))
