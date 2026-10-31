"""blender -b --python tools/export_character_edit_blender.py: simple textured editing assets."""
from pathlib import Path
import sys,csv,math,shutil,json
import bpy
from mathutils import Vector
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/blender_addon/wildstar_m3'))
import m3
DATA=ROOT/'WoWClient/ClientData'
OUT=ROOT/'exports/character_edit_kit'
OUT.mkdir(parents=True,exist_ok=True)
TEX=OUT/'textures';TEX.mkdir(exist_ok=True)
shutil.copy2(ROOT/'build_m3test/character_composition/atlas_22_0.png',TEX/'Human_Skin_Atlas.png')
shutil.copy2(ROOT/'exports/character_clothing_png/Clothing_Atlas_Medium_008.png',TEX/'Clothing_Atlas.png')
bpy.ops.wm.read_factory_settings(use_empty=True)
families={}
with (ROOT/'tools/blender_addon/wildstar_m3/model_mesh.csv').open(encoding='utf-8') as f:
    for row in csv.DictReader(f):families[int(row['ID'])]=row['EnumName'].rstrip('0123456789')

def material(name,image):
    mat=bpy.data.materials.new(name);mat.use_nodes=True
    shader=mat.node_tree.nodes.get('Principled BSDF');shader.inputs['Roughness'].default_value=.8
    tex=mat.node_tree.nodes.new('ShaderNodeTexImage');tex.image=bpy.data.images.load(str(image),check_existing=True)
    mat.node_tree.links.new(tex.outputs['Color'],shader.inputs['Base Color'])
    mat.node_tree.nodes.active=tex
    return mat
skin=material('Skin_Paint_Here',TEX/'Human_Skin_Atlas.png')
armor=material('Armor_Paint_Here',TEX/'Clothing_Atlas.png')

def load(path,collection,mat):
    raw=(DATA/path).read_bytes();a=m3.read_model(raw);minimum={}
    for geo in a.geometries:
        for mesh in geo.meshes:
            if mesh.group not in (0,255):
                family=families.get(mesh.group,'group'+str(mesh.group));minimum[family]=min(minimum.get(family,255),mesh.group)
    result=[]
    for gi,geo in enumerate(a.geometries):
        for mi,mesh in enumerate(geo.meshes):
            if not mesh.index_count or not mesh.vertex_count:continue
            if mesh.group not in (0,255) and mesh.group!=minimum[families.get(mesh.group,'group'+str(mesh.group))]:continue
            ids=geo.indices[mesh.start_index:mesh.start_index+mesh.index_count]
            faces=[tuple(ids[k:k+3]) for k in range(0,len(ids),3)]
            faces=[f for f in faces if len(set(f))==3 and max(f)<mesh.vertex_count]
            if not faces:continue
            positions=geo.positions[mesh.start_vertex:mesh.start_vertex+mesh.vertex_count]
            vertices=[(p[0],-p[2],p[1]) for p in positions]
            name=Path(path.replace('\\','/')).stem+f'_{gi}_{mi}'
            data=bpy.data.meshes.new(name);data.from_pydata(vertices,[],faces);data.update()
            uv=data.uv_layers.new(name='Original_WildStar_UV')
            for loop in data.loops:
                u,v=geo.uv1[mesh.start_vertex+loop.vertex_index];uv.data[loop.index].uv=(u,1-v)
            for poly in data.polygons:poly.use_smooth=True
            obj=bpy.data.objects.new(name,data);collection.objects.link(obj);data.materials.append(mat)
            obj['Original_M3']=path;obj['UV_note']='Original UVs; PNG top-left V converted to Blender bottom-left V'
            result.append(obj)
    return result

body=bpy.data.collections.new('01_BODY_skin');bpy.context.scene.collection.children.link(body)
clothes=bpy.data.collections.new('02_ARMOR_toggle_visibility');bpy.context.scene.collection.children.link(clothes)
base=[]
for path in ['Art/Character/Human/Male/Human_M.m3','Art/Character/Human/Male/Heads/Face_01_Human_M.m3','Art/Character/Human/Male/Heads/Hair_01_Human_M.m3']:
    base+=load(path,body,skin)
outfit=[]
for part in ['Chest','Pants','Boots','Gloves','Shoulders']:
    outfit+=load(f'Art/Item/Armor/Medium/Medium_008/AMR_Medium_Medium_008_{part}_Human_M.m3',clothes,armor)

def select(objects):
    bpy.ops.object.select_all(action='DESELECT')
    for obj in objects:obj.select_set(True)
    bpy.context.view_layer.objects.active=objects[0]

select(base)
bpy.ops.export_scene.gltf(filepath=str(OUT/'Human_Base.glb'),export_format='GLB',use_selection=True,export_animations=False)
bpy.ops.wm.obj_export(filepath=str(OUT/'Human_Base.obj'),export_selected_objects=True,export_materials=True,path_mode='RELATIVE')
select(base+outfit)
bpy.ops.export_scene.gltf(filepath=str(OUT/'Human_With_Armor.glb'),export_format='GLB',use_selection=True,export_animations=False)
scene=bpy.context.scene
points=[v.co for o in base for v in o.data.vertices]
lo=Vector([min(p[i] for p in points) for i in range(3)]);hi=Vector([max(p[i] for p in points) for i in range(3)])
center=(lo+hi)/2;size=max(hi-lo)
camera=bpy.data.objects.new('Preview_Camera',bpy.data.cameras.new('Preview_Camera'));scene.collection.objects.link(camera)
camera.data.type='ORTHO';camera.data.ortho_scale=size*1.2
camera.location=center+Vector((0,-size*3,size*.1));camera.rotation_euler=(center-camera.location).to_track_quat('-Z','Y').to_euler();scene.camera=camera
scene.render.engine='BLENDER_WORKBENCH';scene.render.resolution_x=900;scene.render.resolution_y=900;scene.render.resolution_percentage=100
scene.display.shading.light='STUDIO';scene.display.shading.color_type='TEXTURE';scene.display.shading.show_shadows=True
scene.render.image_settings.file_format='PNG';scene.render.filepath=str(OUT/'Human_With_Armor_preview.png');bpy.ops.render.render(write_still=True)
for o in outfit:o.hide_render=True;o.hide_set(True)
select(base);scene.render.filepath=str(OUT/'Human_Base_preview.png');bpy.ops.render.render(write_still=True)
for image in bpy.data.images:
    if image.source=='FILE':image.filepath='//textures/'+Path(image.filepath).name
for area in bpy.context.screen.areas:
    if area.type=='VIEW_3D':
        area.spaces.active.shading.type='SOLID';area.spaces.active.shading.color_type='TEXTURE';area.spaces.active.region_3d.view_distance=size*1.5;area.spaces.active.region_3d.view_location=center
bpy.ops.wm.save_as_mainfile(filepath=str(OUT/'Human_Edit.blend'))
(OUT/'model_sources.json').write_text(json.dumps(dict(body=[o['Original_M3'] for o in base],armor=[o['Original_M3'] for o in outfit],bodyMeshes=len(base),armorMeshes=len(outfit),triangles=sum(len(o.data.polygons) for o in base+outfit),staticBindPose=True),indent=2))
print('EXPORTED',OUT,'body meshes',len(base),'armor meshes',len(outfit))
