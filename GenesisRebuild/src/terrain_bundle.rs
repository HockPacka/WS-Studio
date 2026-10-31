//! Multi-AREA terrain export. Never overwrite source ClientData. Produce an
//! isolated folder with original AREA filenames, after all output tiles have
//! been prepared, parsed and validated in memory. This is a best-effort
//! rollback bundle, NOT an atomic multi-file transaction across crashes.
use std::{fs,io::Write,path::{Path,PathBuf}};
use std::collections::{BTreeMap,BTreeSet};
use wildstar_formats::area::{RawArea,cross_tile_write::{
    BorderSample,plan_cross_tile_border_edits,validate_cross_tile_border,
},height_border::{
    HeightBorderSample,route_source_height_edges,plan_cross_tile_height_edits,
    validate_cross_tile_heights,
}};
use wildstar_formats::zone::ZoneTileCoords;
use crate::terrain_paint::TerrainPaint;

#[derive(Default)]
struct NeighbourEdits {
    color_and_weights:Vec<BorderSample>,
    heights:Vec<HeightBorderSample>,
}

fn neighbour_source(source:&Path, coords:ZoneTileCoords)->Result<PathBuf,String>{
    let parent=source.parent().ok_or("AREA bundle: source folder unknown")?;
    let original=source.file_stem().and_then(|s|s.to_str())
        .ok_or("AREA bundle: source filename not UTF-8")?;
    let parsed=ZoneTileCoords::from_path_or_name(
        source.to_str().ok_or("AREA bundle: source path not UTF-8")?
    ).ok_or("AREA bundle: source is not a coordinate-named AREA")?;
    let hex=parsed.to_hex();
    if original.len()<4 ||
        !original[original.len()-4..].eq_ignore_ascii_case(&hex){
        return Err("AREA bundle: source filename coordinate suffix malformed".into());
    }
    let prefix=&original[..original.len()-4];
    let mut found=None::<PathBuf>;
    for entry in fs::read_dir(parent)
        .map_err(|e|format!("AREA bundle: cannot scan {}: {e}",parent.display()))?
    {
        let entry=entry.map_err(|e|e.to_string())?;
        let path=entry.path();
        if !path.is_file() ||
            !path.extension().and_then(|x|x.to_str())
                .is_some_and(|x|x.eq_ignore_ascii_case("area")) {continue;}
        let Some(stem)=path.file_stem().and_then(|s|s.to_str()) else{continue;};
        if stem.len()<4 || !stem[..stem.len()-4].eq_ignore_ascii_case(prefix){
            continue;
        }
        if ZoneTileCoords::from_path_or_name(
            path.to_str().ok_or("AREA bundle: invalid neighbor path")?
        )!=Some(coords){continue;}
        if found.is_some(){
            return Err(format!("AREA bundle: duplicate neighbour {}",coords.to_hex()));
        }
        found=Some(path);
    }
    found.ok_or_else(||format!(
        "AREA bundle: required neighbour tile {} missing; refusing unsynchronized export",
        coords.to_hex()))
}

