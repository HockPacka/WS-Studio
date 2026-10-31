// Resolves RVAs of WowClient64.exe to function + source line with dbghelp (the exe must be the one the crash came from, its PDB next to it).
// build: cl /nologo /EHsc /O1 tools\analysis\symbolize.cpp dbghelp.lib /Fe:build_m3test\symbolize.exe
// usage: symbolize <exe> <rva hex> [<rva hex> ...]
#include <windows.h>
#include <dbghelp.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv) {
    if (argc < 3) {
        return 1;
    }

    HANDLE process = GetCurrentProcess();
    SymSetOptions(SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);

    char dir[MAX_PATH];
    strcpy(dir, argv[1]);
    char* slash = strrchr(dir, 92);
    char* fslash = strrchr(dir, 47);
    if (fslash > slash) slash = fslash;
    if (slash) *slash = 0; else strcpy(dir, ".");

    if (!SymInitialize(process, dir, FALSE)) {
        return 2;
    }

    const DWORD64 base = 0x140000000ull;
    DWORD64 loaded = SymLoadModuleEx(process, nullptr, argv[1], nullptr, base, 0, nullptr, 0);

    if (!loaded) {
        printf("load failed %lu\n", GetLastError());
        return 3;
    }

    IMAGEHLP_MODULE64 mi = { sizeof(mi) };
    if (SymGetModuleInfo64(process, loaded, &mi)) printf("symtype %d pdb %s\n", mi.SymType, mi.LoadedPdbName);
    for (int i = 2; i < argc; i++) {
        DWORD64 rva = strtoull(argv[i], nullptr, 16);
        DWORD64 addr = base + rva;
        char buf[sizeof(SYMBOL_INFO) + 512];
        SYMBOL_INFO* sym = reinterpret_cast<SYMBOL_INFO*>(buf);
        sym->SizeOfStruct = sizeof(SYMBOL_INFO);
        sym->MaxNameLen = 500;
        DWORD64 disp = 0;
        IMAGEHLP_LINE64 line = { sizeof(line) };
        DWORD ldisp = 0;
        printf("%s: ", argv[i]);

        if (SymFromAddr(process, addr, &disp, sym)) {
            printf("%s+0x%llx", sym->Name, disp);
        } else {
            printf("(no symbol)");
        }

        if (SymGetLineFromAddr64(process, addr, &ldisp, &line)) {
            printf("  %s:%lu", line.FileName, line.LineNumber);
        }

        printf("\n");
    }

    return 0;
}
