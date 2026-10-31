#!/usr/bin/env python3
"""Smoke test + statistics of wildstar_m3/extras.py on every extracted .m3.  usage: test_extras.py [every-nth-file]"""
import collections
import glob
import importlib.util
import multiprocessing as mp
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
spec = importlib.util.spec_from_file_location('extras', os.path.join(ROOT, 'tools', 'blender_addon', 'wildstar_m3', 'extras.py'))
extras = importlib.util.module_from_spec(spec)
spec.loader.exec_module(extras)


def work(path):
    st = collections.Counter()
    try:
        e = extras.read_extras(open(path, 'rb').read())
    except Exception as ex:  # noqa: BLE001
        st['error:' + type(ex).__name__ + ':' + str(ex)[:60]] += 1
        return st
    st['ok'] += 1
    for name in ('cameras', 'lights', 'sound_events', 'sound_emitters', 'attachments', 'collision', 'anim_states', 'face_ranges', 'bone_tracks'):
        if getattr(e, name):
            st[name + ':models'] += 1
            st[name + ':items'] += len(getattr(e, name))
    if e.hull:
        st['hull:models'] += 1
    for cam in e.cameras:
        if cam.fov is None or not cam.fov.halves:
            st['camera_without_fov'] += 1
        elif not all(0.0 < v < 3.2 for v in cam.fov.halves):
            st['camera_fov_out_of_range'] += 1
    for li in e.lights:
        st['light_type%d' % li.type] += 1
    if e.head_bone != 0xFFFF:
        st['head_bone'] += 1
    return st


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    files = sorted(glob.glob(os.path.join(ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
    tot = collections.Counter()
    with mp.Pool(max(1, (os.cpu_count() or 4) - 2)) as p:
        for st in p.imap_unordered(work, files, chunksize=64):
            tot.update(st)
    for k in sorted(tot):
        print('%-40s %d' % (k, tot[k]))
