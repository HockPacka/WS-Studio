#!/usr/bin/env python3
"""Validate the documented WildStar formats (tex, tbl, bin, area, m3) against EVERY file in the archives.

Reads straight from the archives (no extracted copy needed), runs in parallel and writes docs/validation_report.json.
A file is 'ok' when the structure from the NexusVault binary templates is consistent (all offsets/sizes/relations hold),
'partial' when it parses but contains parts the template cannot describe, 'fail' otherwise.
Also reports byte coverage: how many bytes of each file are covered by structures we understand.
"""
import collections
import json
import lzma
import multiprocessing as mp
import os
import struct
import sys
import time
import zlib

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, 'Halon'))
import halon  # noqa: E402

ROOT = os.path.dirname(HERE)
PATCH = os.path.join(ROOT, 'WildStar', 'Patch')
ARCHIVES = ('ClientData', 'ClientDataEN', 'ClientDataDE')
CHECKED = ('.tex', '.m3', '.area', '.tbl', '.bin')


def inflate(f, raw, limit=0):
    if f.compression == 1:
        return raw[:limit] if limit else raw
    if f.compression == 3:
        d = zlib.decompressobj(-15)
    elif f.compression == 5:
        raw = raw[:5] + struct.pack('<Q', f.uncompressed_size) + raw[5:]
        d = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE)
    else:
        raise ValueError('compression %d' % f.compression)
    return d.decompress(raw, limit) if limit else d.decompress(raw)


def a16(x):
    return (x + 15) & ~15


class Bad(Exception):
    pass


def need(cond, why):
    if not cond:
        raise Bad(why)


