# Native sky models and cloud fields: dbg49

Executable: `WoWClient/WowClient64_dbg49.exe`.
SHA256: `26A705CF6F1CAC2F3891385DF363F1DC9A8E3F39E4EA4E71D78B658BE0EEE65F`.
Build: `build_m3test/sky_stage2_final_build.log`. The previously existing dbg48 is preserved.

This extends [dbg47 atmosphere](sky_integration_dbg47.md) with authored SKY model instances and moving CloudSet geometry. Original SKY/M3/TEX/TBL files remain unchanged.

## Authored models

The C++ SKY reader now decodes the model array at 0x2E8: u16 parameter, u16 flags, u32 unknown, UTF-16 path, and an eight-float track. The first parameter remains unnamed; it is not assumed to be an animation ID. The native flag getter at [FUN_1407d7220](sky_analysis/ghidra/FUN_1407d7220.c) reads the u16 at record+2.

Model tracks use cyclic interpolation across midnight, unlike ordinary clamped parameter tracks. The first two floats provide rotation angles in degrees; floats 4..7 provide RGB and opacity. Spatial sky weights multiply model opacity. Instances are kept distinct for different sky IDs and slots, so two source skies can independently rotate/tint the same shared model.

The original rotation matrix and day-animation behavior are established by [FUN_1407d6080](sky_analysis/ghidra/FUN_1407d6080.c). Zero-roll row-vector rotation is:

```text
 cos(a)          0          -sin(a)
 sin(a)*sin(e)   cos(e)      cos(a)*sin(e)
 sin(a)*cos(e)  -sin(e)      cos(a)*cos(e)
```

The loader initially selects sequence 150. Model flag 2 binds that sequence to day seconds / 86400. The adapter uses sequence 150 when present and retains the converted default otherwise. Rotation is transformed through M3ToM2's axis mapping (z,x,y). Instance RGB/alpha are passed through the existing M3-to-M2 material/texture path in a separate camera-centered model scene, using neutral scene lighting and no extra WoW fog.

This enables the original referenced suns, moons, stars, skybox rings and authored cloud shells. Missing models are logged and suppressed instead of drawing ErrorCube substitutes. Scene/model resources are released on leaving the native sky region or unloading the map.

## CloudSet fields

The u32 track at 0x310 is resolved through SkyCloudSet.tbl and SkyTrackCloudSet.tbl. Adjacent resource IDs are blended, including the last-to-first interval across midnight; ID 0 contributes no field. Duplicate set IDs from overlapping world skies are merged. The asset selection uses each track's actual `count`, not every populated model column. [Native count](sky_analysis/ghidra/FUN_1407d5a60.c) and [asset/scale lookup](sky_analysis/ghidra/FUN_1407d5ad0.c) verify these table meanings.

The original manager [FUN_1407c4fc0](sky_analysis/ghidra/FUN_1407c4fc0.c) establishes the field defaults:

- Six lanes with boundaries -2000, -1200, -200, 0, 200, 1200, 2000.
- A horizontal cloud plane at source y=200, yawed 45 degrees.
- Clouds sweep from x=-2000 to +2000 at 15 source units per second.
- Per-asset random scale between table minSize and maxSize.
- Fade begins at absolute x=1600 and reaches zero at x=2000.
- Spawn rate is density × speed / 4000, giving the table density as the expected steady-state population before empty slots and unavailable assets.

The adapter initializes a deterministic steady-state population immediately, rather than waiting for the original stochastic spawn process to fill the plane. It then moves and wraps those instances with the same speed/limits and fades the wrap. Each participating set has its own stable population and spatial/time blend opacity. Thus the motion, geometry selection and range follow the source data, while individual random placement, population transitions and spawn history are an adaptation.

Cloud geometry is read directly with the existing M3 reader. The 57 resolved models exercised by validation each have one geometry and group 255. Hidden helper meshes are excluded, indices are checked and converted to per-mesh u16 draws. The raw field renderer currently uses bind geometry; original per-cloud skeletal/sequence deformation is not reproduced.

## Dedicated cloud shader

`WoW/Source/WorldClient/Shaders/WildStarCloud.hlsl` adapts the original M3CloudPS variant 0 to D3D9:

1. Texture red indexes sixteen authored cloud colors: `index = 15 * red`, equivalent to the original linear lookup coordinate `0.03125 + 0.9375 * red`.
2. The source cloud SH evaluates directional illumination, multiplied by two as in the original shader.
3. Texture green masks the sun highlight: `max(dot(direction,sun)-0.8660254,0) * green * 7.464102`.
4. Texture alpha is multiplied by material opacity and field blend/fade opacity.
5. The original primary-output fog/color expression is retained, with a zero additional fog floor in this adaptation. Sky depth is forced in the vertex shader so the distant cloud plane is not clipped by terrain draw distance.

The sixteen-color lookup uses floating-point constants, avoiding an extra 8-bit lookup texture and retaining HDR inputs until final scene output. Ordinary non-cloud material records have a separate diffuse-sampling branch. Native MRT secondary output, deferred cloud composition and the full fog-floor calculation are not reproduced.

`tools/build_sky_shaders.py` uses Windows D3DCompiler_47 to compile vs_3_0 and ps_3_0 into `WildStarCloudBytecode.h`. The generated header embeds bytecode in the executable and records the HLSL source hash. No loose shader installation or runtime compiler is required. The cloud field pass currently supports the D3D9/D3D9Ex backend; other backends skip that field pass.

Shaders are registered with the engine for device-loss handling. The pass saves/restores render states and the shader constants it changes. Source textures use the existing native TEX loader and retain their alpha.

## Validation

- Release client and standalone native reader compile successfully.
- All 1,290 SKY files still parse and evaluate; source bytes are retained. The earlier 381 warning occurrences for unsupported SH shapes/time anomalies remain.
- Independent Python decoding matches native model paths/flags, cyclic rotations, RGB/alpha and CloudSet key blends at five times in five skies (25 samples), alongside existing SH/band and AREA coordinate checks.
- Independent CSV/placement math matches seven cloud sets at three times: 21 cases, including lane selection, asset count, scale, movement, rotation and fade.
- 57 referenced cloud models and 14 diffuse TEX textures successfully pass the existing native conversion tools. [Cloud validation report](sky_analysis/cloud_validation.json).
- A hidden D3D9 device **executes the embedded vertex/pixel shaders**, reads back rendered pixels, and passes 18 combinations of red-channel endpoints/interpolation, alpha 0/128/255 and cloud/ordinary material modes. This validates actual bytecode, not only HLSL compilation. Test source: `tools/analysis/sky_shader_device_check.cpp`.
- Game rendering and the complete engine draw-state interaction have not been visually verified during this implementation run. The isolated GPU test does not prove in-game ordering, intensity or coverage.

Eight referenced models are absent both from the local extracted tree and from a case-insensitive lookup in the available ClientData archive: one Astroid model and seven Cirrus variants. They are skipped and logged. This does not affect CloudSet 6 used by the inspected Ellevar sky; it can reduce cloud population in other sets.

Reproduce data checks:

```powershell
python tools/build_sky_shaders.py
cmake --build wowdecomp/build/x64 --config Release --target WowClient sky_cli m3_to_m2_cli tex_to_blp_cli -- /m:4 /v:minimal
python tools/analysis/sky_native_check.py
python tools/analysis/sky_cloud_check.py
wowdecomp/build/x64/bin/Release/sky_cli.exe --check WoWClient/ClientData/Sky
```

The GPU test was compiled with MSVC C++17, `/Iwowdecomp`, and `d3d9.lib user32.lib`, then run as `build_m3test/sky_shader_device_check.exe`. It creates no visible window and does not present frames.

## In-game check and remaining work

Run dbg49 from WoWClient. Use `/run WSSkyTime(12)` and `/run WSSkyTime(0)` at the same position; `/run WSSkyTime(-1)` restores normal day progression. Check for celestial models, the authored sky shells and moving cloud fields. Loading diagnostics use `[Sky] model` and `[SkyCloud]` in WildStar.log.

Still open: cubemap reflections/filtering, 3D color LUT grading, native fog density/distance transfer, complete directional SH surface lighting, cone/local-source SH contributions, particulates, glare/scattering postprocess, native cloud animation/spawn history and secondary render targets. These remain separate from the newly connected visible sky-model/cloud passes.
