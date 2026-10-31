-- Exercise actual menu callbacks under the client's own Lua 5.1 runtime.
local widgets = {}
local methods = {}
function methods:SetScript(event, fn) self[event] = fn end
function methods:RegisterEvent(event) self.events[event]=true end
function methods:SetText(value) self.text=value end
function methods:GetText() return self.text or "" end
function methods:SetChecked(value) self.checked = value end
function methods:GetChecked() return self.checked end
function methods:IsShown() return self.shown end
function methods:Show() self.shown = true; if self.OnShow then self:OnShow() end end
function methods:Hide() self.shown = false end
local function widget(kind, name)
    local frame = setmetatable({kind=kind,events={},shown=true}, {__index=function(_,key) return methods[key] or function() end end})
    widgets[#widgets+1] = frame
    if name then _G[name] = frame end
    return frame
end
function methods:CreateFontString() return widget("FontString") end
function methods:CreateTexture() return widget("Texture") end
function methods:GetNormalTexture() return widget("Texture") end
function methods:GetPushedTexture() return widget("Texture") end
function methods:GetHighlightTexture() return widget("Texture") end
function methods:Click() if self.OnClick then self:OnClick() end end
CreateFrame = widget
UnitGUID=function()return "0x0000000000000001" end
local function event(name)
    local count=#widgets
    for i=1,count do local frame=widgets[i];if frame.events[name] and frame.OnEvent then frame:OnEvent(name) end end
end

local function exercise(glue)
    widgets = {}
    WSMaterialDebugFrame = nil
    WSMaterialDebugToggle = nil
    UIParent = glue and nil or widget("Frame")
    GlueParent = glue and widget("Frame") or nil
    -- Lua's and/or does not yield nil: set the Glue case explicitly.
    if glue then UIParent = nil end
    SlashCmdList = glue and nil or {}
    if glue then SlashCmdList = nil end
    UISpecialFrames = {}
    local before=#widgets
    dofile("WoWClient/Interface/WildStarDebug/MaterialDebug.lua")
    assert(not WSMaterialDebugFrame,"menu built before world entry")
    if glue then assert(#widgets==before,"Glue must not create debug widgets");return end
    assert(#widgets==before+1,"only a lightweight event listener before world entry")
    event("PLAYER_ENTERING_WORLD")
    local panel = assert(WSMaterialDebugFrame)
    assert(not panel:IsShown())
    local checks, buttons = {}, {}
    for _,frame in ipairs(widgets) do
        if frame.kind == "CheckButton" then checks[#checks+1]=frame end
        if frame.kind == "Button" then buttons[#buttons+1]=frame end
    end
    assert(#checks==5 and #buttons==3)
    buttons[3]:OnClick()
    assert(panel:IsShown())
    for i,key in ipairs({"materials","normal","gloss","glow","files"}) do
        checks[i]:SetChecked(false); checks[i]:OnClick()
        assert(not WSGetDebugSetting(key))
    end
    buttons[1]:OnClick()
    for _,key in ipairs({"materials","normal","gloss","glow","files"}) do assert(WSGetDebugSetting(key)) end
    buttons[2]:OnClick(); assert(not panel:IsShown())
    if not glue then
        assert(SLASH_WSMATERIALDEBUG1=="/wsdebug")
        SlashCmdList.WSMATERIALDEBUG(); assert(panel:IsShown())
    end
    local count=#widgets
    event("PLAYER_LEAVING_WORLD")
    assert(not panel:IsShown() and not WSMaterialDebugToggle:IsShown())
    event("PLAYER_ENTERING_WORLD")
    assert(#widgets==count and WSMaterialDebugToggle:IsShown() and not panel:IsShown(),"world re-entry must not rebuild or reopen the panel")
end
exercise(true)
exercise(false)
assert(not pcall(WSSetDebugSetting, "bad-setting", false))
assert(not pcall(WSSetDebugSetting, "files", "false"))

-- Actual browser script: no model enumeration, preview or startup file until
-- world entry; returning to the world must not duplicate the browser.
widgets={};UIParent=nil;GlueParent=widget("Frame")
WSFilterModels=function()error("model enumeration before world entry")end
local before=#widgets
dofile("WoWClient/Interface/WildStarDebug/WildStarDebug.lua")
assert(#widgets==before and not WSDebugFrame)
UIParent=widget("Frame");GlueParent=nil;SlashCmdList={}
local filters,startups=0,0
WSFilterModels=function()filters=filters+1;return 0 end
WSModelTotal=function()return 0 end
WSGetStartup=function()startups=startups+1;return nil end
dofile("WoWClient/Interface/WildStarDebug/WildStarDebug.lua")
assert(not WSDebugFrame and filters==0 and startups==0)
event("PLAYER_ENTERING_WORLD")
assert(WSDebugToggle:IsShown() and not WSDebugFrame:IsShown() and startups==1 and filters==0)
SlashCmdList.WILDSTAR();assert(WSDebugFrame:IsShown() and filters==1)
event("PLAYER_LEAVING_WORLD");assert(not WSDebugToggle:IsShown() and not WSDebugFrame:IsShown())
local count=#widgets
event("PLAYER_ENTERING_WORLD")
assert(#widgets==count and WSDebugToggle:IsShown() and not WSDebugFrame:IsShown() and startups==1)
if print then print("PASS: no Glue debug UI; world-only deferred creation, logout hiding and idempotent re-entry") end
