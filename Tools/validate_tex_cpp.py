#!/usr/bin/env python3
"""Compares the C++ tex decoder (Model3/TexToBlp, JPEG-like and other formats) with the python reference tex.py. usage: validate_tex_cpp.py [every-nth-file]"""
import glob
import importlib.util
import os
import struct
import subprocess
import sys
import tempfile

import numpy as np

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
spec = importlib.util.spec_from_file_location('tex', os.path.join(ROOT, 'tools', 'blender_addon', 'wildstar_m3', 'tex.py'))
tex = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tex)
EXE = os.path.join(ROOT, 'build_m3test', 'tex_to_blp_cli.exe')

step = int(sys.argv[1]) if len(sys.argv) > 1 else 400
base = os.path.join(ROOT, 'WoWClient', 'ClientData')
files = sorted(glob.glob(os.path.join(base, '**', '*.tex'), recursive=True))[::step]
out = os.path.join(tempfile.mkdtemp(), 'a.blp')
res = {'ok': 0, 'fail': 0, 'diff': 0}
worst = []
for f in files:
    data = open(f, 'rb').read()
    try:
        hdr = tex.parse_header(data)
        w, h, rgba = tex.decode_tex(data, 1024)
    except Exception as e:  # noqa: BLE001
        continue
    r = subprocess.run([EXE, f, out], capture_output=True, text=True)
    if r.returncode != 0:
        res['fail'] += 1
        if len(worst) < 5:
            worst.append((os.path.basename(f), r.stderr.strip(), hdr['fmt'], hdr['is_jpg']))
        continue
    blp = open(out, 'rb').read()
    enc, alpha, pref, hasmips = blp[8], blp[9], blp[10], blp[11]
    bw, bh = struct.unpack_from('<II', blp, 12)
    # find the mip that matches the python size (python picks the largest mip <= 1024)
    offs = struct.unpack_from('<16I', blp, 0x14)
    sizes = struct.unpack_from('<16I', blp, 0x54)
    ok = False
    for i in range(16):
        if not sizes[i]:
            break
        mw, mh = max(1, bw >> i), max(1, bh >> i)
        if (mw, mh) == (w, h) and enc == 3:
            px = np.frombuffer(blp, np.uint8, count=mw * mh * 4, offset=offs[i]).reshape(mh, mw, 4)[:, :, [2, 1, 0, 3]]
            d = np.abs(px.astype(int) - rgba.astype(int))
            md = d.mean()
            ok = True
            if md > 2.0:
                res['diff'] += 1
                if len(worst) < 5:
                    worst.append((os.path.basename(f), 'mean abs diff %.2f' % md, hdr['fmt'], hdr['is_jpg']))
            else:
                res['ok'] += 1
            break
    if not ok:
        res.setdefault('skipped(dxt or size)', 0)
        res['skipped(dxt or size)'] += 1
print(len(files), 'files', res)
for w in worst:
    print(w)
