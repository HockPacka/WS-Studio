//! Editable native WildStar AREA clutter selector and suppression masks.
//! In-memory workspace only; no source files modified until explicit Save As.
//! Supports per-stroke Undo/Redo, 2-bit selector painting, No-Clutter mask.
use bevy::prelude::*;
use std::{collections::BTreeMap,path::{Path,PathBuf},io::Write};
use wildstar_formats::area::{
    RawArea,clutter_write::{ClutterEdit,plan,validate}
};
use crate::terrain_paint::TerrainPaint;
const MAX_UNDO:usize=24;
type Blocks=BTreeMap<(usize,usize),Vec<u8>>;
#[derive(Resource,Default)]
pub struct ClutterPaint {
    pub source:Option<PathBuf>,
    origin:Vec2,
    blocks:Blocks,
    baseline:Blocks,
    present:[bool;256],
    stroke:Option<Blocks>,
    undo:Vec<Blocks>,
    redo:Vec<Blocks>,
    pub revision:u64,
}
impl ClutterPaint {
    pub fn load(&mut self,source:&Path,area:&RawArea,origin:Vec2){
        let mut result=Self{source:Some(source.to_path_buf()),origin,
            revision:1,..Default::default()};
        for (i,cell) in area.cells.iter().enumerate(){
            if let Some(cell)=cell.as_ref(){
                result.present[i]=true;
                for bit in [16,27]{
                    if let Some(raw)=cell.block(bit){
                        if raw.len()==64*64{
                            result.blocks.insert((i,bit),raw.to_vec());
                        }
                    }
                }
            }
        }
        result.baseline=result.blocks.clone();
        *self=result;
    }
    pub fn reset(&mut self){*self=Default::default();}
    pub fn ready(&self)->bool{self.source.is_some()}
    pub fn dirty(&self)->bool{self.ready()&&self.blocks!=self.baseline}
    pub fn stroking(&self)->bool{self.stroke.is_some()}
    pub fn begin(&mut self){
        if self.ready()&&self.stroke.is_none(){self.stroke=Some(self.blocks.clone());}
    }
    pub fn end(&mut self){
        if let Some(before)=self.stroke.take(){
            if before!=self.blocks{
                self.undo.push(before);
                if self.undo.len()>MAX_UNDO{self.undo.remove(0);}
                self.redo.clear();
            }
        }
    }
    pub fn undo(&mut self)->bool{
        self.end();
        let Some(prev)=self.undo.pop() else{return false;};
        self.redo.push(self.blocks.clone());
        self.blocks=prev;
        self.revision=self.revision.wrapping_add(1);
        true
    }
    pub fn redo(&mut self)->bool{
        self.end();
        let Some(next)=self.redo.pop() else{return false;};
        self.undo.push(self.blocks.clone());
        self.blocks=next;
        self.revision=self.revision.wrapping_add(1);
        true
    }
    pub fn mask_at(&self,cell:usize,x:usize,z:usize)->Option<bool>{
        (x<64&&z<64).then(||self.blocks.get(&(cell,16)))
            .flatten().and_then(|raw|raw.get(z*64+x))
            .map(|v|v&0x20!=0)
    }
    pub fn selector_at(&self,cell:usize,x:usize,z:usize,slot:usize)->Option<u8>{
        if x>=64||z>=64||slot>=4{return None;}
        self.blocks.get(&(cell,27)).and_then(|raw|raw.get(z*64+x))
            .map(|v|(v>>(slot*2))&3)
    }
    /// x and z are world metres relative to the standalone tile's origin.
    /// Action 0: paint preset; 1: suppress; 2: restore clutter allowance.
    /// All other AREA flags remain untouched.
    pub fn brush(&mut self,world:Vec2,radius:f32,slot:usize,preset:u8,
        action:u8)->bool{
        if !self.ready()||self.stroke.is_none()||slot>=4||
            preset>3||action>2{return false;}
        let center=(world-self.origin+Vec2::splat(256.0))*2.0;
        let radius=(radius*2.0).clamp(0.5,128.0);
        let x0=((center.x-radius).floor() as isize).max(0) as usize;
        let x1=((center.x+radius).ceil() as isize).min(1023) as usize;
        let z0=((center.y-radius).floor() as isize).max(0) as usize;
        let z1=((center.y+radius).ceil() as isize).min(1023) as usize;
        if x0>x1||z0>z1{return false;}
        let mut changed=false;
        for z in z0..=z1{
            for x in x0..=x1{
                let dx=x as f32+0.5-center.x;
                let dz=z as f32+0.5-center.y;
                if dx*dx+dz*dz>radius*radius{continue;}
                let cell=(z/64)*16+x/64;
                if !self.present[cell]{continue;}
                let bit=if action==0{27}else{16};
                let Some(raw)=self.blocks.get_mut(&(cell,bit)) else{continue;};
                let idx=(z%64)*64+x%64;
                let old=raw[idx];
                let new=match action{
                    0=>{
                        let shift=slot*2;
                        (old&!(3<<shift))|((preset&3)<<shift)
                    },
                    1=>old|0x20,
                    _=>old&!0x20,
                };
                if old!=new{
                    raw[idx]=new;changed=true;
                }
            }
        }
        if changed{self.revision=self.revision.wrapping_add(1);}
        changed
    }
    pub fn preview_area(&self,source:&RawArea)->RawArea{
        let mut result=source.clone();
        for (&(index,bit),bytes) in &self.blocks{
            if let Some(cell)=result.cells.get_mut(index).and_then(Option::as_mut){
                if let Some(block)=cell.blocks.get_mut(bit).and_then(Option::as_mut){
                    if block.len()==bytes.len(){*block=bytes.clone();}
                }
            }
        }
        result
    }
    pub fn edits(&self)->Vec<ClutterEdit>{
        let mut changes=Vec::new();
        for (&(cell,bit),new) in &self.blocks{
            let Some(original)=self.baseline.get(&(cell,bit)) else{continue;};
            for (idx,(&old,&value)) in original.iter().zip(new).enumerate(){
                if old==value{continue;}
                let x=idx%64;
                let z=idx/64;
                if bit==27{
                    for slot in 0..4{
                        if ((old>>(slot*2))&3)!=((value>>(slot*2))&3){
                            changes.push(ClutterEdit::Selector{cell,x,z,slot,
                                preset:(value>>(slot*2))&3});
                        }
                    }
                }else if bit==16 && (old^value)&0x20!=0{
                    changes.push(ClutterEdit::Suppressed{cell,x,z,
                        hidden:value&0x20!=0});
                }
            }
        }
        changes
    }
    /// Merge with the already validated height / color / weight export.
    /// Reparse the stage and ensure only the requested Clutter bits change.
    pub fn merge_bytes(&self,base_bytes:Vec<u8>)->Result<Vec<u8>,String>{
        if !self.dirty(){return Ok(base_bytes);}
        let stage=RawArea::from_bytes(base_bytes)?;
        let edits=self.edits();
        if edits.is_empty(){return Ok(stage.original);}
        let replacements=plan(&stage,&edits)?;
        let result=stage.with_cell_block_changes(&replacements)?;
        let reloaded=RawArea::from_bytes(result.clone())?;
        validate(&stage,&reloaded,&edits)?;
        Ok(result)
    }
    pub fn export_as(&self,source:&RawArea,paint:&mut TerrainPaint,
        heights:&[(usize,usize,f32)],destination:&Path)->Result<usize,String>
    {
        if !self.dirty(){return Err("No Clutter changes to export".into());}
        if destination.extension().and_then(|e|e.to_str())
            .is_none_or(|s|!s.eq_ignore_ascii_case("area")){
            return Err("Clutter export requires an .area extension".into());
        }
        if destination.exists(){
            return Err("Clutter export refuses to overwrite an existing file".into());
        }
        let base=if heights.is_empty()&&!paint.dirty(){
            source.original.clone()
        }else{
            paint.build_native_bytes(source,heights)?.0
        };
        let bytes=self.merge_bytes(base)?;
        let mut file=std::fs::OpenOptions::new().create_new(true).write(true)
            .open(destination).map_err(|e|format!("Cannot create AREA: {e}"))?;
        if let Err(e)=file.write_all(&bytes).and_then(|_|file.sync_all()){
            drop(file);let _=std::fs::remove_file(destination);
            return Err(format!("Cannot export Clutter AREA: {e}"));
        }
        Ok(self.edits().len())
    }
}
#[cfg(test)]
mod tests{
    use super::*;
    use wildstar_formats::area::AreaCell;
    fn fixture()->(RawArea,ClutterPaint){
        let mut blocks=vec![None;32];
        blocks[16]=Some(vec![0x08;64*64]);
        blocks[27]=Some(vec![0;64*64]);
        let mut cells=vec![None;256];
        cells[0]=Some(AreaCell{index:0,flags:(1<<16)|(1<<27),
            blocks,subchunks:Vec::new()});
        let area=RawArea{version:0,compressed:false,original:vec![],
            chunks:vec![],cells,lod_prefix:None};
        let mut p=ClutterPaint::default();
        p.load(Path::new("Demo.393b.area"),&area,Vec2::ZERO);
        (area,p)
    }
    #[test]
    fn paint_undo_redo_and_block_fields(){
        let (area,mut p)=fixture();
        p.begin();
        assert!(p.brush(Vec2::new(-240.0,-240.0),4.0,1,3,0));
        p.end();
        assert!(p.dirty());
        assert_eq!(p.selector_at(0,32,32,1),Some(3));
        let original=area.cells[0].as_ref().unwrap().clutter_selector(32,32,1);
        assert_eq!(original,Some(0));
        assert!(p.undo());
        assert!(!p.dirty());
        assert!(p.redo());
        assert!(p.dirty());
        p.begin();
        assert!(p.brush(Vec2::new(-240.0,-240.0),4.0,0,0,1));
        p.end();
        assert_eq!(p.mask_at(0,32,32),Some(true));
        assert_eq!(p.selector_at(0,32,32,1),Some(3));
        assert!(p.undo());
        assert_eq!(p.mask_at(0,32,32),Some(false));
    }
    #[test]
    fn fails_closed_when_native_block_is_missing(){
        let (mut area,_)=fixture();
        area.cells[0].as_mut().unwrap().blocks[27]=None;
        let mut p=ClutterPaint::default();
        p.load(Path::new("Demo.393b.area"),&area,Vec2::ZERO);
        p.begin();
        assert!(!p.brush(Vec2::new(-240.0,-240.0),4.0,0,3,0));
        assert!(!p.dirty());
    }
}
