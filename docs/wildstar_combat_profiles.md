# Gespeicherte native Kampfprofile

Stand 29.10.2026, Paket `phase2-server-profiles-7`.

Der Benutzer hat den vorherigen nativen Betragstest im Spiel bestätigt:
Effekt 89943, Basisbetrag 10, HP 72 → 62 → 72, verified=true.

Die neue Fortsetzung speichert pro Realm und Spieler-GUID eine native Klasse,
optionale native Ratings und zwölf Plätze des aktiven Action Sets. Diese Daten
liegen ausschließlich in der neuen eigenen World-Tabelle
`wildstar_combat_profile`. Die originale Characters-Tabelle, WoW-Klasse,
Startzauber und vorhandene Charakterprofile werden nicht umgeschrieben.

## Benutzung im GM-Spielchat

Beispiel für ein **ausdrücklich durch einen GM konfiguriertes Warrior-Profil**:

```text
.reload eluna
.wscombat profile init 1
.wscombat profile stats 100 100 1
.wscombat profile slot 1 18309 1
.wscombat profile show
.wscombat native
.wscombat test profile398
```

`init` erzeugt ein Profil nur, wenn noch keines existiert. Klasse 1 ist Warrior;
weitere native IDs: 2 Engineer, 3 Esper, 4 Medic, 5 Stalker, 7 Spellslinger.
Die Werte nach `stats` sind AssaultRating, SupportRating und physischer
Schadensart-Multiplikator. Ohne ausdrückliche Konfiguration bleiben sie UNSET;
es gibt keine Umdeutung von WoW-Stärke oder Angriffskraft in native Ratings.

`slot 1 18309 1` speichert Ability-Basis 18309 auf Platz 1 mit genau Tier 1.
Klasse, Basis und Tier müssen im zugehörigen nativen Klassenkatalog passen.
Fremde Klassen, doppelte Ability-Basen, ungültige Plätze oder fehlende/mehrdeutige
Tiers werden abgewiesen. `.wscombat profile clear 1` leert einen Platz.

Ohne Szenarioargument liest `.wscombat native` jetzt dieses gespeicherte
Action Set. Die Auswertung ist damit nicht mehr auf die früheren simulierten
Testmengen angewiesen. `native assault/empty/tank/both` bleibt ausdrücklich
Fixture-Diagnostik und schreibt kein Profil.

`.wscombat test profile398` liest die gespeicherten Werte statt Zahlenargumenten
und führt den bereits vorhandenen GM-Betragstest aus. Der Test bleibt auf den
eigenen GM und auf ein Warrior-Profil begrenzt, berechnet den Basisbetrag von
Effekt 89943 und heilt den gemessenen Verlust zurück. Er ist **kein automatischer
Cast des Action-Set-Proxy-Zaubers** und prüft keine vollständige native
Fähigkeits-/Zielbedingungskette. Es gelten weiterhin die nichttödlichen
Betragsgrenzen und der Abstand von zwei Sekunden.

Mit `.reload eluna` oder erneutem Einloggen gehen die Profildaten nicht verloren:
Die Befehle lesen die World-Datenbank. Jeder erfolgreiche Schreibbefehl meldet
seine nach dem Schreiben erneut gelesene Revision. Für den normalen Login
wird kein Profil erfunden und kein kompletter Spellkatalog geladen.

## Aufbau und Speicherung

- `runtime/CombatProfile.lua`: Validierung und kanonischer numerischer Codec.
- `adapters/azerothcore/CombatProfileStore.lua`: synchroner DB-Adapter mit
  Compare-and-Swap über `revision` und anschließendem Rücklesen.
- `adapters/azerothcore/ws_combat_profile.world.sql`: getrennte Migration.
- `tools/ws_combat_profile_install.py --core ... --output ... --apply`:
  Installation nur der eigenen Tabelle, Prüfung vorhandener Ownership und Schema,
  MySQL-CAS-/Rollback-Test mit nicht realen IDs. Standard ohne `--apply` ist lesend.
- `tools/ws_combat_classes.py --output NEW_FOLDER`: reproduzierbare Klassenkataloge
  aus originalen Spell4/Spell4Base/Class-Tabellen samt SHA-256-Manifest.

