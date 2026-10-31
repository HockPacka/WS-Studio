//! `cargo run -p wildstar_formats --example dump_model -- <file.m3|file.i3>`
use wildstar_formats::{i3,m3};
fn main(){
    let path=std::env::args().nth(1).expect("usage: dump_model <file.m3|file.i3>");
    let d=std::fs::read(&path).expect("read file");
    if m3::is_m3(&d){
        match m3::read_m3(&d){
            Ok(m)=>{
                println!("M3 {} verts, {} tris, {} meshes ({} hidden), {} bones, {} clips",
                    m.vertices.len(),m.triangle_count(),m.meshes.len(),
                    m.meshes.iter().filter(|x|x.is_hidden()).count(),m.bones.len(),m.clips.len());
                println!("bounds {:?} .. {:?}",m.bounds_min,m.bounds_max);
                for (i,t) in m.textures.iter().enumerate(){println!("tex[{i}] kind {} {}",t.kind,t.name);}
                for (i,x) in m.materials.iter().enumerate(){
                    println!("material[{i}] blend {:?} type {} flags {:#x} opacity {} gloss {} glow {} colorMod {:?} color {:?} normal {:?}",
                        x.blend,x.material_type,x.flags,x.opacity,x.gloss,x.glow,x.color_mod,x.color_texture,x.normal_texture);
                }
                for me in &m.meshes{println!("mesh mat {} tex {:?} idx {}",me.material,m.color_texture_of(me),me.index_count);}
            }
            Err(e)=>{eprintln!("M3 error: {e}");std::process::exit(1);}
        }
    }else if i3::is_sector(&d){
        let s=i3::read_sector(&d).unwrap_or_else(|e|{eprintln!("FEDS error: {e}");std::process::exit(1)});
        println!("FEDS {} '{}' {} verts {} tris {} submeshes",path,s.name,s.positions.len(),s.triangle_count(),s.submeshes.len());
    }else if i3::is_model(&d){
        let m=i3::read_model(&d).unwrap_or_else(|e|{eprintln!("FEDI error: {e}");std::process::exit(1)});
        println!("FEDI sectors {:?} exterior {:?} portals {} sets {}",m.sectors,m.sector_exterior,m.portals.len(),m.sets.len());
        for s in &m.sets{println!("set '{}' {} textures {} passes",s.name,s.textures.len(),s.passes.len());}
    }else{eprintln!("unknown format");std::process::exit(2);}
}
