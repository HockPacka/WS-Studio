#!/usr/bin/env python3
"""Join M3 clip animation ids with DB/ModelSequence.tbl names -> docs/animation_ids.csv"""
import collections, csv, multiprocessing as mp, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon
from validate_formats import inflate, PATCH, ROOT, ARCHIVES

def worker(a):
    wid, n = a; ids = collections.Counter(); models = collections.Counter(); i = 0
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
                c, o = struct.unpack_from('<QQ', b, 0x10)
                seen = set()
                for k in range(c):
                    aid = struct.unpack_from('<H', b, o + 0x630 + k * 0x70)[0]
                    ids[aid] += 1; seen.add(aid)
                for aid in seen: models[aid] += 1
    return ids, models

if __name__ == '__main__':
    mp.freeze_support(); n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p: parts = p.map(worker, [(w, n) for w in range(n)])
    ids = collections.Counter(); models = collections.Counter()
    for a, m in parts: ids.update(a); models.update(m)
    names = {}
    with open(os.path.join(ROOT, 'extracted', 'tables_csv', 'ModelSequence.csv'), encoding='utf-8') as fh:
        for r in csv.DictReader(fh): names[int(r['ID'])] = (r['description'], int(r['FallBackID']), int(r['flag']))
    out = os.path.join(ROOT, 'docs', 'animation_ids.csv')
    with open(out, 'w', newline='', encoding='utf-8') as fh:
        w = csv.writer(fh); w.writerow(['id', 'name', 'fallback_id', 'flag', 'clips', 'models'])
        for aid in sorted(ids, key=lambda x: -models[x]):
            nm = names.get(aid, ('', 0, 0)); w.writerow([aid, nm[0], nm[1], nm[2], ids[aid], models[aid]])
    named = sum(ids[a] for a in ids if a in names)
    print('distinct ids %d, named %d; clips %d, named clips %d (%.2f%%)' % (len(ids), sum(1 for a in ids if a in names), sum(ids.values()), named, 100 * named / sum(ids.values())))
    print('unnamed ids:', sorted(a for a in ids if a not in names)[:30])
