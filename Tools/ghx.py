"""Local Ghidra MCP read-only GET client (v7 schema: /mcp/schema).

Examples: ghx.py force_decompile function=1402da040 program=WildStar64.exe
          ghx.py get_xrefs_to address=140350f40 program=WildStar64.exe
Always select the intended program explicitly. /decompile_function is obsolete.
"""
import json
import sys
import urllib.parse
import urllib.request

BASE = 'http://127.0.0.1:8089'


def call(endpoint, **params):
    q = urllib.parse.urlencode({k: v for k, v in params.items() if v is not None})
    with urllib.request.urlopen('%s/%s?%s' % (BASE, endpoint.strip('/'), q), timeout=120) as r:
        return r.read().decode('utf-8', 'replace')


if __name__ == '__main__':
    kv = dict(a.split('=', 1) for a in sys.argv[2:])
    out = call(sys.argv[1], **kv)
    try:
        print(json.dumps(json.loads(out), indent=1)[:int(kv.get('_max', 12000))] if False else out[:20000])
    except Exception:
        print(out[:20000])
