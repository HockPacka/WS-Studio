"""Raw WildStar XSKY v16 reader, checked against the original loader.

Offsets are relative to the fixed 0x4c0 header; nested track tables use the
aligned end of their own table. Unknown fields retain their raw bytes.
Usage: sky_reader.py file.sky [output.json]
       sky_reader.py --check ClientData/Sky output_directory
"""
import bisect
from collections import Counter
import hashlib
import json
import math
from pathlib import Path
import struct
import sys

HEADER_SIZE = 0x4c0
GROUPS = (0x28,0xc0,0x158,0x1f0)
GROUP_ARRAY_WIDTHS = {0x08:16,0x18:32,0x28:48,0x38:48,0x48:48,0x58:108}
TOP_TRACK_WIDTHS = {0x288:16,0x2a0:32,0x2b8:16,0x2d0:24,0x2f8:96,
                    0x310:4,0x328:4,0x360:16,0x398:4,0x3b0:16,0x3c8:16,
                    **{0x3e0+24*i:32 for i in range(8)}}


# Field names. Confidence: see docs/sky_field_semantics.md. Component lists give the meaning of each float of a key value
# (None = not interpolated / always zero in all 1288 local files).
SCREEN_COMPONENTS = ['SepiaR','SepiaG','SepiaB','SepiaA','Gray','White','Saturation','Contrast','Brightness','Gamma',
                     'Iris','LuminanceMin','StarBright','StarAttenuation','StarAdd',
                     'BloomBright','BloomAdd','BloomExp','Decay','Weight','Exposure','Alpha',None,None]
FIELD_NAMES = {
    0x288:('Ambient',['r','g','b','a']),
    0x2a0:('SunDiffuse',['elevationDeg','azimuthDeg',None,None,'r','g','b','a']),
    0x2b8:('SunSpecular',['r','g','b','a']),
    0x2d0:('FogDistance',['FogStart','FogEnd','SkyStart','SkyEnd','CloudFog','SkyFog']),
    0x2f8:('Screen',SCREEN_COMPONENTS),
    0x310:('CloudSetId',['skyCloudSetId']),
    0x328:('CloudAlpha',['alpha']),
    0x360:('SunGlare',['r','g','b','a']),
    0x398:('WindowGlow',['glow']),
    0x3b0:('NightAmbient',['r','g','b','a']),
    0x3c8:('HorizonFogMod',['r','g','b','a']),
    **{0x3e0+24*i:(f'LiquidColor{i}',['r0','g0','b0','a0','r1','g1','b1','a1']) for i in range(8)},
}


class SkyError(ValueError): pass


