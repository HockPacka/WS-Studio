# Texture fixes — dbg40 (2026-10-25)

## Terrain: direct weights for MPHD 0x4

The map WDT sets MPHD flag 0x4. The active path recorded in WildStar.log is
`RenderSinglePassVertexPixelShader`. `CreateShaderTexture` selects format 2;
`UnpackAlphaShadowBitsFixed8888Mip0` copies the three overlay maps directly
to RGB. The multipass big-alpha path also uses additive blending. These maps
must contain **direct normalized layer contributions**, not sequential lerp
alphas. Layer 0 is the remainder `1 - sum(overlays)`.

dbg39 decoded the WildStar BC1 weights correctly but encoded MCAL as
`alpha[k] = weight[k] / sum(weight[0..k])`. That conversion belongs to the
older stacked-alpha format. With the current big-alpha renderer it can make
the implicit base contribution negative and produce false colours/contours.

dbg40 uses `Area3::EncodeBigAlpha`: normalize valid nonnegative layer weights,
quantize all layers together using largest remainders, and emit layers 1..3.
The complete quantized set sums to 255, so overlay sums cannot exceed 255.
Zero coverage falls back to the base layer, matching the previous converter's
fallback rather than introducing new terrain holes.

`tools/adt_preview.py` also used the old stacked rule. Its default now matches
MPHD 0x4; use `--stacked` only for legacy stacked-alpha input. Old previews
did not reproduce the active client interpretation of the emitted MCAL data.

Validation on Western.393b / WS_Western ADT 4,6:

| Check | dbg39 | dbg40 |
|---|---:|---:|
| Samples whose overlay sum exceeds 255 | 289,411 | 0 |
| Maximum overlay sum | 736 | 255 |
| Total samples | 1,048,576 | 1,048,576 |

244/256 MCAL payloads change. MCVT, MCNR, MCRF, MCLY, MTEX, MDDF, MDQT,
MMDX and MMID remain byte-identical. The new ADT remains 3,167,433 bytes.
The production encoder passes 40,000 round-trip cases across 1–4 layers,
checking total, implicit base and per-layer quantization error.

## Objects: tiny TYPE1 texture decoding

The client uses `0xFF00FF00` as its error texture. WildStar.log repeatedly
reports `odd block grid for type1` for:

- `Art/Dev/BLANK_Grey.tex`
- `Art/FX/Texture/Blank_WTE.tex`

Both are real 4x4 textures with three JPEG-like TYPE1 mips (4x4, 2x2, 1x1).
The decoder previously padded to 8x8 DCT blocks and then rejected the odd
block grid. TYPE1's subsampled chroma requires complete **16x16 MCUs** even
when the visible image is smaller. `TexJpg.cpp` now rounds TYPE1 storage
dimensions to 16 before decoding and crops to the visible dimensions. Other
JPEG-like kinds retain their 8x8 block alignment. The Python reader uses the
same corrected storage dimensions.

Both failed textures now convert successfully, with exact expected BGRA at
every mip: Grey `(128,128,128,255)`, White `(255,255,255,255)`. A selected
regression set of 14 textures (eleven 4x4, two 64x64 and one 32x32) covers
53 mips down to 1x1. C++ BLP pixels and the Python reference agree exactly
for every tested channel. This is a selected set, not a full texture survey.

## Files and reproduction

- Executable: `WoWClient/WowClient64_dbg40.exe` (previous builds preserved).
- `area_blocks/dbg40/alpha_comparison.png`: old/new interpretation with
  average texture colours, without lighting or actual texture sampling.
- `area_blocks/dbg40/adt_preview_4_6.png`: corrected ADT preview.
- `area_blocks/dbg40/alpha_validation.txt`: alpha sum counts.
- `area_blocks/dbg40/texture_mips_validation.json`: tested textures/mips.

```powershell
cmake --build wowdecomp/build/x64 --config Release --target WowClient adt_build_cli terrain_blend_cli tex_to_blp_cli --parallel 8
./wowdecomp/build/x64/bin/Release/terrain_blend_cli.exe
python tools/analysis/texture_mip_check.py wowdecomp/build/x64/bin/Release/tex_to_blp_cli.exe build_m3test/dbg40_selected_texture_cases.txt build_m3test/dbg40_mips
# Run from WoWClient:
../wowdecomp/build/x64/bin/Release/adt_build_cli.exe WS_Western 4 6 ../build_m3test/ws_4_6_dbg40.adt
```

No original .area/.tex files are modified. dbg40 builds the ADT and BLP data
in memory. Runtime appearance and stability still require in-game confirmation.
WildStar's height/material blending, terrain tint and some model material
features remain separate conversion differences; these fixes do not establish
visual parity for those features.
