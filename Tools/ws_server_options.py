#!/usr/bin/env python3
"""Option lists of the WildStar character creation as SQL for the server (own table `ws_race_customization`, nothing of the core tables is touched).

Source: the same code the client uses (Area3/Character.cpp through `character_cli --options`), one row per race / gender / option with the label and the number of choices
for the default selection (some lists depend on the other choices, e.g. hair colours per hair style). How the choices are stored in the five WoW bytes of `characters`:
  option 0 skin colour   -> `skin` bits 0..3          option 4 facial hair / ear / horn style -> `facialStyle`
  option 1 face style    -> `face`                    option 5 eye colour -> `hairColor` bits 4..7
  option 2 hair style    -> `hairStyle`               option 6 body type  -> `skin` bits 4..7
  option 3 hair colour   -> `hairColor` bits 0..3
The value stored is the index (0 based) into the choice list of the client's native tables.
usage: ws_server_options.py [--client <WoWClient>] [--out <dir>] [--apply "<AzerothCore folder>"]
"""
import argparse
import csv
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ws_content_output import DEFAULT_CLIENT, Output, add_output_arguments, reject_server_install  # noqa: E402

FIELD = ['skin (bits 0..3)', 'face', 'hairStyle', 'hairColor (bits 0..3)', 'facialStyle', 'hairColor (bits 4..7)', 'skin (bits 4..7)']
RACE_NAME = {22: 'Human (Exile)', 23: 'Granok', 24: 'Aurin', 25: 'Mordesh', 26: 'Cassian', 27: 'Draken', 28: 'Mechari', 29: 'Chua'}

ap = argparse.ArgumentParser()
ap.add_argument('--client', default=DEFAULT_CLIENT)
ap.add_argument('--apply', help='AzerothCore folder: also run the SQL against its acore_world database (mysql in <folder>\\mysql\\bin)')
add_output_arguments(ap)
a = ap.parse_args()
out = Output(a)
exe = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'wowdecomp', 'build', 'x64', 'bin', 'Release', 'character_cli.exe')
text = subprocess.run([exe, '--options'], cwd=a.client, capture_output=True, text=True, check=True).stdout
rows = [l.split('\t') for l in text.splitlines() if l.count('\t') == 4]
sqld = out.adapter_path('sql')
os.makedirs(sqld, exist_ok=True)
esc = lambda s: s.replace("'", "''")
install = os.path.join(sqld, 'ws_race_options.world.sql')
uninstall = os.path.join(sqld, 'ws_race_options.uninstall.world.sql')

with open(install, 'w', encoding='utf-8') as f:
    f.write('-- WildStar character creation options per race (client: Area3/Character.cpp). Own table, safe to re-run.\n')
    f.write('CREATE TABLE IF NOT EXISTS `ws_race_customization` (\n'
            '  `race` TINYINT UNSIGNED NOT NULL, `race_name` VARCHAR(32) NOT NULL, `gender` TINYINT UNSIGNED NOT NULL, `option_index` TINYINT UNSIGNED NOT NULL,\n'
            '  `label` VARCHAR(32) NOT NULL, `choices` SMALLINT UNSIGNED NOT NULL, `stored_in` VARCHAR(32) NOT NULL,\n'
            '  PRIMARY KEY (`race`, `gender`, `option_index`)) ENGINE=InnoDB;\n')
    f.write('DELETE FROM `ws_race_customization` WHERE `race` BETWEEN 22 AND 29;\n')
    vals = []

    for race, sex, option, label, count in rows:
        race, sex, option, count = int(race), int(sex), int(option), int(count)

        if not label and not count:
            continue   # option not available for this race / gender

        vals.append("(%d, '%s', %d, %d, '%s', %d, '%s')" % (race, esc(RACE_NAME.get(race, str(race))), sex, option, esc(label), count, FIELD[option]))

    f.write('INSERT INTO `ws_race_customization` (`race`, `race_name`, `gender`, `option_index`, `label`, `choices`, `stored_in`) VALUES\n' + ',\n'.join(vals) + ';\n')

with open(uninstall, 'w', encoding='utf-8') as f:
    f.write('DROP TABLE IF EXISTS `ws_race_customization`;\n')

print('%d option rows -> %s' % (len(vals), install))

if a.apply:
    mysql = os.path.join(a.apply, 'mysql', 'bin', 'mysql.exe')
    r = subprocess.run([mysql, '-uacore', '-pacore', '-h127.0.0.1', '-P3306', 'acore_world', '-e', 'source ' + install.replace(chr(92), '/')], capture_output=True, text=True)
    print('mysql exit', r.returncode, (r.stderr or '').replace('mysql: [Warning] Using a password on the command line interface can be insecure.', '').strip())

out.finish('server-options')
