//! WildStar client data discovery and case-insensitive virtual path lookup.
//! Both ClientData and ClientDataEN are read-only. Nothing gets copied or mutated.
//! The index is independent of Bevy, so it can be tested and reused by other tools.
use std::collections::{BTreeSet,HashMap};
use std::fs;
use std::path::{Path,PathBuf};

#[derive(Debug,Clone,Copy,PartialEq,Eq)]
pub enum Source { ClientData, ClientDataEN }
impl Source {
    pub fn label(self)->&'static str {
        match self { Self::ClientData=>"ClientData", Self::ClientDataEN=>"ClientDataEN" }
    }
}
#[derive(Debug,Clone)]
pub struct AssetFile { pub path:PathBuf,pub source:Source }

#[derive(Debug,Clone)]
pub struct AssetRoots {
    pub selected:PathBuf,
    pub client_data:PathBuf,
    pub client_data_en:Option<PathBuf>,
}
fn has_name(path:&Path,name:&str)->bool{
    path.file_name().is_some_and(|n|n.to_string_lossy().eq_ignore_ascii_case(name))
}
fn child_dir(parent:&Path,name:&str)->Option<PathBuf>{
    for entry in fs::read_dir(parent).ok()?.flatten() {
        let p=entry.path();
        if p.is_dir() && has_name(&p,name){return Some(p);}
    }
    None
}
impl AssetRoots {
    /// Accept an installation root, a repository containing WoWClient/ClientData,
    /// or either ClientData directory itself. Search directory names up to 3
    /// levels down; never descend into the millions of game files here.
    pub fn discover(selected:&Path)->Result<Self,String>{
        // Preserve the normal Windows Explorer path spelling (not \\?\-extended
        // canonical paths). Make relative paths absolute for persistence.
        let selected=if selected.is_absolute(){
            selected.to_path_buf()
        }else{
            std::env::current_dir().map_err(|e|format!("Current directory: {e}"))?
                .join(selected)
        };
        if !selected.is_dir(){
            return Err(format!("Client root is not an accessible directory: {}",
                selected.display()));
        }
        let (client_data,client_data_en)=if has_name(&selected,"ClientData"){
            let parent=selected.parent().ok_or("ClientData has no parent")?;
            (selected.clone(),child_dir(parent,"ClientDataEN"))
        } else if has_name(&selected,"ClientDataEN"){
            let parent=selected.parent().ok_or("ClientDataEN has no parent")?;
            (child_dir(parent,"ClientData").ok_or("ClientData missing beside ClientDataEN")?,
                Some(selected.clone()))
        } else {
            let mut found=None;
            let mut frontier=vec![(selected.clone(),0usize)];
            while let Some((folder,depth))=frontier.pop(){
                if let Some(base)=child_dir(&folder,"ClientData"){
                    found=Some((base,child_dir(&folder,"ClientDataEN")));
                    break;
                }
                if depth>=3{continue;}
                if let Ok(entries)=fs::read_dir(&folder){
                    for entry in entries.flatten(){
                        let p=entry.path();
                        if entry.file_type().is_ok_and(|t|t.is_dir()&&!t.is_symlink()){
                            // Do not recurse into large generic directories.
                            if !has_name(&p,"ClientDataEN"){frontier.push((p,depth+1));}
                        }
                    }
                }
            }
            found.ok_or_else(||format!(
                "No ClientData folder found at or under {} (depth <= 3)",
                selected.display()))?
        };
        Ok(Self{selected,client_data,client_data_en})
    }
}
pub fn virtual_key(name:&str)->String{
    let n=name.trim().replace('\\',"/");
    let n=n.trim_matches('/');
    let n=n.strip_prefix("res://").unwrap_or(n);
    let lower=n.to_lowercase();
    let mut lower=lower.as_str();
    for prefix in ["clientdata/","clientdataen/"]{
        if lower.starts_with(prefix){lower=&lower[prefix.len()..];break;}
    }
    // Prevent traversal and never assume any source filename is trustworthy.
    let mut segments=Vec::new();
    for seg in lower.split('/') {
        if seg.is_empty()||seg=="."{continue;}
        if seg==".."{return String::new();}
        segments.push(seg);
    }
    segments.join("/")
}

