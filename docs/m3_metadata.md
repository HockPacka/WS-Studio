# What a WildStar .m3 carries – and the game tables that complete it (customization / texture data)

Build 16042. Every statement is tagged **[verified]** (checked against data/tables, with numbers), **[likely]** (strong
correlation) or **[open]**. Counts come from all 34,733 models (`docs/m3_header_survey.json`, `tools/survey_m3_header.py`).

## 1. Inside the .m3 (header 0x630 bytes, all offsets relative to 0x630)

| Header slot | Present in | What it is |
|---|---|---|
| AP 0x010 (0x70 B records) | 100 % | **animation clip table**: animation id, variant, blend in/out, start/end ms, speed, bounds [verified] |
| AP 0x180 (0x160 B records) | 100 % (510,522 bones) | **bones**: ModelBone id (u16 @0, 0xFFFF = none), parent (i16 @4), depth (u16 @6), hash (u32 @8, not CRC32 of the name), 8 animation tracks, bind world matrix, inverse bind matrix, pivot [verified] |
| AP 0x1B0 (u16) | 92 % | **bone map**: vertex bone index -> bone index (max index < map size in every sampled model) [verified] |
| AP 0x1C0 (0x20 B) | 98 % | **textures**: u16 **model texture id** (@0, 0xFFFF = none), u8 type (@2: 0 color, 1 normal, 2 skin-FX), u8 (@3), u32 (@4), float (@8), UTF-16 path (AP @0x10) [verified] |
| AP 0x1F0 (0x30 B) -> descriptions (0x140 B) | 92 % | **materials**: each with up to 4 descriptions; description holds 2 texture indices (@0/@2) + shader/blend words (@0x10..) [partly] |
| AP 0x250 (0xC8 B) | 100 % (1 geometry) | **geometry**: vertex format (11 field types), vertex buffer, index buffer (u16), **meshes** (0x70 B), per-mesh vertex ranges [verified] |
| mesh.group (u8 @0x1E) | | **ModelMesh id** (Hair0..9, Face0..1, Guild_Holomark_*; 255/0 = always shown) = alternative variants toggled by the tables below [verified] |
| mesh.cluster (u8 @0x22) | | **ModelCluster id** = body part (Ankle_L, Chest_Upper, Hand_R ...) used for armor/skin region replacement [verified] |
| mesh.material (u16 @0x16) | | index into the material array [verified] |
| AP 0x190 / 0x1A0 (u16) | 53 % / 60 % | per-bone index lookup tables (count ~ bone count) [likely] |
| AP 0x1D0 / 0x210 / 0x270 / 0x338 (i16, -1 = none) | 54 % / 9 % / 17 % / 7 % | bone-index lists (every value < bone count) [verified range, meaning open] |
| AP 0x200 (u16 id, u16 flag) | 9 % | list of **ModelMesh ids** (100 % are valid ModelMesh ids) – mesh group set [verified ids] |
| AP 0x260 (u16 id, u16 index) | 17 % | **ModelMesh id** (97 % valid) + index [verified ids, index meaning open] |
| AP 0x280 (u16 kind, u16 **ModelAttachment id**, u32 param) | 4 % | event/effect entries; second field is a ModelAttachment id in 95 % [verified] |
| DP 0x290 (keys ms, u16 index into AP 0x280) | 2.3 % | **timeline of events** (effects/sounds/attachments fired at a time) [verified from client code] |
| AP 0x2C8 (u16 -1, u16 0, u32 **VisualEffect id**) | 2.7 % | visual effects used by the model: 81 % of ids are in `VisualEffect`, 68 % in `Spell4Visual` [verified] |
| AP 0x328 (0x38 B) + AP 0x338 | 6.9 % | **cameras** (files named *__camera.m3, floats 1.0/0.1/0.01) [likely] |
| AP 0x080 / DP 0x090-0x0D8, AP 0x0F0 / DP 0x100-0x160, DP 0x020-0x068 | 3.7 % / 100 % / 1 % | per-model track groups with the same record prefix as clips (`id, flags, 100, 150, start, end`) [likely, open] |
| AP 0x2F8 (0xA0 B) | 14.5 % (ships, props) | emitter-like records (particles/ribbons/lights) [open] |
| AP 0x1E0 (0x98 B) | 7.5 % | 6 tracks (3 half3, 3 quat..) like a bone but no matrices: UV/color animation nodes [likely] |
| AP 0x510 / 0x520 / 0x530 | 0.6 % / 0.6 % / 0.5 % | up to 12,591 elements (Datascape terrain cube) – soft-body / dynamic mesh data [open] |
| AP 0x588 / 0x598 / 0x5A8 | 1.6 % / 0.4 % / 0.4 % | in Human_F, Chua_M_Faces, CostumeModel – **customization data** (sliders / morph) [likely, open] |
| AP 0x2B8, 0x308, 0x318, 0x490, 0x4A0, 0x540, 0x550, 0x560, 0x570, DP 0x350, 0x370, 0x5C0 | 0.1-5 % | rare blocks (see survey json) [open] |
| AP 0x220, 0x230, 0x240, 0x2A8, 0x2D8, 0x2E8 | **0 %** | never used in build 16042 |

