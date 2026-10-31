import sys
import os
from pathlib import Path
from PIL import Image, ImageDraw

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/blender_addon/wildstar_m3'))
import tex

OUT_DIR = ROOT / 'WoWClient/WoWOverride/Interface/WildStar/Classes'
OUT_DIR.mkdir(parents=True, exist_ok=True)

DATA_DIR = ROOT / 'WoWClient/ClientData/UI/IconHD/Windows'

CLASSES = [
    ('WARRIOR', 'UI_CRB_Warrior.tex', 'Warrior'),
    ('ENGINEER', 'UI_CRB_Engineer.tex', 'Engineer'),
    ('ESPER', 'UI_CRB_Esper.tex', 'Esper'),
    ('MEDIC', 'UI_CRB_Medic.tex', 'Medic'),
    ('STALKER', 'UI_CRB_Stalker.tex', 'Stalker'),
    ('SPELLSLINGER', 'UI_CRB_Spellslinger.tex', 'Spellslinger'),
]

def make_circular_icon(pil_img, size=128):
    """
    Creates a framed circular class icon with gold/silver border matching WoW's style.
    """
    img = pil_img.resize((size, size), Image.Resampling.LANCZOS)
    
    # Create circular mask
    mask = Image.new('L', (size, size), 0)
    draw = ImageDraw.Draw(mask)
    draw.ellipse((4, 4, size - 5, size - 5), fill=255)
    
    # Border ring
    border = Image.new('RGBA', (size, size), (0, 0, 0, 0))
    bdraw = ImageDraw.Draw(border)
    bdraw.ellipse((2, 2, size - 3, size - 3), outline=(210, 180, 80, 255), width=3)
    bdraw.ellipse((4, 4, size - 5, size - 5), outline=(120, 100, 40, 200), width=1)
    
    out = Image.new('RGBA', (size, size), (0, 0, 0, 0))
    out.paste(img, (0, 0), mask)
    out.alpha_composite(border)
    return out

def main():
    print("=" * 60)
    print("Extracting WildStar Class Icons")
    print("=" * 60)

    for key, tex_name, display_name in CLASSES:
        tex_path = DATA_DIR / tex_name
        if not tex_path.exists():
            print(f"[!] Warning: {tex_path} not found!")
            continue

        raw = tex_path.read_bytes()
        w, h, arr = tex.decode_tex(raw, 16384)
        base_img = Image.fromarray(arr, 'RGBA')

        # 1. Flat 128x128 icon
        flat_img = base_img.resize((128, 128), Image.Resampling.LANCZOS)
        flat_img.save(OUT_DIR / f"{display_name}.tga")
        flat_img.save(OUT_DIR / f"{display_name}.png")

        # 2. Circular framed icon
        circ_img = make_circular_icon(base_img, 128)
        circ_img.save(OUT_DIR / f"{display_name}_Round.tga")
        circ_img.save(OUT_DIR / f"{display_name}_Round.png")

        print(f"[+] Extracted {display_name} ({w}x{h}) -> {OUT_DIR / display_name}.tga")

    print("\n[SUCCESS] All WildStar Class Icons successfully extracted!")

if __name__ == '__main__':
    main()
