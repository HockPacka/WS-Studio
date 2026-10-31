# WildStar `.area` (terrain tile) - state of the decoding (2026-10-25)

**Correction in dbg39:** the 17 x 17 records of bits 13/14/17..20/31 are BC texture blocks, not low-resolution vertices. See [terrain_blocks_dbg39.md](terrain_blocks_dbg39.md) for binary/MCP evidence and the striping fix.

**Correction in dbg40:** the WoW map uses MPHD 0x4, so exported MCAL maps now
store direct additive weights, with the base layer implicit. dbg39's stacked
alpha encoding was incorrect. See [terrain_texture_fixes_dbg40.md](terrain_texture_fixes_dbg40.md).

Reader: `tools/area_reader.py` (structure from `tools/NexusForever/Source/NexusForever.IO/Area`, extended: compressed `_Low` files, all block sizes).
`python tools/area_reader.py file.area` prints the chunks and the first cells; `--check <dir> [limit]` parses a whole tree and counts chunk / block usage
(full run over all 15,051 files: `docs/area_check_all.txt`).

## File
```
u32 magic   bytes 'a','e','r','a'  (regular tile)   or  'A','E','R','A' (the *_Low.*.area LOD tiles)
u32 version (0)
chunks:  u32 id (text stored reversed: 'KNHC' = CHNK, 'TRUC' = CURT, 'pORP' = PROp, 'OMHD' = DHMO), u32 size, data
```
Folder `Map\<MapName>\<MapName>.<xx><yy>.area` (hex tile coordinates, e.g. `.393b`), 15,051 files, 14.6 GB, 115 maps. One tile = 16 x 16 cells = 512 m (cell = 32 m).

## CHNK (terrain)
List of cell entries: `u32 info` (top byte = index delta to the previous cell + 1, low 24 bits = size) followed by the cell. Cell index = x + 16 * y.
* `*_Low` (`AERA`): `info` low 24 bits = **uncompressed** size, the cell is a zlib stream (self delimiting). The first entry (1024 bytes) is no cell (palette?).
* Cell = `u32 flags` + one fixed size block for every set flag bit (in bit order) + trailing sub chunks (`u32 id, u32 size, data`: `Psbw` WBSP?, `Druc` CURD,
  `PORP` PROP (placements), `GtAW` WATG (water?)).

### Block layouts per flag bit (all 32 sizes verified: every cell of the checked files parses exactly; layouts found by neighbour smoothness tests)
Smoothness test = mean |neighbour difference| / std over candidate rasters (width x height x components x element size); the right raster scores 0.02 - 0.1, wrong ones 0.4 - 1.
| bit | bytes | layout | meaning |
|---|---|---|---|
| 0 | 722 | 19 x 19 u16 | **heightmap** (see below) |
| 1 | 16 | 4 x u32 | **4 `WorldLayer` ids of the cell** (`tables_csv/WorldLayer.csv`: colour / normal map path, `MetersPerTextureTile`, height / parallax scale, clutter ids). E.g. `(27, 10, 99, 2)` = MountainStone_ZY, StoneFlattener, MountainStone_Small_XZ, Grass_GrnDrkDesat. Present in 897,320 cells |
| 2 | 8450 | 65 x 65 u16 = 4 x 4 bit (R,G,B,A nibbles) | blend weights, one-hot nibbles (`0xF000`, `0x0F00`, `0x00F0`), not normalised |
| 3 | 8450 | 65 x 65 u16 RGB565 | uncompressed colour map; compressed companion bit 13 |
| 15 | 8450 | 65 x 65 u16 RGB565 | RGB map with BC1 companion bit 14; exact role in alternate terrain paths remains open |
| 29 | 8450 | 65 x 65 u16, 4 nibbles whose **sum is constant (15)** | normalised **4 layer blend weights** |
| 4, 25, 30 | 8450 | 65 x 65 u16 (same family, rare) | not examined yet |
| 5 | 4 | | |
| 6 / 7 | 64 / 16 | 2x2 corners, each four u32 IDs / four u8 weights | **WorldSky IDs and spatial blend weights**, bilinear per corner, duplicate IDs merged; see `sky_format.md` |
| 8 | 4225 | 65 x 65 u8 | |
| 9 | 2178 | 33 x 33 u16 | |
| 10 | 4 | | |
| 11 | 578 | 17 x 17 u16 | |
| 12 | 1 | | |
| 13 | 4624 | 17 x 17 BC2/DXT3 blocks, 16 B each; logical 65 x 65 texels | colour RGB + 4-bit alpha. Bytes 0..7 are sixteen alpha nibbles, 8..11 are RGB565 endpoints, 12..15 contain sixteen 2-bit indices. Alpha attribute meaning remains open. |
| 14, 17, 18, 19, 20, 31 | 2312 | 17 x 17 BC1/DXT1 blocks, 8 B each; logical 65 x 65 texels, padded to 68 x 68 | endpoints u16[0..1], pixel indices u32 at +4. Bit 17: base layer weights; bit 18: signed weight correction. 19/20 are the companion pair for 29. Roles of 14/31 in alternate paths remain open. |
| 16 | 4096 | 64 x 64 packed u8 | zone/terrain flags: `(v >> 3) & 3` selects a zone from bit 28; bit 0 is RoadMarch in NexusForever; bit 5 (`0x20`) suppresses clutter placement in the client |
| 21 | 1 | | always 0 |
| 22 | 16 | | |
| 23 | 16900 | 130 x 130 u8 | |
| 24 | 8 | | |
| 26 | 21316 | **73 x 73 x 4 u8** (RGBA, smoothness 0.02) | image like map, 73 = 72 + 1 samples (0.44 m); values mostly (0,0,0,0), also (0,255,255,0) |
| 27 | 4096 | 64 x 64 u8 = four 2-bit fields | **clutter preset selectors**, one per WorldLayer slot: `(v >> (2 * slot)) & 3` selects `worldClutterId00..03` |
| 28 | 16 | 4 x u32 | **zone ids** |

