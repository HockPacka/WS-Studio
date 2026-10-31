"""Wire session debug controls into existing native adapters (idempotent)."""
from pathlib import Path

root = Path(__file__).resolve().parents[1] / 'wowdecomp'

def edit(file, old, new):
    p = root / file
    s = p.read_text(encoding='utf-8')
    if new in s: return
    if old not in s: raise RuntimeError(f'Anchor missing: {file}: {old[:90]}')
    p.write_text(s.replace(old, new, 1), encoding='utf-8')

def include(file):
    p = root / file
    s = p.read_text(encoding='utf-8')
    line = '#include "Engine/Source/Model3/DebugOptions.h"\n'
    if line not in s: p.write_text(line+s, encoding='utf-8')

edit('Engine/Source/Model3/CMakeLists.txt', '    M3Reader.cpp', '    DebugOptions.cpp\n    M3Reader.cpp')
for f in ['Engine/Source/Model2/WildStarModelShader.cpp', 'Engine/Source/Model2/M2Shared.cpp',
          'Engine/Source/Model3/TexToBlp.cpp', 'Engine/Source/Struct3/WmoBuilder.cpp',
          'WoW/Source/WorldClient/MapPrefetch.cpp', 'WoW/Source/Ui/WildStarDebug.cpp',
          'Engine/Source/Model3/Prefetch.cpp']:
    include(f)

edit('Engine/Source/Model2/WildStarModelShader.cpp',
     '    if (disabled || !vertexShader',
     '    if (!M3::Debug::Enabled("materials") || disabled || !vertexShader')
edit('Engine/Source/Model2/WildStarModelShader.cpp',
     'bool nm = vsn && (batchShader & kNormalMap);',
     'bool nm = vsn && (batchShader & kNormalMap) && M3::Debug::Enabled("normal");')
edit('Engine/Source/Model2/WildStarModelShader.cpp',
     '    float c[5][4] = {',
     '    if (!M3::Debug::Enabled("gloss")) gloss = 0.0f;\n    if (!M3::Debug::Enabled("glow")) glow = 0.0f;\n    float c[5][4] = {')

for f, sig, guard in [
    ('Engine/Source/Model2/M2Shared.cpp', 'int32_t CM2Shared::LoadM3(const char* path, int32_t flags, CAaBox* boundingBox) {',
     'if (!M3::Debug::Enabled("files")) return 0;'),
    ('Engine/Source/Model3/TexToBlp.cpp', 'bool LoadTexAsBlp(const char* name, std::vector<uint8_t>& blp, std::string& error) {',
     'if (!M3::Debug::Enabled("files")) { error = "WildStar file support disabled in debug menu"; return false; }'),
    ('Engine/Source/Struct3/WmoBuilder.cpp', 'const WmoBuild* GetCachedWmo(const std::string& name, std::string& error) {',
     'if (!M3::Debug::Enabled("files")) { error = "WildStar file support disabled in debug menu"; return nullptr; }'),
    ('WoW/Source/WorldClient/MapPrefetch.cpp', 'bool TakeAdt(const Area3::MapWindow& window, const std::string& mapName, int tileX, int tileY, std::vector<uint8_t>& adt, std::string& error) {',
     'if (!M3::Debug::Enabled("files")) { error = "WildStar file support disabled in debug menu"; return false; }'),
    ('WoW/Source/WorldClient/MapPrefetch.cpp', 'void Prefetch(const Area3::MapWindow& window, const std::string& mapName, int x, int y) {',
     'if (!M3::Debug::Enabled("files")) return;'),
]: edit(f, sig, sig+'\n    '+guard)

for sig, guard in [
    ('void PrefetchModel(const std::string& relPath, bool urgent) {', 'if (!M3::Debug::Enabled("files")) return;'),
    ('void PrefetchTexture(const std::string& wsName, bool urgent) {', 'if (!M3::Debug::Enabled("files")) return;'),
    ('bool TakeTexture(const std::string& wsName, std::vector<uint8_t>& blp, std::string& error, bool& ok) {',
     'if (!M3::Debug::Enabled("files")) { ok = false; error = "WildStar file support disabled in debug menu"; return true; }'),
]: edit('Engine/Source/Model3/Prefetch.cpp', sig, sig+'\n    '+guard)

edit('WoW/Source/Ui/WildStarDebug.cpp', 'const Entry s_functions[] = {', '''// Deliberately expose a closed set of switches; invalid names do not change state.
int32_t Script_WSGetDebugSetting(lua_State* L) {
    const char* key = luaL_checkstring(L, 1);
    bool value;
    if (!M3::Debug::Get(key, value)) return luaL_error(L, "Unknown WildStar debug setting: %s", key);
    lua_pushboolean(L, value);
    return 1;
}
int32_t Script_WSSetDebugSetting(lua_State* L) {
    const char* key = luaL_checkstring(L, 1);
    luaL_checktype(L, 2, LUA_TBOOLEAN);
    bool value = lua_toboolean(L, 2) != 0;
    if (!M3::Debug::Set(key, value)) return luaL_error(L, "Unknown WildStar debug setting: %s", key);
    lua_pushboolean(L, value);
    return 1;
}

const Entry s_functions[] = {
    { "WSGetDebugSetting", &Script_WSGetDebugSetting },
    { "WSSetDebugSetting", &Script_WSSetDebugSetting },''')

# Run both scripts after either Glue or world UI has created its parent frames.
edit('WoW/Source/Ui/WildStarDebug.cpp',
     'void WildStarRunDebugScript() {\n    FILE* f = fopen("Interface\\\\WildStarDebug\\\\WildStarDebug.lua", "rb");',
     'static void RunDebugScript(const char* path) {\n    FILE* f = fopen(path, "rb");')
edit('WoW/Source/Ui/WildStarDebug.cpp',
     'FrameScript_ExecuteBuffer(code.data(), code.size(), "@WildStarDebug.lua", &status, nullptr);\n}',
     '''FrameScript_ExecuteBuffer(code.data(), code.size(), path, &status, nullptr);
}

void WildStarRunDebugScript() {
    RunDebugScript("Interface\\\\WildStarDebug\\\\WildStarDebug.lua");
    RunDebugScript("Interface\\\\WildStarDebug\\\\MaterialDebug.lua");
}''')

print('WildStar debug controls wired.')
