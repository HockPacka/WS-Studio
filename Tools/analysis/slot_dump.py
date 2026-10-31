import os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__)); TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS); sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon
from validate_formats import inflate, PATCH, a16
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
path = sys.argv[1]; slot = int(sys.argv[2], 16); n = int(sys.argv[3], 16) if len(sys.argv) > 3 else 0x80
f = fs[path.replace(chr(92), '/')]; i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a: a.seek(o); b = inflate(f, a.read(bs))
for s in range(0x10, 0x630, 8):
    pass
c, off = struct.unpack_from('<QQ', b, slot)
print('slot 0x%X count %d offset 0x%X addr 0x%X filesize %d' % (slot, c, off, off + 0x630, len(b)))
addr = off + 0x630
for p in range(0, n, 16):
    dw = struct.unpack_from('<4I', b, addr + p); q = struct.unpack_from('<2Q', b, addr + p)
    print('+0x%04X %08x %08x %08x %08x  | %s' % (p, *dw, ' '.join('%d' % x if x < 1 << 32 else 'big' for x in q)))
nz = [(s, struct.unpack_from('<Q', b, s)[0]) for s in range(0x10, 0x630, 8) if struct.unpack_from('<Q', b, s)[0]]
