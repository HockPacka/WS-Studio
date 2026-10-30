/* WildStar M3 ABI2 metadata catalogue. Pure functions usable in browser and Node tests. */
(function (root, factory) {
  const api = factory();
  if (typeof module === 'object' && module.exports) module.exports = api;
  root.WSM3Explorer = api;
})(typeof globalThis !== 'undefined' ? globalThis : this, function () {
  'use strict';
  const CATEGORY = [
    ['materials', 'Materialien'], ['textures', 'Texturen'], ['bones', 'Skeleton'],
    ['clips', 'Animationen'], ['emitters', 'Partikel / Ribbons'],
    ['attachments', 'Attachments'], ['cameras', 'Kameras'], ['lights', 'Licht'],
    ['geometry', 'Geometrie'], ['tables', 'Andere Tabellen'],
    ['collision', 'Kollision'], ['header', 'Raw-Header']
  ];
  const arrayOf = v => Array.isArray(v) ? v : [];
  function items(details, category) {
    if (!details) return [];
    switch (category) {
      case 'materials': return arrayOf(details.materialData).map((value, i) => ({ id: i, value, title: `Material ${value.index ?? i}`, description: `${arrayOf(value.layers).length} Layer` }));
      case 'textures': return arrayOf(details.textures).map((value, i) => ({ id: i, value, title: value.path || `Texture ${i}`, description: `Index ${i} · ModelTexture ${value.id ?? '—'} · Typ ${value.type ?? '?'}` }));
      case 'bones': return arrayOf(details.bones).map((value, i) => ({ id: i, value, title: `Bone ${value.index ?? i} · ID ${value.modelBoneId ?? '—'}`, description: `Parent ${value.parent ?? -1} · ${Object.values(value.tracks || {}).filter(t => t && t.count).length} Tracks` }));
      case 'clips': return arrayOf(details.clips).map((value, i) => ({ id: i, value, title: `Animation ${value.id ?? i}`, description: `Variante ${value.variant ?? 0} · ${((value.durationMs || 0) / 1000).toFixed(2)} s` }));
      case 'emitters': return arrayOf(details.emitters).map((value, i) => ({ id: i, value, title: `${value.type === 1 ? 'Ribbon' : 'Particle'} ${i}`, description: `Bone ${value.bone} · Blend ${value.blendMode}` }));
      case 'attachments': return arrayOf(details.attachments).map((value, i) => ({ id: i, value, title: `Attachment ${value.attachmentId ?? i}`, description: `Bone ${value.bone ?? '?'}` }));
      case 'cameras': return arrayOf(details.cameras).map((value, i) => ({ id: i, value, title: `Kamera ${value.id ?? i}`, description: `Bone ${value.bone ?? '?'}` }));
      case 'lights': return arrayOf(details.lights).map((value, i) => ({ id: i, value, title: `Light ${i}`, description: `Typ ${value.type ?? '?'} · Bone ${value.bone ?? '?'}` }));
      case 'geometry': return arrayOf(details.geometryInventory).map((value, i) => ({ id: i, value, title: `Geometry ${value.index ?? i}`, description: `${value.vertexCount ?? 0} Vertices · ${value.meshCount ?? 0} Meshes` }));
      case 'tables': return Object.entries(details.auxiliaryTables || {}).filter(([, value]) => value != null).map(([name, value], i) => ({ id: i, value, title: name, description: `${value.count || 0} Records` }));
      case 'collision': return details.collision ? [{ id: 0, value: details.collision, title: 'Collision', description: `${details.collision.records ?? 0} Records` }] : [];
      case 'header': return details.rawHeader ? [{ id: 0, value: { rawHeader: details.rawHeader }, title: 'LDOM Header', description: '0x630 Bytes · nicht interpretierte Felder' }] : [];
      default: return [];
    }
  }
  function summarizeBuffer(key, value) {
    if (typeof value !== 'string') return value;
    if (/^(times|values|raw|visibilityTimes|visibilityValues)$/i.test(key) && value.length > 20) return `[Base64 · ~${Math.floor(value.length * 3 / 4)} Bytes]`;
    if (/^(rawHeader|headerHex|recordHex|rawDescriptor|rawHeaderHex)$/i.test(key) && value.length > 48) return `[Hex · ${value.length / 2} Bytes]`;
    return value.length > 900 ? value.slice(0, 900) + '… [gekürzt]' : value;
  }
  function compact(value, key = '', depth = 0) {
    if (typeof value === 'string') return summarizeBuffer(key, value);
    if (value == null || typeof value !== 'object') return value;
    if (depth >= 8) return '[Verschachtelte Daten]';
    if (Array.isArray(value)) return value.slice(0, 80).map(v => compact(v, '', depth + 1)).concat(value.length > 80 ? [`… weitere ${value.length - 80}`] : []);
    return Object.fromEntries(Object.entries(value).map(([k, v]) => [k, compact(v, k, depth + 1)]));
  }
  function filter(items, query) {
    const q = String(query || '').trim().toLocaleLowerCase('de');
    return q ? items.filter(v => `${v.title} ${v.description} ${JSON.stringify(compact(v.value)).slice(0, 2500)}`.toLocaleLowerCase('de').includes(q)) : items;
  }
  function decodeLittleEndian(base64, kind, limit) {
    try {
      const bytes = typeof atob === 'function' ? Uint8Array.from(atob(base64), c=>c.charCodeAt(0)) : Uint8Array.from(Buffer.from(base64, 'base64'));
      const stride=4, count=Math.min(Math.floor(bytes.length/stride),limit);
      const view=new DataView(bytes.buffer,bytes.byteOffset,bytes.byteLength);
      return Array.from({length:count},(_,i)=>kind==='f32'?+view.getFloat32(i*4,true).toFixed(5):view.getUint32(i*4,true));
    } catch (_) { return []; }
  }
  function preview(value, key = '', depth = 0) {
    if (value == null || typeof value !== 'object') return compact(value,key,depth);
    if (depth>7)return '[Verschachtelte Daten]';
    if (!Array.isArray(value) && Number.isInteger(value.count) && typeof value.times==='string' && typeof value.values==='string') {
      const n=Math.min(8,value.count);
      return {count:value.count,components:value.components||1,
        keyframesMs:decodeLittleEndian(value.times,'u32',n),
        values:decodeLittleEndian(value.values,'f32',n*(value.components||1)),
        rawTimes:'Base64 im JSON-Export',rawValues:'Base64 im JSON-Export'};
    }
    if (Array.isArray(value))return value.slice(0,70).map(x=>preview(x,'',depth+1)).concat(value.length>70?[`… ${value.length-70} weitere`]:[]);
    return Object.fromEntries(Object.entries(value).map(([k,v])=>[k,preview(v,k,depth+1)]));
  }
  return { CATEGORY, items, compact, filter, preview };
});
