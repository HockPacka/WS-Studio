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

**Keine Originaldatei wird geändert oder konvertiert.** Der Index aus ClientData/ClientDataEN löst Pfade auf, die für die AREA benutzten TEX-Daten werden gezielt gelesen, die Pixel landen nur im RAM/GPU-Bild. Die TEX-Dekodierung wählt einen Mip bis maximal 1024 Pixel Kantenlänge, um den Arbeitsspeicher begrenzt zu halten.

## Unterstützte Formate

- WorldLayer-TBL (LBTD): Felder `ID`, `ColorMapPath`, `NormalMapPath`, `MetersPerTextureTile`; gepackte Typen 3/4/11/20/130
- TEX Header Version 3, Bildformate BGRA 0/1, RGB565 5, Gray 6, BC1 13, BC2 14 und BC3 15
- Gewichtskanäle aus AREA bit29, alternativ bit2, normalisiert vor dem Layer-Mix

## Ausdrücklich noch unvollständig

- **Kein finaler WildStar-GPU-Terrainshader**: Die erste Stufe mixt auf der CPU und rendert eine StandardMaterial-Textur. Dadurch ist echtes vierlagiges Albedo sichtbar, aber nicht die vollständige originale Materialberechnung. Ein WGSL-Layer-Shader mit zusätzlichen Maps kann danach folgen.
- **WildStar-JPEG-TEX**: TYPE1/TYPE2/TYPE3 werden nun ebenfalls nativ entschlüsselt. Der Decoder verwendet die bekannten Huffman-/DCT-Tabellen aus den WS-Tools-Quellen und ist mit synthetischen Testbildern geprüft. Ein vollständiger Vergleich aller Original-TEX-Dateien steht noch aus. Bei nicht lesbaren Layern bleibt die original gespeicherte RGB565-Farbkarte als Fallback erhalten.
- Kein Normal-/Specular-/Parallax-Shading, kein BC1 bit17/18-Korrekturpfad, keine endgültige WildStar-Bit13-/Layer-Tint-Interpretation
- CPU-Atlas nutzt nächstgelegenen Texel und vorläufige 64x64 Gewichtsauflösung je Zelle. Für visuelle Parität sind bilineare Gewichte, Filterung und korrekte sRGB/linear-Gewichtsrechnung nachzurüsten.

Im AREA-Dock erscheinen die Anzahl gefundener Layer-IDs, dekodierter Texturen, Hinweise und konkrete Fehler. Auch direkt im 3D-Viewport wird `TEXTURED` oder `TEXTURED unavailable | RGB565 fallback` samt Grund angezeigt. Die Compilerwarnung zum bisher ungenutzten `notes`-Feld ist behoben, indem die Hinweise tatsächlich dargestellt werden. Falls keine einzige TEX dekodiert wird, enthält die Fehlermeldung jetzt die ersten fünf konkreten Layer-/Dateifehler. Die UI wechselt beim Laden einer AREA auf den AREA-Dock.

## Test

```powershell
cd GenesisRebuild
cargo test -p wildstar_formats
cargo check -p genesis
cargo fast
```

Im Client-Root-Dialog den WildStar-Root auswählen und anschließend über `File -> Open AREA...` eine echte WildStar-`.area`-Datei laden. In `AREA -> Textured` den Materialstatus prüfen.

Referenzen: `HockPacka/WS-Tools/wowdecomp/Engine/Source/Area3/Tbl.cpp`, `tools/tbl_dump.py`, `tools/blender_addon/wildstar_m3/tex.py`, `docs/area_format.md`, `docs/terrain_blocks_dbg39.md`, `docs/terrain_texture_fixes_dbg40.md`.

## Runtime-Splatting (Pixel-Shader, wie LandPS)
Statt eines gebackenen Atlas mischt `src/terrain_splat.wesl` die vier WorldLayer-Texturen jeder 32-m-Zelle pro Pixel:

- **Texture-Array** aller im Tile benutzten Layer (Albedo sRGB + Tangent-Normal), mit Mip-Kette, Repeat und 16x Anisotropie. Größe 512 px (Einzel-Tile) bzw. 256 px (Streaming, begrenzt den Speicher).
- **Gewichtskarte** 1024² (4 Gewichte je Pixel), **Macro-Tint** 1024² (neutral 128), **Layer-Index je Zelle** 16×16, **Kachelgröße je Layer** (`meters_per_tile`) im Uniform.
- Farbe = Σ Gewicht × Layer(Weltmeter / Kachelgröße) × Tint; Normal-Layer werden gemischt und über die Tangente ins Lighting gegeben.
- Debug-Ansichten (1–4) laufen unverändert über die Vertexfarben; nur Ansicht 5 aktiviert den Splat-Shader.
- Fällt der Splat-Pfad aus (keine Texturen dekodierbar), greift weiter der alte Atlas.

### Selbsttest ohne WildStar-Daten
```bash
GENESIS_SPLAT_DEMO=out.png cargo run      # rendert prozedurale Layer, speichert out.png, beendet sich
```
Headless (Linux): `Xvfb :99 &`, `DISPLAY=:99 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json`.

### Nicht geprüft
Mit echten ClientData-Texturen wurde der Shader nicht gesehen. Offen: Vorzeichen der Normal-Y-Achse (DirectX vs. OpenGL), exakte Blend-Funktion der Original-Shader-Permutation.
