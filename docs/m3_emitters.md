# WildStar .m3 – Effect Emitters (Header Array `0x2F8`) & WoW 3.3.5a M2 Cross-Compilation

Parser: `wowdecomp/Engine/Source/Model3/M3Reader.cpp`, Converter: `wowdecomp/Engine/Source/Model3/M3ToM2.cpp`, Engine Runtime: `wowdecomp/Engine/Source/Services/ParticleSystem2.cpp`.
Result over all 34,733 models: **5,023 models, 41,036 emitters (38,465 particle, 2,571 ribbon); 41,013 (99.94 %) parse with the structure below**, bone index in range for 100 %, texture ids valid for 81,014 of 81,016.

---

## 1. Emitter Element (`0xA0` bytes, count = header `0x2F8`)
| Offset | Type | Meaning |
|---|---|---|
| `0x00` | `u16` (`+0xFFFF`) | **bone index** (index into the bone array; 100 % in range) |
| `0x04` | `u32` | **type**: `0` = particle emitter, `1` = ribbon emitter |
| `0x08` | `u32` | **coordSpaceMode**: `0` = local/bone, `1` = model, `2` = world |
| `0x0C` | `u32` | **litFlag**: `0` = unlit, `!=0` = lit |
| `0x14` | `u32` | **shaderMode** |
| `0x1C` | `u32` | **blendMode**: `0` = alpha blend, `1` = opaque, `2` = additive, `3` = mod/screen |
| `0x20` | inline | `u64 count (=1)`, `u32 time`, `u32 value`, `u64 extra` – inline constant |
| `0x30` | `u32` | **noDepthTest** |
| `0x34` | `u16` | **forceFieldMask** |
| `0x38` | `DP` | animated track (`u32` ms keys, `f32` opacity multiplier values) |
| `0x50` | `DP` | animated track (`u32` ms keys, **`u8` visibility/enable values**, count 1..45) |
| `0x68/0x6C` | `u32` | flags |
| `0x70..0x88` | `7 x f32` | `30.0` (91 %), `0.925`, `0.9`, flag, `0.925`, `0.9`, `1.0` – damping/time-scale block |
| `0x90` | `u64` | offset of the **particle template** (`type == 0`), `0xFFFFFFFFFFFFFFFF` for `type == 1` |
| `0x98` | `u64` | offset of the **ribbon template** (`type == 1`), `0xFFFFFFFFFFFFFFFF` for `type == 0` |

Nested offsets are relative to `eb = align16(end of the 0xA0 array)`.

---

## 2. Template Struct & Nested Base Offsets (Ghidra-verified in `FUN_14030c6a0`)
* **CRITICAL GHIDRA CORRECTION (`FUN_14030c6a0` at `0x14030c725` and `0x14030c746`)**:
  * **Particle template (`type == 0`, `FUN_14030bcc0`)**: On-disk size is **`0xED0` bytes** (`nb = t0 + 0xED0`). Previously assumed `0xFF0` was the runtime-expanded instance size (`+0x120` bytes larger), which shifted all DPs by 9 slots whenever a spawn shape sub-struct (`Line`, `Rect`, `Box`, `Cylinder`, `Sphere`) was present at `nb + 0`.
  * **Ribbon template (`type == 1`, `FUN_14030c3d0`)**: On-disk size is **`0x4B0` bytes** (`nb = t0 + 0x4B0`).
* In every 24-byte (`0x18`) DP descriptor inside an `.m3` template:
  * `+0x00`: `uint32_t count` (number of keys)
  * `+0x04`: `uint32_t flags` (interpolation/track flags, **not** the upper 32 bits of count)
  * `+0x08`: `uint64_t keyOffset` (relative to `nb`)
  * `+0x10`: `uint64_t valOffset` (relative to `nb`)

### Spawn Shape Sub-Structures at `t0 + 0x08` (`FUN_14030ba20`, `FUN_140317970`)
`uint16_t shape` at `t0 + 0x08` selects the spawn volume geometry, whose nested sub-struct is pointed to by `t0 + 0x20..0x60` (relative to `nb = t0 + 0xED0`, with internal DPs relative to `sub_base = nb + shOff + sub_struct_size`):

