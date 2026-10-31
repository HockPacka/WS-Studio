//! Native WildStar AREA terrain splat and RGB editor with guarded native Save As.
//! Block 19/20 weight encoding and multi-AREA boundary writes remain unavailable.
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

#[derive(Clone,Copy,PartialEq,Eq,Default)]
pub enum ColorMode { #[default] Color, Darken, Lighten, Smooth }

#[derive(Clone)]
struct Snapshot {
    weights: Vec<u8>,
    slots: Vec<[u32;4]>,
    colors: Vec<u8>,
}
#[derive(Resource,Default)]
pub struct TerrainPaint {
    pub origin: Vec2,
    pub weights: Vec<u8>,
    baseline: Vec<u8>,
    pub slots: Vec<[u32;4]>,
    baseline_slots: Vec<[u32;4]>,
    pub colors: Vec<u8>,
    baseline_colors: Vec<u8>,
    /// Source-specific, read-only visual rasters. Neither affects native AREA exports.
    rgb_bit3: Vec<u8>,
    rgb_bit13: Vec<u8>,
    alpha_bit13: Vec<u8>,
    color_present: Vec<bool>,
    pub color: [u8;3],
    pub color_mode: ColorMode,
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
        self.color_present=area.cells.iter().map(|c|c.as_ref()
            .is_some_and(|c|c.block(3).is_some()||c.block(13).is_some())).collect();
        self.color=[128,128,128];
        self.selected_id=self.slots.iter().zip(&self.present)
            .find(|(_,p)|**p).map(|(slots,_)|slots[0]).filter(|&id|id!=0);
        Ok(())
    }
    pub fn load_colors(&mut self,pixels:&[u8],area:&RawArea)->Result<(),String>{
        if !self.ready() || pixels.len()!=MAP_SIDE*MAP_SIDE*4 {
            return Err("Terrain tint must be an RGBA8 1024x1024 image".into());
        }
        self.colors=pixels.to_vec();
        self.baseline_colors=pixels.to_vec();
        self.rgb_bit3=vec![128;MAP_SIDE*MAP_SIDE*3];
        self.rgb_bit13=vec![128;MAP_SIDE*MAP_SIDE*3];
        self.alpha_bit13=vec![0;MAP_SIDE*MAP_SIDE];
        for (cell_idx,cell) in area.cells.iter().enumerate(){
            let Some(cell)=cell.as_ref() else{continue;};
            let cx=cell_idx%16*64;
            let cz=cell_idx/16*64;
            for z in 0..64{
                for x in 0..64{
                    let px=(cz+z)*MAP_SIDE+cx+x;
                    if let Some(rgb)=cell.color_rgb565(x,z){
                        self.rgb_bit3[px*3..px*3+3].copy_from_slice(&rgb);
                    }
                    if let Some(rgb)=cell.color_bc2(x,z){
                        self.rgb_bit13[px*3..px*3+3].copy_from_slice(&rgb);
                    }
                    if let Some(alpha)=cell.bc2_color_alpha(x,z){
                        self.alpha_bit13[px]=alpha;
                    }
                }
            }
        }
        Ok(())
    }
    /// Read-only source switch. Preserve alpha from the original BC2 blocks
    /// for diagnostics, even when Bit 3 is used for the visible RGB.
    /// Modified RGB texels are overlaid so editing stays visible in every mode.
    pub fn render_tint(&self,source:u32)->Vec<u8>{
        if !self.colors_ready(){return Vec::new();}
        let mut result=self.colors.clone();
        let pixels=MAP_SIDE*MAP_SIDE;
        for i in 0..pixels{
            if self.colors[i*4..i*4+3]==self.baseline_colors[i*4..i*4+3]{
                if source==1 || source==2 {
                    let rgb=if source==1{&self.rgb_bit3}else{&self.rgb_bit13};
                    result[i*4..i*4+3].copy_from_slice(&rgb[i*3..i*3+3]);
                }
            }
            result[i*4+3]=self.alpha_bit13.get(i).copied().unwrap_or(0);
        }
        result
    }
    pub fn colors_ready(&self)->bool {
        self.ready() && self.colors.len()==MAP_SIDE*MAP_SIDE*4
    }
    pub fn dirty(&self)->bool {
        self.ready() && (self.weights!=self.baseline || self.slots!=self.baseline_slots
            || self.colors!=self.baseline_colors)
    }
    pub fn can_undo(&self)->bool{!self.undo.is_empty()}
    pub fn can_redo(&self)->bool{!self.redo.is_empty()}
    fn snapshot(&self)->Snapshot {
        Snapshot{weights:self.weights.clone(),slots:self.slots.clone(),colors:self.colors.clone()}
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
            if before.weights!=self.weights || before.slots!=self.slots || before.colors!=self.colors {self.push_undo(before);}
        }
    }
    fn restore(&mut self, item:Snapshot){
        let changed_slots=self.slots!=item.slots;
        self.weights=item.weights;
        self.slots=item.slots;
        self.colors=item.colors;
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

    /// Paint existing WildStar macro-tint RGB without altering the unknown alpha.
    /// Color mode and swatch are editor settings, not new AREA metadata.
    pub fn color_brush(&mut self,world:Vec2,radius:f32,power:f32,
        falloff:f32,dt:f32,restricted_cell:Option<usize>)->bool
    {
        if !self.colors_ready() || self.stroke.is_none(){return false;}
        let center=(world-self.origin+Vec2::splat(256.0))*2.0;
        let radius=(radius*2.0).max(1.0);
        let x0=((center.x-radius).floor() as isize).max(0) as usize;
        let x1=((center.x+radius).ceil() as isize).min((MAP_SIDE-1) as isize) as usize;
        let z0=((center.y-radius).floor() as isize).max(0) as usize;
        let z1=((center.y+radius).ceil() as isize).min((MAP_SIDE-1) as isize) as usize;
        if x0>x1 || z0>z1{return false;}
        let before=if self.color_mode==ColorMode::Smooth{Some(self.colors.clone())}else{None};
        let mut changed=false;
        for z in z0..=z1{
            for x in x0..=x1{
                let d=(Vec2::new(x as f32+0.5,z as f32+0.5)-center).length();
                if d>=radius{continue;}
                let cell=z/64*16+x/64;
                if !self.present[cell] || !self.color_present[cell] ||
                    restricted_cell.is_some_and(|only|only!=cell) {continue;}
                let off=(z*MAP_SIDE+x)*4;
                let amount=(power.clamp(0.0,2.0)*dt.clamp(0.0,0.1)*15.0
                    *(1.0-d/radius).powf(1.0+4.0*falloff.clamp(0.0,1.0)))
                    .clamp(0.0,1.0);
                if amount<=0.0{continue;}
                let original=[self.colors[off],self.colors[off+1],self.colors[off+2]];
                let target=match self.color_mode{
                    ColorMode::Color=>self.color,
                    ColorMode::Darken=>original.map(|c|((c as f32)*0.4).round() as u8),
                    ColorMode::Lighten=>original.map(|c|(c as f32+(255-c) as f32*0.6).round() as u8),
                    ColorMode::Smooth=>{
                        let src=before.as_ref().expect("smooth input");
                        let mut sum=[0u32;3];
                        let mut count=0u32;
                        for nz in z.saturating_sub(1)..=(z+1).min(MAP_SIDE-1){
                            for nx in x.saturating_sub(1)..=(x+1).min(MAP_SIDE-1){
                                if nx/64!=x/64||nz/64!=z/64{continue;}
                                let at=(nz*MAP_SIDE+nx)*4;
                                for i in 0..3{sum[i]+=src[at+i] as u32;}
                                count+=1;
                            }
                        }
                        std::array::from_fn(|i|(sum[i]/count) as u8)
                    },
                };
                for i in 0..3{
                    let next=(original[i] as f32+
                        (target[i] as f32-original[i] as f32)*amount).round() as u8;
                    if next!=original[i] {self.colors[off+i]=next;changed=true;}
                }
            }
        }
        if changed{self.revision=self.revision.wrapping_add(1);}
        changed
    }

    pub fn native_color_edits(&mut self,area:&RawArea)
        ->Result<(Vec<(usize,usize,Vec<u8>)>,usize),String>
    {
        use wildstar_formats::area::color_write::{
            plan_color_edits,ColorCellEdit,COLOR_BYTES,
        };
        self.end();
        if !self.colors_ready(){return Ok((Vec::new(),0));}
        let mut edits=Vec::new();
        for cell in 0..256{
            if !self.present[cell]{continue;}
            let cx=(cell%16)*64;
            let cz=(cell/16)*64;
            let mut before=Vec::with_capacity(COLOR_BYTES);
            let mut after=Vec::with_capacity(COLOR_BYTES);
            for z in 0..64{
                for x in 0..64{
                    let off=((cz+z)*MAP_SIDE+cx+x)*4;
                    before.extend_from_slice(&self.baseline_colors[off..off+4]);
                    after.extend_from_slice(&self.colors[off..off+4]);
                }
            }
            if before!=after{
                edits.push(ColorCellEdit{index:cell,before,after});
            }
        }
        let cells=edits.len();
        Ok((plan_color_edits(area,&edits)?,cells))
    }

    /// Build changes from just the modified cells; untouched cells and texels
    /// are left exactly as they appeared in the source AREA.
    pub fn native_texture_edits(&mut self,source:&RawArea)
        ->Result<(Vec<(usize,usize,Vec<u8>)>,usize),String>
    {
        use wildstar_formats::area::texture_write::{
            plan_texture_edits, TextureCellEdit, CELL_RGBA_BYTES,
        };
        self.end();
        if !self.ready(){return Err("No editable terrain splat loaded".into());}
        let mut edits=Vec::new();
        for cell in 0..256 {
            if !self.present[cell]{continue;}
            let changed_slots=self.slots[cell]!=self.baseline_slots[cell];
            let mut before=Vec::with_capacity(CELL_RGBA_BYTES);
            let mut after=Vec::with_capacity(CELL_RGBA_BYTES);
            let cx=(cell%16)*64;
            let cz=(cell/16)*64;
            for z in 0..64 {
                for x in 0..64 {
                    let off=((cz+z)*MAP_SIDE+cx+x)*4;
                    before.extend_from_slice(&self.baseline[off..off+4]);
                    after.extend_from_slice(&self.weights[off..off+4]);
                }
            }
            if changed_slots || before!=after {
                edits.push(TextureCellEdit{
                    index:cell,layer_ids:self.slots[cell],
                    weights:after,before,
                });
            }
        }
        let total=edits.len();
        Ok((plan_texture_edits(source,&edits)?,total))
    }

    /// Reject exports whose decompressed layer weights deviate excessively
    /// from the edited preview. BC1 is lossy: better to refuse a poor result
    /// than silently write a visibly different painted surface.
    fn verify_native_weight_fidelity(&self, area:&RawArea)->Result<(),String>{
        const MAX_ERROR:f32=0.20;
        for index in 0..256 {
            if !self.present[index]{continue;}
            let Some(cell)=area.cells[index].as_ref() else {
                return Err("Texture validation: cell missing after export".into());
            };
            let cx=index%16*64;
            let cz=index/16*64;
            let mut affected=false;
            for z in 0..64 {
                for x in 0..64 {
                    let off=((cz+z)*MAP_SIDE+cx+x)*4;
                    if self.baseline[off..off+4]!=self.weights[off..off+4]{
                        affected=true;
                        break;
                    }
                }
                if affected{break;}
            }
            if !affected{continue;}
            for z in 0..64 {
                for x in 0..64 {
                    let off=((cz+z)*MAP_SIDE+cx+x)*4;
                    let actual=cell.compressed_weights(x,z).or_else(||{
                        cell.normalized_weights(x,z)
                            .or_else(||cell.authoring_weights(x,z))
                            .map(|raw|{
                                let total=raw.iter().map(|&w|w as f32).sum::<f32>();
                                if total<=0.0{[1.0,0.0,0.0,0.0]}
                                else{raw.map(|w|w as f32/total)}
                            })
                    }).ok_or("Texture validation: no readable weight block")?;
                    for channel in 0..4 {
                        let expected=self.weights[off+channel] as f32/255.0;
                        if (actual[channel]-expected).abs()>MAX_ERROR{
                            return Err(format!(
                                "Texture compression exceeds 20% error at cell {index} \
pixel ({x},{z}), layer {channel}; export cancelled"
                            ));
                        }
                    }
                }
            }
        }
        Ok(())
    }

    /// Native color is RGB565 or BC2: compare after decompression and
    /// reject significant lossy deviations instead of silently exporting them.
    fn verify_native_color_fidelity(&self,source:&RawArea,area:&RawArea)->Result<(),String>{
        if !self.colors_ready(){return Ok(());}
        const MAX_COLOR_ERROR:i16=50;
        // Verify opaque BC2 metadata on *every* touched/untouched neighbor
        // block: alpha is unknown and must survive every AREA rewrite exactly.
        for index in 0..256 {
            let from=source.cells.get(index).and_then(Option::as_ref);
            let to=area.cells.get(index).and_then(Option::as_ref);
            if let (Some(before),Some(after))=(
                from.and_then(|c|c.block(13)),
                to.and_then(|c|c.block(13))
            ){
                if before.len()!=after.len()||before.len()%16!=0{
                    return Err(format!("AREA BC2 block layout changed in cell {index}"));
                }
                if before.chunks_exact(16).zip(after.chunks_exact(16))
                    .any(|(a,b)|a[..8]!=b[..8]){
                    return Err(format!(
                        "AREA BC2 alpha changed in cell {index}; refusing unsafe export"
                    ));
                }
            }
        }
        for cell_index in 0..256{
            if !self.present[cell_index]{continue;}
            let (cx,cz)=(cell_index%16*64,cell_index/16*64);
            let mut dirty=false;
            for z in 0..64{
                for x in 0..64{
                    let o=((cz+z)*MAP_SIDE+cx+x)*4;
                    if self.baseline_colors[o..o+3]!=self.colors[o..o+3]{
                        dirty=true;break;
                    }
                }
                if dirty{break;}
            }
            if !dirty{continue;}
            let cell=area.cells[cell_index].as_ref().ok_or("Color validation missing cell")?;
            for z in 0..64{
                for x in 0..64{
                    let o=((cz+z)*MAP_SIDE+cx+x)*4;
                    let actual=cell.terrain_color(x,z).ok_or("Color validation missing RGB data")?;
                    for channel in 0..3{
                        let delta=actual[channel] as i16-self.colors[o+channel] as i16;
                        if delta.abs()>MAX_COLOR_ERROR{
                            return Err(format!(
                                "AREA RGB export diverges by {} at cell {cell_index} pixel ({x},{z}), channel {channel}; export blocked",
                                delta.abs()));
                        }
                    }
                    // If Bit 3 and Bit 13 both exist, terrain_color only
                    // checks Bit 3. Also enforce the output of the independent
                    // Bit 13 BC2 representation on every explicitly painted
                    // pixel, so a hidden BC2 corruption cannot slip through.
                    if self.baseline_colors[o..o+3]!=self.colors[o..o+3] {
                        if let Some(compressed)=cell.color_bc2(x,z) {
                            for channel in 0..3 {
                                let delta=compressed[channel] as i16-
                                    self.colors[o+channel] as i16;
                                if delta.abs()>MAX_COLOR_ERROR {
                                    return Err(format!(
                                        "AREA Bit 13 BC2 RGB error {} at cell {cell_index} ({x},{z}) channel {channel}; export blocked",
                                        delta.abs()
                                    ));
                                }
                            }
                        }
                    }
                }
            }
        }
        Ok(())
    }

    /// Validate duplicated 65th samples after all native cell blocks have
    /// been re-encoded and reloaded. Every internal seam sample is checked;
    /// the outer tile edge intentionally remains an independent AREA boundary.
    fn verify_native_edge_samples(&self,exported:&RawArea)->Result<(),String>{
        for index in 0..256{
            if !self.present[index]{continue;}
            let (cx,cz)=(index%16,index/16);
            let adjacent=[
                (cx>0,index.saturating_sub(1),64usize,0usize),
                (cz>0,index.saturating_sub(16),0usize,64usize),
                (cx>0&&cz>0,index.saturating_sub(17),64usize,64usize),
            ];
            for (exists,neighbour,ghost_x,ghost_z) in adjacent {
                if !exists{continue;}
                let Some(cell)=exported.cells.get(neighbour)
                    .and_then(Option::as_ref) else {
                    // There can be sparse AREA tiles. The seam writer will
                    // refuse an edit that needs to update a missing neighbour.
                    continue;
                };
                let source_x=if ghost_x==64{0}else{usize::MAX};
                let source_z=if ghost_z==64{0}else{usize::MAX};
                let count=if ghost_x==64&&ghost_z==64{1}else{64};
                for axis in 0..count{
                    let sx=if source_x==0{0}else{axis};
                    let sz=if source_z==0{0}else{axis};
                    let gx=if ghost_x==64{64}else{axis};
                    let gz=if ghost_z==64{64}else{axis};
                    let src=((cz*64+sz)*MAP_SIDE+cx*64+sx)*4;
                    let weight_dirty=self.weights[src..src+4]!=self.baseline[src..src+4];
                    let color_dirty=self.colors_ready() &&
                        self.colors[src..src+3]!=self.baseline_colors[src..src+3];
                    if weight_dirty {
                        let actual=cell.compressed_weights(gx,gz).or_else(||{
                            cell.normalized_weights(gx,gz)
                                .or_else(||cell.authoring_weights(gx,gz))
                                .map(|raw|{
                                    let sum=raw.iter().map(|&v|v as f32).sum::<f32>();
                                    if sum>0.0{raw.map(|v|v as f32/sum)}
                                    else{[1.0,0.0,0.0,0.0]}
                                })
                        }).ok_or("AREA seam: adjacent weight data unreadable")?;
                        for layer in 0..4{
                            let expected=self.weights[src+layer] as f32/255.0;
                            if (actual[layer]-expected).abs()>0.20{
                                return Err(format!("AREA weight seam error between cells {index} and {neighbour}, layer {layer}"));
                            }
                        }
                    }
                    if color_dirty {
                        let actual=cell.terrain_color(gx,gz)
                            .ok_or("AREA seam: adjacent color data unreadable")?;
                        for channel in 0..3{
                            let delta=actual[channel] as i16-self.colors[src+channel] as i16;
                            if delta.abs()>50{
                                return Err(format!("AREA color seam error between cells {index} and {neighbour}, channel {channel}"));
                            }
                        }
                    }
                }
            }
        }
        Ok(())
    }

    /// Build and validate a native AREA in memory without creating a file.
    /// The bundle exporter uses this to validate ALL tiles before any write.
    pub(crate) fn build_native_bytes(&mut self,source:&RawArea,
        height_edits:&[(usize,usize,f32)])
        ->Result<(Vec<u8>,usize),String>
    {
        // A standalone AREA can have editable heights without a baked
        // WorldLayer atlas. The bundle exporter must still support that
        // height-only case rather than requiring texture paint initialization.
        let (mut patches,changed_cells)=if self.ready(){
            self.native_texture_edits(source)?
        }else{(Vec::new(),0)};
        let (color_patches,color_cells)=if self.ready(){
            self.native_color_edits(source)?
        }else{(Vec::new(),0)};
        patches.extend(color_patches);
        if height_edits.is_empty() && patches.is_empty(){
            return Err("No height or texture changes to export".into());
        }
        let stage=if height_edits.is_empty(){
            source.clone()
        }else{
            RawArea::from_bytes(source.with_height_changes(height_edits)?)?
        };
        let bytes=stage.with_cell_block_changes(&patches)?;
        let reread=RawArea::from_bytes(bytes.clone())?;
        if reread.cell_count()!=source.cell_count()||
            reread.prop_count()!=source.prop_count() {
            return Err("AREA validation failed: terrain cell or prop count changed".into());
        }
        for &(x,z,target) in height_edits {
            let raw=((target+2048.0)*8.0).round().clamp(0.0,65535.0) as u16;
            let cell=(z.min(255)/16)*16+(x.min(255)/16);
            let lx=x-cell%16*16;
            let lz=z-cell/16*16;
            if lx>16||lz>16{
                return Err("AREA height sample validation coordinates invalid".into());
            }
            let after=reread.cells[cell].as_ref()
                .and_then(|c|c.height(lx,lz))
                .ok_or("AREA height sample disappeared during texture export")?;
            if (after-(raw as f32*0.125-2048.0)).abs()>0.0001{
                return Err("AREA texture export altered a height sample".into());
            }
        }
        // All blocks/unknown payloads are validated inside with_cell_block_changes.
        if self.ready(){
            self.verify_native_weight_fidelity(&reread)?;
            self.verify_native_color_fidelity(source,&reread)?;
            self.verify_native_edge_samples(&reread)?;
        }
        Ok((bytes,changed_cells+color_cells))
    }

    /// The first visible row/column of a tile is duplicated in the trailing
    /// ghost row/column of its left/top predecessor AREA. Emit only modified
    /// samples and never infer adjacent material slot layouts.
    pub(crate) fn external_border_samples(&self)->Result<[Vec<
        wildstar_formats::area::cross_tile_write::BorderSample>;3],String>
    {
        use wildstar_formats::area::cross_tile_write::{
            BorderSample,BorderWeights,
        };
        if !self.ready(){return Ok([Vec::new(),Vec::new(),Vec::new()]);}
        let mut out=[Vec::new(),Vec::new(),Vec::new()];
        let sample_at=|x:usize,z:usize|->Option<BorderSample>{
            let idx=(z*MAP_SIDE+x)*4;
            let cell=z/64*16+x/64;
            if !self.present[cell]{return None;}
            let changed_weight=self.weights[idx..idx+4]!=self.baseline[idx..idx+4]
                || self.slots[cell]!=self.baseline_slots[cell];
            let changed_rgb=self.colors_ready() &&
                self.colors[idx..idx+3]!=self.baseline_colors[idx..idx+3];
            if !changed_weight && !changed_rgb{return None;}
            Some(BorderSample{
                x,z,
                weights:changed_weight.then(||BorderWeights{
                    layer_ids:self.slots[cell],
                    rgba:self.weights[idx..idx+4].try_into().unwrap(),
                }),
                rgb:changed_rgb.then(||{
                    self.colors[idx..idx+3].try_into().unwrap()
                }),
            })
        };
        for z in 0..MAP_SIDE{
            if let Some(mut s)=sample_at(0,z){
                s.x=MAP_SIDE;
                out[0].push(s);
            }
        }
        for x in 0..MAP_SIDE{
            if let Some(mut s)=sample_at(x,0){
                s.z=MAP_SIDE;
                out[1].push(s);
            }
        }
        if let Some(mut s)=sample_at(0,0){
            s.x=MAP_SIDE;s.z=MAP_SIDE;
            out[2].push(s);
        }
        Ok(out)
    }

    /// Single-file Save As intentionally does not write adjacent AREA tiles.
    pub fn save_native_as(&mut self,source:&RawArea,
        height_edits:&[(usize,usize,f32)],destination:&std::path::Path)
        ->Result<(usize,usize),String>
    {
        use std::io::Write;
        if destination.extension().and_then(|x|x.to_str())
            .is_none_or(|x|!x.eq_ignore_ascii_case("area")) {
            return Err("Choose an .area destination".into());
        }
        if destination.exists(){
            return Err("Save As refuses to overwrite existing files".into());
        }
        let (bytes,changed_cells)=self.build_native_bytes(source,height_edits)?;
        let mut file=std::fs::OpenOptions::new().write(true).create_new(true)
            .open(destination).map_err(|e|format!("Cannot create {}: {e}",destination.display()))?;
        if let Err(error)=file.write_all(&bytes).and_then(|_|file.sync_all()){
            drop(file);
            let _=std::fs::remove_file(destination);
            return Err(format!("Cannot write AREA: {error}"));
        }
        Ok((height_edits.len(),changed_cells))
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
        let bytes=std::fs::read(&asset.path).ok()?;
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
            "Native Save AREA As: height, textures and RGB color (supported blocks only).");
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
    fn sample_area()->RawArea{
        use wildstar_formats::area::AreaCell;
        let mut blocks=vec![None;32];
        let mut ids=Vec::new();
        for id in [1u32,2,3,4]{ids.extend(id.to_le_bytes());}
        blocks[1]=Some(ids);
        let cell=AreaCell{index:0,flags:1<<1,blocks,subchunks:Vec::new()};
        let mut cells=vec![None;256];
        cells[0]=Some(cell);
        RawArea{version:0,compressed:false,original:Vec::new(),chunks:Vec::new(),
                cells,lod_prefix:None}
    }
    #[test]
    fn painting_undo_redo_and_missing_cell_guards(){
        let mut p=TerrainPaint::default();
        let mut pixels=vec![0u8;MAP_SIDE*MAP_SIDE*4];
        for px in pixels.chunks_exact_mut(4){px[0]=255;}
        p.load(&sample_area(),&pixels,Vec2::ZERO).unwrap();
        assert!(p.ready());
        assert_eq!(p.cell_at(Vec2::new(-247.0,-247.0)),Some(0));
        assert_eq!(p.cell_at(Vec2::new(0.0,0.0)),None);
        p.begin();
        assert!(p.brush(Vec2::new(-248.0,-248.0),2,5.0,2.0,0.3,0.1,None));
        p.end();
        assert!(p.dirty());
        assert!(p.can_undo());
        assert!(p.undo());
        assert!(!p.dirty());
        assert_eq!(p.weights,pixels);
        assert!(p.redo());
        assert!(p.dirty());
        p.begin();
        assert!(!p.brush(Vec2::ZERO,2,4.0,2.0,0.5,0.1,None));
        p.end();
    }
    #[test]
    fn layer_assignment_is_per_cell_undoable_and_never_mutates_raw_area(){
        let source=sample_area();
        let mut p=TerrainPaint::default();
        let mut pixels=vec![0u8;MAP_SIDE*MAP_SIDE*4];
        for px in pixels.chunks_exact_mut(4){px[0]=255;}
        p.load(&source,&pixels,Vec2::ZERO).unwrap();
        p.library.push(WorldLayer{id:99,color_map:"x.tex".into(),
            normal_map:String::new(),meters_per_tile:4.0});
        assert!(p.assign(0,2,99).is_ok());
        assert!(p.rebuild_pending);
        assert_eq!(p.preview_area(&source).cells[0].as_ref().unwrap().layers().unwrap()[2],99);
        assert_eq!(source.cells[0].as_ref().unwrap().layers().unwrap()[2],3);
        assert!(p.assign(0,0,99).is_err());
        assert!(p.undo());
        assert_eq!(p.slots[0][2],3);
        assert!(!p.dirty());
    }
    #[test]
    fn color_brush_undo_redo_and_native_rgb565_plan() {
        let mut source=sample_area();
        let cell=source.cells[0].as_mut().unwrap();
        cell.blocks[3]=Some(vec![0;8450]);
        cell.flags|=1<<3;
        let mut painter=TerrainPaint::default();
        let mut weights=vec![0u8;MAP_SIDE*MAP_SIDE*4];
        for pixel in weights.chunks_exact_mut(4){pixel[0]=255;}
        painter.load(&source,&weights,Vec2::ZERO).unwrap();
        let mut colors=vec![128u8;MAP_SIDE*MAP_SIDE*4];
        for pixel in colors.chunks_exact_mut(4){pixel[3]=255;}
        painter.load_colors(&colors,&source).unwrap();
        painter.color=[200,30,120];
        painter.begin();
        assert!(painter.color_brush(Vec2::new(-248.0,-248.0),4.0,
            2.0,0.3,0.1,None));
        painter.end();
        assert!(painter.dirty());
        assert_eq!(painter.colors[3],255,"BC2 alpha channel must never be painted");
        let (changes,cells)=painter.native_color_edits(&source).unwrap();
        assert_eq!(cells,1);
        assert_eq!(changes.len(),1);
        assert_eq!(changes[0].1,3);
        assert!(painter.undo());
        assert!(!painter.dirty());
        assert_eq!(painter.colors,colors);
        assert!(painter.redo());
        assert!(painter.dirty());
    }
    #[test]
    fn render_source_switches_bit3_and_bit13_without_touching_native_data(){
        let mut area=sample_area();
        let cell=area.cells[0].as_mut().unwrap();
        let mut rgb565=vec![0u8;8450];
        rgb565[..2].copy_from_slice(&0xF800u16.to_le_bytes());
        cell.blocks[3]=Some(rgb565);
        cell.flags|=1<<3;
        let mut bc2=vec![0u8;4624];
        bc2[0]=0xF2; // first alpha=2/15, second alpha=15/15
        bc2[8..10].copy_from_slice(&0x07E0u16.to_le_bytes()); // green
        cell.blocks[13]=Some(bc2);
        cell.flags|=1<<13;
        let mut paint=TerrainPaint::default();
        let mut weights=vec![0u8;MAP_SIDE*MAP_SIDE*4];
        for px in weights.chunks_exact_mut(4){px[0]=255;}
        paint.load(&area,&weights,Vec2::ZERO).unwrap();
        let mut pixels=vec![128u8;MAP_SIDE*MAP_SIDE*4];
        pixels[0..3].copy_from_slice(&[255,0,0]); // Auto uses bit3
        paint.load_colors(&pixels,&area).unwrap();
        assert_eq!(&paint.render_tint(0)[..4],&[255,0,0,34]);
        assert_eq!(&paint.render_tint(1)[..4],&[255,0,0,34]);
        assert_eq!(&paint.render_tint(2)[..4],&[0,255,0,34]);
        assert_eq!(paint.render_tint(2)[7],255);
        assert!(!paint.dirty(),"Preview selection must not change native data");
        paint.color=[42,61,103];
        paint.begin();
        assert!(paint.color_brush(Vec2::new(-255.5,-255.5),2.0,2.0,0.4,0.1,None));
        paint.end();
        let edited=paint.render_tint(2);
        assert_eq!(&edited[0..3],&paint.colors[0..3]);
        assert_eq!(edited[3],34);
        assert!(paint.dirty());
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
