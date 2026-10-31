# Terrain blocks and striping correction — dbg39

2026-10-25. Original binary: `WildStar/Client64/WildStar64.exe`.
Evidence was read from the existing Headless project and then directly from
the running Ghidra MCP 7.0.0 instance, project **WSG**, program
**WildStar64.exe**. No original executable or .area data was modified.

## Findings

| Flag bit | Raw storage | Meaning | dbg39 conversion |
|---|---|---|---|
| 13 | 17x17 **BC2/DXT3** blocks, 16 bytes each, 4,624 bytes | 65x65 colour texture with explicit 4-bit alpha; RGB is the terrain colour attribute. The exact lighting/material meaning of alpha remains open. | Extracted to RGB/alpha PNGs for inspection; not yet applied to WoW terrain colours. |
| 16 | 64x64 packed bytes, 4,096 bytes | Zone and terrain flags. Bits 3–4 select one of four zone IDs from bit 28. Flag 0x20 prevents clutter placement. NexusForever additionally identifies bit 0 as RoadMarch. | Preserved in the original file, not yet mapped into WoW zone/ground-effect data. |
| 17 | 17x17 **BC1/DXT1** blocks, 8 bytes each, 2,312 bytes | Base texture-layer weights, RGB = WorldLayer slots 0–2. Alpha indicates BC1 coverage. | Decoded at 65x65, combined with bit 18, then converted to WoW MCAL. |
| 18 | Same BC1 storage | Signed RGB correction to bit 17. | Applied before deriving/clamping slot 3. |
| 27 | 64x64 bytes, four 2-bit fields per byte | One clutter preset selector per WorldLayer slot. `(byte >> (slot*2)) & 3` selects that layer's `worldClutterId00..03`. | All four fields extracted to separate PNGs. Clutter instances/ground-effect DBC records are not generated yet. |

