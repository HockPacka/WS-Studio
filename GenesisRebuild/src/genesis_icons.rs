//! Compact vector icon atlas for the original Genesis/egui chrome.
//!
//! The 2026-11-02 approval covers all nine menu groups (see
//! ICON_DESIGN_APPROVAL.md). We draw the approved metaphors as clean,
//! high-DPI vectors to avoid embedding the concept sheet's background/text.
//! No window chrome, dock positions, panel colors, or layouts are modified.
use bevy_egui::egui::{self, Color32, Painter, Pos2, Rect, Shape, Stroke, Ui};

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Icon {
    FileNew, Folder, Save, SaveAs, Power, Undo, Redo, Scissors, Copy, Paste,
    Delete, Eye, Cube, Wire, Material, Light, Camera, Fullscreen, Cursor, Move,
    Rotate, Scale, Mountain, Raise, Lower, Smooth, Noise, Stamp, Brush, Palette,
    Water, Link, Layers, Ungroup, Tiles, TileNew, Settings, Sync, World, Tree,
    Sun, Cloud, Fog, Skybox, Weather, Help, Keyboard, Ruler, Pivot, Snap,
    Grid, Book, Assets, Animation, Zone, Inspector, Window,
}

/// Return the approved, subject-specific picture and its accent palette.
/// Names must match the commands already used in main.rs. Unsupported
/// commands intentionally have no icon rather than an unrelated placeholder.
fn select(name: &str) -> Option<(Icon, Color32)> {
    use Icon::*;
    let (i, c) = match name {
        "New" | "New AREA" | "New AREA..." => (FileNew, BLUE),
        "Open AREA..." | "Open AREA by path..." | "Open Zone..." |
        "Open Zone (World Streaming)..." | "Open Model (.m3/.i3)..." => (Folder, BLUE),
        "Save" | "Save Package" => (Save, BLUE),
        "Save As" => (SaveAs, BLUE),
        "Exit" => (Power, RED),
        "Undo" => (Undo, AMBER), "Redo" => (Redo, AMBER),
        "Cut" => (Scissors, AMBER), "Copy" => (Copy, AMBER),
        "Paste" => (Paste, AMBER), "Delete" => (Delete, RED),
        "3D AREA View" | "3D View" | "Editor View" => (Eye, CYAN),
        "Land Wireframe" | "Object Wireframe" => (Wire, CYAN),
        "Hide Land Color" | "Hide Land Layers" | "Land Layer ID" => (Material, CYAN),
        "Hide Shadows" | "Dynamic Shadows" | "Lights" | "Lighting" => (Light, CYAN),
        "Grimvault Preview" | "Aurora Preview" | "Blue Forest Preview" => (Camera, CYAN),
        "FullScreen Effects" => (Fullscreen, CYAN),
        "Select" | "Selection Mask" | "Highlight Primary" => (Cursor, STEEL),
        "Translate" | "Align Selection" => (Move, PURPLE),
        "Rotate" => (Rotate, PURPLE),
        "Scale" => (Scale, PURPLE),
        "Terrain Sculpt" | "Sculpt" => (Mountain, GREEN),
        "Height Brush" => (Raise, GREEN),
        "Smooth" => (Smooth, GREEN),
        "Flatten" => (Lower, GREEN),
        "Noise" => (Noise, GREEN),
        "Clone" | "Stamp" => (Stamp, GREEN),
        "Terrain Paint" | "Paint" | "Texture Brush" | "Texture Brush Properties" => (Brush, GREEN),
        "Color Brush" | "Color Brush Properties" | "Color Palette" => (Palette, GREEN),
        "Props" | "Prop Models" | "Prop Interiors" | "Prop Viewer" => (Cube, PURPLE),
        "Object List" | "Group" => (Layers, PURPLE),
        "Ungroup" => (Ungroup, PURPLE),
        "Snap Points Properties" => (Snap, PURPLE),
        "Clutter" | "Clutter Preset" | "Hide Canopy" |
        "Fade Unused Props" => (Tree, GREEN),
        "Water" | "Simple Water" | "Water Grid" | "Water Sphere" |
        "Water Grid Outer Edge" => (Water, CYAN),
        "World" | "World Overview" | "NewCentral" => (World, GOLD),
        "AREA Inspector" | "Chunk Inspector" | "Inspect" |
        "Area 106" => (Inspector, GOLD),
        "Land Chunk Grid" | "Land Area Grid" => (Tiles, GOLD),
        "Zones" | "Named Region Editor" | "Navigation Window" |
        "Waypoints" => (Zone, GOLD),
        "Environment" | "Sky" | "Sky Editor" | "Time of Day" => (Sun, CYAN),
        "Fog" => (Fog, CYAN),
        "Cloud Shadows" => (Cloud, CYAN),
        "God Rays" => (Light, CYAN),
        "Dock Properties" | "Float Properties" | "Hide Properties" |
        "Bottom Workspace" | "Header Toolbars" => (Window, STEEL),
        "Choose Client Root..." => (Folder, STEEL),
        "ClientData Settings..." => (Settings, STEEL),
        "UI 80%" | "UI 100%" | "UI 125%" | "UI 150%" => (Settings, STEEL),
        "About Genesis" => (Help, STEEL),
        "Keyboard Shortcuts" => (Keyboard, STEEL),
        "Terrain" => (Mountain, GREEN),
        "Objects" => (Cube, PURPLE),
        "Assets" => (Assets, PURPLE),
        "Material" => (Material, PURPLE),
        "Animations" => (Animation, PURPLE),
        "Skybox" => (Skybox, CYAN),
        "Weather" => (Weather, CYAN),
        "Ruler" | "Measure" => (Ruler, AMBER),
        "Pivot" => (Pivot, CYAN),
        "Snapping" => (Snap, RED),
        "Grid" => (Grid, CYAN),
        "Documentation" => (Book, STEEL),
        "Settings" => (Settings, STEEL),
        "Link" => (Link, PURPLE),
        "New AREA..." => (TileNew, GOLD),
        "Sync AREA Borders" => (Sync, GREEN),
        _ => return None,
    };
    Some((i, c))
}

