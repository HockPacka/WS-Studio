# WildStar World & Environment Format Specifications (.dgn, .sky, .area)
**Decompiled from `WildStar64.exe` (`FUN_1402d5650`, `FUN_1407d1000`, `FUN_1402e4ec0`)**

---

## 1. Dungeon / Map Environment Definition (.dgn)
Function: `FUN_1402d5650`

| Offset | Type | Field | Description |
|---|---|---|---|
| `0x00` | `uint32` | `magic` | `'NGND'` (`0x444E474E`, little-endian "DNGN") |
| `0x04` | `uint32` | `version` | Always `6` |
| `0x08` | `uint32` | `name_chars` | Dungeon / Map name length (UTF-16 code units) |
| `0x10` | `uint64` | `name_offset` | Offset to UTF-16 dungeon name string |
| `0x18` | `uint32` | `zone_chars` | Zone identifier string length |
| `0x20` | `uint64` | `zone_offset` | Offset to UTF-16 zone identifier string |
| `0x28` | `uint32` | `sky_chars` | Default sky profile name length |
| `0x30` | `uint64` | `sky_offset` | Offset to UTF-16 sky profile name (e.g. `.sky` reference) |
| `0x38` | `uint64` | `sector_count`| Number of sector references / portals (`FUN_1402ca6c0`) |

---

## 2. Sky & Weather Profile (.sky)
Function: `FUN_1407d1000`

| Offset | Type | Field | Description |
|---|---|---|---|
| `0x00` | `uint32` | `magic` | `'YKSX'` (`0x58534B59`, little-endian "XSKY") |
| `0x04` | `uint32` | `version` | Always `16` (`0x10`) |
| `0x08` | `uint64` | `sky_model` | Skydome model (`.m3`) reference string |
| `0x30` | `track` | `sun_color` | Sun directional light color timeline |
| `0x56` | `track` | `ambient_color`| Ambient light color timeline |
| `0x7C` | `track` | `fog_color` | Distance fog color timeline |
| `0xA2` | `track` | `fog_range` | Fog start and end distance timeline |
| `0xB4` | `track` | `cloud_density`| Cloud layer density / scrolling speed timeline |
| `0xC4` | `uint32` | `layer_count` | Number of sky atmosphere layers |
| `0xC6` | `uint64` | `layer_offset`| Atmosphere layer property table |

---

## 3. Terrain Grid Tile (.area)
Functions: `FUN_1402e4ec0`, `FUN_1402e3010`, `FUN_1402e5720`, `FUN_1402e59b0`, `FUN_1402e5860`

Each `.area` tile covers $512 \times 512$ meters partitioned into $16 \times 16$ cells of $32 \times 32$ meters each.

### Cell Structure
* **Raster Block Bitmask (32 bits)**:
  * Table `0x140c4135c`: 32 physical storage descriptors with varying resolutions (17x17, 33x33, 65x65) encoding heightmaps, normals, layer blending weights, and hole masks.
* **Subchunk Streams**:
  * `'PORP'` (`FUN_1402e3010`): Static world prop instance placements (`.m3` model references, matrices, scaling).
  * `'GtAW'` (`FUN_1402e5720`): Water bodies (80-byte header, 4-byte index buffer, 72-byte water vertex buffer).
  * `'Druc'` (`FUN_1402e59b0`): Procedural clutter/foliage (count, array of 12-byte float XYZ instance positions).
  * `'Psbw'` (`FUN_1402e5860`): Ambient sound emitters and reverb zones.
