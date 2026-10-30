"""Regression: actual WildStar M3 geometry index AP count is BYTES, not u16 elements.

The original Avatus_Gun and both hand assets give an index AP count equal to
2 * geometry.indexCount. The previously deployed native parser incorrectly
used an AP stride of 2, which rejected valid buffers near the end of the file.
This standalone fixture reproduces that allocation layout without copyrighted
assets and would return zero renderable meshes under the old implementation.
"""
from __future__ import annotations
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from native_m3 import read_m3_native


def real_like_end_of_file_index_buffer() -> bytes:
    b = bytearray((ROOT / 'demo' / 'Crystal.m3').read_bytes())
    g = 0x630 + struct.unpack_from('<Q', b, 0x258)[0]
    nc = struct.unpack_from('<Q', b, 0x250)[0]
    base = (g + nc * 0xc8 + 15) & ~15
    def ap(off):
        return struct.unpack_from('<QQ', b, g + off)
    vb, vo = ap(0x38)
    ib, io = ap(0x70)
    mc, mo = ap(0x80)
    # Build a valid layout with vertex data first, mesh headers second and
    # raw index bytes at EOF (the standard Avatus problematic condition).
    vertex = bytes(b[base + vo:base + vo + vb])
    mesh = bytes(b[base + mo:base + mo + mc * 0x70])
    indices = bytes(b[base + io:base + io + ib])
    out = b[:base]
    def align(): out.extend(b'\0' * (-len(out) % 16))
    struct.pack_into('<QQ', out, g + 0x38, len(vertex), len(out) - base)
    out.extend(vertex)
    align()
    struct.pack_into('<QQ', out, g + 0x80, mc, len(out) - base)
    out.extend(mesh)
    align()
    struct.pack_into('<QQ', out, g + 0x70, len(indices), len(out) - base)
    out.extend(indices)
    assert len(out) < (base + struct.unpack_from('<Q', out, g + 0x78)[0]) + 2 * len(indices)
    return bytes(out)


class RealIndexLayoutTests(unittest.TestCase):
    def test_real_wildstar_byte_count_at_end_of_file(self):
        model = read_m3_native(real_like_end_of_file_index_buffer(), 'avatus_layout_synthetic.m3')
        self.assertEqual(model['stats']['meshes'], 3)
        self.assertEqual(model['stats']['triangles'], 48)
        self.assertEqual(model['m3Details']['geometryInventory'][0]['indexCount'], 144)

    def test_truncated_index_buffer_is_not_silently_accepted(self):
        b = real_like_end_of_file_index_buffer()
        # Cut off the final triangle's u16 indices.
        broken = b[:-6]
        model = read_m3_native(broken, 'truncated_geometry.m3')
        self.assertEqual(model['stats']['meshes'], 0)
        self.assertTrue(any('ausgelassen' in w for w in model['warnings']))


if __name__ == '__main__': unittest.main()