class Reader:
    def __init__(self,data):
        self.data=data
        self.regions=[]
        self.tracks=[]
        self.warnings=[]

    def span(self,p,n,label):
        if p<0 or n<0 or p>len(self.data) or n>len(self.data)-p:
            raise SkyError(f'{label}: range {p:#x}+{n:#x} exceeds file size {len(self.data):#x}')
        if n:self.regions.append((p,p+n,label))
        return self.data[p:p+n]

    def ap(self,p,stride,base=HEADER_SIZE):
        self.span(p,16,'array descriptor')
        count,offset=struct.unpack_from('<I4xQ',self.data,p)
        start=base+offset
        self.span(start,count*stride,f'array@{p:x}')
        return count,start

    def string(self,p,base=HEADER_SIZE):
        n,o=self.ap(p,2,base)
        b=self.span(o,n*2,'utf16 string')
        try:return b.decode('utf-16le').rstrip('\0')
        except UnicodeDecodeError as e:raise SkyError(f'bad string@{p:x}') from e

    def track(self,p,stride,base=HEADER_SIZE,kind='float'):
        self.span(p,24,'track descriptor')
        count,times,values=struct.unpack_from('<I4xQQ',self.data,p)
        t=self.span(base+times,count*4,f'track keys@{p:x}')
        v=self.span(base+values,count*stride,f'track values@{p:x}')
        keys=list(struct.unpack('<'+str(count)+'I',t)) if count else []
        sorted_times=all(a<=b for a,b in zip(keys,keys[1:]))
        if not sorted_times:self.warnings.append(dict(descriptor=f'0x{p:x}',base=base,issue='unsorted source times',times=keys))
        fmt='f' if kind=='float' else 'I'
        records=[list(struct.unpack_from('<'+str(stride//4)+fmt,v,i*stride)) for i in range(count)]
        result=dict(descriptor=f'0x{p:x}',count=count,stride=stride,times=keys,values=records)
        # Raw retained even where mixed float/integer records are not named yet.
        result['raw_values_hex']=v.hex()
        result['value_type']=kind
        result['sorted_times']=sorted_times
        self.tracks.append(result)
        return result

    def track_array(self,p,stride):
        n,o=self.ap(p,24)
        base=(o+n*24+15)&~15
        return [self.track(o+i*24,stride,base) for i in range(n)]


def read_sky(data):
    r=Reader(data)
    r.span(0,HEADER_SIZE,'header')
    if data[:4]!=b'YKSX':raise SkyError('not XSKY')
    version=struct.unpack_from('<I',data,4)[0]
    if version!=16:raise SkyError(f'unsupported XSKY version {version}')
    result=dict(version=version,header_size=HEADER_SIZE,source_xml=r.string(0x18),
                header_words=list(struct.unpack_from('<4I',data,8)),header_10_float=struct.unpack_from('<f',data,16)[0],
                header_hex=data[:HEADER_SIZE].hex(),groups={},tracks={})
    for g in GROUPS:
        group=dict(words=list(struct.unpack_from('<2I',data,g)),arrays={})
        for relative,stride in GROUP_ARRAY_WIDTHS.items():
            group['arrays'][f'0x{relative:x}']=r.track_array(g+relative,stride)
        group['sh_track']=r.track(g+0x68,108)
        group['record_110_track']=r.track(g+0x80,272)
        result['groups'][f'0x{g:x}']=group
    for off,stride in TOP_TRACK_WIDTHS.items():
        result['tracks'][f'0x{off:x}']=r.track(off,stride,kind='uint32' if off==0x310 else 'float')
        if off in FIELD_NAMES:
            result['tracks'][f'0x{off:x}']['name'],result['tracks'][f'0x{off:x}']['components']=FIELD_NAMES[off]
    # Sky-associated models: u16 type / u16 unknown / u32 flags, AP UTF16, DP32.
    n,o=r.ap(0x2e8,48);base=o+n*48;result['models']=[]
    for i in range(n):
        p=o+i*48
        result['models'].append(dict(header_words=list(struct.unpack_from('<2I',data,p)),
                                     path=r.string(p+8,base),track=r.track(p+24,32,base)))
    n,o=r.ap(0x340,16);base=o+n*16
    result['particulates']=[r.string(o+i*16,base) for i in range(n)]
    result['strings']={f'0x{off:x}':r.string(off) for off in (0x350,0x378,0x388,0x4b0)}
    result['track_arrays_4a0']=r.track_array(0x4a0,8)
    # 0x4A0: array of tracks, key value = (WindSpawn.tbl id, Wind.tbl id)
    for t in result['track_arrays_4a0']:
        raw=bytes.fromhex(t['raw_values_hex'])
        t['name']='WindSpawn'
        t['wind_pairs']=[list(struct.unpack_from('<II',raw,i*8)) for i in range(len(raw)//8)]
    result['track_count']=len(r.tracks)
    result['key_count']=sum(t['count'] for t in r.tracks)
    result['time_range']=[min((t for tr in r.tracks for t in tr['times']),default=0),
                          max((t for tr in r.tracks for t in tr['times']),default=0)]
    result['regions']=r.regions
    result['warnings']=r.warnings
    return result


def sample_track(track,time):
    """Float helper: clamp endpoints and interpolate interior keys linearly.

    The caller owns day wrapping; this helper uses step selection for IDs.
    The original client also blends resources between adjacent ID keys: use
    sample_resources for that, rather than numerically interpolating IDs.
    Unknown mixed-record tracks should be inspected as raw data, not sampled.
    """
    times,values=track['times'],track['values']
    if not track.get('sorted_times',True):raise SkyError('source track has unsorted times; explicit repair policy required')
    if not times:return None
    i=bisect.bisect_right(times,time)
    if i==0:return values[0]
    if i==len(times) or times[i-1]==time or track.get('value_type')=='uint32':return values[i-1]
    t=(time-times[i-1])/(times[i]-times[i-1])
    return [a+(b-a)*t for a,b in zip(values[i-1],values[i])]


def sample_resources(track,time):
    """Blend resource IDs cyclically across a 86400-second day (FUN_1407d5f20).

    The caller supplies time within the day; exact keys return a single ID.
    """
    if not track.get('sorted_times',True):raise SkyError('source track has unsorted times')
    keys,values=track['times'],track['values']
    if not keys:return []
    i=bisect.bisect_right(keys,time)
    if len(keys)==1:return [(int(values[0][0]),1.0)]
    if i and time==keys[i-1]:return [(int(values[i-1][0]),1.0)]
    left,right=(i-1)%len(keys),i%len(keys)
    start,end=keys[left],keys[right]
    if right<left:
        end+=86400
        if i==0:time+=86400
    if end<=start:raise SkyError('resource track has invalid cyclic interval')
    t=(time-start)/(end-start)
    a,b=int(values[left][0]),int(values[right][0])
    return [(a,1.0)] if a==b else [(a,1-t),(b,t)]


def cell_sky_weights(ids_block,weights_block,u,v):
    """AREA blocks 6/7: merge corner IDs, keep the four largest contributions.

    u/v are normalized cell coordinates. The sky manager normalizes surviving
    loaded resources later; missing/empty data requires its map fallback.
    """
    if len(ids_block)!=64 or len(weights_block)!=16:raise SkyError('bad AREA sky block sizes')
    if not (math.isfinite(u) and math.isfinite(v) and 0<=u<=1 and 0<=v<=1):raise SkyError('invalid sky sample coordinates')
    ids=struct.unpack('<16I',ids_block)
    contributions={}
    corners=((1-u)*(1-v),u*(1-v),(1-u)*v,u*v)
    for corner,spatial in enumerate(corners):
        for slot in range(4):
            i=corner*4+slot
            if ids[i] and weights_block[i]:
                contributions[ids[i]]=contributions.get(ids[i],0)+weights_block[i]/255*spatial
    return sorted(((i,w) for i,w in contributions.items() if w>0),key=lambda p:-p[1])[:4]


def validate(directory,out):
    out.mkdir(parents=True,exist_ok=True)
    cases=[];errors=[];hist=Counter()
    for p in sorted(directory.rglob('*')):
        if p.suffix.lower()!='.sky':continue
        b=p.read_bytes()
        try:
            sky=read_sky(b)
            for t in sky['tracks'].values():hist[t['stride']]+=t['count']
            cases.append(dict(file=str(p),bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),
                              tracks=sky['track_count'],keys=sky['key_count'],time_range=sky['time_range'],
                              models=[m['path'] for m in sky['models']],strings=sky['strings'],warnings=sky['warnings']))
        except (SkyError,struct.error) as e:errors.append(dict(file=str(p),error=str(e)))
    report=dict(files=len(cases),errors=errors,total_keys=sum(c['keys'] for c in cases),
                top_level_record_widths=dict(hist),cases=cases)
    (out/'validation.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
    print(f'Parsed {len(cases)} XSKY v16 files, {len(errors)} errors')
    for error in errors[:10]:print(error)
    return 1 if errors else 0


def main():
    if sys.argv[1]=='--check':return validate(Path(sys.argv[2]),Path(sys.argv[3]))
    sky=read_sky(Path(sys.argv[1]).read_bytes())
    text=json.dumps(sky,indent=2)
    if len(sys.argv)>2:Path(sys.argv[2]).write_text(text,encoding='utf-8')
    else:print(text)
    return 0


if __name__=='__main__':sys.exit(main())
