# WildStar .m3 – the rarely used header blocks (build 16042)

Reader: `tools/blender_addon/wildstar_m3/extras.py` (`read_extras`), validation: `tools/validate_blocks.py` (structure, bounds on 34,712 models),
`tools/validate_semantics.py` (cross-references, `docs/m3_blocks_semantics.json`), `tools/analysis/coverage.py` (byte coverage, `docs/m3_coverage.json`).
Sources: engine loader `FUN_14030cac0` and its slot handlers (`docs/ghidra_matload*.c`, `docs/ghidra_rest*.c`), the model-instance constructor
`FUN_1402f39e0` (`docs/ghidra_users2.c`), game tables, statistics over all models.

Confidence: **[V]** structure validated on every model and meaning proven by cross references, **[S]** structure validated, meaning from strong
circumstantial evidence, **[O]** structure validated, meaning open.
All offsets nested inside an element are relative to `align16(end of the parent array)` (the engine uses the aligned end; the unaligned variant fails on 25 % of the 0x2B8 blocks).
DP value sizes come from the loader helpers: S1 = 1 byte, S2 = 2 (half float / u16), S4 = 4, S6 = 6, S8 = 8.

## Result of the structural coverage
`tools/analysis/coverage.py` walks every .m3 with the structure model (`tools/m3walk.py`): **header 0.84 % + arrays/value blobs 99.04 % of 6.12 GB; unexplained gaps 0.0012 %**
(the remainder is 16-byte alignment padding). Every array and every nested array of every one of the 34,712 .m3 files is now accounted for.
(34,733 files were extracted; 21 do not carry the `LDOM` signature.)

## Corrections to earlier notes
* `0x490` is **not** a byte array / geometry cache. It is a 0x40-byte element with four arrays: the **collision kd-tree** (below).
* `0x2C8` holds **SoundEvent ids** (98.6 % of the ids exist in `SoundEvent.csv`), not VisualEffect ids.
* `0x328` elements are **cameras** (ModelCamera enum), `0x318` elements are **lights**.
* `0x0F0` has 0xB8-byte elements (7 DPs), `0x318` has 16 DPs (3 x S2, 2 x S4 colors, 11 x S2), `0x560` has 5 DPs.

## Cameras – 0x328 (0x38 B) + lookup 0x338 [V]
| Off | Type | Meaning |
|---|---|---|
| 0x00 | u16 | **ModelCamera id** (`ModelCamera.csv`: 1 Portrait, 2 Target, 3 Quest, 4 Datachron, 5 Paperdoll ...) |
| 0x02 | u16 | bone the camera is attached to (100 % < bone count) |
| 0x08 | f32 | aspect ratio (1.0 / 1.333 / 1.777) |
| 0x10 | DP S2 | vertical **field of view** as half float in radians (0.35 .. 1.2; all 7,937 cameras in 0..3.2) |
| 0x28 | f32 | 0.1 or 0.933 (open) |
| 0x2C | f32 | near clip (0.01 in 99 %) |
| 0x30 | f32 | far clip (3276.8 or 100000) |

`0x338` (u16 array, 2–61 entries) is indexed by **ModelCamera id** and returns the camera index (0xFFFF = none): `camera[lookup[id]].id == id` holds for 7,868 / 7,868 entries.
WoW M2 equivalent: `M2Camera` (type, fov, far, near; position/target tracks). WildStar has no target track – the camera bone drives position and orientation.

## Lights – 0x318 (0x190 B) [S]
Header: `u16 type` (0 point 1,923 · 1 spot 91 · 2 rect 35 · 3 directional-circle 47 · 4 directional-rect 40, confirmed by the model names `LIT_SpotLight_*`, `LIT_Rec_*`, `LIT_Dir_Cir_*`, `LIT_Dir_Rec_*`),
`u16 bone` (98–100 % < bones), `u16 x3` (default 0, 0xFFFF…), `+0x06/+0x08` u16 texture ids (cookie/gobo, 100 % valid when set).
DPs (key u32 ms, value): `+0x58` S4 color0 (RGBA8), `+0x70` S4 **color** (RGBA8, alpha 0; e.g. `4fb2e2`), `+0x88` S2 **intensity** (animated flicker, e.g. 3.127),
`+0xA0/+0xB8` S2 size/angle A/B (spot, rect, directional), `+0xD0/+0xE8` S2 size C/D (rect types), `+0x118` S2 (directional: 80), `+0x130` S2 **attenuation start**, `+0x148` S2 **attenuation end**
(point light: 6.4 / 25.6; `LIT_DIR_Cir_ExtremeLong_Narrow`: 100 / 600), `+0x10/+0x28/+0x40/+0x100/+0x160/+0x178` S2 (rarely used).
The instance constructor registers each light with the scene manager (`param_1[2]+0x1E8`, runtime object 0x1B0 bytes).