### Heightmap (bit 0) - verified
* 19 x 19 u16 (row major). `height [m] = raw / 8 - 2048` (same as NexusForever's `WritableMapFileCell`).
* A cell's own vertices are indices **1..17** (17 x 17, spacing 2 m = 32 m / 16); index 0 is the previous cell's last vertex, indices 17,18 repeat the
  **next** cell's vertices 1,2 and 0,1,2 (measured: `cell[x].h[:, 16:19] == cell[x+1].h[:, 0:3]` exactly in x and y).
  So a tile is a 257 x 257 vertex raster (+2). Raw values around 43000 (about +3330 m) appear as isolated plateaus (hole / sentinel marker?).
* WoW 3.3.5a ADT: 16 x 16 MCNK per tile with 9 x 9 + 8 x 8 height samples and 33.33 m chunks - a resample / re-tile is needed (WoW tile = 533.33 m).

## Open
* Bit 13 alpha attribute meaning, alternate-map roles of 14/15/19/20/29/30/31,
  blocks 6/7/8/9/11/22/23/24/26 and remaining flag bits of block 16.
* Native WoW conversion still omits colour tint/alpha attributes and exact
  WildStar shader material blending. Clutter placement is supported since dbg43
  through an in-memory MCLT extension; see `ground_clutter_dbg43.md`. Preserve original
  blocks for reader plugins; do not treat them as interchangeable alpha maps.

## Texture layers
* Bit 1 gives four WorldLayer IDs. `WorldLayer.csv` maps them to colour/normal
  texture paths, tiling, height/parallax parameters, projection, materialType,
  four clutter IDs, specular/emissive parameters and scrolling.
* Bit 17/18 is the main compressed 65x65 weight/correction pair. The former
  17x17-vertex interpretation was incorrect and caused striping in converted ADTs.

## Findings from the game client (Ghidra, WildStar64.exe, 2026-10-25)
* Loader: dispatcher `0x1402df540` (`aera` / `AERA`, chunks `CHNK`, `CURT`, `DHMO`, `PROp`), cell loop `FUN_1402df8a0` (info word = index delta << 24 | size24, max 256 cells),
  `AERA` variant `FUN_1402df720` (zlib cells), cell parser `FUN_1402e4ec0` (reads flags, then for every set bit a block whose size comes from the descriptor table).
* **Descriptor table at `0x140c4135c - 0x10`, 32 entries x 0x38 bytes** (copied into `tools/area_reader.py::CELL_BLOCK_DIMS`): per bit first / last sample index, bytes per sample and a link to
  further bits. Verified: all 32 block sizes of my table are reproduced exactly. New: the raster shapes (heightmap samples -1..17, colour like block 26 is 73 x 73 samples -4..68, block 6 = 2 x 32 B, block 7 = 2 x 8 B, block 24 = 2 x 2 B) and the links
  bit 2 -> 17, 18; bit 3 -> 13; bit 15 -> 14; bit 29 -> 19, 20; bit 30 -> 31 (a 65 x 65 map and its 17 x 17 companion blocks).
* **Terrain vertex shader** (`Shaders\LandVS.vs_4_0.sho`): vertex = `COLOR` (4 normalised bytes = x, z as u16 each, `/65535 * 32 m + cell origin`) + `TEXCOORD` (octahedral normal in 2 bytes + height u16 with
  `raw * 0.125 - 2048`). Confirms the height formula a third time.
* **Terrain pixel shader** (`LandPS`, 1537 permutations; `LandLowPS` for the far terrain samples one colour texture): per cell uv (0..1): `t3` layer colour, `t7` layer normal (the 4 `WorldLayer` ids of the cell),
  `t8` blend weights (rgb = weights of 3 layers, the 4th = 1 - sum), `t9` a **signed offset map in RGB565** that is added to `t8` (`value * (31/15, 63/31, 31/15) - 1`, so the RGB565 neutral point is `(15,31,15)` = `0x7BEF`), `t10` a colour map. Bit 18 is the confirmed signed correction; bit 13 is the colour attribute map.
* Subsequent CPU query evidence assigns bit 17/18 to weights/corrections and bit 13 to RGBA colour attributes; see the correction below.

## Blend weights: corrected decoding (dbg39)
* The descriptor sizes count **compressed 4x4 blocks**. A 65x65 texture occupies
  ceil(65/4)^2 = 17x17 blocks. It is not downsampled to 17x17 vertices.
* BC1 blocks contain two RGB565 endpoints plus sixteen 2-bit pixel selectors.
  Use the endpoint ordering to select four-colour or three-colour/transparent mode.
* Bit 17 supplies base weights RGB; bit 18 supplies signed RGB corrections:
  `w.rgb = base.rgb + correction.rgb * (31/15, 63/31, 31/15) - 1`.
  Then `w.a = 1 - sum(w.rgb)`; clamp each weight to [0,1], apply base alpha.
  The converter samples at the original 65x65 resolution before producing MCAL.
* Bit 2 links to 17/18; bit 29 links to 19/20. Bits 2/29 store uncompressed
  four-nibble authoring weights. The converter retains its existing raw-map
  priority and normalization, then falls back to BC1 pairs 19/20 or 17/18.
* Bit 3 -> 13 is a raw RGB565 map and a BC2 colour texture, not a signed
  correction texture. Earlier correlations of endpoint bytes were misleading.
* Evidence, remaining limitations, and conversion losses:
  [terrain_blocks_dbg39.md](terrain_blocks_dbg39.md).
