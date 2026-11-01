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

### UV-basierte Tangenten für Normalmaps (Render-Parität)

Die Modellvorschau und alle instanziierten Props/Clutter-Modelle erzeugen ihre
Tangenten jetzt aus M3-/I3-Positionen, **UV0**, Dreiecksindizes und
Vertexnormalen statt aus einer pauschalen Weltachsen-Heuristik. Dabei werden
Tangenten an der Vertexnormalen orthogonalisiert und das Vorzeichen der
Bitangente für gespiegelte UV-Inseln in `tangent.w` gespeichert. Fehlende
oder degenerierte UV-Dreiecke bekommen eine endliche orthogonale
Fallback-Tangente; fehlerhafte Vertex-Streams werden abgelehnt.

Die Berechnung liegt unabhängig von Bevy in
`crates/wildstar_formats/src/tangents.rs` mit Unit-Tests für reguläre UVs,
gespiegelte UVs, degenerierte UVs und fehlerhafte Indexdaten. Testaufruf:
`cargo test -p wildstar_formats tangents`.

**Grenzen:** Das repariert die geometrische Tangentenbasis, aber bestätigt
weder die korrekte WildStar-Normalmap-Packing-Erkennung noch die Normal-Y-
Konvention oder GPU-Bildparität. Für gegenüberliegend gespiegelte UV-Inseln,
die dieselben Vertex-Indizes teilen, ist zusätzlich ein Seam-Split nötig.

### Konsistente M3/I3-Normalmap-Kanäle

`crates/wildstar_formats/src/tex/normal.rs` verarbeitet Modell-Normalmaps
jetzt **pro Textur** statt mit unterschiedlichen Vermutungen für jeden Pixel.
Eine konservative Erkennung unterscheidet RGB-Normalmaps von
DXT5nm-artigen Alpha/Green-Normalmaps (X in Alpha, Y in Grün). Aus X/Y wird Z
rekonstruiert; das Ergebnis wird in lineares `Rgba8Unorm` konvertiert.
Die Entscheidung bleibt für alle Pixel derselben Textur konstant, auch wenn
einzelne Pixel neutrales Grau oder Alpha=255 enthalten.

Neue Unit-Tests prüfen das nichtflackernde Layout, gepackte Normalen,
ausserhalb des Einheitskreises liegende XY-Werte und defekte TEX-Daten.
**Einschränkung:** Die Klassifikation ist eine Heuristik, keine vollständige
Entschlüsselung des Original-WildStar-Shader-Flags. RGB ist der sichere
Fallback bei unklaren Daten. Terrain-Normalmaps verwenden weiterhin
ihren eigenen Decoder und sind durch diese Änderung nicht betroffen.

## Native M3 Layer 1–3: PBR Preview Shader

Der M3-Reader speichert alle **bis zu vier** ursprünglichen Material-Layer
(`0x128` Bytes pro Layer), einschließlich Farb-/Normal-Texture-ID, Layer-Klasse,
Material-Type-ID, fünf Modus-Worten und den ersten Parameter-Keys für
Opacity/Gloss/Glow/Color-Mod. Die ursprünglichen Layer-0-Felder bleiben
kompatibel zu bereits vorhandenem Code.

Für Modelle mit decodierbaren Farbtexturen in Layer 1–3 nutzt die
Modelvorschau und das AREA-Prop-Rendering
`src/m3_layers.rs` / `src/m3_layers.wesl`. Die
`ExtendedMaterial<StandardMaterial, M3LayerExtension>` erhält Normalmaps,
Alpha-Modus und Beleuchtung des Basismaterials. Layer 1–3 werden im
Pixel-Shader in Originalreihenfolge auf UV0 per Alpha-Over zusammengesetzt.
Nur vorhandene Farbtexturen aktivieren einen Layer. Fehlende Layer haben
transparente Dummy-Bindings und verschieben andere Slots nicht.

**Noch nicht Retail-paritätisch:** Alpha-Over ist eine bewusst konservative
Vorschau, keine belegte Deutung der fünf M3-Mode-Wörter. Originale Masken,
Color1-Gewichte, Layer-Normalmaps 1–3, UV1-Abhängigkeit, Spezialshader und
Materialanimation bleiben offen. Der separate Clutter-Wind-Shader benutzt
zurzeit weiterhin das Basismaterial; Clutter wird nicht heimlich auf die
noch nicht kombinierte Wind+Layer-Shader-Pipeline umgeschaltet.

CI: `cargo test -p wildstar_formats`,
`cargo check -p genesis`, `cargo check -p genesis --tests`.
Dies prüft den Rust-Code, nicht die GPU-WESL-Pipeline. Die Laufzeitvorschau
muss mit Originalmodellen auf Windows/GPU überprüft werden.
