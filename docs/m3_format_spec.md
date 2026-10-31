# WildStar .m3 – consolidated format specification (build 16042)

Status legend: **[V]** verified on all 34,733 models or by the original shader, **[S]** structure known (sizes/pointers verified),
meaning partly open, **[O]** open. Sources: NexusVault templates, our validators (`tools/validate_*.py`), Ghidra on `WildStar64.exe`,
disassembly of the original `ModelVS.vs_4_0.sho` (D3DCompiler), game tables (`extracted/tables_csv`).

## 1. Container
Little endian. `LDOM` + version 100, header 0x630 bytes. Everything is a tree of arrays:
`AP = {u64 count, u64 offset}`, `DP = {u64 count, u64 keyOffset, u64 valueOffset}` (key array of u32 ms, value array follows, 16-byte aligned).
Offsets of header arrays are relative to 0x630; offsets of arrays nested in an element are relative to `align16(end of the parent array)`. [V]

## 2. Header slots (element size from the engine's own allocators `FUN_14030cac0` / data audit across 34,712 models)
| Slot | Elem | Meaning | Verified Count / Dataset Freq | State |
|---|---:|---|---:|---|
| 0x008 | 8 | Model CRC / Identifier hash | 99.9% (34,700+) | V |
| 0x010 | 0x70 | Animation clips (id, variant, blend, start/end ms, bounds) | **100%** (34,712) | V |
| 0x020/0x038/0x050/0x068 | 24 (DP/AP) | Secondary sequence lookup bags / player race state flags | 1.4% (480+) | V |
| 0x080 | 0x30 | SubClips: sequence slices (start, end, flags) + nested APs (@0x20) | 3.7% (1,300+) | V |
| 0x090/0x0A8/0x0C0/0x0D8 | 24 (DP/AP) | Secondary anim lookup channels & spell visual tags | 0.6% (210+) | V |
| 0x0F0 | **0xB8** | Extended Bone Tracks: 7 dynamic pointer timelines (DP@0x08, 0x20, 0x38, 0x50, 0x68, 0x80, 0x98) | **100%** (34,712) | V |
| 0x100/0x118/0x160 | 24 (DP) | Bone-linked effect timeline channels (spell impacts / explosions) | 0.9% (320+) | V |
| 0x160 / 0x168 | 16 | Hologram projection anchor metadata | <0.1% (20+) | S |
| 0x180 | 0x160 | Bones: ModelBone id u16@0, parent i16@4, extTrack u16@6, hash u32@8, 8 tracks, bind world 4x4, pivot | **100%** (34,712) | V |
| 0x190 | 2 | Per-bone attachment lookup map | 53.6% (18,600+) | V |
| 0x1A0 | 2 | Bone map / palettes (vertex bone index -> bone) | 60.1% (20,800+) | V |
| 0x1B0 | 2 | Secondary bone lookup table | 92.6% (32,100+) | V |
| 0x1C0 | 0x20 | Textures: modelTextureId u16@0, type u8@2, flags u8@3, name AP@0x10 | 98.4% (34,100+) | V |
| 0x1D0 | 2 | Texture replacement slot lookup | 54.1% (18,700+) | V |
| 0x1E0 | 0x98 | Secondary geometry / LOD links (6 tracks, distance switches) | 7.9% (2,750+) | S |
| 0x1F0 | 0x30 | Materials -> layer descriptions (**0x128** each, color/normal tex, 11 DPs) | 92.6% (32,100+) | V |
| 0x200 | 4 | MeshDisplay: (ModelMesh id u16, default-render flag u16) | 9.4% (3,270+) | V |
| 0x210 | 2 | MeshDisplay lookup table | 9.4% (3,270+) | V |
| 0x250 | 0xC8 | Geometries: vertex buffer, index buffer (16/32-bit), submeshes | **100%** (34,712) | V |
| 0x260 / 0x270 | 4 / 2 | Distanz-LOD geometry & mesh lookup tables | 17.1% (5,950+) | V |
| 0x280 | 8 | Attachment points `{u16 bone, u16 0, u32 ModelAttachment id}` | 4.5% (1,550+) | V |
| 0x290 | 4 | Attachment socket name tags / hashes | 2.5% (860+) | S |
| 0x2B8 | 0x28 | Sound emitters: bone u32, AP states `{u16 startEvent, u16 stopEvent, DP onOff}` | 5.0% (1,740+) | V |
| 0x2C8 | 8 | SoundEvent IDs (`{u16 0xFFFF, u16 0, u32 id}`) mapped to SoundEvent.csv | 2.9% (1,000+) | V |
| 0x2F8 | 0xA0 | Particle emitters: bone, texture, modes, blob offset @0x90 -> 0xED0 property bag | 14.8% (5,150+) | V |
| 0x308 | 0x50 | FX tracks: u16 bone, u16 word + 3 S2 DP tracks (@0x08, @0x20, @0x38) | 0.4% (140+) | V |
| 0x318 | 0x190 (400 B) | Lights: type, bone, texture masks, 16 DPs (color, intensity, atten) | 3.4% (1,180+) | V |
| 0x328 / 0x338 | 0x38 / 2 | Cameras: bone, aspect, DP fov, near/far planes / camera lookup | 6.9% (2,400+) | V |
| 0x348 | 0x4B0 | Ribbon emitters: bone, texture, blend mode, 0x4B0 property bag | 99.9% (34,700+) | V |
| 0x350 – 0x380 | Var | Ribbon trail control points, timeline animation keys, UV coords | 2.7% – 4.3% | S |
| 0x490 | 0x40 | Collision KD-tree: AP headers (16 B), AP vertices (float3), AP indices, AP nodes (20 B) | **100%** (34,712) | V |
| 0x4A0 | 4 | Prop states: `{u16 ModelSequence id, u16 variant}` | 2.4% (820+) | V |
| 0x510 – 0x528 | 16 / 4 / 4 | Terrain anchor points / foundation placement nodes (`float3 pos, float 1.0`) | 0.4% (150+) | V |
| 0x530 – 0x538 | Var | Spawner volume nodes & area trigger boundaries | 0.3% (100+) | S |
| 0x540 – 0x558 | Var | Mount / Vehicle passenger & driver seat attachments | <0.1% (20+) | S |
| 0x560 | 0xA0 | Skin FX definitions: bone, textures, blend modes, color/intensity DPs | 3.7% (1,300+) | V |
| 0x570 | 0x20 | Environment shader override passes (Water, Ice, Translucent Glass) | 0.3% (100+) | S |
| 0x588 | 0x20 | Facial morph / blendshape weights timeline | 1.8% (610+) | V |
| 0x598 / 0x5A8 | 0x4C (76 B) / 2 | Face customization slider ranges (`CUST_*` bone delta limits) & lookup | 0.3% (120+) | V |
| 0x5C0 – 0x5C8 | Var | Cloth simulation spring networks & vertex matrices (Banner, Segel) | 2.1% (710+) | S |

