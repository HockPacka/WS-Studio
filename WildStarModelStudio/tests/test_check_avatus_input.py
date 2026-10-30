"""Regression for dragging Avatus.m3 onto the Windows diagnosis launcher."""
from __future__ import annotations
import contextlib
import io
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT))
from check_avatus import KNOWN_PARTS, check_pack, main
from tests.test_native_m3_extended import enriched


class AvatusInputTests(unittest.TestCase):
    def test_dragged_m3_file_is_accepted(self):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d) / 'Avatus' / 'Avatus.m3'
            p.parent.mkdir()
            p.write_bytes(enriched())
            report = check_pack(p, decode_textures=False)
            self.assertEqual(report['mode'], 'single_m3')
            self.assertEqual(report['folder'], str(p.parent.resolve()))
            self.assertEqual(report['summary']['partsTotal'], 1)
            self.assertTrue(report['parts'][0]['readable'])
            self.assertEqual(report['parts'][0]['name'], 'Avatus.m3')

    def test_folder_mode_preserves_full_pack_checks(self):
        with tempfile.TemporaryDirectory() as d:
            folder = Path(d) / 'Avatus'
            folder.mkdir()
            for name in KNOWN_PARTS:
                (folder / name).write_bytes(enriched())
            report = check_pack(folder, decode_textures=False)
            self.assertEqual(report['mode'], 'avatus_pack')
            self.assertEqual(report['summary']['partsTotal'], 4)
            self.assertEqual(report['summary']['partsReadable'], 4)

    def test_file_path_can_contain_windows_like_clientdata_hierarchy(self):
        with tempfile.TemporaryDirectory() as d:
            folder = Path(d) / 'WoWClient' / 'ClientData' / 'Art' / 'Creature' / 'Avatus'
            folder.mkdir(parents=True)
            m3 = folder / 'Avatus.m3'
            m3.write_bytes(enriched())
            report = check_pack(m3, decode_textures=False)
            self.assertEqual(report['summary']['partsReadable'], 1)

    def test_invalid_path_is_handled_without_traceback(self):
        stderr = io.StringIO()
        with contextlib.redirect_stderr(stderr):
            code = main_with_argv(Path('missing_avatus_xyz.m3'))
        self.assertEqual(code, 2)
        self.assertIn('Pfad existiert nicht', stderr.getvalue())
        self.assertNotIn('Traceback', stderr.getvalue())

    def test_non_m3_file_is_rejected_with_useful_message(self):
        with tempfile.TemporaryDirectory() as d:
            p = Path(d) / 'readme.txt'
            p.write_text('x')
            with self.assertRaisesRegex(ValueError, r'\.m3-Datei'):
                check_pack(p)

    def test_cli_creates_json_for_single_file_even_when_some_textures_missing(self):
        with tempfile.TemporaryDirectory() as d:
            model = Path(d) / 'Avatus' / 'Avatus.m3'
            model.parent.mkdir()
            model.write_bytes(enriched())
            report_file = Path(d) / 'result.json'
            proc = subprocess.run([sys.executable, str(ROOT / 'check_avatus.py'), str(model),
                                   '--headers-only', '--json', str(report_file)], capture_output=True,
                                  text=True, timeout=15)
            # Incomplete synthetic package may have unresolved TEX references.
            self.assertIn(proc.returncode, (0, 1))
            self.assertNotIn('Traceback', proc.stderr)
            self.assertTrue(report_file.exists())
            self.assertIn('single_m3', report_file.read_text())


def main_with_argv(target):
    # main() reads argparse from sys.argv; keep test isolated.
    original = sys.argv
    try:
        sys.argv = ['check_avatus.py', str(target)]
        return main()
    finally:
        sys.argv = original


if __name__ == '__main__':
    unittest.main()
