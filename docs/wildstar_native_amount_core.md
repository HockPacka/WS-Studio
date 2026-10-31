# Native Betragsdaten bis zum echten Core-Test

Stand 29.10.2026, Paket `phase2-native-amount-6`.

Der native Effekt 89943 von Spell4 398 wird jetzt aus den originalen Tabellen
bis in den bereits geprüften physischen Core-Schadenspfad durchgereicht.
Die native Formel berechnet den Basisbetrag; der WoW-Core verarbeitet den
angeforderten Schaden. Danach heilt derselbe synchrone Test den gemessenen
Verlust mit dem bestehenden Test-Heilpfad zurück.

Das ist ein **GM-Betragstest mit ausdrücklich angegebenen nativen Teststats**,
noch keine freigegebene Warrior-Fähigkeit. Er übernimmt weder native Cast- und
Zielbedingungen noch vollständige WildStar-Rüstung, Crit, Variance und Procs.
Die Basisformel stammt weiterhin aus der partiellen lokalen NexusForever-
Referenz; sie wurde nicht durch diese Integration zu einer vollständig am
Originalserver verifizierten Schadensformel.

## Daten und Aufruf

`tools/ws_combat_data.py` exportiert jetzt zusätzlich:

- die vollständige Effektzeile 89943 samt float32-Bits,
- GameFormula 1266: `datafloat0 = 0.25`, `datafloat01 = 0.25`,
- die vollständige Formelzeile samt float32-Bits und Quelltabellenhash.

Neue vollständige Offline-Spell-Exporte kopieren auch die originale
`GameFormula.tbl` neben die anderen nativen TBLs. Vorhandene Exportpakete werden
nicht umgeschrieben. WoW-IDs, Client-/Server-DBCs und SQL bleiben unverändert.

Nach dem nächsten Lua-Reload ist folgender **Spielchat-Befehl** verfügbar:

```text
.wscombat test native398 100 100 1
```

Die drei Werte sind AssaultRating, SupportRating und der ausdrücklich gewählte
native Schadensart-Multiplikator. Es werden keine WoW-Werte als WildStar-Ratings
umgedeutet und keine nativen Stats im Charakter gespeichert.

Mit diesen Eingaben ergeben die 0,2/0,2-Koeffizienten und 0,25/0,25-Faktoren
Basisbetrag 10. Die Ausgabe nennt Effekt-ID, Basisbetrag und alle drei HP-Stände.
Der tatsächliche HP-Verlust kann durch den WoW-Core geringer sein. Ohne messbaren
Schaden oder Wiederherstellung wird kein Erfolg behauptet.

Vor dem ersten Core-Aufruf werden GM-Rang, Methoden, lebender Charakter,
verifizierter Heilzauber und Betragsgrenzen geprüft. Der Betrag muss unter dem
aktuellen HP-Stand liegen. Fehlende Stats/Formeln, falscher Effekttyp und zu hohe
Beträge brechen vorher ab. Dieser Pfad trifft nur den eigenen GM und kostet keine
Ressource. Automatisches native Spell-Casting ist weiterhin ausgeschaltet.

## Proxy-Inventur statt erfundener Serverregeln

`tools/analysis/ws_proxy_audit.py` hat sämtliche 16.929 Effekte vom Typ 26
inventarisiert. Verfügbarkeit des rohen `dataBits00`:

| Lookup-Zustand | Zeilen |
|---|---:|
| sowohl Spell4 als auch Spell4Base vorhanden | 6.775 |
| nur Spell4 vorhanden | 8.309 |
| nur Spell4Base vorhanden | 31 |
| in keiner der beiden Tabellen vorhanden | 1.814 |

Die letzte Kategorie enthält auch Null- und Sonderwerte; sie bedeutet nicht
automatisch, dass genau so viele defekte Zauber existieren. Häufige Kombinationen
enthalten beispielsweise dataBits04=1 oder UINT32 4294967295 und dataBits05=60.
Diese Zahlen bekommen ohne Verbrauchernachweis keine erfundenen Bedeutungen
wie Tier-, Level- oder Boolean-Schalter.

Ergebnis: `build_wildstar/analysis/proxy-audit-20261029/report.json` und
`proxy_rows.jsonl`, mit allen zehn Rohparametern, möglichen Instanz-/Basis-
Kandidaten sowie Quell- und Ergebnishashes. Die Inventur verändert keinen Server.

## Verifikation und verbleibende Arbeit

39 Kampf-/Hosttests, sechs Katalogtests und zehn Exporttests bestehen: insgesamt
55 automatisierte Tests. Drei neue Fälle führen echte native Fixture-Daten durch
den Rechner bis zu simulierten Core-Methoden und prüfen Abbruch vor Seiteneffekten.
Das ersetzt noch keinen Live-Test des neuen `native398`-Befehls.

Der Benutzer hat die vorherigen echten Core-Schaden-/Heiltests und die
Assault-Bedingungsauswahl bestätigt. Die vollständige Proxy-Serversemantik,
gespeicherte native Stats/Action Sets und NPC-Angreifbarkeitsprüfung bleiben
separate offene Anbindungen. Sie werden nicht durch den GM-Betragstest simuliert.
