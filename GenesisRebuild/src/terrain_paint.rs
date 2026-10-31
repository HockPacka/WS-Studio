//! Phase 1: CPU-editable 4-channel WildStar terrain splat weights and WorldLayer browser.
//! All texture edits are preview-only until a native multi-block AREA writer is validated.
use bevy::prelude::*;
use bevy_egui::egui;
use std::collections::HashMap;
use wildstar_formats::area::RawArea;
use wildstar_formats::tbl::WorldLayer;
use wildstar_formats::tex::decode_tex;
use crate::{client_data::ClientFiles, terrain_material};

pub const MAP_SIDE: usize = 16 * 64;
const CELL_SIDE: usize = 64;
const MAX_UNDO: usize = 16;
const PAGE: usize = 12;

#[derive(Clone,Copy,PartialEq,Eq,Default)]
pub enum PaintMode { #[default] Paint, Erase, Smooth }

#[derive(Clone)]
struct Snapshot {
    weights: Vec<u8>,
    slots: Vec<[u32;4]>,
}
#[derive(Resource,Default)]
pub struct TerrainPaint {
    pub origin: Vec2,
    pub weights: Vec<u8>,
    baseline: Vec<u8>,
    pub slots: Vec<[u32;4]>,
    baseline_slots: Vec<[u32;4]>,
    present: Vec<bool>,
    stroke: Option<Snapshot>,
    undo: Vec<Snapshot>,
    redo: Vec<Snapshot>,
    pub revision: u64,
    pub gpu_revision: u64,
    pub rebuild_pending: bool,
    pub selected_id: Option<u32>,
    pub mode: PaintMode,
    pub query: String,
    pub page: usize,
    pub error: String,
    library_root: String,
    pub library: Vec<WorldLayer>,
    previews: HashMap<u32, egui::TextureHandle>,
}
impl TerrainPaint {
    pub fn reset(&mut self) { *self = Self::default(); }
    pub fn ready(&self) -> bool {
        self.weights.len() == MAP_SIDE*MAP_SIDE*4 && self.slots.len()==256
    }
    pub fn load(&mut self, area: &RawArea, pixels: &[u8], origin: Vec2) -> Result<(),String> {
        if pixels.len()!=MAP_SIDE*MAP_SIDE*4 {
            return Err("Terrain splat must be a 1024x1024 RGBA8 image".into());
        }
        self.reset();
        self.origin=origin;
        self.weights=pixels.to_vec();
        self.baseline=pixels.to_vec();
        self.present=area.cells.iter().map(|c|c.as_ref().and_then(|c|c.block(1)).is_some()).collect();
        self.slots=area.cells.iter().map(|c|c.as_ref().and_then(|c|c.layers()).unwrap_or([0;4])).collect();
        self.baseline_slots=self.slots.clone();
        self.selected_id=self.slots.iter().zip(&self.present)
            .find(|(_,p)|**p).map(|(slots,_)|slots[0]).filter(|&id|id!=0);
        Ok(())
    }
    pub fn dirty(&self)->bool {
        self.ready() && (self.weights!=self.baseline || self.slots!=self.baseline_slots)
    }
    pub fn can_undo(&self)->bool{!self.undo.is_empty()}
    pub fn can_redo(&self)->bool{!self.redo.is_empty()}
    fn snapshot(&self)->Snapshot {
        Snapshot{weights:self.weights.clone(),slots:self.slots.clone()}
    }
    fn push_undo(&mut self, before:Snapshot){
        self.undo.push(before);
        if self.undo.len()>MAX_UNDO{self.undo.remove(0);}
        self.redo.clear();
    }
    pub fn begin(&mut self) {
        if self.ready() && self.stroke.is_none() {self.stroke=Some(self.snapshot());}
    }
    pub fn end(&mut self) {
        if let Some(before)=self.stroke.take(){
            if before.weights!=self.weights || before.slots!=self.slots {self.push_undo(before);}
        }
    }
    fn restore(&mut self, item:Snapshot){
        let changed_slots=self.slots!=item.slots;
        self.weights=item.weights;
        self.slots=item.slots;
        if changed_slots{self.rebuild_pending=true;}
        self.revision=self.revision.wrapping_add(1);
    }
    pub fn undo(&mut self)->bool{
        self.end();
        let Some(prev)=self.undo.pop() else{return false;};
        self.redo.push(self.snapshot());
        self.restore(prev);
        true
    }
    pub fn redo(&mut self)->bool{
        self.end();
        let Some(next)=self.redo.pop() else{return false;};
        self.undo.push(self.snapshot());
        self.restore(next);
        true
    }
    pub fn select_cell(&mut self, cell:usize, slot:usize){
        self.selected_id=self.slots.get(cell).and_then(|s|s.get(slot.min(3))).copied().filter(|&id|id!=0);
    }
    /// Returns the cell at a hit position; missing cells are not editable.
    pub fn cell_at(&self,world:Vec2)->Option<usize>{
        if !self.ready(){return None;}
        let local=world-self.origin+Vec2::splat(256.0);
        if local.x<0.0||local.y<0.0||local.x>=512.0||local.y>=512.0{return None;}
        let cx=(local.x/32.0) as usize;
        let cz=(local.y/32.0) as usize;
        let i=cz*16+cx;
        self.present.get(i).copied().filter(|b|*b).map(|_|i)
    }
    /// Assign one database WorldLayer to a specific slot of an existing cell.
    /// Never silently replace a second slot with the same id.
    pub fn assign(&mut self,cell:usize,slot:usize,id:u32)->Result<(),String>{
        self.end();
        if !self.ready() || cell>=256 || slot>=4 || !self.present[cell] {
            return Err("Select an editable terrain cell and slot".into());
        }
        if !self.library.iter().any(|l|l.id==id){
            return Err("WorldLayer ID not found in the indexed client".into());
        }
        if self.slots[cell].iter().enumerate().any(|(i,&v)| i!=slot&&v==id) {
            return Err("This WorldLayer is already assigned to another slot in that cell".into());
        }
        if self.slots[cell][slot]==id{return Ok(());}
        let previous=self.snapshot();
        self.slots[cell][slot]=id;
        self.push_undo(previous);
        self.rebuild_pending=true;
        self.revision=self.revision.wrapping_add(1);
        self.selected_id=Some(id);
        Ok(())
    }
    /// Paint a selected WorldLayer ID. Cells without that ID are skipped,
    /// preventing accidental painting of another material on a cell boundary.
    pub fn brush(&mut self,world:Vec2,id:u32,radius:f32,power:f32,falloff:f32,
                 dt:f32,restricted_cell:Option<usize>)->bool {
        if !self.ready() || self.stroke.is_none(){return false;}
        let center=(world-self.origin+Vec2::splat(256.0))*2.0;
        let r=(radius*2.0).max(1.0);
        let x0=((center.x-r).floor() as isize).max(0) as usize;
        let x1=((center.x+r).ceil() as isize).min((MAP_SIDE-1) as isize) as usize;
        let z0=((center.y-r).floor() as isize).max(0) as usize;
        let z1=((center.y+r).ceil() as isize).min((MAP_SIDE-1) as isize) as usize;
        if x0>x1||z0>z1{return false;}
        let before=if self.mode==PaintMode::Smooth{Some(self.weights.clone())}else{None};
        let mut changed=false;
        for z in z0..=z1 {
            for x in x0..=x1 {
                let d=(Vec2::new(x as f32+0.5,z as f32+0.5)-center).length();
                if d>=r{continue;}
                let cell=z/CELL_SIDE*16+x/CELL_SIDE;
                if !self.present[cell] || restricted_cell.is_some_and(|c|c!=cell) {continue;}
                let Some(slot)=self.slots[cell].iter().position(|&v|v==id) else{continue;};
                let mut current=[0u8;4];
                let off=(z*MAP_SIDE+x)*4;
                current.copy_from_slice(&self.weights[off..off+4]);
                let influence=(1.0-d/r).powf(1.0+4.0*falloff.clamp(0.0,1.0));
                let amount=power.clamp(0.0,2.0)*dt.clamp(0.0,0.1)*influence*450.0;
                if amount<=0.0{continue;}
                let old=current[slot] as f32;
                let new=match self.mode{
                    PaintMode::Paint=>(old+amount).min(255.0),
                    PaintMode::Erase=>(old-amount).max(0.0),
                    PaintMode::Smooth=>{
                        let mut sum=0f32;
                        let mut count=0f32;
                        let src=before.as_ref().expect("smooth snapshot");
                        let sx=x/CELL_SIDE;
                        let sz=z/CELL_SIDE;
                        for nz in z.saturating_sub(1)..=(z+1).min(MAP_SIDE-1){
                            for nx in x.saturating_sub(1)..=(x+1).min(MAP_SIDE-1){
                                if nx/CELL_SIDE!=sx||nz/CELL_SIDE!=sz{continue;}
                                sum+=src[(nz*MAP_SIDE+nx)*4+slot] as f32;
                                count+=1.0;
                            }
                        }
                        old+(sum/count-old)*(amount/50.0).clamp(0.0,1.0)
                    }
                };
                let next=normalize_channel(current,slot,new.round() as u8);
                if next!=current{
                    self.weights[off..off+4].copy_from_slice(&next);
                    changed=true;
                }
            }
        }
        if changed{self.revision=self.revision.wrapping_add(1);}
        changed
    }

