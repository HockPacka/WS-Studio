//! Conservative M3 multi-layer colour preview for Genesis.
//! The original client uses material permutation bits and up to four
//! material descriptions; while those shader permutations are still being
//! reverse engineered, this extension preserves Bevy PBR/normal/alpha from
//! Layer 0 and alpha-composites available colour layers 1..3 on the GPU.
//! Missing layers never receive placeholder checkerboards.
use bevy::asset::{embedded_asset, RenderAssetUsages};
use bevy::pbr::{ExtendedMaterial, MaterialExtension};
use bevy::prelude::*;
use bevy::render::render_resource::{
    AsBindGroup, Extent3d, ShaderType, TextureDimension, TextureFormat,
};
use bevy::shader::ShaderRef;

pub type M3LayerMaterial = ExtendedMaterial<StandardMaterial, M3LayerExtension>;

pub struct M3LayerPlugin;
impl Plugin for M3LayerPlugin {
    fn build(&self, app: &mut App) {
        embedded_asset!(app, "m3_layers.wesl");
        app.add_plugins(MaterialPlugin::<M3LayerMaterial>::default());
    }
}

#[derive(ShaderType, Reflect, Debug, Clone)]
pub struct M3LayerParams {
    /// RGB layer tint, with layer opacity stored in x.
    pub colour: [Vec4; 3],
    /// XYZ = whether each texture is present. W reserved.
    pub enabled: UVec4,
}

#[derive(Asset, AsBindGroup, Reflect, Debug, Clone)]
pub struct M3LayerExtension {
    #[uniform(100)]
    pub params: M3LayerParams,
    #[texture(101)]
    #[sampler(102)]
    pub layer1: Option<Handle<Image>>,
    #[texture(103)]
    #[sampler(104)]
    pub layer2: Option<Handle<Image>>,
    #[texture(105)]
    #[sampler(106)]
    pub layer3: Option<Handle<Image>>,
}

impl MaterialExtension for M3LayerExtension {
    fn fragment_shader() -> ShaderRef {
        "embedded://genesis/m3_layers.wesl".into()
    }
}

/// Each entry represents the corresponding native layer 1, 2 or 3.
/// A missing colour texture makes that layer inactive; it cannot shift
/// later layers to another position.
pub fn extension_for(
    images: &mut Assets<Image>,
    overlays: &[(Option<Handle<Image>>, f32, [f32; 3])],
) -> Option<M3LayerExtension> {
    if !overlays.iter().take(3).any(|v| v.0.is_some()) {
        return None;
    }
    // Every declared shader binding has an actual, valid image; shader
    // branches alone cannot compensate for a missing GPU bind-group slot.
    let transparent = images.add(Image::new_fill(
        Extent3d { width: 1, height: 1, depth_or_array_layers: 1 },
        TextureDimension::D2,
        &[0, 0, 0, 0],
        TextureFormat::Rgba8UnormSrgb,
        RenderAssetUsages::default(),
    ));
    let mut flags = UVec4::ZERO;
    let mut params = [Vec4::ZERO; 3];
    let mut layers = [transparent.clone(), transparent.clone(), transparent];
    for (i, (colour, opacity, tint)) in overlays.iter().take(3).enumerate() {
        if let Some(colour) = colour {
            flags[i] = 1;
            layers[i] = colour.clone();
        }
        params[i] = Vec4::new(
            opacity.clamp(0.0, 1.0),
            tint[0].clamp(0.0, 64.0),
            tint[1].clamp(0.0, 64.0),
            tint[2].clamp(0.0, 64.0),
        );
    }
    Some(M3LayerExtension {
        params: M3LayerParams { colour: params, enabled: flags },
        layer1: Some(layers[0].clone()),
        layer2: Some(layers[1].clone()),
        layer3: Some(layers[2].clone()),
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn absent_layers_do_not_allocate_shader_material() {
        let mut assets = Assets::<Image>::default();
        assert!(extension_for(&mut assets, &[]).is_none());
        assert!(extension_for(&mut assets, &[(None, 1.0, [1.0;3])]).is_none());
    }

    #[test]
    fn layer_slots_remain_stable_with_missing_middle_texture() {
        let mut images = Assets::<Image>::default();
        let texture = images.add(Image::default());
        let ext = extension_for(&mut images, &[
            (None, 1.0, [1.0;3]),
            (Some(texture), 0.3, [2.0, 1.0, 1.0]),
            (None, 1.0, [1.0;3]),
        ]).unwrap();
        assert_eq!(ext.params.enabled, UVec4::new(0,1,0,0));
        assert_eq!(ext.params.colour[1].x, 0.3);
        assert_eq!(ext.params.colour[1].y, 2.0);
    }
}
