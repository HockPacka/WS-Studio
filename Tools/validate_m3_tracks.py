#!/usr/bin/env python3
"""Verify the decoded M3 bone animation track layout against every .m3 in the archives.

Bone (0x160 bytes) track DPointers {count, keyOff, valOff} at bone+0x10 + j*24, j=0..7, all relative to
align16(boneArray.end). Keys: uint32 milliseconds. Values follow the keys (16-byte aligned).
Stride per track: j 0-3 -> 6 (3x half), 4-5 -> 8 (4x int16 quaternion, 16384 = 1.0), 6-7 -> 12 (3x float).
"""
import collections, json, multiprocessing as mp, os, struct, sys, math
HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE); sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon
from validate_formats import inflate, a16, PATCH, ROOT, ARCHIVES

STRIDE = (6, 6, 6, 6, 8, 8, 12, 12)

def check(b, size):
    st = collections.Counter()
    if b[:4] != b'LDOM': return st
    bc, bo = struct.unpack_from('<QQ', b, 0x180)
    ba = bo + 0x630
    BB = a16(ba + bc * 0x160)
    st['models'] += 1
    st['bones'] += bc
    has = False
    for i in range(bc):
        o = ba + i * 0x160
        for j in range(8):
            c, k, v = struct.unpack_from('<QQQ', b, o + 0x10 + j * 24)
            if not c: continue
            has = True
            st['tracks'] += 1
            ka, va = k + BB, v + BB
            ok = ka + 4 * c <= size and va + STRIDE[j] * c <= size
            if ok:
                ok = (va == a16(ka + 4 * c))
                st['val_follows_keys'] += ok
                if not ok:
                    st['val_not_after_keys'] += 1
                keys = struct.unpack_from('<%dI' % c, b, ka)
                if all(keys[n] <= keys[n + 1] for n in range(len(keys) - 1)): st['keys_sorted'] += 1
                else: st['keys_unsorted'] += 1
                if j in (4, 5):
                    q = struct.unpack_from('<4h', b, va); n = math.sqrt(sum(x * x for x in q)) / 16384
                    st['quat_unit' if 0.95 < n < 1.05 else 'quat_not_unit'] += 1
            else:
                st['out_of_bounds'] += 1
            st['tracks_j%d' % j] += 1
    st['models_with_anim' if has else 'models_static'] += 1
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
                idx, _ = fs.data.blocks[f.sha1]; off, bs = fs.data.fs[idx]
                arc.seek(off)
                try: tot.update(check(inflate(f, arc.read(bs)), f.uncompressed_size))
                except Exception as e: tot['error:' + type(e).__name__] += 1
    return tot

if __name__ == '__main__':
    mp.freeze_support(); n = max(1, (os.cpu_count() or 4) - 2)
    with mp.Pool(n) as p: parts = p.map(worker, [(w, n) for w in range(n)])
    t = collections.Counter()
    for x in parts: t.update(x)
    json.dump(t, open(os.path.join(ROOT, 'docs', 'm3_track_validation.json'), 'w'), indent=1)
    for k, v in sorted(t.items()): print('%-22s %d' % (k, v))
