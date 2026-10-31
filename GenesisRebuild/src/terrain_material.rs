//! High-fidelity WildStar terrain-material renderer.
//! Composites diffuse albedo + tangent-space normal maps using real WorldLayer.tbl
//! paths, real TEX textures, multi-layer blend weights (Bit 29 / 17+18 / 2),
//! bilinear sampling, and macro color tints (Bit 3 / Bit 13).
use bevy::asset::RenderAssetUsages;
use bevy::prelude::*;
use bevy::render::render_resource::{Extent3d, TextureDimension, TextureFormat, TextureViewDescriptor, TextureViewDimension};
use std::collections::{HashMap, HashSet};
use wildstar_formats::area::{AreaCell, RawArea};
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::tbl::{Table, WorldLayer, world_layers};
use wildstar_formats::tex::{decode_tex, RgbaImage};
use crate::terrain_splat::{SplatData, MAX_LAYERS, NO_LAYER};
use bevy::image::{ImageAddressMode, ImageFilterMode, ImageSampler, ImageSamplerDescriptor};
use std::sync::Arc;

/// 128 px per 32 m cell = 0.25 m per atlas pixel (2048x2048 per tile).
const PX_PER_CELL: usize = 128;
/// Longest edge of a decoded WorldLayer texture.
const LAYER_TEXTURE_SIZE: usize = 1024;
pub const ATLAS_SIDE: usize = 16 * PX_PER_CELL;

pub struct AtlasResult {
    /// Runtime splat data; when present the atlas images are 1x1 placeholders.
    pub splat: Option<SplatData>,
    pub albedo_image: Image,
    pub normal_image: Option<Image>,
    pub layers: usize,
    pub textures: usize,
    pub unresolved: Vec<String>,
    pub notes: Vec<String>,
}

pub fn decode_layers(index: &AssetIndex) -> Result<HashMap<u32, WorldLayer>, String> {
    let path = index
        .resolve("DB/WorldLayer.tbl")
        .or_else(|| index.find_name("WorldLayer.tbl").into_iter().next())
        .ok_or("WorldLayer.tbl missing in ClientData or ClientDataEN")?;
    let tbl = Table::read_file(&path.path)?;
    world_layers(&tbl)
}

use std::sync::Mutex;

#[derive(Default)]
pub struct TextureCache {
    pub diffuse: HashMap<String, RgbaImage>,
    pub normal: HashMap<String, RgbaImage>,
    /// Edge length of the splat texture array layers (0 = default 512).
    pub splat_side: usize,
    /// Resampled layer data with mip chain by (layer id, side): (albedo sRGB, tangent normal).
    pub splat_layers: HashMap<(u32, usize), Arc<(Vec<u8>, Vec<u8>)>>,
}

