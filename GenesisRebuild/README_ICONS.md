# Genesis Icons – Menu/Toolbar integration

Alle neun Icon-Gruppen sind gemäß [ICON_DESIGN_APPROVAL.md](ICON_DESIGN_APPROVAL.md) freigegeben.

## Umsetzung

- Neues Modul: `src/genesis_icons.rs` zeichnet die genehmigten Bildmetaphern (Datei, Werkzeuge, Terrain, Objekte, AREA, Materialien, Umgebung usw.) mit nativen egui-Vektorprimitiven.
- Die bestehende 26 × 26 px Toolbar benutzt jetzt echte Piktogramme **anstelle von Buchstaben oder farbigen Kästchen**.
- Alle Einträge der bestehenden File/Edit/View/Terrain/Objects/.../Help-Menüs erhalten passende kleine, farblich kodierte Icons; Icon und Text haben eine gemeinsame Klickfläche.
- Es gibt **keinen Umbau** von Panel-Layout, Docking, Fensterfarben, Menügruppierung oder UI-Skalierung. Das helle klassisch-beige Genesis-Design bleibt bestehen.
- Das Konzept-Board enthielt Text und dunklen Hintergrund und ist kein transparentes PNG-Sprite-Sheet. Die gewählten Motive werden stattdessen als unabhängige skalierbare Vektoren im Renderer gezeichnet. Ein PNG-Export kann später separat erfolgen; die UI benötigt ihn nicht.
- Icon-Zeichnung erzeugt weder Texturdateien noch zusätzliche externe Font-/Icon-Lizenzen.

## Prüfung

1. `cargo check -p genesis` und `cargo check -p genesis --tests` in Windows-CI.
2. `cargo test -p genesis genesis_icons` mit den Zuordnungs- und Abdeckungsprüfungen.
3. Manueller Windows-Start: 26px-Toolbar, 16px-Menü-Icons, Hover/Click und Tooltip prüfen; Menüs und Dock-Anordnung müssen identisch bleiben.
4. UI-Zoom 80%, 100%, 125%, 150% auf Kontrast und Schärfe prüfen.
5. Der Icon-Renderer ändert die bestehenden Befehle **nicht**. Menüeinträge, die vor dieser Änderung Platzhalter waren, bleiben Platzhalter. Das ist keine Funktionsfreigabe.
