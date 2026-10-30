const assert=require('node:assert/strict');
const A=require('../skeleton_animation.js');
const {readFileSync}=require('node:fs');
function track(times,values,components){const t=Buffer.alloc(times.length*4),v=Buffer.alloc(values.length*4);
 times.forEach((a,i)=>t.writeUInt32LE(a,i*4));values.forEach((a,i)=>v.writeFloatLE(a,i*4));
 return {count:times.length,components,times:t.toString('base64'),values:v.toString('base64')};}
function near(a,b,eps=1e-4){assert(Math.abs(a-b)<eps,`${a} != ${b}`);}
const q=A.slerp([0,0,0,1],[0,0,1,0],.5);
near(q[2],Math.SQRT1_2);near(q[3],Math.SQRT1_2);
assert.equal(A.invert(A.ID())[0],1);
const mat=A.multiply(A.translation([1,2,3]),A.translation([3,2,1]));
assert.deepEqual(Array.from(mat.slice(12,15)),[4,4,4]);
const root={index:0,parent:-1,bindWorld:Array.from(A.ID()),tracks:{translation:track([0,1000],[0,0,0,2,0,0],3),rotation:track([0,1000],[0,0,0,1,0,0,0,1],4)}};
const local=A.translation([0,1,0]);
const child={index:1,parent:0,bindWorld:Array.from(local),tracks:{}};
const clips=[{id:210,startMs:0,durationMs:1000},{id:152,startMs:0,durationMs:1000}];
const player=A.build({m3Details:{bones:[root,child],clips,boneMap:[0,1]}});
assert.equal(player.animatedCount,1);
assert.equal(player.baseTime,0);
assert.equal(player.n,2);
const bind=A.evaluate(player,0);
near(bind[12],0);near(bind[16+12],0); // both bones identity at base
const half=A.evaluate(player,500);
near(half[12],1);near(half[16+12],1);
near(half[13],0);near(half[14],0);
const reset=A.evaluate(player,500,true);near(reset[12],0);near(reset[16+12],0);
assert.equal(A.preferredClip([{id:210,durationMs:10},{id:150,durationMs:50}]),1);
let palette=A.vertexPalette(new Uint8Array([1,0,0,0,0,0,0,0]),new Uint8Array([128,127,0,0,255,0,0,0]),1,[88,1,0],2);
assert(palette);
assert.deepEqual(Array.from(palette.indices.slice(0,2)),[0,1]);
assert.deepEqual(Array.from(palette.weights.slice(0,2)),[128,127]);
assert.equal(palette.influenced,2);
palette=A.vertexPalette(new Uint8Array([9,2,0,0]),new Uint8Array([200,55,0,0]),0,[0,0,1],2);
assert.equal(palette.invalid,1);assert.deepEqual(Array.from(palette.weights),[0,255,0,0]);
palette=A.vertexPalette(new Uint8Array([1,0,0,0]),new Uint8Array([100,0,0,0]),0,[0,1],2);
assert.deepEqual(Array.from(palette.weights),[255,0,0,0]);
// Bind pose must stay unchanged even for nested, rotated rest frames.
const rotated=A.multiply(A.translation([2,-1,3]),A.quatMatrix([0,0,Math.SQRT1_2,Math.SQRT1_2]));
const b0={parent:-1,bindWorld:Array.from(rotated),tracks:{rotation:track([0,1000],[0,0,Math.SQRT1_2,Math.SQRT1_2,0,0,1,0],4),translation:track([0,1000],[2,-1,3,2,-1,3],3)}};
const complex=A.build({m3Details:{bones:[b0],clips:[{id:210,startMs:0,durationMs:1000}],boneMap:[0]}});
const idMat=A.evaluate(complex,0);
for(let i=0;i<16;i++)near(idMat[i],A.ID()[i],5e-4);
const active=A.evaluate(complex,1000);
assert(active.some((n,i)=>Math.abs(n-A.ID()[i])>0.1),'rotation must deform');
console.log('M3 skeleton animation: 25 assertions passed');
