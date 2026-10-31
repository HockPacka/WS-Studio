//! Direct binary WildStar AREA reader. Byte-for-byte original blocks are retained.
//! No conversion to ADT, JSON or external formats is required.
use flate2::{Decompress, FlushDecompress, Status};
use std::path::Path;
pub mod metadata;
pub use metadata::{AreaProp, ZoneSummary, block_description, block_expected_bytes};

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
    /// Parse GtAW water bodies from cell subchunks (FUN_1402e5720).
    pub fn water_bodies(&self) -> Vec<WaterBody> {
        let mut bodies = Vec::new();
        for chunk in &self.subchunks {
            if &chunk.id == b"GtAW" || &chunk.id == b"WATG" {
                let Some(bc_bytes) = chunk.data.get(0..4).and_then(|s| s.try_into().ok()) else { continue; };
                let body_count = u32::from_le_bytes(bc_bytes) as usize;
                let mut pos = 4usize;
                for _ in 0..body_count {
                    let Some(hdr_bytes) = chunk.data.get(pos..pos + 80).and_then(|s| s.try_into().ok()) else { break; };
                    let header: [u8; 80] = hdr_bytes;
                    let min = [
                        f32::from_le_bytes(header[0..4].try_into().unwrap_or([0; 4])),
                        f32::from_le_bytes(header[4..8].try_into().unwrap_or([0; 4])),
                        f32::from_le_bytes(header[8..12].try_into().unwrap_or([0; 4])),
                    ];
                    let max = [
                        f32::from_le_bytes(header[12..16].try_into().unwrap_or([0; 4])),
                        f32::from_le_bytes(header[16..20].try_into().unwrap_or([0; 4])),
                        f32::from_le_bytes(header[20..24].try_into().unwrap_or([0; 4])),
                    ];
                    let index_count = u32::from_le_bytes(header[64..68].try_into().unwrap_or([0; 4])) as usize;
                    let vertex_count = u32::from_le_bytes(header[68..72].try_into().unwrap_or([0; 4])) as usize;
                    pos += 80;

                    let idx_bytes = index_count.checked_mul(4).unwrap_or(usize::MAX);
                    let vtx_bytes = vertex_count.checked_mul(72).unwrap_or(usize::MAX);
                    if pos.checked_add(idx_bytes).and_then(|p| p.checked_add(vtx_bytes)).map(|e| e > chunk.data.len()).unwrap_or(true) {
                        break;
                    }

                    let mut indices = Vec::with_capacity(index_count);
                    for i in 0..index_count {
                        let ip = pos + i * 4;
                        if let Some(ib) = chunk.data.get(ip..ip + 4).and_then(|s| s.try_into().ok()) {
                            indices.push(u32::from_le_bytes(ib));
                        }
                    }
                    pos += idx_bytes;

                    let mut vertices = Vec::with_capacity(vertex_count);
                    for i in 0..vertex_count {
                        let vp = pos + i * 72;
                        if let Some(rb) = chunk.data.get(vp..vp + 72).and_then(|s| s.try_into().ok()) {
                            let raw: [u8; 72] = rb;
                            let position = [
                                f32::from_le_bytes(raw[0..4].try_into().unwrap_or([0; 4])),
                                f32::from_le_bytes(raw[4..8].try_into().unwrap_or([0; 4])),
                                f32::from_le_bytes(raw[8..12].try_into().unwrap_or([0; 4])),
                            ];
                            let normal = [
                                f32::from_le_bytes(raw[12..16].try_into().unwrap_or([0; 4])),
                                f32::from_le_bytes(raw[16..20].try_into().unwrap_or([0; 4])),
                                f32::from_le_bytes(raw[20..24].try_into().unwrap_or([0; 4])),
                            ];
                            let uv = [
                                f32::from_le_bytes(raw[48..52].try_into().unwrap_or([0; 4])),
                                f32::from_le_bytes(raw[52..56].try_into().unwrap_or([0; 4])),
                            ];
                            vertices.push(WaterVertex { position, normal, uv, raw });
                        }
                    }
                    pos += vtx_bytes;

                    bodies.push(WaterBody { header, min, max, indices, vertices });
                }
            }
        }
        bodies
    }
}

