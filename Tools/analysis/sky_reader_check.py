"""Bounds, source preservation, sampling and version tests for sky_reader."""
from pathlib import Path
import struct
import sys
sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
from sky_reader import SkyError,read_sky,sample_track,sample_resources,cell_sky_weights
from sho_reader import read_sho,ShoError

root=Path(__file__).resolve().parents[2]
b=(root/'WoWClient/ClientData/Sky/TestReference.sky').read_bytes()
sky=read_sky(b)
required=max(end for _,end,_ in sky['regions'])
for cut in range(required):
    try:read_sky(b[:cut])
    except SkyError:continue
    raise AssertionError(('accepted truncated source',cut,required))
for off,value in [(0,0),(4,17)]:
    changed=bytearray(b);struct.pack_into('<I',changed,off,value)
    try:read_sky(changed)
    except SkyError:continue
    raise AssertionError('invalid magic/version accepted')
t=dict(times=[0,43200,86400],values=[[0,0],[2,4],[4,8]],value_type='float')
assert sample_track(t,-1)==[0,0]
assert sample_track(t,21600)==[1,2]
assert sample_track(t,43200)==[2,4]
assert sample_track(t,86401)==[4,8]
resource=dict(times=[0,86400],values=[[1],[6]],value_type='uint32')
assert sample_resources(resource,21600)==[(1,0.75),(6,0.25)]
cyclic=dict(times=[21600,64800],values=[[1],[6]],value_type='uint32')
assert sample_resources(cyclic,0)==[(6,0.5),(1,0.5)]
assert sample_resources(cyclic,86400)==[(6,0.5),(1,0.5)]
assert sample_resources(cyclic,21600)==[(1,1.0)]
p=root/'WoWClient/ClientData/Sky/NorthernWilds_Main.sky'
raw=p.read_bytes();source=read_sky(raw)
assert source['warnings'] and source['tracks']['0x2a0']['times'][-2]==60
try:sample_track(source['tracks']['0x2a0'],72000)
except SkyError:pass
else:raise AssertionError('unsorted source silently sampled')
assert raw==p.read_bytes()
ids=struct.pack('<16I',1,2,0,0, 1,2,0,0, 1,2,0,0, 1,2,0,0)
weights=bytes([255,0,0,0, 0,255,0,0, 255,0,0,0, 0,255,0,0])
assert cell_sky_weights(ids,weights,0,0)==[(1,1.0)]
assert cell_sky_weights(ids,weights,1,1)==[(2,1.0)]
assert cell_sky_weights(ids,weights,0.5,0.5)==[(1,0.5),(2,0.5)]
shaders=root/'WoWClient/ClientData/Shaders'
dispatch=read_sho((shaders/'SkyVS.sho').read_bytes())
assert len(dispatch['targets'])==2 and dispatch['targets'][0]['file'].endswith('vs_3_0.sho')
archive=read_sho((shaders/'M3CloudVS.vs_4_0.sho').read_bytes())
assert len(archive['code'])==9 and len(archive['permutation_to_code'])==12 and len(archive['input_layouts'])==9
try:read_sho((shaders/'SkyVS.vs_4_0.sho').read_bytes()[:100])
except ShoError:pass
else:raise AssertionError('truncated SHO accepted')
print('PASS SKY reader: bounds/truncation, magic/version, float interpolation, resource blending, authored time anomalies preserved')
print('PASS AREA sky interpolation + SHDR dispatch + STGT permutation/layout separation')
