# Plan: Originalzauber aus WildStar in WoW 3.3.5a

Stand: 29.10.2026. Planung auf Grundlage der lokalen Tabellen, Quellen,
Analysebelege und der zuletzt installierten Pakete. Dieser Schritt verändert
keinen laufenden Kampf und aktiviert keine ungeklärten Originalmechaniken.

## Ziel und aktueller Abstand

Ziel ist, WildStar-Fähigkeiten aus ihren Originaldaten auszuführen: freie
Ausrichtung, passende Treffergeometrie, Cast-/Channel-/Tick-Zeitpunkte,
Klassenressourcen, mehrstufige Effekte sowie dazu synchronisierte Darstellung.
Eine Native-Fähigkeit darf ihren Schaden nicht zusätzlich aus der bisherigen
WoW-Kompatibilitätsvorlage erhalten.

Aktuell vorhanden:

- Sechs Klassen über bestehende WoW-Trägerklassen, je fünf Starterfähigkeiten.
- Native Spell-/Base-/Tier-IDs, Rohdaten und getrennte eigene ID-Zuordnung.
- Telegraph-Rohdaten für alle 30 Starter; abbrechbare Anzeige im Testclient.
- 47 native Effektbindungen für 23 Starter; sieben nutzen WoW-Effekte.
- Portabler Kampfprototyp für Flächen, Verzögerungen und periodische Effekte.
- Eigene persistente Klassen-/Action-Set-Profile und partielle Betragsformel.
- Im Spiel bestätigter physischer GM-Betragstest, keine vollständige native
  NPC-Kampfausführung. Die jüngste visuelle Version braucht noch Live-Abnahme.

Die laufenden Starter verwenden weiterhin WoW-Zielregeln, Werte und Ressourcen.
Die Originalform ist bisher eine ausdrücklich kosmetische Vorschau. Auch die
portable Geometrie ist normalisiert; sie beweist nicht die Bedeutung aller
nativen Shape-Parameter, Flags, Tick-Regeln oder Bedingungen.

## Architektur

```text
Originaltabellen + Analysebelege
             |
             v
versionierte, freigegebene Fähigkeitsspezifikation
             |
       +-----+-----------------------------------+
       |                                         |
       v                                         v
Client: Eingabe, Zielvorschau, FX             Server: Cast-Zustand,
       Render-Geometrie                            gültige Ziele, Ressourcen,
                                                  Treffer, Effekte
       ^                                         |
       +----- Cast-ID, Phasen und Bestätigung ----+
```

Lua bleibt die portable Klassen-/Profil- und Ablaufebene. Der Server-Host muss
die benötigten Zielprüfungen und Effektaufrufe gegen den jeweiligen Core
bereitstellen. Der Client sendet nur eine Cast-Anfrage samt begrenzter
Zielabsicht; keine Schadenswerte, Ressourcenbestände oder Trefferlisten.

WoW-Spell-IDs dienen als Transport-/Spellbook-Einträge. Pro Fähigkeit gibt es
einen expliziten Modus `compat` oder `native`. Bei `native` werden die bisherigen
WoW-Nutzwirkungen ersetzt, bevor die eigene Ausführung freigegeben wird.
Visuelle WoW-Transporteffekte dürfen als gekennzeichneter Ersatz bleiben.

## 1. Verbindliche Spezifikation je Fähigkeit

Aus Spell4, Spell4Base, Spell4Effects, Spell4Telegraph, TelegraphDamage,
Spell4Conditions, Prerequisite, TargetGroup, Zielbeschränkungen und den
Ressourcen-/Formeltabellen einen vollständigen Ablauf zusammenstellen.

Die Spezifikation enthält Original-ID, Klasse, Basis und Tier; Cast-/Channel-
Phasen; alle Flächen samt lokalen Offsets, Orientierung, Höhenbereich und
Zielauswahl; Effekt-/Tick-Reihenfolge; Kosten, Erzeugung und Cooldowns;
Voraussetzungen; visuelle Phasen und Herkunft jedes Werts.

