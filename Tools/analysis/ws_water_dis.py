"""Disassemble the embedded original WildStar LandWater token streams."""
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
from dxbc_dis import disassemble
from sho_reader import read_sho

for name in ("LandWaterVS.vs_3_0.sho", "LandWaterPS.ps_3_0.sho"):
    data = (ROOT / "WoWClient/ClientData/Shaders" / name).read_bytes()
    blob = read_sho(data)["code"][0]
    code = data[blob["offset"]:blob["offset"] + blob["bytes"]]
    output = ROOT / "analysis" / (name + ".asm.txt")
    output.parent.mkdir(exist_ok=True)
    output.write_text(disassemble(code), encoding="utf-8")
    print(output)
