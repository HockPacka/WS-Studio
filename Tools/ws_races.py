#!/usr/bin/env python3
"""Generate WildStar race DBCs, GlueXML and customization analysis offline.

Reads original client MPQs and WildStar tables. Writes only under --output by
default. --install-client explicitly copies client overrides; direct server
installation is rejected. Extra playable races still require a core adapter.
Usage: ws_races.py [--client PATH] [--output PATH] [--dry]
"""
import argparse
import collections
import csv
import json
import os
import re
import shutil
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import mpq_extract  # noqa: E402
import ws_npc_patch  # noqa: E402
import ws_text  # noqa: E402
from ws_content_output import Output, add_output_arguments, reject_server_install

ROOT = os.path.dirname(HERE)
FIRST_ID = 22          # ChrRaces ids used for the WildStar races (stock 3.3.5a ends at 21)
EXILE, DOMINION = 167, 166  # Faction2 ids used by CharacterCreation.csv (15767 "Exile", 15765 "Dominion")

# WildStar class id -> WoW class id (the creation screen only knows the 10 WoW classes)
CLASS_MAP = {1: 1,   # Warrior       -> Warrior
             2: 9,   # Engineer      -> Warlock
             3: 8,   # Esper         -> Mage
             4: 5,   # Medic         -> Priest
             5: 4,   # Stalker       -> Rogue
             7: 3}   # Spellslinger  -> Hunter

# new race key -> (WildStar Race.csv id, faction, WoW race we clone faction/sounds/outfits/names from,
#                  placeholder icon/background of a stock race until real icons exist, display name, ClientPrefix)
RACES = [
    ('WSHuman',   1, EXILE,    1, 'HUMAN',    'Human',    'Human (Exile)', 'Wh'),
    ('WSGranok',  3, EXILE,    1, 'DWARF',    'Dwarf',    'Granok',        'Wg'),
    ('WSAurin',   4, EXILE,    1, 'NIGHTELF', 'NightElf', 'Aurin',         'Wa'),
    ('WSMordesh', 16, EXILE,   1, 'SCOURGE',  'Scourge',  'Mordesh',       'Wm'),
    ('WSCassian', 1, DOMINION, 2, 'ORC',      'Orc',      'Cassian',       'Wc'),
    ('WSDraken',  5, DOMINION, 2, 'TAUREN',   'Tauren',   'Draken',        'Wd'),
    ('WSMechari', 12, DOMINION, 2, 'GNOME',   'Gnome',    'Mechari',       'Wn'),
    ('WSChua',    13, DOMINION, 2, 'TROLL',   'Troll',    'Chua',          'Wu'),
    ('WSEshara',  2, None,     1, 'HUMAN',    'Human',    'Eshara',        'We'),   # cut race: no creation / customization data
]

# stock icon sheet (UI-CharacterCreate-Races) coordinates, copied from CharacterCreate.lua
ICON = {
    'HUMAN': ((0, .125, 0, .25), (0, .125, .5, .75)), 'DWARF': ((.125, .25, 0, .25), (.125, .25, .5, .75)),
    'GNOME': ((.25, .375, 0, .25), (.25, .375, .5, .75)), 'NIGHTELF': ((.375, .5, 0, .25), (.375, .5, .5, .75)),
    'TAUREN': ((0, .125, .25, .5), (0, .125, .75, 1)), 'SCOURGE': ((.125, .25, .25, .5), (.125, .25, .75, 1)),
    'TROLL': ((.25, .375, .25, .5), (.25, .375, .75, 1)), 'ORC': ((.375, .5, .25, .5), (.375, .5, .75, 1)),
}

RACE_TEXT = {
    'WSHuman': 'Exiles from Earth - the humans who fled the dying Earth and chose to fight the Dominion for Nexus.',
    'WSCassian': 'The Cassians, the noble humans of the Dominion, born to rule the galaxy of the Eldan Empire\'s heirs.',
    'WSGranok': 'Huge and stoic, the Granok are a warrior people of rock and honour who were raised to fight.',
    'WSAurin': 'Nimble forest dwellers of Alizar, the Aurin stand for nature and carry the will of their world.',
    'WSMordesh': 'Humans cursed by the Mordesh plague, kept alive by the Strain and forever fighting the clock.',
    'WSDraken': 'Fierce Dominion warriors whose chieftains rule through strength and the glory of the hunt.',
    'WSMechari': 'Mechanical beings built by the Dominion, the Mechari are cold, precise and unyielding.',
    'WSChua': 'Brilliant and mischievous, the Chua are small tinkerers who build wonders and weapons for the Dominion.',
    'WSEshara': 'The Eshara are not playable in the final WildStar client.',
}