const BLUE: Color32=Color32::from_rgb(34, 118, 193);
const AMBER: Color32=Color32::from_rgb(193, 120, 22);
const CYAN: Color32=Color32::from_rgb(19, 139, 181);
const GREEN: Color32=Color32::from_rgb(48, 153, 70);
const PURPLE: Color32=Color32::from_rgb(144, 93, 188);
const GOLD: Color32=Color32::from_rgb(179, 124, 31);
const RED: Color32=Color32::from_rgb(200, 62, 49);
const STEEL: Color32=Color32::from_rgb(75, 120, 152);

struct Pen<'a> {
    painter: &'a Painter,
    rect: Rect,
    ink: Color32,
}
impl Pen<'_> {
    fn at(&self, x:f32,y:f32)->Pos2 {
        Pos2::new(self.rect.left()+x*self.rect.width()/20.0,
                  self.rect.top()+y*self.rect.height()/20.0)
    }
    fn thick(&self)->f32 {(self.rect.width()/20.0).max(0.6)*1.6}
    fn stroke(&self)->Stroke {Stroke::new(self.thick(), self.ink)}
    fn line(&self, pts:&[(f32,f32)]) {
        let p:Vec<Pos2>=pts.iter().map(|&(x,y)|self.at(x,y)).collect();
        if p.len()>1 {
            self.painter.add(Shape::line(p.clone(),Stroke::new(self.thick()+1.0,Color32::from_black_alpha(95))));
            self.painter.add(Shape::line(p,self.stroke()));
        }
    }
    fn closed(&self,pts:&[(f32,f32)]) {
        if pts.len()<3{return;}
        let v=pts.iter().map(|&(x,y)|self.at(x,y)).collect::<Vec<_>>();
        self.painter.add(Shape::convex_polygon(v, self.ink.gamma_multiply(0.17),
            Stroke::new(self.thick(), self.ink)));
    }
    fn rect(&self,x:f32,y:f32,w:f32,h:f32){
        self.closed(&[(x,y),(x+w,y),(x+w,y+h),(x,y+h)]);
    }
    fn circle(&self,x:f32,y:f32,r:f32){
        self.painter.circle(self.at(x,y),r*self.rect.width()/20.0,
            self.ink.gamma_multiply(0.12),self.stroke());
    }
    fn dot(&self,x:f32,y:f32,r:f32){
        self.painter.circle_filled(self.at(x,y),r*self.rect.width()/20.0,self.ink);
    }
}
fn paint_shape(p:&Pen<'_>,i:Icon){
    use Icon::*;
    match i {
        FileNew => {p.closed(&[(4.,2.),(12.,2.),(16.,6.),(16.,18.),(4.,18.)]);
                    p.line(&[(12.,2.),(12.,6.),(16.,6.)]);p.line(&[(10.,10.),(10.,16.)]);p.line(&[(7.,13.),(13.,13.)]);}
        Folder => {p.closed(&[(2.,6.),(8.,6.),(10.,8.),(18.,8.),(17.,16.),(2.,16.)]);p.line(&[(2.,6.),(2.,4.),(8.,4.),(10.,6.)]);}
        Save | SaveAs => {p.rect(3.,2.,14.,16.);p.rect(6.,2.,8.,5.);p.rect(6.,11.,8.,7.);
            if i==SaveAs{p.line(&[(12.,14.),(18.,8.)]);p.line(&[(16.,8.),(18.,8.),(18.,10.)]);}}
        Power => {p.line(&[(10.,2.),(10.,11.)]);p.line(&[(6.,5.),(4.,8.),(4.,13.),(7.,17.),(13.,17.),(16.,13.),(16.,8.),(14.,5.)]);}
        Undo | Redo => {let reverse=i==Redo;
            if reverse{p.line(&[(4.,9.),(12.,9.),(16.,12.),(16.,16.)]);p.line(&[(8.,5.),(4.,9.),(8.,13.)]);}
            else{p.line(&[(16.,9.),(8.,9.),(4.,12.),(4.,16.)]);p.line(&[(12.,5.),(16.,9.),(12.,13.)]);}}
        Scissors => {p.circle(5.,15.,2.);p.circle(15.,15.,2.);p.line(&[(5.,4.),(13.,13.)]);p.line(&[(15.,4.),(7.,13.)]);}
        Copy => {p.rect(6.,5.,11.,13.);p.line(&[(3.,14.),(3.,2.),(13.,2.)]);p.line(&[(9.,9.),(14.,9.)]);}
        Paste => {p.rect(4.,5.,12.,13.);p.rect(7.,2.,6.,5.);p.line(&[(7.,11.),(13.,11.)]);p.line(&[(7.,14.),(12.,14.)]);}
        Delete => {p.line(&[(4.,4.),(16.,16.)]);p.line(&[(16.,4.),(4.,16.)]);}
        Eye => {p.closed(&[(1.,10.),(6.,5.),(10.,4.),(14.,5.),(19.,10.),(14.,15.),(10.,16.),(6.,15.)]);p.circle(10.,10.,3.);p.dot(10.,10.,1.5);}
        Cube | Assets => {p.closed(&[(10.,2.),(17.,6.),(17.,14.),(10.,18.),(3.,14.),(3.,6.)]);p.line(&[(3.,6.),(10.,10.),(17.,6.)]);p.line(&[(10.,10.),(10.,18.)]);}
        Wire => {p.rect(4.,4.,12.,12.);p.line(&[(4.,4.),(9.,1.),(18.,5.),(16.,16.)]);p.line(&[(16.,4.),(18.,5.)]);p.line(&[(4.,16.),(9.,19.),(18.,16.)]);}
        Material => {p.rect(2.,2.,16.,16.);p.rect(2.,2.,8.,8.);p.rect(10.,10.,8.,8.);}
        Light => {p.circle(10.,8.,5.);p.line(&[(7.,12.),(7.,15.),(13.,15.),(13.,12.)]);p.line(&[(8.,18.),(12.,18.)]);}
        Camera => {p.rect(2.,6.,13.,10.);p.closed(&[(15.,9.),(19.,6.),(19.,16.),(15.,13.)]);p.circle(9.,11.,2.5);}
        Fullscreen => {p.line(&[(2.,8.),(2.,2.),(8.,2.)]);p.line(&[(12.,2.),(18.,2.),(18.,8.)]);p.line(&[(18.,12.),(18.,18.),(12.,18.)]);p.line(&[(8.,18.),(2.,18.),(2.,12.)]);}
        Cursor => {p.closed(&[(3.,2.),(4.,17.),(8.,13.),(11.,18.),(14.,16.),(11.,11.),(17.,9.)]);}
        Move => {p.line(&[(10.,2.),(10.,18.)]);p.line(&[(2.,10.),(18.,10.)]);p.line(&[(7.,5.),(10.,2.),(13.,5.)]);p.line(&[(7.,15.),(10.,18.),(13.,15.)]);p.line(&[(5.,7.),(2.,10.),(5.,13.)]);p.line(&[(15.,7.),(18.,10.),(15.,13.)]);}
        Rotate | Sync => {p.line(&[(17.,8.),(14.,4.),(9.,3.),(5.,5.),(3.,9.)]);p.line(&[(13.,8.),(17.,8.),(18.,4.)]);
            p.line(&[(3.,12.),(6.,16.),(11.,17.),(15.,15.),(17.,11.)]);p.line(&[(7.,12.),(3.,12.),(2.,16.)]);}
        Scale => {p.line(&[(3.,16.),(17.,2.)]);p.line(&[(10.,2.),(17.,2.),(17.,9.)]);p.line(&[(3.,10.),(3.,17.),(10.,17.)]);}
        Mountain | Raise | Lower | Smooth | Noise | Stamp => {
            p.closed(&[(1.,17.),(7.,7.),(11.,12.),(14.,5.),(19.,17.)]);
            if i==Raise{p.line(&[(12.,2.),(12.,9.)]);p.line(&[(9.,5.),(12.,2.),(15.,5.)]);}
            if i==Lower{p.line(&[(12.,2.),(12.,9.)]);p.line(&[(9.,6.),(12.,9.),(15.,6.)]);}
            if i==Smooth{p.line(&[(3.,16.),(6.,14.),(10.,14.),(14.,13.),(18.,13.)]);}
            if i==Noise{p.line(&[(3.,14.),(5.,10.),(7.,14.),(9.,8.),(12.,13.),(15.,9.),(18.,14.)]);}
            if i==Stamp{p.rect(13.,2.,5.,5.);}
        }
        Brush => {p.line(&[(6.,15.),(16.,3.)]);p.closed(&[(14.,3.),(17.,2.),(19.,5.),(16.,7.)]);p.closed(&[(3.,13.),(7.,14.),(8.,17.),(4.,19.),(2.,17.)]);}
        Palette => {p.closed(&[(10.,2.),(5.,3.),(2.,8.),(2.,13.),(7.,17.),(11.,17.),(12.,14.),(15.,13.),(18.,10.),(17.,6.),(14.,3.)]);
            for (x,y) in [(6.,7.),(11.,5.),(15.,8.),(6.,12.)]{p.dot(x,y,1.1);}}
        Water => {p.closed(&[(10.,2.),(5.,9.),(4.,13.),(6.,17.),(10.,18.),(14.,17.),(16.,13.),(15.,9.)]);p.line(&[(6.,12.),(7.,15.),(9.,16.)]);}
        Link => {p.line(&[(7.,12.),(13.,7.)]);p.circle(5.,14.,3.);p.circle(15.,6.,3.);}
        Layers | Ungroup => {p.closed(&[(10.,2.),(18.,7.),(10.,12.),(2.,7.)]);p.line(&[(2.,11.),(10.,16.),(18.,11.)]);if i==Layers{p.line(&[(2.,15.),(10.,19.),(18.,15.)]);}else{p.line(&[(10.,13.),(10.,19.)]);}}
        Tiles | TileNew | World => {for (x,y) in [(2.,2.),(11.,2.),(2.,11.),(11.,11.)]{p.rect(x,y,7.,7.);}
            if i==TileNew{p.line(&[(15.,1.),(15.,9.)]);p.line(&[(11.,5.),(19.,5.)]);}
            if i==World{p.circle(10.,10.,7.);}}
        Settings => {p.circle(10.,10.,6.);p.circle(10.,10.,2.5);for (x1,y1,x2,y2) in
            [(10.,1.,10.,4.),(10.,16.,10.,19.),(1.,10.,4.,10.),(16.,10.,19.,10.),
            (3.,3.,5.,5.),(15.,15.,17.,17.),(3.,17.,5.,15.),(15.,5.,17.,3.)]{
                p.line(&[(x1,y1),(x2,y2)]);}}
        Tree => {p.closed(&[(10.,2.),(16.,9.),(13.,9.),(18.,15.),(2.,15.),(7.,9.),(4.,9.)]);p.line(&[(10.,15.),(10.,19.)]);}
        Sun => {p.circle(10.,10.,4.5);for (a,b,c,d) in [(10.,1.,10.,4.),(10.,16.,10.,19.),
            (1.,10.,4.,10.),(16.,10.,19.,10.),(3.,3.,6.,6.),(14.,14.,17.,17.),
            (3.,17.,6.,14.),(14.,6.,17.,3.)]{p.line(&[(a,b),(c,d)]);}}
        Cloud | Weather => {p.line(&[(4.,14.),(3.,11.),(5.,8.),(8.,8.),(11.,4.),(14.,6.),(15.,9.),(18.,10.),(18.,14.),(4.,14.)]);
            if i==Weather {p.line(&[(8.,15.),(6.,18.)]);p.line(&[(14.,15.),(12.,18.)]);}}
        Fog => {p.line(&[(3.,5.),(17.,5.)]);p.line(&[(1.,9.),(15.,9.)]);p.line(&[(5.,13.),(19.,13.)]);p.line(&[(2.,17.),(13.,17.)]);}
        Skybox => {p.closed(&[(2.,16.),(6.,8.),(10.,12.),(15.,4.),(19.,16.)]);p.circle(5.,5.,2.);}
        Help => {p.circle(10.,10.,8.);p.line(&[(7.,7.),(8.,5.),(12.,5.),(14.,8.),(10.,11.),(10.,13.)]);p.dot(10.,16.,1.);}
        Keyboard => {p.rect(2.,5.,16.,11.);for (x,y) in [(5.,8.),(9.,8.),(13.,8.),(5.,11.),(9.,11.),(13.,11.)]{p.dot(x,y,0.8);}p.line(&[(7.,14.),(13.,14.)]);}
        Ruler => {p.closed(&[(2.,12.),(13.,2.),(18.,7.),(7.,18.)]);for (x,y) in [(6.,10.),(9.,7.),(12.,4.)]{p.line(&[(x,y),(x+2.,y+2.)]);}}
        Pivot => {p.circle(10.,10.,5.);p.line(&[(10.,1.),(10.,19.)]);p.line(&[(1.,10.),(19.,10.)]);p.dot(10.,10.,1.3);}
        Snap => {p.closed(&[(4.,2.),(8.,2.),(8.,11.),(12.,11.),(12.,2.),(16.,2.),(16.,12.),(12.,17.),(8.,17.),(4.,12.)]);}
        Grid => {p.rect(3.,3.,14.,14.);for n in [7.,12.]{p.line(&[(n,3.),(n,17.)]);p.line(&[(3.,n),(17.,n)]);}}
        Book => {p.line(&[(10.,5.),(10.,18.)]);p.closed(&[(2.,3.),(8.,3.),(10.,5.),(10.,18.),(7.,16.),(2.,16.)]);p.closed(&[(18.,3.),(12.,3.),(10.,5.),(10.,18.),(13.,16.),(18.,16.)]);}
        Animation => {p.rect(2.,3.,16.,14.);p.closed(&[(8.,6.),(14.,10.),(8.,14.)]);}
        Zone => {p.closed(&[(10.,2.),(16.,7.),(15.,12.),(10.,19.),(5.,12.),(4.,7.)]);p.circle(10.,8.,2.);}
        Inspector => {p.rect(3.,3.,12.,12.);p.circle(13.,13.,3.);p.line(&[(15.,15.),(19.,19.)]);}
        Window => {p.rect(2.,3.,16.,14.);p.line(&[(2.,7.),(18.,7.)]);p.line(&[(13.,7.),(13.,17.)]);}
    }
}

