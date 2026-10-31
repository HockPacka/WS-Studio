# Ground clutter — dbg43

WorldLayer.tbl's four clutter IDs and WorldClutter.tbl's six weighted assets,
density, minScale and rotation ranges are read directly. Source selection uses
AREA layer weights, per-layer two-bit selectors in block 27, and block 16's
0x20 no-clutter mask. Seeds use source-world cell coordinates. Normal source
files and DBCs are unchanged.

The private in-memory ADT subchunk MCLT (version 1) carries per-cell model paths
and local placements. CMapChunk submits nearby instances to WoW's existing
CDetailDoodad renderer, sharing geometry/textures, native distance fade,
lighting, pools and cleanup. Heights come from the actual ADT triangle planes;
holes and steep slopes are rejected. WS chunks have up to 16 batches; native
chunks retain their four-batch admission limit. Missing WS models are skipped
and logged rather than replaced by scattered ErrorCubes.

Opaque M3 clutter materials get a derived `#opaque.blp` texture in memory.
Its RGB/mips are preserved and alpha is 255, avoiding accidental cutouts in
small rocks whose alpha stores material attributes. Masked vegetation keeps
its original alpha. TEX source bytes remain unchanged. The GPU reload path
also understands this texture recipe.

Original evidence: FUN_140381070/140381300/140381970 in
`ghidra_terrain_mcp_evidence.c`. Actual ClutterVS/ClutterPS DXBC was disassembled
from ClientData/Shaders; excerpts saved as `shader_clutter_vs.txt` and
`shader_clutter_ps.txt`. The native WoW DetailDoodad shader permutations were
also inspected from MPQ, in `../build_m3test/dbg43_shaders`.

## Validation

- Test tile Western.393b / WoW 4,6: 77,672 stored candidates, 256 populated
  chunks, 47 valid models sharing six texture atlases, maximum 435 per chunk.
- Independent source/CSV validation: zero blocked placements, invalid presets
  or missing model/texture conversions. Every model meets the current one-atlas
  ground-detail contract and fits the 4,096 vertex/index batch limits.
- Synthetic tests: all four layer/selector slots, no-clutter masks, weighted
  asset slots, deterministic seeds, rare densities, absent blend map fallback,
  serialization round trips and truncated/malformed records.
- Real opaque stone and synthetic DXT1/3/5: RGB/mips preserved, alpha made
  opaque; TEX lookup recipe tested.
- Existing 1,289 ADT chunks/subchunks checked unchanged against dbg40,
  excluding new MCLT data and adjusted offsets. Terrain blend tests pass.

Reports: `ground_clutter_dbg43_validation.json`,
`ground_clutter_opaque_dbg43_validation.json`. Offline placement preview:
`ground_clutter_dbg43_placements.png` (source orientation; red = forbidden,
green = stored placement). No live gameplay/performance check was performed.

## Deliberate conversion differences

The original worker uses up to min(8000,density*16) trials. This conversion uses
one eighth of that budget, stochastic rounding for rare densities, then native
groundEffectDensity thinning: 16 means half, 32+ means full stored density.
groundEffectDist controls native fade/range. Batch limits may omit further
instances. Placement RNG is stable but not WildStar's exact sequence.
Layer contributions are squared and normalized with the worker's 0.25 selected
contribution cutoff. Additional WildStar per-layer bias/height blending is not
reproduced. Plants remain upright with neutral vertex tint; original instance
flag orientation, wind, normal-map lighting and emissive behavior remain open.

## Reproduction

```
cmake --build wowdecomp/build/x64 --config Release --target WowClient adt_build_cli clutter_cli tex_to_blp_cli --parallel 8
wowdecomp/build/x64/bin/Release/clutter_cli.exe
python tools/analysis/clutter_check.py WoWClient/ClientData/Map/Western/Western.393b.area build_m3test/ws_4_6_dbg43.adt build_m3test/clutter_dbg43
python tools/analysis/clutter_opaque_check.py
```

Run adt_build_cli from WoWClient with `WS_Western 4 6 ../build_m3test/ws_4_6_dbg43.adt`.
Client executable: `../WoWClient/WowClient64_dbg43.exe`.
