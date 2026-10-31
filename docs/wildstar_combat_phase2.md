# Phase 2: gemeinsame Kampfgrundlage – erster Implementierungsstand

Stand: 28.10.2026. **Phase 2 ist noch nicht vollständig abgenommen.** Die portable
Ausführung und der Diagnoseadapter sind implementiert; native Fähigkeiten sind
damit noch nicht für den laufenden Kampf freigegeben.

## Neuer Stand: serverseitig gespeicherte native Profile

Version `phase2-server-profiles-7` ergänzt eigene persistente Spielerprofile mit
nativer Klasse, optionalen Ratings und aktuellem Action Set. Alle sechs nativen
Klassenkataloge werden bedarfsweise geladen. Die neue eigene SQL-Tabelle ist
installiert; MySQL-CAS/Readback/Rollback ist geprüft. Insgesamt 67 automatisierte
Tests bestehen. Keine echten Profile wurden automatisch erstellt; Ratings sind
explizite GM-Konfiguration, noch keine Originalprogression.
Details und Befehle: [wildstar_combat_profiles.md](wildstar_combat_profiles.md).

## Neuer Stand: native Betragsdaten im Core-Test

Version `phase2-native-amount-6` verbindet Originaleffekt 89943 und GameFormula
1266 über die partielle Referenz-Basisformel mit dem echten GM-Core-Testpfad.
55 automatisierte Tests bestehen. Zusätzlich sind alle 16.929 nativen
Proxy-Effekte mit Rohparametern und Lookup-Kandidaten inventarisiert.
Grenzen und genauer Aufruf: [wildstar_native_amount_core.md](wildstar_native_amount_core.md).
Native automatische Fähigkeiten bleiben weiterhin gesperrt; der neue Aufruf
ist ausdrücklich ein Betragstest mit vorgegebenen Stats.

## Neuer Stand: getrennte Spell-IDs und Proxy-Referenzen

Die Assault-Bedingungsauswahl wurde im Spiel bestätigt. Die nächste Fortsetzung
ergänzt eine explizite Auflösung von Spell4-Instanzen gegenüber Basis-ID plus
Tier, weist gleich nummerierte fremde Einträge ab und sperrt Proxy-Kandidaten
im neuen Export ausdrücklich als nicht ausführbare Kontextreferenzen.
Details: [wildstar_proxy_resolution.md](wildstar_proxy_resolution.md).
Version `phase2-typed-spells-5`; automatische native Casts weiterhin gesperrt.

## Neuer Stand am 29.10.2026: Typ 221 geklärt

Der Benutzer bestätigt den kombinierten Schaden-/Heiltest als funktionierend.
Die folgende Originalclient-Analyse hat Typ 221 als aktives Action-Set-Mitglied
entschlüsselt und die bisher aus NexusForever übernommenen Vergleichsoperatoren
3/4 und 5/6 korrigiert. Der Prüfer unterstützt jetzt die realen Warrior-Bedingungen;
36 Kampf-/Hosttests bestehen. Details und Nachweise:
[wildstar_prerequisite_221.md](wildstar_prerequisite_221.md).

GM-Diagnose nach `.reload eluna`: `.wscombat native empty`, `assault`, `tank`
oder `both`. Dies sind ausdrücklich simulierte Action Sets; sie ändern keine
Charakterprofile und wirken nicht auf Kämpfe. Ohne Szenario bleibt der Zustand
UNKNOWN, solange kein serverseitiges natives Action Set angebunden ist.
Version: `phase2-prerequisites-4`. Die nachfolgenden Abschnitte dokumentieren
die vorangegangenen Stände; ihre offene Bedeutung von 221 ist damit überholt.

## Fortsetzung: Core-Testadapter v2

Nach dem ersten Live-Test wurde im Screenshot Schaden von HP 63 auf 54 bei
angefordertem Betrag 10 beobachtet. Die Lua-Probe meldete ausschließlich
`IsValidAttackTarget` als fehlend. Der spätere Heilschritt 63 auf 63 belegt noch
keine wirksame Heilung. Version `phase2-core-tests-3` ergänzt deshalb
`.wscombat test roundtrip 10`: synchron Schaden am eigenen GM, danach Heilung
genau des gemessenen Verlusts; Ausgabe zeigt alle drei HP-Stände und die
beobachteten Differenzen. Ohne messbaren Schaden oder ohne Wiederherstellung
wird kein Erfolg behauptet. Betrag muss unter dem aktuellen Lebensstand liegen.
Ein optionaler Ressourcenverbrauch erfolgt nur einmal. Die drei zusätzlichen
Roundtrip-Tests bestehen; der neue Roundtrip im echten Repack steht noch aus.