Jeder Teil erhält einen Belegstatus: Originaltabellendaten,
Originalclient-Verbraucher belegt, Referenzimplementierung, Annäherung oder
ungeklärt. Rohdaten und Hashes bleiben erhalten. Unbekannte Mechaniken dürfen
nicht durch einen stillen Standardwert zu vermeintlichen Originalregeln werden.

**Abnahme:** Für jeden der 30 Starter gibt es eine eigenständige, prüfbare
Abhängigkeitsliste und eine Liste seiner tatsächlichen Native-Blocker.

## 2. Produktionsfähigen Server-Host herstellen

Vor dem ersten nativen Gegnerkampf prüfen, welche APIs das konkrete Repack
wirklich bereitstellt. `IsValidAttackTarget` fehlte beim bisherigen Lua-Test;
eine Liste unfreundlicher Einheiten ersetzt diese Prüfung nicht.

Benötigt werden gültige Schadens-/Heilziele einschließlich Immunitäten,
Unangreifbarkeit, PvP-/Duellregeln, Fraktion, Map, Instanz, Phase und Sichtlinie;
korrekt zugeordnete Core-Schadens-/Heilereignisse; Abbruch, Tod, Logout und
Despawn; sowie ein verlässlicher Update-Zeitgeber. Unveränderliche IDs statt
ungesicherter Unit-Zeiger über verzögerte Aufrufe halten.

Fehlende Funktionen über eine kleine Core-Erweiterung exponieren. Dafür sind
passende Quellen und ein reproduzierbarer Build des Repack-Cores erforderlich;
der vorhandene partielle Referenzbaum ist kein vollständiger Buildbaum. Eine
beliebige DLL kann diese Versionsbindung nicht ersetzen. Bis dahin können
Importer, Renderer und isolierte Testfälle weiterentwickelt werden.

**Abnahme:** Native Tests treffen ausschließlich berechtigte Ziele. Der Core
erhält Schaden/Heilung mit korrekter Urheberschaft genau einmal. Bedrohung,
Absorption, Tod und Kampflog werden kontrolliert. Ein bloßes Setzen von HP zählt
nicht als fertige Integration.

## 3. Gemeinsame Geometrie und Cast-Zustandsmaschine

Kreis, Ring mit Innenradius, Rechteck, Quadrat, Kegel mit beliebigem Winkel,
LongCone und Pie getrennt belegen und implementieren. Native Achsen/Einheiten,
Offsets, Rotation und Parameterbelegung gegen Originalverbraucher prüfen.
Client und Server führen denselben versionierten Geometrievertrag aus und
werden mit identischen Referenzpunkten getestet.

Zusätzlich klären: Caster- oder Bodenanker, bei Start fixierte oder mitgeführte
Fläche, Verhalten bei Drehung/Bewegung, Trefferzeitpunkte, Trefferbudget,
Mehrfachflächen, Zielkapseln und vertikale Reichweite. Terrainprojektion ist
Darstellung und ersetzt keine Sichtlinien-/Höhenprüfung.

Serverzustände: Anfrage -> angenommen -> Vorbereitung/Channel -> Treffer/Ticks
-> abgeschlossen oder abgebrochen. Kosten-, Cooldown- und Ziel-Snapshot-Zeitpunkt
werden je Mechanik ermittelt; der heutige Prototyp ist dafür noch kein Beleg.

**Abnahme:** Ziele innerhalb, außerhalb und exakt auf jeder Flächengrenze;
verschiedene Höhen; Drehung/Bewegung; Unterbrechung vor dem Treffer und zwischen
Ticks. Anzeige und Treffer müssen im jeweiligen Test dieselbe Fläche meinen.

## 4. Erster Pilot: Warrior