## Sound – 0x2C8, 0x2B8 [V/S]
* `0x2C8` (8 B): `u16 0xFFFF, u16 0, u32 SoundEvent id` (98.6 % of 4,142 distinct ids are rows of `SoundEvent.csv`: `Play_Human_Foley_Body_Falls`, `Play_Humanoid_2H_2HL_Sheath` …).
* `0x2B8` (0x28 B) **sound emitter**: `u32 bone` (100 % valid), AP @0x08 (records 0x20 B with an S2 DP at +8; never populated in 16042),
  AP @0x18 of 0x20-byte records `{u16 startEvent, u16 stopEvent, u32 0, DP S1 on/off @+8}`; both event indices are **indices into the 0x2C8 list** (100 % of 668 records).
  Characters have two emitters (the foot bones), props one. The instance constructor creates one audio object per element through the global audio manager.
* `0x2E8` (8 B) and `0x2D8` (2 B) are empty in all models.

## Attachments – 0x280 + DP 0x290 [S]
Element 8 B: `u16 bone` (100 %), `u16 0`, `u32 ModelAttachment id` (`ModelAttachment.csv`: 1 NAME, 2 HAND_LF, 3 HAND_RT, 4 BACK, 5 SHEATH_LF …); DP `0x290` (key u32 ms, value u16) is the attachment visibility/state timeline.

## Collision kd-tree – 0x490 (0x40 B) [V]
One element (almost always 1) with four arrays: **header records** (16 B), **vertices** (float3, 12 B), **indices** (u32, triangle list) and **kd-tree nodes** (20 B).
Header record: `{u32 firstNode, u32 firstIndex, u32 indexCount, u16 a (0xFFFF none), u16 b}`; records are contiguous (`firstIndex` = running sum; 25,083 / 25,083 elements),
one kd-tree per record starting at `firstNode`. Node: `{f32 split, u32 indexStart, u32 indexCount, u32 left, u32 right}` – `indexStart/Count` is the straddling-triangle range of the
node (child ranges follow it), children are node indices relative to the global node array (0 = none). Verified: all indices < vertex count, index count % 3 == 0, children < node count,
ranges inside the index array (25,083 / 25,083). Presumably used for picking / collision queries. 10,695 models have an empty element.
WoW M2 equivalent: `collision_triangles / collision_vertices / collision_normals / collision_bounding_box`.

## Hull mesh – 0x510 / 0x520 / 0x530 [S]
`0x510` (16 B): float4 vertices (xyz + a 0..1 value, byte/255), `0x520` / `0x530` u32 index lists (both < vertex count in 192 / 160 models); present in 192 cinematic/“cave” models
(Datascape, NexusIntro, character bios); 26,665 vertices / 132,375 + 7,320 indices in total (39 … several thousand vertices per model). Proxy/occluder-like geometry; purpose open.

## Animated-prop states – 0x4A0 [V]
u32 array, each entry = `{u16 ModelSequence id, u16 variant}` (e.g. 1118 `AP_State0_Idle`, 1120 `AP_State1_Idle`, 1109 `AP_State0_State1`; 100 % of 1,755 ids exist in `ModelSequence`,
variants 1–4). The state machine of animated props (cinematics, doors, devices); only 389 of the ids are clips of the same file because the state animations live in sibling files.

## Face customization – 0x598 (0x4C B) + 0x5A8 [V]
Element: `u32 bone` (a `CUST_*` face bone: CUST_Nose, CUST_EyeSocket_Rt, CUST_EyeBrow_Rt, CUST_EyeSquint_Rt …; 100 %), then 6 float3: **translation min / max** (± 0.005 m), **rotation min / max** (radians, ± 0.09 … 0.26),
**scale min / max** (0.75 … 1.25). These are the limits of the character-creation face sliders. `0x5A8` (u16, 32–37 entries) maps slider index -> range index in `0x598` (0xFFFF none; max == count-1 in all 130 models).
All 130 models are `Art/Character/*/Heads/Face_*.m3`.

