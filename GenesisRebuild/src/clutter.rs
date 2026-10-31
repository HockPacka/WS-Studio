//! Genesis clutter instancing foundation (diagnostic preview, not a WildStar
//! WorldClutter.tbl reproduction). Bevy's opaque/masked Mesh3d renderer can
//! automatically GPU-instance separate entities when each uses the EXACT
//! SAME Mesh and Material asset handles. Never create assets per instance.
//!
//! Native bit27 selector and bit16 (0x20) suppression mask are respected.
//! WorldClutter.tbl weighted asset selection and density are NOT decoded yet;
//! the editor selects one existing M3 model for an explicit diagnostic preview.
use bevy::prelude::*;
use wildstar_formats::area::{HeightGrid,RawArea};

use crate::{GenesisState,LoadedArea,OrbitCamera};
use crate::client_data::ClientFiles;
use crate::terrain_edit::TerrainEdit;

const GRID:usize=257;
const CELL_GRID:usize=16;

#[derive(Debug,Clone,Copy)]
pub struct Placement {
    pub cell:usize,
    pub local:Vec3,
    pub yaw:f32,
    pub scale:f32,
}
#[derive(Resource,Default)]
pub struct ClutterPreview {
    roots:Vec<(Entity,Vec3)>,
    pub instances:usize,
    pub parts_per_instance:usize,
    pub opaque_parts:usize,
    pub transparent_parts:usize,
    pub rejected_by_mask:usize,
    pub rejected_by_selector:usize,
    pub rejected_by_weight:usize,
    pub rejected_by_slope:usize,
    pub status:String,
    seen_request:u64,
    source:Option<std::path::PathBuf>,
    last_camera:Option<Vec3>,
    last_cutoff:f32,
}
fn next(random:&mut u32)->f32{
    *random^=*random<<13;
    *random^=*random>>17;
    *random^=*random<<5;
    (*random as f32)/(u32::MAX as f32)
}
fn sample_height(grid:&HeightGrid,x:f32,z:f32)->Option<(f32,f32)>{
    if !(0.0..=256.0).contains(&x)||!(0.0..=256.0).contains(&z){
        return None;
    }
    let ax=x.floor().min(255.0) as usize;
    let az=z.floor().min(255.0) as usize;
    let tx=(x-ax as f32).clamp(0.0,1.0);
    let tz=(z-az as f32).clamp(0.0,1.0);
    let ids=[
        az*GRID+ax,az*GRID+ax+1,
        (az+1)*GRID+ax,(az+1)*GRID+ax+1,
    ];
    if ids.iter().any(|&i|!grid.present.get(i).copied().unwrap_or(false)){
        return None;
    }
    let heights=ids.map(|i|grid.heights[i]);
    let top=heights[0]+(heights[1]-heights[0])*tx;
    let bottom=heights[2]+(heights[3]-heights[2])*tx;
    let slope=((heights[1]-heights[0]).abs()
        .max((heights[3]-heights[2]).abs())
        .max((heights[2]-heights[0]).abs())
        .max((heights[3]-heights[1]).abs()))*0.5;
    Some((top+(bottom-top)*tz,slope))
}
fn weight(cell:&wildstar_formats::area::AreaCell,x:usize,z:usize,layer:usize)
    ->Option<f32>
{
    // Bits 29/2 store 0..15 nibbles. Normalize the actual sum so sparse
    // authoring maps do not create fictitious extra layer strength.
    if let Some(raw)=cell.normalized_weights(x,z)
        .or_else(||cell.authoring_weights(x,z))
    {
        let sum=raw.iter().map(|&v|v as f32).sum::<f32>();
        return (sum>0.0).then(||raw[layer] as f32/sum);
    }
    cell.compressed_weights(x,z).map(|raw|raw[layer])
}
#[derive(Default)]
struct Generated {
    instances:Vec<Placement>,
    masked:usize,
    selector:usize,
    weight:usize,
    slope:usize,
}
fn placements(
    area:&RawArea,grid:&HeightGrid,layer:usize,selector:u8,
    density:usize,limit:usize,
)->Generated{
    let mut result=Generated::default();
    if layer>3||selector>3||density==0||limit==0{return result;}
    for cell_index in 0..256usize{
        if result.instances.len()>=limit{break;}
        let Some(cell)=area.cells[cell_index].as_ref() else{continue;};
        // Do not assume that a terrain layer is usable without its native IDs.
        let Some(layer_ids)=cell.layers() else{continue;};
        if layer_ids[layer]==0 || cell.block(27).is_none() ||
            cell.block(16).is_none() {continue;}
        let cx=cell_index%CELL_GRID;
        let cz=cell_index/CELL_GRID;
        let mut rand=(cell_index as u32).wrapping_mul(0x9E3779B1)
            ^ 0xA341316C ^ ((layer as u32)<<9) ^ ((selector as u32)<<16);
        for _ in 0..density.min(128){
            if result.instances.len()>=limit{break;}
            let x=next(&mut rand)*63.999;
            let z=next(&mut rand)*63.999;
            let sx=x as usize;
            let sz=z as usize;
            if cell.zone_flag(sx,sz).is_some_and(|flags|flags&0x20!=0){
                result.masked+=1;continue;
            }
            if cell.clutter_selector(sx,sz,layer)!=Some(selector) {
                result.selector+=1;continue;
            }
            let Some(strength)=weight(cell,sx,sz,layer) else{
                result.weight+=1;continue;
            };
            if strength<0.25||next(&mut rand)>strength {
                result.weight+=1;continue;
            }
            let vx=cx as f32*16.0+x*0.25;
            let vz=cz as f32*16.0+z*0.25;
            let Some((height,slope))=sample_height(grid,vx,vz) else{
                result.slope+=1;continue;
            };
            // This is a conservative research-preview filter, not the
            // verified WildStar clutter worker's slope distribution.
            if slope>1.0 {result.slope+=1;continue;}
            result.instances.push(Placement{
                cell:cell_index,
                local:Vec3::new(vx*2.0-256.0,height,vz*2.0-256.0),
                yaw:next(&mut rand)*std::f32::consts::TAU,
                scale:0.85+next(&mut rand)*0.30,
            });
        }
    }
    result
}
fn destroy(commands:&mut Commands,preview:&mut ClutterPreview){
    for (root,_) in preview.roots.drain(..){
        commands.entity(root).despawn();
    }
    preview.instances=0;
    preview.parts_per_instance=0;
    preview.opaque_parts=0;
    preview.transparent_parts=0;
    preview.last_camera=None;
    preview.last_cutoff=0.0;
    preview.transparent_parts=0;
    preview.rejected_by_mask=0;
    preview.rejected_by_selector=0;
    preview.rejected_by_weight=0;
    preview.rejected_by_slope=0;
}
pub fn update_preview(
    mut commands:Commands,
    state:Res<GenesisState>,
    loaded:Res<LoadedArea>,
    edit:Res<TerrainEdit>,
    client:Res<ClientFiles>,
    orbit:Res<OrbitCamera>,
    mut preview:ResMut<ClutterPreview>,
    mut meshes:ResMut<Assets<Mesh>>,
    mut materials:ResMut<Assets<StandardMaterial>>,
    mut images:ResMut<Assets<Image>>,
){
    // Always dispose previous tile's entities, even when preview is off.
    if preview.source!=edit.source {
        destroy(&mut commands,&mut preview);
        preview.source=edit.source.clone();
        preview.status="Open a standalone AREA and select a native M3 model.".into();
    }
    if state.clutter_preview_request!=preview.seen_request{
        preview.seen_request=state.clutter_preview_request;
        destroy(&mut commands,&mut preview);
        if !state.clutter_preview_enabled{
            preview.status="Clutter debug instancing preview disabled.".into();
        }else if let (Some(area),Some(grid),Some(index))=
            (loaded.tile.as_ref(),edit.grid(),client.index.as_ref())
        {
            let path=state.clutter_model_path.trim();
            let mut budget=1;
            match client.prop_models.load(
                index,&mut meshes,&mut materials,&mut images,path,&mut budget
            ){
                Some(model)=>{
                    let mut eligible=Vec::new();
                    for part in &model.parts{
                        let Some(mat)=materials.get(&part.material) else{continue;};
                        // Bevy automatically instances opaque/masked PBR meshes
                        // with common handles. Blend/Add materials must be
                        // separately sorted and are excluded from this preview.
                        let opaque=matches!(mat.alpha_mode,AlphaMode::Opaque|AlphaMode::Mask(_));
                        if opaque {eligible.push(part.clone());}
                        else{preview.transparent_parts+=1;}
                    }
                    if eligible.is_empty(){
                        preview.status="M3 model has no opaque/cutout drawable parts for GPU batching.".into();
                        return;
                    }
                    let generated=placements(
                        area,&grid,state.clutter_layer,state.clutter_selector,
                        state.clutter_density as usize,
                        state.clutter_instance_limit as usize
                    );
                    preview.rejected_by_mask=generated.masked;
                    preview.rejected_by_selector=generated.selector;
                    preview.rejected_by_weight=generated.weight;
                    preview.rejected_by_slope=generated.slope;
                    preview.parts_per_instance=eligible.len();
                    preview.opaque_parts=eligible.len();
                    let origin=edit.origin;
                    let mut by_cell=std::collections::BTreeMap::<usize,Vec<Placement>>::new();
                    for item in generated.instances {
                        by_cell.entry(item.cell).or_default().push(item);
                    }
                    for (cell,items) in by_cell{
                        let center=Vec3::new(origin.x+(cell%16) as f32*32.0-240.0,
                            0.0,origin.y+(cell/16) as f32*32.0-240.0);
                        // Root is at world origin; child instances carry world
                        // transforms so shared mesh handles can be batched.
                        let root=commands.spawn((
                            Transform::default(),Visibility::Inherited,
                        )).id();
                        for item in items{
                            let xyz=Vec3::new(origin.x+item.local.x,item.local.y,
                                origin.y+item.local.z);
                            let rotation=Quat::from_rotation_y(item.yaw);
                            let t=Transform{
                                translation:xyz,rotation,
                                scale:Vec3::splat(item.scale),
                            };
                            for part in &eligible{
                                let instance=commands.spawn((
                                    Mesh3d(part.mesh.clone()),
                                    MeshMaterial3d(part.material.clone()),
                                    t,
                                )).id();
                                commands.entity(root).add_child(instance);
                            }
                            preview.instances+=1;
                        }
                        preview.roots.push((root,center));
                    }
                    preview.status=format!(
                        "{} diagnostic instances, {} reused mesh parts, {} material groups; not native WorldClutter generation",
                        preview.instances,preview.opaque_parts,
                        preview.opaque_parts
                    );
                },
                None=>{
                    preview.status="M3 not available from ClientData; enter an indexed virtual .m3 path.".into();
                },
            }
        }else{
            preview.status="Standalone AREA and indexed ClientData required.".into();
        }
    }
    if preview.roots.is_empty(){return;}
    let camera=orbit.origin();
    let cutoff=state.clutter_view_distance.max(32.0);
    if preview.last_cutoff==cutoff &&
        preview.last_camera.is_some_and(|last|last.distance_squared(camera)<16.0){
        return;
    }
    preview.last_camera=Some(camera);
    preview.last_cutoff=cutoff;
    let square=cutoff*cutoff;
    for &(entity,center) in &preview.roots{
        // Cull spatial groups on X/Z, not arbitrary terrain elevation.
        let d=(camera.x-center.x).powi(2)+(camera.z-center.z).powi(2);
        commands.entity(entity).insert(
            if d<=square {Visibility::Inherited}else{Visibility::Hidden}
        );
    }
}

