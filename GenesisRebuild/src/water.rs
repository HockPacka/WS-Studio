//! Water geometry and material generator for WildStar GtAW subchunks.
use bevy::asset::RenderAssetUsages;
use bevy::mesh::{Indices, PrimitiveTopology};
use bevy::prelude::*;
use wildstar_formats::area::WaterBody;

pub fn water_mesh(bodies: &[WaterBody]) -> Option<Mesh> {
    if bodies.is_empty() {
        return None;
    }
    let mut positions = Vec::new();
    let mut normals = Vec::new();
    let mut uvs = Vec::new();
    let mut colors = Vec::new();
    let mut indices = Vec::new();

    let mut vertex_offset = 0u32;
    for body in bodies {
        if body.vertices.is_empty() || body.indices.is_empty() {
            continue;
        }
        for v in &body.vertices {
            positions.push(v.position);
            normals.push(v.normal);
            uvs.push(v.uv);
            colors.push([0.2f32, 0.55f32, 0.8f32, 0.75f32]);
        }
        for &idx in &body.indices {
            indices.push(vertex_offset + idx);
        }
        vertex_offset += body.vertices.len() as u32;
    }

    if indices.is_empty() {
        return None;
    }

    let vertex_count = positions.len();
    let mut mesh = Mesh::new(PrimitiveTopology::TriangleList, RenderAssetUsages::default());
    mesh.insert_attribute(Mesh::ATTRIBUTE_POSITION, positions);
    mesh.insert_attribute(Mesh::ATTRIBUTE_NORMAL, normals);
    mesh.insert_attribute(Mesh::ATTRIBUTE_UV_0, uvs);
    mesh.insert_attribute(Mesh::ATTRIBUTE_COLOR, colors);
    let tangents = vec![[1.0f32, 0.0f32, 0.0f32, 1.0f32]; vertex_count];
    mesh.insert_attribute(Mesh::ATTRIBUTE_TANGENT, tangents);
    mesh.insert_indices(Indices::U32(indices));
    Some(mesh)
}

pub fn water_material() -> StandardMaterial {
    StandardMaterial {
        base_color: Color::srgba(0.18, 0.52, 0.78, 0.75),
        perceptual_roughness: 0.08,
        metallic: 0.1,
        reflectance: 0.85,
        alpha_mode: AlphaMode::Blend,
        cull_mode: None,
        double_sided: true,
        ..default()
    }
}
