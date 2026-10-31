"""Resolve M3 mesh materials to original ModelPS permutations and disassemble them."""
from pathlib import Path
import importlib.util
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from sho_reader import read_sho
from dxbc_dis import disassemble

spec = importlib.util.spec_from_file_location('m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def permutation(mesh, material, pass_kind):
    """Native FUN_14030e510, using the raw 0x70-byte M3 mesh record."""
    result = struct.unpack_from('<H', mesh, 0x14)[0] - 1
    material_index = struct.unpack_from('<H', mesh, 0x16)[0]
    assert material_index == material[0]
    material = material[1]
    present = [struct.unpack_from('<h', mesh, 0x30 + 2 * i)[0] != -1 for i in range(4)]
    for i in range(len(material.layers)):
        if material.layers[i].klass != 3:
            present[i] = True
    if material.header[2] == 1:
        return result + pass_kind * 4
    special = [struct.unpack_from('<h', mesh, 0x28 + 2 * i)[0] == 2 for i in range(4)]
    value = (pass_kind * 16 + result) * 2
    value = (value + special[2]) * 2
    value = (value + special[1]) * 2
    value = (value + special[0]) * 2
    value = (value + special[3]) * 2
    value = value + present[0]
    value = (value + present[1]) * 2
    value = (value + present[2]) * 2
    value = (value + present[3]) * 2
    return value


def main():
    if len(sys.argv) < 3:
        raise SystemExit('usage: m3_shader_probe.py output_dir model.m3 [...]')
    output = Path(sys.argv[1])
    output.mkdir(parents=True, exist_ok=True)
    shader_path = ROOT / 'WoWClient/ClientData/Shaders/ModelPS.ps_4_0.sho'
    shader_data = shader_path.read_bytes()
    container = read_sho(shader_data)
    mapping = container['permutation_to_code']
    for arg in sys.argv[2:]:
        path = Path(arg)
        if not path.is_absolute():
            path = ROOT / path
        data = path.read_bytes()
        model = m3.read_model(data)
        geometry_count, geometry_offset = struct.unpack_from('<QQ', data, 0x250)
        geometry_offset += m3.HEADER_END
        geometry_base = m3._a16(geometry_offset + geometry_count * 0xC8)
        print('\n', path.relative_to(ROOT), sep='')
        for gi, geometry in enumerate(model.geometries):
            g = geometry_offset + gi * 0xC8
            vertex_flags = struct.unpack_from('<H', data, g + 0x1E)[0]
            mesh_count, mesh_offset = struct.unpack_from('<QQ', data, g + 0x80)
            mesh_base = geometry_base + mesh_offset
            print('geometry', gi, 'vertex_size', geometry.vertex_size, 'flags', hex(vertex_flags),
                  'meshes', mesh_count)
            # FUN_14030dbb0: 7 = low/static, 8 = extended/static, 9 = full/skinned.
            if geometry.vertex_size < 0x11:
                pass_kind = 0
            elif (vertex_flags & 0xF0) != 0:
                pass_kind = 1
            else:
                pass_kind = 2
            for mi in range(mesh_count):
                mesh = data[mesh_base + mi * 0x70:mesh_base + (mi + 1) * 0x70]
                material_index = struct.unpack_from('<H', mesh, 0x16)[0]
                if material_index >= len(model.material_info):
                    print('mesh', mi, 'invalid material', material_index)
                    continue
                material = model.material_info[material_index]
                key = permutation(mesh, (material_index, material), pass_kind)
                code = mapping[key] if key < len(mapping) else 0xFFFFFFFF
                print('mesh', mi, 'material', material_index, 'pass_kind', pass_kind,
                      'mesh_words', struct.unpack_from('<8H', mesh, 0x28),
                      'permutation', key, 'code', code)
                if code != 0xFFFFFFFF:
                    item = container['code'][code]
                    blob = shader_data[item['offset']:item['offset'] + item['bytes']]
                    text = disassemble(blob).rstrip('\0').replace('\r', '')
                    name = f'{path.stem}_g{gi}_m{mi}_p{key}_c{code}.txt'
                    (output / name).write_text(text, encoding='utf-8')
                    print(' disassembly', name)
                # FUN_14030e510 returns the geometry/depth key. The archive also
                # contains forward/lighting candidates at 0x1000-byte key steps;
                # retain them for analysis without claiming a render-pass mapping.
                for candidate_kind in range(4, 30, 2):
                    candidate = key + (candidate_kind - pass_kind) * 0x800
                    if candidate >= len(mapping):
                        continue
                    candidate_code = mapping[candidate]
                    if candidate_code == 0xFFFFFFFF:
                        continue
                    item = container['code'][candidate_code]
                    blob = shader_data[item['offset']:item['offset'] + item['bytes']]
                    text = disassemble(blob).rstrip('\0').replace('\r', '')
                    if 'mov o0.xyzw, -v1.zzzz' in text:
                        continue
                    name = f'{path.stem}_g{gi}_m{mi}_candidate{candidate_kind}_p{candidate}_c{candidate_code}.txt'
                    (output / name).write_text(text, encoding='utf-8')
                    print(' color_candidate', candidate_kind, candidate, candidate_code, name)


if __name__ == '__main__':
    main()
