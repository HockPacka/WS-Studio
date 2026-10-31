# WildStar M3 materials / shaders -> what WoW 3.3.5a must be extended to reproduce the original look

Basis: `docs/m3_materials.md`, `docs/i3_shader_notes.md`, `docs/sky_shader_mapping.md`, `docs/m3_texture_fixes_dbg41.md` and a read of the client render path
(`Engine/Source/Model2/M2Shared.cpp::GetEffect`, `M2Scene.cpp::ComputeElementShaders`, `ShaderEffect/*`, `WoW/Source/WorldClient/Map.cpp`, `MapObj.cpp`).
Statements marked (inferred) come from shader disassembly, not from the original CPU code. No in-game comparison screenshots were made for this document.

## 1. How WoW picks a look today (fixed set, no free shader)

* **M2**: `CM2Shared::GetEffect(batch)` builds an effect name from a *vertex* shader (`Diffuse_T1`, `Diffuse_T2`, `Diffuse_Env`, `Diffuse_T1_T2`, `Diffuse_T1_Env`, ...) and a
  *pixel* shader (`Combiners_Opaque`, `_Mod`, `_Add`, `_Mod2x`, `_Decal`, `_Fade`, two-texture pairs `Combiners_X_Y`). Files: `Shaders\Vertex`, `Shaders\Pixel`, `Shaders\Effects`.
  Maximum two texture stages, one UV set per stage, no tangent space, no normal map, no per-material constants besides diffuse / emissive / alpha ref.
  `CM2Scene::ComputeElementShaders` only varies: specular on/off, light count, bone influences (0..2), shadow (0..2), PCF, alpha test. Blend: `s_blendModes[3][7]`.
  Our converter (`M3ToM2.cpp`) writes shader = 0, one texture per M3 layer-0 colour map, blend mode 0..6 from the M3 material -> always `Combiners_Opaque`/`Mod` with `Diffuse_T1`.
* **WMO** (i3 structures): `CMapObj::s_classicShaders/s_unifiedShaders` (`MapObjDiffuse/Specular/Metal/Env/Opaque/EnvMetal`, `MapObjU*`), one or two textures, MOCV vertex colour as ambient.
* **Terrain**: `Terrain0..3` pixel shaders (1..4 layers, alpha-map blend, `Terrain2_pcf`...), vertex colour MCCV (flag 0x2 in MPHD) is multiplied (we use this for the colour map).
* **Sky / clouds**: `WildStarSkyModels.cpp` + `WildStarCloud.hlsl` (already a custom path).

## 2. What WildStar M3 / i3 / terrain materials need (from the analysis)

| # | WildStar feature | Where it lives | WoW today | Lost? |
|---|---|---|---|---|
| 1 | up to **4 colour layers** (+4 normal layers), blended by vertex weights / mask texture (`ModelPS` t0..t7, v5 weights) | M3 layer table 0x128 B, `FUN_14030e510` selects one of 16 958 ModelPS | only layer 0 is exported | layers 1..3 |
| 2 | **colour-texture alpha = tint mask**: `c*(1-m) + c*m*tint`, `m = a*scale+bias` | CB1 [4], [20] | alpha only used for cutout | dye / glow tint areas show untinted |
| 3 | **normal map** (two-channel xy, z rebuilt), tangent frame v7..v9 | t4..t7 | none (M2 has no normals map path) | all per-pixel relief |
| 4 | **gloss / specular** (normal alpha, scale+bias) and `DP gloss` | CB1 [5] | vertex-lit specular flag only | gloss |
| 5 | **glow / emissive** (`DP glow`, HDR `colour_mod`) | layer params | `SetEmissive` constant per batch exists; M3 glow not mapped | glow strength / HDR > 1 clamped |
| 6 | **opacity** animated (`DP opacity` key) | layer params | first key -> M2 alpha track (dbg41) | animated opacity beyond first key |
| 7 | **height / parallax** (`DP height`, `parallax`, v10) | layer params | none | parallax |
| 8 | **blend modes 0..6** + modes > 6 | material +0x14 | modes 0..6 mapped; >6 falls back to alpha | exotic modes |
| 9 | second UV set (v3/v4 zw), UV animation | ModelVS TEXCOORD1 | `Diffuse_T2` exists but converter uses UV0 only | UV1 |
| 10 | vertex colour streams COLOR0..2 (tint, AO-like multiplier, 127 = neutral) | M3 / FEDS vertex | M2 has one colour stream, i3->WMO MOCV not written | vertex colour |
| 11 | **deferred lighting** (G-buffer MRT output, point/spot lights in a light pass, shadow t12..t14) | engine | WoW forward, max ~4 lights per object (`lightCount`) | lighting model differs fundamentally |
| 12 | terrain `LandPS` (1 537 perms): layer colour t3, normal t7, weights t8, signed offset t9, **colour map t10** | .area | Terrain0..3 + MCCV (colour map approximated) | per-layer normals, offset map, exact blend |
| 13 | water, fog, sky, tone mapping / HDR / bloom | post | WoW fog + day/night; no HDR | HDR range, bloom |

