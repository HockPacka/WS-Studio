"""Typed dump of one emitter.   usage: emitter_typed.py <archive path of .m3> [emitter index]"""
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'blender_addon', 'wildstar_m3'))
import halon  # noqa: E402
import emitter  # noqa: E402
import m3  # noqa: E402
from validate_formats import inflate, PATCH  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
f = fs[sys.argv[1].replace(chr(92), '/')]
i, _ = fs.data.blocks[f.sha1]
o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a:
    a.seek(o)
    b = inflate(f, a.read(bs))
model = m3.read_model(b)
ems = emitter.read_emitters(b)
k = int(sys.argv[2]) if len(sys.argv) > 2 else 0
em = [e for e in ems if e.type == 0 and e.valid][k]
print('emitter', em.index, 'bone', em.bone, 'textures', [model.textures[t][0][-40:] for t in em.texture_ids if t != 0xFFFF and t < len(model.textures)])
print('floats', [round(x, 3) for x in em.floats], 'ints', em.ints, 'flags', em.flags)


def show(raw, st, n):
    out = []
    for j in range(n):
        v = raw[j * st:(j + 1) * st]
        if st == 1:
            out.append(str(v[0]))
        elif st == 2:
            u = struct.unpack('<H', v)[0]
            h = struct.unpack('<e', v)[0]
            out.append('%d|h%.3g' % (u, h))
        elif st == 4:
            out.append('rgba%s|h%s|f%.3g' % (tuple(v), tuple(round(x, 3) for x in struct.unpack('<2e', v)), struct.unpack('<f', v)[0]))
        elif st == 6:
            out.append('h3%s' % (tuple(round(x, 3) for x in struct.unpack('<3e', v)),))
        elif st == 12:
            out.append('f3%s|rgba%s' % (tuple(round(x, 3) for x in struct.unpack('<3f', v)), tuple(v[:4])))
    return ' '.join(out)


for p in em.props:
    if not p.count:
        continue
    st = p.stride or 4
    raw = p.raw
    print('%3d @%03X n=%-2d S%-2d keys=%s  %s' % (p.index, p.pos, p.count, st, list(p.keys)[:4], show(raw, st, min(p.count, 3))))
