/* WildStar Model Studio — native M3 + WebGL2 skeleton/material viewer. */
'use strict';
const $ = id => document.getElementById(id);
const state = { model:null, meshes:[], selected:-1, grid:true, axes:true, wire:false, smooth:true, renderMode:"shaded", catalogCategory:"materials", catalogSelected:0, materialsEnabled:true,
  yaw:0.65, elevation:0.34, distance:9, center:[0,0,0], radius:2, floor:0,
  lastPointer:null, moving:false, spinning:false, busy:false,
  materialTimeMs:0, materialDurationMs:10000, materialPlaying:false, materialLastFrame:null, materialSpeed:1,
  materialClip:-1, materialTracks:0, uvPreview:false, uvSpeedU:0.2, uvSpeedV:0,
  uvRotate:0, uvScale:1, flipbooks:[], selectedFlipbook:-1,
  skeleton:null, skeletonEnabled:true, bindPose:false, skinTexture:null, skinLastTime:NaN, skinningMeshes:0, invalidInfluences:0 };
let gl = null, program = null, loc = {}, gridMesh = null, axesMesh = null, renderQueued = false;
let textureManager = null;
const atlasImages=new Map();
let toastTimer = 0;
const canvas = $('glcanvas');

function toast(message, isError=false) {
  const n = $('toast'); n.textContent = message; n.classList.toggle('error',isError); n.classList.remove('hidden');
  clearTimeout(toastTimer); toastTimer = setTimeout(()=>n.classList.add('hidden'),5500);
}
function showError(error) {
 const msg = String(error?.message || error || 'Unbekannter Fehler');
 text('warnings', msg); text('canvasStatus', 'LOAD ERROR'); text('bottomState', 'LADEFEHLER');
 $('warnings').classList.add('failure');
 toast(msg, true); console.error('[WildStar Viewer]', msg);
}
function pretty(n) { return Number(n).toLocaleString('de-DE'); }
function text(id, value) { $(id).textContent = String(value); }
function escapeHtml(s) { return String(s).replace(/[&<>"']/g, c=>({'&':'&amp;','<':'&lt;','>':'&gt;','"':'&quot;',"'":'&#39;'}[c])); }
function props(target, items) { target.innerHTML = items.map(([label,value])=>
  `<div class="property-row"><span>${escapeHtml(label)}</span><strong>${escapeHtml(value)}</strong></div>`).join(''); }

function shader(type, source) {
  const s=gl.createShader(type); gl.shaderSource(s,source); gl.compileShader(s);
  if (!gl.getShaderParameter(s,gl.COMPILE_STATUS)) throw new Error(gl.getShaderInfoLog(s)); return s;
}
function initGL() {
  gl = canvas.getContext('webgl2',{alpha:true,antialias:true,preserveDrawingBuffer:true});
  if (!gl) { toast('WebGL2 wird von diesem Browser/Gerät nicht unterstützt.',true); text('canvasStatus','NO WEBGL2'); return; }
  const vs=`#version 300 es
  layout(location=0) in vec3 aPosition;layout(location=1) in vec3 aNormal;
  layout(location=2) in vec2 aUV;layout(location=3) in vec4 aVertexColor;
  layout(location=4) in vec3 aTangent;layout(location=5) in vec3 aBitangent;
  layout(location=6) in vec4 aBoneIndices;layout(location=7) in vec4 aBoneWeights;
  uniform mat4 uMVP; uniform bool uSkinning; uniform sampler2D uSkinMatrices;
  out vec3 vNormal;out vec3 vPosition;out vec2 vUV;out vec4 vVertexColor;out vec3 vTangent;out vec3 vBitangent;
  mat4 boneMat(int index){return mat4(texelFetch(uSkinMatrices,ivec2(0,index),0),texelFetch(uSkinMatrices,ivec2(1,index),0),
    texelFetch(uSkinMatrices,ivec2(2,index),0),texelFetch(uSkinMatrices,ivec2(3,index),0));}
  void main(){vec4 p=vec4(aPosition,1.);vec3 n=aNormal,t=aTangent,b=aBitangent;
    float total=dot(aBoneWeights,vec4(1.));
    if(uSkinning && total>0.00001){
      mat4 m=aBoneWeights.x*boneMat(int(aBoneIndices.x)) + aBoneWeights.y*boneMat(int(aBoneIndices.y)) +
          aBoneWeights.z*boneMat(int(aBoneIndices.z)) + aBoneWeights.w*boneMat(int(aBoneIndices.w));
      p=(m*p)/total;n=mat3(m)*n;t=mat3(m)*t;b=mat3(m)*b;
    }
    gl_Position=uMVP*p;vNormal=normalize(n);vPosition=p.xyz;vUV=aUV;
    vVertexColor=aVertexColor;vTangent=t;vBitangent=b;}`;
  const fs=`#version 300 es
  precision highp float;
  in vec3 vNormal;in vec3 vPosition;in vec2 vUV;in vec4 vVertexColor;in vec3 vTangent;in vec3 vBitangent;
  uniform vec4 uColor;uniform bool uUnlit;uniform bool uSmooth;
  uniform int uMode;uniform bool uHasUV;uniform bool uHasColor;uniform bool uMaterialsEnabled;
  uniform int uLayerCount;uniform int uBlendMode;
  uniform int uHasColorTex[4];uniform int uHasNormalTex[4];
  uniform float uLayerOpacity[4];uniform float uLayerGloss[4];uniform float uLayerGlow[4];uniform vec3 uLayerTint[4];
  uniform sampler2D uColorTex0;uniform sampler2D uColorTex1;uniform sampler2D uColorTex2;uniform sampler2D uColorTex3;
  uniform vec2 uUVScroll;uniform float uUVRotation;uniform float uUVScale;
  uniform sampler2D uNormalTex0;uniform sampler2D uNormalTex1;uniform sampler2D uNormalTex2;uniform sampler2D uNormalTex3;
  out vec4 outColor;
  vec2 animatedUV(){vec2 uv=(vUV-0.5)*uUVScale;float c=cos(uUVRotation),s=sin(uUVRotation);
    return vec2(uv.x*c-uv.y*s,uv.x*s+uv.y*c)+0.5+uUVScroll;}
  vec4 colorTexture(int i){vec2 uv=animatedUV();if(i==0)return texture(uColorTex0,uv);if(i==1)return texture(uColorTex1,uv);if(i==2)return texture(uColorTex2,uv);return texture(uColorTex3,uv);}
  vec3 normalTexture(int i){vec2 uv=animatedUV();if(i==0)return texture(uNormalTex0,uv).xyz;if(i==1)return texture(uNormalTex1,uv).xyz;
    if(i==2)return texture(uNormalTex2,uv).xyz;return texture(uNormalTex3,uv).xyz;}
  void main(){
    if(uUnlit){outColor=uColor;return;}
    vec3 n=normalize(vNormal);
    if(uMode==3){outColor=vec4(n*.5+.5,1.);return;}
    if(uMode==2){if(!uHasUV){outColor=vec4(.38,.45,.52,1.);return;}
      vec2 cell=floor(vUV*10.);float check=mod(cell.x+cell.y,2.);
      vec3 col=mix(vec3(.12,.28,.35),vec3(.69,.87,.88),check);
      vec2 stripe=fract(vUV*10.);float edge=min(min(stripe.x,stripe.y),min(1.-stripe.x,1.-stripe.y));
      outColor=vec4(mix(vec3(.03,.09,.14),col,smoothstep(.005,.045,edge)),1.);return;
    }
    if(uMode==1){outColor=vec4(uHasColor?clamp(vVertexColor.rgb*2.,0.,1.):vec3(.42),uHasColor?vVertexColor.a:1.);return;}
    vec4 base=vec4(1.);float gloss=.35;float glow=0.;bool mapped=false;
    if(uMaterialsEnabled && uHasUV && uLayerCount>0){
      for(int i=0;i<4;i++){
        if(i>=uLayerCount)break;
        float opacity=clamp(uLayerOpacity[i],0.,1.);
        if(uHasColorTex[i]!=0){
          vec4 texel=colorTexture(i);
          vec3 tinted=texel.rgb*uLayerTint[i];
          if(!mapped){base.rgb=tinted;base.a=texel.a*opacity;}
          else {base.rgb=mix(base.rgb,tinted,clamp(texel.a*opacity,0.,1.));base.a=max(base.a,texel.a*opacity);}
          mapped=true;
        }
        gloss=mix(gloss,uLayerGloss[i],i==0?1.:opacity);
        glow=max(glow,uLayerGlow[i]);
      }
      for(int i=0;i<4;i++){
        if(i>=uLayerCount)break;
        if(uHasNormalTex[i]!=0){
          vec3 mapN=normalize(normalTexture(i)*2.-1.);
          vec3 tangent=vTangent;vec3 bitangent=vBitangent;
          if(length(tangent)<.1 || length(bitangent)<.1){
            vec3 dp1=dFdx(vPosition),dp2=dFdy(vPosition);vec2 du1=dFdx(vUV),du2=dFdy(vUV);
            tangent=normalize(dp1*du2.y-dp2*du1.y);bitangent=normalize(dp2*du1.x-dp1*du2.x);
          }
          tangent=normalize(tangent-n*dot(n,tangent));
          bitangent=normalize(cross(n,tangent))*((dot(cross(n,tangent),bitangent)<0.)?-1.:1.);
          if(length(tangent)>.1)n=normalize(mat3(tangent,bitangent,n)*mapN);
          break;
        }
      }
      if(uBlendMode==1 && base.a<.5)discard;
    }
    vec3 light=normalize(vec3(.65,-.4,1.));
    float amount=uSmooth?max(dot(n,light),0.):max(dot(normalize(cross(dFdx(vPosition),dFdy(vPosition))),light),0.);
    float shade=.37+.67*amount;
    vec3 view=normalize(vec3(.4,.4,1.));vec3 halfVec=normalize(light+view);
    float specular=pow(max(dot(n,halfVec),0.),mix(7.,96.,clamp(gloss,0.,1.)))*(.04+.40*gloss);
    // Real texture colours must not be multiplied by the fallback mesh palette.
    vec3 albedo=mapped?base.rgb:uColor.rgb;
    vec3 rgb=albedo*(shade+specular)+albedo*glow*.65;
    float alpha=(uMaterialsEnabled&&mapped)?base.a:uColor.a;
    if(uBlendMode==0 || uBlendMode==1)alpha=1.;
    if(uHasColor)rgb*=clamp(vVertexColor.rgb*2.,0.,2.);
    outColor=vec4(rgb,alpha);
  }`;
  program=gl.createProgram(); gl.attachShader(program,shader(gl.VERTEX_SHADER,vs)); gl.attachShader(program,shader(gl.FRAGMENT_SHADER,fs)); gl.linkProgram(program);
  if(!gl.getProgramParameter(program,gl.LINK_STATUS)) throw new Error(gl.getProgramInfoLog(program));
  gl.useProgram(program); loc.mvp=gl.getUniformLocation(program,'uMVP');loc.color=gl.getUniformLocation(program,'uColor');
  loc.unlit=gl.getUniformLocation(program,'uUnlit');loc.smooth=gl.getUniformLocation(program,'uSmooth');
  loc.skinning=gl.getUniformLocation(program,'uSkinning');loc.skinMatrices=gl.getUniformLocation(program,'uSkinMatrices');
  gl.uniform1i(loc.skinMatrices,8);
  loc.mode=gl.getUniformLocation(program,'uMode');loc.hasUV=gl.getUniformLocation(program,'uHasUV');loc.hasColor=gl.getUniformLocation(program,'uHasColor');
  gl.enable(gl.DEPTH_TEST);gl.depthFunc(gl.LEQUAL);gl.enable(gl.BLEND);gl.blendFunc(gl.SRC_ALPHA,gl.ONE_MINUS_SRC_ALPHA);
  gl.disable(gl.CULL_FACE);
  textureManager=window.WSMaterialRenderer.createManager(gl,program,requestRender);
  resetGuides(); requestRender();
}
function matMul(a,b){ const o=new Float32Array(16);for(let c=0;c<4;c++)for(let r=0;r<4;r++)for(let k=0;k<4;k++)o[c*4+r]+=a[k*4+r]*b[c*4+k];return o; }
function perspective(fov,aspect,near,far){const f=1/Math.tan(fov/2),a=new Float32Array(16);a[0]=f/aspect;a[5]=f;a[10]=(far+near)/(near-far);a[11]=-1;a[14]=2*far*near/(near-far);return a;}
function minus(a,b){return a.map((v,i)=>v-b[i]);}function dot(a,b){return a.reduce((s,v,i)=>s+v*b[i],0);}function cross(a,b){return [a[1]*b[2]-a[2]*b[1],a[2]*b[0]-a[0]*b[2],a[0]*b[1]-a[1]*b[0]];}
function norm(a){let m=Math.hypot(...a)||1;return a.map(v=>v/m);}
function lookAt(eye,target,up){const z=norm(minus(eye,target)),x=norm(cross(up,z)),y=cross(z,x),o=new Float32Array(16);
  for(let i=0;i<3;i++){o[i*4]=x[i];o[i*4+1]=y[i];o[i*4+2]=z[i];}o[12]=-dot(x,eye);o[13]=-dot(y,eye);o[14]=-dot(z,eye);o[15]=1;return o; }
function colorToRGBA(hex,a=1){const h=hex.replace('#','');return [parseInt(h.slice(0,2),16)/255,parseInt(h.slice(2,4),16)/255,parseInt(h.slice(4,6),16)/255,a];}
function fromB64(s,kind){const binary=atob(s); const bytes=new Uint8Array(binary.length); for(let i=0;i<binary.length;i++)bytes[i]=binary.charCodeAt(i);return kind==='f32'?new Float32Array(bytes.buffer):kind==='u8'?bytes:new Uint32Array(bytes.buffer);}
function glMesh(positions,normals,indices,uvs=null,colors=null,tangents=null,bitangents=null,skinning=null){
  const vao=gl.createVertexArray();gl.bindVertexArray(vao);
  const pos=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,pos);gl.bufferData(gl.ARRAY_BUFFER,positions,gl.STATIC_DRAW);gl.enableVertexAttribArray(0);gl.vertexAttribPointer(0,3,gl.FLOAT,false,0,0);
  const normal=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,normal);gl.bufferData(gl.ARRAY_BUFFER,normals,gl.STATIC_DRAW);gl.enableVertexAttribArray(1);gl.vertexAttribPointer(1,3,gl.FLOAT,false,0,0);
  let uvBuffer=null,colorBuffer=null;
  gl.disableVertexAttribArray(2);gl.vertexAttrib2f(2,0,0);
  if(uvs && uvs.length===positions.length/3*2){
    uvBuffer=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,uvBuffer);gl.bufferData(gl.ARRAY_BUFFER,uvs,gl.STATIC_DRAW);
    gl.enableVertexAttribArray(2);gl.vertexAttribPointer(2,2,gl.FLOAT,false,0,0);
  }
  gl.disableVertexAttribArray(3);gl.vertexAttrib4f(3,1,1,1,1);
  if(colors && colors.length===positions.length/3*4){
    colorBuffer=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,colorBuffer);gl.bufferData(gl.ARRAY_BUFFER,colors,gl.STATIC_DRAW);
    gl.enableVertexAttribArray(3);gl.vertexAttribPointer(3,4,gl.UNSIGNED_BYTE,true,0,0);
  }
  const makeDirection=(idx,values)=>{
    gl.disableVertexAttribArray(idx);gl.vertexAttrib3f(idx,0,0,0);
    if(!values||values.length!==positions.length)return null;
    const buffer=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,buffer);gl.bufferData(gl.ARRAY_BUFFER,values,gl.STATIC_DRAW);
    gl.enableVertexAttribArray(idx);gl.vertexAttribPointer(idx,3,gl.FLOAT,false,0,0);return buffer;
  };
  const tangentBuffer=makeDirection(4,tangents),bitangentBuffer=makeDirection(5,bitangents);
  let boneBuffer=null,weightBuffer=null;
  gl.disableVertexAttribArray(6);gl.vertexAttrib4f(6,0,0,0,0);
  gl.disableVertexAttribArray(7);gl.vertexAttrib4f(7,0,0,0,0);
  if(skinning && skinning.indices.length===positions.length/3*4 && skinning.influenced){
    boneBuffer=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,boneBuffer);
    gl.bufferData(gl.ARRAY_BUFFER,skinning.indices,gl.STATIC_DRAW);
    gl.enableVertexAttribArray(6);gl.vertexAttribPointer(6,4,gl.UNSIGNED_SHORT,false,0,0);
    weightBuffer=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,weightBuffer);
    gl.bufferData(gl.ARRAY_BUFFER,skinning.weights,gl.STATIC_DRAW);
    gl.enableVertexAttribArray(7);gl.vertexAttribPointer(7,4,gl.UNSIGNED_BYTE,true,0,0);
  }
  const ib=gl.createBuffer();gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER,ib);gl.bufferData(gl.ELEMENT_ARRAY_BUFFER,indices,gl.STATIC_DRAW);
  gl.bindVertexArray(null);return {vao,pos,normal,uvBuffer,colorBuffer,tangentBuffer,bitangentBuffer,boneBuffer,weightBuffer,hasWeights:!!boneBuffer,hasUV:!!uvBuffer,hasColor:!!colorBuffer,ib,nIndices:indices.length,rawIndices:indices,wireBuffer:null,wireCount:0};
}
function glLines(vertices){const vao=gl.createVertexArray();gl.bindVertexArray(vao);
 const pos=gl.createBuffer();gl.bindBuffer(gl.ARRAY_BUFFER,pos);gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(vertices),gl.STATIC_DRAW);
 gl.enableVertexAttribArray(0);gl.vertexAttribPointer(0,3,gl.FLOAT,false,0,0);gl.disableVertexAttribArray(1);gl.bindVertexArray(null);
 return {vao,pos,count:vertices.length/3}; }
