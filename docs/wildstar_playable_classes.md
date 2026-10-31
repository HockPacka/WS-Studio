# Playable class starter sets: WoW compatibility v1

2026-10-29. The user explicitly selected a playable compatibility mode.
This release installs **six carrier-bound classes with five abilities each**.
It does not implement the complete WildStar combat system.

| WildStar class | WoW carrier | Starter abilities |
| --- | --- | --- |
| Warrior | Warrior | Relentless Strikes, Menacing Strike, Kick, Whirlwind, Power Link |
| Engineer | Warlock | Pulse Blast, Electrocute, Flak Cannon, Unstable Anomaly, Urgent Withdrawal |
| Esper | Mage | Telekinetic Strike, Illusionary Blades, Bolster, Crush, Projected Spirit |
| Medic | Priest | Discharge, Gamma Rays, Emission, Mending Probes, Crisis Wave |
| Stalker | Rogue | Shred, Impale, Stealth, Stagger, Neutralize |
| Spellslinger | Hunter | Quick Draw, Charged Shot, Wild Barrage, Healing Salve, Flash Freeze |

The existing character creation UI already maps these classes to their carriers.
No new carrier class IDs are introduced. Login automatically learns the five
approved spells for races 22-29; existing characters receive them too. Repeated
login is idempotent. Ordinary WoW races do not receive these starters. Existing
native diagnostic profiles, including explicit GM ratings and action sets, are
preserved and are **not** used as the engine combat stats.

## Play and test

1. Fully restart the client after installation, then log into a WildStar character.
2. The addon displays five secure spell buttons. `/wsabilities` toggles the bar
   outside combat; drag its background to reposition it.
3. `.wsclass status` lists the actual server-learned IDs and engine templates.
   `.wsclass learn` synchronizes a currently logged-in character if needed.
4. The spells are also mapped to the carrier's existing spellbook skill tab.

Buttons use `SecureActionButtonTemplate` with numeric spell IDs. The shipped
3.3.5a `SecureTemplates.lua` dispatches those through `CastSpellByID`. The local
client returns only two values from `UnitClass`, so the addon maps its class
token rather than assuming the modern third class-ID return value.

## Actual execution and explicit differences

Only the WoW engine executes these spells. It handles casts, target validity,
range, line of sight, immunity, costs, cooldowns and effects. No Lua damage/heal
hook or client-supplied amount is added. The IDs are taken from the canonical
1,000,000-based registry and are disjoint from the legacy telegraph executor.

The machine-readable policy is
`plugins/wildstar335a/data/compatibility_starters.json`. Each entry pairs one
specific native tier-1 instance with a reviewed WoW spell template. The release
manifest records native base/instance/effect IDs, original descriptions, engine
templates, costs, schools and cooldowns. Native names and extracted icons are
used, while **effect amounts, casting, targeting, durations and visual effects
are WoW approximations**. DUMMY effects and Rogue combo point generation are
removed; unreviewed effect types and triggered-spell dependencies are rejected.
Carrier-family talent flags and stance restrictions are cleared.

Examples of substantive differences:

- Menacing Strike currently uses a WoW taunt, without the native hit/heal chain.
- Whirlwind/Flak Cannon/Wild Barrage/Neutralize use WoW instant area damage.
- Electrocute uses a cast-time attack rather than native channel behavior.
- Bolster/Emission/Mending Probes/Healing Salve use WoW periodic healing.
- Crush/Stagger use a WoW stun; native interrupt armor is not implemented.
- Illusionary Blades uses a WoW projectile with periodic damage.
- Urgent Withdrawal uses WoW Disengage movement.
- Shred and Impale currently share the same starter damage template; their
  costs/cooldowns differ. Native damage balance is not reproduced.

Mana replaces the caster-specific resources. Warrior uses Rage; Stalker uses
Energy. The compatibility school mapping is Physical -> Physical, Tech ->
Nature, Magic -> Arcane, healing -> Holy. Native telegraphs, bot AI, charge
stages, Spell Surge, full combos, tiers, AMP and original progression remain
open. All five abilities are available from level 1 for this first test release.
These are starter rank values, not a balanced level-80 ability set. Existing
WoW carrier abilities and talents remain available.

## Packaging and validation

`tools/ws_combat_starters.py` stages separate approved DBC deltas; it never
marks the full diagnostic catalog as executable. Raw native TBL files are not
changed. The package appends Spell, SpellIcon and SkillLineAbility rows while
preserving all existing rows/string bytes, independently for client and server.

`tools/ws_combat_starters_install.py` checks namespace conflicts against current
SQL references, live DBC hashes, copied asset hashes and the legacy telegraph
table. Installation requires a stopped worldserver, backs up every replaced
file, verifies readback and rolls back files on a write failure. It performs no
SQL migrations or profile writes. Learned spells subsequently persist through
the core's normal character save path.

Staging: `build_wildstar/combat_starters_v2/manifest.json`.
Installation receipt: `build_wildstar/deployments/combat-starters-live-20261029/installation.json`.
The previous diagnostic command `.wscombat` still describes the separate native
research/probe path; `.wsclass` describes the playable compatibility release.

Automated validation covers class/race isolation, idempotent learning, missing
DBC failure, actual six-class staged data and engine row restrictions. Existing
combat/export tests also run. Actual in-game cast behavior still needs a client
restart and live verification; an offline or mocked test is not proof of a live
damage/heal/control result.
