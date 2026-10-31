# M3 textures and alpha — dbg41

## Causes and implementation

The M3 converter emitted blend mode 0 for every mesh. Alpha was already preserved
in the decoded TEX/BLP, but the opaque M2 shader discarded its role as coverage.
The converter now uses material header +0x14:

| M3 mode | M2 mode | Meaning |
|---|---|---|
| 0 | 0 | Opaque; texture alpha may contain material data |
| 1 | 1 | Alpha mask / cutout |
| 2 | 2 | Alpha blending |
| 3 | 3 | Add, without source alpha |
| 4 | 4 | Add, with source alpha |
| 5 | 5 | Multiply |
| 6 | 6 | Multiply 2x |

Ghidra MCP on the open `WSG/WildStar64.exe` program: `FUN_1403283c0`
reads mode +0x14 and sets the mask shader constant to **0.5** for mode 1,
0 for opaque, and 1/255 for blended modes. Its transparent-pass blend factors
agree with modes 2..6 above. Relevant excerpts are saved in
`ghidra_m3_material_mcp_evidence.c`.
The renderer now uses a 0.5 base mask threshold for converted M3 models;
native M2 models keep WoW's 224/255 threshold. Model fade still scales the
threshold through the existing WoW path.

The first opacity key of layer 0 (DP +0x60, default 1) becomes the M2 color
alpha track. Mode 0 with opacity below 0.996 is promoted to alpha blending,
as in the original renderer. Material flags bit 0/1 map to disabled depth test /
disabled depth writes. Single-layer color multipliers are no longer skipped.

All used M3 color textures previously had M2 texture flags 0, forcing clamp
when `CM2SceneRender::SetupTextures` set the sampler. Actual rock UVs range
from -2.34 to 0.97 in U; pine UVs range from -2.84 to 2.23 in V.
Flags 3 now enable U/V repetition instead of extending the edge texels into
long stripes. This is a sampling correction, not a newly decoded M3 flag.

Materials without a color texture now select an explicit white texture slot.
Previously they selected texture 0, which could be another material's atlas.

## Verification

Build: `cmake --build wowdecomp/build/x64 --config Release --target WowClient m3_to_m2_cli tex_to_blp_cli --parallel 8`

Run: `python tools/analysis/m3_material_check.py`

Checks:

- Real PurpleStarFlower: mode 1, alpha mask.
- Real WeepingUmbrella: opaque trunk/blank material and masked foliage.
- Real Withered PointyPine: opaque bark and masked canopy.
- Real SlantedPointyLarge White rock: opaque despite alpha values below 255.
- All seven blend modes in controlled copies of the raw flower file.
- Opacity 0, 0.25, 0.75, 1; M2 alpha values within 1/32767.
- Missing color texture, depth flags, and single-layer tint.
- Six real color TEX files, 56 mip levels through 1x1: C++ BLP output compared
  to independent Python decoding, including the alpha channel.

Reports: `m3_material_dbg41_validation.json`, `m3_alpha_dbg41_validation.json`.
Executable: `../WoWClient/WowClient64_dbg41.exe`.

Original M3/TEX files remain unchanged. No in-game rendering check was performed.
Remaining limitations: material DP animation is represented by the first key;
only color layer 0 is rendered. Separate normal/SkinFX channels and multilayer
height blending are not interpreted as coverage masks. Modes above 6 currently
fall back to alpha blending; their exact special behavior is still open.