function disposeMesh(m){gl.deleteVertexArray(m.vao);gl.deleteBuffer(m.pos);if(m.normal)gl.deleteBuffer(m.normal);if(m.uvBuffer)gl.deleteBuffer(m.uvBuffer);if(m.colorBuffer)gl.deleteBuffer(m.colorBuffer);if(m.tangentBuffer)gl.deleteBuffer(m.tangentBuffer);if(m.bitangentBuffer)gl.deleteBuffer(m.bitangentBuffer);if(m.boneBuffer)gl.deleteBuffer(m.boneBuffer);if(m.weightBuffer)gl.deleteBuffer(m.weightBuffer);if(m.ib)gl.deleteBuffer(m.ib);if(m.wireBuffer)gl.deleteBuffer(m.wireBuffer);}
function resetGuides(){if(!gl)return; if(gridMesh)disposeMesh(gridMesh);if(axesMesh)disposeMesh(axesMesh);
 const v=[],unit=Math.pow(10,Math.floor(Math.log10(Math.max(state.radius,1)/3))); const span=10*unit;
 for(let i=-10;i<=10;i++){let t=i*unit;v.push(-span,t,state.floor,span,t,state.floor,t,-span,state.floor,t,span,state.floor);}
 gridMesh=glLines(v);
 const s=Math.max(state.radius*.34,.5),x=state.center[0],y=state.center[1],z=state.floor;
 axesMesh=[glLines([x,y,z,x+s,y,z]),glLines([x,y,z,x,y+s,z]),glLines([x,y,z,x,y,z+s])];
}
function resetCamera(){if(!state.model)return;const b=state.model.bounds;
 state.center=[(b[0]+b[3])/2,(b[1]+b[4])/2,(b[2]+b[5])/2];state.radius=Math.max(0.01,Math.hypot(b[3]-b[0],b[4]-b[1],b[5]-b[2])/2);
 state.distance=Math.max(.7,state.radius*2.65);state.floor=b[2]-Math.max(0.01,state.radius*.04);state.yaw=.72;state.elevation=.35;
 resetGuides();requestRender(); }
