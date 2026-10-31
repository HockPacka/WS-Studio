"""Information of the WildStar structures (.i3) that the WoW 3.3.5a WMO conversion does not carry over: counts over all files -> docs/i3_wow_loss_report.md
usage: i3_loss_report.py <ClientData dir> [out.md]
"""
import collections
import os
import struct
import sys

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import i3_reader as r  # noqa: E402

H = 0x170


def al(x):
    return (x + 15) & ~15


def slot(b, o):
    return struct.unpack_from('<IxxxxQ', b, o)


def main():
    client = sys.argv[1]
    out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'docs', 'i3_wow_loss_report.md')
    stat = collections.Counter()
    kinds = collections.Counter()
    sub_kinds = collections.Counter()
    param_slots = collections.Counter()

    for dp, _, fs in os.walk(os.path.join(client, 'Art')):
        low = {x.lower(): x for x in fs}

        for f in fs:
            if not f.endswith('.i3'):
                continue

            b = open(os.path.join(dp, f), 'rb').read()

            if b[:4] == b'FEDS':
                stat['sector files'] += 1
                p = r.parse(b)
                n = p['arrays']['pos'][0]
                stat['sector vertices'] += n
                stat['sector triangles'] += p['arrays']['index'][0] // 3

                if n:
                    pos, nrm, uv0, uv1, rgba = r.decode_vertices(b, p)
                    raw = np.frombuffer(b, np.uint8, n * 20, r.HEADER + p['arrays']['vtx20'][1]).reshape(-1, 20)

                    if np.abs(uv1).max() > 0:
                        stat['sectors with a second UV set'] += 1

                    if (raw[:, 16] != 0).any():
                        stat['sectors with vertex flag byte 16 = 255'] += 1

                    if len(set(raw[:, 17].tolist())) > 1 or len(set(raw[:, 18].tolist())) > 1:
                        stat['sectors with varying vertex colour bytes 17 / 18'] += 1

                c, o, _ = p['arrays']['submesh']

                for i in range(c):
                    rec = struct.unpack_from('<7I', b, r.HEADER + o + i * 28)
                    sub_kinds[rec[0]] += 1

                if p['arrays']['kd_nodes'][0]:
                    stat['sectors with a kd tree'] += 1

            elif b[:4] == b'FEDI':
                stat['model files'] += 1
                cnt, off = slot(b, 0x40)
                stat['material sets'] += cnt

                if cnt > 1:
                    stat['models with several material sets (variants)'] += 1

                if not cnt:
                    continue

                arr = H + off
                child = arr + al(cnt * 0x58)

                for si in range(cnt):
                    rr = arr + si * 0x58
                    tc, to = slot(b, rr + 0x38)
                    ta = child + to
                    string_base = ta + tc * 0x20
                    textures = []
                    for t in range(tc):
                        nc, no = slot(b, ta + t * 0x20 + 0x10)
                        raw = b[string_base + no:string_base + no + nc * 2]
                        textures.append(raw.decode('utf-16le', 'replace').rstrip('\0'))
                    c2, o2 = slot(b, rr + 0x18)
                    a2 = child + o2
                    ch2 = a2 + al(c2 * 0x28)
                    stat['passes'] += c2

                    for q in range(c2):
                        qq = a2 + q * 0x28
                        c3, o3 = slot(b, qq + 0x18)
                        mb = ch2 + o3 + al(c3 * 0x128)

                        for k in range(c3):
                            mr = ch2 + o3 + k * 0x128
                            v = struct.unpack_from('<8H', b, mr)
                            stat['materials'] += 1
                            kinds[v[4]] += 1
                            has = False

                            for s in range(11):
                                n, o1, o2_ = struct.unpack_from('<IxxxxQQ', b, mr + 0x18 + s * 0x18)

                                if n:
                                    param_slots[s] += 1
                                    has = True
                                    if s in (1, 2, 3) and n > 1:
                                        stat['animated gloss / glow / opacity tracks (first key exported)'] += 1

                            stat['materials with parameters'] += has
                            if v[1] < len(textures) and textures[v[1]]:
                                low = textures[v[1]].lower()
                                if 'blank_normal' in low or 'blank normal' in low:
                                    stat['placeholder normal maps (intentionally skipped)'] += 1
                                else:
                                    stat['normal maps transferred to WMO texture 2'] += 1
                            else:
                                stat['materials without a normal map'] += 1

    lines = ['# i3 -> WoW 3.3.5a WMO: what is not carried over', '',
             'Generated by `tools/i3_loss_report.py` over `%s`. See `docs/i3_dgn_format.md`, `docs/i3_shader_notes.md`.' % client, '', '## Counts', '']

    for k, v in sorted(stat.items()):
        lines.append('* %s: %d' % (k, v))

    lines += ['', '## Material `kind` (u16 at +8 of the 0x128 material record)', '']
    lines += ['* kind %d: %d materials' % (k, v) for k, v in sorted(kinds.items())]
    lines += ['', '## Sub mesh `kind` (first field of the FEDS sub mesh record)', '']
    lines += ['* kind %d: %d sub meshes' % (k, v) for k, v in sorted(sub_kinds.items())]
    lines += ['', '## Material parameter slots in use (slot -> materials)', '']
    lines += ['* slot %d: %d' % (k, v) for k, v in sorted(param_slots.items())]
    lines += ['', '## Transferred into the WMO / client extension',
              '',
              '* UV0 and UV1 are retained in two `MOTV` chunks.',
              '* Genuine normal maps are retained in `MOMT.m_texture2`; blank-normal placeholders are skipped.',
              '* The first gloss, glow and opacity keys are stored as UNORM8 values and evaluated by the marked-material pixel shader.',
              '* The tangent frame is reconstructed from view-position and UV derivatives. COLOR2 is not a vertex colour and is not written as `MOCV`.',
              '', '## Not represented, or only partially represented',
              '',
              '| WildStar data | WMO / client | consequence |', '|---|---|---|',
              '| animated gloss / glow / opacity tracks | first key only | temporal material changes are lost |',
              '| height / parallax tracks (slots 4, 6, 7, 8, 9) | preserved by the native I3 reader, not rendered | original surface depth is not reproduced |',
              '| color mod track (slot 10) | preserved by the native I3 reader, not rendered | original RGB modulation is not reproduced |',
              '| second UV set | retained in WMO, not sampled by the current material shader | UV1-dependent detail is not visible |',
              '| alpha of the colour texture (tint / glow mask) | opacity only; mask semantics not reconstructed | original tint / masked glow can differ |',
              '| material variants | set 0 only | other colour schemes not selectable |',
              '| WildStar light shapes, animated intensity and exact attenuation | WoW point-light approximation | lighting is not fully original |']
    open(out, 'w', encoding='utf-8').write('\n'.join(lines) + '\n')
    print('written', out)


if __name__ == '__main__':
    main()