#[derive(Debug, Clone)]
pub struct WaterVertex {
    pub position: [f32; 3],
    pub normal: [f32; 3],
    pub uv: [f32; 2],
    pub raw: [u8; 72],
}

#[derive(Debug, Clone)]
pub struct WaterBody {
    pub header: [u8; 80],
    pub min: [f32; 3],
    pub max: [f32; 3],
    pub indices: Vec<u32>,
    pub vertices: Vec<WaterVertex>,
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
    pub fn all_water_bodies(&self) -> Vec<WaterBody> {
        self.cells.iter().flatten().flat_map(|c| c.water_bodies()).collect()
    }
    /// Build a new AREA byte stream, patching height samples in affected cells only.
    /// All unknown payloads, unrelated chunks, and untouched compressed streams
    /// are copied byte-for-byte. Changes use global 257x257 mesh coordinates.
    /// Editing an absent cell or a missing height vertex is rejected.
    pub fn with_height_changes(&self, changes: &[(usize, usize, f32)]) -> Result<Vec<u8>, String> {
        use std::collections::{BTreeMap, HashMap};
        use flate2::{Compression, write::ZlibEncoder};
        use std::io::Write;

        if changes.is_empty() { return Ok(self.original.clone()); }
        let mut samples = HashMap::<usize,u16>::new();
        for &(x,z,height) in changes {
            if x > 256 || z > 256 || !height.is_finite() {
                return Err("AREA: invalid height sample position/value".into());
            }
            let cell_x = if x == 256 { 15 } else { x / 16 };
            let cell_z = if z == 256 { 15 } else { z / 16 };
            if self.cells[cell_z * 16 + cell_x].as_ref()
                .and_then(|cell|cell.block(0)).is_none() {
                return Err(format!("AREA: height sample ({x},{z}) belongs to a missing cell"));
            }
            let raw = ((height + 2048.0) * 8.0).round().clamp(0.0, 65535.0) as u16;
            samples.insert(z * 257 + x, raw);
        }
        let mut patch_by_cell = BTreeMap::<usize,Vec<(usize,u16)>>::new();
        for cell in self.cells.iter().flatten() {
            let Some(block) = cell.block(0) else { continue; };
            for rz in 0..19usize {
                for rx in 0..19usize {
                    let gx = cell.index % 16 * 16 + rx;
                    let gz = cell.index / 16 * 16 + rz;
                    // Stored sample (1,1) is the first visible mesh vertex;
                    // include the one-sample ghost border when it belongs to this tile.
                    let Some(gx) = gx.checked_sub(1) else { continue; };
                    let Some(gz) = gz.checked_sub(1) else { continue; };
                    if gx > 256 || gz > 256 { continue; }
                    let Some(&raw) = samples.get(&(gz * 257 + gx)) else { continue; };
                    let offset = (rz * 19 + rx) * 2;
                    let old = block.get(offset..offset + 2)
                        .ok_or("AREA: height block truncated")?;
                    if old != raw.to_le_bytes() {
                        patch_by_cell.entry(cell.index).or_default().push((offset, raw));
                    }
                }
            }
        }
        if patch_by_cell.is_empty() { return Ok(self.original.clone()); }
        let mut output = self.original.get(..8).ok_or("AREA: missing header")?.to_vec();
        let mut found = std::collections::BTreeSet::new();
        for chunk in &self.chunks {
            if &chunk.id != b"KNHC" && &chunk.id != b"CHNK" {
                let end = chunk.file_offset + 8 + chunk.data.len();
                output.extend_from_slice(self.original.get(chunk.file_offset..end)
                    .ok_or("AREA: invalid original chunk offset")?);
                continue;
            }
            let input = chunk.data.as_slice();
            let mut rebuilt = Vec::with_capacity(input.len());
            let mut pos = 0usize;
            let mut last = 0usize;
            let mut first = true;
            while pos < input.len() {
                let word = read_u32(input, pos)?;
                let start = pos;
                pos += 4;
                let delta = (word >> 24) as usize;
                let len = (word & 0x00ff_ffff) as usize;
                if len > 1_048_576 { return Err("AREA: unreasonable cell payload".into()); }
                let (decoded, end) = if self.compressed {
                    let mut data = vec![0u8; len];
                    let mut decoder = Decompress::new(true);
                    let status = decoder.decompress(&input[pos..], &mut data, FlushDecompress::Finish)
                        .map_err(|err| format!("AREA: zlib write scan failed: {err}"))?;
                    if status != Status::StreamEnd || decoder.total_out() != len as u64 {
                        return Err("AREA: compressed cell length mismatch".into());
                    }
                    (data, pos + decoder.total_in() as usize)
                } else {
                    let end = pos.checked_add(len).ok_or("AREA: cell size overflow")?;
                    (input.get(pos..end).ok_or("AREA: truncated cell")?.to_vec(), end)
                };
                if end > input.len() { return Err("AREA: cell stream overrun".into()); }
                pos = end;
                if self.compressed && first {
                    // First compressed record holds the LOD prefix, not a cell.
                    rebuilt.extend_from_slice(&input[start..end]);
                    first = false;
                    continue;
                }
                first = false;
                let index = last.checked_add(delta).ok_or("AREA: cell index overflow")?;
                if index >= 256 { return Err("AREA: invalid cell index".into()); }
                last = index + 1;
                if let Some(patches) = patch_by_cell.get(&index) {
                    let mut altered = decoded;
                    let flags = read_u32(&altered, 0)?;
                    if flags & 1 == 0 { return Err("AREA: target cell has no height block".into()); }
                    for &(offset, raw) in patches {
                        let range = altered.get_mut(4 + offset..4 + offset + 2)
                            .ok_or("AREA: target height offset out of bounds")?;
                        range.copy_from_slice(&raw.to_le_bytes());
                    }
                    if self.compressed {
                        rebuilt.extend_from_slice(&input[start..start+4]);
                        let mut encoder = ZlibEncoder::new(Vec::new(), Compression::default());
                        encoder.write_all(&altered).map_err(|e| e.to_string())?;
                        rebuilt.extend(encoder.finish().map_err(|e| e.to_string())?);
                    } else {
                        rebuilt.extend_from_slice(&input[start..start+4]);
                        rebuilt.extend_from_slice(&altered);
                    }
                    found.insert(index);
                } else {
                    rebuilt.extend_from_slice(&input[start..end]);
                }
            }
            output.extend_from_slice(&chunk.id);
            output.extend_from_slice(&u32::try_from(rebuilt.len())
                .map_err(|_| "AREA: chunk exceeds u32 size")?.to_le_bytes());
            output.extend_from_slice(&rebuilt);
        }
        if found.len() != patch_by_cell.len() {
            return Err("AREA: not all edited cells occurred in the source stream".into());
        }
        let verified = Self::from_bytes(output.clone())?;
        for (&index, patches) in &patch_by_cell {
            let cell = verified.cells[index].as_ref().ok_or("AREA: edited cell vanished")?;
            let block = cell.block(0).ok_or("AREA: edited height block vanished")?;
            for &(offset, raw) in patches {
                if block.get(offset..offset + 2) != Some(raw.to_le_bytes().as_slice()) {
                    return Err("AREA: exported height verification failed".into());
                }
            }
        }
        for (before, after) in self.chunks.iter().zip(verified.chunks.iter()) {
            if before.id != after.id || ((&before.id != b"KNHC" && &before.id != b"CHNK") && before.data != after.data) {
                return Err("AREA: unrelated chunk changed during export".into());
            }
        }
        Ok(output)
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
        let data=include_bytes!("../../../../WildStarModelStudio/demo/Hills.area").to_vec();
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
    fn decodes_synthetic_water_subchunk() {
        let mut subchunk_data = Vec::new();
        // 1 body
        subchunk_data.extend(1u32.to_le_bytes());
        // 80-byte header
        let mut header = vec![0u8; 80];
        // min = (-16.0, 50.0, -16.0)
        header[0..4].copy_from_slice(&(-16.0f32).to_bits().to_le_bytes());
        header[4..8].copy_from_slice(&(50.0f32).to_bits().to_le_bytes());
        header[8..12].copy_from_slice(&(-16.0f32).to_bits().to_le_bytes());
        // max = (16.0, 50.0, 16.0)
        header[12..16].copy_from_slice(&(16.0f32).to_bits().to_le_bytes());
        header[16..20].copy_from_slice(&(50.0f32).to_bits().to_le_bytes());
        header[20..24].copy_from_slice(&(16.0f32).to_bits().to_le_bytes());
        // index_count = 3, vertex_count = 3
        header[64..68].copy_from_slice(&3u32.to_le_bytes());
        header[68..72].copy_from_slice(&3u32.to_le_bytes());
        subchunk_data.extend(&header);

        // 3 indices
        subchunk_data.extend(0u32.to_le_bytes());
        subchunk_data.extend(1u32.to_le_bytes());
        subchunk_data.extend(2u32.to_le_bytes());

        // 3 vertices (72 bytes each)
        for i in 0..3 {
            let mut vtx = vec![0u8; 72];
            let pos_x = (i as f32) * 5.0;
            vtx[0..4].copy_from_slice(&pos_x.to_bits().to_le_bytes());
            vtx[4..8].copy_from_slice(&(50.0f32).to_bits().to_le_bytes());
            vtx[8..12].copy_from_slice(&(0.0f32).to_bits().to_le_bytes());
            // normal Y = 1.0
            vtx[16..20].copy_from_slice(&(1.0f32).to_bits().to_le_bytes());
            subchunk_data.extend(&vtx);
        }

        let cell = AreaCell {
            index: 0,
            flags: 0,
            blocks: vec![None; 32],
            subchunks: vec![RawChunk {
                id: *b"GtAW",
                file_offset: 0,
                data: subchunk_data,
            }],
        };

        let bodies = cell.water_bodies();
        assert_eq!(bodies.len(), 1);
        assert_eq!(bodies[0].indices, vec![0, 1, 2]);
        assert_eq!(bodies[0].vertices.len(), 3);
        assert_eq!(bodies[0].vertices[1].position[0], 5.0);
        assert_eq!(bodies[0].vertices[1].position[1], 50.0);
        assert_eq!(bodies[0].vertices[1].normal[1], 1.0);
    }
    #[test]
    fn reject_truncated(){
        assert!(RawArea::from_bytes(b"aera\x00\x00\x00\x00KNHC\xff\xff\xff\xff".to_vec()).is_err());
    }
}

impl RawArea {
    /// Collect all unique WorldSky IDs referenced across all cells in this area tile.
    pub fn all_sky_ids(&self) -> std::collections::BTreeSet<u32> {
        let mut ids = std::collections::BTreeSet::new();
        for cell in self.cells.iter().flatten() {
            if let Some(corners) = cell.sky_ids() {
                for corner in corners {
                    for id in corner {
                        if id != 0 {
                            ids.insert(id);
                        }
                    }
                }
            }
        }
        ids
    }

