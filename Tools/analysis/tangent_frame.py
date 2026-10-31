import math, os, struct, sys
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, HERE)
sys.argv = [sys.argv[0]] + sys.argv[1:2]
from vertex_fields import raw, vertex_raw, oct_decode, m3
path = sys.argv[1]
b = raw(path); L, vb, types, vsize = vertex_raw(b)
mo = m3.read_model(b); g = mo.geometries[0]
def dec(i, nm, s=127.0):
    p, q = struct.unpack_from('<2b', vb[i], L[nm]); return oct_decode(p / s, q / s)
def dot(a, c): return sum(x * y for x, y in zip(a, c))
import collections
st = collections.defaultdict(list)
for i in range(0, len(vb), 3):
    A, B, C = dec(i, 'f3a'), dec(i, 'f3b'), dec(i, 'f3c')
    st['a.b'].append(dot(A, B)); st['b.c'].append(dot(B, C)); st['a.c'].append(dot(A, C))
for k, v in st.items():
    print(k, 'mean %.3f  mean|.| %.3f  frac|.|<0.15 %.2f' % (sum(v) / len(v), sum(abs(x) for x in v) / len(v), sum(abs(x) < 0.15 for x in v) / len(v)))
# tangent from UVs: per-vertex dP/du accumulated, compare to candidates
pos = g.positions; uv = g.uv1
acc = [[0.0] * 3 for _ in pos]
for me in g.meshes:
    idx = g.indices[me.start_index: me.start_index + me.index_count]
    for t in range(0, len(idx) - 2, 3):
        ia, ib, ic = [me.start_vertex + i for i in idx[t:t + 3]]
        p0, p1, p2 = pos[ia], pos[ib], pos[ic]
        u0, u1, u2 = uv[ia], uv[ib], uv[ic]
        e1 = [p1[k] - p0[k] for k in range(3)]; e2 = [p2[k] - p0[k] for k in range(3)]
        du1, dv1, du2, dv2 = u1[0] - u0[0], u1[1] - u0[1], u2[0] - u0[0], u2[1] - u0[1]
        d = du1 * dv2 - du2 * dv1
        if abs(d) < 1e-9: continue
        tang = [(e1[k] * dv2 - e2[k] * dv1) / d for k in range(3)]
        for i in (ia, ib, ic):
            for k in range(3): acc[i][k] += tang[k]
for nm in ('f3a', 'f3c'):
    ds = []
    for i in range(0, len(vb), 3):
        a = acc[i]; ln = math.sqrt(sum(x * x for x in a))
        if ln < 1e-9: continue
        ds.append(dot(dec(i, nm), [x / ln for x in a]))
    print(nm, 'vs dP/du: mean %.3f mean|.| %.3f' % (sum(ds) / len(ds), sum(abs(x) for x in ds) / len(ds)))
print('--- with negated decodes')
def neg(v): return [-x for x in v]
def cross(a, c): return [a[1]*c[2]-a[2]*c[1], a[2]*c[0]-a[0]*c[2], a[0]*c[1]-a[1]*c[0]]
ds = collections.defaultdict(list)
for i in range(0, len(vb), 3):
    N, T, X = neg(dec(i, 'f3b')), neg(dec(i, 'f3a')), neg(dec(i, 'f3c'))
    ds['N.T'].append(dot(N, T)); ds['N.X'].append(dot(N, X)); ds['T.X'].append(dot(T, X))
    c = cross(N, T); ds['X.(NxT)'].append(dot(X, c))
    ds['|N|'].append(math.sqrt(dot(N, N))); ds['|T|'].append(math.sqrt(dot(T, T)))
for k, v in ds.items(): print(k, 'mean %.3f mean|.| %.3f' % (sum(v)/len(v), sum(abs(x) for x in v)/len(v)))
