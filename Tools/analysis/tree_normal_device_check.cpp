// Standalone hidden D3D9 readback; does not control the user's game window.
#include <windows.h>
#include <d3d9.h>
#include <d3dcompiler.h>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include "Engine/Source/Model3/TexJpg.h"
#include "Engine/Source/Model2/Shaders/WildStarModelBytecode.h"

static void Put(std::vector<uint8_t>& v,size_t at,uint32_t x){std::memcpy(v.data()+at,&x,4);}
int main() {
    auto module=GetModuleHandleA(nullptr);WNDCLASSA cls={};cls.lpfnWndProc=DefWindowProcA;cls.hInstance=module;cls.lpszClassName="WSTreeNormalReadback";
    RegisterClassA(&cls);HWND window=CreateWindowA(cls.lpszClassName,"Tree normal shader check",WS_POPUP,0,0,32,32,nullptr,nullptr,module,nullptr);
    IDirect3D9* api=Direct3DCreate9(D3D_SDK_VERSION);if(!api||!window)return 2;
    D3DPRESENT_PARAMETERS pp={};pp.Windowed=TRUE;pp.SwapEffect=D3DSWAPEFFECT_DISCARD;pp.hDeviceWindow=window;pp.BackBufferWidth=16;pp.BackBufferHeight=16;pp.BackBufferFormat=D3DFMT_A8R8G8B8;
    IDirect3DDevice9* device=nullptr;HRESULT hr=api->CreateDevice(D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,window,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&pp,&device);
    if(FAILED(hr)){std::printf("FAIL device %08lx\n",hr);return 3;}
    const char* vsSource=
        "struct I{float3 p:POSITION;float2 uv:TEXCOORD0;};"
        "struct O{float4 p:POSITION;float4 c:COLOR0;float2 uv:TEXCOORD0;float3 v:TEXCOORD1;float3 n:TEXCOORD2;float f:FOG;};"
        "O main(I i){O o;o.p=float4(i.p,1);o.c=1;o.uv=i.uv;o.v=i.p;o.n=float3(0,0,1);o.f=1;return o;}";
    ID3DBlob* code=nullptr;ID3DBlob* error=nullptr;
    hr=D3DCompile(vsSource,std::strlen(vsSource),nullptr,nullptr,nullptr,"main","vs_3_0",0,0,&code,&error);
    if(FAILED(hr)){if(error)std::puts((char*)error->GetBufferPointer());return 4;}
    IDirect3DVertexShader9* vs=nullptr;IDirect3DPixelShader9* ps=nullptr;IDirect3DVertexDeclaration9* decl=nullptr;
    const D3DVERTEXELEMENT9 layout[]={{0,0,D3DDECLTYPE_FLOAT3,D3DDECLMETHOD_DEFAULT,D3DDECLUSAGE_POSITION,0},{0,12,D3DDECLTYPE_FLOAT2,D3DDECLMETHOD_DEFAULT,D3DDECLUSAGE_TEXCOORD,0},D3DDECL_END()};
    hr=device->CreateVertexShader((const DWORD*)code->GetBufferPointer(),&vs);code->Release();if(error)error->Release();
    if(SUCCEEDED(hr))hr=device->CreatePixelShader((const DWORD*)WildStarModelBytecode::Pixel3,&ps);
    if(SUCCEEDED(hr))hr=device->CreateVertexDeclaration(layout,&decl);
    if(FAILED(hr)){std::printf("FAIL shaders %08lx\n",hr);return 5;}
    IDirect3DTexture9* texture=nullptr;IDirect3DSurface9* target=nullptr;IDirect3DSurface9* readback=nullptr;
    device->CreateTexture(8,8,1,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&texture,nullptr);
    device->GetRenderTarget(0,&target);device->CreateOffscreenPlainSurface(16,16,D3DFMT_A8R8G8B8,D3DPOOL_SYSTEMMEM,&readback,nullptr);
    if(!texture||!target||!readback)return 6;
    device->SetVertexShader(vs);device->SetPixelShader(ps);device->SetVertexDeclaration(decl);device->SetTexture(0,texture);device->SetTexture(1,texture);
    device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);device->SetRenderState(D3DRS_ZENABLE,FALSE);device->SetRenderState(D3DRS_ALPHABLENDENABLE,FALSE);device->SetRenderState(D3DRS_ALPHATESTENABLE,FALSE);
    for(int unit=0;unit<2;++unit){device->SetSamplerState(unit,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);device->SetSamplerState(unit,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);device->SetSamplerState(unit,D3DSAMP_SRGBTEXTURE,FALSE);}
    const float quad[][5]={{-1,-1,.5f,0,1},{-1,1,.5f,0,0},{1,-1,.5f,1,1},{1,1,.5f,1,0}};
    float constants[5][4]={};constants[0][3]=1;constants[4][1]=1;constants[4][2]=1;device->SetPixelShaderConstantF(16,&constants[0][0],5);
    std::vector<uint8_t> tex(112,0),pixels;std::string message;
    Put(tex,0,0x474658);Put(tex,4,3);Put(tex,8,8);Put(tex,12,8);Put(tex,16,1);Put(tex,20,1);Put(tex,24,1);Put(tex,32,1);Put(tex,36,1);Put(tex,52,1);
    const uint8_t planes[]={128,128,0,255};for(int i=0;i<4;++i){tex[40+i*3]=75;tex[41+i*3]=1;tex[42+i*3]=planes[i];}
    if(!M3::DecodeJpgTexMip(tex.data(),tex.size(),0,8,8,pixels,message))return 7;
    DWORD results[2]={};
    for(int legacy=0;legacy<2;++legacy) {
        D3DLOCKED_RECT lock={};texture->LockRect(0,&lock,nullptr,0);
        for(int y=0;y<8;++y)for(int x=0;x<8;++x){uint8_t* dst=(uint8_t*)lock.pBits+y*lock.Pitch+x*4;if(legacy){dst[0]=255;dst[1]=0;dst[2]=128;dst[3]=128;}else std::memcpy(dst,&pixels[(y*8+x)*4],4);}
        texture->UnlockRect(0);device->Clear(0,nullptr,D3DCLEAR_TARGET,0,1,0);device->BeginScene();hr=device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,quad,sizeof(quad[0]));device->EndScene();
        if(FAILED(hr)||FAILED(device->GetRenderTargetData(target,readback)))return 8;
        readback->LockRect(&lock,nullptr,D3DLOCK_READONLY);results[legacy]=*(DWORD*)((uint8_t*)lock.pBits+8*lock.Pitch+8*4);readback->UnlockRect();
    }
    const int correctedBlue=results[0]&255,legacyBlue=results[1]&255;
    std::printf("normal debug readback corrected=%08lx legacy=%08lx\n",results[0],results[1]);
    if(correctedBlue<250||legacyBlue>140)return 9;
    readback->Release();target->Release();texture->Release();decl->Release();ps->Release();vs->Release();device->Release();api->Release();DestroyWindow(window);
    std::puts("PASS native TYPE2 planes -> actual model PS3: flat normal restored; legacy channel layout reproduces sideways normal");
    return 0;
}
