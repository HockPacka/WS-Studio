"""Link registered WildStar windows to native zones, map pictures and terrain sources.

Outputs are a separate, reproducible content package. Native assets are read only.
"""
import argparse
from collections import Counter, defaultdict
import csv
import hashlib
import json
import multiprocessing
from pathlib import Path
import re
import struct
import sys
import math

import area_reader as A
from ws_content_output import DEFAULT_CLIENT, DEFAULT_OUTPUT
from ws_map_setup import Dbc
from ws_content_output import ClientArchive

AREA_BASE=50000
CELL=33.333332
TILE=CELL*16

def f2u(x):return struct.unpack('<I',struct.pack('<f',x))[0]

def parents(zid,zones):
    seen=set()
    while zid in zones and zid not in seen:
        yield zid;seen.add(zid);zid=int(zones[zid]['parentZoneId'])

def world_rect(bounds,w,margin=1.0,square=False):
    x0,x1,z0,z1=bounds
    left=-17066.666+(x1+1-16*w['bb'])*CELL
    right=-17066.666+(x0-16*w['bb'])*CELL
    top=-17066.666+(z1+1-16*w['aa'])*CELL
    bottom=-17066.666+(z0-16*w['aa'])*CELL
    cx,cy=(top+bottom)/2,(left+right)/2
    height=max(top-bottom,(left-right)/(1 if square else 1.5))*margin
    return [cy+height*.75,cy-height*.75,cx+height*.5,cx-height*.5]

