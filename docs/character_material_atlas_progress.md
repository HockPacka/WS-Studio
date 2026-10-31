# Character texture integration — native data and atlas work

Scope: native M3 character composition, separate from the renderer changes being
developed concurrently. The source tree contains both changes. This document
records the tested atlas/reader work without claiming that every original shader
permutation has been reproduced.

Test snapshot: `WoWClient/WowClient64_CharacterTextures_test.exe`.
SHA256: `e5aa43a1558c34e27653ff0dc7924604e9599bef4587c8312c794327dfd5f11a`.
This distinct filename leaves the concurrent agent's numbered dbg builds alone.

## Implemented in order

1. **Color and coverage**: retain region layout, component priority and native
   `skinMaskMap` compositing. Trace the actual region files loaded. Missing
   declared masks that do not decode now produce an error rather than silently
   painting opaque. Absent region candidates are reported; an absent mask keeps
   the existing white/default behavior. Character coverage remains opaque; source
   color alpha is not used as body transparency.
2. **Normal atlas**: build the normal map from `skinNormalMap` region files using
   the same UV layout, priorities and coverage masks. Preserve all four channels,
   especially A/G for the shader's DXT5nm decoding. Regions without normal data
   have a flat normal default. Body and attached parts reference this generated
   atlas instead of nonexistent logical whole-map filenames.
3. **Skin dye**: read `skinDyeMap`, `itemColorSetId`, `ItemColorSet` and
   `DyeColorRamp`. Resolve channel 0 to a native skin-ramp row. A dye-only component
   with no color map uses the native black default, then applies the ramp. This
   fixes otherwise omitted dyed hair layers. Disabled/missing color sets do not
   invent a color. Source byte-space blending is implemented; a renderer comparison
   is still needed to verify the original color-space and filtering behavior.
4. **Additional material layers**: keep four indexed slots and `layerCount`, texture
   indices, five source-mode words, class/type, original 0x128 bytes and all ten
   known parameter tracks, including keys. The unresolved +0x90 descriptor stays
   raw. Remap every layer's texture indices when attaching head/hair/ear meshes.
   Keep `color`/`normal` field names for the concurrent renderer's layer slots.
5. **SkinFX inventory**: 467 files under `Art/Character` reference 481 color and
   481 normal textures, zero textures of type 2. There are 710 one-layer and 32
   two-layer materials. Of the 24 models containing two-layer materials, only
   `Aurin/Female/Cine_Aurin_Tree01.m3` uses different texture pairs in its layers.
   The other materials reuse their first color/normal pair. This does not prove
   that SkinFX is absent elsewhere in the game.
   All 312 absent direct texture filenames belong to native replacement slots
   1/2. No fixed character-M3 texture reference is missing from this inventory.
6. **Gloss/glow masks**: the normal atlas preserves the R/B channels as well as A/G;
   the reader retains every layer's gloss/glow modes and tracks. Exact source-mode
   to shader-channel mapping remains open. This work does not replace it with a
   guessed mask or claim full weighted four-layer rendering.

Race=0 customization rows are additionally filtered by their character asset
family. Mordesh cybernetics must not become generic Chua/Human options. The
documented Mordesh reuse of Human assets remains allowed.

Generated texture namespace: `characteratlas/v4_<race>_<sex>_<7 choices>_{color,normal}`.
Content cache version: 10. Source files and server databases are not modified.

## Original-engine evidence

`ComponentPS.ps_4_0.sho`, variants 3/9:

```text
shade = dye.red - 0.5/255
U = shade * (255 / rampWidth)
V = (rampIndex + 0.5) / rampHeight
if shade >= 0 and V > 1/rampHeight:
    result.rgb = lerp(color.rgb, ramp(U,V).rgb, dye.green)
```

For 8-bit input and the 256-wide skin ramp the sampled texel is exactly
`redByte-1`. Row 0 is disabled by the threshold. Alpha is unchanged by dye.

Ghidra, `WildStar64.exe` build 16042, x86:LE:64:

- `FUN_1401dc490`: loads the original skin and armor ramps.
- `FUN_1401dce80`: skin U scale 255/width; armor U scale 85/width; V step and half texel.
- `FUN_1401dc0d0`: resolves three DyeColorRamp indices and packs 10-bit rows.
- `FUN_1401e5bc0`: constructs CB0 row positions/differences and row threshold.
- `FUN_1401dcd30`: initializes the default white mask and opaque black color.

Saved decompilation evidence: `build_m3test/component_shader/cpu_component_evidence.json`.

## Validation

- `character_runtime_check.py`: 15 profiles, 105 individual option cycles;
  generated color and normal BLPs decode, match dimensions, retain opaque color
  alpha and varying normal A/G data. Includes original/native language regression.
- `character_texture_audit.py`: 15 initial profiles plus option cycles, actual
  source-path trace. Counts are profile/display/region occurrences, not a claim
  that every Cartesian appearance combination or every source file was covered.
- `character_material_inventory.py`: independent raw M3 inventory over 467 models.
- `material_reader_cli Art/Character`: 467 models, 742 materials, 774 layers,
  319 nonempty known parameter tracks, no rejected character models.
- Dye golden cases check no-dye red=0, disabled row=0, green=0, full/partial dye,
  exact red-byte shade indexing, and unchanged color alpha.
- `ws_debug_cli` still passes the debug-menu callbacks and generated-texture gate.
- An optional scan over all of Art was bounded after covering additional
  cinematic/creature/dev/FX assets. It encountered geometry-index rejections in
  the existing mesh path and is not counted as a complete all-M3 pass. Its partial
  log is `build_m3test/material_reader_all_art_partial.log`.
- Portable package includes 19 byte-identical native tables; merge/unmerge and
  direct-server-output guards pass. Original assets remain external.

The source audit reports absent candidate regions: 99 color, 78 normal, 18 mask
and 2 dye occurrences in this sample. These are not automatically missing required
assets: region flags and component defaults allow partial maps. The two dye
occurrences are Mordesh male ear/horn and female hair/head regions. They keep
their existing color when no dye map is provided. No replacement assets were
fabricated. The visual result still needs checking in a live client.
