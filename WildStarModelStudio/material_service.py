"""Resolve local WildStar TEX files, including extracted per-creature asset packs.

No path from an M3 file is used directly outside a trusted selected root.
"""
from __future__ import annotations
from pathlib import Path
import secrets
import struct

TEXTURE_LIMIT = 32 * 1024 * 1024


def clientdata_root(model_path: Path | None) -> Path | None:
    if not model_path:
        return None
    resolved = model_path.resolve()
    for p in (resolved.parent, *resolved.parents):
        if p.name.casefold() == 'clientdata':
            return p
    return None


def _casefold_path(root: Path, virtual: str) -> Path | None:
    """Case-insensitive relative lookup with symlink escape prevention."""
    norm = virtual.replace('\\', '/').strip()
    parts = norm.split('/')
    if not parts or any(not p or p in ('.', '..') or ':' in p or '\x00' in p for p in parts):
        return None
    cur = root
    for part in parts:
        if not cur.is_dir():
            return None
        exact = cur / part
        if exact.is_file() or exact.is_dir():
            cur = exact
            continue
        try:
            cur = next((q for q in cur.iterdir() if q.name.casefold() == part.casefold()), None)
        except (OSError, PermissionError):
            return None
        if cur is None:
            return None
    try:
        if not cur.resolve().is_relative_to(root.resolve()):
            return None
    except (OSError, ValueError):
        return None
    return cur if cur.is_file() and cur.suffix.casefold() == '.tex' else None


def texture_path(root: Path, virtual: str) -> Path | None:
    if not virtual or len(virtual) > 1024:
        return None
    path = virtual.replace('\\', '/')
    if path.casefold().startswith('clientdata/'):
        path = path[len('clientdata/'):]
    return _casefold_path(root, path)


def pack_texture_path(model_path: Path | None, virtual: str, selected_root: Path | None = None) -> Path | None:
    """Find official Creature/<name>/Textures/<file> in a flat extracted pack.

    WS-Tools/Avatus/Avatus.m3 + WS-Tools/Avatus/Textures/*.tex is a real
    example, while the model refers to Art/Creature/Avatus/Textures/*.tex.
    Only the exact creature name, Textures folder and basename are accepted.
    """
    if not virtual or len(virtual) > 1024:
        return None
    path = virtual.replace('\\', '/').strip()
    parts = path.split('/')
    if len(parts) < 5 or any(not part or part in ('.', '..') or ':' in part or '\x00' in part for part in parts):
        return None
    if (len(parts) != 5 or parts[0].casefold() != 'art' or
            parts[1].casefold() != 'creature' or parts[3].casefold() != 'textures' or
            not parts[4].casefold().endswith('.tex')):
        return None
    creature, filename = parts[2], parts[4]
    candidates = []
    if model_path is not None and model_path.parent.name.casefold() == creature.casefold():
        candidates.append(model_path.parent)
    if selected_root is not None:
        candidates.append(selected_root)
        candidates.append(selected_root / creature)
    for base in candidates:
        if not base.is_dir() or base.name.casefold() != creature.casefold():
            continue
        found = _casefold_path(base, f'Textures/{filename}')
        if found:
            return found
    return None


def attach_materials(server, model: dict, model_path: Path | None = None) -> dict:
    server.asset_paths = {}
    server.asset_cache = {}
    server.asset_token = secrets.token_hex(16)
    if model.get('format') != 'M3':
        return model
    selected_root = getattr(server, 'texture_root', None)
    root = clientdata_root(model_path) or selected_root
    details = model.get('m3Details') or {}
    textures = details.get('textures') or []
    assets = []
    for i, texture in enumerate(textures):
        virtual = texture.get('path', '')
        found = texture_path(root, virtual) if root else None
        source = 'ClientData' if found else None
        if not found:
            found = pack_texture_path(model_path, virtual, selected_root)
            if found:
                source = 'Local Asset Pack'
        if found:
            try:
                if found.stat().st_size > TEXTURE_LIMIT:
                    found = None
            except OSError:
                found = None
        if found:
            server.asset_paths[i] = found
        assets.append(dict(id=i, path=virtual, modelTextureId=texture.get('id'),
                           type=texture.get('type'), source=source if found else None,
                           status='ready' if found else 'missing',
                           url=f'/api/texture/{server.asset_token}/{i}' if found else None))
    # Expose supplementary TEX assets from the extracted creature pack too.
    # This includes Avatus_Glass_Grad and SkinFX even when a selected mesh does
    # not directly bind them as diffuse or normal maps.
    extras = []
    if model_path is not None:
        pack_dir = model_path.parent
        tex_dir = next((d for d in pack_dir.iterdir()
                        if d.is_dir() and d.name.casefold() == 'textures'), None) if pack_dir.is_dir() else None
        if tex_dir is not None:
            registered = {path.resolve() for path in server.asset_paths.values()}
            for candidate in sorted(tex_dir.iterdir(), key=lambda x: x.name.casefold()):
                if len(extras) >= 96:
                    break
                if candidate.suffix.casefold() != '.tex':
                    continue
                safe = _casefold_path(pack_dir, f'{tex_dir.name}/{candidate.name}')
                if safe is None or safe.resolve() in registered:
                    continue
                try:
                    if safe.stat().st_size > TEXTURE_LIMIT:
                        continue
                except OSError:
                    continue
                tex_id = len(textures) + len(extras)
                server.asset_paths[tex_id] = safe
                registered.add(safe.resolve())
                extras.append({'id': tex_id, 'name': safe.name,
                               'url': f'/api/texture/{server.asset_token}/{tex_id}'})
    model['packExtraTextures'] = extras
    model['textureAssets'] = assets
    model['textureRootReady'] = bool(root or model_path)
    model['textureCountReady'] = len(server.asset_paths)
    model['materialRenderVersion'] = 2
    return model


def color_state(material: dict):
    raw = material.get('headerHex', '')
    try:
        data = bytes.fromhex(raw)
        return struct.unpack_from('<I', data, 0x14)[0] if len(data) >= 0x18 else 0
    except (ValueError, TypeError, struct.error):
        return 0
