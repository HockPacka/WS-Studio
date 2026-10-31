//! Runtime 4-layer terrain splatting, like the original LandPS shader: the WorldLayer
//! textures stay at full resolution in a texture array and are tiled and blended per
//! pixel with the decoded weight map and macro tint, instead of being baked into an atlas.
//!
//! Bindings (extension slots start at 100, see `terrain_splat.wesl`):
//!   100 params | 101 albedo array + 102 sampler | 103 normal array
//!   104 weight map + 105 sampler | 106 macro tint map | 107 per-cell layer indices
use bevy::asset::embedded_asset;
use bevy::pbr::{ExtendedMaterial, MaterialExtension};
use bevy::prelude::*;
use bevy::render::render_resource::{AsBindGroup, ShaderType};
use bevy::shader::ShaderRef;

pub type TerrainMaterial = ExtendedMaterial<StandardMaterial, SplatExt>;

/// Array index meaning "no layer in this slot".
pub const NO_LAYER: u8 = 255;
/// Layers per tile (`tiling` holds 4 per Vec4).
pub const MAX_LAYERS: usize = 254;
const TILING_VECS: usize = 64;

pub struct TerrainSplatPlugin;
impl Plugin for TerrainSplatPlugin {
    fn build(&self, app: &mut App) {
        embedded_asset!(app, "terrain_splat.wesl");
        app.add_plugins(MaterialPlugin::<TerrainMaterial>::default());
    }
}

#[derive(ShaderType, Reflect, Debug, Clone)]
pub struct SplatParams {
    /// 0 = plain StandardMaterial (debug views), 1 = splat colour.
    pub enabled: u32,
    pub has_normals: u32,
    /// Edge length of the tile in metres (UV 0..1).
    pub tile_meters: f32,
    /// 0 = macro tint off, 1 = full strength (blend towards neutral in between).
    pub tint_strength: f32,
    /// 0 = multiply in linear light, 1 = multiply in sRGB/gamma space (how the old atlas bake worked).
    pub tint_gamma: u32,
    pub _pad: u32,
    /// Inverse tiling length (1 / metres per texture repeat), indexed by array layer.
    pub tiling: [Vec4; TILING_VECS],
}
impl Default for SplatParams {
    fn default() -> Self {
        Self { enabled: 0, has_normals: 0, tile_meters: 512.0, tint_strength: 1.0, tint_gamma: 1, _pad: 0, tiling: [Vec4::ZERO; TILING_VECS] }
    }
}

#[derive(Asset, AsBindGroup, Reflect, Debug, Clone, Default)]
pub struct SplatExt {
    #[uniform(100)]
    pub params: SplatParams,
    #[texture(101, dimension = "2d_array")]
    #[sampler(102)]
    pub albedo: Option<Handle<Image>>,
    #[texture(103, dimension = "2d_array")]
    pub normals: Option<Handle<Image>>,
    #[texture(104)]
    #[sampler(105)]
    pub weights: Option<Handle<Image>>,
    #[texture(106)]
    pub tint: Option<Handle<Image>>,
    #[texture(107, filterable = false)]
    pub cell_layers: Option<Handle<Image>>,
}

impl MaterialExtension for SplatExt {
    fn fragment_shader() -> ShaderRef {
        "embedded://genesis/terrain_splat.wesl".into()
    }
}

/// CPU side result of baking one tile; turned into assets on the main thread.
pub struct SplatData {
    pub albedo: Image,
    pub normals: Image,
    pub weights: Image,
    pub tint: Image,
    pub cell_layers: Image,
    pub tiling: Vec<f32>,
    pub has_normals: bool,
    pub layer_count: usize,
}

impl SplatData {
    pub fn into_extension(self, images: &mut Assets<Image>, enabled: bool) -> SplatExt {
        let mut params = SplatParams { enabled: enabled as u32, has_normals: self.has_normals as u32, ..default() };
        for (i, t) in self.tiling.iter().enumerate().take(TILING_VECS * 4) {
            params.tiling[i / 4][i % 4] = *t;
        }
        SplatExt {
            params,
            albedo: Some(images.add(self.albedo)),
            normals: Some(images.add(self.normals)),
            weights: Some(images.add(self.weights)),
            tint: Some(images.add(self.tint)),
            cell_layers: Some(images.add(self.cell_layers)),
        }
    }
}

/// Live tint settings, applied to every terrain material.
#[derive(Clone, Copy, PartialEq)]
pub struct TintSettings {
    pub strength: f32,
    pub gamma_space: bool,
}
impl Default for TintSettings {
    fn default() -> Self {
        Self { strength: 1.0, gamma_space: true }
    }
}

impl TintSettings {
    pub fn apply(&self, materials: &mut Assets<TerrainMaterial>) {
        for (_, material) in materials.iter_mut() {
            material.extension.params.tint_strength = self.strength;
            material.extension.params.tint_gamma = self.gamma_space as u32;
        }
    }
}
