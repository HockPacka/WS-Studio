//! File > New: create an editable native AREA in the separate ClientFiles workspace.
//! This is a Genesis-compatible test tile, not a registered retail map.
use bevy_egui::egui;
use std::{fs::{self,OpenOptions},io::Write,path::{Path,PathBuf}};
use wildstar_formats::area::{RawArea,builder::AreaBuilder};
use wildstar_formats::zone::ZoneTileCoords;

#[derive(Debug,Clone)]
pub struct Options {
    pub map_name:String,
    pub tile_x:u8,
    pub tile_z:u8,
    pub start_height:f32,
    pub world_layer_id:u32,
    pub map_folder:String,
    pub error:String,
}
impl Default for Options {
    fn default()->Self {
        let cwd=std::env::current_dir().unwrap_or_else(|_|PathBuf::from("."));
        let project=if cwd.file_name().and_then(|x|x.to_str())
            .is_some_and(|x|x.eq_ignore_ascii_case("GenesisRebuild")){
            cwd.parent().unwrap_or(&cwd).to_path_buf()
        }else{cwd};
        Self{
            map_name:"GenesisTest".into(),
            tile_x:0x40,tile_z:0x40,start_height:0.0,world_layer_id:0,
            map_folder:project.join("ClientFiles").join("Map").to_string_lossy().into_owned(),
            error:String::new(),
        }
    }
}
impl Options {
    pub fn validate(&self)->Result<(),String>{
        if self.map_name.is_empty() || self.map_name.len()>64 ||
           !self.map_name.bytes().all(|c|c.is_ascii_alphanumeric() || c==b'_' || c==b'-'){
            return Err("Map name: 1-64 letters, digits, underscore or hyphen (no paths).".into());
        }
        if !self.start_height.is_finite() ||
           !(-2048.0..=6143.875).contains(&self.start_height){
            return Err("Start height must be -2048..6143.875 metres.".into());
        }
        if self.map_folder.trim().is_empty(){return Err("Choose an output Map folder.".into());}
        Ok(())
    }
    pub fn destination(&self)->Result<PathBuf,String>{
        self.validate()?;
        let coords=ZoneTileCoords::new(self.tile_z,self.tile_x);
        let name=format!("{}.{}.area",self.map_name,coords.to_hex());
        Ok(Path::new(self.map_folder.trim()).join(&self.map_name).join(name))
    }
    /// Create new only; existing game data and already-authored maps are never replaced.
    pub fn create(&self)->Result<PathBuf,String>{
        let path=self.destination()?;
        if path.exists(){return Err(format!("AREA already exists: {}",path.display()));}
        let bytes=AreaBuilder::flat(self.start_height,self.world_layer_id).build()?;
        let decoded=RawArea::from_bytes(bytes.clone())?;
        if decoded.cell_count()!=256{return Err("AREA must contain 256 height cells.".into());}
        let parent=path.parent().ok_or("Missing map folder")?;
        fs::create_dir_all(parent)
            .map_err(|e|format!("Cannot create {}: {e}",parent.display()))?;
        let mut file=OpenOptions::new().write(true).create_new(true).open(&path)
            .map_err(|e|format!("Cannot create {}: {e}",path.display()))?;
        if let Err(err)=file.write_all(&bytes).and_then(|_|file.sync_all()){
            drop(file); let _=fs::remove_file(&path);
            return Err(format!("Cannot write AREA: {err}"));
        }
        drop(file);
        match RawArea::from_path(&path){
            Ok(reloaded) if reloaded.cell_count()==256=>Ok(path),
            _=>{
                let _=fs::remove_file(&path);
                Err("New AREA did not pass disk round-trip validation.".into())
            }
        }
    }
}

