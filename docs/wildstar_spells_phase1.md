# Schritt 1: WildStar-Zauberexport und IDs

Der neue Einstieg ist `tools/ws_spells_to_dbc.py`. Der alte Exporter mit direkten Schreibzugriffen auf drei Live-DBC-Dateien wurde ersetzt; seine unveränderte Quelle liegt als Hash-Backup unter `build_wildstar/backups/spell-exporter-legacy/`.

## Fertiger Prüfstand

Maßgebliches Paket: `build_wildstar/spells_phase1_v3/`.

- 66.383 native Spell4-Einträge, 131.010 Effektzeilen und sechs Klassen sind erfasst.
- IDs 1.000.001 bis 1.088.671 sind deterministisch zugeordnet. Ein vorhandenes `id_map.json` erhält alle bisherigen Zuordnungen bei Erweiterungen.
- Die Reservierungsprüfung liest die installierten Client-/Server-DBCs und 55 numerische Spell-Referenzspalten der World-Datenbank. Im neuen Bereich wurden keine Überschneidungen gefunden. Vor einer späteren Installation muss diese Prüfung erneut erfolgen.
- Originale TBL-Dateien und die englische Sprachdatei sind bytegetreu im Paket erhalten. Normalisierte JSONL-Daten behalten Float32-Rohbits und nicht interpretierte dataBits.
- 2.208 originale Fähigkeitensymbole wurden anhand der nativen Sprite-/Folder-Deklarationen gefunden und nach TGA konvertiert. Für 187 Referenzen ließ sich keine eindeutige Quelle auflösen; es wurden keine Ersatzbilder erfunden.
- Cast-Zeiten, Cooldowns, Reichweiten und globale Dauerwerte werden ohne Rundung auf ähnliche WoW-Einträge exportiert. Eigene Lookup-Zeilen erhalten unabhängige, reservierungsgeprüfte IDs.
- Alle 49.839 ursprünglichen WoW-Spell-Zeilen sowie die Originalzeilen und Zeichenketten der vier Lookup-DBCs bleiben unverändert.
- Alle 66.383 Katalogeinträge wurden geprüft. Neun gezielte Tests bestehen. Ein Wiederholungslauf mit vorherigem ID-Manifest erzeugte dieselben 2.213 DBC-/Icon-Dateien bytegleich. Die zehn geprüften Live-DBC-Dateien blieben unverändert.

## Dateien

| Datei | Zweck |
|---|---|
| `id_map.json` | Persistente native ID → WoW-ID und Lookup-Zuordnungen |
| `reservations.json` | Read-only Momentaufnahme der belegten DBC-/SQL-IDs |
| `class_catalog.json` | Native Klassen, Grundfähigkeiten und klassengekennzeichnete Spell-Kandidaten |
| `abilities.jsonl` | Namen, Klasse/Tier, IDs und expliziter Umsetzungs-/Teststatus |
| `native/spells.jsonl` | Native Spell-Felder, Rohbits, Ziele, Ressourcen, Tooltips und aufgelöste Referenzen |
| `native/Spell4Effects.jsonl` | Sämtliche Effektzeilen einschließlich uninterpretierter Parameter und Rohbits |
| `dependencies.jsonl` | Bekannte Cast-Event-/Proxy-Zauberabhängigkeiten mit Provenienz |
| `missing_references.jsonl` | Nicht vorhandene Zielzeilen in den geprüften Relationen |
| `icons.json` | Originalquellen, Bildabmessungen und nicht auflösbare Icon-Namen |
| `catalog/*.dbc` | Nicht spielbereite Vorschau auf Basis der originalen WoW-DBCs |
| `catalog/deltas/*.json` | Additive Vorschau-Deltas, explizit `installable=false` |
| `validation.json` | Ergebnis der vollständigen Paketprüfung |

Die Rollen- und Klassenfähigkeitslisten enthalten auch interne Trigger, Tiers und alte Datensätze. Sie sind noch kein fertiges Fähigkeitenbuch.

