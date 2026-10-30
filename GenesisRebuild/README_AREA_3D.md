# GenesisRebuild — Direct RAW AREA 3D Viewport

The classic Genesis UI displays **real 3D terrain rendered by Bevy 0.20.1**. Original `.area` data is read as raw binary Rust structures, without converting to JSON, CSV, or WoW ADT.

## Run on Windows

Requires Rust stable (1.95+). From `WS-Studio/GenesisRebuild`:

    cargo run -- "../WildStarModelStudio/demo/Hills.area"

Without an argument the bundled example Hills.area is opened automatically if it exists. To load your own file, choose **File → Open AREA...**, paste the original `.area` filename, then click **Load AREA**. Select **View → 3D AREA View** to return from static screenshot comparison mode.

## Camera controls

| Action | Input |
|---|---|
| Orbit | Right mouse drag |
| Pan | Middle mouse drag |
| Zoom | Mouse wheel |
| Travel | W / A / S / D while viewport hovered |
| Faster travel | Shift + W / A / S / D |

## Implementation

- `src/area.rs`: read-only `area` / `aera` / `AERA` binary parsing; chunk offsets; 256 indexed terrain cells; all 32 raw blocks; unknown subchunks and original bytes retained in memory. Compressed `AERA` cells are inflated directly with `flate2`.
- `src/terrain.rs`: 257 × 257 visible vertex heightfield; original 19 × 19 raw border layout; 32-meter cells; a 512-meter tile; height formula `u16 / 8 - 2048`. Missing source cells produce mesh holes.
- `src/main.rs`: Camera3d, directional light, input navigation, a viewport constrained behind classic UI, load-by-path control, mesh replacement, status.
- `WildStarModelStudio/demo/Hills.area`: real repository example used by the Rust test.

## Scope

The terrain is rendered with **temporary height/slope vertex colors**. It is not yet using WildStar's BC1/BC2 terrain textures and four-layer blend weights. Props, original vegetation, sky and water remain preserved in raw data but are not drawn. Only **one AREA tile** is loaded at a time. The UI tools are still visual placeholders; no terrain editing or saving is enabled.

## Verify

    cargo check
    cargo test --bin genesis

Windows CI performs compile and binary-reader tests. Successful CI does **not** prove GPU presentation or pixel-perfect UI similarity; this still requires visual runtime testing. The input `.area` file is never modified.