//! Native Windows folder/file picker and background client-asset indexing.
//! The game install is read-only. The selected root is persisted per user.
use bevy::prelude::*;
use bevy_egui::egui;
use rfd::FileDialog;
use std::path::{Path,PathBuf};
use std::sync::mpsc::{self,Receiver,TryRecvError};
use std::sync::Mutex;
use wildstar_formats::assets::{AssetIndex,AssetRoots};

#[derive(Resource)]
pub struct ClientFiles {
    pub root_text:String,
    pub settings_open:bool,
    pub scanning:bool,
    pub status:String,
    pub index:Option<AssetIndex>,
    receiver:Mutex<Option<Receiver<AssetIndex>>>,
    /// Decoded .m3/.i3 prop meshes; dropped together with the index on re-scan.
    pub prop_models:crate::props::PropModelCache,
}
impl Default for ClientFiles {
    fn default()->Self{
        Self{
            root_text:String::new(),
            settings_open:false,
            scanning:false,
            status:"ClientData not configured (optional). Open Settings > ClientData Settings... to configure.".into(),
            index:None,
            receiver:Mutex::new(None),
            prop_models:Default::default(),
        }
    }
}
fn settings_file()->Option<PathBuf>{
    // Per-user Windows settings; never write into the WildStar client tree.
    std::env::var_os("LOCALAPPDATA")
        .or_else(||std::env::var_os("XDG_CONFIG_HOME"))
        .map(|p|PathBuf::from(p).join("GenesisRebuild").join("client_root.txt"))
}
fn save_root(path:&Path){
    if let Some(file)=settings_file(){
        if let Some(parent)=file.parent(){
            if std::fs::create_dir_all(parent).is_ok(){
                let _=std::fs::write(file,path.to_string_lossy().as_bytes());
            }
        }
    }
}
impl ClientFiles {
    pub fn initialize(&mut self,cli_root:Option<String>){
        let previous=settings_file()
            .and_then(|p|std::fs::read_to_string(p).ok())
            .map(|s|s.trim().to_string())
            .filter(|s|!s.is_empty());
        if let Some(folder)=cli_root.or(previous){
            self.root_text=folder;
            self.begin_scan();
        }
    }
    pub fn begin_scan(&mut self){
        if self.scanning{return;}
        let roots=match AssetRoots::discover(Path::new(self.root_text.trim())){
            Ok(roots)=>roots,
            Err(error)=>{
                // Keep the last successfully indexed root if the new text is invalid.
                // Invalid input must not block the editor or destroy a usable index.
                self.status=format!("Invalid WildStar root: {error}");
                return;
            }
        };
        self.root_text=roots.selected.to_string_lossy().into_owned();
        self.status=format!("Indexing ClientData and ClientDataEN in {} …",
            roots.selected.display());
        self.scanning=true;
        self.index=None;
        let (tx,rx)=mpsc::channel();
        *self.receiver.lock().expect("asset receiver lock")=Some(rx);
        std::thread::spawn(move||{
            let result=AssetIndex::build(roots);
            let _=tx.send(result);
        });
    }
    pub fn poll(&mut self){
        if !self.scanning{return;}
        let message={
            let guard=self.receiver.lock().expect("asset receiver lock");
            guard.as_ref().map(|rx|rx.try_recv())
        };
        match message{
            Some(Ok(index))=>{
                self.scanning=false;
                self.status=format!(
                    "Asset index ready: {} unique files, ClientData: {}, ClientDataEN: {}",
                    index.file_count(),index.scanned[0],index.scanned[1]);
                if let Some(roots)=index.roots.as_ref(){save_root(&roots.selected);}
                self.index=Some(index);
                *self.receiver.lock().expect("asset receiver lock")=None;
            }
            Some(Err(TryRecvError::Disconnected))=>{
                self.scanning=false;
                self.status="Asset indexing stopped unexpectedly. Choose the root again.".into();
                *self.receiver.lock().expect("asset receiver lock")=None;
            }
            _=>{}
        }
    }
    pub fn ready(&self)->bool{self.index.is_some() && !self.scanning}
    /// Disconnect the optional asset root; never touch the game installation.
    pub fn clear_root(&mut self){
        if self.scanning{return;}
        self.root_text.clear();
        self.index=None;
        self.prop_models=Default::default();
        self.status="ClientData disconnected. Standalone AREA editing remains available.".into();
        if let Some(path)=settings_file(){let _=std::fs::remove_file(path);}
    }
    pub fn choose_root(&mut self){
        let mut picker=FileDialog::new()
            .set_title("WildStar Client-Root auswählen (ClientData / ClientDataEN)");
        if Path::new(&self.root_text).is_dir(){
            picker=picker.set_directory(&self.root_text);
        }
        if let Some(folder)=picker.pick_folder(){
            self.root_text=folder.to_string_lossy().into_owned();
            self.begin_scan();
        }
    }
    pub fn choose_area(&self,current_path:&str)->Option<PathBuf>{
        let mut picker=FileDialog::new()
            .set_title("WildStar .area-Datei öffnen")
            .add_filter("WildStar AREA", &["area"]);
        let selected_area=Path::new(current_path);
        let existing_parent=selected_area.parent().filter(|p|p.is_dir());
        if let Some(folder)=existing_parent {
            picker=picker.set_directory(folder);
        }else if let Some(root)=self.index.as_ref().and_then(|i|i.roots.as_ref()){
            let map_dir=root.client_data.join("Map");
            picker=picker.set_directory(if map_dir.is_dir(){&map_dir}else{&root.client_data});
        }
        picker.pick_file()
    }
    pub fn client_data_dir(&self) -> Option<PathBuf> {
        self.index.as_ref().and_then(|i| i.roots.as_ref()).map(|r| r.client_data.clone())
    }
}
pub fn poll_system(mut assets:ResMut<ClientFiles>){assets.poll();}