fn collect_textures(
    area: &RawArea,
    index: &AssetIndex,
    layers: &HashMap<u32, WorldLayer>,
    cache: &Mutex<TextureCache>,
) -> (
    HashMap<u32, RgbaImage>,
    HashMap<u32, RgbaImage>,
    Vec<String>,
    usize,
) {
    let mut diffuse_images = HashMap::new();
    let mut normal_images = HashMap::new();
    let mut seen_diffuse = HashSet::new();
    let mut seen_normal = HashSet::new();
    let mut errors = Vec::new();
    let mut used = HashSet::new();

    for cell in area.cells.iter().flatten() {
        if let Some(ids) = cell.layers() {
            for id in ids {
                if id == 0 {
                    continue;
                }
                used.insert(id);
                let Some(layer) = layers.get(&id) else {
                    errors.push(format!("WorldLayer #{id}: missing database row"));
                    continue;
                };

                // Diffuse texture
                if !layer.color_map.is_empty() && seen_diffuse.insert(id) {
                    let cached = cache.lock().ok().and_then(|c| c.diffuse.get(&layer.color_map).cloned());
                    if let Some(image) = cached {
                        diffuse_images.insert(id, image);
                    } else if let Some(asset) = index.resolve(&layer.color_map) {
                        match std::fs::read(&asset.path) {
                            Ok(data) => match decode_tex(&data, LAYER_TEXTURE_SIZE) {
                                Ok(image) => {
                                    if let Ok(mut c) = cache.lock() {
                                        c.diffuse.insert(layer.color_map.clone(), image.clone());
                                    }
                                    diffuse_images.insert(id, image);
                                }
                                Err(error) => errors.push(format!(
                                    "WorldLayer #{id} {}: {error}",
                                    layer.color_map
                                )),
                            },
                            Err(error) => errors.push(format!(
                                "WorldLayer #{id}: cannot read {}: {error}",
                                asset.path.display()
                            )),
                        }
                    } else {
                        errors.push(format!("WorldLayer #{id}: missing {}", layer.color_map));
                    }
                }

                // Normal texture
                if !layer.normal_map.is_empty() && seen_normal.insert(id) {
                    let cached = cache.lock().ok().and_then(|c| c.normal.get(&layer.normal_map).cloned());
                    if let Some(image) = cached {
                        normal_images.insert(id, image);
                    } else if let Some(asset) = index.resolve(&layer.normal_map) {
                        match std::fs::read(&asset.path) {
                            Ok(data) => match decode_tex(&data, LAYER_TEXTURE_SIZE) {
                                Ok(image) => {
                                    if let Ok(mut c) = cache.lock() {
                                        c.normal.insert(layer.normal_map.clone(), image.clone());
                                    }
                                    normal_images.insert(id, image);
                                }
                                Err(error) => errors.push(format!(
                                    "WorldLayer #{id} normal {}: {error}",
                                    layer.normal_map
                                )),
                            },
                            Err(error) => errors.push(format!(
                                "WorldLayer #{id}: cannot read normal {}: {error}",
                                asset.path.display()
                            )),
                        }
                    }
                }
            }
        }
    }

    (diffuse_images, normal_images, errors, used.len())
}

pub(crate) fn unpack_normal(raw: [u8; 4]) -> [f32; 3] {
    let [r, g, b, a] = raw;
    // Detect DXT5nm vs RGB normal map
    // In DXT5nm, alpha is X, green is Y, red and blue are constant/unused
    if (r == g && r == b) || (r > 200 && b > 200) || (a != 255 && a != 0) {
        let nx = (a as f32 / 255.0) * 2.0 - 1.0;
        let ny = (g as f32 / 255.0) * 2.0 - 1.0;
        let nz = (1.0 - nx * nx - ny * ny).max(0.0).sqrt();
        [nx, ny, nz]
    } else {
        let nx = (r as f32 / 255.0) * 2.0 - 1.0;
        let ny = (g as f32 / 255.0) * 2.0 - 1.0;
        let nz = ((b as f32 / 255.0) * 2.0 - 1.0).max(0.01);
        let len = (nx * nx + ny * ny + nz * nz).sqrt().max(0.0001);
        [nx / len, ny / len, nz / len]
    }
}

fn weights(cell: &AreaCell, sx: usize, sz: usize) -> [f32; 4] {
    if let Some(w) = cell.compressed_weights(sx, sz) {
        return w;
    }
    let raw = cell
        .normalized_weights(sx, sz)
        .or_else(|| cell.authoring_weights(sx, sz));
    let Some(raw) = raw else {
        return [1., 0., 0., 0.];
    };
    let sum: usize = raw.iter().map(|&v| v as usize).sum();
    if sum == 0 {
        return [1., 0., 0., 0.];
    }
    raw.map(|v| v as f32 / sum as f32)
}

fn macro_tint(cell: &AreaCell, sx: usize, sz: usize) -> [f32; 3] {
    if let Some(rgb) = cell.terrain_color(sx, sz) {
        // Neutral in WildStar is (128, 128, 128)
        [
            rgb[0] as f32 / 128.0,
            rgb[1] as f32 / 128.0,
            rgb[2] as f32 / 128.0,
        ]
    } else {
        [1.0, 1.0, 1.0]
    }
}

