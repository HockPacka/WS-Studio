#!/usr/bin/env python3
"""Validate the material layer structure (description size 0x128) on every .m3; compares with the old 0x140 assumption."""
import collections, json, multiprocessing as mp, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon')); sys.path.insert(0, os.path.join(HERE, 'blender_addon', 'wildstar_m3'))
import halon
from validate_formats import inflate, a16, PATCH, ROOT, ARCHIVES

def check(b, st):
    tc = struct.unpack_from('<Q', b, 0x1C0)[0]
    mc, mo = struct.unpack_from('<QQ', b, 0x1F0); ma = mo + 0x630; db = a16(ma + mc * 0x30)
    for k in range(mc):
        r = ma + k * 0x30
        dc, do = struct.unpack_from('<QQ', b, r + 0x20)
        st['materials'] += 1; st['layers%d' % dc] += 1
        for stride, tag in ((0x128, 's128'), (0x140, 's140')):
            for j in range(dc):
                p = do + db + j * stride
                if p + stride > len(b): st[tag + '_oob'] += 1; continue
                t0, t1 = struct.unpack_from('<2H', b, p)
                for t in (t0, t1):
                    st[tag + ('_tex_ok' if (t < tc or t == 0xFFFF) else '_tex_bad')] += 1
                if tag == 's128':
                    kl = struct.unpack_from('<I', b, p + 0x120)[0]
                    st['class%d' % kl if kl < 8 else 'class_other'] += 1
                    if j > 0: st['layer_gt0_checked'] += 1

def worker(a):
    wid, n = a; st = collections.Counter(); i = 0
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
                try: check(inflate(f, arc.read(bs)), st)
                except Exception as ex: st['error:' + type(ex).__name__] += 1
    return st

if __name__ == '__main__':
    mp.freeze_support(); n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p: parts = p.map(worker, [(w, n) for w in range(n)])
    t = collections.Counter()
    for x in parts: t.update(x)
    json.dump(t, open(os.path.join(ROOT, 'docs', 'm3_material_validation.json'), 'w'), indent=1)
    for k, v in sorted(t.items()): print('%-20s %d' % (k, v))