Die sechs Kataloge werden als `Classes/Class<ID>.data` ausgeliefert. Eluna soll
sie nicht wie `.lua`-Skripte beim Start rekursiv ausführen. Der Adapter lädt mit
`dofile` nur den ausdrücklich benötigten Klassenkatalog. Die native
Kandidatenmenge enthält wie der Rohdatenexport auch interne/retired Varianten;
sie wird nicht automatisch als erlerntes Fähigkeitenbuch ausgegeben.

Der Codec enthält nur kanonische Zahlen, feste Versionsmarker und feste
Trennzeichen. Texte oder SQL-Identifikatoren des Benutzers gehen nicht in die
SQL ein. Realm und GUID werden aus dem aktuellen eingeloggten Spieler gelesen.
Änderungsbefehle sind auf GM-Rang 3 beschränkt und bearbeiten dessen eigenes
Profil. Stale Revisionen überschreiben keine inzwischen geänderten Werte;
fehlgeschlagene Schreibvorgänge werden nicht als gespeichert bestätigt.

Sämtliche DB-Zugriffe dieser ersten Anbindung erfolgen auf ausdrücklichen
GM-Befehl, nicht pro Frame und nicht automatisch beim Login. Für eine spätere
produktive Cast-Ausführung ist ein Mapthread-tauglicher Zustandscache mit
Invalidierung und einer Lern-/Fortschrittsanbindung noch erforderlich.

## NPC-Zielprüfung: konkreter Befund

Der zur Repack-Revision passende Quellausschnitt
`tools/reference/azerothcore-191715d85cad/src/server/game/Grids/Notifiers/GridNotifiers.h`
zeigt für `AnyUnfriendlyUnitInObjectRangeCheck`: lebend, kein Critter, Entfernung,
nicht freundlich und eine zusätzliche Creature-AOE-Bedingung. Der Prüfer ruft
**nicht** `IsValidAttackTarget` auf. Deshalb ist `GetUnfriendlyUnitsInRange`
kein vollständiger Ersatz für die fehlende Eluna-Methode. NPC-Schadensbefehle
bleiben bis zu einer verlässlichen Bindung oder einem vollständig geprüften
Core-Zauberpfad gesperrt; die Profilspeicherung umgeht diese Grenze nicht.

## Verifikation und Installation

67 automatisierte Tests bestehen: 51 Kampf-/Host-/Profiltests und 16 Katalog-/
Exporttests. Die zwölf Profiltests prüfen sechs Klassen, exakte Tierwahl,
Codec-Rundlauf, Trennung von Realm/GUID, Konflikte, fehlgeschlagene Schreibvorgänge
und den vollständigen Befehlsweg Profil → gespeicherte Ratings → Betrag →
simulierte Core-Schaden-/Heilmethoden. Die SQL-Adaptertests verwenden isoliertes
SQLite; zusätzlich bestand der echte MySQL-CAS-/Rollback-Test auf dem Server.
Die Testzeilen wurden zurückgerollt und ihre Abwesenheit erneut bestätigt.

Die eigene Tabelle ist installiert. Es wurden **keine echten Spielerprofile
automatisch angelegt oder mit Beispielwerten befüllt**. Backups/Installations-
und Prüfbelege liegen unter `build_wildstar/deployments/combat-profile-schema-*`
und `combat-server-profiles-*`. Die neuen Lua-Befehle werden mit dem nächsten
Lua-Reload verfügbar. Ein Live-Nachweis der neuen Profilbefehle steht noch aus.

Noch offen: automatische native Charakterklassenzuordnung aus der
Charaktererstellung, originale Lern-/Level-/Ausrüstungsprogression, mehrere
gespeicherte Spec-Konfigurationen, NPC-Profile und vollständige Proxy-Ausführung.
Die jetzt gespeicherten Ratings sind GM-konfigurierte servereigene Werte, keine
bereits fertig rekonstruierte Originalprogression. Native Auto-Casts bleiben aus.

Primärquellen zur Adapterprüfung:
[Eluna WorldDBQuery/WorldDBExecute](https://github.com/ElunaLuaEngine/Eluna/blob/master/methods/AzerothCore/GlobalMethods.h),
[Eluna Unit-Methoden](https://github.com/ElunaLuaEngine/Eluna/blob/master/methods/AzerothCore/UnitMethods.h),
[passender NPCBots-Core: GridNotifiers](https://github.com/trickerer/AzerothCore-wotlk-with-NPCBots/blob/191715d85cad/src/server/game/Grids/Notifiers/GridNotifiers.h).