fn fallback_rgb(cell: &AreaCell, sx: usize, sz: usize) -> [u8; 4] {
    cell.terrain_color(sx, sz)
        .map(|[r, g, b]| [r, g, b, 255])
        .unwrap_or([116, 116, 116, 255])
}

/// Resample to `side` x `side` (box filter when shrinking by an integer factor, bilinear otherwise).
fn resample(img: &RgbaImage, side: usize) -> Vec<u8> {
    let mut out = vec![255u8; side * side * 4];
    if img.width == 0 || img.height == 0 {
        return out;
    }
    let kx = img.width / side;
    let ky = img.height / side;
    for y in 0..side {
        for x in 0..side {
            let p = (y * side + x) * 4;
            if kx >= 1 && ky >= 1 && img.width % side == 0 && img.height % side == 0 {
                let mut acc = [0u32; 4];
                for yy in 0..ky {
                    for xx in 0..kx {
                        let q = ((y * ky + yy) * img.width + x * kx + xx) * 4;
                        for c in 0..4 {
                            acc[c] += img.rgba[q + c] as u32;
                        }
                    }
                }
                let n = (kx * ky) as u32;
                for c in 0..4 {
                    out[p + c] = (acc[c] / n) as u8;
                }
            } else {
                let px = img.sample_bilinear((x as f32 + 0.5) / side as f32, (y as f32 + 0.5) / side as f32);
                out[p..p + 4].copy_from_slice(&px);
            }
        }
    }
    out
}

/// `base` followed by every smaller mip level down to 1x1 (2x2 box filter).
fn with_mips(base: Vec<u8>, side: usize) -> Vec<u8> {
    let mut out = base.clone();
    let (mut prev, mut size) = (base, side);
    while size > 1 {
        let next_size = size / 2;
        let mut next = vec![0u8; next_size * next_size * 4];
        for y in 0..next_size {
            for x in 0..next_size {
                for c in 0..4 {
                    let at = |dx: usize, dy: usize| prev[((y * 2 + dy) * size + x * 2 + dx) * 4 + c] as u32;
                    next[(y * next_size + x) * 4 + c] = ((at(0, 0) + at(1, 0) + at(0, 1) + at(1, 1) + 2) / 4) as u8;
                }
            }
        }
        out.extend_from_slice(&next);
        prev = next;
        size = next_size;
    }
    out
}

fn array_image(data: Vec<u8>, side: usize, layers: usize, format: TextureFormat, sampler: bool) -> Image {
    let levels = (side as f32).log2() as u32 + 1;
    let mut image = Image::new_uninit(
        Extent3d { width: side as u32, height: side as u32, depth_or_array_layers: layers.max(1) as u32 },
        TextureDimension::D2,
        format,
        RenderAssetUsages::default(),
    );
    image.data = Some(data);
    image.texture_descriptor.mip_level_count = levels;
    image.texture_view_descriptor = Some(TextureViewDescriptor {
        dimension: Some(TextureViewDimension::D2Array),
        ..default()
    });
    if sampler {
        image.sampler = ImageSampler::Descriptor(ImageSamplerDescriptor {
            address_mode_u: ImageAddressMode::Repeat,
            address_mode_v: ImageAddressMode::Repeat,
            address_mode_w: ImageAddressMode::Repeat,
            mag_filter: ImageFilterMode::Linear,
            min_filter: ImageFilterMode::Linear,
            mipmap_filter: ImageFilterMode::Linear,
            anisotropy_clamp: 16,
            ..default()
        });
    }
    image
}

