/* WildStar M3 LDOM v100 extended binary parser for Model Studio.
   Native, dependency-free C ABI; library has no network, filesystem or SDK dependencies.
   Parsing layout derived from HockPacka/WS-Tools M3Reader.cpp / m3_format_spec.md.
   Exposes semantic metadata and animation/keyframe data for future renderer use.
   Compile Windows: clang -target x86_64-pc-windows-msvc -ffreestanding -fno-builtin
   -fno-stack-protector -O2 -c ws_m3_parser.c (link with kernel32 import library).
*/
#include "ws_m3_parser.h"
#ifdef _WIN32
int _fltused = 0; /* MSVC target without a CRT */
__declspec(dllimport) void* __stdcall GetProcessHeap(void);
__declspec(dllimport) void* __stdcall HeapAlloc(void*, unsigned long, size_t);
__declspec(dllimport) void* __stdcall HeapReAlloc(void*, unsigned long, void*, size_t);
__declspec(dllimport) int __stdcall HeapFree(void*, unsigned long, void*);
static void *mem_alloc(size_t n) { return HeapAlloc(GetProcessHeap(), 0, n?n:1); }
static void *mem_realloc(void *p, size_t n) { return p ? HeapReAlloc(GetProcessHeap(), 0, p, n?n:1) : mem_alloc(n); }
void ws_m3_free(void *p) { if(p) HeapFree(GetProcessHeap(), 0, p); }
#else
#include <stdlib.h>
static void *mem_alloc(size_t n) { return malloc(n?n:1); }
static void *mem_realloc(void *p, size_t n) { return realloc(p, n?n:1); }
void ws_m3_free(void *p) { free(p); }
#endif
uint32_t ws_m3_abi_version(void) { return 2; }

typedef struct { char *p; size_t len, cap; int failed; } Writer;
typedef struct { const unsigned char *p; size_t size; } Reader;
static void copy_bytes(void *dst, const void *src, size_t n) { unsigned char *d=(unsigned char*)dst; const unsigned char *s=(const unsigned char*)src; size_t i; for(i=0;i<n;i++) d[i]=s[i]; }
static size_t strlen_local(const char *s) { size_t n=0; if(!s)return 0; while(s[n] && n<65536)n++;return n; }
static char *make_string(const char *s) { size_t n=strlen_local(s); char *v=(char*)mem_alloc(n+1); if(v){copy_bytes(v,s,n);v[n]=0;}return v; }
static int span(const Reader *r, uint64_t off, uint64_t n) { return off <= r->size && n <= r->size-off; }
static uint64_t rd(const Reader *r, uint64_t off, unsigned n) { uint64_t x=0; unsigned i; if(!span(r,off,n))return 0; for(i=0;i<n;i++) x|=((uint64_t)r->p[off+i])<<(i*8);return x; }
static float flt(const Reader *r, uint64_t off) { union { uint32_t u;float f; } x; x.u=(uint32_t)rd(r,off,4);return x.f; }
static int okfloat(float x) { return x==x && x<1.0e8f && x>-1.0e8f; }
static uint64_t a16(uint64_t x) { return (x+15U)&~15ULL; }
static int ap(const Reader *r, uint64_t at, uint64_t base, uint64_t stride, uint64_t *count, uint64_t *pos) {
    uint64_t n,o; if(!span(r,at,16))return 0;
    n=rd(r,at,8);o=rd(r,at+8,8);
    if(n>20000000 || base>r->size || o>r->size-base)return 0;
    if(stride && n>(uint64_t)r->size/stride)return 0;
    *pos=base+o;*count=n;
    return span(r,*pos,n*stride);
}
static void ensure(Writer *w,size_t extra) { size_t need,cap;char *p;
    if(w->failed)return;
    if(extra > 512ULL*1024*1024 || w->len>512ULL*1024*1024-extra){w->failed=1;return;}
    need=w->len+extra+1;if(need<=w->cap)return;
    cap=w->cap?w->cap:1024;
    while(cap<need){if(cap>(512ULL*1024*1024)/2){cap=need;break;}cap*=2;}
    p=(char*)mem_realloc(w->p,cap);if(!p){w->failed=1;return;}w->p=p;w->cap=cap;
}
static void putc_w(Writer *w,char c) {ensure(w,1);if(!w->failed){w->p[w->len++]=c;w->p[w->len]=0;}}
static void puts_w(Writer *w,const char *s) {size_t n=strlen_local(s);ensure(w,n);if(!w->failed){copy_bytes(w->p+w->len,s,n);w->len+=n;w->p[w->len]=0;}}
static void number(Writer *w,uint64_t v) {char tmp[32];int n=0;do{tmp[n++]=(char)('0'+v%10);v/=10;}while(v&&n<31);while(n)putc_w(w,tmp[--n]);}
static void json_str(Writer *w,const char *s) {size_t i,n=strlen_local(s);putc_w(w,'"');for(i=0;i<n;i++){
    unsigned c=(unsigned char)s[i];if(c=='"'||c=='\\'){putc_w(w,'\\');putc_w(w,(char)c);} else if(c<32){puts_w(w,"\\u00");putc_w(w,"0123456789abcdef"[(c>>4)&15]);putc_w(w,"0123456789abcdef"[c&15]);}else putc_w(w,(char)c);
}putc_w(w,'"');}
static void dec_float(Writer *w,float value) {
    /* Six fixed decimal digits preserve UVs and animation samples; avoid CRT. */
    uint64_t integer,frac; if(!okfloat(value)){putc_w(w,'0');return;}
    if(value<0){putc_w(w,'-');value=-value;}integer=(uint64_t)value;
    frac=(uint64_t)((value-(float)integer)*1000000.0f+0.5f);
    if(frac>=1000000){integer++;frac=0;}number(w,integer);putc_w(w,'.');
    for(int k=100000;k;k/=10)putc_w(w,(char)('0'+(frac/(uint64_t)k)%10));
}
static void signed_number(Writer *w,int64_t v) {if(v<0){putc_w(w,'-');number(w,(uint64_t)(-(v+1))+1);}else number(w,(uint64_t)v);}
static void float_array(Writer *w,const Reader *r,uint64_t pos,size_t n) {
    putc_w(w,'[');for(size_t i=0;i<n;i++){if(i)putc_w(w,',');dec_float(w,flt(r,pos+i*4));}putc_w(w,']');
}
static void hex_bytes(Writer *w,const Reader *r,uint64_t pos,size_t n) {
    const char *digits="0123456789abcdef";putc_w(w,'"');
    for(size_t i=0;i<n&&span(r,pos+i,1);i++){unsigned v=r->p[pos+i];putc_w(w,digits[v>>4]);putc_w(w,digits[v&15]);}
    putc_w(w,'"');
}