| `shape` (`t0 + 0x08`) | Pointer at | Sub-struct size | Internal DPs & Meaning |
|---|---|---|---|
| `0` (Point) | — | — | Emits from `(0,0,0)` |
| `1` (Line) | `t0 + 0x28` (count `@+0x20`) | `0x0C * count` | Array of 12-byte (`3 x float`) line/polyline points |
| `2` (Disk) | `t0 + 0x30` | `0x30` | Radius DP (`f16`) |
| `3` (Rect / Plane) | `t0 + 0x38` | `0x30` | `+0x00`: half-width X (`f16`), `+0x18`: half-length Z (`f16`) |
| `4` (Box) | `t0 + 0x40` | `0x50` | `+0x00`: half-X (`f16`), `+0x18`: half-Y (`f16`), `+0x30`: half-Z (`f16`) |
| `5` (Cylinder) | `t0 + 0x48` | `0x60` | `+0x00`: outer radius (`f16`), `+0x18`: height (`f16`), `+0x30`: inner radius (`f16`) |
| `6` (Sphere) | `t0 + 0x50` | `0x30` | `+0x00`: outer radius (`f16`), `+0x18`: inner radius (`f16`) |
| `8..11` (Mesh) | `t0 + 0x58` | `0x40` | Emits from model mesh surface |
| `12` (Spline) | `t0 + 0x60` | `0x90` | Emits along spline curve |

### Complete 23 Single Properties (`k = 0..22`, `t0 + 0x68 + 0x18 * k`, Ghidra `FUN_140313c20` & `FUN_1403141f0`)
| `k` | Template Offset | On-Disk Type | Meaning |
|---|---|---|---|
| `0` | `+0x068` | `S2` (`uint16_t`) | **spawnCountMin** (particles spawned per burst/interval) |
| `1` | `+0x080` | `S2` (`uint16_t`) | **spawnCountMax** |
| `2` | `+0x098` | `S4` (`int32_t`) | **intervalMin** in milliseconds (`<= 0` = one-shot burst) |
| `3` | `+0x0B0` | `S4` (`int32_t`) | **intervalMax** in milliseconds |
| `4` | `+0x0C8` | `S2` (`f16`) | **activeWindowMin** (emitter active window start) |
| `5` | `+0x0E0` | `S2` (`f16`) | **activeWindowMax** (emitter active window end) |
| `6` | `+0x0F8` | `S4` (`int32_t`) | **lifeMin** in milliseconds |
| `7` | `+0x110` | `S4` (`int32_t`) | **lifeMax** in milliseconds |
| `8` | `+0x128` | `S6` (`3 x f16`) | **dirMin** (initial velocity direction vector min, WildStar Y-up) |
| `9` | `+0x140` | `S6` (`3 x f16`) | **dirMax** (initial velocity direction vector max, WildStar Y-up) |
| `10` | `+0x158` | `S2` (`f16`) | **speedMin** (initial scalar speed multiplier in m/s) |
| `11` | `+0x170` | `S2` (`f16`) | **speedMax** |
| `12` | `+0x188` | `S6` (`3 x f16`) | **accel** (world/local acceleration vector `(ax, ay, az)`, gravity on Y) |
| `13` | `+0x1A0` | `S2` (`f16`) | **spinMin** (initial particle rotation angle min, radians) |
| `14` | `+0x1B8` | `S2` (`f16`) | **spinMax** |
| `15` | `+0x1D0` | `S2` (`f16`) | **spinSpeedMin** (angular velocity min, rad/s) |
| `16` | `+0x1E8` | `S2` (`f16`) | **spinSpeedMax** |
| `17` | `+0x200` | `S2` (`f16`) | **yawMin** (3D tumble/yaw min) |
| `18` | `+0x218` | `S2` (`f16`) | **yawMax** |
| `19` | `+0x230` | `S2` (`f16`) | **scaleMin** (initial particle size multiplier min) |
| `20` | `+0x248` | `S2` (`f16`) | **scaleMax** |
| `21` | `+0x260` | `S4` (`int32_t`) | **maxParticles** (capacity, default 40) |
| `22` | `+0x278` | `S12` (`3 x float`) | **localOffset** (emitter translation offset, active when `templateFlags & 2`) |

