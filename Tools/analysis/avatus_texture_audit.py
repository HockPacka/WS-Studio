"""Decode Avatus SkinFX textures and report channel evidence without assuming semantics."""
import importlib.util
import json
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw

ROOT = Path(__file__).resolve().parents[2]
DECODER = ROOT / "WildstarTools/WildStarModelStudio/tex_decoder.py"
spec = importlib.util.spec_from_file_location("wildstar_tex", DECODER)
tex = importlib.util.module_from_spec(spec)
spec.loader.exec_module(tex)


def audit(relative, output):
    path = ROOT / relative
    data = path.read_bytes()
    header = tex.header(data)
    image = tex.decode(data, max_size=1024).convert("RGBA")
    image.save(output / f"{path.stem}.png")
    pixels = np.asarray(image)
    channels = []
    panels = [image.convert("RGB")]
    labels = ["RGB", "R", "G", "B", "A"]
    for index, name in enumerate("RGBA"):
        values = pixels[:, :, index]
        channels.append({
            "channel": name,
            "minimum": int(values.min()),
            "maximum": int(values.max()),
            "mean": float(values.mean()),
            "nonzeroFraction": float(np.count_nonzero(values) / values.size),
            "uniqueValues": int(np.unique(values).size),
        })
        panels.append(Image.fromarray(values, "L").convert("RGB"))
    width, height = image.size
    sheet = Image.new("RGB", (width * 5, height + 32), (24, 24, 24))
    draw = ImageDraw.Draw(sheet)
    for index, panel in enumerate(panels):
        sheet.paste(panel, (index * width, 32))
        draw.text((index * width + 8, 8), labels[index], fill=(255, 255, 255))
    sheet.save(output / f"{path.stem}_channels.png")
    return {
        "file": relative,
        "header": {key: value for key, value in header.items() if key != "sizes"},
        "decodedSize": list(image.size),
        "channels": channels,
        "channelEquality": {
            "R=G": bool(np.array_equal(pixels[:, :, 0], pixels[:, :, 1])),
            "R=B": bool(np.array_equal(pixels[:, :, 0], pixels[:, :, 2])),
            "G=B": bool(np.array_equal(pixels[:, :, 1], pixels[:, :, 2])),
        },
    }


def main():
    output = ROOT / "build_m3test/scratch/avatus_skinfx_sho"
    output.mkdir(parents=True, exist_ok=True)
    reports = [
        audit("WoWClient/ClientData/Art/Creature/Avatus/Textures/Avatus_Glass_SkinFX.tex", output),
        audit("WoWClient/ClientData/Art/FX/Texture/FX_Skin/Active/Caretaker_01.tex", output),
        audit("WoWClient/ClientData/Art/Creature/Avatus/Textures/Avatus_Glass_Grad.tex", output),
        audit("WoWClient/ClientData/Art/FX/Texture/FX_Skin/Death_Flux_Thick_RED.tex", output),
    ]
    (output / "avatus_texture_audit.json").write_text(json.dumps(reports, indent=2), encoding="utf-8")
    print(json.dumps(reports, indent=2))


if __name__ == "__main__":
    main()
