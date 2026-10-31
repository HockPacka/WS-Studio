"""Inventory and disassemble the SKY/atmosphere shader families from ClientData.

Usage: sky_shader_audit.py output_directory
Compiled shader indices and renderer permutation indices are kept separate;
the STGT permutation and input-layout maps are exported explicitly.
"""
import hashlib
import json
from pathlib import Path
import re
import struct
import sys
from dxbc_dis import disassemble

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools'))
from sho_reader import read_sho
FAMILIES={
    'SkyVS':('vs','Sky geometry transform + directional SH color + height band','1407c3b60','0x1678'),
    'SkyPS':('ps','Sky RGB output; variant 0 clamps to 1.5','1407c3b60','0x1680'),
    'M3CloudVS':('vs','Model/cloud geometry, position and UV generation','1402eb270','see decompilation'),
    'M3CloudPS':('ps','Cloud SH lighting, texture/LUT color, sun highlight and fog','1402eb270','see decompilation'),
    'LightSunSkyPS':('ps','Sun/sky deferred lighting and surface shading','140253a90','0x888'),
    'FogVS':('vs','Fog pass geometry','140253a90','0x890'),
    'FogPS':('ps','Scene distance/height fog variants','140253a90','0x898'),
    'FogDepthPS':('ps','Depth-dependent fog support variants','140253a90','0x8a0'),
    'fogSkyps':('ps','Sky/fog composition','140253a90','0x848'),
    'CompositeEnvMapPS':('ps','Environment-map compositing support','1407c3b60','0x1688'),
    'FilterEnvMapPS':('ps','Environment-map filtering support','1407c3b60','0x1690'),
    'DownsampleEnvMapPS':('ps','Environment-map downsampling support','1407c3b60','0x1698'),
    'CompositeCUBEMapPS':('ps','Cube-map compositing support','1407c3b60','0x16a0'),
    'CompositePS':('ps','Scene postprocess/composition; exact SKY LUT routing still open','140253a90','0x868'),
    'scatterPS':('ps','Supporting screen-space scatter effect; not assumed Rayleigh/Mie','140253a90','0x8e0'),
}


def main():
    out=Path(sys.argv[1]);out.mkdir(parents=True,exist_ok=True)
    reports=[]
    for stem,(stage,role,creator,member) in FAMILIES.items():
        dispatch_path=ROOT/'WoWClient/ClientData/Shaders'/f'{stem}.sho'
        source=dispatch_path.read_bytes();dispatch=read_sho(source)
        reports.append(dict(file=str(dispatch_path.relative_to(ROOT)),bytes=len(source),sha256=hashlib.sha256(source).hexdigest(),role=role,container=dispatch))
        for profile in (f'{stage}_3_0',f'{stage}_4_0'):
            path=ROOT/'WoWClient/ClientData/Shaders'/f'{stem}.{profile}.sho'
            if not path.exists():continue
            b=path.read_bytes();container=read_sho(b)
            blobs=[(item['offset'],item['bytes']) for item in container['code']]
            entries=[]
            if blobs:
                status='container shader code disassembled'
                for i,(off,size) in enumerate(blobs):
                    blob=b[off:off+size]
                    parts=[]
                    if blob[:4]==b'DXBC':
                        n=struct.unpack_from('<I',blob,28)[0]
                        parts=[blob[struct.unpack_from('<I',blob,32+4*j)[0]:][:4].decode('ascii','replace') for j in range(n)]
                    try:text=disassemble(blob).rstrip('\0')
                    except RuntimeError as e:
                        entries.append(dict(blob=i,file_offset=off,bytes=size,chunks=parts,status=str(e)))
                        continue
                    output=f'{stem}_{profile}_{i:03d}.txt'
                    (out/output).write_text(text,encoding='utf-8')
                    constants=re.findall(r'dcl_constantbuffer (CB\d+\[\d+\])',text)
                    legacy_constants=sorted(set(re.findall(r'\bc\d+\b',text)),key=lambda s:int(s[1:]))
                    resources=[line for line in text.splitlines() if line.startswith('dcl_resource') or line.startswith('dcl_sampler')]
                    entries.append(dict(blob=i,file_offset=off,bytes=size,chunks=parts,constants=constants,
                                        legacy_constants=legacy_constants,resources=resources,disassembly=output))
            reports.append(dict(file=str(path.relative_to(ROOT)),bytes=len(b),sha256=hashlib.sha256(b).hexdigest(),
                                role=role,creator=creator,renderer_member=member,profile=profile,status=status,
                                shader_count=len(blobs),container=container,blobs=entries))
    (out/'shader_manifest.json').write_text(json.dumps(reports,indent=2),encoding='utf-8')
    print('Shader audit:',len(reports),'files;',sum(r.get('shader_count',0) for r in reports),'shader programs;',
          sum('disassembly' in b for r in reports for b in r.get('blobs',[])),'disassembled')


if __name__=='__main__':main()
