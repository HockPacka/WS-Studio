//! Native table-driven clutter placement, using the shared-M3 instancing renderer.
//! This reads WorldLayer.tbl and WorldClutter.tbl, and never writes AREA files.
//! Candidate limits/RNG/slope rules are an explicit preview approximation;
//! they are NOT claimed to be identical to the original retail worker.
use bevy::prelude::*;
use std::{collections::HashMap,path::Path};
use wildstar_formats::{
    area::{AreaCell,HeightGrid,RawArea},
    assets::AssetIndex,
    tbl::{ClutterAsset,Table,WorldClutter,WorldLayer,world_clutters,world_layers},
};
use crate::clutter::{next,sample_height,weight};
use crate::terrain_paint::TerrainPaint;

#[derive(Clone,Debug,PartialEq)]
pub struct NativePlacement {
    pub cell:usize,
    pub position:Vec3,
    pub yaw:f32,
    pub scale:f32,
    pub model:String,
}
#[derive(Default)]
pub struct NativeGenerated {
    pub placements:Vec<NativePlacement>,
    pub populated_cells:usize,
    pub suppressed:usize,
    pub rejected_weights:usize,
    pub rejected_density:usize,
    pub rejected_preset:usize,
    pub rejected_asset:usize,
    pub rejected_slope:usize,
}
pub struct Catalog {
    pub layers:HashMap<u32,WorldLayer>,
    pub presets:HashMap<u32,WorldClutter>,
}
fn table_from_index(index:&AssetIndex,name:&str)->Result<Table,String>{
    // Prefer the native ClientData\DB file; a filename-only fallback is
    // allowed for differently packed client roots, but never a guessed row.
    let file=index.resolve(&format!("DB/{name}"))
        .or_else(||index.find_name(name).into_iter().next())
        .ok_or_else(||format!("Clutter: {name} not found in ClientData index"))?;
    Table::read_file(&file.path)
}
pub fn load_catalog(index:&AssetIndex)->Result<Catalog,String>{
    let layers=world_layers(&table_from_index(index,"WorldLayer.tbl")?)?;
    let presets=world_clutters(&table_from_index(index,"WorldClutter.tbl")?)?;
    if layers.is_empty()||presets.is_empty(){
        return Err("Clutter: empty WorldLayer/WorldClutter database".into());
    }
    Ok(Catalog{layers,presets})
}
fn tile_seed(source:&Path)->u32{
    // Stable source-area identity independent from HashMap iteration and
    // installation path, unlike a process-randomized Rust default hasher.
    let stem=source.file_name().unwrap_or_default().to_string_lossy();
    stem.bytes().fold(2166136261u32,|hash,b|
        (hash^(b.to_ascii_lowercase() as u32)).wrapping_mul(16777619))
}
fn blended_weights(cell:&AreaCell,cell_index:usize,x:f32,z:f32,
    paint:Option<&TerrainPaint>)->Option<[f32;4]>{
    let ix=x.floor().min(63.0) as usize;
    let iz=z.floor().min(63.0) as usize;
    let tx=x-ix as f32;
    let tz=z-iz as f32;
    let mut result=[0.0f32;4];
    for (k,out) in result.iter_mut().enumerate(){
        let sample=|x,z|{
            paint.and_then(|p|p.clutter_weight_at(cell_index,x,z,k))
                .or_else(||weight(cell,x,z,k))
        };
        let v00=sample(ix,iz)?;
        let v10=sample(ix+1,iz)?;
        let v01=sample(ix,iz+1)?;
        let v11=sample(ix+1,iz+1)?;
        let a=v00+(v10-v00)*tx;
        let b=v01+(v11-v01)*tx;
        let w=(a+(b-a)*tz).max(0.0);
        *out=w*w;
    }
    let sum=result.iter().sum::<f32>();
    (sum>0.0&&sum.is_finite()).then(||result.map(|w|w/sum))
}
fn choose_asset(preset:&WorldClutter,roll:f32)->Option<&ClutterAsset>{
    let valid=|a:&&ClutterAsset|{
        a.path.to_ascii_lowercase().ends_with(".m3") &&
        a.weight.is_finite()&&a.weight>0.0 &&
        a.min_scale.is_finite()&&a.min_scale>0.0 &&
        a.rotation_min.is_finite()&&a.rotation_max.is_finite()
    };
    let total=preset.assets.iter().filter(valid).map(|a|a.weight).sum::<f32>();
    if total<=0.0||!total.is_finite(){return None;}
    let mut remaining=roll*total;
    let mut last=None;
    for asset in preset.assets.iter().filter(valid){
        last=Some(asset);
        remaining-=asset.weight;
        if remaining<=0.0{return Some(asset);}
    }
    last
}
/// Native source metadata determines layer, selector, preset and model.
/// Candidate budget uses 1/8 of the documented source worker count, limited
/// by the UI. This prevents constructing tens of thousands of entities in
/// one editor frame while retaining density ratios and weighted M3 choices.
/// Whole-tile facade preserved for future batch preview/CLI generation.
#[allow(dead_code)]
pub fn generate(
    area:&RawArea,grid:&HeightGrid,catalog:&Catalog,source:&Path,
    trials_per_cell:usize,instance_limit:usize,
)->NativeGenerated{
    generate_with_paint(area,grid,catalog,source,trials_per_cell,
        instance_limit,None)
}
/// Identical native selection, but samples live editable WorldLayer weights.
/// Assemble exactly the same per-cell placements in native cell order.
/// Global cap is applied only when collecting outputs. Individual cell RNG
/// streams are independent and can be cached/recomputed without affecting
/// placements in other cells.
/// Whole-tile facade preserved for a future all-cells rebuild action.
#[allow(dead_code)]
pub fn generate_with_paint(
    area:&RawArea,grid:&HeightGrid,catalog:&Catalog,source:&Path,
    trials_per_cell:usize,instance_limit:usize,paint:Option<&TerrainPaint>,
)->NativeGenerated{
    let mut out=NativeGenerated::default();
    if trials_per_cell==0||instance_limit==0{return out;}
    for index in 0..256 {
        if out.placements.len()>=instance_limit{break;}
        let cell=generate_cell_with_paint(area,grid,catalog,source,index,
            trials_per_cell,paint);
        out.populated_cells+=cell.populated_cells;
        out.suppressed+=cell.suppressed;
        out.rejected_weights+=cell.rejected_weights;
        out.rejected_density+=cell.rejected_density;
        out.rejected_preset+=cell.rejected_preset;
        out.rejected_asset+=cell.rejected_asset;
        out.rejected_slope+=cell.rejected_slope;
        let remaining=instance_limit-out.placements.len();
        out.placements.extend(cell.placements.into_iter().take(remaining));
    }
    out
}