Vertex data: position as 3 x float or 3 x i16 / 1024; bone indices 4 x u8, weights 4 x u8 (sum 255); UV as half floats
(1 or 2 sets); 3 more per-vertex fields (normals/tangents packed, 2 B each) and 2 x 4 B (colors) are packed but not decoded yet [open].

## 2. "Customization" – where it lives (game tables, `extracted/tables_csv/`)

An .m3 is only the *base model*. Which meshes, textures, colors and slider settings apply is decided by tables:

| Table | Rows | Role | Link to the .m3 |
|---|---:|---|---|
| `Creature2ModelInfo` / `Creature2DisplayInfo` | 4,328 / 13,868 | NPC/character **display**: `assetPath` (.m3), up to 6 texture overrides `assetTexture00..05` with `modelTextureId00..05`, `colorShiftTexturePath` + mask, `materialDataId*` (skin/weapon/armor color), `modelMeshId00..15`, `itemDisplayId00..19`, scale, speeds | `modelTextureIdNN` = m3 texture u16 @0 (63/65 found; slot 00 hits type 0 color, slot 01 type 1 normal) [verified]; `modelMeshIdNN` = mesh.group (100 % valid ModelMesh ids) [verified] |
| `ItemDisplay` | 8,737 | **equipment**: `objectModel`, `skinnedModel(L)`, `attachedModel` + `attachedTexture`, `modelTextureId*`, `skin/armor Mask/Color/Normal/Dye` maps, `componentRegionFlags`, `componentPriority`, `modelMeshId00..03`, `dyeChannelFlags`, `modelPoseId`, `shaderPreset00/01` | same ids; `modelMeshId` 100 % valid; `modelPoseId` 100 % valid ModelPose [verified] |
| `CharacterCustomization` | 4,784 | per race/gender and slot: `raceId`, `gender`, `itemSlotId`, `itemDisplayId`, label/value pairs | 15 race x gender combos; picks an ItemDisplay (hair, face, ears ...) [verified] |
| `CharacterCustomizationLabel` / `Selection` | 27 / 248 | labels of the customization UI and the allowed values (+ cost) | text ids -> `en-US.bin` [verified] |
| `CustomizationParameter` / `CustomizationParameterMap` | 24 / 443 | body/face **sliders**: scale/rotation/position deltas applied to a **bone** (`modelBoneId`) per race/gender | 443/443 `modelBoneId` are valid ModelBone ids -> m3 bones via bone.model_bone_id [verified] |
| `DyeColorRamp` | 422 | dye colors (`rampIndex`, `componentMapEnum`, cost) | applied via the dye maps of ItemDisplay [verified table, shader use open] |
| `ColorShift` / `colorShiftTexturePath` | | LUT .tex files (`Art\FX\LutMaps\*_LUT.tex`) for hue shifts of creatures | [verified table] |
| `ReplaceableMaterialInfo` | | shader/material presets for replaceable textures (layers, color/normal/height index per layer) | [verified table] |
| `ModelMesh` (201) / `ModelCluster` (61) / `ModelBone` (62) / `ModelAttachment` (202) / `ModelPose` (201) / `ModelEvent` (81) / `ModelCamera` (60) / `ModelSkinFX` (3) | | **enumerations** that give names to the ids stored in the m3 | bone/mesh/cluster ids [verified] |
| `ModelSequence*` | 7,287 | animation names / fallbacks / by mode, weapon, seat posture | clip animation id [verified] |

## 3. "TextureData" – what drives textures

1. The m3 lists *default* textures (type 0 color / 1 normal / 2 skin-FX) per **material description pair** (two texture indices).
2. A texture entry carries a **model texture id** (u16 @0). Tables replace the file of the entry with that id
   (`assetTextureNN` + `modelTextureIdNN`). Example: AgressorBot textures 2 (id 1, Color) and 3 (id 2, Normal) are replaced
   by `Creature2DisplayInfo` 21308 `assetTexture00/01`.
3. Skin/armor are masked: `ItemDisplay.skinMaskMap/skinColorMap/skinNormalMap/skinDyeMap` and the armor equivalents,
   selected by `componentRegionFlags` against the mesh **cluster**.
4. Colors: `DyeColorRamp` (dyes) and `ColorShift` LUT textures.
5. .tex itself: 112-byte header (size, mip count, format 0/1 ARGB, 5 RGB565, 6 gray, 13/14/15 DXT1/3/5, or WildStar JPG
   variants 0-2 with per-channel quality + default color), mips stored smallest first [verified, decoder in `tools/blender_addon/wildstar_m3/tex.py`].

## 4. Not (yet) decoded
Normals/tangent packing, vertex colors, the emitter/ribbon/light blocks (AP 0x2F8, 0x510-0x5A8), the group blocks at 0x080/0x0F0, track set 1/3/5/7,
the byte @3 / u32 @4 / float @8 of texture entries, material description words @0x10.. . For all of them the survey json lists which models carry them
(good Ghidra start points: `FUN_1402eb270` default model builder, `FUN_140300fd0` instance update).
