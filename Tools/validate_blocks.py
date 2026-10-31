#!/usr/bin/env python3
"""Validate the layouts of the rarely used M3 header blocks (engine loader FUN_14030cac0 + slot handlers) on every extracted .m3.

Spec: slot -> (element size, [fields]) with field = (offset, 'ap'|'dp', value size or nested spec).
  ap: (count u64, offset u64) -> array of `value size` bytes or of nested records
  dp: (count u64, key offset u64, value offset u64) -> count u32 keys + count values of `value size`
Nested offsets are relative to the (aligned or unaligned) end of the parent array; both variants are tried and the better one is reported.
usage: validate_blocks.py [every-nth-file]"""
import collections
import glob
import json
import multiprocessing as mp
import os
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
H = 0x630


def a16(x):
    return (x + 15) & ~15


REC20_S2 = (0x20, [(0x08, 'dp', 2)])
REC20_S1 = (0x20, [(0x08, 'dp', 1)])
SPEC = {
    0x490: (0x40, [(0x00, 'ap', 0x10), (0x10, 'ap', 0xC), (0x20, 'ap', 4), (0x30, 'ap', 0x14)]),
    0x2A8: (0x10, [(0x00, 'ap', 2)]),
    0x2B8: (0x28, [(0x08, 'ap', REC20_S2), (0x18, 'ap', REC20_S1)]),
    0x308: (0x50, [(0x08, 'dp', 2), (0x20, 'dp', 2), (0x38, 'dp', 2)]),
    0x318: (0x190, [(0x10, 'dp', 2), (0x28, 'dp', 2), (0x40, 'dp', 2), (0x58, 'dp', 4), (0x70, 'dp', 4), (0x88, 'dp', 2), (0xA0, 'dp', 2),
                    (0xB8, 'dp', 2), (0xD0, 'dp', 2), (0xE8, 'dp', 2), (0x100, 'dp', 2), (0x118, 'dp', 2), (0x130, 'dp', 2), (0x148, 'dp', 2),
                    (0x160, 'dp', 2), (0x178, 'dp', 2)]),
    0x328: (0x38, [(0x10, 'dp', 2)]),
    0x4A0: (4, []),
    0x540: (0x68, [(0x08, 'dp', 2), (0x20, 'dp', 4), (0x38, 'dp', 6), (0x50, 'dp', 8)]),
    0x550: (2, []),
    0x560: (0xA0, [(0x28, 'dp', 2), (0x40, 'dp', 2), (0x58, 'dp', 4), (0x70, 'dp', 4), (0x88, 'dp', 4)]),
    0x570: (0x20, [(0x08, 'dp', 1)]),
    0x588: (0x20, [(0x08, 'dp', 2)]),
    0x598: (0x4C, []),
    0x5A8: (2, []),
}
TOP_DP = {0x5C0: 1}


def check_array(b, addr, count, es, spec_fields, aligned, st, label):
    """returns True if the array and all nested arrays are inside the file"""
    size = len(b)
    if addr < H or addr + count * es > size:
        return False
    base = addr + count * es
    if aligned:
        base = a16(base)
    for k in range(count):
        e = addr + k * es
        for off, kind, arg in spec_fields:
            if kind == 'ap':
                c, o = struct.unpack_from('<QQ', b, e + off)
                if not c:
                    continue
                if isinstance(arg, tuple):
                    if not check_array(b, base + o, c, arg[0], arg[1], aligned, st, label):
                        return False
                else:
                    if base + o < H or base + o + c * arg > size:
                        return False
            else:
                c, ko, vo = struct.unpack_from('<QQQ', b, e + off)
                if not c:
                    continue
                if base + ko < H or base + ko + c * 4 > size or base + vo < H or base + vo + c * arg > size:
                    return False
                # keys are ascending animation times
                keys = struct.unpack_from('<%dI' % min(c, 64), b, base + ko)
                if any(keys[i] > keys[i + 1] for i in range(len(keys) - 1)):
                    st[label + ':keys_unsorted'] += 1
    return True


def work(path):
    b = open(path, 'rb').read()
    st = collections.Counter()
    if b[:4] != b'LDOM':
        return st
    for slot, (es, fields) in SPEC.items():
        c, o = struct.unpack_from('<QQ', b, slot)
        if not c:
            continue
        lab = '%03X' % slot
        st[lab + ':models'] += 1
        st[lab + ':elements'] += c
        if c > 1 << 22:
            st[lab + ':bad_count'] += 1
            continue
        res = []
        for aligned in (True, False):
            sub = collections.Counter()
            res.append((check_array(b, o + H, c, es, fields, aligned, sub, lab), sub))
        if res[0][0]:
            st[lab + ':ok_aligned'] += 1
            st.update(res[0][1])
        if res[1][0]:
            st[lab + ':ok_unaligned'] += 1
        if not res[0][0] and not res[1][0]:
            st[lab + ':bad'] += 1
    for slot, vs in TOP_DP.items():
        c, ko, vo = struct.unpack_from('<QQQ', b, slot)
        if c:
            lab = '%03X' % slot
            st[lab + ':models'] += 1
            if ko + H + c * 4 <= len(b) and vo + H + c * vs <= len(b):
                st[lab + ':ok'] += 1
            else:
                st[lab + ':bad'] += 1
    # three-array block 0x510 / 0x520 / 0x530
    for slot, es in ((0x510, 0x10), (0x520, 4), (0x530, 4)):
        c, o = struct.unpack_from('<QQ', b, slot)
        if c:
            lab = '%03X' % slot
            st[lab + ':models'] += 1
            st[lab + ':ok' if o + H + c * es <= len(b) else lab + ':bad'] += 1
    return st


if __name__ == '__main__':
    mp.freeze_support()
    step = int(sys.argv[1]) if len(sys.argv) > 1 else 1
    files = sorted(glob.glob(os.path.join(ROOT, 'extracted', 'ClientData', '**', '*.m3'), recursive=True))[::step]
    tot = collections.Counter()
    with mp.Pool(max(1, (os.cpu_count() or 4) - 2)) as p:
        for st in p.imap_unordered(work, files, chunksize=64):
            tot.update(st)
    print(len(files), 'files')
    for k in sorted(tot):
        print('%-28s %d' % (k, tot[k]))
    json.dump(dict(tot), open(os.path.join(ROOT, 'docs', 'm3_blocks_validation.json'), 'w'), indent=1)
