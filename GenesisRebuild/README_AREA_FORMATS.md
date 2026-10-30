# WildStar AREA: native Rust parser + Genesis inspection

The `wildstar_formats` crate is a **read-only, Bevy-independent** Rust library. The native `.area` / `AERA` reader was moved from `GenesisRebuild/src/area.rs` to:

```text
GenesisRebuild/
├── crates/wildstar_formats/
│   ├── Cargo.toml
│   └── src/
│       ├── lib.rs
│       ├── area.rs
│       └── area/metadata.rs
├── src/
│   ├── main.rs
│   ├── area_ui.rs
│   └── terrain.rs
└── Cargo.toml
```

The library does not need a DLL, Python, JSON or exported assets. `area::RawArea::from_path(path)` loads an original binary tile.

## Decoded data (source: WS-Tools)

- Header version and regular `area/aera` or zlib `AERA` variant.
- Top-level raw chunks `KNHC/CHNK`, `pORP`, `TRUC`, `OMHD`; chunk offsets and payloads.
- Indexed 16×16 terrain cells, flags, all 32 block sizes, original block payloads and cell subchunks.
- Heights: bit 0, 19×19 `u16` (one-sample overlap), rendered 257×257 grid, `height = raw/8 - 2048`.
- WorldLayer: bit 1, four `u32` layer IDs per cell.
- Authoring weights: bit 2 (65×65 four raw nibble channels, **not normalized**) and bit 29 (65×65 normalized four-channel packed weights).
- Bit 3: 65×65 RGB565 raster, converted to RGB8 for previews.
- Bits 6/7: four corners, each with four WorldSky IDs and four weights.
- Bits 16/28: 64×64 zone selector and flags, four WorldZone IDs, road bit 0, clutter suppression bit 5; sample histograms and dominant ID.
- Bit 27: 64×64 clutter selectors, four 2-bit fields per sample; per-layer histograms.
- Top-level `pORP`: 104-byte prop records, UTF-16LE model path, position, quaternion, scale, tint; malformed count rejected, unknown record bytes preserved.
- Bits 13,14,17,18,19,20,31 contain BC1/BC2 compressed data, and other flag bits are kept as original raw bytes with unresolved descriptions.

The role of unknown flags, all subchunk payloads, alternate texture paths, BC1/BC2 alpha semantics and water/curve payloads is **not claimed to be decoded**.

## Genesis interface

Open **File → Open AREA…**, then **Window → AREA Inspector**, or choose the **AREA** dock tab. Select a cell from 0–255 to inspect its real data. The AREA dock also offers five terrain preview modes:

| Preview | Meaning |
| --- | --- |
| Height | Existing illustrative height/slope colors |
| RGB565 | Original terrain color map where bit 3 exists |
| Layer IDs | Stable debug color per WorldLayer ID, **not original material** |
| Zone IDs | Stable debug color per WorldZone ID at the selected 64×64 zone samples |
| Blend | Heatmap of selected weight channel from bit 29 or bit 2 |

Unavailable fields fall back to neutral height colors. Layer IDs do not yet resolve to texture paths from `WorldLayer.csv`. Models are listed as placements; M3/I3 props are not rendered yet. The input `.area` is never modified.

## Tests

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo run -- "../WildStarModelStudio/demo/Hills.area"
```

Unit tests cover original Hills.area, compressed AERA handling, malformed chunk bounds, WorldLayer/Zone/Sky/Clutter metadata, RGB565 and weight decoding, and prop record bounds/path/transform. Windows CI tests the library first and then checks the Bevy application. A visual/GPU smoke test remains necessary on Windows.

Sources: `HockPacka/WS-Tools/docs/area_format.md`, `tools/area_reader.py`, `tools/area_inspect.py`; top-level props follow the documented AdtBuilder layout.