Header scalars (bounding volumes at 0x390/0x3D0/0x410/0x450/0x4B0, head bone 0x580, random ranges 0x5D8) and all details of the blocks above: `docs/m3_rare_blocks.md`.

## 3. Vertex format (geometry +0x20 types, +0x2B positions) [V]
| Field | Bytes | Decoding |
|---|---:|---|
| position | 12 (3 x f32) or 6 (3 x i16 / 1024) | |
| tangent (f3a) | 2 | octahedral, UNORM8: `x = b0/255*2-1, y = b1/255*2-1, z = 1-|x|-|y|`, fold if z<0; = dP/du (corr +0.999) |
| normal (f3b) | 2 | same encoding; matches face normals (mean dot 0.86-0.90) and the original VS |
| bitangent (f3c) | 2 | same encoding; = -dP/dv (corr -0.999) |
| bone indices | 4 x u8 | index into bone map |
| bone weights | 4 x u8 | sum 255 |
| color0 (f4a) | 4 x u8 | vertex color; VS: rgb x 2 (0x80 = 1.0), alpha direct |
| color1 (f4b) | 4 x u8 | second color; pixel shader uses .zw as UV of a ninth texture (lightmap/decal) and .y as a value |
| uv1 / uv2 | 2 x f16 each | |
| f6 | 1 | unused by ModelVS [O] |

## 4. Geometry struct (0xC8) [V]
+0x18 vertexCount u32, +0x1C vertexSize u16, +0x1E flags u16, +0x20 field types[11], +0x2B field positions[11], +0x38 AP vertex bytes,
+0x68 indexCount u32, +0x70 AP index bytes (u16), +0x80 AP meshes (0x70 each: startIndex, startVertex, indexCount, vertexCount, material u16@0x16, group u8@0x1E, cluster u8@0x22),
+0x90 vertexCount2, +0x98 AP per-mesh start vertex (u32, cumulative), +0xA8 AP u16 x (triangles+1) (monotonic, purpose open), +0xB8 AP per-mesh start triangle (u32, cumulative).
Indices are local to each mesh (add `startVertex`).
Mesh +0x38 is a u32 flag field. The original normal draw-list builder
`FUN_1402f9f10` excludes meshes when `(flags & 0x0A) == 0x0A`; examples are
bush domes and bark-covered tree envelopes. See `m3_visibility_fixes_dbg42.md`.

## 5. Effect emitter blob (0x2F8 +0x90) [S]
A flat struct of ~8.3 KB (0x2040 / 0x20E0 / ... depending on the template) beginning with a header and a table of DP properties
(24 bytes each starting at +0x68; constants use count 1, keys/values 16-byte slots), interleaved with inline scalars (e.g. float 1.0 + ints at +0x290).
Texture ids inside (u16 at +0x978/+0x994/+0x996/+0x99A for particles, +0x3C4/+0x3DC/+0x3DE/+0x406 for ribbons) index the model's texture array.
The meaning of the individual properties (rate, lifetime, size, color curves ...) is [O].

## 6. Track semantics (bone) [V]
0 scale, 2 parent scale copy, 4 rotation (i16/16384), 6 translation (parent frame); 1/3/5/7 = pose layers (keys appear only in BasePose / Alert / BodyType clips).
Mirrored limbs use negative scale; the sign convention per bone is solved from the base pose (see `docs/m3_animation_format.md`).
