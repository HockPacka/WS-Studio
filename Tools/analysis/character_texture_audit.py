"""Trace actual composed-character texture loads; absent region files are candidates,
not automatically missing required assets (some components paint only a subset).
"""
from pathlib import Path
from concurrent.futures import ThreadPoolExecutor
from collections import Counter
import json,os,subprocess
ROOT=Path(__file__).resolve().parents[2]
OUT=ROOT/'build_m3test/character_texture_audit';OUT.mkdir(exist_ok=True)
exe=ROOT/'wowdecomp/build/x64/bin/Release/character_cli.exe'
def run(pair):
    race,sex=pair
    args=[str(exe),str(race),str(sex),'0','0','1','0','1','0','0']
    p=subprocess.run(args,cwd=ROOT/'WoWClient',env=dict(os.environ,WS_CHAR_AUDIT='1'),capture_output=True,text=True,timeout=180)
    (OUT/f'{race}_{sex}.log').write_text(p.stdout+'\n'+p.stderr,encoding='utf-8')
    if p.returncode:raise AssertionError((race,sex,p.returncode,p.stderr))
    entries={tuple(line.split('\t')[1:]) for line in p.stdout.splitlines() if line.startswith('texture_source\t')}
    for kind,display,region,state,path in entries:
        if state=='loaded':assert (ROOT/'WoWClient/ClientData'/path).is_file(),path
        if race==29:assert '\\Mordesh\\' not in path,'cross-race cybernetics must not be offered to Chua'
    return dict(race=race,sex=sex,counts=dict(Counter((row[0]+':'+row[3]) for row in entries)),
                entries=[dict(zip(['kind','display','region','state','path'],row)) for row in sorted(entries)])
pairs=[(r,s) for r in range(22,30) for s in ([0] if r==29 else [0,1])]
with ThreadPoolExecutor(max_workers=3) as pool:profiles=list(pool.map(run,pairs))
totals=Counter()
for profile in profiles:totals.update(profile['counts'])
report=dict(scope='15 initial profiles plus seven individual option cycles per profile; not every Cartesian appearance combination',
    absentMeaning='candidate region paths not provided; not proven missing required textures',totals=dict(totals),profiles=profiles)
(OUT/'report.json').write_text(json.dumps(report,indent=2),encoding='utf-8')
print('PASS native texture source trace:',dict(totals))
