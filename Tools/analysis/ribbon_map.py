import collections, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__)); TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS); sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon
from validate_formats import inflate, PATCH, a16
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]; files = []
while stack:
    d = stack.pop(); files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3')); stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
blobs = []; sizes = collections.Counter(); T = collections.Counter()
with open(fs.data.name, 'rb') as a:
    for f in files[::int(sys.argv[1]) if len(sys.argv) > 1 else 6]:
        i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]; a.seek(o); b = inflate(f, a.read(bs))
        c, off = struct.unpack_from('<QQ', b, 0x2F8)
        if not c: continue
        addr = off + 0x630; base = a16(addr + c * 0xA0)
        els = []
        for k in range(c):
            e = addr + k * 0xA0; t = struct.unpack_from('<I', b, e + 4)[0]; bo = struct.unpack_from("<Q", b, e + (0x98 if t == 1 else 0x90))[0]
            starts = []
            for p in (0x20, 0x38, 0x50):
                cc, ko, vo = struct.unpack_from('<QQQ', b, e + p)
                if cc: starts += [ko, vo]
            els.append((t, bo, starts)); T[t] += 1
        for k, (t, bo, st) in enumerate(els):
            if t != 1 or bo >= 1 << 40: continue
            if k + 1 < len(els) and els[k + 1][2]:
                nxt = min(els[k + 1][2])
                if nxt > bo: sizes[nxt - bo] += 1
            if len(blobs) < 600: blobs.append(b[base + bo: base + bo + 0x1800])
print('types', dict(T), 'type1 blob sizes', sizes.most_common(6), 'samples', len(blobs))
N = len(blobs); ok = collections.Counter()
for bl in blobs:
    for p in range(0x20, min(len(bl), 0x1700) - 24, 8):
        cnt, ko, vo = struct.unpack_from('<QQQ', bl, p)
        if 1 <= cnt <= 4096 and ko % 16 == 0 and vo % 16 == 0 and vo - ko == a16(4 * cnt) and ko >= 0x10 and ko < 0x20000: ok[p] += 1
pos = [p for p in sorted(ok) if ok[p] >= 0.8 * N]
fin = []
for p in pos:
    if not fin or p >= fin[-1] + 24: fin.append(p)
print('DPs', len(fin), ' '.join('%X' % p for p in fin))
