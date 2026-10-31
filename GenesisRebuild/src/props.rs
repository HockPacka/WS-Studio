//! World prop instances for WildStar pORP / PORP chunks.
//! `.m3` / `.i3` models are read natively from the ClientData index; every texture
//! path stored in the model metadata is resolved through the same index.
use std::collections::HashMap;
use std::sync::Mutex;

use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, Mesh, PrimitiveTopology};
use bevy::prelude::*;
use bevy::render::render_resource::{Extent3d, TextureDimension, TextureFormat};
use wildstar_formats::area::AreaProp;
use wildstar_formats::assets::{virtual_key, AssetIndex};
use wildstar_formats::tex::decode_tex;
use wildstar_formats::{i3, m3};

/// Model files above this size are not loaded synchronously.
const MAX_MODEL_BYTES: u64 = 64 * 1024 * 1024;
/// Triangles kept per prop model.
const MAX_MODEL_TRIANGLES: usize = 400_000;
/// New models decoded per `spawn_props` call; the rest keep the marker cube until the next load.
const MODEL_LOADS_PER_CALL: usize = 48;
/// Longest edge of a decoded prop texture.
const MAX_TEXTURE_SIZE: usize = 512;

#[derive(Component)]
#[allow(dead_code)]
pub struct PropMarker {
    pub index: usize,
    pub model_path: Option<String>,
}

#[derive(Clone, Copy, PartialEq, Eq)]
pub enum ModelKind {
    M3,
    I3,
}

#[derive(Clone)]
struct ModelPart {
    mesh: Handle<Mesh>,
    texture: Option<Handle<Image>>,
}

#[derive(Clone)]
struct CachedModel {
    kind: ModelKind,
    parts: Vec<ModelPart>,
}

/// Decoded prop models, textures and metadata reports by virtual path.
#[derive(Default)]
pub struct PropModelCache {
    models: Mutex<HashMap<String, Option<CachedModel>>>,
    textures: Mutex<HashMap<String, Option<Handle<Image>>>>,
    reports: Mutex<HashMap<String, Vec<String>>>,
}

/// Geometry of one draw part (vertices are remapped so parts do not duplicate the whole buffer).
#[derive(Default)]
struct PartGeometry {
    positions: Vec<[f32; 3]>,
    normals: Vec<[f32; 3]>,
    uvs: Vec<[f32; 2]>,
    indices: Vec<u32>,
    remap: HashMap<u32, u32>,
}
impl PartGeometry {
    fn push_vertex(&mut self, source: u32, pos: [f32; 3], normal: [f32; 3], uv: [f32; 2]) -> u32 {
        if let Some(&i) = self.remap.get(&source) {
            return i;
        }
        let i = self.positions.len() as u32;
        self.positions.push(pos);
        self.normals.push(normal);
        self.uvs.push(uv);
        self.remap.insert(source, i);
        i
    }
    fn into_mesh(self) -> Mesh {
        let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
        mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, self.positions);
        mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, self.normals);
        mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, self.uvs);
        mesh.insert_indices(Indices::U32(self.indices));
        mesh
    }
}

fn read_asset(index: &AssetIndex, path: &str) -> Option<Vec<u8>> {
    let file = index.resolve(path)?;
    if std::fs::metadata(&file.path).ok()?.len() > MAX_MODEL_BYTES {
        return None;
    }
    std::fs::read(&file.path).ok()
}

