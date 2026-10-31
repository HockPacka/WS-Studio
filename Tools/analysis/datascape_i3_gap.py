"""Datascape-specific I3/DGN inventory for the WildStar -> WoW gap analysis.

Usage: python tools/analysis/datascape_i3_gap.py [Datascape directory]
Prints JSON; does not modify game data.
"""
from __future__ import annotations

import collections
import json
import os
from pathlib import Path
import struct
import sys

import numpy as np

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))
import dgn_reader as dgn  # noqa: E402
import i3_reader as i3  # noqa: E402

H = 0x170
UNKNOWN_FEDI_SLOTS = ("s60", "s70", "s80", "s90", "sa0", "sc0")


def align16(value: int) -> int:
    return (value + 15) & ~15


def slot(data: bytes, offset: int) -> tuple[int, int]:
    return struct.unpack_from("<IxxxxQ", data, offset)


def utf16(data: bytes, offset: int, count: int) -> str:
    return data[offset:offset + count * 2].decode("utf-16le", "replace").rstrip("\0")


def material_sets(data: bytes) -> list[dict]:
    count, offset = slot(data, 0x40)
    array = H + offset
    child = array + align16(count * 0x58)
    sets = []
    for set_index in range(count):
        record = array + set_index * 0x58
        name_count, name_offset = slot(data, record + 0x08)
        pass_count, pass_offset = slot(data, record + 0x18)
        texture_count, texture_offset = slot(data, record + 0x38)
        name = utf16(data, child + name_offset, name_count)
        pass_array = child + pass_offset
        texture_array = child + texture_offset
        string_base = texture_array + texture_count * 0x20
        textures = []
        for texture_index in range(texture_count):
            path_count, path_offset = slot(data, texture_array + texture_index * 0x20 + 0x10)
            textures.append(utf16(data, string_base + path_offset, path_count))
        pass_child = pass_array + align16(pass_count * 0x28)
        passes = []
        for pass_index in range(pass_count):
            material_count, material_offset = slot(data, pass_array + pass_index * 0x28 + 0x18)
            materials = []
            for material_index in range(material_count):
                record_at = pass_child + material_offset + material_index * 0x128
                flags = struct.unpack_from("<8H", data, record_at)
                parameters = {}
                for parameter_slot in range(10):
                    parameter_count = struct.unpack_from("<I", data, record_at + 0x18 + parameter_slot * 0x18)[0]
                    if parameter_count:
                        parameters[str(parameter_slot)] = parameter_count
                materials.append({
                    "color_tex": flags[0],
                    "normal_tex": flags[1],
                    "kind": flags[4],
                    "parameters": parameters,
                })
            passes.append(materials)
        sets.append({"name": name, "textures": textures, "passes": passes})
    return sets


def client_data_for(root: Path) -> Path:
    for parent in (root, *root.parents):
        if parent.name.lower() == "clientdata":
            return parent
    raise ValueError(f"No ClientData ancestor for {root}")


def is_placeholder_normal(path: str) -> bool:
    normalized = path.replace("/", "\\").lower()
    return "blank_normal" in normalized or "blank normal" in normalized


