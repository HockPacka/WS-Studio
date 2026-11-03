# Exact mouse-tip terrain decal (Genesis)

Fix the brush decal being offset from the Windows cursor hotspot.

Bevy Camera::viewport_to_world expects **full-window logical
coordinates**, and internally subtracts the viewport's own origin.
The old code subtracted the egui viewport top-left first, causing a
double-offset whenever menus / docks were visible.

The 3D brush cursor now uses pointer.latest_pos() and passes the
absolute mouse position converted with:
egui_pixels_per_point / camera.target_scaling_factor().
This maintains exact cursor alignment across display DPI (100%/200%)
and Genesis UI zoom (80%/100%/125%/150%). No hand-tuned pixel offsets.
All three brush tools (Sculpt, Texture/Color, Clutter) use this mapping.

Raycast refinement now uses the exact terrain triangle height, like
the decal geometry, rather than bilinear approximation. The cursor
world hit is also the sculpt/paint stroke hit, preventing divergence.

Tests: cursor_tip_keeps_full_window_offset,
cursor_tip_handles_egui_zoom_and_native_dpi.
Manual Windows GPU test: move mouse to each viewport corner and over
hills; hold left button and paint while moving; open right dock;
change Windows display DPI / egui zoom; move into menu to hide brush.

Classic Genesis UI, client asset paths and AREA files unchanged.
