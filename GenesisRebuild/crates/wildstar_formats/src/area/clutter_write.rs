//! Native Clutter writer for existing 64x64 AREA blocks 16 (terrain flags)
//! and 27 (four packed 2-bit WorldLayer clutter selectors).
//!
//! Fail closed for missing/malformed blocks. Preserve unrelated bit fields,
//! all other cell blocks, and all original AREA chunks through RawArea's
//! size-preserving patcher. No ghost samples exist in these 64x64 blocks.
use super::RawArea;
use std::collections::BTreeMap;

#[derive(Debug,Clone,Copy,PartialEq,Eq)]
pub enum ClutterEdit {
    Selector{cell:usize,x:usize,z:usize,slot:usize,preset:u8},
    Suppressed{cell:usize,x:usize,z:usize,hidden:bool},
}
impl ClutterEdit {
    fn target(self)->Result<(usize,usize,usize),String>{
        let (cell,x,z)=match self{
            Self::Selector{cell,x,z,..}|Self::Suppressed{cell,x,z,..}=>(cell,x,z),
        };
        if cell>=256||x>=64||z>=64{
            return Err("Clutter native: target outside existing 16x16 / 64x64 grid".into());
        }
        if let Self::Selector{slot,preset,..}=self{
            if slot>=4||preset>3{
                return Err("Clutter native: slot/preset outside 0..3".into());
            }
        }
        Ok((cell,x,z))
    }
}
pub fn plan(area:&RawArea,changes:&[ClutterEdit])
    ->Result<Vec<(usize,usize,Vec<u8>)>,String>
{
    let mut patches=BTreeMap::<(usize,usize),Vec<u8>>::new();
    for &change in changes{
        let (cell_index,x,z)=change.target()?;
        let bit=match change{
            ClutterEdit::Selector{..}=>27,
            ClutterEdit::Suppressed{..}=>16,
        };
        let cell=area.cells.get(cell_index).and_then(Option::as_ref)
            .ok_or_else(||format!("Clutter native: cell {cell_index} is absent"))?;
        let raw=cell.block(bit).ok_or_else(||format!(
            "Clutter native: cell {cell_index} lacks block {bit}"
        ))?;
        if raw.len()!=64*64{
            return Err(format!(
                "Clutter native: cell {cell_index} has malformed block {bit}"
            ));
        }
        let out=patches.entry((cell_index,bit)).or_insert_with(||raw.to_vec());
        let offset=z*64+x;
        let before=out[offset];
        out[offset]=match change{
            ClutterEdit::Selector{slot,preset,..}=>{
                let shift=slot*2;
                (before&!(3<<shift))|((preset&3)<<shift)
            },
            ClutterEdit::Suppressed{hidden,..}=>{
                if hidden{before|0x20}else{before&!0x20}
            },
        };
    }
    Ok(patches.into_iter().map(|((cell,bit),data)|(cell,bit,data)).collect())
}
/// Check the exact requested bytes, untouched bytes, flags, cell count, prop
/// count, and other native blocks after the saved area has been reparsed.
pub fn validate(source:&RawArea,output:&RawArea,changes:&[ClutterEdit])
    ->Result<(),String>
{
    if source.cell_count()!=output.cell_count()||
        source.prop_count()!=output.prop_count(){
        return Err("Clutter native: AREA cell or prop count changed".into());
    }
    let expected=plan(source,changes)?;
    let mut expected_map=BTreeMap::new();
    for (cell,bit,data) in expected{
        expected_map.insert((cell,bit),data);
    }
    for (index,(before,after)) in source.cells.iter().zip(output.cells.iter()).enumerate(){
        match (before,after) {
            (None,None)=>continue,
            (Some(b),Some(a))=>{
                if b.flags!=a.flags{
                    return Err(format!("Clutter native: changed cell flags at {index}"));
                }
                for bit in 0..32{
                    let expectation=expected_map.get(&(index,bit)).map(Vec::as_slice)
                        .or_else(||b.block(bit));
                    if expectation!=a.block(bit){
                        return Err(format!(
                            "Clutter native: unexpected block {bit} modification at cell {index}"
                        ));
                    }
                }
            },
            _=>return Err("Clutter native: cell occupancy changed".into()),
        }
    }
    Ok(())
}
#[cfg(test)]
mod tests{
    use super::*;
    use super::super::AreaCell;
    fn area()->RawArea{
        let mut blocks=vec![None;32];
        blocks[16]=Some(vec![0x8Bu8;64*64]);
        blocks[27]=Some(vec![0xD8u8;64*64]);
        blocks[3]=Some(vec![0xAAu8;65*65*2]);
        let mut cells=vec![None;256];
        cells[0]=Some(AreaCell{index:0,flags:(1<<16)|(1<<27)|(1<<3),
            blocks,subchunks:Vec::new()});
        RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells,lod_prefix:None}
    }
    #[test]
    fn selector_preserves_other_three_layers_and_suppression_preserves_flags(){
        let a=area();
        let edits=[
            ClutterEdit::Selector{cell:0,x:7,z:9,slot:1,preset:3},
            ClutterEdit::Suppressed{cell:0,x:7,z:9,hidden:true},
            ClutterEdit::Selector{cell:0,x:7,z:9,slot:2,preset:2},
        ];
        let patches=plan(&a,&edits).unwrap();
        assert_eq!(patches.len(),2);
        let mut saved=a.clone();
        for (cell,bit,data) in patches{
            saved.cells[cell].as_mut().unwrap().blocks[bit]=Some(data);
        }
        validate(&a,&saved,&edits).unwrap();
        let old=0xD8u8;
        let new=saved.cells[0].as_ref().unwrap().block(27).unwrap()[9*64+7];
        assert_eq!(new&0b1100_0011,old&0b1100_0011);
        assert_eq!((new>>2)&3,3);
        assert_eq!((new>>4)&3,2);
        let flag=saved.cells[0].as_ref().unwrap().block(16).unwrap()[9*64+7];
        assert_eq!(flag,0x8B|0x20);
        assert_eq!(saved.cells[0].as_ref().unwrap().block(3),a.cells[0].as_ref().unwrap().block(3));
    }
    #[test]
    fn refuses_absent_flags_invalid_slots_and_outside_cells(){
        let mut a=area();
        assert!(plan(&a,&[ClutterEdit::Selector{
            cell:0,x:0,z:0,slot:4,preset:0}]).is_err());
        assert!(plan(&a,&[ClutterEdit::Suppressed{
            cell:0,x:64,z:0,hidden:true}]).is_err());
        assert!(plan(&a,&[ClutterEdit::Selector{
            cell:1,x:0,z:0,slot:0,preset:1}]).is_err());
        a.cells[0].as_mut().unwrap().blocks[27]=None;
        assert!(plan(&a,&[ClutterEdit::Selector{
            cell:0,x:0,z:0,slot:0,preset:1}]).is_err());
    }
    #[test]
    fn stale_or_tampered_output_fails_validation(){
        let a=area();
        let changes=[ClutterEdit::Selector{
            cell:0,x:0,z:0,slot:0,preset:1
        }];
        let mut output=a.clone();
        assert!(validate(&a,&output,&changes).is_err());
        let patches=plan(&a,&changes).unwrap();
        for (cell,bit,data) in patches{
            output.cells[cell].as_mut().unwrap().blocks[bit]=Some(data);
        }
        validate(&a,&output,&changes).unwrap();
        output.cells[0].as_mut().unwrap().blocks[3].as_mut().unwrap()[0]^=1;
        assert!(validate(&a,&output,&changes).is_err());
    }
}
