//! Editable WildStar AREA height workspace.
//! One session per standalone AREA. World-streamed tiles remain read-only.
use bevy::prelude::*;
use std::path::{Path, PathBuf};
use std::io::Write;
use wildstar_formats::area::{HeightGrid, RawArea, tile_heights};

const GRID: usize = 257;
const UNDO_LIMIT: usize = 24;

#[derive(Clone, Copy, PartialEq, Eq)]
pub enum BrushMode { Raise, Smooth, Flatten, Noise }

#[derive(Resource, Default)]
pub struct TerrainEdit {
    pub source: Option<PathBuf>,
    pub origin: Vec2,
    heights: Vec<f32>,
    baseline: Vec<f32>,
    present: Vec<bool>,
    pub cell_count: usize,
    before_stroke: Option<Vec<f32>>,
    flatten_target: Option<f32>,
    undo: Vec<Vec<f32>>,
    redo: Vec<Vec<f32>>,
    pub revision: u64,
    pub mesh_revision: u64,
}

impl TerrainEdit {
    pub fn reset(&mut self) { *self = Self::default(); }
    pub fn is_ready(&self) -> bool { self.source.is_some() && self.heights.len() == GRID * GRID }
    pub fn stroking(&self)->bool{self.before_stroke.is_some()}
    pub fn load(&mut self, source: &Path, area: &RawArea, origin: Vec2) {
        let grid = tile_heights(area);
        *self = Self {
            source: Some(source.to_owned()), origin,
            heights: grid.heights.clone(),
            baseline: grid.heights,
            present: grid.present,
            cell_count: grid.cells,
            revision: 1,
            ..default()
        };
    }
    /// Reserved for enabling/disabling context-sensitive Undo in a future inspector.
    #[allow(dead_code)]
    pub fn can_undo(&self) -> bool { !self.undo.is_empty() }
    /// Reserved for enabling/disabling context-sensitive Redo in a future inspector.
    #[allow(dead_code)]
    pub fn can_redo(&self) -> bool { !self.redo.is_empty() }
    /// Reserved for the pending-changes indicator and save-state UI.
    #[allow(dead_code)]
    pub fn has_changes(&self) -> bool {
        self.is_ready() && self.heights != self.baseline
    }
    pub fn grid(&self) -> Option<HeightGrid> {
        if !self.is_ready() { return None; }
        let mut min = f32::MAX;
        let mut max = f32::MIN;
        for (&h, &present) in self.heights.iter().zip(&self.present) {
            if present { min = min.min(h); max = max.max(h); }
        }
        Some(HeightGrid {
            heights: self.heights.clone(), present: self.present.clone(),
            cells: self.cell_count,
            min: if min.is_finite() { min } else { 0.0 },
            max: if max.is_finite() { max } else { 0.0 },
        })
    }
    /// Sample precisely the same diagonal triangle surface as the rendered
    /// 257x257 height mesh, instead of bilinear heights that could float
    /// above or sink below steep terrain between vertices.
    pub fn surface_height(&self,world:Vec2)->Option<f32>{
        if !self.is_ready(){return None;}
        let x=(world.x-self.origin.x+256.0)*0.5;
        let z=(world.y-self.origin.y+256.0)*0.5;
        if !(0.0..=256.0).contains(&x) || !(0.0..=256.0).contains(&z){return None;}
        let x0=(x.floor() as usize).min(255);
        let z0=(z.floor() as usize).min(255);
        let tx=(x-x0 as f32).clamp(0.0,1.0);
        let tz=(z-z0 as f32).clamp(0.0,1.0);
        let a=z0*GRID+x0;
        let b=a+1;
        let c=a+GRID;
        let d=c+1;
        if [a,b,c,d].iter().any(|&i|!self.present[i]){return None;}
        let (ha,hb,hc,hd)=(self.heights[a],self.heights[b],
                            self.heights[c],self.heights[d]);
        // terrain.rs triangulates: [a,c,b] and [b,c,d].
        Some(if tx+tz<=1.0{
            ha+(hb-ha)*tx+(hc-ha)*tz
        }else{
            hd+(hc-hd)*(1.0-tx)+(hb-hd)*(1.0-tz)
        })
    }

