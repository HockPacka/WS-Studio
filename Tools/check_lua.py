import re, sys

path = sys.argv[1] if len(sys.argv) > 1 else 'WoWClient/WoWOverride/Interface/GlueXML/WSRaces.lua'
with open(path, 'r', encoding='utf-8') as f:
    text = f.read()

text = re.sub(r'--\[\[.*?\]\]', '', text, flags=re.DOTALL)
text = re.sub(r'--[^\n]*', '', text)
text = re.sub(r'"(?:\\.|[^"\\])*"', '""', text)
text = re.sub(r"'(?:\\.|[^'\\])*'", "''", text)

tokens = re.findall(r'\b(?:function|then|do|repeat|until|end)\b', text)
stack = []
for tok in tokens:
    if tok in ('function', 'then', 'do', 'repeat'):
        stack.append(tok)
    elif tok == 'end':
        if not stack:
            print('Extra end!')
            sys.exit(1)
        top = stack.pop()
        if top not in ('function', 'then', 'do'):
            print(f'Mismatched end for {top}')
            sys.exit(1)
    elif tok == 'until':
        if not stack:
            print('Extra until!')
            sys.exit(1)
        top = stack.pop()
        if top != 'repeat':
            print(f'Mismatched until for {top}')
            sys.exit(1)

if stack:
    print('Remaining open blocks:', stack)
    sys.exit(1)
else:
    print('LUA SYNTAX PERFECT!')
