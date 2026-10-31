#!/usr/bin/env python3
"""Fast file-type inventory straight from the archive indexes (no disk scan).
Reads the first 8 bytes of up to N sample files per extension from the archive for magic detection."""
import collections
import json
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'Halon'))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import halon  # noqa: E402
from extract_raw import decompress, walk  # noqa: E402

root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
patch = os.path.join(root, 'WildStar', 'Patch')
out = os.path.join(root, 'docs')
os.makedirs(out, exist_ok=True)
SAMPLES = 12

stats = collections.OrderedDict()
for name in ('ClientData', 'ClientDataEN', 'ClientDataDE'):
    fs = halon.Filesystem(os.path.join(patch, name))
    with open(fs.data.name, 'rb') as arc:
        for f in walk(fs.root):
            ext = os.path.splitext(f.name)[1].lower() or '(none)'
            s = stats.setdefault(ext, {'count': 0, 'bytes': 0, 'archives': collections.Counter(), 'dirs': collections.Counter(),
                                       'magics': collections.Counter(), 'samples': [], 'zero': 0})
            s['count'] += 1
            s['bytes'] += f.uncompressed_size
            s['archives'][name] += 1
            s['dirs'][f.path.replace('\\', '/').split('/')[0]] += 1
            if f.uncompressed_size == 0:
                s['zero'] += 1
            if len(s['samples']) < SAMPLES and 0 < f.uncompressed_size < 8 * 2**20:
                idx, _ = fs.data.blocks[f.sha1]
                off, bs = fs.data.fs[idx]
                arc.seek(off)
                data = decompress(f, arc.read(bs))
                s['samples'].append(f.path.replace('\\', '/'))
                s['magics'][data[:4].hex()] += 1

res = {}
for ext, s in sorted(stats.items(), key=lambda kv: -kv[1]['count']):
    res[ext] = {'count': s['count'], 'bytes': s['bytes'], 'zero_size': s['zero'], 'archives': dict(s['archives']),
                'top_dirs': dict(s['dirs'].most_common(5)), 'magics': dict(s['magics'].most_common(4)), 'samples': s['samples'][:3]}
with open(os.path.join(out, 'file_types.json'), 'w', encoding='utf-8') as fh:
    json.dump(res, fh, indent=1)

tot = sum(v['count'] for v in res.values())
print('total entries %d, %.2f GB uncompressed' % (tot, sum(v['bytes'] for v in res.values()) / 2**30))
print('%-9s %8s %9s  %-26s %s' % ('ext', 'count', 'MB', 'top dirs', 'magics'))
for ext, v in res.items():
    mg = ', '.join('%s[%s]' % (m, bytes.fromhex(m).decode('ascii', 'replace').replace('\0', '.')) for m in v['magics'])
    print('%-9s %8d %9.1f  %-26s %s' % (ext, v['count'], v['bytes'] / 2**20, ','.join(v['top_dirs'])[:26], mg))
