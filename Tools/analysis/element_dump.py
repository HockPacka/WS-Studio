"""Dump raw elements of a header array and flag likely nested (count, offset) pairs.
usage: element_dump.py <model path> <slot hex> <elem size hex> [n elements]"""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, os.path.join(os.path.dirname(HERE), 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
path, slot, es = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
n = int(sys.argv[4]) if len(sys.argv) > 4 else 2
f = fs[path.replace(chr(92), '/')]
i, _ = fs.data.blocks[f.sha1]
o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a:
    a.seek(o)
    b = inflate(f, a.read(bs))
H = 0x630
c, off = struct.unpack_from('<QQ', b, slot)
addr = off + H
base = a16(addr + c * es)
print('slot 0x%X count %d addr 0x%X elemsize 0x%X nested base 0x%X filesize %d' % (slot, c, addr, es, base, len(b)))
for k in range(min(n, c)):
    e = addr + k * es
    print('--- element', k)
    for p in range(0, es, 8):
        q = struct.unpack_from('<Q', b, e + p)[0]
        lo, hi = struct.unpack_from('<II', b, e + p)
        note = ''
        if p + 16 <= es:
            cnt, ofs = struct.unpack_from('<QQ', b, e + p)
            if 0 < cnt < 100000 and ofs < len(b) and base + ofs + cnt <= len(b):
                note = '  <-- (count %d, offset 0x%X) -> 0x%X' % (cnt, ofs, base + ofs)
        print('  +0x%03X  %08x %08x   (%.5g, %.5g)%s' % (p, lo, hi, struct.unpack_from('<f', b, e + p)[0], struct.unpack_from('<f', b, e + p + 4)[0], note))
