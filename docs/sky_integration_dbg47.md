# Native SKY integration: dbg47

Test executable: `WoWClient/WowClient64_dbg47.exe`. The previously existing dbg44, dbg45 and dbg46 executables are preserved. Build log: `build_m3test/dbg44_verified_build.log` (the initial working build label was dbg44). Source changes are in Area3/Sky, WorldClient/WildStarSky, DayNight and the existing WildStar Lua debug registration.

## Implemented

- Native XSKY v16 reader, retaining all original bytes, with bounded relative offsets and finite float checks. Only the fields consumed by this first rendering stage are decoded in C++; the Python reader remains the more comprehensive raw inventory.
- WorldSky.tbl resolution of AREA block 6/7 corner IDs and weights; bilinear spatial interpolation, merging of IDs, four dominant contributions and normalization over loaded resources. Uses the same window/tile/cell/axis convention as the terrain builder. Ordinary WoW maps use their existing path.
- Day-time sampling from client day progression, plus a local sky-time override for testing. Invalid source key order/range is reported and the affected contribution is skipped without rewriting data.
- Ambient, directional and two-color hemisphere SH contributions and explicit 27-float SH tracks. Original projection constants are taken from FUN_1401aefa0 and FUN_1401af0b0. All sixteen gradient colors are sampled and blended before display.
- A sky mesh matching the original **band heights** and **32 longitudes**. FUN_1407cb5a0 uses a cylinder of radius one, fourteen rings, a top pole at +10 and a bottom pole at approximately -5. The horizon is band 12, not the middle band. The WoW draw adapter duplicates seam/pole vertices to use its existing triangle-strip path.
- CPU evaluation of directional sky SH plus band colors on that mesh. This adapts the original shader's polynomial/color operations to WoW's vertex-color draw path; SHO bytecode is not executed directly.
- SKY ambient and sun color/direction transferred into WoW scene lighting; camera-facing horizon color from the fog group transferred into the existing fog path. Azeroth celestial objects/clouds/glare/skybox overrides are suppressed while native SKY is active.
- Loading, missing-resource and unsupported-contribution diagnostics prefixed `[Sky]` in `WoWClient/WildStar.log`.

Original height defaults were read through the sixteen pointers at VA 0x140c3acf0, each default float at pointer+0x20. Starting at 10, the subsequent vertical decrements are 2.4042461, 3.8637030, 1.3178370, 0.6821630, 0.4288250, 0.3032250, 0.2326730, 0.1899770, 0.1631370, 0.1462640, 0.1362970, 0.1316530, 0.5773500, 1.1547010, 3.2679491. Evidence: [native geometry](sky_analysis/ghidra/FUN_1407cb5a0.c), [hemisphere projection](sky_analysis/ghidra/FUN_1401aefa0.c), [directional projection](sky_analysis/ghidra/FUN_1401af0b0.c).

## Validation

- Release client and standalone sky_cli build successfully.
- Native reader accepts all **1,290** local SKY files and evaluates five day times with finite SH output, preserving source bytes. It reports 381 warning occurrences for currently unsupported contribution shapes and authored time issues; these are not structural parse failures.
- Independent Python comparison: **25 samples** across Ellevar_Main_005, Ellevar_SZ_CreepyForest_001, TestReference, NorthernWilds_Main and WhiteVale_Main match all evaluated SH coefficients and sixteen color bands within 3e-5 tolerance.
- Six AREA queries with different intra-cell positions match independent corner-weight decoding after conversion to WoW world coordinates. Ordinary-map and out-of-map queries return inactive.
- Header truncation, invalid relative pointers and the authored horizon/pole heights are checked by the standalone executable. Existing Python SKY/container checks still pass.
- Gameplay rendering has **not** been visually verified in the client by this implementation run. CPU/reference tests do not prove GPU state, fog appearance or final lighting intensity.

Reproduce:

```powershell
cmake --build wowdecomp/build/x64 --config Release --target WowClient sky_cli -- /m:4 /v:minimal
wowdecomp/build/x64/bin/Release/sky_cli.exe --check WoWClient/ClientData/Sky
python tools/analysis/sky_native_check.py
python tools/analysis/sky_reader_check.py
```

## In-game check

Start dbg47 in the normal WoWClient working directory and visit the WildStar map. Compare day and night at the same position:

```lua
/run WSSkyTime(12)
/run WSSkyTime(0)
/run WSSkyTime(-1)
```

Negative time restores server/client day progression. This override changes the local WildStar atmosphere only. Move between open Ellevar and CreepyForest to check spatial blending. The log should report loading WorldSky IDs 14 and 16 on the inspected Western tile.

## Remaining fidelity gaps

This is the first visible atmosphere stage, not a complete reproduction of all native passes:

- Sky-associated M3 geometry (sun, moons, stars, authored skyboxes), CloudSet/CloudTrack cloud models and their dedicated color-lookup material remain to be connected. The first stage therefore has no replacement celestial objects or clouds.
- Cubemap reflection filtering/composition, 3D color LUT grading, particulates and screen-space scattering are not integrated.
- Cone/local-source SH shapes at group arrays +0x38/+0x48 remain raw and generate warnings. The two Ellevar skies used on the test tile do not use these shapes.
- Surface lighting is reduced to WoW's ambient + one directional light. Full directional SH for terrain/models needs shader changes. Sky SH itself is evaluated directionally on the CPU.
- Colors use WoW's 8-bit vertex path and clamp at 1.0; original sky output can reach 1.5 before later composition. HDR/postprocess fidelity remains open.
- Fog **color** is sourced from SKY. Existing WoW fog distances/density, underwater/interior handling and weather behavior are retained until the native fog scalar meanings and shader transfer are implemented.
- Sky fallback when AREA metadata is absent is the existing WoW path; the original map-default sky fallback is not connected yet. Loading is synchronous on tile changes and the metadata cache currently retains one tile.

No original AREA, SKY, SHO, TBL or TEX files are rewritten. Raw undecoded fields remain available for subsequent stages. See [raw format](sky_format.md) and [shader mapping](sky_shader_mapping.md).
