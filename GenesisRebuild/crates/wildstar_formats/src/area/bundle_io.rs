//! Stage, verify and publish a set of AREA files as one visible bundle.
//!
//! Never modify an original AREA. Files are written with create_new into an
//! isolated sibling staging directory, synced, byte-verified, parsed again and
//! *only then* exposed under the final bundle name with one directory rename.
//! Directory rename provides atomic visibility of the completed set on the
//! same filesystem. It is NOT a guarantee of post-power-loss durability, and
//! the Linux no-clobber race needs a platform-specific renameat2 strategy.
//! On Windows (Genesis target) renaming onto an existing destination fails.
use super::RawArea;
use std::{
    collections::BTreeSet,
    fs::{self,OpenOptions},
    io::Write,
    path::{Component,Path,PathBuf},
};

fn leaf_name(value:&str,extension:Option<&str>)->Result<(),String>{
    if value.is_empty() || value=="." || value==".." ||
        value.contains('/') || value.contains('\\') || value.contains(':') ||
        value.chars().any(|c|c.is_control()) ||
        !matches!(Path::new(value).components().next(),Some(Component::Normal(_))) ||
        Path::new(value).components().count()!=1
    {
        return Err(format!("AREA bundle: unsafe path component {value:?}"));
    }
    if let Some(ext)=extension{
        if !Path::new(value).extension().and_then(|e|e.to_str())
            .is_some_and(|e|e.eq_ignore_ascii_case(ext)){
            return Err(format!("AREA bundle: only .{ext} files may be published"));
        }
    }
    // Windows reserves these names even when followed by .area.
    let stem=value.split('.').next().unwrap_or("").to_ascii_uppercase();
    if ["CON","PRN","AUX","NUL","COM1","COM2","COM3","COM4","COM5",
        "COM6","COM7","COM8","COM9","LPT1","LPT2","LPT3","LPT4",
        "LPT5","LPT6","LPT7","LPT8","LPT9"].contains(&stem.as_str()) {
        return Err("AREA bundle: reserved Windows device filename".into());
    }
    if value.ends_with(' ') || value.ends_with('.') {
        return Err("AREA bundle: trailing space/dot in filename".into());
    }
    Ok(())
}

fn create_unique_stage(parent:&Path,final_name:&str)->Result<PathBuf,String>{
    // The staging sibling must share the target filesystem for rename().
    // Only directories newly created by this function may be cleaned up.
    for index in 0..256u32 {
        let path=parent.join(format!(".{final_name}.stage.{}.{}",
            std::process::id(),index));
        match fs::create_dir(&path){
            Ok(())=>return Ok(path),
            Err(e) if e.kind()==std::io::ErrorKind::AlreadyExists=>continue,
            Err(e)=>return Err(format!(
                "AREA bundle: could not create staging directory {}: {e}",
                path.display())),
        }
    }
    Err("AREA bundle: no unique staging directory available".into())
}

fn publish_inner(
    parent:&Path,folder_name:&str,files:&[(String,Vec<u8>)],
    mut after_stage_file:impl FnMut(usize)->Result<(),String>,
)->Result<Vec<PathBuf>,String>{
    leaf_name(folder_name,None)?;
    if files.is_empty() {
        return Err("AREA bundle: no files to publish".into());
    }
    let mut unique=BTreeSet::new();
    for (name,bytes) in files{
        leaf_name(name,Some("area"))?;
        if !unique.insert(name.to_lowercase()){
            return Err(format!("AREA bundle: duplicate AREA filename {name}"));
        }
        RawArea::from_bytes(bytes.clone())
            .map_err(|e|format!("AREA bundle: invalid AREA {name}: {e}"))?;
    }
    if !parent.is_dir(){
        return Err(format!("AREA bundle: target parent {} is not a folder",
            parent.display()));
    }
    let final_path=parent.join(folder_name);
    if final_path.exists(){
        return Err(format!("AREA bundle: {} exists; refusing replacement",
            final_path.display()));
    }
    let stage=create_unique_stage(parent,folder_name)?;
    let result=(||->Result<(),String>{
        for (index,(name,bytes)) in files.iter().enumerate(){
            let path=stage.join(name);
            let mut output=OpenOptions::new().create_new(true).write(true)
                .open(&path).map_err(|e|format!(
                    "AREA bundle: cannot stage {}: {e}",path.display()))?;
            output.write_all(bytes).and_then(|()|output.sync_all())
                .map_err(|e|format!(
                    "AREA bundle: cannot flush staged AREA {}: {e}",path.display()))?;
            drop(output);
            let reread=fs::read(&path).map_err(|e|format!(
                "AREA bundle: cannot verify staged AREA {}: {e}",path.display()))?;
            if reread!=*bytes{
                return Err(format!(
                    "AREA bundle: staged AREA {name} differs from validated bytes"));
            }
            RawArea::from_bytes(reread).map_err(|e|format!(
                "AREA bundle: staged AREA {name} is invalid: {e}"))?;
            after_stage_file(index)?;
        }
        // There is no destination file before this rename. A completed bundle
        // therefore appears in the file browser as a whole or not at all
        // for ordinary process failures. Avoid overwriting an existing folder.
        if final_path.exists(){
            return Err(format!(
                "AREA bundle: {} was created concurrently; refusing replacement",
                final_path.display()));
        }
        fs::rename(&stage,&final_path).map_err(|e|format!(
            "AREA bundle: cannot publish validated staging directory: {e}"))?;
        Ok(())
    })();
    if let Err(error)=result{
        // Only remove our own freshly created staging folder, never a user's
        // preexisting bundle. A process crash may leave a hidden .stage folder.
        let _=fs::remove_dir_all(&stage);
        return Err(error);
    }
    Ok(files.iter().map(|(name,_)|final_path.join(name)).collect())
}

