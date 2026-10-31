# Genesis Terrain Render Options

This is an editor **preview-only** feature for the native WildStar `.area` WorldLayer renderer. It changes neither source data nor the output of native `Save AREA As`.

## Where to find it

Open a textured standalone `.area` with ClientData indexed, then use the **Render** tab in the right Genesis dock. The **Paint** tab also has a **Render Options** shortcut.

Select **Activate Textured Terrain** if a height/diagnostic view was active.

## Macro-color source

- **Auto (default)**: original priority — Bit 3 RGB565, falling back to Bit 13 BC2 RGB.
- **Bit 3 only**: visualize original 65×65 RGB565 attributes, without the Bit 13 fallback.
- **Bit 13 only**: visualize BC2/DXT3 compressed color attributes even when Bit 3 exists in the same cell.

Cells with no data for the selected source are displayed with neutral 128/255 macro-color, *not* with synthesized or mixed game data. Runtime switches build a temporary 1024×1024 RGB atlas; original data is unchanged. Painted RGB texels are overlaid on all selected source views to keep Color Brush edits visible, but export still updates native color blocks according to the codec rules.

**Limitation:** the per-source switch currently works only on a loaded **standalone AREA**. Streaming tiles keep the existing automatic source priority. Other shader settings (normal-map switch, tint, debug shading and texture-repeat multiplier) apply to all loaded splat materials.

## Shader options

| Option | Result |
|---|---|
| Tint Strength | 0 = no macro-color multiplication; 1 = native tint intensity |
| Gamma-space tint | Toggle gamma-space vs linear-light tint multiplication |
| Texture Repeats | 0.25×–8× the WorldLayer texture repetition rate, render-only |
| Use normal maps | Enable or disable decoded WorldLayer tangent-space normals |
| Normal Strength | 0–2× normal map XY perturbation (when normals are enabled) |
| Reset Render Options | Restore original render defaults |

## Render/debug views

| View | What it draws |
|---|---|
| Lit WorldLayer + PBR | Four WorldLayer diffuse maps with weights, macro tint, normals and Bevy PBR lighting |
| Unlit WorldLayer albedo | Diffuse texture blend without tint or lighting |
| Weightmap RGB | Weight channels of slots 0, 1, 2 (slot 3 isn't part of RGB composite) |
| Selected layer weight | Grayscale 0–1 weight for any chosen layer slot 0–3 |
| Macro-color RGB | Raw selected Bit 3 or Bit 13 RGB texture, unlit |
| Bit 13 BC2 alpha (raw) | Raw BC2 four-bit alpha (expanded 0–255), unlit grayscale |
| Surface normals | World-space normal orientation displayed as RGB |

**BC2 alpha is not treated as terrain opacity.** Its WildStar shader meaning remains unresolved. This view is a debug inspection aid only.

## Files

- `crates/wildstar_formats/src/area/metadata.rs` — separate `color_bc2` decoder, BC2 alpha nibble decoder and preserved Bit 3 priority.
- `src/terrain_material.rs` — packs original BC2 alpha into the tint-map alpha channel.
- `src/terrain_paint.rs` — original per-source RGB caches, read-only preview switching and painted RGB overlay.
- `src/terrain_splat.rs` and `terrain_splat.wesl` — uniform render controls, normal strength and debug visualizations.
- `src/main.rs` — new **Render** tab and live image upload.

## Test expectations

The Rust unit tests validate Bit 3/13 precedence, BC2 nibble order and source switching, without writing original files. GitHub Actions separately compiles the editor. These checks **do not render a real game scene** or validate the entire WESL/WGPU render pipeline; test with representative original WildStar AREA assets before considering visual parity achieved.
