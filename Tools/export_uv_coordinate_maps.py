"""Plot original WildStar component regions with exact pixel and UV coordinates."""
from pathlib import Path
import sys,json,csv
from PIL import Image,ImageDraw,ImageFont
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
from tbl_dump import parse
OUT=ROOT/'exports/character_edit_kit/uv_maps';OUT.mkdir(parents=True,exist_ok=True)
def table(n):
    _,c,r=parse((ROOT/'WoWClient/ClientData/DB'/(n+'.tbl')).read_bytes());return [dict(zip([x[0] for x in c],v)) for v in r]
regions={r['ID']:r for r in table('ComponentRegion')};rects=table('ComponentRegionRect')
names={'Armor_Buckle':'Gürtelschnalle','Armor_Face':'Gesichtsschutz','Armor_Shoulders':'Schultern','Armor_Chest':'Brust','Armor_Pants':'Hose','Armor_Head':'Helm','Armor_Sleeves':'Ärmel','Armor_Misc':'Zusatzteile','Armor_Gloves':'Handschuhe','Armor_Boots':'Stiefel'}
allrows=[]

def plot(name,layout,component):
    rs=[r for r in rects if r['componentLayoutId']==layout and regions[r['regionId']]['componentMap']==component]
    width=max(r['rectLimX'] for r in rs);height=max(r['rectLimY'] for r in rs)
    image=Image.new('RGB',(1800,1250),'white');draw=ImageDraw.Draw(image)
    fontpath='C:/Windows/Fonts/segoeui.ttf'
    font=lambda size:ImageFont.truetype(fontpath,size)
    colors=['#76b7e5','#a9d18e','#f4b183','#c5a4dd','#ffd966','#8dd3c7','#f49ac2','#b4c7e7','#c9bd9b','#b6d7a8','#f6b8a7']
    scale=min(850/width,940/height);left,top=100,165
    draw.text((50,22),name.replace('_',' ')+' – originale Texturregionen',font=font(32),fill='#14283f')
    draw.text((50,75),f'{width} × {height} Pixel | ComponentLayoutId {layout} | Pixel links oben; UV links unten',font=font(20),fill='#445566')
    descriptions=[]
    for i,r in enumerate(rs):
        label=regions[r['regionId']]['EnumName'];x0,y0,x1,y1=[r[k] for k in ['rectMinX','rectMinY','rectLimX','rectLimY']]
        if not label:continue
        color=colors[i%len(colors)]
        box=(left+x0*scale,top+y0*scale,left+x1*scale,top+y1*scale)
        draw.rectangle(box,fill=color,outline='#263544',width=2)
        number=str(len(descriptions)+1)
        cx=(box[0]+box[2])/2;cy=(box[1]+box[3])/2
        draw.text((cx,cy),number,font=font(22),fill='black',anchor='mm',stroke_width=2,stroke_fill='white')
        descriptions.append((f'{number}. {names.get(label,label)} ({label})',f'PNG: x {x0}–{x1}, y {y0}–{y1}',f'UV: U {x0/width:.4f}–{x1/width:.4f}, V {1-y1/height:.4f}–{1-y0/height:.4f}',color))
        allrows.append(dict(map=name,layoutId=layout,regionId=r['regionId'],region=label,width=width,height=height,x0=x0,y0=y0,x1=x1,y1=y1,u0=x0/width,u1=x1/width,v0=1-y1/height,v1=1-y0/height))
    for x in range(0,width+1,128):
        px=left+x*scale
        draw.line((px,top,px,top+height*scale),fill='#8a8a8a')
        draw.text((px,top+height*scale+12),str(x),font=font(15),fill='black',anchor='mt')
        draw.text((px,top-12),f'{x/width:g}',font=font(15),fill='#214c85',anchor='mb')
    for y in range(0,height+1,128):
        py=top+y*scale
        draw.line((left,py,left+width*scale,py),fill='#8a8a8a')
        draw.text((left-12,py),str(y),font=font(15),fill='black',anchor='rm')
        draw.text((left+width*scale+12,py),f'{1-y/height:g}',font=font(15),fill='#214c85',anchor='lm')
    draw.text((left,top-55),'UV U →',font=font(19),fill='#214c85')
    draw.text((left,top+height*scale+43),'PNG X / Pixel →',font=font(19),fill='black')
    draw.text((40,123), 'PNG Y ↓',font=font(17),fill='black')
    draw.text((1000,123),'Bereiche und Koordinaten',font=font(25),fill='#14283f')
    spacing=min(100,960/max(1,len(descriptions)))
    for i,(title,pixels,uv,color) in enumerate(descriptions):
        x=1030;y=top+i*spacing
        draw.rectangle((1000,y+4,1019,y+23),fill=color,outline='black')
        draw.text((x,y),title,font=font(21),fill='#14283f')
        draw.text((x,y+30),pixels,font=font(18),fill='#334455')
        draw.text((x,y+55),uv,font=font(18),fill='#214c85')
    draw.text((50,1180),'x1/y1 sind exklusive Pixelgrenzen. Die Regionen sind Atlasflächen; die Mesh-UVs bestimmen die Lage am Körper.',font=font(19),fill='#334455')
    draw.text((50,1210),'Haut (Skin) und Kleidung (Armor) sind getrennte Atlanten. Nicht direkt übereinander malen.',font=font(19),fill='#334455')
    image.save(OUT/(name+'.png'))

def main():
    plot('Armor_Alle_Rassen',10,1)
    races={r['ID']:r for r in table('Race')}
    for name,race in [('Human_Exile',1),('Granok',3),('Aurin',4),('Mordesh',16),('Cassian_Dominion',1),('Draken',5),('Mechari',12),('Chua',13)]:
        plot(name+'_Skin',races[race]['componentLayoutIdMale'],0)
    (OUT/'coordinates.json').write_text(json.dumps(allrows,ensure_ascii=False,indent=2),encoding='utf-8')
    with (OUT/'coordinates.csv').open('w',newline='',encoding='utf-8-sig') as f:
        w=csv.DictWriter(f,fieldnames=list(allrows[0]));w.writeheader();w.writerows(allrows)
    (OUT/'README.txt').write_text('Quelle: ComponentRegion.tbl und ComponentRegionRect.tbl, Race.tbl.\n'
        'Armor_Alle_Rassen.png ist der gemeinsame Kleidungsatlas (componentMap=1, Layout 10).\n'
        'Die anderen Karten zeigen die Hautatlanten (componentMap=0). Kleidung wird nicht an denselben Pixelpositionen in die Haut-PNG gemalt.\n'
        'Handschuhe: Armor_Gloves; Stiefel: Armor_Boots; Brust: Armor_Chest; Aermel: Armor_Sleeves.\n'
        'Ein Item kann mehrere Regionen belegen; ItemDisplay.componentRegionFlags bestimmt die belegten Regionen.\n'
        'Die Mesh-UVs bestimmen die genaue Lage auf dem 3D-Modell. coordinates.csv/.json enthalten Pixelrechtecke und Blender-UV-Werte.\n',encoding='utf-8')
    print('UV maps:',OUT,'files',len(list(OUT.glob('*.png'))),'coordinate rows',len(allrows))
if __name__=='__main__':main()
