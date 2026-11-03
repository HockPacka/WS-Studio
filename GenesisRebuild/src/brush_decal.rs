//! Terrain-conforming brush projection for the native Genesis AREA editor.
//!
//! A translucent, unlit mesh is reconstructed from the CURRENT editable
//! heightfield under the cursor. Unlike egui's flat screen-space circles,
//! this overlay follows slopes and is depth-occluded by world geometry.
//! The radial mask uses the same Hardness and F/O profile as sculpt/paint;
//! it does not write to the original AREA or create a persisted decal.
use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, PrimitiveTopology};
use bevy::prelude::*;

use crate::terrain_edit::TerrainEdit;

const SURFACE_OFFSET: f32 = 0.075;
const RING_OFFSET: f32 = 0.12;

#[derive(Resource, Default)]
pub struct BrushPreview {
    pub position: Option<Vec2>, // X/Z in world metres
    pub radius: f32,
    pub hardness: f32,
    pub falloff: f32,
    pub color: [f32;3],
    pub binary: bool,
}
impl BrushPreview {
    pub fn show(&mut self,hit:Vec3,radius:f32,hardness:f32,falloff:f32,
                color:[f32;3],binary:bool){
        self.position=Some(Vec2::new(hit.x,hit.z));
        self.radius=radius;
        self.hardness=hardness;
        self.falloff=falloff;
        self.color=color;
        self.binary=binary;
    }
}
#[derive(Resource,Default)]
pub struct BrushRenderer {
    entity: Option<Entity>,
    mesh: Option<Handle<Mesh>>,
}
struct Geometry {
    positions:Vec<[f32;3]>,
    normals:Vec<[f32;3]>,
    colors:Vec<[f32;4]>,
    uv:Vec<[f32;2]>,
    indices:Vec<u32>,
}
impl Geometry {
    fn new()->Self{
        Self{positions:Vec::new(),normals:Vec::new(),colors:Vec::new(),
             uv:Vec::new(),indices:Vec::new()}
    }
    fn point(&mut self,edit:&TerrainEdit,world:Vec2,
             color:[f32;4],lift:f32)->Option<u32>{
        let height=edit.surface_height(world)?;
        let index=self.positions.len() as u32;
        // Mesh is local to the AREA center. The world origin is added
        // by the entity Transform, matching the underlying tile mesh.
        self.positions.push([world.x-edit.origin.x,height+lift,world.y-edit.origin.y]);
        self.normals.push([0.0,1.0,0.0]);
        self.colors.push(color);
        self.uv.push([0.0,0.0]);
        Some(index)
    }
    fn quad(&mut self,a:Option<u32>,b:Option<u32>,
            c:Option<u32>,d:Option<u32>){
        if let (Some(a),Some(b),Some(c),Some(d))=(a,b,c,d){
            self.indices.extend_from_slice(&[a,c,b,b,c,d]);
        }
    }
    fn mesh(self)->Option<Mesh>{
        if self.indices.is_empty(){return None;}
        let mut m=Mesh::new(PrimitiveTopology::TriangleList,
                            RenderAssetUsages::default());
        m.insert_attribute(Mesh::ATTRIBUTE_POSITION,self.positions);
        m.insert_attribute(Mesh::ATTRIBUTE_NORMAL,self.normals);
        m.insert_attribute(Mesh::ATTRIBUTE_COLOR,self.colors);
        m.insert_attribute(Mesh::ATTRIBUTE_UV_0,self.uv);
        m.insert_indices(Indices::U32(self.indices));
        Some(m)
    }
}

fn add_ring(g:&mut Geometry,edit:&TerrainEdit,center:Vec2,
            radius:f32,width:f32,segments:usize,color:[f32;4]){
    if radius<=0.0{return;}
    let inner=(radius-width*0.5).max(0.0);
    let outer=radius+width*0.5;
    let mut last_inner=None;
    let mut last_outer=None;
    for i in 0..=segments {
        let theta=i as f32 * std::f32::consts::TAU / segments as f32;
        let ray=Vec2::new(theta.cos(),theta.sin());
        let a=g.point(edit,center+ray*inner,color,RING_OFFSET);
        let b=g.point(edit,center+ray*outer,color,RING_OFFSET);
        if i>0 {g.quad(last_inner,last_outer,a,b);}
        last_inner=a;
        last_outer=b;
    }
}