static const char kB64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static void base64(Writer *w,const void *v,size_t n) {const unsigned char *p=(const unsigned char*)v;size_t i;ensure(w,((n+2)/3)*4);if(w->failed)return;
    for(i=0;i<n;i+=3){unsigned a=p[i],b=i+1<n?p[i+1]:0,c=i+2<n?p[i+2]:0;
      putc_w(w,kB64[a>>2]);putc_w(w,kB64[((a&3)<<4)|(b>>4)]);
      putc_w(w,i+1<n?kB64[((b&15)<<2)|(c>>6)]:'=');putc_w(w,i+2<n?kB64[c&63]:'=');
    }
}
static void append_utf16(Writer *w,const Reader *r,uint64_t off,uint64_t count) {
    uint64_t i;putc_w(w,'"');if(count>2048||!span(r,off,count*2)){putc_w(w,'"');return;}
    for(i=0;i<count;i++){unsigned cp=(unsigned)rd(r,off+i*2,2);if(!cp)break;
        if(cp>=0xD800&&cp<=0xDBFF&&i+1<count){unsigned low=(unsigned)rd(r,off+(i+1)*2,2);if(low>=0xDC00&&low<=0xDFFF){cp=0x10000+((cp-0xD800)<<10)+(low-0xDC00);i++;}}
        if(cp=='"'||cp=='\\'){putc_w(w,'\\');putc_w(w,(char)cp);}else if(cp<32){putc_w(w,'_');}else if(cp<0x80){putc_w(w,(char)cp);}
        else if(cp<0x800){putc_w(w,(char)(0xC0|(cp>>6)));putc_w(w,(char)(0x80|(cp&63)));}
        else if(cp<0x10000){putc_w(w,(char)(0xE0|(cp>>12)));putc_w(w,(char)(0x80|((cp>>6)&63)));putc_w(w,(char)(0x80|(cp&63)));}
        else if(cp<0x110000){putc_w(w,(char)(0xF0|(cp>>18)));putc_w(w,(char)(0x80|((cp>>12)&63)));putc_w(w,(char)(0x80|((cp>>6)&63)));putc_w(w,(char)(0x80|(cp&63)));}
    }
    putc_w(w,'"');
}
static float abs_f(float x){return x<0?-x:x;}
static float sqrt_f(float v){float x;int k;if(v<=0)return 1.0f;x=v>1?v:1.0f;for(k=0;k<15;k++)x=.5f*(x+v/x);return x;}
static void oct_normal(unsigned a,unsigned b,float *xyz) {
    float x=(float)a/255.0f*2-1,y=(float)b/255.0f*2-1,z=1-abs_f(x)-abs_f(y),t,n;
    if(z<0){t=x;x=(1-abs_f(y))*(x>=0?1:-1);y=(1-abs_f(t))*(y>=0?1:-1);}
    n=sqrt_f(x*x+y*y+z*z);xyz[0]=x/n;xyz[1]=y/n;xyz[2]=z/n;
}
static int vertex_layout(const Reader *r,uint64_t g,int *posType,int offsets[11],uint32_t *stride) {
    uint64_t off=0;
    *posType=(int)rd(r,g+0x20,1);
    for(int i=0;i<11;i++){
        int t=(int)rd(r,g+0x20+i,1),width=0;offsets[i]=-1;
        if(i==0){if(t==1)width=12;else if(t==2)width=6;else return 0;}
        else if(i<=3){if(t==3)width=2;else if(t)return 0;}
        else if(i<=7){if(t==4)width=4;else if(t)return 0;}
        else if(i<=9){if(t==5)width=4;else if(t)return 0;}
        else {if(t==6)width=1;else if(t)return 0;}
        if(width)offsets[i]=(int)off;
        off+=(unsigned)width;
    }
    *stride=(uint32_t)off;
    return off!=0;
}
static float half_float(uint16_t h) {
    /* IEEE-754 half to float, with NaN/Inf returned as 0 for JSON-safety. */
    union {uint32_t u;float f;} x;uint32_t s=(uint32_t)(h&0x8000)<<16,e=(h>>10)&31,m=h&1023;
    if(e==31){x.u=0;return x.f;}
    if(e==0){if(!m){x.u=s;return x.f;}int exponent=-14;while((m&1024)==0){m<<=1;exponent--;}m&=1023;x.u=s|((uint32_t)(exponent+127)<<23)|(m<<13);}
    else x.u=s|((e+112)<<23)|(m<<13);
    return x.f;
}
static void output_array_as_b64(Writer *w,const void *ptr,size_t byte_count,const char *name){
    puts_w(w,",\"");puts_w(w,name);puts_w(w,"\":\"");base64(w,ptr,byte_count);putc_w(w,'"');
}

static void bounds_add(float *bd,float x,float y,float z) {float v[3];int i;v[0]=x;v[1]=y;v[2]=z;for(i=0;i<3;i++){if(v[i]<bd[i])bd[i]=v[i];if(v[i]>bd[i+3])bd[i+3]=v[i];}}
/* The native file is a relocatable data tree. Unknown payloads are *not*
 * reinterpreted as supported semantics: their descriptor/raw values are
 * surfaced separately for future reverse engineering. */