/// One geometry per material of the model, with the texture path of the material's first layer.
fn m3_geometry(data: &[u8]) -> Result<Vec<(PartGeometry, Option<String>)>, String> {
    let model = m3::read_m3(data)?;
    if model.visible_indices().len() / 3 > MAX_MODEL_TRIANGLES {
        return Err("M3 too large".into());
    }
    let mut by_material: Vec<(u16, PartGeometry)> = Vec::new();
    for mesh in model.meshes.iter().filter(|m| !m.is_hidden()) {
        let slot = match by_material.iter().position(|(m, _)| *m == mesh.material) {
            Some(i) => i,
            None => {
                by_material.push((mesh.material, PartGeometry::default()));
                by_material.len() - 1
            }
        };
        let geometry = &mut by_material[slot].1;
        let start = mesh.start_index as usize;
        for &ix in &model.indices[start..start + mesh.index_count as usize] {
            let v = model.vertices[ix as usize];
            let i = geometry.push_vertex(ix, v.pos, v.normal, v.uv);
            geometry.indices.push(i);
        }
    }
    let parts: Vec<_> = by_material
        .into_iter()
        .filter(|(_, g)| !g.indices.is_empty())
        .map(|(material, g)| {
            let texture = model
                .materials
                .get(material as usize)
                .and_then(|m| m.color_texture)
                .and_then(|t| model.textures.get(t))
                .map(|t| t.name.clone());
            (g, texture)
        })
        .collect();
    if parts.is_empty() {
        return Err("no drawable M3 geometry".into());
    }
    Ok(parts)
}

/// One geometry per material of material set 0 over all sectors of a FEDI model.
fn i3_geometry(index: &AssetIndex, model_path: &str, data: &[u8]) -> Result<Vec<(PartGeometry, Option<String>)>, String> {
    let model = i3::read_model(data)?;
    let set = model.sets.first();
    let mut by_material: Vec<(usize, PartGeometry)> = Vec::new();
    let mut triangles = 0usize;
    for sector in 0..model.sectors.len() {
        let Some(path) = model.sector_path(model_path, sector) else { continue };
        let Some(bytes) = read_asset(index, &path) else { continue };
        let Ok(mesh) = i3::read_sector(&bytes) else { continue };
        for sub in mesh.submeshes.iter() {
            let Some(material) = sub.material() else { continue };
            let slot = match by_material.iter().position(|(m, _)| *m == material) {
                Some(i) => i,
                None => {
                    by_material.push((material, PartGeometry::default()));
                    by_material.len() - 1
                }
            };
            let geometry = &mut by_material[slot].1;
            for tri in sub.triangles() {
                for &ix in &mesh.indices[tri * 3..tri * 3 + 3] {
                    // Vertex ids are per sector; keep them distinct between sectors.
                    let key = ix ^ ((sector as u32) << 24);
                    let u = ix as usize;
                    let i = geometry.push_vertex(key, mesh.positions[u], mesh.normals[u], mesh.uv0[u]);
                    geometry.indices.push(i);
                }
                triangles += 1;
            }
        }
        if triangles > MAX_MODEL_TRIANGLES {
            break;
        }
    }
    let parts: Vec<_> = by_material
        .into_iter()
        .map(|(material, g)| {
            let texture = set.and_then(|s| s.color_texture(0, material)).map(str::to_string);
            (g, texture)
        })
        .collect();
    if parts.is_empty() {
        return Err("no drawable I3 sector geometry".into());
    }
    Ok(parts)
}

fn model_kind(path: &str) -> Option<ModelKind> {
    let lower = path.to_ascii_lowercase();
    if lower.ends_with(".m3") {
        Some(ModelKind::M3)
    } else if lower.ends_with(".i3") {
        Some(ModelKind::I3)
    } else {
        None
    }
}

impl PropModelCache {
    fn texture(&self, index: &AssetIndex, images: &mut Assets<Image>, path: &str) -> Option<Handle<Image>> {
        let key = virtual_key(path);
        let mut map = self.textures.lock().ok()?;
        if let Some(hit) = map.get(&key) {
            return hit.clone();
        }
        let handle = read_asset(index, path)
            .and_then(|data| decode_tex(&data, MAX_TEXTURE_SIZE).ok())
            .filter(|t| t.width > 0 && t.height > 0)
            .map(|t| {
                images.add(Image::new(
                    Extent3d { width: t.width as u32, height: t.height as u32, depth_or_array_layers: 1 },
                    TextureDimension::D2,
                    t.rgba,
                    TextureFormat::Rgba8UnormSrgb,
                    RenderAssetUsages::default(),
                ))
            });
        map.insert(key, handle.clone());
        handle
    }

