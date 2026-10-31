//! Semantic, read-only decoding layered over the 32 preserved raw blocks.
//! Documented against WS-Tools/docs/area_format.md and area_inspect.py.
//! Unconfirmed fields are explicitly labelled unresolved.
use super::{AreaCell,RawArea};

pub fn block_description(bit:usize)->&'static str {
    match bit {
        0=>"19x19 u16 heightmap; metres=raw/8-2048",
        1=>"Four WorldLayer u32 IDs",
        2=>"65x65 RGBA nibble authoring weights (non-normalized)",
        3=>"65x65 RGB565 terrain color raster",
        6=>"2x2 corners with four WorldSky IDs per corner",
        7=>"2x2 corners with four WorldSky weights per corner",
        13=>"17x17 BC2/DXT3 texture blocks (alpha role unresolved)",
        14=>"17x17 BC1 texture blocks (role unresolved)",
        15=>"65x65 RGB565 alternative map (role unresolved)",
        16=>"64x64 road, WorldZone selector and clutter suppression flags",
        17=>"17x17 BC1 terrain layer base weights",
        18=>"17x17 BC1 signed weight correction",
        19|20=>"17x17 BC1 partner to bit29 (partly unresolved)",
        21=>"One byte, observed zero (role unresolved)",
        26=>"73x73x4 RGBA raster (role unresolved)",
        27=>"64x64 packed four 2-bit clutter selectors",
        28=>"Four WorldZone u32 IDs",
        29=>"65x65 4x4-bit normalized terrain layer weights",
        31=>"17x17 BC1 alternative texture (role unresolved)",
        _=>"Unresolved raw block, payload preserved",
    }
}
pub fn block_expected_bytes(bit:usize)->Option<usize>{
    const SIZES:[usize;32]=[
        722,16,8450,8450,8450,4,64,16,4225,2178,4,578,1,4624,2312,8450,
        4096,2312,2312,2312,2312,1,16,16900,8,8450,21316,4096,16,8450,8450,2312
    ];
    SIZES.get(bit).copied()
}
fn u32_at(b:&[u8],o:usize)->Option<u32>{
    Some(u32::from_le_bytes(b.get(o..o+4)?.try_into().ok()?))
}
fn f32_at(b:&[u8],o:usize)->Option<f32>{
    Some(f32::from_bits(u32_at(b,o)?))
}

#[derive(Debug,Clone)]
pub struct ZoneSummary {
    pub ids:[u32;4],
    pub slot_counts:[usize;4],
    pub dominant_id:Option<u32>,
    pub road_samples:usize,
    pub suppress_clutter_samples:usize,
}
#[derive(Debug,Clone)]
pub struct AreaProp {
    pub index:usize,
    pub model_path:Option<String>,
    pub scale:f32,
    pub rotation_xyzw:[f32;4],
    pub position_xyz:[f32;3],
    pub tint:u32,
    pub name_offset:u32,
    /// Complete original record, including all currently unknown bytes.
    pub raw_record:[u8;104],
}
fn utf16_name(data:&[u8],start:usize,min_start:usize)->Option<String>{
    if start<min_start || start>=data.len() || start%2!=0{return None;}
    let end=data.len().min(start.saturating_add(2048));
    let mut chars=Vec::new();
    for p in (start..end.saturating_sub(1)).step_by(2) {
        let unit=u16::from_le_bytes([data[p],data[p+1]]);
        if unit==0{return String::from_utf16(&chars).ok();}
        chars.push(unit);
    }
    None
}
fn decode_props(payload:&[u8])->Result<Vec<AreaProp>,String>{
    if payload.len()<4{return Err("pORP: header shorter than 4 bytes".into());}
    let count=u32_at(payload,0).unwrap() as usize;
    let string_table_start=count.checked_mul(104).and_then(|v|v.checked_add(4))
        .ok_or("pORP: record count overflow")?;
    if count>2_000_000 || string_table_start>payload.len(){
        return Err("pORP: record count exceeds payload".into());
    }
    let mut result=Vec::with_capacity(count);
    for index in 0..count{
        let from=4+index*104;
        let raw_record:[u8;104]=match payload.get(from..from+104).and_then(|s| s.try_into().ok()) {
            Some(r) => r,
            None => break,
        };
        let name_offset=u32_at(&raw_record,20).unwrap_or(0);
        let mut rotation=[0f32;4];
        let mut position=[0f32;3];
        for (i,value) in rotation.iter_mut().enumerate(){*value=f32_at(&raw_record,32+i*4).unwrap_or(0.0);}
        for (i,value) in position.iter_mut().enumerate(){*value=f32_at(&raw_record,48+i*4).unwrap_or(0.0);}
        result.push(AreaProp{
            index,model_path:utf16_name(payload,name_offset as usize,string_table_start),
            scale:f32_at(&raw_record,28).unwrap_or(1.0),
            rotation_xyzw:rotation,position_xyz:position,
            tint:u32_at(&raw_record,80).unwrap_or(0),name_offset,raw_record,
        });
    }
    Ok(result)
}

