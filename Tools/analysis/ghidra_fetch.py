"""Fetch complete read-only Ghidra MCP responses without console truncation."""
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from ghx import call


def main():
    if len(sys.argv) < 4:
        raise SystemExit("usage: ghidra_fetch.py output.json endpoint key=value [...]")
    output = Path(sys.argv[1])
    if not output.is_absolute():
        output = ROOT / output
    params = dict(item.split("=", 1) for item in sys.argv[3:])
    params.setdefault("program", "WildStar64.exe")
    raw = call(sys.argv[2], **params)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(raw, encoding="utf-8")
    try:
        report = json.loads(raw)
        code = report.get("decompiled")
        if code:
            output.with_suffix(".c").write_text(code, encoding="utf-8")
            print(output.with_suffix(".c"), len(code), "characters")
        else:
            print(output, len(raw), "characters")
    except json.JSONDecodeError:
        print(output, len(raw), "characters")


if __name__ == "__main__":
    main()