## 3. Extension points in the WoW client (ordered by value / effort)

1. **New M2 effect family "WildStarModel"** (highest value, medium effort).
   * `CM2Shared::GetEffect(M2Batch*)`: the branch `batch->m_shader & 0x8000` already supports special effects (0x8001..3 hard coded). Add ids 0x8010+ that map to new
     `Shaders\Vertex\WildStar*.hlsl` / `Shaders\Pixel\WildStar*.hlsl` and register them with `InitEffect`. The converter then writes shader = 0x8010 + variant.
   * Variant key analogous to `ComputeElementShaders`: {has tint mask, has normal map, has glow, 2nd UV, 2/3/4 layers}. Keep it small (<= 32 variants) instead of 16 958.
   * `CM2SceneRender::SetupTextures` (line ~80-130): bind up to 4 textures per batch (today 2 stages); texture combos in M2 (`bo+0x10`) are per batch -> use the M2 `texture count`
     > 2 only through the new effect (the stock path ignores extra units), or put layers in the texture-combo lookup (consecutive entries) and read them in the effect.
   * Per-batch constants (tint colour, gloss, glow, colour_mod, alpha scale/bias): there is no slot. Options: (a) reuse `SetDiffuse`/`SetEmissive` (2 colours) +
     `SetAlphaRef` for scalars; (b) add `CShaderEffect::SetMaterialParams(float[4*N])` writing a new pixel constant register range, filled in `CM2SceneRender` from a side table keyed by
     (model, batch) that the M3 reader publishes (`M3Reader` already holds the layer data). (b) is the clean solution.
   * Tangent frame: `M2Vertex` has no tangent. Either compute tangents in the pixel shader from `ddx/ddy` (no format change, SM3 needs `ps_3_0`), or add a second vertex stream in
     `CM2Model` upload. Derivative-based is recommended first.
2. **Lighting model**: shader code in the new pixel shader can approximate the deferred result in forward: diffuse*lights + gloss specular + glow. Needs the light list that
   `CShaderEffect::SetLocalLighting` already uploads; no engine change besides using more of it. A real deferred path is out of scope.
3. **Terrain**: add `Terrain*_WS` pixel shaders for `CMap` (Map.cpp:684-736 creation, `MapRenderChunk` binding) that sample a per-chunk offset/normal texture;
   needs one more sampler per chunk and a per-chunk texture upload path (`CMapChunk` -> `GxTex`). Medium/high effort. Cheap interim: keep MCCV colour map (done).
4. **WMO / i3**: write MOCV from the FEDS colour stream (builder change only), use `MapObjU*` shaders for 2 layers; tint mask (item 2) needs a new `MapObj*WS` effect
   (same mechanism as 1). Normal maps again need a new effect.
5. **Blend modes > 6, UV animation, parallax**: add to the new effect; no engine change.
6. **HDR / bloom**: WoW 3.3.5a has no HDR target (`GxFormat` RGBA8). Clamp-only unless a post pass is added in `CWorldSceneRender` (not recommended).

## 4. What cannot be reproduced without a renderer change (information lost in WoW)

