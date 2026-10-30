"""A small two-key synthetic crystal that uses the actual WildStar M3 packed skin format."""
import struct
from pathlib import Path
from tests.test_native_m3_extended import enriched, aligned

ROOT=Path(__file__).resolve().parents[1]

def make_animated_demo():
    b=bytearray(enriched());g=0x630
    gb=(g+0xc8+15)&~15
    n=struct.unpack_from('<I',b,g+0x18)[0]
    stride=struct.unpack_from('<H',b,g+0x1c)[0]
    src=gb+struct.unpack_from('<Q',b,g+0x40)[0]
    original=bytes(b[src:src+n*stride])
    # Native per-vertex layout: pos float3, oct normal2, bone id uint8[4], weight uint8[4], UV1 half2.
    b[g+0x20:g+0x2b]=bytes([1,0,3,0,4,4,0,0,5,0,0])
    new_stride=26
    struct.pack_into('<H',b,g+0x1c,new_stride)
    aligned(b)
    start=len(b)
    for i in range(n):
        old=original[i*stride:(i+1)*stride]
        b.extend(old[:14]);b.extend(bytes([0,0,0,0,255,0,0,0]));b.extend(old[14:18])
    struct.pack_into('<QQ',b,g+0x38,n*new_stride,start-gb)
    # Track 6 is two translations. The original fixture used one nonzero sample.
    count,offset=struct.unpack_from('<QQ',b,0x180)
    bone=0x630+offset;base=(bone+count*0x160+15)&~15
    aligned(b);keys=len(b)-base;b.extend(struct.pack('<2I',0,1500))
    aligned(b);values=len(b)-base;b.extend(struct.pack('<6f',0,0,0,1.7,0,0))
    struct.pack_into('<QQQ',b,bone+0x10+6*24,2,keys,values)
    return bytes(b)

if __name__=='__main__':
    result=ROOT/'demo'/'AnimatedCrystal.m3';result.write_bytes(make_animated_demo());print(result,result.stat().st_size)
