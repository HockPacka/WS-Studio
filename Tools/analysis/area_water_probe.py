"""Dump WATG/WBSP water payloads and WorldWater table schemas."""
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import area_reader as A
from tbl_dump import parse as read_tbl


def words(data):
    for offset in range(0, min(len(data), 512), 4):
        raw = data[offset:offset + 4]
        integer = struct.unpack("<I", raw)[0]
        number = struct.unpack("<f", raw)[0]
        print(f"  {offset:04x}: {raw.hex()} u={integer:10d} f={number:14.6g}")


folder = ROOT / "WoWClient/ClientData/Map/Western"
found = 0
for path in sorted(folder.glob("Western.*.area")):
    area = A.read_area(path.read_bytes())
    for name, size, chunk, pos in area["chunks"]:
        if name not in ("CHNK", "KNHC"):
            continue
        for index, flags, cell in A.read_chnk(chunk, area["compressed"]):
            cell_flags, blocks, subs = A.split_cell(cell)
            water = {key: value for key, value in subs if key in ("GtAW", "Psbw")}
            if "GtAW" not in water:
                continue
            print(f"FILE {path.name} CELL {index} flags=0x{cell_flags:x}")
            for key in ("GtAW", "Psbw"):
                print(f"{key} size={len(water[key])}")
                words(water[key])
            found += 1
            if found >= 2:
                break
        if found >= 2:
            break
    if found >= 2:
        break

for table in ("WorldWaterType", "WorldWaterLayer", "WorldWaterFog", "WorldWaterEnvironment"):
    path = ROOT / f"WoWClient/ClientData/DB/{table}.tbl"
    name, columns, rows = read_tbl(path.read_bytes())
    print(f"TABLE {table}: columns={len(columns)} rows={len(rows)}")
    print(columns)
    for row in rows[:2]:
        print(row)
