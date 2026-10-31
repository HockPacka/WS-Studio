//! Read-only AREA bits 19/20 reverse-engineering diagnostics.
//!
//! Binary evidence links bit 29 authoring weights to BC1 pair 19/20, but the
//! exact shader permutation, correction scale and alpha/coverage semantics
//! have NOT been confirmed in the original retail renderer.
//!
//! Deliberately separate from the production decoder and AREA writers.
//! Every numeric result below is a candidate hypothesis, not proof of parity.
use super::{AreaCell,RawArea};

const SIDE:usize=65;
const BLOCKS:usize=17;

#[derive(Debug,Clone,Copy,PartialEq,Eq)]
pub enum CorrectionHypothesis {
    /// RGB = base + (correction * (31/15,63/31,31/15) - 1)
    Direct,
    /// RGB = base + 0.5 * (correction * factor - 1) (old Genesis hypothesis)
    Half,
    /// Direct correction multiplied by the BC1 base alpha coverage
    DirectCoverage,
    /// Half correction multiplied by the BC1 base alpha coverage
    HalfCoverage,
}
impl CorrectionHypothesis {
    pub const ALL:[Self;4]=[
        Self::Direct,Self::Half,Self::DirectCoverage,Self::HalfCoverage
    ];
    pub fn label(self)->&'static str {
        match self{
            Self::Direct=>"direct",
            Self::Half=>"half",
            Self::DirectCoverage=>"direct_coverage",
            Self::HalfCoverage=>"half_coverage",
        }
    }
    pub fn index(self)->usize{
        match self{
            Self::Direct=>0,Self::Half=>1,
            Self::DirectCoverage=>2,Self::HalfCoverage=>3,
        }
    }
}
#[derive(Debug,Clone,Copy,Default)]
struct BC1Sample {
    rgb:[f32;3],
    coverage:f32,
    three_color:bool,
}
/// Decode both BC1 endpoint orders, including index 3 transparent in the
/// three-color mode. The fourth layer is implicit: max(0,1-sum(rgb)).
fn bc1_sample(block:&[u8],x:usize,z:usize)->Option<BC1Sample>{
    if block.len()!=8||x>=4||z>=4{return None;}
    let a=u16::from_le_bytes([block[0],block[1]]);
    let b=u16::from_le_bytes([block[2],block[3]]);
    let selectors=u32::from_le_bytes(block[4..8].try_into().ok()?);
    let which=((selectors>>((z*4+x)*2))&3) as usize;
    let unpack=|n:u16|[
        ((n>>11)&31) as f32/31.0,
        ((n>>5)&63) as f32/63.0,
        (n&31) as f32/31.0,
    ];
    let p=unpack(a);
    let q=unpack(b);
    let three=a<=b;
    let (rgb,coverage)=match which{
        0=>(p,1.0),
        1=>(q,1.0),
        2=>(
            if three {std::array::from_fn(|i|(p[i]+q[i])*0.5)}
            else{std::array::from_fn(|i|(2.0*p[i]+q[i])/3.0)},1.0
        ),
        _ if three=>([0.0;3],0.0),
        _=>(std::array::from_fn(|i|(p[i]+2.0*q[i])/3.0),1.0),
    };
    Some(BC1Sample{rgb,coverage,three_color:three})
}
fn sample_pair(
    cell:&AreaCell,base_bit:usize,correction_bit:usize,
    x:usize,z:usize,model:CorrectionHypothesis,
)->Option<([f32;4],BC1Sample)>{
    if x>=SIDE||z>=SIDE{return None;}
    let base=cell.block(base_bit)?;
    let corr=cell.block(correction_bit)?;
    if base.len()!=BLOCKS*BLOCKS*8||corr.len()!=BLOCKS*BLOCKS*8 {
        return None;
    }
    let bx=x/4;
    let bz=z/4;
    let block_offset=(bz*BLOCKS+bx)*8;
    let sample_base=bc1_sample(&base[block_offset..block_offset+8],x%4,z%4)?;
    let sample_corr=bc1_sample(&corr[block_offset..block_offset+8],x%4,z%4)?;
    let factors=[31.0/15.0,63.0/31.0,31.0/15.0];
    let multiplier=match model{
        CorrectionHypothesis::Direct|CorrectionHypothesis::DirectCoverage=>1.0,
        _=>0.5,
    };
    let coverage=match model{
        CorrectionHypothesis::DirectCoverage|CorrectionHypothesis::HalfCoverage=>
            sample_base.coverage,
        _=>1.0,
    };
    let mut rgba=[0.0f32;4];
    for i in 0..3 {
        rgba[i]=(sample_base.rgb[i]+
            (sample_corr.rgb[i]*factors[i]-1.0)*multiplier).clamp(0.0,1.0);
    }
    rgba[3]=(1.0-rgba[0]-rgba[1]-rgba[2]).clamp(0.0,1.0);
    // Direct coverage is an actual hypothesis; zero-coverage samples carry
    // no material weights. Do not silently replace them with base-layer 1.
    for v in &mut rgba {*v*=coverage;}
    let sum: f32=rgba.iter().sum();
    if sum>1e-6 {
        for v in &mut rgba{*v/=sum;}
    }
    Some((rgba,sample_base))
}
fn raw29(cell:&AreaCell,x:usize,z:usize)->Option<[f32;4]>{
    let raw=cell.normalized_weights(x,z)?;
    let sum=raw.iter().map(|v|*v as f32).sum::<f32>();
    if sum==0.0{return None;}
    Some(raw.map(|v|v as f32/sum))
}
#[derive(Debug,Clone,Copy,Default)]
pub struct ModelError {
    pub sample_count:usize,
    pub mean_abs_error:f64,
    pub max_abs_error:f64,
    pub within_2_of_255:usize,
    pub within_10_of_255:usize,
}
#[derive(Debug,Clone)]
pub struct CellWeightResearch {
    pub index:usize,
    pub has_bit29:bool,
    pub has_pair19_20:bool,
    pub has_pair17_18:bool,
    pub pair19_base_3color_blocks:usize,
    pub pair19_corr_3color_blocks:usize,
    pub pair19_base_transparent_samples:usize,
    pub compared_samples:usize,
    pub errors:[ModelError;4],
    pub best_model:Option<CorrectionHypothesis>,
}
impl CellWeightResearch {
    pub fn to_csv_row(&self)->String{
        let mut parts=vec![
            self.index.to_string(),
            self.has_bit29.to_string(),
            self.has_pair19_20.to_string(),
            self.has_pair17_18.to_string(),
            self.pair19_base_3color_blocks.to_string(),
            self.pair19_corr_3color_blocks.to_string(),
            self.pair19_base_transparent_samples.to_string(),
            self.compared_samples.to_string(),
            self.best_model.map(|m|m.label()).unwrap_or("none").to_string(),
        ];
        for error in &self.errors {
            parts.push(error.sample_count.to_string());
            parts.push(format!("{:.8}",error.mean_abs_error));
            parts.push(format!("{:.8}",error.max_abs_error));
            parts.push(error.within_2_of_255.to_string());
            parts.push(error.within_10_of_255.to_string());
        }
        parts.join(",")
    }
}
fn three_color_count(block:Option<&[u8]>)->usize{
    let Some(bytes)=block else{return 0;};
    bytes.chunks_exact(8).filter(|chunk|{
        let a=u16::from_le_bytes([chunk[0],chunk[1]]);
        let b=u16::from_le_bytes([chunk[2],chunk[3]]);
        a<=b
    }).count()
}
/// Reproducible, full-resolution comparison of all 65×65 samples to bit 29.
/// Missing raw 29 and zero-sum raw samples are explicitly excluded from MAE.
/// No original AREA bytes are modified.
pub fn inspect_cell(cell:&AreaCell)->CellWeightResearch {
    let mut result=CellWeightResearch{
        index:cell.index,
        has_bit29:cell.block(29).is_some(),
        has_pair19_20:cell.block(19).is_some()&&cell.block(20).is_some(),
        has_pair17_18:cell.block(17).is_some()&&cell.block(18).is_some(),
        pair19_base_3color_blocks:three_color_count(cell.block(19)),
        pair19_corr_3color_blocks:three_color_count(cell.block(20)),
        pair19_base_transparent_samples:0,
        compared_samples:0,
        errors:[ModelError::default();4],
        best_model:None,
    };
    if !result.has_pair19_20{return result;}
    let mut sum=[0.0f64;4];
    for z in 0..SIDE{
        for x in 0..SIDE{
            if let Some((_,base))=sample_pair(
                cell,19,20,x,z,CorrectionHypothesis::Direct) {
                if base.coverage==0.0 {
                    result.pair19_base_transparent_samples+=1;
                }
            }
            let Some(target)=raw29(cell,x,z) else{continue;};
            result.compared_samples+=1;
            for (i,model) in CorrectionHypothesis::ALL.iter().enumerate(){
                let Some((sample,_))=sample_pair(cell,19,20,x,z,*model)
                    else{continue;};
                let error=&mut result.errors[i];
                error.sample_count+=1;
                let mut local_max=0.0f64;
                for c in 0..4{
                    let delta=(target[c]-sample[c]).abs() as f64;
                    sum[i]+=delta;
                    local_max=local_max.max(delta);
                    error.max_abs_error=error.max_abs_error.max(delta);
                }
                if local_max<=2.0/255.0{error.within_2_of_255+=1;}
                if local_max<=10.0/255.0{error.within_10_of_255+=1;}
            }
        }
    }
    for i in 0..4{
        let n=result.errors[i].sample_count;
        if n>0{
            result.errors[i].mean_abs_error=sum[i]/(n*4) as f64;
        }
    }
    result.best_model=CorrectionHypothesis::ALL.iter().copied()
        .filter(|m|result.errors[m.index()].sample_count>0)
        .min_by(|a,b|{
            result.errors[a.index()].mean_abs_error.total_cmp(
                &result.errors[b.index()].mean_abs_error)
        });
    result
}

