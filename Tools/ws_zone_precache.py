"""Prepare an offline asset-cache manifest from real AREA props and terrain layers.

The native content_cache_cli warms these exact runtime cache formats while the
game is closed. Original assets and server data are never changed.
"""
import argparse
import csv
import json
from pathlib import Path
import shutil
import struct
import area_reader as A

ROOT=Path(__file__).resolve().parents[1]

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--map',required=True);ap.add_argument('--zone',type=int,required=True)
    ap.add_argument('--radius',type=int,default=1);ap.add_argument('--install-client',action='store_true')
    args=ap.parse_args()
    if not 0<=args.radius<=2:ap.error('radius must be 0..2 terrain tiles')
    client=ROOT/'WoWClient';native=client/'ClientData'
    scan=json.loads((ROOT/'build_wildstar/generated/cache/all_map_links_scan_v1.json').read_text(encoding='utf-8'))['maps'][args.map]['tiles']
    core=[tuple(map(int,k.split(','))) for k,g in scan.items() if args.zone in g]
    if not core:ap.error('zone has no scanned cells in this map')
    tiles=[tuple(map(int,k.split(','))) for k in scan if any(abs(int(k.split(',')[0])-b)<=args.radius and abs(int(k.split(',')[1])-a)<=args.radius for b,a in core)]
    props=set();layers=set();missing=[]
    for bb,aa in tiles:
        tile=A.read_area((native/'Map'/args.map/f'{args.map}.{aa:02x}{bb:02x}.area').read_bytes())
        for tag,_,data,_ in tile['chunks']:
            if tag in ('CHNK','KNHC'):
                for idx,flags,cell in A.read_chnk(data,tile['compressed']):
                    if idx<0 or not flags&2:continue
                    offset=4+(722 if flags&1 else 0)
                    layers.update(struct.unpack_from('<4I',cell,offset))
            elif tag=='pORP':
                count=struct.unpack_from('<I',data)[0]
                if 8+count*104>len(data):raise ValueError('prop array overrun')
                for i in range(count):
                    record=8+i*104;offset=struct.unpack_from('<I',data,record+16)[0]
                    scale=struct.unpack_from('<f',data,record+24)[0]
                    if not 0<scale<1000 or offset>=len(data):continue
                    end=offset
                    while end+2<=len(data) and data[end:end+2]!=b'\0\0':end+=2
                    name=data[offset:end].decode('utf-16le','replace')
                    if name and 'collision' not in name.lower():props.add(name)
    jobs=set()
    for path in sorted(props):
        source=native/path
        if source.suffix.lower() not in ('.m3','.i3','.dgn'):continue
        if not source.is_file():missing.append(path);continue
        if source.suffix.lower()=='.dgn':
            data=source.read_bytes()
            if data[:4]!=b'NGND':continue
            count,offset=struct.unpack_from('<QQ',data,0x28)
            if count>4096 or 0x50+offset+count*2>len(data):raise ValueError('DGN model pointer')
            path=data[0x50+offset:0x50+offset+count*2].decode('utf-16le').rstrip('\0')
            source=native/path
        kind={'.m3':'m3','.i3':'wmo'}.get(source.suffix.lower())
        if kind and source.is_file():jobs.add((kind,path))
    with (client/'tables_csv/WorldLayer.csv').open(encoding='utf-8') as f:
        layer_rows={int(r['ID']):r for r in csv.DictReader(f)}
    for layer in layers:
        for value in layer_rows.get(layer,{}).values():
            if value.lower().endswith('.tex'):
                if (native/value).is_file():jobs.add(('tex','WS\\'+value[:-4]+'.blp'))
                else:missing.append(value)
    for bb,aa in tiles:
        path=f'Map\\{args.map}\\{args.map}.{aa:02x}{bb:02x}'
        if (native/(path+'.tex')).is_file():jobs.add(('tex','WS\\'+path+'~minimap.blp'))
    out=ROOT/'build_m3test'/f'zone{args.zone}_warmup';out.mkdir(parents=True,exist_ok=True)
    manifest=out/f'zone{args.zone}_{args.map.lower()}.tsv'
    manifest.write_text(''.join(k+'\t'+p+'\n' for k,p in sorted(jobs)),encoding='utf-8')
    report=dict(zone=args.zone,map=args.map,coreTiles=len(core),tiles=len(tiles),assets=len(jobs),missing=sorted(set(missing)),
                expandedAssets='native CLI also follows WMO dressings and model/structure texture references')
    (out/'plan.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    if args.install_client:
        dest=client/'Tools/WildStar';dest.mkdir(parents=True,exist_ok=True)
        shutil.copy2(ROOT/'wowdecomp/build/i3_portal_fix/bin/Release/content_cache_cli.exe',dest/'content_cache_cli.exe')
        shutil.copy2(manifest,dest/manifest.name)
        launcher=client/f'Precache_Zone{args.zone}.cmd'
        launcher.write_text('@echo off\ncd /d "%~dp0"\n"Tools\\WildStar\\content_cache_cli.exe" warm "Tools\\WildStar\\'+manifest.name+'"\nset "WS_CACHE_RESULT=%ERRORLEVEL%"\npause\nexit /b %WS_CACHE_RESULT%\n',encoding='ascii')
    print(json.dumps(report,ensure_ascii=True))
    print('Manifest:',manifest)

if __name__=='__main__':main()