/// Create an isolated bundle folder containing only modified AREA files.
/// The source file is *never* opened in write mode or overwritten; neighbour
/// sources are resolved by exact map prefix and four-digit ZZXX coordinates.
/// All files are fully validated before creating the bundle directory.
///
/// Handles texture/color 65th samples and 19x19 native height ghost overlap,
/// including one sample past both tile edges (-1 and 257). All eight
/// neighbours can be exported if required by the edited height vertices.
pub fn export_bundle(
    paint:&mut TerrainPaint,source:&RawArea,source_path:&Path,
    height_edits:&[(usize,usize,f32)],destination_parent:&Path,
)->Result<Vec<PathBuf>,String>{
    let source_name=source_path.file_name()
        .ok_or("AREA bundle: source filename missing")?
        .to_string_lossy().into_owned();
    let coords=ZoneTileCoords::from_path_or_name(
        source_path.to_str().ok_or("AREA bundle: source name not UTF-8")?
    ).ok_or("AREA bundle: source filename needs the native ZZXX tile suffix")?;
    let prefix=source_path.file_stem().and_then(|v|v.to_str())
        .ok_or("AREA bundle: source stem invalid")?;
    if !prefix.ends_with(&coords.to_hex()) &&
        !prefix.to_ascii_lowercase().ends_with(&coords.to_hex()){
        return Err("AREA bundle: source filename lacks verified ZZXX suffix".into());
    }
    let outgoing=paint.external_border_samples()?;
    let mut jobs=BTreeMap::<(i8,i8),NeighbourEdits>::new();
    // Texture/color edits only influence the predecessor's duplicated 65th
    // edge texel. 257x257 height edits additionally need +X/+Z neighbors:
    // a native 19x19 cell stores one ghost vertex *outside* both tile sides.
    for (slot,samples) in outgoing.iter().enumerate(){
        if samples.is_empty(){continue;}
        let offset=match slot{
            0=>(-1,0),1=>(0,-1),_=>(-1,-1),
        };
        jobs.entry(offset).or_default()
            .color_and_weights.extend_from_slice(samples);
    }
    for (offset,samples) in route_source_height_edges(height_edits)?{
        jobs.entry(offset).or_default().heights.extend(samples);
    }
    // Validate source before reading any neighbouring tile or writing files.
    let (base_bytes,_cells)=paint.build_native_bytes(source,height_edits)?;
    let mut outputs=vec![(source_name,base_bytes)];
    for ((dx,dz),requests) in &jobs{
        let x=match dx {
            -1=>coords.x.checked_sub(1),
            1=>coords.x.checked_add(1),
            _=>Some(coords.x),
        }.ok_or("AREA bundle: neighbour X coordinate outside map")?;
        let z=match dz {
            -1=>coords.z.checked_sub(1),
            1=>coords.z.checked_add(1),
            _=>Some(coords.z),
        }.ok_or("AREA bundle: neighbour Z coordinate outside map")?;
        let destination=ZoneTileCoords::new(z,x);
        let path=neighbour_source(source_path,destination)?;
        let neighbor=RawArea::from_path(&path).map_err(|e|
            format!("AREA bundle: cannot decode {}: {e}",path.display()))?;
        // Process both edit families without duplicate Bit 0/3/17 blocks.
        let color_plan=plan_cross_tile_border_edits(
            &neighbor,&requests.color_and_weights)?;
        let color_bytes=neighbor.with_cell_block_changes(&color_plan)?;
        let color_stage=RawArea::from_bytes(color_bytes)?;
        let height_plan=plan_cross_tile_height_edits(
            &color_stage,&requests.heights)?;
        let bytes=color_stage.with_cell_block_changes(&height_plan)?;
        let reread=RawArea::from_bytes(bytes.clone())?;
        if reread.cell_count()!=neighbor.cell_count() ||
            reread.prop_count()!=neighbor.prop_count(){
            return Err("AREA bundle: neighbor cell or prop count changed".into());
        }
        validate_cross_tile_border(
            &neighbor,&reread,&requests.color_and_weights)?;
        validate_cross_tile_heights(&reread,&requests.heights)?;
        let name=path.file_name().ok_or("AREA bundle: neighbour name missing")?
            .to_string_lossy().into_owned();
        outputs.push((name,bytes));
    }
    let mut unique=BTreeSet::new();
    if outputs.iter().any(|(name,_)|!unique.insert(name.to_ascii_lowercase())){
        return Err("AREA bundle: output filenames collide".into());
    }
    // The destination is always a new directory, so it cannot be confused
    // with a game's native Map directory nor replace any existing files.
    let bundle_root=destination_parent.join(format!(
        "{}_GenesisBundle",source_path.file_stem()
            .and_then(|v|v.to_str()).unwrap_or("Terrain")
    ));
    if bundle_root.exists(){
        return Err(format!(
            "AREA bundle: {} already exists; choose an unused output location",
            bundle_root.display()
        ));
    }
    fs::create_dir(&bundle_root).map_err(|e|
        format!("AREA bundle: cannot create {}: {e}",bundle_root.display()))?;
    let mut created=Vec::new();
    let result=(||->Result<(),String>{
        for (name,bytes) in &outputs{
            let path=bundle_root.join(name);
            let mut file=fs::OpenOptions::new().write(true).create_new(true)
                .open(&path).map_err(|e|format!(
                    "AREA bundle: cannot create {}: {e}",path.display()
                ))?;
            created.push(path.clone());
            file.write_all(bytes).and_then(|_|file.sync_all())
                .map_err(|e|format!("AREA bundle: write failed at {}: {e}",path.display()))?;
        }
        Ok(())
    })();
    if let Err(err)=result {
        // Best-effort rollback only for files created by this operation.
        for path in created {let _=fs::remove_file(path);}
        let _=fs::remove_dir(&bundle_root);
        return Err(err);
    }
    Ok(outputs.iter().map(|(name,_)|bundle_root.join(name)).collect())
}