#[derive(Debug,Clone)]
pub struct AreaWeightResearch{
    pub cells:Vec<CellWeightResearch>,
    pub present_pairs:usize,
    pub paired_with_bit29:usize,
    pub compared_samples:usize,
    /// Best among cells with bit 29, based on aggregate channel MAE.
    pub aggregate:[ModelError;4],
    pub best_model:Option<CorrectionHypothesis>,
}
impl AreaWeightResearch{
    pub fn inspect(area:&RawArea)->Self{
        let cells=area.cells.iter().flatten()
            .map(inspect_cell).collect::<Vec<_>>();
        let present_pairs=cells.iter().filter(|c|c.has_pair19_20).count();
        let paired_with_bit29=cells.iter()
            .filter(|c|c.has_pair19_20&&c.has_bit29).count();
        let compared_samples=cells.iter().map(|c|c.compared_samples).sum();
        let mut aggregate=[ModelError::default();4];
        for cell in &cells{
            for i in 0..4{
                let source=cell.errors[i];
                let dst=&mut aggregate[i];
                dst.mean_abs_error+=source.mean_abs_error*
                    (source.sample_count*4) as f64;
                dst.sample_count+=source.sample_count;
                dst.max_abs_error=dst.max_abs_error.max(source.max_abs_error);
                dst.within_2_of_255+=source.within_2_of_255;
                dst.within_10_of_255+=source.within_10_of_255;
            }
        }
        for metric in &mut aggregate{
            if metric.sample_count>0{
                metric.mean_abs_error/=(metric.sample_count*4) as f64;
            }
        }
        let best_model=CorrectionHypothesis::ALL.iter().copied()
            .filter(|m|aggregate[m.index()].sample_count>0)
            .min_by(|a,b|{
                aggregate[a.index()].mean_abs_error.total_cmp(
                    &aggregate[b.index()].mean_abs_error)
            });
        Self{cells,present_pairs,paired_with_bit29,
            compared_samples,aggregate,best_model}
    }
    pub fn csv(&self)->String{
        let mut csv=String::from(
            "cell,bit29,pair19_20,pair17_18,base_3color_blocks,corr_3color_blocks,base_transparent_samples,compared_samples,best_model"
        );
        for model in CorrectionHypothesis::ALL{
            for field in ["samples","mean_abs","max_abs","within_2_255","within_10_255"]{
                csv.push(',');
                csv.push_str(model.label());
                csv.push('_');
                csv.push_str(field);
            }
        }
        csv.push('\n');
        for cell in &self.cells{
            csv.push_str(&cell.to_csv_row());
            csv.push('\n');
        }
        csv
    }
}

