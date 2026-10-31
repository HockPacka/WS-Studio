"""Survey value strides of every key/value track (nested + top level) over all models, and byte attribution with m3walk."""
import collections
import json
import multiprocessing as mp
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
import halon  # noqa: E402
import m3walk  # noqa: E402
from validate_formats import inflate, PATCH, ROOT, ARCHIVES  # noqa: E402


def worker(a):
    wid, n, step = a
    strides = collections.defaultdict(collections.Counter)
    own = collections.Counter()
    total = 0
    cnt = 0
    i = 0
    for name in ARCHIVES:
        fs = halon.Filesystem(os.path.join(PATCH, name))
        with open(fs.data.name, 'rb') as arc:
            stack = [fs.root]
            files = []
            while stack:
                d = stack.pop()
                files.extend(d.files.values())
                stack.extend(d.dirs.values())
            files.sort(key=lambda f: f.path)
            for f in files:
                if not f.name.lower().endswith('.m3'):
                    continue
                i += 1
                if i % n != wid or (i // n) % step:
                    continue
                idx, _ = fs.data.blocks[f.sha1]
                off, bs = fs.data.fs[idx]
                arc.seek(off)
                b = inflate(f, arc.read(bs))
                if b[:4] != b'LDOM':
                    continue
                total += len(b)
                cnt += 1
                for start, end, r in m3walk.extents(b):
                    own[r.label] += end - start
                    if r.kind == 'values':
                        s = m3walk.stride_of(r.count, end - start)
                        strides[r.label][s] += 1
    return {k: dict(v) for k, v in strides.items()}, dict(own), total, cnt


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p:
        parts = p.map(worker, [(w, n, step) for w in range(n)])
    strides = collections.defaultdict(collections.Counter)
    own = collections.Counter()
    total = cnt = 0
    for s, o, t, c in parts:
        for k, v in s.items():
            strides[k].update(v)
        own.update(o)
        total += t
        cnt += c
    json.dump({'strides': {k: dict(v) for k, v in strides.items()}, 'owned': dict(own), 'bytes': total, 'files': cnt},
              open(os.path.join(ROOT, 'docs', 'm3_strides.json'), 'w'), indent=1)
    print('files', cnt, 'bytes', total)
    for k in sorted(strides):
        top = strides[k].most_common(3)
        print('%-22s %s' % (k, ', '.join('%s x%d' % (s, c) for s, c in top)))
    print('--- byte ownership top 25')
    for k, v in own.most_common(25):
        print('%-26s %12d %5.2f%%' % (k, v, 100.0 * v / total))
