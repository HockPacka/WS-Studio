"""Renders a FEDS sector (front / side view) with the vertex bytes 16..19 interpreted as colour in several channel orders, to see which reading is coherent paint
(smooth regions) and which is noise (docs/i3_shader_notes.md, COLOR2).
usage: i3_color_probe.py <sector.i3> <out.png> [submesh number]
"""
import os
import struct
import sys

import numpy as np
from PIL import Image

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import i3_reader as r  # noqa: E402

b = open(sys.argv[1], 'rb').read()
p = r.parse(b)
pos, nrm, uv0, uv1, rgba = r.decode_vertices(b, p)
raw = np.frombuffer(b, np.uint8, len(pos) * 20, r.HEADER + p['arrays']['vtx20'][1]).reshape(-1, 20)
ci, oi, _ = p['arrays']['index']
idx = np.frombuffer(b, '<u4', ci, r.HEADER + oi).reshape(-1, 3)
orders = {'rgba (b16 r, b17 g, b18 b)': (0, 1, 2), 'bgra (b16 b, b17 g, b18 r)': (2, 1, 0), 'b17 b18 b16': (1, 2, 0), 'b18 b17 b16': (2, 1, 0)}
W = 520
img = Image.new('RGB', (W * 3, W * 2), 'white')
names = list(orders)[:3]

for row, (vi, vj) in enumerate(((2, 1), (0, 1))):
    a = pos[:, [vi, vj]]
    mn, mx = a.min(0), a.max(0)
    sc = (W - 20) / max(mx - mn)
    q = (a - mn) * sc + 10
    q[:, 1] = W - q[:, 1]

    for col, name in enumerate(names):
        o = orders[name]
        cols = raw[:, [16 + o[0], 16 + o[1], 16 + o[2]]]
        px = np.array(img.crop((col * W, row * W, (col + 1) * W, (row + 1) * W)))

        # painter: far to near by mean depth (axis not shown)
        depth = pos[:, 0 if vi == 2 else 2][idx].mean(1)
        order = np.argsort(depth)

        from PIL import ImageDraw
        tile = Image.new('RGB', (W, W), 'white')
        d = ImageDraw.Draw(tile)

        for t in idx[order][::2]:
            c = tuple(int(x) for x in cols[t].mean(0))
            d.polygon([(float(q[v, 0]), float(q[v, 1])) for v in t], fill=c)

        img.paste(tile, (col * W, row * W))

img.save(sys.argv[2])
print('written', sys.argv[2], names)
