
1. Die Terrain-Sculpting-Tools (Geländeformung)

Die Spielwelt in Genesis bestand aus einem Raster von quadratischen Kacheln (Chunks), die wiederum in kleinere Unterkacheln (Sub-Chunks) aufgeteilt waren. Für die Bearbeitung der Höhenwerte (Heightmap) gab es ein klassisches Pinsel-Modul mit einstellbarem Radius, Härtegrad (Falloff) und Stärke:
• Raise / Lower (Heben / Senken): Zog das Terrain-Gitter entlang der vertikalen Achse nach oben oder unten.
• Flatten / Plateau (Ebnen): Ein entscheidendes Werkzeug für Level-Designer. Man wählte eine Zielhöhe per Klick und zog mit dem Pinsel absolut flache Ebenen in Berge, um dort später Gebäude, Straßen oder ganze Siedlungen ohne schwebende Kanten zu platzieren.
• Smooth (Glätten): Berechnete den Durchschnittswert benachbarter Polygon-Punkte, um harte, unnatürliche Kanten nach dem Formen abzurunden.
• Noise / Roughness (Aufrauen): Fügte per Zufallsgenerator gezackte Unebenheiten hinzu, damit Hügelketten und Felswände nicht zu steril aussahen.
• Hole Punch / Terrain Cutout (Löcher schneiden): Da ein normales Höhen-Gitter keine Überhänge oder Höhlen darstellen kann, besaß Genesis ein Werkzeug, um einzelne Polygon-Kacheln des Bodens unsichtbar und durchlässig zu schalten. An diese offenen Stellen dockten die Artists dann ein 3D-Modell eines Höhleneingangs (.m3- oder .i3-Datei) nahtlos an.

2. Das Texture- & Color-Painting-Modul

Wie in der Dokumentation The Art of WildStar auf YouTube zu sehen ist, entstand der handgemalte Look des Bodens durch das Zusammenspiel von vier spezifischen Mal-Werkzeugen im Editor:
• 4-Layer Texture Brush: Pro Kachel (Sub-Chunk) erlaubte die Engine maximal vier verschiedene Bodentexturen gleichzeitig (z. B. Erde, Gras, Fels, Pflasterstein). Mit dem Pinsel malten die Artists auf eine sogenannte Blend-Map (Alpha-Maske), um weiche Übergänge zwischen diesen vier Schichten zu erzeugen.
• Specular & Normal Blending: Das Tool mischte nicht nur die Farben, sondern berücksichtigte automatisch die Tiefeninformationen der Texturen. Wenn man Sand über Kopfsteinpflaster malte, füllten sich erst die Rillen zwischen den Steinen mit Sand, bevor die Steine selbst verdeckt wurden.
• Vertex Color Brush (Direktes Einfärben): Eines der mächtigsten Werkzeuge der WildStar-Engine. Unabhängig von der Textur konnten Entwickler die Eckpunkte des Bodengitters farblich ansprühen.
	• Anwendung: Ein Artist nahm dasselbe grüne Gras-Texturset, färbte den Boden in einem Gebiet aber per Pinsel leicht bläulich (für Nacht-Zonen wie Celestion) oder violett-schwarz (für verseuchte Strain-Gebiete), ohne dass dafür neue Texturen geladen werden mussten.
• Baked Shadow Brush: Ein dunkler Pinsel, mit dem man künstliche Kontaktschatten unter große Felsen, Zäune oder Bäume direkt auf den Boden malte, um den Objekten mehr optisches Gewicht zu verleihen.

3. Das Clutter- & Flora-System (Prozedurale Details)

Damit Entwickler nicht Millionen einzelner Grashalme per Hand setzen mussten, besaß Genesis ein automatisiertes Verteilungs-Tool:
• Auto-Clutter via Textur-Verknüpfung: In den Einstellungen einer Bodentextur (z. B. „Wiesengras“) war hinterlegt, welche kleinen 3D-Modelle (Blumen, Halme, kleine Kiesel) dazu gehören. Sobald der Artist mit dem Textur-Pinsel Gras auf den Boden malte, ließ das Clutter-Tool im selben Moment vollautomatisch wippende 3D-Grasbüschel aus dem Boden sprießen.
• Clutter Exclusion Brush (Auschluss-Pinsel): Wenn ein Designer ein kleines Lagerfeuer auf eine Wiese stellte und das automatische Gras durch das Feuer ragte, konnte er mit diesem Radiergummi-Pinsel das prozedurale Gras an exakt dieser Stelle unterdrücken, ohne die grüne Bodentextur darunter zu löschen.

4. Das Prop-Placement- & „Set Dressing“-Tool

Für alle festen 3D-Objekte (Bäume, Felsen, Kisten, Raumschiffe, Gebäude), die das Prop Team von Carbine auf YouTube in Maya erstellte, bot Genesis einen umfangreichen Objekt-Manipulator:
• 3D-Gizmo (Move, Rotate, Scale): Jedes platzierte Objekt besaß drei farbige Achsenringe. Da WildStar einen überzeichneten Comic-Stil nutzte, war das Scale-Tool extrem wichtig: Aus einem einzigen modellierten Felsbrocken bauten die Artists durch massives Vergrößern, Stauchen und auf den Kopf drehen ganze Gebirgsketten (sogenanntes Kitbashing).
• Surface Snapping & Normal Alignment: Beim Ziehen eines Objekts aus dem Asset-Browser über das Gelände klebte das Modell automatisch am Boden fest und neigte sich auf Wunsch exakt im Winkel des Hangs (ideal für Zäune, Sträucher oder herabgefallene Trümmer).
• Object Tint Picker: Genau wie den Boden konnten Artists auch einzelne 3D-Objekte direkt im Editor umfärben, damit ein Stein aus einer Wüstenzone farblich auch in ein Schneegebiet passte.
• Prefab / Group Tool: Wenn ein Designer aus 20 Einzelteilen (Zelt, Kisten, Lampe, Stuhl) ein hübsches kleines Lager gebaut hatte, konnte er diese Auswahl als Gruppe zusammenfassen und überall auf der Karte als fertiges Set kopieren.

