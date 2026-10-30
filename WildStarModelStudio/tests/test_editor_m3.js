'use strict';
const assert=require('node:assert/strict');
const {CATEGORY,items,filter,preview}=require('../m3_explorer.js');
const Buffer=require('node:buffer').Buffer;
const f=new Float32Array([1,2,3]);
const u=new Uint32Array([0,100,200]);
const details={
 textures:[{id:65535,path:'Art\\Creature\\Test_Diffuse.tex',type:0}],
 materialData:[{index:0,layers:[{colorTexture:0,normalTexture:65535,parameters:{gloss:{count:3,components:1,times:Buffer.from(u.buffer).toString('base64'),values:Buffer.from(f.buffer).toString('base64')}}}]}],
 bones:[{index:0,modelBoneId:18,parent:-1,tracks:{translation:{count:3,components:1,times:Buffer.from(u.buffer).toString('base64'),values:Buffer.from(f.buffer).toString('base64')}}}],
 clips:[{id:152,variant:0,durationMs:1500}],
 emitters:[{type:0,bone:1,blendMode:2}],
 attachments:[], cameras:[], lights:[], geometryInventory:[], auxiliaryTables:{soundEvents:{count:4}},
 collision:{records:0,items:[]}, rawHeader:'aa'.repeat(1584),
};
assert.equal(CATEGORY.length,12);
assert.equal(items(details,'textures').length,1);
assert.equal(items(details,'materials')[0].title,'Material 0');
assert.equal(items(details,'bones')[0].description,'Parent -1 · 1 Tracks');
assert.equal(items(details,'clips')[0].description,'Variante 0 · 1.50 s');
assert.equal(items(details,'tables').length,1);
assert.equal(filter(items(details,'textures'),'diffuse').length,1);
const p=preview(details.bones[0]);
assert.deepEqual(p.tracks.translation.keyframesMs,[0,100,200]);
assert.deepEqual(p.tracks.translation.values,[1,2,3]);
assert.match(preview({rawHeader:details.rawHeader}).rawHeader,/Hex/);
console.log('M3 Explorer: 10 assertions OK');
