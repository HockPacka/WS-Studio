"""Validate SKY resource/table joins and AREA corner sky IDs; inventory TEX shapes."""
from collections import Counter
import csv
import json
from pathlib import Path
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from sky_reader import read_sky,cell_sky_weights
from area_reader import read_area,read_chnk,split_cell
ROOT=Path(__file__).resolve().parents[2]
CLIENT=ROOT/'WoWClient'


def table(name):
    return {int(r['ID']):r for r in csv.DictReader((CLIENT/'tables_csv'/f'{name}.csv').open(encoding='utf-8-sig'))}


def main():
    out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
    world,cloud,tracks=table('WorldSky'),table('SkyCloudSet'),table('SkyTrackCloudSet')
    missing=[];resources={};cloud_ids=Counter();unknown_ids=[];warnings=[]
    def resource(name,owner):
        if not name:return
        path=CLIENT/'ClientData'/name.replace('\\','/')
        if not path.is_file():missing.append(dict(owner=owner,path=name));return
        if name in resources:return
        record=dict(path=name,bytes=path.stat().st_size)
        if path.suffix.lower()=='.tex':
            with path.open('rb') as f:hdr=f.read(40)
            words=struct.unpack('<10I',hdr)
            record.update(width=words[2],height=words[3],depth=words[4],faces=words[5],mips=words[6],format=words[7],jpeg=words[8])
        resources[name]=record
    for p in sorted((CLIENT/'ClientData/Sky').rglob('*.sky')):
        sky=read_sky(p.read_bytes())
        for model in sky['models']:resource(model['path'],p.name)
        for path in sky['strings'].values():resource(path,p.name)
        for path in sky['particulates']:resource(path,p.name)
        for values in sky['tracks']['0x310']['values']:
            id=values[0];cloud_ids[id]+=1
            if id and id not in cloud:unknown_ids.append(dict(owner=p.name,id=id))
        if sky['warnings']:warnings.append(dict(file=p.name,tracks=sky['warnings']))
    for id,row in world.items():
        resource(row['assetPath'],f'WorldSky {id}')
        resource(row['assetPathInFlux'],f'WorldSky {id} Flux')
    missing_tracks=[]
    for id,row in cloud.items():
        for k in range(6):
            trackid=int(row[f'skyTrackCloudSetId0{k}'])
            if not trackid:continue
            if trackid not in tracks:missing_tracks.append((id,trackid));continue
            row2=tracks[trackid]
            for j in range(int(row2['count'])):resource(row2[f'model{j:02d}'],f'SkyTrackCloudSet {trackid}')
    tile=CLIENT/'ClientData/Map/Western/Western.393b.area'
    area=read_area(tile.read_bytes());tile_ids=Counter();cells=0
    for tag,_,data,_ in area['chunks']:
        if tag not in ('CHNK','KNHC'):continue
        for index,_,raw in read_chnk(data,area['compressed']):
            if index<0:continue
            blocks=split_cell(raw)[1]
            if 6 not in blocks or 7 not in blocks:continue
            cells+=1
            for id,w in cell_sky_weights(blocks[6],blocks[7],0.5,0.5):
                if id not in world:unknown_ids.append(dict(owner=f'AREA cell {index}',id=id))
                tile_ids[id]+=w
    report=dict(world_sky_rows=len(world),cloud_set_rows=len(cloud),cloud_track_rows=len(tracks),
                cloud_ids_in_sky=dict(cloud_ids),unknown_sky_or_cloud_ids=unknown_ids,missing_cloud_tracks=missing_tracks,
                missing_resources=missing,time_anomalies=warnings,
                tile=dict(file=str(tile.relative_to(ROOT)),cells=cells,skies=[dict(id=id,weight_sum=w,asset=world[id]['assetPath']) for id,w in tile_ids.items()]),
                resources=list(resources.values()))
    (out/'resource_links.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
    shapes=Counter((r['depth'],r['faces']) for r in resources.values() if 'depth' in r)
    print('SKY links:',len(world),'WorldSky rows;',len(resources),'resources;',len(missing),'missing references; TEX depth/faces',dict(shapes))
    print('AREA test tile:',report['tile']['skies'])
    assert not unknown_ids and not missing_tracks


if __name__=='__main__':main()
