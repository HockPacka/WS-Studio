"""Compare every stored JPEG-like/DXT mip of selected TEX files with a C++ BLP.

usage: texture_mip_check.py tex_to_blp_cli.exe cases.txt output_directory
cases.txt contains one TEX path per line. Also asserts known blank colours.
"""
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys

import numpy as np

spec = importlib.util.spec_from_file_location('tex', Path(__file__).resolve().parents[1] / 'blender_addon/wildstar_m3/tex.py')
tex = importlib.util.module_from_spec(spec); spec.loader.exec_module(tex)


def main():
    out = Path(sys.argv[3]); out.mkdir(parents=True, exist_ok=True)
    results = []
    for index, name in enumerate(Path(sys.argv[2]).read_text().splitlines()):
        if not name.strip(): continue
        path = Path(name); data = path.read_bytes(); hdr = tex.parse_header(data)
        blp_path = out / f'{index:03d}.blp'
        subprocess.run([sys.argv[1], str(path), str(blp_path)], check=True)
        b = blp_path.read_bytes(); w, h = struct.unpack_from('<II',b,12)
        if not hdr['is_jpg'] and hdr['fmt'] in (13, 14, 15):
            # DXT payloads are passed through, including their alpha blocks.
            fmt = hdr['fmt']
            assert b[8] == 2 and b[9] == {13: 1, 14: 4, 15: 8}[fmt]
            source = {}
            pos = tex.HEADER_SIZE
            for i in range(hdr['mips']):
                shift = hdr['mips'] - 1 - i
                mw, mh = max(1, hdr['w'] >> shift), max(1, hdr['h'] >> shift)
                size = ((mw + 3) // 4) * ((mh + 3) // 4) * (8 if fmt == 13 else 16)
                source[mw, mh] = data[pos:pos + size]
                pos += size
            levels = []
            for mip in range(16):
                off = struct.unpack_from('<I', b, 0x14 + mip * 4)[0]
                size = struct.unpack_from('<I', b, 0x54 + mip * 4)[0]
                if not size: break
                mw, mh = max(1, w >> mip), max(1, h >> mip)
                assert b[off:off + size] == source[mw, mh], (path, mip)
                levels.append(dict(width=mw, height=mh, max_error=0, mean_error=0.0))
            assert levels[-1]['width'] == levels[-1]['height'] == 1, path
            results.append(dict(path=str(path), format=f'DXT{ {13: 1, 14: 3, 15: 5}[fmt]}', mips=levels))
            continue
        # Decoded JPG-like sources may be emitted as raw BGRA or as the client's
        # memory-saving DXT1/DXT5 encoding. Compare pixels in either case; DXT
        # introduces loss, so its mean error is bounded instead of requiring
        # the raw converter's exact two-byte round trip.
        compressed = b[8] == 2
        assert (compressed and b[10] in (0, 7)) or (b[8] == 3 and b[9] == 8), (path,b[8],b[9],b[10])
        levels = []
        for mip in range(16):
            off = struct.unpack_from('<I', b, 0x14 + mip*4)[0]
            size = struct.unpack_from('<I', b, 0x54 + mip*4)[0]
            if not size: break
            mw, mh = max(1,w>>mip), max(1,h>>mip)
            if compressed:
                actual = tex.decode_dxt(b[off:off+size],mw,mh,{0:1,7:5}[b[10]])
            else:
                actual = np.frombuffer(b,np.uint8,count=mw*mh*4,offset=off).reshape(mh,mw,4)[..., [2,1,0,3]]
            source_mip = hdr['mip_count'] - 1 - mip
            assert source_mip >= 0, (path,mip)
            ref = tex.decode_jpg(data,hdr,tex.HEADER_SIZE,source_mip,mw,mh)
            delta = np.abs(actual.astype(int)-ref.astype(int))
            if compressed:
                assert delta.mean() <= 12, (path,mip,delta.max(),delta.mean())
            else:
                assert delta.max() <= 2, (path,mip,delta.max(),delta.mean())
            expected = {'blank_grey.tex':128,'blank_wte.tex':255}.get(path.name.lower())
            if expected is not None:
                tolerance = 4 if compressed else 0
                assert np.all(np.abs(actual[...,:3].astype(int)-expected) <= tolerance), (path,mip,np.unique(actual[...,:3]))
                assert np.all(actual[...,3] == 255), (path,mip,'alpha')
            levels.append(dict(width=mw,height=mh,max_error=int(delta.max()),mean_error=float(delta.mean())))
        assert levels[-1]['width'] == levels[-1]['height'] == 1, path
        results.append(dict(path=str(path),mips=levels))
    report = dict(textures=len(results),mips=sum(len(r['mips']) for r in results),results=results)
    (out/'validation.json').write_text(json.dumps(report,indent=2))
    print('PASS',report['textures'],'textures,',report['mips'],'mips including 1x1')


if __name__ == '__main__': main()
