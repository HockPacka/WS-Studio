Editor-Block (Unkomprimiert im Tool)	Runtime-Block (Vom Cooker komprimiert)	Verwendungszweck im Editor
Bit 2 (8.450 B, 65×65 u16 4-Nibble)	Bit 17 & 18 (2.312 B, BC1 / DXT1)	Layer-Blend-Weights: Der World-Artist malte 4 Layer mit variablen Alphawerten. Der Cooker packte dies in 17×17 BC1-Blöcke.
Bit 3 & 15 (8.450 B, 65×65 RGB565)	Bit 13 & 14 (4.624 B, BC2 / DXT3)	Vertex-Color / Tinting: Künstler konnten Farbtönungen direkt auf das Terrain pinseln.
Bit 29 (8.450 B, 4 Nibbles, Summe=15)	Bit 19 & 20 (2.312 B, BC1)	Normalisierte 4-Layer-Gewichte.