pub fn show(ctx:&egui::Context,open:&mut bool,options:&mut Options)->Option<PathBuf>{
    if !*open{return None;}
    let mut visible=*open;
    let mut submit=false;
    egui::Window::new("New AREA")
        .id(egui::Id::new("genesis-new-area"))
        .collapsible(false).resizable(true)
        .default_size(egui::vec2(460.0,280.0))
        .open(&mut visible)
        .show(ctx,|ui|{
            ui.heading("Create editable terrain AREA");
            ui.label("512 x 512 metres; 16 x 16 native cells; 257 x 257 heights.");
            egui::Grid::new("genesis-new-area-fields").num_columns(2)
                .spacing(egui::vec2(10.0,5.0)).show(ui,|ui|{
                    ui.label("Map name");ui.text_edit_singleline(&mut options.map_name);ui.end_row();
                    ui.label("Tile X / Z");
                    ui.horizontal(|ui|{
                        ui.add(egui::DragValue::new(&mut options.tile_x).range(0..=255));
                        ui.add(egui::DragValue::new(&mut options.tile_z).range(0..=255));
                    });ui.end_row();
                    ui.label("Start height (m)");
                    ui.add(egui::DragValue::new(&mut options.start_height)
                        .speed(0.125).range(-2048.0..=6143.875));ui.end_row();
                    ui.label("WorldLayer ID");
                    ui.add(egui::DragValue::new(&mut options.world_layer_id).range(0..=u32::MAX));
                    ui.end_row();
                });
            ui.separator();
            ui.label("Output folder (ClientFiles / Map)");
            ui.horizontal(|ui|{
                ui.add(egui::TextEdit::singleline(&mut options.map_folder)
                    .desired_width((ui.available_width()-90.0).max(130.0)));
                if ui.button("Browse...").clicked(){
                    let mut picker=rfd::FileDialog::new()
                        .set_title("Choose ClientFiles/Map folder");
                    if Path::new(options.map_folder.trim()).is_dir(){
                        picker=picker.set_directory(options.map_folder.trim());
                    }
                    if let Some(dir)=picker.pick_folder(){
                        options.map_folder=dir.to_string_lossy().into_owned();
                    }
                }
            });
            match options.destination(){
                Ok(path)=>{ui.label(egui::RichText::new(format!("New: {}",path.display())).small());},
                Err(err)=>{ui.colored_label(egui::Color32::DARK_RED,err);},
            }
            if !options.error.is_empty(){
                ui.colored_label(egui::Color32::DARK_RED,&options.error);
            }
            ui.label(egui::RichText::new(
                "No TBL entries are created. WorldLayer ID 0 works as a terrain-only preview."
            ).small());
            ui.horizontal(|ui|{
                if ui.button("Create AREA").clicked(){submit=true;}
                if ui.button("Cancel").clicked(){visible=false;}
            });
        });
    *open=visible;
    if submit {
        match options.create(){
            Ok(path)=>{*open=false;options.error.clear();return Some(path);}
            Err(error)=>options.error=error,
        }
    }
    None
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn native_tile_coordinates_are_encoded_as_z_then_x(){
        let mut opts=Options::default();
        assert!(opts.destination().unwrap().ends_with("GenesisTest.4040.area"));
        opts.tile_z=0x37;opts.tile_x=0x47;
        assert!(opts.destination().unwrap().ends_with("GenesisTest.3747.area"));
    }
    #[test]
    fn invalid_names_and_heights_do_not_create_files(){
        let mut opts=Options::default();
        for value in ["../bad","bad/name","bad\\name","","two words"]{
            opts.map_name=value.into();
            assert!(opts.destination().is_err());
        }
        opts.map_name="SafeName".into();
        opts.start_height=f32::NAN;
        assert!(opts.destination().is_err());
    }
    #[test]
    fn file_is_created_and_existing_file_is_never_overwritten(){
        let stamp=std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH).unwrap().as_nanos();
        let temp=std::env::temp_dir().join(format!("genesis-area-{}-{stamp}",std::process::id()));
        let mut opts=Options::default();
        opts.map_folder=temp.to_string_lossy().into_owned();
        opts.map_name="SafeName".into();
        let path=opts.create().unwrap();
        assert_eq!(RawArea::from_path(&path).unwrap().cell_count(),256);
        let original=fs::read(&path).unwrap();
        assert!(opts.create().is_err());
        assert_eq!(fs::read(&path).unwrap(),original);
        let _=fs::remove_dir_all(temp);
    }
}
