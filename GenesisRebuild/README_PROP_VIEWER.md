# Genesis Prop Viewer (M3/I3)

**Branch:** `feature/genesis-m3-i3-render-parity` – read-only development preview.

## How to open

1. Run Genesis and select a WildStar root containing `ClientData` (and optionally `ClientDataEN`).
2. Open **Objects > Prop Viewer**, **Window > Prop Viewer**, or click **Prop Viewer** on the ribbon.
3. Browse the indexed files. Search accepts any substring of the virtual path (e.g. `avatus`, `art/creature`), with **M3 + I3 / M3 / I3** filters. The library is sorted and paginated (60 models per page).
4. Click a model to load it in the existing 3D viewport. `File > Open Model (.m3/.i3)...` remains an alternative.
5. Use **Frame**, **Reset rotation**, **Turntable** (adjustable speed) and per-render-part visibility controls.
6. Expand **Model metadata / references** for mesh/material/bone/clip counts, referenced textures (OK/MISSING), I3 sectors and other parsed fields.

You can also click **View model separately** on a prop entry under the AREA's Objects dock. Opening a model switches away from a running zone stream or AREA; opening a zone again clears the model preview.

## Architecture

- `src/prop_viewer.rs`: indexed asset browser, filters, inspector state, camera commands and turntable.
- `src/main.rs`: Genesis menu, dock, load state and world/model switching.
- `src/props.rs`: shared M3/I3 parser and Bevy mesh/material cache, `PreviewScene`, model metadata.
- `crates/wildstar_formats/src/{m3,i3}.rs`: low-level native binary decoding.

The viewer **does not write to WildStar client files**. It uses one model at a time and hides unavailable/unsupported geometry without inventing replacements. There is a 64 MiB per-file limit, a 400k-triangle limit and a 512 px texture decode limit in the current renderer.

## Coverage and known limitations

- Native M3 geometry, UV0/UV1, vertex colors, materials and static bind-pose preview.
- Native I3 FEDI + FEDS sector geometry or standalone FEDS preview with a fallback material; material pass selection, vertex color, UV0/UV1 and collision-only filtering.
- The parser reads M3 bone keyframes, but the 3D viewport does **not yet skin or play animations**.
- I3 alternative material sets, full original WildStar custom shader behavior, M3 FX/ribbons/lights and portal-based indoor visibility are **not finished**.
- Part toggles affect the standalone viewer instance only; world props and original files are unchanged.

## Verification

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo run
```

In Genesis, use an actual indexed `.m3` and both a root `FEDI` `.i3` and its `FEDS` sector companion. Validate geometry visibility, texture resolution, camera focus, switching back to AREA/zone, missing assets, the search filter and turntable. Passing compile/tests is not equivalent to a verified in-game visual match.