function prepareEdges(mesh){if(mesh.wireBuffer)return;
 let src=mesh.rawIndices,edges=new Uint32Array(src.length*2);
 for(let i=0,j=0;i<src.length;i+=3){edges[j++]=src[i];edges[j++]=src[i+1];edges[j++]=src[i+1];edges[j++]=src[i+2];edges[j++]=src[i+2];edges[j++]=src[i];}
 mesh.wireBuffer=gl.createBuffer();gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER,mesh.wireBuffer);gl.bufferData(gl.ELEMENT_ARRAY_BUFFER,edges,gl.STATIC_DRAW);mesh.wireCount=edges.length;
 // ELEMENT_ARRAY_BUFFER is bound to a VAO in WebGL2: restore original index buffer.
 gl.bindVertexArray(mesh.vao);gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER,mesh.ib);gl.bindVertexArray(null);
}
function requestRender(){if(!gl || renderQueued)return;renderQueued=true;requestAnimationFrame(render);}
function render(now=0){renderQueued=false;if(!gl)return;
  if(state.materialPlaying&&state.model?.format==='M3'){
    if(state.materialLastFrame!==null){const delta=Math.min(Math.max(0,now-state.materialLastFrame),150);
      state.materialTimeMs=(state.materialTimeMs+delta*state.materialSpeed)%Math.max(1,state.materialDurationMs);}
    state.materialLastFrame=now;updateAnimationReadout();
  }else state.materialLastFrame=null;const dpr=Math.min(window.devicePixelRatio||1,2),w=Math.max(2,Math.round(canvas.clientWidth*dpr)),h=Math.max(2,Math.round(canvas.clientHeight*dpr));
 if(canvas.width!==w||canvas.height!==h){canvas.width=w;canvas.height=h;}gl.viewport(0,0,w,h);gl.clearColor(0,0,0,0);gl.clear(gl.COLOR_BUFFER_BIT|gl.DEPTH_BUFFER_BIT);
 const yaw=state.yaw,el=state.elevation,di=state.distance,c=state.center,eye=[c[0]+Math.sin(yaw)*Math.cos(el)*di,c[1]-Math.cos(yaw)*Math.cos(el)*di,c[2]+Math.sin(el)*di];
 const mvp=matMul(perspective(Math.PI/4,w/h,Math.max(.001,di/2000),Math.max(200,di*50)),lookAt(eye,c,[0,0,1]));
 gl.useProgram(program);gl.uniformMatrix4fv(loc.mvp,false,mvp);
 // A missing animation texture or an unsupported GPU must never hide the static mesh.
 // Determine this value before drawing: previously `usingSkeleton` was undefined,
 // causing ReferenceError on the first mesh in every v0.9 render frame.
 let usingSkeleton=false;
 try { usingSkeleton=updateSkeletonGPU(); }
 catch(error){
   console.error('[WildStar Viewer] GPU-Skinning fehlgeschlagen; statische Darstellung aktiv:',error);
   state.skeletonEnabled=false;usingSkeleton=false;
   if($('skeletonEnabled'))$('skeletonEnabled').checked=false;
   toast('GPU-Skinning deaktiviert: Modell wird statisch dargestellt.',true);
 }
 gl.uniform1i(loc.skinning,0);
 gl.uniform1i(loc.smooth,state.smooth?1:0);
 function line(g,color){gl.uniform1i(loc.skinning,0);gl.uniform1i(loc.unlit,1);gl.uniform4fv(loc.color,color);gl.bindVertexArray(g.vao);gl.vertexAttrib3f(1,0,0,1);gl.drawArrays(gl.LINES,0,g.count);}
 if(state.grid && gridMesh){gl.depthMask(false);line(gridMesh,[.25,.42,.54,.34]);gl.depthMask(true);}
 if(state.axes && axesMesh){const cols=[[1,.42,.43,.95],[.48,.86,.51,.95],[.39,.7,1,.95]];axesMesh.forEach((m,i)=>line(m,cols[i]));}
 // Opaque meshes write depth first; transparent glass is drawn afterwards.
 const clock=materialClock();
  const uv=state.uvPreview?{scroll:[state.uvSpeedU*state.materialTimeMs/1000,state.uvSpeedV*state.materialTimeMs/1000],rotation:state.uvRotate*Math.PI/180*state.materialTimeMs/1000,scale:state.uvScale}:{scroll:[0,0],rotation:0,scale:1};
  const order=state.meshes.map((mesh,i)=>({mesh,i,mode:window.WSMaterialRenderer.materialInfo(state.model,mesh.material,clock).blend}))
   .sort((a,b)=>(a.mode>1)-(b.mode>1));
 for(const {mesh,i} of order){if(!mesh.visible)continue;
  gl.uniform1i(loc.skinning,usingSkeleton&&mesh.gpu.hasWeights?1:0);
  gl.uniform1i(loc.unlit,0);
  gl.uniform1i(loc.mode,({shaded:0,vertex:1,uv:2,normal:3})[state.renderMode] ?? 0);
  gl.uniform1i(loc.hasUV,mesh.gpu.hasUV?1:0);gl.uniform1i(loc.hasColor,mesh.gpu.hasColor?1:0);
  const col=colorToRGBA(mesh.color);if(i===state.selected){col[0]=Math.min(1,col[0]*1.18);col[1]=Math.min(1,col[1]*1.18);col[2]=Math.min(1,col[2]*1.18);}gl.uniform4fv(loc.color,col);
  const mat=window.WSMaterialRenderer.materialInfo(state.model,mesh.material,clock);
  const matEnabled=state.materialsEnabled && state.renderMode==='shaded' && mesh.gpu.hasUV;
  const mode=textureManager?.bind(mat,matEnabled,uv)??0;
  if(matEnabled && mat.layers.some(layer=>layer.color>=0 && textureManager?.cache.get(layer.color)?.ready)){
    gl.uniform4fv(loc.color,[1,1,1,1]);
  }
  if(mode===0||mode===1){gl.disable(gl.BLEND);gl.depthMask(true);}
  else {gl.enable(gl.BLEND);gl.depthMask(false);
    if(mode===3)gl.blendFunc(gl.ONE,gl.ONE);
    else if(mode===5||mode===6)gl.blendFunc(gl.DST_COLOR,mode===5?gl.ZERO:gl.SRC_COLOR);
    else gl.blendFunc(gl.SRC_ALPHA,gl.ONE_MINUS_SRC_ALPHA);
  }
  gl.bindVertexArray(mesh.gpu.vao);gl.drawElements(gl.TRIANGLES,mesh.gpu.nIndices,gl.UNSIGNED_INT,0);
  if(state.wire){prepareEdges(mesh.gpu);gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER,mesh.gpu.wireBuffer);gl.uniform1i(loc.unlit,1);gl.uniform4fv(loc.color,i===state.selected?[.94,.97,1,.84]:[.02,.07,.12,.58]);gl.drawElements(gl.LINES,mesh.gpu.wireCount,gl.UNSIGNED_INT,0);gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER,mesh.gpu.ib);}
 }
 gl.depthMask(true);gl.enable(gl.BLEND);gl.blendFunc(gl.SRC_ALPHA,gl.ONE_MINUS_SRC_ALPHA);
 gl.bindVertexArray(null);
 if(state.spinning && state.model){state.yaw+=.006;}
  if(state.spinning || state.materialPlaying){updateAtlasPreview();requestRender();}
}
function initSkeletonGPU(){
  if(!gl || !state.skeleton)return;
  const count=state.skeleton.n;
  if(!gl.getParameter(gl.MAX_VERTEX_TEXTURE_IMAGE_UNITS) || count>gl.getParameter(gl.MAX_TEXTURE_SIZE)){
    toast('GPU-Skinning wird von dieser Grafikkarte nicht unterstützt.',true);return;
  }
  const texture=gl.createTexture();gl.activeTexture(gl.TEXTURE0+8);gl.bindTexture(gl.TEXTURE_2D,texture);
  gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MIN_FILTER,gl.NEAREST);
  gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MAG_FILTER,gl.NEAREST);
  gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_S,gl.CLAMP_TO_EDGE);
  gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_T,gl.CLAMP_TO_EDGE);
  gl.texImage2D(gl.TEXTURE_2D,0,gl.RGBA32F,4,count,0,gl.RGBA,gl.FLOAT,state.skeleton.skin);
  const allocError=gl.getError();
  if(allocError!==gl.NO_ERROR){
    gl.deleteTexture(texture);state.skinTexture=null;state.skeletonEnabled=false;
    toast(`GPU-Skinning nicht verfügbar (WebGL ${allocError}); statische Darstellung bleibt aktiv.`,true);
    return;
  }
  state.skinTexture=texture;state.skinLastTime=NaN;
}
function updateSkeletonGPU(){
  if(!gl || !state.skinTexture || !state.skeleton || !state.skeletonEnabled)return false;
  const time=materialClock();
  if(!Number.isFinite(state.skinLastTime)||state.skinLastTime!==time||state.skinLastBind!==state.bindPose){
    window.WSSkeletonAnimation.evaluate(state.skeleton,time,state.bindPose);
    gl.activeTexture(gl.TEXTURE0+8);gl.bindTexture(gl.TEXTURE_2D,state.skinTexture);
    gl.texSubImage2D(gl.TEXTURE_2D,0,0,0,4,state.skeleton.n,gl.RGBA,gl.FLOAT,state.skeleton.skin);
    const uploadError=gl.getError();
    if(uploadError!==gl.NO_ERROR)throw new Error(`Bone-Matrix-Upload: WebGL-Fehler ${uploadError}`);
    state.skinLastTime=time;state.skinLastBind=state.bindPose;
  }
  gl.activeTexture(gl.TEXTURE0+8);gl.bindTexture(gl.TEXTURE_2D,state.skinTexture);
  return true;
}
function setBusy(b,label='Modell wird geladen…'){state.busy=b;$('loading').classList.toggle('hidden',!b);text('loadingLabel',label);}
async function responseJson(response){let j=await response.json();if(!response.ok || j.error)throw new Error(j.error||`HTTP ${response.status}`);return j;}
async function loadAnimatedDemo(){if(state.busy)return;setBusy(true,'Animation-Demo wird geladen…');try{await applyModel(await responseJson(await fetch('/api/animated-demo')));}catch(e){showError(e);}finally{setBusy(false);}}
async function loadDemo(){if(state.busy)return;setBusy(true,'Demo-Modell wird geladen…');try{await applyModel(await responseJson(await fetch('/api/demo')));}catch(e){showError(e);}finally{setBusy(false);}}
async function openFile(file){if(!file||state.busy)return;if(!/\.(m3|i3|area)$/i.test(file.name)){toast('Bitte eine .m3-, .i3- oder .area-Datei auswählen.',true);return;}
 setBusy(true,'Analysiere '+file.name+'…');try{await applyModel(await responseJson(await fetch('/api/open',{method:'POST',headers:{'X-Viewer-Request':'1','X-File-Name':encodeURIComponent(file.name)},body:file})));}catch(e){showError(e);}finally{setBusy(false);}}