/// Texture arrays, per-cell layer indices, weight map and macro tint for the runtime splat shader.
fn build_splat(
    area: &RawArea,
    layers: &HashMap<u32, WorldLayer>,
    diffuse: &HashMap<u32, RgbaImage>,
    normals: &HashMap<u32, RgbaImage>,
    cache: &Mutex<TextureCache>,
) -> Option<SplatData> {
    let side = cache.lock().ok().map(|c| c.splat_side).filter(|&s| s > 0).unwrap_or(512);
    let mut ids: Vec<u32> = diffuse.keys().copied().collect();
    ids.sort_unstable();
    ids.truncate(MAX_LAYERS);
    if ids.is_empty() {
        return None;
    }
    let slot_of: HashMap<u32, u8> = ids.iter().enumerate().map(|(i, &id)| (id, i as u8)).collect();

    let mut albedo = Vec::new();
    let mut normal = Vec::new();
    let mut tiling = Vec::with_capacity(ids.len());
    for &id in &ids {
        let cached = cache.lock().ok().and_then(|c| c.splat_layers.get(&(id, side)).cloned());
        let blob = cached.unwrap_or_else(|| {
            let color = resample(&diffuse[&id], side);
            let n = match normals.get(&id) {
                Some(img) => {
                    let raw = resample(img, side);
                    let mut out = vec![255u8; side * side * 4];
                    for (src, dst) in raw.chunks_exact(4).zip(out.chunks_exact_mut(4)) {
                        let v = unpack_normal([src[0], src[1], src[2], src[3]]);
                        for c in 0..3 {
                            dst[c] = ((v[c] * 0.5 + 0.5) * 255.0).clamp(0.0, 255.0).round() as u8;
                        }
                    }
                    out
                }
                None => [128u8, 128, 255, 255].repeat(side * side),
            };
            let blob = Arc::new((with_mips(color, side), with_mips(n, side)));
            if let Ok(mut c) = cache.lock() {
                c.splat_layers.insert((id, side), blob.clone());
            }
            blob
        });
        albedo.extend_from_slice(&blob.0);
        normal.extend_from_slice(&blob.1);
        tiling.push(1.0 / layers.get(&id).map(|l| l.meters_per_tile.max(0.1)).unwrap_or(4.0));
    }

    const MAP: usize = 16 * 64;
    let mut weight_px = vec![0u8; MAP * MAP * 4];
    let mut tint_px = vec![128u8; MAP * MAP * 4];
    let mut cell_px = vec![NO_LAYER; 16 * 16 * 4];
    for (cell_index, cell) in area.cells.iter().enumerate() {
        let Some(cell) = cell.as_ref() else { continue };
        let cell_ids = cell.layers().unwrap_or([0; 4]);
        let slots: [Option<u8>; 4] = std::array::from_fn(|i| slot_of.get(&cell_ids[i]).copied());
        for (i, slot) in slots.iter().enumerate() {
            cell_px[cell_index * 4 + i] = slot.unwrap_or(NO_LAYER);
        }
        let (cx, cz) = (cell_index % 16, cell_index / 16);
        for z in 0..64 {
            for x in 0..64 {
                let w = weights(cell, x, z);
                let p = ((cz * 64 + z) * MAP + cx * 64 + x) * 4;
                for i in 0..4 {
                    weight_px[p + i] = if slots[i].is_some() { (w[i] * 255.0).round() as u8 } else { 0 };
                }
                if let Some(rgb) = cell.terrain_color(x, z) {
                    tint_px[p..p + 3].copy_from_slice(&rgb);
                }
                tint_px[p + 3] = 255;
            }
        }
    }

    let flat = |data: Vec<u8>, side: usize, format| {
        Image::new(
            Extent3d { width: side as u32, height: side as u32, depth_or_array_layers: 1 },
            TextureDimension::D2,
            data,
            format,
            RenderAssetUsages::default(),
        )
    };
    let has_normals = !normals.is_empty();
    Some(SplatData {
        albedo: array_image(albedo, side, ids.len(), TextureFormat::Rgba8UnormSrgb, true),
        normals: array_image(normal, side, ids.len(), TextureFormat::Rgba8Unorm, false),
        weights: flat(weight_px, MAP, TextureFormat::Rgba8Unorm),
        tint: flat(tint_px, MAP, TextureFormat::Rgba8Unorm),
        cell_layers: {
            let mut image = flat(cell_px, 16, TextureFormat::Rgba8Unorm);
            image.sampler = ImageSampler::nearest();
            image
        },
        tiling,
        has_normals,
        layer_count: ids.len(),
    })
}

pub fn bake(area: &RawArea, index: &AssetIndex) -> Result<AtlasResult, String> {
    let layers = decode_layers(index)?;
    let cache = Mutex::new(TextureCache::default());
    bake_with_cache(area, index, &layers, &cache)
}

