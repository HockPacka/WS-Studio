/* WildStar M3 material timelines. The ABI2 parser already publishes DP keyframes.
 * Keyframes are literal M3 timestamps (milliseconds); interpolation here is an
 * editor preview, not a claim about undocumented original .SHO shader variants.
 * UV motion is a clearly labelled preview override, not parsed M3 UV metadata.
 */
(function(root,factory){const api=factory();if(typeof module==='object'&&module.exports)module.exports=api;root.WSMaterialAnimation=api;})(typeof globalThis!=='undefined'?globalThis:this,function(){
 'use strict';
 const trackCache=new WeakMap();
 function decode(base64){try{
  if(typeof base64!=='string'||base64.length>16000000)return null;
  const b=typeof atob==='function'?Uint8Array.from(atob(base64),ch=>ch.charCodeAt(0)):Uint8Array.from(Buffer.from(base64,'base64'));
  return b;
 }catch(_){return null;}}
 function track(data,components=1){
  if(!data||typeof data!=='object')return null;
  const cached=trackCache.get(data);if(cached)return cached;
  const n=data.count|0,c=data.components||components;
  if(n<1||n>4096||c!==components)return null;
  const kb=decode(data.times),vb=decode(data.values);
  if(!vb||vb.length<n*c*4||(n>1&&(!kb||kb.length<n*4)))return null;
  const tk=kb?new DataView(kb.buffer,kb.byteOffset,kb.byteLength):null,tv=new DataView(vb.buffer,vb.byteOffset,vb.byteLength);
  const times=new Array(n),values=new Array(n*c);
  for(let i=0;i<n;i++){
    times[i]=kb&&kb.length>=(i+1)*4?tk.getUint32(i*4,true):0;
    if(i>0&&times[i]<times[i-1])return null;
    for(let j=0;j<c;j++){const v=tv.getFloat32((i*c+j)*4,true);if(!Number.isFinite(v))return null;values[i*c+j]=v;}
  }
  const parsed={times,values,components:c,count:n};trackCache.set(data,parsed);return parsed;
 }
 function evaluate(data,ms,components=1,defaults=null){
  const fallback=defaults||(components===1?0:Array(components).fill(0));const t=track(data,components);
  if(!t)return fallback;
  const {times,values,count}=t;
  function at(i){return components===1?values[i]:values.slice(i*components,(i+1)*components);}
  if(!Number.isFinite(ms)||ms<=times[0]||count===1)return at(0);
  if(ms>=times[count-1])return at(count-1);
  let lo=0,hi=count-1;while(hi-lo>1){const mid=(lo+hi)>>1;if(times[mid]<=ms)lo=mid;else hi=mid;}
  const f=Math.max(0,Math.min(1,(ms-times[lo])/(times[hi]-times[lo]||1)));
  return components===1?values[lo]*(1-f)+values[hi]*f:
    Array.from({length:components},(_,j)=>values[lo*components+j]*(1-f)+values[hi*components+j]*f);
 }
 function materialTrackCount(model){let n=0;
  for(const m of model?.m3Details?.materialData||[])for(const layer of m.layers||[])
    for(const name of ['opacity','gloss','glow','colorMod'])if(layer.parameters?.[name]?.count>1)n++;
  return n;
 }
 function availableFlipbooks(model){const out=[];
  for(const [i,e] of (model?.m3Details?.emitters||[]).entries()){
   if(e.type!==0||!e.template||e.template.kind!=='particle')continue;
   const t=e.template,cols=Math.floor(t.flipbookCols||1),shift=Math.floor(t.flipbookRowShift||0);
   if(cols<1||cols>64||shift<0||shift>7)continue;
   const rows=2**shift,max=cols*rows;
   const frames=Math.floor(t.flipbookFrames||max);
   if(frames<2||frames>max)continue;
   const id=[t.texture0,t.texture1].find(x=>Number.isInteger(x)&&x>=0&&x!==65535&&x<(model.textureAssets?.length||0));
   if(id===undefined)continue;
   out.push({emitter:i,texture:id,cols,rows,frames,speed:Number.isFinite(t.flipbookSpeed)&&t.flipbookSpeed>0?t.flipbookSpeed:1});
  }
  return out;
 }
 function frameFor(flipbook,seconds){if(!flipbook)return 0;return Math.floor(Math.max(0,seconds)*flipbook.speed)%flipbook.frames;}
 function frameRect(flipbook,seconds){const frame=frameFor(flipbook,seconds);return {frame,x:frame%flipbook.cols,y:Math.floor(frame/flipbook.cols),cols:flipbook.cols,rows:flipbook.rows};}
 function clipClock(clip,localTimeMs){const start=Number(clip?.startMs)||0,duration=Number(clip?.durationMs)||10000;
  return start+Math.max(0,Math.min(Math.max(1,duration),Number(localTimeMs)||0));}
 return {track,evaluate,materialTrackCount,availableFlipbooks,frameFor,frameRect,clipClock};
});
