// Runtime WorldLayer splatting (4 layers per 32 m cell), modelled on LandPS:
// colour = sum(weight_i * layer_i(world metres / tiling)) * macro tint.
import bevy_pbr::render::{
    pbr_fragment::pbr_input_from_standard_material,
    pbr_functions::{alpha_discard, apply_pbr_lighting, main_pass_post_lighting_processing, calculate_tbn_mikktspace},
    forward_io::{VertexOutput, FragmentOutput},
};

struct SplatParams {
    enabled: u32,
    has_normals: u32,
    tile_meters: f32,
    pad: u32,
    tiling: array<vec4<f32>, 64>,
}

@group(constants::MATERIAL_BIND_GROUP) @binding(100) var<uniform> splat: SplatParams;
@group(constants::MATERIAL_BIND_GROUP) @binding(101) var albedo_layers: texture_2d_array<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(102) var layer_sampler: sampler;
@group(constants::MATERIAL_BIND_GROUP) @binding(103) var normal_layers: texture_2d_array<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(104) var weight_map: texture_2d<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(105) var weight_sampler: sampler;
@group(constants::MATERIAL_BIND_GROUP) @binding(106) var tint_map: texture_2d<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(107) var cell_layers: texture_2d<f32>;

@fragment
fn fragment(
    vertex_output: VertexOutput,
    @builtin(front_facing) is_front: bool,
) -> FragmentOutput {
    var in = vertex_output;
    var pbr_input = pbr_input_from_standard_material(in, is_front);

    if (splat.enabled != 0u) {
        let uv = in.uv;
        let meters = uv * splat.tile_meters;
        // Derivatives are taken here, in uniform control flow, then reused for every layer fetch.
        let dx = dpdx(meters);
        let dy = dpdy(meters);
        let cell = clamp(vec2<i32>(floor(uv * 16.0)), vec2<i32>(0), vec2<i32>(15));
        let ids = textureLoad(cell_layers, cell, 0) * 255.0;
        let weights = textureSample(weight_map, weight_sampler, uv);
        let tint = textureSample(tint_map, weight_sampler, uv).rgb * (255.0 / 128.0);

        var color = vec3<f32>(0.0);
        var normal = vec3<f32>(0.0);
        var total = 0.0;
        for (var slot = 0u; slot < 4u; slot++) {
            let id = u32(ids[slot] + 0.5);
            let w = weights[slot];
            if (id < 254u && w > 0.0001) {
                let t = splat.tiling[id >> 2u][id & 3u];
                let p = meters * t;
                color += textureSampleGrad(albedo_layers, layer_sampler, p, id, dx * t, dy * t).rgb * w;
                if (splat.has_normals != 0u) {
                    let n = textureSampleGrad(normal_layers, layer_sampler, p, id, dx * t, dy * t).xyz;
                    normal += (n * 2.0 - 1.0) * w;
                }
                total += w;
            }
        }
        if (total > 0.0001) {
            pbr_input.material.base_color = vec4<f32>(color / total * tint, 1.0);
            if (splat.has_normals != 0u) {
                let tbn = calculate_tbn_mikktspace(pbr_input.world_normal, in.world_tangent);
                pbr_input.N = normalize(tbn * normalize(normal));
            }
        }
    }

    pbr_input.material.base_color = alpha_discard(
        pbr_input.material.flags,
        pbr_input.material.alpha_cutoff,
        pbr_input.material.base_color,
    );

    var out: FragmentOutput;
    out.color = apply_pbr_lighting(pbr_input);
    out.color = main_pass_post_lighting_processing(pbr_input, out.color);
    return out;
}
