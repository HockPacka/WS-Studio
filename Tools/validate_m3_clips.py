#!/usr/bin/env python3
"""Verify the M3 clip (sequence) table: header array @0x010, count x 0x70-byte records, relative to 0x630.
Record: u16 animationId, u16 variant, u16 u04, u16 u06, u16 blendIn(ms), u16 blendOut(ms), u32 startMs, u32 endMs,
        f32 u14 (speed?), u32[2] 0, vec4 boundsMin, vec4 boundsMax (x2 copies), pad."""
import collections, json, multiprocessing as mp, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon
from validate_formats import inflate, a16, PATCH, ROOT, ARCHIVES

def check(b, size):
    st = collections.Counter()
    if b[:4] != b'LDOM': return st
    c, o = struct.unpack_from('<QQ', b, 0x10)
    st['models'] += 1
    if not c: st['models_no_clips'] += 1; return st
    a = o + 0x630
    if a + c * 0x70 > size: st['out_of_bounds'] += 1; return st
    bc, bo = struct.unpack_from('<QQ', b, 0x180); ba = bo + 0x630; BB = a16(ba + bc * 0x160)
    T = set()
    for i in range(bc):
        for j in range(8):
            n, k, v = struct.unpack_from('<QQQ', b, ba + i * 0x160 + 0x10 + j * 24)
            if n: T.update(struct.unpack_from('<%dI' % n, b, k + BB))
    tmax = max(T) if T else 0
    st['models_with_clips'] += 1
    anim = bool(T)
    prev = -1; sorted_ok = True
    for i in range(c):
        r = a + i * 0x70
        aid, var, _, _, bi, bo_, s, e = struct.unpack_from('<6H2I', b, r)
        st['clips'] += 1
        if anim: st['clips_in_animated_models'] += 1
        if s < e: st['start_lt_end'] += 1
        if anim and e <= tmax: st['end_within_timeline'] += 1
        if anim and s in T: st['start_is_keyframe'] += 1
        if aid < prev: sorted_ok = False
        prev = aid
        st['bb_dup'] += b[r + 0x20:r + 0x40] == b[r + 0x40:r + 0x60]
    st['ids_sorted' if sorted_ok else 'ids_unsorted'] += 1
    return st

def worker(a):
    wid, n = a; tot = collections.Counter(); i = 0
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
                try: tot.update(check(inflate(f, arc.read(bs)), f.uncompressed_size))
                except Exception as ex: tot['error:' + type(ex).__name__] += 1
    return tot

if __name__ == '__main__':
    mp.freeze_support(); n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p: parts = p.map(worker, [(w, n) for w in range(n)])
    t = collections.Counter()
    for x in parts: t.update(x)
    json.dump(t, open(os.path.join(ROOT, 'docs', 'm3_clip_validation.json'), 'w'), indent=1)
    for k, v in sorted(t.items()): print('%-22s %d' % (k, v))
