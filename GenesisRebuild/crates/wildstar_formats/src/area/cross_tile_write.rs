//! Read-only-input, native cross-AREA seam patches for 65x65 terrain attributes.
//! Only writes the trailing ghost row/column of a neighbouring AREA. It cannot
//! write terrain interiors, add a missing block, reinterpret layer IDs, or
//! update unresolved 19/20 compressed weight companions.
use super::{AreaCell,RawArea};
use super::texture_write::{bc1_encode,nibbles_for_rgba};
use super::color_write::encode_rgb565;
use std::collections::{BTreeMap,BTreeSet};

const CELL:usize=64;
const BLOCKS:usize=17;

#[derive(Debug,Clone,Copy,PartialEq,Eq)]
pub struct BorderWeights {
    /// IDs in the *source* cell. Reject copies across different slot layouts.
    pub layer_ids:[u32;4],
    pub rgba:[u8;4],
}
#[derive(Debug,Clone,Copy,PartialEq,Eq)]
pub struct BorderSample {
    /// Target AREA global sample coordinates (0..=1024). Either x or z
    /// MUST be 1024, so an interior sample cannot accidentally be overwritten.
    pub x:usize,
    pub z:usize,
    pub weights:Option<BorderWeights>,
    pub rgb:Option<[u8;3]>,
}
#[derive(Default,Clone)]
struct Samples {
    weight:BTreeMap<(usize,usize),BorderWeights>,
    color:BTreeMap<(usize,usize),[u8;3]>,
}
/// A duplicated sample at an internal cell boundary must be written into the
/// next cell's 0 and the previous cell's 64. At the tile border, only the last
/// cell's coordinate 64 is updated, never a hypothetical next tile.
fn native_axes(pos:usize)->Vec<(usize,usize)>{
    if pos==1024 {return vec![(15,64)];}
    let cell=pos/CELL;
    let local=pos%CELL;
    if local==0 && cell>0 {
        vec![(cell,0),(cell-1,64)]
    }else{
        vec![(cell,local)]
    }
}
fn read_weight(cell:&AreaCell,x:usize,z:usize)->Option<[u8;3]>{
    let w=cell.compressed_weights(x,z).or_else(||{
        cell.normalized_weights(x,z)
            .or_else(||cell.authoring_weights(x,z))
            .map(|v|{
                let sum=v.iter().map(|&v|v as f32).sum::<f32>();
                if sum>0.0{v.map(|c|c as f32/sum)}
                else{[1.0,0.0,0.0,0.0]}
            })
    })?;
    Some(std::array::from_fn(|i|(w[i].clamp(0.0,1.0)*255.0).round() as u8))
}
fn neutral_bc1_correction()->[u8;8]{
    let mut block=[0u8;8];
    block[..2].copy_from_slice(&0x7BF0u16.to_le_bytes());
    block[2..4].copy_from_slice(&0x7BEFu16.to_le_bytes());
    block[4..].copy_from_slice(&0x5555_5555u32.to_le_bytes());
    block
}
/// Build exact-size native block patches on a neighbouring AREA using only
/// the duplicated 65th edge samples. Unknown and untouched bytes are retained.
///
/// For a source tile's x=0 edge, pass target samples at x=1024; for its z=0
/// edge, pass target samples at z=1024. At the top-left tile corner, pass
/// (1024,1024) to the diagonal predecessor.
/// This API deliberately never opens or overwrites a file.
pub fn plan_cross_tile_border_edits(
    area:&RawArea,samples:&[BorderSample],
)->Result<Vec<(usize,usize,Vec<u8>)>,String>{
    let mut targets=BTreeMap::<usize,Samples>::new();
    let mut seen=BTreeSet::new();
    for sample in samples {
        if sample.x>1024||sample.z>1024 ||
            (sample.x!=1024 && sample.z!=1024) ||
            (sample.weights.is_none()&&sample.rgb.is_none()) {
            return Err("AREA border: expected a target on x=1024 or z=1024".into());
        }
        if !seen.insert((sample.x,sample.z)) {
            return Err("AREA border: duplicated target sample".into());
        }
        if let Some(w)=sample.weights {
            if w.rgba.iter().map(|&v|v as u16).sum::<u16>()!=255 {
                return Err("AREA border: weights must add to 255".into());
            }
        }
        for (cx,lx) in native_axes(sample.x){
            for (cz,lz) in native_axes(sample.z){
                let dst=targets.entry(cz*16+cx).or_default();
                if let Some(w)=sample.weights {
                    if dst.weight.insert((lx,lz),w).is_some(){
                        return Err("AREA border: duplicate weight texel".into());
                    }
                }
                if let Some(rgb)=sample.rgb {
                    if dst.color.insert((lx,lz),rgb).is_some(){
                        return Err("AREA border: duplicate color texel".into());
                    }
                }
            }
        }
    }
    let mut patches=BTreeMap::<(usize,usize),Vec<u8>>::new();
    for (index,changes) in targets {
        let cell=area.cells.get(index).and_then(Option::as_ref)
            .ok_or_else(||format!("AREA border: target cell {index} missing"))?;
        if !changes.weight.is_empty(){
            if cell.block(19).is_some()||cell.block(20).is_some(){
                return Err(format!("AREA border: cell {index} uses unsupported 19/20"));
            }
            let original_ids=cell.layers().ok_or_else(||format!(
                "AREA border: target cell {index} lacks WorldLayer IDs"
            ))?;
            for w in changes.weight.values(){
                if w.layer_ids!=original_ids{
                    return Err(format!(
                        "AREA border: WorldLayer ID mismatch in neighbour cell {index}"
                    ));
                }
            }
            if cell.block(18).is_some()&&cell.block(17).is_none(){
                return Err("AREA border: bit18 correction lacks bit17 base".into());
            }
            if [2usize,29,17].iter().all(|&bit|cell.block(bit).is_none()){
                return Err(format!("AREA border: cell {index} has no writable weights"));
            }
            for bit in [2usize,29]{
                if let Some(original)=cell.block(bit){
                    if original.len()!=65*65*2{
                        return Err("AREA border: malformed raw weight block".into());
                    }
                    let mut raw=original.to_vec();
                    for (&(x,z),w) in &changes.weight {
                        let offset=(z*65+x)*2;
                        raw[offset..offset+2].copy_from_slice(
                            &nibbles_for_rgba(w.rgba).to_le_bytes());
                    }
                    patches.insert((index,bit),raw);
                }
            }
            if let Some(original)=cell.block(17){
                if original.len()!=BLOCKS*BLOCKS*8 {
                    return Err("AREA border: malformed BC1 weight block".into());
                }
                let mut raw=original.to_vec();
                let mut correction=cell.block(18).map(|b|b.to_vec());
                let touched=changes.weight.keys().map(|&(x,z)|
                    (z/4)*BLOCKS+x/4).collect::<BTreeSet<_>>();
                for block in touched {
                    let bx=block%BLOCKS;
                    let bz=block/BLOCKS;
                    let mut rgb=[[0u8;3];16];
                    for dz in 0..4{
                        for dx in 0..4{
                            let x=bx*4+dx;
                            let z=bz*4+dz;
                            rgb[dz*4+dx]=if let Some(w)=changes.weight.get(&(x,z)){
                                [w.rgba[0],w.rgba[1],w.rgba[2]]
                            }else{
                                read_weight(cell,x.min(64),z.min(64))
                                    .ok_or("AREA border: unable to decode original BC1 weight")?
                            };
                        }
                    }
                    raw[block*8..block*8+8].copy_from_slice(&bc1_encode(rgb));
                    if let Some(c)=correction.as_mut(){
                        c[block*8..block*8+8]
                            .copy_from_slice(&neutral_bc1_correction());
                    }
                }
                patches.insert((index,17),raw);
                if let Some(c)=correction{patches.insert((index,18),c);}
            }
        }
        if !changes.color.is_empty(){
            if cell.block(3).is_none()&&cell.block(13).is_none(){
                return Err(format!("AREA border: cell {index} has no writable RGB"));
            }
            if let Some(original)=cell.block(3){
                if original.len()!=65*65*2 {
                    return Err("AREA border: malformed RGB565 block".into());
                }
                let mut raw=original.to_vec();
                for (&(x,z),rgb) in &changes.color {
                    let offset=(z*65+x)*2;
                    raw[offset..offset+2].copy_from_slice(
                        &encode_rgb565(rgb).to_le_bytes());
                }
                patches.insert((index,3),raw);
            }
            if let Some(original)=cell.block(13){
                if original.len()!=BLOCKS*BLOCKS*16 {
                    return Err("AREA border: malformed BC2 color block".into());
                }
                let mut raw=original.to_vec();
                let touched=changes.color.keys().map(|&(x,z)|
                    (z/4)*BLOCKS+x/4).collect::<BTreeSet<_>>();
                for block in touched {
                    let bx=block%BLOCKS;
                    let bz=block/BLOCKS;
                    let mut rgb=[[0u8;3];16];
                    for dz in 0..4{
                        for dx in 0..4{
                            let x=bx*4+dx;
                            let z=bz*4+dz;
                            rgb[dz*4+dx]=changes.color.get(&(x,z)).copied()
                                .or_else(||cell.color_bc2(x.min(64),z.min(64)))
                                .ok_or("AREA border: cannot decode original BC2 RGB")?;
                        }
                    }
                    // RGB only; preserve every original BC2 alpha nibble.
                    raw[block*16+8..block*16+16].copy_from_slice(&bc1_encode(rgb));
                }
                patches.insert((index,13),raw);
            }
        }
    }
    Ok(patches.into_iter().map(|((index,bit),bytes)|
        (index,bit,bytes)).collect())
}

