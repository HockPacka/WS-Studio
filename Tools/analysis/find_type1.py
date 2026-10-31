import os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__)); TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS); sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon
from validate_formats import inflate, PATCH, a16
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]; files = []
while stack:
    d = stack.pop(); files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3')); stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
n = 0
with open(fs.data.name, 'rb') as a:
    for f in files[::5]:
        i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]; a.seek(o); b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, 0x2F8)
        if not c: continue
        addr = off + 0x630; base = a16(addr + c * 0xA0)
        for k in range(c):
            e = addr + k * 0xA0
            if struct.unpack_from('<I', b, e + 4)[0] == 1:
                print(f.path, 'element', k, 'of', c, 'blob@0x90', hex(struct.unpack_from('<Q', b, e + 0x90)[0]), '@0x98', hex(struct.unpack_from('<Q', b, e + 0x98)[0]), 'id', hex(struct.unpack_from('<I', b, e)[0]))
                n += 1
                break
        if n >= 6: break