#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn deterministic_rng_matches_with_fixed_cell_seed(){
        let mut a=0x9324_A801;
        let mut b=a;
        for _ in 0..250{
            assert_eq!(next(&mut a),next(&mut b));
        }
    }
    fn test_area(blocked:bool,selector:u8)->(RawArea,HeightGrid){
        let mut raw=vec![None;32];
        let mut layers=Vec::new();
        for layer in [71u32,0,0,0] {
            layers.extend(layer.to_le_bytes());
        }
        raw[1]=Some(layers);
        let mut weightmap=vec![0u8;65*65*2];
        for bytes in weightmap.chunks_exact_mut(2){
            bytes.copy_from_slice(&0x000Fu16.to_le_bytes());
        }
        raw[2]=Some(weightmap);
        raw[16]=Some(vec![if blocked{0x20}else{0};64*64]);
        raw[27]=Some(vec![selector;64*64]);
        let cell=wildstar_formats::area::AreaCell{
            index:0,flags:(1<<1)|(1<<2)|(1<<16)|(1<<27),
            blocks:raw,subchunks:Vec::new(),
        };
        let mut cells=vec![None;256];
        cells[0]=Some(cell);
        let a=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None};
        let g=HeightGrid{
            heights:vec![0.0;GRID*GRID],
            present:vec![true;GRID*GRID],
            cells:1,min:0.0,max:0.0,
        };
        (a,g)
    }
    #[test]
    fn selector_mask_weights_and_budgets_gate_deterministic_generation(){
        let (area,grid)=test_area(false,0);
        let a=placements(&area,&grid,0,0,32,12);
        let b=placements(&area,&grid,0,0,32,12);
        assert_eq!(a.instances.len(),12);
        assert_eq!(a.instances.len(),b.instances.len());
        for (a,b) in a.instances.iter().zip(&b.instances){
            assert_eq!(a.local,b.local);
            assert_eq!(a.yaw,b.yaw);
            assert_eq!(a.scale,b.scale);
            assert_eq!(a.cell,0);
        }
        assert!(placements(&area,&grid,0,1,32,50).instances.is_empty());
        assert!(placements(&area,&grid,1,0,32,50).instances.is_empty());
        let (blocked,grid)=test_area(true,0);
        let result=placements(&blocked,&grid,0,0,32,50);
        assert_eq!(result.instances.len(),0);
        assert_eq!(result.masked,32);
    }
    #[test]
    fn missing_native_clutter_blocks_produce_no_guessed_instances(){
        let area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells:vec![None;256],lod_prefix:None};
        let grid=HeightGrid{heights:vec![0.0;GRID*GRID],
            present:vec![true;GRID*GRID],cells:256,min:0.0,max:0.0};
        assert!(placements(&area,&grid,0,0,100,500).instances.is_empty());
    }
}
