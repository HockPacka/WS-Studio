# Native Proxy-Auflösung und getrennte Spell-IDs

Stand 29.10.2026. Die Assault-Auswahl des Bedingungsprüfers wurde vom Benutzer
im Spiel bestätigt: 398=false, 39339=false, 18309=true. Sie ist eine Diagnose
mit simuliertem Action Set; kein Charakterprofil wurde verändert.

## Was jetzt implementiert ist

`runtime/SpellCatalog.lua` trennt ausdrücklich:

- `kind=instance`: exakte Spell4-ID, kein zusätzlicher Tierparameter.
- `kind=base`: exakte Spell4Base-ID plus ausdrücklich angegebenes Tier.

Es gibt keinen Wechsel der Tabellen bei fehlenden Einträgen, kein voreingestelltes
Tier und kein Abrunden auf ein vorhandenes Tier. Mehrere Instanzen für dieselbe
Basis/Tier-Kombination, ungültige Indizes und fremde native Klassen werden
abgewiesen. Die IDs bleiben unverändert. Das ist ein verwendbarer Katalog-Lookup,
noch keine Entscheidung über die Semantik der Proxy-Parameter.

Der kleine Server-Diagnosekatalog enthält die relevanten Warrior-Reihen und die
gleich nummerierten fremden Instanzen. Er wird aus Originaltabellen erzeugt;
deren Hashes stehen in `CombatData.json`. Er lädt keinen vollständigen globalen
Spellkatalog in die laufende Lua-Engine.

| Native Basis | Tier 1: Spell4-ID | Weitere Tiers |
|---:|---:|---|
| 398 | 398 | nur Tier 1 |
| 18309 | 32078 | Tier 2–9: 48040, 48044, 48045, 48046, 48047, 48048, 48049, 48050 |
| 39339 | 61053 | Tier 2–9: 61054–61061 |
| 35927 | 55543 | nur Tier 1; ursprünglicher Class-Grundangriff |

Die exakte Instanz 18309 gehört dagegen zu Basis 8675, Tier 10, einem
NPC-Brawler-Stun. Instanz 39339 gehört zu Basis 23673, Tier 1, einem deprecated
Klasseneintrag mit classIdPlayer 15. Ein Spieler-Warrior-Lookup darf diese
Instanzen nicht stillschweigend anstelle der Warrior-Basis wählen.

## Originalclient: belegte Lookup-Kette

`FUN_140567950` kopiert Originaleffekte in 0xa8-Byte-Records: Typ bei +0x10,
dataBits00 bei +0x40, Voraussetzung für CasterApply bei +0x74.

`FUN_1403d3520` prüft für seinen Darstellungs-/Abfragepfad Effekt Typ 0x1a,
wertet die Voraussetzung aus und übergibt den rohen Wert +0x40 an
`FUN_1403acd90`. Diese Funktion versucht für einen lokalen Spieler bzw.
kontrollierten Akteur zuerst `FUN_1405a5b90`, die akteurspezifische Tabelle bei
state+0x7d18. Andernfalls benutzt sie `FUN_1407a0fd0`, den statischen Cache bei
manager+0x540. `FUN_14055e180` baut diesen Cache nach den IDs der Spell4-Zeilen.

Wichtig: Die akteurspezifische Tabelle ist kein belegter universeller
Basis-ID-zu-Tier-Mapper. Unter anderem erstellt `FUN_1403d4210` veränderte
Spell-Daten auf Basis eines statischen Spell4-Eintrags. Deshalb implementieren
wir keine automatische Konvertierung jedes Proxy-Werts in eine Spell4Base-ID.

Die eigentliche Basis-/Konfigurationsauswahl ist separat sichtbar:
`FUN_1403bad30` sucht eine Ability im Besitzstand und liest die Spell4-ID für die
angegebene aktive Konfiguration; das ist ein anderer Pfad als der reine
akteurspezifische Spell-Daten-Cache.

Auch `FUN_1405eda10` (Lua-Abfrage für Proxy-Channel-Daten) enthält einen
Typ-26-Lookup. Solche Client-Abfragepfade belegen noch nicht die vollständige
serverseitige Ausführung, insbesondere nicht die Bedeutung aller dataBits01–09.
Die öffentliche lokale NexusForever-Implementierung reicht dafür ebenfalls
nicht als vollständiger Nachweis aus.

## Schutz im Offline-Exporter

Neue Exporte kennzeichnen Proxy-Abhängigkeiten nun als
`targetKind=contextual_proxy_lookup`, `requiresContext=true`, `executable=false`
und lassen `wowTarget=null`. Der frühere direkte Spell4-Kandidat bleibt unter
`referenceCandidateWowTarget` zur Analyse erhalten; alle zehn rohen Parameter
bleiben ebenfalls enthalten. Bestehende Exportpakete werden nicht umgeschrieben,
IDs und DBC-Generierung wurden nicht geändert.

Damit ist die alte Referenzinterpretation weiterhin nachvollziehbar, wird aber
nicht als freigegebene Engine-Zuordnung weitergereicht. Das bestehende
`installable=false` der Katalog-Deltas bleibt wirksam.

## Tests, Installation und noch offener Schritt

Sechs neue Lua-5.1-Katalogtests prüfen beide Namespace-Kollisionen, alle neun
Tiers der zwei Warrior-Reihen, fehlende Werte, falsche Klasse, doppelte
Basis-/Tierkombinationen und unveränderliche Ergebnisse. Ein zusätzlicher
Exporttest prüft, dass ein Proxy-Kandidat keine ausführbare WoW-Referenz erhält.
Die bisherigen 36 Kampf-/Hosttests bleiben grün.

Version `phase2-typed-spells-5` ergänzt die rein lesenden GM-Befehle:

```text
.wscombat spell base 18309 1
.wscombat spell base 39339 1
.wscombat spell instance 18309
```

Der erste zeigt Spell4 32078, der zweite 61053. Der dritte wird wegen der
abweichenden nativen Klasse abgewiesen. Diese Befehle sind ausdrücklich
Warrior-Katalogdiagnostik; sie verändern keinen Lernstand und führen keinen
Zauber aus. Sie werden nach dem nächsten Lua-Reload verfügbar.

**Weiter offen:** Nachweis der serverseitigen Proxy-Modi und Tierweitergabe,
Anbindung eines tatsächlich gespeicherten nativen Spieler-Action-Sets sowie die
NPC-Zielprüfung im Repack ohne gebundene `IsValidAttackTarget`-Lua-Methode.
Native automatische Casts bleiben bis zur Klärung gesperrt. Kein weiterer
manueller Katalogtest ist für die bereits automatisiert geprüften Fälle nötig.

Nachweise liegen in `docs/combat_analysis/`; neue Originalclient-Dateien sind
mit SHA-256 im `proxy_evidence_manifest.json` erfasst.
