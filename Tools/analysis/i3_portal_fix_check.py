"""Build regression fixtures using the isolated converter, validate the screenshot M3."""
from pathlib import Path
import importlib.util,json,struct,subprocess,sys
ROOT=Path(__file__).resolve().parents[2]
OUT=ROOT/'build_m3test/i3_portal_probe'
BIN=ROOT/'wowdecomp/build/i3_portal_fix/bin/Release'
DATA=ROOT/'WoWClient/ClientData'

def run(*args):
    subprocess.run([str(a) for a in args],cwd=ROOT,check=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)

def main():
    models=json.loads((OUT/'inventory.json').read_text())
    paths=OUT/'native_model_paths.txt'
    paths.write_text('\n'.join(str(DATA/m['path']) for m in models if m['portalsRaw']),encoding='utf-8')
    result=subprocess.run([str(BIN/'portal_geometry_cli.exe'),str(paths)],cwd=ROOT,check=True,capture_output=True,text=True)
    print(result.stdout.strip())
    for name,path in [
        ('pell_small',r'Art\Structure\Model\Building_Kits\Pell\Pell_SmallHouse_001\STR_Building_SmPellHouse_000.i3'),
        ('church',r'Art\Structure\Model\Building_Kits\Imperium\Churches\STR_Imperium_SmallChurch.i3')]:
        run(BIN/'i3_wmo_cli.exe',str(DATA)+'/',path,OUT/(name+'_fixed'))
        run(sys.executable,ROOT/'tools/wmo_check.py',OUT/(name+'_fixed'))
    run(sys.executable,ROOT/'tools/analysis/i3_portal_visibility_probe.py','--fixed')
    print('PASS WMO structure, retained indoor groups, nonempty render loops')
    source=DATA/'Art/Prop/Constructed/House/Pell/Large/PRP_PellHouse_Large_000.m3'
    target=OUT/'pell_house_fixed.m2'
    run(BIN/'m3_to_m2_cli.exe',source,target,OUT/'pell_house_fixed.skin')
    spec=importlib.util.spec_from_file_location('ws_m3',ROOT/'tools/blender_addon/wildstar_m3/m3.py')
    module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    model=module.read_model(source.read_bytes());b=target.read_bytes()
    combo_count,combo_at=struct.unpack_from('<II',b,0x80)
    texture_count,texture_at=struct.unpack_from('<II',b,0x50)
    meshes=[mesh for geo in model.geometries for mesh in geo.meshes]
    skin=(OUT/'pell_house_fixed.skin').read_bytes()
    sections,sections_at=struct.unpack_from('<II',skin,0x1c)
    assert combo_count==sections*8
    checked=[]
    for i in range(sections):
        start,count=struct.unpack_from('<2H',skin,sections_at+i*48+4)
        candidates=[mesh for mesh in meshes if mesh.start_vertex==start and mesh.vertex_count==count]
        assert len(candidates)==1
        mesh=candidates[0]
        material=model.material_info[mesh.material]
        colors=[layer.tex_color for layer in material.layers if 0<=layer.tex_color<len(model.textures)]
        if len(colors)!=1 or 0<=material.layers[0].tex_color<len(model.textures):continue
        combo=struct.unpack_from('<8H',b,combo_at+i*16)
        assert combo[0]==colors[0],(i,colors,combo)
        # A selected texture must actually carry a filename, not the white slot.
        length,offset=struct.unpack_from('<II',b,texture_at+combo[0]*16+8)
        assert length>1 and offset<len(b) and b[offset]!=0
        checked.append(dict(mesh=i,material=mesh.material,color=combo[0],normal=combo[1]))
    assert checked,'fixture no longer exercises a sparse single-layer material'
    (OUT/'sparse_material_fixed.json').write_text(json.dumps(checked,indent=2),encoding='utf-8')
    print('PASS Pell sparse material:',checked)

if __name__=='__main__':main()