pub fn bake_with_cache(
    area: &RawArea,
    index: &AssetIndex,
    layers: &HashMap<u32, WorldLayer>,
    cache: &Mutex<TextureCache>,
) -> Result<AtlasResult, String> {
    let (diffuse_images, normal_images, unresolved, layer_count) =
        collect_textures(area, index, layers, cache);

    if diffuse_images.is_empty() {
        let detail = unresolved
            .iter()
            .take(5)
            .cloned()
            .collect::<Vec<_>>()
            .join(" | ");
        return Err(format!(
            "0/{layer_count} terrain textures decoded. {detail}"
        ));
    }

    // Preferred path: blend at runtime in the terrain shader at full texture resolution.
    if let Some(splat) = build_splat(area, layers, &diffuse_images, &normal_images, cache) {
        let placeholder = |pixel: [u8; 4], format| {
            Image::new(
                Extent3d { width: 1, height: 1, depth_or_array_layers: 1 },
                TextureDimension::D2,
                pixel.to_vec(),
                format,
                RenderAssetUsages::default(),
            )
        };
        return Ok(AtlasResult {
            albedo_image: placeholder([255; 4], TextureFormat::Rgba8UnormSrgb),
            normal_image: None,
            layers: layer_count,
            textures: diffuse_images.len(),
            unresolved,
            notes: vec![
                format!("Runtime splat shader: {} layers, tiled per pixel at full resolution", splat.layer_count),
                if splat.has_normals { "Tangent-space normal layers blended per pixel".into() } else { "No normal maps found in WorldLayer".into() },
                "Bit 29 / 17+18 / 2 blend weights decoded".into(),
                "Bit 3 / Bit 13 macro color tinting applied (LandPS v6)".into(),
            ],
            splat: Some(splat),
        });
    }

    let has_any_normals = !normal_images.is_empty();
    let mut albedo_pixels = vec![0u8; ATLAS_SIDE * ATLAS_SIDE * 4];
    let mut normal_pixels = if has_any_normals {
        vec![0u8; ATLAS_SIDE * ATLAS_SIDE * 4]
    } else {
        Vec::new()
    };

    let step_meters = 32.0 / PX_PER_CELL as f32;

    for index_cell in 0..256 {
        let Some(cell) = area.cells[index_cell].as_ref() else {
            continue;
        };
        let ids = cell.layers().unwrap_or([0; 4]);
        let base_x = (index_cell % 16) as f32 * 32.0;
        let base_z = (index_cell / 16) as f32 * 32.0;

        // Pre-resolve active cell textures and inverse tiling (avoids millions of hash lookups)
        let mut active_layers: Vec<(usize, &RgbaImage, Option<&RgbaImage>, f32)> = Vec::with_capacity(4);
        for i in 0..4 {
            let id = ids[i];
            if id != 0 {
                if let Some(diff) = diffuse_images.get(&id) {
                    let norm = normal_images.get(&id);
                    let tiling = layers.get(&id).map(|l| l.meters_per_tile.max(0.1)).unwrap_or(4.0);
                    active_layers.push((i, diff, norm, 1.0 / tiling));
                }
            }
        }

        for z in 0..PX_PER_CELL {
            let sz = (z * 65) / PX_PER_CELL;
            for x in 0..PX_PER_CELL {
                let sx = (x * 65) / PX_PER_CELL;
                let w = weights(cell, sx, sz);
                let tint = macro_tint(cell, sx, sz);
                let base = fallback_rgb(cell, sx, sz);

                let wx = base_x + (x as f32 + 0.5) * step_meters;
                let wz = base_z + (z as f32 + 0.5) * step_meters;

                let mut col_sum = [0f32; 3];
                let mut norm_sum = [0f32; 3];
                let mut norm_weight_sum = 0f32;

                if active_layers.is_empty() {
                    col_sum = [base[0] as f32, base[1] as f32, base[2] as f32];
                } else {
                    for &(layer_idx, diff_tex, norm_tex, inv_tiling) in &active_layers {
                        let weight = w[layer_idx];
                        if weight <= 0.0001 {
                            continue;
                        }
                        let u = wx * inv_tiling;
                        let v = wz * inv_tiling;

                        // Diffuse
                        let col = diff_tex.sample_bilinear(u, v);
                        for c in 0..3 {
                            col_sum[c] += col[c] as f32 * weight;
                        }

                        // Normal
                        if has_any_normals {
                            if let Some(ntex) = norm_tex {
                                let nraw = ntex.sample_bilinear(u, v);
                                let n = unpack_normal(nraw);
                                for c in 0..3 {
                                    norm_sum[c] += n[c] * weight;
                                }
                                norm_weight_sum += weight;
                            }
                        }
                    }
                }

                // Apply macro tint (LandPS: mul r2.xyz, r2, v6)
                for c in 0..3 {
                    col_sum[c] = (col_sum[c] * tint[c]).clamp(0.0, 255.0);
                }

                let px = (index_cell / 16 * PX_PER_CELL + z) * ATLAS_SIDE
                    + (index_cell % 16 * PX_PER_CELL + x);
                let p = px * 4;

                albedo_pixels[p] = col_sum[0].round() as u8;
                albedo_pixels[p + 1] = col_sum[1].round() as u8;
                albedo_pixels[p + 2] = col_sum[2].round() as u8;
                albedo_pixels[p + 3] = 255;

                if has_any_normals {
                    if norm_weight_sum > 0.0001 {
                        let len = (norm_sum[0] * norm_sum[0]
                            + norm_sum[1] * norm_sum[1]
                            + norm_sum[2] * norm_sum[2])
                            .sqrt()
                            .max(0.0001);
                        let nx = norm_sum[0] / len;
                        let ny = norm_sum[1] / len;
                        let nz = norm_sum[2] / len;
                        normal_pixels[p] =
                            ((nx * 0.5 + 0.5) * 255.0).clamp(0.0, 255.0).round() as u8;
                        normal_pixels[p + 1] =
                            ((ny * 0.5 + 0.5) * 255.0).clamp(0.0, 255.0).round() as u8;
                        normal_pixels[p + 2] =
                            ((nz * 0.5 + 0.5) * 255.0).clamp(0.0, 255.0).round() as u8;
                        normal_pixels[p + 3] = 255;
                    } else {
                        // Neutral tangent normal [0, 0, 1] -> [128, 128, 255]
                        normal_pixels[p] = 128;
                        normal_pixels[p + 1] = 128;
                        normal_pixels[p + 2] = 255;
                        normal_pixels[p + 3] = 255;
                    }
                }
            }
        }
    }

    let albedo_image = Image::new(
        Extent3d {
            width: ATLAS_SIDE as u32,
            height: ATLAS_SIDE as u32,
            depth_or_array_layers: 1,
        },
        TextureDimension::D2,
        albedo_pixels,
        TextureFormat::Rgba8UnormSrgb,
        RenderAssetUsages::default(),
    );

    let normal_image = if has_any_normals {
        Some(Image::new(
            Extent3d {
                width: ATLAS_SIDE as u32,
                height: ATLAS_SIDE as u32,
                depth_or_array_layers: 1,
            },
            TextureDimension::D2,
            normal_pixels,
            TextureFormat::Rgba8Unorm,
            RenderAssetUsages::default(),
        ))
    } else {
        None
    };

    Ok(AtlasResult {
        splat: None,
        albedo_image,
        normal_image,
        layers: layer_count,
        textures: diffuse_images.len(),
        unresolved,
        notes: vec![
            format!("{ATLAS_SIDE}x{ATLAS_SIDE} 4-layer bilinear albedo atlas with true tiling"),
            if has_any_normals {
                "Tangent-space normal maps blended & applied".into()
            } else {
                "No normal maps found in WorldLayer".into()
            },
            "Bit 29 / 17+18 / 2 blend weights decoded".into(),
            "Bit 3 / Bit 13 macro color tinting applied (LandPS v6)".into(),
        ],
    })
}
