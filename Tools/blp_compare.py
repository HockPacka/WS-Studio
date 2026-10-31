"""Compares the DXT BLP written by tex_to_blp_cli with the uncompressed BGRA BLP of the same texture (PSNR of level 0 and of the whole chain).
usage: blp_compare.py <raw.blp> <dxt.blp>
"""
import struct
import sys

import numpy as np


def header(b):
    w, h = struct.unpack_from('<II', b, 12)
    offs = struct.unpack_from('<16I', b, 0x14)
    sizes = struct.unpack_from('<16I', b, 0x54)
    return b[8], b[10], w, h, offs, sizes


def decode_dxt(data, w, h, dxt5):
    bw, bh = (w + 3) // 4, (h + 3) // 4
    bs = 16 if dxt5 else 8
    blocks = np.frombuffer(data, np.uint8, bw * bh * bs).reshape(bh, bw, bs)
    cb = blocks[:, :, 8:] if dxt5 else blocks
    c0 = cb[:, :, 0].astype(np.uint16) | (cb[:, :, 1].astype(np.uint16) << 8)
    c1 = cb[:, :, 2].astype(np.uint16) | (cb[:, :, 3].astype(np.uint16) << 8)

    def rgb(c):
        r = (c >> 11) & 31
        g = (c >> 5) & 63
        bl = c & 31
        return np.stack([(r << 3) | (r >> 2), (g << 2) | (g >> 4), (bl << 3) | (bl >> 2)], -1).astype(np.int32)

    p0, p1 = rgb(c0), rgb(c1)
    pal = np.stack([p0, p1, (2 * p0 + p1) // 3, (p0 + 2 * p1) // 3], 3)      # bh, bw, 3, 4
    idx = cb[:, :, 4].astype(np.uint32) | (cb[:, :, 5].astype(np.uint32) << 8) | (cb[:, :, 6].astype(np.uint32) << 16) | (cb[:, :, 7].astype(np.uint32) << 24)
    out = np.zeros((bh * 4, bw * 4, 4), np.uint8)

    for i in range(16):
        k = ((idx >> (2 * i)) & 3).astype(np.int32)
        px = np.take_along_axis(pal, k[:, :, None, None].repeat(3, 2), 3)[:, :, :, 0]
        y, x = i >> 2, i & 3
        out[y::4, x::4, 0] = px[:, :, 2]
        out[y::4, x::4, 1] = px[:, :, 1]
        out[y::4, x::4, 2] = px[:, :, 0]

    if dxt5:
        a0 = blocks[:, :, 0].astype(np.int32)
        a1 = blocks[:, :, 1].astype(np.int32)
        bits = np.zeros((bh, bw), np.uint64)

        for i in range(6):
            bits |= blocks[:, :, 2 + i].astype(np.uint64) << np.uint64(8 * i)

        pal_a = [a0, a1] + [((7 - k) * a0 + k * a1) // 7 for k in range(1, 7)]
        pal_a = np.stack(pal_a, 2)

        for i in range(16):
            k = ((bits >> np.uint64(3 * i)) & np.uint64(7)).astype(np.int32)
            out[(i >> 2)::4, (i & 3)::4, 3] = np.take_along_axis(pal_a, k[:, :, None], 2)[:, :, 0]
    else:
        out[:, :, 3] = 255

    return out[:h, :w]


def psnr(a, b):
    mse = np.mean((a.astype(np.float64) - b.astype(np.float64)) ** 2)
    return 99.0 if mse == 0 else 10 * np.log10(255.0 * 255.0 / mse)


raw = open(sys.argv[1], 'rb').read()
dxt = open(sys.argv[2], 'rb').read()
ct, pf, w, h, ro, rs = header(raw)
ct2, pf2, w2, h2, do, ds = header(dxt)
print('raw  : color %d pixel %d %dx%d, %d bytes' % (ct, pf, w, h, len(raw)))
print('dxt  : color %d pixel %d %dx%d, %d bytes (%.1f x smaller)' % (ct2, pf2, w2, h2, len(dxt), len(raw) / len(dxt)))
for level in range(16):
    if not rs[level]:
        break
    lw, lh = max(1, w >> level), max(1, h >> level)
    a = np.frombuffer(raw, np.uint8, lw * lh * 4, ro[level]).reshape(lh, lw, 4)
    d = decode_dxt(dxt[do[level]:do[level] + ds[level]], lw, lh, pf2 == 7)
    print('level %2d %4dx%-4d PSNR rgb %.1f dB  alpha %.1f dB' % (level, lw, lh, psnr(a[:, :, :3], d[:, :, :3]), psnr(a[:, :, 3], d[:, :, 3])))
