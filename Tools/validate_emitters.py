#!/usr/bin/env python3
"""Validate the emitter template structure on every .m3: DP positions, offsets, and chain consistency."""
import collections, json, multiprocessing as mp, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon')); sys.path.insert(0, os.path.join(HERE, 'blender_addon', 'wildstar_m3'))
import halon, emitter
from validate_formats import inflate, a16, PATCH, ROOT, ARCHIVES

def check(b, st):
    c, off = struct.unpack_from('<QQ', b, 0x2F8)
    if not c: return
    st['models'] += 1
    addr = off + 0x630; base = a16(addr + c * 0xA0); size = len(b)
    ems = emitter.read_emitters(b)
    nb_bones = struct.unpack_from('<Q', b, 0x180)[0]; ntex = struct.unpack_from('<Q', b, 0x1C0)[0]
    # element nested starts to compute chain
    starts = []
    for e in ems:
        s = []
        for p, (cc, keys, raw) in zip((0x20, 0x38, 0x50), e.tracks):
            pass
        ea = addr + e.index * 0xA0
        for p in (0x38, 0x50):
            cc, ko, vo = struct.unpack_from('<QQQ', b, ea + p)
            if cc: s += [ko, vo]
        starts.append(s)
    for e in ems:
        st['emitters'] += 1; st['type%d' % e.type] += 1
        st['bone_in_range' if e.bone < nb_bones else 'bone_out_of_range'] += 1
        if e.type == 0 and e.texture_ids:
            for tid in e.texture_ids:
                if tid != 0xFFFF:
                    st['tex_ok' if tid < ntex else 'tex_bad'] += 1
        if not e.valid:
            st['invalid:' + ','.join(e.problems)] += 1
        if e.type not in emitter.STRUCT_SIZE or e.template_offset >= 1 << 40:
            st['no_template'] += 1; continue
        t = base + e.template_offset; S = emitter.STRUCT_SIZE[e.type]; nb = t + S
        ok = e.valid and len(e.props) >= (emitter.TAIL_UNION_FIRST if e.type == 0 else len(emitter.DP_POS[1])); end = 0
        for pr in e.props:
            cc = pr.count
            ea = t + pr.pos
            cnt, ko, vo = struct.unpack_from('<QQQ', b, ea)
            if cc == 0:
                if ko or vo: ok = False
                continue
            if not (ko % 16 == 0 and vo % 16 == 0 and vo - ko == a16(4 * cc) and ko >= 0x10 and nb + vo + 2 <= size): ok = False; break
            end = max(end, vo)
        st['struct_ok' if ok else 'struct_bad'] += 1
        # constant-key convention
        if ok:
            const = sum(1 for pr in e.props if pr.count == 1)
            st['const_props'] += const; st['props'] += sum(1 for pr in e.props if pr.count)
    return

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
    json.dump(t, open(os.path.join(ROOT, 'docs', 'm3_emitter_validation.json'), 'w'), indent=1)
    for k, v in sorted(t.items()): print('%-18s %d' % (k, v))
