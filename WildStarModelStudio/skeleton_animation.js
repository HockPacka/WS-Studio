/* WildStar M3 skeleton playback: bind-pose-preserving CPU bone-pose evaluation,
   GPU skin matrices. The known primary M3 tracks (0/2/4/6) are supported.
   The secondary pose tracks (1/3/5/7) and all proprietary transition semantics
   are deliberately left out until their blending meaning is verified.
   Binary field mapping: HockPacka/WS-Tools M3Anim.cpp and m3_animation_format.md.
*/
(function(root,factory){const api=factory(root.WSMaterialAnimation||(typeof require==='function'?require('./material_animation.js'):null));if(typeof module==='object'&&module.exports)module.exports=api;root.WSSkeletonAnimation=api;})(typeof globalThis!=='undefined'?globalThis:this,function(Anim){
 'use strict';
 const ID=()=>new Float32Array([1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1]);
 const EPS=1e-7;
 function multiply(a,b){const o=new Float32Array(16);for(let j=0;j<4;j++)for(let i=0;i<4;i++){
  let x=0;for(let k=0;k<4;k++)x+=a[k*4+i]*b[j*4+k];o[j*4+i]=x;
 }return o;}
 function invert(m){ // Gauss-Jordan: resilient to negative and nonuniform scales
  const a=new Float64Array(32);
  for(let r=0;r<4;r++)for(let c=0;c<4;c++){a[r*8+c]=m[c*4+r];a[r*8+4+c]=r===c?1:0;}
  for(let c=0;c<4;c++){let p=c;for(let r=c+1;r<4;r++)if(Math.abs(a[r*8+c])>Math.abs(a[p*8+c]))p=r;
   if(Math.abs(a[p*8+c])<1e-10)return null;
   if(p!==c)for(let j=0;j<8;j++){const v=a[c*8+j];a[c*8+j]=a[p*8+j];a[p*8+j]=v;}
   const scale=a[c*8+c];for(let j=0;j<8;j++)a[c*8+j]/=scale;
   for(let r=0;r<4;r++)if(r!==c){const f=a[r*8+c];for(let j=0;j<8;j++)a[r*8+j]-=f*a[c*8+j];}
  }
  const out=new Float32Array(16);for(let r=0;r<4;r++)for(let c=0;c<4;c++)out[c*4+r]=a[r*8+4+c];return out;
 }
 function translation(p){const m=ID();m[12]=p[0];m[13]=p[1];m[14]=p[2];return m;}
 function scale3(p){const m=ID();m[0]=p[0];m[5]=p[1];m[10]=p[2];return m;}
 function quatMatrix(q){let [x,y,z,w]=q;const len=Math.hypot(x,y,z,w);if(len<EPS)return ID();x/=len;y/=len;z/=len;w/=len;
  const xx=x*x,yy=y*y,zz=z*z,xy=x*y,xz=x*z,yz=y*z,wx=w*x,wy=w*y,wz=w*z;
  return new Float32Array([1-2*(yy+zz),2*(xy+wz),2*(xz-wy),0,2*(xy-wz),1-2*(xx+zz),2*(yz+wx),0,2*(xz+wy),2*(yz-wx),1-2*(xx+yy),0,0,0,0,1]);
 }
 function normalizeQuat(q){const n=Math.hypot(...q);return n>EPS?q.map(x=>x/n):[0,0,0,1];}
 function slerp(a,b,t){a=normalizeQuat(a);b=normalizeQuat(b);let d=a.reduce((s,x,i)=>s+x*b[i],0);
  if(d<0){b=b.map(x=>-x);d=-d;}d=Math.min(1,Math.max(-1,d));
  if(d>0.9995)return normalizeQuat(a.map((x,i)=>x+(b[i]-x)*t));
  const theta=Math.acos(d),ss=Math.sin(theta);const x=Math.sin((1-t)*theta)/ss,y=Math.sin(t*theta)/ss;
  return a.map((v,i)=>v*x+b[i]*y);
 }
 function value(track,time,components,def,quaternion=false){const decoded=Anim?.track(track,components);if(!decoded)return def.slice();
  const {times,values,count}=decoded;let lo=0,hi=count-1;
  if(time<=times[0])return Array.from(values.slice(0,components));
  if(time>=times[count-1])return Array.from(values.slice((count-1)*components,count*components));
  while(hi-lo>1){const mid=(lo+hi)>>1;if(times[mid]<=time)lo=mid;else hi=mid;}
  const a=Array.from(values.slice(lo*components,(lo+1)*components)),b=Array.from(values.slice(hi*components,(hi+1)*components));
  const f=(time-times[lo])/(times[hi]-times[lo]||1);
  return quaternion?slerp(a,b,f):a.map((x,i)=>x*(1-f)+b[i]*f);
 }
 function boneLocalRaw(bone,time){const tracks=bone.tracks||{};
  const t=value(tracks.translation,time,3,[0,0,0]);const q=value(tracks.rotation,time,4,[0,0,0,1],true);
  const scale=value(tracks.scale,time,3,[1,1,1]);const parent=value(tracks.parentScale,time,3,[1,1,1]);
  const effective=scale.map((x,i)=>Math.min(100,Math.max(.00001,Math.abs(x)/(Math.abs(parent[i])>.000001?Math.abs(parent[i]):1))));
  return multiply(multiply(translation(t),quatMatrix(q)),scale3(effective));
 }
 function hasTracks(bone){return ['scale','rotation','translation','parentScale'].some(k=>bone.tracks?.[k]?.count>0);}
 function baseTimeFor(clips){return (clips||[]).find(c=>c.id===210)?.startMs??(clips||[]).find(c=>c.id===150)?.startMs??(clips||[])[0]?.startMs??0;}
 const toView=new Float32Array([1,0,0,0,0,0,1,0,0,-1,0,0,0,0,0,1]);
 const fromView=new Float32Array([1,0,0,0,0,0,-1,0,0,1,0,0,0,0,0,1]);
 function fromStored(raw){return Array.isArray(raw)&&raw.length===16&&raw.every(Number.isFinite)?Float32Array.from(raw):ID();}
 function signed(id){return scale3(id);}
 function signOptions(){const r=[];for(let n=0;n<=3;n++)for(let k=0;k<8;k++){
  const s=[k&1?-1:1,k&2?-1:1,k&4?-1:1];if(s.filter(x=>x===-1).length===n)r.push(signed(s));
 }return r;}
 const SIGNS=signOptions();
 function score(a,b){let m=0;for(let j=0;j<4;j++)for(let i=0;i<3;i++)m=Math.max(m,Math.abs(a[j*4+i]-b[j*4+i]));return m;}
 function build(model){const details=model?.m3Details||{},bones=details.bones||[],n=bones.length;
  if(!n||n>4096)return null;
  const clips=details.clips||[],baseTime=baseTimeFor(clips),parents=new Int32Array(n),bind=[],inverseBind=[],localBase=[],solves=[],motion=[];
  for(let i=0;i<n;i++){
   const b=bones[i],p=Number(b.parent);parents[i]=Number.isInteger(p)&&p>=0&&p<n&&p!==i?p:-1;
   bind.push(fromStored(b.bindWorld));motion.push(hasTracks(b));
  }
  // Parent ordering is explicitly resolved; do not assume bone IDs are topologically sorted.
  const order=[],visiting=new Uint8Array(n);
  function visit(i){if(visiting[i]===2)return;if(visiting[i]===1){parents[i]=-1;return;}
   visiting[i]=1;if(parents[i]>=0)visit(parents[i]);visiting[i]=2;order.push(i);}
  for(let i=0;i<n;i++)visit(i);
  let solved=0,unsolved=0;
  for(const i of order){const b=bones[i],p=parents[i],parentBind=p>=0?bind[p]:ID();
   const invP=invert(parentBind)||ID();const localBind=multiply(invP,bind[i]);
   const baseRaw=boneLocalRaw(b,baseTime);
   let x=ID(),y=ID();if(motion[i]){
    let best=Infinity;const ts=value(b.tracks?.translation,baseTime,3,[0,0,0]),q=value(b.tracks?.rotation,baseTime,4,[0,0,0,1],true);
    const sc=value(b.tracks?.scale,baseTime,3,[1,1,1]);const ps=value(b.tracks?.parentScale,baseTime,3,[1,1,1]);
    const s=sc.map((v,j)=>Math.min(100,Math.max(.00001,Math.abs(v)/(Math.abs(ps[j])>.000001?Math.abs(ps[j]):1))));
    for(const sx of SIGNS)for(const sy of SIGNS){const m=multiply(multiply(multiply(multiply(sx,translation(ts)),quatMatrix(q)),sy),scale3(s));
     const error=score(m,localBind);if(error<best){best=error;x=sx;y=sy;}
    }
    if(best<0.03)solved++;else{x=ID();y=ID();unsolved++;}
   }
   const corrected=multiply(multiply(multiply(multiply(x,translation(value(b.tracks?.translation,baseTime,3,[0,0,0]))),quatMatrix(value(b.tracks?.rotation,baseTime,4,[0,0,0,1],true))),y),scale3(value(b.tracks?.scale,baseTime,3,[1,1,1]).map((v,j)=>{
    const pv=value(b.tracks?.parentScale,baseTime,3,[1,1,1])[j];return Math.min(100,Math.max(.00001,Math.abs(v)/(Math.abs(pv)>1e-6?Math.abs(pv):1)));})));
   localBase[i]={localBind,x,y,baseInverse:invert(corrected)||invert(baseRaw)||ID()};
   inverseBind[i]=invert(bind[i])||ID();
  }
  const palette=details.boneMap||[];
  const player={bones,n,parents,order,bind,inverseBind,localBase,motion,palette,baseTime,solved,unsolved,animatedCount:motion.filter(Boolean).length};
  player.skin=new Float32Array(n*16);player.world=new Array(n);
  // Initialize true rest pose. When an animation starts evaluate() recomputes every bone.
  for(let i=0;i<n;i++)player.skin.set(ID(),i*16);
  return player;
 }
 function evaluate(player,time,bindPose=false){if(!player)return null;
  const {bones,parents,order,localBase,world,bind,inverseBind,skin}=player;
  if(bindPose){for(let i=0;i<player.n;i++)skin.set(ID(),i*16);return skin;}
  for(const i of order){const p=parents[i],setup=localBase[i];let local=setup.localBind;
   if(player.motion[i]){
    const bone=bones[i],tracks=bone.tracks||{};
    const t=translation(value(tracks.translation,time,3,[0,0,0]));const q=quatMatrix(value(tracks.rotation,time,4,[0,0,0,1],true));
    const sc=value(tracks.scale,time,3,[1,1,1]),parent=value(tracks.parentScale,time,3,[1,1,1]);
    const s=scale3(sc.map((v,j)=>Math.min(100,Math.max(.00001,Math.abs(v)/(Math.abs(parent[j])>1e-6?Math.abs(parent[j]):1)))));
    const raw=multiply(multiply(multiply(multiply(setup.x,t),q),setup.y),s);
    local=multiply(setup.localBind,multiply(setup.baseInverse,raw));
   }
   world[i]=p<0?local:multiply(world[p],local);
   const native=multiply(world[i],inverseBind[i]);
   skin.set(multiply(multiply(toView,native),fromView),i*16);
  }
  return skin;
 }
 function vertexPalette(boneIndices,boneWeights,start,palette,boneCount){if(!boneIndices||!boneWeights||boneIndices.length!==boneWeights.length||boneIndices.length%4!==0)return null;
  const mapped=new Uint16Array(boneIndices.length),weights=new Uint8Array(boneWeights);
  let influenced=0,invalid=0;
  for(let i=0;i<boneIndices.length;i+=4){let sum=0;
   for(let j=0;j<4;j++){
    if(!weights[i+j])continue;
    const loc=Number(start)+boneIndices[i+j],idx=palette[loc];
    if(!Number.isInteger(idx)||idx<0||idx>=boneCount){weights[i+j]=0;invalid++;continue;}
    mapped[i+j]=idx;sum+=weights[i+j];
   }
   if(sum){influenced++;if(sum!==255){let rem=255;let last=-1;for(let j=0;j<4;j++)if(weights[i+j])last=j;for(let j=0;j<4;j++){if(!weights[i+j])continue;const w=j===last?rem:Math.min(rem,Math.round(weights[i+j]*255/sum));weights[i+j]=w;rem-=w;}}
   }
  }
  return {indices:mapped,weights,influenced,invalid};
 }
 function preferredClip(clips){const idx=(clips||[]).findIndex(c=>c.id===150&&c.durationMs>0);if(idx>=0)return idx;
  const a=(clips||[]).findIndex(c=>c.id===210&&c.durationMs>0);if(a>=0)return a;
  return (clips||[]).findIndex(c=>c.durationMs>0);
 }
 return {ID,multiply,invert,translation,scale3,quatMatrix,slerp,value,baseTimeFor,build,evaluate,vertexPalette,preferredClip};
});
