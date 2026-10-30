//! Minimal honest WildStar terrain-material preview.
//! A CPU-composited atlas uses real WorldLayer.tbl paths, real TEX pixels and
//! the four AREA cell weight channels. It is uploaded as a Bevy Image and
//! rendered by StandardMaterial. It is NOT the final WildStar GPU shader.
use bevy::asset::RenderAssetUsages;
use bevy::prelude::*;
use bevy::render::render_resource::{Extent3d,TextureDimension,TextureFormat};
use std::collections::{HashMap,HashSet};
use wildstar_formats::area::{RawArea,AreaCell};
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::tbl::{Table,WorldLayer,world_layers};
use wildstar_formats::tex::{RgbaImage,decode_tex};

const PX_PER_CELL:usize=64;
pub const ATLAS_SIDE:usize=16*PX_PER_CELL;

pub struct AtlasResult {
    pub image:Image,
    pub layers:usize,
    pub textures:usize,
    pub unresolved:Vec<String>,
    pub notes:Vec<String>,
}
fn decode_layers(index:&AssetIndex)->Result<HashMap<u32,WorldLayer>,String>{
    let path=index.resolve("DB/WorldLayer.tbl")
        .or_else(||index.find_name("WorldLayer.tbl").into_iter().next())
        .ok_or("WorldLayer.tbl missing in ClientData or ClientDataEN")?;
    let tbl=Table::read_file(&path.path)?;
    world_layers(&tbl)
}
fn collect_textures(area:&RawArea,
                    index:&AssetIndex,
                    layers:&HashMap<u32,WorldLayer>)
    ->(HashMap<u32,RgbaImage>,Vec<String>,usize)
{
    let mut images=HashMap::new();
    let mut seen=HashSet::new();
    let mut errors=Vec::new();
    let mut used=HashSet::new();
    for cell in area.cells.iter().flatten(){
        if let Some(ids)=cell.layers(){
            for id in ids{
                if id==0{continue;}
                used.insert(id);
                if !seen.insert(id){continue;}
                let Some(layer)=layers.get(&id) else{
                    errors.push(format!("WorldLayer #{id}: missing database row"));
                    continue;
                };
                if layer.color_map.is_empty(){
                    errors.push(format!("WorldLayer #{id}: no ColorMapPath"));
                    continue;
                }
                let Some(asset)=index.resolve(&layer.color_map) else{
                    errors.push(format!("WorldLayer #{id}: missing {}",layer.color_map));
                    continue;
                };
                match std::fs::read(&asset.path){
                    Ok(data)=>match decode_tex(&data,256){
                        Ok(image)=>{images.insert(id,image);},
                        Err(error)=>errors.push(format!(
                            "WorldLayer #{id} {}: {error}",layer.color_map)),
                    },
                    Err(error)=>errors.push(format!(
                        "WorldLayer #{id}: cannot read {}: {error}",asset.path.display())),
                }
            }
        }
    }
    (images,errors,used.len())
}
fn weights(cell:&AreaCell,sx:usize,sz:usize)->[f32;4]{
    let raw=cell.normalized_weights(sx,sz)
        .or_else(||cell.authoring_weights(sx,sz));
    let Some(raw)=raw else{return [1.,0.,0.,0.];};
    let sum:usize=raw.iter().map(|&v|v as usize).sum();
    if sum==0{return [1.,0.,0.,0.];}
    raw.map(|v|v as f32/sum as f32)
}
fn fallback_rgb(cell:&AreaCell,sx:usize,sz:usize)->[u8;4]{
    cell.color_rgb565(sx,sz)
        .map(|[r,g,b]|[r,g,b,255])
        .unwrap_or([116,116,116,255])
}
pub fn bake(area:&RawArea,index:&AssetIndex)->Result<AtlasResult,String>{
    let layers=decode_layers(index)?;
    let (images,unresolved,layer_count)=collect_textures(area,index,&layers);
    if images.is_empty(){
        let detail=unresolved.iter().take(5).cloned().collect::<Vec<_>>().join(" | ");
        return Err(format!(
            "0/{layer_count} terrain textures decoded. {detail}"
        ));
    }
    // Each AREA tile has 16x16 independent 32m cells. 64x64 pixels/cell
    // represents 0.5m per sample, matching the native 65x65 weight maps.
    let mut pixels=vec![0u8;ATLAS_SIDE*ATLAS_SIDE*4];
    for index_cell in 0..256{
        let Some(cell)=area.cells[index_cell].as_ref() else{continue;};
        let ids=cell.layers().unwrap_or([0;4]);
        for z in 0..PX_PER_CELL{
            for x in 0..PX_PER_CELL{
                let sx=x.min(64);let sz=z.min(64);
                let weights=weights(cell,sx,sz);
                let base=fallback_rgb(cell,sx,sz);
                let wx=(index_cell%16) as f32*32.+(x as f32+0.5)*0.5;
                let wz=(index_cell/16) as f32*32.+(z as f32+0.5)*0.5;
                let mut sum=[0f32;3];
                for i in 0..4{
                    if weights[i]==0.{continue;}
                    let tex=images.get(&ids[i]);
                    let color=if let (Some(texture),Some(layer))=(tex,layers.get(&ids[i])){
                        let tiling=layer.meters_per_tile.max(0.001);
                        texture.sample_wrapped(wx/tiling,wz/tiling)
                    }else{base};
                    for c in 0..3 {sum[c]+=color[c] as f32*weights[i];}
                }
                let px=(index_cell/16*PX_PER_CELL+z)*ATLAS_SIDE
                    +(index_cell%16*PX_PER_CELL+x);
                let p=px*4;
                for c in 0..3{pixels[p+c]=sum[c].round().clamp(0.,255.) as u8;}
                pixels[p+3]=255;
            }
        }
    }
    let image=Image::new(
        Extent3d{width:ATLAS_SIDE as u32,height:ATLAS_SIDE as u32,
            depth_or_array_layers:1},
        TextureDimension::D2,pixels,TextureFormat::Rgba8UnormSrgb,
        RenderAssetUsages::default(),
    );
    Ok(AtlasResult{
        image,layers:layer_count,textures:images.len(),unresolved,
        notes:vec![
            "CPU-composited real TEX albedo atlas, not the WildStar GPU shader".into(),
            "65x65 bit29 weights; bit2 fallback if bit29 is absent".into(),
            "Missing layer assets fallback to original AREA RGB565 color".into(),
            "Normal maps and compressed BC weight corrections are not rendered yet".into(),
        ]
    })
}
