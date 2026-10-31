//! World prop instances and visualization for WildStar pORP / PORP chunks.
use std::collections::HashMap;
use std::sync::Mutex;

use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, Mesh, PrimitiveTopology};
use bevy::prelude::*;
use wildstar_formats::area::AreaProp;
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::{i3, m3};

/// Model files above this size are not loaded synchronously.
const MAX_MODEL_BYTES: u64 = 64 * 1024 * 1024;
/// Triangles kept per prop model.
const MAX_MODEL_TRIANGLES: usize = 400_000;
/// New models decoded per `spawn_props` call; the rest keep the marker cube until the next load.
const MODEL_LOADS_PER_CALL: usize = 48;

/// Decoded `.m3` / `.i3` prop meshes by virtual path (`None` = not readable, remembered).
#[derive(Default)]
pub struct PropModelCache {
    meshes: Mutex<HashMap<String, Option<(Handle<Mesh>, ModelKind)>>>,
}

#[derive(Clone, Copy, PartialEq, Eq)]
pub enum ModelKind {
    M3,
    I3,
}

fn mesh_from(positions: Vec<[f32; 3]>, normals: Vec<[f32; 3]>, uvs: Vec<[f32; 2]>, indices: Vec<u32>) -> Mesh {
    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, positions);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, normals);
    mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
    mesh.insert_indices(Indices::U32(indices));
    mesh
}

fn read_asset(index: &AssetIndex, path: &str) -> Option<Vec<u8>> {
    let file = index.resolve(path)?;
    if std::fs::metadata(&file.path).ok()?.len() > MAX_MODEL_BYTES {
        return None;
    }
    std::fs::read(&file.path).ok()
}

pub fn m3_mesh(data: &[u8]) -> Result<Mesh, String> {
    let model = m3::read_m3(data)?;
    let indices = model.visible_indices();
    if indices.is_empty() || indices.len() / 3 > MAX_MODEL_TRIANGLES {
        return Err("no drawable M3 geometry".into());
    }
    Ok(mesh_from(
        model.vertices.iter().map(|v| v.pos).collect(),
        model.vertices.iter().map(|v| v.normal).collect(),
        model.vertices.iter().map(|v| v.uv).collect(),
        indices,
    ))
}

/// All renderable submeshes (collision-only ones are skipped) of every sector of a FEDI model.
pub fn i3_mesh(index: &AssetIndex, model_path: &str, data: &[u8]) -> Result<Mesh, String> {
    let model = i3::read_model(data)?;
    let (mut positions, mut normals, mut uvs, mut indices) = (Vec::new(), Vec::new(), Vec::new(), Vec::new());
    for sector in 0..model.sectors.len() {
        let Some(path) = model.sector_path(model_path, sector) else { continue };
        let Some(bytes) = read_asset(index, &path) else { continue };
        let Ok(sector_mesh) = i3::read_sector(&bytes) else { continue };
        let base = positions.len() as u32;
        positions.extend_from_slice(&sector_mesh.positions);
        normals.extend_from_slice(&sector_mesh.normals);
        uvs.extend_from_slice(&sector_mesh.uv0);
        for sub in sector_mesh.submeshes.iter().filter(|s| !s.is_collision_only()) {
            for tri in sub.triangles() {
                indices.extend(sector_mesh.indices[tri * 3..tri * 3 + 3].iter().map(|i| i + base));
            }
        }
        if indices.len() / 3 > MAX_MODEL_TRIANGLES {
            break;
        }
    }
    if indices.is_empty() {
        return Err("no drawable I3 sector geometry".into());
    }
    Ok(mesh_from(positions, normals, uvs, indices))
}

impl PropModelCache {
    fn load(
        &self,
        index: &AssetIndex,
        meshes: &mut Assets<Mesh>,
        path: &str,
        budget: &mut usize,
    ) -> Option<(Handle<Mesh>, ModelKind)> {
        let lower = path.to_ascii_lowercase();
        let kind = if lower.ends_with(".m3") { ModelKind::M3 } else if lower.ends_with(".i3") { ModelKind::I3 } else { return None };
        let key = wildstar_formats::assets::virtual_key(path);
        let mut map = self.meshes.lock().ok()?;
        if let Some(hit) = map.get(&key) {
            return hit.clone();
        }
        if *budget == 0 {
            return None;
        }
        *budget -= 1;
        let built = read_asset(index, path).and_then(|data| match kind {
            ModelKind::M3 => m3_mesh(&data).ok(),
            ModelKind::I3 => i3_mesh(index, path, &data).ok(),
        });
        let entry = built.map(|mesh| (meshes.add(mesh), kind));
        map.insert(key, entry.clone());
        entry
    }
}

#[derive(Component)]
#[allow(dead_code)]
pub struct PropMarker {
    pub index: usize,
    pub model_path: Option<String>,
}

pub fn spawn_props(
    commands: &mut Commands,
    props: &[AreaProp],
    meshes: &mut Assets<Mesh>,
    materials: &mut Assets<StandardMaterial>,
    index: Option<&AssetIndex>,
    cache: &PropModelCache,
) -> Vec<Entity> {
    if props.is_empty() {
        return Vec::new();
    }

    // Shared mesh for prop indicator markers
    let marker_mesh = meshes.add(Cuboid::new(1.0, 1.0, 1.0));
    let marker_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.9, 0.75, 0.25),
        perceptual_roughness: 0.4,
        metallic: 0.2,
        ..default()
    });

    let m3_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.55, 0.65, 0.8),
        perceptual_roughness: 0.7,
        cull_mode: None,
        ..default()
    });
    let i3_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.78, 0.7, 0.55),
        perceptual_roughness: 0.8,
        cull_mode: None,
        ..default()
    });
    let mut budget = MODEL_LOADS_PER_CALL;
    let mut entities = Vec::with_capacity(props.len().min(5000));
    for prop in props.iter().take(5000) {
        let pos = Vec3::new(
            prop.position_xyz[0],
            prop.position_xyz[1],
            prop.position_xyz[2],
        );

        let q = prop.rotation_xyzw;
        let len_sq = q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3];
        let rot = if len_sq > 0.0001 {
            Quat::from_xyzw(q[0], q[1], q[2], q[3]).normalize()
        } else {
            Quat::IDENTITY
        };

        let scale = Vec3::splat(prop.scale.clamp(0.1, 50.0));

        let model = index
            .zip(prop.model_path.as_deref())
            .and_then(|(index, path)| cache.load(index, meshes, path, &mut budget));
        let transform = Transform { translation: pos, rotation: rot, scale };
        let marker = PropMarker { index: prop.index, model_path: prop.model_path.clone() };
        let entity = match model {
            Some((mesh, kind)) => commands
                .spawn((
                    Mesh3d(mesh),
                    MeshMaterial3d(if kind == ModelKind::M3 { m3_material.clone() } else { i3_material.clone() }),
                    transform,
                    marker,
                ))
                .id(),
            None => commands
                .spawn((Mesh3d(marker_mesh.clone()), MeshMaterial3d(marker_material.clone()), transform, marker))
                .id(),
        };

        entities.push(entity);
    }

    entities
}
