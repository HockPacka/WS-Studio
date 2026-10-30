//! Direct binary WildStar AREA reader. Byte-for-byte original blocks are retained.
//! No conversion to ADT, JSON or external formats is required.
use flate2::{Decompress, FlushDecompress, Status};
use std::path::Path;

const BLOCK_SIZES: [usize;32] = [
    722,16,8450,8450,8450,4,64,16,4225,2178,4,578,1,4624,2312,8450,
    4096,2312,2312,2312,2312,1,16,16900,8,8450,21316,4096,16,8450,8450,2312,
];

#[derive(Debug,Clone)]
pub struct RawChunk {
    pub id: [u8;4],
    pub file_offset: usize,
    pub data: Vec<u8>,
}

#[derive(Debug,Clone)]
pub struct AreaCell {
    pub index: usize,
    pub flags: u32,
    pub blocks: Vec<Option<Vec<u8>>>,
    pub subchunks: Vec<RawChunk>,
}
impl AreaCell {
    pub fn block(&self, bit:usize)->Option<&[u8]>{
        self.blocks.get(bit).and_then(|b|b.as_deref())
    }
    /// 19x19 stored samples; local vertex (0,0) starts at stored (1,1).
    pub fn height(&self, x:usize, z:usize)->Option<f32>{
        if x>16 || z>16 { return None; }
        let data=self.block(0)?;
        let o=((z+1)*19+x+1)*2;
        let h=u16::from_le_bytes(data.get(o..o+2)?.try_into().ok()?);
        Some(h as f32*0.125-2048.0)
    }
    pub fn layers(&self)->Option<[u32;4]> {
        let b=self.block(1)?;
        let mut ids=[0;4];
        for (i,v) in ids.iter_mut().enumerate() {
            *v=u32::from_le_bytes(b.get(i*4..i*4+4)?.try_into().ok()?);
        }
        Some(ids)
    }
    pub fn zones(&self)->Option<[u32;4]> {
        let b=self.block(28)?;
        let mut ids=[0;4];
        for (i,v) in ids.iter_mut().enumerate() {
            *v=u32::from_le_bytes(b.get(i*4..i*4+4)?.try_into().ok()?);
        }
        Some(ids)
    }
}

#[derive(Debug,Clone)]
pub struct RawArea {
    pub version:u32,
    pub compressed:bool,
    pub original:Vec<u8>,
    pub chunks:Vec<RawChunk>,
    pub cells:Vec<Option<AreaCell>>,
    pub lod_prefix:Option<Vec<u8>>,
}
impl RawArea {
    pub fn from_path(path:&Path)->Result<Self,String>{
        let bytes=std::fs::read(path).map_err(|e|format!("{}: {e}",path.display()))?;
        Self::from_bytes(bytes)
    }
    pub fn from_bytes(original:Vec<u8>)->Result<Self,String>{
        if original.len()<8 { return Err("AREA: truncated header".into()); }
        let compressed=match &original[0..4] {
            b"aera" | b"area" | b"AREA"=>false,
            b"AERA"=>true,
            _=>return Err("AREA: bad magic (expected area/aera/AERA)".into())
        };
        let version=read_u32(&original,4)?;
        let mut cells=vec![None;256];
        let mut chunks=Vec::new();
        let mut lod_prefix=None;
        let mut pos=8usize;
        while pos < original.len() {
            if pos+8>original.len() { return Err("AREA: truncated chunk header".into()); }
            let id:[u8;4]=original[pos..pos+4].try_into().unwrap();
            let size=read_u32(&original,pos+4)? as usize;
            let end=(pos+8).checked_add(size).ok_or("AREA: chunk size overflow")?;
            if end>original.len() { return Err(format!("AREA: chunk {:?} exceeds file",id)); }
            let data=original[pos+8..end].to_vec();
            if &id==b"KNHC" || &id==b"CHNK" {
                parse_cells(&data,compressed,&mut cells,&mut lod_prefix)?;
            }
            chunks.push(RawChunk{id,file_offset:pos,data});
            pos=end;
        }
        Ok(Self{version,compressed,original,chunks,cells,lod_prefix})
    }
    pub fn cell_count(&self)->usize{
        self.cells.iter().filter(|c|c.is_some()).count()
    }
    pub fn prop_count(&self)->usize{
        self.chunks.iter().filter(|c|&c.id==b"pORP")
            .filter_map(|c|c.data.get(0..4))
            .map(|b|u32::from_le_bytes(b.try_into().unwrap()) as usize)
            .sum()
    }
}

