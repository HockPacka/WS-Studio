"""Generate lazily loaded native class catalogs; no SQL, learning or client writes."""
import argparse,hashlib,json,sys
from pathlib import Path
from wildstar_spells.schema import read_tbl
from ws_combat_data import lua
ROOT=Path(__file__).resolve().parents[1]
def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--output',type=Path,required=True)
    a=ap.parse_args();assert not a.output.exists(),'choose a new catalog folder'
    db=ROOT/'WoWClient/ClientData/DB';spells=read_tbl(db/'Spell4.tbl');bases=read_tbl(db/'Spell4Base.tbl');classes=read_tbl(db/'Class.tbl')
    bi=bases.index();a.output.mkdir(parents=True);report={}
    for c in classes.rows:
        cid=c['ID'];instances={};tiers={}
        for r in spells.rows:
            b=bi[r['spell4BaseIdBaseSpell']]
            if b['classIdPlayer']!=cid:continue
            instances[r['ID']]={'id':r['ID'],'baseId':b['ID'],'tier':r['tierIndex'],'nativeClass':cid,'description':r['description']}
            tiers.setdefault(b['ID'],{}).setdefault(r['tierIndex'],{})[r['ID']]=True
        payload={'classId':cid,'className':c['enumName'],'instances':instances,'baseTiers':tiers,'runtimeReady':False}
        p=a.output/('Class'+str(cid)+'.data');p.write_text('-- Generated native class catalog; no automatic ability learning.\nreturn '+lua(payload)+'\n',encoding='utf-8')
        report[cid]={'name':c['enumName'],'instances':len(instances),'bases':len(tiers),'sha256':hashlib.sha256(p.read_bytes()).hexdigest()}
    (a.output/'manifest.json').write_text(json.dumps({'classes':report,'sourceHashes':{'Spell4':spells.sha256,'Spell4Base':bases.sha256,'Class':classes.sha256}},indent=2))
    print(json.dumps(report))
if __name__=='__main__':main()
