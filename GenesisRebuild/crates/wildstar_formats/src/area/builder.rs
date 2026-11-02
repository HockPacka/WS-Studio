//! New standalone native uncompressed AREA tile builder; no copied game data.
use super::RawArea;
const GRID:usize=257;
const CELL_BYTES:usize=4+722+16+8450+8450;
const FLAGS:u32=(1<<0)|(1<<1)|(1<<2)|(1<<3);

#[derive(Clone,Debug)]
pub struct AreaBuilder {
    pub heights:Vec<f32>,
    pub world_layer_id:u32,
    pub macro_color:[u8;3],
}
impl AreaBuilder {
    pub fn flat(height:f32,world_layer_id:u32)->Self {
        Self{heights:vec![height;GRID*GRID],world_layer_id,macro_color:[128;3]}
    }
    pub fn with_heights(mut self,heights:Vec<f32>)->Self {
        self.heights=heights;self
    }
    pub fn build(&self)->Result<Vec<u8>,String>{
        if self.heights.len()!=GRID*GRID {
            return Err("AREA Builder: expected 257x257 heights".into());
        }
        let heights=self.heights.iter().map(|&height|{
            if !height.is_finite() || !(-2048.0..=6143.875).contains(&height) {
                return Err(format!("AREA Builder: invalid height {height:?}"));
            }
            Ok(((height+2048.0)*8.0).round() as u16)
        }).collect::<Result<Vec<_>,String>>()?;
        let [r,g,b]=self.macro_color;
        let red=(r as u32*31+127)/255;
        let green=(g as u32*63+127)/255;
        let blue=(b as u32*31+127)/255;
        let rgb565=(((red<<11)|(green<<5)|blue) as u16).to_le_bytes();
        let mut chunk=Vec::with_capacity(256*(4+CELL_BYTES));
        for cz in 0..16usize {
            for cx in 0..16usize {
                let mut cell=Vec::with_capacity(CELL_BYTES);
                cell.extend_from_slice(&FLAGS.to_le_bytes());
                // Native 19x19 samples: visible 17x17 at [1..17]^2.
                for z in 0..19usize {for x in 0..19usize{
                    let gx=(cx*16+x).saturating_sub(1).min(256);
                    let gz=(cz*16+z).saturating_sub(1).min(256);
                    cell.extend_from_slice(&heights[gz*GRID+gx].to_le_bytes());
                }}
                for id in [self.world_layer_id,0,0,0] {
                    cell.extend_from_slice(&id.to_le_bytes());
                }
                // Bit 2: 65x65 unnormalized four-channel nibbles, slot0=15.
                for _ in 0..65*65 {cell.extend_from_slice(&15u16.to_le_bytes());}
                // Bit 3: native 65x65 RGB565 macro tint.
                for _ in 0..65*65 {cell.extend_from_slice(&rgb565);}
                if cell.len()!=CELL_BYTES {
                    return Err("AREA Builder: invalid cell block length".into());
                }
                // High byte = delta index, 24 low bits = cell size.
                chunk.extend_from_slice(&(CELL_BYTES as u32).to_le_bytes());
                chunk.extend_from_slice(&cell);
            }
        }
        let size=u32::try_from(chunk.len()).map_err(|_|"AREA: chunk too large")?;
        let mut bytes=Vec::with_capacity(chunk.len()+16);
        bytes.extend_from_slice(b"aera");
        bytes.extend_from_slice(&0u32.to_le_bytes());
        bytes.extend_from_slice(b"KNHC");
        bytes.extend_from_slice(&size.to_le_bytes());
        bytes.extend_from_slice(&chunk);
        let area=RawArea::from_bytes(bytes.clone())?;
        if area.cell_count()!=256 || area.cells.iter().flatten().any(|c|
            c.block(0).is_none()||c.block(1).is_none()||
            c.block(2).is_none()||c.block(3).is_none()
        ) {return Err("AREA Builder: validation failed".into());}
        Ok(bytes)
    }
}
#[cfg(test)]
mod tests{
    use super::*;
    use crate::area::tile_heights;
    #[test]
    fn creates_256_cells_and_all_native_blocks(){
        let data=AreaBuilder::flat(0.0,22).build().unwrap();
        let area=RawArea::from_bytes(data.clone()).unwrap();
        assert_eq!(area.original,data);
        assert_eq!(area.version,0);
        assert!(!area.compressed);
        assert_eq!(area.cell_count(),256);
        assert_eq!(area.chunks[0].id,*b"KNHC");
        for cell in area.cells.iter().flatten(){
            assert_eq!(cell.flags,FLAGS);
            assert_eq!(cell.layers(),Some([22,0,0,0]));
            assert_eq!(cell.authoring_weights(0,0),Some([15,0,0,0]));
            assert_eq!(cell.authoring_weights(64,64),Some([15,0,0,0]));
            assert_eq!(cell.height(8,8),Some(0.0));
        }
        assert!(tile_heights(&area).present.iter().all(|v|*v));
    }
    #[test]
    fn height_halos_match_neighbor_cell_edge(){
        let h=(0..GRID*GRID).map(|i|{
            (i%GRID) as f32*0.125+(i/GRID) as f32*0.25
        }).collect::<Vec<_>>();
        let area=RawArea::from_bytes(
            AreaBuilder::flat(0.0,0).with_heights(h.clone()).build().unwrap()
        ).unwrap();
        for z in 0..17 {
            assert_eq!(area.cells[0].as_ref().unwrap().height(16,z),
                       area.cells[1].as_ref().unwrap().height(0,z));
        }
        assert_eq!(area.cells[255].as_ref().unwrap().height(16,16),Some(h[256*GRID+256]));
    }
    #[test]
    fn rejects_invalid_height_arrays(){
        assert!(AreaBuilder::flat(f32::NAN,0).build().is_err());
        assert!(AreaBuilder::flat(9000.0,0).build().is_err());
        assert!(AreaBuilder::flat(-3000.0,0).build().is_err());
        assert!(AreaBuilder::flat(0.0,0).with_heights(vec![0.0;20]).build().is_err());
    }
    #[test]
    fn existing_height_editor_can_save_new_tile(){
        let area=RawArea::from_bytes(AreaBuilder::flat(0.0,0).build().unwrap()).unwrap();
        let new=RawArea::from_bytes(area.with_height_changes(&[(17,17,7.5)]).unwrap()).unwrap();
        assert_eq!(new.cells[17].as_ref().unwrap().height(1,1),Some(7.5));
    }
}
