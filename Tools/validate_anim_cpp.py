#!/usr/bin/env python3
"""Checks the C++ M3 -> M2 animation export (Model3/M3Anim.cpp): the world position of every bone origin at a given sequence time computed from the
exported M2 keys must equal the one computed directly from the M3 tracks (python reference, tools/blender_addon/wildstar_m3/m3.py + the sign solver).
usage: validate_anim_cpp.py model.m3 [model.m3 ...]"""
import importlib.util
import itertools
import os
import struct
import subprocess
import sys
import tempfile

import numpy as np

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, 'build_m3test', 'm3_to_m2_cli.exe')
spec = importlib.util.spec_from_file_location('m3', os.path.join(ROOT, 'tools', 'blender_addon', 'wildstar_m3', 'm3.py'))
m3lib = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3lib)

P = np.array([[0, 0, 1, 0], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 0, 1]], float)   # WildStar (x,y,z) -> WoW (z,x,y)


def quat_mat(x, y, z, w):
    n = (x * x + y * y + z * z + w * w) ** 0.5
    x, y, z, w = x / n, y / n, z / n, w / n
    m = np.eye(4)
    m[:3, :3] = [[1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w)],
                 [2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w)],
                 [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]]
    return m


def tr(v):
    m = np.eye(4)
    m[:3, 3] = v
    return m


def sample(track, t, quat=False):
    ts = track.times
    if t <= ts[0]:
        return np.array(track.values[0], float)
    if t >= ts[-1]:
        return np.array(track.values[-1], float)
    hi = int(np.searchsorted(ts, t, side='right'))
    lo = hi - 1
    f = (t - ts[lo]) / max(1, ts[hi] - ts[lo])
    a, b = np.array(track.values[lo], float), np.array(track.values[hi], float)
    if quat:
        if a @ b < 0:
            b = -b
        d = a @ b
        if d > 0.9995:
            r = a + (b - a) * f
        else:
            th = np.arccos(d)
            r = (np.sin((1 - f) * th) * a + np.sin(f * th) * b) / np.sin(th)
        return r / np.linalg.norm(r)
    return a + (b - a) * f


def reference(model, t, base_time):
    skin = set(model.bone_map)
    n = len(model.bones)
    A = [np.array([[b.bind_world[c * 4 + r] for c in range(4)] for r in range(4)], float) for b in model.bones]
    real = [not np.allclose(A[i], np.eye(4), atol=1e-6) for i in range(n)]
    signs = sorted(itertools.product((1, -1), repeat=3), key=lambda s: s.count(-1))
    X = [np.eye(4)] * n
    Y = [np.eye(4)] * n

    def local(i, tt, Xm, Ym):
        b = model.bones[i]
        if b.translation is None and b.rotation is None and b.scale is None and b.parent_scale is None:
            # bone without tracks stays at its bind pose relative to the parent
            if real[i]:
                return A[i] if b.parent < 0 or not real[b.parent] else np.linalg.inv(A[b.parent]) @ A[i]
            return np.eye(4)
        loc = sample(b.translation, tt) if b.translation is not None else np.zeros(3)
        q = sample(b.rotation, tt, True) if b.rotation is not None else np.array([0, 0, 0, 1.0])
        sc = np.array(sample(b.scale, tt) if b.scale is not None else np.ones(3), float)
        if b.parent_scale is not None:
            psc = sample(b.parent_scale, tt)
            for k in range(3):
                if abs(psc[k]) > 1e-6:
                    sc[k] /= abs(psc[k])
        return Xm @ tr(loc) @ quat_mat(*q) @ Ym @ np.diag([abs(sc[0]), abs(sc[1]), abs(sc[2]), 1.0])

    for i, b in enumerate(model.bones):
        p = b.parent
        if p < 0 or not real[i] or not real[p]:
            continue
        done = False
        for sx in signs:
            for sy in signs:
                xm = np.diag([*sx, 1.0])
                ym = np.diag([*sy, 1.0])
                M = A[p] @ local(i, base_time, xm, ym)
                if np.abs(M[:3, :] - A[i][:3, :]).max() < 0.03:
                    X[i], Y[i] = xm, ym
                    done = True
                    break
            if done:
                break
    cache = {}

    def world(i, tt):
        if i in cache:
            return cache[i]
        b = model.bones[i]
        L = local(i, tt, X[i], Y[i])
        cache[i] = L if b.parent < 0 else world(b.parent, tt) @ L
        return cache[i]

    res = []
    for i in range(n):
        w = world(i, t)
        res.append(P @ w[:, 3])   # bone origin in WoW axes (W_b * origin) - only valid for bones whose bind frame origin is the bone origin
    return A, res


