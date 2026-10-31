//! Bevy renderer integration for WildStar .sky files.
//! Evaluates day-night cycles, sun positions, ambient and directional lighting,
//! fog, and screen parameters to drive Bevy's lighting and camera systems.

use bevy::color::Color;
use bevy::math::{Vec3, Vec4};
use bevy::prelude::*;
use std::collections::HashMap;
use std::sync::Arc;
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::sky::{read_sky, SkyFile};
use wildstar_formats::tbl::{world_skies, Table, WorldSky};

/// Evaluated atmospheric parameters for the Bevy renderer at a specific time of day.
#[derive(Debug, Clone)]
pub struct EvaluatedSky {
    pub ambient_color: Color,
    pub sun_diffuse_color: Color,
    pub sun_direction: Vec3,
    pub sun_elevation_deg: f32,
    pub sun_azimuth_deg: f32,
    pub sun_specular_color: Color,
    pub fog_start: f32,
    pub fog_end: f32,
    pub sky_start: f32,
    pub sky_end: f32,
    pub cloud_fog: f32,
    pub sky_fog: f32,
    pub cloud_set_id: u32,
    pub cloud_alpha: f32,
    pub night_ambient: Color,
    pub horizon_fog_mod: Color,
}

impl Default for EvaluatedSky {
    fn default() -> Self {
        Self {
            ambient_color: Color::srgb(0.2, 0.2, 0.25),
            sun_diffuse_color: Color::srgb(1.0, 0.95, 0.9),
            sun_direction: Vec3::new(0.5, -1.0, 0.3).normalize(),
            sun_elevation_deg: 45.0,
            sun_azimuth_deg: 135.0,
            sun_specular_color: Color::srgb(1.0, 1.0, 1.0),
            fog_start: 100.0,
            fog_end: 1500.0,
            sky_start: 50.0,
            sky_end: 2000.0,
            cloud_fog: 0.1,
            sky_fog: 0.5,
            cloud_set_id: 0,
            cloud_alpha: 1.0,
            night_ambient: Color::BLACK,
            horizon_fog_mod: Color::WHITE,
        }
    }
}

/// Evaluates a `SkyFile` at a given day second (0.0 .. 86400.0).
pub fn evaluate_sky(sky: &SkyFile, time_seconds: f32) -> EvaluatedSky {
    let mut eval = EvaluatedSky::default();

    // Ambient RGBA (0x288)
    if let Some(amb) = sky.ambient.sample(time_seconds) {
        if amb.len() >= 4 {
            eval.ambient_color = Color::srgba(amb[0].max(0.0), amb[1].max(0.0), amb[2].max(0.0), amb[3].clamp(0.0, 1.0));
        }
    }

    // SunDiffuse (0x2A0): elevationDeg, azimuthDeg, _, _, RGBA
    if let Some(sun) = sky.sun_diffuse.sample(time_seconds) {
        if sun.len() >= 8 {
            eval.sun_elevation_deg = sun[0];
            eval.sun_azimuth_deg = sun[1];
            eval.sun_diffuse_color = Color::srgba(sun[4].max(0.0), sun[5].max(0.0), sun[6].max(0.0), sun[7].clamp(0.0, 1.0));

            // Convert spherical angles to directional vector pointing from sun towards world
            let elev_rad = sun[0].to_radians();
            let azim_rad = sun[1].to_radians();
            let cos_elev = elev_rad.cos();
            // In WildStar world coords: X = east, Y = north/up, Z = south
            let dir = Vec3::new(
                azim_rad.sin() * cos_elev,
                elev_rad.sin(),
                azim_rad.cos() * cos_elev,
            );
            eval.sun_direction = -dir.normalize_or_zero();
        }
    }

    // SunSpecular (0x2B8): RGBA
    if let Some(spec) = sky.sun_specular.sample(time_seconds) {
        if spec.len() >= 4 {
            eval.sun_specular_color = Color::srgba(spec[0].max(0.0), spec[1].max(0.0), spec[2].max(0.0), spec[3].clamp(0.0, 1.0));
        }
    }

    // FogDistance (0x2D0): FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog
    if let Some(fog) = sky.fog_distance.sample(time_seconds) {
        if fog.len() >= 6 {
            eval.fog_start = fog[0];
            eval.fog_end = fog[1];
            eval.sky_start = fog[2];
            eval.sky_end = fog[3];
            eval.cloud_fog = fog[4];
            eval.sky_fog = fog[5];
        }
    }

    // CloudSetId (0x310)
    let resources = sky.cloud_set_id.sample_resources(time_seconds as u32);
    if let Some((id, _)) = resources.first() {
        eval.cloud_set_id = *id;
    }

    // CloudAlpha (0x328)
    if let Some(ca) = sky.cloud_alpha.sample(time_seconds) {
        if let Some(&alpha) = ca.first() {
            eval.cloud_alpha = alpha;
        }
    }

    // NightAmbient (0x3B0)
    if let Some(na) = sky.night_ambient.sample(time_seconds) {
        if na.len() >= 4 {
            eval.night_ambient = Color::srgba(na[0].max(0.0), na[1].max(0.0), na[2].max(0.0), na[3].clamp(0.0, 1.0));
        }
    }

    // HorizonFogMod (0x3C8)
    if let Some(hf) = sky.horizon_fog_mod.sample(time_seconds) {
        if hf.len() >= 4 {
            eval.horizon_fog_mod = Color::srgba(hf[0].max(0.0), hf[1].max(0.0), hf[2].max(0.0), hf[3].clamp(0.0, 1.0));
        }
    }

    eval
}