# ----------------------------------------------------------------------------- tex
def check_tex(b, size):
    need(len(b) >= 112, 'short header')
    h = struct.unpack_from('<10I', b, 0)
    sig, ver, w, hgt, depth, sides, mips, fmt, is_jpg, jfmt = h
    need(sig == 0x00584647 or b[:3] == b'GFX' or b[1:4] == b'GFX' or sig == 0x00474658, 'signature')
    need(ver == 3, 'version %d' % ver)
    mip_count = struct.unpack_from('<I', b, 52)[0]
    sizes = struct.unpack_from('<13I', b, 56)
    need(mip_count <= 13, 'mip count')
    if is_jpg:
        need(112 + sum(sizes[:mip_count]) == size, 'jpg size mismatch')
        return ('ok' if jfmt in (0, 1, 2) else 'partial'), {'kind': 'jpg%d' % jfmt}, size
    bpp = {0: 4, 1: 4, 5: 3, 6: 1}
    need(fmt in (0, 1, 5, 6, 13, 14, 15, 18), 'unknown format %d' % fmt)
    total = 0
    for k in range(mips):
        a, c = max(1, w >> k), max(1, hgt >> k)
        if fmt in (13, 14, 15):
            total += max(1, (a + 3) // 4) * max(1, (c + 3) // 4) * (8 if fmt == 13 else 16)
        elif fmt in bpp:
            total += a * c * bpp[fmt]
    if fmt == 18:
        return 'partial', {'kind': 'fmt18'}, 112
    extra = size - 112 - total
    # exact, or exact * faces (cube/array), or small trailing footer
    mult = max(sides, 1) * max(depth, 1)
    if 0 <= extra < 128 or (extra >= 0 and total * mult == size - 112) or extra == total * (mult - 1) + extra % 128 and extra >= 0 and mult > 1:
        return 'ok', {'kind': 'fmt%d%s' % (fmt, '+footer' if 0 < extra < 128 else '')}, size
    return 'partial', {'kind': 'fmt%d?size' % fmt}, 112


# ----------------------------------------------------------------------------- bin
def check_bin(b, size):
    need(size >= 96, 'short header')
    sig, ver, lang, _unk = struct.unpack_from('<4I', b, 0)
    need(sig == 0x4C544558 or b[:4] == b'LTEX' or b[:4] == b'XETL', 'signature')
    (tl, to, sl, so, ll, lo, ec, eo, _u, to2) = struct.unpack_from('<10Q', b, 16)
    H = 96
    need(H + eo + ec * 8 <= size, 'entry table')
    for off, ln in ((to, tl), (so, sl), (lo, ll)):
        need(H + off + ln * 2 <= size, 'name string')
    base = H + to2
    for i in range(ec):
        _id, off = struct.unpack_from('<II', b, H + eo + i * 8)
        p = base + off * 2
        need(p < size, 'text offset')
        # find terminator
        j = p
        while j + 1 < size and (b[j] or b[j + 1]):
            j += 2
        need(j + 1 < size, 'unterminated text')
    return 'ok', {'ver': ver, 'entries': ec}, size


# ----------------------------------------------------------------------------- tbl
TBL_TYPES = {3: 4, 4: 4, 11: 4, 20: 8, 130: 8}


def check_tbl(b, size):
    need(size >= 96, 'short header')
    sig, ver = struct.unpack_from('<II', b, 0)
    need(b[:4] in (b'LBTD', b'DTBL'), 'signature')
    (name_cnt, _u1, rec_size, field_cnt, field_off, rec_cnt, total_rec, rec_off, lk_cnt, lk_off, _pad) = struct.unpack_from('<11Q', b, 8)
    H = 96
    need(H + name_cnt * 2 <= size, 'table name')
    fp = H + field_off
    need(fp + field_cnt * 24 <= size, 'field table')
    types = []
    for i in range(field_cnt):
        name_n, _u, name_off, dtype, _p, _u2 = struct.unpack_from('<IIQHHI', b, fp + i * 24)
        types.append(dtype)
    unknown = [t for t in types if t not in TBL_TYPES]
    names_base = a16(fp + field_cnt * 24)
    for i in range(field_cnt):
        name_n, _u, name_off, *_ = struct.unpack_from('<IIQHHI', b, fp + i * 24)
        need(names_base + name_off + name_n * 2 <= size, 'field name')
    need(rec_size * rec_cnt <= total_rec, 'record size math')
    need(H + rec_off + total_rec <= size, 'record area')
    need(H + lk_off + lk_cnt * 4 <= size, 'lookup table')
    # per record layout check (first, last record + string pointers of all records for string cols)
    consumed = 0
    for t in types:
        if t not in TBL_TYPES:
            break
        if t == 130 and consumed % 8:
            consumed += 4
        consumed += TBL_TYPES[t]
    if not unknown:
        need(consumed <= rec_size and rec_size - consumed < 16, 'record layout %d vs %d' % (consumed, rec_size))
        str_cols = []
        pos = 0
        for t in types:
            if t == 130 and pos % 8:
                pos += 4
            if t == 130:
                str_cols.append(pos)
            pos += TBL_TYPES[t]
        for r in range(rec_cnt):
            rp = H + rec_off + r * rec_size
            for c in str_cols:
                (sp,) = struct.unpack_from('<Q', b, rp + c)
                q = H + rec_off + sp
                need(sp < total_rec and q + 2 <= size, 'string pointer')
    return ('partial' if unknown else 'ok'), {'fields': field_cnt, 'records': rec_cnt, 'unk_types': sorted(set(unknown))}, size


# ----------------------------------------------------------------------------- area
CHNK = 0x43484E4B
PROP_PKG = 0x50524F70
TRUC = 0x43555254
FLAG_SIZES = {0: 722, 1: 16, 2: 8450, 3: 8450, 4: 8450, 6: 64, 7: 16, 8: 4225, 13: 4624, 28: 16}


def check_area(b, size):
    need(size >= 8, 'short')
    need(b[:4] in (b'aera', b'AERA', b'area', b'AREA'), 'signature')
    pos = 8
    known_bytes = 8
    pkgs = collections.Counter()
    unknown_flags = collections.Counter()
    partial = False
    while pos + 8 <= size:
        sig, psz = struct.unpack_from('<II', b, pos)
        need(pos + 8 + psz <= size, 'package overflows')
        body = pos + 8
        end = body + psz
        pkgs[struct.pack('<I', sig).decode('ascii', 'replace')] += psz + 8
        if sig == CHNK:
            p = body
            while p < end:
                need(p + 8 <= end, 'chunk header')
                (v,) = struct.unpack_from('<I', b, p)
                csz, idx = v & 0xFFFFFF, v >> 24
                cend = p + 4 + csz
                need(cend <= end, 'chunk overflows')
                (flags,) = struct.unpack_from('<I', b, p + 4)
                q = p + 8
                chunk_known = True
                for bit in range(32):
                    if not flags & (1 << bit):
                        continue
                    n = FLAG_SIZES.get(bit)
                    if n is None:
                        unknown_flags[bit] += 1
                        chunk_known = False
                        break
                    q += n
                    need(q <= cend, 'flag block overflows')
                if chunk_known:
                    while q < cend:
                        need(q + 8 <= cend, 'subchunk header')
                        ssig, ssz = struct.unpack_from('<II', b, q)
                        need(q + 8 + ssz <= cend, 'subchunk overflows')
                        q += 8 + ssz
                    need(q == cend, 'subchunk misalignment')
                    known_bytes += csz + 4
                else:
                    partial = True
                p = cend
            known_bytes += 8
        elif sig in (PROP_PKG, 0x504F5270):
            (cnt,) = struct.unpack_from('<I', b, body)
            q = body + 4
            for _ in range(cnt):
                need(q + 0x68 <= end, 'prop header')
                ps, pe = struct.unpack_from('<II', b, q + 0x14)
                need(pe >= ps and (pe - ps) % 2 == 0, 'prop path')
                q += 0x68 + (pe - ps)
                need(q <= end, 'prop overflow')
            need(end - q == 16, 'prop trailer %d' % (end - q))
            known_bytes += psz + 8
        elif sig == TRUC:
            partial = True  # opaque in template
        else:
            partial = True
            pkgs['?unknown'] += 1
        pos = end
    need(pos == size, 'trailing bytes')
    return ('partial' if partial else 'ok'), {'pkgs': dict(pkgs), 'unk_flags': dict(unknown_flags)}, known_bytes


# ----------------------------------------------------------------------------- m3
HEADER_END = 0x630
M3_UNKNOWN_AP = {  # offset in header -> element size
    0x010: 1, 0x080: 1, 0x0F0: 1, 0x190: 1, 0x1A0: 1, 0x1D0: 2, 0x1E0: 0x98, 0x200: 4, 0x210: 2, 0x220: 0x46, 0x230: 4, 0x240: 0x70,
    0x260: 4, 0x270: 2, 0x280: 8, 0x2A8: 0x10, 0x2B8: 0x28, 0x2C8: 8, 0x2D8: 2, 0x2E8: 8, 0x2F8: 0xA0, 0x308: 0x50, 0x318: 0x190,
    0x328: 0x38, 0x338: 2, 0x490: 0x40, 0x4A0: 4, 0x510: 0x10, 0x520: 4, 0x530: 4, 0x540: 0x68, 0x550: 2, 0x560: 0xA0, 0x570: 0x20,
    0x588: 0x20, 0x598: 0x4C, 0x5A8: 2,
}
M3_UNKNOWN_DP = (0x020, 0x038, 0x050, 0x068, 0x090, 0x0A8, 0x0C0, 0x0D8, 0x100, 0x118, 0x130, 0x148, 0x160, 0x290, 0x350, 0x370, 0x5C0)


def vertex_size(types):
    s = {1: 12, 2: 6}.get(types[0], 0)
    for i in (1, 2, 3):
        if types[i] == 3:
            s += 2
    for i in (4, 5, 6, 7):
        if types[i] == 4:
            s += 4
    if types[8] == 5:
        s += 4
    if types[9] == 5:
        s += 4
    if types[10] == 6:
        s += 1
    return s


def check_m3(b, size):
    need(size >= HEADER_END, 'short header')
    need(b[:4] == b'LDOM', 'signature')
    (ver,) = struct.unpack_from('<I', b, 4)
    known = HEADER_END

    def ap(off):
        return struct.unpack_from('<QQ', b, off)

    for off, es in M3_UNKNOWN_AP.items():
        cnt, o = ap(off)
        if cnt:
            need(o + HEADER_END + cnt * es <= size, 'unknown array 0x%X out of bounds' % off)
    for off in M3_UNKNOWN_DP:
        cnt, ok, ov = struct.unpack_from('<QQQ', b, off)
        if cnt:
            need(ok + HEADER_END < size and ov + HEADER_END < size, 'dpointer 0x%X out of bounds' % off)

    # bone map / bones
    bm_c, bm_o = ap(0x1B0)
    need(bm_o + HEADER_END + bm_c * 2 <= size, 'bone map')
    known += bm_c * 2
    bn_c, bn_o = ap(0x180)
    bn_addr = bn_o + HEADER_END
    need(bn_addr + bn_c * 0x160 <= size, 'bones')
    known += bn_c * 0x160
    for i in range(bn_c):
        (par,) = struct.unpack_from('<h', b, bn_addr + i * 0x160 + 4)
        need(-1 <= par < bn_c, 'bone parent')

    # textures
    tx_c, tx_o = ap(0x1C0)
    tx_addr = tx_o + HEADER_END
    need(tx_addr + tx_c * 0x20 <= size, 'textures')
    known += tx_c * 0x20
    name_base = a16(tx_addr + tx_c * 0x20)
    tex_names = []
    for i in range(tx_c):
        n_c, n_o = struct.unpack_from('<QQ', b, tx_addr + i * 0x20 + 16)
        a = n_o + name_base
        need(a + n_c * 2 <= size, 'texture name')
        known += n_c * 2
        tex_names.append(b[a:a + n_c * 2].decode('utf-16le', 'replace').rstrip('\0'))

    # materials
    mt_c, mt_o = ap(0x1F0)
    mt_addr = mt_o + HEADER_END
    need(mt_addr + mt_c * 0x30 <= size, 'materials')
    known += mt_c * 0x30
    desc_base = a16(mt_addr + mt_c * 0x30)
    for i in range(mt_c):
        d_c, d_o = struct.unpack_from('<QQ', b, mt_addr + i * 0x30 + 0x20)
        need(d_o + desc_base + d_c * 0x128 <= size, 'material descriptions')
        known += d_c * 0x128

    # geometry
    g_c, g_o = ap(0x250)
    g_addr = g_o + HEADER_END
    need(g_addr + g_c * 0xC8 <= size, 'geometry')
    known += g_c * 0xC8
    gbase = a16(g_addr + g_c * 0xC8)
    vs_ok = True
    for i in range(g_c):
        g = g_addr + i * 0xC8
        vcount, vsize, _vflags = struct.unpack_from('<IHH', b, g + 0x18)
        ftypes = struct.unpack_from('<11B', b, g + 0x20)
        vd_c, vd_o = struct.unpack_from('<QQ', b, g + 0x38)
        icount = struct.unpack_from('<I', b, g + 0x68)[0]
        id_c, id_o = struct.unpack_from('<QQ', b, g + 0x70)
        ms_c, ms_o = struct.unpack_from('<QQ', b, g + 0x80)
        vc2 = struct.unpack_from('<I', b, g + 0x90)[0]
        mr_c, mr_o = struct.unpack_from('<QQ', b, g + 0x98)
        need(vsize == 0 or vertex_size(ftypes) == vsize, 'vertex size %d != fields %d' % (vsize, vertex_size(ftypes)))
        va = vd_o + gbase
        need(va + vcount * vsize <= size, 'vertex data')
        known += vcount * vsize
        ia = id_o + gbase
        need(ia + icount * 2 <= size, 'index data')
        known += icount * 2
        ma = ms_o + gbase
        need(ma + ms_c * 0x70 <= size, 'meshes')
        known += ms_c * 0x70
        ra = mr_o + gbase
        need(ra + mr_c * 4 <= size, 'mesh vertex range')
        known += mr_c * 4
        for m in range(ms_c):
            istart, vstart, icnt, vcnt = struct.unpack_from('<4I', b, ma + m * 0x70)
            need(istart + icnt <= icount and vstart + vcnt <= vcount, 'mesh range')
        if icount:
            idx = memoryview(b)[ia:ia + icount * 2].cast('H')
            need(max(idx) < vcount, 'index out of vertex range')
    return 'ok', {'ver': ver, 'geom': g_c, 'bones': bn_c, 'textures': tx_c, 'tex_names': tex_names[:0]}, known


CHECKS = {'.tex': check_tex, '.bin': check_bin, '.tbl': check_tbl, '.area': check_area, '.m3': check_m3}


# ----------------------------------------------------------------------------- driver
def worker(args):
    wid, nworkers = args
    res = {e: {'total': 0, 'ok': 0, 'partial': 0, 'fail': 0, 'bytes': 0, 'known_bytes': 0, 'reasons': collections.Counter(),
               'kinds': collections.Counter(), 'fail_examples': []} for e in CHECKED}
    i = 0
    for name in ARCHIVES:
        fs = halon.Filesystem(os.path.join(PATCH, name))
        with open(fs.data.name, 'rb') as arc:
            stack = [fs.root]
            files = []
            while stack:
                d = stack.pop()
                files.extend(d.files.values())
                stack.extend(d.dirs.values())
            files.sort(key=lambda f: f.path)
            for f in files:
                ext = os.path.splitext(f.name)[1].lower()
                if ext not in CHECKED:
                    continue
                i += 1
                if i % nworkers != wid:
                    continue
                r = res[ext]
                r['total'] += 1
                r['bytes'] += f.uncompressed_size
                try:
                    idx, _ = fs.data.blocks[f.sha1]
                    off, bs = fs.data.fs[idx]
                    arc.seek(off)
                    raw = arc.read(bs)
                    if ext == '.tex':
                        data = inflate(f, raw, 4096)
                    else:
                        data = inflate(f, raw)
                        need(len(data) == f.uncompressed_size, 'decompressed size')
                    status, info, known = CHECKS[ext](data, f.uncompressed_size)
                    r[status] += 1
                    r['known_bytes'] += known
                    if ext == '.tex':
                        r['kinds'][info['kind']] += 1
                    elif ext == '.m3':
                        r['kinds']['v%d' % info['ver']] += 1
                    elif ext == '.area':
                        for k, v in info['pkgs'].items():
                            r['kinds']['pkg:' + k] += v
                        for k, v in info['unk_flags'].items():
                            r['kinds']['unknown_flag_bit%d' % k] += v
                    elif ext == '.tbl':
                        for t in info['unk_types']:
                            r['kinds']['unknown_type_%d' % t] += 1
                except Bad as e:
                    r['fail'] += 1
                    r['reasons'][str(e)] += 1
                    if len(r['fail_examples']) < 5:
                        r['fail_examples'].append(f.path)
                except Exception as e:  # noqa: BLE001
                    r['fail'] += 1
                    r['reasons']['%s: %s' % (type(e).__name__, e)] += 1
                    if len(r['fail_examples']) < 5:
                        r['fail_examples'].append(f.path)
    return res


def main():
    n = max(1, (os.cpu_count() or 4) - 2)
    t0 = time.time()
    with mp.Pool(n) as pool:
        parts = pool.map(worker, [(w, n) for w in range(n)])
    total = {}
    for e in CHECKED:
        t = {'total': 0, 'ok': 0, 'partial': 0, 'fail': 0, 'bytes': 0, 'known_bytes': 0,
             'reasons': collections.Counter(), 'kinds': collections.Counter(), 'fail_examples': []}
        for p in parts:
            r = p[e]
            for k in ('total', 'ok', 'partial', 'fail', 'bytes', 'known_bytes'):
                t[k] += r[k]
            t['reasons'].update(r['reasons'])
            t['kinds'].update(r['kinds'])
            t['fail_examples'] += r['fail_examples']
        t['reasons'] = dict(t['reasons'].most_common(15))
        t['kinds'] = dict(t['kinds'].most_common(30))
        t['fail_examples'] = t['fail_examples'][:8]
        total[e] = t
    out = os.path.join(ROOT, 'docs')
    os.makedirs(out, exist_ok=True)
    with open(os.path.join(out, 'validation_report.json'), 'w', encoding='utf-8') as fh:
        json.dump(total, fh, indent=1)
    print('done in %.0fs with %d workers' % (time.time() - t0, n))
    for e, t in total.items():
        pct = 100.0 * t['ok'] / t['total'] if t['total'] else 0
        cov = 100.0 * t['known_bytes'] / t['bytes'] if t['bytes'] else 0
        print('%-6s total=%6d ok=%6d partial=%5d fail=%5d  ok=%.1f%%  byte-coverage=%.1f%%' % (e, t['total'], t['ok'], t['partial'], t['fail'], pct, cov))
        if t['reasons']:
            print('       fail reasons:', t['reasons'])
        if t['kinds']:
            print('       kinds:', dict(list(t['kinds'].items())[:14]))


if __name__ == '__main__':
    mp.freeze_support()
    main()
