import os
import subprocess

def fix_ws_races():
    for p in ['WoWClient/WoWOverride/Interface/GlueXML/WSRaces.lua', 'build_wildstar/wildstar335a/client/WoWOverride/Interface/GlueXML/WSRaces.lua']:
        if not os.path.exists(p):
            continue
        with open(p, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        
        # Check around line 324
        new_lines = []
        for i, line in enumerate(lines):
            new_lines.append(line)
            if 'pushedTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])' in line and i + 1 < len(lines) and 'end' in lines[i+1]:
                # Next line is 'end' closing pushedTex, insert an extra 'end' after it to close 'if coords then'
                pass
        
        # Or better: search for the exact segment
        full = "".join(lines)
        target = """\t\t\t\tlocal coords = CLASS_ICON_TCOORDS[cKey]
\t\t\t\tif coords then
\t\t\t\t\tif normalTex then
\t\t\t\t\t\tnormalTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\t\tnormalTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\t\tend
\t\t\t\tif pushedTex then
\t\t\t\t\tpushedTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\tpushedTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\tend
\t\t\tend"""

        replacement = """\t\t\t\tlocal coords = CLASS_ICON_TCOORDS[cKey]
\t\t\t\tif coords then
\t\t\t\t\tif normalTex then
\t\t\t\t\t\tnormalTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\t\tnormalTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\t\tend
\t\t\t\t\tif pushedTex then
\t\t\t\t\t\tpushedTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\t\tpushedTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\t\tend
\t\t\t\tend
\t\t\tend"""

        if target in full:
            full = full.replace(target, replacement)
            with open(p, 'w', encoding='utf-8') as f:
                f.write(full)
            print(f"Successfully fixed WSRaces.lua: {p}")
        else:
            print(f"Target not found in {p}")

def fix_telegraph_server_lua():
    paths = [
        r'Repack AzerothCore NPCBots(2026)(Update 6.2)\Repack AzerothCore NPCBots\Core\lua_scripts\WildStarTelegraph.lua',
        r'Repack AzerothCore NPCBots\Core\lua_scripts\WildStarTelegraph.lua'
    ]
    for p in paths:
        if not os.path.exists(p):
            continue
        with open(p, 'r', encoding='utf-8') as f:
            content = f.read()

        target = """                        -- Optional: Treffer-Visual am Ziel abspielen
                        if visualSpellId and visualSpellId > 0 then
                            caster:CastSpell(target, visualSpellId, true)
                        end
                    end
                end
            end
        end
    end
    
    return hitCount
end"""

        replacement = """                        -- Optional: Treffer-Visual am Ziel abspielen
                        if visualSpellId and visualSpellId > 0 then
                            caster:CastSpell(target, visualSpellId, true)
                        end
                    end
                end
            end
        end
    
    return hitCount
end"""
        if target in content:
            content = content.replace(target, replacement)
            with open(p, 'w', encoding='utf-8') as f:
                f.write(content)
            print(f"Successfully fixed WildStarTelegraph.lua: {p}")
        else:
            print(f"Target not found in {p}")

if __name__ == '__main__':
    fix_ws_races()
    fix_telegraph_server_lua()
