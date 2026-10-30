# Genesis – schnellere lokale Builds ohne Dynamic Linking

## Fehler bei `cargo fast` (Bevy 0.20.1)

Wenn `cargo fast` meldet:

```text
failed to select a version for the requirement `bevy_dylib = "^0.20.1"`
candidate versions found which didn't match: 0.20.0, ...
```

liegt das daran, dass Bevy 0.20.1 bei aktiviertem Feature `bevy/dynamic_linking` die Version `bevy_dylib 0.20.1` verlangt, die aktuell auf crates.io nicht verfügbar ist. Das ist **kein Fehler in deinem AREA-Reader**.

Im Branch `feature/genesis-raw-area-3d` ist der Alias korrigiert: er verzichtet auf `dynamic_linking`. Bevy 0.20.1 und der Lockfile bleiben unverändert.

## Starten

Im Ordner `GenesisRebuild`:

```powershell
cargo fast -- "../WildStarModelStudio/demo/Hills.area"
```

`cargo fast` ist jetzt ein Alias für **`cargo run`**. Beide Befehle verwenden das **gleiche `dev`-Profil** und den **gleichen `target/debug`-Cache**. Damit gibt es keinen separaten `fast-dev`-Erstbuild mehr. Auch dieser Alias kann die erneute Übersetzung von `genesis` nach Codeänderungen nicht vermeiden.

```powershell
cargo fast-check
```

ist ein Alias für `cargo check`: Es prüft Rust-Code, ohne eine ausführbare `.exe` zu linken.

## Was tatsächlich schneller wird

Im `Cargo.toml` gilt für die lokale Anwendung:

```toml
[profile.dev.package.genesis]
opt-level = 0
debug = 0
codegen-units = 256
```

Das deaktiviert **nur für das Paket `genesis`** die Erstellung zusätzlicher Debug-Symbole, wodurch das Kompilieren und Linken schneller sein kann. Der übliche Debug-Profile-Modus mit Debug-Assertions bleibt aktiviert. Wenn du Debug-Symbole für `genesis` brauchst, setze `debug = 1` oder `debug = 2`.

Nach einer Änderung an Cargo-Profilen muss Cargo betroffene Artefakte einmal erneuern. Danach wird der Cache weiterverwendet. Es kann auf Windows beim Linken weiterhin eine Verzögerung auftreten.

**Nicht machen:** `cargo clean` bei jedem Start, ständig zwischen Toolchains wechseln oder `RUSTFLAGS` ändern. Das verwirft oder invalidiert oft den Cache.

Die normalen Befehle `cargo run` und `cargo build --release` bleiben nutzbar. Das `bevy_dylib`-Feature wird nicht mehr aktiviert und `Cargo.lock` muss nicht gelöscht werden.

## Fehlersuche

- `cargo check` schnell, `cargo run` langsam? Dann ist oft **Codegenerierung oder Linken** der eigenen `.exe` der Engpass.
- `cargo build --timings`: Erstellt einen Buildbericht im Verzeichnis `target/cargo-timings/`.
- `cargo run -v`: Gibt Rustc- und Linker-Aufrufe ausführlicher aus.

Docs: [Cargo Profiles](https://doc.rust-lang.org/cargo/reference/profiles.html), [Bevy Fast Compiles](https://bevy.org/learn/quick-start/getting-started/setup/#enable-fast-compiles-optional).

Nur Branch `feature/genesis-raw-area-3d`. Kein Release- oder Game-Daten-Format geändert.
