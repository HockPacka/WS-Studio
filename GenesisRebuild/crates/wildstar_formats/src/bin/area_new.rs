//! Create a new AREA only; never overwrite existing ClientData.
use std::{env,fs::OpenOptions,io::Write,path::PathBuf};
use wildstar_formats::area::{RawArea,builder::AreaBuilder};
fn run()->Result<(),String>{
    let mut args=env::args().skip(1);
    let (mut path,mut height,mut layer)=(None::<PathBuf>,0.0f32,0u32);
    while let Some(flag)=args.next(){
        match flag.as_str(){
            "--out"=>path=Some(PathBuf::from(args.next().ok_or("missing --out filename")?)),
            "--height"=>height=args.next().ok_or("missing --height meters")?
                .parse().map_err(|_|"invalid --height")?,
            "--layer-id"=>layer=args.next().ok_or("missing --layer-id")?
                .parse().map_err(|_|"invalid --layer-id")?,
            "--help"|"-h"=>{
                println!("area_new --out <new .area> [--height meters] [--layer-id existing_WorldLayer_ID]");
                return Ok(());
            },
            _=>return Err(format!("unknown option {flag:?}")),
        }
    }
    let path=path.ok_or("missing --out")?;
    if !path.extension().and_then(|s|s.to_str())
        .is_some_and(|s|s.eq_ignore_ascii_case("area")){
        return Err("--out must end with .area".into());
    }
    let bytes=AreaBuilder::flat(height,layer).build()?;
    if RawArea::from_bytes(bytes.clone())?.cell_count()!=256{
        return Err("AREA failed round-trip validation".into());
    }
    let mut output=OpenOptions::new().write(true).create_new(true).open(&path)
        .map_err(|e|format!("cannot create new AREA at {}: {e}",path.display()))?;
    if let Err(e)=output.write_all(&bytes).and_then(|_|output.sync_all()){
        drop(output);
        let _=std::fs::remove_file(&path);
        return Err(format!("write failed: {e}"));
    }
    println!("New AREA: {} ({} bytes; 256 cells; WorldLayer ID {})",
        path.display(),bytes.len(),layer);
    Ok(())
}
fn main(){if let Err(e)=run(){eprintln!("area_new: {e}");std::process::exit(1);}}