    /// Original AREA remains byte-for-byte unchanged: build only a transient
    /// source clone when the user changes slot IDs, for rebaking GPU textures.
    pub fn preview_area(&self,source:&RawArea)->RawArea{
        let mut area=source.clone();
        for (i,cell) in area.cells.iter_mut().enumerate(){
            if let Some(cell)=cell.as_mut(){
                if let Some(block)=cell.blocks.get_mut(1).and_then(Option::as_mut){
                    for (j,id) in self.slots[i].iter().enumerate(){
                        block[j*4..j*4+4].copy_from_slice(&id.to_le_bytes());
                    }
                }
            }
        }
        area
    }
    pub fn ensure_library(&mut self,client:&ClientFiles){
        if self.library_root==client.root_text || !client.ready(){return;}
        self.library_root=client.root_text.clone();
        self.library=client.index.as_ref().and_then(|index|
            terrain_material::decode_layers(index).ok())
            .map(|table|{
                let mut values:Vec<WorldLayer>=table.into_values().collect();
                values.sort_by(|a,b|a.color_map.to_lowercase().cmp(&b.color_map.to_lowercase()));
                values
            }).unwrap_or_default();
        self.previews.clear();
    }
    fn thumb(&mut self,ui:&egui::Ui,client:&ClientFiles,id:u32,path:&str)->Option<egui::TextureHandle>{
        if let Some(handle)=self.previews.get(&id){return Some(handle.clone());}
        let index=client.index.as_ref()?;
        let asset=index.resolve(path)?;
        let bytes=std::fs::read(asset).ok()?;
        let decoded=decode_tex(&bytes,128).ok()?;
        let mut pixels=Vec::with_capacity(48*48*4);
        for y in 0..48{
            for x in 0..48{
                let u=x as f32/48.0;
                let v=y as f32/48.0;
                pixels.extend_from_slice(&decoded.sample_wrapped(u,v));
            }
        }
        let handle=ui.ctx().load_texture(format!("world-layer-{id}"),
            egui::ColorImage::from_rgba_unmultiplied([48,48],&pixels),
            egui::TextureOptions::LINEAR);
        self.previews.insert(id,handle.clone());
        Some(handle)
    }
    pub fn browser(&mut self,ui:&mut egui::Ui,client:&ClientFiles,cell:usize,slot:&mut usize){
        self.ensure_library(client);
        if !self.ready(){
            ui.colored_label(egui::Color32::DARK_RED,
                "Open an AREA with decoded runtime splat textures to paint.");
            return;
        }
        let cell=cell.min(255);
        ui.label(format!("Cell {}  |  4 WorldLayer slots",cell));
        for i in 0..4 {
            let id=self.slots[cell][i];
            let desc=self.library.iter().find(|l|l.id==id)
                .map(|l|l.color_map.rsplit(['/', '\\']).next().unwrap_or(&l.color_map).to_string())
                .unwrap_or_else(||format!("WorldLayer #{id}"));
            ui.horizontal(|ui|{
                if ui.selectable_label(*slot==i,format!("Slot {i}: #{id}")).clicked(){
                    *slot=i;
                    self.select_cell(cell,i);
                }
                ui.label(egui::RichText::new(desc).small());
            });
        }
        ui.separator();
        ui.label(egui::RichText::new("WorldLayer Browser").strong());
        ui.add(egui::TextEdit::singleline(&mut self.query).hint_text("Search ID or texture path"));
        let query=self.query.trim().to_lowercase();
        let matching:Vec<(u32,String,String,f32)>=self.library.iter()
            .filter(|l|query.is_empty()||l.id.to_string().contains(&query)||
                l.color_map.to_lowercase().contains(&query))
            .map(|l|(l.id,l.color_map.clone(),l.normal_map.clone(),l.meters_per_tile)).collect();
        let pages=matching.len().div_ceil(PAGE).max(1);
        self.page=self.page.min(pages-1);
        ui.horizontal(|ui|{
            if ui.small_button("Previous").clicked(){self.page=self.page.saturating_sub(1);}
            ui.label(format!("Page {}/{} | {} layers",self.page+1,pages,matching.len()));
            if ui.small_button("Next").clicked(){self.page=(self.page+1).min(pages-1);}
        });
        for (id,path,normal,tiling) in matching.iter().skip(self.page*PAGE).take(PAGE){
            ui.horizontal(|ui|{
                if let Some(image)=self.thumb(ui,client,*id,path){
                    ui.add(egui::Image::new((image.id(),egui::vec2(36.0,36.0))));
                }else{
                    ui.label("[TEX]");
                }
                ui.vertical(|ui|{
                    let name=path.rsplit(['/', '\\']).next().unwrap_or(path);
                    if ui.selectable_label(self.selected_id==Some(*id),
                        format!("#{id} {name}")).clicked(){self.selected_id=Some(*id);}
                    ui.label(egui::RichText::new(format!("{tiling:.1} m/tile | Normal: {}",
                        if normal.is_empty(){"no"}else{"yes"})).small());
                });
            });
        }
        if let Some(id)=self.selected_id {
            if ui.button(format!("Assign WorldLayer #{id} to Slot {} (Cell {cell})",*slot)).clicked(){
                self.error=match self.assign(cell,(*slot).min(3),id){
                    Ok(())=>String::new(),Err(e)=>e,
                };
            }
        }
        if !self.error.is_empty(){ui.colored_label(egui::Color32::DARK_RED,&self.error);}
        ui.separator();
        ui.horizontal(|ui|{
            ui.radio_value(&mut self.mode,PaintMode::Paint,"Paint");
            ui.radio_value(&mut self.mode,PaintMode::Erase,"Erase");
            ui.radio_value(&mut self.mode,PaintMode::Smooth,"Smooth");
        });
        ui.label("Paint affects cells containing the selected WorldLayer ID.");
        ui.colored_label(egui::Color32::DARK_RED,
            "PREVIEW ONLY: Save AREA As exports HEIGHTS, not texture edits.");
        ui.label(format!("Unsaved texture edits: {}",if self.dirty(){"YES"}else{"no"}));
    }
}

/// Set selected channel and distribute remaining weight across the other three.
/// For both paint and erase, the total always sums to 255.
fn normalize_channel(mut rgba:[u8;4], slot:usize, goal:u8)->[u8;4]{
    let remaining=255u16-goal as u16;
    let original_sum=(0..4).filter(|&i|i!=slot).map(|i|rgba[i] as u16).sum::<u16>();
    let mut sum=0u16;
    for i in 0..4{
        if i==slot{continue;}
        let next=if original_sum==0{
            if i==(slot+1)%4{remaining}else{0}
        }else{
            (rgba[i] as u16*remaining/original_sum).min(remaining)
        };
        rgba[i]=next as u8;
        sum+=next;
    }
    if sum<remaining{
        let other=(0..4).filter(|&i|i!=slot).max_by_key(|&i|rgba[i]).unwrap_or((slot+1)%4);
        rgba[other]=rgba[other].saturating_add((remaining-sum) as u8);
    }
    rgba[slot]=goal;
    rgba
}
#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn all_paint_updates_are_normalized_and_preserve_goal(){
        for slot in 0..4{
            for goal in [0,1,127,254,255]{
                let a=normalize_channel([30,30,30,165],slot,goal);
                assert_eq!(a[slot],goal);
                assert_eq!(a.iter().map(|&v|v as u16).sum::<u16>(),255);
            }
        }
    }
    #[test]
    fn editing_requires_a_valid_tile(){
        let mut p=TerrainPaint::default();
        assert!(!p.ready());
        p.begin();
        assert!(!p.brush(Vec2::ZERO,0,5.0,1.0,0.5,0.016,None));
        assert!(!p.dirty());
        assert!(!p.undo());
    }
}