### Lifetime Gradients (`FUN_140313c20` & `ParticleGPUVS.vs_4_0`)
Each gradient group has a `uint16_t` stop count (`<= 5`), up to 5 value DPs, and up to 5 `uint8_t` position DPs (`0..255` = `0..100 %` of particle life), sorted chronologically by position:

| Group | Count `u16` at | Values at (stride `0x18`) | Positions at | Role |
|---|---|---|---|---|
| **colorStops** | `+0x294` | `+0x298` (`S4` RGBA8, 2 channels: 2nd at `+0x310`) | `+0x388` (`S1`) | RGB color over lifetime (`+0x290` float is `colorGain`) |
| **alphaStops** | `+0x400` | `+0x408` (`S1` `u8`) | `+0x480` (`S1`) | Opacity (`0..255`) over lifetime |
| **sizeStops** | `+0x4F8` | `+0x500` (`S2` `f16`) | `+0x578` (`S1`) | Uniform size multiplier over lifetime |
| **velScaleStops** | `+0x5F0` | `+0x5F8` (`S2` `f16`) | `+0x670` (`S1`) | Velocity scale / second extent over lifetime |
| **quadPivot** | `+0x6E8` | `+0x6F0` (`S4` `2 x f16`) | `+0x768` (`S1`) | Custom billboard anchor when `templateFlags & 8` |
| **stretchStops** | `+0x86C` | `+0x870` (`S2` `f16`) | `+0x8E8` (`S1`) | Velocity-aligned stretch/length multiplier |
| **layer2 UV (`G/H/I/J/K`)** | `+0x99C..+0xD78` | `+0x9A0..+0xD80` (`S2`) | `+0xA18..+0xDF8` (`S1`) | Secondary texture UV scroll/rotation/scale |

### Flipbook Grid, Flags & 3D Child Model (`t0 + 0xE78..0xEC8`, Ghidra `FUN_1403135b0` & `FUN_140316eb0`)
| Template Offset | Type | Meaning |
|---|---|---|
| `+0x978` | `int16_t` | Primary sprite texture index into `Model::textures` |
| `+0x994`, `+0x996`, `+0x99A` | `int16_t` | Secondary multi-texture layer indices (mask / distortion / ramp) |
| `+0xE78` | `uint32_t` | **flipbookCols** (UV atlas columns) |
| `+0xE7C` | `uint32_t` | **flipbookRows** (UV atlas rows) |
| `+0xE88` | `uint32_t` | **flipbookFrames** (number of active cells in atlas) |
| `+0xE8C` | `float` | **flipbookSpeed** (playback speed multiplier) |
| `+0xEB8` | `uint64_t` | **childModelLen** (UTF-16 character count for 3D mesh particle model) |
| `+0xEC0` | `uint64_t` | **childModelOff** (offset to UTF-16 string relative to `nb = t0 + 0xED0`) |
| `+0xEC8` | `uint32_t` | **templateFlags**: bit 0 (`0x01`) = radial velocity from shape center, bit 1 (`0x02`) = use `localOffset` (`k=22`), bit 3 (`0x08`) = custom quad pivot (`+0x6E8`), bit 7 (`0x80`) = velocity-aligned tail stretch |

### Ribbon Template (`type == 1`, `nb = t0 + 0x4B0`, Ghidra `FUN_14030c3d0`)
| Template Offset | Type | Meaning |
|---|---|---|
| `+0x000` | `uint8_t` | **mode** (`0` = time-based trail, `1` = bone-chain strip) |
| `+0x002` | `uint16_t` | **segmentIntervalMs** (spawn interval per ribbon edge in ms) |
| `+0x026` | `uint16_t` | **edgeLifetimeMs** (lifetime of each ribbon segment in ms) |
| `+0x028` | `uint32_t` | **templateFlags** |
| `+0x030` | `DP (S6)` | **accel** (`3 x f16` gravity/acceleration vector) |
| `+0x044` | `float` | **colorGain** (HDR multiplier) |
| `+0x048` / `+0x050` / `+0x140` | `u16` + `5x S4` + `5x S1` | **colorStops** (up to 5 RGBA8 stops + `u8` lifetime positions) |
| `+0x1B8` / `+0x1C0` / `+0x238` | `u16` + `5x S1` + `5x S1` | **alphaStops** (up to 5 `u8` alpha stops + `u8` lifetime positions) |
| `+0x2B0` / `+0x2B8` / `+0x330` | `u16` + `5x S2` + `5x S1` | **widthStops** (up to 5 `f16` ribbon width stops + `u8` lifetime positions) |
| `+0x3C4` | `int16_t` | **texture** index into `Model::textures` |

