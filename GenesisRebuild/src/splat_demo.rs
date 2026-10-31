//! Self-test of the terrain splat shader without any WildStar data:
//! `GENESIS_SPLAT_DEMO=out.png genesis` renders procedural layers, saves a screenshot and exits.
use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, PrimitiveTopology};
use bevy::pbr::ExtendedMaterial;
use bevy::prelude::*;
use bevy::render::render_resource::{Extent3d, TextureDimension, TextureFormat};
use bevy::render::view::screenshot::{save_to_disk, Screenshot};

use crate::terrain_splat::{SplatData, TerrainMaterial, TerrainSplatPlugin};

const SIDE: usize = 128;

#[derive(Resource)]
struct Out(String);

pub fn run(out: String) {
    App::new()
        .insert_resource(Out(out))
        .add_plugins(DefaultPlugins.set(WindowPlugin {
            primary_window: Some(Window { resolution: (900, 560).into(), ..default() }),
            ..default()
        }))
        .add_plugins(TerrainSplatPlugin)
        .add_systems(Startup, setup)
        .add_systems(Update, capture)
        .run();
}

fn mips(base: Vec<u8>) -> Vec<u8> {
    let mut out = base.clone();
    let (mut prev, mut size) = (base, SIDE);
    while size > 1 {
        let n = size / 2;
        let mut next = vec![0u8; n * n * 4];
        for y in 0..n {
            for x in 0..n {
                for c in 0..4 {
                    let at = |dx: usize, dy: usize| prev[((y * 2 + dy) * size + x * 2 + dx) * 4 + c] as u32;
                    next[(y * n + x) * 4 + c] = ((at(0, 0) + at(1, 0) + at(0, 1) + at(1, 1) + 2) / 4) as u8;
                }
            }
        }
        out.extend_from_slice(&next);
        prev = next;
        size = n;
    }
    out
}

fn layer_pixels(layer: usize) -> (Vec<u8>, Vec<u8>) {
    let mut color = Vec::new();
    let mut normal = Vec::new();
    for y in 0..SIDE {
        for x in 0..SIDE {
            let (fx, fy) = (x as f32 / SIDE as f32, y as f32 / SIDE as f32);
            let wave = (fx * std::f32::consts::TAU * 4.0).sin() * (fy * std::f32::consts::TAU * 4.0).sin();
            let rgb = match layer {
                0 => [60.0 + 40.0 * wave, 140.0 + 30.0 * wave, 50.0], // grass
                1 => [200.0, 170.0 + 30.0 * wave, 80.0],              // path
                _ => [110.0 + 25.0 * wave, 105.0, 100.0],            // rock
            };
            let edge = x < 2 || y < 2; // visible tile seams prove the repeat
            let k = if edge { 0.4 } else { 1.0 };
            color.extend_from_slice(&[(rgb[0] * k) as u8, (rgb[1] * k) as u8, (rgb[2] * k) as u8, 255]);
            let (nx, ny) = (wave * 0.4, (fx * 25.0).cos() * 0.1);
            let n = Vec3::new(nx, ny, 1.0).normalize();
            normal.extend_from_slice(&[((n.x * 0.5 + 0.5) * 255.0) as u8, ((n.y * 0.5 + 0.5) * 255.0) as u8, ((n.z * 0.5 + 0.5) * 255.0) as u8, 255]);
        }
    }
    (mips(color), mips(normal))
}