Zunächst Spell4 **398** / Effekt **89943** als kleinsten serverseitigen
Schadenspfad verwenden. Dafür existieren Formel- und Live-Testbelege. Spell 398
hat in der aktuellen Direktzuordnung keinen eigenen Telegraphen; ihm wird
deshalb keine erfundene Originalfläche zugewiesen. Der Test beweist weiterhin
nicht die vollständige WildStar-Schadensformel.

Danach **Relentless Strikes**, Basis **18309**, Tier-1-Instanz **32078**, als
ersten vollständigen Spielerzauber umstellen: Originalkegel, mehrere Ziele,
Combo-Abfolge, zugehörige Ressourcen- und Effektphasen.

Wichtiger Blocker: Instanz 32078 enthält einen Proxy-Effekt vom Typ 26. Erst
dessen echten Zielpfad und Combo-Zustand klären; 18309 darf nicht einfach als
Spell4-Instanz benutzt werden. Instanz 18309 bezeichnet einen fremden NPC-Zauber.
Die verbleibenden Proxy-Datenfelder sind nicht vollständig entschlüsselt.

**Abnahme:** Ein Warrior kann den freigegebenen Ablauf auslösen, passend zu den
belegten Zielregeln Gegner treffen und auf freigegebene Weise Ressourcen
erzeugen/verbrauchen. Abbruch und Wiederholung funktionieren; der bisherige
Sinister-Strike-Effekt und der alte Lua-750-Schaden wirken nicht zusätzlich.

## 5. Effektfamilien und native Werte ergänzen

Nach dem Pilot gemeinsame Handler nacheinander erweitern:

1. Direkter Schaden/Heilung, verzögerte Treffer, DoT/HoT und Channel-Ticks.
2. Getrennte native Stats, Physical/Tech/Magic, Schilde und Absorption.
3. Buffs, Debuffs, Stapel-/Ablaufregeln, Dispel, Stun/Root und Interrupt Armor.
4. Bewegung, Ladestufen, Combos, Procs und geprüfte Proxy-/Kindzauber.
5. Bots, beschworene Einheiten und ihre Befehls-/Bedrohungslogik.

Die bisherige Betragsformel ist partiell. Crit, Varianz, Abwehr, Schilde,
Mehrfachtreffer und Procs werden gesondert belegt. WoW-Rüstung oder WoW-Stats
werden nicht ohne Kennzeichnung als native Werte ausgegeben. Die Entscheidung,
welche Abwehr die Native-Engine berechnet und welche der Core noch anwendet,
muss insbesondere doppelte Schadensreduktion ausschließen.

## 6. Klassenweise erweitern

Die folgende Reihenfolge ist ein vorgeschlagener Arbeitsplan, kein Beleg dafür,
dass ihre Wrapper bereits vollständig aufgelöst sind:

| Reihenfolge | Klasse | Erster Kandidat | Darauf aufbauend |
| --- | --- | --- | --- |
| 1 | Warrior | Relentless Strikes | Combo, Kinetic Energy, weitere Angriffe |
| 2 | Esper | Telekinetic Strike | Rechteck, Psi-Punkte, Heilung |
| 3 | Stalker | Shred | Kegel, Suit Power, Stealth, Positionsregeln |
| 4 | Medic | Discharge, danach Emission | Channel, Actuators/Focus, Schildheilung |
| 5 | Spellslinger | Quick Draw | Schussfolgen, Aufladen, Spell Surge |
| 6 | Engineer | Pulse Blast | Volatility, Channels, danach Bots |

Schon die Direktdaten zeigen Proxy-/Zusatzmechaniken in allen genannten
Starter-Wrappers. Die einfache Darstellung einer Fähigkeit sagt daher nichts
über die Vollständigkeit ihrer Ausführung aus. Nach dem ersten fertigen Zauber
pro Klasse werden deren fünf Starter und anschließend weitere Originalfähigkeiten
ergänzt. Tiers, AMP und Progression folgen auf eine tragfähige Basisausführung.

