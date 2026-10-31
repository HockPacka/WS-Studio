#!/usr/bin/env python3
"""Zone music for the WildStar zones (offline: output goes to the staging directory, see ws_content_output.py).

Chain (all from the original ClientData / tables_csv):
  WorldZone.soundZoneKitId (inherited from the parent zone if 0) -> SoundZoneKit.soundMusicSetId -> SoundMusicSet.soundEventIdStart -> SoundEvent.name
  -> Wwise event (Events.bnk, FNV-1 hash of the lower case name) -> actions -> Structure_Music.bnk containers / segments / tracks -> <id>.wem media files
The .wem files (Wwise Vorbis) are decoded with tools/vgmstream/vgmstream-cli.exe into <output>/client/WoWOverride/Sound/WildStar/ws_<id>.wav and referenced from
new SoundEntries.dbc (id SOUND_BASE + zone), ZoneMusic.dbc (id MUSIC_BASE + zone) rows; AreaTable.dbc rows of the staging copy (ws_zones.py must have run) get
their ZoneMusic field set.
usage: ws_music.py [--map Western] [--max-files 10] [--only-zone 13] [--install-client]
"""
import argparse
import concurrent.futures
import csv
import json
import os
import pickle
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import wwise_bnk as W  # noqa: E402
import ws_text  # noqa: E402
from ws_content_output import Output, add_output_arguments, reject_server_install  # noqa: E402
from ws_map_setup import Dbc, DEFAULT_CLIENT  # noqa: E402

AREA_BASE = 50000     # = kAreaIdBase (Area3/AdtBuilder.h); server terrain uses uint16
SOUND_BASE = 900000
MUSIC_BASE = 900000
VGMSTREAM = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'vgmstream', 'vgmstream-cli.exe')