    fn height_bilinear(&self, world: Vec2) -> Option<f32> {
        let x = (world.x - self.origin.x + 256.0) * 0.5;
        let z = (world.y - self.origin.y + 256.0) * 0.5;
        if !(0.0..=256.0).contains(&x) || !(0.0..=256.0).contains(&z) { return None; }
        let x0 = (x.floor() as usize).min(255);
        let z0 = (z.floor() as usize).min(255);
        let tx = (x - x0 as f32).clamp(0.0, 1.0);
        let tz = (z - z0 as f32).clamp(0.0, 1.0);
        let ids = [z0*GRID+x0,z0*GRID+x0+1,(z0+1)*GRID+x0,(z0+1)*GRID+x0+1];
        if ids.iter().any(|&i| !self.present[i]) { return None; }
        let h0 = self.heights[ids[0]] + (self.heights[ids[1]]-self.heights[ids[0]])*tx;
        let h1 = self.heights[ids[2]] + (self.heights[ids[3]]-self.heights[ids[2]])*tx;
        Some(h0 + (h1-h0)*tz)
    }

    /// Ray march against the height field, refine the first entry crossing.
    pub fn raycast(&self, ray: Ray3d) -> Option<Vec3> {
        if !self.is_ready() { return None; }
        let mut last = None::<(f32, f32)>;
        let direction = *ray.direction;
        for i in 0..=2000 {
            let t = i as f32 * 3.0;
            let point = ray.origin + direction * t;
            let delta = self.surface_height(Vec2::new(point.x, point.z))
                .map(|height| point.y - height);
            if let Some(current) = delta {
                if let Some((previous_t, previous_delta)) = last {
                    if previous_delta >= 0.0 && current <= 0.0 {
                        let mut a = previous_t;
                        let mut b = t;
                        for _ in 0..12 {
                            let mid = (a + b) * 0.5;
                            let p = ray.origin + direction * mid;
                            let d = self.surface_height(Vec2::new(p.x,p.z))
                                .map(|h|p.y-h).unwrap_or(1.0);
                            if d > 0.0 { a = mid; } else { b = mid; }
                        }
                        return Some(ray.origin + direction * ((a+b)*0.5));
                    }
                }
                last = Some((t,current));
            } else {
                last = None;
            }
        }
        None
    }

    pub fn begin_stroke(&mut self, point: Vec2) {
        if !self.is_ready() || self.before_stroke.is_some() { return; }
        self.before_stroke = Some(self.heights.clone());
        self.flatten_target = self.height_bilinear(point);
    }

    /// Change the in-memory height grid only; native AREA bytes are not mutated here.
    pub fn brush(&mut self, point: Vec2, radius: f32, strength: f32,
        hardness: f32, falloff: f32, dt: f32, mode: BrushMode) -> bool {
        if !self.is_ready() || self.before_stroke.is_none() { return false; }
        let cx = (point.x - self.origin.x + 256.0) * 0.5;
        let cz = (point.y - self.origin.y + 256.0) * 0.5;
        let radius_grid = (radius * 0.5).max(0.5);
        let x0 = ((cx-radius_grid).floor() as isize).max(0) as usize;
        let x1 = ((cx+radius_grid).ceil() as isize).min(256) as usize;
        let z0 = ((cz-radius_grid).floor() as isize).max(0) as usize;
        let z1 = ((cz+radius_grid).ceil() as isize).min(256) as usize;
        if x0 > x1 || z0 > z1 { return false; }
        let source = self.heights.clone();
        let mut modified = false;
        for z in z0..=z1 {
            for x in x0..=x1 {
                let i = z*GRID+x;
                if !self.present[i] { continue; }
                let d = Vec2::new(x as f32-cx,z as f32-cz).length();
                if d >= radius_grid { continue; }
                let influence = crate::brush_profile::influence(d,radius_grid,hardness,falloff);
                let old = self.heights[i];
                let amount = strength.abs().clamp(0.0, 30.0)*dt.clamp(0.0, 0.1)*influence;
                let new = match mode {
                    BrushMode::Raise => old + strength.signum()*amount*4.0,
                    BrushMode::Flatten => old +
                        (self.flatten_target.unwrap_or(old)-old)*amount.clamp(0.0, 1.0),
                    BrushMode::Smooth => {
                        let mut sum = 0.0;
                        let mut count = 0.0;
                        for nz in z.saturating_sub(1)..=(z+1).min(256) {
                            for nx in x.saturating_sub(1)..=(x+1).min(256) {
                                let ni=nz*GRID+nx;
                                if self.present[ni] { sum+=source[ni]; count+=1.0; }
                            }
                        }
                        if count > 0.0 {
                            old + (sum/count-old)*amount.clamp(0.0,1.0)
                        } else { old }
                    }
                    BrushMode::Noise => {
                        let noise = ((x as f32*0.71).sin()*(z as f32*1.13).cos()).clamp(-1.0,1.0);
                        old+noise*amount*2.0
                    }
                };
                // Native heights are u16 with 1/8 meter resolution.
                let quantized = (((new+2048.0)*8.0).round().clamp(0.0,65535.0))/8.0-2048.0;
                if (old-quantized).abs()>0.00001 {
                    self.heights[i]=quantized;
                    modified=true;
                }
            }
        }
        if modified { self.revision = self.revision.wrapping_add(1); }
        modified
    }

