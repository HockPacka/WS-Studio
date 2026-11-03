//! UV-derived tangent frames for M3/I3 normal-mapped geometry.
//! Pure math, independent of Bevy, so the renderer and format tests can share it.
//! For each vertex we Gram-Schmidt-orthogonalize the accumulated triangle
//! tangent against its shading normal. The fourth component is bitangent
//! handedness (negative for mirrored UVs), as required by Bevy's PBR shader.

fn dot(a: [f32; 3], b: [f32; 3]) -> f32 {
    a[0] * b[0] + a[1] * b[1] + a[2] * b[2]
}

fn cross(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0],
    ]
}

fn sub(a: [f32; 3], b: [f32; 3]) -> [f32; 3] {
    [a[0] - b[0], a[1] - b[1], a[2] - b[2]]
}

fn normalize(a: [f32; 3]) -> Option<[f32; 3]> {
    let length_sq = dot(a, a);
    if !length_sq.is_finite() || length_sq <= 1.0e-16 {
        return None;
    }
    let inv = length_sq.sqrt().recip();
    Some([a[0] * inv, a[1] * inv, a[2] * inv])
}

/// Compute one tangent (xyz) and UV-handedness (w) per vertex.
///
/// Returns `None` for malformed vertex streams or indices rather than
/// producing an attribute whose length disagrees with the mesh's positions.
/// Zero-area UV triangles are ignored; vertices without usable triangle UVs
/// receive a finite orthogonal fallback frame. No normal-map texture data is
/// modified here.
///
/// M3/I3 readers already split most authored UV seams into separate vertices.
/// If a source mesh *shares* vertices across opposite-handed UV islands,
/// splitting those vertices is still required for exact seam rendering.
pub fn generate_tangents(
    positions: &[[f32; 3]],
    normals: &[[f32; 3]],
    uv0: &[[f32; 2]],
    indices: &[u32],
) -> Option<Vec<[f32; 4]>> {
    let count = positions.len();
    if normals.len() != count || uv0.len() != count || indices.len() % 3 != 0 {
        return None;
    }

    let mut tangent_sum = vec![[0.0_f32; 3]; count];
    let mut bitangent_sum = vec![[0.0_f32; 3]; count];

    for tri in indices.chunks_exact(3) {
        let [a, b, c] = [tri[0] as usize, tri[1] as usize, tri[2] as usize];
        if a >= count || b >= count || c >= count {
            return None;
        }

        let edge1 = sub(positions[b], positions[a]);
        let edge2 = sub(positions[c], positions[a]);
        let du1 = uv0[b][0] - uv0[a][0];
        let dv1 = uv0[b][1] - uv0[a][1];
        let du2 = uv0[c][0] - uv0[a][0];
        let dv2 = uv0[c][1] - uv0[a][1];
        let determinant = du1 * dv2 - dv1 * du2;
        if !determinant.is_finite() || determinant.abs() < 1.0e-8 {
            continue;
        }

        let area = dot(cross(edge1, edge2), cross(edge1, edge2)).sqrt();
        if !area.is_finite() || area <= 1.0e-8 {
            continue;
        }
        let factor = area / determinant;
        let tangent = [
            (edge1[0] * dv2 - edge2[0] * dv1) * factor,
            (edge1[1] * dv2 - edge2[1] * dv1) * factor,
            (edge1[2] * dv2 - edge2[2] * dv1) * factor,
        ];
        let bitangent = [
            (edge2[0] * du1 - edge1[0] * du2) * factor,
            (edge2[1] * du1 - edge1[1] * du2) * factor,
            (edge2[2] * du1 - edge1[2] * du2) * factor,
        ];
        if !tangent.iter().chain(bitangent.iter()).all(|v| v.is_finite()) {
            continue;
        }
        for index in [a, b, c] {
            for axis in 0..3 {
                tangent_sum[index][axis] += tangent[axis];
                bitangent_sum[index][axis] += bitangent[axis];
            }
        }
    }

    let mut result = Vec::with_capacity(count);
    for i in 0..count {
        let n = normalize(normals[i]).unwrap_or([0.0, 1.0, 0.0]);
        let projected = [
            tangent_sum[i][0] - n[0] * dot(n, tangent_sum[i]),
            tangent_sum[i][1] - n[1] * dot(n, tangent_sum[i]),
            tangent_sum[i][2] - n[2] * dot(n, tangent_sum[i]),
        ];
        let fallback_axis = if n[1].abs() > 0.9 {
            [1.0, 0.0, 0.0]
        } else {
            [0.0, 1.0, 0.0]
        };
        let tangent = normalize(projected)
            .or_else(|| normalize(cross(fallback_axis, n)))
            .unwrap_or([1.0, 0.0, 0.0]);
        let sign = if dot(cross(n, tangent), bitangent_sum[i]) < 0.0 {
            -1.0
        } else {
            1.0
        };
        result.push([tangent[0], tangent[1], tangent[2], sign]);
    }
    Some(result)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn unit_quad() -> ([[f32; 3]; 4], [[f32; 3]; 4], [[f32; 2]; 4], [u32; 6]) {
        (
            [[0., 0., 0.], [1., 0., 0.], [1., 1., 0.], [0., 1., 0.]],
            [[0., 0., 1.]; 4],
            [[0., 0.], [1., 0.], [1., 1.], [0., 1.]],
            [0, 1, 2, 0, 2, 3],
        )
    }

    #[test]
    fn quad_uvs_align_tangents_with_u_axis() {
        let (positions, normals, uvs, indices) = unit_quad();
        let result = generate_tangents(&positions, &normals, &uvs, &indices).unwrap();
        for t in result {
            assert!((t[0] - 1.0).abs() < 1.0e-5);
            assert!(t[1].abs() < 1.0e-5 && t[2].abs() < 1.0e-5);
            assert_eq!(t[3], 1.0);
        }
    }

    #[test]
    fn mirrored_uvs_flip_handedness_without_flipping_normals() {
        let (positions, normals, mut uvs, indices) = unit_quad();
        for uv in &mut uvs { uv[0] = -uv[0]; }
        let result = generate_tangents(&positions, &normals, &uvs, &indices).unwrap();
        for t in result {
            assert!((t[0] + 1.0).abs() < 1.0e-5);
            assert_eq!(t[3], -1.0);
        }
    }

    #[test]
    fn degenerate_uvs_produce_finite_orthogonal_fallback() {
        let (positions, normals, _, indices) = unit_quad();
        let uvs = [[0.0, 0.0]; 4];
        let result = generate_tangents(&positions, &normals, &uvs, &indices).unwrap();
        assert_eq!(result.len(), 4);
        for t in result {
            assert!(t.iter().all(|v| v.is_finite()));
            assert!(dot([t[0], t[1], t[2]], [0., 0., 1.]).abs() < 1.0e-5);
            assert!((dot([t[0], t[1], t[2]], [t[0], t[1], t[2]]) - 1.0).abs() < 1.0e-5);
        }
    }

    #[test]
    fn rejects_mismatched_streams_and_invalid_indices() {
        let (positions, normals, uvs, indices) = unit_quad();
        assert!(generate_tangents(&positions, &normals[..3], &uvs, &indices).is_none());
        assert!(generate_tangents(&positions, &normals, &uvs, &[0, 1, 9]).is_none());
        assert!(generate_tangents(&positions, &normals, &uvs, &[0, 1]).is_none());
    }
}