class Index(W.Bank):
    """object table of all banks"""

    def __init__(self, audio, cache):
        if os.path.exists(cache):
            self.objs = pickle.load(open(cache, 'rb'))
            return

        self.objs = {}

        for f in sorted(os.listdir(audio)):
            if f.endswith('.bnk'):
                self.objs.update({k: v for k, v in W.Bank(os.path.join(audio, f)).objs.items() if k not in self.objs})

        os.makedirs(os.path.dirname(cache), exist_ok=True)
        pickle.dump(self.objs, open(cache, 'wb'))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=DEFAULT_CLIENT)
    ap.add_argument('--map', default='Western', help='only zones that have cells in this map (ws_zone_cells.py json of ws_worldmap.py)')
    ap.add_argument('--all-maps', action='store_true', help='all native WorldZone rows, including inherited music on the added maps')
    ap.add_argument('--max-files', type=int, default=10)
    ap.add_argument('--only-zone', type=int, default=0)
    ap.add_argument('--dry-run', action='store_true')
    ap.add_argument('--jobs', type=int, default=4)
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap, a)
    out = Output(a)
    tables = os.path.join(a.client, 'tables_csv')
    audio = os.path.join(a.client, 'ClientData', 'Audio')

    def load(name, key):
        return {int(r[key]): r for r in csv.DictReader(open(os.path.join(tables, name), encoding='utf-8'))}

    zones = load('WorldZone.csv', 'ID')
    kits = load('SoundZoneKit.csv', 'ID')
    sets = load('SoundMusicSet.csv', 'ID')
    events = load('SoundEvent.csv', 'id')
    text = ws_text.load(os.path.join(a.client, 'ClientDataEN', 'en-US.bin'))
    cells_json = os.path.join(out.root, 'cache', 'cells_%s.json' % a.map)
    wanted = set(zones) if a.all_maps else {int(k) for k in json.load(open(cells_json))} if os.path.exists(cells_json) else set(zones)
    if not 1 <= a.max_files <= 10:ap.error('--max-files must be between 1 and 10 (SoundEntries file slots)')

    if a.only_zone:
        wanted = {a.only_zone}

    index = Index(audio, os.path.join(out.root, 'cache', 'hirc.pkl'))
    media = {int(f[:-4]) for f in os.listdir(audio) if f.endswith('.wem') and f[:-4].isdigit()}

    def kit_of(zid):
        seen = set()

        while zid in zones and zid not in seen:
            seen.add(zid)
            kit = int(zones[zid]['soundZoneKitId'])
            kit_seen=set()
            while kit in kits and kit not in kit_seen:
                kit_seen.add(kit)
                music=int(kits[kit].get('soundMusicSetId','0') or 0)
                if music:return kit,music
                kit=int(kits[kit].get('soundZoneKitIdParent','0') or 0)

            zid = int(zones[zid]['parentZoneId'])

        return 0, 0

    plan = {}   # zone -> (event name, [wem ids])
    cache = {}  # event name -> wems

    for zid in sorted(wanted):
        kit, music = kit_of(zid)

        if not music or music not in sets:
            continue

        ev = events.get(int(sets[music]['soundEventIdStart']))

        if not ev:
            continue

        name = ev['name']

        if name not in cache:
            eid = W.fnv(name)
            cache[name] = index.event_media(eid, media)[1] if eid in index.objs else []

        if cache[name]:
            plan[zid] = (name, cache[name])

    allwems = sorted({w for _, ws in plan.values() for w in ws})
    print('%d zones with music, %d events, %d media files' % (len(plan), len({n for n, _ in plan.values()}), len(allwems)))

    est = sum(os.path.getsize(os.path.join(audio, '%d.wem' % w)) for w in allwems) * 5 / 1e9
    print('estimated WAV size %.1f GB' % est)

    if a.dry_run:
        return

    sound_dir = out.client_path('WoWOverride/Sound/WildStar/x').rsplit(os.sep, 1)[0]

    def convert(wem):
        dst = os.path.join(sound_dir, 'ws_%d.wav' % wem)
        src = os.path.join(audio, '%d.wem' % wem)

        if os.path.exists(dst) and os.path.getmtime(dst) >= os.path.getmtime(src):
            return True

        installed=os.path.join(a.client,'WoWOverride','Sound','WildStar','ws_%d.wav'%wem)
        if os.path.isfile(installed) and os.path.getmtime(installed)>=os.path.getmtime(src):
            shutil.copy2(installed,dst)
            return True

        r = subprocess.run([VGMSTREAM, '-o', dst, src], capture_output=True)
        return r.returncode == 0 and os.path.isfile(dst) and os.path.getsize(dst)>44

    with concurrent.futures.ThreadPoolExecutor(a.jobs) as pool:
        ok = dict(zip(allwems, pool.map(convert, allwems)))

    print('decoded %d / %d' % (sum(ok.values()), len(ok)))

    # ---- DBC rows
    se = Dbc(out.original_dbc('SoundEntries'))
    zm = Dbc(out.original_dbc('ZoneMusic'))
    tmpl = [r for r in se.recs if r[0] == 9012]
    tmpl = list(tmpl[0]) if tmpl else list(se.recs[0])
    se.recs = [r for r in se.recs if not (SOUND_BASE <= r[0] < SOUND_BASE + 100000)]
    zm.recs = [r for r in zm.recs if not (MUSIC_BASE <= r[0] < MUSIC_BASE + 100000)]
    music_of = {}

    for zid, (name, wems) in sorted(plan.items()):
        files = [w for w in wems if ok.get(w)]
        files = sorted(files, key=lambda w: -os.path.getsize(os.path.join(audio, '%d.wem' % w)))[:a.max_files]

        if not files:
            continue

        zname = text.get(int(zones[zid]['localizedTextIdName']), '').strip() or 'zone%d' % zid
        row = list(tmpl)
        row[0] = SOUND_BASE + zid
        row[2] = se.add_string('WS_Music_%d_%s' % (zid, zname.replace(' ', '_')))
        count = len(files)

        for k in range(10):
            row[3 + k] = se.add_string('ws_%d.wav' % files[k]) if k < count else 0
            row[13 + k] = 1 if k < count else 0

        row[23] = se.add_string('Sound\\WildStar')
        se.recs.append(row)
        zm.recs.append([MUSIC_BASE + zid, zm.add_string('WS-%d-%s' % (zid, zname.replace(' ', '_'))), 10000, 10000, 30000, 30000, SOUND_BASE + zid, SOUND_BASE + zid])
        music_of[zid] = MUSIC_BASE + zid

    for dbc, rel in ((se, 'WoWOverride/DBFilesClient/SoundEntries.dbc'), (zm, 'WoWOverride/DBFilesClient/ZoneMusic.dbc')):
        dbc.save(out.client_path(rel))
        out.install_client_file(rel)

    # ---- AreaTable (the staging copy written by ws_zones.py): ZoneMusic field
    area_path = out.client_path('WoWOverride/DBFilesClient/AreaTable.dbc')

    if os.path.exists(area_path):
        area = Dbc(area_path)
        patched = 0

        for r in area.recs:
            z = r[0] - AREA_BASE

            if z in music_of:
                r[8] = music_of[z]
                patched += 1

        area.save(area_path)
        out.install_client_file('WoWOverride/DBFilesClient/AreaTable.dbc')
        print('AreaTable.dbc: %d zones got ZoneMusic' % patched)
    else:
        print('AreaTable.dbc not in the staging directory: run ws_zones.py first')

    for rel in sorted(os.listdir(sound_dir)):
        out.install_client_file('WoWOverride/Sound/WildStar/' + rel)

    print('SoundEntries / ZoneMusic rows:', len(music_of))
    report=dict(allMaps=a.all_maps,zones=len(wanted),musicZones=len(music_of),events=len(cache),
                decodedMedia=sum(ok.values()),failedMedia=[w for w in allwems if not ok.get(w)],
                zoneMusic={str(z):dict(event=plan[z][0],zoneMusic=mid) for z,mid in music_of.items()},
                wwiseSelection='reachable media from native start events; switch/mood conditions approximated')
    with open(os.path.join(out.root,'music_links.json'),'w',encoding='utf-8') as f:json.dump(report,f,indent=2)
    out.finish('music')


if __name__ == '__main__':
    main()