def f2u(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


class Dbc:
    """generic 4-byte-field WDBC (records of arbitrary size are kept raw)"""

    def __init__(self, data):
        magic, self.rc, self.fc, self.rs, ss = struct.unpack_from('<4s4I', data, 0)
        assert magic == b'WDBC'
        self.recs = [bytearray(data[20 + i * self.rs:20 + (i + 1) * self.rs]) for i in range(self.rc)]
        self.strings = bytearray(data[20 + self.rc * self.rs:20 + self.rc * self.rs + ss])

    def u32(self, r, i):
        return struct.unpack_from('<I', r, i * 4)[0]

    def set32(self, r, i, v):
        struct.pack_into('<I', r, i * 4, v & 0xFFFFFFFF)

    def string(self, off):
        return self.strings[off:self.strings.index(b'\0', off)].decode('utf-8', 'replace')

    def add_string(self, s):
        if not s:
            return 0
        raw = s.encode('utf-8') + b'\0'
        i = self.strings.find(raw)
        if i >= 0 and (i == 0 or self.strings[i - 1] == 0):
            return i
        off = len(self.strings)
        self.strings += raw
        return off

    def save(self):
        out = bytearray(struct.pack('<4s4I', b'WDBC', len(self.recs), self.fc, self.rs, len(self.strings)))
        for r in self.recs:
            out += r
        return bytes(out + self.strings)


class Client:
    def __init__(self, data_dir):
        self.arcs = []
        for rel in mpq_extract.ORDER:
            p = os.path.join(data_dir, rel)
            if os.path.exists(p):
                self.arcs.append(mpq_extract.Mpq(p))

    def get(self, name):
        for a in self.arcs:
            d = a.read(name)
            if d and d != b'PATCH':
                return d
        raise FileNotFoundError(name)


def read_csv(tables, name):
    with open(os.path.join(tables, name + '.csv'), newline='', encoding='utf-8') as f:
        return list(csv.DictReader(f))


# ---------------------------------------------------------------- customization analysis

def analyze(tables, text):
    races = {int(r['ID']): r for r in read_csv(tables, 'Race')}
    labels = {int(r['ID']): text.get(int(r['localizedTextId']), '?') for r in read_csv(tables, 'CharacterCustomizationLabel')}
    slots = {int(r['ID']): r['EnumName'] for r in read_csv(tables, 'ItemSlot')}
    acc = collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(lambda: collections.defaultdict(set))))
    for r in read_csv(tables, 'CharacterCustomization'):
        race = int(r['raceId'])
        if race == 0:
            continue
        slot = slots.get(int(r['itemSlotId']), 'slot%s' % r['itemSlotId'])
        for k in ('00', '01'):
            lab = int(r['characterCustomizationLabelId' + k])
            if lab:
                acc[race][int(r['gender'])][slot][lab].add(int(r['value' + k]))
    out = {}
    for race, rec in sorted(acc.items()):
        name = races[race]['enumName']
        out[name] = {'raceId': race, 'sexes': {}}
        for sex, sl in sorted(rec.items()):
            opts = []
            for slot, labs in sl.items():
                for lab, vals in sorted(labs.items()):
                    opts.append({'slot': slot, 'labelId': lab, 'label': labels.get(lab, '?'),
                                 'values': len(vals), 'min': min(vals), 'max': max(vals)})
            out[name]['sexes']['male' if sex == 0 else 'female'] = opts
    return out


def merged(opts):
    """options with the same slot + label text (e.g. 'Hair Style' has several label ids) merged: summed number of choices"""
    m = collections.OrderedDict()
    for o in opts:
        k = (o['slot'], o['label'])
        m.setdefault(k, {'slot': o['slot'], 'label': o['label'], 'values': 0, 'labelIds': []})
        m[k]['values'] += o['values']
        m[k]['labelIds'].append(o['labelId'])
    return list(m.values())


