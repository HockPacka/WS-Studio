# Genesis ClientData – optional editor settings

**Verhalten ab diesem Stand:** Der Genesis-Editor startet grundsätzlich **ohne obligatorischen WildStar-Data-Root-Dialog**. Das bestehende helle Genesis-Layout und die übrigen Menübefehle bleiben unverändert.

- **Settings → ClientData Settings...** öffnet einen optionalen Dialog mit Pfad-Eingabe, Ordnerauswahl, Validieren/Indexieren und Trennen.
- Bereits gespeicherter Root wird beim Start wie bisher automatisch indexiert, ohne dass ein Dialog aufpoppt.
- Der Pfad wird erst nach erfolgreicher Indexierung im lokalen Nutzerprofil unter **LOCALAPPDATA/GenesisRebuild/client_root.txt** gespeichert; der WildStar-Client wird dabei nicht verändert.
- **Disconnect** löscht nur diesen gespeicherten Konfigurationspfad und setzt den Asset-Index zurück. Der Spielordner bleibt unverändert.
- Eine **Standalone-.area** kann auch ganz ohne ClientData über **File → Open AREA...** oder **Open AREA by path...** geladen, mit dem Height-Editor bearbeitet und als neue Datei exportiert werden. Terraintexturen/Modelldaten sind dann ggf. nicht verfügbar, was in der Vorschau als Fallback sichtbar bleibt.
- **Open Zone (World Streaming)** sowie **Open Model (.m3/.i3)** setzen für native Assetauflösung weiterhin einen indexierten ClientData-Root voraus. Genesis weist dafür ausdrücklich auf das Settings-Menü hin.
- Ungültig eingegebene Wurzelpfade öffnen keinen Blockierdialog. Ein bereits gültiger Index wird bei der Validierung eines falschen Pfads nicht gelöscht.
- Test: `cargo test -p genesis unconfigured_client_root_does_not_force_setup_dialog`, `cargo check -p genesis`, `cargo check -p genesis --tests`, manueller Windows-Start mit/ohne gespeicherten Root, Offline-AREA-Laden und Settings→Indexieren/Trennen.

**Grenze:** Bei laufendem Asset-Index-Neuscan ist der Dialog bedienbar, aber Root-Pfadänderungen/Trennen bleiben gesperrt, bis die Indexierung beendet ist. Für die Übernahme neuer WorldLayer-Texturen in bereits geladene AREAs diese erneut öffnen.