static int track_descriptor(const Reader *r,uint64_t at,uint64_t base,uint32_t width,
                            uint64_t *count,uint64_t *k,uint64_t *v) {
    uint64_t n,ko,vo;
    if(!span(r,at,24))return 0;
    n=rd(r,at,8);ko=rd(r,at+8,8);vo=rd(r,at+16,8);
    if(n>200000||n>r->size/4||(width&&n>r->size/width))return 0;
    if(base>r->size||ko>r->size-base||vo>r->size-base)return 0;
    if(!span(r,base+ko,n*4)||!span(r,base+vo,n*width))return 0;
    *count=n;*k=base+ko;*v=base+vo;return 1;
}
/* vals are packed little endian IEEE754 float32, times packed uint32. */
static void write_track(Writer *w,const Reader *r,uint64_t at,uint64_t base,int kind,int components) {
    uint64_t n,k,v;uint32_t width=(uint32_t)(kind==0?components*2:kind==1?components*2:components*4);
    if(!track_descriptor(r,at,base,width,&n,&k,&v)){puts_w(w,"null");return;}
    puts_w(w,"{\"count\":");number(w,n);puts_w(w,",\"components\":");number(w,(uint64_t)components);
    puts_w(w,",\"times\":\"");base64(w,r->p+k,(size_t)n*4);
    puts_w(w,"\",\"values\":\"");
    if(n){
        float *f=(float*)mem_alloc((size_t)n*(size_t)components*4);
        if(!f){w->failed=1;return;}
        for(uint64_t i=0;i<n;i++)for(int j=0;j<components;j++){
            uint64_t off=v+i*width+(uint64_t)j*(kind==2?4:2);
            f[i*(uint64_t)components+(unsigned)j]=kind==0?half_float((uint16_t)rd(r,off,2)):
                  kind==1?(float)(int16_t)rd(r,off,2)/16384.0f:flt(r,off);
        }
        base64(w,f,(size_t)n*components*4);ws_m3_free(f);
    }
    puts_w(w,"\"}");
}
static void write_bones(Writer *w,const Reader *r,uint64_t count,uint64_t ba) {
    static const char *names[]={"scale","scaleSecondary","parentScale","parentScaleSecondary",
         "rotation","rotationSecondary","translation","translationSecondary"};
    uint64_t base=a16(ba+count*0x160);
    puts_w(w,",\"bones\":[");
    for(uint64_t i=0;i<count;i++){
        uint64_t at=ba+i*0x160;
        if(i)putc_w(w,',');puts_w(w,"{\"index\":");number(w,i);
        puts_w(w,",\"modelBoneId\":");number(w,rd(r,at,2));
        puts_w(w,",\"parent\":");signed_number(w,(int16_t)rd(r,at+4,2));
        puts_w(w,",\"depth\":");number(w,rd(r,at+6,2));
        puts_w(w,",\"hash\":");number(w,rd(r,at+8,4));
        puts_w(w,",\"bindWorld\":");float_array(w,r,at+0xd0,16);
        puts_w(w,",\"inverseBind\":");float_array(w,r,at+0x110,16);
        puts_w(w,",\"pivot\":");float_array(w,r,at+0x150,3);
        puts_w(w,",\"tracks\":{");
        for(int t=0;t<8;t++){
            if(t)putc_w(w,',');json_str(w,names[t]);putc_w(w,':');
            write_track(w,r,at+0x10+(uint64_t)t*24,base,t<4?0:t<6?1:2,t<4?3:t<6?4:3);
        }
        puts_w(w,"}}");if(w->failed)return;
    }
    putc_w(w,']');
}
static void write_materials(Writer *w,const Reader *r,uint64_t count,uint64_t ma) {
    static const char *parameters[]={"shaderValue","gloss","glow","opacity","height","raw0x90","heightScale",
                         "heightOffset","parallaxScale","parallaxOffset","colorMod"};
    static const unsigned offsets[]={0x18,0x30,0x48,0x60,0x78,0x90,0xA8,0xC0,0xD8,0xF0,0x108};
    uint64_t db=a16(ma+count*0x30);
    puts_w(w,",\"materialData\":[");
    for(uint64_t i=0;i<count;i++){
        uint64_t at=ma+i*0x30,n=rd(r,at+0x20,8),off=rd(r,at+0x28,8),d,nested;
        if(i)putc_w(w,',');puts_w(w,"{\"index\":");number(w,i);puts_w(w,",\"headerHex\":");hex_bytes(w,r,at,32);
        if(n>4||db>r->size||off>r->size-db||!span(r,db+off,n*0x128)){
            puts_w(w,",\"layers\":[],\"error\":\"invalid material layer pointer\"}");continue;
        }
        nested=a16(db+off+n*0x128);
        puts_w(w,",\"layers\":[");
        for(d=0;d<n;d++){
            uint64_t at2=db+off+d*0x128;
            if(d)putc_w(w,',');puts_w(w,"{\"colorTexture\":");number(w,rd(r,at2,2));
            puts_w(w,",\"normalTexture\":");number(w,rd(r,at2+2,2));
            puts_w(w,",\"layerClass\":");number(w,rd(r,at2+0x120,4));
            puts_w(w,",\"materialType\":");number(w,rd(r,at2+0x124,4));
            puts_w(w,",\"words\":[");for(int j=0;j<5;j++){if(j)putc_w(w,',');number(w,rd(r,at2+4+j*4,4));}putc_w(w,']');
            puts_w(w,",\"parameters\":{");
            for(int j=0;j<11;j++){
                uint64_t kn,vn,nn;int components=j==10?3:1;
                if(j)putc_w(w,',');json_str(w,parameters[j]);putc_w(w,':');
                if(!track_descriptor(r,at2+offsets[j],nested,4*(uint32_t)components,&nn,&kn,&vn)||nn>4096){puts_w(w,"null");continue;}
                puts_w(w,"{\"count\":");number(w,nn);puts_w(w,",\"times\":\"");base64(w,r->p+kn,(size_t)nn*4);
                puts_w(w,"\",\"values\":\"");base64(w,r->p+vn,(size_t)nn*components*4);puts_w(w,"\"}");
            }
            puts_w(w,"}}");
        }
        puts_w(w,"]}");if(w->failed)return;
    }
    putc_w(w,']');
}
static int em_property(const Reader *r,uint64_t tpl,uint64_t nested,int i,uint32_t width,uint64_t *addr) {
    uint64_t p=tpl+0x68+(uint64_t)i*24,n=rd(r,p,4),o=rd(r,p+16,8);
    if(!n||n>200000||nested>r->size||o>r->size-nested||!span(r,nested+o,width))return 0;
    *addr=nested+o;return 1;
}
static void emitter_template(Writer *w,const Reader *r,uint64_t rec,uint64_t base) {
    uint32_t type=(uint32_t)rd(r,rec+4,4);
    uint64_t offset=rd(r,rec+(type==1?0x98:0x90),8);
    uint64_t bytes=type==1?0x4b0:0xed0;
    if(type>1||base>r->size||offset>r->size-base||!span(r,base+offset,bytes)){
        puts_w(w,",\"template\":null");return;
    }
    uint64_t t=base+offset,nested=t+bytes;
    puts_w(w,",\"template\":{\"kind\":");json_str(w,type?"ribbon":"particle");
    puts_w(w,",\"rawHeaderHex\":");hex_bytes(w,r,t,48);
    if(type==0){
        puts_w(w,",\"texture0\":");number(w,rd(r,t+0x978,2));
        puts_w(w,",\"texture1\":");number(w,rd(r,t+0x994,2));
        puts_w(w,",\"shape\":");number(w,rd(r,t+8,2));
        puts_w(w,",\"shapeFlags\":");number(w,rd(r,t+10,1));
        puts_w(w,",\"templateFlags\":");number(w,rd(r,t+0xec8,4));
        puts_w(w,",\"flipbookCols\":");number(w,rd(r,t+0xe78,4));
        puts_w(w,",\"flipbookSpeed\":");dec_float(w,flt(r,t+0xe7c));
        puts_w(w,",\"flipbookRowShift\":");number(w,rd(r,t+0xe84,4));
        puts_w(w,",\"flipbookFrames\":");number(w,rd(r,t+0xe8c,4));
        uint64_t length=rd(r,t+0xeb8,4),pathOffset=rd(r,t+0xec0,8);
        if(length&&length<2048&&nested<=r->size&&pathOffset<=r->size-nested&&span(r,nested+pathOffset,length*2)){
            puts_w(w,",\"childModel\":");append_utf16(w,r,nested+pathOffset,length);
        }
        /* Confirmed in WS-Tools: the first two particles are u16 spawn counts,
         * intervals/lifetimes i32 ms, direction/speed and sizes are half-floats. */
        static const char *names[]={"spawnMin","spawnMax","intervalMinMs","intervalMaxMs",
            "activeMin","activeMax","lifeMinMs","lifeMaxMs","directionMin","directionMax",
            "speedMin","speedMax","acceleration","spinMin","spinMax","spinSpeedMin",
            "spinSpeedMax","yawMin","yawMax","scaleMin","scaleMax","maxParticles","localOffset"};
        static const int widths[]={2,2,4,4,2,2,4,4,6,6,2,2,6,2,2,2,2,2,2,2,2,4,12};
        puts_w(w,",\"properties\":{");
        for(int i=0;i<23;i++){
            uint64_t a;
            if(i)putc_w(w,',');json_str(w,names[i]);putc_w(w,':');
            if(!em_property(r,t,nested,i,widths[i],&a)){puts_w(w,"null");continue;}
            if(i==8||i==9||i==12){putc_w(w,'[');for(int j=0;j<3;j++){if(j)putc_w(w,',');dec_float(w,half_float((uint16_t)rd(r,a+j*2,2)));}putc_w(w,']');}
            else if(i==22){float_array(w,r,a,3);}
            else if(i==0||i==1)number(w,rd(r,a,2));
            else if(i==2||i==3||i==6||i==7||i==21)signed_number(w,(int32_t)rd(r,a,4));
            else dec_float(w,half_float((uint16_t)rd(r,a,2)));
        }
        putc_w(w,'}');
    }else{
        puts_w(w,",\"texture\":");number(w,rd(r,t+0x3c4,2));
        puts_w(w,",\"mode\":");number(w,rd(r,t,1));
        puts_w(w,",\"segmentIntervalMs\":");number(w,rd(r,t+2,2));
        puts_w(w,",\"edgeLifetimeMs\":");number(w,rd(r,t+0x26,2));
        puts_w(w,",\"templateFlags\":");number(w,rd(r,t+0x28,4));
        puts_w(w,",\"colorGain\":");dec_float(w,flt(r,t+0x44));
        puts_w(w,",\"colorStops\":");number(w,rd(r,t+0x48,2));
        puts_w(w,",\"alphaStops\":");number(w,rd(r,t+0x1b8,2));
        puts_w(w,",\"widthStops\":");number(w,rd(r,t+0x2b0,2));
    }
    putc_w(w,'}');
}
static void write_small_tables(Writer *w,const Reader *r) {
    static const struct {const char *name;uint16_t slot;uint16_t stride;} tables[]={
        {"meshDisplay",0x200,4},{"soundEmitters",0x2b8,0x28},
        {"soundEventIds",0x2c8,8},{"stateAnimations",0x4a0,4},
        {"faceCustomization",0x598,0x4c},{"faceCustomizationLookup",0x5a8,2},
        {"collisionHullVertices",0x510,0x10},{"collisionHullIndices0",0x520,4},{"collisionHullIndices1",0x530,4}
    };
    puts_w(w,",\"auxiliaryTables\":{");
    for(size_t q=0;q<sizeof(tables)/sizeof(tables[0]);q++) {
        uint64_t n=0,a=0;uint16_t stride=tables[q].stride;
        if(q)putc_w(w,',');json_str(w,tables[q].name);putc_w(w,':');
        if(!ap(r,tables[q].slot,0x630,stride,&n,&a)||n>100000){puts_w(w,"null");continue;}
        puts_w(w,"{\"count\":");number(w,n);
        if(n&&stride&&n*(uint64_t)stride<4*1024*1024){
            puts_w(w,",\"raw\":\"");base64(w,r->p+a,(size_t)n*stride);putc_w(w,'"');
        }
        puts_w(w,",\"offset\":");number(w,a);putc_w(w,'}');
    }
    putc_w(w,'}');
}
static void write_geometry_inventory(Writer *w,const Reader *r,uint64_t n,uint64_t a) {
    puts_w(w,",\"geometryInventory\":[");
    for(uint64_t i=0;i<n;i++) {
        uint64_t g=a+i*0xc8;
        if(i)putc_w(w,',');puts_w(w,"{\"index\":");number(w,i);
        puts_w(w,",\"vertexCount\":");number(w,rd(r,g+0x18,4));
        puts_w(w,",\"vertexStride\":");number(w,rd(r,g+0x1c,2));
        puts_w(w,",\"indexCount\":");number(w,rd(r,g+0x68,4));
        puts_w(w,",\"meshCount\":");number(w,rd(r,g+0x80,8));
        puts_w(w,",\"vertexTypes\":[");
        for(int j=0;j<11;j++) {if(j)putc_w(w,',');number(w,rd(r,g+0x20+j,1));}
        putc_w(w,']');
        puts_w(w,",\"fieldOffsets\":[");
        for(int j=0;j<11;j++) {if(j)putc_w(w,',');number(w,rd(r,g+0x2b+j,1));}
        puts_w(w,"]}");
    }
    putc_w(w,']');
}
static void write_auxiliary(Writer *w,const Reader *r) {
    uint64_t n,a;
    /* Confirmed native M3 tables, names/field sizes as found in WS-Tools. */
    puts_w(w,",\"attachments\":[");
    if(ap(r,0x280,0x630,8,&n,&a)&&n<=65536)for(uint64_t i=0;i<n;i++){
        if(i)putc_w(w,',');puts_w(w,"{\"slot\":");number(w,rd(r,a+i*8,2));
        puts_w(w,",\"bone\":");number(w,rd(r,a+i*8+2,2));
        puts_w(w,",\"attachmentId\":");number(w,rd(r,a+i*8+4,2));
        puts_w(w,",\"index\":");number(w,rd(r,a+i*8+6,2));putc_w(w,'}');
    }
    putc_w(w,']');
    puts_w(w,",\"cameras\":[");
    if(ap(r,0x328,0x630,0x38,&n,&a)&&n<=65536)for(uint64_t i=0;i<n;i++){
        if(i)putc_w(w,',');puts_w(w,"{\"id\":");number(w,rd(r,a+i*0x38,2));
        puts_w(w,",\"bone\":");number(w,rd(r,a+i*0x38+2,2));
        puts_w(w,",\"recordHex\":");hex_bytes(w,r,a+i*0x38,0x38);putc_w(w,'}');
    }
    putc_w(w,']');
    puts_w(w,",\"lights\":[");
    if(ap(r,0x318,0x630,0x190,&n,&a)&&n<=65536)for(uint64_t i=0;i<n;i++){
        if(i)putc_w(w,',');puts_w(w,"{\"type\":");number(w,rd(r,a+i*0x190,2));
        puts_w(w,",\"bone\":");number(w,rd(r,a+i*0x190+2,2));
        puts_w(w,",\"rawDescriptor\":");hex_bytes(w,r,a+i*0x190,0x190);putc_w(w,'}');
    }
    putc_w(w,']');
    puts_w(w,",\"emitters\":[");
    if(ap(r,0x2F8,0x630,0xa0,&n,&a)&&n<=10000){
        uint64_t base=a16(a+n*0xa0);
        for(uint64_t i=0;i<n;i++){
            uint64_t rec=a+i*0xa0,cn,keys,vals;
            if(i)putc_w(w,',');puts_w(w,"{\"bone\":");number(w,rd(r,rec,2));
            puts_w(w,",\"type\":");number(w,rd(r,rec+4,4));
            puts_w(w,",\"coordSpace\":");number(w,rd(r,rec+8,4));
            puts_w(w,",\"litFlag\":");number(w,rd(r,rec+0x14,4));
            puts_w(w,",\"shaderMode\":");number(w,rd(r,rec+0x18,4));
            puts_w(w,",\"blendMode\":");number(w,rd(r,rec+0x1c,4));
            puts_w(w,",\"noDepthTest\":");number(w,rd(r,rec+0x20,4));
            puts_w(w,",\"forceFieldMask\":");number(w,rd(r,rec+0x68,2));
            if(track_descriptor(r,rec+0x50,base,1,&cn,&keys,&vals)&&cn<=4096){
                puts_w(w,",\"visibilityTimes\":\"");base64(w,r->p+keys,(size_t)cn*4);
                puts_w(w,"\",\"visibilityValues\":\"");base64(w,r->p+vals,(size_t)cn);putc_w(w,'"');
            }
            puts_w(w,",\"rawDescriptor\":");hex_bytes(w,r,rec,0xa0);
            emitter_template(w,r,rec,base);
            putc_w(w,'}');
        }
    }
    putc_w(w,']');
    puts_w(w,",\"collision\":{");
    if(ap(r,0x490,0x630,0x40,&n,&a)&&n<=1000){
        puts_w(w,"\"records\":");number(w,n);puts_w(w,",\"items\":[");
        for(uint64_t i=0;i<n;i++){if(i)putc_w(w,',');hex_bytes(w,r,a+i*0x40,0x40);}putc_w(w,']');
    }else puts_w(w,"\"records\":0,\"items\":[]");
    putc_w(w,'}');
    puts_w(w,",\"rawHeader\":");hex_bytes(w,r,0,0x630);
}
static int parse(const Reader *r,const char *filename,Writer *w,const char **failure){
    uint64_t gc,ga,bc,ba,cc,ca,tc,ta,mc,ma,tot_vertices=0,tot_triangles=0,tot_meshes=0,gi;
    uint64_t unusedBoneMapCount=0,unusedBoneMapAt=0;int warned_skips=0, skipped=0;float bd[6]={1e8f,1e8f,1e8f,-1e8f,-1e8f,-1e8f};
    static const char *colors[]={"#7dcbe8","#e2a67d","#91d5b4","#b9a8f0","#edc27f","#dca4bc","#90b2e9","#c2cf91","#7cc8b8","#e6af91"};
    if(r->size<0x630||r->p[0]!='L'||r->p[1]!='D'||r->p[2]!='O'||r->p[3]!='M'){*failure="Keine WildStar-M3-Datei (LDOM-Header fehlt).";return 0;}
    if(rd(r,4,4)!=100){*failure="M3-Version nicht unterstützt (erwartet LDOM v100).";return 0;}
    if(!ap(r,0x250,0x630,0xC8,&gc,&ga)||!ap(r,0x180,0x630,0x160,&bc,&ba)||!ap(r,0x10,0x630,0x70,&cc,&ca)||!ap(r,0x1C0,0x630,0x20,&tc,&ta)||!ap(r,0x1F0,0x630,0x30,&mc,&ma)){
        *failure="M3-Header enthält ungültige Geometrie-/Bone-/Clip-/Textur-Offsets.";return 0;
    }
    if(gc>1024||bc>100000||cc>100000||tc>100000||mc>100000){*failure="M3-Tabellen überschreiten die Sicherheitsgrenzen.";return 0;}
    puts_w(w,"{\"name\":");json_str(w,filename?filename:"model.m3");puts_w(w,",\"format\":\"M3\",\"sections\":[");
    for(gi=0;gi<gc;gi++){
        uint64_t g=ga+gi*0xc8,geo_base=a16(ga+gc*0xc8),vdata,indices,mesh_rec,unused,count,ms,vi;
        uint32_t vertices=(uint32_t)rd(r,g+0x18,4),icount=(uint32_t)rd(r,g+0x68,4),vsize=(uint32_t)rd(r,g+0x1c,2),stride;
        int pt,offsets[11];
        if(!vertex_layout(r,g,&pt,offsets,&stride)||!vsize||vsize!=stride){skipped++;continue;}
        /* Geometry +0x70 is an AP of BYTES holding u16 indices.
           The count is byte length (2 * geometry.indexCount), not an
           element count. Previously stride=2 doubled its bounds check,
           silently skipping every Avatus geometry. */
        if(!ap(r,g+0x38,geo_base,1,&unused,&vdata) || !ap(r,g+0x70,geo_base,1,&count,&indices)||!ap(r,g+0x80,geo_base,0x70,&ms,&mesh_rec)){
            skipped++;continue;
        }
        if(vertices>4000000||icount>20000000||ms>20000||!span(r,vdata,(uint64_t)vertices*vsize)||!span(r,indices,(uint64_t)icount*2)||count<(uint64_t)icount*2){skipped++;continue;}
        for(vi=0;vi<ms;vi++){
            uint64_t mr=mesh_rec+vi*0x70,firsti=rd(r,mr,4),firstv=rd(r,mr+4,4),ni=rd(r,mr+8,4),nv=rd(r,mr+12,4),flags=rd(r,mr+0x38,4);
            unsigned mat=(unsigned)rd(r,mr+0x16,2),group=(unsigned)rd(r,mr+0x1E,1),cluster=(unsigned)rd(r,mr+0x22,1);
            float *pos=NULL,*nor=NULL,*uv1=NULL,*uv2=NULL,*tan=NULL,*bit=NULL;
            unsigned char *color0=NULL,*color1=NULL,*boneIndex=NULL,*boneWeight=NULL;
            uint32_t *idx=NULL;size_t vi2,j,valid=0;
            if(ni<3||nv<3)continue;
            if(firstv+nv>vertices||firsti+ni>icount || ni>3000000 || nv>750000 || tot_meshes>=350 || tot_vertices+nv>750000 || (flags&0xA)==0xA){skipped++;continue;}
            pos=(float*)mem_alloc((size_t)nv*3*sizeof(float));nor=(float*)mem_alloc((size_t)nv*3*sizeof(float));idx=(uint32_t*)mem_alloc((size_t)ni*sizeof(uint32_t));
            if(offsets[8]>=0)uv1=(float*)mem_alloc((size_t)nv*2*sizeof(float));
            if(offsets[9]>=0)uv2=(float*)mem_alloc((size_t)nv*2*sizeof(float));
            if(offsets[1]>=0)tan=(float*)mem_alloc((size_t)nv*3*sizeof(float));
            if(offsets[3]>=0)bit=(float*)mem_alloc((size_t)nv*3*sizeof(float));
            if(offsets[6]>=0)color0=(unsigned char*)mem_alloc((size_t)nv*4);
            if(offsets[7]>=0)color1=(unsigned char*)mem_alloc((size_t)nv*4);
            if(offsets[4]>=0)boneIndex=(unsigned char*)mem_alloc((size_t)nv*4);
            if(offsets[5]>=0)boneWeight=(unsigned char*)mem_alloc((size_t)nv*4);
            if(!pos||!nor||!idx||(offsets[8]>=0&&!uv1)||(offsets[9]>=0&&!uv2)||(offsets[1]>=0&&!tan)||(offsets[3]>=0&&!bit)||
               (offsets[6]>=0&&!color0)||(offsets[7]>=0&&!color1)||(offsets[4]>=0&&!boneIndex)||(offsets[5]>=0&&!boneWeight)){
                *failure="Nicht genug Speicher für Modellgeometrie.";goto mesh_fail;
            }
            for(vi2=0;vi2<(size_t)nv;vi2++){
                uint64_t v=vdata+(firstv+vi2)*vsize;float x,y,z,nxyz[3];
                if(pt==1){x=flt(r,v+offsets[0]);y=flt(r,v+offsets[0]+4);z=flt(r,v+offsets[0]+8);}
                else{x=(int16_t)rd(r,v+offsets[0],2)/1024.0f;y=(int16_t)rd(r,v+offsets[0]+2,2)/1024.0f;z=(int16_t)rd(r,v+offsets[0]+4,2)/1024.0f;}
                if(!okfloat(x)||!okfloat(y)||!okfloat(z)){*failure="M3 enthält ungültige Vertex-Koordinaten.";goto mesh_fail;}
                pos[vi2*3]=x;pos[vi2*3+1]=-z;pos[vi2*3+2]=y;
                bounds_add(bd,x,-z,y);
                if(offsets[2]>=0)oct_normal((unsigned)r->p[v+offsets[2]],(unsigned)r->p[v+offsets[2]+1],nxyz);
                else{nxyz[0]=0;nxyz[1]=1;nxyz[2]=0;}
                nor[vi2*3]=nxyz[0];nor[vi2*3+1]=-nxyz[2];nor[vi2*3+2]=nxyz[1];
                if(uv1){uv1[vi2*2]=half_float((uint16_t)rd(r,v+offsets[8],2));uv1[vi2*2+1]=1.0f-half_float((uint16_t)rd(r,v+offsets[8]+2,2));}
                if(uv2){uv2[vi2*2]=half_float((uint16_t)rd(r,v+offsets[9],2));uv2[vi2*2+1]=1.0f-half_float((uint16_t)rd(r,v+offsets[9]+2,2));}
                if(tan){oct_normal(r->p[v+offsets[1]],r->p[v+offsets[1]+1],nxyz);
                    tan[vi2*3]=nxyz[0];tan[vi2*3+1]=-nxyz[2];tan[vi2*3+2]=nxyz[1];}
                if(bit){oct_normal(r->p[v+offsets[3]],r->p[v+offsets[3]+1],nxyz);
                    bit[vi2*3]=nxyz[0];bit[vi2*3+1]=-nxyz[2];bit[vi2*3+2]=nxyz[1];}
                if(color0)copy_bytes(color0+vi2*4,r->p+v+offsets[6],4);
                if(color1)copy_bytes(color1+vi2*4,r->p+v+offsets[7],4);
                if(boneIndex)copy_bytes(boneIndex+vi2*4,r->p+v+offsets[4],4);
                if(boneWeight)copy_bytes(boneWeight+vi2*4,r->p+v+offsets[5],4);

            }
            for(j=0;j+2<(size_t)ni;j+=3){uint32_t a=(uint32_t)rd(r,indices+(firsti+j)*2,2),b=(uint32_t)rd(r,indices+(firsti+j+1)*2,2),c=(uint32_t)rd(r,indices+(firsti+j+2)*2,2);
                if(a<nv&&b<nv&&c<nv&&a!=b&&a!=c&&b!=c){idx[valid++]=a;idx[valid++]=b;idx[valid++]=c;}
            }
            if(valid){
                if(tot_meshes)putc_w(w,',');puts_w(w,"{\"name\":\"Geometry ");number(w,gi);puts_w(w," / Mesh ");number(w,vi);puts_w(w,"\",\"color\":");json_str(w,colors[(mat*7+(mat/5))%10]);
                puts_w(w,",\"material\":");number(w,mat);puts_w(w,",\"vertices\":");number(w,nv);puts_w(w,",\"triangles\":");number(w,valid/3);
                puts_w(w,",\"meta\":{\"group\":");number(w,group);puts_w(w,",\"cluster\":");number(w,cluster);puts_w(w,",\"flags\":");number(w,flags);
                puts_w(w,",\"bonePaletteStart\":");number(w,rd(r,mr+0x10,2));puts_w(w,",\"bonePaletteCount\":");number(w,rd(r,mr+0x12,2));
                puts_w(w,"},\"positions\":\"");base64(w,pos,(size_t)nv*3*sizeof(float));
                puts_w(w,"\",\"normals\":\"");base64(w,nor,(size_t)nv*3*sizeof(float));puts_w(w,"\",\"indices\":\"");base64(w,idx,valid*sizeof(uint32_t));putc_w(w,'"');
                if(uv1)output_array_as_b64(w,uv1,(size_t)nv*2*sizeof(float),"uv1");
                if(uv2)output_array_as_b64(w,uv2,(size_t)nv*2*sizeof(float),"uv2");
                if(tan)output_array_as_b64(w,tan,(size_t)nv*3*sizeof(float),"tangents");
                if(bit)output_array_as_b64(w,bit,(size_t)nv*3*sizeof(float),"bitangents");
                if(color0)output_array_as_b64(w,color0,(size_t)nv*4,"color0");
                if(color1)output_array_as_b64(w,color1,(size_t)nv*4,"color1");
                if(boneIndex)output_array_as_b64(w,boneIndex,(size_t)nv*4,"boneIndices");
                if(boneWeight)output_array_as_b64(w,boneWeight,(size_t)nv*4,"boneWeights");
                putc_w(w,'}');
                tot_meshes++;tot_vertices+=nv;tot_triangles+=valid/3;
            }
            ws_m3_free(pos);ws_m3_free(nor);ws_m3_free(idx);ws_m3_free(uv1);ws_m3_free(uv2);ws_m3_free(tan);ws_m3_free(bit);
            ws_m3_free(color0);ws_m3_free(color1);ws_m3_free(boneIndex);ws_m3_free(boneWeight);
            if(w->failed){*failure="M3-Darstellung zu groß oder Speicherfehler.";return 0;}
            continue;
mesh_fail:
            ws_m3_free(pos);ws_m3_free(nor);ws_m3_free(idx);ws_m3_free(uv1);ws_m3_free(uv2);ws_m3_free(tan);ws_m3_free(bit);
            ws_m3_free(color0);ws_m3_free(color1);ws_m3_free(boneIndex);ws_m3_free(boneWeight);
            return 0;
        }
    }
    /* FX-only/helper assets may legitimately have no renderable triangles.
       Preserve all metadata and let the UI display an empty preview. */
    if(tot_meshes==0)for(int i=0;i<6;i++)bd[i]=0.0f;
    puts_w(w,"],\"bounds\":[");for(int i=0;i<6;i++){if(i)putc_w(w,',');dec_float(w,bd[i]);}
    puts_w(w,"],\"stats\":{\"vertices\":");number(w,tot_vertices);puts_w(w,",\"triangles\":");number(w,tot_triangles);puts_w(w,",\"meshes\":");number(w,tot_meshes);
    puts_w(w,",\"bones\":");number(w,bc);puts_w(w,",\"animations\":");number(w,cc);puts_w(w,",\"materials\":");number(w,mc);puts_w(w,",\"textures\":");number(w,tc);
    puts_w(w,",\"version\":");number(w,rd(r,4,4));puts_w(w,"},\"parser\":\"Native C DLL (ABI 2)\",\"m3Details\":{\"clips\":[");
    for(uint64_t i=0;i<cc;i++){uint64_t at=ca+i*0x70;uint64_t start=rd(r,at+12,4),end=rd(r,at+16,4);
        if(i)putc_w(w,',');puts_w(w,"{\"id\":");number(w,rd(r,at,2));puts_w(w,",\"variant\":");number(w,rd(r,at+2,2));puts_w(w,",\"durationMs\":");number(w,end>=start?end-start:0);
        puts_w(w,",\"startMs\":");number(w,start);puts_w(w,",\"endMs\":");number(w,end);
        puts_w(w,",\"blendIn\":");number(w,rd(r,at+8,2));puts_w(w,",\"blendOut\":");number(w,rd(r,at+10,2));
        puts_w(w,",\"speed\":");dec_float(w,flt(r,at+0x14));
        putc_w(w,'}');
    }
    puts_w(w,"],\"moreClips\":");number(w,0);puts_w(w,",\"textures\":[");
    for(uint64_t i=0;i<tc;i++){uint64_t at=ta+i*0x20,count=rd(r,at+16,8),off=rd(r,at+24,8);uint64_t base=a16(ta+tc*0x20);
        if(i)putc_w(w,',');puts_w(w,"{\"id\":");number(w,rd(r,at,2));puts_w(w,",\"type\":");number(w,rd(r,at+2,1));
        puts_w(w,",\"flags\":");number(w,rd(r,at+3,1));
        puts_w(w,",\"unknown4\":");number(w,rd(r,at+4,4));
        puts_w(w,",\"unknown8\":");dec_float(w,flt(r,at+8));
        puts_w(w,",\"path\":");
        if(off>r->size||base>r->size||off>r->size-base||count>2048||!span(r,base+off,count*2))puts_w(w,"\"\"");
        else append_utf16(w,r,base+off,count);
        putc_w(w,'}');
    }
    puts_w(w,"],\"moreTextures\":");number(w,0);
        /* m3Details now covers all explicitly supported native data arrays. */
    (void)ap(r,0x1B0,0x630,2,&unusedBoneMapCount,&unusedBoneMapAt);
    puts_w(w,",\"boneMap\":[");
    for(uint64_t i=0;i<unusedBoneMapCount;i++) {if(i)putc_w(w,',');number(w,rd(r,unusedBoneMapAt+i*2,2));}
    putc_w(w,']');
    write_bones(w,r,bc,ba);
    write_materials(w,r,mc,ma);
    write_auxiliary(w,r);
    write_geometry_inventory(w,r,gc,ga);
    write_small_tables(w,r);
    puts_w(w,"},\"warnings\":[\"M3-Parsing erweitert: das WebGL-Viewport rendert bislang nur statische Geometrie; TEX-Shader, Bone-Skinning, FX noch nicht angebunden.\"");
    if(tot_meshes==0)puts_w(w,",\"Dieses M3 besitzt keine in der Vorschau darstellbaren Meshes; Metadaten wurden dennoch gelesen.\"");
    if(skipped){puts_w(w,",\"Einige versteckte, ungültige oder übergroße Meshes wurden ausgelassen.\"");warned_skips=1;}
    (void)warned_skips;puts_w(w,"]}");
    if(w->failed){*failure="M3-Ausgabe zu groß oder Speicherfehler.";return 0;}
    return 1;
}
int ws_m3_parse_json(const void *bytes,size_t size,const char *filename,char **json,char **error) {
    Reader r;Writer w;const char *fail="Unbekannter M3-Parserfehler.";
    if(!json||!error)return 0;*json=0;*error=0;
    if(!bytes||size==0||size>512ULL*1024*1024){*error=make_string("Ungültige Dateigröße (max. 512 MiB). ");return 0;}
    r.p=(const unsigned char*)bytes;r.size=size;w.p=0;w.len=0;w.cap=0;w.failed=0;
    if(!parse(&r,filename,&w,&fail)) {ws_m3_free(w.p);*error=make_string(fail);return 0;}
    *json=w.p;return 1;
}
