# Genesis WorldLayer Texture Painter — native AREA format support

The Genesis editor now has an experimental **native texture Save As path for known WildStar AREA layouts**. Unsupported compressed companion formats are rejected before any destination file is created. The original ClientData files remain read-only.

## Texture editor

- **WorldLayer Browser:** reads `WorldLayer.tbl`, previews original TEX textures and displays material IDs / paths / normal-map availability / tiling.
- **Per-cell four material slots:** assign WorldLayer IDs to the four slots of an editable 32m AREA cell.
- **Paint / Erase / Smooth:** edits a 1024x1024 RGBA8 weight atlas in CPU memory and updates the shader's splat image. Uses brush strength/radius/falloff and whole-stroke Undo/Redo (16 levels).
- Painting by WorldLayer ID will affect only cells that have already assigned that same ID. The optional **Restrict to Selection** isolates a cell.

## New: native Terrain Color Brush (RGB565 + BC2)

- In **Paint → Color Brush**, use the RGB picker and **Color / Darken / Lighten / Smooth**. Size, Power and Falloff apply. The brush operates on the existing 1024×1024 macro-tint atlas, updates the shader in real time and shares stroke-level Undo/Redo with texture painting.
- **Block 3**: edited pixels are converted back to native RGB565 in the original 65×65 authoring raster. Unedited texels are copied byte-for-byte.
- **Block 13**: changed 4×4 BC2/DXT3 RGB groups use the optimized shared BC1 RGB encoder. The original **8-byte BC2 alpha payload of every block is preserved byte-for-byte**, since the true role of the terrain alpha channel is not yet fully decoded. After export, directly painted pixels in Bit 13 are checked **independently** of Bit 3. This matters when both formats exist in a cell and have different original colors.
- Both blocks are updated together if both are present; edits refuse cells lacking these block types. **A 50/255 per-channel fidelity gate** compares the in-memory result to the native reloaded AREA and blocks poor exports.
- The existing `Save AREA As...` now combines *height, WorldLayer weights and terrain RGB* in the same new non-overwriting file, subject to codec guards.
- Edited RGB samples on the **left/top edges of a cell** now update the duplicated 65th texel in its left, top and top-left neighbours **inside the current AREA**. This covers RGB565 bit 3 and BC2 bit 13 while preserving original BC2 alpha bytes. The outer edge of the AREA is deliberately not propagated into another AREA file.
- The newly added format tests verify raw RGB565, compressed BC2, preservation of unknown BC2 alpha bits and unrelated AREA chunks.

## Phase A: BC1/BC2 fidelity hardening

- The same deterministic optimized BC1 color encoder now serves **bit 17 weights and bit 13 BC2 RGB**. Its initial farthest-pixel candidate is always retained unless a lower 4x4 squared RGB error is found.
- Painting one pixel in a compressed 4x4 block no longer replaces the other original compressed texels with an unrelated raw weight map or Bit 3 preview.
- Before creating a new AREA output, validation checks **Bit 13 directly on painted pixels even where Bit 3 takes render priority**, and compares every source/export BC2 alpha block byte-for-byte.
- New regressions compare quality with the legacy encoder across greyscale gradients, mixed colors, uniform colors, tints and fixed-seed noise, and verify source preservation when Bit 3/13 or raw/BC1 representations disagree.
- This is **format quality and safety**, not proof of retail GPU shader parity. The original game assets and native bit 19/20 encoding are unchanged.

## Native AREA export: supported vs blocked

Supported (native, data-preserving where possible):
- **Bit 1**: four WorldLayer u32 IDs, written only when a cell's slot assignment changes.
- **Bit 2 and bit 29**: 65×65 four-nibble maps. Changed texels are quantized with a largest-remainder method so all four nibbles sum to 15; untouched source texels remain byte-identical.
- **Bit 17 and bit 18 (BC1/DXT1)**: changed 4×4 BC1 regions are recompressed from the edited weights. The signed correction block is set to a neutral value **in changed regions only**. All untouched BC1 blocks remain byte-identical.
- Supports both uncompressed `aera/area` and zlib-compressed `AERA` containers via the shared `RawArea::with_cell_block_changes` writer. All unrelated top-level chunks, unknown per-cell blocks and subchunks, and unmodified zlib cell streams are retained.
- **Combined height + texture + color Save As:** builds and validates a new standalone `.area` using the existing height writer and the new texture block writer. The destination is created with `create_new`, so existing files, including source game assets, cannot be overwritten.

**Explicitly blocked**:
- Editing weights in cells containing **bits 19/20**; their relationship to bit 29 needs further disassembly and native roundtrip validation.
- Source cells without a known writable weight representation, duplicate cell edits, missing cells and changes that would alter block sizes.
- Storing edited texture weights as a replacement for `.tex` assets or changing the original client tables. Only `.area` layer mappings and blend weights are in scope.

**Known fidelity limits**:
- The BC1 encoder is **lossy**, even after optimization. Re-encoded 4×4 regions can change slightly at unedited pixels. The new encoder chooses among actual-pixel, RGB bounds and principal-axis candidates, fits endpoints by least squares, and refines nearby RGB565 codes. It never accepts a candidate with higher squared RGB error than the original farthest-pixel approach. Unedited BC1 weight texels inside changed blocks now come from their **original BC1 source**, and unedited BC2 color texels come from their **original Bit 13 RGB**, not from another attribute's preview.
- Texture-weight edits to x=0/z=0 now propagate into their **intra-AREA neighbour's 65th sample** for raw bit 2/29 and BC1 bit 17/18, including corner neighbours. Encoded BC1 correction samples are neutralised only inside re-encoded blocks. Neighbouring **AREA files** are not edited and cross-tile seams still need a multi-AREA solution. Export rejects absent neighbours, unresolved bit 19/20 neighbour layouts and reloaded seam deviations beyond the safety tolerance.
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

**Current Phase A research:** The **Render → Bit 19/20 Weight Research** panel offers a *read-only, tentative* BC1 decode (using the known 17/18 interpretation as a hypothesis), and reports the selected cell's difference from native bit 29. This is diagnostic evidence, **not validation** of a 19/20 writer. All writes involving the unresolved 19/20 pair remain blocked.

**Next step**: verify bit 29's compressed companion pair **19/20** using real client map samples and shader behavior, implement a native encoder only after validation, add multi-AREA tile-edge propagation, improve BC1/BC2 error quality, and visually verify real retail maps before considering the system production-safe.
