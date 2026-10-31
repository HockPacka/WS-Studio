"""Locate native DX9 shaders that consume the SkinFX G-buffer channel."""
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from sho_reader import read_sho
from dxbc_dis import disassemble


def main():
    output = ROOT / "build_m3test/scratch/avatus_skinfx_sho/light_consumers"
    output.mkdir(parents=True, exist_ok=True)
    report = []
    for name in ("LightPS.ps_3_0.sho", "LightSunSkyPS.ps_3_0.sho", "CompositePS.ps_3_0.sho", "FogPS.ps_3_0.sho"):
        data = (ROOT / "WoWClient/ClientData/Shaders" / name).read_bytes()
        container = read_sho(data)
        keys = sorted({key for key, code in enumerate(container["permutation_to_code"]) if code != 0xFFFFFFFF})
        print(name, "keys", len(keys), "codes", len(container["code"]))
        for key in keys:
            code_index = container["permutation_to_code"][key]
            item = container["code"][code_index]
            blob = data[item["offset"]:item["offset"] + item["bytes"]]
            text = disassemble(blob).rstrip("\0").replace("\r", "")
            samplers = sorted(set(re.findall(r"dcl_2d s(\d+)", text)), key=int)
            # G-buffer 3 is conventionally s3 in the native lighting passes. Keep
            # all green-channel reads as candidates; pass mapping is checked separately.
            green_reads = [line.strip() for line in text.splitlines()
                           if re.search(r"\b[rs]\d+\.y\b|\b[rs]\d+\.[xyzw]*y[xyzw]*\b", line)
                           and ("texld" in line or "mul" in line or "mad" in line or "lrp" in line)]
            interesting = "3" in samplers and any("s3" in line for line in text.splitlines())
            if not interesting:
                continue
            filename = f"{Path(name).stem}_p{key}_c{code_index}.txt"
            (output / filename).write_text(text, encoding="utf-8")
            report.append({"shader": name, "permutation": key, "code": code_index,
                           "samplers": samplers, "greenCandidates": green_reads, "file": filename})
    (output / "report.json").write_text(json.dumps(report, indent=2), encoding="utf-8")
    print("s3 candidates", len(report), "report", output / "report.json")


if __name__ == "__main__":
    main()
