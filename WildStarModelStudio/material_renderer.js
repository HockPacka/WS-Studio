/* WildStar material bindings — approximate multi-layer shading based on WS-Tools
   M3 material 0x30 / layer 0x128 and TEX types. No proprietary SHOs embedded. */
(function (root,factory){const api=factory();if(typeof module==='object'&&module.exports)module.exports=api;root.WSMaterialRenderer=api;})(typeof globalThis!=='undefined'?globalThis:this,function(){
 'use strict';
 const anim=(typeof require==='function'&&typeof module==='object'&&module.exports)?require('./material_animation.js'):globalThis.WSMaterialAnimation;
 function blendMode(material){const h=material?.headerHex||'';return h.length>=48?parseInt(h.slice(40,48).match(/../g).reverse().join(''),16)||0:0;}
 function firstParam(layer,key,def){const p=layer?.parameters?.[key];if(!p||!p.values)return def;
  try{const binary=typeof atob==='function'?Uint8Array.from(atob(p.values),c=>c.charCodeAt(0)):new Uint8Array(Buffer.from(p.values,'base64'));
   if(binary.length<4)return def;const val=new DataView(binary.buffer,binary.byteOffset,binary.byteLength).getFloat32(0,true);return Number.isFinite(val)?val:def;
  }catch(_){return def;}}
 function vecParam(layer,key,def){const p=layer?.parameters?.[key];if(!p||!p.values)return def;
  try{const buf=typeof atob==='function'?Uint8Array.from(atob(p.values),c=>c.charCodeAt(0)):new Uint8Array(Buffer.from(p.values,'base64'));
   if(buf.length<12)return def;const d=new DataView(buf.buffer,buf.byteOffset,buf.byteLength);return Array.from({length:3},(_,i)=>d.getFloat32(i*4,true)).map((v,i)=>Number.isFinite(v)?v:def[i]);
  }catch(_){return def;}}
 const toTextureID=v=>Number.isInteger(v)&&v>=0&&v!==65535?v:-1;
 function materialInfo(model,index,timeMs=0){const mat=model?.m3Details?.materialData?.[index];
  if(!mat)return {blend:0,layers:[]};
  return {blend:blendMode(mat),layers:(mat.layers||[]).slice(0,4).map(l=>({color:toTextureID(l.colorTexture),normal:toTextureID(l.normalTexture),
      opacity:Math.max(0,Math.min(1,anim.evaluate(l.parameters?.opacity,timeMs,1,1))),gloss:Math.max(0,Math.min(1,anim.evaluate(l.parameters?.gloss,timeMs,1,0.35))),
      glow:Math.max(0,Math.min(5,anim.evaluate(l.parameters?.glow,timeMs,1,0))),tint:anim.evaluate(l.parameters?.colorMod,timeMs,3,[1,1,1])}))};
 }
 function createManager(gl,program,render){
  const spots=[];const keys=['uColorTex0','uColorTex1','uColorTex2','uColorTex3','uNormalTex0','uNormalTex1','uNormalTex2','uNormalTex3'];
  for(let i=0;i<8;i++){const loc=gl.getUniformLocation(program,keys[i]);spots.push(loc);gl.useProgram(program);gl.uniform1i(loc,i);}
  const un={count:gl.getUniformLocation(program,'uLayerCount'),hasColor:gl.getUniformLocation(program,'uHasColorTex[0]'),
    hasNormal:gl.getUniformLocation(program,'uHasNormalTex[0]'),gloss:gl.getUniformLocation(program,'uLayerGloss[0]'),
    glow:gl.getUniformLocation(program,'uLayerGlow[0]'),opacity:gl.getUniformLocation(program,'uLayerOpacity[0]'),
    tint:gl.getUniformLocation(program,'uLayerTint[0]'),blend:gl.getUniformLocation(program,'uBlendMode'),enable:gl.getUniformLocation(program,'uMaterialsEnabled'),
    uvScroll:gl.getUniformLocation(program,'uUVScroll'),uvRotation:gl.getUniformLocation(program,'uUVRotation'),uvScale:gl.getUniformLocation(program,'uUVScale')};
  const cache=new Map();let modelToken=0;
  function placeholder(pixel,srgb){const t=gl.createTexture();gl.bindTexture(gl.TEXTURE_2D,t);gl.texImage2D(gl.TEXTURE_2D,0,srgb?gl.SRGB8_ALPHA8:gl.RGBA8,1,1,0,gl.RGBA,gl.UNSIGNED_BYTE,new Uint8Array(pixel));gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MIN_FILTER,gl.LINEAR);gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MAG_FILTER,gl.LINEAR);return t;}
  const white=placeholder([255,255,255,255],true),flat=placeholder([128,128,255,255],false);
  function release(){modelToken++;for(const tex of cache.values())if(tex.glTexture)gl.deleteTexture(tex.glTexture);cache.clear();}
  function load(assets){release();const stamp=modelToken;
   for(const asset of assets||[]){if(!asset?.url)continue;
    const record={ready:false,glTexture:null,error:null};cache.set(asset.id,record);
    const image=new Image();image.onload=()=>{
      if(stamp!==modelToken)return;
      const texture=gl.createTexture();gl.bindTexture(gl.TEXTURE_2D,texture);
      gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL,true);
      gl.texImage2D(gl.TEXTURE_2D,0,gl.RGBA,gl.RGBA,gl.UNSIGNED_BYTE,image);
      gl.pixelStorei(gl.UNPACK_FLIP_Y_WEBGL,false);
      gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MIN_FILTER,gl.LINEAR_MIPMAP_LINEAR);
      gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MAG_FILTER,gl.LINEAR);
      gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_S,gl.REPEAT);
      gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_T,gl.REPEAT);
      gl.generateMipmap(gl.TEXTURE_2D);record.ready=true;record.glTexture=texture;render();
    };
    image.onerror=()=>{record.error='TEX konnte nicht dekodiert werden';render();};image.src=asset.url;
   }
  }
  function bind(info,enabled,uv={}){
    const layers=enabled?info.layers:[];
    const hc=[0,0,0,0],hn=[0,0,0,0],g=[0,0,0,0],e=[0,0,0,0],o=[1,1,1,1],t=[1,1,1,1,1,1,1,1,1,1,1,1];
    const bindTex=(id,slot,fallback)=>{const rec=cache.get(id);const valid=id>=0 && rec?.ready;
      gl.activeTexture(gl.TEXTURE0+slot);gl.bindTexture(gl.TEXTURE_2D,valid?rec.glTexture:fallback);return valid?1:0;};
    for(let i=0;i<4;i++){
      const l=layers[i];hc[i]=bindTex(l?.color??-1,i,white);hn[i]=bindTex(l?.normal??-1,i+4,flat);
      if(l){g[i]=l.gloss;e[i]=l.glow;o[i]=l.opacity;for(let k=0;k<3;k++)t[i*3+k]=Math.max(0,Math.min(5,l.tint[k]));}
    }
    gl.uniform2fv(un.uvScroll,uv.scroll||[0,0]);gl.uniform1f(un.uvRotation,uv.rotation||0);gl.uniform1f(un.uvScale,uv.scale||1);
    gl.uniform1i(un.count,layers.length);gl.uniform1i(un.blend,enabled?info.blend:0);
    gl.uniform1i(un.enable,enabled?1:0);gl.uniform1iv(un.hasColor,hc);gl.uniform1iv(un.hasNormal,hn);
    gl.uniform1fv(un.gloss,g);gl.uniform1fv(un.glow,e);gl.uniform1fv(un.opacity,o);gl.uniform3fv(un.tint,t);
    return enabled?info.blend:0;
  }
  return {load,bind,release,cache};
 }
 return {blendMode,firstParam,vecParam,materialInfo,createManager};
});
