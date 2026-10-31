import sys,xml.etree.ElementTree as ET,json,argparse
from pathlib import Path
from PIL import Image,ImageDraw
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools/blender_addon/wildstar_m3'));import tex
args=argparse.ArgumentParser();args.add_argument('--output',type=Path,default=ROOT/'WoWClient/WoWOverride/Interface/WildStar/Races');args.add_argument('--data',type=Path,default=ROOT/'WoWClient/ClientData');a=args.parse_args()
root=a.data;out=a.output;out.mkdir(parents=True,exist_ok=True)
xml=ET.parse(root/'UI/Assets/Docs/Sprites/charactercreate.xml')
rows=[];sheets={}
for sprite in xml.iter('Sprite'):
 name=sprite.get('Name','')
 if not name.startswith('sprCharC_Finalize_Race'):continue
 key=name.split('_Race')[1];frame=sprite.find('Frame');path=frame.get('Texture');p=root/path.replace('\\','/')
 if path not in sheets:
  w,h,a=tex.decode_tex(p.read_bytes(),16384);sheets[path]=Image.fromarray(a,'RGBA')
 box=tuple(int(frame.get(n)) for n in ['x0','y0','x5','y5']);crop=sheets[path].crop(box)
 image=Image.new('RGBA',(128,128));crop.thumbnail((124,124),Image.Resampling.LANCZOS);image.paste(crop,((128-crop.width)//2,(128-crop.height)//2))
 image.save(out/(key+'.tga'));image.save(out/(key+'.png'));rows.append(dict(key=key,sprite=name,source=path,box=box))
preview=Image.new('RGBA',(8*128,2*154),(35,40,45,255));draw=ImageDraw.Draw(preview)
for i,r in enumerate(rows):
 x=(i%8)*128;y=(i//8)*154;preview.alpha_composite(Image.open(out/(r['key']+'.png')),(x,y));draw.text((x+6,y+130),r['key'],fill='white')
preview.save(out/'preview.png');(out/'manifest.json').write_text(json.dumps(rows,indent=2));print([r['key'] for r in rows])
