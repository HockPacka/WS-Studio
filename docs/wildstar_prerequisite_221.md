# Native Prerequisites: Typ 221 und Vergleichsoperatoren

29.10.2026, Original `WildStar/Client64/WildStar64.exe`, Build 16042,
Ghidra `x86:LE:64:default`, Projekt WSG. Die Binärdatei wurde nicht verändert.
Ein zuvor nicht als Funktion erkannter Bereich bei `14049d6d0` wurde in der
Ghidra-Analyse als Funktion definiert; keine vorhandenen Typen/Namen überschrieben.

## Befund: ausgerüstetes aktives Action Set

Der Dispatcher `FUN_1404a2100`, Fall `0xdd` (221), ruft die virtuelle Funktion
bei Offset `0x190` auf, mit Akteur, Vergleich und `objectId`.
Der konkrete Manager wird in `FUN_14049be30` mit Vtable `140b67740` erzeugt.
Der Eintrag bei `140b678d0` zeigt auf `FUN_14049d6d0`.

Diese Funktion:

1. Akzeptiert nur den lokalen Spieler (`actor == *(state + 0x78)`).
2. Liest die aktive Konfiguration bei `state + 0x6dec`.
3. Prüft zwölf Pointer ab `state + 0xac0 + configuration * 0x180`.
4. Vergleicht bei belegten Plätzen das Feld `slotObject + 0x118` mit `objectId`.
5. Vergleich 1 bedeutet vorhanden, Vergleich 2 nicht vorhanden.

Unabhängige Bestätigung: der registrierte Lua-Aufruf
`ActionSetLib.GetCurrentActionSet`, `FUN_140758510`, gibt für dieselbe aktive
Konfiguration genau zwölf solcher Werte aus `slotObject + 0x118` zurück.
Die Originaloberfläche `ClientData/UI/Abilities/AbilitiesBuilder.lua:332`
verwendet diese Werte als Ability-IDs für die belegten Plätze.

**Typ 221 ist Mitgliedschaft im aktiven Action Set, kein allgemeiner
Spellbook-Besitztest.** Ein gelernter, aber nicht dort ausgerüsteter Zauber darf
den Test nicht erfüllen. Im portablen Adapter heißt die autoritative Menge
`context.nativeActionSet` (native Ability-ID → true). Ein fehlendes Action Set
ist UNKNOWN; es darf nicht als leeres, vollständig bekanntes Set gelten.

Der Client prüft nur seinen lokalen Spieler. Eine serverseitige Implementierung
muss stattdessen das eigene gespeicherte Action Set des betreffenden
Spielercharakters verwenden. Eine beliebige Client-Meldung darf es nicht ersetzen.
Die aktuellen GM-Szenarien verwenden ausdrückliche Testdaten und speichern
kein Action Set in einem echten Charakterprofil.

## Warrior 55543: reale Bedingungen

| Prerequisite | Bedingung | Ausgewählter roher Proxy-Wert |
|---|---|---:|
| 23082 | 18309 und 39339 fehlen im aktiven Set | 398 |
| 23083 | 18309 ist im aktiven Set | 18309 |
| 23084 | 18309 fehlt und 39339 ist im aktiven Set | 39339 |

Sind beide enthalten, greift nur 23083. Alle vier Zustände wurden mit den aus
`Prerequisite.tbl` und `Spell4Effects.tbl` exportierten Originalzeilen geprüft:
leer, nur 18309, nur 39339, beide. Jeder Zustand erfüllt genau eine Bedingung.
Die Konsolenbezeichnungen `assault` und `tank` sind lesbare Namen für diese
zwei Testmengen; sie implementieren keine Klassenhaltung oder Talentlogik.

`dataBits00` bleibt hier ausdrücklich ein roher Proxy-Wert. Der bisherige
NexusForever-Proxy-Handler übergibt ihn an die zweiparametrige `CastSpell`-
Überladung, die eine Spell4-ID erwartet. Gleichzeitig bezeichnet 18309 in
Spell4Base einen Warrior-Eintrag, in Spell4 aber einen NPC-Brawler-Stun;
39339 ist in Spell4Base ein Warrior-Eintrag, in Spell4 dagegen ein als deprecated
markierter fremder Klasseneintrag (native classIdPlayer 15). Die frühere Annahme,
es gebe keine Spell4-Zeile 39339, wurde durch den vollständigen Abgleich korrigiert.
Die richtige Proxy-Auflösung und Tierwahl sind deshalb separat am Originalclient
zu klären. Aus dem belegten Action-Set-Test folgt noch keine Berechtigung,
den rohen Proxy-Wert direkt als WoW-/Spell4-Zauber auszuführen.

## Vergleichsoperatoren: Korrektur gegenüber NexusForever

Die Originalfunktionen `FUN_1404a2090` (uint) und `FUN_1404a2010` (float) zeigen:

| Wert | Originalclient | Bisherige lokale NexusForever-Enum |
|---:|---|---|
| 1 | gleich | gleich |
| 2 | ungleich | ungleich |
| 3 | größer als | größer oder gleich |
| 4 | größer oder gleich | größer als |
| 5 | kleiner als | kleiner oder gleich |
| 6 | kleiner oder gleich | kleiner als |

Der erste portable Prüfer hatte die Referenz-Enum übernommen. Er wurde jetzt auf
die Originalclient-Werte korrigiert. Tests prüfen alle sechs Operatoren jeweils
unterhalb, gleich und oberhalb des Grenzwerts. Die Rohdaten/IDs bleiben unverändert.

Weitere Originaldetails: `FUN_1404a1ca0` benutzt Bit 0 der Flags für AND/OR;
`FUN_1404a5190` beendet die vorbereiteten Bedingungen am ersten Typ 0. Der
Lua-Prüfer übernimmt beides. Nicht verstandene Typen bleiben UNKNOWN; UNKNOWN
wird auch durch ein verschachteltes NOT nicht zu TRUE.

## Implementierung und Nachweis

- `plugins/wildstar335a/runtime/Prerequisite.lua`: korrigierter Prüfer.
- `tools/tests/test_ws_combat_host.py`: Grenzfälle und vier reale Warrior-Zustände.
- `docs/combat_analysis/1404a2100.c`: Dispatcher.
- `docs/combat_analysis/14049d6d0.c`: direkter Typ-221-Prüfer.
- `docs/combat_analysis/GetCurrentActionSet.c`: unabhängige Lua-API-Bestätigung.
- `docs/combat_analysis/1404a2090.c`, `1404a2010.c`: Vergleichsoperatoren.
- `docs/combat_analysis/1404a1ca0.c`, `1404a5190.c`: Modus und Zeilenende.
- Begleitende JSON-Dateien speichern Ghidra-Antworten mit Sprache und Adressen;
  `evidence_manifest.json` enthält Binär- und Dateihashes.

Der Benutzer hat zuvor den kombinierten GM-Schaden-/Heiltest als funktionierend
bestätigt. Dieser Live-Nachweis ersetzt weder die ausstehende Proxy-Auflösung
noch die Anbindung gespeicherter nativer Action Sets. Native Fähigkeiten bleiben
bis dahin gesperrt; die Ghidra-Analyse allein wird nicht als Live-Fähigkeitstest
ausgewiesen.
