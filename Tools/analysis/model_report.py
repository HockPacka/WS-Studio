"""Materials / layers / emitters report of one model. usage: model_report.py model.m3"""
import importlib.util
import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def load(name, rel):
    spec = importlib.util.spec_from_file_location(name, os.path.join(ROOT, rel))
    m = importlib.util.module_from_spec(spec)
    sys.modules[name] = m
    spec.loader.exec_module(m)
    return m


m3 = load('m3', 'tools/blender_addon/wildstar_m3/m3.py')
data = open(sys.argv[1], 'rb').read()
mo = m3.read_model(data)
print('textures')
for i, t in enumerate(mo.textures):
    print('  %2d type %d  %s' % (i, t[1], t[0].replace(chr(92), '/').split('/')[-1]))
print('materials', len(mo.material_info))
for i, mi in enumerate(mo.material_info):
    print(' mat %d header %s' % (i, list(mi.header)))
    for j, l in enumerate(mi.layers):
        par = {k: (round(v[1][0], 3) if v[1] and not isinstance(v[1][0], tuple) else v[1][0] if v[1] else None) for k, v in l.params.items() if k in ('opacity', 'glow', 'gloss', 'color_mod')}
        print('    layer %d color %s normal %s class %d type %d words %s %s' % (j, l.tex_color, l.tex_normal, l.klass, l.material_type, list(l.words), par))
print('meshes')
for g in mo.geometries:
    for me in g.meshes:
        print('  group %d material %d indices %d' % (me.group, me.material, me.index_count))
try:
    em = load('emitter', 'tools/blender_addon/wildstar_m3/emitter.py')
    ems = em.read_emitters(data)
    print('emitters', len(ems))
    for e in ems[:30]:
        print('  #%d type %d bone %d valid %s textures %s' % (e.index, e.type, e.bone, e.valid, e.texture_ids))
except Exception as ex:  # noqa: BLE001
    print('emitter read failed', ex)
