#!/usr/bin/env python3
"""Inventory of extracted WildStar files: per extension count, size, magic bytes."""
import collections
import json
import os
import sys

root = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'extracted')
out_json = sys.argv[2] if len(sys.argv) > 2 else os.path.join(root, 'inventory.json')

stats = collections.defaultdict(lambda: {'count': 0, 'bytes': 0, 'magics': collections.Counter(), 'archives': collections.Counter(), 'example': None, 'dirs': collections.Counter()})
for dirpath, _, files in os.walk(root):
    rel = os.path.relpath(dirpath, root).replace('\\', '/')
    parts = rel.split('/')
    if parts == ['.']:
        continue
    arc = parts[0]
    sub = parts[1] if len(parts) > 1 else ''
    for f in files:
        ext = os.path.splitext(f)[1].lower() or '(none)'
        p = os.path.join(dirpath, f)
        s = stats[ext]
        size = os.path.getsize(p)
        s['count'] += 1
        s['bytes'] += size
        s['archives'][arc] += 1
        s['dirs'][sub] += 1
        if s['example'] is None:
            s['example'] = os.path.relpath(p, root).replace('\\', '/')
        try:
            with open(p, 'rb') as fh:
                head = fh.read(4)
        except OSError:
            head = b''
        s['magics'][head.hex()] += 1

ordered = sorted(stats.items(), key=lambda kv: -kv[1]['count'])
res = {}
for ext, s in ordered:
    res[ext] = {
        'count': s['count'], 'bytes': s['bytes'],
        'archives': dict(s['archives']),
        'dirs': dict(s['dirs'].most_common(6)),
        'magics': dict(s['magics'].most_common(5)),
        'example': s['example'],
    }
with open(out_json, 'w', encoding='utf-8') as fh:
    json.dump(res, fh, indent=1)

tot = sum(s['count'] for s in stats.values())
totb = sum(s['bytes'] for s in stats.values())
print('total files %d, %.2f GB' % (tot, totb / 2**30))
print('%-8s %8s %9s  %s' % ('ext', 'count', 'MB', 'top magics (hex[ascii])'))
for ext, s in ordered:
    mg = ', '.join('%s[%s]x%d' % (m, bytes.fromhex(m).decode('ascii', 'replace').replace('\0', '.') if m else '', c) for m, c in s['magics'].most_common(3))
    print('%-8s %8d %9.1f  %s' % (ext, s['count'], s['bytes'] / 2**20, mg))