#[cfg(test)]
mod tests{
    use super::*;
    fn cell()->AreaCell{
        let mut blocks=vec![None;32];
        let mut base=vec![0u8;17*17*8];
        let mut corr=vec![0u8;17*17*8];
        let mut raw=vec![0u8;65*65*2];
        for px in raw.chunks_exact_mut(2){
            px.copy_from_slice(&0x000Fu16.to_le_bytes());
        }
        for block in base.chunks_exact_mut(8){
            block[..2].copy_from_slice(&0xF800u16.to_le_bytes());
            block[2..4].copy_from_slice(&0x0000u16.to_le_bytes());
        }
        for block in corr.chunks_exact_mut(8){
            block[..2].copy_from_slice(&0x7BF0u16.to_le_bytes());
            block[2..4].copy_from_slice(&0x7BEFu16.to_le_bytes());
            block[4..].copy_from_slice(&0x5555_5555u32.to_le_bytes());
        }
        blocks[19]=Some(base);
        blocks[20]=Some(corr);
        blocks[29]=Some(raw);
        AreaCell{index:7,flags:(1<<19)|(1<<20)|(1<<29),
            blocks,subchunks:Vec::new()}
    }
    #[test]
    fn bc1_modes_and_alpha_coverage_are_decoded_without_inventing_rgb(){
        let mut block=[0u8;8];
        block[..2].copy_from_slice(&0x001Fu16.to_le_bytes());
        block[2..4].copy_from_slice(&0xF800u16.to_le_bytes());
        block[4..].copy_from_slice(&0xE4u32.to_le_bytes());
        let a=bc1_sample(&block,0,0).unwrap();
        let b=bc1_sample(&block,1,0).unwrap();
        let mid=bc1_sample(&block,2,0).unwrap();
        let transparent=bc1_sample(&block,3,0).unwrap();
        assert!(a.three_color);
        assert_eq!(a.rgb,[0.0,0.0,1.0]);
        assert_eq!(b.rgb,[1.0,0.0,0.0]);
        assert_eq!(mid.rgb,[0.5,0.0,0.5]);
        assert_eq!(transparent.coverage,0.0);
        assert_eq!(transparent.rgb,[0.0,0.0,0.0]);
        block[..2].copy_from_slice(&0xF800u16.to_le_bytes());
        block[2..4].copy_from_slice(&0x001Fu16.to_le_bytes());
        let opaque=bc1_sample(&block,3,0).unwrap();
        assert!(!opaque.three_color);
        assert_eq!(opaque.coverage,1.0);
        assert!(opaque.rgb[0]>0.0&&opaque.rgb[2]>0.0);
    }
    #[test]
    fn full_cell_compares_4225_samples_and_reports_all_hypotheses(){
        let original=cell();
        let before19=original.block(19).unwrap().to_vec();
        let research=inspect_cell(&original);
        assert_eq!(research.compared_samples,65*65);
        assert_eq!(research.errors[0].sample_count,65*65);
        assert_eq!(research.errors[3].sample_count,65*65);
        assert!(research.errors[0].mean_abs_error<0.04);
        assert_eq!(original.block(19).unwrap(),before19);
        let mut missing=original.clone();
        missing.blocks[29]=None;
        assert_eq!(inspect_cell(&missing).compared_samples,0);
        missing.blocks[29]=Some(vec![0u8;65*65*2]);
        assert_eq!(inspect_cell(&missing).compared_samples,0);
    }
    #[test]
    fn report_counts_cells_and_has_parseable_fixed_column_csv(){
        let c=cell();
        let mut tiles=vec![None;256];
        tiles[7]=Some(c);
        let area=RawArea{version:0,compressed:false,original:Vec::new(),
            chunks:Vec::new(),cells:tiles,lod_prefix:None};
        let summary=AreaWeightResearch::inspect(&area);
        assert_eq!(summary.present_pairs,1);
        assert_eq!(summary.paired_with_bit29,1);
        assert_eq!(summary.compared_samples,65*65);
        let csv=summary.csv();
        assert_eq!(csv.lines().count(),2);
        let lines=csv.lines().collect::<Vec<_>>();
        assert_eq!(lines[0].split(',').count(),lines[1].split(',').count());
        assert!(csv.contains("direct_coverage_mean_abs"));
    }
}
