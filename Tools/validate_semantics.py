#!/usr/bin/env python3
"""Cross-reference checks for the rare M3 blocks (do the decoded index fields really point into the arrays we think they do?).
usage: validate_semantics.py [every-nth-file]   ->  docs/m3_blocks_semantics.json"""
import collections
import glob
import json
import multiprocessing as mp
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import validate_blocks as vb  # noqa: E402

H = vb.H


def work(path):
    b = open(path, 'rb').read()
    st = collections.Counter()
    if b[:4] != b'LDOM':
        return st
    cnt = lambda s: struct.unpack_from('<Q', b, s)[0]  # noqa: E731
    nb, nclip, nsnd, ncam, nlight, n598 = cnt(0x180), cnt(0x10), cnt(0x2C8), cnt(0x328), cnt(0x318), cnt(0x598)

    def ok(name, cond):
        st[name + (':ok' if cond else ':bad')] += 1

    # 0x2B8: bone + start/stop sound event index pairs
    c, o = struct.unpack_from('<QQ', b, 0x2B8)
    if c and vb.check_array(b, o + H, c, 0x28, vb.SPEC[0x2B8][1], True, collections.Counter(), 'x'):
        base = vb.a16(o + H + c * 0x28)
        for k in range(c):
            e = o + H + k * 0x28
            ok('2B8.bone', struct.unpack_from('<I', b, e)[0] < nb)
            n, off = struct.unpack_from('<QQ', b, e + 0x18)
            for r in range(n):
                lo, hi = struct.unpack_from('<HH', b, base + off + r * 0x20)
                ok('2B8.rec_lo<sounds', lo < nsnd)
                ok('2B8.rec_hi<sounds', hi < nsnd)
    # 0x308 / 0x328 / 0x598 bone indices, 0x338 camera lookup, 0x5A8 face lookup
    for slot, es, off, name in ((0x308, 0x50, 0, '308.bone'), (0x328, 0x38, 2, '328.bone'), (0x598, 0x4C, 0, '598.bone'), (0x570, 0x20, 0, '570.u16_0<bones')):
        c, o = struct.unpack_from('<QQ', b, slot)
        for k in range(c if c < 1 << 20 and o + H + c * es <= len(b) else 0):
            ok(name, struct.unpack_from('<H', b, o + H + k * es + off)[0] < nb)
    c, o = struct.unpack_from('<QQ', b, 0x338)
    if c and o + H + c * 2 <= len(b):
        for v in struct.unpack_from('<%dH' % c, b, o + H):
            if v != 0xFFFF:
                ok('338.camera_index', v < ncam)
        st['338.len%d' % c] += 1
    c, o = struct.unpack_from('<QQ', b, 0x5A8)
    if c and o + H + c * 2 <= len(b):
        for v in struct.unpack_from('<%dH' % c, b, o + H):
            if v != 0xFFFF:
                ok('5A8.face_range_index', v < n598)
    # 0x4A0: (animation id, variant) must exist in the clip table
    c, o = struct.unpack_from('<QQ', b, 0x4A0)
    if c and o + H + c * 4 <= len(b):
        ca, oa = struct.unpack_from('<QQ', b, 0x10)
        clips = {struct.unpack_from('<HH', b, oa + H + i * 0x70)[:2] for i in range(ca)} if oa + H + ca * 0x70 <= len(b) else set()
        for i in range(c):
            ok('4A0.in_clips', struct.unpack_from('<HH', b, o + H + i * 4) in clips)
    # 0x490 collision kd-tree
    c, o = struct.unpack_from('<QQ', b, 0x490)
    if c and o + H + c * 0x40 <= len(b):
        base = vb.a16(o + H + c * 0x40)
        for k in range(c):
            e = o + H + k * 0x40
            (nh, oh), (nv, ov), (ni, oi), (nn, on) = [struct.unpack_from('<QQ', b, e + q) for q in (0, 0x10, 0x20, 0x30)]
            if not nv:
                st['490.empty'] += 1
                continue
            recs = [struct.unpack_from('<IIIHH', b, base + oh + i * 16) for i in range(nh)]
            ok('490.hdr_contiguous', all(r[1] == sum(q[2] for q in recs[:i]) for i, r in enumerate(recs)) and sum(r[2] for r in recs) == ni)
            ok('490.hdr_firstNode<nodes', all(r[0] < nn for r in recs))
            nmat = cnt(0x1F0)
            ok('490.hdr_u16a<materials|ffff', all(r[3] == 0xFFFF or r[3] < nmat for r in recs))
            groups = set()
            gc, go = struct.unpack_from('<QQ', b, 0x250)
            for g in range(gc):
                gp = go + H + g * 0xC8
                mc, mo = struct.unpack_from('<QQ', b, gp + 0x80)
                mb = vb.a16(go + H + gc * 0xC8)
                for m in range(mc):
                    groups.add(b[mb + mo + m * 0x70 + 0x1E])
            ok('490.hdr_u16b_in_mesh_groups', all(r[4] in groups for r in recs))
            idx = struct.unpack_from('<%dI' % ni, b, base + oi) if ni else ()
            ok('490.index<verts', all(x < nv for x in idx))
            ok('490.index%3', ni % 3 == 0)
            nodes = [struct.unpack_from('<f4I', b, base + on + i * 20) for i in range(nn)]
            ok('490.node_children', all(n[3] < nn and n[4] < nn for n in nodes))
            ok('490.node_range', all(n[1] + n[2] <= ni for n in nodes))
    # 0x510/0x520/0x530 hull
    nv, ov = struct.unpack_from('<QQ', b, 0x510)
    n2, o2 = struct.unpack_from('<QQ', b, 0x520)
    n3, o3 = struct.unpack_from('<QQ', b, 0x530)
    if nv:
        ok('510.520.idx<verts', o2 + H + n2 * 4 <= len(b) and all(x < nv for x in struct.unpack_from('<%dI' % n2, b, o2 + H)))
        if n3:
            ok('510.530.idx<verts', o3 + H + n3 * 4 <= len(b) and all(x < nv for x in struct.unpack_from('<%dI' % n3, b, o3 + H)))
    return st


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    files = sorted(glob.glob(os.path.join(vb.ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
    tot = collections.Counter()
    with mp.Pool(max(1, (os.cpu_count() or 4) - 2)) as p:
        for st in p.imap_unordered(work, files, chunksize=64):
            tot.update(st)
    for k in sorted(tot):
        print('%-28s %d' % (k, tot[k]))
    json.dump(dict(tot), open(os.path.join(vb.ROOT, 'docs', 'm3_blocks_semantics.json'), 'w'), indent=1)
