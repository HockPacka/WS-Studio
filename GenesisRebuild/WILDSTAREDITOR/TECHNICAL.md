Editor-Block (Unkomprimiert im Tool)	Runtime-Block (Vom Cooker komprimiert)	Verwendungszweck im Editor
Bit 2 (8.450 B, 65×65 u16 4-Nibble)	Bit 17 & 18 (2.312 B, BC1 / DXT1)	Layer-Blend-Weights: Der World-Artist malte 4 Layer mit variablen Alphawerten. Der Cooker packte dies in 17×17 BC1-Blöcke.
Bit 3 & 15 (8.450 B, 65×65 RGB565)	Bit 13 & 14 (4.624 B, BC2 / DXT3)	Vertex-Color / Tinting: Künstler konnten Farbtönungen direkt auf das Terrain pinseln.
Bit 29 (8.450 B, 4 Nibbles, Summe=15)	Bit 19 & 20 (2.312 B, BC1)	Normalisierte 4-Layer-Gewichte.

4. Besondere Werkzeuge innerhalb der Terrain-Engine
"Genesis Blend" (Height-Bias-Blending):
Bit 18 speichert eine vorzeichenbehaftete Offset-Map (t9 im LandPS-Shader).
Statt einfachen linearen Alpha-Übergängen berechnete das Genesis-Tool mathematisch basierend auf der Height- und Normal-Map, wie z. B. Steine durch Schnee oder Risse in Felsen durchschimmern.
Straßen- & Pfad-Deformer (CURD, CURT, RoadMarch):
Am Kopf jeder .area-Datei existiert der Chunk CURT (Curve Table) und in den Zellen CURD (Curve Data / Splines).
Bit 16 (64×64 u8 Flags): Bit 0 steuert das sogenannte RoadMarch (ein Spline-Werkzeug im Editor, das Wege in die Heightmap einfräst und glättet).
Bit 16 Flag 0x20: Unterdrückt Foliage/Clutter, damit auf angelegten Wegen kein Gras wächst.
Clutter-Pinsel (WorldClutter.csv):
Bit 27 (64×64 u8): Speichert 2-Bit-Selektoren für die 4 Layer (worldClutterId00..03). Im Genesis-Editor konnten Artists die Vegetationsdichte maskieren.
Wasser- & Kollisionswerkzeuge:
Zellen enthalten WAtG (Water Geometry) und wbsp (Water Binary Space Partitioning für Physik/Kollision und Schwimm-Abfragen).
Terrain-Conforming für Props (M3-Anchor-Points):
In den Modell-Dateien existieren die Slots 0x510–0x528 (Terrain Anchors). Das Genesis-Editor-Tool nutzte diese Nodes, um modulare Gebäude und Klippen automatisch am unebenen Boden auszurichten.

E_MAP_REFERENCED_BY_LANDLAYERWEIGHTS

  
E_MAP_REFERENCED_BY_LANDCLUTTERPRESETS

  
E_MAP_DUPLICATE: duplicate (Land/Ocean) LayerId

  
CMapArea: Corrupt area / CMapChunk: Corrupt chunk

1. Der Name des offiziellen Carbine-Terrain-Tools: "Genesis"
Auf der PAX 2013 und in Interviews/Polycount-Feature-Artikeln stellte Carbine Studios ihr proprietäres internes Terrain- und World-Building-System vor: "Genesis" (interner World & Level Editor).
Ursprung & Parallelen zu World of Warcraft: Carbine Studios wurde von ca. 17–20 ehemaligen Blizzard-Kernentwicklern gegründet (darunter leitende Entwickler von WoW Classic). Daher ist die WildStar-Terrain-Architektur die direkte, moderne Weiterentwicklung von Blizzards WoW ADT-Engine (16×16 Chunks, Layer-Splatting, Doodad-Instancing).