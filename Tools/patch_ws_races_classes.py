from pathlib import Path

target_file = Path('WoWClient/WoWOverride/Interface/GlueXML/WSRaces.lua')
content = target_file.read_text(encoding='utf-8')

addition = """
-- ============================================================================
-- Authentic WildStar Classes System for Character Creation
-- ============================================================================

WS_CLASS_INFO = {
\t["WARRIOR"] = {
\t\tname = "Warrior",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Warrior.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Warrior_Round.tga",
\t\troles = "Role: Tank, Melee Damage",
\t\tdesc = "When it comes to combat, the Warrior is an unstoppable juggernaut, destroying his enemies with a combination of brute force and deadly weaponry. Warriors solve problems the old-fashioned way - cutting down enemies with their swords and ripsaw shields, or blasting them to pieces with a trusty arm cannon.",
\t},
\t["WARLOCK"] = {
\t\tname = "Engineer",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Engineer.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Engineer_Round.tga",
\t\troles = "Role: Tank, Ranged Damage",
\t\tdesc = "The Engineer utilizes a technological mastery to craft the right tool for any situation - most notably ones where heavy firepower is a necessity. Armed with heavy launchers, combat bot companions, and reinforced exo-suits, Engineers command the battlefield with unmatched explosive firepower.",
\t},
\t["MAGE"] = {
\t\tname = "Esper",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Esper.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Esper_Round.tga",
\t\troles = "Role: Healer, Ranged Damage",
\t\tdesc = "Espers are masters of illusion, attacking their enemies with powerful psychic weapons and projecting inspiring visions to heal their friends and allies. Combat with an Esper is a deadly phantasmal dance that torments enemies with their darkest fears before pushing them over the edge of madness.",
\t},
\t["PRIEST"] = {
\t\tname = "Medic",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Medic.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Medic_Round.tga",
\t\troles = "Role: Healer, Medium-range Damage",
\t\tdesc = "Medics thrive when submersed in battle, healing those that fight with them and crushing those that stand before them. Equipped with dual shock resonators and holographic actuator fields, Medics mend wounded flesh and shield allies while annihilating foes at close quarters.",
\t},
\t["ROGUE"] = {
\t\tname = "Stalker",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Stalker.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Stalker_Round.tga",
\t\troles = "Role: Tank, Melee Damage",
\t\tdesc = "The Stalker strikes ferociously with his claws, using advanced stealth technology to deal multiple blows to his enemies. The Stalker also uses a mix of technological abilities to tactically control the battlefield, leaving a pile of corpses in his wake.",
\t},
\t["HUNTER"] = {
\t\tname = "Spellslinger",
\t\ticon = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger.tga",
\t\troundIcon = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger_Round.tga",
\t\troles = "Role: Healer, Ranged Damage",
\t\tdesc = "The Spellslinger is a steely-eyed gun-for-hire, using deadly precision and acrobatic agility to put his enemies in the ground. With a lethal combination of hair-trigger pistols and powerful magic, the Spellslinger is a dangerous foe - blasting enemies with a deadly barrage of bullets or casting runic sigils that sow destruction and death.",
\t},
}

local function IsWildStarRaceSelected()
\tlocal _, raceKey = GetNameForRace()
\tif not raceKey then return false end
\treturn string.sub(strupper(raceKey), 1, 2) == "WS"
end

local WS_OriginalEnumerateClasses = CharacterCreateEnumerateClasses
function CharacterCreateEnumerateClasses(...)
\tWS_OriginalEnumerateClasses(...)

\tlocal isWS = IsWildStarRaceSelected()
\tlocal index = 1

\tfor i = 1, select("#", ...), 3 do
\t\tlocal cKey = strupper(select(i + 1, ...) or "")
\t\tlocal button = _G["CharacterCreateClassButton"..index]
\t\tlocal normalTex = _G["CharacterCreateClassButton"..index.."NormalTexture"]
\t\tlocal pushedTex = _G["CharacterCreateClassButton"..index.."PushedTexture"]

\t\tif button then
\t\t\tbutton:ClearAllPoints()

\t\t\tif isWS then
\t\t\t\tlocal info = WS_CLASS_INFO[cKey]
\t\t\t\tif info then
\t\t\t\t\tbutton.name = info.name
\t\t\t\t\tbutton.tooltip = info.name

\t\t\t\t\tif normalTex then
\t\t\t\t\t\tnormalTex:SetTexture(info.icon)
\t\t\t\t\t\tnormalTex:SetTexCoord(0, 1, 0, 1)
\t\t\t\t\tend
\t\t\t\t\tif pushedTex then
\t\t\t\t\t\tpushedTex:SetTexture(info.icon)
\t\t\t\t\t\tpushedTex:SetTexCoord(0, 1, 0, 1)
\t\t\t\t\tend
\t\t\t\tend

\t\t\t\t-- Position right under the WildStar races in two neat columns
\t\t\t\t-- Column 1: x = 50 (under Exiles), Column 2: x = 150 (under Dominion)
\t\t\t\tlocal col = (index - 1) % 2
\t\t\t\tlocal row = math.floor((index - 1) / 2)
\t\t\t\tlocal x = (col == 0) and 50 or 150
\t\t\t\tlocal y = -285 - (row * 50)

\t\t\t\tbutton:SetParent(CharacterCreateConfigurationFrame)
\t\t\t\tbutton:SetScale(1)
\t\t\t\tbutton:SetPoint("TOP", CharacterCreateConfigurationFrame, "TOP", x, y)
\t\t\telse
\t\t\t\t-- Standard WoW Layout at bottom
\t\t\t\tlocal row = math.floor((index - 1) / 5)
\t\t\t\tlocal col = (index - 1) % 5
\t\t\t\tlocal x = -90 + (col * 44)
\t\t\t\tlocal y = -463 - (row * 44)

\t\t\t\tbutton:SetParent(CharacterCreateConfigurationFrame)
\t\t\t\tbutton:SetScale(1)
\t\t\t\tbutton:SetPoint("TOP", CharacterCreateConfigurationFrame, "TOP", x, y)

\t\t\t\tlocal coords = CLASS_ICON_TCOORDS[cKey]
\t\t\t\tif coords then
\t\t\t\t\tif normalTex then
\t\t\t\t\t\tnormalTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\t\tnormalTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\t\tend
\t\t\t\tif pushedTex then
\t\t\t\t\tpushedTex:SetTexture("Interface\\\\Glues\\\\CharacterCreate\\\\UI-CharacterCreate-Classes")
\t\t\t\t\tpushedTex:SetTexCoord(coords[1], coords[2], coords[3], coords[4])
\t\t\t\tend
\t\t\tend
\t\tend
\t\tindex = index + 1
\tend
end

local WS_OriginalSetCharacterClass = SetCharacterClass
function SetCharacterClass(id)
\tWS_OriginalSetCharacterClass(id)

\tif IsWildStarRaceSelected() then
\t\tlocal _, classFileName = GetSelectedClass()
\t\tlocal info = WS_CLASS_INFO[strupper(classFileName or "")]
\t\tif info then
\t\t\tif CharacterCreateClassName then
\t\t\t\tCharacterCreateClassName:SetText(info.name)
\t\t\tend
\t\t\tif CharacterCreateClassLabel then
\t\t\t\tCharacterCreateClassLabel:SetText(info.name)
\t\t\tend
\t\t\tif CharacterCreateClassIcon then
\t\t\t\tCharacterCreateClassIcon:SetTexture(info.roundIcon or info.icon)
\t\t\t\tCharacterCreateClassIcon:SetTexCoord(0, 1, 0, 1)
\t\t\tend
\t\t\tif CharacterCreateClassRolesText then
\t\t\t\tCharacterCreateClassRolesText:SetText(info.roles)
\t\t\tend
\t\t\tif CharacterCreateClassText then
\t\t\t\tCharacterCreateClassText:SetText(info.desc .. "\\n\\n")
\t\t\tend
\t\tend
\tend
end
"""

if "WS_CLASS_INFO" not in content:
    target_file.write_text(content.strip() + "\n\n" + addition.strip() + "\n", encoding='utf-8')
    print("Successfully appended WildStar Classes integration to WSRaces.lua!")
else:
    print("Already integrated in WSRaces.lua!")
