"""Test whether the four unknown I3 vertex bytes encode a TBN quaternion."""
from pathlib import Path
import sys

import numpy as np

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from i3_reader import parse, decode_vertices, HEADER


def oct_decode(x, y):
    x = x / 127.5 - 1.0
    y = y / 127.5 - 1.0
    z = 1.0 - np.abs(x) - np.abs(y)
    t = np.maximum(-z, 0.0)
    x += np.where(x >= 0, -t, t)
    y += np.where(y >= 0, -t, t)
    n = np.stack([x, y, z], axis=1)
    return n / np.maximum(np.linalg.norm(n, axis=1, keepdims=True), 1e-12)


def rotate(q, axis):
    v = np.zeros_like(q[:, :3])
    v[:, axis] = 1.0
    xyz = q[:, :3]
    w = q[:, 3:4]
    inner = np.cross(xyz, v) + w * v
    return v + 2.0 * np.cross(xyz, inner)


def main(path):
    data = Path(path).read_bytes()
    parsed = parse(data)
    _, normal, _, _, _ = decode_vertices(data, parsed)
    count = len(normal)
    offset = HEADER + parsed['arrays']['vtx20'][1]
    raw = np.frombuffer(data, np.uint8, count * 20, offset).reshape(count, 20)
    print(path, 'vertices', count)
    for order in ((0, 1, 2, 3), (3, 0, 1, 2), (1, 2, 3, 0), (0, 1, 3, 2)):
        q = raw[:, order].astype(np.float32) / 127.5 - 1.0
        q /= np.maximum(np.linalg.norm(q, axis=1, keepdims=True), 1e-12)
        dots = [np.einsum('ij,ij->i', rotate(q, axis), normal) for axis in range(3)]
        print('quat order', order, 'axis meanAbsDot', [round(float(np.mean(np.abs(d))), 4) for d in dots],
              'axis meanDot', [round(float(np.mean(d)), 4) for d in dots])
    for x, y in ((0, 1), (1, 0), (2, 3), (3, 2), (0, 2), (2, 0), (1, 3), (3, 1)):
        tangent = oct_decode(raw[:, x].astype(np.float32), raw[:, y].astype(np.float32))
        dot = np.einsum('ij,ij->i', tangent, normal)
        print('oct', (x, y), 'meanAbsDot', round(float(np.mean(np.abs(dot))), 4),
              'meanDot', round(float(np.mean(dot)), 4))


if __name__ == '__main__':
    main(sys.argv[1])
