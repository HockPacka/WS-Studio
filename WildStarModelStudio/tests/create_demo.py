"""Create tiny, synthetic models to test the viewer without proprietary assets."""
from pathlib import Path
import math
import struct

ROOT = Path(__file__).resolve().parents[1]
DEMO = ROOT / 'demo'
DEMO.mkdir(exist_ok=True)

def align16(x): return (x + 15) & ~15

def oct_encode(x,y,z):
    d=abs(x)+abs(y)+abs(z) or 1
    x/=d; y/=d; z/=d
    if z<0:
        x,y=(1-abs(y))*(1 if x>=0 else -1),(1-abs(x))*(1 if y>=0 else -1)
    return max(0,min(255,round((x+1)*127.5))),max(0,min(255,round((y+1)*127.5)))

def make_crystal(scale,x=0,y=0,z=0):
    points=[(x+0*scale,y+2.1*scale+z*0,z),
        (x-0.7*scale,y+0.55*scale,z-0.7*scale),
        (x+0.7*scale,y+0.55*scale,z-0.7*scale),
        (x+0.7*scale,y+0.55*scale,z+0.7*scale),
        (x-0.7*scale,y+0.55*scale,z+0.7*scale),
        (x-0.45*scale,y-0.45*scale,z-0.45*scale),
        (x+0.45*scale,y-0.45*scale,z-0.45*scale),
        (x+0.45*scale,y-0.45*scale,z+0.45*scale),
        (x-0.45*scale,y-0.45*scale,z+0.45*scale),
        (x,y-1.1*scale,z)]
    indices=[]
    for i in range(4):
        j=(i+1)%4
        indices.extend([0,1+i,1+j,1+i,5+i,5+j,1+i,5+j,1+j,5+i,9,5+j])
    # Demo deliberately faceted; normals are only approximate.
    normals=[]
    for vx,vy,vz in points:
        dx,dy,dz=vx-x,vy-y,vz-z
        norm=math.hypot(dx,dy,dz) or 1
        normals.append((dx/norm,dy/norm,dz/norm))
    return points,normals,indices


def create_m3():
    geometries=[make_crystal(1.0,0,0,0), make_crystal(.6,2.1,-.5,.5),make_crystal(.38,-1.8,-.6,.3)]
    verts=[]; inds=[]; meshrecs=[]
    for n,(p,normal,idx) in enumerate(geometries):
        startv=len(verts); starti=len(inds)
        verts.extend((pos,nn) for pos,nn in zip(p,normal));inds.extend(idx)
        meshrecs.append((starti,startv,len(idx),len(p),n))
    b=bytearray(0x630)
    b[:4]=b'LDOM';struct.pack_into('<I',b,4,100)
    struct.pack_into('<QQ',b,0x250,1,0)
    header=0x630
    geo=bytearray(0xc8)
    struct.pack_into('<IHH',geo,0x18,len(verts),14,0)
    geo[0x20]=1;geo[0x22]=3   # float3 position, oct2 normal
    struct.pack_into('<I',geo,0x68,len(inds))
    b.extend(geo)
    b.extend(b'\x00'*(align16(len(b))-len(b)))
    base=len(b)
    struct.pack_into('<QQ',b,header+0x38, len(verts)*14, len(b)-base)
    for pos,normal in verts:
        b.extend(struct.pack('<3f',*pos));b.extend(bytes(oct_encode(*normal)))
    b.extend(b'\x00'*(align16(len(b))-len(b)))
    struct.pack_into('<QQ',b,header+0x70,len(inds)*2,len(b)-base)
    b.extend(struct.pack('<'+'H'*len(inds),*inds))
    b.extend(b'\x00'*(align16(len(b))-len(b)))
    struct.pack_into('<QQ',b,header+0x80,len(meshrecs),len(b)-base)
    for s,v,ni,nv,material in meshrecs:
        r=bytearray(0x70)
        struct.pack_into('<4I',r,0,s,v,ni,nv)
        struct.pack_into('<H',r,0x16,material)
        r[0x1e]=0;r[0x22]=0
        b.extend(r)
    (DEMO/'Crystal.m3').write_bytes(b)


def create_i3():
    p,n,idx=make_crystal(.75)
    b=bytearray(0x1b0)
    b[:4]=b'FEDS';struct.pack_into('<I',b,4,30)
    def add(co,blob,stride):
        off=len(b)-0x1b0
        struct.pack_into('<I4xQ',b,co,len(blob)//stride,off)
        b.extend(blob)
        b.extend(b'\x00'*(align16(len(b))-len(b)))
    add(0x38,b''.join(struct.pack('<3f',*pos) for pos in p),12)
    attrs=[]
    for nn in n:
        a,c=oct_encode(*nn);r=bytearray(20);r[5]=c;r[6]=a;struct.pack_into('<4e',r,8,0,0,0,0);r[16:20]=b'\xff\xff\xff\xff';attrs.append(bytes(r))
    add(0x48,b''.join(attrs),20)
    add(0x58,struct.pack('<'+'I'*len(idx),*idx),4)
    add(0x78,struct.pack('<7I',0,0,len(idx)-1,0,len(p)-1,0x100,0),28)
    (DEMO/'Crystal.Sector_Exterior.i3').write_bytes(b)

if __name__=='__main__':
    create_m3();create_i3();print('Created demo models:',*(str(x) for x in DEMO.iterdir()))

def create_fedi():
    b=bytearray(0x170);b[:4]=b'FEDI';struct.pack_into('<I',b,4,41)
    def add(offset,blob,stride):
        struct.pack_into('<I4xQ',b,offset,len(blob)//stride,len(b)-0x170)
        b.extend(blob)
        b.extend(b'\0'*(align16(len(b))-len(b)))
    add(0x120,'Sector_Exterior\0'.encode('utf-16le'),2)
    add(0x130,struct.pack('<I',0),4)
    add(0x20,struct.pack('<I',0)+b'\0'*60,0x40)
    (DEMO/'Crystal.i3').write_bytes(b)


def create_area():
    # 256 terrain cells, low smooth heights, no proprietary textures.
    cells=bytearray()
    for cy in range(16):
        for cx in range(16):
            heights=[]
            for ly in range(19):
                for lx in range(19):
                    gx=cx*16+lx-1;gy=cy*16+ly-1
                    height=3*math.sin(gx/23)+2*math.cos(gy/35)
                    heights.append(int(round((2048+height)*8)))
            chunk=struct.pack('<I',1)+struct.pack('<361H',*heights)
            cells.extend(struct.pack('<I',len(chunk)))
            cells.extend(chunk)
    b=b'area'+struct.pack('<I',0)+b'KNHC'+struct.pack('<I',len(cells))+cells
    (DEMO/'Hills.area').write_bytes(b)

if __name__=='__main__':
    create_fedi()
    create_area()
    print('Created additional FEDI and AREA demos')
