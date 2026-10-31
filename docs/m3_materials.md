# WildStar .m3 – materials and shader parameters (build 16042)

Parser: `tools/blender_addon/wildstar_m3/m3.py` (`Model.material_info`), validation: `tools/validate_materials.py` (`docs/m3_material_validation.json`).
Sources: engine file loader `FUN_14030cac0` (= the .m3 loader: checks `LDOM`, version 100), the material loaders `FUN_14030f290 -> FUN_14030b010 -> FUN_14030a9d0`,
the shader permutation selector `FUN_14030e510`, statistics over 50,320 materials / 75,491 layers of all 34,733 models, and the game table `ReplaceableMaterialInfo`.

## Layout (header array 0x1F0)
**Material, 0x30 bytes**
| Off | Type | Meaning |
|---|---|---|
| 0x00 | u32 | 0 in 94 % (otherwise ids up to 172) [O] |
| 0x08 | u32 | material **type**: 0 normal (99 % of props/items), 1 special permutation path, 2 effect path (13 % of FX) [engine: `==2`, `==1` branches] |
| 0x0C | u32 | **flags**: bit 1 (value 2) = FX/effect flag (51 % of FX), bit 9 (0x200) read by the renderer; large values like 7328 / 24578 are FX presets |
| 0x10 | u32 | enum 0 / 5 / 6 / 3 / 4 (FX: 5 in 27 %, props/structures: 6 in ~41 %) [O] |
| 0x14 | u32 | **blend mode**: 0 opaque, 1 cutout (threshold 0.5), 2 alpha, 3 add, 4 alpha-add, 5 multiply, 6 multiply2x; 7 special/unresolved. Confirmed renderer `FUN_1403283c0`; see `m3_texture_fixes_dbg41.md` |
| 0x18, 0x1C | u32 | 0..64 render-state / variant ids (not indices into any model array) [O] |
| 0x20 | AP | **layers** (descriptions) – count (1..4) and offset |

**Layer ("description"), 0x128 bytes (not 0x140 – the NexusVault template is for a later build; validated: 0 invalid texture ids with 0x128, 88 with 0x140)**
| Off | Type | Meaning |
|---|---|---|
| 0x00 / 0x02 | u16 / u16 | texture index of the **color** (type 0) and **normal** (type 1) texture (100 % match the types in the textures array); 0xFFFF = none |
| 0x04..0x17 | 5 x u32 | layer mode enums 0..6 (+0x08: 0/1/5, +0x0C: 0/1/5, +0x10: 0/5/6, +0x14: 0/3/5). Character/terrain/items use 5 far more often [O] |
| 0x18, 0x30, 0x48, 0x60, 0x78, 0xA8, 0xC0, 0xD8, 0xF0 | DP, key u32 / value **float32** | animated scalar parameters (engine loader: nine 4-byte DPs) |
| 0x90 | DP | not touched by the loader (raw) |
| 0x108 | DP, value **3 x float32** | HDR color multiplier (values like 1.5,1.5,1.5 / 2,2,2 / 1,0,0) |
| 0x120 | u32 | layer **class**: 3 = standard (99.9 %); `!= 3` makes the permutation selector enable a special layer path |
| 0x124 | u32 | **material type id** 0..22 (matches the 22 rows of `MaterialType`; terrain = 7, structures/props mostly 2, FX 7) |
DP value arrays are relative to `align16(end of the descriptions array)` as everywhere else; 99 % are constants (count 1).

### Parameter names (match the field order of `ReplaceableMaterialInfo`: shader, gloss, glow, opacity, height, ... colorMod)
| DP offset | name | evidence |
|---|---|---|
| 0x18 | shader_value | 0 in 94 % (RM default 0) |
| 0x30 | gloss | 0 .. 1 (0.5, 0.25, 0.8, 0.65, 1.0) |
| 0x48 | glow | 0 .. 0.8, 0 in 73 % |
| 0x60 | opacity | 1.0 in 77 % (RM default 1) |
| 0x78 | height | 1.0 in 84 % (RM default 1) |
| 0xA8 | height_scale | 0.5 .. 16 (low confidence) |
| 0xC0 | height_offset | 1.0 / negative (low confidence) |
| 0xD8 | parallax_scale | 0.008 .. 0.05 |
| 0xF0 | parallax_offset | **= -parallax_scale / 2 exactly** (0.01 -> -0.005, 0.02 -> -0.01 ...) |
| 0x108 | color_mod (xyz) | `ReplaceableMaterialInfo.colorModX/Y/Z` |
The first three groups (gloss/glow/opacity) and color_mod are supported by default values and ranges; height/parallax by the exact -1/2 relation.

## Shader permutation (`FUN_14030e510`)
The renderer picks one of the precompiled `ModelPS/ModelVS` variants (`Shaders/ModelPS.ps_4_0.sho` has 16,958 blobs, ModelVS 3,396) from:
* per draw: material index, 4 texture slot types (`== 2` flags) and 4 texture ids (`!= -1`),
* per layer 0..3: *present* = (texture id != -1) or (layer class != 3),
* material type `+0x08 == 1` -> index = base + pass * 4, otherwise a bit-field built from the four *present* flags, the four slot-type flags and the pass kind
  (`iVar7`: 0, 1 or 2 from the pass value 7 / 8 / 9).
So an m3 material has up to **4 layers**; every layer contributes bits to the variant and its DPs feed the pixel-shader constants.

## Blender importer
Materials get the layer data as custom properties (`ws_material_header`, `ws_layerN_*`, parameters); gloss sets the Principled roughness
(`1 - gloss`). Color texture of layer 0 is assigned; normal maps and layer blending are not wired.

## Still open
`material.+0x00/+0x10/+0x18/+0x1C`, the five layer mode words (+0x04..+0x17), the raw DP at +0x90, exact meaning of height_scale/height_offset, and the
mapping from the permutation index to the individual `.sho` variants (the bit order above is taken from the code; the .sho entries are not named).
