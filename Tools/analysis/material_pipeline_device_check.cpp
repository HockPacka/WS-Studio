// Hidden D3D9 readback of actual MPQ vertex/combiners and the embedded M3 PS.
#include <windows.h>
#include <d3d9.h>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include "Engine/Source/Model2/Shaders/WildStarModelBytecode.h"

static std::vector<char> Read(const std::string& p) {
    std::ifstream f(p,std::ios::binary);return {(std::istreambuf_iterator<char>(f)),{}};
}
int main(int argc,char** argv) {
    if(argc!=2)return 2;std::string dir=std::string(argv[1])+"/";
    WNDCLASSA cls={};cls.lpfnWndProc=DefWindowProcA;cls.hInstance=GetModuleHandleA(nullptr);cls.lpszClassName="WSMaterialReadback";
    RegisterClassA(&cls);HWND window=CreateWindowA(cls.lpszClassName,"Material check",WS_POPUP,0,0,16,16,nullptr,nullptr,cls.hInstance,nullptr);
    IDirect3D9* api=Direct3DCreate9(D3D_SDK_VERSION);if(!api||!window)return 2;
    D3DPRESENT_PARAMETERS pp={};pp.Windowed=TRUE;pp.SwapEffect=D3DSWAPEFFECT_DISCARD;pp.hDeviceWindow=window;pp.BackBufferWidth=16;pp.BackBufferHeight=16;pp.BackBufferFormat=D3DFMT_A8R8G8B8;
    IDirect3DDevice9* d=nullptr;
    if(FAILED(api->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,window,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&pp,&d)))return 3;
    IDirect3DVertexShader9* vs[2]={};IDirect3DPixelShader9* ps[4]={};
    for(int i=0;i<2;++i){auto code=Read(dir+"Diffuse_T1_T2_"+std::to_string(30+i)+".bin");if(code.empty()||FAILED(d->CreateVertexShader((DWORD*)code.data(),&vs[i])))return 4;}
    if(FAILED(d->CreatePixelShader((DWORD*)WildStarModelBytecode::Pixel1,&ps[0]))||FAILED(d->CreatePixelShader((DWORD*)WildStarModelBytecode::Pixel9,&ps[1])))return 4;
    for(int i=0;i<2;++i){auto code=Read(dir+(i?"Combiners_Mod_0.bin":"Combiners_Opaque_0.bin"));if(code.empty()||FAILED(d->CreatePixelShader((DWORD*)code.data(),&ps[2+i])))return 4;}
    const D3DVERTEXELEMENT9 layout[]={{0,0,D3DDECLTYPE_FLOAT3,0,D3DDECLUSAGE_POSITION,0},{0,12,D3DDECLTYPE_FLOAT3,0,D3DDECLUSAGE_NORMAL,0},{0,24,D3DDECLTYPE_FLOAT2,0,D3DDECLUSAGE_TEXCOORD,0},{0,32,D3DDECLTYPE_FLOAT2,0,D3DDECLUSAGE_TEXCOORD,1},D3DDECL_END()};
    IDirect3DVertexDeclaration9* decl=nullptr;if(FAILED(d->CreateVertexDeclaration(layout,&decl)))return 4;d->SetVertexDeclaration(decl);
    const float quad[4][10]={{-1,-1,.5f,0,0,1,.5f,.5f,255,0},{-1,1,.5f,0,0,1,.5f,.5f,255,0},{1,-1,.5f,0,0,1,.5f,.5f,255,0},{1,1,.5f,0,0,1,.5f,.5f,255,0}};
    float vc[34][4]={};
    for(int i=0;i<4;++i)vc[2+i][i]=1;
    vc[6][0]=vc[7][1]=vc[8][0]=vc[9][1]=1;
    vc[11][0]=vc[11][1]=vc[11][2]=.5f;vc[12][2]=-1;
    for(int i=0;i<4;++i)vc[28][i]=1;
    vc[30][1]=vc[30][2]=1;vc[31][0]=vc[32][1]=vc[33][2]=1;
    d->SetVertexShaderConstantF(0,&vc[0][0],34);
    float pc[23][4]={};pc[2][3]=1.f/255;pc[16][2]=-1;pc[16][3]=1;
    pc[18][0]=pc[18][1]=pc[18][2]=.5f;pc[20][1]=1;pc[21][0]=pc[21][1]=pc[21][2]=pc[21][3]=1;pc[22][0]=1;
    d->SetPixelShaderConstantF(0,&pc[0][0],23);
    IDirect3DTexture9* textures[4]={};
    for(int i=0;i<4;++i){if(FAILED(d->CreateTexture(1,1,1,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&textures[i],nullptr)))return 5;d->SetTexture(i,textures[i]);d->SetSamplerState(i,D3DSAMP_MINFILTER,D3DTEXF_POINT);d->SetSamplerState(i,D3DSAMP_MAGFILTER,D3DTEXF_POINT);}
    auto color=[&](int i,DWORD c){D3DLOCKED_RECT l={};textures[i]->LockRect(0,&l,nullptr,0);*(DWORD*)l.pBits=c;textures[i]->UnlockRect(0);};
    d->SetRenderState(D3DRS_ZENABLE,FALSE);d->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);d->SetRenderState(D3DRS_LIGHTING,FALSE);
    IDirect3DSurface9 *target=nullptr,*readback=nullptr;d->GetRenderTarget(0,&target);
    if(FAILED(d->CreateOffscreenPlainSurface(16,16,D3DFMT_A8R8G8B8,D3DPOOL_SYSTEMMEM,&readback,nullptr)))return 6;
    auto render=[&](int v,int p,bool additive,const float (*vertices)[10]){
        d->SetVertexShader(vs[v]);d->SetPixelShader(ps[p]);
        d->SetRenderState(D3DRS_ALPHATESTENABLE,additive);d->SetRenderState(D3DRS_ALPHAFUNC,D3DCMP_GREATER);d->SetRenderState(D3DRS_ALPHAREF,1);
        d->SetRenderState(D3DRS_ALPHABLENDENABLE,additive);d->SetRenderState(D3DRS_SRCBLEND,additive?D3DBLEND_SRCALPHA:D3DBLEND_ONE);d->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_ONE);
        d->Clear(0,nullptr,D3DCLEAR_TARGET,additive?0xff101010:0,1,0);d->BeginScene();HRESULT hr=d->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,vertices,sizeof(quad[0]));d->EndScene();
        if(FAILED(hr)||FAILED(d->GetRenderTargetData(target,readback)))return DWORD(0xdeadbeef);
        D3DLOCKED_RECT l={};readback->LockRect(&l,nullptr,D3DLOCK_READONLY);DWORD c=*(DWORD*)((char*)l.pBits+8*l.Pitch+8*4);readback->UnlockRect();return c;
    };
    // Actual layered VS/PS: incoming light/specular permutation 31 darkens
    // material color before PS lighting. The selected material permutation is 30.
    color(0,0xff0000ff);color(1,0xff00ff00);color(2,0xffff0000);
    DWORD oldLit=render(1,1,false,quad),fixedLit=render(0,1,false,quad);
    // Stock combiner: additive zero-alpha grey texels must leave the background.
    color(0,0x00808080);DWORD oldWeb=render(0,2,true,quad),fixedWeb=render(0,3,true,quad);
    color(0,0xff808080);DWORD visibleWeb=render(0,0,true,quad);
    pc[22][0]=.25f;d->SetPixelShaderConstantF(22,pc[22],1);
    DWORD quarterWeb=render(0,0,true,quad);
    pc[22][0]=1;d->SetPixelShaderConstantF(22,pc[22],1);
    // Four quantized weights: w0=63/255, w1=w2=w3=64/255. A white fourth
    // texture must reach sampler 3, not merely leave its weight unused.
    color(0,0xff0000ff);color(1,0xff00ff00);color(2,0xffff0000);color(3,0xffffffff);
    float fourLayerQuad[4][10];memcpy(fourLayerQuad,quad,sizeof(quad));
    for(auto& vertex:fourLayerQuad){vertex[8]=64.25f;vertex[9]=64.0f/255.0f;}
    pc[20][3]=1;d->SetPixelShaderConstantF(20,pc[20],1);
    DWORD fourLayers=render(0,1,false,fourLayerQuad);
    printf("layered lighting old=%08lx fixed=%08lx; zero-alpha additive old=%08lx fixed=%08lx visible=%08lx quarter=%08lx; four layers=%08lx\n",oldLit,fixedLit,oldWeb,fixedWeb,visibleWeb,quarterWeb,fourLayers);
    int oldGreen=(oldLit>>8)&255,green=(fixedLit>>8)&255;
    int fourRed=(fourLayers>>16)&255,fourGreen=(fourLayers>>8)&255,fourBlue=fourLayers&255;
    auto nearValue=[](int value,int expected){return value>=expected-2&&value<=expected+2;};
    bool lightingOk=oldGreen>=60&&oldGreen<=68&&green>=124&&green<=132;
    bool webOk=(fixedWeb&0xffffff)==0x101010&&(oldWeb&0xff)>100&&(visibleWeb&0xff)>(fixedWeb&0xff)+20;
    bool fourOk=nearValue(fourRed,128)&&nearValue(fourGreen,128)&&nearValue(fourBlue,127);
    bool opacityOk=true;
    for(int shift=0;shift<24;shift+=8){int full=(visibleWeb>>shift)&255,quarter=(quarterWeb>>shift)&255;opacityOk&=nearValue(quarter,16+(full-16)/4);}
    bool ok=lightingOk&&webOk&&fourOk&&opacityOk;
    printf("checks lighting=%d web=%d four=%d opacity=%d rgb=%d,%d,%d\n",lightingOk?1:0,webOk?1:0,fourOk?1:0,opacityOk?1:0,fourRed,fourGreen,fourBlue);
    readback->Release();target->Release();for(auto t:textures)t->Release();decl->Release();for(auto p:ps)p->Release();for(auto v:vs)v->Release();d->Release();api->Release();DestroyWindow(window);
    puts(ok?"PASS one lighting application; masked additive background rejected; visible texels retained; four weighted layers sampled; instance opacity scales additive contribution":"FAIL material pipeline regression");return ok?0:1;
}