async function browseNative(){if(state.busy)return;setBusy(true,'Dateiauswahl wird geöffnet…');try{const data=await responseJson(await fetch('/api/browse',{method:'POST',headers:{'X-Viewer-Request':'1'},body:''}));if(!data.cancelled)await applyModel(data);}catch(e){showError('Dateidialog: '+e.message+' — alternativ Datei hier ablegen.');}finally{setBusy(false);}}
async function applyModel(m){
 if(!Array.isArray(m.sections))throw new Error('M3-Parser lieferte keine Mesh-Tabelle.');
 // Free previous GPU data first.
 if(textureManager)textureManager.release();
 atlasImages.clear();
 if(gl)for(const mesh of state.meshes)if(mesh.gpu)disposeMesh(mesh.gpu);
 state.meshes=[];state.model=m;state.selected=-1;
  state.skeleton=m.format==='M3'?window.WSSkeletonAnimation.build(m):null;
  state.skinningMeshes=0;state.invalidInfluences=0;
  initSkeletonGPU();
 for(const s of m.sections){
   const attributes=state.skeleton&&s.boneIndices&&s.boneWeights?
     window.WSSkeletonAnimation.vertexPalette(fromB64(s.boneIndices,'u8'),fromB64(s.boneWeights,'u8'),
       s.meta?.bonePaletteStart??0,state.skeleton.palette,state.skeleton.n):null;
   if(attributes?.influenced)state.skinningMeshes++;
   state.invalidInfluences+=attributes?.invalid||0;
   const gpu=gl?glMesh(fromB64(s.positions,'f32'),fromB64(s.normals,'f32'),fromB64(s.indices,'u32'),
       s.uv1?fromB64(s.uv1,'f32'):null,s.color0?fromB64(s.color0,'u8'):null,
       s.tangents?fromB64(s.tangents,'f32'):null,s.bitangents?fromB64(s.bitangents,'f32'):null,attributes):null;
   state.meshes.push({...s,positions:null,normals:null,indices:null,uv1:null,uv2:null,tangents:null,bitangents:null,
     color0:null,color1:null,boneIndices:null,boneWeights:null,gpu,visible:true,
     hasUV:!!s.uv1,hasUV2:!!s.uv2,hasVertexColor:!!s.color0,hasWeights:!!s.boneWeights});
   for(const attr of ['positions','normals','indices','uv1','uv2','tangents','bitangents','color0','color1','boneIndices','boneWeights'])delete s[attr];
 }
 $('warnings').classList.remove('failure');
 $('emptyState').classList.toggle('hidden',m.sections.length>0);text('fileTitle',m.name);text('formatChip',m.format);text('inspectorName',m.name);text('inspectorType',m.format+(m.sections.length&&gl?' · MATERIAL PREVIEW':' · METADATA ONLY'));text('statVertices',pretty(m.stats.vertices));
 text('statTriangles',pretty(m.stats.triangles));text('statMeshes',pretty(m.stats.meshes));text('statBones',pretty(m.stats.bones||0));text('sceneCount',m.stats.meshes);
 let meta=[['Format',m.format],['Version',m.stats.version],['Meshes',pretty(m.stats.meshes)],['Vertices',pretty(m.stats.vertices)],['Triangles',pretty(m.stats.triangles)],['Bones',pretty(m.stats.bones||0)],['Animation clips',pretty(m.stats.animations||0)],['Materials',m.stats.materials],['Textures',m.stats.textures]];
 if(m.parser)meta.push(['Parser',m.parser]);
 if(m.stats.cells!==undefined)meta.push(['Terrain cells',m.stats.cells+' / 256']);
 if(m.stats.sectors!==undefined)meta.push(['Sectors',m.stats.sectors+' / '+m.stats.expectedSectors]);
 props($('modelProperties'),meta);$('selectedProperties').innerHTML='<div class="property-row muted">Mesh in der Liste auswählen</div>';
 if(textureManager)textureManager.load(m.textureAssets);
 configureMaterialAnimation(m);
 updateMaterialInspector();
 updatePackDetails(m);
 text('warnings',m.warnings?.length?m.warnings.join('\n'):'M3 gelesen. Materiallayer und primäre Skelett-Tracks werden angenähert; proprietäre SHOs werden nicht ausgeführt.');
 renderM3Details(m.m3Details);text('canvasStatus',!gl?'WEBGL2 FEHLT · METADATEN BEREIT':m.sections.length?(state.skinningMeshes?'SKINNING + MATERIAL READY':'MATERIAL PREVIEW READY'):'METADATA READY');text('bottomState',m.format+(gl&&m.sections.length?' · MATERIAL PREVIEW':' · METADATA ONLY'));$('meshSearch').value='';resetCamera();renderMeshList();requestRender();toast(m.name+' geladen · '+pretty(m.stats.triangles)+' Dreiecke');
}
// Local M3 creature-pack navigation, including Avatus's body, gun, and hands.
function updatePackDetails(model){
 const parts=Array.isArray(model.modelParts)?model.modelParts:[];
 const section=$('modelPartsSection');section.hidden=parts.length<2;
 text('modelPartsCount',parts.length);
 const list=$('modelPartsList');list.replaceChildren();
 for(const part of parts){
   const btn=document.createElement('button');btn.type='button';btn.className='model-part'+(part.active?' active':'');
   const symbol=document.createElement('span');symbol.textContent=part.active?'◉':'◇';
   const name=document.createElement('span');name.textContent=part.name;
   btn.append(symbol,name);btn.disabled=part.active;
   btn.onclick=async()=>{if(state.busy)return;setBusy(true,'Lade '+part.name+'…');
    try{await applyModel(await responseJson(await fetch(part.url)));}
    catch(e){showError(e);}finally{setBusy(false);}};
   list.append(btn);
 }
 const report=$('assetValidation');report.hidden=model.format!=='M3';
 const assets=model.textureAssets||[],ready=assets.filter(a=>a.status==='ready');
 const fromPack=ready.filter(a=>a.source==='Local Asset Pack').length;
 const missing=assets.filter(a=>a.status!=='ready');
 text('assetValidationText',`${ready.length}/${assets.length} Texturen gefunden${fromPack?' · '+fromPack+' aus lokalem Modellpaket':''}. ${parts.length>1?parts.length+' zusammengehörige Modelle.':''}`);
 text('assetMissingList',missing.length?'Fehlende Texturen: '+missing.map(x=>x.path).join(' · '):'Alle referenzierten TEX-Dateien gefunden.');
 const gallery=$('packExtraTextures');gallery.replaceChildren();
 for(const asset of model.packExtraTextures||[]){
  const item=document.createElement('div');item.className='pack-extra-item';
  const img=document.createElement('img');img.loading='lazy';img.alt=asset.name;img.src=asset.url;
  const title=document.createElement('span');title.textContent=asset.name;
  item.append(img,title);gallery.append(item);
 }
}

