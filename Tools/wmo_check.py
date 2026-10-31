"""Validates the WMO files written by i3_wmo_cli (docs/i3_dgn_format.md) the way the client reads them (CMapObj::Load, CMapObjGroup::CreateDataPointers):
chunk chain of the root file, group files, index / batch / BSP ranges.

usage: wmo_check.py <prefix>                      checks <prefix>.wmo and <prefix>_NNN.wmo
       wmo_check.py --all <ClientData dir> <out dir> [filter]   builds (i3_wmo_cli) and checks every FEDI .i3 below Art, prints a summary
       wmo_check.py --preview <prefix> <out.png>  wireframe preview of all groups (3 views)
"""
import os
import struct
import subprocess
import sys

ROOT_ORDER = ['MOHD', 'MOTX', 'MOMT', 'MOGN', 'MOGI', 'MOSB', 'MOPV', 'MOPT', 'MOPR', 'MOVV', 'MOVB', 'MOLT', 'MODS', 'MODN', 'MODD', 'MFOG']


def chunks(b, start=0):
    o = start
    out = []
    while o < len(b):
        if o + 8 > len(b):
            raise ValueError('truncated chunk header at %#x' % o)
        tok = b[o:o + 4][::-1].decode('latin-1')
        size = struct.unpack_from('<I', b, o + 4)[0]
        if o + 8 + size > len(b):
            raise ValueError('chunk %s beyond file' % tok)
        out.append((tok, o + 8, size))
        o += 8 + size
    return out


def check_root(b):
    ch = chunks(b)
    if ch[0][0] != 'MVER' or struct.unpack_from('<I', b, ch[0][1])[0] != 17:
        raise ValueError('MVER')
    got = [c[0] for c in ch[1:]]
    if got != ROOT_ORDER:
        raise ValueError('chunk order %s' % got)
    d = {c[0]: c for c in ch}
    mohd = d['MOHD']
    nmat, ngrp = struct.unpack_from('<2I', b, mohd[1])
    if d['MOMT'][2] != 64 * nmat:
        raise ValueError('MOMT size')
    if d['MOGI'][2] != 32 * ngrp:
        raise ValueError('MOGI size')
    # Texture offsets and the private WildStar material extension. Stock WMO
    # materials keep the original zero values in texture2 / color2 / flags2.
    motx = d['MOTX']
    marked = normals = 0

    def texture_offset(off, label, allow_empty=False):
        if off >= motx[2] or (not allow_empty and not b[motx[1] + off]):
            raise ValueError(label)
        end = b.find(b'\0', motx[1] + off, motx[1] + motx[2])
        if end < 0:
            raise ValueError(label + ' terminator')

    for i in range(nmat):
        o = d['MOMT'][1] + 64 * i
        off, off2 = struct.unpack_from('<I8xI', b, o + 12)
        texture_offset(off, 'texture offset', allow_empty=True)
        packed, flags2 = struct.unpack_from('<2I', b, o + 0x28)
        if not flags2 & 0x80000000:
            if off2 or packed or flags2:
                raise ValueError('unmarked material extension %d' % i)
            continue
        if flags2 & 0x7FFFFFFE or struct.unpack_from('<I', b, o + 4)[0] != 0 or packed >> 24 != 0xFF:
            raise ValueError('WildStar material fields %d' % i)
        marked += 1
        if flags2 & 1:
            texture_offset(off2, 'normal texture offset')
            normals += 1
        elif off2:
            raise ValueError('normal map without marker %d' % i)
    global WILDSTAR_MATERIALS, WILDSTAR_NORMALS
    WILDSTAR_MATERIALS = marked
    WILDSTAR_NORMALS = normals
    nd = struct.unpack_from('<I', b, mohd[1] + 0x14)[0]
    ns = struct.unpack_from('<I', b, mohd[1] + 0x18)[0]
    if d['MODD'][2] != 0x28 * nd or d['MODS'][2] != 32 * ns:
        raise ValueError('MODD / MODS size')
    for i in range(nd):
        o = d['MODD'][1] + 0x28 * i
        if (struct.unpack_from('<I', b, o)[0] & 0xFFFFFF) >= max(1, d['MODN'][2]):
            raise ValueError('doodad name offset')
    for i in range(ns):
        start, count = struct.unpack_from('<II', b, d['MODS'][1] + 32 * i + 20)
        if start + count > nd:
            raise ValueError('doodad set range')
    np_ = struct.unpack_from('<I', b, mohd[1] + 8)[0]
    if d['MOPT'][2] != 20 * np_ or d['MOPR'][2] % 8:
        raise ValueError('MOPT / MOPR size')
    nv = d['MOPV'][2] // 12
    for i in range(np_):
        start, count = struct.unpack_from('<HH', b, d['MOPT'][1] + 20 * i)
        if start + count > nv or count < 3:
            raise ValueError('portal vertex range')
    nr = d['MOPR'][2] // 8
    for i in range(nr):
        pi, gi, side = struct.unpack_from('<HHh', b, d['MOPR'][1] + 8 * i)
        if pi >= np_ or gi >= ngrp or side not in (-1, 1):
            raise ValueError('portal reference')
    nl = struct.unpack_from('<I', b, mohd[1] + 0x0C)[0]
    if d['MOLT'][2] != 48 * nl:
        raise ValueError('MOLT size')
    for i in range(nl):
        o = d['MOLT'][1] + 48 * i
        light_type, atten, doodad_set = struct.unpack_from('<3B', b, o)
        intensity = struct.unpack_from('<f', b, o + 0x14)[0]
        atten_start, atten_end = struct.unpack_from('<2f', b, o + 0x28)
        if light_type not in (0, 1) or not atten or doodad_set >= ns or intensity < 0 or atten_end <= atten_start:
            raise ValueError('light %d values' % i)
    global DOODADS, PORTAL_REFS, GROUPS, LIGHTS
    DOODADS = nd
    PORTAL_REFS = nr
    GROUPS = ngrp
    LIGHTS = nl
    return nmat, ngrp


