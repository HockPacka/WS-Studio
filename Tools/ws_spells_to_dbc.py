#!/usr/bin/env python3
"""Generate a collision-checked, non-playable WildStar spell catalog offline.
No client/server installation and no SQL execution. Combat effects await phase 2.
"""
import argparse,json
from pathlib import Path
from wildstar_spells.reservations import snapshot
from wildstar_spells.exporter import export
ROOT=Path(__file__).resolve().parents[1]
def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--client',type=Path,default=ROOT/'WoWClient')
    p.add_argument('--output',type=Path,default=ROOT/'build_wildstar/spells_phase1')
    p.add_argument('--server-core',type=Path,default=ROOT/'Repack AzerothCore NPCBots(2026)(Update 6.2)/Repack AzerothCore NPCBots/Core',help='READ ONLY namespace audit of this AzerothCore adapter')
    p.add_argument('--reservations',type=Path,help='previous reservation snapshot, for a fully offline rebuild')
    p.add_argument('--prior-id-map',type=Path,default=ROOT/'plugins/wildstar335a/data/spell_ids.json',help='persistent native-ID registry; defaults to the shipped WildStar registry')
    p.add_argument('--id-base',type=int,default=1000000)
    a=p.parse_args()
    if a.output.exists():p.error('Output already exists. Choose a new staging directory; existing/live data is never overwritten.')
    print('1/3 Reading namespace reservations (no server writes)',flush=True)
    reserve=json.loads(a.reservations.read_text()) if a.reservations else snapshot(a.client,a.server_core)
    prior=json.loads(a.prior_id_map.read_text()) if a.prior_id_map and a.prior_id_map.is_file() else None
    if a.prior_id_map and not a.prior_id_map.is_file() and a.prior_id_map!=ROOT/'plugins/wildstar335a/data/spell_ids.json':p.error('Prior ID registry does not exist')
    print('2/3 Reading original TBL files and generating offline metadata',flush=True)
    report=export(a.client,a.output,reserve,prior,a.id_base)
    print('3/3 Finished catalog (not installable / not playable)',flush=True);print(json.dumps(report,indent=2))
if __name__=='__main__':main()
