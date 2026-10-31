"""Read-only tree face/material evidence, independent of the WoW renderer."""
from pathlib import Path
from collections import defaultdict
import importlib.util,json,math
ROOT=Path(__file__).resolve().parents[2]
spec=importlib.util.spec_from_file_location('ws_tree_m3',ROOT/'tools/blender_addon/wildstar_m3/m3.py')
m3=importlib.util.module_from_spec(spec);spec.loader.exec_module(m3)
def probe(path):
    model=m3.read_model(path.read_bytes());faces=defaultdict(list);triangles=0
    for gi,g in enumerate(model.geometries):
        for mi,mesh in enumerate(g.meshes):
            for start in range(mesh.start_index,mesh.start_index+mesh.index_count,3):
                ids=[i+mesh.start_vertex for i in g.indices[start:start+3]]
                pts=tuple(tuple(g.positions[i]) for i in ids)
                key=tuple(sorted(pts))
                if len(set(key))!=3:continue
                order=[key.index(p) for p in pts]
                parity=sum(order[a]>order[b] for a in range(3) for b in range(a+1,3))%2
                normals=[g.normals[i] for i in ids]
                normal=tuple(sum(n[k] for n in normals)/3 for k in range(3))
                faces[key].append(dict(geometry=gi,mesh=mi,material=mesh.material,parity=parity,normal=normal))
                triangles+=1
    opposite=[];same=0
    for pts,items in faces.items():
        for i,x in enumerate(items):
            for y in items[i+1:]:
                if x['parity']==y['parity']:same+=1;continue
                nx,ny=x['normal'],y['normal'];length=math.sqrt(sum(a*a for a in nx)*sum(b*b for b in ny))
                dot=sum(a*b for a,b in zip(nx,ny))/length if length else 0
                opposite.append(dict(a=x,b=y,normalDot=dot))
    return dict(model=str(path.relative_to(ROOT/'WoWClient/ClientData')),triangles=triangles,
        coincidentOppositePairs=len(opposite),opposingNormals=sum(p['normalDot']<-.8 for p in opposite),
        coincidentSameWindingPairs=same,examples=opposite[:3],
        materials=[dict(header=list(x.header),layers=[dict(color=l.tex_color,normal=l.tex_normal,modes=list(l.words)) for l in x.layers]) for x in model.material_info],
        textures=[dict(path=t[0],type=t[1]) for t in model.textures],
        hasLayerWeights=any(g.field_types[7]==4 for g in model.geometries))
def main():
    paths=[ROOT/'WoWClient/ClientData/Art/Prop/Natural/Tree'/p for p in [
        'PointyPine/PRP_Tree_PointyPine_000.m3',
        'PointyPine/Algeroc/PRP_Tree_AlgerocPointyPine_000.m3',
        'BridgerPine/PRP_Tree_BridgerPine_Green_000.m3']]
    reports=[probe(p) for p in paths]
    out=ROOT/'build_m3test/tree_normal_probe/surface_report.json';out.parent.mkdir(exist_ok=True)
    out.write_text(json.dumps(reports,indent=2),encoding='utf-8')
    for r in reports:print(Path(r['model']).name, 'triangles=',r['triangles'],'opposite pairs=',r['coincidentOppositePairs'],'opposing normals=',r['opposingNormals'],'layer weights=',r['hasLayerWeights'])
if __name__=='__main__':main()
