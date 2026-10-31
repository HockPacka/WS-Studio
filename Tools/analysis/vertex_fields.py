"""Experiment: decode the packed 2-byte (f3a/f3b/f3c), 4-byte (f4a/f4b) and 1-byte (f6) vertex fields of an .m3 and compare
candidate encodings with geometric face normals."""
import math
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TOOLS = os.path.dirname(HERE)
sys.path.insert(0, os.path.join(TOOLS, 'Halon'))
sys.path.insert(0, TOOLS)
sys.path.insert(0, os.path.join(TOOLS, 'blender_addon', 'wildstar_m3'))
import halon  # noqa: E402
from validate_formats import inflate, PATCH, a16  # noqa: E402
import m3  # noqa: E402

fs = halon.Filesystem(os.path.join(PATCH, 'ClientData'))


def raw(path):
    f = fs[path.replace('\\', '/')]
    i, _ = fs.data.blocks[f.sha1]
    o, bs = fs.data.fs[i]
    with open(fs.data.name, 'rb') as a:
        a.seek(o)
        return inflate(f, a.read(bs))


def vertex_raw(b):
    """returns geometry-0 info: layout dict, vertex bytes list, positions, meshes, indices"""
    H = 0x630
    ga = struct.unpack_from('<Q', b, 0x258)[0] + H
    gb = a16(ga + 0xC8)
    vcount, vsize = struct.unpack_from('<IH', b, ga + 0x18)
    types = struct.unpack_from('<11B', b, ga + 0x20)
    layout, _ = m3._vertex_layout(types)
    vd_o = struct.unpack_from('<Q', b, ga + 0x40)[0]
    va = vd_o + gb
    return dict(layout), [b[va + i * vsize: va + (i + 1) * vsize] for i in range(vcount)], types, vsize


def oct_decode(x, y):
    # octahedral mapping, x,y in [-1,1]
    z = 1.0 - abs(x) - abs(y)
    if z < 0:
        x, y = (1 - abs(y)) * (1 if x >= 0 else -1), (1 - abs(x)) * (1 if y >= 0 else -1)
    n = math.sqrt(x * x + y * y + z * z) or 1
    return (x / n, y / n, z / n)


def sph_decode(a, b):
    th = a * math.pi
    ph = b * math.pi / 2
    return (math.sin(ph) * math.cos(th), math.sin(ph) * math.sin(th), math.cos(ph))


if __name__ == '__main__':
    path = sys.argv[1]
    b = raw(path)
    mo = m3.read_model(b)
    g = mo.geometries[0]
    L, vb, types, vsize = vertex_raw(b)
    print('layout', L, 'vsize', vsize, 'types', types)
    pos = g.positions
    # face normals accumulated per vertex (mesh-local indices + start vertex)
    acc = [[0.0, 0.0, 0.0] for _ in pos]
    for me in g.meshes:
        idx = g.indices[me.start_index: me.start_index + me.index_count]
        for t in range(0, len(idx) - 2, 3):
            ia, ib, ic = [me.start_vertex + i for i in idx[t:t + 3]]
            a, bb, c = pos[ia], pos[ib], pos[ic]
            u = [bb[k] - a[k] for k in range(3)]
            v = [c[k] - a[k] for k in range(3)]
            n = [u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]]
            for i in (ia, ib, ic):
                for k in range(3):
                    acc[i][k] += n[k]
    for nm in ('f3a', 'f3b', 'f3c'):
        if nm not in L:
            continue
        off = L[nm]
        stats = {}
        for name, dec in (('oct int8/127', lambda p, q: oct_decode(p / 127.0, q / 127.0)),
                          ('sph int8/127', lambda p, q: sph_decode(p / 127.0, q / 127.0))):
            dots = []
            for i in range(0, len(vb), 7):
                p, q = struct.unpack_from('<2b', vb[i], off)
                n = dec(p, q)
                a = acc[i]
                ln = math.sqrt(sum(x * x for x in a)) or 1
                dots.append(sum(n[k] * a[k] / ln for k in range(3)))
            stats[name] = (sum(dots) / len(dots), sum(abs(d) for d in dots) / len(dots))
        print(nm, {k: (round(v[0], 3), round(v[1], 3)) for k, v in stats.items()},
              'sample bytes', [struct.unpack_from('<2b', vb[i], off) for i in range(0, 12, 3)])
    for nm in ('f4a', 'f4b'):
        if nm in L:
            vals = [vb[i][L[nm]:L[nm] + 4] for i in range(0, len(vb), 11)]
            print(nm, 'sample', [v.hex() for v in vals[:8]], 'distinct', len(set(vals)))
    if 'f6' in L:
        print('f6 distinct', sorted({vb[i][L['f6']] for i in range(len(vb))})[:20])