def menu_labels(opts):
    """Which WildStar option feeds which of the 5 WoW customization buttons (skin / face / hair style / hair colour / facial)."""
    opts = merged(opts)

    def best(slot, word=None):
        c = [o for o in opts if o['slot'] == slot and (word is None or word in o['label'])]
        return max(c, key=lambda o: o['values'])['label'] if c else None
    return {
        'skin': best('BodySkin') or 'Skin Color',
        'face': best('BodyFace', 'Face') or 'Face Style',
        'hairStyle': best('BodyHair', 'Style') or best('BodyHair') or 'Hair Style',
        'hairColor': best('BodyHair', 'Color') or best('BodyFacialHair', 'Color') or 'Hair Color',
        'facial': best('BodyFacialHair', 'Style') or best('BodyEar', 'Style') or best('BodyEar') or best('BodyEye', 'Style') or 'Accessories',
    }


def write_docs(custom, creation, path_json, path_md):
    os.makedirs(os.path.dirname(path_json), exist_ok=True)
    json.dump({'creation': creation, 'customization': custom}, open(path_json, 'w'), indent=1)
    lines = ['# WildStar race customization options (generated by tools/ws_races.py)', '',
             'Source: `CharacterCustomization.csv` x `CharacterCustomizationLabel.csv` x `ItemSlot.csv`; values = number of distinct choices.', '']
    for name, d in custom.items():
        lines.append('## %s (race id %d)' % (name, d['raceId']))
        c = creation.get(name)
        if c:
            lines.append('Factions: %s - classes: %s' % (', '.join(c['factions']), ', '.join(c['classes'])))
        for sex, opts in d['sexes'].items():
            lines += ['', '**%s**' % sex, '', '| slot | option | choices (summed over label ids) | label ids |', '|---|---|---|---|']
            lines += ['| %s | %s | %d | %s |' % (o['slot'], o['label'], o['values'], ','.join(map(str, o['labelIds']))) for o in merged(opts)]
        lines.append('')
    open(path_md, 'w', encoding='utf-8').write('\n'.join(lines))