/// Generate one standalone 32 m native AREA cell with its independent RNG.
/// No global instance cap is applied here; callers may cache the candidates.
pub fn generate_cell_with_paint(
    area:&RawArea,grid:&HeightGrid,catalog:&Catalog,source:&Path,
    index:usize,trials_per_cell:usize,paint:Option<&TerrainPaint>,
)->NativeGenerated{
    let mut out=NativeGenerated::default();
    if index>=256||trials_per_cell==0{return out;}
    let seed=tile_seed(source);
        let Some(cell)=area.cells[index].as_ref() else{return out;};
        let Some(ids)=cell.layers() else{return out;};
        let mut mapping:[[Option<&WorldClutter>;4];4]=[[None;4];4];
        let mut max_density=0.0f32;
        for slot in 0..4{
            let Some(layer)=catalog.layers.get(&ids[slot]) else{continue;};
            for selector in 0..4{
                if let Some(preset)=catalog.presets.get(&layer.clutter_ids[selector]){
                    if preset.density>0.0&&preset.density.is_finite(){
                        mapping[slot][selector]=Some(preset);
                        max_density=max_density.max(preset.density);
                    }
                }
            }
        }
        if max_density<=0.0{return out;}
        out.populated_cells+=1;
        let mut rng=seed^(index as u32).wrapping_mul(0x9E3779B1)^0xA341316C;
        if rng==0{rng=0x9E3779B9;}
        // Original source attempts: min(8000, density*16).
        // Preview uses the documented dbg43 1/8 budget.
        let ideal=(max_density*2.0).min(1000.0)
            .min(trials_per_cell.min(128) as f32);
        let mut attempts=ideal.floor() as usize;
        if next(&mut rng)<ideal.fract(){attempts+=1;}
        for _ in 0..attempts{
            let x=next(&mut rng)*32.0;
            let z=next(&mut rng)*32.0;
            let layer_roll=next(&mut rng);
            let density_roll=next(&mut rng);
            let asset_roll=next(&mut rng);
            let scale_roll=next(&mut rng);
            let rotation_roll=next(&mut rng);
            let px=(x*2.0).floor().min(63.0) as usize;
            let pz=(z*2.0).floor().min(63.0) as usize;
            if cell.zone_flag(px,pz).is_some_and(|flags|flags&0x20!=0){
                out.suppressed+=1;continue;
            }
            let weights=blended_weights(cell,index,x*2.0,z*2.0,paint)
                .or_else(||(0..4).find(|&slot|catalog.layers.contains_key(&ids[slot]))
                    .map(|slot|std::array::from_fn(|k|if k==slot{1.0}else{0.0})));
            let Some(weights)=weights else{
                out.rejected_weights+=1;continue;
            };
            let mut layer=0usize;
            let mut r=layer_roll;
            while layer<3 {
                r-=weights[layer];
                if r<=0.0 {break;}
                layer+=1;
            }
            if weights[layer]<0.25{
                out.rejected_weights+=1;continue;
            }
            let selector=cell.clutter_selector(px,pz,layer)
                .unwrap_or(0) as usize;
            let Some(preset)=mapping[layer][selector] else{
                out.rejected_preset+=1;continue;
            };
            if density_roll*max_density>=preset.density{
                out.rejected_density+=1;continue;
            }
            let Some(asset)=choose_asset(preset,asset_roll) else{
                out.rejected_asset+=1;continue;
            };
            // 32 m cell, 2 m vertex grid, 0.5 m per clutter selector pixel.
            let vx=(index%16) as f32*16.0+x*0.5;
            let vz=(index/16) as f32*16.0+z*0.5;
            let Some((height,slope))=sample_height(grid,vx,vz) else{
                out.rejected_slope+=1;continue;
            };
            // Preview-only conservative slope guard; original orientations
            // and source-world seeds have not been conclusively reconstructed.
            if height>=3000.0||slope>1.0{
                out.rejected_slope+=1;continue;
            }
            let scale=asset.min_scale+
                scale_roll*(1.0-asset.min_scale);
            let rotation=asset.rotation_min+
                rotation_roll*(asset.rotation_max-asset.rotation_min);
            out.placements.push(NativePlacement{
                cell:index,
                position:Vec3::new(vx*2.0-256.0,height,vz*2.0-256.0),
                yaw:rotation,scale,
                model:asset.path.replace('\\',"/"),
            });
        }
    out
}