def brute(path, nm, step=5):
    import itertools
    b = raw(path)
    mo = m3.read_model(b)
    g = mo.geometries[0]
    L, vb, types, vsize = vertex_raw(b)
    pos = g.positions
    acc = [[0.0, 0.0, 0.0] for _ in pos]
    for me in g.meshes:
        idx = g.indices[me.start_index: me.start_index + me.index_count]
        for t in range(0, len(idx) - 2, 3):
            ia, ib, ic = [me.start_vertex + i for i in idx[t:t + 3]]
            a, bb, c = pos[ia], pos[ib], pos[ic]
            u = [bb[k] - a[k] for k in range(3)]
            v = [c[k] - a[k] for k in range(3)]
            n = [u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0]]
            for i in (ia, ib, ic):
                for k in range(3):
                    acc[i][k] += n[k]
    nrm = []
    for a in acc:
        ln = math.sqrt(sum(x * x for x in a))
        nrm.append([x / ln for x in a] if ln > 1e-9 else None)
    off = L[nm]
    decs = {
        'oct': lambda p, q: oct_decode(p / 127.0, q / 127.0),
        'xy+z': lambda p, q: (p / 127.0, q / 127.0, math.sqrt(max(0, 1 - (p / 127.0) ** 2 - (q / 127.0) ** 2))),
        'xy-z': lambda p, q: (p / 127.0, q / 127.0, -math.sqrt(max(0, 1 - (p / 127.0) ** 2 - (q / 127.0) ** 2))),
        'sph': lambda p, q: sph_decode(p / 127.0, q / 127.0),
        'sph2': lambda p, q: (math.sin((q / 127.0 * 0.5 + 0.5) * math.pi) * math.cos(p / 127.0 * math.pi), math.sin((q / 127.0 * 0.5 + 0.5) * math.pi) * math.sin(p / 127.0 * math.pi), math.cos((q / 127.0 * 0.5 + 0.5) * math.pi)),
        'sph3': lambda p, q: (math.sin((p / 127.0 * 0.5 + 0.5) * math.pi) * math.cos(q / 127.0 * math.pi), math.sin((p / 127.0 * 0.5 + 0.5) * math.pi) * math.sin(q / 127.0 * math.pi), math.cos((p / 127.0 * 0.5 + 0.5) * math.pi)),
        'octu': lambda p, q: oct_decode((p & 255) / 255.0 * 2 - 1, (q & 255) / 255.0 * 2 - 1),
        'octu2': lambda p, q: oct_decode((p & 255) / 128.0 - 1, ((q + 128) & 255) / 127.5 - 1),
        'oct128': lambda p, q: oct_decode(p / 128.0, q / 128.0),
        'oct255': lambda p, q: oct_decode((p + 0.5) / 127.5, (q + 0.5) / 127.5),
    }
    res = []
    idxs = [i for i in range(0, len(vb), step) if nrm[i]]
    raws = [struct.unpack_from('<2b', vb[i], off) for i in idxs]
    for dn, dec in decs.items():
        vecs = [dec(p, q) for p, q in raws]
        for perm in itertools.permutations(range(3)):
            for sg in itertools.product((1, -1), repeat=3):
                s = 0.0
                for v, i in zip(vecs, idxs):
                    w = [sg[k] * v[perm[k]] for k in range(3)]
                    s += sum(w[k] * nrm[i][k] for k in range(3))
                res.append((s / len(idxs), dn, perm, sg))
    res.sort(reverse=True)
    return res[:4]


if len(sys.argv) > 2:
    for nm in sys.argv[2:]:
        print(nm, brute(sys.argv[1], nm))
