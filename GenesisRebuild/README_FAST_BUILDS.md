# Schneller entwickeln: `Compiling genesis v0.1.0`

Wenn du Rust-Code in `src/main.rs`, `src/area.rs`, `src/terrain.rs` usw. änderst, **muss Rust das Paket `genesis` erneut übersetzen**. Das ist korrektes Cargo-Verhalten, kein vollständiger Bevy-Neubau. Ein erneutes Linken kann unter Windows aber teuer sein.

## 1. Gewohnter Start, jetzt mit weniger Debug-Daten für Genesis

```powershell
cd GenesisRebuild
cargo run -- "../WildStarModelStudio/demo/Hills.area"
```

`[profile.dev.package.genesis]` in `Cargo.toml` erzeugt weniger Debug-Informationen für **nur `genesis`** (`debug = 1`, `opt-level = 0`). Das kann die Kompilierung und das Linken beschleunigen. Debug-Assertions bleiben aktiviert. Die bereits übersetzten Bevy-Abhängigkeiten müssen für diese Profiländerung nicht umkonfiguriert werden, **aber die eigene Crate wird beim ersten Start nach der Änderung einmal neu übersetzt**.

## 2. Optional: deutlich schnellere Build-Iterationen durch Dynamic Linking

```powershell
cd GenesisRebuild
cargo fast -- "../WildStarModelStudio/demo/Hills.area"
```

`cargo fast` ist ein Alias aus `.cargo/config.toml` für:

```powershell
cargo run --profile fast-dev --features bevy/dynamic_linking -- "../WildStarModelStudio/demo/Hills.area"
```

- **Der erste Aufruf kann sehr lange dauern**: Bevy muss für das gesonderte `fast-dev`-Profil samt `bevy_dylib` neu gebaut werden.
- **Weitere Aufrufe mit demselben Befehl** verwenden den bereits gebauten dynamischen Bevy-Code und sind für Änderungen an unserem Editor gewöhnlich wesentlich schneller.
- `Compiling genesis` kann **weiterhin** erscheinen: deine geänderte Anwendung wird natürlich noch kompiliert, aber es müssen weniger große Teile statisch in die EXE gelinkt werden.
- Windows benötigt für Bevy Dynamic Linking optimierte Abhängigkeiten. Deshalb verwendet nur das `fast-dev`-Profil `[profile.fast-dev.package."*"] opt-level = 3`. Beim normalen `cargo run` bleiben sie unverändert.
- Zum Prüfen ohne vollständiges EXE-Linken: `cargo check` oder `cargo fast-check`.

**Wichtig:** Dynamic Linking ist ausschließlich für die lokale Entwicklung vorgesehen. Das dynamische Profil benötigt Bevy-Laufzeitbibliotheken und eignet sich nicht als standalone Release. Für Builds zur Veröffentlichung `cargo build --release` ohne `dynamic_linking` verwenden.

## 3. Unnötige Neubauten vermeiden

- Immer aus demselben Ordner/Workspace und mit demselben Buildbefehl arbeiten. Ein Wechsel zwischen `cargo fast`, `cargo run` und `cargo run --release` benutzt unterschiedliche Artefakte.
- Nicht `cargo clean` nach jeder Änderung ausführen: das löscht den Buildcache unter `target/`.
- Kein wechselndes `RUSTFLAGS`, `CARGO_TARGET_DIR`, Rust-Toolchain oder Bevy-Feature-Set zwischen Builds setzen: das kann viele Crates neu kompilieren.
- `cargo check` prüft Code deutlich schneller, weil es keinen vollständigen Programm-Link ausführt; zum tatsächlichen Anzeigen des 3D-Viewports ist `cargo run`/ `cargo fast` nötig.
- Mehrere `cargo`-Prozesse auf demselben Zielverzeichnis vermeiden (Lock-Wartezeiten).
- Falls der Schritt `Compiling genesis` trotz dieser Maßnahmen sehr lange dauert: `cargo build --timings` erzeugt einen HTML-Buildbericht, mit dem die langsamen Crates identifiziert werden können.

## Optional: schnellerer Windows-Linker

Nach Installation von `rust-lld.exe` (siehe offizielle Bevy-Anleitung) kann man **lokal** in `GenesisRebuild/.cargo/config.toml` ergänzen:

```toml
[target.x86_64-pc-windows-msvc]
linker = "rust-lld.exe"
```

Das wird **nicht standardmäßig eingeschaltet**, weil es auf einem Windows-PC ohne den entsprechenden Linker den Build verhindern würde. Ein Linkerwechsel kann außerdem einmalig einen erneuten Build auslösen.

Quellen: [Bevy – Fast Compiles](https://bevy.org/learn/quick-start/getting-started/setup/#enable-fast-compiles-optional), [Cargo – Profiles](https://doc.rust-lang.org/cargo/reference/profiles.html).

## Status

Diese Optimierungen verändern **keinen GDScript-Code**, keine .area-Rohdaten, keine Editor-Menüs und keine Release-Optionen. Sie liegen ausschließlich im Branch `feature/genesis-raw-area-3d`.