fn read_u32(bytes:&[u8],o:usize)->Result<u32,String>{
    let b=bytes.get(o..o+4).ok_or_else(||format!("AREA: u32 out of range at {o}"))?;
    Ok(u32::from_le_bytes(b.try_into().unwrap()))
}
fn parse_cells(input:&[u8], compressed:bool,
               cells:&mut[Option<AreaCell>], lod_prefix:&mut Option<Vec<u8>>)->Result<(),String>{
    let mut pos=0usize;
    let mut last=0usize;
    let mut first=true;
    while pos<input.len() {
        let word=read_u32(input,pos)?;
        pos+=4;
        let delta=(word>>24) as usize;
        let size=(word&0x00ff_ffff) as usize;
        if size>1_048_576 { return Err("AREA: unreasonable cell size".into()); }
        let bytes=if compressed {
            let mut decoded=vec![0u8;size];
            let mut d=Decompress::new(true);
            let status=d.decompress(&input[pos..],&mut decoded,FlushDecompress::Finish)
                .map_err(|e|format!("AREA: zlib error: {e}"))?;
            if status!=Status::StreamEnd || d.total_out()!=size as u64 {
                return Err("AREA: truncated zlib cell / decoded size mismatch".into());
            }
            let consumed=d.total_in() as usize;
            if consumed==0 { return Err("AREA: empty zlib stream".into()); }
            pos=pos.checked_add(consumed).ok_or("AREA: position overflow")?;
            if pos>input.len() { return Err("AREA: compressed stream overrun".into()); }
            decoded
        } else {
            let end=pos.checked_add(size).ok_or("AREA: size overflow")?;
            let data=input.get(pos..end).ok_or("AREA: cell exceeds CHNK chunk")?;
            pos=end;
            data.to_vec()
        };
        if compressed && first {
            first=false;
            if lod_prefix.is_some(){return Err("AREA: duplicated LOD prefix".into());}
            *lod_prefix=Some(bytes);
            continue;
        }
        first=false;
        let index=last.checked_add(delta).ok_or("AREA: index overflow")?;
        if index>=256 { return Err(format!("AREA: cell index {index} out of range")); }
        last=index+1;
        if cells[index].is_some(){return Err(format!("AREA: duplicate cell index {index}")); }
        let flags=read_u32(&bytes,0)?;
        let mut offset=4usize;
        let mut blocks=vec![None;32];
        for (bit,size) in BLOCK_SIZES.iter().enumerate() {
            if flags&(1u32<<bit)==0 { continue; }
            let end=offset.checked_add(*size).ok_or("AREA: block size overflow")?;
            blocks[bit]=Some(bytes.get(offset..end)
                .ok_or_else(||format!("AREA: bit {bit} overflows cell {index}"))?.to_vec());
            offset=end;
        }
        let mut subchunks=Vec::new();
        while offset<bytes.len(){
            let id:[u8;4]=bytes.get(offset..offset+4)
                .ok_or("AREA: short subchunk id")?.try_into().unwrap();
            let length=read_u32(&bytes,offset+4)? as usize;
            let end=(offset+8).checked_add(length).ok_or("AREA: subchunk length overflow")?;
            let data=bytes.get(offset+8..end).ok_or("AREA: subchunk exceeds cell")?;
            subchunks.push(RawChunk{id,file_offset:offset,data:data.to_vec()});
            offset=end;
        }
        cells[index]=Some(AreaCell{index,flags,blocks,subchunks});
    }
    Ok(())
}

