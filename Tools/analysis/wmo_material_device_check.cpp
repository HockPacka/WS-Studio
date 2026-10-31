// D3D9 readback regression for WildStar WMO normal-map lighting.
#include <windows.h>
#include <d3d9.h>
#include <cstdio>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include "WoW/Source/WorldClient/Shaders/WildStarWmoBytecode.h"

static std::vector<char> Read(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    return { std::istreambuf_iterator<char>(file), {} };
}

int main(int argc, char** argv) {
    if (argc != 2) return 2;
    const std::string dir = std::string(argv[1]) + "/";
    WNDCLASSA cls = {};
    cls.lpfnWndProc = DefWindowProcA;
    cls.hInstance = GetModuleHandleA(nullptr);
    cls.lpszClassName = "WSWmoMaterialReadback";
    RegisterClassA(&cls);
    HWND window = CreateWindowA(cls.lpszClassName, "WMO material check", WS_POPUP, 0, 0, 16, 16, nullptr, nullptr, cls.hInstance, nullptr);
    IDirect3D9* api = Direct3DCreate9(D3D_SDK_VERSION);
    if (!api || !window) return 2;
    D3DPRESENT_PARAMETERS pp = {};
    pp.Windowed = TRUE;
    pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    pp.hDeviceWindow = window;
    pp.BackBufferWidth = 16;
    pp.BackBufferHeight = 16;
    pp.BackBufferFormat = D3DFMT_A8R8G8B8;
    IDirect3DDevice9* d = nullptr;
    if (FAILED(api->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &d))) return 3;

    auto code = Read(dir + "MapObjUDiffuse_T1_31.bin");
    IDirect3DVertexShader9* vs = nullptr;
    IDirect3DPixelShader9* ps = nullptr;
    if (code.empty() || FAILED(d->CreateVertexShader(reinterpret_cast<DWORD*>(code.data()), &vs)) ||
        FAILED(d->CreatePixelShader(reinterpret_cast<const DWORD*>(WildStarWmoBytecode::Pixel), &ps))) return 4;
    const D3DVERTEXELEMENT9 layout[] = {
        { 0, 0, D3DDECLTYPE_FLOAT3, 0, D3DDECLUSAGE_POSITION, 0 },
        { 0, 12, D3DDECLTYPE_FLOAT3, 0, D3DDECLUSAGE_NORMAL, 0 },
        { 0, 24, D3DDECLTYPE_D3DCOLOR, 0, D3DDECLUSAGE_COLOR, 0 },
        { 0, 28, D3DDECLTYPE_FLOAT2, 0, D3DDECLUSAGE_TEXCOORD, 0 },
        D3DDECL_END()
    };
    IDirect3DVertexDeclaration9* decl = nullptr;
    if (FAILED(d->CreateVertexDeclaration(layout, &decl))) return 4;
    d->SetVertexDeclaration(decl);
    struct Vertex { float p[3], n[3]; DWORD color; float uv[2]; };
    const Vertex quad[4] = {
        { { -1, -1, .5f }, { 0, 0, 1 }, 0xff808080, { 0, 0 } },
        { { -1, 1, .5f }, { 0, 0, 1 }, 0xff808080, { 0, 1 } },
        { { 1, -1, .5f }, { 0, 0, 1 }, 0xff808080, { 1, 0 } },
        { { 1, 1, .5f }, { 0, 0, 1 }, 0xff808080, { 1, 1 } },
    };
    float vc[35][4] = {};
    for (int i = 0; i < 4; ++i) vc[2 + i][i] = 1;
    for (int i = 0; i < 4; ++i) vc[31 + i][i] = 1;
    vc[10][0] = vc[10][1] = vc[10][2] = .25f;
    vc[11][0] = vc[11][1] = vc[11][2] = .75f;
    vc[12][2] = -1;
    vc[28][0] = vc[28][1] = vc[28][2] = .5f;
    vc[30][0] = 1;
    vc[30][2] = 1;
    d->SetVertexShaderConstantF(0, &vc[0][0], 35);
    float pc[23][4] = {};
    pc[2][0] = pc[2][1] = pc[2][2] = 0;
    pc[16][2] = -1;
    pc[17][0] = pc[17][1] = pc[17][2] = .25f;
    pc[18][0] = pc[18][1] = pc[18][2] = .75f;
    pc[19][0] = 1;
    pc[20][0] = 1;
    pc[21][0] = pc[21][1] = pc[21][2] = .5f;
    d->SetPixelShaderConstantF(0, &pc[0][0], 23);

    IDirect3DTexture9* textures[2] = {};
    for (int i = 0; i < 2; ++i) {
        if (FAILED(d->CreateTexture(1, 1, 1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, &textures[i], nullptr))) return 5;
        d->SetTexture(i, textures[i]);
        d->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_POINT);
        d->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
    }
    auto color = [](IDirect3DTexture9* texture, DWORD value) {
        D3DLOCKED_RECT locked = {};
        texture->LockRect(0, &locked, nullptr, 0);
        *static_cast<DWORD*>(locked.pBits) = value;
        texture->UnlockRect(0);
    };
    color(textures[0], 0xff808080);
    d->SetVertexShader(vs);
    d->SetPixelShader(ps);
    d->SetRenderState(D3DRS_ZENABLE, FALSE);
    d->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    d->SetRenderState(D3DRS_LIGHTING, FALSE);
    IDirect3DSurface9* target = nullptr;
    IDirect3DSurface9* readback = nullptr;
    d->GetRenderTarget(0, &target);
    if (FAILED(d->CreateOffscreenPlainSurface(16, 16, D3DFMT_A8R8G8B8, D3DPOOL_SYSTEMMEM, &readback, nullptr))) return 6;
    auto render = [&](bool normalEnable) {
        pc[19][3] = normalEnable ? 1 : 0;
        d->SetPixelShaderConstantF(19, pc[19], 1);
        d->Clear(0, nullptr, D3DCLEAR_TARGET, 0, 1, 0);
        d->BeginScene();
        HRESULT hr = d->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, quad, sizeof(quad[0]));
        d->EndScene();
        if (FAILED(hr) || FAILED(d->GetRenderTargetData(target, readback))) return DWORD(0xdeadbeef);
        D3DLOCKED_RECT locked = {};
        readback->LockRect(&locked, nullptr, D3DLOCK_READONLY);
        DWORD result = *reinterpret_cast<DWORD*>(static_cast<char*>(locked.pBits) + 8 * locked.Pitch + 8 * 4);
        readback->UnlockRect();
        return result;
    };

    color(textures[1], 0x00000000); // DXT5nm x=y=0, reconstructed z=1.
    pc[20][1] = 1;
    d->SetPixelShaderConstantF(20, pc[20], 1);
    DWORD geometric = render(false);
    pc[20][1] = 0;
    d->SetPixelShaderConstantF(20, pc[20], 1);
    DWORD withoutNormal = render(false);
    DWORD flatNormal = render(true);
    color(textures[1], 0xcd00cd00); // DXT5nm x=y about .607, reconstructed z about .514.
    DWORD bumpedNormal = render(true);
    pc[20][1] = 1;
    d->SetPixelShaderConstantF(20, pc[20], 1);
    DWORD bumpedDebug = render(true);
    pc[20][1] = 0;
    d->SetPixelShaderConstantF(20, pc[20], 1);
    printf("geometric=%08lx no normal=%08lx flat normal=%08lx bumped normal=%08lx bumped debug=%08lx\n", geometric, withoutNormal, flatNormal, bumpedNormal, bumpedDebug);
    bool ok = (geometric & 0xFF000000) == 0xFF000000 && (geometric & 0xFF) > 200 && withoutNormal != 0xdeadbeef && flatNormal == withoutNormal && bumpedNormal != flatNormal;

    readback->Release();
    target->Release();
    for (auto texture : textures) texture->Release();
    decl->Release();
    ps->Release();
    vs->Release();
    d->Release();
    api->Release();
    DestroyWindow(window);
    puts(ok ? "PASS flat normal preserves stock lighting; perturbed normal changes lighting" : "FAIL WMO material pipeline regression");
    return ok ? 0 : 1;
}