def blp_raw(image):
    # Match the runtime BLP2 ARGB8888 writer, including the palette padding.
    b=bytearray(0x494);b[:4]=b'BLP2';struct.pack_into('<I',b,4,1)
    b[8:12]=bytes([3,8,2,1]);struct.pack_into('<2I',b,12,*image.size)
    for mip in range(16):
        pixels=image.tobytes('raw','BGRA');struct.pack_into('<I',b,0x14+mip*4,len(b));struct.pack_into('<I',b,0x54+mip*4,len(pixels));b+=pixels
        if image.size==(1,1):break
        image=image.resize((max(1,image.width//2),max(1,image.height//2)))
    return b

def overview(args):
    client,output,w,keys,rect=args
    import numpy as np
    from PIL import Image
    sys.path.insert(0,str(Path(__file__).resolve().parent/'blender_addon/wildstar_m3'))
    import tex
    l,r,t,b=rect;scale=1002/(l-r)
    canvas=Image.new('RGBA',(1024,768),(18,22,24,255));missing=[];decoded=0
    for key in keys:
        bb,aa=map(int,key.split(','))
        p=Path(client)/'ClientData/Map'/w['map']/f"{w['map']}.{aa:02x}{bb:02x}.tex"
        if not p.is_file():missing.append(p.name);continue
        try:
            _,_,pixels=tex.decode_tex(p.read_bytes(),max(16,math.ceil(TILE*scale)))
            tile=Image.fromarray(np.asarray(pixels,dtype=np.uint8),'RGBA').transpose(Image.Transpose.ROTATE_180)
            tile.putalpha(255)
            west=-17066.666+(bb+1-w['bb'])*TILE
            north=-17066.666+(aa+1-w['aa'])*TILE
            x0,y0=round((l-west)*scale),round((t-north)*scale)
            x1,y1=round((l-west+TILE)*scale),round((t-north+TILE)*scale)
            canvas.paste(tile.resize((max(1,x1-x0),max(1,y1-y0)),Image.Resampling.LANCZOS),(x0,y0));decoded+=1
        except Exception as e:missing.append(p.name+': '+str(e))
    folder=f"WildStarMap{w['id']}"
    base=Path(output)/'client/WoWOverride/Interface/WorldMap'/folder;base.mkdir(parents=True,exist_ok=True)
    for i in range(12):
        piece=canvas.crop((i%4*256,i//4*256,i%4*256+256,i//4*256+256))
        (base/f'{folder}{i+1}.blp').write_bytes(blp_raw(piece))
    preview=Path(output)/'previews';preview.mkdir(exist_ok=True)
    canvas.save(preview/f'{folder}.png')
    return dict(map=w['id'],folder=folder,decodedTiles=decoded,missing=missing)

def generate(client,output,data):
    zones={int(z['ID']):z for z in table(client,'WorldZone')}
    mz={int(z['worldZoneId']):z for z in table(client,'MapZone') if int(z['worldZoneId']) and z['folder']}
    registered=windows(client);areas=Dbc(str(output/'client/WoWOverride/DBFilesClient/AreaTable.dbc'))
    archive=ClientArchive(client/'Data');wa=Dbc(archive.get('DBFilesClient\\WorldMapArea.dbc'));wc=Dbc(archive.get('DBFilesClient\\WorldMapContinent.dbc'))
    map_names={};worlds=table(client,'World')
    for row in worlds:map_names[int(row['ID'])]=row['assetPath'].replace('\\','/').split('/')[-1]
    unknown_zones=Counter()
    facts={};ownership=defaultdict(Counter);tasks=[];area_id=900000;physical=set();server_files=0
    adapter=output/'server/adapters/azerothcore/map-links';mapdir=adapter/'maps';mapdir.mkdir(parents=True,exist_ok=True)
    for w in registered:
        source=data['maps'][w['map']];keys=[];bounds={};groups=defaultdict(list);tiles={}
        for key,grid in source['tiles'].items():
            bb,aa=map(int,key.split(','))
            if not(w['bb']<=bb<w['bb']+64 and w['aa']<=aa<w['aa']+64):continue
            keys.append(key);tiles[key]=grid
            converted=[0]*256
            for idx,zid in enumerate(grid):
                if not zid:continue
                if zid not in zones:unknown_zones[zid]+=1;continue   # the area file names a zone that is not in WorldZone: no area for that cell (listed in the report)
                physical.add(zid);chain=list(parents(zid,zones))
                for z in chain:ownership[z][w['id']]+=1
                gx,gz=16*bb+idx%16,16*aa+idx//16
                group=next((z for z in chain if z in mz),chain[-1]);groups[group].append((gx,gz))
                # Native cell axes both reverse into ADT. AC indexes areaMap[x*16+y].
                converted[(15-idx%16)*16+(15-idx//16)]=AREA_BASE+zid
            tx,ty=63-bb+w['bb'],63-aa+w['aa']
            area=struct.pack('<4sHH',b'AREA',0,0)+struct.pack('<256H',*converted)
            header=struct.pack('<4s10I',b'MAPS',9,12340,44,len(area),0,0,0,0,0,0)
            (mapdir/f"{w['id']:03d}{tx:02d}{ty:02d}.map").write_bytes(header+area);server_files+=1
        if not keys:raise ValueError('Registered map has no scanned tiles: '+str(w))
        coords=[tuple(map(int,k.split(','))) for k in keys]
        tilebounds=[min(k[0] for k in coords)*16,(max(k[0] for k in coords)+1)*16-1,min(k[1] for k in coords)*16,(max(k[1] for k in coords)+1)*16-1]
        rect=world_rect(tilebounds,w);folder=f"WildStarMap{w['id']}";root=920000+w['id']
        wa.recs.append([root,w['id'],0,wa.add_string(folder),*map(f2u,rect),0xffffffff,0,0])
        # 63:42 is the visible 1002:668 ratio. Actual geography is in WorldMapArea.
        wc.recs.append([930000+w['id'],w['id'],0,62,0,41,0,0,f2u(1),0,0,f2u(1),f2u(1),0])
        tasks.append((str(client),str(output),w,keys,rect))
        picture_rows=[]
        for zid,points in sorted(groups.items()):
            native=mz.get(zid);picture=folder;placement=rect
            if native:
                path=client/'ClientData/UI/Maps'/native['folder']
                if any(path.glob('*[Rr]evealed*.tex')):
                    picture='WS_'+native['folder']
                    bbounds=[min(p[0] for p in points),max(p[0] for p in points),min(p[1] for p in points),max(p[1] for p in points)]
                    # Native square picture is centered inside WoW's 3:2 canvas.
                    placement=world_rect(bbounds,w,1.25,True)
            area_id+=1
            wa.recs.append([area_id,w['id'],AREA_BASE+zid,wa.add_string(picture),*map(f2u,placement),0xffffffff,0,root])
            picture_rows.append(dict(zone=zid,area=AREA_BASE+zid,picture=picture,rect=placement,
                                     alignment='native-art bounding-box estimate' if picture.startswith('WS_') else 'exact tile coordinates'))
        facts[w['id']]=dict(**w,tiles=len(keys),worldMapRoot=root,overview=folder,zones=picture_rows,
                            nativeZoneIds=sorted({z for g in tiles.values() for z in g if z}))
    # Preserve native parent hierarchy; assign every parent by descendant usage.
    assigned=0;unplaced=[]
    for row in areas.recs:
        zid=row[0]-AREA_BASE
        if zid not in zones:continue
        candidates=ownership.get(zid)
        if candidates:row[1]=max(candidates,key=lambda k:(candidates[k],-k));assigned+=1
        else:
            row[1]=next((max(ownership[p],key=ownership[p].get) for p in parents(zid,zones) if ownership.get(p)),0)
            if not row[1]:unplaced.append(zid)
    for dbc,name in [(areas,'AreaTable'),(wa,'WorldMapArea'),(wc,'WorldMapContinent')]:dbc.save(str(output/'client/WoWOverride/DBFilesClient'/(name+'.dbc')))
    # Audit the terrain layers as actual source paths, without replacing missing art.
    layers={int(r['ID']):r for r in table(client,'WorldLayer')};terrain=[]
    for name,source in data['maps'].items():
        absent=[];unknown=[];paths=set()
        for lid in source['layers']:
            layer=layers.get(lid)
            if not layer:unknown.append(lid);continue
            for key,value in layer.items():
                if isinstance(value,str) and value.lower().endswith('.tex'):
                    paths.add(value)
                    if not (client/'ClientData'/value).is_file():absent.append(value)
        terrain.append(dict(map=name,layers=len(source['layers']),textureSources=len(paths),missing=sorted(set(absent)),unknownLayerIds=unknown))
    with multiprocessing.Pool(6) as pool:
        images=[]
        for result in pool.imap_unordered(overview,tasks):
            images.append(result);print('overview',result['map'],'tiles',result['decodedTiles'],'missing',len(result['missing']),flush=True)
    report=dict(schema=1,areaBase=AREA_BASE,windows=list(facts.values()),mapCount=len(data['maps']),
                physicalZones=len(physical),unknownZoneCells={str(k):v for k,v in sorted(unknown_zones.items())},assignedZones=assigned,unplacedZones=unplaced,
                serverAreaFiles=server_files,overviews=sorted(images,key=lambda r:r['map']),terrain=terrain,
                areaLookup='cell block 28; dominant slot from block 16; parent ancestry retained',
                serverTerrain='AzerothCore MAPS v9 area grids only; existing terrain height/collision sections are preserved by installer')
    (output/'map_links.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    (adapter/'README.md').write_text('Generated AzerothCore MAPS v9 area grids. Client/server AreaTable IDs: 50000 + native WorldZone.\nInstaller preserves existing height/liquid/hole sections. No navigation or collision data is synthesized.\n',encoding='utf-8')
    print('Linked',len(registered),'windows;',assigned,'zone assignments;',server_files,'server area tiles',flush=True)

SELECTORS = bytes((x >> 3) & 3 for x in range(256))


def table(client, name):
    with (Path(client)/'tables_csv'/(name+'.csv')).open(encoding='utf-8') as f:
        return list(csv.DictReader(f))


def windows(client):
    dbc = Dbc(str(Path(client)/'WoWOverride/DBFilesClient/Map.dbc'))
    out=[]
    for row in dbc.recs:
        name=bytes(dbc.strings[row[1]:]).split(b'\0',1)[0].decode('utf-8')
        if not name.startswith('WS_'):continue
        m=re.fullmatch(r'WS_(.+)_o(\d+)_(\d+)',name)
        if m:source,bb,aa=m[1],int(m[2]),int(m[3])
        else:
            m=re.fullmatch(r'WS_(Western|Eastern|NewCentral)(?:_(\d+)_(\d+))?',name)
            if not m:raise ValueError('Unknown registered WildStar window: '+name)
            source,bb,aa=m[1],64*int(m[2] or 0),64*int(m[3] or 0)
        out.append(dict(id=row[0],directory=name,map=source,bb=bb,aa=aa))
    return sorted(out,key=lambda w:w['id'])


def scan_one(args):
    client,name,tiles=args
    folder=Path(client)/'ClientData/Map'/name
    result=dict(tiles={},layers=[],missing=[],errors=[])
    layers=set()
    for key in tiles:
        bb,aa=map(int,key.split(','))
        path=folder/f'{name}.{aa:02x}{bb:02x}.area'
        if not path.is_file():result['missing'].append(path.name);continue
        try:
            area=A.read_area(path.read_bytes());grid=[0]*256
            for tag,_,chunk,_ in area['chunks']:
                if tag not in ('CHNK','KNHC'):continue
                for idx,flags,cell in A.read_chnk(chunk,area['compressed']):
                    if not 0<=idx<256:continue
                    pos=4;ids=None;selectors=b''
                    for bit,size in enumerate(A.CELL_BLOCK_SIZE):
                        if flags & (1<<bit):
                            if pos+size>len(cell):raise ValueError('cell block overrun')
                            if bit==1:layers.update(struct.unpack_from('<4I',cell,pos))
                            elif bit==16:selectors=cell[pos:pos+size].translate(SELECTORS)
                            elif bit==28:ids=struct.unpack_from('<4I',cell,pos)
                            pos+=size
                    if ids:
                        candidates=[k for k in range(4) if ids[k]]
                        if candidates:grid[idx]=ids[max(candidates,key=lambda k:selectors.count(k))]
            result['tiles'][key]=grid
        except Exception as e:result['errors'].append(dict(file=path.name,error=str(e)))
    result['layers']=sorted(layers-{0})
    return name,result


def scan(client,output,jobs):
    original=json.loads((output/'cache/all_maps_scan.json').read_text())
    result={}
    with multiprocessing.Pool(jobs) as pool:
        for name,data in pool.imap_unordered(scan_one,[(str(client),n,list(v[0])) for n,v in original.items()]):
            result[name]=data
            print(f"scanned {name}: {len(data['tiles'])} tiles, {len(data['errors'])} errors",flush=True)
    report=dict(schema=1,maps=result)
    path=output/'cache/all_map_links_scan_v1.json'
    path.write_text(json.dumps(report,separators=(',',':')),encoding='utf-8')
    if any(d['errors'] or d['missing'] for d in result.values()):raise RuntimeError('Incomplete source scan; inspect '+str(path))
    print('Complete zone/layer scan:',len(result),'maps',flush=True)
    return report


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--client',default=DEFAULT_CLIENT)
    ap.add_argument('--output',default=DEFAULT_OUTPUT)
    ap.add_argument('--rescan',action='store_true')
    ap.add_argument('--scan-only',action='store_true')
    ap.add_argument('--jobs',type=int,default=6)
    a=ap.parse_args();client=Path(a.client).resolve();output=Path(a.output).resolve()
    cache=output/'cache/all_map_links_scan_v1.json'
    data=scan(client,output,a.jobs) if a.rescan or not cache.exists() else json.loads(cache.read_text())
    if not a.scan_only:generate(client,output,data)


if __name__=='__main__':main()
