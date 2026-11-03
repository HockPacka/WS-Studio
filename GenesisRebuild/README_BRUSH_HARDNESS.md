# Terrain Brush Hardness (Sculpt/Texture/Color)

The previously displayed single radius circle now becomes **two concentric
circles**: outer Size boundary and the inner Hardness boundary. The region
inside the inner ring receives full brush strength; the edge fades to zero
using a smoothstep profile whose steepness is controlled separately by the
existing F/O slider. Defaults: Hardness 0.58, F/O 0.58.

The same shared `brush_profile::influence` helper is used for height Sculpt,
Texture Brush and Color Brush, so the inner ring marks the real full-strength
region. The original classic/beige Genesis UI layout is unchanged: a new
Hardness slider is simply added to existing tool properties, including
floating brush panels.

Hardness 0: inner radius collapses to the center, only outer ring visible.
Hardness 1: hard edge at full radius, coincident inner ring hidden.
Clutter masking remains a binary radius brush and still shows one ring,
because its edge does not support opacity/feather. Terrain cursor radius
is a screen-space **approximation** of metres, not yet a true 3D contour
following terrain geometry.

QA:
- Check Hardness 0.0 / 0.5 / 1.0 and F/O 0.0 / 1.0 while painting.
- Verify identical inner and outer boundaries for Brush, Texture and Color.
- Undo/Redo and native Save-As stay unchanged; source assets remain read-only.
- CI compiles `genesis` and `genesis --tests`; run `cargo test -p genesis brush_profile`
  separately to execute new profile tests and verify the UI on a Windows GPU.