def parse_m2(m2):
    def arr(off):
        return struct.unpack_from('<II', m2, off)
    ns, so = arr(0x1C)
    nb, bo = arr(0x2C)
    seqs = []
    for i in range(ns):
        o = so + i * 0x40
        sid, var = struct.unpack_from('<HH', m2, o)
        dur = struct.unpack_from('<I', m2, o + 4)[0]
        seqs.append((sid, var, dur))
    bones = []
    for i in range(nb):
        o = bo + i * 0x58
        par = struct.unpack_from('<H', m2, o + 8)[0]
        piv = struct.unpack_from('<3f', m2, o + 0x4C)
        tracks = []
        for t_off, kind in ((0x10, 0), (0x24, 1), (0x38, 2)):
            ttype, loop = struct.unpack_from('<HH', m2, o + t_off)
            tc, tof = arr(o + t_off + 4)
            kc, kof = arr(o + t_off + 12)
            per_seq = []
            for s in range(tc):
                n1, off1 = struct.unpack_from('<II', m2, tof + s * 8)
                n2, off2 = struct.unpack_from('<II', m2, kof + s * 8)
                times = list(struct.unpack_from('<%dI' % n1, m2, off1)) if n1 else []
                if kind == 1:
                    raw = np.array(struct.unpack_from('<%dH' % (4 * n2), m2, off2), float).reshape(-1, 4) / 32767.5 - 1.0 if n2 else np.zeros((0, 4))
                else:
                    raw = np.array(struct.unpack_from('<%df' % (3 * n2), m2, off2), float).reshape(-1, 3) if n2 else np.zeros((0, 3))
                per_seq.append((times, raw))
            tracks.append(per_seq)
        bones.append((par, np.array(piv, float), tracks))
    return seqs, bones


def m2_bone_matrices(bones, s, t):
    n = len(bones)
    out = [None] * n

    def val(per_seq, kind, default):
        times, raw = per_seq[s] if s < len(per_seq) else ([], [])
        if not times:
            return default
        ts = np.array(times)
        if t <= ts[0]:
            return raw[0]
        if t >= ts[-1]:
            return raw[-1]
        hi = int(np.searchsorted(ts, t, side='right'))
        lo = hi - 1
        f = (t - ts[lo]) / max(1, ts[hi] - ts[lo])
        a, b = raw[lo], raw[hi]
        if kind == 1:
            if a @ b < 0:
                b = -b
            r = a + (b - a) * f
            return r / np.linalg.norm(r)
        return a + (b - a) * f

    def mat(i):
        if out[i] is not None:
            return out[i]
        par, piv, tracks = bones[i]
        trn = val(tracks[0], 0, np.zeros(3))
        rot = val(tracks[1], 1, np.array([0, 0, 0, 1.0]))
        scl = val(tracks[2], 2, np.ones(3))
        R = quat_mat(*rot)
        local = tr(piv) @ tr(trn) @ R @ np.diag([*scl, 1.0]) @ tr(-piv)
        out[i] = local if par == 0xFFFF else mat(par) @ local
        return out[i]

    return [mat(i) for i in range(n)]


def main():
    tmp = tempfile.mkdtemp()
    for path in sys.argv[1:]:
        model = m3lib.read_model(open(path, 'rb').read())
        m2p, skp = os.path.join(tmp, 'a.m2'), os.path.join(tmp, 'a.skin')
        r = subprocess.run([EXE, path, m2p, skp], capture_output=True, text=True)
        if r.returncode:
            print(os.path.basename(path), 'convert failed', r.stderr.strip())
            continue
        seqs, bones = parse_m2(open(m2p, 'rb').read())
        base_time = next((c.start for aid in (210, 150) for c in model.clips if c.anim_id == aid), 0)
        # the clip list order == sequence order (limited to 250)
        clips = model.clips[:min(len(seqs), int(os.environ.get('NCLIPS', '10')))]
        worst = {}
        for s, c in enumerate(clips):
            if c.end - c.start < 1:
                continue
            for frac in (0.0, 0.5, 1.0):
                t_rel = int((c.end - c.start) * frac)
                A, ref = reference(model, c.start + t_rel, base_time)
                Ms = m2_bone_matrices(bones, s, t_rel)
                err = 0.0
                skinned = set(model.bone_map)
                for i, b in enumerate(model.bones):
                    if i not in skinned:
                        continue            # helper bones carry no vertices
                    # origin of the bind frame moved by the skin matrix: M * pivot  ==  P * W_b(t) * (A_b^-1 * A_b origin)
                    piv = bones[i][1]
                    got = (Ms[i] @ np.append(piv, 1.0))[:3]
                    want = ref[i][:3] if not np.allclose(A[i], np.eye(4), atol=1e-6) else got
                    err = max(err, float(np.abs(got - want).max()))
                worst[(c.anim_id, frac)] = err
        vals = sorted(worst.values())
        print('%-40s clips %d  bones %d  max err %.4f  median %.4f' % (os.path.basename(path), len(clips), len(model.bones), vals[-1] if vals else -1, vals[len(vals) // 2] if vals else -1))


if __name__ == '__main__':
    main()
