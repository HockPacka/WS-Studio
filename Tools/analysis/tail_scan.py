"""Find models whose last known array start owns a huge tail (= unexplained data)."""
import collections
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
sys.path.insert(0, os.path.join(os.path.dirname(HERE), 'Halon'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH  # noqa: E402
from byte_ownership import starts  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))
stack = [fs.root]
files = []
while stack:
    d = stack.pop()
    files.extend(f for f in d.files.values() if f.name.lower().endswith('.m3'))
    stack.extend(d.dirs.values())
files.sort(key=lambda f: f.path)
tails = []
lab = collections.Counter()
with open(fs.data.name, 'rb') as a:
    for f in files[::int(sys.argv[1]) if len(sys.argv) > 1 else 9]:
        i, _ = fs.data.blocks[f.sha1]
        o, bs = fs.data.fs[i]
        a.seek(o)
        b = inflate(f, a.read(bs))
        st = sorted(set(starts(b)))
        if not st:
            continue
        addr, label = st[-1]
        tail = len(b) - addr
        lab[label] += tail
        tails.append((tail, f.path, label, len(b)))
tails.sort(reverse=True)
print('tail owner label -> bytes', lab.most_common(8))
for t in tails[:12]:
    print('%10d  of %10d  %-18s %s' % (t[0], t[3], t[2], t[1][-60:]))