fn splat_data() -> SplatData {
    let (mut albedo, mut normals) = (Vec::new(), Vec::new());
    for layer in 0..3 {
        let (c, n) = layer_pixels(layer);
        albedo.extend(c);
        normals.extend(n);
    }
    let image = |data: Vec<u8>, w: usize, layers: usize, format, levels: u32| {
        let mut image = Image::new_uninit(
            Extent3d { width: w as u32, height: w as u32, depth_or_array_layers: layers as u32 },
            TextureDimension::D2,
            format,
            RenderAssetUsages::default(),
        );
        image.data = Some(data);
        image.texture_descriptor.mip_level_count = levels;
        image
    };
    let levels = (SIDE as f32).log2() as u32 + 1;
    let mut albedo_img = image(albedo, SIDE, 3, TextureFormat::Rgba8UnormSrgb, levels);
    albedo_img.sampler = bevy::image::ImageSampler::Descriptor(bevy::image::ImageSamplerDescriptor {
        address_mode_u: bevy::image::ImageAddressMode::Repeat,
        address_mode_v: bevy::image::ImageAddressMode::Repeat,
        mag_filter: bevy::image::ImageFilterMode::Linear,
        min_filter: bevy::image::ImageFilterMode::Linear,
        mipmap_filter: bevy::image::ImageFilterMode::Linear,
        ..default()
    });
    const MAP: usize = 1024;
    let mut weights = vec![0u8; MAP * MAP * 4];
    let mut tint = vec![128u8; MAP * MAP * 4];
    for z in 0..MAP {
        for x in 0..MAP {
            let p = (z * MAP + x) * 4;
            let fx = x as f32 / MAP as f32;
            let path = (1.0 - ((fx - 0.5 + (z as f32 / 90.0).sin() * 0.08).abs() * 14.0)).clamp(0.0, 1.0);
            weights[p] = ((1.0 - path) * 255.0) as u8; // slot 0 = grass
            weights[p + 1] = (path * 255.0) as u8;     // slot 1 = path
            tint[p + 3] = 255;
        }
    }
    // cell slots: grass, path, rock, none (rock stays unused: weight 0)
    let mut cells = Vec::new();
    for _ in 0..256 {
        cells.extend_from_slice(&[0u8, 1, 2, 255]);
    }
    let mut cell_layers = image(cells, 16, 1, TextureFormat::Rgba8Unorm, 1);
    cell_layers.sampler = bevy::image::ImageSampler::nearest();
    SplatData {
        albedo: albedo_img,
        normals: image(normals, SIDE, 3, TextureFormat::Rgba8Unorm, levels),
        weights: image(weights, MAP, 1, TextureFormat::Rgba8Unorm, 1),
        tint: image(tint, MAP, 1, TextureFormat::Rgba8Unorm, 1),
        cell_layers,
        tiling: vec![0.25; 3],
        has_normals: true,
        layer_count: 3,
    }
}

fn setup(
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<TerrainMaterial>>,
    mut images: ResMut<Assets<Image>>,
) {
    let n = 64usize;
    let (mut pos, mut nor, mut uv, mut idx) = (Vec::new(), Vec::new(), Vec::new(), Vec::new());
    let height = |x: f32, z: f32| (x * 0.03).sin() * 3.0 + (z * 0.02).cos() * 2.0;
    for z in 0..=n {
        for x in 0..=n {
            let (wx, wz) = (x as f32 / n as f32 * 512.0 - 256.0, z as f32 / n as f32 * 512.0 - 256.0);
            pos.push([wx, height(wx, wz), wz]);
            let dx = (height(wx + 1.0, wz) - height(wx - 1.0, wz)) / 2.0;
            let dz = (height(wx, wz + 1.0) - height(wx, wz - 1.0)) / 2.0;
            nor.push(Vec3::new(-dx, 1.0, -dz).normalize().to_array());
            uv.push([x as f32 / n as f32, z as f32 / n as f32]);
        }
    }
    for z in 0..n {
        for x in 0..n {
            let a = (z * (n + 1) + x) as u32;
            idx.extend_from_slice(&[a, a + n as u32 + 1, a + 1, a + 1, a + n as u32 + 1, a + n as u32 + 2]);
        }
    }
    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, pos);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, nor);
    mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uv);
    mesh.insert_attribute(Mesh::ATTRIBUTE_TANGENT, vec![[1.0f32, 0.0, 0.0, 1.0]; (n + 1) * (n + 1)]);
    mesh.insert_indices(Indices::U32(idx));
    commands.spawn((
        Mesh3d(meshes.add(mesh)),
        MeshMaterial3d(materials.add(ExtendedMaterial {
            base: StandardMaterial { base_color: Color::WHITE, perceptual_roughness: 0.85, cull_mode: None, ..default() },
            extension: splat_data().into_extension(&mut images, true),
        })),
    ));
    commands.spawn((DirectionalLight { illuminance: 12000.0, ..default() },
        Transform::from_xyz(-40.0, 60.0, 30.0).looking_at(Vec3::ZERO, Vec3::Y)));
    commands.spawn((Camera3d::default(), Transform::from_xyz(0.0, 12.0, 70.0).looking_at(Vec3::new(0.0, 0.0, 0.0), Vec3::Y)));
}

fn capture(mut commands: Commands, out: Res<Out>, mut frame: Local<u32>) {
    *frame += 1;
    if *frame == 90 {
        commands.spawn(Screenshot::primary_window()).observe(save_to_disk(out.0.clone()));
    }
    if *frame == 150 {
        std::process::exit(0);
    }
}