# ---------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('--client', default=ws_npc_patch.DEFAULT_CLIENT)
    ap.add_argument('--server', default=ws_npc_patch.DEFAULT_SERVER)
    ap.add_argument('--no-server', action='store_true')
    ap.add_argument('--dry', action='store_true')
    ap.add_argument('--skip-models', action='store_true', help='do not (re)run ws_npc_patch.py for the race models')
    add_output_arguments(ap)
    a = ap.parse_args()
    reject_server_install(ap,a)
    output=Output(a)

    tables = os.path.join(a.client, 'tables_csv')
    text = ws_text.load(os.path.join(a.client, 'ClientDataEN', 'en-US.bin'))
    ws_races = {int(r['ID']): r for r in read_csv(tables, 'Race')}
    classes = {int(r['ID']): text.get(int(r['localizedTextId']), r['enumName']) for r in read_csv(tables, 'Class')}

    # race -> faction -> classes from CharacterCreation.csv
    rc = collections.defaultdict(lambda: collections.defaultdict(set))
    for r in read_csv(tables, 'CharacterCreation'):
        if int(r['raceId']) and int(r['classId']) and r['costumeOnly'] != 'True' and r['enabled'] == 'True':
            rc[int(r['raceId'])][int(r['factionId'])].add(int(r['classId']))

    custom = analyze(tables, text)
    creation = {}
    for rid, f in rc.items():
        creation[ws_races[rid]['enumName']] = {
            'factions': sorted({'Exile' if k == EXILE else 'Dominion' for k in f}),
            'classes': sorted({classes[c] for s in f.values() for c in s})}
    if not a.dry:
        docs=os.path.join(a.output,'analysis');os.makedirs(docs,exist_ok=True)
        write_docs(custom, creation, os.path.join(docs, 'ws_race_customization.json'),os.path.join(docs, 'ws_race_customization.md'))

    # ---- display ids (CreatureDisplayInfo.id = BASE + index in the sorted .m3 list, see ws_npc_patch.py)
    models = {p.lower(): ws_npc_patch.BASE + i for i, p in enumerate(ws_npc_patch.model_list(a.client))}

    race_models = sorted({ws_races[w][k] for _n, w, *_ in RACES for k in ('maleAssetPath', 'femaleAssetPath')
                          if ws_races[w][k].replace('/', '\\').lower() in models})
    if not a.dry and not a.skip_models:
        # ws_npc_patch.py rebuilds CreatureModelData / CreatureDisplayInfo from the originals on every run and only contains the
        # models listed with --include, so the race models have to be part of that list (the 4 default test models are kept)
        cmd = [sys.executable, os.path.join(HERE, 'ws_npc_patch.py'), '--client', a.client, '--output', a.output]
        if a.install_client:cmd.append('--install-client')
        for t in ['prp_bag_backpack_000.m3', r'Art\Character\Aurin\Female\Aurin_F.m3', r'Art\Creature\StemDragon\StemDragon.m3',
                  r'Art\Creature\Boulderback\Boulderback.m3'] + race_models:
            cmd += ['--include', t]
        r = subprocess.run(cmd, capture_output=True, text=True)
        print((r.stdout or '').strip().splitlines()[-4:] if r.returncode == 0 else r.stderr)
        if r.returncode:
            raise SystemExit('ws_npc_patch.py failed')

    def display(race_id, sex):
        r = ws_races[race_id]
        path = (r['femaleAssetPath'] if sex else r['maleAssetPath']).replace('/', '\\').lower()
        if path not in models:
            print('WARNING: model %s of race %s is not in %s\\ClientData (display id 0)' % (path, r['enumName'], a.client))
            return 0
        return models[path]

    cl = Client(os.path.join(a.client, 'Data'))
    out = {}

    def load(name):
        out[name] = Dbc(cl.get('DBFilesClient\\%s.dbc' % name))
        return out[name]

    # ---- ChrRaces
    chr_races = load('ChrRaces')
    assert chr_races.fc == 69 and chr_races.rs == 276
    stock = {chr_races.u32(r, 0): r for r in chr_races.recs}
    chr_races.recs = [r for r in chr_races.recs if chr_races.u32(r, 0) < FIRST_ID]    # idempotent
    new_ids = {}
    for n, (key, wsid, faction, base, icon, bg, name, prefix) in enumerate(RACES):
        rid = FIRST_ID + n
        new_ids[key] = rid
        row = bytearray(stock[base])
        s = chr_races.set32
        s(row, 0, rid)
        flags = chr_races.u32(row, 1) & ~0x1
        s(row, 1, flags | (0x1 if faction is None else 0))
        s(row, 2, chr_races.u32(stock[base], 2))
        s(row, 4, display(wsid, 0))
        s(row, 5, display(wsid, 1))
        s(row, 6, chr_races.add_string(prefix))
        s(row, 11, chr_races.add_string(key))
        for off in (14, 31, 48):
            s(row, off, chr_races.add_string(name))
        opts = custom.get(ws_races[wsid]['enumName'], {'sexes': {}})['sexes']
        male = opts.get('male') or opts.get('female') or []
        female = opts.get('female') or male
        s(row, 65, chr_races.add_string(key.upper() + 'M'))
        s(row, 66, chr_races.add_string(key.upper() + 'F'))
        s(row, 67, chr_races.add_string(key.upper()))
        s(row, 68, 0)
        chr_races.recs.append(row)

    # ---- CharBaseInfo: (race u8, class u8) pairs
    cbi = load('CharBaseInfo')
    cbi.recs = [r for r in cbi.recs if r[0] < FIRST_ID]
    for key, wsid, faction, *_ in RACES:
        if faction is None:
            continue
        for wsclass in sorted(rc[wsid][faction]):
            cbi.recs.append(bytearray([new_ids[key], CLASS_MAP[wsclass]]))

    # ---- CharStartOutfit / NameGen: clones of the stock rows of the faction's template race
    cso = load('CharStartOutfit')
    cso.recs = [r for r in cso.recs if (cso.u32(r, 1) & 0xFF) < FIRST_ID]
    next_id = max(cso.u32(r, 0) for r in cso.recs) + 1
    base_cso = list(cso.recs)
    ng = load('NameGen')
    ng.recs = [r for r in ng.recs if ng.u32(r, 2) < FIRST_ID]
    next_ng = max(ng.u32(r, 0) for r in ng.recs) + 1
    base_ng = list(ng.recs)
    from ws_playable_races import registry
    native_rules = {r['key']: r for r in registry(a.client)['races']}
    for key, wsid, faction, base, *_ in RACES:
        if faction is None:
            continue
        allowed = {c['wowClass']: c for c in native_rules[key]['classes']}
        for r in base_cso:
            v = cso.u32(r, 1)
            cls = allowed.get((v >> 8) & 0xFF)
            if cls and (v & 0xFF) == cls['templateRace'] and ((v >> 16) & 0xFF) in cls['sexes']:
                n = bytearray(r)
                cso.set32(n, 0, next_id)
                cso.set32(n, 1, (v & ~0xFF) | new_ids[key])
                n[8:] = bytes(len(n) - 8)   # no starter equipment: WoW items cannot be shown on the WildStar race models (see tools/ws_empty_outfits.py)
                cso.recs.append(n)
                next_id += 1
        for r in base_ng:
            if ng.u32(r, 2) == base and ng.u32(r, 3) in native_rules[key]['sexes']:
                n = bytearray(r)
                ng.set32(n, 0, next_ng)
                ng.set32(n, 2, new_ids[key])
                ng.recs.append(n)
                next_ng += 1

    # ---- write DBCs
    cdir = os.path.join(a.output,'client','WoWOverride','DBFilesClient')
    for name, dbc in out.items():
        data = dbc.save()
        if name == 'CharBaseInfo':
            data = struct.pack('<4s4I', b'WDBC', len(dbc.recs), 2, 2, len(dbc.strings)) + b''.join(bytes(r) for r in dbc.recs) + bytes(dbc.strings)
        print('%-16s %5d rows' % (name, len(dbc.recs)))
        if a.dry:
            continue
        os.makedirs(cdir, exist_ok=True)
        open(os.path.join(cdir, name + '.dbc'), 'wb').write(data)
        output.install_client_file('WoWOverride/DBFilesClient/'+name+'.dbc')

    # ---- GlueXML
    gdir = os.path.join(a.output,'client','WoWOverride','Interface','GlueXML')
    glue = {}
    for f in ('CharacterCreate.lua', 'CharacterCreate.xml', 'GlueXML.toc'):
        glue[f] = cl.get('Interface\\GlueXML\\' + f).decode('utf-8', 'replace')
    glue['CharacterCreate.lua'] = re.sub(r'MAX_RACES = \d+;', 'MAX_RACES = 18;', glue['CharacterCreate.lua'])
    # The C++ rules can reject a sex that has no native model (Chua female).
    # Reflect the actual result in the UI rather than the requested sex.
    glue['CharacterCreate.lua'] = glue['CharacterCreate.lua'].replace(
        '\tSetSelectedSex(sex);', '\tSetSelectedSex(sex);\r\n\tsex = GetSelectedSex();', 1)
    glue['CharacterCreate.xml'] = patch_xml(glue['CharacterCreate.xml'])
    if 'WSRaces.lua' not in glue['GlueXML.toc']:
        glue['GlueXML.toc'] = glue['GlueXML.toc'].rstrip() + '\r\nWSRaces.lua\r\n'
    glue['WSRaces.lua'] = make_lua(custom, creation, ws_races)
    glue['WSRaceIcons.lua'] = open(os.path.join(HERE, 'client', 'WSRaceIcons.lua'), encoding='utf-8-sig').read()
    if 'WSRaceIcons.lua' not in glue['GlueXML.toc']:
        glue['GlueXML.toc'] = glue['GlueXML.toc'].rstrip() + '\r\nWSRaceIcons.lua\r\n'
    print('GlueXML override: %s' % ', '.join(sorted(glue)))
    if not a.dry:
        os.makedirs(gdir, exist_ok=True)
        for f, c in glue.items():
            open(os.path.join(gdir, f), 'w', encoding='utf-8', newline='').write(c)
            output.install_client_file('WoWOverride/Interface/GlueXML/'+f)
        icons = os.path.join(a.output, 'client', 'WoWOverride', 'Interface', 'WildStar', 'Races')
        subprocess.run([sys.executable, os.path.join(HERE, 'extract_race_icons.py'), '--output', icons,
                        '--data', os.path.join(a.client, 'ClientData')], check=True)
        for name in os.listdir(icons):
            if name.endswith('.tga'):
                output.install_client_file('WoWOverride/Interface/WildStar/Races/'+name)
        output.finish('races')


