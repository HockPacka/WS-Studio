#!/usr/bin/env python3
"""Extract WildStar .archive/.index pairs to disk in raw (unconverted) form.

Built on Halon's index parser. Differences to `halon.py extract`:
  - opens the archive once instead of once per file
  - supports deflate (type 3) as well as LZMA (type 5) and stored (type 1)
  - resumable: skips files that already exist with the right size
  - continues on errors and writes them to a log
"""
import argparse
import os
import struct
import sys
import time
import lzma
import zlib

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'Halon'))
import halon  # noqa: E402


def decompress(file, contents):
    if file.compression == 1:
        data = contents
    elif file.compression == 3:
        data = zlib.decompressobj(-15).decompress(contents)
    elif file.compression == 5:
        props = contents[:5] + struct.pack('<Q', file.uncompressed_size) + contents[5:]
        data = lzma.LZMADecompressor(format=lzma.FORMAT_ALONE).decompress(props)
    else:
        raise ValueError('unknown compression type %d' % file.compression)
    if len(data) != file.uncompressed_size:
        raise ValueError('size mismatch: got %d, expected %d' % (len(data), file.uncompressed_size))
    return data


def walk(directory):
    yield from directory.files.values()
    for sub in directory.dirs.values():
        yield from walk(sub)


def extract_archive(base, out_root, only, log):
    name = os.path.basename(base)
    if not (os.path.exists(base + '.index') and os.path.exists(base + '.archive')):
        print('[%s] .index/.archive missing, skipped' % name)
        return 0, 0, 0
    fs = halon.Filesystem(base)
    root = fs[only] if only else fs.root
    if isinstance(root, halon.File):
        files = [root]
    else:
        files = list(walk(root))
    out_dir = os.path.join(out_root, name)
    print('[%s] %d files -> %s' % (name, len(files), out_dir))

    done = skipped = failed = 0
    start = time.time()
    with open(fs.data.name, 'rb') as archive:
        for i, f in enumerate(files, 1):
            target = os.path.join(out_dir, f.path)
            try:
                if os.path.exists(target) and os.path.getsize(target) == f.uncompressed_size:
                    skipped += 1
                    continue
                index, _ = fs.data.blocks[f.sha1]
                offset, blocksize = fs.data.fs[index]
                archive.seek(offset)
                data = decompress(f, archive.read(blocksize))
                os.makedirs(os.path.dirname(target), exist_ok=True)
                with open(target, 'wb') as out:
                    out.write(data)
                done += 1
            except Exception as e:  # keep going, report at the end
                failed += 1
                log.write('%s\t%s\t%s: %s\n' % (name, f.path, type(e).__name__, e))
            if i % 5000 == 0:
                print('  %d/%d  (%.0fs)' % (i, len(files), time.time() - start), flush=True)
    print('[%s] extracted %d, skipped %d, failed %d in %.0fs' % (name, done, skipped, failed, time.time() - start))
    return done, skipped, failed


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    root = os.path.dirname(here)
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument('--patch-dir', default=os.path.join(root, 'WildStar', 'Patch'))
    p.add_argument('--out', default=os.path.join(root, 'extracted'))
    p.add_argument('--archives', nargs='+', default=['ClientData', 'ClientDataEN', 'ClientDataDE'])
    p.add_argument('--only', default='', help='only extract this path inside each archive, e.g. Art/Creature')
    a = p.parse_args()

    os.makedirs(a.out, exist_ok=True)
    totals = [0, 0, 0]
    with open(os.path.join(a.out, 'extract_errors.log'), 'w', encoding='utf-8') as log:
        for name in a.archives:
            try:
                r = extract_archive(os.path.join(a.patch_dir, name), a.out, a.only, log)
            except FileNotFoundError as e:
                print('[%s] path not found in archive: %s' % (name, e))
                continue
            totals = [x + y for x, y in zip(totals, r)]
    print('TOTAL extracted %d, skipped %d, failed %d' % tuple(totals))
    if totals[2]:
        print('See %s' % os.path.join(a.out, 'extract_errors.log'))
    return 1 if totals[2] else 0


if __name__ == '__main__':
    sys.exit(main())