Der erste Selbsttest wurde vom Benutzer im laufenden Server erfolgreich ausgeführt
(Screenshot mit `PASS: cost, shield, periodic timing, unique targets, cancellation, cleanup`).
Das bestätigt die Lua-Ausführung im Repack, noch keinen echten Kampftest.

Neu hinzugekommen sind `runtime/Prerequisite.lua`, der synchrone
`adapters/azerothcore/CombatHost.lua` und generierte `data/CombatData.lua`.
Der GM-Adapter meldet Version `phase2-core-tests-2`.

Die Testbefehle gehören **in den Chat eines eingeloggten GM-Charakters**, nicht
in die Serverkonsole `AC>`. Der Adapter gibt bei Konsolenausführung jetzt einen
entsprechenden Hinweis aus.

```text
.reload eluna
.wscombat probe
.wscombat test selfdamage 10
```

Nach mindestens zwei Sekunden:

```text
.wscombat test heal 10
```

`selfdamage` und `heal` treffen ausschließlich den eigenen GM-Charakter. Für einen
ausgewählten feindlichen NPC existiert zusätzlich `.wscombat test damage 10`.
Dieser Pfad verlangt die tatsächlich gebundene Methode `IsValidAttackTarget`;
fehlt sie im Repack, bleibt er gesperrt. Der Probe-Befehl listet fehlende Methoden.
Keine Fraktionsnummer wird als Ersatz für die echte Angreifbarkeitsprüfung benutzt.

Ein optionaler letzter Zahlenwert testet den Verbrauch der **aktuellen technischen
WoW-Ressource**, z. B. `.wscombat test selfdamage 10 5`. Das ist noch keine
Zuordnung nativer WildStar-Vitals. Mengen sind auf 1–1000 begrenzt, Kosten auf
0–100, die GM-Testbefehle haben zwei Sekunden Abstand. Es wird nicht automatisch
Schaden ausgeführt; nur ein ausdrücklicher GM-Testbefehl löst den Aufruf aus.

Der Host verwendet `DealDamage(target, amount, false, 0, 0)` (physischer
WoW-Testpfad) und `DealHeal(target, 2050, amount, false)` (bestehender WoW-Heilzauber
nur zur Testattribution). Die Wirkung hängt von Core-Regeln, Rüstung, Absorption,
Godmode und dem aktuellen Lebensstand ab; angeforderter Betrag und gemessener
HP-Unterschied werden getrennt ausgegeben. Keine `SetHealth`-Abkürzung.
Die öffentliche Eluna-AzerothCore-Implementierung wurde als Referenz geprüft;
identisches Verhalten des modifizierten Repack ist erst durch Live-Tests belegt.
Ein erfolgreicher Methodenaufruf allein beweist insbesondere nicht alle Procs.

`tools/ws_combat_data.py` prüft vor Erzeugung des Testpakets, dass Zauber 2050
in Client- und Server-Spell.dbc einen HEAL-Effekt hat, und speichert Hashes.
Er exportiert außerdem die originalen drei Proxy-Effekte und ihre Bedingungen
aus den nativen TBLs. `.wscombat native` zeigt ihre aktuelle Auswertbarkeit an.

Prerequisites: AND/OR, Vergleiche, Level, native Rasse/Klasse, native Spellbook-
Prüfung vom Typ 214 und verschachtelte Bedingungen sind implementiert.
Fehlende Werte, unbekannte Typen und Zyklen ergeben UNKNOWN. Insbesondere macht
Negation aus UNKNOWN keinen erfüllten Zweig. Typ **221 bleibt unbekannt**;
Warrior-55543 wird deshalb noch nicht ausgeführt. Die drei Proxies werden nicht
gemeinsam ausgelöst. Keine Gleichsetzung von 221 mit 214 aufgrund ähnlicher Namen.

Tests nach dieser Fortsetzung: 29 Lua-5.1-Tests bestehen, darunter zwölf zusätzliche
Host-/Prerequisite-Tests mit simulierten Core-Objekten. Diese ersetzen keine echten
Spieler-/NPC-Kampftests. Der neue Host ist synchron für unmittelbare GM-Tests;
Core-Periodik, Abbruchereignisse und Ressourcen-Transaktionen bei Core-Fehlern
sind noch nicht produktiv angebunden. Die portable Periodik bleibt separat getestet.

