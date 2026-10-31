//! Bevy renderer integration for WildStar .sky files.
//! Evaluates day-night cycles, sun positions, ambient and directional lighting,
//! fog, skydome background, and celestial models (suns, moons, stars, clouds, nebulae)
//! to drive Bevy's lighting, camera systems and skybox background.

use bevy::asset::RenderAssetUsages;
use bevy::camera::ClearColorConfig;
use bevy::color::Color;
use bevy::math::{Vec3, Vec4};
use bevy::mesh::{Indices, Mesh, PrimitiveTopology};
use bevy::prelude::*;
use std::collections::HashMap;
use std::sync::Arc;
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::sky::{read_sky, SkyFile};
use wildstar_formats::tbl::{world_skies, world_zones, Table, WorldSky, WorldZone};

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
            // In WildStar world coords: X = east, Y = up, Z = south
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

/// Cache of loaded `.sky` files, `WorldSky.tbl`, and `WorldZone.tbl` index.
#[derive(Resource, Default)]
pub struct SkyManager {
    pub world_skies: HashMap<u32, WorldSky>,
    pub world_zones: HashMap<u32, WorldZone>,
    pub loaded_skies: HashMap<String, Arc<SkyFile>>,
    pub time_of_day: f32, // In seconds (default e.g. 12:00 = 43200.0)
    pub current_evaluated: Option<EvaluatedSky>,
    pub current_sky_id: Option<u32>,
    pub current_sky_path: Option<String>,
    pub current_zone_id: Option<u32>,
    pub skybox_root_entity: Option<Entity>,
}

impl SkyManager {
    #[allow(dead_code)]
    pub fn new() -> Self {
        Self {
            world_skies: HashMap::new(),
            world_zones: HashMap::new(),
            loaded_skies: HashMap::new(),
            time_of_day: 43200.0, // 12:00 PM
            current_evaluated: None,
            current_sky_id: None,
            current_sky_path: None,
            current_zone_id: None,
            skybox_root_entity: None,
        }
    }

    /// Load or ensure `WorldSky.tbl` and `WorldZone.tbl` are parsed.
    pub fn ensure_tables(&mut self, index: &AssetIndex) -> Result<(), String> {
        if self.world_skies.is_empty() {
            if let Some(tbl_path) = index
                .resolve("DB/WorldSky.tbl")
                .or_else(|| index.find_name("WorldSky.tbl").into_iter().next())
            {
                if let Ok(table) = Table::read_file(&tbl_path.path) {
                    if let Ok(skies) = world_skies(&table) {
                        self.world_skies = skies;
                    }
                }
            }
        }
        if self.world_zones.is_empty() {
            if let Some(zone_path) = index
                .resolve("DB/WorldZone.tbl")
                .or_else(|| index.find_name("WorldZone.tbl").into_iter().next())
            {
                if let Ok(ztable) = Table::read_file(&zone_path.path) {
                    if let Ok(zones) = world_zones(&ztable) {
                        self.world_zones = zones;
                    }
                }
            }
        }
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
        let dir = evaluated.sun_direction.normalize();
        // Prevent colinear NaN / panic when sun points straight down or up
        let up = if dir.dot(Vec3::Y).abs() > 0.98 {
            Vec3::Z
        } else {
            Vec3::Y
        };
        *transform = Transform::from_translation(Vec3::ZERO)
            .looking_to(dir, up);
    }
}

#[derive(Component)]
pub struct GenesisSun;

/// Component tagging spawned skybox root entities that should follow the camera translation.
#[derive(Component)]
pub struct SkyboxRoot;

/// Marker component for the base skydome background mesh.
#[derive(Component)]
pub struct SkyboxDome;

/// Marker and tracking data for celestial and sky models (suns, moons, stars, clouds).
#[derive(Component)]
pub struct SkyboxCelestial {
    pub model_index: usize,
    pub sky_path: String,
    pub base_scale: f32,
    pub material_handles: Vec<Handle<StandardMaterial>>,
}