## 7. Darstellung, Netzwerk und Effekte vervollständigen

Serverbestätigte Cast-IDs, Start-/Phasen-/Trefferzeiten und Abbrüche an sichtbare
Teilnehmer senden. Lokale Vorschau darf sofort reagieren, wird aber mit dem
Serverzustand abgeglichen. Reihenfolge, Duplikate, Verzögerung, Reichweite,
Instanz und Phase berücksichtigen. Ein serverseitiger Cast darf nicht allein
von einer frei sendbaren Addon-Nachricht ausgelöst werden.

Derzeit existiert nur Darstellung beobachtbarer Unit-Tokens. Eine Umgebung-
Verteilung für weitere Akteure muss ergänzt werden. Der native Renderer braucht
variable Kegelwinkel, echte Ringradien, alle Offsets und mehrere bedingte Formen.

Für FX die tatsächlichen Stage-/Target-Flags, Animationsereignisse, Verzögerungen,
Attachments und Scale-Regeln rekonstruieren. Anschließend die sieben
Fallback-Fähigkeiten, SkinFX/Emitter ohne Geometrie, native Projektile und
Soundphasen ergänzen. Wiederholtes Casten darf keine verwaisten Effekte oder
erneute synchrone Modellkonvertierung bei jedem Treffer verursachen.

**Abnahme:** Sichtbare Phasen stimmen mit der serverseitigen Ausführung überein,
auch bei Abbruch und mit mehreren Spielern. Original-FX werden nicht allein
wegen erfolgreicher Offline-Konvertierung als im Spiel geprüft markiert.

## 8. Freigabe, Debug und Portabilität

Eigene Daten-/SQL-Pakete, Lua-Plugin und Core-Host getrennt versionieren;
Bestandsdaten und IDs erhalten. Bestehende explizite Diagnoseprofile nicht
automatisch überschreiben. Native Klassen-/Ressourcendaten bekommen eigene
Felder statt eine stillschweigende Umdeutung von WoW-Trägerklassenwerten.

Ein serverseitig kontrollierter Modus je Fähigkeit sowie GM-Diagnosen zeigen:
ausgewählte Instanz/Tier, erfüllte Voraussetzungen, aktive Fläche, Trefferliste,
Basisbetrag/Reduktionen, Ressourcenänderung und Effektphasen. Die globale
Client-Vorschau ist kein Umschalter für die Ausführungsart.

Jede Fähigkeit wird einzeln freigegeben. Die Matrix umfasst Spieler/NPC,
Freund/Feind, Mehrspieler, Immunität, LoS, Höhe, Tod/Logout/Mapwechsel, Abbruch,
Ticks, Kosten, Cooldown, Doppelverarbeitung und wiederholte Casts unter Last.
Ein anderer Server benötigt einen passenden Host und dieselben Fähigkeitspakete;
eine universell auf jedem Core lauffähige Binärdatei wird nicht vorausgesetzt.

## Konkretes nächstes Arbeitspaket

1. Vollständigen Relentless-Strikes-Abhängigkeitsbericht mit Rohparametern und
   Belegstatus erzeugen; zusätzlich alle 30 Starter nach Blockern klassifizieren.
2. Repack-Host auf benötigte APIs prüfen und passende Core-Buildquelle klären.
3. Proxy-/Combo-Ausführung des Piloten und native Kegelparameter am Originalclient
   weiterverfolgen; Clientbelege nicht als Beweis des geschlossenen Servers ausgeben.
4. Gemeinsamen Geometrievertrag mit Grenztests bauen.
5. Erst danach den Pilot serverseitig ausführen und live abnehmen.

Eine vollständige 1:1-Zusage ist heute nicht belegbar: Originalserverlogik ist
nicht vollständig vorhanden, und mehrere Datenfelder/Mechaniken sind offen.
Der Plan liefert schrittweise prüfbare Originalmechaniken und weist verbleibende
Annäherungen ausdrücklich aus.
