"""Core-independent WDBC row patches. Never connects to a database.

All numeric columns retain their original u32 bit patterns. String columns
are relocated through their text, so another server's string offsets survive.
"""
import argparse,json,struct
from pathlib import Path

STRINGS={
    'CreatureModelData':{2},'CreatureDisplayInfo':{6,7,8,9},
    'ChrRaces':{6,11,65,66,67}|set(range(14,30))|set(range(31,47))|set(range(48,64)),
    'NameGen':{1},'CharStartOutfit':set(),'CharBaseInfo':set(),
    'Map':{1}|set(range(5,21))|set(range(23,39))|set(range(40,56)),
    'AreaTable':set(range(11,27)),
    'WorldMapArea':{3},'WorldMapContinent':set(),
    'ZoneMusic':{1},'SoundEntries':{2,23}|set(range(3,13)),
    'SkillRaceClassInfo':set(),'SkillLineAbility':set(),
    'Spell':set(range(136,152))|set(range(153,169))|set(range(170,186))|set(range(187,203)),
    'SpellCastTimes':set(),'SpellDuration':set(),
    'SpellRange':set(range(6,22))|set(range(23,39)),'SpellIcon':{1},
    'SpellVisual':set(),'SpellVisualKit':set(),'SpellVisualEffectName':{1,2},
}

class Dbc:
    def __init__(self,data,name):
        if len(data)<20:raise ValueError('truncated DBC')
        magic,self.count,self.fields,self.size,ss=struct.unpack_from('<4s4I',data)
        if magic!=b'WDBC' or 20+self.count*self.size+ss!=len(data):raise ValueError('invalid DBC size/header')
        self.name=name;self.packed=name=='CharBaseInfo'
        special=self.packed and (self.size,self.fields)==(2,2) or name=='CharStartOutfit' and (self.size,self.fields)==(296,77)
        if not special and self.size!=self.fields*4:raise ValueError('unsupported DBC record layout: '+name)
        self.rows=[data[20+i*self.size:20+(i+1)*self.size] for i in range(self.count)]
        self.strings=bytearray(data[20+self.count*self.size:])
        if not self.strings or self.strings[-1]!=0:raise ValueError('invalid DBC string block')
        if name not in STRINGS:raise ValueError('unregistered string-column schema: '+name)

    def decode(self,row):
        values=list(row) if self.packed else list(struct.unpack('<%dI'%(self.size//4),row))
        for col in STRINGS[self.name]:
            off=values[col]
            if off>=len(self.strings):raise ValueError('DBC string offset out of range')
            end=self.strings.find(0,off)
            values[col]=bytes(self.strings[off:end]).decode('utf-8')
        return values

    def key(self,values):return values[:2] if self.packed else values[:1]
    def encode(self,values):
        if len(values)!=(2 if self.packed else self.size//4):raise ValueError('wrong delta field count')
        values=list(values)
        for col in STRINGS[self.name]:
            if not isinstance(values[col],str):raise ValueError('string field needs text')
            raw=values[col].encode('utf-8')+b'\0';off=0
            while True:
                off=self.strings.find(raw,off)
                if off<0:off=len(self.strings);self.strings+=raw;break
                if off==0 or self.strings[off-1]==0:break
                off+=1
            values[col]=off
        return bytes(values) if self.packed else struct.pack('<%dI'%(self.size//4),*values)

    def save(self):return struct.pack('<4s4I',b'WDBC',len(self.rows),self.fields,self.size,len(self.strings))+b''.join(self.rows)+bytes(self.strings)

def owned(name,v,strings,model_count):
    if name in ('CreatureModelData','CreatureDisplayInfo'):return 200000<=v[0]<200000+model_count
    if name=='ChrRaces':return 22<=v[0]<=30
    if name=='CharBaseInfo':return 22<=v[0]<=30
    if name=='CharStartOutfit':return 22<=(v[1]&255)<=30
    if name=='NameGen':return 22<=v[2]<=30
    if name=='Map':return v[1].startswith('WS_')
    if name=='AreaTable':return 50000<=v[0]<60000 or 900000<=v[0]<1000000
    if name in ('WorldMapArea','WorldMapContinent','ZoneMusic','SoundEntries'):return 900000<=v[0]<1000000
    if name in ('SkillRaceClassInfo','SkillLineAbility'):return 9000000<=v[0]<9100000
    return False

def export_delta(name,original,generated,model_count):
    base=Dbc(original,name);new=Dbc(generated,name)
    if (base.fields,base.size)!=(new.fields,new.size):raise ValueError('different DBC layouts')
    old={tuple(base.key(v)):v for row in base.rows for v in [base.decode(row)]}
    rows=[]
    for raw in new.rows:
        v=new.decode(raw)
        if not owned(name,v,STRINGS[name],model_count):continue
        key=new.key(v);expected=old.get(tuple(key))
        if expected==v:continue
        rows.append(dict(key=key,fields=v,expected=expected))
    return dict(schemaVersion=1,table=name,fieldCount=new.fields,recordSize=new.size,
                encoding='u8' if new.packed else 'u32-bits',stringColumns=sorted(STRINGS[name]),records=rows)

def merge(delta,data,remove=False):
    if delta.get('installable') is False:raise ValueError('Catalog-only delta: combat adapter not approved; refusing installation')
    name=delta['table'];target=Dbc(data,name)
    if delta.get('schemaVersion')!=1 or delta['stringColumns']!=sorted(STRINGS[name]) or (delta['fieldCount'],delta['recordSize'])!=(target.fields,target.size):raise ValueError('delta schema mismatch')
    indexed={};positions={}
    for index,row in enumerate(target.rows):
        v=target.decode(row);key=tuple(target.key(v))
        if key in indexed:raise ValueError('duplicate target key '+str(key))
        indexed[key]=v;positions[key]=index
    operations=[];seen=set()
    for item in delta['records']:
        key=tuple(item['key']);new=item['fields'];expected=item['expected'];current=indexed.get(key)
        if key in seen or key!=tuple(target.key(new)) or (expected is not None and key!=tuple(target.key(expected))):raise ValueError('invalid/duplicate patch key')
        seen.add(key)
        if remove:
            if current==expected:continue
            if current!=new:raise ValueError('refusing to remove changed/unowned row '+str(key))
            operations.append((key,expected))
        else:
            if current==new:continue
            if current!=expected:raise ValueError('ID conflict in '+name+' '+str(key))
            operations.append((key,new))
    # No output or mutations until every affected row has passed preflight.
    removed=set()
    for key,v in operations:
        if v is None:removed.add(positions[key])
        elif key in positions:target.rows[positions[key]]=target.encode(v)
        else:target.rows.append(target.encode(v))
    target.rows=[r for i,r in enumerate(target.rows) if i not in removed]
    return target.save()

def main():
    ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('delta');ap.add_argument('input');ap.add_argument('output');ap.add_argument('--remove',action='store_true');a=ap.parse_args()
    src,dst=Path(a.input).resolve(),Path(a.output).resolve()
    if src==dst:ap.error('output must be a separate file; live input is never overwritten')
    if dst.exists():ap.error('output already exists; choose a new file')
    result=merge(json.loads(Path(a.delta).read_text(encoding='utf-8')),src.read_bytes(),a.remove)
    dst.parent.mkdir(parents=True,exist_ok=True)
    with dst.open('xb') as f:f.write(result)
    print('Prepared',dst,'; input unchanged')

if __name__=='__main__':main()
