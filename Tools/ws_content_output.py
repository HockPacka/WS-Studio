"""Offline WildStar content generation. Never opens a server DB or server tree.

Original WoW DBCs are read from the supplied client's MPQs. Generated files
belong to a staging directory; copying to a client requires --install-client.
Server installation is deliberately outside these generators.
"""
import hashlib
import json
from pathlib import Path
import mpq_extract

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_CLIENT = str(ROOT / 'WoWClient')
DEFAULT_OUTPUT = str(ROOT / 'build_wildstar' / 'generated')

class ClientArchive:
    def __init__(self, data_dir):
        self.arcs=[]
        for rel in mpq_extract.ORDER:
            path=Path(data_dir)/rel
            if path.is_file():self.arcs.append(mpq_extract.Mpq(str(path)))

    def get(self, name):
        for archive in self.arcs:
            data=archive.read(name)
            if data and data!=b'PATCH':return data
        raise FileNotFoundError(name)

def add_output_arguments(parser):
    parser.add_argument('--output',default=DEFAULT_OUTPUT,help='staging directory; no server writes')
    parser.add_argument('--install-client',action='store_true',help='also copy generated client overrides into --client')

def reject_server_install(parser,args):
    if getattr(args,'server',None) or getattr(args,'apply',False):
        parser.error('Direct server installation has been removed. Generate an offline package with --output; server adapters are separate.')

class Output:
    def __init__(self,args):
        self.root=Path(args.output).resolve();self.client=Path(args.client).resolve()
        if self.root==self.client or self.client in self.root.parents:
            raise ValueError('--output must be outside the source client tree')
        self.install=args.install_client
        self.archive=ClientArchive(self.client/'Data')

    def original_dbc(self,name):
        return self.archive.get('DBFilesClient\\'+name+'.dbc')

    def client_path(self,relative):
        path=self.root/'client'/Path(relative.replace('\\','/'))
        path.parent.mkdir(parents=True,exist_ok=True)
        return str(path)

    def adapter_path(self,relative):
        path=self.root/'server'/'adapters'/'azerothcore'/Path(relative)
        path.parent.mkdir(parents=True,exist_ok=True)
        return str(path)

    def install_client_file(self,relative):
        if not self.install:return
        rel=Path(relative.replace('\\','/'));source=self.root/'client'/rel;dest=self.client/rel
        dest.parent.mkdir(parents=True,exist_ok=True)
        if dest.is_file():
            digest=hashlib.sha256(dest.read_bytes()).hexdigest()[:16]
            backup=self.root/'backups'/'client'/rel.parent/(rel.name+'.'+digest)
            backup.parent.mkdir(parents=True,exist_ok=True)
            if not backup.exists():backup.write_bytes(dest.read_bytes())
        dest.write_bytes(source.read_bytes())

    def finish(self,component):
        manifest=self.root/'generation.json'
        data=json.loads(manifest.read_text(encoding='utf-8')) if manifest.exists() else {'schemaVersion':1,'components':[]}
        if component not in data['components']:data['components'].append(component)
        data.update(serverInstallation=False,clientInstalled=self.install,source='client MPQs and original WildStar ClientData',
                    serverAdapter='azerothcore SQL output only; not core-independent SQL')
        manifest.parent.mkdir(parents=True,exist_ok=True);manifest.write_text(json.dumps(data,indent=2)+'\n',encoding='utf-8')
        print('Offline output:',self.root,'(server untouched)')
