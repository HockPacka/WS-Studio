"""Export actual composed characters, then inspect their serialized M2 animation.

Uses CPU skin matrices reconstructed from exported (quantized) keys, not just
the converter's intermediate transforms. Run from the project root.
"""
import concurrent.futures
import csv
import json
import os
from pathlib import Path
import struct
import subprocess
import sys

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from validate_anim_cpp import parse_m2, m2_bone_matrices

OUT = ROOT / 'build_m3test/character_attachment_check'
OUT.mkdir(parents=True, exist_ok=True)
EXE = ROOT / 'wowdecomp/build/i3_portal_fix/bin/Release/character_cli.exe'


def run(pair):
    race, sex = pair
    path = OUT / f'{race}_{sex}.m2'
    env = dict(os.environ, WS_CHARACTER_M2=str(path))
    p = subprocess.run([str(EXE), str(race), str(sex)], cwd=ROOT/'WoWClient',
                       env=env, capture_output=True, text=True, timeout=180)
    (OUT / f'{race}_{sex}.log').write_text(p.stdout+p.stderr, encoding='utf-8')
    assert p.returncode == 0, (pair, p.returncode, p.stderr)
    raw = path.read_bytes()
    seqs, bones = parse_m2(raw)
    with Path(str(path)+'.bones.csv').open() as f:
        ids = {int(r['id']): int(r['index']) for r in csv.DictReader(f) if int(r['id']) != 65535}
    result = dict(race=race, sex=sex, sequences=[], attachments=[])
    for sid in [0, 4, 5]:
        si = next(i for i, q in enumerate(seqs) if q[0] == sid)
        for t in [0, seqs[si][2]//2, max(0, seqs[si][2]-1)]:
            mats = m2_bone_matrices(bones, si, t)
            assert all(np.isfinite(m).all() for m in mats), (pair, sid, t, 'non-finite matrix')
            head = ids[73]
            scales = np.linalg.svd(mats[head][:3, :3], compute_uv=False)
            # Detect the reported half-size head, without assuming an exact
            # scale of one in animated squash/stretch poses.
            assert min(scales) > .70 and max(scales) < 1.4, (pair, sid, t, scales)
            result['sequences'].append(dict(id=sid,time=t,headScale=scales.tolist()))
    si = next(i for i, q in enumerate(seqs) if q[0] == 0)
    mats = m2_bone_matrices(bones, si, 0)
    count, offset = struct.unpack_from('<II', raw, 0xf0)
    for k in range(count):
        o = offset+k*40
        aid, bone = struct.unpack_from('<IH', raw, o)
        point = np.array([*struct.unpack_from('<3f', raw, o+8), 1.0])
        assert bone < len(bones) and np.isfinite(point).all()
        if aid in [1, 2]:
            expected = ids[59 if aid == 1 else 58]
            assert bone == expected
            assert np.linalg.norm(point[:3]) > .25, (pair, aid, 'anchor still at origin')
            # The helper must be near its parent hand, not at the root.
            parent = bones[bone][0]
            hand = mats[parent] @ np.r_[bones[parent][1], 1.0]
            actual = mats[bone] @ point
            distance = float(np.linalg.norm(actual[:3]-hand[:3]))
            assert distance < .6, (pair, aid, distance)
            result['attachments'].append(dict(id=aid,bone=bone,bind=point[:3].tolist(),
                                              stand=actual[:3].tolist(),distanceToHand=distance))
    assert len(result['attachments']) == 2, pair
    return result


if __name__ == '__main__':
    pairs = [(r,s) for r in range(22,30) for s in ([0] if r==29 else [0,1])]
    if len(sys.argv)>1:
        pairs = [(int(sys.argv[1]),int(sys.argv[2]) if len(sys.argv)>2 else 0)]
    with concurrent.futures.ThreadPoolExecutor(max_workers=2) as pool:
        results = list(pool.map(run,pairs))
    (OUT/'report.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8')
    print(f'PASS {len(results)} composed characters, {len(results)*9} Stand/Walk/Run samples, '
          f'{len(results)*2} hand anchors and {len(results)*7} option cycles')
