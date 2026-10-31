//! Native WildStar AREA terrain texture block encoding (known, validated subset).
//! Unknown pairs, specifically the bit 29 -> 19/20 companion encoding, are
//! *not* written. The caller must surface the error rather than silently
//! producing mismatched GPU / editor data.
use super::{AreaCell, RawArea};
use std::collections::BTreeMap;

pub const CELL_SIDE:usize=64;
pub const CELL_RGBA_BYTES:usize=CELL_SIDE*CELL_SIDE*4;
const RAW_SIDE:usize=65;
const BC_BLOCKS:usize=17;

#[derive(Debug,Clone)]
pub struct TextureCellEdit {
    pub index:usize,
    pub layer_ids:[u32;4],
    /// 64x64 normalized RGBA8, row-major; 255 == 100%.
    pub weights:Vec<u8>,
    /// Original preview RGBA8 at the same resolution; dirty-pixel mask.
    pub before:Vec<u8>,
}

fn nibbles_for_rgba(px:[u8;4])->u16 {
    // Largest remainder apportionment, so the 4 nibbles sum exactly 15.
    let mut counts=[0u16;4];
    let mut tails=[0u16;4];
    for i in 0..4 {
        let v=px[i] as u16*15;
        counts[i]=v/255;
        tails[i]=v%255;
    }
    let sum:usize=counts.iter().map(|&v|v as usize).sum();
    for _ in sum..15 {
        let best=(0..4).max_by_key(|&i|(tails[i],std::cmp::Reverse(i))).unwrap();
        counts[best]+=1;
        tails[best]=0;
    }
    counts[0]|(counts[1]<<4)|(counts[2]<<8)|(counts[3]<<12)
}
fn px4(buf:&[u8],at:usize)->[u8;4] {
    let b=&buf[at*4..at*4+4];
    [b[0],b[1],b[2],b[3]]
}
fn rgb565(rgb:[u8;3])->u16 {
    let r=((rgb[0] as u32*31+127)/255) as u16;
    let g=((rgb[1] as u32*63+127)/255) as u16;
    let b=((rgb[2] as u32*31+127)/255) as u16;
    (r<<11)|(g<<5)|b
}
fn rgb_from_565(n:u16)->[f32;3] {
    [((n>>11)&31) as f32/31.0,
      ((n>>5)&63) as f32/63.0, (n&31) as f32/31.0]
}

/// Four-color BC1 block encoder. 4x4 texels and no alpha channel. Intentionally
/// simple bounding-box / nearest-palette codec; the BC1 conversion is lossy.
fn bc1_encode(rgb:[[u8;3];16])->[u8;8] {
    // Pick actual texels with the largest RGB distance. Component-wise
    // min/max can produce a non-existent color (e.g. yellow for mixed red and
    // green weights) and destroy otherwise exact two-color blocks.
    let mut endpoints=(0usize,0usize);
    let mut spread=0u32;
    for i in 0..16{
        for j in (i+1)..16{
            let dist=(0..3).map(|c|{
                let d=rgb[i][c] as i32-rgb[j][c] as i32;
                (d*d) as u32
            }).sum::<u32>();
            if dist>spread{spread=dist;endpoints=(i,j);}
        }
    }
    let mut a=rgb565(rgb[endpoints.0]);
    let mut b=rgb565(rgb[endpoints.1]);
    if a<b {std::mem::swap(&mut a,&mut b);}
    if a==b {
        if a<65535{a+=1;}else{b-=1;}
    }
    let p0=rgb_from_565(a);
    let p1=rgb_from_565(b);
    let palette=[
        p0,p1,
        std::array::from_fn(|c|(2.0*p0[c]+p1[c])/3.0),
        std::array::from_fn(|c|(p0[c]+2.0*p1[c])/3.0),
    ];
    let mut indices=0u32;
    for (i,p) in rgb.iter().enumerate(){
        let best=(0..4).min_by(|&a,&b|{
            let dist=|j:usize|{
                (0..3).map(|c|{
                    let d=p[c] as f32/255.0-palette[j][c];
                    d*d
                }).sum::<f32>()
            };
            dist(a).total_cmp(&dist(b))
        }).unwrap();
        indices|=(best as u32)<<(i*2);
    }
    let mut out=[0u8;8];
    out[0..2].copy_from_slice(&a.to_le_bytes());
    out[2..4].copy_from_slice(&b.to_le_bytes());
    out[4..8].copy_from_slice(&indices.to_le_bytes());
    out
}
/// BC1 signed-weight correction neutral RGB565 = 0x7BEF.
fn neutral_correction_block()->[u8;8]{
    let mut block=[0u8;8];
    block[0..2].copy_from_slice(&0x7BF0u16.to_le_bytes());
    block[2..4].copy_from_slice(&0x7BEFu16.to_le_bytes());
    block[4..8].copy_from_slice(&0x5555_5555u32.to_le_bytes()); // index 1
    block
}

