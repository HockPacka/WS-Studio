//! Per-cell incremental native Clutter entity rebuild planner.
//! Comparing the new deterministic placement set with the last rendered
//! placement set also detects changes caused by a shared global instance cap.
//! Never remove unchanged cells' existing Bevy entities.
use std::collections::{BTreeMap,BTreeSet,hash_map::DefaultHasher};
use std::hash::{Hash,Hasher};
use wildstar_formats::area::{HeightGrid,RawArea};
use crate::terrain_paint::TerrainPaint;
use crate::clutter_native::NativePlacement;
pub type CellPlacements=BTreeMap<usize,Vec<NativePlacement>>;

#[derive(Debug,Default,PartialEq,Eq)]
pub struct Plan{
    pub replace:BTreeSet<usize>,
    pub retain:usize,
}
pub fn by_cell(placements:Vec<NativePlacement>)->CellPlacements{
    let mut result=CellPlacements::new();
    for p in placements {
        result.entry(p.cell).or_default().push(p);
    }
    result
}
pub fn diff(previous:&CellPlacements,next:&CellPlacements)->Plan{
    let mut result=Plan::default();
    for &cell in previous.keys().chain(next.keys()).collect::<BTreeSet<_>>() {
        if previous.get(&cell)!=next.get(&cell) {
            result.replace.insert(cell);
        } else {
            result.retain+=1;
        }
    }
    result
}
/// CPU-side change detection, scoped to a single native 32 metre cell.
/// Hash exactly the data which influences Clutter generation:
/// native layer IDs, weight blocks, clutter selectors/masks, 17x17 height
/// samples (including neighboring shared vertices) and live painted weights.
/// Unlike the old full-AREA scan, unchanged cell RNG/height/weight sampling
/// is skipped entirely. Color-only strokes do not trigger regeneration.
pub fn fingerprint(
    area:&RawArea,grid:&HeightGrid,paint:Option<&TerrainPaint>,index:usize,
)->u64{
    let mut hasher=DefaultHasher::new();
    index.hash(&mut hasher);
    if index>=256{return hasher.finish();}
    if let Some(cell)=area.cells.get(index).and_then(Option::as_ref){
        for bit in [1,2,16,17,18,19,20,27,29]{
            bit.hash(&mut hasher);
            cell.block(bit).hash(&mut hasher);
        }
    }else{
        false.hash(&mut hasher);
    }
    let cx=index%16*16;
    let cz=index/16*16;
    for z in cz..=cz+16{
        for x in cx..=cx+16{
            let p=z*257+x;
            grid.present.get(p).copied().unwrap_or(false).hash(&mut hasher);
            grid.heights.get(p).map(|v|v.to_bits()).hash(&mut hasher);
        }
    }
    if let Some(paint)=paint.filter(|p|p.ready()){
        let wx=index%16*64;
        let wz=index/16*64;
        for z in wz..=wz+64{
            for x in wx..=wx+64{
                let offset=(z*1024+x)*4;
                paint.weights.get(offset..offset+4).hash(&mut hasher);
            }
        }
    }
    hasher.finish()
}
#[cfg(test)]
mod tests{
    use super::*;
    use bevy::prelude::Vec3;
    fn p(cell:usize,id:&str)->NativePlacement{
        NativePlacement{cell,position:Vec3::new(cell as f32,2.0,3.0),
            yaw:0.3,scale:1.0,model:id.into()}
    }
    #[test]
    fn fingerprint_reacts_only_to_relevant_native_cell_data(){
        use wildstar_formats::area::AreaCell;
        let mut blocks=vec![None;32];
        blocks[1]=Some(vec![0u8;16]);
        blocks[16]=Some(vec![0u8;64*64]);
        blocks[27]=Some(vec![0u8;64*64]);
        let cell=AreaCell{index:0,flags:(1<<1)|(1<<16)|(1<<27),
            blocks,subchunks:Vec::new()};
        let mut cells=vec![None;256];
        cells[0]=Some(cell);
        let mut area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None};
        let mut grid=HeightGrid{heights:vec![0.0;257*257],
            present:vec![true;257*257],cells:1,min:0.0,max:0.0};
        let before=fingerprint(&area,&grid,None,0);
        let untouched=fingerprint(&area,&grid,None,1);
        area.cells[0].as_mut().unwrap().blocks[27].as_mut().unwrap()[123]=2;
        assert_ne!(fingerprint(&area,&grid,None,0),before);
        assert_eq!(fingerprint(&area,&grid,None,1),untouched);
        // A boundary height vertex belongs to both neighbouring cells.
        let old_a=fingerprint(&area,&grid,None,0);
        let old_b=fingerprint(&area,&grid,None,1);
        grid.heights[8*257+16]=6.0;
        assert_ne!(fingerprint(&area,&grid,None,0),old_a);
        assert_ne!(fingerprint(&area,&grid,None,1),old_b);
        assert_eq!(fingerprint(&area,&grid,None,17),
            fingerprint(&area,&grid,None,17));
    }
    #[test]
    fn changed_cell_rebuilds_only_changed_group(){
        let old=by_cell(vec![p(1,"A"),p(3,"B"),p(3,"C"),p(9,"D")]);
        let new=by_cell(vec![p(1,"A"),p(3,"B"),p(3,"X"),p(9,"D")]);
        let plan=diff(&old,&new);
        assert_eq!(plan.replace,BTreeSet::from([3]));
        assert_eq!(plan.retain,2);
    }
    #[test]
    fn removed_cells_and_new_cells_are_both_dirty(){
        let old=by_cell(vec![p(1,"A"),p(9,"Z")]);
        let new=by_cell(vec![p(1,"A"),p(2,"B")]);
        let plan=diff(&old,&new);
        assert_eq!(plan.replace,BTreeSet::from([2,9]));
        assert_eq!(plan.retain,1);
    }
    #[test]
    fn unchanged_candidates_cause_zero_entity_rebuilds(){
        let old=by_cell(vec![p(1,"A"),p(9,"B")]);
        let new=by_cell(vec![p(1,"A"),p(9,"B")]);
        assert_eq!(diff(&old,&new),Plan{replace:BTreeSet::new(),retain:2});
    }
    #[test]
    fn global_instance_budget_eviction_is_detected(){
        let before=by_cell(vec![p(0,"A"),p(1,"B"),p(2,"C")]);
        let after=by_cell(vec![p(0,"A"),p(0,"A2"),p(1,"B")]);
        assert_eq!(diff(&before,&after).replace,BTreeSet::from([0,2]));
    }
}