/// Blends multiple `EvaluatedSky` results according to normalized weights.
#[allow(dead_code)]
pub fn blend_evaluated_skies(entries: &[(EvaluatedSky, f32)]) -> EvaluatedSky {
    if entries.is_empty() {
        return EvaluatedSky::default();
    }
    let total_weight: f32 = entries.iter().map(|(_, w)| *w).sum();
    if total_weight <= 1e-6 {
        return entries[0].0.clone();
    }

    let mut blended = EvaluatedSky::default();
    let mut amb = Vec4::ZERO;
    let mut sun_diff = Vec4::ZERO;
    let mut sun_spec = Vec4::ZERO;
    let mut sun_dir = Vec3::ZERO;
    let mut night_amb = Vec4::ZERO;
    let mut fog_start = 0.0;
    let mut fog_end = 0.0;
    let mut sky_start = 0.0;
    let mut sky_end = 0.0;
    let mut cloud_alpha = 0.0;

    for (sky, weight) in entries {
        let norm = weight / total_weight;
        let c = sky.ambient_color.to_linear();
        amb += Vec4::new(c.red, c.green, c.blue, c.alpha) * norm;

        let s = sky.sun_diffuse_color.to_linear();
        sun_diff += Vec4::new(s.red, s.green, s.blue, s.alpha) * norm;

        let sp = sky.sun_specular_color.to_linear();
        sun_spec += Vec4::new(sp.red, sp.green, sp.blue, sp.alpha) * norm;

        let na = sky.night_ambient.to_linear();
        night_amb += Vec4::new(na.red, na.green, na.blue, na.alpha) * norm;

        sun_dir += sky.sun_direction * norm;
        fog_start += sky.fog_start * norm;
        fog_end += sky.fog_end * norm;
        sky_start += sky.sky_start * norm;
        sky_end += sky.sky_end * norm;
        cloud_alpha += sky.cloud_alpha * norm;
    }

    blended.ambient_color = Color::linear_rgba(amb.x, amb.y, amb.z, amb.w);
    blended.sun_diffuse_color = Color::linear_rgba(sun_diff.x, sun_diff.y, sun_diff.z, sun_diff.w);
    blended.sun_specular_color = Color::linear_rgba(sun_spec.x, sun_spec.y, sun_spec.z, sun_spec.w);
    blended.night_ambient = Color::linear_rgba(night_amb.x, night_amb.y, night_amb.z, night_amb.w);
    blended.sun_direction = sun_dir.normalize_or_zero();
    blended.fog_start = fog_start;
    blended.fog_end = fog_end;
    blended.sky_start = sky_start;
    blended.sky_end = sky_end;
    blended.cloud_alpha = cloud_alpha;
    blended.cloud_set_id = entries[0].0.cloud_set_id;

    blended
}

