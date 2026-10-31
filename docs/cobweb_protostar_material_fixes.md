# Cobweb / Protostar material corrections (2026-10-26)

Continues the inspection steps in the pasted Argon quota transcript. That
transcript contains activity names, not evidence that the underlying issues
were fixed. These changes address two reproduced material pipeline defects.

## Additive cobweb sheets ignore coverage

`PRP_Cobweb_StarShape_SquareFit_000.m3` uses native additive blend mode 3,
coverage-enabled color alpha, and a flat placeholder normal. The converter
selected no custom material features and left its M2 combiner at zero.
`CM2Shared::GetEffect` consequently chose `Combiners_Opaque`: the actual MPQ
pixel shader sets output alpha to vertex alpha, ignoring texture alpha.

The original texture has RGB near 128 even where alpha is zero. These hidden
texels therefore passed the blended-material alpha test and added grey sheets
to the image. A transparent material without custom features now uses combiner
1 (`Combiners_Mod`), which multiplies texture alpha by vertex alpha. Original
additive blend factors remain unchanged; zero-alpha texels can be rejected.

## Material lighting applied twice

The custom M3 pixel shader computes ambient/sun lighting. Its binder previously
retained the stock vertex shader's light/specular permutation, merely selecting
the shadow group to obtain position and normal outputs. Actual local MPQ
`Diffuse_T1_T2` permutation 31 computes lit COLOR0, while permutation 30 returns
the unlit material color. Multiplying permutation 31's result by custom pixel
lighting darkened it a second time.

The binder now selects `30 + 10 * ((vertexPermute % 30) / 10)`: same bone layout,
position/normal outputs, no stock light/specular modulation. The custom pixel
shader remains responsible for its existing lighting approximation. This is
not a full implementation of WildStar's original deferred lighting or local
light handling.

## Checks and delivery

`python tools/analysis/material_pipeline_check.py` passes:

* Real converter output for all 30 cobweb models and two Protostar machines.
* StarShape cobweb keeps blend mode 3, now uses combiner 1.
* Layered machine materials retain texture bindings with nonempty filenames.
* Hidden D3D9 readback uses original MPQ vertex/combiners and our embedded PS9:
  doubled-light green 64 becomes 127 for the same ambient input.
* Additive zero-alpha grey background: old output `ff909090`, corrected output
  `ff101010` (unchanged clear color). Visible texels still yield `ff909090`.

Reports and extracted diagnostic bytecode are in
`build_m3test/material_fx_probe/`. Cache version 16 invalidates older generated
models. The combined client includes the i3 portal fixes documented in
`i3_portal_visibility_investigation.md`; original ClientData assets are intact.

Client: `WoWClient/WowClient64_MaterialsPortals_test.exe`. In-game verification
of the submitted scenes is still pending. Particle emission, flipbook timing,
and all remaining native material modes are not claimed fixed by these tests.