/// Draw a distinct vector icon at any size (16px menus, 19px toolbars).
/// The light Genesis frame stays untouched. The tiny dark silhouette helps
/// saturated WildStar accents remain legible on the original beige UI.
pub fn paint(ui:&Ui,name:&str,rect:Rect) {
    if let Some((kind, color))=select(name) {
        let pen=Pen{painter:ui.painter(),rect,ink:color};
        paint_shape(&pen,kind);
    }
}

/// Click target covers the whole row, including its icon; unlike putting
/// an icon next to ui.button this preserves mouse/keyboard menu behavior.
pub fn menu_item(ui:&mut Ui,label:&str)->egui::Response {
    let response=ui.button(format!("     {label}"));
    let icon_rect=Rect::from_min_size(
        response.rect.left_top()+egui::vec2(4.0,(response.rect.height()-16.0)*0.5),
        egui::vec2(16.0,16.0),
    );
    paint(ui,label,icon_rect);
    response
}
#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn approved_groups_have_non_placeholder_icons() {
        for name in ["New","Undo","3D AREA View","Height Brush","Props",
            "Open AREA...","Clutter","Sky","Select","AREA Inspector",
            "Color Brush","Terrain Paint","Zones","Object List","Water",
            "Keyboard Shortcuts"] {
            assert!(select(name).is_some(),"missing approved icon for {name}");
        }
    }
    #[test]
    fn real_menu_command_names_have_icons() {
        for name in ["Save As","Redo","Cut","Copy","Paste","Delete",
            "Land Wireframe","Lights","Rotate","Scale","Smooth","Noise",
            "Texture Brush","World","Color Palette","Open Model (.m3/.i3)...",
            "Prop Viewer","Fog","Cloud Shadows","Named Region Editor",
            "Dock Properties","About Genesis"] {
            assert!(select(name).is_some(), "missing icon for {name}");
        }
    }
    #[test]
    fn unsupported_command_is_not_misrepresented() {
        assert!(select("unimplemented_random_command").is_none());
    }
}
