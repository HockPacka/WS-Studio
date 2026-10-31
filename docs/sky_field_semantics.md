# SKY top-level fields: names and meaning

Resolves the fields that [sky_format.md](sky_format.md) listed as unnamed (0x288, 0x2D0, 0x2F8, 0x328, 0x360, 0x398, 0x3B0, 0x3C8, 0x3E0, 0x4A0) and the three light tracks next to them.
Sources: `WildStar64.exe` build 16042 (Ghidra), the 1288 local `.sky` files, and the game tables in `WoWClient/tables_csv`. `tools/sky_reader.py` now labels these tracks (`name` / `components` per track, `wind_pairs` for 0x4A0).

## Where the names come from

The executable holds the XML tag names of the sky authoring format as UTF-16 strings (0x140b54200 ..). The relevant order is

`Sky, LightingSH, SkySH, FogSH, Clouds, Cloud, Particulate, Sunglare, WindowGlow, NightAmbient, HorizonFogMod, LiquidColor0..7, CloudAlpha, CloudSH, Ambient, Directional, ... SunDiffuse, SunSpecular, Skybox, WaterFog, FogDistance, Screen, Gradient, Band, FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog, SepiaR/G/B/A, Gray, White, Saturation, Contrast, Brightness, Gamma, Key, EnvMap, Wind, ColorCorrection, ... r0 g0 b0 a0 r1 g1 b1 a1, ... Iris, LuminanceMin, StarBright, StarAttenuation, StarAdd, BloomBright, BloomAdd, BloomExp, Decay, Weight, Exposure, Alpha, Index, Priority, r0, g0, id, WindSpawnId, Wind`

The assignment below combines this list with the track layouts (the per-frame evaluator `FUN_1407d3560` and its interpolators `FUN_1407d8350 / 8590 / 88c0 / 8b00 / 8f40 / 140309410 / 1407d13d0`), the value statistics over all files, and table joins.

## Fields

| Offset | Name | Layout (floats per key) | Confidence | Evidence |
|---|---|---|---|---|
| 0x288 | Ambient | RGBA, a = 1 | medium | RGBA track, 1095 files, dark colours (mean 0.3); tag order `Ambient, SunDiffuse, SunSpecular` |
| 0x2A0 | SunDiffuse | elevation deg (-90..90), azimuth deg (0..360), 2 x 0, RGBA | medium-high | interpolator copies floats 0,1 and 4..7; angles only here; light colour follows the day (blue at night) |
| 0x2B8 | SunSpecular | RGBA | medium | only 8 files, black or grey; third light track |
| 0x2D0 | FogDistance | FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog | high for the layout, medium for the order | six floats; [0] -937..1 and [1] 145..1800 are distances, [4] 0..0.5 and [5] 0..1 are fractions; the empty-track default fills [0], [1], [4], [5] from quality tables; tag order |
| 0x2F8 | Screen | 22 interpolated floats + 2 spare, see below | high for the layout | the evaluator copies exactly floats 0..21; indices 4, 5, 10..14 are not interpolated and are 0 in all files |
| 0x310 | CloudSetId | u32 id into `SkyCloudSet.tbl` | high | already used by the client (dbg49) |
| 0x328 | CloudAlpha | float | medium-high | its blended value (manager field +0x1640, same default table 0x140c56100) multiplies the alpha of every cloud instance in `FUN_1407c4fc0`; the reader treated it as u32 (identical for 0, only one local file authors it: Flux_Dark = 0) |
| 0x360 | SunGlare | RGBA | medium | tag order `Sunglare` (with `File` 0x378 / `File2` 0x388 = glare M3 files); orange at sunrise, grey at night |
| 0x398 | WindowGlow | float, 0 or 1 in all 77 files | medium | tag order; looks like an on/off level for lit windows at night |
| 0x3B0 | NightAmbient | RGBA | high | blended value is added to the SH DC term: `ambient += value * 3.5449078` (= 1 / 0.2820948) in `FUN_1407c4fc0` |
| 0x3C8 | HorizonFogMod | RGBA | medium | tag order; the empty-track default differs from the other colours (`0x140c777f0` vs `0x140c777d0`, multiplier-like) |
| 0x3E0 + 24 i | LiquidColor0..7 | color0 RGBA, color1 RGBA (default white) | high for the index | `WorldWaterFog.skyColorIndex` takes the values 0..7 and selects the track; tag `r0 g0 b0 a0 r1 g1 b1 a1` |
| 0x4A0 | WindSpawn | array of tracks; key value = (WindSpawn.tbl id, Wind.tbl id) | high | 1030 of 1030 pairs: first value is a `WindSpawn.tbl` id (or 0), second a `Wind.tbl` id (or 0); tags `WindSpawnId`, `Wind` |

### 0x2F8 Screen (index -> name)

| Index | Name | Note |
|---|---|---|
| 0..3 | SepiaR, SepiaG, SepiaB, SepiaA | neutral (0.502, 0.502, 0.502, 1) is common |
| 4, 5 | Gray, White | not interpolated, 0 everywhere |
| 6..9 | Saturation, Contrast, Brightness, Gamma | ranges 0..2, 0.7..1.05, 0.125..2, 0.1..3, mean about 1 |
| 10..14 | Iris, LuminanceMin, StarBright, StarAttenuation, StarAdd | not interpolated, 0 everywhere (unused star / eye adaptation) |
| 15..21 | BloomBright, BloomAdd, BloomExp, Decay, Weight, Exposure, Alpha | order-based assignment; `Decay` (index 18) is 0.94..0.99 in the files, as expected for a radial blur decay |
| 22, 23 | - | always 0 |

Indices 15..21 are the least certain part: the group and the order are supported, the exact slot of each name is an inference from the tag order and the value ranges.

## What stays open

* 0x288 versus 0x2B8 versus 0x360 are assigned from tag order and value profile, not from a consumer that was read. Which shader constant receives them is not traced.
* The unused Screen slots (Iris, LuminanceMin, Star*) have no authored data locally, so their meaning cannot be checked.
* The per-feature weight table of the sky manager (`FUN_1407c4fc0`, offsets 0x864 / 0x8D8 / 0x94C and 0x9C0 / 0xA34 / 0xAA8 in three slots of 0x74 bytes) was only partly mapped; parameter index k = 16, 17, 18, 19..26 line up with 0x398, 0x3B0, 0x3C8, LiquidColor0..7.
* The native C++ reader (`Area3/Sky.cpp`) still reads only the fields the renderer uses; the new names are in the Python reader.

## Joins found along the way

* `WorldWaterFog.skyColorIndex` (0..7) -> `LiquidColorN` of the active sky.
* `WindSpawn.tbl` (interval and direction range of a gust) and `Wind.tbl` (duration, radius, speed, sine magnitude / frequency) are the targets of 0x4A0.
