// M3 native layer slots 1..3: alpha-over approximation for the World Editor.
// The exact WildStar shader permutation/mask and color1 blend semantics
// are not verified. Layer 0 retains Bevy's StandardMaterial PBR/normal/glow.
import bevy_pbr::render::{
    pbr_fragment::pbr_input_from_standard_material,
    pbr_functions::{alpha_discard, apply_pbr_lighting, main_pass_post_lighting_processing},
    forward_io::{VertexOutput, FragmentOutput},
};

struct M3LayerParams {
    colour: array<vec4<f32>, 3>,
    enabled: vec4<u32>,
}

@group(constants::MATERIAL_BIND_GROUP) @binding(100) var<uniform> layers: M3LayerParams;
@group(constants::MATERIAL_BIND_GROUP) @binding(101) var colour1: texture_2d<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(102) var sampler1: sampler;
@group(constants::MATERIAL_BIND_GROUP) @binding(103) var colour2: texture_2d<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(104) var sampler2: sampler;
@group(constants::MATERIAL_BIND_GROUP) @binding(105) var colour3: texture_2d<f32>;
@group(constants::MATERIAL_BIND_GROUP) @binding(106) var sampler3: sampler;

@fragment
fn fragment(vertex_output: VertexOutput, @builtin(front_facing) front: bool) -> FragmentOutput {
    var pbr = pbr_input_from_standard_material(vertex_output, front);
    var base = pbr.material.base_color;
    let uv = vertex_output.uv;
    if (layers.enabled.x != 0u) {
        let texel = textureSample(colour1, sampler1, uv);
        let amount = clamp(texel.a * layers.colour[0].x, 0.0, 1.0);
        base.rgb = mix(base.rgb, texel.rgb * layers.colour[0].yzw, amount);
    }
    if (layers.enabled.y != 0u) {
        let texel = textureSample(colour2, sampler2, uv);
        let amount = clamp(texel.a * layers.colour[1].x, 0.0, 1.0);
        base.rgb = mix(base.rgb, texel.rgb * layers.colour[1].yzw, amount);
    }
    if (layers.enabled.z != 0u) {
        let texel = textureSample(colour3, sampler3, uv);
        let amount = clamp(texel.a * layers.colour[2].x, 0.0, 1.0);
        base.rgb = mix(base.rgb, texel.rgb * layers.colour[2].yzw, amount);
    }
    pbr.material.base_color = alpha_discard(
        pbr.material.flags, pbr.material.alpha_cutoff, base
    );
    var output: FragmentOutput;
    output.color = apply_pbr_lighting(pbr);
    output.color = main_pass_post_lighting_processing(pbr, output.color);
    return output;
}
