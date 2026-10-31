"""Inventory animation data of M3 models actually referenced by SKY files."""
from pathlib import Path
import importlib.util
import json
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from sky_reader import read_sky
spec = importlib.util.spec_from_file_location('m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def main():
    data = ROOT / 'WoWClient/ClientData'
    output = ROOT / 'build_m3test/scratch/sky_animation_dark_m3/sky_animation_inventory.json'
    references = {}
    skies = sorted((data / 'Sky').glob('*.sky'))
    for sky_path in skies:
        sky = read_sky(sky_path.read_bytes())
        for model in sky['models']:
            rel = model['path'].replace('\\', '/')
            references.setdefault(rel, []).append(sky_path.name)
    rows = []
    for index, (rel, users) in enumerate(sorted(references.items())):
        path = data / rel
        row = {'path': rel, 'skyFiles': sorted(set(users)), 'exists': path.is_file()}
        if path.is_file():
            try:
                model = m3.read_model(path.read_bytes())
                bone_tracks = []
                for bone in model.bones:
                    tracks = [t for t in (bone.scale, bone.parent_scale, bone.rotation, bone.translation,
                                          bone.scale2, bone.parent_scale2, bone.rotation2, bone.translation2)
                              if t and len(t.times) > 1]
                    if tracks:
                        bone_tracks.append({'bone': bone.model_bone_id, 'keys': sum(len(t.times) for t in tracks)})
                material_tracks = []
                for mi, material in enumerate(model.material_info):
                    for li, layer in enumerate(material.layers):
                        for name, (times, values) in layer.params.items():
                            if len(times) > 1:
                                material_tracks.append({'material': mi, 'layer': li, 'parameter': name,
                                                        'keys': len(times), 'startMs': min(times), 'endMs': max(times)})
                row.update(clips=[{'id': c.anim_id, 'variant': c.variant, 'startMs': c.start, 'endMs': c.end}
                                  for c in model.clips],
                           vertexSizes=[g.vertex_size for g in model.geometries],
                           color0=any(g.color0 for g in model.geometries),
                           animatedBones=bone_tracks, animatedMaterials=material_tracks)
            except Exception as exc:
                row['error'] = str(exc)
        rows.append(row)
        if (index + 1) % 50 == 0:
            print(f'{index + 1}/{len(references)} Modelle', flush=True)
    animated = [r for r in rows if r.get('animatedBones') or r.get('animatedMaterials')]
    report = {'skyFiles': len(skies), 'uniqueModels': len(rows), 'animatedModels': animated, 'models': rows}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding='utf-8')
    print(f'SKY-Dateien={len(skies)}, referenzierte M3={len(rows)}, mit Bone-/Material-Keyframes={len(animated)}')
    for row in animated:
        print(row['path'], 'Bones=', row['animatedBones'], 'Materialien=', row['animatedMaterials'])
    print('Bericht:', output)


if __name__ == '__main__':
    main()
