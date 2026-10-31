# .m3 und .i3 lesen

Native Rust-Reader in `crates/wildstar_formats` (keine DLL, kein JSON). Portiert aus WS-Tools
(`wowdecomp/Engine/Source/Model3/M3Reader.cpp`, `Struct3/I3Reader.cpp`, `docs/m3_format_spec.md`, `docs/i3_dgn_format.md`).

| Modul | Format | Inhalt |
|---|---|---|
| `m3` | `LDOM` v100 | Vertices (Position, Normal, UV, Bone-Gewichte), Indizes, Meshes (+ Hidden-Flag `flags & 0x0A == 0x0A`), Texturen, Materialien, Bones, Clips, Bounds |
| `i3` | `FEDS` v30 (Sector) | Positionen, Normalen, UV0/UV1, Vertexfarben, Indizes, Submeshes (Collision-only wird erkannt) |
| `i3` | `FEDI` v41 (Modell) | Sektorliste (+ Exterior-Flag), Portale, Material-Sets mit Texturpfaden |

Ein `.i3`-Bauwerk besteht aus `X.i3` plus je einer `X.<Sector>.i3` pro Sektor (`I3Model::sector_path`).

## Im Editor
`props.rs` ersetzt den Platzhalter-Würfel eines Props durch das echte Mesh, wenn `.m3`/`.i3` im ClientData-Index
gefunden wird (Cache pro Pfad, max. 48 neue Modelle pro Tile-Spawn, Dateien > 64 MiB werden übersprungen).
Nicht lesbare Modelle behalten den Würfel.
Props werden pro Material in Teilmeshes zerlegt; der Texturpfad (M3: erste Material-Ebene, I3: Material-Set `Default_Pass` wenn vorhanden, sonst 0) wird über den Index aufgelöst und mit dem `.tex`-Decoder (max. 512 px) als Farbtextur gesetzt. Fehlt die Textur, bleibt die Einfärbung.

### Direkte Modellvorschau
Im File-Menü **Open Model (.m3/.i3)...** wählen (oder **Open Model...** im oberen Toolbar). Die Datei muss in den aktuell indexierten `ClientData`-/`ClientDataEN`-Ordnern liegen. Genesis zeigt FEDI-Modelle mit ihren FEDS-Sektoren, einzelne FEDS-Dateien und M3-Modelle im 3D-Viewport, setzt den Kamera-Fokus anhand der Bounds und zeigt die Metadaten im Objects-Dock. Beim Wechsel in die Modellvorschau wird das laufende World Streaming beendet; die Dateien werden nicht verändert.

### M3/I3-Rendering-Ausbau
- M3 liest nun **beide UV-Sets und beide Vertexfarbkanäle** aus den Vertexlayouts. Für den PBR-Vertexfarbkanal wird M3-Color0 mit WildStar-RGB-Multiplikator 2 (`byte / 128`) übernommen; ein nicht vorhandener Farbkanal bleibt neutral.
- Die Geometrie übergibt UV0, UV1 und Vertexfarbe an Bevy. `StandardMaterial` verwendet zunächst UV0; das zweite UV-Set und Color1 sind für einen künftigen WildStar-spezifischen Shader vorhanden, aber **kein Nachweis der originalen Layer-Mischung**.
- I3 lädt sowohl **FEDI-Strukturen mit mehreren FEDS-Sektoren** als auch **direkt geöffnete FEDS-Sektordateien**. Letztere haben ohne FEDI-Metadatensatz keine Materialtextur und erscheinen mit Fallback-Farbe.
- I3 berücksichtigt Materialindex **und Material-Pass** separat (`submesh.id`: high bits = Material, low byte = Pass); Collision-only-Submeshes werden weiterhin ausgeschlossen. Vertexfarbwerte und UV1 bleiben erhalten. Bei mehreren Materialsets wird aktuell `Default_Pass` bevorzugt, andere Varianten sind nicht editierbar.
- I3 verwendet einen 64-Bit-Key `(Sektor, Vertexindex)` statt einer Kollisionsträchtigen 24-Bit-Kombination. Fehler bei fehlenden Sektoren sind über die Metadaten nachvollziehbar.


## Material-Eigenschaften
Pro Material (`docs/m3_materials.md` in WS-Tools) werden gelesen und auf ein `StandardMaterial` abgebildet:

| WildStar | Bevy |
|---|---|
| Blend-Modus (Header +0x14): 0 opak, 1 Cutout, 2 Alpha, 3 Add, 4 Alpha-Add, 5/6 Multiply | `AlphaMode` Opaque / Mask(0.5) / Blend / Add / Multiply |
| Opacity (Layer-DP +0x60) | Alpha der Basisfarbe |
| Color-Mod (Layer-DP +0x108, HDR-Multiplikator) | Multiplikator der Basisfarbe |
| Gloss (Layer-DP +0x30) | `perceptual_roughness = 1 - gloss` (min. 0.15) |
| Glow (Layer-DP +0x48) | Emissive = Color-Mod × Glow, Emissive-Textur = Farbtextur |
| Normal-Textur (DXT5nm oder RGB) | `normal_map_texture`, Tangenten per `generate_tangents` |
| I3 Material-Kind 5 (Decal) | Alpha-Blend |

Prüfen ohne ClientData: `GENESIS_PROP_MODEL=Avatus.m3 GENESIS_PROP_DEMO=out.png cargo run` rendert ein Modell mit diesen Parametern (ohne Texturen).

## Metadaten im Editor
Im Objects-Dock zeigt jeder Prop-Eintrag alle Modell-Metadaten (Vertices, Dreiecke, Bounds, Bones, Clips, Texturen, Sektoren, Portale, Material-Sets). Jeder referenzierte Pfad wird gegen den ClientData-Index geprüft und mit `[OK]` bzw. `[MISSING]` markiert.

## Noch offen
- Skinfx-Texturen, Mehrschicht-Materialien (4 Layer, Layer-Gewichte aus Vertexfarbe 1) und Material-Varianten (`Aurin_Autumn`); nur Layer 0 wird gerendert.
- Animierte Material-Parameter (nur der erste Key), Parallax/Height, originalgetreues I3-Vertexfarb-Blending und UV1-abhängige Spezialshader.
- Skelette: Die acht nativen Keyframe-Tracks pro M3-Bone werden nun dekodiert (Scale-Half3, Quaternion-i16 und Translation-f32), inklusive Zeitstempeln und Interpolations-API. **GPU-/CPU-Skinning und tatsächliches Abspielen der Clips fehlen noch**; Modelle werden weiterhin statisch dargestellt. Alternative Pose-Layers 1/3/5/7 sind nur als Rohtracks verfügbar.
- M3: Spezial-Emittersysteme, Ribbon-Rendering, Licht- und Kamera-Entities sowie sekundäre Animations-Pose-Layer-Interpretation fehlen.
- Achsen/Skalierung der Props gegenüber dem Terrain sind ungeprüft (Transform wird wie beim Marker übernommen).

## Prüfen
```bash
cargo test -p wildstar_formats
cargo run -p wildstar_formats --example dump_model -- Avatus.m3
```

> **Verifikationsstand:** Parser-Unit-Tests decken nun die M3-Zweitkanäle, M3-Bonetracks (inkl. Quaternion-Interpolation) und I3-Passkodierung ab. Original-WildStar-GPU-Vergleich, Animationsplayback und vollständige Sondermaterialien sind weiterhin nicht nachgewiesen.
