"""
tools/patch_char_create_menu.py
Bottom-anchored Character Creation UI:
Anchors Classes and Customization from the BOTTOM of CharacterCreateConfigurationFrame
so they never collide with the race buttons at the top, and fit strictly inside their designated framed sections.

Three Distinct Visual Frames:
1. Top Section ("TRENNER"):
   - Separator Line 1 (y = 376)
   - Gender Label ("Male" / "Female") at y = 358
   - Gender Buttons (Male left, Female right) at y = 328
   - Separator Line 2 (y = 304)

2. Middle Section ("CLASSES"):
   - Headers: "WoW Classes" (x = -114, y = 282) and "WildStar Classes" (x = 114, y = 282)
   - Row 1 (upper, y = 248): WoW 1..5 left, WildStar 1..3 right
   - Row 2 (lower, y = 212): WoW 6..10 left, WildStar 4..6 right
   - Separator Line 3 (y = 192)

3. Bottom Section ("COSTUM OPTION"):
   - Header: "CUSTOMIZATION" at y = 170
   - Customization Buttons (2 columns: left 1..4, right 5..7):
     Row 1: y = 142 (Skin Color / Facial Hair)
     Row 2: y = 114 (Face Style / Eye Color)
     Row 3: y = 86  (Hair Style / Body Type)
     Row 4: y = 58  (Hair Color)
   - Randomize Button at y = 20
"""

from pathlib import Path
import sys

XML_PATH_1 = Path("WoWClient/WoWOverride/Interface/GlueXML/CharacterCreate.xml")
XML_PATH_2 = Path("build_wildstar/wildstar335a/client/WoWOverride/Interface/GlueXML/CharacterCreate.xml")
LUA_PATH_1 = Path("WoWClient/WoWOverride/Interface/GlueXML/WSRaces.lua")
LUA_PATH_2 = Path("build_wildstar/wildstar335a/client/WoWOverride/Interface/GlueXML/WSRaces.lua")

