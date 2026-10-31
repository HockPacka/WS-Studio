"""Correlates the packed vertex bytes of FEDS sectors with geometry (normal, position) to find out what they mean (docs/i3_shader_notes.md).
usage: i3_vertex_probe.py <sector.i3> [...]
"""
import os
import sys

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import i3_reader as r  # noqa: E402


def corr(v, a):
    return float(np.corrcoef(v, a)[0, 1]) if v.std() > 0 and a.std() > 0 else 0.0


for f in sys.argv[1:]:
    b = open(f, 'rb').read()
    p = r.parse(b)
    pos, n, uv0, uv1, rgba = r.decode_vertices(b, p)
    raw = np.frombuffer(b, np.uint8, len(pos) * 20, r.HEADER + p['arrays']['vtx20'][1]).reshape(-1, 20).astype(float)
    print(os.path.basename(f), len(pos), 'vertices')

    for c in (0, 1, 2, 3, 16, 17, 18, 19):
        v = raw[:, c]
        print('  byte %2d unique %3d min %3d max %3d  corr normal(x y z) %5.2f %5.2f %5.2f  position(x y z) %5.2f %5.2f %5.2f' % (
            c, len(set(v.tolist())), v.min(), v.max(), corr(v, n[:, 0]), corr(v, n[:, 1]), corr(v, n[:, 2]), corr(v, pos[:, 0]), corr(v, pos[:, 1]), corr(v, pos[:, 2])))