/// Raw Bevy-friendly grid, uses 17x17 visible vertices per 32-meter cell.
/// The mesh generator can directly use the height values; missing cells are holes.
#[derive(Debug)]
pub struct HeightGrid {
    pub heights:Vec<f32>,
    pub present:Vec<bool>,
    pub cells:usize,
    pub min:f32,
    pub max:f32,
}
pub fn tile_heights(area:&RawArea)->HeightGrid{
    let mut heights=vec![0f32;257*257];
    let mut present=vec![false;257*257];
    let mut min=f32::MAX;
    let mut max=f32::MIN;
    let mut valid=0;
    for cell in area.cells.iter().flatten(){
        if cell.block(0).is_none(){continue;}
        valid+=1;
        for z in 0..17 {
            for x in 0..17 {
                if let Some(h)=cell.height(x,z) {
                    let gx=(cell.index%16)*16+x;
                    let gz=(cell.index/16)*16+z;
                    let i=gz*257+gx;
                    if !present[i] {
                        present[i]=true;
                        heights[i]=h;
                        min=min.min(h);
                        max=max.max(h);
                    }
                }
            }
        }
    }
    if valid==0 {min=0.;max=0.;}
    HeightGrid{heights,present,cells:valid,min,max}
}

#[cfg(test)]
mod tests{
    use super::*;
    fn chunk(id:&[u8;4],contents:&[u8])->Vec<u8>{
        let mut v=Vec::new();v.extend(id);v.extend((contents.len() as u32).to_le_bytes());v.extend(contents);v
    }
    fn cell()->Vec<u8> {
        let mut v=Vec::new();
        v.extend((1u32 | 1u32<<1 | 1u32<<28).to_le_bytes());
        for _ in 0..361 { v.extend(16400u16.to_le_bytes());}
        for i in [9u32,3,2,1] {v.extend(i.to_le_bytes());}
        for i in [101u32,102,0,0] {v.extend(i.to_le_bytes());}
        v
    }
    #[test]
    fn real_raw_demo_hills(){
        let data=include_bytes!("../../WildStarModelStudio/demo/Hills.area").to_vec();
        let area=RawArea::from_bytes(data).unwrap();
        assert_eq!(area.version,0);
        assert_eq!(area.cell_count(),256);
        assert!(area.cells.iter().flatten().all(|x|x.block(0).is_some()));
        let grid=tile_heights(&area);
        assert!(grid.present.iter().all(|v|*v));
    }
    #[test]
    fn synthetic_regular_and_raw_metadata(){
        let cell=cell();
        let mut chnk=(cell.len() as u32).to_le_bytes().to_vec();
        chnk.extend(cell);
        let mut data=b"aera".to_vec();
        data.extend(0u32.to_le_bytes());
        data.extend(chunk(b"KNHC",&chnk));
        data.extend(chunk(b"TEST",&[0x1,0x2,0x3]));
        let area=RawArea::from_bytes(data.clone()).unwrap();
        assert_eq!(area.original,data);
        assert_eq!(area.cell_count(),1);
        let c=area.cells[0].as_ref().unwrap();
        assert_eq!(c.layers(),Some([9,3,2,1]));
        assert_eq!(c.zones(),Some([101,102,0,0]));
        assert!((c.height(0,0).unwrap()-2.).abs()<f32::EPSILON);
        assert_eq!(area.chunks[1].data,vec![1,2,3]);
        let heights=tile_heights(&area);
        assert!(heights.present[0]);
        assert!(!heights.present[128*257+128]);
    }
    #[test]
    fn compressed_lod(){
        use flate2::{Compression,write::ZlibEncoder};
        use std::io::Write;
        let compress=|data:&[u8]|{
            let mut enc=ZlibEncoder::new(Vec::new(),Compression::default());
            enc.write_all(data).unwrap();
            enc.finish().unwrap()
        };
        let cell=cell();
        let mut contents=(1024u32).to_le_bytes().to_vec();
        contents.extend(compress(&vec![0u8;1024]));
        contents.extend((cell.len() as u32).to_le_bytes());
        contents.extend(compress(&cell));
        let mut file=b"AERA".to_vec();file.extend(0u32.to_le_bytes());
        file.extend(chunk(b"KNHC",&contents));
        let area=RawArea::from_bytes(file).unwrap();
        assert!(area.compressed);
        assert_eq!(area.lod_prefix.as_ref().unwrap().len(),1024);
        assert_eq!(area.cell_count(),1);
    }
    #[test]
    fn reject_truncated(){
        assert!(RawArea::from_bytes(b"aera\x00\x00\x00\x00KNHC\xff\xff\xff\xff".to_vec()).is_err());
    }
}
