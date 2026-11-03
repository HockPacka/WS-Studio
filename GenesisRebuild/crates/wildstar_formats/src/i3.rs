//! Native reader for WildStar `.i3` structure files.
//!   `FEDS` (version 30): sector file `<Model>.<Sector>.i3` - the triangles
//!   `FEDI` (version 41): model file  `<Model>.i3`          - materials, textures, sector list
//! Format: WS-Tools `docs/i3_dgn_format.md`, reference `Struct3/I3Reader.cpp`.
use crate::binary::*;

const SECTOR_HEADER:usize=0x1B0;
const MODEL_HEADER:usize=0x170;

#[derive(Debug,Clone,Copy)]
pub struct SectorSubmesh {
    pub kind:u32,
    /// Inclusive ranges into `SectorMesh::indices` / vertices.
    pub first_index:u32,pub last_index:u32,
    pub first_vertex:u32,pub last_vertex:u32,
    /// `(material number + 1) << 8 | material set slot`
    pub id:u32,
}
impl SectorSubmesh {
    pub fn material(&self)->Option<usize>{
        let hi=self.id>>8;
        if hi==0||self.id&0xFF==0xFF{None}else{Some(hi as usize-1)}
    }
    /// Low byte selects the material pass; 0xFF is collision-only.
    pub fn pass(&self)->Option<usize>{self.material().map(|_|(self.id&0xFF) as usize)}
    /// `hi == 0` or `lo == 255` is collision geometry only.
    pub fn is_collision_only(&self)->bool{self.material().is_none()}
    pub fn triangles(&self)->std::ops::Range<usize>{
        self.first_index as usize/3..(self.last_index as usize+1)/3
    }
}
#[derive(Debug,Clone,Default)]
pub struct SectorMesh {
    pub name:String,
    pub bbox_min:[f32;3],pub bbox_max:[f32;3],
    pub positions:Vec<[f32;3]>,
    pub normals:Vec<[f32;3]>,
    pub uv0:Vec<[f32;2]>,
    pub uv1:Vec<[f32;2]>,
    pub colors:Vec<[u8;4]>,
    pub indices:Vec<u32>,
    pub tri_flags:Vec<u16>,
    pub submeshes:Vec<SectorSubmesh>,
}
impl SectorMesh {
    pub fn triangle_count(&self)->usize{self.indices.len()/3}
}
#[derive(Debug,Clone,Copy,Default)]
pub struct I3Material {
    pub color_tex:u16,pub normal_tex:u16,
    /// 0 normal, 3 / 5 special (decal / emissive).
    pub kind:u16,
}
#[derive(Debug,Clone,Default)]
pub struct I3Pass { pub materials:Vec<I3Material> }
/// Variant of the model ("Default_Pass", "Aurin_Autumn", ...).
#[derive(Debug,Clone,Default)]
pub struct I3MaterialSet {
    pub name:String,
    pub textures:Vec<String>,
    pub passes:Vec<I3Pass>,
}
impl I3MaterialSet {
    pub fn color_texture(&self,pass:usize,material:usize)->Option<&str>{
        let m=self.passes.get(pass)?.materials.get(material)?;
        if m.color_tex==0xFFFF{return None;}
        self.textures.get(m.color_tex as usize).map(String::as_str)
    }
}
/// Opening between two sectors, transformed into model space.
#[derive(Debug,Clone,Default)]
pub struct I3Portal {
    pub sector_a:usize,pub sector_b:usize,
    pub vertices:Vec<[f32;3]>,
    pub indices:Vec<u16>,
}
#[derive(Debug,Clone,Default)]
pub struct I3Model {
    pub bbox_min:[f32;3],pub bbox_max:[f32;3],
    pub names:Vec<String>,
    /// Sector names; the file of a sector is `<model without .i3>.<sector>.i3`.
    pub sectors:Vec<String>,
    pub sector_exterior:Vec<bool>,
    pub portals:Vec<I3Portal>,
    pub sets:Vec<I3MaterialSet>,
}
impl I3Model {
    /// Virtual file name of a sector, e.g. `Art\X\Wall.i3` + `Sector_Exterior` -> `Art\X\Wall.Sector_Exterior.i3`.
    pub fn sector_path(&self,model_path:&str,sector:usize)->Option<String>{
        let name=self.sectors.get(sector)?;
        let stem=model_path.strip_suffix(".i3").or_else(||model_path.strip_suffix(".I3")).unwrap_or(model_path);
        Some(format!("{stem}.{name}.i3"))
    }
}

