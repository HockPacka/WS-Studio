#!/usr/bin/env python3
"""Survey every array/DPointer slot of the M3 header across all models -> docs/m3_header_survey.json"""
import collections, json, multiprocessing as mp, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon
from validate_formats import inflate, PATCH, ROOT, ARCHIVES, M3_UNKNOWN_AP

AP_SLOTS = sorted(set(list(M3_UNKNOWN_AP) + [0x180, 0x1B0, 0x1C0, 0x1F0, 0x250]))
DP_SLOTS = [0x20, 0x38, 0x50, 0x68, 0x90, 0xA8, 0xC0, 0xD8, 0x100, 0x118, 0x130, 0x148, 0x160, 0x290, 0x350, 0x370, 0x5C0]

def worker(a):
    wid, n = a; res = {}; i = 0
    for name in ARCHIVES:
        fs = halon.Filesystem(os.path.join(PATCH, name))
        with open(fs.data.name, 'rb') as arc:
            stack = [fs.root]; files = []
            while stack:
                d = stack.pop(); files.extend(d.files.values()); stack.extend(d.dirs.values())
            files.sort(key=lambda f: f.path)
            for f in files:
                if not f.name.lower().endswith('.m3'): continue
                i += 1
                if i % n != wid: continue
                idx, _ = fs.data.blocks[f.sha1]; off, bs = fs.data.fs[idx]; arc.seek(off)
                b = inflate(f, arc.read(bs))
                if b[:4] != b'LDOM': continue
                for kind, slots in (('AP', AP_SLOTS), ('DP', DP_SLOTS)):
                    for s in slots:
                        c = struct.unpack_from('<Q', b, s)[0]
                        r = res.setdefault('%s%03X' % (kind, s), {'models': 0, 'total': 0, 'max': 0, 'example': None})
                        if c:
                            r['models'] += 1; r['total'] += c
                            if c > r['max']: r['max'] = c; r['example'] = f.path
                res.setdefault('_models', {'n': 0})['n'] += 1
    return res

if __name__ == '__main__':
    mp.freeze_support(); n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p: parts = p.map(worker, [(w, n) for w in range(n)])
    tot = {}
    for part in parts:
        for k, v in part.items():
            t = tot.setdefault(k, {'models': 0, 'total': 0, 'max': 0, 'example': None, 'n': 0})
            if k == '_models': t['n'] += v['n']; continue
            t['models'] += v['models']; t['total'] += v['total']
            if v['max'] > t['max']: t['max'] = v['max']; t['example'] = v['example']
    json.dump(tot, open(os.path.join(ROOT, 'docs', 'm3_header_survey.json'), 'w'), indent=1)
    N = tot['_models']['n']
    print('models', N)
    for k in sorted(k for k in tot if k != '_models'):
        v = tot[k]; print('%-6s non-empty in %6d (%5.1f%%)  total elems %9d  max %6d  e.g. %s' % (k, v['models'], 100.0 * v['models'] / N, v['total'], v['max'], (v['example'] or '')[-50:]))
