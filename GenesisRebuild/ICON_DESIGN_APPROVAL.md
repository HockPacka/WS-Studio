# Genesis – Freigabe der Menü- und Toolbar-Icons

**Freigegeben am:** 2026-11-02
**Projekt:** GenesisEditor-Rebuilder / WS-Studio, Bevy 0.20.1
**Branch:** `feature/genesis-m3-i3-render-parity`
**Entscheidung:** Alle neun vorgeschlagenen Icon-Gruppen **JA**. Keine abgelehnten Gruppen; keine Überarbeitung dieser Freigaberunde nötig.

## Freigegebenes Icon-Konzept

**Design-Referenz:** Die visuelle Vorschlagstafel „GENESIS – Menü- & Toolbar-Icons“, die unmittelbar vor der Nutzer-Freigabe im Chat erzeugt und gezeigt wurde. Ihre Farb- und Formsprache (dunkler Sci-Fi-Hintergrund, leuchtende cyan-/blau-/grün-/violett-/goldfarbene Symbolakzente, gut unterscheidbare Piktogramme) ist der genehmigte Ausgangspunkt.

Das Concept-Art-Board ist **noch kein Sprite-Atlas oder Icon-Paket**. Einzelne transparente PNGs oder Vektorquellen wurden damit **noch nicht** erzeugt oder in dieses Repository eingebunden. Die Freigabe gilt für die vorgeschlagene Gestaltungsrichtung und die Icon-Gruppen, nicht für ungetestete 16-px-Rastergrafiken.

| Nr. | Gruppe | Entscheidung | Freigegebene Piktogramme |
| --- | --- | --- | --- |
| 1 | Datei | **JA** | Neu, Öffnen, Speichern, Speichern unter, Beenden |
| 2 | Bearbeiten | **JA** | Rückgängig, Wiederholen, Ausschneiden, Kopieren, Einfügen, Löschen |
| 3 | Ansicht | **JA** | Editor-Ansicht, Wireframe, Materialien, Beleuchtung, Kamera, Vollbild |
| 4 | Terrain | **JA** | Höhe anheben, Höhe absenken, Glätten, Terrain-Rauschen, Textur-Paint, Farb-Paint, Blenden |
| 5 | Objekte | **JA** | Platzieren, Verschieben, Rotieren, Skalieren, Verknüpfen, Gruppieren, Gruppierung aufheben |
| 6 | Welt / AREA | **JA** | Neue AREA, AREA öffnen, AREA-Eigenschaften, Welten-Übersicht, Ränder synchronisieren, mehrere AREAs laden |
| 7 | Materialien & Assets | **JA** | Materialien, Texturen, Modelle (M3/I3), Animationen (M3), Clutter, Presets, Asset-Bibliothek |
| 8 | Umgebung | **JA** | Sonne, Sky/Himmel, Nebel, Skybox, Wetter, Beleuchtungseinstellungen |
| 9 | Werkzeuge & Einstellungen | **JA** | Auswahl, Bereichsauswahl, Messen, Pivot, Snapping, Raster, Achsen/Gizmo, Einstellungen, Editor-Optionen, Tastenkürzel, Über Genesis, Dokumentation, Hilfe |

## Geplante technische Aufbereitung – noch offen

- [x] Freigabe aller neun Icon-Gruppen eingeholt.
- [x] Keine Icon-Gruppe abgelehnt – deshalb keine Konzept-Überarbeitung nötig.
- [ ] Jede genehmigte Grafik als **einzelnes, eindeutiges Icon** mit transparentem Hintergrund neu zeichnen oder sauber freistellen; Textlabels gehören nicht in die Icondateien.
- [ ] Einheitliche Pixelgrößen **16 × 16, 24 × 24, 32 × 32, 64 × 64** prüfen (gegebenenfalls zusätzlich HiDPI-Quelldatei).
- [ ] Kein automatisches Zerschneiden der Präsentationsgrafik als produktionsfertige Icons behandeln: Leuchten, Hintergründe und Text sind in der Concept-Art nicht als transparente Ebenen getrennt.
- [ ] Dunkles Konzept gegen Genesis **helle/beige Editor-Chrome** testen und bei Bedarf dezente, kontrastreiche Light-Theme-Variante derselben genehmigten Symbole erzeugen. Symbole/Formgebung beibehalten.
- [ ] Pro Icon feste Dateinamen und Zustandsvarianten (normal, hovered, disabled, selected) definieren.
- [ ] Icons den **tatsächlich implementierten** Menübefehlen in `src/main.rs` zuordnen, ohne Platzhalterfunktionen als fertig auszugeben.
- [ ] Ansicht bei 16/24/32 px sowie auf HiDPI-Bildschirmen visuell freigeben.
- [ ] PNG-Assets, Zuordnungsliste und Lizenz-/Provenienz-Hinweise im Feature-Branch versionieren.
- [ ] Nach Integration Windows-Build und tatsächlichen Genesis-UI-Start prüfen.

## Änderungskontrolle

Diese Dokumentation ist eine **angenommene Designentscheidung**, keine Implementierungs-/GPU-Abnahme. Änderungen an Stil, Icon-Metaphern oder Farbgruppen sollen separat zur Freigabe vorgelegt werden. Weitere Arbeiten ausschließlich auf dem benannten Feature-Branch; `main` bleibt unangetastet.