    fn load(
        &self,
        index: &AssetIndex,
        meshes: &mut Assets<Mesh>,
        images: &mut Assets<Image>,
        path: &str,
        budget: &mut usize,
    ) -> Option<CachedModel> {
        let kind = model_kind(path)?;
        let key = virtual_key(path);
        if let Some(hit) = self.models.lock().ok()?.get(&key) {
            return hit.clone();
        }
        if *budget == 0 {
            return None;
        }
        *budget -= 1;
        let built = read_asset(index, path).and_then(|data| match kind {
            ModelKind::M3 => m3_geometry(&data).ok(),
            ModelKind::I3 => i3_geometry(index, path, &data).ok(),
        });
        let entry = built.map(|parts| CachedModel {
            kind,
            parts: parts
                .into_iter()
                .map(|(geometry, texture)| ModelPart {
                    mesh: meshes.add(geometry.into_mesh()),
                    texture: texture.and_then(|t| self.texture(index, images, &t)),
                })
                .collect(),
        });
        self.models.lock().ok()?.insert(key, entry.clone());
        entry
    }

    /// Human readable metadata of a model; every referenced path is checked against the client index.
    pub fn report(&self, index: &AssetIndex, path: &str) -> Vec<String> {
        let key = virtual_key(path);
        if let Some(hit) = self.reports.lock().ok().and_then(|r| r.get(&key).cloned()) {
            return hit;
        }
        let lines = build_report(index, path);
        if let Ok(mut reports) = self.reports.lock() {
            reports.insert(key, lines.clone());
        }
        lines
    }
}

fn found(index: &AssetIndex, path: &str) -> &'static str {
    if index.resolve(path).is_some() { "OK" } else { "MISSING" }
}

fn build_report(index: &AssetIndex, path: &str) -> Vec<String> {
    let mut out = vec![format!("File: {} [{}]", path, found(index, path))];
    let Some(kind) = model_kind(path) else {
        out.push("Not an .m3/.i3 model".into());
        return out;
    };
    let Some(file) = index.resolve(path) else { return out };
    let Ok(data) = std::fs::read(&file.path) else {
        out.push("Cannot read file".into());
        return out;
    };
    match kind {
        ModelKind::M3 => match m3::read_m3(&data) {
            Ok(m) => {
                out.push(format!("M3: {} vertices, {} triangles, {} meshes ({} hidden)",
                    m.vertices.len(), m.triangle_count(), m.meshes.len(),
                    m.meshes.iter().filter(|x| x.is_hidden()).count()));
                out.push(format!("Bounds: {:?} .. {:?}", m.bounds_min, m.bounds_max));
                out.push(format!("Bones: {}, clips: {}, materials: {}", m.bones.len(), m.clips.len(), m.materials.len()));
                for (i, t) in m.textures.iter().enumerate() {
                    let kind = match t.kind { 0 => "color", 1 => "normal", 2 => "skinfx", _ => "?" };
                    out.push(format!("Texture {i} ({kind}): {} [{}]", t.name, found(index, &t.name)));
                }
            }
            Err(e) => out.push(format!("M3 read error: {e}")),
        },
        ModelKind::I3 => match i3::read_model(&data) {
            Ok(m) => {
                out.push(format!("I3 bounds: {:?} .. {:?}", m.bbox_min, m.bbox_max));
                out.push(format!("Portals: {}", m.portals.len()));
                for (i, name) in m.sectors.iter().enumerate() {
                    let sector = m.sector_path(path, i).unwrap_or_default();
                    out.push(format!("Sector {i} '{name}' ({}): {} [{}]",
                        if m.sector_exterior[i] { "exterior" } else { "interior" }, sector, found(index, &sector)));
                }
                for set in &m.sets {
                    out.push(format!("Material set '{}': {} textures, {} passes", set.name, set.textures.len(), set.passes.len()));
                    for t in set.textures.iter().filter(|t| !t.is_empty()) {
                        out.push(format!("  {t} [{}]", found(index, t)));
                    }
                }
            }
            Err(e) => {
                // A FEDS sector opened directly.
                match i3::read_sector(&data) {
                    Ok(s) => out.push(format!("I3 sector '{}': {} vertices, {} triangles, {} submeshes",
                        s.name, s.positions.len(), s.triangle_count(), s.submeshes.len())),
                    Err(_) => out.push(format!("I3 read error: {e}")),
                }
            }
        },
    }
    out
}