pub fn is_sector(d:&[u8])->bool{d.len()>=SECTOR_HEADER&&&d[..4]==b"FEDS"&&u32_at(d,4)==Some(30)}
pub fn is_model(d:&[u8])->bool{d.len()>=MODEL_HEADER&&&d[..4]==b"FEDI"&&u32_at(d,4)==Some(41)}

/// `{u32 count, u32 pad, u64 offset}`
fn slot(d:&[u8],at:usize)->(u32,u64){(u32_at(d,at).unwrap_or(0),u64_at(d,at+8).unwrap_or(0))}
fn vec3(d:&[u8],at:usize)->[f32;3]{[f32_at(d,at).unwrap_or(0.0),f32_at(d,at+4).unwrap_or(0.0),f32_at(d,at+8).unwrap_or(0.0)]}

pub fn read_sector(d:&[u8])->Result<SectorMesh,String>{
    if !is_sector(d){return Err("not a FEDS v30 file".into());}
    let len=d.len();
    let h=SECTOR_HEADER;
    let (nc,no)=slot(d,0x20);
    let (pc,po)=slot(d,0x38);
    let (ac,ao)=slot(d,0x48);
    let (ic,io)=slot(d,0x58);
    let (tc,to)=slot(d,0x68);
    let (sc,so)=slot(d,0x78);
    let mut out=SectorMesh::default();
    if let Some(at)=range(len,h,no,nc as u64,2){out.name=utf16(d,at,nc as usize);}
    out.bbox_min=vec3(d,0x120);out.bbox_max=vec3(d,0x130);

    let pa=range(len,h,po,pc as u64,12).ok_or("positions beyond file")?;
    out.positions=(0..pc as usize).map(|i|vec3(d,pa+i*12)).collect();
    if ac!=pc{return Err("vertex attributes mismatch".into());}
    let aa=range(len,h,ao,ac as u64,20).ok_or("vertex attributes mismatch")?;
    for i in 0..pc as usize{
        let v=aa+i*20;
        // Octahedral normal: x = byte 6, y = byte 5.
        let mut x=d[v+6] as f32/255.0*2.0-1.0;
        let mut y=d[v+5] as f32/255.0*2.0-1.0;
        let z=1.0-x.abs()-y.abs();
        let t=(-z).max(0.0);
        x+=if x>=0.0{-t}else{t};
        y+=if y>=0.0{-t}else{t};
        let l=(x*x+y*y+z*z).sqrt()+1e-12;
        out.normals.push([x/l,y/l,z/l]);
        let h16=|o:usize|half_to_f32(u16_at(d,v+o).unwrap_or(0));
        out.uv0.push([h16(8),h16(10)]);
        out.uv1.push([h16(12),h16(14)]);
        out.colors.push([d[v+16],d[v+17],d[v+18],d[v+19]]);
    }

    if ic%3!=0{return Err("indices beyond file".into());}
    let ia=range(len,h,io,ic as u64,4).ok_or("indices beyond file")?;
    out.indices=(0..ic as usize).map(|i|u32_at(d,ia+i*4).unwrap_or(0)).collect();
    if out.indices.iter().any(|&i|i>=pc){return Err("index out of range".into());}
    if tc>0{
        if let Some(at)=range(len,h,to,tc as u64,2){
            out.tri_flags=(0..tc as usize).map(|i|u16_at(d,at+i*2).unwrap_or(0)).collect();
        }
    }

    let sa=range(len,h,so,sc as u64,28).ok_or("submeshes beyond file")?;
    for i in 0..sc as usize{
        let r=sa+i*28;
        let s=SectorSubmesh{
            kind:u32_at(d,r).unwrap_or(0),first_index:u32_at(d,r+4).unwrap_or(0),
            last_index:u32_at(d,r+8).unwrap_or(0),first_vertex:u32_at(d,r+12).unwrap_or(0),
            last_vertex:u32_at(d,r+16).unwrap_or(0),id:u32_at(d,r+20).unwrap_or(0),
        };
        if s.last_index>=ic||s.first_index>s.last_index+1||s.last_vertex>=pc{
            return Err("submesh range out of bounds".into());
        }
        out.submeshes.push(s);
    }
    Ok(out)
}

