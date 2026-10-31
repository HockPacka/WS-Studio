# WildStar `.i3` and `.dgn` formats

Tools: `tools/i3_reader.py`, `tools/dgn_reader.py` (both validate every file: `--check <ClientData/Art>`).
Client loaders (WildStar64.exe): FEDS `FUN_1402d2e30`, FEDI `FUN_1402c9270` (caller `FUN_1402c9db0`), NGND `FUN_1402d5650` (caller `FUN_1402d5d40`).

All three are *relocatable structs*: arrays are `{u32 count, u32 pad, u64 offset}`, offsets are relative to the end of the header.

## Overview – what they are

A static structure (building, dungeon kit) = one **model file** `X.i3` (FEDI) + one **sector file** per sector `X.<Sector>.i3` (FEDS, the actual triangles).
A dungeon kit additionally has a **definition** `X.dgn` (NGND) and numbered **dressing files** `X.<N>.dgn` (props placed inside the dungeon).
The M3 loader/`area` work is unrelated; i3 structures are placed by `.area` props / the dungeon system.

Counts: 1704 `.i3` (1291 FEDS, 413 FEDI, 2.0 GB, largest 55 MB Datascape sectors), 986 `.dgn` (221 NGND, 765 dressings, 386 573 placements, 4694 distinct models).
Validation: 1291/1291 FEDS, 413/413 FEDI, 986/986 DGN consistent (every array inside the file).

## FEDS – sector file (magic `FEDS`, version 30, header 0x1B0)

| header @ | stride | meaning |
|---|---|---|
| 0x20 | 2 | UTF-16 sector name (`Sector_Exterior`) |
| 0x38 | 12 | vertex positions, float3 |
| 0x48 | 20 | vertex attributes (below) |
| 0x58 | 4 | u32 indices, 3 per triangle |
| 0x68 | 2 | u16 per triangle (surface/material flag, e.g. 16) |
| 0x78 | 28 | sub meshes `{kind, firstIndex, lastIndex, firstVertex, lastVertex, id, 0}` (indices inclusive) |
| 0x88 | 8 | kd-tree nodes `{float split, u32 info}` (flag 0x80000000 = leaf) |
| 0x98 | 8 | kd leaves `{start, count}` into |
| 0xA8 | 4 | triangle numbers |
| 0xB8 0xC8 0xE8 0xF8 0x108 | 4 | u32 arrays (usually empty) |
| 0xD8 / 0x140 / 0x180 | 16 / 24 / 32 | lists of `{count, u64 off -> u16[]}` |
| 0x150 / 0x160 / 0x170 | 16 / 2 / 2 | struct D arrays (usually empty) |
| 0x190 | 2 | submesh numbers |
| 0x120 / 0x130 | – | bounding box min / max (float3 + pad) |

Vertex (20 bytes): `[0..3]` packed (tangent frame, not decoded yet), `[5],[6]` octahedral normal (x = byte6, y = byte5, `n = oct_decode`; mean dot with the face normals 0.97),
`[8..15]` 4 half floats = UV0 and UV1, `[16..19]` colour RGBA bytes.
`python tools/i3_reader.py --obj sector.i3 out.obj` exports positions, UV0, normals, one object per sub mesh (`docs/i3_wallbuilding_sample.obj`,
`docs/i3_wallbuilding_preview.png` shows the decoded Falkrin wall building from 3 sides).

## FEDI – model file (magic `FEDI`, version 41, header 0x170)

Plain arrays (count @ offset): sectors @0x20 (stride 0x40, first u32 = index into the name table), 0x30 (0x90, nested u16 arrays), 0x40 (0x58 material records, nested), 0x50 (u16),
0x60 (0x40), 0x70 (0x28), 0x80 (0xB0), 0x90 (0x20), 0xA0 (0x40), 0xB0 (u16), 0xC0 (0x38), 0xD0 (8), 0xE0 / 0xF0 (u16), 0x100 / 0x110 (u32),
**string pool** @0x120 (UTF-16), **name table** @0x130 (u32 char offsets into the pool). Bounding box @0x140 / 0x150.
The sector file of sector `S` of model `M` is `M.S.i3` (client builds it with `_wsplitpath/_wmakepath`).
The pool also contains the shader pass names (`Default_Pass`), the texture paths (`*_Color.tex`, `*_Normal.tex`) and shader parameters.
Material records (0x40 slot) hold shader parameter blocks (float4 / texture slots `ffff 0001 05000000 ...` followed by the pool index); only the structure is known,
the per parameter meaning is still open.

## NGND – dungeon definition (`X.dgn`, magic `NGND`, version 6, header 0x50)

`@0x08` guid string, `@0x18` display name, `@0x28` model path (`Art\...\X.i3`), `@0x38` dressing list (stride 0x28:
`{u32 index, pad, count/off name, count/off dressing file}`, nested offsets are relative to the 16-byte-aligned end of the dressing array; Datascape BW_000 / DataCore require 8 padding bytes).

## Dressing file (`X.<N>.dgn`, no magic)

