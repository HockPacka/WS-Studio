import math, os, struct, sys, collections
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
path = sys.argv[1]; sys.argv = sys.argv[:1]
from vertex_fields import raw, vertex_raw, oct_decode, m3
b = raw(path); L, vb, types, vsize = vertex_raw(b)
mo = m3.read_model(b); g = mo.geometries[0]
def dec(i, nm):
    p, q = struct.unpack_from('<2B', vb[i], L[nm]); return oct_decode(p / 255.0 * 2 - 1, q / 255.0 * 2 - 1)
def dot(a, c): return sum(x * y for x, y in zip(a, c))
pos = g.positions; uv = g.uv1
accT = [[0.0] * 3 for _ in pos]; accB = [[0.0] * 3 for _ in pos]
for me in g.meshes:
    idx = g.indices[me.start_index: me.start_index + me.index_count]
    for t in range(0, len(idx) - 2, 3):
        ia, ib, ic = [me.start_vertex + i for i in idx[t:t + 3]]
        p0, p1, p2 = pos[ia], pos[ib], pos[ic]; u0, u1, u2 = uv[ia], uv[ib], uv[ic]
        e1 = [p1[k] - p0[k] for k in range(3)]; e2 = [p2[k] - p0[k] for k in range(3)]
        du1, dv1, du2, dv2 = u1[0] - u0[0], u1[1] - u0[1], u2[0] - u0[0], u2[1] - u0[1]
        d = du1 * dv2 - du2 * dv1
        if abs(d) < 1e-9: continue
        T = [(e1[k] * dv2 - e2[k] * dv1) / d for k in range(3)]
        B = [(e2[k] * du1 - e1[k] * du2) / d for k in range(3)]
        for i in (ia, ib, ic):
            for k in range(3): accT[i][k] += T[k]; accB[i][k] += B[k]
def norm(v):
    l = math.sqrt(dot(v, v)); return [x / l for x in v] if l > 1e-9 else None
res = collections.defaultdict(list)
for i in range(0, len(vb), 3):
    N = dec(i, 'f3b'); A = dec(i, 'f3a'); C = dec(i, 'f3c')
    t = norm(accT[i]); bt = norm(accB[i])
    res['N.A'].append(dot(N, A)); res['N.C'].append(dot(N, C)); res['A.C'].append(dot(A, C))
    if t: res['A.dPdu'].append(dot(A, t)); res['C.dPdu'].append(dot(C, t))
    if bt: res['A.dPdv'].append(dot(A, bt)); res['C.dPdv'].append(dot(C, bt))
for k, v in res.items(): print('%-7s mean %+.3f mean|.| %.3f' % (k, sum(v) / len(v), sum(abs(x) for x in v) / len(v)))
