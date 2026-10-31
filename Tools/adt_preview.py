"""Renders the terrain layers of an ADT built by adt_build_cli (docs/wildstar_content_layout.md) to a PNG, independent of the game client:
every chunk = 64 x 64 texels, colour = alpha weighted average colour of the layer textures (WorldLayer .tex), so seams / blocks in the data become visible.
usage: adt_preview.py <file.adt> <out.png> [client dir] [--stacked]
Default: MPHD flag 0x4 direct additive weights. --stacked previews legacy lerp alpha.
"""
import importlib.util
import os
import struct
import sys

import numpy as np
from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location('tex', os.path.join(HERE, 'blender_addon', 'wildstar_m3', 'tex.py'))
tex = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tex)


def tok(b, o):
    return b[o:o + 4][::-1].decode('latin-1')


def average_color(client, name):
    path = os.path.join(client, 'ClientData', name[3:].replace('.blp', '.tex'))
    try:
        w, h, px = tex.decode_tex(open(path, 'rb').read(), 64)
        a = np.asarray(px, float).reshape(-1, np.asarray(px).shape[-1])
        return a[:, :3].mean(0)
    except Exception:  # noqa: BLE001
        return np.array([128.0, 0.0, 128.0])


def main():
    adt = open(sys.argv[1], 'rb').read()
    out = sys.argv[2]
    client = sys.argv[3] if len(sys.argv) > 3 and not sys.argv[3].startswith('--') else os.path.join(os.path.dirname(HERE), 'WoWClient')
    stacked = '--stacked' in sys.argv
    o = 0
    chunks = []
    names = []
    while o < len(adt):
        t = tok(adt, o)
        sz = struct.unpack_from('<I', adt, o + 4)[0]
        if t == 'MTEX':
            names = [x.decode() for x in adt[o + 8:o + 8 + sz].split(b'\0')[:-1]]
        if t == 'MCNK':
            chunks.append((o, sz))
        o += 8 + sz
    cols = [average_color(client, n) for n in names]
    img = np.zeros((16 * 64, 16 * 64, 3), np.uint8)
    for idx, (co, sz) in enumerate(chunks):
        cx, cy = idx % 16, idx // 16
        nl = struct.unpack_from('<I', adt, co + 8 + 0x0C)[0]
        p = co + 8 + 0x80
        layers = []
        alpha = b''
        while p < co + 8 + sz:
            t = tok(adt, p)
            s2 = struct.unpack_from('<I', adt, p + 4)[0]
            if t == 'MCLY':
                layers = [struct.unpack_from('<4I', adt, p + 8 + q * 16) for q in range(nl)]
            if t == 'MCAL':
                alpha = adt[p + 8:p + 8 + s2]
            p += 8 + s2
        tile = np.zeros((64, 64, 3), float)
        overlays = np.zeros((64, 64, 1), float)
        for q, (tid, fl, off, eff) in enumerate(layers):
            c = cols[tid]
            if q == 0:
                tile[:] = c
            else:
                a = np.frombuffer(alpha[off:off + 4096], np.uint8).reshape(64, 64)[:, :, None] / 255.0
                if stacked:
                    tile = tile * (1 - a) + c * a
                else:
                    tile += c * a
                    overlays += a
        if layers and not stacked:
            tile -= cols[layers[0][0]] * overlays
        img[cy * 64:(cy + 1) * 64, cx * 64:(cx + 1) * 64] = tile.clip(0, 255).astype(np.uint8)
    Image.fromarray(img).save(out)
    print('saved', out, img.shape)


if __name__ == '__main__':
    main()