BUTTON = ('\t\t\t\t\t\t\t<CheckButton name="CharacterCreateRaceButton%d" inherits="CharacterCreateRaceButtonTemplate" id="%d" scale="0.7">\r\n'
          '\t\t\t\t\t\t\t\t<Anchors>\r\n%s\r\n\t\t\t\t\t\t\t\t</Anchors>\r\n\t\t\t\t\t\t\t</CheckButton>\r\n')


def patch_xml(xml):
    """10 race buttons (2 columns x 5) -> 18 buttons (Alliance column 1..9, Horde column 10..18), 0.7 scale so 9 rows fit above the gender buttons"""
    parts = []
    for i in range(1, 19):
        if i in (1, 10):
            anchor = '\t\t\t\t\t\t\t\t\t<Anchor point="TOP" relativePoint="TOP" x="%d" y="-75"/>' % (-50 if i == 1 else 50)
        else:
            anchor = '\t\t\t\t\t\t\t\t\t<Anchor point="TOPLEFT" relativeTo="CharacterCreateRaceButton%d" relativePoint="BOTTOMLEFT" x="0" y="-8"/>' % (i - 1)
        parts.append(BUTTON % (i, i, anchor))
    pat = re.compile(r'[ \t]*<CheckButton name="CharacterCreateRaceButton1" .*?</CheckButton>\r?\n(?:[ \t]*<CheckButton name="CharacterCreateRaceButton\d+" .*?</CheckButton>\r?\n)*', re.S)
    new, n = pat.subn(lambda m: ''.join(parts), xml, count=1)
    assert n == 1 and 'CharacterCreateRaceButton18' in new
    title = ''.join('<FontString name="WildStar%sTitle" inherits="FactionName_Shadow_Huge" '
             'justifyH="CENTER" text="%s"><Size x="118" y="30"/><Anchors>'
             '<Anchor point="TOP" x="%d" y="-20"/></Anchors>'
             '<Color r="0.48" g="0.88" b="1.0"/></FontString>' % (name,name,x)
             for name,x in [('Exiles',50),('Dominion',150)])
    anchor='<FontString name="CharacterCreateAllianceLabel"'
    assert new.count(anchor)==1
    new=new.replace(anchor,title+'\n'+anchor,1)
    new,n=re.subn(r'(<Frame name="CharacterCreateConfigurationFrame">\s*<Size x=")256(" y="758"/>)',r'\g<1>456\2',new,count=1)
    assert n==1
    for name,x in [('Alliance',-150),('Horde',-50)]:
        pattern=r'(<FontString name="CharacterCreate'+name+r'Label".*?<Anchor point="TOP" relativePoint="TOP" x=")-?\d+(" y="-20"/>)'
        new,n=re.subn(pattern,lambda m:m[1]+str(x)+m[2],new,count=1,flags=re.S)
        assert n==1
    for i in (1,2,3):
        pattern=r'(<Texture name="CharacterCreateOuterBorder'+str(i)+r'"[^>]*>\s*<Size x=")256'
        new,n=re.subn(pattern,r'\g<1>456',new,count=1)
        assert n==1
    # rows 6 and 7 (eye colour, body type) above the five stock customization rows; hidden by WSRaces.lua when a race has no such option
    row1 = re.search(r'[ \t]*<Frame name="CharacterCustomizationButtonFrame1" .*?</Frame>\r?\n', new, re.S)
    assert row1
    extra = ''
    for n, below in ((6, 1), (7, 6)):
        extra += ('\t\t\t\t\t\t\t<Frame name="CharacterCustomizationButtonFrame%d" inherits="CharacterCustomizationFrameTemplate" id="%d">\r\n'
                  '\t\t\t\t\t\t\t\t<Anchors>\r\n\t\t\t\t\t\t\t\t\t<Anchor point="BOTTOM" relativeTo="CharacterCustomizationButtonFrame%d" relativePoint="TOP" x="0" y="0"/>\r\n'
                  '\t\t\t\t\t\t\t\t</Anchors>\r\n\t\t\t\t\t\t\t</Frame>\r\n') % (n, n, below)
    new = new[:row1.end()] + extra + new[row1.end():]
    # seven rows of 32 px would reach into the class icons: scale all customization rows to fit the space of the original five
    new, n = re.subn(r'(<Frame name="CharacterCustomizationButtonFrame\d" inherits="CharacterCustomizationFrameTemplate" id="\d")>', r'\1 scale="0.74">', new)
    assert n == 7
    pattern=r'<Texture name="CharacterCreateBanners"[^>]*>.*?</Texture>'
    def banners(m):
        first=m[0].replace('x="0" y="-5"','x="-100" y="-5"')
        second=m[0].replace('CharacterCreateBanners','WildStarFactionBanners').replace('x="0" y="-5"','x="100" y="-5"')
        return first+'\n'+second
    new,n=re.subn(pattern,banners,new,count=1,flags=re.S)
    assert n==1
    return new