pub fn settings_panel(ctx:&egui::Context,assets:&mut ClientFiles){
    if !assets.settings_open{return;}
    let mut open=assets.settings_open;
    egui::Window::new("Genesis – Editor Settings")
        .id(egui::Id::new("genesis-editor-settings"))
        .open(&mut open)
        .resizable(true)
        .default_size(egui::vec2(560.,225.))
        .default_pos(ctx.content_rect().center()-egui::vec2(280.,110.))
        .show(ctx,|ui|{
            ui.heading("WildStar ClientData");
            ui.label("Optional: Genesis can start and edit standalone AREA terrain without a ClientData root.");
            ui.label("For textured terrain, M3/I3 assets, TBL references and world streaming, select the game data folder.");
            ui.horizontal(|ui|{
                ui.add_enabled_ui(!assets.scanning,|ui|{
                    ui.add(egui::TextEdit::singleline(&mut assets.root_text)
                        .desired_width((ui.available_width()-110.).max(120.))
                        .hint_text("WildStar root or ClientData directory"));
                    if ui.button("Browse...").clicked(){assets.choose_root();}
                });
            });
            ui.horizontal(|ui|{
                if ui.add_enabled(!assets.scanning,
                    egui::Button::new("Validate and index")).clicked(){
                    assets.begin_scan();
                }
                if ui.add_enabled(!assets.scanning && (assets.ready() || !assets.root_text.is_empty()),
                    egui::Button::new("Disconnect")).clicked(){
                    assets.clear_root();
                }
                if assets.scanning{ui.spinner();}
            });
            ui.separator();
            ui.label(&assets.status);
            ui.label(egui::RichText::new(
                "Read-only ClientData access. The selected path is saved per user in LOCALAPPDATA/GenesisRebuild; no paths are stored inside the game client."
            ).small());
        });
    assets.settings_open=open;
}

#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn unconfigured_client_root_does_not_force_setup_dialog(){
        let client=ClientFiles::default();
        assert!(!client.settings_open);
        assert!(!client.scanning);
        assert!(!client.ready());
        assert!(client.root_text.is_empty());
    }
}
pub fn asset_summary(ui:&mut egui::Ui,assets:&ClientFiles,
                     area:Option<&wildstar_formats::area::RawArea>){
    ui.label(egui::RichText::new("ClientData Asset Index").strong());
    ui.label(&assets.status);
    let Some(index)=assets.index.as_ref() else{return;};
    if let Some(roots)=index.roots.as_ref(){
        ui.monospace(format!("Base: {}",roots.client_data.display()));
        ui.monospace(format!("EN: {}",roots.client_data_en.as_ref()
            .map(|p|p.display().to_string()).unwrap_or_else(||"missing".into())));
    }
    ui.monospace(format!("Files: {}, .area: {}, .tex: {}, .m3: {}, .i3: {}, .sky: {}, .tbl: {}",
        index.file_count(),index.extensions(&["area"]),index.extensions(&["tex"]),
        index.extensions(&["m3"]),index.extensions(&["i3"]),
        index.extensions(&["sky"]),index.extensions(&["tbl"])));
    if !index.warnings.is_empty(){
        ui.collapsing("Scan warnings",|ui|{
            for warning in index.warnings.iter().take(15){ui.label(warning);}
        });
    }
    if let Some(tile)=area{
        let report=index.area_report(tile);
        ui.separator();
        ui.label("Referenced by selected AREA");
        ui.monospace(format!(
            "Props with asset paths: {} / {} found",
            report.models_found,report.models_total
        ));
        ui.monospace(format!(
            "WorldLayer IDs: {}, WorldSky IDs: {}, WorldZone IDs: {}",
            report.unique_layer_ids.len(),
            report.unique_sky_ids.len(),
            report.unique_zone_ids.len()
        ));
        // Tables are looked up by filename; an index entry is not yet a decoder
        // for the game's binary TBL schema.
        for table in ["WorldLayer.tbl","WorldSky.tbl","WorldZone.tbl"]{
            let candidates=index.find_name(table);
            if let Some(file)=candidates.first(){
                ui.label(format!("{table}: {} [{}]",
                    file.path.display(),file.source.label()));
            }else{
                ui.label(format!("{table}: not found"));
            }
        }
        ui.label(egui::RichText::new(
            "IDs need a TBL database decoder before material/sky paths can be resolved.")
            .small());
        if !report.missing_models.is_empty(){
            ui.collapsing(format!("Unresolved prop paths ({})",
                report.missing_models.len()),|ui|{
                for path in &report.missing_models{ui.monospace(path);}
            });
        }
    }
}