def generate_xml_content():
    with open(XML_PATH_1, "r", encoding="utf-8") as f:
        content = f.read()

    # 1. WS Button Template
    ws_template = '''	<CheckButton name="CharacterCreateWSClassButtonTemplate" inherits="CharacterCreateIconButtonTemplate" virtual="true">
		<Scripts>
			<OnClick>
				if ( self.enable ) then
					WS_ClassButton_OnClick(self);
					CharacterCreateTooltip:Hide();
				end
			</OnClick>
			<OnEnter>
				GlueTooltip_SetOwner(self, CharacterCreateTooltip, -3, -5);
				GlueTooltip_SetText(self.tooltip, CharacterCreateTooltip);
			</OnEnter>
			<OnLeave>
				CharacterCreateTooltip:Hide();
			</OnLeave>
		</Scripts>
		<NormalTexture name="$parentNormalTexture"/>
		<PushedTexture name="$parentPushedTexture">
			<Size x="38" y="38"/>
			<Anchors>
				<Anchor point="CENTER" x="2" y="-2"/>
			</Anchors>
		</PushedTexture>
	</CheckButton>
'''
    if "CharacterCreateWSClassButtonTemplate" not in content:
        target = '</CheckButton>\n\t<CheckButton name="CharacterCreateGenderButtonTemplate"'
        replacement = '</CheckButton>\n' + ws_template + '\t<CheckButton name="CharacterCreateGenderButtonTemplate"'
        if target in content:
            content = content.replace(target, replacement, 1)

    # 2. Update FontStrings & Separators in <Layers> of configuration frame (anchored from BOTTOM)
    fs_start = content.find('<Texture name="CharacterCreateSeparator1"')
    if fs_start == -1:
        fs_start = content.find('<FontString name="CharacterCreateGender"')
    fs_end = content.find('</Layer>\n\t\t\t\t\t\t</Layers>', fs_start)
    if fs_start != -1 and fs_end != -1:
        new_layers = '''<Texture name="CharacterCreateSeparator1">
									<Size x="420" y="2"/>
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="376"/>
									</Anchors>
									<Color r="0.8" g="0.65" b="0.2" a="0.6"/>
								</Texture>
								<Texture name="CharacterCreateSeparator2">
									<Size x="420" y="2"/>
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="304"/>
									</Anchors>
									<Color r="0.8" g="0.65" b="0.2" a="0.6"/>
								</Texture>
								<Texture name="CharacterCreateSeparator3">
									<Size x="420" y="2"/>
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="192"/>
									</Anchors>
									<Color r="0.8" g="0.65" b="0.2" a="0.6"/>
								</Texture>
								<FontString name="CharacterCreateGender" inherits="GlueFontNormalSmall">
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="358"/>
									</Anchors>
									<Color r="1.0" g="0.82" b="0.0"/>
								</FontString>
								<FontString name="CharacterCreateWoWClassesLabel" inherits="GlueFontNormalLarge" text="WoW Classes" justifyH="CENTER">
									<Size x="190" y="18"/>
									<Anchors>
										<Anchor point="BOTTOM" x="-114" y="282"/>
									</Anchors>
									<Color r="1.0" g="0.82" b="0.0"/>
								</FontString>
								<FontString name="CharacterCreateWSClassesLabel" inherits="GlueFontNormalLarge" text="WildStar Classes" justifyH="CENTER">
									<Size x="190" y="18"/>
									<Anchors>
										<Anchor point="BOTTOM" x="114" y="282"/>
									</Anchors>
									<Color r="0.48" g="0.88" b="1.0"/>
								</FontString>
								<FontString name="CharacterCreateCustomizationLabel" inherits="GlueFontNormalLarge" text="CUSTOMIZATION" justifyH="CENTER">
									<Size x="200" y="18"/>
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="170"/>
									</Anchors>
									<Color r="1.0" g="0.82" b="0.0"/>
								</FontString>
								<FontString name="CharacterCreateClassName" inherits="CharacterCreateTooltipFont">
									<Size x="0" y="0"/>
									<Anchors>
										<Anchor point="BOTTOM" x="0" y="-1000"/>
									</Anchors>
								</FontString>
							'''
        content = content[:fs_start] + new_layers + content[fs_end:]

    # 3. Replace Gender, Class, Customization, and Randomize buttons in <Frames> (anchored from BOTTOM)
    frames_start = content.find('<!-- Gender Selection:')
    if frames_start == -1:
        frames_start = content.find('<CheckButton name="CharacterCreateGenderButtonMale"')
    frames_end = content.find('<EditBox name="CharacterCreateNameEdit"')
    block_end = content.rfind('</Frames>', frames_start, frames_end)

    new_frames_snippet = '''<!-- Gender Selection: In TRENNER section, anchored from BOTTOM -->
							<CheckButton name="CharacterCreateGenderButtonMale" inherits="CharacterCreateGenderButtonTemplate" scale="0.78">
								<Anchors>
									<Anchor point="BOTTOM" x="-26" y="328"/>
								</Anchors>
								<Scripts>
									<OnLoad>
										_G[self:GetName().."NormalTexture"]:SetTexCoord(0, 0.5, 0, 1.0);
										_G[self:GetName().."PushedTexture"]:SetTexCoord(0, 0.5, 0, 1.0);
									</OnLoad>
									<OnClick>
										PlaySound("gsCharacterCreationClass");
										if ( GetSelectedSex() ~= SEX_MALE ) then
											SetCharacterGender(SEX_MALE);
										end
									</OnClick>
									<OnEnter>
										GlueTooltip_SetOwner(self, CharacterCreateTooltip, -3, -5);
										GlueTooltip_SetText(MALE, CharacterCreateTooltip);
									</OnEnter>
								</Scripts>
							</CheckButton>
							<CheckButton name="CharacterCreateGenderButtonFemale" inherits="CharacterCreateGenderButtonTemplate" scale="0.78">
								<Anchors>
									<Anchor point="BOTTOM" x="26" y="328"/>
								</Anchors>
								<Scripts>
									<OnLoad>
										_G[self:GetName().."NormalTexture"]:SetTexCoord(0.5, 1.0, 0, 1.0);
										_G[self:GetName().."PushedTexture"]:SetTexCoord(0.5, 1.0, 0, 1.0);
									</OnLoad>
									<OnClick>
										PlaySound("gsCharacterCreationClass");
										if ( GetSelectedSex() ~= SEX_FEMALE ) then
											SetCharacterGender(SEX_FEMALE);
										end
									</OnClick>
									<OnEnter>
										GlueTooltip_SetOwner(self, CharacterCreateTooltip, -3, -5);
										GlueTooltip_SetText(FEMALE, CharacterCreateTooltip);
									</OnEnter>
								</Scripts>
							</CheckButton>

							<!-- Left Side: WoW Classes (10 classes: 5 cols x 2 rows, Left to Right, anchored from BOTTOM) -->
							<!-- Row 1 (upper row at y = 248): 1 (Warrior), 2 (Paladin), 3 (Hunter), 4 (Rogue), 5 (Priest) -->
							<CheckButton name="CharacterCreateClassButton1" inherits="CharacterCreateClassButtonTemplate" id="1" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-190" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton2" inherits="CharacterCreateClassButtonTemplate" id="2" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-152" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton3" inherits="CharacterCreateClassButtonTemplate" id="3" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-114" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton4" inherits="CharacterCreateClassButtonTemplate" id="4" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-76" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton5" inherits="CharacterCreateClassButtonTemplate" id="5" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-38" y="248"/>
								</Anchors>
							</CheckButton>
							<!-- Row 2 (lower row at y = 212): 6 (Death Knight), 7 (Shaman), 8 (Mage), 9 (Warlock), 10 (Druid) -->
							<CheckButton name="CharacterCreateClassButton6" inherits="CharacterCreateClassButtonTemplate" id="6" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-190" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton7" inherits="CharacterCreateClassButtonTemplate" id="7" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-152" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton8" inherits="CharacterCreateClassButtonTemplate" id="8" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-114" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton9" inherits="CharacterCreateClassButtonTemplate" id="9" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-76" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateClassButton10" inherits="CharacterCreateClassButtonTemplate" id="10" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="-38" y="212"/>
								</Anchors>
							</CheckButton>

							<!-- Right Side: WildStar Classes (6 classes: 3 cols x 2 rows, Left to Right, anchored from BOTTOM) -->
							<!-- Row 1 (upper row at y = 248): 1 (Warrior), 2 (Engineer), 3 (Esper) -->
							<CheckButton name="CharacterCreateWSClassButton1" inherits="CharacterCreateWSClassButtonTemplate" id="1" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="64" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateWSClassButton2" inherits="CharacterCreateWSClassButtonTemplate" id="2" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="114" y="248"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateWSClassButton3" inherits="CharacterCreateWSClassButtonTemplate" id="3" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="164" y="248"/>
								</Anchors>
							</CheckButton>
							<!-- Row 2 (lower row at y = 212): 4 (Medic), 5 (Stalker), 6 (Spellslinger) -->
							<CheckButton name="CharacterCreateWSClassButton4" inherits="CharacterCreateWSClassButtonTemplate" id="4" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="64" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateWSClassButton5" inherits="CharacterCreateWSClassButtonTemplate" id="5" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="114" y="212"/>
								</Anchors>
							</CheckButton>
							<CheckButton name="CharacterCreateWSClassButton6" inherits="CharacterCreateWSClassButtonTemplate" id="6" scale="0.75">
								<Anchors>
									<Anchor point="BOTTOM" x="164" y="212"/>
								</Anchors>
							</CheckButton>

							<!-- Customization: Left column (1-4), Right column (5-7), anchored from BOTTOM -->
							<Frame name="CharacterCustomizationButtonFrame1" inherits="CharacterCustomizationFrameTemplate" id="1" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="-105" y="142"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame2" inherits="CharacterCustomizationFrameTemplate" id="2" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="-105" y="114"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame3" inherits="CharacterCustomizationFrameTemplate" id="3" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="-105" y="86"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame4" inherits="CharacterCustomizationFrameTemplate" id="4" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="-105" y="58"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame5" inherits="CharacterCustomizationFrameTemplate" id="5" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="105" y="142"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame6" inherits="CharacterCustomizationFrameTemplate" id="6" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="105" y="114"/>
								</Anchors>
							</Frame>
							<Frame name="CharacterCustomizationButtonFrame7" inherits="CharacterCustomizationFrameTemplate" id="7" scale="0.74">
								<Anchors>
									<Anchor point="BOTTOM" x="105" y="86"/>
								</Anchors>
							</Frame>

							<!-- Randomize Button: Anchored at BOTTOM -->
							<Button name="CharCreateRandomizeButton" inherits="GlueButtonSmallTemplate" text="RANDOMIZE">
								<Size x="146" y="30"/>
								<Anchors>
									<Anchor point="BOTTOM" x="0" y="20"/>
								</Anchors>
								<Scripts>
									<OnLoad>
										self:SetWidth(self:GetTextWidth() + 50);
									</OnLoad>
									<OnClick>
										CharacterCreate_Randomize();
									</OnClick>
									<OnUpdate>
										CharacterCreate_DeathKnightSwap(self);
									</OnUpdate>
								</Scripts>
							</Button>
'''
    content = content[:frames_start] + new_frames_snippet + content[block_end:]
    return content

