# Genesis WorldLayer Texture Painter — Phase 1

This feature adds **interactive, preview-only** terrain texture painting in the existing Genesis Bevy editor, without changing the original WildStar client files.

## Current functionality

- **WorldLayer Browser** searches real `DB/WorldLayer.tbl` entries by ID or texture path, shows the associated diffuse `.tex` thumbnail, meters-per-tile and normal-map presence (12 entries per page).
- **Four slots per 32 m terrain cell** are displayed with their actual `WorldLayer` IDs. Select a slot, choose a WorldLayer in the browser, and click **Assign ... to Slot**. Assignment changes only the editable preview and may trigger a one-time rebuild of the runtime splat arrays.
- **Paint / Erase / Smooth** blend weight channels on the visible terrain. The current splat map uses **1024×1024 RGBA8 pixels** (64×64 per cell); the paint brush edits this GPU-backed map in memory and uploads it to the existing Bevy material.
- Adjustable **Size, Power and Falloff**, plus per-stroke **Undo/Redo** (16 strokes). `Ctrl+Z` / `Ctrl+Y` operate on the active Paint dock's history.
- The selected **WorldLayer ID** is carried across cell boundaries: a brush paints only cells that already contain that same ID, preventing accidental overwriting of another slot. Assign the WorldLayer to additional cells before painting across them.
- **Restrict to Selection** confines strokes to the previously selected cell; hover over a cell without pressing the mouse button to select it.
- **The input source AREA is never modified** while editing textures. Texture changes are intentionally **not** exported yet.

## Usage

1. Configure ClientData and open a **standalone** `.area` file with decoded terrain splats.
2. Open the **Paint** dock and select **Texture Brush**. The editor should show the textured terrain view, not a debug layer.
3. Move over a cell to select it. Select one of four slots and/or choose a WorldLayer from the library. Click **Assign WorldLayer to Slot** to change the material used by that slot in that cell.
4. Choose **Paint**, **Erase**, or **Smooth** and left-drag directly on terrain. Right mouse rotates the camera; middle mouse pans.
5. Use **Undo Paint** and **Redo Paint** from the dock, or the standard edit shortcuts. The green circle indicates approximate brush radius.

## Important limitations

- **Save AREA As... only saves height sculpt changes.** To avoid misleading exports or accidental loss, Save As is blocked while any texture preview edits are pending; Undo them to return to the source texture state if you need to export height edits.
- Native write support for source bits **1, 2, 17/18, 19/20, 29**, loss-aware BC1 encoding and cross-tile propagation belongs to **Phase 2**, after representative WildStar files have been validated.
- Texture slots are per **cell**, not global. The current first phase does not automatically assign a new WorldLayer to every cell under the brush.
- Missing/undecodable WorldLayer TEX files cannot be displayed. WorldLayer preview rebakes may be expensive for large source tiles and are performed only when slot assignments change; normal brush strokes only update the weight image.
- Colour painting (RGB565 / BC2), new texture import, rotation/projection settings and full original LandPS parity are later stages.

## Code

- `GenesisRebuild/src/terrain_paint.rs`: editable CPU weight atlas, WorldLayer browser/thumbnail cache, per-cell slot IDs, paint operations, snapshots, tests.
- `GenesisRebuild/src/main.rs`: picking, brush, active dock, material rebuild, GPU uploads and safe Save As guard.
- `GenesisRebuild/src/terrain_material.rs` and `src/terrain_splat.wesl` remain the runtime splat renderer.

## Checks

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo test -p genesis --bin genesis
```

A Windows `cargo check` validates compilation; visual GPU operation still needs a real ClientData test with the editor. The new Genesis unit tests cover normalization, undo/redo, missing cells and slot assignment.
