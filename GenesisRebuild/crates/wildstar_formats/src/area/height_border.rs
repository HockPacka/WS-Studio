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
/// Route modified source 257x257 height vertices to neighboring AREA tiles.
/// The 19x19 native cell stores one extra sample outside each side of a tile:
/// source x=0/1 => left neighbor x=256/257, x=255/256 => right -1/0.
/// The same applies to z and to all four diagonal neighbors.
/// Returns (tile delta X, tile delta Z) -> target extended samples.
pub fn route_source_height_edges(
    changes:&[(usize,usize,f32)]
)->Result<BTreeMap<(i8,i8),Vec<HeightBorderSample>>,String>{
    let mut routed=BTreeMap::<(i8,i8),Vec<HeightBorderSample>>::new();
    let mut seen=BTreeSet::new();
    for &(x,z,height) in changes{
        if x>256 || z>256 {
            return Err("AREA height seam: source vertex outside 257x257 grid".into());
        }
        quantize_height(height)?;
        if !seen.insert((x,z)) {
            return Err("AREA height seam: duplicate source height vertex".into());
        }
        let mut x_offsets=Vec::new();
        let mut z_offsets=Vec::new();
        if x<=1{x_offsets.push(-1i8);}
        if x>=255{x_offsets.push(1i8);}
        if z<=1{z_offsets.push(-1i8);}
        if z>=255{z_offsets.push(1i8);}
        for &dx in &x_offsets{
            routed.entry((dx,0)).or_default().push(HeightBorderSample{
                x:x as i32-dx as i32*256,z:z as i32,height,
            });
        }
        for &dz in &z_offsets{
            routed.entry((0,dz)).or_default().push(HeightBorderSample{
                x:x as i32,z:z as i32-dz as i32*256,height,
            });
        }
        for &dx in &x_offsets{
            for &dz in &z_offsets{
                routed.entry((dx,dz)).or_default().push(HeightBorderSample{
                    x:x as i32-dx as i32*256,
                    z:z as i32-dz as i32*256,height,
                });
            }
        }
    }
    Ok(routed)
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
    fn routes_visible_and_ghost_samples_to_all_eight_adjacent_tiles(){
        let changes=[
            (0usize,0usize,11.0f32),
            (1,1,12.0),
            (255,255,13.0),
            (256,256,14.0),
            (0,256,16.0), // bottom-left -> upper/right diagonal neighbours
            (256,0,17.0), // top-right -> lower/left diagonal neighbours
            (7,129,15.0),
        ];
        let mapped=route_source_height_edges(&changes).unwrap();
        assert_eq!(mapped.len(),8);
        for &(x,z,h) in &[
            (256,256,11.0),(257,257,12.0)
        ]{
            assert!(mapped[&(-1,-1)].contains(&HeightBorderSample{x,z,height:h}));
        }
        assert!(mapped[&(1,1)].contains(&HeightBorderSample{
            x:-1,z:-1,height:13.0,
        }));
        assert!(mapped[&(1,1)].contains(&HeightBorderSample{
            x:0,z:0,height:14.0,
        }));
        assert!(mapped[&(-1,0)].contains(&HeightBorderSample{
            x:263,z:129,height:15.0,
        })==false); // non-ghost x=7 must not be copied
        assert_eq!(route_source_height_edges(&[(7,7,3.0)]).unwrap().len(),0);
        assert!(route_source_height_edges(&[(257,0,0.0)]).is_err());
        assert!(route_source_height_edges(&[(0,0,1.0),(0,0,2.0)]).is_err());
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
    fn height_border_roundtrips_raw_and_zlib_area_with_unknown_chunk_preserved(){
        use flate2::{Compression,write::ZlibEncoder};
        use std::io::Write;
        let mut payload=1u32.to_le_bytes().to_vec();
        payload.extend(vec![0x10u8;19*19*2]);
        for compressed in [false,true]{
            let mut stream=Vec::new();
            let zip=|raw:&[u8]|{
                let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
                enc.write_all(raw).unwrap();
                enc.finish().unwrap()
            };
            if compressed{
                stream.extend(3u32.to_le_bytes());
                stream.extend(zip(b"LOD"));
            }
            let mut last=0usize;
            for index in [0usize,15,31,255]{
                let delta=index-last;
                let word=((delta as u32)<<24)|(payload.len() as u32);
                stream.extend(word.to_le_bytes());
                if compressed{stream.extend(zip(&payload));}
                else{stream.extend(&payload);}
                last=index+1;
            }
            let mut file=if compressed{b"AERA".to_vec()}else{b"aera".to_vec()};
            file.extend(0u32.to_le_bytes());
            file.extend(b"KNHC");
            file.extend((stream.len() as u32).to_le_bytes());
            file.extend(stream);
            file.extend(b"KEEP");
            file.extend(3u32.to_le_bytes());
            file.extend(b"XYZ");
            let original=RawArea::from_bytes(file).unwrap();
            let samples=[
                HeightBorderSample{x:-1,z:0,height:16.375},
                HeightBorderSample{x:256,z:16,height:19.125},
                HeightBorderSample{x:257,z:257,height:-2.625},
            ];
            let plan=plan_cross_tile_height_edits(&original,&samples).unwrap();
            assert_eq!(plan.len(),4);
            let data=original.with_cell_block_changes(&plan).unwrap();
            let exported=RawArea::from_bytes(data).unwrap();
            validate_cross_tile_heights(&exported,&samples).unwrap();
            assert_eq!(exported.cell_count(),original.cell_count());
            assert_eq!(exported.chunks[1].data,b"XYZ");
            if compressed{assert_eq!(exported.lod_prefix,Some(b"LOD".to_vec()));}
            assert_eq!(original.cells[0].as_ref().unwrap().height(0,0),
                exported.cells[0].as_ref().unwrap().height(0,0));
            assert_eq!(exported.cells[15].as_ref().unwrap().height(16,16),
                Some(19.125));
            assert_eq!(exported.cells[31].as_ref().unwrap().height(16,0),
                Some(19.125));
        }
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