5. Das Sky-, Lighting- & Environment-Volume-Tool

Wie im WildStar-Portfolio auf Reddit zu den Engine-Upgrades erwähnt wird, steuerte Genesis die gesamte Atmosphäre über unsichtbare Zonen-Boxen (Environment Volumes):
• Zone Volume Box: Designer zogen im Editor einen unsichtbaren 3D-Kasten um ein Gebiet (z. B. um einen gruseligen Wald oder einen Krater).
• Skybox & Fog Controller: Jedem dieser Kästen wurde ein eigenes Umwelt-Profil zugewiesen. Darin befanden sich Farbregler für das Sonnenlicht (Directional Light), das Schattenlicht (Ambient Light), die Dichte und Farbe des Höhennebels sowie die Auswahl des Himmels-Hintergrunds (Skybox) und der schwebenden Planeten.
• Echtzeit-Blending: Lief der Spieler im Spiel (oder die Kamera im Editor) von einem Kasten in den nächsten, blendete die Engine alle Farben, Nebelwerte und Lichtstimmungen butterweich innerhalb weniger Sekunden ineinander über.

6. Das Liquid- / Water-Tool (Flüssigkeiten)

Wasser war in Genesis kein Teil des normalen Bodengitters, sondern ein eigenes Werkzeug-Modul:
• Liquid Plane Generator: Man spannte ein flaches Polygon-Netz auf einer bestimmten Höhe über einer Senke im Gelände auf.
• Shader-Zuweisung: Über ein Dropdown-Menü bestimmte man das Material der Flüssigkeit – von klarem, spiegelndem Wasser über giftig blubbernden Schleim bis hin zu glühender Lava.
• Flow- & Depth-Regler: Das Tool berechnete automatisch den Abstand zwischen der Wasseroberfläche und dem darunterliegenden Terrain. Dadurch wurde das Wasser am Ufer automatisch durchsichtig (mit weißem Schaumrand) und in der Mitte tiefblau und undurchsichtig. Mit Richtungspfeilen ließ sich zudem einstellen, in welche Richtung ein Fluss strömen sollte.

7. Die Gameplay-, KI- & Scripting-Werkzeuge

Sobald die Welt stand, wechselten die Content-Designer (wie im Design-Portfolio von Mike DiRenzo und der PAX-Demo auf YouTube beschrieben) in die Gameplay-Modi von Genesis:
• Creature Spawner & Scale Preview: Designer wählten aus der Datenbank (die im externen Creature Editor gepflegt wurde) eine Monster-ID aus und klickten auf den Boden, um Spawnpunkte zu setzen. Genesis lud daraufhin das echte 3D-Modell des Monsters inklusive seiner eingestellten Zufalls-Größen (Min/Max-Skalierung) direkt in die Ansicht, damit man prüfen konnte, ob der Bossgegner überhaupt durch die Tür passt.
• Spline / Waypoint Tool: Ein Linien-Werkzeug, mit dem man Punkte auf dem Boden verband. Diese Linien dienten als feste Patrouillen-Wege für Wachen, als Flugrouten für die Taxis oder als Kamerafahrten für kleine Zwischensequenzen.
• Trigger Volumes (Unsichtbare Auslöser): Farbige, im Spiel unsichtbare Boxen oder Kugeln. Betrat ein Spieler diesen Bereich, feuerte ein verknüpftes Skript ab (z. B. „Starte einen Funkspruch“, „Löse eine Soldier-Holdout-Mission aus“ oder „Verursache Lava-Schaden“).
• Socket- & Plug-Marker (Für Housing & Warplots): Ein sehr spezielles WildStar-Tool. Damit markierten Designer große, flache Bereiche auf einer Karte als „Steckplatz“ (Socket). Später im Spiel konnten Spieler (beim Hausbau) oder das System dynamisch ganze vorgebaute Mini-Gebiete (wie eine Mine, ein Sprungpuzzle oder eine PvP-Kanone) in diese Steckplätze hineinladen.
• NavMesh-Generator & Collision-Blocker: Ein Analyse-Tool, das eine farbige Schicht über den gesamten Boden legte, um zu zeigen, wo Monster und Spieler entlanglaufen können (begehbare Winkel) und wo es zu steil ist. Mit Invisible Walls (unsichtbaren Kollisionswänden) konnten Designer zudem verhindern, dass Explorer-Spieler an Orten über Berge sprangen, die noch gar nicht fertig gebaut waren.
Möchtest du wissen, wie diese Datenbank-Verknüpfungen (.tbl-Dateien) im Hintergrund mit dem Editor zusammengespielt haben, oder interessiert dich, wie heutige Community-Tools wie der NexusExplorer diese alten Editor-Daten wieder sichtbar machen?