## Bewusst offen statt simuliert

Die Engine-Abbildung von nativen Effekten, Zielen, Schulen, Ressourcen und Visual-Abläufen gehört zur nächsten Implementierungsphase. Das Paket enthält dafür die originalen Daten und markiert `runtimeReady=false`, `implemented=false`, `tested=false`. Es erzeugt weder Dummy-Kampfeffekte noch pauschalen Schaden. Die Vorschau-DBC enthält deshalb keine ausführbaren Effekte. `ws_dbc_delta.merge` verweigert die Installation eines so markierten Deltas.

Es bestehen 15 fehlende Querverweise: zehn Stack-Gruppen, vier Visual-Gruppen und eine AOE-Zielgruppe. Diese Einträge erhalten den Status `unknown`; die übrigen `data_available_requires_adapter`. Die Prüfung dokumentiert ihre Relationsabdeckung. Unklassifizierte dataBits bleiben erhalten und gelten nicht als entschlüsselte Trigger oder Formeln.

Vier Effektzeilen besitzen die native SpellId 0. Sie bleiben vollständig im Rohdatenpaket, statt einem willkürlichen Zauber zugeordnet zu werden.

Die alten IDs `100000 + Spell4-ID` sind nur Migrationsverweise. Der neue Export löscht oder überschreibt diese Live-Zeilen nicht. Insbesondere bleiben die sechs identifizierten `spell_dbc`-Überschneidungen und der fremde Script-Verweis auf 100101 während dieser Offline-Phase unangetastet. Eine spätere Migration braucht einen eigenen Abgleich der tatsächlichen Besitz-/Zeilenfingerprints.

## Layoutkorrektur des ursprünglichen Audits

Die physische Spell.dbc hat 234 Felder. Jede lokalisierte Zeichenkette belegt 16 Strings **plus ein Flag**, nicht nur 16 Felder. Die ursprüngliche Prüfung hatte deshalb SchoolMask fälschlich bei 221 gesucht. Richtig ist 225. Der alte Exporter schreibt dort pauschal physisch; es war nicht leer. Dieser Auditfehler wurde korrigiert. Reichweite bei 46 und ImplicitTargetA bei 86..88 bleiben die bestätigten Fehlerstellen des alten Exporters.

Der neue Exporter leitet das Layout aus dem lokalen `SpellRec.h` ab und bricht bei einer abweichenden Gesamtgröße oder unerwarteten Schlüsselposition ab. Tests decken insbesondere die vier lokalisierten Blöcke samt Flags ab.

## Wiederholen und prüfen

Ein neues Verzeichnis verwenden, da bestehende Ausgaben nicht überschrieben werden:

```powershell
python tools/ws_spells_to_dbc.py --output build_wildstar/spells_phase1_next `
  --prior-id-map build_wildstar/spells_phase1_v3/id_map.json
```

Dieser Aufruf liest die aktuellen Reservierungen des lokalen AzerothCore-Adapters. Für einen vollständig offline durchgeführten Wiederaufbau kann stattdessen die bereits geprüfte Momentaufnahme übergeben werden:

```powershell
python tools/ws_spells_to_dbc.py --output build_wildstar/spells_phase1_repeat `
  --reservations build_wildstar/spells_phase1_v3/reservations.json `
  --prior-id-map build_wildstar/spells_phase1_v3/id_map.json
python tools/ws_spell_validate.py build_wildstar/spells_phase1_repeat `
  --previous build_wildstar/spells_phase1_v3
python tools/tests/test_ws_spell_export.py
```

Es gibt keine `--apply`- oder automatische Installationsoption. Der Serveradapter dient hier ausschließlich der ID-Prüfung. Für die nächste Phase steht damit eine überprüfbare Datengrundlage bereit; ein funktionierender originaler Klassenkampf wurde mit diesem Schritt noch nicht implementiert oder im Spiel abgenommen.
