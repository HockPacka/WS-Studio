"""Validate candidate WATG/WBSP layouts across .area water cells."""
from pathlib import Path
from collections import Counter
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import area_reader as A
from tbl_dump import parse as read_tbl


def u32(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


def f32(data, offset):
    return struct.unpack_from("<f", data, offset)[0]


def decode_watg(data):
    if len(data) < 60:
        raise ValueError("short WATG")
    surface_count, water_type = struct.unpack_from("<II", data)
    surfaces = []
    offset = 4
    for surface in range(surface_count):
        if offset + 80 > len(data):
            raise ValueError("short WATG surface header")
        layer, flags, index_count, vertex_count = struct.unpack_from("<4I", data, offset + 56)
        indices_at = offset + 80
        vertices_at = indices_at + index_count * 4
        end = vertices_at + vertex_count * 72
        if end > len(data):
            raise ValueError(f"short WATG surface at {offset:#x}: {end} > {len(data)}")
        indices = struct.unpack_from(f"<{index_count}I", data, indices_at)
        if indices and max(indices) >= vertex_count:
            raise ValueError(f"WATG index {max(indices)} >= {vertex_count}")
        vertices = [struct.unpack_from("<18f", data, vertices_at + index * 72)
                    for index in range(vertex_count)]
        surfaces.append(dict(layer=layer, flags=flags, indices=indices, vertices=vertices))
        offset = end
    if offset != len(data):
        raise ValueError(f"WATG trailing bytes: {len(data) - offset}")
    result = dict(version=surface_count, water_type=water_type, surfaces=surfaces)
    if surfaces:
        result.update(surfaces[0])
    return result


def decode_wbsp(data):
    if len(data) < 84:
        raise ValueError("short WBSP")
    vertex_count, polygon_count = struct.unpack_from("<II", data, 0x44)
    offset = 84
    next_index = 0
    polygons = []
    for polygon in range(polygon_count):
        vertices = []
        for item in range(vertex_count - next_index):
            if offset + 24 > len(data):
                raise ValueError("short WBSP vertex")
            bounds = struct.unpack_from("<4f", data, offset)
            index, layer = struct.unpack_from("<II", data, offset + 16)
            offset += 24
            if index != next_index:
                raise ValueError(f"WBSP vertex sequence {index} != {next_index} at {offset - 24:#x}")
            vertices.append((bounds, layer))
            next_index += 1
            # The first vertex carries the polygon's total vertex count in bounds[0]
            # only indirectly; detect the edge records by their non-float integer payload.
            if offset + 24 <= len(data):
                possible_index = u32(data, offset + 16)
                if possible_index == next_index:
                    continue
            break
        edges = []
        while offset + 24 <= len(data) and len(edges) < len(vertices) - 1:
            edges.append(struct.unpack_from("<6i", data, offset))
            offset += 24
        polygons.append((vertices, edges))
    return polygons, data[offset:]


def water_cells(limit=None):
    count = 0
    for path in sorted((ROOT / "WoWClient/ClientData/Map/Western").glob("Western.*.area")):
        area = A.read_area(path.read_bytes())
        for name, size, chunk, pos in area["chunks"]:
            if name not in ("CHNK", "KNHC"):
                continue
            for index, flags, cell in A.read_chnk(chunk, area["compressed"]):
                cell_flags, blocks, subs = A.split_cell(cell)
                water = {key: value for key, value in subs if key in ("GtAW", "Psbw")}
                if "GtAW" in water and "Psbw" in water:
                    yield path.name, index, water["GtAW"], water["Psbw"]
                    count += 1
                    if limit and count >= limit:
                        return


def main():
    _, columns, rows = read_tbl((ROOT / "WoWClient/ClientData/DB/WorldWaterLayer.tbl").read_bytes())
    for row in rows:
        if row[0] in (63, 67, 110, 118, 119, 121, 122, 141, 142, 162):
            print("LAYER", row)
    watg_layers = Counter()
    wbsp_layers = Counter()
    polygons = Counter()
    tails = Counter()
    for number, (name, cell, watg_raw, wbsp_raw) in enumerate(water_cells(100)):
        watg = decode_watg(watg_raw)
        polygons_raw, tail = decode_wbsp(wbsp_raw)
        watg_layers[watg["layer"]] += 1
        for vertices, edges in polygons_raw:
            polygons[len(vertices)] += 1
            for _, layer in vertices:
                wbsp_layers[layer] += 1
        tails[len(tail)] += 1
        if number < 2:
            print("CELL", name, cell, "WATG", len(watg["indices"]), len(watg["vertices"]),
                  "WBSP polygons", len(polygons_raw), "tail", len(tail))
            for i, vertex in enumerate(watg["vertices"][:3]):
                print(" WATG VERTEX", i, ["%.6g" % value for value in vertex])
            for i, (vertices, edges) in enumerate(polygons_raw[:2]):
                print(" WBSP POLY", i, "vertices", len(vertices), "edges", edges)
            print(" WBSP TAIL", [u32(tail, i) for i in range(0, min(len(tail), 96), 4)])
    print("VALIDATED", number + 1, "WATG layers", watg_layers)
    print("WBSP layers", wbsp_layers, "polygon sizes", polygons, "tail sizes", tails)


if __name__ == "__main__":
    main()
