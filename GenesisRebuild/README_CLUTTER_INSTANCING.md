# Genesis Clutter – GPU Instancing Foundation

## Current status

**Native table-driven instanced preview is implemented.** Genesis loads
\`ClientData/DB/WorldLayer.tbl\` and \`ClientData/DB/WorldClutter.tbl\` using the
existing LBTD decoder, resolves the original four
\`worldClutterId00..03\` entries per WorldLayer and selects one of each
WorldClutter preset's six weighted \`assetPath0..05\` M3 models. Model part
meshes and materials are loaded into the existing model cache and shared
unchanged across thousands of compatible visible instances.

Both **Build Native Instanced Clutter** and the original manual diagnostic
preview remain available in the Clutter dock. Native mode is the default;
uncheck "Native TBL-driven placement" to use a manually selected model.

To use it: index the original WildStar ClientData, open a standalone AREA,
select the **Clutter** tab, leave native mode enabled and click **Build Native
Instanced Clutter**. Use the candidates-per-cell, max-instance and group
view-distance controls to limit editor load. Click **Clear** to remove all
instanced objects. If an indexed asset is absent or decoding fails, the
preview skips that model and reports it; it does not spawn an ErrorCube.

**Bevy automatically instantiates compatible opaque or alpha-masked mesh
entities using matching Mesh/Material handles.** This does not guarantee a
specific measured draw-call count or native WildStar density parity. Dynamic
alpha blending and additive material parts remain excluded from this fast path.

## Native lookup and generator

The lookup chain is \`AREA bit1 WorldLayer IDs\` → WorldLayer.tbl
\`worldClutterId0[0..3]\` selected by the four packed 2-bit fields in
\`AREA bit27\` → WorldClutter.tbl \`density\` and six weighted assets →
cached original M3 parts. \`AREA bit16\` flag \`0x20\` suppresses instances.
The generator samples the native 65×65 weight grid with bilinear blending,
squares the normalized layer weights, rejects a selected contribution below
0.25, samples the editable height grid and ignores steep/hole positions.
It uses per-cell stable seeds and a deliberate 1/8 source-trial budget,
bounded by the user-configured candidate and instance limits.

The original WildStar GPU worker's exact RNG sequence, material flag
interpretation, wind, scatter distribution and instance orientation are not
fully verified. **This is an editor preview implementing native table
relationships, not a bit-identical reproduction of WildStar's placement.**

## Native Clutter Painter, Undo/Redo and Save As

The Clutter dock now includes **Paint native AREA Clutter data**. Its
three modes edit only the already existing native per-cell 64×64 blocks:

- **Preset** chooses a WorldLayer slot 0..3 and a preset 0..3, updating
  only the corresponding two bits in **AREA Bit 27**. The other three
  WorldLayer selectors in each pixel are byte-preserved.
- **Exclude** sets only **Bit 16 mask bit 5 (0x20)** at a painted pixel,
  suppressing vegetation there without modifying road/zone flags.
- **Restore** clears only the same **0x20** mask bit, leaving all other
  terrain flags intact.

Brush radius is in world-space metres, and editable AREA cells are never
silently created. If a cell has no matching native block, painting does
nothing rather than inventing a block layout. The workspace keeps a maximum
of 24 per-stroke Undo/Redo snapshots, with Ctrl+Z and Ctrl+Y when Clutter
painting is active. **Save AREA As...** and **Export AREA Bundle...** include
the Clutter edits alongside supported terrain heights and textures.
Export uses the existing validated, non-overwriting native AREA writer and
staged-bundle publisher. Bit 16/27 changes do not require inter-AREA ghost
synchronization because the stored maps are exactly 64×64 per cell.

The **Auto-regenerate after Terrain/Clutter edits** toggle defaults on.
The current instance preview is rebuilt when the height grid, texture
weights, or Clutter selectors/masks change **after the active stroke ends**,
not on every mouse-move event. The preview samples unsaved WorldLayer
assignments, painted weights, and native 16/27 changes from in-memory
workspaces. WorldClutter.tbl metadata are cached while the indexed
ClientData root is unchanged; per-instance Mesh and Material handles remain
shared. Auto-regeneration is now **incremental at the Bevy entity level** for the
native TBL-driven preview: Genesis recomputes deterministic placements, groups
them by the original 32 m AREA cell, and compares each cell's new placement
list with the last rendered list. Only changed cell roots (including cells
that become empty) are despawned and respawned. Unchanged cells retain their
exact Bevy `Entity` IDs and cached M3 mesh/material handles. This also catches
neighboring cells affected indirectly by the **global instance budget**.
Explicit **Build Native Instanced Clutter** and source/client changes retain
a full reset path. Manual one-model preview remains a full rebuild.

For correctness, **CPU candidate generation still scans all 256 AREA cells**
on each completed change; the expensive entity creation and GPU resource
updates are restricted to changed groups. A future optimization can reduce
CPU work to dirty cells with deterministic per-cell quotas and explicit
height-grid edge dependency tracking. No retail placement parity is claimed.

The Clutter dock reports the most recent number of regenerated cells,
retained cells and newly spawned instances, so you can verify that editing
one cell does not rebuild unrelated plants. The independent
`src/clutter_rebuild.rs` diff planner has regression tests covering
unchanged instance preservation, modified cells, emptied cells and
global-budget reallocations.

The native writer is in \`wildstar_formats/src/area/clutter_write.rs\` and
the in-memory painter is \`GenesisRebuild/src/clutter_paint.rs\`. No
original source data are overwritten. Source-bit preservation and
validation tests reject missing cell blocks, illegal selectors, invalid
coordinates and modifications to unrelated flags/blocks. The actual
WildStar placement algorithm and dynamic wind remain unverified.

## Implementation and testing

- \`wildstar_formats/src/tbl.rs\`: extracts four WorldLayer clutter IDs and
  the WorldClutter ID/flags/density and six model paths, weights, scales,
  rotation ranges, flags and emissive fields; no unsupported fields are
  silently treated as guaranteed native behavior.
- \`GenesisRebuild/src/clutter_native.rs\`: read-only catalog loader,
  deterministic weighted preset selection and bounded per-cell generation.
- \`GenesisRebuild/src/clutter.rs\`: cached shared M3 mesh/material handles,
  grouped instance entities, transparency exclusion, cell distance culling,
  per-build asset load budget and summary statistics.
- \`GenesisRebuild/src/main.rs\`: native/manual toggle and rebuild controls.
- Format-crate tests exercise table schema; editor unit tests cover model
  selection, masks, absent presets, bounded instance creation and determinism.
  A Windows compile check is not a replacement for GPU measurement.

---

## Current status

The **Clutter** dock also retains a **diagnostic, manual M3 instancing preview**.
It is retained for single-model debugging. Native table-driven instancing is now present, but **native painting, full shader parity and original distribution still need research**.

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

- Verify exact model paths, weighted asset choice and density against several
  original client maps. The six weighted assets and four layer presets now
  load from TBL; world-client RNG/orientation remain approximations.
- Compare placements and coverage with actual WildStar client output.
- Rebuild affected cells on terrain paint/sculpt events, add quality LOD,
  vegetation wind and true native Bit27 editing and save/undo semantics.
- Benchmark substantial mixed grass/rock scenes and verify mesh/material
  auto-instancing and camera/visibility performance in a real GPU capture.

References:
- Bevy automatic instancing: https://bevy.org/examples/shaders/automatic-instancing/
- Native source study: https://github.com/HockPacka/WS-Tools/blob/main/docs/ground_clutter_dbg43.md
