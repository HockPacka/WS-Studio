# M3 helper envelopes and texture reload — dbg42

## Visible mesh selection

Original WildStar build 16042 `FUN_1402f9f10` iterates geometry meshes (0x70
bytes) and excludes `(mesh.byte_at_0x38 & 10) == 10` before constructing the
normal draw list through `FUN_14030e7b0` / `FUN_1403258c0`.
The Ghidra MCP decompilation is saved in
`ghidra_m3_mesh_visibility_mcp_evidence.c`.

Our converter previously emitted every group 0/255 mesh, including these
envelopes. The raw M3 reader now retains `mesh.flags` at +0x38; the M2 builder
applies the original exclusion before group selection. This is based on file
flags, not texture names, bounds, or a list of plant names. Raw source geometry
is retained by the reader and original files remain unchanged.

Verified examples:

| Model | Excluded mesh | Flags | Retained batches |
|---|---|---|---|
| WeepingUmbrella 000 | closed dome, 290 vertices / 528 triangles, BLANK_Grey | 0x0A | two masked foliage meshes |
| WeepingUmbrella EldanTech 000 | helper envelope | 0x0A | one layered foliage mesh |
| AlgerocPointyPine 000 | 101-vertex envelope, bark material | 0x20A | opaque trunk and masked canopy |

The precise name/purpose of each excluded helper pass remains open; the original
normal-draw exclusion itself is confirmed. We do not claim all are collision meshes.

## Original shader inspection

Inspected the actual `WoWClient/ClientData/Shaders/ModelPS.ps_4_0.sho` archive
(16,958 DXBC blobs) with the system D3D disassembler using `tools/analysis/dxbc_dis.py`.
Saved mask/depth permutation examples:

- `shader_modelps_16_mask.txt`: samples color alpha from t3 and a normal/material
  channel from t7, combines them through CB1 and interpolated weights, multiplies
  by v2.w, subtracts CB2[1].y, and discards negative coverage.
- `shader_modelps_240_mask.txt`: samples t0/t4, includes parallax and an effect
  overlay t12/t13, and finishes with the same coverage threshold.

These demonstrate that WildStar's masks can involve more than plain color alpha.
They are archive blob indices, not a claim that a photographed object selects
one of these exact permutations. `FUN_14030e510` selects shader permutations
using mesh/material fields. The mesh exclusion above happens before shading
and explains why the envelope should not be sent to the normal WoW draw path.
Full WildStar multilayer/parallax shading remains outside the current M2 path.
Original shader files are unchanged.

## GPU texture reload

Initial WS texture creation converts TEX to BLP in memory. The GPU reload
callback instead went through `TextureLoadBlpMips`, which attempted to open a
nonexistent `WS\...blp` file. That path now also converts the TEX source in
memory, then uses the existing BLP chain-copy path before releasing the temporary
buffer. This prevents loss of the texture on cache/device reload. Native BLP
loading follows its previous path. Build verified; device reset not tested live.

## Validation

`python tools/analysis/m3_material_check.py`:

- Six real models, including both envelope cases and previously working props.
- Original visible batch modes retained; helper envelopes absent.
- Controlled flags 0, 2, 8 retained; 0x0A and 0x20A excluded.
- Seven material blend modes, four opacity cases, depth flags, missing-texture
  fallback, and single-layer tint still pass.
- Eight source textures / 78 mip levels including alpha: JPEG-like output compared
  to independent decoding; DXT payloads including alpha blocks preserved byte for byte.

Reports: `m3_material_dbg42_validation.json`, `m3_alpha_dbg42_validation.json`.
Build log: `../build_m3test/dbg42_build.log`.
Executable: `../WoWClient/WowClient64_dbg42.exe`. No in-game visual check performed.
