# Genesis terrain-conforming brush decal

The former egui screen-space circle has been replaced by a real **world-space,
terrain-following 3D preview overlay**. It is a transient decal-like mesh,
not a persisted WildStar decal/AREA chunk.

- Mouse raycast hits current editable terrain, then a translucent mesh is
  reconstructed over the terrain under that world-space cursor.
- The surface sampling uses the **same triangle diagonal** as the native
  257x257 terrain mesh; each overlay vertex is offset slightly upward to
  avoid z-fighting and retains 3D camera depth/occlusion.
- Sculpt is amber, Texture/Color Brush green; Clutter Mask light green.
- Outer ring = brush radius in **metres**, inner ring = hardness core.
- Fill opacity uses the same hardness+falloff attenuation as actual
  sculpt/texture/color painting; binary clutter has only an outer ring.
- Preview is hidden outside the viewport, when the pointer misses the
  terrain, on a read-only streamed map, or when another tool is active.
- At tile borders, any triangles with missing height samples are discarded.
- No modifications to existing panel layout, brush sizes, source files,
  native AREA blocks, or asset root requirements.
- The one-frame preview is rendered by egui's post-UI system so cursor
  changes and painting share the same editor input; no extra window/UI.

## Tests / manual QA

Run cargo check -p genesis and cargo check -p genesis --tests.
Unit tests in brush_decal.rs verify projected mesh heights over a
non-flat sample, tile-edge clipping and missing-area safety.
Run cargo test -p genesis brush_decal to execute them if desired.

Manually open a new AREA, sculpt a visible hill, orbit camera:
brush decals should follow heights and remain depth-occluded on slopes,
inner ring and outer ring should match brush dimensions. Mouse leaving
the terrain must hide the overlay; model preview and world streaming must
not show a stale brush. Watch alpha blending and z-fighting on Windows GPU.

This implementation uses geometry projection rather than a screen-space
circle or an engine-managed depth-reconstructed GPU decal shader. A future
shader pass can reduce mesh rebuild costs and exactly reproduce fine
terrain texel footprints without changing the brush preview API.
