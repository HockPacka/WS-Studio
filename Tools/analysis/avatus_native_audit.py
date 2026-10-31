"""Inventory Avatus M3 materials, texture roles, and native ModelPS keys."""
import importlib.util
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from sho_reader import read_sho
spec = importlib.util.spec_from_file_location('wildstar_m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)
probe_spec = importlib.util.spec_from_file_location('m3_shader_probe', ROOT / 'tools/analysis/m3_shader_probe.py')
probe = importlib.util.module_from_spec(probe_spec)
probe_spec.loader.exec_module(probe)


def audit(path):
    data = path.read_bytes()
    model = m3.read_model(data)
    geometry_count, geometry_offset = struct.unpack_from('<QQ', data, 0x250)
    geometry_offset += m3.HEADER_END
    geometry_base = m3._a16(geometry_offset + geometry_count * 0xC8)
    container = read_sho((ROOT / 'WoWClient/ClientData/Shaders/ModelPS.ps_4_0.sho').read_bytes())
    mapping = container['permutation_to_code']
    result = {
        'model': str(path.relative_to(ROOT)),
        'textures': [dict(index=i, name=t[0], type=t[1], replacementSlot=t[2]) for i, t in enumerate(model.textures)],
        'materials': [], 'meshes': [],
    }
    for mi, mat in enumerate(model.material_info):
        result['materials'].append(dict(index=mi, header=list(mat.header), layers=[
            dict(index=li, color=layer.tex_color, normal=layer.tex_normal, words=list(layer.words),
                 klass=layer.klass, materialType=layer.material_type,
                 parameters={name: {'keys': list(value[0]), 'values': list(value[1])}
                             for name, value in layer.params.items()})
            for li, layer in enumerate(mat.layers)]))
    for gi, geometry in enumerate(model.geometries):
        g = geometry_offset + gi * 0xC8
        vertex_flags = struct.unpack_from('<H', data, g + 0x1E)[0]
        mesh_count, mesh_offset = struct.unpack_from('<QQ', data, g + 0x80)
        mesh_base = geometry_base + mesh_offset
        pass_kind = 0 if geometry.vertex_size < 0x11 else (1 if vertex_flags & 0xF0 else 2)
        for mi in range(mesh_count):
            raw = data[mesh_base + mi * 0x70:mesh_base + (mi + 1) * 0x70]
            material_index = struct.unpack_from('<H', raw, 0x16)[0]
            material = model.material_info[material_index]
            key = probe.permutation(raw, (material_index, material), pass_kind)
            code = mapping[key] if key < len(mapping) else 0xFFFFFFFF
            result['meshes'].append(dict(geometry=gi, mesh=mi, material=material_index, passKind=pass_kind,
                                         permutation=key, code=code, vertices=geometry.meshes[mi].vertex_count,
                                         indices=geometry.meshes[mi].index_count))
    result['summary'] = dict(textures=len(model.textures), skinFx=sum(t[1] == 2 for t in model.textures),
                             materials=len(model.material_info), meshes=len(result['meshes']),
                             vertices=sum(m['vertices'] for m in result['meshes']),
                             indices=sum(m['indices'] for m in result['meshes']),
                             uniquePermutations=sorted(set(m['permutation'] for m in result['meshes'])),
                             missingPermutations=[m['permutation'] for m in result['meshes'] if m['code'] == 0xFFFFFFFF])
    return result


def main():
    folder = ROOT / 'WoWClient/ClientData/Art/Creature/Avatus'
    output = ROOT / 'build_m3test/scratch/avatus_skinfx_sho'
    output.mkdir(parents=True, exist_ok=True)
    reports = []
    for name in ('Avatus.m3', 'Avatus_Gun.m3', 'Avatus_HandLf.m3', 'Avatus_HandRt.m3'):
        report = audit(folder / name)
        reports.append(report)
        print(name, json.dumps(report['summary']))
        for texture in report['textures']:
            if texture['type'] == 2:
                users = []
                for mat in report['materials']:
                    for layer in mat['layers']:
                        if texture['index'] in (layer['color'], layer['normal']):
                            users.append((mat['index'], layer['index'], 'color' if layer['color'] == texture['index'] else 'normal'))
                print(' SkinFX', texture['index'], texture['name'], 'direct layer users', users)
    (output / 'avatus_native_audit.json').write_text(json.dumps(reports, indent=2), encoding='utf-8')
    print('report', output / 'avatus_native_audit.json')


if __name__ == '__main__':
    main()
