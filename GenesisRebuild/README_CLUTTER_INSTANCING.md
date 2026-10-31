# Genesis Clutter – GPU Instancing Foundation

## Current status

The **Clutter** dock has a new **diagnostic, manual M3 instancing preview**.
It is a foundation for the eventual native WildStar clutter generator, **not
yet a native WorldClutter.tbl reconstruction or a clutter painter**.

The preview:
- Reuses the exact `Handle<Mesh>` and `Handle<StandardMaterial>` from
  the existing M3 model cache. Bevy 0.20 automatically batches and instances
  compatible opaque and alpha-masked `Mesh3d` entities with the same handles.
  No mesh or material assets are created per placed instance.
- Omits alpha-blended and additive model parts from this fast path, since
  transparent sorting and batching have different constraints.
- Distributes *bounded, deterministic* placement candidates across the 256
  native 32m terrain cells; every cell uses a stable source-cell RNG seed.
- Reads real native **AREA bit 27** (the 2-bit preset selector for each of the
  four WorldLayer slots) and **bit 16 bit 5** (`0x20` suppresses clutter).
- Uses native **bit 29 / bit 2 / compressed 17+18** weight data to include
  only candidates with a sufficient selected material layer contribution.
  Requires actual source layer IDs; missing native data is **not guessed**.
- Samples the current standalone 257×257 terrain heightfield; checks presence
  and conservatively rejects steep candidate positions.
- Places instances in per-cell visibility groups. Camera X/Z distance toggles
  whole cell groups; Bevy still performs its native per-mesh frustum culling.
- Caps preview candidates per cell and total instance count. Groups and all
  child mesh entities are removed when changing AREA or disabling preview.
- Rebuilding the preview after sculpting re-samples the current edited
  heightfield; no original game data is modified.

## Usage

1. Open an original, standalone `.area`, and index the original ClientData.
2. Open **Clutter** on the right-hand Genesis dock.
3. Enter the virtual path of a real indexed `.m3` plant or rock model.
4. Choose a **WorldLayer slot** (0..3) and an **AREA bit-27 preset index** (0..3).
5. Select candidates per cell, maximum instances, and view distance.
6. Click **Build Instanced Preview**. The selected M3 will appear wherever
   the native data's slot selector, weight and no-clutter flags allow it.
7. Click **Clear** to remove the preview entities. To update after a terrain
   edit or model change, click Build again.

**The chosen model is assigned manually.** This step only checks placement,
filtering, model caching, GPU-compatible shared material handles and distance
culling. Do not infer that Bit 27 directly names M3 assets, or that the
preview's instance count equals the original game's density.

## Why shared handles matter

The Bevy 0.20 renderer has built-in automatic GPU instancing for compatible
meshes using the *same mesh and material handles*. Sharing just the underlying
vertex data is insufficient if each plant receives a new material handle.
Genesis therefore uses one cached M3 mesh/material per model part across all
placed instances. Multiple model parts can require multiple batches. The
actual number of draw calls and GPU instance grouping **must be measured**
using RenderDoc or another GPU profiler on the target hardware. Source code
and successful compilation alone do not prove one draw call per asset.

## Limits before a real WildStar clutter editor

- Parse all four actual `worldClutterId00..03` fields per WorldLayer.tbl row.
- Read `WorldClutter.tbl` weighted M3 assets, density, min scale and rotation.
- Replace manually selected M3 with exact preset-driven asset choice. Source
  `WS-Tools/docs/ground_clutter_dbg43.md` documents a tested partial
  conversion, including 6 weighted assets and native no-clutter suppression.
- Compare placements and coverage with actual WildStar client output.
- Rebuild affected cells on terrain paint/sculpt events, add quality LOD,
  vegetation wind and true native Bit27 editing and save/undo semantics.
- Benchmark substantial mixed grass/rock scenes and verify mesh/material
  auto-instancing and camera/visibility performance in a real GPU capture.

References:
- Bevy automatic instancing: https://bevy.org/examples/shaders/automatic-instancing/
- Native source study: https://github.com/HockPacka/WS-Tools/blob/main/docs/ground_clutter_dbg43.md