// Full searchable ABI 2 reader/explorer (no 20-record truncation).
function catalogueEntries(){return window.WSM3Explorer?.items(state.model?.m3Details,state.catalogCategory)||[];}
function focusM3Category(category,index=0){
 if(!state.model?.m3Details)return;
 state.catalogCategory=category;state.catalogSelected=index;
 $('m3Category').value=category;$('m3Filter').value='';renderM3Catalogue();
}
function renderM3Details(details){
 const sec=$('m3DetailsSection');sec.hidden=!details;
 if(!details)return;
 const categories=window.WSM3Explorer.CATEGORY;
 const select=$('m3Category');select.replaceChildren();
 for(const [key,label] of categories){const opt=document.createElement('option');opt.value=key;
   opt.textContent=`${label} (${window.WSM3Explorer.items(details,key).length})`;select.append(opt);}
 if(!categories.some(([k])=>k===state.catalogCategory))state.catalogCategory='materials';
 if(!window.WSM3Explorer.items(details,state.catalogCategory).length){
    state.catalogCategory=categories.find(([k])=>window.WSM3Explorer.items(details,k).length)?.[0]||'materials';
 }
 state.catalogSelected=0;$('m3Filter').value='';select.value=state.catalogCategory;
 const total=categories.reduce((n,[key])=>n+window.WSM3Explorer.items(details,key).length,0);
 text('m3CountBadge',`${pretty(total)} Einträge`);renderM3Catalogue();
}
function renderM3Catalogue(){
 const list=$('m3DataList'),panel=$('m3DataDetail'),title=$('m3DetailTitle');list.replaceChildren();
 const items=catalogueEntries();const shown=window.WSM3Explorer.filter(items,$('m3Filter').value);
 text('m3CategoryStats',`${pretty(shown.length)} / ${pretty(items.length)} Einträge · Klick für Details`);
 for(const item of shown.slice(0,100)){
  const button=document.createElement('button');button.className='m3-data-item'+(item.id===state.catalogSelected?' selected':'');
  const h=document.createElement('strong');h.textContent=item.title;const sub=document.createElement('small');sub.textContent=item.description;
  button.append(h,sub);button.onclick=()=>{state.catalogSelected=item.id;renderM3Catalogue();};list.append(button);
 }
 if(shown.length>100){const note=document.createElement('div');note.className='m3-category-stats';note.textContent=`${pretty(shown.length-100)} weitere Treffer — Suchfilter verwenden.`;list.append(note);}
 if(!shown.length){const no=document.createElement('div');no.className='m3-category-stats';no.textContent='Keine Treffer';list.append(no);}
 const selected=shown.find(x=>x.id===state.catalogSelected) || shown[0];
 if(!selected){title.textContent='Kein Eintrag';panel.textContent='Für diese Suche liegen keine Daten vor.';return;}
 title.textContent=selected.title;
 panel.textContent=JSON.stringify(window.WSM3Explorer.preview(selected.value),null,2);
}
function exportM3Metadata(){
 const model=state.model;if(!model?.m3Details){toast('Zuerst ein M3-Modell laden.',true);return;}
 const payload={name:model.name,format:model.format,parser:model.parser,stats:model.stats,
   bounds:model.bounds,sections:state.meshes.map(m=>({name:m.name,vertices:m.vertices,triangles:m.triangles,material:m.material,
      meta:m.meta,uv1:m.hasUV,uv2:m.hasUV2,colors:m.hasVertexColor,weights:m.hasWeights})),
   m3Details:model.m3Details};
 const blob=new Blob([JSON.stringify(payload,null,2)],{type:'application/json'});
 const url=URL.createObjectURL(blob);const a=document.createElement('a');a.href=url;
 a.download=model.name.replace(/[^\w.\-]/g,'_')+'.m3-metadata.json';a.click();
 setTimeout(()=>URL.revokeObjectURL(url),15000);
 toast('M3-Metadaten exportiert');
}
function renderMeshList(){const list=$('meshList');list.replaceChildren();const query=$('meshSearch').value.trim().toLowerCase();let found=0;
 for(let i=0;i<state.meshes.length;i++){const m=state.meshes[i];if(query && !m.name.toLowerCase().includes(query) && !String(m.material).includes(query))continue;found++;
  const item=document.createElement('div');item.className='mesh-item'+(i===state.selected?' selected':'');item.title=m.name;
  const check=document.createElement('input');check.type='checkbox';check.checked=m.visible;check.setAttribute('aria-label','Sichtbarkeit '+m.name);
  check.addEventListener('change',()=>{m.visible=check.checked;requestRender();});
  const ico=document.createElement('span');ico.className='mesh-glyph';ico.textContent='⬡';
  const nm=document.createElement('span');nm.className='mesh-name';nm.textContent=m.name;
  const tri=document.createElement('span');tri.className='mesh-tris';tri.textContent=pretty(m.triangles);
  item.append(check,ico,nm,tri);item.addEventListener('click',e=>{if(e.target===check)return;state.selected=i;props($('selectedProperties'),[['Name',m.name],['Vertices',pretty(m.vertices)],['Triangles',pretty(m.triangles)],['Material',m.material],['UV1',m.hasUV?'Vorhanden':'—'],['UV2',m.hasUV2?'Vorhanden':'—'],['Vertexfarben',m.hasVertexColor?'Vorhanden':'—'],['Bone Weights',m.hasWeights?'Vorhanden':'—'],...Object.entries(m.meta||{}).map(([k,v])=>[k,v])]);renderMeshList();if(state.model?.m3Details)focusM3Category('materials',m.material);updateAnimationReadout();updateMaterialInspector();requestRender();});
  list.append(item);
 }
 if(!found){const empty=document.createElement('div');empty.className='empty-list';empty.textContent=query?'Keine Treffer.':'Noch kein Modell geladen.';list.append(empty);}
}
function updateMaterialInspector(){
 const m=state.model;if(!m)return;
 const panel=$('materialInspector');panel.hidden=m.format!=='M3';
 if(panel.hidden)return;
 const assets=m.textureAssets||[];
 text('textureStatus',`${assets.filter(a=>a.url).length}/${assets.length} TEX gefunden${!m.textureRootReady?' · ClientData-Ordner auswählen':''}`);
 const wrap=$('materialTextureList');wrap.replaceChildren();
 const info=window.WSMaterialRenderer.materialInfo(m,state.selected>=0?state.meshes[state.selected]?.material:0,materialClock());
 text('materialBlend',`Blend: ${['Opaque','Cutout','Alpha','Add','Alpha-Add','Multiply','Multiply 2x'][info.blend]||'Special'} · ${info.layers.length} Layer`);
 for(const [i,layer] of info.layers.entries()){
  const row=document.createElement('div');row.className='material-asset-row';
  for(const [kind,id] of [['Diffuse',layer.color],['Normal',layer.normal]]){
    if(id<0)continue;
    const data=assets[id];const tile=document.createElement('div');tile.className='material-asset-tile';
    if(data?.url){const img=document.createElement('img');img.alt=`${kind} Layer ${i}`;img.src=data.url;img.onerror=()=>{img.replaceWith(document.createTextNode('⚠'));};tile.append(img);}
    else {const missing=document.createElement('div');missing.className='tex-missing';missing.textContent='—';tile.append(missing);}
    const label=document.createElement('small');label.textContent=`L${i} ${kind} ${data?.url?'✓':'fehlt'}`;tile.title=data?.path||'Keine Datei';tile.append(label);row.append(tile);
  }
  if(row.children.length)wrap.append(row);
 }
}
function materialClock(){
 const clip=state.materialClip<0?null:state.model?.m3Details?.clips?.[state.materialClip];
 return clip?window.WSMaterialAnimation.clipClock(clip,state.materialTimeMs):state.materialTimeMs;
}
function configureMaterialAnimation(model){
 const panel=$('animatedMaterials');panel.hidden=model?.format!=='M3';
 state.materialTimeMs=0;state.materialLastFrame=null;state.materialClip=window.WSSkeletonAnimation.preferredClip(model?.m3Details?.clips);
 state.bindPose=state.materialClip<0&&!state.skeleton?.animatedCount;
 state.skeletonEnabled=true;state.materialTracks=window.WSMaterialAnimation.materialTrackCount(model);
 state.flipbooks=window.WSMaterialAnimation.availableFlipbooks(model);
 state.selectedFlipbook=state.flipbooks.length?0:-1;
 const clips=model?.m3Details?.clips||[];
 const clipLabels={150:'Default_Stand',210:'Default_BasePose',152:'Default_Run',153:'Default_Walk',
   154:'Default_WalkBackwards',155:'Default_Attack',156:'Default_Dodge',165:'Default_Death',
   166:'Default_JumpStart',167:'Default_JumpLoop',159:'Default_JumpLand',151:'Default_Ready',
   157:'Default_Wound',164:'Default_HandsClosed',282:'Default_Sprint',278:'Default_Talk',
   429:'Default_Stunned',710:'2HGun_Fire',1334:'Default_Birth',1118:'AP_State0_Idle',
   1120:'AP_State1_Idle',1122:'AP_State2_Idle'};
 const select=$('materialAnimClip');select.replaceChildren();
 const restOpt=new Option('Bind-Pose (unanimiert)','-2');select.add(restOpt);
 const globalOpt=new Option('Globale M3-Zeitachse','-1');select.add(globalOpt);
 for(const [i,clip] of clips.entries()){
  const name=`${clipLabels[clip.id]||'M3 Clip'} · #${clip.id} · ${((clip.durationMs||0)/1000).toFixed(2)}s${clip.variant?' · Var '+clip.variant:''}`;
  select.add(new Option(name,String(i)));
 }
 select.value=String(state.materialClip);
 let maxTime=0;
 for(const mat of model?.m3Details?.materialData||[])for(const layer of mat.layers||[])
  for(const p of Object.values(layer.parameters||{})){
   if(p?.count>1){const tr=window.WSMaterialAnimation.track(p,layer.parameters?.colorMod===p?3:1);
    if(tr)maxTime=Math.max(maxTime,tr.times[tr.count-1]);}
  }
 state.materialDurationMs=Math.max(1000,Math.min(600000,Math.max(maxTime,...clips.map(c=>c.endMs||0))||10000));
 if(state.materialClip>=0)state.materialDurationMs=Math.max(1,clips[state.materialClip]?.durationMs||10000);
 state.materialPlaying=!!(state.materialTracks||state.flipbooks.length||state.skeleton?.animatedCount);
 if(state.materialClip===-2||state.bindPose)state.materialPlaying=false;
 $('materialPlay').textContent=state.materialPlaying?'❚❚ Pause':'▶ Play';
 const flip=$('flipbookEmitter');flip.replaceChildren();flip.add(new Option('Kein Flipbook','-1'));
 for(const [i,f] of state.flipbooks.entries()){
  const name=`Emitter ${f.emitter} · TEX ${f.texture} · ${f.cols}×${f.rows} · ${f.frames} Frames`;
  flip.add(new Option(name,String(i)));
 }
 flip.value=String(state.selectedFlipbook);$('flipbookArea').hidden=!state.flipbooks.length;
 const boneCount=state.skeleton?.animatedCount||0;
 $('materialTracksCount').textContent=`${boneCount} animierte Bones · ${state.skinningMeshes} skinnte Meshes · ${state.materialTracks} Material-Tracks · ${state.flipbooks.length} Flipbooks`;
 $('skeletonEnabled').checked=state.skeletonEnabled;
 $('skeletonEnabled').disabled=!state.skeleton?.animatedCount||!state.skinTexture;
 $('skeletonBindPose').checked=state.bindPose;
 $('skeletonDetails').textContent=state.skeleton?`Bind-Zeit ${state.skeleton.baseTime} ms · ${state.skeleton.solved} Basis-Signaturen gelöst · ${state.skeleton.unsolved} Fallbacks · ${state.invalidInfluences} nicht zuordenbare Weights`:'Keine Skelettdaten';
 updateAnimationReadout();updateAtlasPreview();requestRender();
}
function updateAnimationReadout(){
 const duration=state.materialDurationMs;const progress=$('materialTimeline');
 progress.max=String(duration);progress.value=String(Math.min(duration,Math.round(state.materialTimeMs)));
 $('materialTimeLabel').textContent=`${(state.materialTimeMs/1000).toFixed(2)} / ${(duration/1000).toFixed(2)} s`;
 if(state.model?.format==='M3'){
  const material=state.meshes[state.selected>=0?state.selected:0]?.material??0;
  const info=window.WSMaterialRenderer.materialInfo(state.model,material,materialClock());
  const l=info.layers[0];
  $('animatedValues').textContent=l?`Material ${material} · Opacity ${l.opacity.toFixed(2)} · Glow ${l.glow.toFixed(2)} · Gloss ${l.gloss.toFixed(2)}`:'Keine Material-Keyframes';
 }
}
function selectMaterialClip(){
 state.materialClip=Number($('materialAnimClip').value);
 const clip=state.materialClip<0?null:state.model?.m3Details?.clips?.[state.materialClip];
 state.bindPose=state.materialClip===-2; $('skeletonBindPose').checked=state.bindPose;
 if(state.bindPose){state.materialPlaying=false;$('materialPlay').textContent='▶ Play';}
 if(clip)state.materialDurationMs=Math.max(1,clip.durationMs||10000);
 else {
  let max=0;for(const mat of state.model?.m3Details?.materialData||[])for(const layer of mat.layers||[])
   for(const [name,p] of Object.entries(layer.parameters||{}))if(p?.count>1){const tr=window.WSMaterialAnimation.track(p,name==='colorMod'?3:1);if(tr)max=Math.max(max,tr.times[tr.count-1]);}
  state.materialDurationMs=Math.max(1000,Math.min(600000,max||10000));
 }
 state.materialTimeMs=0;state.materialLastFrame=null;state.skinLastTime=NaN;updateAnimationReadout();updateMaterialInspector();requestRender();
}
function updateAtlasPreview(){
 const flip=state.flipbooks[state.selectedFlipbook],canvas=$('flipbookCanvas');
 if(!flip||!canvas)return;
 const asset=state.model?.textureAssets?.[flip.texture],ctx=canvas.getContext('2d');if(!ctx)return;
 ctx.clearRect(0,0,canvas.width,canvas.height);
 if(!asset?.url){$('flipbookFrame').textContent='Emitter-Textur nicht gefunden';return;}
 let img=atlasImages.get(asset.url);
 if(!img){img=new Image();atlasImages.set(asset.url,img);img.onload=()=>{updateAtlasPreview();};img.onerror=()=>{$('flipbookFrame').textContent='TEX konnte nicht geladen werden';};img.src=asset.url;return;}
 if(!img.complete||!img.naturalWidth)return;
 const rect=window.WSMaterialAnimation.frameRect(flip,state.materialTimeMs/1000);
 const w=img.naturalWidth/rect.cols,h=img.naturalHeight/rect.rows;
 ctx.imageSmoothingEnabled=true;
 const outScale=Math.min(canvas.width/w,canvas.height/h);
 const dw=w*outScale,dh=h*outScale;
 ctx.drawImage(img,rect.x*w,rect.y*h,w,h,(canvas.width-dw)/2,(canvas.height-dh)/2,dw,dh);
 $('flipbookFrame').textContent=`Frame ${rect.frame+1}/${flip.frames} · Speed ${flip.speed.toFixed(2)} · TEX ${flip.texture}`;
}
async function chooseTextureRoot(){
 try{const data=await responseJson(await fetch('/api/texture-root',{method:'POST',headers:{'X-Viewer-Request':'1'},body:''}));
  if(data.cancelled)return;
  if(data.sections)await applyModel(data);else toast('Texturordner ausgewählt. Jetzt ein Modell laden.');
 }catch(e){showError(e);}
}
function bindUI(){
 $('nativeBrowse').onclick=browseNative;$('demoButton').onclick=loadDemo;$('heroDemo').onclick=loadDemo;
 $('textureFolder').onclick=chooseTextureRoot;$('animatedDemoButton').onclick=loadAnimatedDemo;
 $('materialsToggle').onchange=e=>{state.materialsEnabled=e.target.checked;requestRender();};
 $('materialPlay').onclick=()=>{if(state.materialClip===-2){state.materialClip=window.WSSkeletonAnimation.preferredClip(state.model?.m3Details?.clips);$('materialAnimClip').value=String(state.materialClip);selectMaterialClip();}
   state.bindPose=false;$('skeletonBindPose').checked=false;state.skinLastTime=NaN;
   state.materialPlaying=!state.materialPlaying;state.materialLastFrame=null;
   $('materialPlay').textContent=state.materialPlaying?'❚❚ Pause':'▶ Play';requestRender();};
 $('materialAnimClip').onchange=selectMaterialClip;
 $('skeletonEnabled').onchange=e=>{state.skeletonEnabled=e.target.checked;requestRender();};
 $('skeletonBindPose').onchange=e=>{state.bindPose=e.target.checked;state.skinLastTime=NaN;requestRender();};
 $('skeletonStop').onclick=()=>{state.materialPlaying=false;state.materialTimeMs=0;state.materialLastFrame=null;state.bindPose=true;
   $('skeletonBindPose').checked=true;$('materialPlay').textContent='▶ Play';updateAnimationReadout();requestRender();};
 $('materialTimeline').oninput=e=>{state.materialTimeMs=Number(e.target.value)||0;state.materialLastFrame=null;
   updateAnimationReadout();updateAtlasPreview();updateMaterialInspector();requestRender();};
 $('materialSpeed').onchange=e=>{state.materialSpeed=Number(e.target.value)||1;state.materialLastFrame=null;};
 $('uvPreviewToggle').onchange=e=>{state.uvPreview=e.target.checked;
   if(state.uvPreview&&!state.materialPlaying){state.materialPlaying=true;state.materialLastFrame=null;$('materialPlay').textContent='❚❚ Pause';}
   requestRender();};
 for(const [id,key] of [['uvSpeedU','uvSpeedU'],['uvSpeedV','uvSpeedV'],['uvRotation','uvRotate'],['uvTiling','uvScale']])
   $(id).oninput=e=>{let n=Number(e.target.value);if(Number.isFinite(n)){state[key]=n;requestRender();}};
 $('flipbookEmitter').onchange=e=>{state.selectedFlipbook=Number(e.target.value);updateAtlasPreview();requestRender();};
 $('uploadButton').onclick=()=>$('fileInput').click();$('fileInput').onchange=e=>{openFile(e.target.files?.[0]);e.target.value='';};
 $('meshSearch').addEventListener('input',renderMeshList);
 $('m3Category').onchange=e=>{state.catalogCategory=e.target.value;state.catalogSelected=0;renderM3Catalogue();};
 $('m3Filter').oninput=renderM3Catalogue;
 $('exportM3Json').onclick=exportM3Metadata;
 $('renderMode').onchange=e=>{state.renderMode=e.target.value;requestRender();};
 $('showAll').onclick=()=>{state.meshes.forEach(m=>m.visible=true);renderMeshList();requestRender();};
 $('hideAll').onclick=()=>{state.meshes.forEach(m=>m.visible=false);renderMeshList();requestRender();};
 for(const [id,key] of [['toggleGrid','grid'],['toggleAxes','axes'],['toggleWire','wire']])$(id).onclick=()=>{state[key]=!state[key];$(id).classList.toggle('active',state[key]);requestRender();};
 $('resetCamera').onclick=resetCamera;
 $('smoothToggle').onchange=e=>{state.smooth=e.target.checked;requestRender();};
 $('spinToggle').onchange=e=>{state.spinning=e.target.checked;requestRender();};
 $('screenshot').onclick=()=>{if(!state.model)return toast('Zuerst ein Modell öffnen.');requestRender();const out=document.createElement('canvas');out.width=canvas.width;out.height=canvas.height;
  const ctx=out.getContext('2d');const bg=ctx.createRadialGradient(out.width/2,out.height/2,0,out.width/2,out.height/2,out.width*.75);bg.addColorStop(0,'#22374b');bg.addColorStop(1,'#0b1622');ctx.fillStyle=bg;ctx.fillRect(0,0,out.width,out.height);ctx.drawImage(canvas,0,0);
  const a=document.createElement('a');a.download=state.model.name.replace(/[^\w.\-]/g,'_')+'.png';a.href=out.toDataURL('image/png');a.click();};
 $('fullScreen').onclick=()=>{if(document.fullscreenElement)document.exitFullscreen();else $('viewport').requestFullscreen?.();};
 const view=$('viewport');let dragDepth=0;
 view.addEventListener('dragenter',e=>{e.preventDefault();dragDepth++;$('dragOverlay').classList.remove('hidden');});
 view.addEventListener('dragover',e=>{e.preventDefault();e.dataTransfer.dropEffect='copy';});
 view.addEventListener('dragleave',e=>{e.preventDefault();dragDepth=Math.max(0,dragDepth-1);if(!dragDepth)$('dragOverlay').classList.add('hidden');});
 view.addEventListener('drop',e=>{e.preventDefault();dragDepth=0;$('dragOverlay').classList.add('hidden');openFile(e.dataTransfer?.files?.[0]);});
 canvas.oncontextmenu=e=>e.preventDefault();
 canvas.addEventListener('pointerdown',e=>{if(e.button>2)return;state.lastPointer=[e.clientX,e.clientY];state.moving=(e.button===2||e.shiftKey||e.button===1)?'pan':'rotate';canvas.setPointerCapture(e.pointerId);});
 canvas.addEventListener('pointerup',()=>{state.lastPointer=null;state.moving=false;});
 canvas.addEventListener('pointercancel',()=>{state.lastPointer=null;state.moving=false;});
 canvas.addEventListener('pointermove',e=>{if(!state.lastPointer||!state.model)return;const dx=e.clientX-state.lastPointer[0],dy=e.clientY-state.lastPointer[1];state.lastPointer=[e.clientX,e.clientY];
  if(state.moving==='pan'){
    const panScale=state.distance*Math.tan(Math.PI/8)*2/Math.max(100,canvas.clientHeight),right=[Math.cos(state.yaw),Math.sin(state.yaw),0];
    const up=[-Math.sin(state.yaw)*Math.sin(state.elevation),Math.cos(state.yaw)*Math.sin(state.elevation),Math.cos(state.elevation)];
    for(let i=0;i<3;i++)state.center[i]+=(-dx*right[i]+dy*up[i])*panScale;
  } else{state.yaw-=dx*.008;state.elevation=Math.max(-1.5,Math.min(1.5,state.elevation+dy*.008));}requestRender();});
 canvas.addEventListener('wheel',e=>{if(!state.model)return;e.preventDefault();state.distance=Math.max(.015,Math.min(1e7,state.distance*Math.exp(e.deltaY*.001)));requestRender();},{passive:false});
 window.addEventListener('keydown',e=>{
   if((e.ctrlKey||e.metaKey)&&e.key.toLowerCase()==='o'){e.preventDefault();browseNative();return;}
   if(['INPUT','SELECT','TEXTAREA'].includes(e.target?.tagName)||e.ctrlKey||e.altKey||e.metaKey)return;
   if(e.key.toLowerCase()==='f'&&state.model)resetCamera();
   if(e.code==='Space'&&state.model?.format==='M3'){e.preventDefault();$('materialPlay').click();}
   if(['ArrowLeft','ArrowRight'].includes(e.code)&&state.model?.format==='M3'){
     e.preventDefault();state.materialTimeMs=Math.max(0,Math.min(state.materialDurationMs,state.materialTimeMs+(e.code==='ArrowRight'?100:-100)));
     state.materialLastFrame=null;updateAnimationReadout();requestRender();
   }
  });
 new ResizeObserver(requestRender).observe(canvas);
}
try{initGL();bindUI();fetch('/api/status').then(responseJson).then(status => {
 const el=$('parserState');el.textContent=status.nativeM3?`M3: native ABI ${status.abi}`:'M3: '+(status.error||'DLL fehlt');
 if(!status.nativeM3)showError('Native M3-Parser nicht bereit: '+(status.error||'DLL fehlt')); 
 }).catch(e=>console.error('Parser-Status',e));
 if(new URLSearchParams(location.search).has('demo'))loadDemo();
 if(new URLSearchParams(location.search).has('startup')){
  setBusy(true,'Startmodell wird geladen…');fetch('/api/startup').then(responseJson).then(data=>data.cancelled?null:applyModel(data)).catch(e=>showError(e)).finally(()=>setBusy(false));
}}catch(e){console.error(e);toast('Renderer-Fehler: '+e.message,true);}
