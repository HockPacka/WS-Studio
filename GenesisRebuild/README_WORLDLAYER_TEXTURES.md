# Genesis: echtes WorldLayer-Terrainmaterial (erste Renderstufe)

Implementiert im Branch `feature/genesis-raw-area-3d`.

## Datenpipeline

```text
Originale .area
  bit 1 => 4 WorldLayer IDs pro Zelle
  bit 29 => 65x65 normalisierte 4-Kanal-Blendgewichte
  bit 2 => alternative 65x65-Authoring-Gewichte (Fallback)
          |
ClientData[/ClientDataEN]/DB/WorldLayer.tbl
  ID -> ColorMapPath, NormalMapPath, MetersPerTextureTile
          |
ClientData/Art/.../*.tex (nur benötigte Layer)
  GFX header, BGRA, RGB565, BC1/BC2/BC3 -> RGBA8
          |
CPU Terrain-Atlas 1024x1024, 16x16 Zellen, je 64x64 Pixel
  gewichtete vier Diffuse-Layer, echte UV-Skalierung
          |
Bevy StandardMaterial.base_color_texture
  + Mesh3d UV0 = x/256, z/256
```

Der Editor wählt beim Laden einer AREA standardmäßig den **Textured**-Modus. Im rechten **AREA-Dock** kann jederzeit zwischen Height, RGB565, Layer IDs, Zone IDs, Blend und Textured gewechselt werden. Im Textured-Modus sind die Vertexfarben neutralweiß, damit das tatsächliche Albedo nicht durch Debugfarben verändert wird.

**Keine Originaldatei wird geändert oder konvertiert.** Der Index aus ClientData/ClientDataEN löst Pfade auf, die für die AREA benutzten TEX-Daten werden gezielt gelesen, die Pixel landen nur im RAM/GPU-Bild. Die TEX-Dekodierung wählt einen Mip bis maximal 256 Pixel Kantenlänge, um den Arbeitsspeicher begrenzt zu halten.

## Unterstützte Formate

- WorldLayer-TBL (LBTD): Felder `ID`, `ColorMapPath`, `NormalMapPath`, `MetersPerTextureTile`; gepackte Typen 3/4/11/20/130
- TEX Header Version 3, Bildformate BGRA 0/1, RGB565 5, Gray 6, BC1 13, BC2 14 und BC3 15
- Gewichtskanäle aus AREA bit29, alternativ bit2, normalisiert vor dem Layer-Mix

## Ausdrücklich noch unvollständig

- **Kein finaler WildStar-GPU-Terrainshader**: Die erste Stufe mixt auf der CPU und rendert eine StandardMaterial-Textur. Dadurch ist echtes vierlagiges Albedo sichtbar, aber nicht die vollständige originale Materialberechnung. Ein WGSL-Layer-Shader mit zusätzlichen Maps kann danach folgen.
- **TEX mit WildStars JPEG-artiger Kompression** (`is_jpg`): wird mit klarer Fehlermeldung nicht dekodiert. Bei nicht lesbaren Layer-Texturen wird nur für diese Layer auf die tatsächlich in AREA enthaltene RGB565-Farbmap zurückgegriffen. Falls gar keine TEX-Textur verwendbar ist, wird die bisherige Höhen-Vorschau beibehalten.
- Kein Normal-/Specular-/Parallax-Shading, kein BC1 bit17/18-Korrekturpfad, keine endgültige WildStar-Bit13-/Layer-Tint-Interpretation
- CPU-Atlas nutzt nächstgelegenen Texel und vorläufige 64x64 Gewichtsauflösung je Zelle. Für visuelle Parität sind bilineare Gewichte, Filterung und korrekte sRGB/linear-Gewichtsrechnung nachzurüsten.

Im AREA-Dock erscheinen die Anzahl gefundener Layer-IDs, dekodierter Texturen und konkrete Fehler für fehlende bzw. nicht unterstützte Formate.

## Test

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo fast
```

Im Client-Root-Dialog den WildStar-Root auswählen und anschließend über `File -> Open AREA...` eine echte WildStar-`.area`-Datei laden. In `AREA -> Textured` den Materialstatus prüfen.

Referenzen: `HockPacka/WS-Tools/wowdecomp/Engine/Source/Area3/Tbl.cpp`, `tools/tbl_dump.py`, `tools/blender_addon/wildstar_m3/tex.py`, `docs/area_format.md`, `docs/terrain_blocks_dbg39.md`, `docs/terrain_texture_fixes_dbg40.md`.
