# Tree normal debug raster: decoder fault and separate layer-binding fault

The screenshot alone does not identify the exact tree instance. This investigation
checks three real pine assets and their textures, the current converter, and the
actual compiled M3 pixel shader. It does not claim a live before/after screenshot.

## Confirmed fault 1: JPEG TYPE2 channel packing

The old C++ and Python texture decoders both assumed a conventional ARGB plane
sequence for `jfmt=1`. That reference agreement hid a shared mistake.

Original `WildStar64.exe`, build 16042, x86:LE:64:

- `FUN_140299eb0` chooses the TYPE2 decode routines for header +0x24 == 1.
- `FUN_1402bf7d0` writes uncompressed BGRA as source planes `[2,1,3,0]`.
  Its first pixel is packed with the nested CONCAT expression that puts plane 0
  in the high byte, plane 3 in the red byte, plane 1 in green, and plane 2 in blue.
- `FUN_1402bfa80` uses the same arrangement in its BC3 output: alpha from plane 0;
  RGB565 red from plane 3, green from plane 1, blue from plane 2.

| Logical output | Old decoder | Native routine / correction |
|---|---|---|
| A | plane 0 | plane 0 |
| R | plane 1 | plane 3 |
| G | plane 2 | plane 1 |
| B | plane 3 | plane 2 |

ModelPS variant 1536 samples t4 then reconstructs XY from `.wy` (A/G). Variants
1152/1376/3456 also contain RG paths, so the older claim that every permutation
uses only A/G was too broad. Our current M3 shader uses A/G. The decoder correction
restores the expected A/G values for the investigated TYPE2 normal maps without
changing the shader's channel convention.

Real textures:

- `PRP_Tree_PointyPine_Canopy_000_Normal.tex`
- `PRP_Tree_PointyPine_Canopy_001_Normal.tex`

Before correction the median (A,G) is (127,0), after correction (127,126).
About 55% of level-0 texels had `x*x+y*y >= 1`, forcing the reconstructed tangent
Z to zero. After correction that fraction is 0%. These are full texture-level
statistics, not a measured percentage of visible leaf pixels in the screenshot.

Changes: `Model3/TexJpg.cpp` and the Python reference decoder. TYPE1/TYPE3 and
non-JPEG formats are unchanged. Cache version 11 invalidates old converted BLPs.
The debug file remains active; disabling debug is not the decoder fix.

## Confirmed fault 2: layered pine samples a color map as a normal

The actual converter emits the following for `PRP_Tree_PointyPine_000.m3`:

```text
shader = 0x88c0  (normal + layered)
texture combos = [0, 2, 0, 1, 3, 1]
textures 0/2 = color, textures 1/3 = normal
```

The stock setup puts color texture 2 on sampler 1. The layer texture hook binds
the actual normals on samplers 8..10. But `WildStarModelShader::Bind` still chooses
only shader variants 0..7, omitting bit 8 for WS_LAYERED. Its ordinary PS3 therefore
reads sampler 1 as a normal map. The two-texture vertex shader also supplies
weights/position/normal under a different TEXCOORD layout than ordinary PS3 expects.
This is a proven binding error for this pine, independent of the TYPE2 correction.

`PRP_Tree_AlgerocPointyPine_000.m3` has no vertex layer-weight stream. Its converted
batches are 0x8840 with normal pairs [2,3] / [0,1], so it demonstrates why the
layer fault alone cannot explain every pine-normal problem.

The concurrent shader implementation was left unchanged. Required follow-up:
select WS_LAYERED variants 9/11/13/15 from kLayered and match the vertex output
signature. Merely disabling normal debug would hide both problems.

## Geometry cross-check

The three examined pine models contain exact opposite-winding face pairs. Their
averaged normals match, rather than oppose. This alone does not establish z-fighting
as the cause of the colored raster; no geometry or culling changes were made.

## Validation and artifacts

- `tex_type2_cli`: independent distinct plane constants derived from the native
  routine, TYPE1/3 regression, and BLP channel preservation within BC3 quantization.
- Python decoder checked against the same independent constants, not just against
  the C++ implementation.
- Hidden D3D9 readback executes the actual embedded model PS3. Corrected flat
  normal: `ff7f80ff`; old layout: `ff7f007f`. The latter is a sideways normal.
- Two real normal maps decoded/compared; original non-TYPE2 canopy color BLP is
  byte-identical before/after.
- 15 character profiles, 105 option cycles, and original/native language tests pass.
- Portable package separation and all 19 original table checks pass.
- Release client build passes. Test executable and SHA256 are recorded in
  `build_m3test/tree_normal_probe/build.json`.

Evidence, original decompilation, shader disassembly, converted batches, images
and metrics are in `build_m3test/tree_normal_probe/`. GPU test source is
`tools/analysis/tree_normal_device_check.cpp`; geometry probe is
`tools/analysis/tree_surface_probe.py`.

The decoder fix is tested on the CPU and GPU. Whether the screenshot's fine raster
is fully gone requires a live comparison; layered trees retain the second fault.