/// Re-decode the patched AREA before saving, validating both the border
/// representation and unchanged BC2 alpha, including the hidden Bit 13 colors.
pub fn validate_cross_tile_border(
    source:&RawArea,reloaded:&RawArea,samples:&[BorderSample]
)->Result<(),String>{
    for sample in samples {
        for (cx,lx) in native_axes(sample.x) {
            for (cz,lz) in native_axes(sample.z) {
                let index=cz*16+cx;
                let after=reloaded.cells.get(index).and_then(Option::as_ref)
                    .ok_or("AREA border: output missing a target cell")?;
                if let Some(w)=sample.weights {
                    let decoded=after.compressed_weights(lx,lz).or_else(||{
                        after.normalized_weights(lx,lz)
                            .or_else(||after.authoring_weights(lx,lz))
                            .map(|v|{
                                let sum=v.iter().map(|&c|c as f32).sum::<f32>();
                                if sum>0.0{v.map(|c|c as f32/sum)}
                                else{[1.0,0.0,0.0,0.0]}
                            })
                    }).ok_or("AREA border: output weight sample unreadable")?;
                    for channel in 0..4 {
                        if (decoded[channel]-w.rgba[channel] as f32/255.0).abs()>0.20 {
                            return Err(format!(
                                "AREA border: weight compression error in cell {index} ({lx},{lz}), slot {channel}"
                            ));
                        }
                    }
                }
                if let Some(rgb)=sample.rgb {
                    if let Some(raw)=after.color_rgb565(lx,lz){
                        if (0..3).any(|i|(raw[i] as i16-rgb[i] as i16).abs()>50){
                            return Err("AREA border: raw RGB565 mismatch".into());
                        }
                    }
                    if let Some(bc2)=after.color_bc2(lx,lz){
                        if (0..3).any(|i|(bc2[i] as i16-rgb[i] as i16).abs()>50){
                            return Err("AREA border: compressed BC2 RGB mismatch".into());
                        }
                    }
                }
            }
        }
    }
    for (before,after) in source.cells.iter().zip(&reloaded.cells) {
        let (Some(before),Some(after))=(before.as_ref(),after.as_ref()) else{continue;};
        if let (Some(a),Some(b))=(before.block(13),after.block(13)){
            if a.len()!=b.len()||a.chunks_exact(16).zip(b.chunks_exact(16))
                .any(|(a,b)|a[..8]!=b[..8]){
                return Err("AREA border: original BC2 alpha changed".into());
            }
        }
    }
    Ok(())
}

