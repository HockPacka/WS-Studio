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

pub(super) fn nibbles_for_rgba(px:[u8;4])->u16 {
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

/// Order endpoints into BC1's opaque four-colour mode. An equal pair would
/// switch BC1 into three-colour/transparent mode, which is invalid for the
/// terrain weights and for the RGB half of the BC2 writer.
fn bc1_ordered(mut a:u16,mut b:u16)->(u16,u16){
    if a<b {std::mem::swap(&mut a,&mut b);}
    if a==b {
        if a<u16::MAX {a+=1;}else{b-=1;}
    }
    (a,b)
}

/// Evaluate an encoded BC1 block against the actual 4x4 RGB targets with the
/// normalized RGB565 interpolation used by the game client. Lower is better.
fn bc1_evaluate(rgb:&[[u8;3];16],a:u16,b:u16)->(f64,u32){
    let p0=rgb_from_565(a).map(|v|v as f64);
    let p1=rgb_from_565(b).map(|v|v as f64);
    let palette=[
        p0,p1,
        std::array::from_fn(|c|(2.0*p0[c]+p1[c])/3.0),
        std::array::from_fn(|c|(p0[c]+2.0*p1[c])/3.0),
    ];
    let mut total=0.0f64;
    let mut indices=0u32;
    for (i,pixel) in rgb.iter().enumerate(){
        let mut best=0usize;
        let mut best_error=f64::INFINITY;
        for index in 0..4usize {
            let mut error=0.0f64;
            for channel in 0..3 {
                let diff=pixel[channel] as f64/255.0-palette[index][channel];
                error+=diff*diff;
            }
            if error<best_error {best_error=error;best=index;}
        }
        total+=best_error;
        indices|=(best as u32)<<(i*2);
    }
    (total,indices)
}

/// Least-squares RGB endpoints for a fixed assignment of the 16 pixels to
/// the four BC1 palette entries. Both endpoints are quantized back to RGB565.
fn bc1_fit_endpoints(rgb:&[[u8;3];16],indices:u32)->Option<(u16,u16)>{
    let factors=[(1.0,0.0),(0.0,1.0),(2.0/3.0,1.0/3.0),
        (1.0/3.0,2.0/3.0)];
    let (mut aa,mut ab,mut bb)=(0.0,0.0,0.0);
    let (mut ar,mut br)=([0.0f64;3],[0.0f64;3]);
    for i in 0..16usize {
        let (a,b)=factors[((indices>>(i*2))&3) as usize];
        aa+=a*a;ab+=a*b;bb+=b*b;
        for channel in 0..3 {
            let t=rgb[i][channel] as f64/255.0;
            ar[channel]+=t*a;
            br[channel]+=t*b;
        }
    }
    let det=aa*bb-ab*ab;
    if det<=1e-9 {return None;}
    let mut first=[0u8;3];
    let mut second=[0u8;3];
    for channel in 0..3 {
        let x=((ar[channel]*bb-br[channel]*ab)/det).clamp(0.0,1.0);
        let y=((br[channel]*aa-ar[channel]*ab)/det).clamp(0.0,1.0);
        first[channel]=(x*255.0).round() as u8;
        second[channel]=(y*255.0).round() as u8;
    }
    Some(bc1_ordered(rgb565(first),rgb565(second)))
}

fn bc1_mutate_565(value:u16,channel:usize,step:i32)->Option<u16>{
    let (shift,mask) = match channel {
        0=>(11u32,31i32),
        1=>(5u32,63i32),
        _=>(0u32,31i32),
    };
    let old=((value>>shift)&mask as u16) as i32;
    let next=old+step;
    if next<0||next>mask{return None;}
    Some((value & !((mask as u16)<<shift))|((next as u16)<<shift))
}

/// Deterministic four-colour BC1 RGB encoder shared by weight maps (bit 17)
/// and the RGB half of BC2/DXT3 terrain colors (bit 13).
///
/// Seeds with actual farthest-apart pixels, per-channel bounds and PCA extrema;
/// iteratively fits endpoints by least squares and finally optimizes nearby
/// RGB565 codes. Every candidate is evaluated against the complete 4x4 block,
/// and the initial farthest-pixel candidate is retained unless SSE decreases.
/// This minimizes visible changes in neighbouring pixels inside dirty blocks.
pub(super) fn bc1_encode(rgb:[[u8;3];16])->[u8;8]{
    let mut farthest=(0usize,0usize);
    let mut spread=0i64;
    for i in 0..16 {
        for j in (i+1)..16 {
            let dist=(0..3).map(|c|{
                let d=rgb[i][c] as i64-rgb[j][c] as i64;
                d*d
            }).sum::<i64>();
            if dist>spread {spread=dist;farthest=(i,j);}
        }
    }
    let mut low=[255u8;3];
    let mut high=[0u8;3];
    let mut mean=[0.0f64;3];
    for pixel in &rgb {
        for c in 0..3 {
            low[c]=low[c].min(pixel[c]);
            high[c]=high[c].max(pixel[c]);
            mean[c]+=pixel[c] as f64/16.0;
        }
    }
    let mut covariance=[[0.0f64;3];3];
    for pixel in &rgb {
        for c in 0..3 {
            for k in 0..3 {
                covariance[c][k]+=(pixel[c] as f64-mean[c])
                    *(pixel[k] as f64-mean[k]);
            }
        }
    }
    let mut direction=[1.0f64,1.0,1.0];
    for _ in 0..8 {
        let next=std::array::from_fn::<_,3,_>(|c|{
            (0..3).map(|k|covariance[c][k]*direction[k]).sum::<f64>()
        });
        let magnitude=next.iter().map(|v|v*v).sum::<f64>().sqrt();
        if magnitude<1e-10 {break;}
        direction=next.map(|v|v/magnitude);
    }
    let project=|pixel:&[u8;3]|->f64{
        (0..3).map(|c|(pixel[c] as f64-mean[c])*direction[c]).sum()
    };
    let mut ext=(0usize,0usize);
    for i in 1..16 {
        if project(&rgb[i])<project(&rgb[ext.0]) {ext.0=i;}
        if project(&rgb[i])>project(&rgb[ext.1]) {ext.1=i;}
    }
    let seeds=[
        bc1_ordered(rgb565(rgb[farthest.0]),rgb565(rgb[farthest.1])),
        bc1_ordered(rgb565(low),rgb565(high)),
        bc1_ordered(rgb565(rgb[ext.0]),rgb565(rgb[ext.1])),
    ];
    let mut best_pair=seeds[0];
    let mut best=bc1_evaluate(&rgb,best_pair.0,best_pair.1);
    for seed in seeds {
        let mut pair=seed;
        for _ in 0..9 {
            let assessment=bc1_evaluate(&rgb,pair.0,pair.1);
            if assessment.0<best.0 {
                best=assessment;
                best_pair=pair;
            }
            let Some(fitted)=bc1_fit_endpoints(&rgb,assessment.1) else {break;};
            if fitted==pair {break;}
            pair=fitted;
        }
        let assessment=bc1_evaluate(&rgb,pair.0,pair.1);
        if assessment.0<best.0 {
            best=assessment;
            best_pair=pair;
        }
    }
    // Quantized endpoint refinement: the exact least-squares float solution
    // may lie between RGB565 codes, so probe neighbouring endpoint codes.
    for _ in 0..3 {
        let mut improved=false;
        for endpoint in 0..2 {
            for channel in 0..3 {
                for shift in [-1,1] {
                    let current=if endpoint==0{best_pair.0}else{best_pair.1};
                    let Some(near)=bc1_mutate_565(current,channel,shift) else {continue;};
                    let pair=if endpoint==0 {
                        bc1_ordered(near,best_pair.1)
                    }else{
                        bc1_ordered(best_pair.0,near)
                    };
                    let assessment=bc1_evaluate(&rgb,pair.0,pair.1);
                    if assessment.0+1e-12<best.0 {
                        best=assessment;
                        best_pair=pair;
                        improved=true;
                    }
                }
            }
        }
        if !improved {break;}
    }
    let mut out=[0u8;8];
    out[0..2].copy_from_slice(&best_pair.0.to_le_bytes());
    out[2..4].copy_from_slice(&best_pair.1.to_le_bytes());
    out[4..8].copy_from_slice(&best.1.to_le_bytes());
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
        let changed_samples=changed.iter().copied()
            .collect::<std::collections::BTreeSet<_>>();
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
                    let index=z*CELL_SIDE+x;
                    px[dz*4+dx]=if changed_samples.contains(&index){
                        let rgba=px4(&edit.weights,index);
                        [rgba[0],rgba[1],rgba[2]]
                    }else{
                        // The raw map and preview can differ from the compressed
                        // Bit 17/18 pair. Preserve original BC1 appearance of
                        // untouched samples rather than importing another
                        // representation into an entire 4x4 compressed block.
                        let original=cell.compressed_weights(x,z)
                            .ok_or("Texture codec: missing original BC1 pixel")?;
                        std::array::from_fn(|i|
                            (original[i].clamp(0.0,1.0)*255.0).round() as u8)
                    };
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
    use std::collections::BTreeSet;
    // The native authoring rasters are 65x65, not 64x64: x=64/z=64
    // duplicates the next cell's x=0/z=0 sample. Propagate only *inside*
    // this AREA tile, without guessing neighbouring AREA file contents.
    let mut patches=BTreeMap::<(usize,usize),Vec<u8>>::new();
    let mut seen=BTreeSet::new();
    let mut seam=BTreeMap::<usize,BTreeMap<(usize,usize),[u8;4]>>::new();
    for edit in edits {
        if !seen.insert(edit.index) {
            return Err("Texture codec: duplicated cell edit".into());
        }
        let cell=area.cells.get(edit.index).and_then(Option::as_ref)
            .ok_or("Texture codec: editing absent cell")?;
        for (bit,data) in make_cell_edits(cell,edit)? {
            patches.insert((edit.index,bit),data);
        }
        if edit.before.len()!=CELL_RGBA_BYTES || edit.weights.len()!=CELL_RGBA_BYTES {
            return Err("Texture codec: invalid 64x64 RGBA8 weight payload".into());
        }
        let cx=edit.index%16;
        let cz=edit.index/16;
        for z in 0..CELL_SIDE {
            for x in 0..CELL_SIDE {
                let pixel=z*CELL_SIDE+x;
                if px4(&edit.before,pixel)==px4(&edit.weights,pixel) {
                    continue;
                }
                if x!=0 && z!=0 {continue;}
                let rgba=px4(&edit.weights,pixel);
                if rgba.iter().map(|&v|v as u16).sum::<u16>()!=255 {
                    return Err("Texture seam: changed sample weights must sum to 255".into());
                }
                if x==0 && cx>0 {
                    seam.entry(edit.index-1).or_default().insert((64,z),rgba);
                }
                if z==0 && cz>0 {
                    seam.entry(edit.index-16).or_default().insert((x,64),rgba);
                }
                if x==0 && z==0 && cx>0 && cz>0 {
                    seam.entry(edit.index-17).or_default().insert((64,64),rgba);
                }
            }
        }
    }
    for (index,samples) in seam {
        let cell=area.cells.get(index).and_then(Option::as_ref)
            .ok_or_else(||format!("Texture seam cell {index} missing in source AREA"))?;
        if cell.block(19).is_some()||cell.block(20).is_some() {
            return Err(format!(
                "Texture seam cell {index} uses unresolved 19/20 compressed companions"
            ));
        }
        let writable=[2usize,29usize,17usize].iter()
            .any(|&bit|cell.block(bit).is_some());
        if !writable {
            return Err(format!("Texture seam cell {index} has no native weight blocks"));
        }
        if cell.block(18).is_some() && cell.block(17).is_none() {
            return Err(format!("Texture seam cell {index} has bit 18 without bit 17"));
        }
        for bit in [2,29] {
            if let Some(original)=cell.block(bit) {
                let mut raw=patches.remove(&(index,bit))
                    .unwrap_or_else(||original.to_vec());
                for (&(x,z),rgba) in &samples {
                    let offset=(z*RAW_SIDE+x)*2;
                    raw[offset..offset+2]
                        .copy_from_slice(&nibbles_for_rgba(*rgba).to_le_bytes());
                }
                patches.insert((index,bit),raw);
            }
        }
        if let Some(original)=cell.block(17) {
            let mut base=patches.remove(&(index,17))
                .unwrap_or_else(||original.to_vec());
            let mut correction=cell.block(18).map(|raw|
                patches.remove(&(index,18)).unwrap_or_else(||raw.to_vec()));
            let touched=samples.keys()
                .map(|&(x,z)|(z/4)*BC_BLOCKS+x/4)
                .collect::<BTreeSet<_>>();
            for block in touched {
                let bx=block%BC_BLOCKS;
                let bz=block/BC_BLOCKS;
                let mut rgb=[[0u8;3];16];
                for dz in 0..4 {
                    for dx in 0..4 {
                        let x=bx*4+dx;
                        let z=bz*4+dz;
                        let w=samples.get(&(x,z)).map(|v|v.map(|c|c as f32/255.0))
                            .or_else(||cell.compressed_weights(x.min(64),z.min(64)))
                            .or_else(||{
                                cell.normalized_weights(x.min(64),z.min(64)).map(|v|{
                                    let total=v.iter().map(|&v|v as f32).sum::<f32>();
                                    if total>0.0 {
                                        v.map(|c|c as f32/total)
                                    }else{[1.0,0.0,0.0,0.0]}
                                })
                            })
                            .ok_or("Texture seam: unable to restore original BC1 samples")?;
                        rgb[dz*4+dx]=std::array::from_fn(|c|
                            (w[c].clamp(0.0,1.0)*255.0).round() as u8);
                    }
                }
                base[block*8..block*8+8].copy_from_slice(&bc1_encode(rgb));
                if let Some(c)=correction.as_mut(){
                    c[block*8..block*8+8].copy_from_slice(&neutral_correction_block());
                }
            }
            patches.insert((index,17),base);
            if let Some(c)=correction {patches.insert((index,18),c);}
        }
    }
    Ok(patches.into_iter()
        .map(|((cell,bit),data)|(cell,bit,data)).collect())
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
    fn populated_cell(index:usize)->AreaCell{
        let mut c=cell(&[2,29,17,18]);
        c.index=index;
        for bit in [2,29] {
            let mut raw=vec![0u8;8450];
            for p in raw.chunks_exact_mut(2){p.copy_from_slice(&0x000Fu16.to_le_bytes());}
            c.blocks[bit]=Some(raw);
        }
        let mut base=Vec::new();
        let mut corr=Vec::new();
        for _ in 0..(BC_BLOCKS*BC_BLOCKS){
            base.extend(bc1_encode([[255,0,0];16]));
            corr.extend(neutral_correction_block());
        }
        c.blocks[17]=Some(base);
        c.blocks[18]=Some(corr);
        c
    }
    #[test]
    fn internal_weight_seams_sync_raw_and_bc1_and_preserve_outer_tile_edge(){
        let mut cells=vec![None;256];
        for index in [0,1,16,17] {cells[index]=Some(populated_cell(index));}
        let area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None};
        let mut change=edit();
        change.index=17;
        let patch=plan_texture_edits(&area,&[change]).unwrap();
        // Edited cell (17), its left (16), upper (1) and diagonal (0).
        assert_eq!(patch.len(),16);
        let mut rewritten=area.clone();
        for (index,bit,data) in patch {
            rewritten.cells[index].as_mut().unwrap().blocks[bit]=Some(data);
        }
        for (index,x,z) in [(17,0,0),(16,64,0),(1,0,64),(0,64,64)] {
            let cell=rewritten.cells[index].as_ref().unwrap();
            assert_eq!(cell.normalized_weights(x,z),Some([0,15,0,0]));
            let w=cell.compressed_weights(x,z).unwrap();
            assert!(w[1]>0.90,"seam ({index},{x},{z}) = {w:?}");
        }
        // Pixel (63,63) in every neighbour must not be touched.
        for index in [0,1,16] {
            let cell=rewritten.cells[index].as_ref().unwrap();
            assert_eq!(cell.normalized_weights(63,63),Some([15,0,0,0]));
        }
        // The first cell has no left/up neighbours; do not touch an adjacent AREA.
        let patch=plan_texture_edits(&area,&[edit()]).unwrap();
        assert!(patch.iter().all(|(index,_,_)|*index==0));
    }
    #[test]
    fn weight_seam_roundtrips_real_area_container_in_raw_and_zlib_modes(){
        use flate2::{Compression,write::ZlibEncoder};
        use std::io::Write;
        let make_record=||{
            let c=populated_cell(0);
            let mut result=(c.blocks.iter().enumerate().fold(0u32,|flags,(i,b)|{
                if b.is_some(){flags | (1u32<<i)}else{flags}
            })).to_le_bytes().to_vec();
            for block in c.blocks.iter().flatten(){result.extend_from_slice(block);}
            result
        };
        let record=make_record();
        for compressed in [false,true]{
            let mut stream=Vec::new();
            if compressed{
                let zip=|raw:&[u8]|{
                    let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
                    enc.write_all(raw).unwrap();
                    enc.finish().unwrap()
                };
                stream.extend(3u32.to_le_bytes());
                stream.extend(zip(b"LOD"));
                for _ in 0..2{
                    stream.extend((record.len() as u32).to_le_bytes());
                    stream.extend(zip(&record));
                }
            }else{
                for _ in 0..2{
                    stream.extend((record.len() as u32).to_le_bytes());
                    stream.extend(&record);
                }
            }
            let mut bytes=if compressed{b"AERA".to_vec()}else{b"aera".to_vec()};
            bytes.extend(0u32.to_le_bytes());
            bytes.extend(b"KNHC");
            bytes.extend((stream.len() as u32).to_le_bytes());
            bytes.extend(stream);
            bytes.extend(b"KEEP");
            bytes.extend(5u32.to_le_bytes());
            bytes.extend(b"untch");
            let area=RawArea::from_bytes(bytes).unwrap();
            assert_eq!(area.cell_count(),2);
            let mut change=edit();
            change.index=1;
            let patches=plan_texture_edits(&area,&[change]).unwrap();
            assert_eq!(patches.len(),8);
            let written=area.with_cell_block_changes(&patches).unwrap();
            let reloaded=RawArea::from_bytes(written).unwrap();
            assert_eq!(reloaded.cells[1].as_ref().unwrap().normalized_weights(0,0),
                Some([0,15,0,0]));
            assert_eq!(reloaded.cells[0].as_ref().unwrap().normalized_weights(64,0),
                Some([0,15,0,0]));
            assert!(reloaded.cells[0].as_ref().unwrap()
                .compressed_weights(64,0).unwrap()[1]>0.9);
            assert_eq!(reloaded.chunks[1].data,b"untch");
            assert_eq!(area.cells[0].as_ref().unwrap().normalized_weights(64,0),
                Some([15,0,0,0]));
        }
    }
    #[test]
    fn ghost_write_refuses_unresolved_19_20_neighbour(){
        let mut cells=vec![None;256];
        let mut neighbour=populated_cell(0);
        neighbour.blocks[19]=Some(vec![0u8;2312]);
        cells[0]=Some(neighbour);
        cells[1]=Some(populated_cell(1));
        let area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None};
        let mut edit=edit();
        edit.index=1;
        assert!(plan_texture_edits(&area,&[edit]).unwrap_err().contains("19/20"));
    }
    fn bc1_error(rgb:&[[u8;3];16],encoded:[u8;8])->f64 {
        let a=u16::from_le_bytes([encoded[0],encoded[1]]);
        let b=u16::from_le_bytes([encoded[2],encoded[3]]);
        assert!(a>b,"BC1 must use opaque four-color mode");
        let (error,indices)=bc1_evaluate(rgb,a,b);
        assert_eq!(indices,u32::from_le_bytes(encoded[4..8].try_into().unwrap()),
            "BC1 palette selectors must minimize endpoint reconstruction error");
        error
    }
    fn farthest_pixel_baseline(rgb:&[[u8;3];16])->[u8;8] {
        let mut pair=(0usize,0usize);
        let mut maximum=0u32;
        for i in 0..16 {
            for j in (i+1)..16 {
                let dist=(0..3).map(|c|{
                    let d=rgb[i][c] as i32-rgb[j][c] as i32;
                    (d*d) as u32
                }).sum::<u32>();
                if dist>maximum {maximum=dist;pair=(i,j);}
            }
        }
        let (a,b)=bc1_ordered(rgb565(rgb[pair.0]),rgb565(rgb[pair.1]));
        let (_,selectors)=bc1_evaluate(rgb,a,b);
        let mut result=[0u8;8];
        result[..2].copy_from_slice(&a.to_le_bytes());
        result[2..4].copy_from_slice(&b.to_le_bytes());
        result[4..].copy_from_slice(&selectors.to_le_bytes());
        result
    }
    #[test]
    fn bc1_reencoding_keeps_original_unpainted_weights_when_preview_differs(){
        let cell=populated_cell(0);
        // Simulate a raw/preview disagreement: source BC1 is first-layer
        // red, but the selected preview before/after is second-layer green.
        let mut before=vec![0u8;CELL_RGBA_BYTES];
        for px in before.chunks_exact_mut(4){px[1]=255;}
        let mut after=before.clone();
        after[0..4].copy_from_slice(&[0,0,255,0]);
        let edit=TextureCellEdit{
            index:0,layer_ids:[10,11,12,13],weights:after,before,
        };
        let patches=make_cell_edits(&cell,&edit).unwrap();
        let mut rewritten=cell.clone();
        for (bit,data) in patches{rewritten.blocks[bit]=Some(data);}
        assert!(rewritten.compressed_weights(0,0).unwrap()[2]>0.65,
            "edited pixel must use the new blue weight");
        assert!(rewritten.compressed_weights(1,0).unwrap()[0]>0.75,
            "unpainted BC1 neighbor must retain the original red weight");
        assert_eq!(rewritten.normalized_weights(1,0),Some([15,0,0,0]),
            "untouched raw weights must stay byte-exact");
    }
    #[test]
    fn optimized_bc1_never_exceeds_original_endpoint_error(){
        let grayscale=std::array::from_fn(|i| {
            let value=(i*16) as u8;
            [value,value,value]
        });
        let four_color=std::array::from_fn(|i|
            [[255,0,0],[0,255,0],[0,0,255],[220,190,40]][i%4]);
        let subtle_tint=std::array::from_fn(|i| [
            90+(i%4) as u8*11,
            130+(i/4) as u8*13,
            170+(i%3) as u8*9,
        ]);
        let solid=[[128u8,96u8,64u8];16];
        let mut seed=0x1234_5678u32;
        let random=std::array::from_fn(|_|{
            std::array::from_fn(|_|{
                seed^=seed<<13;
                seed^=seed>>17;
                seed^=seed<<5;
                (seed>>24) as u8
            })
        });
        let patterns=[grayscale,four_color,subtle_tint,solid,random];
        let mut improvements=0usize;
        for target in &patterns {
            let legacy=bc1_error(target,farthest_pixel_baseline(target));
            let encoded=bc1_encode(*target);
            let current=bc1_error(target,encoded);
            assert!(current<=legacy+1e-10,
                "optimized BC1 error {current} > previous {legacy}");
            if current+1e-9<legacy{improvements+=1;}
            assert_eq!(encoded,bc1_encode(*target),"BC1 must be deterministic");
        }
        assert!(improvements>0,"at least one representative block must improve");
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
