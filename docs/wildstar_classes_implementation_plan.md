# Plan: originale WildStar-Klassen und Fähigkeiten in WoW 3.3.5a

Stand: 28.10.2026. Read-only Prüfung der lokalen Exporte, des laufenden AzerothCore-Repack-Adapters, der Client-Quellen und der vorhandenen NexusForever-Referenz. Dieser Schritt hat keine Kampfzauber, Klassen oder Serverkonfigurationen verändert.

## Ergebnis

Eine spielbare Umsetzung der sechs Klassen ist technisch realistisch. Eine vollständige 1:1-Umsetzung sämtlicher originaler Fähigkeiten ist mit dem derzeitigen Stand **nicht nachgewiesen**. Die vorhandenen DBCs sind ein Katalog/Prototyp, keine fertige Übertragung der WildStar-Kampflogik. Ein unverändertes Repack plus das aktuelle Lua-Skript reicht nicht als Grundlage für eine solche Zusage.

Empfohlen wird ein eigener WildStar-Klassenadapter mit serverseitiger Kampflogik, getrennten IDs/Metadaten und einer Erweiterung des vorhandenen Clients. Lua bleibt für Oberfläche, Konfiguration, Diagnose und erste Prototypen sinnvoll. Für die vollständige Umsetzung sollten die zum NPCBots-Repack passenden Core-Quellen und eine reproduzierbare Build-Umgebung verfügbar sein. Lokale Referenzausschnitte und ein anderer Trinity/TSWoW-Quellbaum ersetzen diese passende Basis nicht.

## Was nachweislich vorhanden ist

Der reproduzierbare Befund steht in `build_wildstar/analysis/class_feasibility/audit.json`, erzeugt von `tools/analysis/class_feasibility_audit.py`.

- Sechs Class-Zeilen: Warrior (1), Engineer (2), Esper (3), Medic (4), Stalker (5), Spellslinger (7). Alle in Class.csv referenzierten direkten Angriffs-/Innate-/Wiederbelebungs-Spell4-IDs sind vorhanden.
- 66.383 Spell4-Zeilen, 44.838 Spell4Base-Zeilen und 131.010 Spell4Effects-Zeilen mit 134 unterschiedlichen Effekt-Typen.
- 24.343 Spell4Telegraph-Zeilen, die 12.701 verschiedene Spell4-IDs referenzieren. Dazu TelegraphDamage, Zielmechaniken, Bedingungen, Kosten, Cooldown-Gruppen und Tier-Voraussetzungen.
- Native Visual-Tabellen: Spell4VisualGroup → Spell4Visual → VisualEffect, einschließlich Ressourcenpfaden und Ereignisdaten. Vorhandene Reader für M3/Materialien und ein Telegraph-Renderer sind Bausteine; sie führen die komplette native Spell-Visual-Zustandsmaschine noch nicht nachweislich aus.
- AMP-/Augmentationsdaten, Ressourcen/Vital-Definitionen und native Klassenreferenzen sind exportiert.
- Klassenicons und Beschreibungen stehen in der Charaktererstellung. Dort werden bestehende WoW-Klassenslots verwendet:

| WildStar | Technischer WoW-Träger |
|---|---|
| Warrior | Warrior, ID 1 |
| Engineer | Warlock, ID 9 |
| Esper | Mage, ID 8 |
| Medic | Priest, ID 5 |
| Stalker | Rogue, ID 4 |
| Spellslinger | Hunter, ID 3 |

Das ist eine UI-/Trägerzuordnung. Sie implementiert keine originalen Klassenmechaniken.

Klassenbezogene Spell4-Datenzeilen sind vorhanden: Warrior 2.395, Engineer 2.004, Esper 2.171, Medic 1.692, Stalker 1.635, Spellslinger 2.189. Die Zuordnung erfolgt über Spell4Base.classIdPlayer. Diese Zahlen enthalten interne Varianten, Trigger und Tier-Zeilen; sie sind **keine Anzahl erlernbarer Fähigkeiten**. Spell4GroupList darf nicht allein über eine gleichlautende ID mit Class verknüpft werden, um ein Fähigkeitenbuch zu erzeugen.

## Konkrete Probleme im aktuellen Export

Client und aktiver Server haben bytegleiche Spell.dbc-Dateien mit 116.222 Zeilen: alle 66.383 erwarteten WildStar-IDs sind vorhanden, keine doppelten DBC-IDs. Trotzdem sind in sämtlichen WildStar-Zeilen die tatsächlichen Felder für RangeIndex, ImplicitTargetA/B, DurationIndex, SpellVisualID und SpellIconID null.

`tools/ws_spells_to_dbc.py` setzt derzeit 54.352 Einträge als Dummy und 12.031 als pauschalen Schadenseffekt mit BasePoints 750. Die Effekte liegen im dritten Effektslot. Native Spell4Effects, Skalierung, Heilung, Schilde, Ressourcen, Procs und Klassenfähigkeiten werden dabei nicht vollständig ausgewertet.

Zusätzlich sind Feldindizes falsch zugeordnet. Anhand des lokalen SpellRec-Layouts:

| Bedeutung | Exporter schreibt | Richtiger DBC-Index |
|---|---:|---:|
| RangeIndex | 45 | 46 |
| ImplicitTargetA des benutzten dritten Slots | 85 | 88 |
| SchoolMask | 225 | 225 (korrektes Feld, pauschal physisch) |

Index 45 ist ManaPerSecondPerLevel, 85 ist EffectMechanic[2]. SchoolMask 225 wird vom alten Exporter pauschal auf physisch gesetzt. Die vorherige Audit-Version hatte hier f�lschlich 221 gepr�ft; das ist korrigiert. Darum bedeutet ein vorhandener Name/Spell-Eintrag nicht, dass Reichweite, Treffer oder Kosten funktionieren.

Auch der pauschale Offset `100000 + Spell4-ID` ist nicht ausreichend abgesichert: Die exportierten IDs 100001, 100099, 100100, 100101, 100102 und 150000 überschneiden sich mit bereits vorhandenen `spell_dbc`-Einträgen. 100101 ist zusätzlich mit dem fremden Server-Skript `spell_valkyr_ball_periodic_dummy_aura` verbunden. Das sind echte Überschneidungen trotz eindeutiger DBC-Zeilen. Die vorhandenen Servereinträge dürfen nicht einfach gelöscht werden.

Die Startzauber-Tabelle enthält derzeit keine WildStar-Startzauber für die WildStar-Rassenmaske. Der vorhandene Spell-Script-Eintrag im exportierten Bereich ist kein Klassenadapter, sondern die genannte Kollision.

## Was das aktuelle Telegraph-System leistet

Installiert sind WildStarTelegraph.lua und WildStarTelegraphData.lua; der Serverstart bestätigt die Registrierung. Der Client enthält WildStarTelegraphRenderer und ein Addon für Telegraph-Nachrichten.

Das ist ein Prototyp mit geometrischen Treffertests und verzögertem Auslösen. Der automatische Cast-Hook übergibt pauschal 750 Schaden und `isHealing=false`. Er ist nicht bereits die Auswertung der 131.010 nativen Effektzeilen. Platzhalter-WoW-Visuals, feste Hit-Radien/Höhengrenzen und vereinfachte Formen müssen gegen die Originalparameter geprüft werden. Native Effekte und zusätzliche Lua-Treffer dürfen denselben Cast nicht doppelt abrechnen. Abbruch, Tod, Bewegung, Timing und mehrere Beobachter sind bislang nicht als komplette Klassenmechanik abgenommen.

Die lokale NexusForever-Referenz hilft bei Enum-Bedeutungen und Geometrie, ist aber selbst kein Vollständigkeitsbeleg: Die untersuchte Registrierung in SpellEffectHandler.cs enthält 16 Handler; die nativen Tabellen verwenden 134 Effekt-Typen. Die C#-Implementierung läuft außerdem nicht unmittelbar in AzerothCore.

## Empfohlene Architektur

1. **Gemeinsame native Datenebene:** typisierte Spell-/Klassenbeschreibungen aus den originalen Tabellen; Spell4-ID, Base-ID, Tier, Effektfolge, Zielbedingungen, Ressourcen und Asset-Referenzen bleiben nachvollziehbar erhalten. Unbekannte dataBits werden nicht als fertige Formeln ausgegeben.
2. **Eigene ID-Zuordnung:** Manifest NativeSpellId → WoWSpellId, geprüft gegen DBCs UND relevante Server-SQL-Referenzen. Bestehende WoW-Spells bleiben erhalten. Änderungen werden als getrennte Client-/Server-Deltas mit Backup und Rollback erzeugt.
3. **AzerothCore-Adapter:** serverseitige Auswertung von Effekten, Ressourcen, Schilden, Interrupt Armor, Procs, Bedrohung, Bots und Bewegungsfähigkeiten. Native Klassenidentität und Fortschritt werden in eigenen Plugin-Tabellen gespeichert. Bestehende technische WoW-Slots können für WildStar-Charaktere als Träger dienen; zusätzliche echte Protokoll-Klassenplätze sind ein separates Client/Core-Projekt mit Anpassung harter Klassenlimits und Masken.
4. **Client-Erweiterung:** Fähigkeitensymbole, Tooltips, Ressourcenanzeigen, LAS, Telegraphen und native Visual-/Animationsereignisse. Anzeigen und lokale Vorhersage ersetzen keine serverseitige Treffer-/Kostenentscheidung.
5. **Portable Paketierung:** Native Tabellen/Assets, Client-Reader, serverunabhängige Spezifikation und AzerothCore-spezifischer Adapter bleiben getrennt. Ein anderer Server bekommt einen eigenen Adapter statt umgeschriebener Originaldaten.

## Umsetzung mit Abnahmekriterien

### 1. Export und Klassendefinitionen bereinigen