/// Creates an inward-facing dome mesh for the background ambient sky gradient.
pub fn create_skydome_mesh(radius: f32, rings: usize, sectors: usize) -> Mesh {
    let mut positions: Vec<[f32; 3]> = Vec::new();
    let mut normals: Vec<[f32; 3]> = Vec::new();
    let mut uvs: Vec<[f32; 2]> = Vec::new();
    let mut indices: Vec<u32> = Vec::new();

    for r in 0..=rings {
        let phi = (r as f32 / rings as f32) * (std::f32::consts::FRAC_PI_2 * 1.1);
        let y = phi.cos() * radius;
        let sin_phi = phi.sin();

        for s in 0..=sectors {
            let theta = (s as f32 / sectors as f32) * std::f32::consts::TAU;
            let x = sin_phi * theta.sin() * radius;
            let z = sin_phi * theta.cos() * radius;

            positions.push([x, y, z]);
            let norm = Vec3::new(x, y, z).normalize_or_zero();
            normals.push([-norm.x, -norm.y, -norm.z]); // Inward facing
            uvs.push([s as f32 / sectors as f32, r as f32 / rings as f32]);
        }
    }

    for r in 0..rings {
        for s in 0..sectors {
            let first = (r * (sectors + 1) + s) as u32;
            let second = first + (sectors + 1) as u32;

            // Inverted winding so inside faces are front-facing
            indices.push(first);
            indices.push(second);
            indices.push(first + 1);

            indices.push(second);
            indices.push(second + 1);
            indices.push(first + 1);
        }
    }

    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, positions);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, normals);
    mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
    mesh.insert_indices(Indices::U32(indices));
    mesh
}

/// Rebuild the complete skybox hierarchy for the given `sky_id`.
pub fn rebuild_skybox(
    commands: &mut Commands,
    sky_mgr: &mut SkyManager,
    sky_id: u32,
    index: &AssetIndex,
    meshes: &mut Assets<Mesh>,
    materials: &mut Assets<StandardMaterial>,
    images: &mut Assets<Image>,
    cache: &crate::props::PropModelCache,
) {
    // Despawn existing skybox entities
    if let Some(old) = sky_mgr.skybox_root_entity.take() {
        if let Ok(mut ent) = commands.get_entity(old) {
            ent.despawn();
        }
    }

    let Some(sky_file) = sky_mgr.get_sky_by_id(index, sky_id) else { return; };
    sky_mgr.current_sky_id = Some(sky_id);
    let sky_path = sky_mgr.world_skies.get(&sky_id).map(|ws| ws.asset_path.clone()).unwrap_or_default();
    sky_mgr.current_sky_path = Some(sky_path.clone());

    let root_entity = commands.spawn((
        SkyboxRoot,
        Transform::default(),
        InheritedVisibility::default(),
    )).id();
    sky_mgr.skybox_root_entity = Some(root_entity);

    // 1. Spawn base procedural skydome
    let dome_mesh = create_skydome_mesh(4500.0, 16, 32);
    let initial_ambient = sky_mgr.current_evaluated.as_ref().map(|e| e.ambient_color).unwrap_or(Color::srgb(0.15, 0.2, 0.3));
    let dome_mat = materials.add(StandardMaterial {
        base_color: initial_ambient,
        unlit: true,
        cull_mode: None,
        alpha_mode: AlphaMode::Blend,
        fog_enabled: false,
        ..default()
    });
    let dome_ent = commands.spawn((
        SkyboxDome,
        Mesh3d(meshes.add(dome_mesh)),
        MeshMaterial3d(dome_mat),
        Transform::default(),
        InheritedVisibility::default(),
    )).id();
    commands.entity(root_entity).add_child(dome_ent);

    // 2. Spawn celestial and skybox models from sky_file.models
    for (model_index, sky_model) in sky_file.models.iter().enumerate() {
        let Some(bytes) = crate::props::read_asset(index, &sky_model.path) else { continue; };
        let Ok(parts) = crate::props::m3_geometry(&bytes) else { continue; };

        // Determine bounding radius of model to scale appropriately
        let mut max_dist_sq: f32 = 0.0;
        for (geom, _) in &parts {
            for pos in &geom.positions {
                let d2 = pos[0]*pos[0] + pos[1]*pos[1] + pos[2]*pos[2];
                if d2 > max_dist_sq { max_dist_sq = d2; }
            }
        }
        let r = max_dist_sq.sqrt().max(0.1);
        let base_scale = (3800.0 / r).clamp(400.0, 4800.0);

        let mut part_materials = Vec::new();
        let mut part_entities = Vec::new();
        for (geom, desc) in parts {
            let color = desc.color.as_deref().and_then(|p| cache.texture(index, images, p));
            let normal = desc.normal.as_deref().and_then(|p| cache.normal_map(index, images, p));
            let mut mesh = geom.into_mesh();
            if normal.is_some() {
                crate::props::generate_fast_tangents(&mut mesh);
            }
            let mut mat = crate::props::standard_material(crate::props::ModelKind::M3, &desc, color, normal);
            mat.unlit = true;
            mat.cull_mode = None;
            mat.alpha_mode = AlphaMode::Blend;
            mat.fog_enabled = false;
            let mat_handle = materials.add(mat);
            part_materials.push(mat_handle.clone());
            let child = commands.spawn((
                Mesh3d(meshes.add(mesh)),
                MeshMaterial3d(mat_handle),
                Transform::default(),
                InheritedVisibility::default(),
            )).id();
            part_entities.push(child);
        }

        let celestial_ent = commands.spawn((
            Transform::from_scale(Vec3::splat(base_scale)),
            InheritedVisibility::default(),
            SkyboxCelestial {
                model_index,
                sky_path: sky_path.clone(),
                base_scale,
                material_handles: part_materials,
            },
        )).id();
        for child in part_entities {
            commands.entity(celestial_ent).add_child(child);
        }
        commands.entity(root_entity).add_child(celestial_ent);
    }
}

