const assert=require('assert');
const r=require('../material_renderer.js');
function param(...values){const raw=Buffer.alloc(values.length*4);values.forEach((v,i)=>raw.writeFloatLE(v,i*4));return {count:1,values:raw.toString('base64')};}
let header=Buffer.alloc(32);header.writeUInt32LE(1,20);
const model={m3Details:{materialData:[{headerHex:header.toString('hex'),layers:[{colorTexture:3,normalTexture:4,
  parameters:{opacity:param(0.7),gloss:param(0.6),glow:param(0.2),colorMod:param(1,0.3,2)}}]}]}};
const mat=r.materialInfo(model,0);
assert.equal(mat.blend,1);assert.equal(mat.layers.length,1);assert.equal(mat.layers[0].color,3);
assert.equal(mat.layers[0].normal,4);assert(Math.abs(mat.layers[0].opacity-0.7)<0.001);
assert.deepEqual(r.materialInfo(model,999),{blend:0,layers:[]});
console.log('Material shader mapping tests passed');
