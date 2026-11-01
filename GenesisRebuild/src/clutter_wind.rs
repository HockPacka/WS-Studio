//! GPU vertex wind for eligible instanced Clutter M3 parts.
//! Bevy ExtendedMaterial preserves StandardMaterial texture/alpha/PBR setup.
//! One extended material per original StandardMaterial handle, shared by
//! all instances. Time evolves in GPU view globals, not on CPU Transform.
///
use std::collections::HashMap;
use bevy::{
    prelude::*,
    pbr::{ExtendedMaterial,MaterialExtension},
    render::render_resource::{AsBindGroup},
    shader::ShaderRef,
    asset::AssetId,
};
const WIND_SHADER:&str="shaders/clutter_wind.wesl";
pub type WindMaterial=ExtendedMaterial<StandardMaterial,WindExtension>;

#[derive(Asset,AsBindGroup,Reflect,Debug,Clone)]
pub struct WindExtension{
    // slot 100 is after the StandardMaterial bindings 0..99.
    // x=displacement in metres, y=frequency, z=local tip-height ramp,
    // w reserved for future gust tuning.
    #[uniform(100)]
    pub params:Vec4,
    #[uniform(100)]
    pub direction:Vec4,
}
impl MaterialExtension for WindExtension{
    fn vertex_shader()->ShaderRef{WIND_SHADER.into()}
    // Only forward pass vertex displacement is enabled for now. The native
    // default shadow/prepass vertex shaders do not deform the same way;
    // shadows are disabled for this preview material until that is fixed.
    fn enable_shadows()->bool{false}
}
#[derive(Resource,Default)]
pub struct WindMaterialCache{
    cached:HashMap<AssetId<StandardMaterial>,Handle<WindMaterial>>,
    last:Option<[u32;5]>,
}
impl WindMaterialCache{
    pub fn get_or_create(
        &mut self,source:&Handle<StandardMaterial>,
        standard:&Assets<StandardMaterial>,
        extensions:&mut Assets<WindMaterial>,
        strength:f32,speed:f32,direction:Vec2,
    )->Option<Handle<WindMaterial>>{
        let key=source.id();
        if let Some(handle)=self.cached.get(&key){return Some(handle.clone());}
        let base=standard.get(source)?.clone();
        let handle=extensions.add(ExtendedMaterial{
            base,extension:WindExtension::new(strength,speed,direction),
        });
        self.cached.insert(key,handle.clone());
        Some(handle)
    }
    /// Adjust all shared GPU uniforms only when parameters change.
    /// No per-instance CPU transforms, shader/pipeline recompilation or
    /// duplicated StandardMaterial are needed on every animation frame.
    pub fn synchronize(&mut self,assets:&mut Assets<WindMaterial>,
        strength:f32,speed:f32,direction:Vec2){
        let packed=[
            strength.to_bits(),speed.to_bits(),direction.x.to_bits(),
            direction.y.to_bits(),0,
        ];
        if self.last==Some(packed){return;}
        self.last=Some(packed);
        let new=WindExtension::new(strength,speed,direction);
        for handle in self.cached.values(){
            if let Some(material)=assets.get_mut(handle){
                material.extension=new.clone();
            }
        }
    }
}
impl WindExtension{
    fn new(strength:f32,speed:f32,direction:Vec2)->Self{
        let direction=direction.normalize_or_zero();
        Self{
            params:Vec4::new(strength.clamp(0.0,1.5),
                speed.clamp(0.0,8.0),1.0,0.0),
            direction:Vec4::new(direction.x,direction.y,0.0,0.0),
        }
    }
}
pub fn is_wind_vegetation(path:&str)->bool{
    let p=path.to_ascii_lowercase();
    ["grass","leaf","leaves","shrub","plant","bush","fern","flower",
        "foliage","reed","vine"].iter().any(|word|p.contains(word))
}
/// GPU distance visibility uses Bevy's native dithered VisibilityRange,
/// on the Mesh3d child, not its parent cell root.
pub fn lod_range(part:usize,lod_distance:f32,view_distance:f32)
    ->bevy::camera::visibility::VisibilityRange{
    let far=view_distance.max(32.0);
    let end=if part==0{far}else{lod_distance.clamp(5.0,far)};
    bevy::camera::visibility::VisibilityRange{
        start_margin:0.0..0.0,
        end_margin:(end*0.86)..end,
        use_aabb:false,
    }
}
#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn winds_only_natural_foliage_not_rocks(){
        assert!(is_wind_vegetation("Art/Plants/BlueFlower.m3"));
        assert!(is_wind_vegetation("Terrain/GrassThin.m3"));
        assert!(!is_wind_vegetation("Art/Crystals/IceSpike.m3"));
        assert!(!is_wind_vegetation("Art/Rocks/Boulder.m3"));
    }
    #[test]
    fn lod_ranges_are_bounded_even_for_wrong_ui_distances(){
        let near=lod_range(1,90.0,200.0);
        let far=lod_range(0,90.0,200.0);
        assert_eq!(near.end_margin.end,90.0);
        assert_eq!(far.end_margin.end,200.0);
        assert!(near.end_margin.start>0.0);
        assert!(lod_range(5,9999.0,100.0).end_margin.end<=100.0);
    }
    #[test]
    fn wind_uniform_clamps_and_normalizes_direction(){
        let value=WindExtension::new(3.0,99.0,Vec2::new(3.0,4.0));
        assert_eq!(value.params.x,1.5);
        assert_eq!(value.params.y,8.0);
        assert!((Vec2::new(value.direction.x,value.direction.y).length()-1.0)<0.0001);
    }
}