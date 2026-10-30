## THE WILDSTAR EDITOR
1. Kern-Architektur: Das „WYSIWYG“-Prinzip

Genesis war ein in C++ geschriebenes, proprietäres All-in-One-Werkzeug, das direkt auf der eigenen Grafik-Engine von WildStar aufsetzte.
• Echtzeit-Vorschau: Der Editor arbeitete nach dem What You See Is What You Get-Prinzip. Es gab kein separates Kompilieren von Licht oder Geometrie, das Stunden dauerte. Wenn ein Artist einen Baum platzierte oder die Sonne verschob, sah das Bild im Editor exakt so aus wie später für den Spieler im fertigen Client.
• Nahtloser In-Game-Wechsel: Designer konnten per Knopfdruck direkt im Editor in ihren Charakter schlüpfen, um Abstände, Sprunghöhen (wichtig für den Explorer-Pfad) und Sichtlinien sofort aus der Spielerperspektive zu testen.

2. Die wichtigsten Werkzeuge & Module

Aus den Aufnahmen von der PAX-Demo auf YouTube und den Portfolios ehemaliger Level-Designer auf Zerply lassen sich die Hauptfunktionen genau rekonstruieren:
• Terrain Sculpting & Chunk-System: Die Welt war in quadratische Kacheln (Chunks) unterteilt. Mit Pinsel-Werkzeugen (Brushes) konnten Entwickler das Gelände anheben, absenken, glätten oder steile Klippen ziehen.
• Texture Blending & Vertex Color: Um den typischen, handgemalten Comic-Look von WildStar zu erzeugen, nutzte Genesis ein Mehrkanal-Textursystem. Artists malten verschiedene Bodentexturen (z. B. Gras, Erde, außerirdisches Gestein) übereinander. Zusätzlich erlaubte der Editor direktes Vertex Painting – man konnte also die Polygon-Eckpunkte des Bodens direkt im Editor einfärben, um künstliche Schatten, Schmutz oder leuchtende Eldan-Spuren ohne extra Texturen zu erzeugen.
• Prop Placement & „Set Dressing“: Externe 3D-Modelle (aus Programmen wie Maya) wurden als sogenannte Props in eine riesige Asset-Bibliothek geladen. Im Editor konnten diese frei skaliert, gedreht und ineinander geschoben werden. Ein spezieller Pinsel übernahm das automatische Verteilen von Kleinkram (Grasbüschel, kleine Steine, Kristalle) anhand von festgelegten Dichtewerten. (Fun Fact: Das beliebte Housing-System im Spiel nutzte im Grunde eine stark vereinfachte Version genau dieser Objekt-Manipulatoren aus Genesis).
• Umgebungs- & Wasser-Tools: Beleuchtung, Himmelsfarben (Skyboxes), dichter Nebel und die Platzierung von Wasserflächen samt Fließrichtung wurden ebenfalls direkt pro Zone oder sogar pro kleinem Untergebiet eingestellt. In der PAX-Demo sieht man, wie ein Regler das gesamte Farbschema eines Gebiets innerhalb von Sekunden von „sonnigem Tag“ auf „düsteren verseuchten Sumpf“ umstellt.

3. Der Workflow: Wie das Team zusammenarbeitete

Im Hinter-den-Kulissen-Video The Art of WildStar auf YouTube und im Fachartikel The WildStar Creation Process auf Game Developer wird beschrieben, wie Genesis als Schnittstelle für fast alle Abteilungen diente:
1. Blockout (Greyboxing): Zuerst formten die Level-Designer das grobe Gelände und stellten graue Platzhalter-Boxen für Gebäude auf, um Laufwege zu planen.
2. World Art Pass: Danach übernahmen die Environment Artists dieselbe Datei in Genesis, ersetzten die Boxen durch fertige 3D-Gebäude, malten die Bodentexturen und bauten die grobe Vegetation.
3. Layered Content (Design-Integration): Über eingebaute Templates und den verknüpften Creature Editor zogen die Content-Designer anschließend NPCs, Monster-Spawnpunkte, Patrouillen-Wege und unsichtbare Auslöser (Trigger) für Quests, Challenges und Path-Missionen direkt auf die Karte.
4. Final Polish (Set Dressing): Zum Schluss ging die Karte zurück an das Art-Team, das in Genesis winzige Details (herumliegende Werkzeuge, Lichtquellen, Partikeleffekte) hinzufügte, damit die platzierte Quest-Umgebung lebendig wirkte.

4. Dateiformate (Wissen aus dem Reverse-Engineering)

Als die Server 2018 schlossen, begannen Programmierer aus der Community (rund um Emulatoren-Projekte wie NexusForever auf GitHub), die von Genesis exportierten Spieldateien zu entschlüsseln. Dadurch ist bekannt, was der Editor am Ende ausgespuckt hat:
• .area-Dateien: In diesem Format speicherte Genesis die kompletten Kartendaten – also die Höheninformationen (Heightmaps), welche Texturen wo liegen, die Wasser-Ebenen und die genauen Koordinaten aller platzierten 3D-Objekte.
• .m3 und .i3: Das waren die internen Formate für 3D-Modelle (Meshes, Animationen) und Innenräume, die in Genesis platziert wurden.
• .tbl-Dateien: Sämtliche Gameplay-Daten, die Designer im Editor verknüpften (welche Kreatur welche Werte hat, welche Quest wo startet), wurden in solchen Datenbank-Tabellen abgelegt.
Bis heute ist die Programmier-Datei (Genesis.exe) leider nie im Internet aufgetaucht (geleakt), weshalb Modder für das Betrachten der alten .area-Karten eigene Programme wie den NexusExplorer schreiben mussten.