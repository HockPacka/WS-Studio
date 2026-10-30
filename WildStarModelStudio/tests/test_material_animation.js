const assert=require('node:assert/strict');
const anim=require('../material_animation.js');
const r=require('../material_renderer.js');
function tr(times,values,components=1){
 const t=Buffer.alloc(times.length*4),v=Buffer.alloc(values.length*4);
 times.forEach((x,i)=>t.writeUInt32LE(x,i*4));values.forEach((x,i)=>v.writeFloatLE(x,i*4));
 return {count:times.length,components,times:t.toString('base64'),values:v.toString('base64')};
}
const opacity=tr([0,1000,2000],[0,1,0]);
assert.equal(anim.evaluate(opacity,0),0);
assert(Math.abs(anim.evaluate(opacity,500)-0.5)<0.00001);
assert(Math.abs(anim.evaluate(opacity,1500)-0.5)<0.00001);
assert.equal(anim.evaluate(opacity,5000),0);
const tint=tr([100,1100],[1,0,0,0,0.5,1],3);
assert.deepEqual(anim.evaluate(tint,600,3).map(x=>+x.toFixed(3)),[0.5,0.25,0.5]);
assert.equal(anim.track(tr([100,50],[0,1])),null); // unordered keys
assert.equal(anim.evaluate(null,150,1,0.4),0.4);
assert.equal(anim.clipClock({startMs:1000,durationMs:2000},500),1500);
assert.equal(anim.clipClock({startMs:1000,durationMs:2000},3000),3000);
let hdr=Buffer.alloc(32);hdr.writeUInt32LE(2,20);
const model={m3Details:{materialData:[{headerHex:hdr.toString('hex'),layers:[{
 colorTexture:0,normalTexture:1,parameters:{opacity,gloss:tr([0],[.6]),glow:tr([0,1000],[0,2]),colorMod:tint}
 }]}],emitters:[{type:0,template:{kind:'particle',texture0:0,texture1:65535,
 flipbookCols:4,flipbookRowShift:2,flipbookFrames:10,flipbookSpeed:5}}]},textureAssets:[{url:'/a.png'},{url:'/b.png'}]};
const material=r.materialInfo(model,0,500);
assert(Math.abs(material.layers[0].opacity-.5)<1e-5);
assert(Math.abs(material.layers[0].gloss-.6)<1e-5);
assert(Math.abs(material.layers[0].glow-1)<1e-5);
assert.equal(anim.materialTrackCount(model),3); // opacity, glow, colorMod
assert.equal(material.blend,2);
const books=anim.availableFlipbooks(model);
assert.equal(books.length,1);
assert.deepEqual(anim.frameRect(books[0],1.25),{frame:6,x:2,y:1,cols:4,rows:4});
assert.equal(anim.frameFor(books[0],2.4),2);
assert.equal(anim.availableFlipbooks({m3Details:{emitters:[{type:0,template:{kind:'particle',texture0:99,flipbookCols:2,flipbookFrames:4}}]},textureAssets:[]}).length,0);
console.log('M3 animated materials/flipbooks: 16 checks OK');
