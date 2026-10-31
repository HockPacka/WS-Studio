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
Props werden pro Material in Teilmeshes zerlegt; der Texturpfad (M3: erste Material-Ebene, I3: Material-Set 0) wird über den Index aufgelöst und mit dem `.tex`-Decoder (max. 512 px) als Farbtextur gesetzt. Fehlt die Textur, bleibt die Einfärbung.

## Metadaten im Editor
Im Objects-Dock zeigt jeder Prop-Eintrag alle Modell-Metadaten (Vertices, Dreiecke, Bounds, Bones, Clips, Texturen, Sektoren, Portale, Material-Sets). Jeder referenzierte Pfad wird gegen den ClientData-Index geprüft und mit `[OK]` bzw. `[MISSING]` markiert.

## Noch offen
- Normal-/Skinfx-Texturen, Mehrschicht-Materialien und Material-Varianten (nur Farbtextur der ersten Ebene).
- M3: Animationstracks, Partikel/Ribbons, Lichter, Kameras werden nicht dekodiert.
- Achsen/Skalierung der Props gegenüber dem Terrain sind ungeprüft (Transform wird wie beim Marker übernommen).

## Prüfen
```bash
cargo test -p wildstar_formats
cargo run -p wildstar_formats --example dump_model -- Avatus.m3
```