/// Cache of loaded `.sky` files and `WorldSky.tbl` index.
#[derive(Resource, Default)]
pub struct SkyManager {
    pub world_skies: HashMap<u32, WorldSky>,
    pub loaded_skies: HashMap<String, Arc<SkyFile>>,
    pub time_of_day: f32, // In seconds (default e.g. 12:00 = 43200.0)
    pub current_evaluated: Option<EvaluatedSky>,
}

impl SkyManager {
    #[allow(dead_code)]
pub fn new() -> Self {
        Self {
            world_skies: HashMap::new(),
            loaded_skies: HashMap::new(),
            time_of_day: 43200.0, // 12:00 PM
            current_evaluated: None,
        }
    }

    /// Load or ensure `WorldSky.tbl` is parsed.
    pub fn ensure_tables(&mut self, index: &AssetIndex) -> Result<(), String> {
        if !self.world_skies.is_empty() {
            return Ok(());
        }
        let tbl_path = index
            .resolve("DB/WorldSky.tbl")
            .or_else(|| index.find_name("WorldSky.tbl").into_iter().next())
            .ok_or("WorldSky.tbl not found in asset index")?;
        let table = Table::read_file(&tbl_path.path)?;
        self.world_skies = world_skies(&table)?;
        Ok(())
    }

    /// Read or fetch cached `SkyFile` by virtual asset path.
    pub fn get_or_load_sky(&mut self, index: &AssetIndex, path: &str) -> Option<Arc<SkyFile>> {
        if let Some(sky) = self.loaded_skies.get(path) {
            return Some(sky.clone());
        }
        let asset = index.resolve(path)?;
        let bytes = std::fs::read(&asset.path).ok()?;
        let sky = read_sky(&bytes).ok()?;
        let arc = Arc::new(sky);
        self.loaded_skies.insert(path.to_string(), arc.clone());
        Some(arc)
    }

    /// Resolve a `WorldSky.tbl` ID into a `SkyFile`.
    pub fn get_sky_by_id(&mut self, index: &AssetIndex, sky_id: u32) -> Option<Arc<SkyFile>> {
        let path = self.world_skies.get(&sky_id)?.asset_path.clone();
        self.get_or_load_sky(index, &path)
    }
}

/// Apply evaluated sky directional lighting to Bevy DirectionalLight component.
pub fn apply_sky_to_sun_light(evaluated: &EvaluatedSky, light: &mut DirectionalLight, transform: &mut Transform) {
    light.color = evaluated.sun_diffuse_color;
    // Aim light along sun direction
    if evaluated.sun_direction.length_squared() > 1e-4 {
        *transform = Transform::from_translation(Vec3::ZERO)
            .looking_to(evaluated.sun_direction, Vec3::Y);
    }
}

#[derive(Component)]
pub struct GenesisSun;

