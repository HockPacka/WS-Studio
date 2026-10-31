//! Per-cell incremental native Clutter entity rebuild planner.
//! Comparing the new deterministic placement set with the last rendered
//! placement set also detects changes caused by a shared global instance cap.
//! Never remove unchanged cells' existing Bevy entities.
use std::collections::{BTreeMap,BTreeSet};
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
#[cfg(test)]
mod tests{
    use super::*;
    use bevy::prelude::Vec3;
    fn p(cell:usize,id:&str)->NativePlacement{
        NativePlacement{cell,position:Vec3::new(cell as f32,2.0,3.0),
            yaw:0.3,scale:1.0,model:id.into()}
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
