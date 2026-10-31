import os, sys, struct
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE); sys.path.insert(0, os.path.dirname(HERE)); sys.path.insert(0, os.path.join(os.path.dirname(HERE), 'Halon'))
import halon
from validate_formats import inflate, PATCH
from byte_ownership import starts, H
fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
path = sys.argv[1]
f = fs[path.replace(chr(92), '/')]; i, _ = fs.data.blocks[f.sha1]; o, bs = fs.data.fs[i]
with open(fs.data.name, 'rb') as a: a.seek(o); b = inflate(f, a.read(bs))
st = sorted(set(starts(b)))
print(path, len(b), 'bytes')
prev = None
agg = []
for k, (addr, label) in enumerate(st):
    end = st[k + 1][0] if k + 1 < len(st) else len(b)
    if agg and agg[-1][1] == label.split('.')[0] and False: pass
    agg.append((addr, label, end - addr))
cur = None
for addr, label, size in agg:
    print('0x%08x %-26s %10d' % (addr, label, size))