DOODADS = 0
PORTAL_REFS = 0
GROUPS = 0
LIGHTS = 0
INTERIOR = 0


def check_group(b, nmat):
    ch = chunks(b)
    if ch[0][0] != 'MVER' or ch[1][0] != 'MOGP':
        raise ValueError('group header')
    hdr = ch[1][1]
    flags = struct.unpack_from('<I', b, hdr + 8)[0]
    pstart, pcount = struct.unpack_from('<2H', b, hdr + 0x24)
    if pstart + pcount > PORTAL_REFS:
        raise ValueError('group portal range')
    global INTERIOR
    if flags & 0x2000:
        INTERIOR += 1
    nint, next_ = struct.unpack_from('<2H', b, hdr + 0x2A)
    sub = chunks(b[:ch[1][1] + ch[1][2]], hdr + 0x44)
    names = [s[0] for s in sub]
    want = ['MOPY', 'MOVI', 'MOVT', 'MONR', 'MOTV', 'MOBA'] + (['MOLR'] if flags & 0x200 else []) + (['MODR'] if flags & 0x800 else []) + (['MOBN', 'MOBR'] if flags & 1 else [])
    if flags & 0x4:
        want.append('MOCV')
    if flags & 0x2000000:
        want.append('MOTV')
    if names != want:
        raise ValueError('subchunks %s' % names)
    d = {s[0]: s for s in sub}
    nv = d['MOVT'][2] // 12
    ni = d['MOVI'][2] // 2
    uv_chunks = [s for s in sub if s[0] == 'MOTV']
    if d['MONR'][2] != d['MOVT'][2] or any(s[2] // 8 != nv for s in uv_chunks) or d['MOPY'][2] != 2 * (ni // 3) or nv > 65535:
        raise ValueError('array sizes')
    if 'MOCV' in d and d['MOCV'][2] != nv * 4:
        raise ValueError('vertex colour size')
    idx = struct.unpack_from('<%dH' % ni, b, d['MOVI'][1])
    if max(idx) >= nv:
        raise ValueError('index >= vertex count')
    nb = d['MOBA'][2] // 24
    if nb != next_ + nint:
        raise ValueError('batch count')
    covered = 0
    for k in range(nb):
        r = d['MOBA'][1] + 24 * k
        istart, icount, vs, ve, fl, mat = struct.unpack_from('<IHHHBB', b, r + 12)
        if istart + icount > ni or ve >= nv or mat >= nmat:
            raise ValueError('batch %d range' % k)
        if any(i < vs or i > ve for i in idx[istart:istart + icount]):
            raise ValueError('batch %d vertex range' % k)
        covered += icount
    mopy = d['MOPY'][1]
    for t in range(ni // 3):
        if b[mopy + 2 * t + 1] >= nmat:
            raise ValueError('poly material')
    if 'MOLR' in d:
        for ref in struct.unpack_from('<%dH' % (d['MOLR'][2] // 2), b, d['MOLR'][1]):
            if ref >= LIGHTS:
                raise ValueError('light ref')
    if 'MODR' in d:
        for ref in struct.unpack_from('<%dH' % (d['MODR'][2] // 2), b, d['MODR'][1]):
            if ref >= DOODADS:
                raise ValueError('doodad ref')
    nn = d['MOBN'][2] // 16 if 'MOBN' in d else 0
    nr = d['MOBR'][2] // 2 if 'MOBR' in d else 0
    for k in range(nn):
        f, neg, pos, nf, fs, dist = struct.unpack_from('<HhhHIf', b, d['MOBN'][1] + 16 * k)
        if f & 4:
            if fs + nf > nr:
                raise ValueError('bsp leaf faces')
        elif not (0 <= neg < nn and 0 <= pos < nn):
            raise ValueError('bsp child')
    for f in struct.unpack_from('<%dH' % nr, b, d['MOBR'][1]):
        if f >= ni // 3:
            raise ValueError('bsp face')
    return nv, ni // 3, nb, covered // 3


def check(prefix):
    root = open(prefix + '.wmo', 'rb').read()
    nmat, ngrp = check_root(root)
    tot = [0, 0, 0]
    for g in range(ngrp):
        r = check_group(open('%s_%03d.wmo' % (prefix, g), 'rb').read(), nmat)
        tot[0] += r[0]
        tot[1] += r[1]
        tot[2] += r[2]
    return nmat, ngrp, tot


def load_preview(prefix):
    import numpy as np
    root = open(prefix + '.wmo', 'rb').read()
    nmat, ngrp = check_root(root)
    verts, tris = [], []
    base = 0
    for g in range(ngrp):
        b = open('%s_%03d.wmo' % (prefix, g), 'rb').read()
        ch = chunks(b)
        sub = chunks(b[:ch[1][1] + ch[1][2]], ch[1][1] + 0x44)
        d = {s[0]: s for s in sub}
        nv = d['MOVT'][2] // 12
        v = np.frombuffer(b, '<f4', nv * 3, d['MOVT'][1]).reshape(nv, 3)
        ni = d['MOVI'][2] // 2
        i = np.frombuffer(b, '<u2', ni, d['MOVI'][1]).reshape(-1, 3).astype(int) + base
        verts.append(v)
        tris.append(i)
        base += nv
    return np.concatenate(verts), np.concatenate(tris)


def main():
    if len(sys.argv) >= 4 and sys.argv[1] == '--preview':
        import numpy as np
        from PIL import Image, ImageDraw
        v, t = load_preview(sys.argv[2])
        W = 500
        img = Image.new('RGB', (3 * W, W), 'white')
        dr = ImageDraw.Draw(img)
        for k, (i, j) in enumerate(((1, 0), (1, 2), (0, 2))):
            a = v[:, [i, j]]
            mn, mx = a.min(0), a.max(0)
            sc = (W - 20) / max(mx - mn)
            q = (a - mn) * sc + 10
            q[:, 1] = W - q[:, 1]
            for tri in t[::2]:
                dr.polygon([(q[x, 0] + k * W, q[x, 1]) for x in tri], outline=(0, 0, 0))
        img.save(sys.argv[3])
        return
    if len(sys.argv) >= 4 and sys.argv[1] == '--all':
        client, out = sys.argv[2], sys.argv[3]
        flt = sys.argv[4].lower() if len(sys.argv) > 4 else ''
        exe = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'build_m3test', 'i3_wmo_cli.exe')
        os.makedirs(out, exist_ok=True)
        n = ok = fail = 0
        errs = {}
        totals = [0, 0, 0, 0, 0]
        for dp, _, fs in os.walk(os.path.join(client, 'Art')):
            for f in fs:
                if not f.endswith('.i3'):
                    continue
                full = os.path.join(dp, f)
                if open(full, 'rb').read(4) != b'FEDI' or (flt and flt not in full.lower()):
                    continue
                rel = os.path.relpath(full, client)
                n += 1
                prefix = os.path.join(out, 'm%d' % n)
                r = subprocess.run([exe, client.rstrip('\\/') + '/', rel, prefix], capture_output=True, text=True)
                if r.returncode:
                    fail += 1
                    errs.setdefault(r.stderr.strip(), []).append(rel)
                    continue
                try:
                    nmat, ngrp, tot = check(prefix)
                    ok += 1
                    totals[0] += ngrp
                    totals[1] += tot[1]
                    totals[2] += nmat
                    totals[3] += WILDSTAR_MATERIALS
                    totals[4] += WILDSTAR_NORMALS
                except Exception as e:  # noqa: BLE001
                    fail += 1
                    errs.setdefault('check: %s' % e, []).append(rel)
                for x in os.listdir(out):
                    if x.startswith('m%d' % n + '.') or x.startswith('m%d_' % n):
                        os.remove(os.path.join(out, x))
        print('models %d ok %d failed %d, groups %d, triangles %d, materials %d (WildStar %d, normal maps %d)' % (n, ok, fail, *totals))
        for e, l in errs.items():
            print(e, len(l), l[:2])
        return
    nmat, ngrp, tot = check(sys.argv[1])
    print('materials %d (WildStar %d, normal maps %d) groups %d (interior %d, portal refs %d) vertices %d triangles %d batches %d' % (nmat, WILDSTAR_MATERIALS, WILDSTAR_NORMALS, ngrp, INTERIOR, PORTAL_REFS, tot[0], tot[1], tot[2]))


if __name__ == '__main__':
    main()
