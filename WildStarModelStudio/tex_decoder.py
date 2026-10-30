"""WildStar GFX v3 .tex -> PNG for the local Model Studio viewer.

Independent Python implementation informed by the WildStar format documentation
in HockPacka/WS-Tools. Handles DXT1/3/5, BGRA, RGB565, grey, and the
WildStar JPEG-like four-channel entropy stream (types 0/1/2).

Requires Pillow and numpy. Decode is restricted to one downsampled mip and
bounded dimensions; no input file path is ever trusted by this module.
"""
from __future__ import annotations

from io import BytesIO
import math
import struct
import numpy as np
from PIL import Image

MAX_DIM = 8192
MAX_BYTES = 48 * 1024 * 1024

class TexError(ValueError):
    pass


def header(b: bytes) -> dict:
    if len(b) < 112 or not (b[1:4] == b'GFX' or b[:3] in (b'XFG',b'GFX')):
        raise TexError('Keine WildStar-TEX-Datei (GFX-Signatur fehlt)')
    sig, version, w, h, depth, sides, mips, fmt, jpg, kind = struct.unpack_from('<10I', b)
    if version != 3 or not 0 < w <= MAX_DIM or not 0 < h <= MAX_DIM or depth not in (0,1,16) or sides not in (0,1,6):
        raise TexError('Ungültiger TEX-Header oder nicht unterstützte Dimensionen')
    if not 1 <= mips <= 13:
        raise TexError('Ungültige TEX-Mipmap-Anzahl')
    return dict(w=w,h=h,depth=depth,sides=sides,mips=mips,fmt=fmt,jpg=jpg,kind=kind,
                channels=[struct.unpack_from('<3B',b,40+i*3) for i in range(4)],
                jpg_mips=struct.unpack_from('<I',b,52)[0],sizes=struct.unpack_from('<13I',b,56))


def _dims(h,i,total):
    shift=total-1-i
    return max(1,h['w']>>shift),max(1,h['h']>>shift)


def _choose(h,total,max_size):
    if total < 1 or total > 13:
        raise TexError('TEX-Mip-Kette ungültig')
    n=total-1
    while n>0 and max(_dims(h,n,total))>max_size:
        n-=1
    return n, *_dims(h,n,total)


