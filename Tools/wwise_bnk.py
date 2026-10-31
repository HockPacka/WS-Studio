"""Minimal Wwise soundbank (.bnk, version 88) reader: object table of the HIRC chunk plus a reference walk.

The node parameter blocks are not parsed. Instead an object's blob is scanned for 32-bit values that are the id of another HIRC object or the id of a media
file (<id>.wem); that is enough to collect every media file an event can play (event -> actions -> containers / music segments -> tracks -> sources).
usage: wwise_bnk.py <bank.bnk> [Name | hash]   - lists the media of the event with that name (FNV-1 of the lower case name) or hash
"""
import os
import struct
import sys

TYPES = {1: 'Settings', 2: 'Sound', 3: 'Action', 4: 'Event', 5: 'RandomSeq', 6: 'SwitchCont', 7: 'ActorMixer', 8: 'AudioBus', 9: 'BlendCont',
         10: 'MusicSegment', 11: 'MusicTrack', 12: 'MusicSwitch', 13: 'MusicPlaylist', 14: 'Attenuation', 15: 'DialogueEvent', 16: 'Motion', 17: 'MotionFx',
         18: 'Effect', 19: 'Unknown19', 20: 'AuxBus'}


def fnv(name):
    h = 2166136261

    for c in name.lower().encode('ascii'):
        h = (h * 16777619) & 0xFFFFFFFF
        h ^= c

    return h


class Bank:
    def __init__(self, path):
        b = open(path, 'rb').read()
        self.objs = {}
        o = 0

        while o + 8 <= len(b):
            tag, size = struct.unpack_from('<4sI', b, o)
            body = b[o + 8:o + 8 + size]

            if tag == b'BKHD':
                self.version, self.bank_id = struct.unpack_from('<II', body, 0)
            elif tag == b'HIRC':
                n = struct.unpack_from('<I', body, 0)[0]
                p = 4

                for _ in range(n):
                    t = body[p]
                    sz = struct.unpack_from('<I', body, p + 1)[0]
                    oid = struct.unpack_from('<I', body, p + 5)[0]
                    self.objs[oid] = (t, body[p + 9:p + 5 + sz])
                    p += 5 + sz

            o += 8 + size

    def refs(self, oid, media):
        """ids of other objects (and media ids) mentioned by an object's blob"""
        t, blob = self.objs[oid]
        out = []

        if t == 4:   # event: u32 count, action ids
            n = struct.unpack_from('<I', blob, 0)[0]
            return [struct.unpack_from('<I', blob, 4 + 4 * i)[0] for i in range(n)], []

        found, med = [], []

        for i in range(0, len(blob) - 3):
            v = struct.unpack_from('<I', blob, i)[0]

            if v != oid and v in self.objs:
                found.append(v)
            elif v in media:
                med.append(v)

        return found, med

    def event_media(self, event_id, media):
        seen, todo, wems = set(), [event_id], []

        while todo:
            c = todo.pop()

            if c in seen or c not in self.objs:
                continue

            seen.add(c)
            kids, med = self.refs(c, media)
            wems += med
            todo += kids

        return seen, sorted(set(wems))


if __name__ == '__main__':
    bank = Bank(sys.argv[1])
    print('version', bank.version, 'objects', len(bank.objs))
    counts = {}

    for t, _ in bank.objs.values():
        counts[TYPES.get(t, t)] = counts.get(TYPES.get(t, t), 0) + 1

    print(counts)

    if len(sys.argv) > 2:
        key = sys.argv[2]
        eid = int(key) & 0xFFFFFFFF if key.lstrip('-').isdigit() else fnv(key)
        audio = os.path.dirname(os.path.abspath(sys.argv[1]))
        media = {int(f[:-4]) for f in os.listdir(audio) if f.endswith('.wem') and f[:-4].isdigit()}
        print('event id', eid, 'present', eid in bank.objs)

        if eid in bank.objs:
            seen, wems = bank.event_media(eid, media)
            print(len(seen), 'objects', len(wems), 'media', wems[:20])
