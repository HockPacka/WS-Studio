"""Associate Avatus 0x560 records with meshes through actual vertex skin weights.

The record's first word is a direct bone-array index. This is geometric
association evidence, not a claim that WildStar selects effects per mesh.
"""
import importlib.util
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('wildstar_m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def audit(path, native, records):
    data = path.read_bytes()
    model = m3.read_model(data)
    geometry_count, geometry_offset = struct.unpack_from('<QQ', data, 0x250)
    geometry_offset += m3.HEADER_END
    geometry_base = m3._a16(geometry_offset + geometry_count * 0xC8)
    mesh_infos = {}
    for gi, geometry in enumerate(model.geometries):
        g = geometry_offset + gi * 0xC8
        mesh_count, mesh_offset = struct.unpack_from('<QQ', data, g + 0x80)
        mesh_base = geometry_base + mesh_offset
        for mi, mesh in enumerate(geometry.meshes):
            raw = mesh_base + mi * 0x70
            bone_start, bone_count = struct.unpack_from('<2H', data, raw + 0x10)
            # Native FUN_140310f70 compares mesh +0x1C with the runtime
            # 0x560-record index when attaching SkinFX draw items.
            skinfx_record = struct.unpack_from('<H', data, raw + 0x1C)[0]
            # Mesh indices are local to the mesh's vertex window.
            used_vertices = sorted({mesh.start_vertex + vi for vi in
                                    geometry.indices[mesh.start_index:mesh.start_index + mesh.index_count]})
            influences = []
            for vi in used_vertices:
                for local, weight in zip(geometry.bone_idx[vi], geometry.bone_w[vi]):
                    mapped = bone_start + local
                    if weight and mapped < len(model.bone_map):
                        influences.append((vi, model.bone_map[mapped], weight / 255.0))
            mesh_infos[(gi, mi)] = {
                'boneStart': bone_start, 'boneCount': bone_count,
                'skinFxRecord': skinfx_record,
                'influences': influences, 'usedVertices': used_vertices,
            }

    result = {'model': native['model'], 'bones': [], 'records': []}
    for bi, bone in enumerate(model.bones):
        result['bones'].append({'index': bi, 'modelBoneId': bone.model_bone_id,
                                'parent': bone.parent, 'hash': bone.hash,
                                'pivot': list(bone.pivot)})
    for record in records['skinFxRecords']:
        root = record['words'][0]
        descendants = {root} if root < len(model.bones) else set()
        changed = True
        while changed:
            changed = False
            for bi, bone in enumerate(model.bones):
                if bone.parent in descendants and bi not in descendants:
                    descendants.add(bi)
                    changed = True
        item = {
            'record': record['index'], 'boneIndex': root,
            'bone': result['bones'][root] if root < len(result['bones']) else None,
            'descendantBoneIndices': sorted(descendants),
            'textureA': record['textureA'], 'textureB': record['textureB'],
            'recordMeshes': [], 'directMeshes': [], 'hierarchyMeshes': [],
        }
        for native_mesh in native['meshes']:
            key = (native_mesh['geometry'], native_mesh['mesh'])
            info = mesh_infos[key]
            direct = [x for x in info['influences'] if x[1] == root]
            hierarchy = [x for x in info['influences'] if x[1] in descendants]
            common = {
                'geometry': key[0], 'mesh': key[1], 'material': native_mesh['material'],
                'permutation': native_mesh['permutation'],
                'usedVertexCount': len(info['usedVertices']),
            }
            if info['skinFxRecord'] == record['index']:
                item['recordMeshes'].append(dict(common))
            if direct:
                weighted_vertices = {x[0] for x in direct}
                item['directMeshes'].append(dict(common,
                    weightedVertexCount=len(weighted_vertices),
                    influenceWeightSum=sum(x[2] for x in direct),
                    maximumVertexWeight=max(sum(x[2] for x in direct if x[0] == vi) for vi in weighted_vertices)))
            if hierarchy:
                weighted_vertices = {x[0] for x in hierarchy}
                item['hierarchyMeshes'].append(dict(common,
                    weightedVertexCount=len(weighted_vertices),
                    influenceWeightSum=sum(x[2] for x in hierarchy),
                    maximumVertexWeight=max(sum(x[2] for x in hierarchy if x[0] == vi) for vi in weighted_vertices)))
        result['records'].append(item)
    return result


def main():
    folder = ROOT / 'WoWClient/ClientData/Art/Creature/Avatus'
    scratch = ROOT / 'build_m3test/scratch/avatus_skinfx_sho'
    native_reports = json.loads((scratch / 'avatus_native_audit.json').read_text(encoding='utf-8'))
    skinfx_reports = json.loads((scratch / 'avatus_skinfx_records.json').read_text(encoding='utf-8'))
    reports = []
    for native, records in zip(native_reports, skinfx_reports):
        path = ROOT / native['model']
        report = audit(path, native, records)
        reports.append(report)
        print(path.name)
        for record in report['records']:
            bone = record['bone']
            print(f"  record {record['record']} bone {record['boneIndex']} "
                  f"modelBoneId={bone['modelBoneId'] if bone else 'invalid'}")
            print('    recordMeshes', [(m['geometry'], m['mesh'], m['material'],
                                          hex(m['permutation'])) for m in record['recordMeshes']])
            for kind in ('directMeshes', 'hierarchyMeshes'):
                print('   ', kind, [(m['geometry'], m['mesh'], m['material'],
                                     hex(m['permutation']), m['weightedVertexCount'],
                                     round(m['maximumVertexWeight'], 4)) for m in record[kind]])
    output = scratch / 'avatus_skinfx_mesh_audit.json'
    output.write_text(json.dumps(reports, indent=2), encoding='utf-8')
    print('report', output)


if __name__ == '__main__':
    main()
