"""Inspect converted I3 WMO material textures and tangent-space UV degeneracy."""
import math
from pathlib import Path
import struct
import sys

import numpy as np


def chunks(data, start=0, end=None):
    offset = start
    end = len(data) if end is None else end
    while offset + 8 <= end:
        token = data[offset:offset + 4][::-1].decode('latin1')
        size = struct.unpack_from('<I', data, offset + 4)[0]
        yield token, offset + 8, size
        offset += 8 + size


def main(prefix):
    prefix = Path(prefix)
    root = prefix.with_suffix('.wmo').read_bytes()
    root_chunks = {token: (offset, size) for token, offset, size in chunks(root)}
    offset, size = root_chunks['MOTX']
    strings = root[offset:offset + size]
    offset, size = root_chunks['MOMT']
    materials = []
    for index in range(size // 64):
        at = offset + index * 64
        flags, shader, blend, texture, _, _, normal = struct.unpack_from('<7I', root, at)
        packed, flags2 = struct.unpack_from('<2I', root, at + 0x28)
        def name(string_offset):
            end = strings.find(b'\0', string_offset)
            return strings[string_offset:end].decode('utf8', 'replace')
        materials.append((name(texture), name(normal), flags2, blend, packed))
        if flags2 & 0x80000000:
            print(f'material {index:3} blend={blend} flags2={flags2:#x} packed={packed:#010x}')
            print(f'  color  {name(texture)}')
            print(f'  normal {name(normal)}')
    total = [0, 0, 0]
    for group_index in range(256):
        group_path = prefix.with_name(prefix.name + f'_{group_index:03d}.wmo')
        if not group_path.exists():
            break
        data = group_path.read_bytes()
        header = chunks(data)
        next(header)  # MVER
        _, group_start, group_size = next(header)  # MOGP
        group_chunks = {token: (offset, size) for token, offset, size in chunks(data, group_start + 0x44, group_start + group_size)}
        vo, vs = group_chunks['MOVT']
        no, ns = group_chunks['MONR']
        uo, us = group_chunks['MOTV']
        normals = np.frombuffer(data, dtype='<f4', count=ns // 4, offset=no).reshape(-1, 3)
        uvs = np.frombuffer(data, dtype='<f4', count=us // 4, offset=uo).reshape(-1, 2)
        total[0] += vs // 12
        total[1] += int(np.count_nonzero(np.abs(np.linalg.norm(normals, axis=1) - 1.0) > 0.02))
        total[2] += int(np.count_nonzero(~np.isfinite(uvs).all(axis=1)))
    print(f'groups={group_index} vertices={total[0]} non_unit_normals={total[1]} non_finite_uvs={total[2]}')


if __name__ == '__main__':
    main(sys.argv[1])
