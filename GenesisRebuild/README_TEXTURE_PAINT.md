# Genesis WorldLayer Texture Painter — native AREA format support

The Genesis editor now has an experimental **native texture Save As path for known WildStar AREA layouts**. Unsupported compressed companion formats are rejected before any destination file is created. The original ClientData files remain read-only.

## Texture editor

- **WorldLayer Browser:** reads `WorldLayer.tbl`, previews original TEX textures and displays material IDs / paths / normal-map availability / tiling.
- **Per-cell four material slots:** assign WorldLayer IDs to the four slots of an editable 32m AREA cell.
- **Paint / Erase / Smooth:** edits a 1024x1024 RGBA8 weight atlas in CPU memory and updates the shader's splat image. Uses brush strength/radius/falloff and whole-stroke Undo/Redo (16 levels).
- Painting by WorldLayer ID will affect only cells that have already assigned that same ID. The optional **Restrict to Selection** isolates a cell.

## Native AREA export: supported vs blocked

Supported (native, data-preserving where possible):
- **Bit 1**: four WorldLayer u32 IDs, written only when a cell's slot assignment changes.
- **Bit 2 and bit 29**: 65×65 four-nibble maps. Changed texels are quantized with a largest-remainder method so all four nibbles sum to 15; untouched source texels remain byte-identical.
- **Bit 17 and bit 18 (BC1/DXT1)**: changed 4×4 BC1 regions are recompressed from the edited weights. The signed correction block is set to a neutral value **in changed regions only**. All untouched BC1 blocks remain byte-identical.
- Supports both uncompressed `aera/area` and zlib-compressed `AERA` containers via the shared `RawArea::with_cell_block_changes` writer. All unrelated top-level chunks, unknown per-cell blocks and subchunks, and unmodified zlib cell streams are retained.
- **Combined height + texture Save As:** builds and validates a new standalone `.area` using the existing height writer and the new texture block writer. The destination is created with `create_new`, so existing files, including source game assets, cannot be overwritten.

**Explicitly blocked**:
- Editing weights in cells containing **bits 19/20**; their relationship to bit 29 needs further disassembly and native roundtrip validation.
- Source cells without a known writable weight representation, duplicate cell edits, missing cells and changes that would alter block sizes.
- Storing edited texture weights as a replacement for `.tex` assets or changing the original client tables. Only `.area` layer mappings and blend weights are in scope.

**Known fidelity limits**:
- The BC1 encoder is **lossy**. Its output is an approximation of 4×4 target weights. Neighbor pixels inside a re-encoded 4×4 region can change slightly even if they were not painted.
- Changes to the 64×64 interior weight atlas do not yet regenerate every 65th edge texel/outer AREA border. This can produce seams along some cell/AREA boundaries. Cross-AREA writes are not implemented.
- WildStar's material permutations and any unverified functions of the BC1 companion bits are not yet reproduced. If a cell uses unknown combinations, editing must fail closed.
- Visual GPU verification with real game data is still required. Synthetically validated bytes are not a guarantee of exact retail WildStar rendering.

## Steps to test

1. Open an original `.area` in **standalone editable mode**.
2. Select the **Paint** tab → **Texture Brush**, select one of the four cell slots, and choose/assign a WorldLayer from the browser.
3. Paint, erase, smooth, undo and redo until satisfied.
4. Use **Save AREA As...**. Choose a **new, unused** output path.
5. If the source contains unsupported bits 19/20, the editor will **refuse** that texture export. This is expected and protects the original.
6. Re-open the exported AREA and inspect texture weights, slopes and previously unchanged props/water. Compare results against the original.

## Validation

- `cargo test -p wildstar_formats`: raw/zlib block-writer roundtrips, original chunk preservation, native texture packer tests and unsupported-companion rejection.
- `cargo check -p genesis`: Bevy editor integration.
- `cargo check -p genesis --tests`: compile the editor test targets.

The format writer lives under `crates/wildstar_formats/src/area/texture_write.rs`. The shared byte-preserving block writer is in `area.rs`; the editor's combined export is in `src/terrain_paint.rs`.

**Next step**: verify bit 29's compressed companion pair **19/20**, implement its native encoder, improve BC1 error quality and border propagation, then validate with real retail maps before considering the system fully production-safe.
