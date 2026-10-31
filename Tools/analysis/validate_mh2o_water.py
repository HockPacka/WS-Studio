"""Validate WildStar WSW1 surfaces embedded in a generated ADT MH2O chunk."""
from pathlib import Path
import math
import struct
import sys

MAGIC = 0x31575357


def u32(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


def validate(path):
    data = Path(path).read_bytes()
    chunks = {}
    offset = 0
    while offset + 8 <= len(data):
        name = data[offset:offset + 4]
        size = u32(data, offset + 4)
        end = offset + 8 + size
        if end > len(data):
            raise ValueError(f"ADT chunk {name!r} exceeds file")
        chunks[name] = data[offset + 8:end]
        offset = end
    if offset != len(data):
        raise ValueError("ADT trailing bytes")
    water = chunks.get(b"O2HM")
    if water is None:
        raise ValueError("MH2O chunk missing")
    if len(water) < 256 * 12:
        raise ValueError("short MH2O descriptor table")

    surfaces = {}
    furthest = 256 * 12
    for chunk in range(256):
        instances_at, count, attributes = struct.unpack_from("<3I", water, chunk * 12)
        if not count:
            if instances_at or attributes:
                raise ValueError(f"chunk {chunk}: empty descriptor has offsets")
            continue
        if instances_at < 256 * 12 or instances_at + count * 24 > len(water):
            raise ValueError(f"chunk {chunk}: instance array out of bounds")
        records = []
        for layer in range(count):
            at = instances_at + layer * 24
            liquid_type, vertex_format = struct.unpack_from("<2H", water, at)
            minimum, maximum = struct.unpack_from("<2f", water, at + 4)
            vertex_at = u32(water, at + 20)
            if not liquid_type & 0x8000 or vertex_format != 3:
                raise ValueError(f"chunk {chunk}: not a WildStar surface")
            if not math.isfinite(minimum) or not math.isfinite(maximum) or minimum > maximum:
                raise ValueError(f"chunk {chunk}: invalid height range")
            if vertex_at + 68 > len(water):
                raise ValueError(f"chunk {chunk}: WSW1 header out of bounds")
            magic, index_count, vertex_count = struct.unpack_from("<3I", water, vertex_at)
            if magic != MAGIC or not index_count or not vertex_count or vertex_count > 65535:
                raise ValueError(f"chunk {chunk}: invalid WSW1 counts")
            indices_at = vertex_at + 68
            vertices_at = indices_at + index_count * 4
            end = vertices_at + vertex_count * 72
            if end > len(water):
                raise ValueError(f"chunk {chunk}: surface payload out of bounds")
            indices = struct.unpack_from(f"<{index_count}I", water, indices_at)
            if max(indices) >= vertex_count:
                raise ValueError(f"chunk {chunk}: index exceeds vertex count")
            for vertex in range(vertex_count):
                values = struct.unpack_from("<14f", water, vertices_at + vertex * 72)
                if not all(math.isfinite(value) for value in values):
                    raise ValueError(f"chunk {chunk}: non-finite vertex data")
            records.append((index_count, vertex_count))
            furthest = max(furthest, end)
        surfaces[chunk] = records
    if furthest != len(water):
        raise ValueError(f"MH2O size mismatch: used {furthest}, actual {len(water)}")
    # Source cells 169/170 use storage x/y; WoW reverses both cell axes.
    expected = {86: [(258, 67)], 85: [(750, 162)]}
    for chunk, record in expected.items():
        if surfaces.get(chunk) != record:
            raise ValueError(f"chunk {chunk}: expected {record}, got {surfaces.get(chunk)}")
    print(f"OK {path}: {len(surfaces)} chunks, {sum(map(len, surfaces.values()))} WSW1 surfaces, {len(water)} MH2O bytes")
    print(f"OK source cells 169/170 -> WoW chunks 86/85: {surfaces[86]}, {surfaces[85]}")


if __name__ == "__main__":
    validate(sys.argv[1])
