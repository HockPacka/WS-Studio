# Terrain chunk phase (dbg38, 2026-10-25)

The dbg37 converter limited texture factors to 0.125. dbg38 preserves
`4 / MetersPerTextureTile`, including 0.0625 (64 WildStar metres) and
0.03125 (128 WildStar metres). World geometry scales these dimensions by
`33.333332 / 32` in WoW.

## Evidence and implementation

`tools/adt_preview.py` renders alpha-weighted **average texture colours**.
It checks the weight distribution but cannot establish that actual texture
sampling, lighting, or shadows are correct. The original claim that the
preview proves a rendering cause was too strong.

The local WoW `patch.MPQ` Terrain.bls shaders were disassembled using
`tools/analysis/terrain_shader_dump.py`. Each of vs_1_1, vs_2_0 and vs_3_0
contains 128 permutations. For example, permutation 0 of vs_3_0 computes:

```text
add r0.xy, -c23.yxzw, v0.yxzw
mov r1.xy, c18
mad o3.xy, r0, r1.yxzw, c13.yxzw
```

Thus diffuse UVs subtract the chunk origin, multiply by the layer scale,
and add an independent offset. At 0.0625 a chunk spans half a texture;
at 0.03125 it spans one quarter. Restarting at zero cannot join these edges.

The renderer now supplies `fract(chunkIndex * 8 * factor)` along both world
axes. Grid indices are rounded from the world origin before taking the
fraction to avoid drift from large float coordinates. The shader swaps X/Y;
matrix paths therefore add phase.y to d0 and phase.x to d1. The change covers
the four matrix multipass paths, both vertex shader multipass paths, and both
single-pass paths. Single-pass paths also apply each layer's own scale.
Animation offsets are combined with the phase; diffuse offsets are cleared
after drawing. Alpha UVs retain their original scale and offsets. The four
existing smoothing passes are retained.

## Validation

- Release builds of WowClient and adt_build_cli succeeded (existing compiler
  warnings remain).
- `tools/analysis/terrain_uv_check.cpp` includes the production phase helper:
  6,336 edges passed for factors 1 through 1/32, including ADT boundaries,
  outer map edges and negative indices. Worst wrap error from float geometry:
  0.000625320025 texture repeats (threshold 0.001).
- Rebuilt WS_Western tile 4,6: 3,150,977 bytes. Layer counts by factor:
  1:461, 0.5:305, 0.25:35, 0.125:23, 0.0625:57, 0.03125:31.
- Compared with `WoWClient/WildStarContent/test/ws_4_6.adt`: MCVT, MCNR,
  MCRF and MCAL payloads are byte-identical. Previously all 111 rock layers
  with factors <=0.125 were stored as 0.125.

Executable: `WoWClient/WowClient64_dbg38.exe`. The client builds the new ADT
data in memory from the original .area files. No installation of the test ADT
is needed. dbg37 is preserved for comparison.

**Not yet verified in game:** visual disappearance of the reported rectangles,
lighting/shadow contributions, and runtime stability of this new executable.
Check the same location using dbg37 and dbg38 at the same time/weather;
`WoWClient/Logs/WildStar.log` records the single-pass render path too.

## Reproduce

From the project root, with the existing Visual Studio toolchain:

```powershell
cmake --build wowdecomp/build/x64 --config Release --target WowClient adt_build_cli --parallel 8
# Run the converter with WoWClient as its working directory:
../wowdecomp/build/x64/bin/Release/adt_build_cli.exe WS_Western 4 6 ../build_m3test/ws_4_6_dbg38.adt
# Compile the regression from a Visual Studio x64 developer shell:
cl /nologo /EHsc /O2 /Iwowdecomp tools/analysis/terrain_uv_check.cpp /Fe:build_m3test/terrain_uv_check.exe /Fo:build_m3test/terrain_uv_check.obj
build_m3test/terrain_uv_check.exe
```

For shader inspection, build the existing tools/StormLib project as a shared
x64 library with bundled dependencies, then run:

```powershell
python tools/analysis/terrain_shader_dump.py build_m3test/stormlib/Release/StormLib.dll WoWClient build_m3test/terrain_shaders
```