/// System that syncs Bevy's directional light with the evaluated WildStar sky.
pub fn update_sky_lighting(
    state: Res<crate::GenesisState>,
    mut sky_mgr: ResMut<SkyManager>,
    client: Res<crate::client_data::ClientFiles>,
    loaded: Res<crate::LoadedArea>,
    mut lights: Query<(&mut DirectionalLight, &mut Transform), With<GenesisSun>>,
) {
    let Some(index) = client.index.as_ref() else { return; };
    let _ = sky_mgr.ensure_tables(index);

    // Convert UI slider hours (0.0 .. 24.0) to day seconds
    let time_seconds = (state.time_of_day * 3600.0).clamp(0.0, 86400.0);
    sky_mgr.time_of_day = time_seconds;

    // Check if the loaded area has any active skies
    let first_sky_id = loaded.tile.as_ref().and_then(|tile| tile.all_sky_ids().into_iter().next());

    if let Some(first_sky_id) = first_sky_id {
        if let Some(sky_file) = sky_mgr.get_sky_by_id(index, first_sky_id) {
            let eval = evaluate_sky(&sky_file, time_seconds);
            for (mut light, mut transform) in lights.iter_mut() {
                apply_sky_to_sun_light(&eval, &mut light, &mut transform);
            }
            sky_mgr.current_evaluated = Some(eval);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use wildstar_formats::sky::Track;

    #[test]
    fn evaluates_sky_and_sun_direction() {
        let sky = SkyFile {
            version: 16,
            source_xml: String::new(),
            header_words: [0; 4],
            header_10_float: 0.0,
            lighting_group: Default::default(),
            sky_group: Default::default(),
            fog_group: Default::default(),
            cloud_group: Default::default(),
            ambient: Track {
                times: vec![0, 43200],
                values: vec![vec![0.1, 0.1, 0.2, 1.0], vec![0.5, 0.5, 0.6, 1.0]],
            },
            sun_diffuse: Track {
                times: vec![0, 43200],
                values: vec![
                    vec![-30.0, 0.0, 0.0, 0.0, 0.1, 0.1, 0.3, 1.0],
                    vec![60.0, 180.0, 0.0, 0.0, 1.0, 0.9, 0.8, 1.0],
                ],
            },
            sun_specular: Default::default(),
            fog_distance: Track {
                times: vec![0],
                values: vec![vec![50.0, 1000.0, 10.0, 1200.0, 0.2, 0.8]],
            },
            models: Vec::new(),
            screen: Default::default(),
            cloud_set_id: Default::default(),
            cloud_alpha: Default::default(),
            particulates: Vec::new(),
            env_map_tex: String::new(),
            sun_glare: Default::default(),
            sun_glare_model1: String::new(),
            sun_glare_model2: String::new(),
            window_glow: Default::default(),
            night_ambient: Default::default(),
            horizon_fog_mod: Default::default(),
            liquid_colors: Default::default(),
            wind_spawns: Vec::new(),
            color_lut_tex: String::new(),
        };

        let noon = evaluate_sky(&sky, 43200.0);
        assert_eq!(noon.sun_elevation_deg, 60.0);
        assert_eq!(noon.sun_azimuth_deg, 180.0);
        assert_eq!(noon.fog_start, 50.0);
        assert_eq!(noon.fog_end, 1000.0);
        assert!(noon.sun_direction.length_squared() > 0.99);

        // Test blending of two evaluated skies
        let dusk = evaluate_sky(&sky, 0.0);
        let blended = blend_evaluated_skies(&[(noon, 0.5), (dusk, 0.5)]);
        assert_eq!(blended.fog_start, 50.0);
    }
}

/// Component tagging spawned skybox root entities that should follow the camera translation.
#[derive(Component)]
pub struct SkyboxRoot;

/// System to sync skybox model positions to the main camera so they remain at visual infinity.
pub fn update_skybox_position(
    camera_q: Query<&Transform, (With<crate::GenesisCamera>, Without<SkyboxRoot>)>,
    mut skybox_q: Query<&mut Transform, With<SkyboxRoot>>,
) {
    if let Ok(cam_tf) = camera_q.single() {
        for mut skybox_tf in skybox_q.iter_mut() {
            skybox_tf.translation = cam_tf.translation;
        }
    }
}

/// System to update camera distance fog based on evaluated sky parameters.
pub fn update_camera_fog(
    sky_mgr: Res<SkyManager>,
    mut cameras: Query<&mut DistanceFog, With<crate::GenesisCamera>>,
) {
    let Some(eval) = sky_mgr.current_evaluated.as_ref() else { return; };
    for mut fog in cameras.iter_mut() {
        fog.color = eval.horizon_fog_mod;
        fog.falloff = FogFalloff::Linear {
            start: eval.fog_start.max(0.0),
            end: eval.fog_end.max(eval.fog_start + 1.0),
        };
    }
}