def lua_str(s):
    return '"' + s.replace('\\', '\\\\').replace('"', '\\"') + '"'


def make_lua(custom, creation, ws_races):
    L = ['-- generated by tools/ws_races.py - WildStar races for the character creation screen', '']
    L.append('-- race icon / background placeholders (stock race sheet) until WildStar race icons are converted')
    for key, wsid, faction, base, icon, bg, name, prefix in RACES:
        for sex, suffix in ((0, '_MALE'), (1, '_FEMALE')):
            c = ICON[icon][sex]
            L.append('RACE_ICON_TCOORDS[%s] = {%s, %s, %s, %s};' % ((lua_str(key.upper() + suffix),) + tuple(repr(float(x)) for x in c)))
        L.append('RACE_INFO_%s = %s;' % (key.upper(), lua_str(RACE_TEXT[key])))
        L.append('%s_DISABLED = %s;' % (key.upper(), lua_str('%s is not available.' % name)))
    L += ['', 'WS_BACKGROUND_FALLBACK = {']
    # Native silhouettes have their own preview transform. A shared camera and
    # attachment point avoids the incompatible Dwarf/Troll camera offsets.
    L += ['\t[%s] = "Human",' % lua_str(k) for k, *_ in RACES]
    L += ['};', 'local WS_OrigGetCreateBackgroundModel = GetCreateBackgroundModel;',
          'function GetCreateBackgroundModel()',
          '\tlocal name = WS_OrigGetCreateBackgroundModel();',
          '\treturn WS_BACKGROUND_FALLBACK[name] or name;', 'end', '']
    L += ['local WS_OrigGetSelectBackgroundModel = GetSelectBackgroundModel;',
          'function GetSelectBackgroundModel(index)',
          '\tlocal name = WS_OrigGetSelectBackgroundModel(index);',
          '\treturn WS_BACKGROUND_FALLBACK[name] or name;', 'end', '']
    L.append('-- customization button texts per race: skin / face / hair style / hair colour / facial option of the WildStar tables')
    for key, wsid, *_ in RACES:
        sexes = custom.get(ws_races[wsid]['enumName'], {'sexes': {}})['sexes']
        male = sexes.get('male') or sexes.get('female') or []
        female = sexes.get('female') or male
        ml, fl = menu_labels(male), menu_labels(female)
        K = key.upper()
        L.append('HAIR_%s_STYLE = %s;' % (K, lua_str(ml['hairStyle'])))
        L.append('HAIR_%s_COLOR = %s;' % (K, lua_str(ml['hairColor'])))
        L.append('FACIAL_HAIR_%sM = %s;' % (K, lua_str(ml['facial'])))
        L.append('FACIAL_HAIR_%sF = %s;' % (K, lua_str(fl['facial'])))
    L.append('')
    L.append('-- every WildStar option per race / sex: { label, slot, number of choices } (CharacterCustomization.csv)')
    L.append('WS_RACE_CUSTOMIZATION = {')
    for key, wsid, *_ in RACES:
        sexes = custom.get(ws_races[wsid]['enumName'], {'sexes': {}})['sexes']
        L.append('\t[%s] = {' % lua_str(key))
        for sex, opts in sexes.items():
            L.append('\t\t%s = {%s},' % (sex, ', '.join('{%s, %s, %d}' % (lua_str(o['label']), lua_str(o['slot']), o['values']) for o in merged(opts))))
        L.append('\t},')
    L.append('};')
    L += ['', '-- Native creation restrictions remain visible in the gender controls.',
          'local WS_OriginalSetCharacterRace = SetCharacterRace;',
          'function SetCharacterRace(id)',
          '\tWS_OriginalSetCharacterRace(id);',
          '\tlocal _, key = GetNameForRace();',
          '\tif key == "WSChua" then',
          '\t\tCharacterCreateGenderButtonFemale:Disable();',
          '\telse',
          '\t\tCharacterCreateGenderButtonFemale:Enable();',
          '\tend', '\tif WS_UpdateCustomizationLabels then WS_UpdateCustomizationLabels(); end', 'end', '']
    L += ['-- Four adjacent faction groups in the expanded left selection panel.',
          'local WS_OriginalEnumerateRaces = CharacterCreateEnumerateRaces;',
          'local WS_Exiles = { WSHuman=true, WSGranok=true, WSAurin=true, WSMordesh=true };',
          'local WS_Dominion = { WSCassian=true, WSDraken=true, WSMechari=true, WSChua=true };',
          'function CharacterCreateEnumerateRaces(...)',
          '\tWS_OriginalEnumerateRaces(...);',
          '\tlocal exiles, dominion, alliance, horde = 0, 0, 0, 0;',
          '\tfor i=1, select("#", ...), 3 do',
          '\t\tlocal index = (i+2)/3;',
          '\t\tlocal key = select(i+1, ...);',
          '\t\tlocal button = _G["CharacterCreateRaceButton"..index];',
          '\t\tbutton:ClearAllPoints();',
          '\t\tif WS_Exiles[key] or WS_Dominion[key] then',
          '\t\t\tlocal row, x;',
          '\t\t\tif WS_Exiles[key] then exiles=exiles+1; row=exiles; x=50;',
          '\t\t\telse dominion=dominion+1; row=dominion; x=150; end',
          '\t\t\tbutton:SetParent(CharacterCreateConfigurationFrame);',
          '\t\t\tbutton:SetScale(1);',
          '\t\t\tbutton:SetPoint("TOP", CharacterCreateConfigurationFrame, "TOP", x, -75-(row-1)*46);',
          '\t\telse',
          '\t\t\tlocal _, faction = GetFactionForRace(index);',
          '\t\t\tlocal row, x;',
          '\t\t\tif faction == "Alliance" then alliance=alliance+1; row=alliance; x=-150;',
          '\t\t\telse horde=horde+1; row=horde; x=-50; end',
          '\t\t\tbutton:SetParent(CharacterCreateConfigurationFrame);',
          '\t\t\tbutton:SetScale(1);',
          '\t\t\tbutton:SetPoint("TOP", CharacterCreateConfigurationFrame, "TOP", x, -75-(row-1)*46);',
          '\t\tend', '\tend', 'end', '']
    L += ['-- Native choices are indices in the five persisted WoW appearance fields; rows 6 and 7 (eye colour, body type) are packed into their high nibbles.',
          'local WS_OriginalUpdateHair = CharacterCreate_UpdateHairCustomization;',
          'function WS_UpdateCustomizationLabels()',
          '\tif not WSGetCustomizationInfo then return; end',
          '\tfor i=1,7 do',
          '\t\tlocal label, selected, count = WSGetCustomizationInfo(i);',
          '\t\tlocal text = _G["CharacterCustomizationButtonFrame"..i.."Text"];',
          '\t\tlocal left = _G["CharacterCustomizationButtonFrame"..i.."LeftButton"];',
          '\t\tlocal right = _G["CharacterCustomizationButtonFrame"..i.."RightButton"];',
          '\t\tlocal row = _G["CharacterCustomizationButtonFrame"..i];',
          '\t\tif i > 5 then if label and label ~= "" then row:Show(); else row:Hide(); end end',
          '\t\tif label then',
          '\t\t\ttext:SetText(count > 0 and (label.." "..selected.."/"..count) or label);',
          '\t\t\tif count > 1 then left:Enable(); right:Enable(); else left:Disable(); right:Disable(); end',
          '\t\telse',
          '\t\t\tif i < 3 then text:SetText(_G["CHAR_CUSTOMIZATION"..i.."_DESC"]); end',
          '\t\t\tleft:Enable(); right:Enable();',
          '\t\tend',
          '\tend', 'end',
          'function CharacterCreate_UpdateHairCustomization()',
          '\tWS_OriginalUpdateHair(); WS_UpdateCustomizationLabels();', 'end',
          'local WS_OriginalCycle = CycleCharCustomization;',
          'function CycleCharCustomization(...)',
          '\tWS_OriginalCycle(...); WS_UpdateCustomizationLabels();', 'end',
          'local WS_OriginalRandomize = RandomizeCharCustomization;',
          'function RandomizeCharCustomization(...)',
          '\tWS_OriginalRandomize(...); WS_UpdateCustomizationLabels();', 'end', '']
    return '\r\n'.join(L) + '\r\n'


if __name__ == '__main__':
    main()