#[cfg(test)]
mod tests{
    use super::*;
    use super::super::AreaCell;
    fn mock_cell(index:usize,ids:[u32;4])->AreaCell{
        let mut blocks=vec![None;32];
        blocks[1]=Some(ids.iter().flat_map(|v|v.to_le_bytes()).collect());
        let mut raw=vec![0u8;65*65*2];
        for pixel in raw.chunks_exact_mut(2){
            pixel.copy_from_slice(&0x000Fu16.to_le_bytes());
        }
        blocks[2]=Some(raw);
        let mut rgb=vec![0u8;65*65*2];
        for pixel in rgb.chunks_exact_mut(2){
            pixel.copy_from_slice(&0xF800u16.to_le_bytes());
        }
        blocks[3]=Some(rgb);
        AreaCell{index,flags:(1<<1)|(1<<2)|(1<<3),
            blocks,subchunks:Vec::new()}
    }
    fn mock_area()->RawArea{
        let mut cells=vec![None;256];
        for index in [239,254,255] {
            cells[index]=Some(mock_cell(index,[3,4,5,6]));
        }
        RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None}
    }
    #[test]
    fn maps_last_column_and_row_and_diagonal_without_touching_interior(){
        let area=mock_area();
        let weight=BorderWeights{layer_ids:[3,4,5,6],rgba:[0,255,0,0]};
        let samples=[
            BorderSample{x:1024,z:960,weights:Some(weight),rgb:Some([0,255,0])},
            BorderSample{x:960,z:1024,weights:Some(weight),rgb:None},
            BorderSample{x:1024,z:1024,weights:None,rgb:Some([0,0,255])},
        ];
        let plan=plan_cross_tile_border_edits(&area,&samples).unwrap();
        assert_eq!(plan.len(),5);
        let mut amended=area.clone();
        for (index,bit,data) in plan{
            amended.cells[index].as_mut().unwrap().blocks[bit]=Some(data);
        }
        assert_eq!(amended.cells[255].as_ref().unwrap()
            .authoring_weights(64,0),Some([0,15,0,0]));
        assert_eq!(amended.cells[254].as_ref().unwrap()
            .authoring_weights(64,64),Some([0,15,0,0]));
        assert_eq!(amended.cells[255].as_ref().unwrap()
            .color_rgb565(64,64),Some([0,0,255]));
        assert_eq!(amended.cells[255].as_ref().unwrap()
            .authoring_weights(0,0),Some([15,0,0,0]));
        validate_cross_tile_border(&area,&amended,&samples).unwrap();
    }
    #[test]
    fn rejects_unsafe_border_writes(){
        let area=mock_area();
        let weight=BorderWeights{layer_ids:[3,4,5,6],rgba:[0,255,0,0]};
        let valid=BorderSample{x:1024,z:1000,weights:Some(weight),rgb:None};
        assert!(plan_cross_tile_border_edits(&area,&[
            BorderSample{x:1,..valid}
        ]).is_err());
        assert!(plan_cross_tile_border_edits(&area,&[valid,valid]).is_err());
        let bad=BorderSample{weights:Some(BorderWeights{
            layer_ids:[90,4,5,6],..weight}),..valid};
        assert!(plan_cross_tile_border_edits(&area,&[bad]).unwrap_err()
            .contains("WorldLayer ID mismatch"));
        let mut unknown=area.clone();
        unknown.cells[255].as_mut().unwrap().blocks[19]=Some(vec![0;2312]);
        assert!(plan_cross_tile_border_edits(&unknown,&[valid]).unwrap_err()
            .contains("19/20"));
        assert!(plan_cross_tile_border_edits(&area,&[
            BorderSample{x:1024,z:10,weights:Some(weight),rgb:None}
        ]).is_err());
    }
}
