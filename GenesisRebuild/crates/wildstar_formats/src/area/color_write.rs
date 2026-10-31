//! Native WildStar terrain macro-color editing (bit 3 RGB565 + bit 13 BC2).
//! Only the RGB attribute is edited; all existing BC2 alpha nibbles are kept
//! byte-for-byte. Never fabricate or alter unknown alpha semantics.
use super::{RawArea,AreaCell};
use super::texture_write::bc1_encode;
use std::collections::{BTreeSet,BTreeMap};

pub const COLOR_SIDE:usize=64;
pub const COLOR_BYTES:usize=COLOR_SIDE*COLOR_SIDE*4;
const SOURCE_SIDE:usize=65;
const BLOCK_SIDE:usize=17;

#[derive(Debug,Clone)]
pub struct ColorCellEdit{
    pub index:usize,
    /// 64x64 RGBA8 colors in cell-local row-major order.
    pub before:Vec<u8>,
    pub after:Vec<u8>,
}

fn encode_rgb565(rgb:&[u8])->u16{
    let r=(rgb[0] as u32*31+127)/255;
    let g=(rgb[1] as u32*63+127)/255;
    let b=(rgb[2] as u32*31+127)/255;
    ((r<<11)|(g<<5)|b) as u16
}
fn modified_rgb(before:&[u8],after:&[u8],pixel:usize)->bool{
    let off=pixel*4;
    before[off..off+3]!=after[off..off+3]
}
fn patches_for_cell(cell:&AreaCell,edit:&ColorCellEdit)
    ->Result<Vec<(usize,Vec<u8>)>,String>
{
    if edit.before.len()!=COLOR_BYTES||edit.after.len()!=COLOR_BYTES {
        return Err("AREA color edit requires 64x64 RGBA8 source and target".into());
    }
    for (old,new) in edit.before.chunks_exact(4).zip(edit.after.chunks_exact(4)){
        if old[3]!=new[3] {
            return Err("AREA color export cannot change unverified alpha attributes".into());
        }
    }
    let changes=(0..COLOR_SIDE*COLOR_SIDE).filter(|&pixel|
        modified_rgb(&edit.before,&edit.after,pixel)).collect::<Vec<_>>();
    if changes.is_empty(){return Ok(Vec::new());}
    let bit3=cell.block(3);
    let bit13=cell.block(13);
    if bit3.is_none()&&bit13.is_none(){
        return Err(format!("AREA cell {} has no supported RGB color blocks (3/13)",cell.index));
    }
    let mut patches=Vec::new();
    if let Some(raw)=bit3 {
        if raw.len()!=SOURCE_SIDE*SOURCE_SIDE*2{
            return Err("AREA RGB565 source block has wrong length".into());
        }
        let mut rgb=raw.to_vec();
        for &pixel in &changes{
            let x=pixel%COLOR_SIDE;
            let z=pixel/COLOR_SIDE;
            let src=pixel*4;
            let off=(z*SOURCE_SIDE+x)*2;
            rgb[off..off+2].copy_from_slice(&encode_rgb565(&edit.after[src..src+3]).to_le_bytes());
        }
        patches.push((3,rgb));
    }
    if let Some(raw)=bit13 {
        if raw.len()!=BLOCK_SIDE*BLOCK_SIDE*16{
            return Err("AREA BC2 source block has wrong length".into());
        }
        let mut bc2=raw.to_vec();
        let mut blocks=BTreeSet::new();
        for pixel in changes{
            let x=pixel%COLOR_SIDE;
            let z=pixel/COLOR_SIDE;
            blocks.insert((z/4)*BLOCK_SIDE+x/4);
        }
        for block in blocks {
            let bx=block%BLOCK_SIDE;
            let bz=block/BLOCK_SIDE;
            let mut colors=[[0u8;3];16];
            for z in 0..4{
                for x in 0..4{
                    let offset=(((bz*4+z)*COLOR_SIDE)+(bx*4+x))*4;
                    colors[z*4+x].copy_from_slice(&edit.after[offset..offset+3]);
                }
            }
            let offset=block*16;
            // BC2's 8-byte alpha payload is not RGB: it must be retained.
            bc2[offset+8..offset+16].copy_from_slice(&bc1_encode(colors));
        }
        patches.push((13,bc2));
    }
    Ok(patches)
}
/// Produce byte-exact-size native block changes. Unknown block payloads remain
/// untouched via RawArea::with_cell_block_changes.
pub fn plan_color_edits(area:&RawArea,edits:&[ColorCellEdit])
    ->Result<Vec<(usize,usize,Vec<u8>)>,String>
{
    let mut seen=BTreeMap::<usize,()>::new();
    let mut patches=Vec::new();
    for edit in edits{
        if seen.insert(edit.index,()).is_some(){return Err("Duplicate AREA color cell edit".into());}
        let cell=area.cells.get(edit.index).and_then(Option::as_ref)
            .ok_or("Color edit targets a missing AREA cell")?;
        for (bit,bytes) in patches_for_cell(cell,edit)?{
            patches.push((edit.index,bit,bytes));
        }
    }
    Ok(patches)
}