/// System that syncs Bevy's directional light and triggers skybox rebuilding with the evaluated WildStar sky.
pub fn update_sky_lighting(
    mut commands: Commands,
    state: Res<crate::GenesisState>,
    mut sky_mgr: ResMut<SkyManager>,
    client: Res<crate::client_data::ClientFiles>,
    loaded: Res<crate::LoadedArea>,
    streaming: Res<crate::streaming::WorldStreaming>,
    orbit: Res<crate::OrbitCamera>,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut images: ResMut<Assets<Image>>,
    mut lights: Query<(&mut DirectionalLight, &mut Transform), (With<GenesisSun>, Without<crate::GenesisCamera>, Without<SkyboxRoot>)>,
    dome_q: Query<&MeshMaterial3d<StandardMaterial>, With<SkyboxDome>>,
) {
    let Some(index) = client.index.as_ref() else { return; };
    let _ = sky_mgr.ensure_tables(index);

    // Convert UI slider hours (0.0 .. 24.0) to day seconds
    let time_seconds = (state.time_of_day * 3600.0).clamp(0.0, 86400.0);
    sky_mgr.time_of_day = time_seconds;

    // 1. Sample camera position to determine active zone and sky weights
    let cam_pos = orbit.origin();
    let (mut active_skies, mut current_zone) = streaming.sample_sky_and_zone_at(cam_pos.x, cam_pos.z);

    if active_skies.is_empty() {
        if let Some(tile) = loaded.tile.as_ref() {
            let rel_x = cam_pos.x.clamp(0.0, 511.999);
            let rel_z = cam_pos.z.clamp(0.0, 511.999);
            let (tile_skies, tile_zone) = tile.sample_sky_and_zone(rel_x, rel_z);
            active_skies = tile_skies;
            if current_zone.is_none() {
                current_zone = tile_zone;
            }
        }
    }

    sky_mgr.current_zone_id = current_zone;

    // 2. Determine dominant / primary sky ID
    let primary_sky_id = active_skies.first().map(|(id, _)| *id)
        .or_else(|| streaming.fallback_sky_id())
        .or_else(|| loaded.tile.as_ref().and_then(|tile| tile.all_sky_ids().into_iter().next()))
        .or_else(|| {
            if sky_mgr.world_skies.contains_key(&11) {
                Some(11)
            } else {
                sky_mgr.world_skies.keys().copied().next()
            }
        });

    if let Some(primary_sky_id) = primary_sky_id {
        if sky_mgr.current_sky_id != Some(primary_sky_id) {
            rebuild_skybox(
                &mut commands,
                &mut sky_mgr,
                primary_sky_id,
                index,
                &mut meshes,
                &mut materials,
                &mut images,
                &client.prop_models,
            );
        }

        // 3. Evaluate and blend all active skies
        let mut evaluated_list = Vec::with_capacity(active_skies.len());
        for &(sky_id, weight) in &active_skies {
            if let Some(sky_file) = sky_mgr.get_sky_by_id(index, sky_id) {
                let eval = evaluate_sky(&sky_file, time_seconds);
                evaluated_list.push((eval, weight));
            }
        }

        let eval = if !evaluated_list.is_empty() {
            blend_evaluated_skies(&evaluated_list)
        } else if let Some(sky_file) = sky_mgr.get_sky_by_id(index, primary_sky_id) {
            evaluate_sky(&sky_file, time_seconds)
        } else {
            EvaluatedSky::default()
        };

        for (mut light, mut transform) in lights.iter_mut() {
            apply_sky_to_sun_light(&eval, &mut light, &mut transform);
        }
        // Update dome color
        for dome_mat_handle in dome_q.iter() {
            if let Some(mut mat) = materials.get_mut(&dome_mat_handle.0) {
                mat.base_color = eval.ambient_color;
            }
        }
        sky_mgr.current_evaluated = Some(eval);
    }
}