/// Builds a finite, terrain-following patch clipped to actual present cells.
/// When a brush overlaps the tile boundary, triangles outside are omitted.
fn build_mesh(edit:&TerrainEdit,p:&BrushPreview)->Option<Mesh>{
    if !edit.is_ready(){return None;}
    let center=p.position?;
    if !center.is_finite() || !p.radius.is_finite() || p.radius<=0.0 {return None;}
    let radius=p.radius.clamp(0.5,50.0);
    // At a 50 m brush radius this gives 128 angular by 26 radial steps,
    // well below full-tile mesh resolution while keeping hills conforming.
    let segments=((std::f32::consts::TAU*radius/2.2).ceil() as usize).clamp(48,144);
    let radial=((radius/1.6).ceil() as usize).clamp(4,40);
    let mut g=Geometry::new();
    let mut previous:Option<Vec<Option<u32>>>=None;
    for r in 0..=radial {
        let distance=radius*r as f32/radial as f32;
        let influence=if p.binary{1.0}else{
            crate::brush_profile::influence(distance,radius,p.hardness,p.falloff)
        };
        // Low-opacity projection with a more visible full-strength core.
        let alpha=if distance>=radius{0.0}else{0.06+0.16*influence};
        let mut row=Vec::with_capacity(segments+1);
        for i in 0..=segments {
            let theta=i as f32*std::f32::consts::TAU / segments as f32;
            let pos=center+Vec2::new(theta.cos(),theta.sin())*distance;
            row.push(g.point(edit,pos,[p.color[0],p.color[1],p.color[2],alpha],
                             SURFACE_OFFSET));
        }
        if let Some(last)=previous.as_ref(){
            for i in 0..segments {
                g.quad(last[i],last[i+1],row[i],row[i+1]);
            }
        }
        previous=Some(row);
    }
    let line_width=(radius*0.035).clamp(0.45,1.5);
    add_ring(&mut g,edit,center,radius,line_width,segments,
             [p.color[0],p.color[1],p.color[2],0.95]);
    let h=p.hardness.clamp(0.0,1.0);
    if !p.binary && h>0.04 && h<0.96 {
        add_ring(&mut g,edit,center,radius*h,line_width*0.8,segments,
                 [0.98,0.97,0.88,0.92]);
    }
    g.mesh()
}

/// Runs after the egui viewport recorded this frame's raycast, so the
/// projected preview follows the mouse without a separate screen-circle.
pub fn update(
    preview:Res<BrushPreview>,
    edit:Res<TerrainEdit>,
    mut render:ResMut<BrushRenderer>,
    mut meshes:ResMut<Assets<Mesh>>,
    mut materials:ResMut<Assets<StandardMaterial>>,
    mut commands:Commands,
){
    let mesh=build_mesh(&edit,&preview);
    let Some(mesh)=mesh else {
        if let Some(entity)=render.entity{
            commands.entity(entity).insert(Visibility::Hidden);
        }
        return;
    };
    let handle=if let Some(handle)=render.mesh.as_ref(){
        if let Some(existing)=meshes.get_mut(handle){
            *existing=mesh;
            handle.clone()
        }else{
            let new=meshes.add(mesh);
            render.mesh=Some(new.clone());
            new
        }
    }else{
        let new=meshes.add(mesh);
        render.mesh=Some(new.clone());
        new
    };
    if let Some(entity)=render.entity {
        commands.entity(entity).insert((
            Visibility::Visible,
            Mesh3d(handle),
            Transform::from_xyz(edit.origin.x,0.0,edit.origin.y),
        ));
    } else {
        let material=materials.add(StandardMaterial{
            base_color:Color::WHITE,
            unlit:true,
            alpha_mode:AlphaMode::Blend,
            cull_mode:None,
            ..default()
        });
        render.entity=Some(commands.spawn((
            Mesh3d(handle),
            MeshMaterial3d(material),
            Transform::from_xyz(edit.origin.x,0.0,edit.origin.y),
        )).id());
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use wildstar_formats::area::{RawArea,builder::AreaBuilder};

    fn session(sloped:bool)->TerrainEdit {
        let heights=(0..257usize*257).map(|i|{
            let x=i%257;
            let z=i/257;
            if sloped{x as f32 * 0.125 + z as f32 * 0.25}else{0.0}
        }).collect::<Vec<_>>();
        let a=RawArea::from_bytes(
            AreaBuilder::flat(0.0,0).with_heights(heights).build().unwrap()
        ).unwrap();
        let mut s=TerrainEdit::default();
        s.load(std::path::Path::new("test.4040.area"),&a,Vec2::ZERO);
        s
    }
    #[test]
    fn projected_mesh_follows_slope_not_a_flat_plane(){
        let edit=session(true);
        let p=BrushPreview{position:Some(Vec2::ZERO),radius:14.0,hardness:0.5,
            falloff:0.5,color:[0.2,1.0,0.4],binary:false};
        let mesh=build_mesh(&edit,&p).unwrap();
        let coords=mesh.attribute(Mesh::ATTRIBUTE_POSITION).unwrap();
        let Some(bevy::mesh::VertexAttributeValues::Float32x3(points))=Some(coords) else{
            panic!("Brush decal positions must be f32x3")
        };
        let min=points.iter().map(|p|p[1]).fold(f32::INFINITY,f32::min);
        let max=points.iter().map(|p|p[1]).fold(f32::NEG_INFINITY,f32::max);
        assert!(max-min>1.0,"Surface projected decal must follow height changes");
        assert!(mesh.indices().is_some());
    }
    #[test]
    fn preview_is_clipped_outside_a_tile(){
        let edit=session(false);
        let off=BrushPreview{position:Some(Vec2::new(1000.0,1000.0)),radius:10.0,
            hardness:0.5,falloff:0.5,color:[0.2,1.0,0.4],binary:false};
        assert!(build_mesh(&edit,&off).is_none());
        let edge=BrushPreview{position:Some(Vec2::new(255.0,255.0)),..off};
        assert!(build_mesh(&edit,&edge).is_some());
    }
    #[test]
    fn no_editable_area_cannot_show_a_decal(){
        let empty=TerrainEdit::default();
        let preview=BrushPreview{position:Some(Vec2::ZERO),radius:10.0,
            hardness:0.5,falloff:0.5,color:[1.0,1.0,0.0],binary:false};
        assert!(build_mesh(&empty,&preview).is_none());
    }
}
