# WildStar structure shaders (ModelPS) - notes for the i3 material support

State 2025-10-25. Source: `ClientData\Shaders\ModelPS.ps_4_0.sho` (container `STGT`, 16 958 DXBC pixel shader permutations, no reflection data, header = table of
`{size, offset}` pairs at 0x58), disassembled with `tools/analysis/dxbc_dis.py <sho> <index>`. The permutation index is a mixed radix key computed by the client from the material
features; that mapping is NOT decoded yet.

## What the permutations read
* Textures t0..t7 are the material textures: pairs (colour, normal) = t0/t1, t2/t3, t4/t5, t6/t7 (up to four layers); t8..t11 environment / lightmap type inputs, t12..t14 global
  (shadow / light buffers). Constant buffers: CB1 = material parameters (28 float4), CB2 = frame / fog / light constants, CB0 / CB3 only in some permutations.
* The **alpha channel of the colour texture is a mask**: `m = alpha * cb1[4].x + cb1[4].w` (per layer scale / bias); the colour is split into `c * (1 - m)` (normal diffuse) and
  `c * m * cb1[20].xyz` (tinted by a per layer colour = dye / colour variation / glow tint). The alpha of the normal texture (`t1.w`) goes through the same kind of scale / bias (cb1[5]),
  probably gloss / specular.
* The normal textures store the normal in two channels (the shader rebuilds z with `sqrt(1 - x^2 - y^2)`), i.e. BC5-like / xy normals.
* Vertex inputs v2 (tint multiplier), v5 (layer weights, `v5.w` for layer 3), v3/v4 (two UV sets, xy / zw), v7..v9 tangent frame, v10 parallax offset.

## What is known about the data feeding it
* The FEDI material records (0x128 bytes) carry the texture indices (u16 colour, u16 normal), the `kind` flags and ten sparse parameter slots (count, key array, value array); for the
  Imperium tower all slots are empty -> the tint / scale values are shader defaults or come from somewhere else (not found yet). The placement tint of the `.area` props of this
  tower is neutral (`ff7f7f7f`).
* The 4x4 / 1x1 placeholders (`Art\Dev\BLANK_Grey`, `Blank_Normal`) are referenced by 318 of 413 models; the client refuses textures smaller than 8x8 (`GxTexCreate`), which showed as
  plain green (`s_defaultColor`) - fixed by enlarging them to 8x8 in `LoadTexAsBlp`.

## What the WoW 3.3.5a WMO path can show (current builder)
| WildStar | WoW WMO | state |
|---|---|---|
| colour texture RGB | MOMT texture 1 | yes |
| colour texture alpha (tint / glow mask) | alpha only for decals (kind 5) | lost (mask not applied) |
| normal map, gloss | no equivalent in WMO shaders | lost |
| layers 2..4 (t2..t7) | MOMT texture 2 (two layer shaders) | not used |
| UV set 1, vertex colours, layer weights | MOTV / MOCV | UV1 and colours not written |
| tint colours / glow | MOMT sidn colour + flag 0x10 (self illumination) | not used (source of the tint unknown) |
| material variants (`Aurin_Autumn`) | - | set 0 only |

## Open
* permutation key -> features (find the client function that builds the key, search `ModelPS` loader / `STGT` in WildStar64.exe),
* the source of the CB1 values for structures (material slots / q record fields `+0x10 / +0x14` look like (end, start) ranges into a parameter table),
* meaning of FEDS submesh `kind` (0 collision only without material, 2, 4, 6, 7).

## Update (second pass)
* In the analysed permutation t0..t3 are **four colour layers** (their RGB is used as colour; alpha = mask with scale / bias from CB1), t4..t7 are the **four normal layers** in
  DXT5nm layout (x in alpha, y in green, z rebuilt); the layers are blended with weights derived from vertex data (`v5.xyz`, weight 4 = `v5.w`) and a mask texture.
  The FEDI pass / material layout of the structures uses one colour + one normal texture per material (submesh id = (material + 1) << 8 | pass), so only one layer is active per draw.
* STGT container: header u64 = {magic+version, blob count 0x423e, 0, 0xEA00, offset A, 1, offset C, 0xEA00, offset B}; A and B are two 59 904 entry u32 tables (A: 58 747 non zero keys, B: 17 distinct
  values) - a lookup structure, NOT the keys of the blobs in blob order (a bit / register correlation over 1200 blobs gave no signal). The client reads them in `FUN_1402956f0` (callers
  `FUN_140295c40`, `FUN_140296a00`, `FUN_1402a95e0`, `FUN_1402aa3e0`); the key computation is still to be found.
* Vertex stream of the model shaders (ModelVS signature): POSITION, COLOR0, COLOR1, COLOR2, TEXCOORD0, TEXCOORD1 (+ BLENDINDICES / BLENDWEIGHT for skinned models). For the 20 byte
  FEDS vertex this means COLOR0 = bytes 0..3 (packed, probably tangent), COLOR1 = bytes 4..7 (octahedral normal in bytes 5 / 6), TEXCOORD = 4 half floats, COLOR2 = bytes 16..19
  (byte 16 is 0 or 255, bytes 17 / 18 around 100..150, byte 19 = 255; probably the vertex colour / tint multiplier: 127 = neutral).
* FEDI material parameter slots: 4003 of 11 911 materials carry parameters, always one float per slot: slot 4 mostly 1.0, slot 3 mostly 1.0, slot 2 0 or 0.5, slots 8 / 9 = +/- 1/256 pairs
  (looks like UV / parallax scale and bias), slot 1 / 6 / 7 rare. There is no colour in the material, the tint colour (CB1[20..23]) must come from the instance (it is neutral for the
  placements checked: `ff7f7f7f`) or from game logic.