/// System to sync celestial model rotations and tints each frame as time of day progresses.
pub fn update_skybox_celestials(
    sky_mgr: Res<SkyManager>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut query: Query<(&SkyboxCelestial, &mut Transform, &mut Visibility)>,
) {
    let time_seconds = sky_mgr.time_of_day;
    for (celestial, mut transform, mut visibility) in query.iter_mut() {
        let Some(sky_file) = sky_mgr.loaded_skies.get(&celestial.sky_path) else { continue; };
        let Some(sky_model) = sky_file.models.get(celestial.model_index) else { continue; };
        if sky_model.track.is_empty() {
            *visibility = Visibility::Inherited;
            transform.scale = Vec3::splat(celestial.base_scale);
            continue;
        }
        if let Some(vals) = sky_model.track.sample(time_seconds) {
            let elev = vals.first().copied().unwrap_or(0.0);
            let azim = vals.get(1).copied().unwrap_or(0.0);
            let r = vals.get(4).copied().unwrap_or(1.0);
            let g = vals.get(5).copied().unwrap_or(1.0);
            let b = vals.get(6).copied().unwrap_or(1.0);
            let a = vals.get(7).copied().unwrap_or(1.0);

            if a < 0.005 {
                *visibility = Visibility::Hidden;
            } else {
                *visibility = Visibility::Inherited;
                let elev_rad = elev.to_radians();
                let azim_rad = azim.to_radians();
                let cos_elev = elev_rad.cos();
                let target_dir = Vec3::new(
                    azim_rad.sin() * cos_elev,
                    elev_rad.sin(),
                    -azim_rad.cos() * cos_elev,
                ).normalize_or_zero();

                if target_dir.length_squared() > 1e-4 {
                    let up = if target_dir.dot(Vec3::Y).abs() > 0.98 { Vec3::Z } else { Vec3::Y };
                    transform.rotation = Transform::IDENTITY.looking_to(target_dir, up).rotation;
                }
                transform.scale = Vec3::splat(celestial.base_scale);

                // Update material tint
                for mat_handle in &celestial.material_handles {
                    if let Some(mut mat) = materials.get_mut(mat_handle) {
                        mat.base_color = Color::srgba(r.clamp(0.0, 2.0), g.clamp(0.0, 2.0), b.clamp(0.0, 2.0), a.clamp(0.0, 1.0));
                    }
                }
            }
        }
    }
}

/// System to sync skybox root position to the main camera so sky elements remain at visual infinity.
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

/// System to update camera distance fog and background clear color based on evaluated sky parameters.
pub fn update_camera_fog(
    sky_mgr: Res<SkyManager>,
    mut cameras: Query<(&mut Camera, &mut DistanceFog), With<crate::GenesisCamera>>,
) {
    let Some(eval) = sky_mgr.current_evaluated.as_ref() else { return; };
    for (mut camera, mut fog) in cameras.iter_mut() {
        camera.clear_color = ClearColorConfig::Custom(eval.horizon_fog_mod);
        fog.color = eval.horizon_fog_mod;
        let start = if eval.fog_start.is_finite() { eval.fog_start.max(0.0) } else { 100.0 };
        let end = if eval.fog_end.is_finite() { eval.fog_end.max(start + 10.0) } else { 2000.0 };
        fog.falloff = FogFalloff::Linear {
            start,
            end,
        };
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
