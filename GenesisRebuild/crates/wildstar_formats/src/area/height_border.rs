//! Lossless in-layout height ghost synchronization across WildStar AREA files.
//! A native cell stores 19x19 u16 samples: cell origin -1 through +17 in
//! global 257x257 vertex coordinates. Adjacent tiles therefore overlap by two
//! ghost samples. No file writes or guessing of missing geometry.
use super::RawArea;
use std::collections::{BTreeMap,BTreeSet};

#[derive(Clone,Copy,Debug,PartialEq)]
pub struct HeightBorderSample{
    /// Neighbor AREA coordinates, allowing the one-sample padding -1 and 257.
    pub x:i32,
    pub z:i32,
    pub height:f32,
}
pub fn quantize_height(height:f32)->Result<u16,String>{
    if !height.is_finite(){
        return Err("AREA height seam: non-finite height".into());
    }
    // Exactly the same native u16 transform as RawArea::with_height_changes.
    Ok(((height+2048.0)*8.0).round().clamp(0.0,65535.0) as u16)
}
fn is_ghost_boundary(v:i32)->bool{
    matches!(v,-1|0|256|257)
}
fn sample_position(index:usize,rx:usize,rz:usize)->(i32,i32){
    ((index%16*16+rx) as i32-1,(index/16*16+rz) as i32-1)
}
/// Return exact-size native Bit 0 replacements. Only accepts target samples
/// on a tile's exterior border (including the -1 and +257 ghost margin);
/// the neighbouring tile's ordinary interior is never edited.
///
/// All stored copies of a vertex are updated, including the row/column
/// overlap of 19x19 cell blocks. This is independent from the public 0..256
/// height writer and never needs to fabricate a new flag or block.
pub fn plan_cross_tile_height_edits(
    area:&RawArea,samples:&[HeightBorderSample]
)->Result<Vec<(usize,usize,Vec<u8>)>,String>{
    let mut expected=BTreeMap::<(i32,i32),u16>::new();
    for sample in samples {
        if !(-1..=257).contains(&sample.x) ||
            !(-1..=257).contains(&sample.z) ||
            !(is_ghost_boundary(sample.x)||is_ghost_boundary(sample.z)){
            return Err(format!(
                "AREA height seam: ({},{}) is not a neighbour border",sample.x,sample.z
            ));
        }
        let value=quantize_height(sample.height)?;
        if expected.insert((sample.x,sample.z),value).is_some(){
            return Err("AREA height seam: duplicate requested sample".into());
        }
    }
    let mut seen=BTreeSet::new();
    let mut patches=Vec::new();
    for cell in area.cells.iter().flatten(){
        let Some(original)=cell.block(0) else{continue;};
        if original.len()!=19*19*2{
            return Err(format!("AREA height seam: cell {} malformed bit0",cell.index));
        }
        let mut bytes=original.to_vec();
        let mut dirty=false;
        for rz in 0..19 {
            for rx in 0..19 {
                let key=sample_position(cell.index,rx,rz);
                let Some(&raw)=expected.get(&key) else{continue;};
                seen.insert(key);
                let offset=(rz*19+rx)*2;
                let next=raw.to_le_bytes();
                if bytes[offset..offset+2]!=next {
                    bytes[offset..offset+2].copy_from_slice(&next);
                    dirty=true;
                }
            }
        }
        if dirty{patches.push((cell.index,0,bytes));}
    }
    if seen.len()!=expected.len(){
        let missing=expected.keys().find(|key|!seen.contains(key)).unwrap();
        return Err(format!(
            "AREA height seam: missing target sample ({},{})",missing.0,missing.1
        ));
    }
    Ok(patches)
}
/// Ensure that *every stored alias* of a requested ghost vertex carries the
/// newly encoded native u16, not merely the first visible mesh sample.
pub fn validate_cross_tile_heights(
    area:&RawArea,samples:&[HeightBorderSample]
)->Result<(),String>{
    let mut seen=BTreeSet::new();
    for sample in samples{
        let raw=quantize_height(sample.height)?.to_le_bytes();
        for cell in area.cells.iter().flatten(){
            let Some(block)=cell.block(0) else{continue;};
            if block.len()!=19*19*2{
                return Err("AREA height seam: malformed output height block".into());
            }
            for rz in 0..19{
                for rx in 0..19{
                    if sample_position(cell.index,rx,rz)!=(sample.x,sample.z){continue;}
                    let offset=(rz*19+rx)*2;
                    if block[offset..offset+2]!=raw{
                        return Err(format!("AREA height seam: mismatch at cell {} ({},{})",
                            cell.index,sample.x,sample.z));
                    }
                    seen.insert((sample.x,sample.z));
                }
            }
        }
        if !seen.contains(&(sample.x,sample.z)){
            return Err("AREA height seam: output vertex unavailable".into());
        }
    }
    Ok(())
}

#[cfg(test)]
mod tests{
    use super::*;
    use super::super::AreaCell;
    fn cell(index:usize)->AreaCell{
        let mut blocks=vec![None;32];
        blocks[0]=Some(vec![0x10;19*19*2]);
        AreaCell{index,flags:1,blocks,subchunks:Vec::new()}
    }
    fn area(indices:&[usize])->RawArea{
        let mut cells=vec![None;256];
        for &index in indices{cells[index]=Some(cell(index));}
        RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None}
    }
    #[test]
    fn extends_height_seams_to_minus_one_and_plus_257(){
        let source=area(&[0,15,31,255]);
        let samples=[
            HeightBorderSample{x:-1,z:0,height:16.375},
            HeightBorderSample{x:256,z:16,height:19.125},
            HeightBorderSample{x:257,z:257,height:-2.625},
        ];
        let edits=plan_cross_tile_height_edits(&source,&samples).unwrap();
        assert_eq!(edits.len(),4);
        let mut result=source.clone();
        for (index,bit,bytes) in edits{
            assert_eq!(bit,0);
            result.cells[index].as_mut().unwrap().blocks[0]=Some(bytes);
        }
        validate_cross_tile_heights(&result,&samples).unwrap();
        assert_eq!(result.cells[15].as_ref().unwrap().height(16,16),Some(19.125));
        assert_eq!(result.cells[31].as_ref().unwrap().height(16,0),Some(19.125));
        assert_eq!(result.cells[0].as_ref().unwrap().height(0,0),Some(0x1010 as f32*0.125-2048.0));
        assert_eq!(result.cells[255].as_ref().unwrap().height(16,16),
            Some(0x1010 as f32*0.125-2048.0));
    }
    #[test]
    fn rejects_bad_coordinates_duplicate_and_unrepresented_vertices(){
        let source=area(&[0]);
        for sample in [
            HeightBorderSample{x:5,z:5,height:1.0},
            HeightBorderSample{x:258,z:0,height:1.0},
            HeightBorderSample{x:-2,z:0,height:1.0},
            HeightBorderSample{x:0,z:0,height:f32::NAN},
        ]{
            assert!(plan_cross_tile_height_edits(&source,&[sample]).is_err());
        }
        let valid=HeightBorderSample{x:-1,z:0,height:5.0};
        assert!(plan_cross_tile_height_edits(&source,&[valid,valid]).is_err());
        assert!(plan_cross_tile_height_edits(&source,&[
            HeightBorderSample{x:257,z:0,height:3.0}
        ]).unwrap_err().contains("missing target sample"));
    }
}