    pub fn end_stroke(&mut self) {
        let Some(before) = self.before_stroke.take() else { return; };
        self.flatten_target = None;
        if before == self.heights { return; }
        self.undo.push(before);
        if self.undo.len() > UNDO_LIMIT { self.undo.remove(0); }
        self.redo.clear();
    }

    pub fn undo(&mut self) -> bool {
        self.end_stroke();
        let Some(previous) = self.undo.pop() else { return false; };
        self.redo.push(std::mem::replace(&mut self.heights, previous));
        self.revision=self.revision.wrapping_add(1);
        true
    }
    pub fn redo(&mut self) -> bool {
        self.end_stroke();
        let Some(next) = self.redo.pop() else { return false; };
        self.undo.push(std::mem::replace(&mut self.heights, next));
        self.revision=self.revision.wrapping_add(1);
        true
    }

    pub fn changes(&self) -> Vec<(usize,usize,f32)> {
        if !self.is_ready() { return Vec::new(); }
        self.heights.iter().zip(&self.baseline).enumerate()
            .filter(|(i,(a,b))| self.present[*i] && (*a-*b).abs() >= 0.0625)
            .map(|(i,(h,_))| (i%GRID,i/GRID,*h))
            .collect()
    }

    /// Save As only: never replace an existing file, including the source.
    /// Serialize + verify before creating the destination. create_new eliminates
    /// a race with files created between the dialog and the write.
    pub fn save_as(&mut self, source: &RawArea, output: &Path) -> Result<usize,String> {
        self.end_stroke();
        if !self.is_ready() { return Err("No editable AREA loaded".into()); }
        if output.extension().and_then(|s|s.to_str()).is_none_or(|s|!s.eq_ignore_ascii_case("area")) {
            return Err("Choose an .area destination".into());
        }
        if self.source.as_deref()==Some(output) || output.exists() {
            return Err("Save As refuses to overwrite existing files".into());
        }
        let changes=self.changes();
        if changes.is_empty() { return Err("No terrain heights changed".into()); }
        let bytes=source.with_height_changes(&changes)?;
        let reread=RawArea::from_bytes(bytes.clone())?;
        if reread.cell_count()!=source.cell_count() || reread.prop_count()!=source.prop_count() {
            return Err("AREA validation failed: cell or prop count changed".into());
        }
        let mut file=std::fs::OpenOptions::new().write(true).create_new(true)
            .open(output).map_err(|e|format!("Cannot create {}: {e}",output.display()))?;
        if let Err(error)=file.write_all(&bytes).and_then(|_|file.sync_all()) {
            drop(file);
            let _=std::fs::remove_file(output);
            return Err(format!("Failed to write AREA: {error}"));
        }
        Ok(changes.len())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn missing_session_rejects_strokes_and_writes() {
        let mut session=TerrainEdit::default();
        assert!(!session.brush(Vec2::ZERO, 10.0, 1.0, 0.58, 0.5, 0.1, BrushMode::Raise));
        assert_eq!(session.changes().len(),0);
        assert!(!session.undo());
    }
}