fn rotate(q:[f32;4],v:[f32;3])->[f32;3]{
    let tx=2.0*(q[1]*v[2]-q[2]*v[1]);
    let ty=2.0*(q[2]*v[0]-q[0]*v[2]);
    let tz=2.0*(q[0]*v[1]-q[1]*v[0]);
    [v[0]+q[3]*tx+(q[1]*tz-q[2]*ty),v[1]+q[3]*ty+(q[2]*tx-q[0]*tz),v[2]+q[3]*tz+(q[0]*tx-q[1]*ty)]
}

pub fn read_model(d:&[u8])->Result<I3Model,String>{
    if !is_model(d){return Err("not a FEDI v41 file".into());}
    let len=d.len();
    let h=MODEL_HEADER;
    let mut out=I3Model{bbox_min:vec3(d,0x140),bbox_max:vec3(d,0x150),..Default::default()};
    let (pc,po)=slot(d,0x120);
    let (nc,no)=slot(d,0x130);
    let (sc,so)=slot(d,0x20);
    let (mc,mo)=slot(d,0x40);
    let err="arrays beyond file";
    let pool=range(len,h,po,pc as u64,2).ok_or(err)?;
    let names=range(len,h,no,nc as u64,4).ok_or(err)?;
    let sectors=range(len,h,so,sc as u64,0x40).ok_or(err)?;
    let sets=range(len,h,mo,mc as u64,0x58).ok_or(err)?;

    for i in 0..nc as usize{
        let chars=u32_at(d,names+4*i).unwrap_or(u32::MAX);
        out.names.push(if chars<pc{utf16(d,pool+2*chars as usize,(pc-chars) as usize)}else{String::new()});
    }
    for i in 0..sc as usize{
        let r=sectors+0x40*i;
        let n=u32_at(d,r).unwrap_or(u32::MAX) as usize;
        out.sectors.push(out.names.get(n).cloned().ok_or("sector name index")?);
        out.sector_exterior.push(u32_at(d,r+0x30).unwrap_or(0)!=0);
    }

    // Portals: stored twice (a -> b and b -> a); the first of each pair is kept.
    let (pcnt,poff)=slot(d,0x30);
    if let Some(at)=range(len,h,poff,pcnt as u64,0x90).filter(|_|pcnt>0){
        let child=at+align16(pcnt as usize*0x90);
        for i in 0..pcnt as usize{
            let r=at+i*0x90;
            let a=u16_at(d,r+4).unwrap_or(0xFFFF) as usize;
            let b=u16_at(d,r+6).unwrap_or(0xFFFF) as usize;
            if a>=sc as usize||b>=sc as usize||a==b{continue;}
            let (vc,vo)=slot(d,r+0x40);
            let (xc,xo)=slot(d,r+0x50);
            let (Some(va),Some(xa))=(range(len,child,vo,vc as u64,16),range(len,child,xo,xc as u64,2)) else{continue;};
            if vc<3||vc>65535||xc<3||xc%3!=0{continue;}
            let pos=vec3(d,r+0x10);
            let scale=vec3(d,r+0x20);
            let mut q=[0f32;4];
            for k in 0..4{q[k]=f32_at(d,r+0x30+k*4).unwrap_or(0.0);}
            let qn=q.iter().map(|v|v*v).sum::<f32>().sqrt();
            if !qn.is_finite()||qn<1e-6||scale.iter().any(|s|s.abs()<1e-8){continue;}
            for v in &mut q{*v/=qn;}
            let indices:Vec<u16>=(0..xc as usize).map(|k|u16_at(d,xa+k*2).unwrap_or(0)).collect();
            if indices.iter().any(|&k|k as u32>=vc){continue;}
            let vertices:Vec<[f32;3]>=(0..vc as usize).map(|k|{
                let v=vec3(d,va+16*k);
                let w=rotate(q,[v[0]*scale[0],v[1]*scale[1],v[2]*scale[2]]);
                [w[0]+pos[0],w[1]+pos[1],w[2]+pos[2]]
            }).collect();
            let near=|p:&[f32;3],o:&[f32;3]|(p[0]-o[0]).abs()+(p[1]-o[1]).abs()+(p[2]-o[2]).abs()<1e-3;
            let mirrored=out.portals.iter().any(|o|o.sector_a==b&&o.sector_b==a&&o.vertices.len()==vertices.len()
                &&vertices.iter().all(|v|o.vertices.iter().any(|w|near(v,w))));
            if !mirrored{out.portals.push(I3Portal{sector_a:a,sector_b:b,vertices,indices});}
        }
    }

    let child=sets+align16(mc as usize*0x58);
    for i in 0..mc as usize{
        let r=sets+i*0x58;
        let (nmc,nmo)=slot(d,r+0x08);
        let (pac,pao)=slot(d,r+0x18);
        let (txc,txo)=slot(d,r+0x38);
        let mut set=I3MaterialSet::default();
        if nmc>0{if let Some(at)=range(len,child,nmo,nmc as u64,2){set.name=utf16(d,at,nmc as usize);}}
        let err="material set arrays beyond file";
        let pass_at=range(len,child,pao,pac as u64,0x28).ok_or(err)?;
        let tex_at=range(len,child,txo,txc as u64,0x20).ok_or(err)?;
        let strings=tex_at+txc as usize*0x20;
        for t in 0..txc as usize{
            let (pc2,po2)=slot(d,tex_at+t*0x20+0x10);
            let at=range(len,strings,po2,pc2 as u64,2).ok_or("texture path beyond file")?;
            set.textures.push(if pc2>0{utf16(d,at,pc2 as usize)}else{String::new()});
        }
        let pass_child=pass_at+align16(pac as usize*0x28);
        for q in 0..pac as usize{
            let (mcnt,moff)=slot(d,pass_at+q*0x28+0x18);
            let mat_at=range(len,pass_child,moff,mcnt as u64,0x128).ok_or("materials beyond file")?;
            let materials=(0..mcnt as usize).map(|m|{
                let mr=mat_at+m*0x128;
                I3Material{color_tex:u16_at(d,mr).unwrap_or(0xFFFF),normal_tex:u16_at(d,mr+2).unwrap_or(0xFFFF),
                    kind:u16_at(d,mr+8).unwrap_or(0)}
            }).collect();
            set.passes.push(I3Pass{materials});
        }
        out.sets.push(set);
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;
    fn put(d:&mut Vec<u8>,at:usize,b:&[u8]){
        if d.len()<at+b.len(){d.resize(at+b.len(),0);}
        d[at..at+b.len()].copy_from_slice(b);
    }
    fn set_slot(d:&mut Vec<u8>,at:usize,count:u32,off:u64){
        put(d,at,&count.to_le_bytes());put(d,at+8,&off.to_le_bytes());
    }
    fn sector()->Vec<u8>{
        let mut d=vec![0u8;SECTOR_HEADER];
        d[..4].copy_from_slice(b"FEDS");d[4..8].copy_from_slice(&30u32.to_le_bytes());
        // name(3 UTF-16) @0, pos(3*12) @8, attr(3*20) @48, index(3*4) @108, submesh(28) @120
        set_slot(&mut d,0x20,3,0);set_slot(&mut d,0x38,3,8);set_slot(&mut d,0x48,3,48);
        set_slot(&mut d,0x58,3,108);set_slot(&mut d,0x78,1,120);
        for (i,c) in "Abc".encode_utf16().enumerate(){put(&mut d,SECTOR_HEADER+i*2,&c.to_le_bytes());}
        let pos=[[0f32,0.0,0.0],[1.0,0.0,0.0],[0.0,1.0,0.0]];
        for (i,p) in pos.iter().enumerate(){for k in 0..3{put(&mut d,SECTOR_HEADER+8+i*12+k*4,&p[k].to_le_bytes());}}
        for i in 0..3{
            let v=SECTOR_HEADER+48+i*20;
            put(&mut d,v,&[0;20]);
            d[v+5]=128;d[v+6]=128;
            put(&mut d,v+8,&0x3C00u16.to_le_bytes());
        }
        for i in 0..3u32{put(&mut d,SECTOR_HEADER+108+i as usize*4,&i.to_le_bytes());}
        let s=SECTOR_HEADER+120;
        put(&mut d,s+8,&2u32.to_le_bytes());put(&mut d,s+16,&2u32.to_le_bytes());
        put(&mut d,s+20,&0x0100u32.to_le_bytes());put(&mut d,s+27,&[0]);
        put(&mut d,0x130,&1f32.to_le_bytes());
        d
    }
    #[test]
    fn reads_sector_triangles(){
        let s=read_sector(&sector()).unwrap();
        assert_eq!(s.name,"Abc");
        assert_eq!(s.positions.len(),3);
        assert_eq!(s.triangle_count(),1);
        assert_eq!(s.uv0[0][0],1.0);
        assert_eq!(s.submeshes[0].material(),Some(0));
        assert_eq!(s.submeshes[0].triangles(),0..1);
        let n=s.normals[0];
        assert!(((n[0]*n[0]+n[1]*n[1]+n[2]*n[2])-1.0).abs()<1e-4);
    }
    #[test]
    fn sector_rejects_bad_index(){
        let mut d=sector();
        put(&mut d,SECTOR_HEADER+108,&9u32.to_le_bytes());
        assert!(read_sector(&d).is_err());
        assert!(read_sector(b"FEDS").is_err());
    }
    #[test]
    fn material_and_pass_are_separate_fields(){
        let s=SectorSubmesh{kind:0,first_index:0,last_index:2,
            first_vertex:0,last_vertex:2,id:(3<<8)|1};
        assert_eq!(s.material(),Some(2));
        assert_eq!(s.pass(),Some(1));
        assert!(!s.is_collision_only());
        let collision=SectorSubmesh{id:(3<<8)|0xFF,..s};
        assert_eq!(collision.material(),None);
        assert_eq!(collision.pass(),None);
    }
    #[test]
    fn collision_only_submesh(){
        let s=SectorSubmesh{kind:0,first_index:0,last_index:2,first_vertex:0,last_vertex:2,id:0x01FF};
        assert!(s.is_collision_only());
    }
    #[test]
    fn model_sector_names_and_paths(){
        let mut d=vec![0u8;MODEL_HEADER];
        d[..4].copy_from_slice(b"FEDI");d[4..8].copy_from_slice(&41u32.to_le_bytes());
        // pool "Sector_Exterior\0" (16 chars) @0, names[1] @32, sectors[1] (0x40) @48
        set_slot(&mut d,0x120,16,0);set_slot(&mut d,0x130,1,32);set_slot(&mut d,0x20,1,48);
        set_slot(&mut d,0x30,0,0);set_slot(&mut d,0x40,0,200);
        for (i,c) in "Sector_Exterior".encode_utf16().enumerate(){put(&mut d,MODEL_HEADER+i*2,&c.to_le_bytes());}
        put(&mut d,MODEL_HEADER+32,&0u32.to_le_bytes());
        put(&mut d,MODEL_HEADER+48+0x30,&1u32.to_le_bytes());
        d.resize(MODEL_HEADER+300,0);
        let m=read_model(&d).unwrap();
        assert_eq!(m.sectors,vec!["Sector_Exterior"]);
        assert_eq!(m.sector_exterior,vec![true]);
        assert_eq!(m.sector_path("Art\\X\\Wall.i3",0).unwrap(),"Art\\X\\Wall.Sector_Exterior.i3");
    }
}
