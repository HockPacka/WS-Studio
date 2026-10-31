-- Executed by the project's real Lua 5.1 host, no live DB or network.
print=print or function()end
dofile("WoWClient/Interface/WildStarDebug/ProfileProtocol.lua")
dofile("build_wildstar/wildstar335a/server/adapters/azerothcore/appearance/AppearanceCatalog.lua")
local P=WSPProtocol
local firstHuman
for id,m in pairs(WSPCatalog.models)do if m.races[22] and m.sex==0 then firstHuman=id end end
assert(firstHuman)
local f={1,firstHuman,22,0,0,0,0,0,0,0,0,0,0,0}
local profile=P.Encode({fields=f,groups={},items={4160,4161,4159,4162}})
assert(P.Parse(profile,WSPCatalog))
assert(not P.Parse(profile.."' SQL",WSPCatalog))
assert(not P.Parse("1,0,0,0,0,0,0,0,0,0,0,0,0,0;;",WSPCatalog))
local fragmented=string.rep("1234567890",100);local frames=P.Frames(fragmented);local cache={};local decoded
for i=#frames,1,-1 do decoded=P.Receive(cache,"test",frames[i],1) or decoded end
assert(decoded==fragmented)
assert(not P.Receive(cache,"x","1:1:99:a",1))
assert(not P.Receive(cache,"x",string.rep("x",241),1))
local events,timers,sql,sends={},{},{},{}
local now=100000
GetGameTime=function()return math.floor(now/1000)end
GetCurrTime=function()return now end
WorldDBQuery=function()return nil end
WorldDBExecute=function(query)sql[#sql+1]=query end
RegisterServerEvent=function(id,fn)events[id]=fn end
RegisterPlayerEvent=function()end
CreateLuaEvent=function(fn)timers[#timers+1]=fn end
local all={}
GetPlayersInWorld=function()return all end
local function unit(id,player,rank)
    local u={id=id,player=player,rank=rank or 0,native=49,display=49,dbid=player and 0 or 70001}
    function u:IsPlayer()return self.player end
    function u:ToCreature()return not self.player and self or nil end
    function u:GetDBTableGUIDLow()return self.dbid end
    function u:GetGUIDLow()return self.id end
    function u:GetUInt32Value(i)return i==0 and self.id or self.player and 0 or 4046454785 end
    function u:GetNativeDisplayId()return self.native end
    function u:GetDisplayId()return self.display end
    function u:SetNativeDisplayId(id)self.native=id end
    function u:SetDisplayId(id)self.display=id end
    function u:GetGMRank()return self.rank end
    function u:GetMapId()return 5000 end
    function u:GetInstanceId()return 0 end
    function u:GetDistance()return 5 end
    function u:GetSelection()return self.target end
    function u:GetPlayersInRange()return all end
    function u:GetCreaturesInRange()return self.target and {self.target} or {} end
    function u:SendAddonMessage(prefix,message,channel,receiver)
        assert(prefix==P.PREFIX and channel==7 and receiver==self and #message<=240)
        sends[#sends+1]={player=receiver,frame=message}
    end
    return u
end
local gm=unit(10,true,3);local viewer=unit(20,true,0);local creature=unit(900,false,0)
gm.target=creature;viewer.target=creature;all={gm,viewer}
dofile("plugins/wildstar335a/adapters/azerothcore/WildStarAppearanceServer.lua")
local function send(player,text)
    now=now+1000
    local scope,body=string.match(text,"^S|([A-Z]+)|(.*)$")
    if scope then local u=scope=="SELF" and player or player.target;text="S|"..scope.."|"..string.format("%08X%08X",u:GetUInt32Value(1),u:GetUInt32Value(0)).."|"..body end
    scope=string.match(text,"^C|([A-Z]+)$")
    if scope then local u=scope=="SELF" and player or player.target;text="C|"..scope.."|"..string.format("%08X%08X",u:GetUInt32Value(1),u:GetUInt32Value(0)) end
    for _,frame in ipairs(P.Frames(text))do assert(events[30](30,player,7,P.PREFIX,frame)==false)end
end
send(gm,"H|"..WSPCatalog.hash);send(viewer,"H|"..WSPCatalog.hash)
send(gm,"S|TARGET|"..profile)
assert(creature.native==firstHuman and creature.display==firstHuman)
assert(WildStarAppearance.HasProfile(creature) and #sql==1)
local incoming,seen={},false
for _,m in ipairs(sends)do if m.player==viewer then local message=P.Receive(incoming,"server",m.frame,GetGameTime());if message and string.sub(message,1,2)=="V|"then seen=true;assert(string.sub(message,-#profile)==profile)end end end
assert(seen,"second player did not receive the edited NPC profile")
send(viewer,"S|TARGET|"..profile);assert(#sql==1,"non-GM edited a profile")
send(gm,"S|TARGET|"..profile.."' SQL");assert(#sql==1)
creature.display=999 -- shapeshift/temporary morph must remain
timers[1]();assert(creature.display==999)
creature.display=firstHuman
send(gm,"C|TARGET");assert(creature.display==49 and creature.native==49 and not WildStarAppearance.HasProfile(creature))
send(gm,"S|SELF|"..profile);assert(WildStarAppearance.HasProfile(gm) and gm.display==firstHuman)
local savedQuery=sql[#sql]
assert(string.find(savedQuery,"'P',10",1,true))
-- Reload from persistence: new server script instances reconstruct the profile.
WorldDBQuery=function()
    return {GetString=function(_,i)return i==0 and "P" or profile end,GetUInt32=function(_,i)return i==1 and 10 or i==2 and firstHuman or 49 end,NextRow=function()return false end}
end
dofile("plugins/wildstar335a/adapters/azerothcore/WildStarAppearanceServer.lua")
assert(WildStarAppearance.HasProfile(gm));gm.native=49;gm.display=49;WildStarAppearance.Apply(gm);assert(gm.display==firstHuman)
-- Run the actual client editor against the simulated server, not a copy of its callbacks.
local framesCreated,clientMessages,applied={},{},{}
local methods={}
function methods:SetScript(name,fn)assert(type(fn)=="function" or fn==nil);self.scripts[name]=fn end
function methods:SetText(text)self.text=text end
function methods:GetText()return self.text or ""end
function methods:Show()self.shown=true end
function methods:Hide()self.shown=false end
function methods:IsShown()return self.shown end
local function widget()
    return setmetatable({scripts={},shown=false},{__index=function(_,k)return methods[k] or function()end end})
end
function methods:CreateFontString()return widget()end
CreateFrame=function(_,name)local f=widget();framesCreated[#framesCreated+1]=f;if name then _G[name]=f end;return f end
UIParent=widget();SlashCmdList={};UnitGUID=function(token)local u=token=="target" and creature or gm;return "0x"..string.format("%08X%08X",u:GetUInt32Value(1),u:GetUInt32Value(0))end
UnitName=function()return "GM"end;GetTime=function()return now/1000 end
WSResetUnitProfiles=function()applied={}end
WSProfileCatalog=function()return WSPCatalog.hash end
WSProfilePath=function(text)local p=P.Parse(text);return p and "WS\\Art\\Character\\Human\\Male\\Human_M.m3" or nil end
WSProfileCharacter=function(_,choices,option,delta,race)
    local c={race=race or 22,sex=0,choices={},labels={}}
    for i=1,7 do c.choices[i]=choices and choices[i] or 0;if option==i then c.choices[i]=(c.choices[i]+delta)%3 end;c.labels[i]="Option "..i.." "..c.choices[i]end
    return c
end
WSProfilePresets=function()return {}end
WSApplyUnitProfile=function(g,p)applied[g]=p;return true end
WSDebugModel=widget();SendChatMessage=function()end
SendAddonMessage=function(prefix,frame,channel,name)
    assert(prefix==P.PREFIX and channel=="WHISPER" and name=="GM")
    clientMessages[#clientMessages+1]=frame;events[30](30,gm,7,prefix,frame)
end
dofile("WoWClient/Interface/WildStarDebug/AppearanceEditor.lua")
local receiver=framesCreated[#framesCreated]
local function drain()
    for i=1,10 do now=now+100;receiver.scripts.OnUpdate(receiver,.1)end
    local messages=sends;sends={}
    for _,m in ipairs(messages)do if m.player==gm then receiver.scripts.OnEvent(receiver,"CHAT_MSG_ADDON",P.PREFIX,m.frame,"WHISPER","GM")end end
end
sends={};receiver.scripts.OnEvent(receiver,"PLAYER_ENTERING_WORLD");drain()
WSAppearanceSetBase(firstHuman,"0,255",0)
for _,f in ipairs(framesCreated)do if f.text=="Option 1 0"then f.scripts.OnClick(f);break end end
local before=#sql
WSAppearanceApply("TARGET");drain();assert(#sql==before+1,"actual editor did not save target profile")
local recipientSeen=false;for _,m in ipairs(sends)do if m.player==viewer then recipientSeen=true end end
assert(creature.display==firstHuman)
local count=0;for _ in pairs(applied)do count=count+1 end
for _,frame in ipairs(P.Frames("V|000000000000000A|"..profile))do receiver.scripts.OnEvent(receiver,"CHAT_MSG_ADDON",P.PREFIX,frame,"WHISPER","Impostor")end
local countAfter=0;for _ in pairs(applied)do countAfter=countAfter+1 end;assert(countAfter==count)
dofile("build_wildstar/wildstar335a/server/adapters/azerothcore/appearance/WildStarAppearance.lua")
assert(WildStarAppearance.HasProfile(gm),"self-contained deployment did not reload the saved profile")
print("PASS appearance protocol: fragmentation/reassembly, bounds, GM enforcement, NPC + player persistence, reload, morph preservation, two-client snapshot, clear")