* HDR values > 1 (`colour_mod`, glow), bloom, deferred light accumulation, soft shadows of the WildStar pipeline.
* 16 958 ModelPS permutations beyond the feature set chosen in 3.1 (per-permutation exact math is not decoded; the key is computed in a function not yet found - see `i3_shader_notes.md` "Open").
* Layer weights from vertex streams where the stream meaning is unknown (v5) - the exact mapping of COLOR0..2 is inferred only.

## 5. Open analysis items (needed before implementing 3.1 exactly)

1. Decode the permutation key (`FUN_1402956f0` callers `FUN_140295c40/140296a00/1402a95e0/1402aa3e0`) -> list of which feature bits exist.
2. Dump CB1 layout for the most common ~20 ModelPS permutations with `tools/analysis/dxbc_dis.py` and map each register to a layer parameter (gloss, glow, opacity, tint colour).
3. Verify tint source for characters (customisation colours) - hair / skin tint likely feeds CB1 [20..23] through the instance, not the material.
4. Terrain: map LandPS t9 (offset) semantics (probably a height/blend bias) against the RGB565 data we already decode.

## 6. Recommended order

1. M3 export of tint mask + glow into the existing `Diffuse_T1` path (cheap, uses `SetEmissive`): shows most visible difference on characters.
2. New effect `WildStarModel` with per-batch constants and derivative tangents (3.1) -> normal map, gloss, tint, 2nd UV.
3. Layers 2..4 + blend weights.
4. Terrain shader and WMO shaders.

## 7. Implemented (dbg83) - WildStarModel pixel shader

* **Stock reconnaissance** (extracted `Shaders\{Vertex,Pixel}\*_3_0\*.bls` with `tools/mpq_extract.py`, container `GXSH`: magic, version 0x10003, permutation count, per permutation `u32,u32,u16,u16,size,code`):
  the lit `Diffuse_T1` vertex shader permutations output `o1` colour (per-vertex lit), `o2` uv, `o3` world position, `o4` world normal, `o5` shadow coords, fog; pixel constants: `c2` = fog colour (+ alpha ref in w).
  Sun direction / colour / ambient are in `CShaderEffect::s_sunDir/s_sunDiffuse/s_sunAmbient`, camera position = `CM2Scene::m_viewInv.d0..d2`.
* **Converter** (`Model3/M3ToM2.cpp`, cache version 8): meshes whose material has a real normal map (not Blank/Flat), gloss >= 1/14 or glow >= 1/17.5 get M2 shader id `0x8800 | gloss(3 bit, /7) | glow(3 bit, *0.8/7) << 3 | 0x40 (normal map)`;
  texture combos are now two per mesh (colour, normal or white); batch texture count 2 when a normal map is present. `M3Reader` reads gloss (DP 0x30) and glow (DP 0x48).
* **Client** (`Engine/Source/Model2/WildStarModelShader.{h,cpp}`, `Shaders/WildStarModel.hlsl`, `tools/build_ws_model_shader.py` -> `WildStarModelBytecode.h`):
  `CM2Shared::GetEffect` maps marked batches to the stock `Diffuse_T1 + Combiners_Mod` effect; `CM2SceneRender::DrawBatch` / `DrawBatchDoodad` call `WildStarModelShader::Bind` after `SetShaders`, which swaps the pixel shader
  (6 ps_3_0 variants: vertex normal available / normal map / alpha test) and sets `c16..c20` (sun dir, sun diffuse, ambient, camera + gloss, glow). Shadowed passes (shadow value != 0) keep the stock shader.
  Shader: derivative tangent frame, normal map (x = alpha, y = green), relative sun-term correction of the per-vertex lit colour, sun specular from gloss, glow = unlit texture colour added, stock fog / alpha rules.
* **Switches / tuning**: `WoWOverride\ws_normal_flip.txt` containing `1` flips the green channel of the normal map (convention unverified in game). If a pixel shader variant is invalid the log gets `[ModelShader] ...` and the stock shaders are used.
* **Not done**: tint mask (no tint data in M3 materials, see section 5.3), layers 2..4, second UV set, parallax, terrain / WMO shaders; shadowed passes; D3D11 path (shaders are ps_3_0 only).
* **Unverified**: no in-game check yet (normal-map orientation, strength of the sun-term correction, specular intensity are first estimates).