def _dds_image(blob,w,h,fmt):
    # Build standard DDS container in memory and use Pillow's BCn decoder.
    block_size=8 if fmt==13 else 16
    fourcc={13:b'DXT1',14:b'DXT3',15:b'DXT5'}[fmt]
    hdr=bytearray(124)
    struct.pack_into('<I',hdr,0,124)
    struct.pack_into('<I',hdr,4,0x1007)
    struct.pack_into('<II',hdr,8,h,w)
    struct.pack_into('<I',hdr,16,max(1,(w+3)//4)*block_size)
    struct.pack_into('<I',hdr,72,32)
    struct.pack_into('<I',hdr,76,4)
    hdr[80:84]=fourcc
    struct.pack_into('<I',hdr,104,0x1000)
    with Image.open(BytesIO(b'DDS '+hdr+blob)) as im:
        return im.convert('RGBA').copy()


def _jpeg_tables():
    """Retrieve the standard JPEG Huffman tables from Pillow's JPEG encoder.

    WildStar's proprietary streams use the ordinary baseline JPEG VLC tables,
    but have their own four plane ordering and no JPEG container markers.
    """
    buf=BytesIO()
    Image.new('RGB',(16,16),(0,0,0)).save(buf,'JPEG',quality=50,subsampling=0)
    d=buf.getvalue();pos=2;tables={}
    while pos<len(d) and d[pos]==0xff:
        while pos<len(d) and d[pos]==0xff:pos+=1
        marker=d[pos];pos+=1
        if marker in (0xd9,0xda):break
        length=struct.unpack_from('>H',d,pos)[0]
        block=d[pos+2:pos+length];pos+=length
        if marker!=0xc4:continue
        k=0
        while k<len(block):
            flag=block[k];bits=list(block[k+1:k+17]);k+=17
            n=sum(bits);values=list(block[k:k+n]);k+=n
            # Canonical Huffman lookup keyed by (bits, code).
            lookup={};code=0;v=0
            for nbits,amount in enumerate(bits,1):
                for _ in range(amount):
                    lookup[(nbits,code)]=values[v];v+=1;code+=1
                code<<=1
            tables[(flag>>4,flag&15)]=lookup
    needed=((0,0),(1,0),(0,1),(1,1))
    if any(key not in tables for key in needed):
        raise TexError('JPEG Huffman-Tabellen nicht verfügbar')
    return tables


_TABLES=None
_DCT=None


def _dct():
    global _DCT
    if _DCT is None:
        _DCT=np.array([[((.125)**.5 if k==0 else .5)*math.cos((2*n+1)*k*math.pi/16)
                        for n in range(8)] for k in range(8)],dtype=np.float32)
    return _DCT


def _zigzag():
    idx=[0]*64;n=i=j=0;direction=1
    while n<64:
        idx[i+j*8]=n
        i+=direction;j-=direction
        if direction>0:
            if i>=8:i=7;j+=2;direction=-1
            elif j<0:j=0;direction=-1
        else:
            if j>=8:j=7;i+=2;direction=1
            elif i<0:i=0;direction=1
        n+=1
    return idx


_ZIG=_zigzag()

class _Bits:
    def __init__(self,data):
        self.data=data
        self.pos=0
        self.total=len(data)*8
    def read(self,n):
        if self.pos+n>self.total:
            raise TexError('WildStar JPEG-Datenstrom abgeschnitten')
        out=0
        for _ in range(n):
            out=(out<<1)|((self.data[self.pos>>3]>>(7-(self.pos&7)))&1)
            self.pos+=1
        return out
    def huff(self,table):
        value=0
        for length in range(1,17):
            value=(value<<1)|self.read(1)
            result=table.get((length,value))
            if result is not None:return result
        raise TexError('Ungültiger WildStar-JPEG-Huffman-Code')


def _signed_value(b,n):
    if n==0:return 0
    return b if b>=(1<<(n-1)) else b-(1<<n)+1


def _decode_8x8(bits,dc,ac,prev):
    out=np.zeros(64,dtype=np.int32)
    size=bits.huff(dc)
    delta=_signed_value(bits.read(size),size)
    out[0]=prev+delta
    i=1
    while i<64:
        sym=bits.huff(ac)
        if sym==0:break
        if sym==0xf0:
            i+=16;continue
        i+=(sym>>4)
        size=sym&15
        if i>=64:raise TexError('JPEG AC-Werte außerhalb des Blocks')
        out[i]=_signed_value(bits.read(size),size)
        i+=1
    return out[_ZIG],int(out[0])


def _decode_jpg(b,h,mip,w,hh):
    if h['kind'] not in (0,1,2):raise TexError('Unbekanntes TEX-JPEG-Format')
    total=h['jpg_mips']
    if total<1 or total>13:raise TexError('JPEG-Mip-Zähler ungültig')
    size=h['sizes'][mip];offset=112+sum(h['sizes'][:mip])
    if size>MAX_BYTES or offset+size>len(b):raise TexError('JPEG-Mip außerhalb der Datei')
    data=b[offset:offset+size];kind=h['kind'];block=16 if kind==0 else 8
    cw=(w+block-1)//block*block;ch=(hh+block-1)//block*block
    across,down=cw//8,ch//8
    count=across*down
    luma=[True,kind==1,kind==1,True]
    defaults=[c[2] if c[1] else None for c in h['channels']]
    tables=_jpeg_tables()
    stream=_Bits(data)
    nper=[count//4 if kind==0 and i in (1,2) else count for i in range(4)]
    coeff=[np.zeros((n,64),dtype=np.int32) for n in nper]
    pred=[0]*4
    def one(channel,index):
        if defaults[channel] is not None:return
        dc=tables[(0,0 if luma[channel] else 1)]
        ac=tables[(1,0 if luma[channel] else 1)]
        raw,pred[channel]=_decode_8x8(stream,dc,ac,pred[channel])
        coeff[channel][index]=raw
    if kind==0:
        if across%2 or down%2:raise TexError('Ungültiges 4:2:0 MCU-Layout')
        for my in range(down//2):
            for mx in range(across//2):
                start=my*2*across+mx*2
                for q in (start,start+1,start+across,start+across+1):one(0,q)
                one(1,my*(across//2)+mx)
                one(2,my*(across//2)+mx)
                for q in (start,start+1,start+across,start+across+1):one(3,q)
    else:
        for k in range(count):
            for channel in range(4):one(channel,k)
    baseqt=Image.open(BytesIO(_base_jpeg())).quantization
    matrix=_dct()
    planes=[]
    for channel in range(4):
        default=defaults[channel]
        if default is not None:
            planes.append(np.full((hh,w),default,dtype=np.int32))
            continue
        qbase=np.array(baseqt[0 if luma[channel] else 1],dtype=np.float32)
        quality=h['channels'][channel][0]
        qt=np.clip(qbase*((200-quality*2)*.01),1,255)
        c=np.trunc(coeff[channel].astype(np.float32)*qt).reshape(-1,8,8)
        pixels=np.rint(matrix.T @ c @ matrix).astype(np.int32)
        pixels=np.clip(pixels+(128 if luma[channel] else 0),0 if luma[channel] else -256,255)
        if kind==0 and channel in (1,2):
            px=pixels.reshape(down//2,across//2,8,8).transpose(0,2,1,3).reshape(ch//2,cw//2)
            px=px.repeat(2,0).repeat(2,1)
        else:
            px=pixels.reshape(down,across,8,8).transpose(0,2,1,3).reshape(ch,cw)
        planes.append(px[:hh,:w])
    p1,p2,p3,p4=planes
    if kind==1:
        r=np.clip(p4,0,255);g=np.clip(p2,0,255);blue=np.clip(p3,0,255);alpha=np.clip(p1,0,255)
    else:
        r1=p1-(p3>>1)
        g=np.clip(r1+p3,0,255)
        blue=np.clip(r1-(p2>>1),0,255)
        r=np.clip(blue+p2,0,255)
        alpha=np.clip(p4,0,255)
    return Image.fromarray(np.stack([r,g,blue,alpha],axis=-1).astype(np.uint8),'RGBA')

_BASE_JPEG=None

def _base_jpeg():
    global _BASE_JPEG
    if _BASE_JPEG is None:
        out=BytesIO();Image.new('RGB',(16,16),(10,20,30)).save(out,'JPEG',quality=50,subsampling=0)
        _BASE_JPEG=out.getvalue()
    return _BASE_JPEG


def decode(data: bytes,max_size:int=1024)->Image.Image:
    h=header(data)
    if h['sides']>1 or h['depth']>1:
        raise TexError('Cubemap/3D-LUT: Diese Vorschau unterstützt nur normale 2D-Texturen')
    if h['jpg']:
        mip,w,hh=_choose(h,h['jpg_mips'],max_size)
        return _decode_jpg(data,h,mip,w,hh)
    mip,w,hh=_choose(h,h['mips'],max_size)
    fmt=h['fmt'];sizes=[]
    for i in range(h['mips']):
        mw,mh=_dims(h,i,h['mips'])
        if fmt in (13,14,15):sizes.append(max(1,(mw+3)//4)*max(1,(mh+3)//4)*(8 if fmt==13 else 16))
        elif fmt in (0,1,5,6):sizes.append(mw*mh*{0:4,1:4,5:2,6:1}[fmt])
        else:raise TexError(f'Nicht unterstütztes WildStar-TEX-Format: {fmt}')
    offset=112+sum(sizes[:mip]);size=sizes[mip]
    if size>MAX_BYTES or offset+size>len(data):raise TexError('TEX-Mip abgeschnitten')
    chunk=data[offset:offset+size]
    if fmt in (13,14,15):return _dds_image(chunk,w,hh,fmt)
    if fmt in (0,1):return Image.frombytes('RGBA',(w,hh),chunk,'raw','BGRA')
    if fmt==5:
        px=np.frombuffer(chunk,dtype='<u2').reshape(hh,w).astype(np.uint32)
        rgb=np.stack([((px>>11)&31)*255//31,((px>>5)&63)*255//63,(px&31)*255//31,np.full_like(px,255)],axis=-1)
        return Image.fromarray(rgb.astype(np.uint8),'RGBA')
    raw=np.frombuffer(chunk,dtype=np.uint8).reshape(hh,w)
    return Image.fromarray(np.stack([raw,raw,raw,np.full_like(raw,255)],-1),'RGBA')


def decode_png(data:bytes,max_size:int=1024)->bytes:
    out=BytesIO();decode(data,max_size).save(out,'PNG',optimize=False);return out.getvalue()
