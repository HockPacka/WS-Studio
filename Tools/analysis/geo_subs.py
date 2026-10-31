"""Print counts/spans/strides of the geometry sub arrays of a model"""
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

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
for path in sys.argv[1:]:
    f = fs[path.replace(chr(92), '/')]
    i, _ = fs.data.blocks[f.sha1]
    o, bs = fs.data.fs[i]
    with open(fs.data.name, 'rb') as a:
        a.seek(o)
        b = inflate(f, a.read(bs))
    print(path, len(b))
    gc, go = struct.unpack_from('<QQ', b, 0x250)
    g = go + 0x630
    print(' geometry struct raw:')
    for p in range(0, 0xC8, 8):
        print('   +0x%02X %016x' % (p, struct.unpack_from('<Q', b, g + p)[0]))
    for start, end, r in m3walk.extents(b):
        if r.label.startswith('geo.'):
            print('  %-22s count %-8d span %-9d stride %s  first bytes %s' % (r.label, r.count, end - start, m3walk.stride_of(r.count, end - start), b[start:start + 16].hex()))