/// Publish validated in-memory native AREAs without exposing a partial bundle.
/// For crash-proof durability across power loss, file and directory fsync
/// rules differ by OS and are not covered by this API.
pub fn publish_area_bundle(
    parent:&Path,folder_name:&str,files:&[(String,Vec<u8>)],
)->Result<Vec<PathBuf>,String>{
    publish_inner(parent,folder_name,files,|_|Ok(()))
}

#[cfg(test)]
mod tests{
    use super::*;
    use std::time::{SystemTime,UNIX_EPOCH};
    struct Temp(PathBuf);
    impl Temp{
        fn new()->Self{
            let ticks=SystemTime::now().duration_since(UNIX_EPOCH)
                .unwrap().as_nanos();
            let dir=std::env::temp_dir().join(format!(
                "genesis_bundle_test_{}_{}",std::process::id(),ticks));
            fs::create_dir(&dir).unwrap();
            Self(dir)
        }
    }
    impl Drop for Temp{
        fn drop(&mut self){let _=fs::remove_dir_all(&self.0);}
    }
    fn sample_area()->Vec<u8>{
        let mut cell=1u32.to_le_bytes().to_vec();
        for _ in 0..(19*19){cell.extend(16400u16.to_le_bytes());}
        let mut area=b"aera".to_vec();
        area.extend(0u32.to_le_bytes());
        area.extend(b"KNHC");
        area.extend(((cell.len()+4) as u32).to_le_bytes());
        area.extend((cell.len() as u32).to_le_bytes());
        area.extend(cell);
        RawArea::from_bytes(area.clone()).unwrap();
        area
    }
    #[test]
    fn staged_publish_exposes_complete_verified_bundle_without_source_changes(){
        let root=Temp::new();
        let original=root.0.join("Demo.4040.area");
        let source=sample_area();
        fs::write(&original,&source).unwrap();
        let records=[
            ("Demo.4040.area".to_string(),source.clone()),
            ("Demo.403f.area".to_string(),source.clone()),
        ];
        let paths=publish_area_bundle(&root.0,"DemoBundle",&records).unwrap();
        assert_eq!(paths.len(),2);
        assert_eq!(fs::read(&paths[0]).unwrap(),source);
        assert_eq!(fs::read(&paths[1]).unwrap(),source);
        assert_eq!(fs::read(original).unwrap(),source);
        let mut directory=fs::read_dir(&root.0).unwrap();
        let mut entries=Vec::new();
        while let Some(Ok(entry))=directory.next(){entries.push(entry.file_name());}
        assert_eq!(entries.len(),2,"no hidden staging folder after publish");
        assert!(publish_area_bundle(&root.0,"DemoBundle",&records)
            .unwrap_err().contains("exists"));
        assert_eq!(fs::read(&paths[0]).unwrap(),source);
    }
    #[test]
    fn staged_failure_cleans_only_owned_files_and_keeps_bundle_invisible(){
        let root=Temp::new();
        let source=sample_area();
        let records=[
            ("Demo.4040.area".to_string(),source.clone()),
            ("Demo.403f.area".to_string(),source),
        ];
        let error=publish_inner(&root.0,"Interrupted",&records,|n|{
            if n==0{Err("injected stage write error".into())}
            else{Ok(())}
        }).unwrap_err();
        assert!(error.contains("injected"));
        assert!(!root.0.join("Interrupted").exists());
        assert_eq!(fs::read_dir(&root.0).unwrap().count(),0);
    }
    #[test]
    fn reject_unsafe_names_duplicate_and_invalid_data_without_side_effects(){
        let root=Temp::new();
        let valid=sample_area();
        for name in ["../escape.area","dir/escape.area","C:\\bad.area",
            "NUL.area","bad.txt","..\\oops.area"]{
            assert!(publish_area_bundle(&root.0,"Clean",
                &[(name.to_string(),valid.clone())]).is_err(),"{name}");
        }
        assert!(publish_area_bundle(&root.0,"../Escaped",
            &[("Demo.4040.area".into(),valid.clone())]).is_err());
        assert!(publish_area_bundle(&root.0,"Clean",&[
            ("DEMO.4040.AREA".into(),valid.clone()),
            ("demo.4040.area".into(),valid.clone()),
        ]).is_err());
        assert!(publish_area_bundle(&root.0,"Clean",&[
            ("Demo.4040.area".into(),vec![1,2,3])
        ]).is_err());
        assert_eq!(fs::read_dir(&root.0).unwrap().count(),0);
    }
}
