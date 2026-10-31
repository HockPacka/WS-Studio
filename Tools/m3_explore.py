import sys,struct
sys.path.insert(0,'tools/Halon'); sys.path.insert(0,'tools')
import halon
from validate_formats import inflate, a16
fs=halon.Filesystem('WildStar/Patch/ClientData')
def get(path):
    f=fs[path]; i,_=fs.data.blocks[f.sha1]; o,bs=fs.data.fs[i]
    with open(fs.data.name,'rb') as a: a.seek(o); return inflate(f,a.read(bs))
if __name__=='__main__':
    path=sys.argv[1]; b=get(path); H=0x630
    print(path,len(b))
    bc,bo=struct.unpack_from('<QQ',b,0x180); ba=bo+H
    BB=a16(ba+bc*0x160); print('bones',bc,'base',hex(BB),'size',len(b))
    for i in range(min(bc,int(sys.argv[2]) if len(sys.argv)>2 else 3)):
        o=ba+i*0x160
        print('bone',i,'parent',struct.unpack_from('<h',b,o+4)[0],'u0',struct.unpack_from('<I',b,o)[0],'u8',b[o+8:o+12].hex())
        for j in range(8):
            c,k,v=struct.unpack_from('<QQQ',b,o+0x10+j*24)
            print('  DP%d count=%d key=0x%x val=0x%x'%(j,c,k,v), end='')
            if c:
                ka=k+BB; va=v+BB
                print('  keys',struct.unpack_from('<%dI'%min(c,6),b,ka) if ka+4*min(c,6)<=len(b) else '?', 'vals', b[va:va+32].hex())
            else: print()
