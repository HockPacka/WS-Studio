#!/usr/bin/env python3
"""Runs the in-memory M3->M2 converter (wowdecomp/Engine/Source/Model3, test exe build_m3test/m3_to_m2_cli.exe) over extracted models
and validates the produced M2/skin byte streams with an independent parser.  usage: validate_m2_synth.py [every-nth-file]"""
import collections
import glob
import os
import struct
import subprocess
import sys
import tempfile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE = os.path.join(ROOT, 'build_m3test', 'm3_to_m2_cli.exe')


def arr(b, off):
    return struct.unpack_from('<II', b, off)


def check(m2, skin):
    err = []
    if m2[:4] != b'MD20' or struct.unpack_from('<I', m2, 4)[0] != 264:
        return ['header']
    size = len(m2)

    def inside(name, off, esize):
        c, o = arr(m2, off)
        if c and (o > size or o + c * esize > size):
            err.append(name + ' out of bounds')
        return c, o

    ns, so = inside('sequences', 0x1C, 0x40)
    nb, bo = inside('bones', 0x2C, 0x58)
    nv, vo = inside('vertices', 0x3C, 0x30)
    nt, to = inside('textures', 0x50, 0x10)
    inside('materials', 0x70, 4)
    nbc, bco = inside('bonecombos', 0x78, 2)
    ntc, tco = inside('texcombos', 0x80, 2)
    for i in range(nb):
        o = bo + i * 0x58
        par = struct.unpack_from('<H', m2, o + 8)[0]
        if par != 0xFFFF and par >= nb:
            err.append('bone parent')
        for t in (0x10, 0x24, 0x38):
            tc, tof = arr(m2, o + t + 4)
            kc, kof = arr(m2, o + t + 12)
            if tc != ns or kc != ns or tof + 8 * tc > size or kof + 8 * kc > size:
                err.append('track arrays')
    for i in range(nv):
        o = vo + i * 0x30
        idx = m2[o + 0x10:o + 0x14]
        if any(x >= nb for x in idx):
            err.append('vertex bone index')
            break
    for i in range(nt):
        c, o = arr(m2, to + i * 0x10 + 8)
        if c and (o + c > size or m2[o + c - 1] != 0):
            err.append('texture name')
    # skin
    if skin[:4] != b'SKIN':
        err.append('skin magic')
        return err
    ssize = len(skin)
    sv, svo = arr(skin, 4)
    si, sio = arr(skin, 0x0C)
    sbn, sbo = arr(skin, 0x14)
    sc, sco = arr(skin, 0x1C)
    bc, bco2 = arr(skin, 0x24)
    for name, c, o, e in (('skin.vertices', sv, svo, 2), ('skin.indices', si, sio, 2), ('skin.bones', sbn, sbo, 4), ('skin.sections', sc, sco, 0x30), ('skin.batches', bc, bco2, 0x18)):
        if o + c * e > ssize:
            err.append(name + ' out of bounds')
    if err:
        return err
    if any(x >= sv for x in struct.unpack_from('<%dH' % si, skin, sio)):
        err.append('skin index >= skin vertices')
    if any(x >= nv for x in struct.unpack_from('<%dH' % sv, skin, svo)):
        err.append('skin vertex >= m2 vertices')
    for i in range(sc):
        o = sco + i * 0x30
        vs, vc, is_, ic = struct.unpack_from('<4H', skin, o + 4)
        if vs + vc > sv or is_ + ic > si or ic % 3:
            err.append('section range')
    for i in range(bc):
        o = bco2 + i * 0x18
        sec, geo, col, mat, lay, tcnt, tcombo = struct.unpack_from('<HHHHHHH', skin, o + 4)
        if sec >= sc or mat >= struct.unpack_from('<I', m2, 0x70)[0] or tcombo >= ntc:
            err.append('batch refs')
    return err


def main():
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 50
    base = os.path.join(ROOT, 'extracted', 'ClientData')
    if not os.path.isdir(base):
        base = os.path.join(ROOT, 'WoWClient', 'ClientData')
    files = sorted(glob.glob(os.path.join(base, '**', '*.m3'), recursive=True))[::step]
    st = collections.Counter()
    tmp = tempfile.mkdtemp()
    m2p, skp = os.path.join(tmp, 'a.m2'), os.path.join(tmp, 'a.skin')
    for f in files:
        r = subprocess.run([EXE, f, m2p, skp], capture_output=True, text=True)
        if r.returncode != 0:
            st['convert fail: ' + (r.stderr.strip()[:60] or 'rc%d' % r.returncode)] += 1
            continue
        e = check(open(m2p, 'rb').read(), open(skp, 'rb').read())
        if e:
            st['invalid: ' + e[0]] += 1
            if st['printed'] < 5:
                st['printed'] += 1
                print(f, e[:3])
        else:
            st['valid'] += 1
    print(len(files), 'files')
    for k, v in sorted(st.items(), key=lambda kv: -kv[1]):
        if k != 'printed':
            print('%6d  %s' % (v, k))


if __name__ == '__main__':
    main()