fn make_cell_edits(cell:&AreaCell, edit:&TextureCellEdit)
    ->Result<Vec<(usize,Vec<u8>)>,String>
{
    if edit.weights.len()!=CELL_RGBA_BYTES || edit.before.len()!=CELL_RGBA_BYTES {
        return Err("Texture codec: each cell requires 64x64 RGBA8 before/after".into());
    }
    if cell.index!=edit.index || cell.block(1).is_none(){
        return Err("Texture codec: target is not a layer-enabled AREA cell".into());
    }
    let original_ids=cell.layers().ok_or("Texture codec: missing layer IDs")?;
    let changed_slots=original_ids!=edit.layer_ids;
    let mut changed=Vec::new();
    for p in 0..CELL_SIDE*CELL_SIDE {
        if px4(&edit.before,p)!=px4(&edit.weights,p){
            let rgba=px4(&edit.weights,p);
            if rgba.iter().map(|&v|v as u16).sum::<u16>()!=255 {
                return Err("Texture codec: edited weight samples must sum to 255".into());
            }
            changed.push(p);
        }
    }
    if changed.is_empty() && !changed_slots {return Ok(Vec::new());}
    let mut out=Vec::new();
    if changed_slots {
        let mut ids=Vec::with_capacity(16);
        for id in edit.layer_ids {ids.extend_from_slice(&id.to_le_bytes());}
        out.push((1,ids));
    }
    if changed.is_empty(){return Ok(out);}

    let has17=cell.block(17).is_some();
    let has18=cell.block(18).is_some();
    let has19=cell.block(19).is_some();
    let has20=cell.block(20).is_some();
    // Bit 29's compressed companion formats are not fully verified.
    if has19||has20 {
        return Err(format!(
            "Texture codec: cell {} uses unresolved bit 19/20 companions; refusing unsafe export",
            cell.index));
    }
    if has18&&!has17{
        return Err("Texture codec: bit 18 correction present without bit 17 base".into());
    }
    // Need at least one known, editable weight representation. Do not insert
    // missing data blocks because that would alter flags and cell layout.
    if cell.block(2).is_none() && cell.block(29).is_none() && !has17{
        return Err(format!("Texture codec: cell {} has no writable weight blocks",cell.index));
    }
    for bit in [2,29] {
        if let Some(raw)=cell.block(bit){
            let mut data=raw.to_vec();
            for &pixel in &changed {
                let x=pixel%CELL_SIDE;
                let z=pixel/CELL_SIDE;
                let packed=nibbles_for_rgba(px4(&edit.weights,pixel));
                let o=(z*RAW_SIDE+x)*2;
                data[o..o+2].copy_from_slice(&packed.to_le_bytes());
            }
            out.push((bit,data));
        }
    }
    if has17 {
        let mut base=cell.block(17).unwrap().to_vec();
        let mut correction=cell.block(18).map(|b|b.to_vec());
        let mut dirty_blocks=std::collections::BTreeSet::new();
        for &pixel in &changed {
            let x=pixel%CELL_SIDE;
            let z=pixel/CELL_SIDE;
            dirty_blocks.insert((z/4)*BC_BLOCKS+x/4);
        }
        for block in dirty_blocks {
            let bx=block%BC_BLOCKS;
            let bz=block/BC_BLOCKS;
            let mut px=[[0u8;3];16];
            for dz in 0..4{
                for dx in 0..4{
                    let x=bx*4+dx;
                    let z=bz*4+dz;
                    let rgba=px4(&edit.weights,z*CELL_SIDE+x);
                    px[dz*4+dx]=[rgba[0],rgba[1],rgba[2]];
                }
            }
            base[block*8..block*8+8].copy_from_slice(&bc1_encode(px));
            if let Some(corr)=correction.as_mut(){
                corr[block*8..block*8+8].copy_from_slice(&neutral_correction_block());
            }
        }
        out.push((17,base));
        if let Some(corr)=correction{out.push((18,corr));}
    }
    Ok(out)
}

/// Generate an exact-size replacement plan. Call RawArea::with_cell_block_changes
/// afterwards, then round-trip and verify to your acceptable BC1 error threshold.
pub fn plan_texture_edits(area:&RawArea, edits:&[TextureCellEdit])
    ->Result<Vec<(usize,usize,Vec<u8>)>,String>
{
    let mut result=Vec::new();
    let mut seen=BTreeMap::<usize,()>::new();
    for edit in edits {
        if seen.insert(edit.index,()).is_some(){
            return Err("Texture codec: duplicated cell edit".into());
        }
        let cell=area.cells.get(edit.index).and_then(Option::as_ref)
            .ok_or("Texture codec: editing absent cell")?;
        for (bit,data) in make_cell_edits(cell,edit)? {
            result.push((edit.index,bit,data));
        }
    }
    Ok(result)
}