## 8. dbg87 - findings and layered materials

* **Stock vertex shaders**: permutations 0..29 of `Diffuse_T1` / `Diffuse_T1_T2` write no position / normal; the shadow groups 30..89 do (view space). WildStar batches therefore use `vertexPermute + 30`, lighting (ambient + sun * N.L) is computed in the pixel shader, specular uses `-viewPos`.
* **Shadow pass**: the stock shadow pixel shaders (`Combiners_Mod` perms 1..3, 5..7) sample 1..4 shadow cascades on s4..s7 (point / PCF variants). They are NOT ported: WildStar batches keep the normal map / layers in shadowed passes but do not receive shadow-map darkening
  (`shadowLevel 0` in the current Config.wtf, so no shadow pass occurs at all). A port would need the cascade code of those 6 shaders.
* **Layers**: 30 % of the 50 320 materials have 2..4 layers. The per-vertex blend weights are the M3 vertex colour 1 (f4b, 4 x u8, bimodal 0 / 255 on the checked prop; channel k = layer slot k, assumption, not verified against ModelPS).
  The converter picks all four present layers, normalises their weights and stores three 8-bit weights packed in M2 uv1 (w0 = 1 - w1 - w2 - w3). Shader id bit `0x80`. Texture combos: 8 per mesh; colours 0..3 on units 0..3 and the normal maps on units 8..11
  (`CM2SceneRender::SetupWildStarLayerTextures`; units 4..7 stay free for the stock shadow maps). Effect `Diffuse_T1_T2 + Combiners_Mod_Mod`, pixel shader `WS_LAYERED` (variants 9, 11, 13, 15). Layer-3 alpha coverage uses shader id bit `0x1000` because `0x0800` is the WildStar marker.
* **Limits**: vertex colour 0 (x2 multiplier / AO) is not applied; a layer's own gloss / glow are not used (layer 0 values for the whole batch).

## 9. dbg90 - terrain normal maps (bytecode patch of the stock shaders)

* Correction: the client runs with shadow mode 3 (`CShadowCache::GetShadowValue() == 3` in the log) although `shadowLevel` is 0, so the terrain uses the shadow shaders (`Terrain3`, four cascades on s5..s8). Earlier statements that no shadow pass occurs were wrong.
  The model shader (section 8) is also active in shadowed passes but does not receive shadow-map darkening there.
* Approach: instead of a replacement shader the stock terrain shaders are patched at the token level (`WoW/Source/WorldClient/WildStarTerrainShader.cpp`), so shadows, per layer lighting flags and all layer counts keep working:
  * vertex shaders (all 128 permutations): one extra output TEXCOORD7 = view space normal (same three instructions the stock lighting uses),
  * pixel shaders (every non-cube permutation, mode 1 / 2 / 3, with and without PCF): normal samplers s9..s12 (layer k reuses the texture coordinate of its colour sampler), blend weights re-sampled from the weight map,
    blended tangent space normal, tangent frame from the planar uv mapping (u runs against model y, v against model x, view space axes = first two rows of the world view matrix), relative sun term applied to the vertex colour (`v0` is replaced by `r30` after the inserted block).
  Offline check (`scratch_mpq/patchps.py`, `patchvs.py`): 128 / 128 vertex shaders and all 44 patchable `Terrain3` permutations disassemble; cube permutations (a4) and single sampler permutations are skipped.
* Files: normal map = colour map name with `_Color` -> `_Normal`; missing normal maps use a flat solid texture. Tuning: `WoWOverride\ws_normal_flip.txt` (content bit 0 flips green, bit 1 flips red, default 1 = green), `WoWOverride\ws_terrain_strength.txt` (float, default 1).
* Log: `[TerrainShader]` lines in `WoWClient\WildStar.log`.
* Not done: LandPS offset map (t9), specular, D3D11.

## 10. dbg92 - models over 65535 indices