Header 0x30: `u32 N, pad, {count, off} placements (stride 0x80), {count, off} records of 0x14 bytes`.
Placement (0x80): `u32 id` `@0x08 count / @0x10 off` of the UTF-16 model path (offset relative to the end of the placement array, usually `.m3`, `Art\Light\LIT_Point_*.m3` are lights),
`@0x20` colour float4, `@0x30` scale (float), `@0x40` position float3, `@0x50` rotation quaternion (x y z w), `@0x60/0x68` count/offset of an extra array (16 byte entries, zero so far).
Tail records (0x14 bytes `{u32 hash, u32 value, 0, 0, 0}`, offset relative to the end of the header) – meaning unknown.
Check: 16347 of 16364 sampled placements lie inside the bounding box (+5 m) of the model of their dungeon, so position/units are right.

## Native reader (WoW 3.3.5a WMO, in memory)

`.i3` structures are WMOs (large objects, own geometry/collision), `.dgn` dressing placements are M3 models = M2 doodads.
Code: `wowdecomp/Engine/Source/Struct3/` (`I3Reader`, `WmoBuilder`), test: `build_m3test/i3_wmo_cli.exe` + `tools/wmo_check.py` (`--all` builds and validates every FEDI model: 413/413 ok, 4086 groups).

* Client hook: `CMapObj::Read` / `ReadGroup` (`MapObjRead.cpp`): a name `WS\Art\...\X.i3` is built in memory (root file + groups `<root>_NNN.wmo`), nothing is read from disk.
* Area: `.area` props that end in `.i3` become MWMO / MWID / MODF entries (AdtBuilder), exact rotation in the extension chunk **MOQT** (parallel to MODF, MHDR m_unused[1]); a structure is referenced from every chunk of its tile that its bounding sphere touches.
* Axes `WoW = (ws z, ws x, ws y) * scale`, scale 1.0417 for structures placed in the terrain (same as the terrain).
* Materials: FEDI material set 0 (`Default_Pass`), `submesh.id = (material + 1) << 8 | pass`; `hi == 0` or `lo == 255` = collision only (no batch). Material -> texture: u16[0] colour texture index of the set (`WS\...blp` through the existing .tex -> BLP path), u16[4] == 5 = decal -> alpha blend.
* Groups: one per sector, split to <= 12000 triangles (median split); one batch per material, vertices are duplicated per batch; collision BSP (MOBN/MOBR) built from the triangles; flags `0x1 | 0x8` (BSP, exterior); no portals, lights, doodads, liquid, vertex colours.
* Not mapped (lost in WoW): second UV set, normal map, kd tree, tangents, material variants (`Aurin_Autumn` etc.), instance scale (prop scale is ignored for structures).

## Open
* tangent bytes `[0..3]` of the FEDS vertex, kd-tree usage, the `tri_u16` values;
* per parameter semantics of the FEDI material records, the 0x30/0x60/0x70/0x80/0x90/0xA0/0xC0 slots;
* the tail records of the dressing files; the 8 models referenced by dressings that do not exist in the client data.
* WoW 3.3.5a: geometry maps directly to M2/WMO style meshes (positions, oct normal -> normal, 2 UV sets, vertex colour); the kd-tree and surface flags have no WoW equivalent (collision only).

## Dressings in the WMO (dbg47)
* The dungeon definition (X.dgn, NGND) next to the model names the model (.i3) it belongs to; every dressing becomes a WMO doodad set: set 0 = Set_$DefaultGlobal (empty), set 1 + n = dressing n (MODS / MODN / MODD, M3 names as WS\...m3, placement in WMO space with the structure scale; lights (Art\Light) and missing models are dropped). Each doodad is referenced (MODR, group flag 0x800) by the group whose box contains it.
* Area props that end in .dgn (36 in Western) are dungeon definitions: their model is placed as WMO with doodad set 1 (default dressing). Which dressing a prop uses is not decoded (prop record +64 is not the index).
* Doodad models are prefetched in the background (MapPrefetch.cpp).

## Portals (dbg48)
* FEDI root slot 0x30 (0x90 byte records) = portals between sectors, stored twice (a -> b and b -> a): `{u32 name, u16 sector a, u16 sector b, +0x10 position, +0x20 scale, +0x30 rotation quaternion, +0x40 local float4 vertex array, +0x50 u16 triangle index array, +0x80 local plane (normal points from a into b)}`. Quads are common but not universal: 82 of 413 inventoried models contain other shapes. Keep the indexed mesh; convex pieces are built from adjacent triangles without filling concavities or holes, capped at 10 corners for the client's clipping buffers.
* Sector record (0x40 bytes) +0x30 = 1 for the outside sector, 0 for inside sectors.
* WMO: MOPV / MOPT / MOPR from these; outside sector groups get flag 0x8 (batches counted as exterior), inside sector groups flag 0x2000 (batches counted as interior), so inside groups are only drawn when the viewer is inside or looks through a portal. A sector that is split into several groups gets one synthetic portal per split plane (the quad of the plane) so that it stays one connected room. A model without portals stays all outside groups; more than 65 000 portal references (16 bit group header) also falls back to all outside.
* Check: `tools/wmo_check.py` validates MOPV / MOPT / MOPR ranges and the group portal ranges.
* Current adapter (2026-10-26) writes root MOHD flag 0x2 for UnifiedRender. Without MOCV, the default client path dispatches indoor groups to ExteriorRender and draws zero indoor-only batches. Portal classification remains active. Limits additionally include 2048 portals (client extension array) and 65535 portal vertices; oversized structures retain the conservative all-exterior fallback. See `docs/i3_portal_visibility_investigation.md` and `tools/analysis/i3_portal_fix_check.py` for regression evidence.
