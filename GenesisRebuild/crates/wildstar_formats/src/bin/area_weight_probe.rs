//! Offline, READ-ONLY Bit 19/20 research across original WildStar AREA files.
//!
//! Run from GenesisRebuild:
//! cargo run -p wildstar_formats --bin area_weight_probe -- \
//!   --root "D:\\WildStar\\ClientData\\World" --out "D:\\Research" --max-files 1000
//!
//! Never exports game assets or modifies original AREA files. The destination
//! must be an existing directory, and both CSV files use create_new.
use std::{
    collections::BTreeSet,
    env,fs,
    fs::OpenOptions,
    io::Write,
    path::{Path,PathBuf},
};
use wildstar_formats::area::{
    RawArea,
    weight_research::{AreaWeightResearch,CorrectionHypothesis},
};

const DEFAULT_LIMIT:usize=250;
const MAX_AREA_BYTES:u64=128*1024*1024;
const AREA_CSV:&str="Genesis_Bit19_20_Areas.csv";
const CELL_CSV:&str="Genesis_Bit19_20_Cells.csv";

struct Options{
    inputs:Vec<PathBuf>,
    output:PathBuf,
    max_files:usize,
}
fn usage()->&'static str{
    "Usage: area_weight_probe --root <AREA folder> [--root <folder> ...] \
     [--file <AREA file> ...] --out <existing output folder> \
     [--max-files <positive number>]\n\
     This tool only reads .area files; it creates two NEW CSV reports."
}
fn options(args:impl IntoIterator<Item=String>)->Result<Options,String>{
    let mut it=args.into_iter();
    let mut inputs=Vec::new();
    let mut output=None;
    let mut max_files=DEFAULT_LIMIT;
    while let Some(flag)=it.next(){
        match flag.as_str(){
            "--root"|"--file"=>{
                let value=it.next().ok_or("Missing path after --root/--file")?;
                inputs.push(PathBuf::from(value));
            },
            "--out"=>{
                let value=it.next().ok_or("Missing output folder after --out")?;
                if output.replace(PathBuf::from(value)).is_some(){
                    return Err("--out specified more than once".into());
                }
            },
            "--max-files"=>{
                let value=it.next().ok_or("Missing --max-files value")?;
                max_files=value.parse::<usize>()
                    .map_err(|_|"--max-files must be an integer")?;
                if max_files==0||max_files>100_000{
                    return Err("--max-files must be in 1..=100000".into());
                }
            },
            "--help"|"-h"=>return Err(usage().into()),
            _=>return Err(format!("Unrecognized flag {flag:?}\n{}",usage())),
        }
    }
    if inputs.is_empty(){return Err(format!("No input given. {}",usage()));}
    let output=output.ok_or_else(||format!("--out required. {}",usage()))?;
    if !output.is_dir(){
        return Err(format!("Output folder {} does not exist",output.display()));
    }
    Ok(Options{inputs,output,max_files})
}
fn is_area(p:&Path)->bool{
    p.extension().and_then(|v|v.to_str())
        .is_some_and(|v|v.eq_ignore_ascii_case("area"))
}
/// Never follow filesystem symlinks/junction shortcuts. Globally sort the
/// result for reproducible row order on Windows and Linux.
fn discover(inputs:&[PathBuf],limit:usize)->Result<Vec<PathBuf>,String>{
    let mut pending=inputs.to_vec();
    let mut found=BTreeSet::new();
    let mut visited=BTreeSet::new();
    while let Some(path)=pending.pop(){
        let info=fs::symlink_metadata(&path).map_err(|e|
            format!("Cannot inspect {}: {e}",path.display()))?;
        if info.file_type().is_symlink(){continue;}
        if info.is_dir(){
            let canonical=fs::canonicalize(&path).map_err(|e|e.to_string())?;
            if !visited.insert(canonical){continue;}
            let entries=fs::read_dir(&path).map_err(|e|
                format!("Cannot enumerate {}: {e}",path.display()))?;
            for entry in entries{
                let entry=entry.map_err(|e|e.to_string())?;
                pending.push(entry.path());
            }
        }else if info.is_file()&&is_area(&path){
            let canonical=fs::canonicalize(&path).map_err(|e|e.to_string())?;
            found.insert(canonical);
            if found.len()>limit{
                return Err(format!(
                    "Found more than {limit} AREA files. Increase --max-files to analyze all; no partial report was created."
                ));
            }
        }
    }
    Ok(found.into_iter().collect())
}
fn escape_csv(s:&str)->String{
    let mut text=String::from("\"");
    for c in s.chars(){
        if c=='\"'{text.push_str("\"\"");}
        else if c=='\r'||c=='\n'{text.push(' ');}
        else{text.push(c);}
    }
    text.push('\"');
    text
}
fn metric_header()->String{
    let mut columns=Vec::new();
    for model in CorrectionHypothesis::ALL{
        let name=model.label();
        for field in ["sample_count","mean_abs","max_abs","within_2_of_255",
            "within_10_of_255"]{
            columns.push(format!("{name}_{field}"));
        }
    }
    columns.join(",")
}
fn metric_row(report:&AreaWeightResearch)->String{
    let mut columns=Vec::new();
    for model in CorrectionHypothesis::ALL{
        let m=report.aggregate[model.index()];
        columns.extend([
            m.sample_count.to_string(),
            format!("{:.9}",m.mean_abs_error),
            format!("{:.9}",m.max_abs_error),
            m.within_2_of_255.to_string(),
            m.within_10_of_255.to_string(),
        ]);
    }
    columns.join(",")
}
struct Report{
    areas:String,
    cells:String,
    scanned:usize,
    with_pairs:usize,
    with_comparison:usize,
    errors:usize,
    ambiguous:usize,
    anomalous_cells:usize,
}
fn analyze(paths:&[PathBuf])->Report{
    let mut r=Report{
        areas:format!(
            "source,status,details,cell_count,paired19_20,paired_with_bit29,compared_samples,best_unique_model,ambiguous_cells,high_error_cells,{}\n",
            metric_header()
        ),
        cells:String::from("source,status,high_error,"),
        scanned:0,with_pairs:0,with_comparison:0,errors:0,
        ambiguous:0,anomalous_cells:0,
    };
    // Reuse the native research header, avoiding changes to its column order.
    let cell_header=AreaWeightResearch{
        cells:Vec::new(),present_pairs:0,paired_with_bit29:0,
        compared_samples:0,aggregate:Default::default(),best_model:None,
    }.csv();
    r.cells.push_str(cell_header.lines().next().unwrap_or("cell"));
    r.cells.push('\n');
    for path in paths{
        r.scanned+=1;
        let quoted_path=escape_csv(&path.to_string_lossy());
        let result=(||->Result<AreaWeightResearch,String>{
            let meta=fs::metadata(path).map_err(|e|e.to_string())?;
            if meta.len()>MAX_AREA_BYTES{
                return Err(format!(
                    "AREA exceeds 128 MiB guard ({} bytes)",meta.len()
                ));
            }
            let area=RawArea::from_path(path)?;
            Ok(AreaWeightResearch::inspect(&area))
        })();
        match result{
            Ok(report)=>{
                if report.present_pairs>0{r.with_pairs+=1;}
                if report.compared_samples>0{r.with_comparison+=1;}
                let ambiguous=report.cells.iter().filter(|cell|
                    cell.compared_samples>0&&cell.best_model.is_none()
                ).count();
                // Heuristic review flag only, not proof of a decoding bug.
                let anomalies=report.cells.iter().filter(|cell|
                    cell.compared_samples>0&&cell.errors.iter()
                        .filter(|e|e.sample_count>0)
                        .all(|e|e.mean_abs_error>0.10)
                ).count();
                r.ambiguous+=ambiguous;
                r.anomalous_cells+=anomalies;
                r.areas.push_str(&format!(
                    "{quoted_path},ok,\"\",{},{},{},{},{},{},{},{}\n",
                    report.cells.len(),report.present_pairs,
                    report.paired_with_bit29,report.compared_samples,
                    escape_csv(report.best_model.map(|m|m.label())
                        .unwrap_or("ambiguous_or_unavailable")),
                    ambiguous,anomalies,metric_row(&report),
                ));
                for cell in &report.cells{
                    let unusual=cell.compared_samples>0&&cell.errors.iter()
                        .filter(|e|e.sample_count>0)
                        .all(|e|e.mean_abs_error>0.10);
                    r.cells.push_str(&format!(
                        "{quoted_path},ok,{unusual},{}\n",cell.to_csv_row()
                    ));
                }
            },
            Err(error)=>{
                r.errors+=1;
                r.areas.push_str(&format!(
                    "{quoted_path},error,{},0,0,0,0,\"none\",0,0,{}\n",
                    escape_csv(&error),std::iter::repeat_n("0",20)
                        .collect::<Vec<_>>().join(",")
                ));
            },
        }
    }
    r
}
/// Write both reports only after the entire collection has been analyzed.
/// Roll back files created by this call if the second write fails. Never
/// unlink a report already existing before this operation.
fn write_reports(output:&Path,r:&Report)->Result<(),String>{
    let areas=output.join(AREA_CSV);
    let cells=output.join(CELL_CSV);
    if areas.exists()||cells.exists(){
        return Err("Research CSV already exists; choose a different output folder. No overwrite.".into());
    }
    let mut owned=Vec::new();
    for (path,data) in [(&areas,&r.areas),(&cells,&r.cells)]{
        let result=(||->Result<(),String>{
            let mut f=OpenOptions::new().write(true).create_new(true)
                .open(path).map_err(|e|format!("Cannot create {}: {e}",path.display()))?;
            owned.push(path.clone());
            f.write_all(data.as_bytes()).and_then(|_|f.sync_all())
                .map_err(|e|format!("Cannot write {}: {e}",path.display()))
        })();
        if let Err(error)=result{
            for path in owned{let _=fs::remove_file(path);}
            return Err(error);
        }
    }
    Ok(())
}
fn main(){
    let result=(||->Result<(),String>{
        let cfg=options(env::args().skip(1))?;
        let paths=discover(&cfg.inputs,cfg.max_files)?;
        if paths.is_empty(){return Err("No .area files found".into());}
        eprintln!("Read-only Bit19/20 research: {} AREA files",paths.len());
        let report=analyze(&paths);
        write_reports(&cfg.output,&report)?;
        println!("Scanned {} AREA files; pair19/20 in {}, comparable bit29 in {}, parse errors {}, ambiguous cells {}, high-error cells {}.",
            report.scanned,report.with_pairs,report.with_comparison,
            report.errors,report.ambiguous,report.anomalous_cells);
        println!("Research CSV: {} and {}",
            cfg.output.join(AREA_CSV).display(),
            cfg.output.join(CELL_CSV).display());
        if report.errors>0 {
            eprintln!("Some AREA files could not be parsed. See per-file error rows in the summary CSV.");
        }
        Ok(())
    })();
    if let Err(error)=result{
        eprintln!("{error}");
        std::process::exit(1);
    }
}
#[cfg(test)]
mod tests{
    use super::*;
    use std::time::{SystemTime,UNIX_EPOCH};
    struct TestRoot(PathBuf);
    impl TestRoot{
        fn new()->Self{
            let t=SystemTime::now().duration_since(UNIX_EPOCH)
                .unwrap().as_nanos();
            let path=env::temp_dir().join(format!(
                "ws_bit_probe_{}_{}",std::process::id(),t
            ));
            fs::create_dir(&path).unwrap();
            Self(path)
        }
    }
    impl Drop for TestRoot{
        fn drop(&mut self){let _=fs::remove_dir_all(&self.0);}
    }
    fn sample_area()->Vec<u8>{
        // Simple native little-endian aera + CHNK, one Bit0 height cell.
        let mut record=1u32.to_le_bytes().to_vec();
        record.extend(vec![0u8;19*19*2]);
        let mut bytes=b"aera".to_vec();
        bytes.extend(0u32.to_le_bytes());
        bytes.extend(b"KNHC");
        bytes.extend(((record.len()+4) as u32).to_le_bytes());
        bytes.extend((record.len() as u32).to_le_bytes());
        bytes.extend(record);
        RawArea::from_bytes(bytes.clone()).unwrap();
        bytes
    }
    #[test]
    fn recursive_scan_and_report_are_read_only_and_deterministic(){
        let root=TestRoot::new();
        let folder=root.0.join("map");
        let report=root.0.join("report");
        fs::create_dir_all(&folder).unwrap();
        fs::create_dir_all(&report).unwrap();
        let source=sample_area();
        fs::write(folder.join("a.area"),&source).unwrap();
        fs::write(folder.join("B.AREA"),&source).unwrap();
        fs::write(folder.join("ignore.txt"),"x").unwrap();
        let files=discover(&[folder.clone()],2).unwrap();
        assert_eq!(files.len(),2);
        assert!(discover(&[folder],1).unwrap_err().contains("more than"));
        let report_data=analyze(&files);
        assert_eq!(report_data.scanned,2);
        assert_eq!(report_data.errors,0);
        assert_eq!(report_data.with_pairs,0);
        write_reports(&report,&report_data).unwrap();
        assert_eq!(fs::read(folder_join(&root.0,"map/a.area")).unwrap(),source);
        assert!(write_reports(&report,&report_data).is_err());
        assert_eq!(fs::read_dir(&report).unwrap().count(),2);
        assert!(report_data.areas.lines().count()==3);
    }
    fn folder_join(root:&Path,relative:&str)->PathBuf{root.join(relative)}
    #[test]
    fn damaged_area_is_recorded_as_error_not_silently_skipped(){
        let root=TestRoot::new();
        let bad=root.0.join("broken.area");
        fs::write(&bad,b"invalid").unwrap();
        let r=analyze(&[bad]);
        assert_eq!(r.scanned,1);
        assert_eq!(r.errors,1);
        assert!(r.areas.contains(",error,"));
        assert!(r.cells.lines().count()==1);
    }
    #[test]
    fn arguments_reject_missing_output_and_zero_limit(){
        let root=TestRoot::new();
        assert!(options(vec!["--root".into(),root.0.to_string_lossy().into()])
            .is_err());
        assert!(options(vec![
            "--root".into(),root.0.to_string_lossy().into(),
            "--out".into(),root.0.to_string_lossy().into(),
            "--max-files".into(),"0".into(),
        ]).is_err());
        assert_eq!(escape_csv("Some \"map\".area"),"\"Some \"\"map\"\".area\"");
    }
}