* Cause of missing geometry on large models: the M2 skin addresses indices with 16 bit start / count, the converter silently dropped every mesh that did not fit. Count over all `Art\**\*.m3` (excluding `(flags & 0x0A) == 0x0A` meshes):
  Creature 86 / 268 models above 65535 indices (11 also above 65535 vertices), Prop 121 / 7388 (23), Structure 28 / 313 (6), Mount 18 / 360 (3), FX 17 / 4305, Cinematics 334 / 1127 (113), Item 6 / 17918.
  Example `Creature\WorldDestroyerBot\WorldDestroyerBot.m3`: 201 492 indices, 3 of 6 meshes were visible before.
* Fix: meshes with more than 65532 indices are split into several sections (same vertex range / material); the section start is 32 bit: low half in `indexStart`, high half in the upper 16 bits of the skin section id (`M2SkinSection::GetIndexStart / SetIndexStart / GetSkinSectionId` in `Model2/M2Data.h`, used by CM2SceneRender, M2Model (batches, optimised geometry, hit test), M2Scene, M2Shared). The optimised geometry merge refuses to merge sections above 65535 indices. Cache version 10.
* Still dropped: models with more than 65535 **vertices** (the skin vertex table is 16 bit; 11 creatures, 23 props, ...), and mesh groups that are alternative variants (the converter keeps the lowest group of each family, e.g. Dagun shows groups 0 and 1 of 6).

## 11. dbg94 - correction of the layer weight channels

Checked on `Prop\Natural\Tree\Large_umberla_Pine\PRP_Tree_LargeUmberla_LargePine_000.m3` (two layers: trunk 0, canopy 1; the canopy mesh has colour 1 = (0, 255, 0, 0), the trunk mesh mixes (0, 255, 0, 0) and (0, 0, 255, 0)): vertex colour 1 is a D3DCOLOR, i.e. BGRA in memory, so the shader sees (r, g, b, a) = layer weights 0, 1, 2, 3.
Memory byte -> layer: byte 2 -> layer 0, byte 1 -> layer 1, byte 0 -> layer 2, byte 3 -> layer 3. Section 8 used byte = layer slot, which swapped the layers of every two layer material (trunk and canopy). Fixed in `M3ToM2.cpp` (`kChannelOfLayer`), cache version 12.

## 12. dbg95 - where the cutout coverage comes from (layer word +0x08)

* Original alpha test (ModelPS permutations 14 / 42 of `ModelPS.ps_4_0.sho`, depth / alpha pass): per layer `coverage = dot(cb1[4 + k], (colour.a, normal.b, normal.r, 1))` (the normal texture is sampled as `t4.yzxw`, channels z and x are used), layers are mixed with the vertex weights `v5.x / .y / .z / .w` = layers 0..3 (this confirms the BGRA mapping of section 11; absent layers contribute the constant `cb1[5].w`), the pixel is discarded when `coverage * v2.w - cb2[1].y < 0`.
  The constants `cb1[4..7]` therefore decide per layer whether the colour alpha is coverage, a mask in the normal map is coverage, or coverage is 1. The CPU function that fills them was not found.
* Statistics over 6000 models (`scratch_mpq/modes.py`): the layer word at +0x08 is 0 for almost all non-cutout layers of bodies, armour, metal and bark and for the trunk layer of the Umbrella pine, and 1 for cutout foliage (canopy 160 of 228 leafy cutout layers). So 0 = "colour alpha is not coverage (tint / dye mask only)", >= 1 = colour alpha is coverage. The meaning of 2..6 is not decoded (treated as coverage); the other four words are still open.
* Before dbg95 every cutout / blended batch cut with the colour alpha, so layers whose alpha is only a mask came out torn (bird body, tree trunk). Now `M3ToM2.cpp` writes per layer coverage bits into the M2 shader id (0x100 / 0x200 / 0x400 = layer 0 / 1 / 2) and also routes cutout or alpha blended batches with a "no coverage" layer through the WildStar pixel shader (`coverage` constants c21 in `WildStarModel.hlsl`: alpha = lerp(1, tex.a, flag)). Cache version 13.
* Normal-map channel coverage (e.g. layers whose cutout shape is stored in the normal map) is not implemented; the mapping of the words 2..6 is the missing piece.