#[derive(Debug, Clone, Default)]
pub struct AssetIndex {
    pub roots:Option<AssetRoots>,
    pub files:HashMap<String,AssetFile>,
    pub scanned:[usize;2],
    pub kinds:HashMap<String,usize>,
    pub warnings:Vec<String>,
    /// Basename -> candidate virtual keys; used only as an explicit fallback.
    by_name:HashMap<String,Vec<String>>,
}
impl AssetIndex {
    pub fn build(roots:AssetRoots)->Self {
        let mut result=Self{roots:Some(roots.clone()),..Default::default()};
        result.scan_dir(&roots.client_data,Source::ClientData);
        if let Some(en)=roots.client_data_en.as_ref(){
            result.scan_dir(en,Source::ClientDataEN);
        }else{
            result.warnings.push("ClientDataEN not found; base assets indexed only".into());
        }
        for (key,asset) in &result.files{
            let filename=key.rsplit('/').next().unwrap_or(key).to_string();
            result.by_name.entry(filename).or_default().push(key.clone());
            let kind=asset.path.extension().unwrap_or_default().to_string_lossy()
                .to_ascii_lowercase();
            *result.kinds.entry(kind).or_default()+=1;
        }
        result
    }
    fn scan_dir(&mut self,root:&Path,source:Source){
        let mut pending=vec![root.to_path_buf()];
        while let Some(dir)=pending.pop(){
            let entries=match fs::read_dir(&dir){
                Ok(entries)=>entries,
                Err(e)=>{
                    if self.warnings.len()<40{
                        self.warnings.push(format!("Cannot scan {}: {e}",dir.display()));
                    }
                    continue;
                }
            };
            for entry in entries.flatten(){
                let Ok(kind)=entry.file_type() else{continue;};
                if kind.is_symlink(){continue;}
                let path=entry.path();
                if kind.is_dir(){pending.push(path);continue;}
                if !kind.is_file(){continue;}
                let Some(relative)=path.strip_prefix(root).ok() else{continue;};
                let key=virtual_key(&relative.to_string_lossy());
                if key.is_empty(){continue;}
                let source_index=if source==Source::ClientData{0}else{1};
                self.scanned[source_index]+=1;
                // ClientDataEN takes priority for localized resources and
                // ClientData for all binary meshes/textures, if duplicated.
                let localization=matches!(
                    path.extension().and_then(|s|s.to_str()).unwrap_or("").to_ascii_lowercase().as_str(),
                    "tbl"|"csv"|"txt"|"xml"|"json"|"lua"|"ini"|"loc"|"po"
                );
                let replace=source==Source::ClientDataEN && localization;
                if replace||!self.files.contains_key(&key){
                    self.files.insert(key,AssetFile{path,source});
                }
            }
        }
    }
    /// Resolve by the exact path carried by a WildStar record (case-insensitive,
    /// Windows or / separators). Does NOT guess model locations.
    pub fn resolve(&self,reference:&str)->Option<&AssetFile>{
        let key=virtual_key(reference);
        if key.is_empty(){return None;}
        self.files.get(&key)
    }
    pub fn find_name(&self,name:&str)->Vec<&AssetFile>{
        let key=virtual_key(name);
        let basename=key.rsplit('/').next().unwrap_or(&key);
        self.by_name.get(basename).into_iter().flatten()
            .filter_map(|candidate|self.files.get(candidate))
            .collect()
    }
    pub fn file_count(&self)->usize{self.files.len()}
    pub fn extensions(&self,names:&[&str])->usize{
        names.iter().map(|name|self.kinds.get(*name).copied().unwrap_or(0)).sum()
    }
}
#[derive(Debug,Default)]
pub struct AreaAssetReport {
    pub models_total:usize,
    pub models_found:usize,
    pub missing_models:Vec<String>,
    pub unique_layer_ids:BTreeSet<u32>,
    pub unique_sky_ids:BTreeSet<u32>,
    pub unique_zone_ids:BTreeSet<u32>,
}
impl AssetIndex {
    /// Model paths are real file references. Numeric WorldLayer/WorldSky/
    /// WorldZone IDs require their respective database-table reader before
    /// resolving to .tex/.sky paths: do not pretend an ID is a filename.
    pub fn area_report(&self,area:&crate::area::RawArea)->AreaAssetReport{
        let mut report=AreaAssetReport::default();
        if let Ok(props)=area.prop_placements(){
            for prop in props{
                if let Some(model)=prop.model_path{
                    report.models_total+=1;
                    if self.resolve(&model).is_some(){
                        report.models_found+=1;
                    }else if report.missing_models.len()<100{
                        report.missing_models.push(model);
                    }
                }
            }
        }
        for cell in area.cells.iter().flatten(){
            if let Some(ids)=cell.layers(){
                for id in ids{if id!=0{report.unique_layer_ids.insert(id);}}
            }
            if let Some(ids)=cell.zones(){
                for id in ids{if id!=0{report.unique_zone_ids.insert(id);}}
            }
            if let Some(corners)=cell.sky_ids(){
                for group in corners{
                    for id in group{if id!=0{report.unique_sky_ids.insert(id);}}
                }
            }
        }
        report
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::{SystemTime,UNIX_EPOCH};
    fn dir()->PathBuf{
        let salt=SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_nanos();
        let folder=std::env::temp_dir().join(format!("genesis_client_root_{}_{}",std::process::id(),salt));
        fs::create_dir_all(&folder).unwrap();
        folder
    }
    #[test]
    fn finds_both_roots_and_resolves_case_insensitive_paths(){
        let temp=dir();
        let game=temp.join("WoWClient");
        let base=game.join("ClientData");
        let en=game.join("ClientDataEN");
        fs::create_dir_all(base.join("Art/Creature")).unwrap();
        fs::create_dir_all(en.join("DB")).unwrap();
        fs::write(base.join("Art/Creature/Test.m3"),b"M3").unwrap();
        fs::write(en.join("DB/WorldLayer.tbl"),b"EN").unwrap();
        let roots=AssetRoots::discover(&temp).unwrap();
        assert_eq!(roots.client_data,base);
        let index=AssetIndex::build(roots);
        assert_eq!(index.scanned,[1,1]);
        let model=index.resolve("ART\\CREATURE\\TEST.M3").unwrap();
        assert_eq!(model.source,Source::ClientData);
        assert!(index.resolve("DB/WorldLayer.tbl").is_some());
        assert_eq!(index.find_name("Test.m3").len(),1);
        assert!(index.resolve("../private/file").is_none());
        assert!(AssetRoots::discover(&en).is_ok());
        fs::remove_dir_all(temp).unwrap();
    }
    #[test]
    fn base_binary_and_localized_table_priority(){
        let temp=dir();
        let base=temp.join("ClientData");
        let en=temp.join("ClientDataEN");
        for root in [&base,&en] {
            fs::create_dir_all(root.join("Sky")).unwrap();
            fs::write(root.join("Sky/Test.sky"),b"SKY").unwrap();
            fs::write(root.join("Sky/WorldSky.tbl"),b"TBL").unwrap();
        }
        let index=AssetIndex::build(AssetRoots::discover(&temp).unwrap());
        assert_eq!(index.resolve("Sky/Test.sky").unwrap().source,Source::ClientData);
        assert_eq!(index.resolve("Sky/WorldSky.tbl").unwrap().source,Source::ClientDataEN);
        fs::remove_dir_all(temp).unwrap();
    }
}