#[cfg(test)]
mod tests{
    use super::*;
    use super::super::{RawChunk};
    use flate2::{Compression,write::ZlibEncoder};
    use std::io::Write;

    #[test]
    fn rgb565_encoder_quantizes_primary_colors(){
        assert_eq!(encode_rgb565(&[255,0,0]),0xf800);
        assert_eq!(encode_rgb565(&[0,255,0]),0x07e0);
        assert_eq!(encode_rgb565(&[0,0,255]),0x001f);
    }
    #[test]
    fn color_writer_preserves_bc2_alpha_and_untouched_regions(){
        let mut blocks=vec![None;32];
        blocks[3]=Some(vec![0;SOURCE_SIDE*SOURCE_SIDE*2]);
        let mut bc2=vec![0;BLOCK_SIDE*BLOCK_SIDE*16];
        for b in bc2.chunks_exact_mut(16){
            b[..8].copy_from_slice(&[0,1,2,3,4,5,6,7]);
        }
        blocks[13]=Some(bc2.clone());
        let cell=AreaCell{index:0,flags:(1<<3)|(1<<13),
            blocks,subchunks:Vec::new()};
        let before=vec![0u8;COLOR_BYTES];
        let mut after=before.clone();
        after[0..3].copy_from_slice(&[255,0,0]);
        let patches=patches_for_cell(&cell,&ColorCellEdit{index:0,before,after}).unwrap();
        assert_eq!(patches.len(),2);
        assert_eq!(&patches[0].1[..2],&[0x00,0xf8]);
        assert_eq!(&patches[0].1[2..],&vec![0;SOURCE_SIDE*SOURCE_SIDE*2-2]);
        let encoded=&patches[1].1;
        for (i,block) in encoded.chunks_exact(16).enumerate(){
            assert_eq!(&block[..8],&[0,1,2,3,4,5,6,7]);
            if i!=0{assert_eq!(&block[8..],&[0;8]);}
        }
    }
    #[test]
    fn compressed_area_color_export_roundtrip_preserves_alpha(){
        let flags=(1u32<<3)|(1u32<<13);
        let mut decoded=flags.to_le_bytes().to_vec();
        decoded.extend(vec![0;SOURCE_SIDE*SOURCE_SIDE*2]);
        let mut bc2=vec![0;BLOCK_SIDE*BLOCK_SIDE*16];
        for block in bc2.chunks_exact_mut(16){block[..8].fill(0xa5);}
        decoded.extend(bc2);
        let zip=|source:&[u8]| {
            let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
            enc.write_all(source).unwrap();
            enc.finish().unwrap()
        };
        let mut stream=3u32.to_le_bytes().to_vec();
        stream.extend(zip(b"LOD"));
        stream.extend((decoded.len() as u32).to_le_bytes());
        stream.extend(zip(&decoded));
        let mut input=b"AERA".to_vec();
        input.extend(0u32.to_le_bytes());
        input.extend(b"KNHC");
        input.extend((stream.len() as u32).to_le_bytes());
        input.extend(stream);
        input.extend(b"TEST");
        input.extend(1u32.to_le_bytes());
        input.push(123);
        let source=RawArea::from_bytes(input).unwrap();
        let before=vec![0u8;COLOR_BYTES];
        let mut after=before.clone();
        after[0..3].copy_from_slice(&[255,0,0]);
        let edits=plan_color_edits(&source,&[ColorCellEdit{index:0,before,after}]).unwrap();
        let result=RawArea::from_bytes(source.with_cell_block_changes(&edits).unwrap()).unwrap();
        let cell=result.cells[0].as_ref().unwrap();
        assert_eq!(cell.color_rgb565(0,0),Some([255,0,0]));
        assert!(cell.terrain_color(0,0).is_some());
        assert_eq!(cell.block(13).unwrap()[0..8],[0xa5;8]);
        assert_eq!(result.chunks[1].data,vec![123]);
        assert_eq!(result.lod_prefix,Some(b"LOD".to_vec()));
    }
}