## Header scalars [V/S]
| Off | Meaning |
|---|---|
| 0x008 | u32 flag (1 in all but one model), 0x00C = 0 |
| 0x348, 0x368 | u16 bone indices (0xFFFF none; auxiliary bones with ModelBone id 0xFFFF, 877 / 1,534 models) |
| 0x580 | u16 **head bone** (`BIND_Head` in 145 models, 0xFFFF otherwise) |
| 0x388 / 0x38C | two f32 (often equal; open) |
| 0x390, 0x3D0, 0x410, 0x450, 0x4B0 | five **bounding volumes**, 0x40 B each: AABB min f32x3 (+0x00), AABB max (+0x10), center (+0x20, = midpoint in 100 %), radius (+0x30, = half diagonal in 100 %). 0x390/0x3D0/0x410/0x450 contain the vertex AABB in 61–65 % (volume ratio median 1.0); 0x4B0 is empty in 24 % |
| 0x4F0 / 0x500 | AABB min / max (no center/radius; open, smaller than the vertex box in most models) |
| 0x5D8 … 0x628 | five **random ranges** `[lo.x lo.y hi.x hi.y]` (0x10 each) – at instance creation the engine interpolates every pair with a random number into the instance (typical: 1/1, 8/10, 0.02/0.05, 0.75/1.0, 0.8/1.2) |

## Structure known, meaning open [O]
* `0x308` (0x50 B, 147 models, mostly FX): `u16 bone`, `u16 word`, three DPs (S2, @0x08/@0x20/@0x38) whose values are flag-tagged 16-bit numbers (0x0049, 0x804F, 0x4056 …).
* `0x540` (0x68 B, 10 models) + `0x550` (u16 [1] = 0, 24 mount models): `u32 (id<<16)`, DPs S2 @0x08 (20 keys), S4 @0x20, S6 @0x38, S8-value DP @0x50 (all empty in the data).
* `0x560` (0xA0 B, 1,273 models: FX, items, props, cinematics): 12 x u16 header (bone, texture indices – 100 % valid – and material indices), DP S2 @0x28 (half 0..1 **alpha/fade** envelope), DP @0x40 (u32 key, u16 value = 1), three S4 DPs (empty in 908 of 909 elements); the runtime object (0x88 B) starts with a neutral tint `0xFF7F7F7F` (the VS multiplies colors by 2, so 0x7F ≈ 1.0) and a scalar 0x100 = 1.0: most likely an animated per-part **color/transparency track** (M2 `colors` / `texture_weights` equivalent). The small u16 values (0..7) are enum/index fields whose targets are not resolved.
* `0x570` (0x20 B, 121 models): `u16 pair`, `u32 0..3`, DP S1 @0x08 (values 0,1,2,3,4,7,8,12).
* `0x588` (0x20 B, 569 models, up to 83 per character): `u32 id`, DP S2 @0x08 (half 0..1 weights, thousands of keys on characters – frame-by-frame animated weights, probably blend-shape/morph weights).
* `0x5C0` (DP, S1): global u8 track (668 models), `0x350 / 0x370` (DP, S4): global 32-bit tracks, `0x020/0x038/0x050/0x068/0x090/0x0A8/0x0C0/0x0D8/0x130/0x148` S1 tracks, `0x100/0x118/0x160` S4 tracks.

## Mapping to WoW 3.3.5a M2
| WildStar | M2 chunk |
|---|---|
| bones 0x180 + tracks | `M2CompBone` (+ `M2Track`) |
| geometry 0x250 | vertices / skin profiles |
| clips 0x010 | `M2Sequence` (+ AnimationData.dbc ids) |
| cameras 0x328/0x338 | `M2Camera` (+ camera lookup table) |
| lights 0x318 | – (M2 of 3.3.5a has no lights; use DBC LightParams / spell visuals) |
| attachments 0x280 | `M2Attachment` + attachment lookup |
| sound 0x2C8 / animation events | `M2Event` (`SND`/`PLAY` events) |
| collision 0x490 | `collision_triangles/vertices/normals` |
| emitters 0x2F8 | `M2Particle` / `M2Ribbon` |
| face ranges 0x598 | no equivalent (CharacterFacialHairStyles/HD morph are DBC-driven) – lost |
| bounding volumes | `bounding_box`, `bounding_sphere_radius`, `collision_box` |