#[cfg(test)]
mod tests {
    use super::*;
    use super::super::{AreaCell,RawChunk};
    fn cell(bits:&[usize])->AreaCell{
        let mut blocks=vec![None;32];
        let mut ids=Vec::new();
        for id in [10u32,11,12,13]{ids.extend(id.to_le_bytes());}
        blocks[1]=Some(ids);
        for &bit in bits {
            let bytes=match bit{2|29=>8450,17|18|19|20=>2312,_=>panic!()};
            blocks[bit]=Some(vec![0;bytes]);
        }
        AreaCell{index:0,flags:0,blocks,subchunks:vec![RawChunk{
            id:*b"DATA",file_offset:0,data:vec![0xAA,0xBB]}]}
    }
    fn edit()->TextureCellEdit{
        let mut before=[0u8;CELL_RGBA_BYTES].to_vec();
        let mut weights=before.clone();
        for px in before.chunks_exact_mut(4){px[0]=255;}
        weights.copy_from_slice(&before);
        weights[0..4].copy_from_slice(&[0,255,0,0]);
        TextureCellEdit{index:0,layer_ids:[10,11,12,13],weights,before}
    }
    #[test]
    fn nibble_sum_exactly_fifteen(){
        for p in [[255,0,0,0],[0,255,0,0],[0,0,128,127],[51,52,101,51]]{
            let x=nibbles_for_rgba(p);
            let sum=(0..4).map(|i|((x>>(i*4))&15) as usize).sum::<usize>();
            assert_eq!(sum,15);
        }
    }
    #[test]
    fn writes_only_changed_pixel_and_preserves_other_samples(){
        let c=cell(&[2,29]);
        let patches=make_cell_edits(&c,&edit()).unwrap();
        assert_eq!(patches.len(),2);
        for (_,data) in patches {
            assert_eq!(&data[0..2],&0x00F0u16.to_le_bytes());
            assert!(data[2..].iter().all(|&v|v==0));
        }
    }
    #[test]
    fn rejects_unknown_companions_without_writing(){
        let c=cell(&[2,29,19,20]);
        let err=make_cell_edits(&c,&edit()).unwrap_err();
        assert!(err.contains("19/20"));
    }
    #[test]
    fn native_texture_export_reloads_in_compressed_and_raw_area(){
        use flate2::{Compression,write::ZlibEncoder};
        use std::io::Write;
        let original=cell(&[2,17,18,29]);
        let mut payload=Vec::new();
        let flags=(1u32<<1)|(1u32<<2)|(1u32<<17)|(1u32<<18)|(1u32<<29);
        payload.extend(flags.to_le_bytes());
        payload.extend(original.block(1).unwrap());
        payload.extend(vec![0x0f;8450]);
        // Original 17/18 BC1 blocks are valid uniform first-layer weights.
        for _ in 0..(17*17){payload.extend(bc1_encode([[255,0,0];16]));}
        for _ in 0..(17*17){payload.extend(neutral_correction_block());}
        payload.extend(vec![0x0f;8450]);
        for compressed in [false,true]{
            let mut stream=Vec::new();
            if compressed{
                let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
                enc.write_all(b"LOD").unwrap();
                stream.extend(3u32.to_le_bytes());
                stream.extend(enc.finish().unwrap());
                let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
                enc.write_all(&payload).unwrap();
                stream.extend((payload.len() as u32).to_le_bytes());
                stream.extend(enc.finish().unwrap());
            }else{
                stream.extend((payload.len() as u32).to_le_bytes());
                stream.extend(&payload);
            }
            let mut bytes=if compressed{b"AERA".to_vec()}else{b"aera".to_vec()};
            bytes.extend(0u32.to_le_bytes());
            bytes.extend(b"KNHC");
            bytes.extend((stream.len() as u32).to_le_bytes());
            bytes.extend(stream);
            bytes.extend(b"KEEP");
            bytes.extend(3u32.to_le_bytes());
            bytes.extend(b"END");
            let area=RawArea::from_bytes(bytes).unwrap();
            let cell=&area.cells[0].as_ref().unwrap();
            assert_eq!(cell.layers(),Some([10,11,12,13]));
            let mut change=edit();
            change.layer_ids[3]=99;
            let changes=plan_texture_edits(&area,&[change]).unwrap();
            let output=area.with_cell_block_changes(&changes).unwrap();
            let result=RawArea::from_bytes(output).unwrap();
            let changed=result.cells[0].as_ref().unwrap();
            assert_eq!(changed.layers(),Some([10,11,12,99]));
            assert_eq!(changed.normalized_weights(0,0),Some([0,15,0,0]));
            let rendered=changed.compressed_weights(0,0).unwrap();
            assert!(rendered[1]>0.90,"BC1 green weight: {rendered:?}");
            assert_eq!(result.chunks[1].data,b"END");
            if compressed{assert_eq!(result.lod_prefix,Some(b"LOD".to_vec()));}
            assert_eq!(area.cells[0].as_ref().unwrap().layers(),Some([10,11,12,13]));
        }
    }
    #[test]
    fn bc1_encoder_has_four_color_endpoint_order(){
        let enc=bc1_encode([[96,80,40];16]);
        let e0=u16::from_le_bytes([enc[0],enc[1]]);
        let e1=u16::from_le_bytes([enc[2],enc[3]]);
        assert!(e0>e1);
        assert_eq!(neutral_correction_block()[2..4],0x7BEFu16.to_le_bytes());
    }
}