pub fn spawn_props(
    commands: &mut Commands,
    props: &[AreaProp],
    meshes: &mut Assets<Mesh>,
    materials: &mut Assets<StandardMaterial>,
    images: &mut Assets<Image>,
    index: Option<&AssetIndex>,
    cache: &PropModelCache,
) -> Vec<Entity> {
    if props.is_empty() {
        return Vec::new();
    }

    // Shared mesh for prop indicator markers (models that cannot be read).
    let marker_mesh = meshes.add(Cuboid::new(1.0, 1.0, 1.0));
    let marker_material = materials.add(StandardMaterial {
        base_color: Color::srgb(0.9, 0.75, 0.25),
        perceptual_roughness: 0.4,
        metallic: 0.2,
        ..default()
    });
    let mut part_materials: HashMap<(Option<AssetId<Image>>, bool), Handle<StandardMaterial>> = HashMap::new();
    let mut budget = MODEL_LOADS_PER_CALL;
    let mut entities = Vec::with_capacity(props.len().min(5000));
    for prop in props.iter().take(5000) {
        let pos = Vec3::new(prop.position_xyz[0], prop.position_xyz[1], prop.position_xyz[2]);
        let q = prop.rotation_xyzw;
        let len_sq = q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3];
        let rot = if len_sq > 0.0001 {
            Quat::from_xyzw(q[0], q[1], q[2], q[3]).normalize()
        } else {
            Quat::IDENTITY
        };
        let scale = Vec3::splat(prop.scale.clamp(0.1, 50.0));
        let transform = Transform { translation: pos, rotation: rot, scale };
        let marker = PropMarker { index: prop.index, model_path: prop.model_path.clone() };

        let model = index
            .zip(prop.model_path.as_deref())
            .and_then(|(index, path)| cache.load(index, meshes, images, path, &mut budget));
        let entity = match model {
            Some(model) => {
                let root = commands.spawn((transform, Visibility::default(), marker)).id();
                for part in &model.parts {
                    let key = (part.texture.as_ref().map(|t| t.id()), model.kind == ModelKind::M3);
                    let material = part_materials
                        .entry(key)
                        .or_insert_with(|| {
                            materials.add(StandardMaterial {
                                base_color: if part.texture.is_some() {
                                    Color::WHITE
                                } else if model.kind == ModelKind::M3 {
                                    Color::srgb(0.55, 0.65, 0.8)
                                } else {
                                    Color::srgb(0.78, 0.7, 0.55)
                                },
                                base_color_texture: part.texture.clone(),
                                perceptual_roughness: 0.8,
                                cull_mode: None,
                                ..default()
                            })
                        })
                        .clone();
                    let child = commands
                        .spawn((Mesh3d(part.mesh.clone()), MeshMaterial3d(material), Transform::default()))
                        .id();
                    commands.entity(root).add_child(child);
                }
                root
            }
            None => commands
                .spawn((Mesh3d(marker_mesh.clone()), MeshMaterial3d(marker_material.clone()), transform, marker))
                .id(),
        };
        entities.push(entity);
    }
    entities
}
