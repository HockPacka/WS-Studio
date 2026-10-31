SEX_MALE=2;SEX_FEMALE=3
local sex=SEX_MALE
function GetSelectedSex() return sex end
function strupper(s) return string.upper(s) end
local selected="WSMordesh"
function GetNameForRace() return "race",selected end
function CharacterCreateEnumerateRaces() end
function SetCharacterRace(key) selected=key end
function SetCharacterGender(value) sex=value end
local function Texture()
 return {SetTexture=function(self,p)self.path=p end,SetTexCoord=function(self,...)self.coords={...} end}
end
CharacterCreateRaceIcon=Texture()
RACE_ICON_TCOORDS={HUMAN_MALE={0,.125,0,.25},HUMAN_FEMALE={0,.125,.5,.75}}
for i=1,9 do _G['CharacterCreateRaceButton'..i..'NormalTexture']=Texture();_G['CharacterCreateRaceButton'..i..'PushedTexture']=Texture() end
dofile('tools/client/WSRaceIcons.lua')
local races={'WSHuman','WSGranok','WSAurin','WSMordesh','WSCassian','WSDraken','WSMechari','WSChua'}
for _,gender in ipairs({SEX_MALE,SEX_FEMALE})do
 SetCharacterGender(gender)
 for _,race in ipairs(races)do
  SetCharacterRace(race)
  assert(string.find(CharacterCreateRaceIcon.path,'Interface\\WildStar\\Races\\',1,true))
  assert(CharacterCreateRaceIcon.coords[1]==0 and CharacterCreateRaceIcon.coords[2]==1)
 end
 CharacterCreateEnumerateRaces('Race','WSMordesh',1,'Human','Human',1)
 assert(string.find(CharacterCreateRaceButton1NormalTexture.path,'Mordesh',1,true))
 assert(CharacterCreateRaceButton1PushedTexture.path==CharacterCreateRaceButton1NormalTexture.path)
 assert(CharacterCreateRaceButton2NormalTexture.path=='Interface\\Glues\\CharacterCreate\\UI-CharacterCreate-Races')
 SetCharacterRace('Human')
 assert(CharacterCreateRaceIcon.path=='Interface\\Glues\\CharacterCreate\\UI-CharacterCreate-RacesRound')
 assert(CharacterCreateRaceIcon.coords[3]==(gender==SEX_MALE and 0 or .5))
end
