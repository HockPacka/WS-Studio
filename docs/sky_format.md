# WildStar XSKY v16: atmosphere and sky

Analysis of the extracted ClientData and the original `WildStar64.exe` (build 16042). Addresses refer to that original executable. Unknown fields remain raw rather than being assigned speculative names. Native client integration: [dbg47 atmosphere](sky_integration_dbg47.md), extended by [dbg49 sky models and cloud fields](sky_integration_dbg49.md).

## Coverage and evidence

The reader accepts all **1,290** local `.sky` files with **83,953 keys** and no structural bounds errors. [Validation report](sky_analysis/validation.json) records source hashes, references and warnings. [Resource report](sky_analysis/resource_links.json) checks WorldSky/CloudSet/CloudTrack joins and local resource availability.

Primary evidence: [loader/relocator FUN_1407d1000](sky_analysis/ghidra/FUN_1407d1000.c), [resource loader FUN_1407d24d0](sky_analysis/ghidra/FUN_1407d24d0.c), [runtime update FUN_1407d3560](sky_analysis/ghidra/FUN_1407d3560.c), [SH evaluation FUN_1407d3ff0](sky_analysis/ghidra/FUN_1407d3ff0.c), [resource key interpolation FUN_1407d5f20](sky_analysis/ghidra/FUN_1407d5f20.c).

## Binary primitives

All integers and floats are little endian. The fixed header is **0x4C0 bytes**. Magic is the byte sequence `YKSX` (LE integer 0x58534B59), followed by version 16.

`AP` is 16 bytes: `u32 count; u32 padding; u64 offset`. `Track` is 24 bytes: `u32 count; u32 padding; u64 timesOffset; u64 valuesOffset`. Strings are counted UTF-16LE. Top-level offsets use file position 0x4C0 as their base. Empty arrays have no required payload.

Nested arrays of Track descriptors use **align16(end of their descriptor array)** as their payload base. Model arrays and particulate string-descriptor arrays use the end of their entire array (already aligned), not the end of each element. Applying the top-level base everywhere yields plausible but incorrect data.

Times are u32 day seconds, normally 0..86400. Ordinary float tracks clamp endpoints and interpolate linearly. Resource IDs are not interpolated as numbers: the client selects two resources and a blend weight, including the last-to-first interval across midnight. Mixed parameter records require field-specific evaluation; the generic float helper is not a faithful evaluator for every record type.

## Header map

Names marked candidate need further tracing. Record widths and pointer structure are verified separately from semantic names.

| Offset | Layout | Meaning / confidence |
|---|---|---|
| 0x000 | u32, u32 | Magic, version |
| 0x008..0x017 | raw words; float at 0x10 | Header options, exact meaning open |
| 0x018 | AP string | Authoring XML path, not a runtime asset |
| 0x028, 0x0C0, 0x158, 0x1F0 | Four 0x98 groups | SH lighting, sky, fog, cloud groups; group order supported by native labels/output use |
| 0x288 | Track, 16-byte values | Ambient RGBA ([names](sky_field_semantics.md), medium) |
| 0x2A0 | Track, 32-byte values | SunDiffuse: elevation and azimuth in degrees, 2 spare floats, RGBA |
| 0x2B8 | Track, 16-byte values | SunSpecular RGBA (medium) |
| 0x2D0 | Track, 24-byte values | FogDistance: FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog |
| 0x2E8 | AP, 48-byte elements | Sky models: first 8 bytes raw, AP path at +8, Track32 at +24 |
| 0x2F8 | Track, 96-byte values | Screen: Sepia RGBA, Gray, White, Saturation, Contrast, Brightness, Gamma, Iris .. StarAdd, Bloom / god-ray values (22 used floats) |
| 0x310 | Track, u32 values | SkyCloudSet IDs, 0 means none |
| 0x328 | Track, float values | CloudAlpha (multiplier of cloud alpha; was read as u32) |
| 0x340 | AP of 16-byte string APs | Particulate resources: rain, dust, snow, etc. |
| 0x350 | AP string | Environment cubemap TEX |
| 0x360 | Track, 16-byte values | SunGlare colour RGBA |
| 0x378, 0x388 | AP string each | Sun-glare M3 resources |
| 0x398 | Track, 4-byte values | WindowGlow (float) |
| 0x3B0 | Track, 16-byte values | NightAmbient RGBA, added to the SH DC term (confirmed) |
| 0x3C8 | Track, 16-byte values | HorizonFogMod RGBA |
| 0x3E0 + 24*i, i=0..7 | Track, 32-byte values | LiquidColor0..7: two RGBA colours; i = `WorldWaterFog.skyColorIndex` |
| 0x4A0 | AP of Track8 | Wind spawns: key value = (`WindSpawn.tbl` id, `Wind.tbl` id) |
| 0x4B0 | AP string | Color grading LUT TEX |

Sky model references include suns, moons, stars, asteroid belts and authored skyboxes. They are additional geometry, not a replacement for the procedural sky color pass.

Each 0x98 group contains:

| Relative offset | Layout / value width | Interpretation |
|---|---|---|
| +0x00 | Two raw u32 | Flags/options, unresolved |
| +0x08 | AP of Track16 | Ambient RGBA contributions |
| +0x18 | AP of Track32 | Directional light: elevation/azimuth in degrees, two spare floats, RGBA |
| +0x28 | AP of Track48 | Two-colour hemisphere: direction, RGBA sky colour, RGBA ground colour |
| +0x38 | AP of Track48 | Cone source: direction, RGBA at value offset 4, cone angle in radians at offset 8 |
| +0x48 | AP of Track48 | Local source: direction, RGBA at offset 4, distance at offset 8, direction-vector scale at offset 9 |
| +0x58 | AP of Track108 | Explicit 27-float SH coefficients |
| +0x68 | Track108 | Direct 27-float SH coefficients |
| +0x80 | Track272 | 16-byte header followed by sixteen RGBA bands |

`FUN_1401af310` projects `+0x38` into nine SH coefficients per colour. Angles below `0.0001` use the directional projection; otherwise the angular result is divided by `sin(min(angle, 1))²`. `FUN_1401af740` handles `+0x48`: it scales and normalizes the direction vector, uses `acos(distance / length)` when `distance < length`, and otherwise uses an angle of `1` radian. Unlike cones, local-source colours receive no cone normalization. Both paths are implemented in the native reader and checked against an independent reference, including real local-source tracks and synthetic boundary cases.

The 272-byte record is confirmed by [FUN_1407d9700](sky_analysis/ghidra/FUN_1407d9700.c): it interpolates two header floats and sixteen vec4 colors. The other two header slots remain unresolved. Its relationship to the indexed sky bands is supported by shader bytecode; preserve the raw record for further work.

## Assignment to world cells

AREA block 6 is **four corners × four u32 WorldSky IDs** (64 bytes). Block 7 is **four corners × four UNORM8 weights** (16 bytes). It is not an 8×8 byte map. [FUN_1402da040](sky_analysis/ghidra/FUN_1402da040.c) bilinearly weights the corners, merges repeated IDs and retains up to four dominant contributions. [FUN_140356560](sky_analysis/ghidra/FUN_140356560.c) loads and normalizes surviving sky contributions, with a fallback if needed.

`WorldSky.ID → assetPath → .sky`; `Track0x310 → SkyCloudSet → SkyTrackCloudSet → cloud M3 resources`. WorldSky has 886 local rows. Cloud table reports include the ID-0 sentinel row. No unresolved nonzero cloud IDs or cloud-track joins were found.

For the inspected Western.393b / WoW tile (4,6), the cell-center contributions use **ID 14, Ellevar_Main_005.sky**, and **ID 16, Ellevar_SZ_CreepyForest_001.sky**. Across 256 cell centers, their accumulated weights are 164.1941 and 91.8059. The result therefore needs spatial sky blending as well as day-time interpolation.

## Source anomalies and missing assets

Three authored files contain unsorted or out-of-day times: `NorthernWilds_Main.sky`, `WhiteVale_Main.sky`, `WhiteVale_Main02.sky`. Values include 60 after 69960, and 99960 before 86400. They are retained and reported; helper sampling rejects unsorted tracks rather than silently changing original data.

The local resource audit finds 102 missing reference occurrences (37 distinct raw path spellings). These are absent from the extracted local tree; that does not establish absence from the original game archives. See the report for owners and paths.

Among resolved environment/LUT TEX resources there are **147 cubemaps with six faces** and **54 3D LUTs with depth 16**. They require dedicated texture loading; ordinary 2D TEX-to-BLP conversion loses essential dimensions.

## WildStar extended-view profile

`WS_` maps default to a 2,400-yard far clip instead of WoW's 1,583.33-yard ceiling. The near clip rises gradually from 0.2 to 0.35 beyond the ordinary ceiling, and the existing low-detail horizon projection uses a scale of at least 4 (user setting, capped at 6). Ordinary WoW maps retain their original validation and near clip.

`wildstarFarClip` selects the WildStar distance from 183.33 through 3,000 yards; `0` disables the complete extension at runtime and restores WoW clipping and authored fog. `wildstarFogScale` ranges effectively from 1 through 6 and defaults to 3. Fog extends towards 90 percent of the selected far clip while retaining the authored start/end ratio. It never shortens an authored fog end that is already more distant. With the default 700-WildStar-metre example, the 2,400-yard profile produces a 2,160-yard fog end.

The math is isolated in `Area3/ViewProfile.cpp`; `sky_cli` checks clipping bounds, near/horizon scaling and fog edge cases. Visual quality and frame time still require an in-game comparison because terrain streaming cost grows with the visible area.

## Reproduce

From the project root:

```powershell
python tools/sky_reader.py --check WoWClient/ClientData/Sky build_m3test/sky/validation
python tools/sky_reader.py WoWClient/ClientData/Sky/Ellevar_Main_005.sky build_m3test/sky/Ellevar_Main_005.json
python tools/analysis/sky_reader_check.py
python tools/analysis/sky_link_check.py build_m3test/sky/validation
python tools/analysis/sky_shader_audit.py build_m3test/sky/shader_audit
```

The raw reader is `tools/sky_reader.py`; shader container reader is `tools/sho_reader.py`. The companion [shader assignment](sky_shader_mapping.md) identifies the renderer passes and the remaining integration work.
