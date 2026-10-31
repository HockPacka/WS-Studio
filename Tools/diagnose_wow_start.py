"""Start one WoW client briefly and report log progress for hang diagnosis."""
from __future__ import annotations

import argparse
from pathlib import Path
import subprocess
import time


def snapshot(path: Path) -> tuple[int, float]:
    try:
        stat = path.stat()
        return stat.st_size, stat.st_mtime
    except FileNotFoundError:
        return 0, 0.0


def tail(path: Path, count: int = 8) -> list[str]:
    try:
        with path.open("rb") as stream:
            stream.seek(0, 2)
            size = stream.tell()
            stream.seek(max(0, size - 32768))
            lines = stream.read().decode("utf-8", errors="replace").splitlines()
        return lines[-count:]
    except FileNotFoundError:
        return ["<missing>"]


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("executable", type=Path)
    parser.add_argument("--seconds", type=int, default=60)
    parser.add_argument("--cdb", type=Path, help="optional cdb.exe for a main-thread stack sample")
    args = parser.parse_args()
    root = Path(__file__).resolve().parent.parent
    exe = args.executable if args.executable.is_absolute() else root / args.executable
    exe = exe.resolve()
    if root not in exe.parents or not exe.is_file():
        parser.error("the executable must exist inside this workspace")
    client = exe.parent
    logs = [client / "WildStar.log", client / "Logs" / "connection.log", client / "Logs" / "WildStar.log"]
    before = {log: snapshot(log) for log in logs}
    started = time.strftime("%Y-%m-%d %H:%M:%S")
    process = subprocess.Popen([str(exe)], cwd=str(client))
    print(f"started={started} pid={process.pid} exe={exe}", flush=True)
    deadline = time.monotonic() + args.seconds
    captured = False
    while time.monotonic() < deadline and process.poll() is None:
        time.sleep(min(5.0, max(0.0, deadline - time.monotonic())))
        if not captured and time.monotonic() >= deadline - 5:
            captured = True
            destination = root / "artifacts" / "diagnostics"
            destination.mkdir(parents=True, exist_ok=True)
            if args.cdb:
                stack_log = destination / f"wow-stack-{exe.stem}-{int(time.time())}.txt"
                with stack_log.open("w", encoding="utf-8") as output:
                    subprocess.run([
                        str(args.cdb), "-pv", "-p", str(process.pid), "-y",
                        str(root / "wowdecomp" / "bin" / "Win"), "-c",
                        ".reload /f; ~0s; k; qd",
                    ], stdout=output, stderr=subprocess.STDOUT, check=False, timeout=120)
                print(f"stack={stack_log}", flush=True)
            subprocess.run([
                "powershell", "-NoProfile", "-Command",
                f"Get-Process -Id {process.pid} | Select-Object Id,Responding,MainWindowTitle,CPU,WorkingSet64,HandleCount | Format-List",
            ], check=False, timeout=10)
            try:
                from PIL import ImageGrab
                destination = root / "artifacts" / "diagnostics"
                destination.mkdir(parents=True, exist_ok=True)
                screenshot = destination / f"wow-start-{exe.stem}-{int(time.time())}.png"
                ImageGrab.grab(all_screens=True).save(screenshot)
                print(f"screenshot={screenshot}", flush=True)
            except Exception as error:
                print(f"screenshot failed: {error}", flush=True)
    exit_code = process.poll()
    print(f"after={args.seconds}s exit_code={exit_code}", flush=True)
    if exit_code is None:
        process.terminate()
        try:
            process.wait(timeout=10)
        except subprocess.TimeoutExpired:
            subprocess.run(["taskkill", "/PID", str(process.pid), "/T", "/F"], check=False, timeout=15)
            process.wait(timeout=10)
        print("test process terminated", flush=True)
    for log in logs:
        current = snapshot(log)
        print(f"log={log} before={before[log]} after={current}", flush=True)
        for line in tail(log):
            print(f"  {line}", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