def generate_lua_content():
    with open(LUA_PATH_1, "r", encoding="utf-8") as f:
        existing = f.read()

    cut_idx = existing.find("WS_CLASS_INFO = {")
    if cut_idx == -1:
        raise RuntimeError("Could not find WS_CLASS_INFO in WSRaces.lua")
    header_part = existing[:cut_idx]

    # Standard race coordinates (TOP, x, -75 - (row-1)*46)
    header_part = header_part.replace('-65-(row-1)*38', '-75-(row-1)*46')
    header_part = header_part.replace('-65-(row-1)*42', '-75-(row-1)*46')

    lua_body = '''WS_CLASS_INFO = {
	["WARRIOR"] = {
		name = "Warrior",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Warrior.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Warrior_Round.tga",
		roles = "Role: Tank, Melee Damage",
		desc = "When it comes to combat, the Warrior is an unstoppable juggernaut, destroying his enemies with a combination of brute force and deadly weaponry. Warriors solve problems the old-fashioned way - cutting down enemies with their swords and ripsaw shields, or blasting them to pieces with a trusty arm cannon.",
	},
	["WARLOCK"] = {
		name = "Engineer",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Engineer.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Engineer_Round.tga",
		roles = "Role: Tank, Ranged Damage",
		desc = "The Engineer utilizes a technological mastery to craft the right tool for any situation - most notably ones where heavy firepower is a necessity. Armed with heavy launchers, combat bot companions, and reinforced exo-suits, Engineers command the battlefield with unmatched explosive firepower.",
	},
	["MAGE"] = {
		name = "Esper",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Esper.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Esper_Round.tga",
		roles = "Role: Healer, Ranged Damage",
		desc = "Espers are masters of illusion, attacking their enemies with powerful psychic weapons and projecting inspiring visions to heal their friends and allies. Combat with an Esper is a deadly phantasmal dance that leaves their foes bewildered and broken.",
	},
	["PRIEST"] = {
		name = "Medic",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Medic.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Medic_Round.tga",
		roles = "Role: Healer, Melee Damage",
		desc = "The battlefield is a violent, chaotic place, and no one understands this better than the Medic. Armed with dual resonators that can heal wounded allies or damage deadly foes, the Medic is a versatile hybrid who uses fields and probes to control the battle.",
	},
	["ROGUE"] = {
		name = "Stalker",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Stalker.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Stalker_Round.tga",
		roles = "Role: Tank, Melee Damage",
		desc = "The Stalker is a shadowy assassin who relies on stealth, guile, and deadly claw weapons to dispatch enemies from behind. Equipped with advanced nano-skin technology and tactical devices, the Stalker strikes unseen and escapes undetected.",
	},
	["HUNTER"] = {
		name = "Spellslinger",
		icon = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger.tga",
		roundIcon = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger_Round.tga",
		roles = "Role: Healer, Ranged Damage",
		desc = "The Spellslinger is a steely-eyed gun-for-hire, using deadly precision and acrobatic agility to put his enemies in the ground. With a lethal combination of hair-trigger pistols and powerful magic, the Spellslinger is a dangerous foe - blasting enemies with a deadly barrage of bullets or casting runic sigils that sow destruction and death.",
	},
}

-- Mapping of the 6 WildStar classes for the Character Creation buttons
-- Row 1 (upper, y = 248): Warrior (1), Engineer (2), Esper (3)
-- Row 2 (lower, y = 212): Medic (4), Stalker (5), Spellslinger (6)
WS_CLASSES = {
	[1] = { name = "Warrior", classIndex = 1, file = "WARRIOR", icon = "Interface\\\\WildStar\\\\Classes\\\\Warrior.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Warrior_Round.tga" },
	[2] = { name = "Engineer", classIndex = 9, file = "WARLOCK", icon = "Interface\\\\WildStar\\\\Classes\\\\Engineer.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Engineer_Round.tga" },
	[3] = { name = "Esper", classIndex = 8, file = "MAGE", icon = "Interface\\\\WildStar\\\\Classes\\\\Esper.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Esper_Round.tga" },
	[4] = { name = "Medic", classIndex = 5, file = "PRIEST", icon = "Interface\\\\WildStar\\\\Classes\\\\Medic.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Medic_Round.tga" },
	[5] = { name = "Stalker", classIndex = 4, file = "ROGUE", icon = "Interface\\\\WildStar\\\\Classes\\\\Stalker.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Stalker_Round.tga" },
	[6] = { name = "Spellslinger", classIndex = 3, file = "HUNTER", icon = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger.tga", round = "Interface\\\\WildStar\\\\Classes\\\\Spellslinger_Round.tga" },
}

local function IsWildStarRaceSelected()
	local _, raceKey = GetNameForRace()
	if not raceKey then return false end
	return string.sub(strupper(raceKey), 1, 2) == "WS"
end

-- Layout and position all class, gender, and customization buttons strictly inside their designated frames
function WS_LayoutButtons()
	-- Frame 1: Top Separator (Line 1)
	if CharacterCreateSeparator1 then
		CharacterCreateSeparator1:ClearAllPoints()
		CharacterCreateSeparator1:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 376)
	end

	-- Frame 1: Gender Controls (anchored from BOTTOM)
	if CharacterCreateGender then
		CharacterCreateGender:ClearAllPoints()
		CharacterCreateGender:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 358)
	end
	if CharacterCreateGenderButtonMale then
		CharacterCreateGenderButtonMale:ClearAllPoints()
		CharacterCreateGenderButtonMale:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", -26, 328)
		CharacterCreateGenderButtonMale:SetScale(0.78)
	end
	if CharacterCreateGenderButtonFemale then
		CharacterCreateGenderButtonFemale:ClearAllPoints()
		CharacterCreateGenderButtonFemale:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 26, 328)
		CharacterCreateGenderButtonFemale:SetScale(0.78)
	end

	-- Frame 1/2: Middle Separator (Line 2, divides Gender from Classes)
	if CharacterCreateSeparator2 then
		CharacterCreateSeparator2:ClearAllPoints()
		CharacterCreateSeparator2:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 304)
	end

	-- Frame 2: Class Headers (anchored from BOTTOM)
	if CharacterCreateWoWClassesLabel then
		CharacterCreateWoWClassesLabel:ClearAllPoints()
		CharacterCreateWoWClassesLabel:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", -114, 282)
	end
	if CharacterCreateWSClassesLabel then
		CharacterCreateWSClassesLabel:ClearAllPoints()
		CharacterCreateWSClassesLabel:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 114, 282)
	end

	-- Frame 2 Left Side: WoW Classes (10 classes: 5 cols x 2 rows, Left to Right, anchored from BOTTOM)
	-- Row 1 (upper, y = 248): 1..5 at x = -190, -152, -114, -76, -38
	-- Row 2 (lower, y = 212): 6..10 at x = -190, -152, -114, -76, -38
	local wow_coords = {
		{ -190, 248 }, { -152, 248 }, { -114, 248 }, { -76, 248 }, { -38, 248 },
		{ -190, 212 }, { -152, 212 }, { -114, 212 }, { -76, 212 }, { -38, 212 },
	}
	for i = 1, 10 do
		local btn = _G["CharacterCreateClassButton"..i]
		if btn then
			btn:ClearAllPoints()
			btn:SetParent(CharacterCreateConfigurationFrame)
			btn:SetScale(0.75)
			btn:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", wow_coords[i][1], wow_coords[i][2])
			btn:Show()
		end
	end

	-- Frame 2 Right Side: WildStar Classes (6 classes: 3 cols x 2 rows, Left to Right, anchored from BOTTOM)
	-- Row 1 (upper, y = 248): 1 (Warrior), 2 (Engineer), 3 (Esper) at x = 64, 114, 164
	-- Row 2 (lower, y = 212): 4 (Medic), 5 (Stalker), 6 (Spellslinger) at x = 64, 114, 164
	local ws_coords = {
		{ 64, 248 },  { 114, 248 }, { 164, 248 },
		{ 64, 212 },  { 114, 212 }, { 164, 212 },
	}
	for k = 1, 6 do
		local wsBtn = _G["CharacterCreateWSClassButton"..k]
		if wsBtn then
			wsBtn:ClearAllPoints()
			wsBtn:SetParent(CharacterCreateConfigurationFrame)
			wsBtn:SetScale(0.75)
			wsBtn:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", ws_coords[k][1], ws_coords[k][2])
			wsBtn.classIndex = WS_CLASSES[k].classIndex
			wsBtn.name = WS_CLASSES[k].name
			wsBtn.tooltip = WS_CLASSES[k].name

			local normal = _G["CharacterCreateWSClassButton"..k.."NormalTexture"]
			local pushed = _G["CharacterCreateWSClassButton"..k.."PushedTexture"]
			if normal then
				normal:SetTexture(WS_CLASSES[k].icon)
				normal:SetTexCoord(0, 1, 0, 1)
			end
			if pushed then
				pushed:SetTexture(WS_CLASSES[k].icon)
				pushed:SetTexCoord(0, 1, 0, 1)
			end
			wsBtn:Show()
		end
	end

	-- Frame 2/3: Bottom Separator (Line 3, divides Classes from Customization)
	if CharacterCreateSeparator3 then
		CharacterCreateSeparator3:ClearAllPoints()
		CharacterCreateSeparator3:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 192)
	end

	-- Frame 3: Customization Header (anchored from BOTTOM)
	if CharacterCreateCustomizationLabel then
		CharacterCreateCustomizationLabel:ClearAllPoints()
		CharacterCreateCustomizationLabel:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 170)
	end

	-- Frame 3: Customization Frames: Col 1 (1-4) on left (x = -105), Col 2 (5-7) on right (x = 105)
	-- Row 1: y = 142 (Skin Color / Facial Hair)
	-- Row 2: y = 114 (Face Style / Eye Color)
	-- Row 3: y = 86  (Hair Style / Body Type)
	-- Row 4: y = 58  (Hair Color)
	local cust_bottom_coords = {
		{ -105, 142 }, { -105, 114 }, { -105, 86 }, { -105, 58 },
		{  105, 142 }, {  105, 114 }, {  105, 86 },
	}
	for i = 1, 7 do
		local frame = _G["CharacterCustomizationButtonFrame"..i]
		if frame then
			frame:ClearAllPoints()
			frame:SetParent(CharacterCreateConfigurationFrame)
			frame:SetScale(0.74)
			frame:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", cust_bottom_coords[i][1], cust_bottom_coords[i][2])
		end
	end

	-- Frame 3: Randomize Button: anchored from BOTTOM at y = 20
	if CharCreateRandomizeButton then
		CharCreateRandomizeButton:ClearAllPoints()
		CharCreateRandomizeButton:SetParent(CharacterCreateConfigurationFrame)
		CharCreateRandomizeButton:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, 20)
	end

	-- Hide center label to avoid collision
	if CharacterCreateClassName then
		CharacterCreateClassName:SetText("")
		CharacterCreateClassName:ClearAllPoints()
		CharacterCreateClassName:SetPoint("BOTTOM", CharacterCreateConfigurationFrame, "BOTTOM", 0, -1000)
	end
end

-- Handler for WildStar Class button clicks
function WS_ClassButton_OnClick(self)
	if not self.enable then return end
	PlaySound("gsCharacterCreationClass")
	local id = self.classIndex
	local currRace = GetSelectedRace()
	local _, _, currClass = GetSelectedClass()
	if currClass ~= id and IsRaceClassValid(currRace, id) then
		SetSelectedClass(id)
		SetCharacterClass(id)
		SetCharacterRace(currRace)
		CharacterChangeFixup()
	else
		self:SetChecked(1)
	end
end

-- Update enabled/disabled, gray desaturation, checked border, and tooltips for ALL 16 class buttons
function WS_UpdateAllClassButtons()
	local isWS = IsWildStarRaceSelected()
	local raceIndex = GetSelectedRace()
	local _, classFileName, selectedClassIndex = GetSelectedClass()

	if isWS then
		-- A WildStar race is selected:
		-- WoW buttons (1..10) are locked & grayed out
		for i = 1, 10 do
			local btn = _G["CharacterCreateClassButton"..i]
			if btn then
				btn.enable = false
				btn:Disable()
				SetButtonDesaturated(btn, 1)
				btn:SetChecked(0)
				btn.tooltip = (btn.name or "Class") .. " (Available for WoW races)"
				btn:Show()
			end
		end

		-- WildStar buttons (1..6) are active if valid for this WS race
		for k = 1, 6 do
			local wsBtn = _G["CharacterCreateWSClassButton"..k]
			local info = WS_CLASSES[k]
			if wsBtn and info then
				local valid = IsRaceClassValid(raceIndex, info.classIndex)
				if valid then
					wsBtn.enable = true
					wsBtn:Enable()
					SetButtonDesaturated(wsBtn, 0)
					wsBtn.tooltip = info.name
				else
					wsBtn.enable = false
					wsBtn:Disable()
					SetButtonDesaturated(wsBtn, 1)
					wsBtn.tooltip = info.name .. " (Not available for this race)"
				end

				if info.classIndex == selectedClassIndex then
					wsBtn:SetChecked(1)
				else
					wsBtn:SetChecked(0)
				end
				wsBtn:Show()
			end
		end

		-- Right-hand info panel: WildStar class details
		local cInfo = WS_CLASS_INFO[strupper(classFileName or "")]
		if cInfo then
			if CharacterCreateClassLabel then
				CharacterCreateClassLabel:SetText(cInfo.name)
			end
			if CharacterCreateClassIcon then
				CharacterCreateClassIcon:SetTexture(cInfo.roundIcon or cInfo.icon)
				CharacterCreateClassIcon:SetTexCoord(0, 1, 0, 1)
			end
			if CharacterCreateClassRolesText then
				CharacterCreateClassRolesText:SetText(cInfo.roles)
			end
			if CharacterCreateClassText then
				CharacterCreateClassText:SetText(cInfo.desc .. "\\n\\n")
			end
		end
	else
		-- A standard WoW race is selected:
		-- WoW buttons (1..10) are active if valid for this WoW race
		for i = 1, 10 do
			local btn = _G["CharacterCreateClassButton"..i]
			if btn then
				local valid = IsRaceClassValid(raceIndex, i)
				if valid then
					btn.enable = true
					btn:Enable()
					SetButtonDesaturated(btn, 0)
					btn.tooltip = btn.name
				else
					btn.enable = false
					btn:Disable()
					SetButtonDesaturated(btn, 1)
					btn.tooltip = (btn.name or "Class") .. " (Not available for this race)"
				end

				if i == selectedClassIndex then
					btn:SetChecked(1)
				else
					btn:SetChecked(0)
				end
				btn:Show()
			end
		end

		-- WildStar buttons (1..6) are locked & grayed out
		for k = 1, 6 do
			local wsBtn = _G["CharacterCreateWSClassButton"..k]
			local info = WS_CLASSES[k]
			if wsBtn and info then
				wsBtn.enable = false
				wsBtn:Disable()
				SetButtonDesaturated(wsBtn, 1)
				wsBtn:SetChecked(0)
				wsBtn.tooltip = info.name .. " (Available for WildStar races)"
				wsBtn:Show()
			end
		end
	end

	-- Keep center class name clean to avoid text collision
	if CharacterCreateClassName then
		CharacterCreateClassName:SetText("")
	end
end

-- Hook CharacterCreateEnumerateClasses
local WS_OriginalEnumerateClasses = CharacterCreateEnumerateClasses
function CharacterCreateEnumerateClasses(...)
	WS_OriginalEnumerateClasses(...)
	WS_LayoutButtons()
	WS_UpdateAllClassButtons()
end

-- Hook SetCharacterClass
local WS_OriginalSetCharacterClass = SetCharacterClass
function SetCharacterClass(id)
	WS_OriginalSetCharacterClass(id)
	WS_UpdateAllClassButtons()
end

-- Hook CharacterCreate_OnShow
local WS_OriginalOnShow = CharacterCreate_OnShow
function CharacterCreate_OnShow()
	if WS_OriginalOnShow then WS_OriginalOnShow() end
	WS_LayoutButtons()
	WS_UpdateAllClassButtons()
	if WS_UpdateCustomizationLabels then WS_UpdateCustomizationLabels() end
end

-- Initial button layout
WS_LayoutButtons()
'''
    return header_part + lua_body

def main():
    print("Generating XML content...")
    new_xml = generate_xml_content()
    for xml_path in (XML_PATH_1, XML_PATH_2):
        if xml_path.parent.exists():
            with open(xml_path, "w", encoding="utf-8") as f:
                f.write(new_xml)
            print(f"Updated {xml_path} ({len(new_xml)} bytes)")

    print("Generating LUA content...")
    new_lua = generate_lua_content()
    for lua_path in (LUA_PATH_1, LUA_PATH_2):
        if lua_path.parent.exists():
            with open(lua_path, "w", encoding="utf-8") as f:
                f.write(new_lua)
            print(f"Updated {lua_path} ({len(new_lua)} bytes)")

    print("Character Creation menu successfully patched!")

if __name__ == "__main__":
    main()
