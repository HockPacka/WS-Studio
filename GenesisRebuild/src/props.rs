//! World prop instances and visualization for WildStar pORP / PORP chunks.
use bevy::mesh::Mesh;
use bevy::prelude::*;
use wildstar_formats::area::AreaProp;

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

        let entity = commands
            .spawn((
                Mesh3d(marker_mesh.clone()),
                MeshMaterial3d(marker_material.clone()),
                Transform {
                    translation: pos,
                    rotation: rot,
                    scale,
                },
                PropMarker {
                    index: prop.index,
                    model_path: prop.model_path.clone(),
                },
            ))
            .id();

        entities.push(entity);
    }

    entities
}