The BC textures contain **65x65 logical texels**, padded to 68x68 by the
compression grid. The number 17 counts 4x4 compression blocks, not vertices.
BC1 has two RGB565 endpoints followed by sixteen 2-bit selectors. BC2 adds
sixteen explicit 4-bit alpha values before its colour block.
[Microsoft's format definitions](https://learn.microsoft.com/en-us/windows/win32/direct3d10/d3d10-graphics-programming-guide-resources-block-compression)
describe the standard packing; the assignments to WildStar flag bits come
from the binary evidence below.

## Why dbg38 produced stripes

`AdtBuilder.cpp` previously interpreted bit 17 as 17x17 vertices, reading
only u16[0] of every 8-byte record, then interpolating those endpoints.
That discarded the second endpoint and **all sixteen pixel selectors** of
each BC1 block. Bit 18 was ignored. This was a data decoding bug in addition
to the independent chunk-UV phase problem addressed by dbg38.

The earlier statement that the ADT weights were already correct was wrong.
The average-colour preview alone was insufficient to validate their decoding.

`Area3/TerrainBlend.cpp` now decodes the pixel selected within each BC1 block:

```text
w.rgb = base.rgb + correction.rgb * (31/15, 63/31, 31/15) - 1
w[3]  = 1 - w[0] - w[1] - w[2]
w     = clamp(w, 0, 1) * base.alpha
```

The converter retains raw-map priority (29, then 2) and existing raw-map
smoothing. Compressed sources use pairs 19/20, then 17/18, at their actual
65x65 resolution. The dbg38 texture-phase correction remains in place.
**Superseded in dbg40:** dbg39 incorrectly encoded these weights as stacked
lerp alphas, although the map uses MPHD 0x4 and the renderer expects direct
additive weights. See [terrain_texture_fixes_dbg40.md](terrain_texture_fixes_dbg40.md).
The weight decoder itself remains valid. Exact WildStar coverage/material-shader
behaviour still requires further conversion work.

## Binary evidence

- `FUN_1402e76e0` requests blocks 0x11/0x12 (17/18), reads RGB565 endpoints
  at +0/+2, and consumes a 32-bit index word at +4 using `index & 3`,
  `index >>= 2` sixteen times. The results feed 4x4 pixel loops, not vertices.
  It also remaps the four pairs of bit 27 whenever layers are reordered.
  See `ghidra_terrain_bit_users.c`.
- `FUN_1402e8680` requests bit 13 and passes each 16-byte block to
  `FUN_140268060`. That decoder calls the colour decoder at block+8, then
  consumes two u32 values four bits at a time for sixteen alpha samples.
  This establishes **BC2**, not BC3. See `ghidra_terrain_bc.c`.
- `FUN_1402da040` (queried through the running MCP) samples 17/18, applies
  the signed correction above and supplies four weights. It samples bit 13
  into RGB attributes plus a separate alpha attribute. It reads bit 16 and
  selects the zone from bit 28 using `(byte >> 3) & 3`.
- The same query, flag 0x1000, reads bit 27 and expands
  `byte & 3`, `(byte >> 2) & 3`, `(byte >> 4) & 3`, `byte >> 6` into four
  output fields.
- `FUN_140381970`, the clutter generation worker scheduled by
  `FUN_140381300`, requests query flags **0x1411** (including weights,
  terrain flags and the four selectors). It rejects terrain flag **0x20**,
  chooses a texture layer by its weight, and indexes the 16 prepared clutter
  entries using **layer*4 + selector[layer]**.
- `FUN_140381070` prepares those 16 entries from four layer objects, each
  containing four IDs at +0x78. Their resources are loaded via
  `FUN_140354790` -> `FUN_140374370` -> `FUN_140374420` ->
  `FUN_140350f40` -> **WorldClutter** table lookup `FUN_14024b100`.

The relevant direct MCP decompilations are preserved in
`ghidra_terrain_mcp_evidence.c`. The separate `ghidra_terrain_bit27_users.c`
is a broad immediate-value survey and contains unrelated uses of integer 27;
do not treat those as terrain-block consumers.

## Validation and outputs

- Release targets **WowClient**, **adt_build_cli**, **terrain_blend_cli** built.
- Synthetic regressions cover all BC1 indices, both interpolation modes,
  transparency, padded edge texels, neutral/non-neutral corrections, 19/20
  fallback, and raw-map source priority.
- All **256 cells** of `Western.393b.area` independently compared with Pillow's
  native BC1 decoder. The C++ decoder uses normalized GPU endpoint floats;
  Pillow expands to 8-bit integers. Maximum accumulated weight difference:
  **0.0291887**, below one 5-bit quantization step (1/31). This is an offline
  cross-check, not a GPU rendering test.
- All **145,956 nonzero clutter selector fields** in that tile select an
  existing WorldClutter ID in the corresponding WorldLayer row.
- Rebuilt WS_Western ADT 4,6: **3,167,433 bytes**. Compared with dbg38,
  **255/256 MCAL payloads change**. MCVT, MCNR, MCRF, MMDX, MMID, MDDF,
  MWMO, MWID, MODF and MTEX payloads remain byte-identical.
- `area_blocks/dbg39/validation.json`: counts and comparison results.
- `area_blocks/dbg39/blend_comparison.png`: old/new weights using fixed
  slot colours; adjacent cells can have different WorldLayer IDs, so these
  fixed slot colours cannot establish inter-cell visual continuity.
- `area_blocks/dbg39/adt_preview_4_6.png`: actual exported ADT weights mixed
  with average source texture colours. This does not simulate lighting or
  actual texture sampling.
- Separate bit13 RGB/alpha, bit16 flags/zone/no-clutter, bit17/18 RGB and
  bit27 slot0..3 images are in `area_blocks/dbg39/`.

Executable: **WoWClient/WowClient64_dbg39.exe**. Earlier debug executables
are preserved. Runtime visual confirmation and stability of dbg39 have not
yet been tested in game.

## Reproduce

```powershell
cmake --build wowdecomp/build/x64 --config Release --target WowClient adt_build_cli terrain_blend_cli --parallel 8
./wowdecomp/build/x64/bin/Release/terrain_blend_cli.exe
./wowdecomp/build/x64/bin/Release/terrain_blend_cli.exe WoWClient/ClientData/Map/Western/Western.393b.area build_m3test/terrain_blend_393b.bin
python tools/analysis/terrain_block_check.py WoWClient/ClientData/Map/Western/Western.393b.area build_m3test/terrain_blend_393b.bin docs/area_blocks/dbg39
# Run adt_build_cli with WoWClient as its working directory:
../wowdecomp/build/x64/bin/Release/adt_build_cli.exe WS_Western 4 6 ../build_m3test/ws_4_6_dbg39.adt
```

The running Ghidra MCP bridge publishes its schema at `/mcp/schema` and
instance details at `/mcp/instance_info`. Current read endpoints include
`/force_decompile?function=...&program=WildStar64.exe` and
`/get_xrefs_to?address=...&program=WildStar64.exe`; the old
`/decompile_function` endpoint is absent in version 7.
