//! Native reader for WildStar `.m3` models (magic `LDOM`, version 100, build 16042).
//! Format: WS-Tools `docs/m3_format_spec.md`, reference `Model3/M3Reader.cpp`.
//! Reads geometry, meshes, textures, materials, bones and clips. Animation
//! tracks, particle/ribbon emitters, lights and cameras are not decoded here.
use crate::binary::*;

const HEADER_END:usize=0x630;

#[derive(Debug,Clone,Copy,Default)]
pub struct M3Vertex {
    pub pos:[f32;3],
    pub normal:[f32;3],
    pub uv:[f32;2],
    pub bone_idx:[u8;4],
    pub bone_weight:[u8;4],
}
#[derive(Debug,Clone)]
pub struct M3Mesh {
    /// Index range into `M3Model::indices` (indices are already global vertex indices).
    pub start_index:u32,
    pub index_count:u32,
    pub start_vertex:u32,
    pub vertex_count:u32,
    pub material:u16,
    pub bone_start:u16,
    pub bone_count:u16,
    pub group:u8,
    pub cluster:u8,
    pub geometry:u32,
    pub flags:u32,
}
impl M3Mesh {
    /// The client excludes meshes with `(flags & 0x0A) == 0x0A` from the normal draw list.
    pub fn is_hidden(&self)->bool{self.flags&0x0A==0x0A}
}
#[derive(Debug,Clone)]
pub struct M3Texture {
    pub name:String,
    /// 0 color, 1 normal, 2 skinfx
    pub kind:u8,
    pub model_texture_id:u16,
}
/// Material header +0x14 (confirmed by the original renderer `FUN_1403283c0`).
#[derive(Debug,Clone,Copy,PartialEq,Eq,Default)]
pub enum M3Blend { #[default] Opaque, Cutout, Alpha, Add, AlphaAdd, Multiply, Multiply2x, Special }
impl M3Blend {
    pub fn from_raw(v:u32)->Self{
        match v{0=>Self::Opaque,1=>Self::Cutout,2=>Self::Alpha,3=>Self::Add,4=>Self::AlphaAdd,
            5=>Self::Multiply,6=>Self::Multiply2x,_=>Self::Special}
    }
}
#[derive(Debug,Clone)]
pub struct M3Material {
    pub blend:M3Blend,
    /// Header +0x08: 0 normal, 1 special permutation, 2 effect.
    pub material_type:u32,
    /// Header +0x0C flags (bit 1 = effect).
    pub flags:u32,
    /// First layer parameters (first key of each track); defaults when absent.
    pub opacity:f32,
    pub gloss:f32,
    pub glow:f32,
    /// HDR colour multiplier of the first layer.
    pub color_mod:[f32;3],
    pub layer_count:u32,
    /// Texture index of the first layer (`None` = no texture).
    pub color_texture:Option<usize>,
    pub normal_texture:Option<usize>,
}
impl Default for M3Material {
    fn default()->Self{
        Self{blend:M3Blend::Opaque,material_type:0,flags:0,opacity:1.0,gloss:0.0,glow:0.0,
            color_mod:[1.0;3],layer_count:0,color_texture:None,normal_texture:None}
    }
}
#[derive(Debug,Clone)]
pub struct M3Bone {
    pub model_bone_id:u16,
    pub parent:i16,
    pub hash:u32,
    /// Bind pose world translation (WildStar axes).
    pub pivot:[f32;3],
    /// World bind matrix as stored (row-vector convention).
    pub bind_world:[f32;16],
}
#[derive(Debug,Clone)]
pub struct M3Clip {
    pub anim_id:u16,
    pub variant:u16,
    pub start_ms:u32,
    pub end_ms:u32,
    pub speed:f32,
}
#[derive(Debug,Clone,Default)]
pub struct M3Model {
    pub vertices:Vec<M3Vertex>,
    pub indices:Vec<u32>,
    pub meshes:Vec<M3Mesh>,
    pub textures:Vec<M3Texture>,
    pub materials:Vec<M3Material>,
    pub bones:Vec<M3Bone>,
    pub bone_map:Vec<u16>,
    pub clips:Vec<M3Clip>,
    /// (ModelMesh id, default-render flag); `M3Mesh::group` indexes this list (255 = always drawn).
    pub mesh_display:Vec<(u16,u16)>,
    pub bounds_min:[f32;3],
    pub bounds_max:[f32;3],
}
impl M3Model {
    pub fn triangle_count(&self)->usize{self.indices.len()/3}
    pub fn bounds_size(&self)->[f32;3]{
        [self.bounds_max[0]-self.bounds_min[0],self.bounds_max[1]-self.bounds_min[1],
         self.bounds_max[2]-self.bounds_min[2]]
    }
    /// Index list of all meshes that the client draws by default.
    pub fn visible_indices(&self)->Vec<u32>{
        let mut out=Vec::new();
        for mesh in self.meshes.iter().filter(|m|!m.is_hidden()){
            let s=mesh.start_index as usize;
            out.extend_from_slice(&self.indices[s..s+mesh.index_count as usize]);
        }
        out
    }
    pub fn color_texture_of(&self,mesh:&M3Mesh)->Option<&str>{
        let tex=self.materials.get(mesh.material as usize)?.color_texture?;
        self.textures.get(tex).map(|t|t.name.as_str())
    }
}

fn octahedral(b0:u8,b1:u8)->[f32;3]{
    let mut x=b0 as f32/255.0*2.0-1.0;
    let mut y=b1 as f32/255.0*2.0-1.0;
    let z=1.0-x.abs()-y.abs();
    if z<0.0{
        let nx=(1.0-y.abs())*if x>=0.0{1.0}else{-1.0};
        let ny=(1.0-x.abs())*if y>=0.0{1.0}else{-1.0};
        x=nx;y=ny;
    }
    let mut n=(x*x+y*y+z*z).sqrt();
    if n==0.0{n=1.0;}
    [x/n,y/n,z/n]
}

pub fn is_m3(data:&[u8])->bool{data.len()>=HEADER_END&&&data[..4]==b"LDOM"}

pub fn read_m3(d:&[u8])->Result<M3Model,String>{
    if !is_m3(d){return Err("not an M3 file".into());}
    let len=d.len();
    // Header array: {u64 count, u64 offset relative to 0x630}.
    let ap=|slot:usize|->Option<(u64,usize)>{
        let count=u64_at(d,slot)?;
        let off=u64_at(d,slot+8)?;
        if off>len as u64{return None;}
        Some((count,off as usize+HEADER_END))
    };
    let mut m=M3Model::default();

    let (n,a)=ap(0x1B0).filter(|&(n,a)|n<=len as u64&&a as u64+n*2<=len as u64)
        .ok_or("bone map out of bounds")?;
    for i in 0..n as usize{m.bone_map.push(u16_at(d,a+i*2).unwrap_or(0));}

    if let Some((n,a))=ap(0x200).filter(|&(n,a)|n<4096&&a as u64+n*4<=len as u64){
        for i in 0..n as usize{
            m.mesh_display.push((u16_at(d,a+i*4).unwrap_or(0),u16_at(d,a+i*4+2).unwrap_or(0)));
        }
    }

    let (n,a)=ap(0x180).filter(|&(n,a)|n<=len as u64&&a as u64+n*0x160<=len as u64)
        .ok_or("bones out of bounds")?;
    for i in 0..n as usize{
        let o=a+i*0x160;
        let mut bind_world=[0f32;16];
        for (k,v) in bind_world.iter_mut().enumerate(){*v=f32_at(d,o+0xD0+k*4).unwrap_or(0.0);}
        m.bones.push(M3Bone{
            model_bone_id:u16_at(d,o).unwrap_or(0),
            parent:u16_at(d,o+4).unwrap_or(0xFFFF) as i16,
            hash:u32_at(d,o+8).unwrap_or(0),
            pivot:[bind_world[12],bind_world[13],bind_world[14]],
            bind_world,
        });
    }

    if let Some((cc,ca))=ap(0x10).filter(|&(c,a)|c<100_000&&a as u64+c*0x70<=len as u64){
        for i in 0..cc as usize{
            let r=ca+i*0x70;
            m.clips.push(M3Clip{
                anim_id:u16_at(d,r).unwrap_or(0),variant:u16_at(d,r+2).unwrap_or(0),
                start_ms:u32_at(d,r+12).unwrap_or(0),end_ms:u32_at(d,r+16).unwrap_or(0),
                speed:f32_at(d,r+20).unwrap_or(1.0),
            });
        }
    }

    let (tc,ta)=ap(0x1C0).filter(|&(n,a)|n<=len as u64&&a as u64+n*0x20<=len as u64)
        .ok_or("textures out of bounds")?;
    let name_base=align16(ta+tc as usize*0x20);
    for i in 0..tc as usize{
        let o=ta+i*0x20;
        let nc=u64_at(d,o+16).unwrap_or(0);
        let no=u64_at(d,o+24).unwrap_or(0);
        let p=range(len,name_base,no,nc,2).ok_or("texture name out of bounds")?;
        m.textures.push(M3Texture{
            name:utf16(d,p,nc as usize),kind:d[o+2],
            model_texture_id:u16_at(d,o).unwrap_or(0xFFFF),
        });
    }

    let (mc,ma)=ap(0x1F0).filter(|&(n,a)|n<=len as u64&&a as u64+n*0x30<=len as u64)
        .ok_or("materials out of bounds")?;
    let desc_base=align16(ma+mc as usize*0x30);
    for i in 0..mc as usize{
        let r=ma+i*0x30;
        let dc=u64_at(d,r+0x20).unwrap_or(0);
        let doff=u64_at(d,r+0x28).unwrap_or(0);
        let mut mat=M3Material{
            material_type:u32_at(d,r+0x08).unwrap_or(0),flags:u32_at(d,r+0x0C).unwrap_or(0),
            blend:M3Blend::from_raw(u32_at(d,r+0x14).unwrap_or(0)),..Default::default()
        };
        if dc>0{
            let p=if dc<=4{range(len,desc_base,doff,dc,0x128)}else{None}
                .ok_or("material layers out of bounds")?;
            mat.layer_count=dc as u32;
            let tex=|v:u16|if v==0xFFFF{None}else{Some(v as usize)};
            mat.color_texture=u16_at(d,p).and_then(tex);
            mat.normal_texture=u16_at(d,p+2).and_then(tex);
            // First key of a layer parameter track; value arrays are relative to align16(end of the layers).
            let nbase=align16(desc_base+doff as usize+dc as usize*0x128);
            let first=|dp:usize,n:usize|->Option<Vec<f32>>{
                if u64_at(d,p+dp)?==0{return None;}
                let at=range(len,nbase,u64_at(d,p+dp+0x10)?,1,n*4)?;
                let v:Vec<f32>=(0..n).map(|k|f32_at(d,at+k*4).unwrap_or(f32::NAN)).collect();
                v.iter().all(|x|x.is_finite()).then_some(v)
            };
            if let Some(v)=first(0x60,1){mat.opacity=v[0].clamp(0.0,1.0);}
            if let Some(v)=first(0x30,1){mat.gloss=v[0].clamp(0.0,4.0);}
            if let Some(v)=first(0x48,1){mat.glow=v[0].clamp(0.0,4.0);}
            if let Some(v)=first(0x108,3).filter(|v|v.iter().all(|x|(0.0..64.0).contains(x))){
                mat.color_mod=[v[0],v[1],v[2]];
            }
        }
        m.materials.push(mat);
    }

    let (gc,ga)=ap(0x250).filter(|&(n,a)|n<=len as u64&&a as u64+n*0xC8<=len as u64)
        .ok_or("geometry out of bounds")?;
    let gb=align16(ga+gc as usize*0xC8);
    for gi in 0..gc as usize{
        let g=ga+gi*0xC8;
        let vcount=u32_at(d,g+0x18).unwrap_or(0) as usize;
        let vsize=u16_at(d,g+0x1C).unwrap_or(0) as usize;
        let types=&d[g+0x20..g+0x2B];
        let vdo=u64_at(d,g+0x40).unwrap_or(0);
        let icount=u32_at(d,g+0x68).unwrap_or(0) as usize;
        let ido=u64_at(d,g+0x78).unwrap_or(0);
        let msc=u64_at(d,g+0x80).unwrap_or(0);
        let mso=u64_at(d,g+0x88).unwrap_or(0);

        // Field order is sequential; the sum of field sizes must equal the vertex size.
        let mut off=0usize;
        let (mut pos_off,mut nor_off,mut bi_off,mut bw_off,mut uv_off)=(None,None,None,None,None);
        match types[0]{1=>{pos_off=Some(off);off+=12;},2=>{pos_off=Some(off);off+=6;},_=>{}}
        if types[1]==3{off+=2;}
        if types[2]==3{nor_off=Some(off);off+=2;}
        if types[3]==3{off+=2;}
        if types[4]==4{bi_off=Some(off);off+=4;}
        if types[5]==4{bw_off=Some(off);off+=4;}
        if types[6]==4{off+=4;}
        if types[7]==4{off+=4;}
        if types[8]==5{uv_off=Some(off);off+=4;}
        if types[9]==5{off+=4;}
        if types[10]==6{off+=1;}
        if vsize!=0&&off!=vsize{return Err("vertex layout size mismatch".into());}

        let va=range(len,gb,vdo,vcount as u64,vsize).ok_or("vertex data out of bounds")?;
        let base=m.vertices.len();
        for v in 0..vcount{
            let p=va+v*vsize;
            let mut out=M3Vertex{normal:[0.0,1.0,0.0],bone_weight:[255,0,0,0],..Default::default()};
            if let Some(o)=pos_off{
                for k in 0..3{
                    out.pos[k]=if types[0]==1{f32_at(d,p+o+k*4).unwrap_or(0.0)}
                        else{u16_at(d,p+o+k*2).unwrap_or(0) as i16 as f32/1024.0};
                }
            }
            if let Some(o)=nor_off{out.normal=octahedral(d[p+o],d[p+o+1]);}
            if let Some(o)=uv_off{
                out.uv=[half_to_f32(u16_at(d,p+o).unwrap_or(0)),half_to_f32(u16_at(d,p+o+2).unwrap_or(0))];
            }
            if let Some(o)=bi_off{out.bone_idx.copy_from_slice(&d[p+o..p+o+4]);}
            if let Some(o)=bw_off{out.bone_weight.copy_from_slice(&d[p+o..p+o+4]);}
            m.vertices.push(out);
        }

        let ia=range(len,gb,ido,icount as u64,2).ok_or("index data out of bounds")?;
        let ma2=range(len,gb,mso,msc,0x70).ok_or("mesh table out of bounds")?;
        let index_base=m.indices.len();
        m.indices.extend((0..icount).map(|k|u16_at(d,ia+k*2).unwrap_or(0) as u32));
        for k in 0..msc as usize{
            let r=ma2+k*0x70;
            let mut me=M3Mesh{
                start_index:u32_at(d,r).unwrap_or(0),start_vertex:u32_at(d,r+4).unwrap_or(0),
                index_count:u32_at(d,r+8).unwrap_or(0),vertex_count:u32_at(d,r+12).unwrap_or(0),
                material:u16_at(d,r+0x16).unwrap_or(0),bone_start:u16_at(d,r+0x10).unwrap_or(0),
                bone_count:u16_at(d,r+0x12).unwrap_or(0),group:d[r+0x1E],cluster:d[r+0x22],
                geometry:gi as u32,flags:u32_at(d,r+0x38).unwrap_or(0),
            };
            if me.start_index as u64+me.index_count as u64>icount as u64
                ||me.start_vertex as u64+me.vertex_count as u64>vcount as u64{
                return Err("mesh range out of bounds".into());
            }
            // Indices are local to the mesh: make them global.
            for q in 0..me.index_count as usize{
                let ix=&mut m.indices[index_base+me.start_index as usize+q];
                if *ix>=me.vertex_count{return Err("index outside of mesh vertex range".into());}
                *ix+=me.start_vertex+base as u32;
            }
            me.start_index+=index_base as u32;
            me.start_vertex+=base as u32;
            m.meshes.push(me);
        }
    }

    if let Some(first)=m.vertices.first(){
        let (mut lo,mut hi)=(first.pos,first.pos);
        for v in &m.vertices{
            for k in 0..3{lo[k]=lo[k].min(v.pos[k]);hi[k]=hi[k].max(v.pos[k]);}
        }
        m.bounds_min=lo;m.bounds_max=hi;
    }
    Ok(m)
}

#[cfg(test)]
mod tests {
    use super::*;
    fn put(d:&mut Vec<u8>,at:usize,bytes:&[u8]){
        if d.len()<at+bytes.len(){d.resize(at+bytes.len(),0);}
        d[at..at+bytes.len()].copy_from_slice(bytes);
    }
    /// One geometry (3 f32 vertices, 1 mesh, 1 triangle), one material, one texture.
    fn sample()->Vec<u8>{
        let mut d=vec![0u8;HEADER_END];
        d[..4].copy_from_slice(b"LDOM");
        d[4..8].copy_from_slice(&100u32.to_le_bytes());
        let set_ap=|d:&mut Vec<u8>,slot:usize,count:u64,off:u64|{
            put(d,slot,&count.to_le_bytes());put(d,slot+8,&off.to_le_bytes());
        };
        // sections after the header, all 16-byte aligned
        set_ap(&mut d,0x1C0,1,0);           // textures at 0x630 (0x20), names at 0x650
        set_ap(&mut d,0x1F0,1,0x30);        // materials at 0x660 (0x30), layers at 0x690
        set_ap(&mut d,0x250,1,0x30+0x30+0x128+0x8);
        let tex=HEADER_END;
        d.resize(tex+0x20,0);
        put(&mut d,tex+2,&[0]);
        put(&mut d,tex+16,&3u64.to_le_bytes());put(&mut d,tex+24,&0u64.to_le_bytes());
        for (i,c) in "A.t".encode_utf16().enumerate(){put(&mut d,tex+0x20+i*2,&c.to_le_bytes());}
        d.resize(tex+0x30,0);
        let mat=tex+0x30;                    // 0x660
        d.resize(mat+0x30,0);
        put(&mut d,mat+0x20,&1u64.to_le_bytes());put(&mut d,mat+0x28,&0u64.to_le_bytes());
        let layer=mat+0x30;                  // 0x690
        d.resize(layer+0x128,0);
        put(&mut d,layer,&0u16.to_le_bytes());put(&mut d,layer+2,&0xFFFFu16.to_le_bytes());
        let geo=layer+0x128;                 // geometry array
        // fix header offset of geometry: relative to 0x630
        let geo_rel=(geo-HEADER_END) as u64;
        set_ap(&mut d,0x250,1,geo_rel);
        d.resize(geo+0xC8,0);
        put(&mut d,geo+0x18,&3u32.to_le_bytes());
        put(&mut d,geo+0x1C,&12u16.to_le_bytes());
        put(&mut d,geo+0x20,&[1]);
        put(&mut d,geo+0x68,&3u32.to_le_bytes());
        put(&mut d,geo+0x80,&1u64.to_le_bytes());
        let gb=align16(geo+0xC8);
        // vertices at gb+0, indices at gb+0x30, meshes at gb+0x40
        put(&mut d,geo+0x40,&0u64.to_le_bytes());
        put(&mut d,geo+0x78,&0x30u64.to_le_bytes());
        put(&mut d,geo+0x88,&0x40u64.to_le_bytes());
        d.resize(gb+0x40+0x70,0);
        let verts=[[0f32,0.0,0.0],[1.0,0.0,0.0],[0.0,2.0,0.0]];
        for (i,v) in verts.iter().enumerate(){for k in 0..3{put(&mut d,gb+i*12+k*4,&v[k].to_le_bytes());}}
        for (i,ix) in [0u16,1,2].iter().enumerate(){put(&mut d,gb+0x30+i*2,&ix.to_le_bytes());}
        let me=gb+0x40;
        put(&mut d,me+8,&3u32.to_le_bytes());put(&mut d,me+12,&3u32.to_le_bytes());
        put(&mut d,me+0x16,&0u16.to_le_bytes());
        d
    }
    #[test]
    fn reads_geometry_textures_and_materials(){
        let m=read_m3(&sample()).unwrap();
        assert_eq!(m.vertices.len(),3);
        assert_eq!(m.triangle_count(),1);
        assert_eq!(m.meshes.len(),1);
        assert_eq!(m.textures[0].name,"A.t");
        assert_eq!(m.color_texture_of(&m.meshes[0]),Some("A.t"));
        assert_eq!(m.bounds_max,[1.0,2.0,0.0]);
        assert_eq!(m.visible_indices(),vec![0,1,2]);
    }
    #[test]
    fn rejects_bad_magic_and_truncation(){
        assert!(read_m3(b"nope").is_err());
        let d=sample();
        assert!(read_m3(&d[..d.len()-40]).is_err());
    }
    #[test]
    fn hidden_mesh_flag(){
        let mut m=read_m3(&sample()).unwrap();
        m.meshes[0].flags=0x0A;
        assert!(m.visible_indices().is_empty());
    }
    #[test]
    fn half_floats(){
        assert_eq!(half_to_f32(0x3C00),1.0);
        assert_eq!(half_to_f32(0xC000),-2.0);
    }
}
