// Execute the embedded cloud shaders on a hidden D3D9 device and read pixels.
// No game files, visible window or Present call; validates actual GPU bytecode.
#include <windows.h>
#include <d3d9.h>
#include <cmath>
#include <cstdio>
#include <initializer_list>
#include "WoW/Source/WorldClient/Shaders/WildStarCloudBytecode.h"

int main() {
    HWND window=CreateWindowExA(0,"STATIC","SKY shader validation",WS_POPUP,0,0,16,16,nullptr,nullptr,GetModuleHandleA(nullptr),nullptr);
    IDirect3D9* api=Direct3DCreate9(D3D_SDK_VERSION);if(!api||!window){puts("FAIL D3D9 initialization");return 1;}
    D3DPRESENT_PARAMETERS pp={};pp.Windowed=TRUE;pp.SwapEffect=D3DSWAPEFFECT_DISCARD;pp.hDeviceWindow=window;pp.BackBufferWidth=16;pp.BackBufferHeight=16;pp.BackBufferFormat=D3DFMT_A8R8G8B8;
    IDirect3DDevice9* device=nullptr;
    HRESULT hr=api->CreateDevice(0,D3DDEVTYPE_HAL,window,D3DCREATE_SOFTWARE_VERTEXPROCESSING|D3DCREATE_FPU_PRESERVE,&pp,&device);
    if(FAILED(hr)){printf("FAIL CreateDevice %08lx\n",hr);api->Release();DestroyWindow(window);return 1;}
    IDirect3DVertexShader9* vs=nullptr;IDirect3DPixelShader9* ps=nullptr;IDirect3DVertexDeclaration9* decl=nullptr;
    const D3DVERTEXELEMENT9 layout[]={{0,0,D3DDECLTYPE_FLOAT3,D3DDECLMETHOD_DEFAULT,D3DDECLUSAGE_POSITION,0},{0,12,D3DDECLTYPE_FLOAT2,D3DDECLMETHOD_DEFAULT,D3DDECLUSAGE_TEXCOORD,0},D3DDECL_END()};
    hr=device->CreateVertexShader(reinterpret_cast<const DWORD*>(WildStarCloudBytecode::Vertex),&vs);
    if(SUCCEEDED(hr))hr=device->CreatePixelShader(reinterpret_cast<const DWORD*>(WildStarCloudBytecode::Pixel),&ps);
    if(SUCCEEDED(hr))hr=device->CreateVertexDeclaration(layout,&decl);
    if(FAILED(hr)){printf("FAIL shader creation %08lx\n",hr);return 1;}
    IDirect3DTexture9* texture=nullptr;IDirect3DSurface9 *target=nullptr,*copy=nullptr;
    device->CreateTexture(1,1,1,0,D3DFMT_A8R8G8B8,D3DPOOL_MANAGED,&texture,nullptr);
    device->GetRenderTarget(0,&target);device->CreateOffscreenPlainSurface(16,16,D3DFMT_A8R8G8B8,D3DPOOL_SYSTEMMEM,&copy,nullptr);
    if(!texture||!target||!copy){puts("FAIL texture/readback setup");return 1;}
    device->SetVertexShader(vs);device->SetPixelShader(ps);device->SetVertexDeclaration(decl);
    device->SetTexture(0,texture);device->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);device->SetRenderState(D3DRS_ZENABLE,FALSE);
    device->SetRenderState(D3DRS_ALPHABLENDENABLE,FALSE);device->SetRenderState(D3DRS_ALPHATESTENABLE,FALSE);device->SetRenderState(D3DRS_SRGBWRITEENABLE,FALSE);
    device->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);device->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);device->SetSamplerState(0,D3DSAMP_SRGBTEXTURE,FALSE);
    const float identity[]={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};device->SetVertexShaderConstantF(0,identity,4);device->SetVertexShaderConstantF(4,identity,4);
    const float vertices[][5]={{-1,-1,1,.5f,.5f},{-1,1,1,.5f,.5f},{1,-1,1,.5f,.5f},{1,1,1,.5f,.5f}};
    int cases=0;
    for(int mode=0;mode<2;++mode)for(int red:{0,128,255})for(int alpha:{0,128,255}) {
        D3DLOCKED_RECT lock={};texture->LockRect(0,&lock,nullptr,0);*static_cast<DWORD*>(lock.pBits)=D3DCOLOR_ARGB(alpha,red,0,0);texture->UnlockRect(0);
        float c[29][4]={};for(int channel=0;channel<3;++channel)c[0][channel]=.5f/.2820948f;
        c[10][3]=float(mode);c[11][0]=.8f;c[11][1]=.6f;c[11][2]=.4f;c[11][3]=.75f;
        for(int i=0;i<16;++i){c[13+i][0]=i/15.f;c[13+i][1]=.25f;c[13+i][2]=.75f;}
        device->SetPixelShaderConstantF(0,&c[0][0],29);device->Clear(0,nullptr,D3DCLEAR_TARGET,0,1,0);
        device->BeginScene();hr=device->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,vertices,sizeof(vertices[0]));device->EndScene();
        if(FAILED(hr)||FAILED(device->GetRenderTargetData(target,copy))){puts("FAIL draw/readback");return 1;}
        copy->LockRect(&lock,nullptr,D3DLOCK_READONLY);DWORD pixel=*reinterpret_cast<DWORD*>(static_cast<char*>(lock.pBits)+8*lock.Pitch+8*4);copy->UnlockRect();
        float a=alpha/255.f*.75f;float expected[]={red/255.f*.8f,mode?.25f*.6f:0,mode?.75f*.4f:0,a};
        if(mode)for(int channel=0;channel<3;++channel)expected[channel]*=a;
        int actual[]={int((pixel>>16)&255),int((pixel>>8)&255),int(pixel&255),int((pixel>>24)&255)};
        for(int channel=0;channel<4;++channel)if(std::abs(actual[channel]-int(expected[channel]*255+.5f))>2){printf("FAIL mode=%d red=%d alpha=%d channel=%d actual=%d expected=%.3f\n",mode,red,alpha,channel,actual[channel],expected[channel]*255);return 1;}
        ++cases;
    }
    copy->Release();target->Release();texture->Release();decl->Release();ps->Release();vs->Release();device->Release();api->Release();DestroyWindow(window);
    printf("PASS D3D9 cloud bytecode: %d GPU readback cases (LUT endpoints/interpolation, alpha, ordinary-material branch)\n",cases);return 0;
}