impl RawArea {
    pub fn prop_placements(&self)->Result<Vec<AreaProp>,String>{
        let mut placements=Vec::new();
        for chunk in &self.chunks{
            if &chunk.id==b"pORP"{placements.extend(decode_props(&chunk.data)?);}
        }
        Ok(placements)
    }
    pub fn block_occurrences(&self)->[usize;32]{
        let mut counts=[0usize;32];
        for cell in self.cells.iter().flatten(){
            for i in cell.active_bits(){counts[i]+=1;}
        }
        counts
    }
}
impl AreaCell {
    pub fn active_bits(&self)->impl Iterator<Item=usize>+'_{
        (0..32).filter(|&i|self.block(i).is_some())
    }
    /// 65x65 bit29 nibble weights, four channel values each 0..15.
    pub fn normalized_weights(&self,x:usize,z:usize)->Option<[u8;4]>{
        if x>=65||z>=65{return None;}
        let b=self.block(29)?;
        let n=u16::from_le_bytes(b.get((z*65+x)*2..(z*65+x)*2+2)?.try_into().ok()?);
        Some([(n&15) as u8,((n>>4)&15) as u8,
            ((n>>8)&15) as u8,((n>>12)&15) as u8])
    }
    /// Bit2 weights are NOT normalized: preserve original nibbles.
    pub fn authoring_weights(&self,x:usize,z:usize)->Option<[u8;4]>{
        if x>=65||z>=65{return None;}
        let b=self.block(2)?;
        let n=u16::from_le_bytes(b.get((z*65+x)*2..(z*65+x)*2+2)?.try_into().ok()?);
        Some([(n&15) as u8,((n>>4)&15) as u8,
            ((n>>8)&15) as u8,((n>>12)&15) as u8])
    }
    /// 65x65 bit3 RGB565 map; exact packed 16bit source remains preserved.
    pub fn color_rgb565(&self,x:usize,z:usize)->Option<[u8;3]>{
        if x>=65||z>=65{return None;}
        let b=self.block(3)?;
        let n=u16::from_le_bytes(b.get((z*65+x)*2..(z*65+x)*2+2)?.try_into().ok()?);
        let r=((n>>11)&31) as u8;let g=((n>>5)&63) as u8;let b=(n&31) as u8;
        Some([(r<<3)|(r>>2),(g<<2)|(g>>4),(b<<3)|(b>>2)])
    }
    /// Terrain macro color tint (Bit 3 RGB565 or Bit 13 BC2).
    pub fn terrain_color(&self,x:usize,z:usize)->Option<[u8;3]>{
        self.color_rgb565(x,z).or_else(||self.color_bc2(x,z))
    }
    /// Decompress bit 13 BC2/DXT3 RGB independently from bit 3.
    /// The 4-bit alpha has an unknown terrain meaning and is exposed separately.
    pub fn color_bc2(&self,x:usize,z:usize)->Option<[u8;3]>{
        if x>=65||z>=65{return None;}
        let b=self.block(13)?;
        if b.len()<4624{return None;}
        let bx=(x/4).min(16);
        let by=(z/4).min(16);
        let px=(x%4).min(3);
        let py=(z%4).min(3);
        let off=(by*17+bx)*16;
        let block=&b[off..off+16];
        let c0=u16::from_le_bytes([block[8],block[9]]);
        let c1=u16::from_le_bytes([block[10],block[11]]);
        let indices=u32::from_le_bytes([block[12],block[13],block[14],block[15]]);
        let shift=(py*4+px)*2;
        let ci=((indices>>shift)&3) as usize;
        let r0=((c0>>11)&31) as u8;let g0=((c0>>5)&63) as u8;let b0=(c0&31) as u8;
        let r1=((c1>>11)&31) as u8;let g1=((c1>>5)&63) as u8;let b1=(c1&31) as u8;
        let rgb0=[(r0<<3)|(r0>>2),(g0<<2)|(g0>>4),(b0<<3)|(b0>>2)];
        let rgb1=[(r1<<3)|(r1>>2),(g1<<2)|(g1>>4),(b1<<3)|(b1>>2)];
        let res=match ci {
            0=>rgb0,
            1=>rgb1,
            2=>[
                ((2*rgb0[0] as u16+rgb1[0] as u16)/3) as u8,
                ((2*rgb0[1] as u16+rgb1[1] as u16)/3) as u8,
                ((2*rgb0[2] as u16+rgb1[2] as u16)/3) as u8,
            ],
            _=>[
                ((rgb0[0] as u16+2*rgb1[0] as u16)/3) as u8,
                ((rgb0[1] as u16+2*rgb1[1] as u16)/3) as u8,
                ((rgb0[2] as u16+2*rgb1[2] as u16)/3) as u8,
            ],
        };
        Some(res)
    }
    /// Raw bit 13 BC2 alpha sample, 0..255, without attributing semantics.
    /// BC2 explicitly packs 16 four-bit alphas in bytes 0..7 per 4x4 block.
    pub fn bc2_color_alpha(&self,x:usize,z:usize)->Option<u8>{
        if x>=65||z>=65{return None;}
        let bytes=self.block(13)?;
        let bx=(x/4).min(16);
        let bz=(z/4).min(16);
        let index=(z%4)*4+(x%4);
        let offset=(bz*17+bx)*16+index/2;
        let byte=*bytes.get(offset)?;
        let nibble=if index%2==0 {byte&15}else{byte>>4};
        Some(nibble*17)
    }
    /// Compressed weights from Bit 17 (base weights BC1) + Bit 18 (signed corrections BC1).
    pub fn compressed_weights(&self,x:usize,z:usize)->Option<[f32;4]>{
        if x>=65||z>=65{return None;}
        let b17=self.block(17)?;
        if b17.len()<2312{return None;}
        let bx=(x/4).min(16);
        let by=(z/4).min(16);
        let px=(x%4).min(3);
        let py=(z%4).min(3);
        let off=(by*17+bx)*8;
        let decode_bc1_rgb=|blk:&[u8]|->[f32;3]{
            let c0=u16::from_le_bytes([blk[0],blk[1]]);
            let c1=u16::from_le_bytes([blk[2],blk[3]]);
            let indices=u32::from_le_bytes([blk[4],blk[5],blk[6],blk[7]]);
            let shift=(py*4+px)*2;
            let ci=(indices>>shift)&3;
            let r0=((c0>>11)&31) as f32/31.0;
            let g0=((c0>>5)&63) as f32/63.0;
            let b0=(c0&31) as f32/31.0;
            let r1=((c1>>11)&31) as f32/31.0;
            let g1=((c1>>5)&63) as f32/63.0;
            let b1=(c1&31) as f32/31.0;
            match ci {
                0=>[r0,g0,b0],
                1=>[r1,g1,b1],
                2=>[(2.0*r0+r1)/3.0,(2.0*g0+g1)/3.0,(2.0*b0+b1)/3.0],
                _=>[(r0+2.0*r1)/3.0,(g0+2.0*g1)/3.0,(b0+2.0*b1)/3.0],
            }
        };
        let base=decode_bc1_rgb(&b17[off..off+8]);
        let mut r=base[0];
        let mut g=base[1];
        let mut b=base[2];
        if let Some(b18)=self.block(18){
            if b18.len()>=2312{
                let corr=decode_bc1_rgb(&b18[off..off+8]);
                let cr=(corr[0]*(31.0/15.0)-1.0)*0.5;
                let cg=(corr[1]*(63.0/31.0)-1.0)*0.5;
                let cb=(corr[2]*(31.0/15.0)-1.0)*0.5;
                r=(r+cr).clamp(0.0,1.0);
                g=(g+cg).clamp(0.0,1.0);
                b=(b+cb).clamp(0.0,1.0);
            }
        }
        let a=(1.0-(r+g+b)).clamp(0.0,1.0);
        let sum=r+g+b+a;
        if sum>0.0001{Some([r/sum,g/sum,b/sum,a/sum])}else{Some([1.0,0.0,0.0,0.0])}
    }
    pub fn sky_ids(&self)->Option<[[u32;4];4]>{
        let b=self.block(6)?;
        let mut result=[[0u32;4];4];
        for (corner,row) in result.iter_mut().enumerate(){
            for (slot,val) in row.iter_mut().enumerate(){
                *val=u32_at(b,corner*16+slot*4)?;
            }
        }
        Some(result)
    }
    pub fn sky_weights(&self)->Option<[[u8;4];4]>{
        let b=self.block(7)?;
        let mut result=[[0u8;4];4];
        for (corner,row) in result.iter_mut().enumerate(){
            row.copy_from_slice(b.get(corner*4..corner*4+4)?);
        }
        Some(result)
    }
    pub fn zone_flag(&self,x:usize,z:usize)->Option<u8>{
        if x>=64||z>=64{return None;}
        self.block(16)?.get(z*64+x).copied()
    }
    pub fn zone_id_at(&self,x:usize,z:usize)->Option<u32>{
        let slot=(self.zone_flag(x,z)?>>3)&3;
        self.zones().map(|ids|ids[slot as usize])
    }
    /// 2-bit selector for the specified layer slot within the 64x64 map.
    pub fn clutter_selector(&self,x:usize,z:usize,layer:usize)->Option<u8>{
        if x>=64||z>=64||layer>=4{return None;}
        let byte=*self.block(27)?.get(z*64+x)?;
        Some((byte>>(2*layer))&3)
    }
    pub fn clutter_selector_histogram(&self)->Option<[[usize;4];4]>{
        let raw=self.block(27)?;
        let mut counts=[[0usize;4];4];
        for &byte in raw {
            for (layer,slots) in counts.iter_mut().enumerate(){
                slots[((byte>>(2*layer))&3) as usize]+=1;
            }
        }
        Some(counts)
    }
    pub fn zone_summary(&self)->Option<ZoneSummary>{
        let ids=self.zones()?;
        let mut slot_counts=[0usize;4];
        let mut road_samples=0;
        let mut suppress_clutter_samples=0;
        if let Some(flags)=self.block(16){
            for &b in flags {
                slot_counts[((b>>3)&3) as usize]+=1;
                if b&1!=0 {road_samples+=1;}
                if b&0x20!=0{suppress_clutter_samples+=1;}
            }
        }
        let dominant_id=if self.block(16).is_some(){
            (0..4).filter(|&slot|ids[slot]!=0)
                .max_by_key(|&slot|slot_counts[slot]).map(|slot|ids[slot])
        }else{None};
        Some(ZoneSummary{ids,slot_counts,dominant_id,road_samples,suppress_clutter_samples})
    }
}