- Den alten Generator durch einen typisierten, zunächst offline arbeitenden Export ersetzen.
- Exakte Cast-/Cooldown-/Range-/Duration-Referenzen, Zielmasken, Schulen und Icons erzeugen; keine pauschalen Schadenswerte.
- Abhängigkeiten verfolgen: ausgelöste Zauber, periodische Effekte, bedingte Effekte, Tiers, Procs und Voraussetzungsketten.
- Fähigkeiten pro Klasse/Tier in einem Manifest mit Status `unbekannt`, `Daten vollständig`, `implementiert`, `getestet` ausweisen.
- Abnahme: keine Kollisionen oder offenen Pflichtreferenzen; Client/Server stimmen für die neuen Einträge überein; identischer Neuaufbau verändert keine fremden WoW-Zeilen.

### 2. Gemeinsame Kampfgrundlage

Implementierung begonnen: portabler Lua-Kern, native Basisbetragsberechnung und getrennte GM-Diagnose. Noch keine Live-Kampffreigabe; Details und offene Core-Anbindung: [wildstar_combat_phase2.md](wildstar_combat_phase2.md).

- Schaden, Heilung, periodische Effekte, Auren, Ressourcenverbrauch/-gewinn, Schilde und Interrupt Armor implementieren.
- Trefferformen, Reichweite, Sichtlinie, eigene/feindliche Ziele und Effektzeitpunkte serverseitig bestimmen.
- Abnahme: deterministische Sollwerte gegen einzelne Ziele, mehrere Ziele, Spieler und NPCs; korrekte Kosten/Cooldowns; Abbrüche hinterlassen keine Treffer oder doppelten Effekte.

### 3. Eine vollständige Pilotklasse: Warrior

- Originalen Grundangriff aus Class.csv sowie eine weitere aktive Fähigkeit, eine defensive Fähigkeit, Ressourcenzyklus und Innate gemeinsam fertigstellen.
- Reale Spell4Effects verwenden; Animation, Telegraph und Schadenszeitpunkt an denselben Cast binden.
- Abnahme: Anlegen, Startzauber, Lernen, Speichern/Neuladen, Kämpfen, Sterben und erneutes Einloggen funktionieren; andere Clients sehen dieselben Effekte. Das bestehende WoW-Klassensystem bleibt für WoW-Charaktere unverändert.

### 4. Die übrigen Klassen nach Mechanik ausbauen

- Medic/Esper: Heilung, Unterstützungsfähigkeiten, Ressourcen und kombinierte Heil-/Schadensflächen.
- Stalker: Tarnung, positionsabhängige Angriffe und Ressourcenverhalten.
- Spellslinger: Spell Surge, Aufladungen und Zauber-/Bewegungsabläufe.
- Engineer: Volatility, mehrere Bot-Rollen, Steuerung, Bedrohung und Wiederherstellung nach Login/Mapwechsel.
- Jede Fähigkeit wird erst nach eigenem Mechaniktest als funktionierend markiert. Reihenfolge darf sich ändern, wenn Pilotdaten eine bessere gemeinsame Grundlage ergeben.

### 5. Vollständige Klassenpakete

- Erlernbare Fähigkeiten von internen Triggern/Altständen abgrenzen; alle Tiers, AMPs, LAS-Wechsel und Fortschrittsdaten ergänzen.
- Originale VFX-/Animationen und Sounds schrittweise durch verfügbare Originalressourcen ersetzen.
- Abnahme: vollständige Klassen-/Tier-Matrix, Mehrspieler-/PvE-/PvP-Fälle, Leistungsprüfung mit vielen Telegraphen und Bots, konsistente Wiederherstellung gespeicherter Klassenstände.

## Entscheidung

**Spielbare originale Klassenlogik:** machbar als eigenes größeres Entwicklungsprojekt. **Sechs Klassen jetzt nur durch Import/Umbenennen vollständig originalgetreu:** nein. **100 % aller Fähigkeiten garantiert aus den vorhandenen Exporten reproduzierbar:** derzeit offen; unbekannte Effektsemantik und serverseitige Regeln müssen pro Fähigkeit geklärt werden.

Als nächster sinnvoller Implementierungsschritt dient Phase 1 mit anschließender Warrior-Pilotklasse. Vor dem vollständigen Core-Modul muss geklärt sein, dass die passende NPCBots-/Eluna-Core-Quelle reproduzierbar gebaut werden kann. Diese Prüfung hat keine realen Kampfzauber auf dem laufenden Server ausgeführt; sie ist eine Daten-/Codeanalyse, kein Live-Funktionstest.

## Primärquellen

- Lokal: tools/ws_spells_to_dbc.py; tools/ws_races.py; WoWClient/tables_csv/Class.csv, Spell4.csv, Spell4Base.csv, Spell4Effects.csv; wowdecomp/WoW/Source/DB/Rec/SpellRec.h.
- Lokal: Core/lua_scripts/WildStarTelegraph.lua; Client WildStarTelegraphRenderer.cpp; NexusForever/Source/NexusForever.Game/Spell/SpellEffectHandler.cs und Telegraph.cs.
- AzerothCore Eluna Player-Events: https://www.azerothcore.org/eluna/Global/RegisterPlayerEvent.html
- AzerothCore Eluna Spell-Events: https://www.azerothcore.org/eluna/Global/RegisterSpellEvent.html
- Eluna CastSpell (triggered casts umgehen Kosten/Castzeit): https://elunaluaengine.github.io/Unit/CastSpell.html