def main() -> None:
    default = Path(__file__).resolve().parents[2] / "WoWClient/ClientData/Art/Structure/Model/Dungeon_Kits/Datascape"
    root = Path(sys.argv[1]).resolve() if len(sys.argv) > 1 else default
    client = client_data_for(root)
    total = collections.Counter()
    material_kinds = collections.Counter()
    submesh_kinds = collections.Counter()
    triangle_flags = collections.Counter()
    parameter_slots = collections.Counter()
    models = {}

    for path in sorted(root.glob("*.i3")):
        data = path.read_bytes()
        if data[:4] == b"FEDS":
            model_name = path.name.split(".", 1)[0]
            entry = models.setdefault(model_name, collections.Counter())
            parsed = i3.parse(data)
            vertex_count = parsed["arrays"]["pos"][0]
            total["sector_files"] += 1
            total["vertices"] += vertex_count
            total["triangles"] += parsed["arrays"]["index"][0] // 3
            entry["sector_files"] += 1
            entry["vertices"] += vertex_count
            entry["triangles"] += parsed["arrays"]["index"][0] // 3
            if vertex_count:
                _, _, _, uv1, rgba = i3.decode_vertices(data, parsed)
                raw = np.frombuffer(data, np.uint8, vertex_count * 20, i3.HEADER + parsed["arrays"]["vtx20"][1]).reshape(-1, 20)
                checks = {
                    "sectors_with_uv1": bool(np.abs(uv1).max() > 0),
                    "sectors_with_packed_tangent_bytes": bool(np.any(raw[:, :4] != 0)),
                    "sectors_with_vertex_flag_byte16": bool(np.any(raw[:, 16] != 0)),
                    "sectors_with_varying_color2": bool(np.any(rgba != rgba[0])),
                    "sectors_with_varying_color2_rgb": bool(np.any(rgba[:, :3] != rgba[0, :3])),
                    "sectors_with_varying_color2_alpha": bool(np.any(rgba[:, 3] != rgba[0, 3])),
                }
                for key, present in checks.items():
                    total[key] += present
                    entry[key] += present
            submesh_count, submesh_offset, _ = parsed["arrays"]["submesh"]
            for submesh_index in range(submesh_count):
                record = struct.unpack_from("<7I", data, i3.HEADER + submesh_offset + submesh_index * 28)
                submesh_kinds[str(record[0])] += 1
                entry[f"submesh_kind_{record[0]}"] += 1
            flag_count, flag_offset, _ = parsed["arrays"]["tri_u16"]
            if flag_count:
                values = np.frombuffer(data, "<u2", flag_count, i3.HEADER + flag_offset)
                triangle_flags.update(str(int(value)) for value in np.unique(values))
            if parsed["arrays"]["kd_nodes"][0]:
                total["sectors_with_kd_tree"] += 1
                entry["sectors_with_kd_tree"] += 1
        elif data[:4] == b"FEDI":
            model_name = path.stem
            entry = models.setdefault(model_name, collections.Counter())
            parsed = i3.parse_idef(data)
            sets = material_sets(data)
            total["model_files"] += 1
            total["material_sets"] += len(sets)
            total["models_with_material_variants"] += len(sets) > 1
            total["native_directed_portal_records"] += parsed["slots"]["s30"][0]
            entry["material_sets"] = len(sets)
            entry["native_directed_portal_records"] = parsed["slots"]["s30"][0]
            entry["sector_records"] = len(parsed["sectors"])
            set_details = []
            for set_index, material_set in enumerate(sets):
                materials = [material for pass_materials in material_set["passes"] for material in pass_materials]
                normal_paths = []
                color_paths = []
                for material in materials:
                    material_kinds[str(material["kind"])] += 1
                    total["materials_all_sets"] += 1
                    entry["materials_all_sets"] += 1
                    if set_index == 0:
                        total["materials_default_set"] += 1
                        entry["materials_default_set"] += 1
                    for parameter_slot, count in material["parameters"].items():
                        parameter_slots[parameter_slot] += 1
                        entry[f"parameter_slot_{parameter_slot}"] += 1
                    if material["parameters"]:
                        total["materials_with_parameters"] += 1
                        entry["materials_with_parameters"] += 1
                    if material["color_tex"] < len(material_set["textures"]):
                        color_path = material_set["textures"][material["color_tex"]]
                        if color_path:
                            color_paths.append(color_path)
                    if material["normal_tex"] < len(material_set["textures"]):
                        normal_path = material_set["textures"][material["normal_tex"]]
                        if normal_path:
                            normal_paths.append(normal_path)
                substantive_normals = [p for p in normal_paths if not is_placeholder_normal(p)]
                existing_normals = [p for p in substantive_normals if (client / p).is_file()]
                total["normal_texture_references"] += len(normal_paths)
                total["nonplaceholder_normal_texture_references"] += len(substantive_normals)
                total["existing_nonplaceholder_normal_texture_references"] += len(existing_normals)
                total["empty_color_texture_materials"] += len(materials) - len(color_paths)
                entry["normal_texture_references"] += len(normal_paths)
                entry["nonplaceholder_normal_texture_references"] += len(substantive_normals)
                if set_index == 0:
                    total["default_set_normal_texture_references"] += len(normal_paths)
                    total["default_set_nonplaceholder_normal_texture_references"] += len(substantive_normals)
                    entry["default_set_normal_texture_references"] = len(normal_paths)
                    entry["default_set_nonplaceholder_normal_texture_references"] = len(substantive_normals)
                set_details.append({
                    "name": material_set["name"],
                    "materials": len(materials),
                    "normal_references": len(normal_paths),
                    "nonplaceholder_normal_references": len(substantive_normals),
                })
            entry["set_names"] = [material_set["name"] for material_set in sets]
            entry["set_details"] = set_details
            entry["unknown_nonempty_fedi_slots"] = {
                name: parsed["slots"][name][0] for name in UNKNOWN_FEDI_SLOTS if parsed["slots"][name][0]
            }
        else:
            raise ValueError(f"Unexpected I3 magic in {path}")

    definitions = []
    dressing_files_seen = set()
    for path in sorted(root.glob("*.dgn")):
        data = path.read_bytes()
        total["dgn_files"] += 1
        if data[:4] != b"NGND":
            continue
        total["dgn_definitions"] += 1
        definition = dgn.parse_definition(data)
        # NGND nested strings begin at the 16-byte-aligned end of the dressing
        # array. The shared Python/C++ readers currently omit this alignment;
        # Main is already aligned, while BW_000/DataCore are eight bytes off.
        dressing_count, dressing_offset = slot(data, 0x38)
        string_base = align16(dgn.DEF_HEADER + dressing_offset + dressing_count * 0x28)
        definition["dressings"] = []
        for dressing_index in range(dressing_count):
            record = dgn.DEF_HEADER + dressing_offset + dressing_index * 0x28
            reference_index = struct.unpack_from("<I", data, record)[0]
            name_count, name_offset = slot(data, record + 8)
            file_count, file_offset = slot(data, record + 0x18)
            definition["dressings"].append({
                "index": reference_index,
                "name": utf16(data, string_base + name_offset, name_count),
                "file": utf16(data, string_base + file_offset, file_count),
            })
        definition_entry = {
            "file": path.name,
            "name": definition["name"],
            "model": os.path.basename(definition["model"]),
            "dressings": len(definition["dressings"]),
            "placements": 0,
            "light_placements_dropped": 0,
            "missing_model_placements_dropped": 0,
            "non_m3_placements_dropped": 0,
            "tail_records_unknown": 0,
            "placement_extra_entries_unknown": 0,
        }
        for dressing_reference in definition["dressings"]:
            dressing_path = client / dressing_reference["file"]
            dressing_files_seen.add(dressing_path.resolve())
            dressing = dgn.parse_dressing(dressing_path.read_bytes())
            total["dressing_files_referenced"] += 1
            definition_entry["placements"] += len(dressing["placements"])
            definition_entry["tail_records_unknown"] += len(dressing["tail"])
            total["dressing_placements"] += len(dressing["placements"])
            total["dressing_tail_records_unknown"] += len(dressing["tail"])
            for placement in dressing["placements"]:
                normalized = placement["model"].replace("/", "\\")
                lower = normalized.lower()
                definition_entry["placement_extra_entries_unknown"] += placement["extra_count"]
                total["dressing_placement_extra_entries_unknown"] += placement["extra_count"]
                if "\\light\\" in lower:
                    definition_entry["light_placements_dropped"] += 1
                    total["light_placements_dropped"] += 1
                elif not lower.endswith(".m3"):
                    definition_entry["non_m3_placements_dropped"] += 1
                    total["non_m3_placements_dropped"] += 1
                elif not (client / normalized).is_file():
                    definition_entry["missing_model_placements_dropped"] += 1
                    total["missing_model_placements_dropped"] += 1
        definitions.append(definition_entry)

    all_dressing_paths = {p.resolve() for p in root.glob("*.dgn") if p.read_bytes()[:4] != b"NGND"}
    total["unreferenced_dressing_files"] = len(all_dressing_paths - dressing_files_seen)
    result = {
        "root": str(root),
        "totals": dict(sorted(total.items())),
        "material_kinds_all_sets": dict(sorted(material_kinds.items())),
        "submesh_kinds": dict(sorted(submesh_kinds.items())),
        "triangle_flag_distinct_values_per_sector": dict(sorted(triangle_flags.items())),
        "material_parameter_slots": dict(sorted(parameter_slots.items())),
        "models": {name: dict(models[name]) for name in sorted(models)},
        "dgn_definitions": definitions,
    }
    print(json.dumps(result, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()