#[cfg(test)]
mod tests {
    use super::*;
    fn sample_cell() -> AreaCell {
        let mut blocks=vec![None;32];
        blocks[1]=Some([11u32,12,13,14].into_iter().flat_map(u32::to_le_bytes).collect());
        blocks[28]=Some([101u32,102,103,104].into_iter().flat_map(u32::to_le_bytes).collect());
        let mut flags=vec![0u8;4096];
        flags[0]=0x20|(2<<3)|1;
        flags[1]=1<<3;
        blocks[16]=Some(flags);
        blocks[27]=Some(vec![0b11100100u8;4096]);
        blocks[6]=Some((0..16u32).flat_map(u32::to_le_bytes).collect());
        blocks[7]=Some((0..16u8).collect());
        blocks[29]=Some(vec![0x21,0xC0].into_iter().cycle().take(8450).collect());
        blocks[2]=Some(vec![0xF0,0x00].into_iter().cycle().take(8450).collect());
        blocks[3]=Some(vec![0x00,0xF8].into_iter().cycle().take(8450).collect());
        AreaCell{index:0,flags:0,blocks,subchunks:Vec::new()}
    }
    #[test]
    fn cell_metadata_decoding() {
        let c=sample_cell();
        assert_eq!(c.layers(),Some([11,12,13,14]));
        assert_eq!(c.zone_id_at(0,0),Some(103));
        assert_eq!(c.zone_id_at(1,0),Some(102));
        let zone=c.zone_summary().unwrap();
        assert_eq!(zone.road_samples,1);
        assert_eq!(zone.suppress_clutter_samples,1);
        assert_eq!(zone.slot_counts.iter().sum::<usize>(),4096);
        assert_eq!(c.clutter_selector(0,0,0),Some(0));
        assert_eq!(c.clutter_selector(0,0,1),Some(1));
        assert_eq!(c.clutter_selector(0,0,2),Some(2));
        assert_eq!(c.clutter_selector(0,0,3),Some(3));
        assert_eq!(c.normalized_weights(0,0),Some([1,2,0,12]));
        assert_eq!(c.authoring_weights(0,0),Some([0,15,0,0]));
        assert_eq!(c.color_rgb565(0,0),Some([255,0,0]));
        assert_eq!(c.terrain_color(0,0),Some([255,0,0]));
        assert_eq!(c.sky_ids().unwrap()[0],[0,1,2,3]);
        assert_eq!(c.sky_weights().unwrap()[3],[12,13,14,15]);
        assert!(c.zone_flag(64,0).is_none());
        assert_eq!(c.clutter_selector_histogram().unwrap()[3][3],4096);
    }
    #[test]
    fn props_path_and_transform() {
        let mut data=vec![0u8;108];
        data[..4].copy_from_slice(&1u32.to_le_bytes());
        data[24..28].copy_from_slice(&108u32.to_le_bytes()); // rec[20..24] = name_offset
        data[32..36].copy_from_slice(&1.5f32.to_le_bytes()); // rec[28..32] = scale
        data[36..40].copy_from_slice(&0.25f32.to_le_bytes()); // rec[32..36] = rot x
        data[52..56].copy_from_slice(&125f32.to_le_bytes()); // rec[48..52] = pos x
        data[84..88].copy_from_slice(&0x12345678u32.to_le_bytes()); // rec[80..84] = tint
        for letter in "Art/Creature/Test.m3".encode_utf16(){
            data.extend(letter.to_le_bytes());
        }
        data.extend(0u16.to_le_bytes());
        let props=decode_props(&data).unwrap();
        assert_eq!(props.len(),1);
        assert_eq!(props[0].model_path.as_deref(),Some("Art/Creature/Test.m3"));
        assert_eq!(props[0].scale,1.5);
        assert_eq!(props[0].position_xyz[0],125.);
        assert_eq!(props[0].tint,0x12345678);
        assert_eq!(props[0].raw_record.len(),104);
        data[..4].copy_from_slice(&u32::MAX.to_le_bytes());
        assert!(decode_props(&data).is_err());
    }
    #[test]
    fn compressed_bc2_color_and_bc1_weights() {
        let mut b13 = vec![0u8; 4624];
        // 17x17 blocks, each 16 bytes. Test block 0:
        // bytes 0..7 alpha, 8..11 RGB565 endpoints, 12..15 indices
        // c0 = pure red (0xF800), c1 = pure green (0x07E0), index 0 = 0 -> c0
        b13[0]=0xF2; // first pixel alpha=2, second alpha=15
        b13[8..10].copy_from_slice(&0xF800u16.to_le_bytes());
        b13[10..12].copy_from_slice(&0x07E0u16.to_le_bytes());
        let mut c = AreaCell {
            index: 0,
            flags: 1 << 13,
            blocks: vec![None; 32],
            subchunks: Vec::new(),
        };
        c.blocks[13] = Some(b13);
        assert_eq!(c.terrain_color(0, 0), Some([255, 0, 0]));
        assert_eq!(c.bc2_color_alpha(0,0),Some(34));
        assert_eq!(c.bc2_color_alpha(1,0),Some(255));
        assert_eq!(c.color_bc2(0,0),Some([255,0,0]));
        assert_eq!(c.bc2_color_alpha(65,0),None);
        let mut raw565=vec![0u8;8450];
        raw565[..2].copy_from_slice(&0x001Fu16.to_le_bytes());
        c.blocks[3]=Some(raw565);
        c.flags|=1<<3;
        assert_eq!(c.terrain_color(0,0),Some([0,0,255])); // bit3 priority
        assert_eq!(c.color_bc2(0,0),Some([255,0,0])); // independent bit13
        assert_eq!(c.bc2_color_alpha(0,0),Some(34));


        let mut b17 = vec![0u8; 2312];
        // 17x17 blocks, each 8 bytes. c0 = pure red, c1 = black, index 0 = 0
        b17[0..2].copy_from_slice(&0xF800u16.to_le_bytes());
        c.flags |= 1 << 17;
        c.blocks[17] = Some(b17);
        let w = c.compressed_weights(0, 0).unwrap();
        assert!(w[0] > 0.9);
    }
    #[test]
    fn real_tile_is_still_readable() {
        let bytes=include_bytes!("../../../../../WildStarModelStudio/demo/Hills.area");
        let area=RawArea::from_bytes(bytes.to_vec()).unwrap();
        assert_eq!(area.cell_count(),256);
        assert_eq!(area.block_occurrences()[0],256);
        assert_eq!(area.prop_placements().unwrap().len(),0);
    }
}
