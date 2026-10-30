//! Terrain geometry produced directly from binary decoded 19x19 cell heights.
use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, PrimitiveTopology};
use bevy::prelude::*;

use wildstar_formats::area::{HeightGrid, RawArea, tile_heights};

pub fn terrain_mesh(area:&RawArea, preview:usize, layer:usize)->Result<(Mesh,Vec3),String>{
    let grid=tile_heights(area);
    if grid.cells==0 {return Err("AREA contains no heightmap blocks".into());}
    let mut positions=Vec::with_capacity(257*257);
    let mut normals=Vec::with_capacity(257*257);
    let mut colors=Vec::with_capacity(257*257);
    let mut uvs=Vec::with_capacity(257*257);
    let center_height=grid.heights[128*257+128];
    let visual_mid=if grid.present[128*257+128]{center_height}
                   else {(grid.min+grid.max)*0.5};
    for z in 0..257 {
        for x in 0..257 {
            let i=z*257+x;
            let h=grid.heights[i];
            positions.push([x as f32*2.0-256.0,h,z as f32*2.0-256.0]);
            // Full-tile UV; the baked 16x16-cell albedo atlas shares this
            // exact coordinate grid, so borders remain spatially aligned.
            uvs.push([x as f32/256.,z as f32/256.]);
            let normal=normal_at(&grid,x,z);
            normals.push(normal.to_array());
            let amount=if grid.max>grid.min {
                ((h-grid.min)/(grid.max-grid.min)).clamp(0.,1.)
            } else { 0.5 };
            let steep=1.0-normal.y.max(0.0);
            // Temporary vertex tint only. Native WildStar texture layers are a later step.
            let fallback=[
                (0.28+amount*0.30+steep*0.18).clamp(0.,1.),
                (0.39+amount*0.22-steep*0.11).clamp(0.,1.),
                (0.29+amount*0.18-steep*0.08).clamp(0.,1.),
                1.0
            ];
            // Debug views use REAL source IDs/maps, not guessed material paths.
            // Colour IDs are deterministic identifiers, NOT WildStar material colours.
            let cell_index=(z/16).min(15)*16+(x/16).min(15);
            let local_x=x.saturating_sub((x/16).min(15)*16);
            let local_z=z.saturating_sub((z/16).min(15)*16);
            let tone=area.cells[cell_index].as_ref().and_then(|cell|{
                match preview {
                    1=>cell.color_rgb565((local_x*4).min(64),(local_z*4).min(64))
                        .map(|v|[v[0] as f32/255.,v[1] as f32/255.,v[2] as f32/255.,1.]),
                    2=>cell.layers().map(|ids|debug_id_color(ids[layer.min(3)])),
                    3=>cell.zone_id_at((local_x*4).min(63),(local_z*4).min(63))
                        .map(debug_id_color),
                    4=>cell.normalized_weights((local_x*4).min(64),(local_z*4).min(64))
                        .or_else(||cell.authoring_weights((local_x*4).min(64),(local_z*4).min(64)))
                        .map(|weights|{
                            let heat=weights[layer.min(3)] as f32/15.;
                            [heat,0.1+0.55*(1.-heat),0.12+0.2*(1.-heat),1.]
                        }),
                    _=>None,
                }
            }).unwrap_or(fallback);
            // The genuine texture atlas already contains blended albedo;
            // neutralize vertex tint to avoid multiplying it by debug colors.
            colors.push(if preview==5{[1.,1.,1.,1.]}else{tone});
        }
    }
    let mut indices=Vec::with_capacity(256*256*6);
    for z in 0..256 {
        for x in 0..256 {
            // Do not fabricate geometry for cells that are absent from the source file.
            let source_index=(z/16)*16+(x/16);
            if area.cells[source_index].as_ref().and_then(|c|c.block(0)).is_none(){
                continue;
            }
            let a=(z*257+x) as u32;
            let b=a+1;
            let c=a+257;
            let d=c+1;
            indices.extend_from_slice(&[a,c,b,b,c,d]);
        }
    }
    let mut mesh=Mesh::new(PrimitiveTopology::TriangleList,RenderAssetUsages::default());
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION,positions);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL,normals);
    mesh.insert_attribute(Mesh::ATTRIBUTE_COLOR,colors);
    mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0,uvs);
    let tangents = vec![[1.0f32, 0.0f32, 0.0f32, 1.0f32]; 257 * 257];
    mesh.insert_attribute(Mesh::ATTRIBUTE_TANGENT, tangents);
    mesh.insert_indices(Indices::U32(indices));
    Ok((mesh,Vec3::new(0.0,visual_mid,0.0)))
}

fn normal_at(grid:&HeightGrid,x:usize,z:usize)->Vec3{
    let idx=z*257+x;
    if !grid.present[idx] {return Vec3::Y;}
    let a=x.saturating_sub(1);
    let b=(x+1).min(256);
    let c=z.saturating_sub(1);
    let d=(z+1).min(256);
    let dx=(grid.heights[z*257+b]-grid.heights[z*257+a])/(2.0*(b-a).max(1) as f32);
    let dz=(grid.heights[d*257+x]-grid.heights[c*257+x])/(2.0*(d-c).max(1) as f32);
    Vec3::new(-dx,1.0,-dz).normalize_or_zero()
}


/// A legible stable hash for IDs in debug overlays; not a material lookup.
fn debug_id_color(id:u32)->[f32;4]{
    if id==0{return [0.22,0.22,0.22,1.];}
    let n=id.wrapping_mul(0x9E3779B1);
    [0.28+((n&255) as f32)/510.,
     0.28+(((n>>8)&255) as f32)/510.,
     0.28+(((n>>16)&255) as f32)/510.,1.]
}