---

## 3. Cross-Compilation M3 -> WoW 3.3.5a M2 & Information Loss Matrix (`M3ToM2.cpp`)

| WildStar `.m3` Emitter Feature | WoW 3.3.5a `.m2` Representation (`M2Particle` / `M2Ribbon`) | Conversion Fidelity & Lost Information |
|---|---|---|
| **Pure FX Models (0 vertices / 0 meshes)** | Synthesized 3-vertex zero-area triangle at `(0,0,0)` + expanded bounding box around all emitter/ribbon bones | **100% Functional** (bypasses WoW `CM2Shared` empty-skin rejection and frustum culling) |
| **Spawn Shapes** (`Point`, `Line`, `Rect`, `Box`, `Cylinder`, `Sphere`, `Mesh`, `Spline`) | Mapped to `CPlaneParticleEmitter` (`type 1`) and `CSphereParticleEmitter` (`type 2`) with `emissionAreaX`, `emissionAreaY`, `zSource` | **Partial Loss**: WoW 3.3.5a lacks native `Box`, `Cylinder`, and `Mesh surface` emitters; `Box` maps to `Plane`, `Cylinder`/`Sphere` map to `Sphere` inner/outer radius |
| **Lifetime Gradients** (`colorStops`, `alphaStops`, `sizeStops`, up to 5 stops at `0..255`) | Converted to `M2ParticlePartTrack` (`colorTrack`, `alphaTrack`, `scaleTrack`) with exact `0..0x7FFF` timestamps | **Lossless for Channel 0**: Second per-particle random color channel (`+0x310`, `lerp(color0, color1, rand)`) is collapsed to Channel 0 because M2 has a single color track |
| **Velocity Scale / Drag (`velScaleStops`) & Stretch (`stretchStops`)** | Mapped to M2 `drag` (`+0x174`), `tailLength` (`+0x15C`), and `0x40000` tail quad flag | **Approximated**: M2 uses a constant scalar `drag` and `tailLength` rather than a 5-stop lifetime curve |
| **Flipbook UV Grids (`flipbookCols`, `flipbookRows`, `flipbookFrames`)** | Mapped to `rows` (`+0x30`), `cols` (`+0x32`), and `headCellTrack`/`tailCellTrack` (`+0x13C`/`+0x14C`); `CParticleEmitter2` extended to allow non-power-of-two grids | **100% Functional in Client**: Standard WoW 3.3.5a rejected non-PoT `rows`/`cols`; `ParticleSystem2.cpp` was extended to support arbitrary grid dimensions |
| **3D Child Particle Models (`childModel`)** | Written to `M2Particle::m_modelFileName` (`+0x18`, `.m3` -> `.m2`); fixed `CParticleEmitter2::PlaceParticleModels` bug in `ParticleSystem2.cpp` | **100% Functional in Client** |
| **Multi-Texture Layers (`+0x994`, `+0x996`, `+0x99A`) & UV Transform (`G/H/I/J`)** | Only primary texture (`+0x978`) is bound | **Lost in Standard M2**: M2 particles only bind 1 texture per emitter unless multi-tex flags are custom-wired |
| **Ribbon Emitters (`type == 1`)** | Converted to `H_RIBBONS` (`0xB0` bytes) + dedicated two-sided material in `H_MATERIALS` | **High Fidelity**: `M2Ribbon` uses emitter-time tracks rather than per-segment lifetime gradients, so peak alpha/width and initial color from the `.m3` ribbon stops are used |
