import collections, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__)); TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS); sys.path.insert(0, os.path.join(TOOLS, 'Halon')); sys.path.insert(0, os.path.join(TOOLS, 'blender_addon', 'wildstar_m3'))
import halon, emitter
from validate_formats import inflate, PATCH, a16
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]; files = []
while stack:
    d = stack.pop(); files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3')); stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
cnt = collections.defaultdict(collections.Counter); mono = collections.Counter(); tot = collections.Counter(); n = 0
with open(fs.data.name, 'rb') as a:
    for f in files[::int(sys.argv[1]) if len(sys.argv) > 1 else 8]:
        i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]; a.seek(o); b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, 0x2F8)
        if not c: continue
        addr = off + 0x630; base = a16(addr + c * 0xA0)
        for em in emitter.read_emitters(b):
            if em.type != 0 or not em.valid or em.template_offset >= 1 << 40: continue
            t = base + em.template_offset
            g = emitter.read_gradients(b, t); n += 1
            for name, d in g.items():
                cnt[name][d['count']] += 1
                p = d['positions']
                if d['count'] > 1:
                    tot[name] += 1
                    if all(p[k] <= p[k + 1] for k in range(len(p) - 1)): mono[name] += 1
print('particle emitters', n)
for name in cnt: print('%-11s stop-count distribution %s   positions monotonic %d/%d' % (name, dict(cnt[name].most_common(7)), mono[name], tot[name]))
