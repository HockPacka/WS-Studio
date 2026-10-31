"""Report animation tracks and vertex-color ranges of real M3 assets."""
from pathlib import Path
import importlib.util
import sys

ROOT = Path(__file__).resolve().parents[2]
spec = importlib.util.spec_from_file_location('m3', ROOT / 'tools/blender_addon/wildstar_m3/m3.py')
m3 = importlib.util.module_from_spec(spec)
spec.loader.exec_module(m3)


def main():
    if len(sys.argv) < 2:
        raise SystemExit('usage: m3_animation_color_probe.py model.m3 [...]')
    for arg in sys.argv[1:]:
        path = Path(arg)
        model = m3.read_model(path.read_bytes())
        print('\n', path.relative_to(ROOT) if path.is_absolute() else path, sep='')
        print('clips', [(c.anim_id, c.start, c.end) for c in model.clips])
        print('geometry', [(g.vertex_size, g.field_types) for g in model.geometries])
        print('textures')
        for ti, texture in enumerate(model.textures):
            print(' ', ti, texture)
        print('materials')
        for mi, material in enumerate(model.material_info):
            print(' ', mi, 'header', material.header)
            for li, layer in enumerate(material.layers):
                params = {name: values for name, (times, values) in layer.params.items() if values}
                print('  layer', li, 'textures', (layer.tex_color, layer.tex_normal),
                      'words', layer.words, 'class', layer.klass, 'type', layer.material_type,
                      'params', params)
        animated = []
        for bone in model.bones:
            tracks = [t for t in (bone.scale, bone.parent_scale, bone.rotation, bone.translation,
                                  bone.scale2, bone.parent_scale2, bone.rotation2, bone.translation2) if t]
            if tracks:
                animated.append((bone.index, bone.model_bone_id, sum(len(t.times) for t in tracks)))
        print('animated_bones', animated)
        for mi, material in enumerate(model.material_info):
            for li, layer in enumerate(material.layers):
                for name, (times, values) in layer.params.items():
                    if len(times) > 1:
                        print('material_track', mi, li, name, 'keys', len(times),
                              'times', (min(times), max(times)), 'first', values[0], 'last', values[-1])
        colors = [c for g in model.geometries for c in g.color0]
        if colors:
            means = [sum(c[k] for c in colors) / len(colors) for k in range(4)]
            bright = sum(any(c[k] > 128 for k in range(3)) for c in colors)
            print('color0', 'vertices', len(colors), 'mean', [round(v, 2) for v in means],
                  'brighter_than_neutral', bright, 'range', [(min(c[k] for c in colors), max(c[k] for c in colors)) for k in range(4)])
        else:
            print('color0 absent')


if __name__ == '__main__':
    main()
