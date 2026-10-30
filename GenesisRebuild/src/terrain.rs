//! Terrain geometry produced directly from binary decoded 19x19 cell heights.
use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, PrimitiveTopology};
use bevy::prelude::*;

use wildstar_formats::area::{HeightGrid, RawArea, tile_heights};

pub fn terrain_mesh(area:&RawArea)->Result<(Mesh,Vec3),String>{
    let grid=tile_heights(area);
    if grid.cells==0 {return Err("AREA contains no heightmap blocks".into());}
    let mut positions=Vec::with_capacity(257*257);
    let mut normals=Vec::with_capacity(257*257);
    let mut colors=Vec::with_capacity(257*257);
    let center_height=grid.heights[128*257+128];
    let visual_mid=if grid.present[128*257+128]{center_height}
                   else {(grid.min+grid.max)*0.5};
    for z in 0..257 {
        for x in 0..257 {
            let i=z*257+x;
            let h=grid.heights[i];
            positions.push([x as f32*2.0-256.0,h,z as f32*2.0-256.0]);
            let normal=normal_at(&grid,x,z);
            normals.push(normal.to_array());
            let amount=if grid.max>grid.min {
                ((h-grid.min)/(grid.max-grid.min)).clamp(0.,1.)
            } else { 0.5 };
            let steep=1.0-normal.y.max(0.0);
            // Temporary vertex tint only. Native WildStar texture layers are a later step.
            colors.push([
                (0.28+amount*0.30+steep*0.18).clamp(0.,1.),
                (0.39+amount*0.22-steep*0.11).clamp(0.,1.),
                (0.29+amount*0.18-steep*0.08).clamp(0.,1.),
                1.0
            ]);
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
