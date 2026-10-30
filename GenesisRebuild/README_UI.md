# Genesis Rebuild — Bevy UI replica (Phase 1)

This is an **original-window-layout visual recreation**, NOT a modern reimagining of the WildStar Genesis editor. The UI targets the attached reference screenshots \`WILDSTAREDITOR/1.png\`–\`10.png\`.

## Run
From \`GenesisRebuild/\`:

\`\`\`powershell
cargo run
\`\`\`

Requires a current Rust stable toolchain and a graphics driver supported by Bevy 0.20. Dependencies are pinned to Bevy 0.20.0 / bevy_egui 0.43.1 rather than the unstable Bevy GitHub main branch. **Cargo.lock** was generated against an older Git dependency and needs regenerating with \`cargo generate-lockfile\` for reproducible builds (the initial \`cargo run\` can also update it). We did not distribute a prebuilt .exe.

## What is reproduced?
- Classic **cream/light-gray Windows-era** menu bars and tight spacing, 3 dense textual ribbon rows.
- 44 small, colored **icon placeholders** with hover tooltips, grouped like the original ribbon.
- Right-side floating **Color Brush Properties** and **Color Palette**, modeled on screenshot **7**.
- Alternative floating **Texture Brush**, **Clutter Preset**, **Object List**, **Snap Points**, and **Named Region** panels.
- Bottom **Occlusion** strip; toggleable **Land Chunk Grid**.
- Original reference screenshots **7 / 9 / 10** cropped into a static viewport illustration, selectable via **View** menu.

The app uses Tahoma from \`C:\Windows\Fonts\tahoma.ttf\` when available; it **does not bundle Windows font files**.

## Important limitations
This is a **UI-only mock**. Icons are intentionally drawn as temporary colored symbols, not original Carbine image assets. Buttons, brush sliders, tabs, and checkboxes can be clicked or selected, but **they do not sculpt terrain, import models, save scenes, or execute editor commands**. The viewport is a static cropped reference screenshot, **not an interactive 3D world**.

Exact pixel identity is not claimed: source images are oblique photos of a display, not lossless UI captures; some labels and icon artwork cannot be recovered precisely. Layout is tuned around a **1280×760** window; on other resolutions the floating panels can be dragged. Compare screenshot 7 to the running program.

## Next visual pass
Replace temporary toolbar glyphs with individually authored pixel icon assets reconstructed from higher-resolution references, then tune pane rectangles, typography, palette spacing, icon colors and per-screenshot arrangements. Do this **before implementing any editing functionality**.

## Files
- \`src/main.rs\` — Bevy + egui implementation.
- \`WILDSTAREDITOR/*.png\` — user-supplied references already in the repository.
- \`TECHNICAL.md\` — existing format-research notes, unchanged.

This branch does **not** change other WS-Studio tools.
