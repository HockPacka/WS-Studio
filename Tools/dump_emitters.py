#!/usr/bin/env python3
"""Dump the effect emitters of an .m3 as JSON.   usage: dump_emitters.py <file.m3> [out.json]"""
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, 'blender_addon', 'wildstar_m3'))
import emitter  # noqa: E402
import m3  # noqa: E402


def half(raw, n):
    return list(struct.unpack('<%de' % n, raw[:2 * n]))


def decode(p):
    """typed view of a property's values by its measured stride"""
    if not p.count:
        return None
    st = p.stride or 4
    if st == 1:
        vals = list(p.raw[:p.count])
    elif st == 2:
        vals = half(p.raw, p.count)
    elif st == 4:
        vals = [half(p.raw[i * 4:i * 4 + 4], 2) for i in range(p.count)]
    elif st == 6:
        vals = [half(p.raw[i * 6:i * 6 + 6], 3) for i in range(p.count)]
    elif st == 12:
        vals = [list(struct.unpack('<3f', p.raw[i * 12:i * 12 + 12])) for i in range(p.count)]
    else:
        vals = [p.raw[i * st:(i + 1) * st].hex() for i in range(p.count)]
    return vals


def main():
    data = open(sys.argv[1], 'rb').read()
    model = m3.read_model(data)
    out = []
    for em in emitter.read_emitters(data):
        d = {'index': em.index, 'bone': em.bone, 'type': 'ribbon' if em.type == 1 else 'particle', 'valid': em.valid,
             'ints': list(em.ints), 'flags': list(em.flags), 'floats': [round(x, 5) for x in em.floats],
             'textures': [model.textures[t][0] for t in em.texture_ids if t != 0xFFFF and t < len(model.textures)],
             'properties': []}
        for p in em.props:
            if p.count:
                d['properties'].append({'index': p.index, 'offset': hex(p.pos), 'count': p.count, 'stride': p.stride or None,
                                        'times': list(p.keys), 'values': decode(p)})
        if em.type == 0 and em.valid and em.template_offset < (1 << 40):
            c, off = struct.unpack_from('<QQ', data, 0x2F8)
            base = ((off + 0x630 + c * 0xA0) + 15) & ~15
            d['gradients'] = emitter.decoded_gradients(data, base + em.template_offset)
        out.append(d)
    txt = json.dumps(out, indent=1, default=str)
    if len(sys.argv) > 2:
        open(sys.argv[2], 'w', encoding='utf-8').write(txt)
        print('%d emitters -> %s' % (len(out), sys.argv[2]))
    else:
        print(txt[:4000])


if __name__ == '__main__':
    main()