#[cfg(test)]
mod tests {
    use super::*;
    use wildstar_formats::area::AreaCell;
    use std::path::PathBuf;
    fn fixture()->(RawArea,HeightGrid,Catalog){
        let mut blocks=vec![None;32];
        let mut ids=Vec::new();
        for id in [11u32,0,0,0]{ids.extend(id.to_le_bytes());}
        blocks[1]=Some(ids);
        let mut weights=vec![0u8;65*65*2];
        for px in weights.chunks_exact_mut(2){
            px.copy_from_slice(&0x000fu16.to_le_bytes());
        }
        blocks[2]=Some(weights);
        blocks[16]=Some(vec![0u8;64*64]);
        blocks[27]=Some(vec![1u8;64*64]);
        let cell=AreaCell{index:0,flags:(1<<1)|(1<<2)|(1<<16)|(1<<27),
            blocks,subchunks:Vec::new()};
        let mut cells=vec![None;256];
        cells[0]=Some(cell);
        let area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None};
        let grid=HeightGrid{heights:vec![0.0;257*257],
            present:vec![true;257*257],cells:1,min:0.0,max:0.0};
        let layer=WorldLayer{id:11,color_map:String::new(),
            normal_map:String::new(),meters_per_tile:8.0,
            clutter_ids:[0,42,0,0]};
        let mut assets=std::array::from_fn(|_|ClutterAsset::default());
        assets[0]=ClutterAsset{path:"Art/Flora/Plant_A.m3".into(),
            weight:1.0,min_scale:0.5,rotation_min:-1.0,
            rotation_max:1.0,..Default::default()};
        assets[5]=ClutterAsset{path:"Art/Flora/Plant_B.m3".into(),
            weight:2.0,min_scale:0.75,rotation_min:-2.0,
            rotation_max:2.0,..Default::default()};
        let preset=WorldClutter{id:42,density:100.0,flags:0,assets};
        let catalog=Catalog{layers:HashMap::from([(11,layer)]),
            presets:HashMap::from([(42,preset)])};
        (area,grid,catalog)
    }
    #[test]
    fn selected_native_preset_produces_deterministic_weighted_models(){
        let (area,grid,catalog)=fixture();
        let source=PathBuf::from("Western.393b.area");
        let a=generate(&area,&grid,&catalog,&source,64,32);
        let b=generate(&area,&grid,&catalog,&source,64,32);
        assert_eq!(a.placements,b.placements);
        assert_eq!(a.placements.len(),32);
        assert!(a.placements.iter().all(|p|
            p.model.ends_with(".m3")&&p.cell==0&&
            (0.5..=1.0).contains(&p.scale)));
        assert!(a.placements.iter().any(|p|p.model.contains("Plant_B")));
    }
    #[test]
    fn no_clutter_and_mismatched_selectors_do_not_spawn(){
        let (mut area,grid,catalog)=fixture();
        let first=area.cells[0].as_mut().unwrap();
        first.blocks[16].as_mut().unwrap().fill(0x20);
        let source=Path::new("Western.393b.area");
        let masked=generate(&area,&grid,&catalog,source,32,100);
        assert!(masked.placements.is_empty());
        assert_eq!(masked.suppressed,32);
        area.cells[0].as_mut().unwrap().blocks[16].as_mut().unwrap().fill(0);
        area.cells[0].as_mut().unwrap().blocks[27].as_mut().unwrap().fill(2);
        let unmatched=generate(&area,&grid,&catalog,source,32,100);
        assert!(unmatched.placements.is_empty());
        assert_eq!(unmatched.rejected_preset,32);
    }
    #[test]
    fn cached_per_cell_generation_matches_full_generation_and_global_cap(){
        let (area,grid,catalog)=fixture();
        let source=Path::new("Western.393b.area");
        let cell=generate_cell_with_paint(&area,&grid,&catalog,source,0,64,None);
        let full=generate_with_paint(&area,&grid,&catalog,source,64,500,None);
        assert_eq!(cell.placements,full.placements);
        let bounded=generate_with_paint(&area,&grid,&catalog,source,64,5,None);
        assert_eq!(bounded.placements,cell.placements[..5].to_vec());
        let absent=generate_cell_with_paint(&area,&grid,&catalog,source,1,64,None);
        assert!(absent.placements.is_empty());
        assert!(generate_cell_with_paint(&area,&grid,&catalog,source,256,64,None)
            .placements.is_empty());
    }
    #[test]
    fn missing_database_and_zero_density_do_not_invent_vegetation(){
        let (area,grid,mut catalog)=fixture();
        catalog.presets.clear();
        assert!(generate(&area,&grid,&catalog,Path::new("A.area"),128,512)
            .placements.is_empty());
        assert!(generate(&area,&grid,&catalog,Path::new("A.area"),0,512)
            .placements.is_empty());
    }
}