    /// Collect all unique WorldZone IDs referenced across all cells in this area tile.
    pub fn all_zone_ids(&self) -> std::collections::BTreeSet<u32> {
        let mut ids = std::collections::BTreeSet::new();
        for cell in self.cells.iter().flatten() {
            if let Some(zones) = cell.zones() {
                for id in zones {
                    if id != 0 {
                        ids.insert(id);
                    }
                }
            }
        }
        ids
    }

    /// Sample blended sky IDs and zone ID at local tile coordinates (0.0 .. 512.0).
    pub fn sample_sky_and_zone(&self, rel_x: f32, rel_z: f32) -> (Vec<(u32, f32)>, Option<u32>) {
        let cx = (rel_x / 32.0).floor().clamp(0.0, 15.0) as usize;
        let cz = (rel_z / 32.0).floor().clamp(0.0, 15.0) as usize;
        let cell_idx = cz * 16 + cx;
        let u = (rel_x - cx as f32 * 32.0) / 32.0;
        let v = (rel_z - cz as f32 * 32.0) / 32.0;

        let Some(Some(cell)) = self.cells.get(cell_idx) else {
            return (Vec::new(), None);
        };

        let skies = if let (Some(ids), Some(weights)) = (cell.sky_ids(), cell.sky_weights()) {
            crate::sky::blend_cell_sky_weights(&ids, &weights, u, v)
        } else {
            Vec::new()
        };

        let sub_x = (u * 64.0).floor().clamp(0.0, 63.0) as usize;
        let sub_z = (v * 64.0).floor().clamp(0.0, 63.0) as usize;
        let zone = cell.zone_id_at(sub_x, sub_z).or_else(|| {
            cell.zones().and_then(|z| z.into_iter().find(|&id| id != 0))
        });

        (skies, zone)
    }
}
