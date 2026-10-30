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
    if payload.len()<8{return Err("pORP: header shorter than 8 bytes".into());}
    let count=u32_at(payload,0).unwrap() as usize;
    let end=count.checked_mul(104).and_then(|v|v.checked_add(8))
        .ok_or("pORP: record count overflow")?;
    if count>2_000_000 || end>payload.len(){
        return Err("pORP: record count exceeds payload".into());
    }
    let mut result=Vec::with_capacity(count);
    for index in 0..count{
        let from=8+index*104;
        let raw_record:[u8;104]=payload[from..from+104].try_into()
            .map_err(|_|"pORP: incomplete record")?;
        let name_offset=u32_at(&raw_record,16).unwrap();
        let mut rotation=[0f32;4];
        let mut position=[0f32;3];
        for (i,value) in rotation.iter_mut().enumerate(){*value=f32_at(&raw_record,28+i*4).unwrap();}
        for (i,value) in position.iter_mut().enumerate(){*value=f32_at(&raw_record,44+i*4).unwrap();}
        result.push(AreaProp{
            index,model_path:utf16_name(payload,name_offset as usize,end),
            scale:f32_at(&raw_record,24).unwrap(),
            rotation_xyzw:rotation,position_xyz:position,
            tint:u32_at(&raw_record,76).unwrap(),name_offset,raw_record,
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
