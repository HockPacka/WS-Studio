# Genesis AREA height editing – first implementation

## Scope

This is a **height-only** standalone AREA editor. It does not modify WildStar's original files or game archives and does not yet write terrain colors, texture weights, roads, props or water. World-streamed zones remain read-only.

## Usage

1. Configure an indexed WildStar ClientData root.
2. Keep **World > Open AREA standalone (editable)** enabled (default). Open a source `.area` through **File > Open AREA...**. Use **Open Zone...** when you want read-only world streaming instead.
3. Select the **Sculpt** dock; click/drag on terrain with the **left mouse button**. The yellow ring previews brush influence. Right mouse button continues to rotate the camera and middle mouse button pans.
4. Select **Normal (Raise / Lower)**, **Smooth**, **Flatten to Height**, **Add Noise**, **Clone Height** (Ctrl/Shift+Click sets source anchor), or **Stamp Geometry** (`Dome`, `Plateau`, `Ridge`, `Crater` profiles — click, hold the mouse button, and drag up/down to dynamically control the stamp height/strength). Brush Size is multiplied by 10 metres. Power includes positive/negative values; hold **Shift** to reverse the sign while painting. Brush shapes (`Circle`, `Chunk`, `Selection`), `Restrict to Selection`, and `Custom Tip` apply across both Sculpt and Paint tools.
5. **Edit > Undo / Redo** (also Ctrl+Z, Ctrl+Y) work one entire mouse stroke at a time. A history of 24 strokes is kept.
6. **File > Save As...** or the Sculpt dock's **Save AREA As...** writes a **new** `.area` file (e.g. `YourTile_edited.area`). The editor refuses to overwrite *any* existing file, even if the dialog allows selection. Reopen your exported file to verify the resulting heightfield.

## Exact data handling

- Each AREA is a 16 × 16 grid of cells, approximately 512 × 512 metres; each 32 m cell contains a 19 × 19 `u16` height block. Visible mesh uses the inner 17 × 17 samples. World-space height is `raw / 8 - 2048`, so edits are quantized to 0.125 m.
- The writer updates only changed samples in each affected cell, including shared inner edges and one-sample ghost borders within the AREA. Neighboring cells of a touched boundary vertex are also patched.
- For raw `area` / `aera`, unchanged cells and chunks are byte-identical. For compressed `AERA`, unchanged zlib streams and the LOD prefix are retained **byte-for-byte**, while edited cell streams are recompressed individually.
- Unknown top-level chunks, unrecognized per-cell blocks and subchunks remain untouched. After serialization, the binary is parsed again; height values, cell/prop counts and unrelated top-level chunks are verified *before* the destination is created.
- Saving uses `create_new` and `sync_all`; no writing into the source and no silent overwrite of existing assets. For the first milestone, modifying the external border of an AREA does **not automatically** update a separate adjacent AREA tile. Neighbor-tile seam propagation will require cross-file editing.
- The editor stores an in-memory baseline plus a bounded Undo/Redo stack; exporting a file does not reset Undo, nor does it silently replace the original in memory.

## Implementation

- `crates/wildstar_formats/src/area.rs`: `RawArea::with_height_changes`, supports uncompressed and zlib-compressed input, strict structural checks, tests.
- `src/terrain_edit.rs`: grid, ray hit testing, brush math (`Raise`, `Smooth`, `Flatten`, `Noise`, `Clone`, `Stamp`), quantization, bounded per-stroke undo/redo, Save As.
- `src/terrain.rs`: regenerate render mesh and normals from a live grid.
- `src/main.rs`: input, UI controls, live scene refresh and loading lifecycle.

## Not yet implemented

- Editable world streaming (live multi-tile sculpting without standalone export).
- Drag visual checks, saving/reopening with representative original WildStar files, and comparison to the original Genesis output.

## CI and interactive check

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo run
```

Try an uncompressed source file and a compressed source file, paint across a cell edge and repeat after Undo, Redo and Save As. Check that the original stays untouched and that a reloaded export produces the same terrain in the viewport.