Installation zusätzlich zu den drei ursprünglichen Runtime-Dateien:
`Prerequisite.lua`, `CombatHost.lua` und `CombatData.lua` ebenfalls nach
`Core/lua_scripts/WildStarCombat/`, aktualisierter Adapter in `lua_scripts/`.
Backups und Hash-Manifest liegen unter `build_wildstar/deployments/combat-core-tests-*`.
SQL und DBCs wurden dabei nicht verändert. `native combat=false` bleibt korrekt;
die neuen expliziten GM-Core-Tests werden separat angezeigt.

Code-Referenz:
[Eluna UnitMethods für AzerothCore](https://github.com/ElunaLuaEngine/Eluna/blob/master/methods/AzerothCore/UnitMethods.h).

## Implementiert und geprüft

- `plugins/wildstar335a/runtime/Combat.lua`: serverseitig aufzurufender Lua-5.1-Kern
  mit getrenntem Host-Vertrag. Validierung vor Kostenabzug, Ressourcenprüfung,
  Cooldown und Cast-Sperre, zeitlich sortierte Einmal-/Periodikeffekte,
  Abbruch ohne verbleibende Treffer, Deduplizierung von Mehrfachzielen.
- Geometrie: Einzelziel, Kreis, Ring, Kegel (Winkel in Radiant), vorwärts gerichtetes
  Rechteck; erneute Prüfung von Reichweite, Höhe, Sichtlinie, Beziehung, Map,
  Instanz, normalisierter Sichtbarkeitsphase und Lebensstatus bei jedem Treffer.
  Flächen sind am aktuellen Caster verankert; bodenzentrierte und bewegte
  Telegraphen sowie Kollisionsradien sind noch nicht umgesetzt.
- Referenz-Zustandsmodell für Schaden, Heilung, Schild, Ressourcen, benannte
  Auren mit Ablauf und Interrupt Armor. Das ist ein Testmodell; dessen Regeln
  (Schild zuerst, Aura ersetzt gleichen Schlüssel, letzter Rüstungsbruch unterbricht)
  sind ausdrücklich normalisierte Regeln, noch keine belegte vollständige
  WildStar-Semantik. Aura-Ablauf wird durch `Combat.expire(unit, now)` angestoßen.
- `NativeAmount.lua`: native Basisbeträge für Effekt 8 (Damage) und 10 (Heal),
  anhand der lokalen NexusForever-Referenz. `dataBits00` wird als IEEE-float32,
  `dataBits01` als Zahlenwert gelesen. Parameter 1–5, 7–8, 10–17, 19, 21–23,
  25–26 werden unterstützt. Unbekannte Parameter werden abgewiesen, nicht nullgesetzt.
  Assault-/Support-Rating braucht explizite GameFormula-1266-Faktoren; die native
  Schadensart braucht einen expliziten Multiplikator. Keine erfundene WoW-Statzuordnung.
  Float32-Arithmetik wird pro Operation gerundet, damit etwa 0,2-Koeffizienten
  vor `Ceiling` keine zusätzlichen Schadenspunkte erzeugen.
- GM-Diagnoseadapter `WildStarCombatServer.lua`: `.wscombat status` und
  `.wscombat selftest`, Rang mindestens 3. Der Selbsttest arbeitet ausschließlich
  auf privaten Lua-Tabellen. Keine SQL-Änderung und keine Kampfzauberregistrierung.

## Host-Vertrag für den folgenden echten Core-Adapter

`Combat.new(host)` benötigt `unit(id)`, `units(caster, range)`,
`friendly(caster, target)`, `los(caster, target)` und
`apply(caster, target, effect, timestamp, castId)`.

IDs sind während eines Casts stabile, map-/instanzübergreifend eindeutige
Schlüssel. `unit` liefert aktuelle Werte oder nil, niemals ein veraltetes
Eluna-Unit-Objekt. `phase` bezeichnet eine normalisierte Sichtbarkeitsgruppe;
ein echter WoW-Phasenbitmaskentest muss der Adapter vornehmen. Feindliche
Zielauswahl braucht zusätzlich echte Angreifbarkeits-/PvP-/Immunitätsregeln.
Host-Aufrufe laufen seriell auf dem Mapthread und dürfen den Scheduler nicht
rekursiv betreten. `advance` wird durch den Server-Takt mit monotoner Millisekundenzeit
aufgerufen. Grobe Zeitsprünge sind Testbetrieb und keine historische Weltsimulation.

`Combat.reduce` dient ausschließlich dem isolierten Referenzmodell. Ein produktives
`apply` muss Schaden/Heilung inklusive Attribution, Bedrohung, Absorption, Tod,
Logs und Procs über den Core abwickeln und Ressourcen/Schild/CC atomar führen.
Für Auren sind native Stapel-, Suspend- und Persistenzbedingungen zu implementieren.
Ein Core-Schaden darf nicht gleichzeitig von DBC und Telegraph-Lua ausgelöst werden.

Der Diagnoseadapter registriert absichtlich keinen Player-Spell-Cast-Handler.
Der vorhandene, parallel bearbeitete `WildStarTelegraph.lua` mit seinem
750-Schadensprototyp bleibt unverändert und ist **nicht** diese Kampflogik.
Die neuen Katalog-IDs bleiben nicht installierbar.

## Konkreter nativer Befund

Warrior-Grundangriff aus Class.tbl: Spell 55543. Seine drei Effekte
132546/132547/132548 sind Proxy-Effekte (Typ 26) auf 398/18309/39339 und hängen
an Prerequisite 23082/23083/23084. Diese Auswahlbedingungen dürfen nicht durch
das Ausführen aller drei Zweige ersetzt werden.

Effekt 89943 von Spell 398 verwendet Damage Typ 8, float32-Multiplikator 1,
Basis 0 und je 0,2 Assault-/Support-Koeffizient. Ein Test mit ausdrücklich
vorgegebenen Ratingwerten 100/100 und Faktoren 0,25/0,25 ergibt Basisbetrag 10.
Das ist ein Testwert, keine Aussage zum tatsächlichen Charakter-/Levelschaden.
Die Basisberechnung führt noch keine Rüstung, Crit, Glance, Variance oder Procs aus.

## Verifikation und Installation

Tests aus Projektwurzel:

```powershell
python -m pip install lupa
python -m unittest discover -s tools/tests -p test_ws_combat.py -v
```

Die Tests führen den Code mit `lupa.lua51` aus. Abgedeckt sind Kosten/Cooldowns,
Abbruch vor und während Periodik, einmalige Treffer, Mehrfachziele,
Freund-/Feindauswahl, Formen, LOS/Range/Map/Instanz/Phasenwechsel, Tod,
Schild/Heilung/Aura/Interrupt Armor, ungültige Eingaben, unveränderliche Castkopien,
native Parameter und float32-Rundung, GM-Prüfung und fehlender Spell-Cast-Hook.

Installation des Diagnosepakets: drei Dateien aus `runtime/` nach
`Core/lua_scripts/WildStarCombat/`, den Adapter nach
`Core/lua_scripts/WildStarCombatServer.lua`. Der Server lädt sie erst beim nächsten
Lua-Reload/Start. Ein kopiertes Skript ist kein Beleg für einen erfolgreichen
Live-Test. Entfernung dieser vier Dateien deaktiviert ausschließlich dieses Paket.

## Noch offen bis Phase-2-Abnahme

1. Passende vollständige Core-Quellen samt Repack-/Eluna-Erweiterungen reproduzierbar
   bauen; lokale `tools/reference/azerothcore-191715d85cad` sind nur Quellauszüge.
2. Host an reale Spieler und NPCs anbinden, API-Version prüfen, echte Kampf-/Heal-
   Pipeline, Ressourcen, Schilde und CC mit Core-Regeln verbinden.
3. Native Zielmasken, Prerequisites, Proxy-Auswahl, Effektbedingungen und Kosten
   vollständig übersetzen. Unbekannte Mechanik bleibt gesperrt.
4. Telegraph- und WoW-Spell-Ausführung auf eine einzige Autorität umstellen,
   Abbruch/Logout/Tod/Mapwechsel mit dem Core verbinden.
5. Echte Mehrspieler-/NPC-Tests und Schadens-/Heilprotokolle gegen Sollwerte abnehmen.

Primärreferenzen für die spätere Eluna-Anbindung (öffentliche Dokumentation,
keine Bestätigung der API-Version des laufenden Repack):
[DealDamage](https://www.azerothcore.org/eluna/Unit/DealDamage.html),
[DealHeal](https://www.azerothcore.org/eluna/Unit/DealHeal.html),
[IsWithinLoS](https://www.azerothcore.org/eluna/WorldObject/IsWithinLoS.html),
[RegisterPlayerEvent](https://www.azerothcore.org/eluna/Global/RegisterPlayerEvent.html).
