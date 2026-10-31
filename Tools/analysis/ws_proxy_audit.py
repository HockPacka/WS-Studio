"""Inventory native Proxy parameter patterns without assigning execution semantics."""
import argparse
import collections
import hashlib
import json
import sys
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from wildstar_spells.schema import read_tbl

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--client',type=Path,default=ROOT/'WoWClient')
    ap.add_argument('--output',type=Path,required=True)
    args=ap.parse_args()
    assert not args.output.exists(),'Choose a new audit folder'
    tables={name:read_tbl(args.client/'ClientData/DB'/(name+'.tbl')) for name in ('Spell4','Spell4Base','Spell4Effects','SpellEffectType')}
    spells=tables['Spell4'].index();bases=tables['Spell4Base'].index()
    bybase=collections.defaultdict(list)
    for row in spells.values():bybase[row['spell4BaseIdBaseSpell']].append(row)
    patterns=collections.Counter();lookups=collections.Counter();rows=[]
    for e in tables['Spell4Effects'].rows:
        if e['effectType']!=26:continue
        raw=e['dataBits00'];instance=spells.get(raw);base=bases.get(raw)
        tag=('both' if instance and base else 'instance_only' if instance else 'base_only' if base else 'neither')
        lookups[tag]+=1
        patterns[(e['dataBits04'],e['dataBits05'],tag)]+=1
        rows.append({'effectId':e['ID'],'parentSpell4':e['spellId'],'lookupStatus':tag,
            'rawParameters':{f'dataBits{i:02d}':e[f'dataBits{i:02d}'] for i in range(10)},
            'rawInstanceCandidate':None if not instance else {'id':instance['ID'],'baseId':instance['spell4BaseIdBaseSpell'],'tier':instance['tierIndex'],'description':instance['description']},
            'baseCandidates':[{'id':r['ID'],'tier':r['tierIndex']} for r in sorted(bybase[raw],key=lambda r:(r['tierIndex'],r['ID']))],
            'runtimeReady':False})
    args.output.mkdir(parents=True)
    with (args.output/'proxy_rows.jsonl').open('w',encoding='utf-8') as stream:
        for row in rows:stream.write(json.dumps(row,separators=(',',':'))+'\n')
    report={'effectCount':len(rows),'lookupStatuses':dict(lookups),
        'patterns':[{'dataBits04':a,'dataBits05':b,'lookupStatus':c,'count':n} for (a,b,c),n in patterns.most_common()],
        'effectTypeDefinition':tables['SpellEffectType'].index()[26],
        'sourceHashes':{name:table.sha256 for name,table in tables.items()},
        'rowsSha256':hashlib.sha256((args.output/'proxy_rows.jsonl').read_bytes()).hexdigest(),
        'semantics':'Statistical evidence only; neither namespace nor flags assigned execution meaning.'}
    (args.output/'report.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
    print(json.dumps({'effectCount':len(rows),'lookupStatuses':dict(lookups),'topPatterns':report['patterns'][:6]}))
if __name__=='__main__':main()
