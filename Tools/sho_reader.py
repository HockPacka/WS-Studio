"""WildStar shader containers: SHDR v2 dispatch and STGT v3 target archives.

Compiled shader blob indices differ from permutation indices. STGT also carries
input-layout DXBC signatures; those are not additional shader programs.
"""
import struct


class ShoError(ValueError): pass


def read_sho(data):
    def span(p,n):
        if p<0 or n<0 or p>len(data) or n>len(data)-p:raise ShoError(f'out of bounds: {p:#x}+{n:#x}')
        return data[p:p+n]
    span(0,8)
    magic,version=struct.unpack_from('<4sI',data)
    if magic==b'SHDR' and version==2:
        span(0,32)
        count,off=struct.unpack_from('<QQ',data,8);table=32+off
        span(table,count*24);base=(table+count*24+15)&~15
        targets=[]
        for i in range(count):
            stage,n,o=struct.unpack_from('<Q2Q',data,table+i*24)
            name=span(base+o,n*2).decode('utf-16le').rstrip('\0')
            targets.append(dict(stage_selector=stage,file=name))
        return dict(magic='SHDR',version=version,targets=targets)
    if magic!=b'STGT' or version!=3:raise ShoError('unsupported shader container')
    span(0,80)
    def array(off,stride):
        n,o=struct.unpack_from('<QQ',data,off);p=80+o;span(p,n*stride)
        return n,p
    def blobs(off):
        n,p=array(off,16);base=(p+n*16+15)&~15;result=[]
        for i in range(n):
            size,o=struct.unpack_from('<QQ',data,p+i*16);start=base+o;span(start,size)
            result.append(dict(index=i,offset=start,bytes=size))
        return result
    def indices(off):
        n,p=array(off,4)
        return list(struct.unpack_from('<'+str(n)+'I',data,p)) if n else []
    code,layouts=blobs(8),blobs(0x28)
    mapping,layout_mapping=indices(0x18),indices(0x38)
    if any(i!=0xffffffff and i>=len(code) for i in mapping):raise ShoError('invalid shader permutation index')
    if any(i!=0xffffffff and i>=len(layouts) for i in layout_mapping):raise ShoError('invalid input-layout index')
    return dict(magic='STGT',version=version,code=code,input_layouts=layouts,
                permutation_to_code=mapping,permutation_to_layout=layout_mapping)
