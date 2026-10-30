//! Visual-only reconstruction of the classic WildStar Genesis editor in Bevy.
//! Screenshots under WILDSTAREDITOR remain the visual references. No world edits yet.
mod area;
mod terrain;
use bevy::prelude::*;
use bevy::camera::Viewport;
use std::path::Path;
use bevy_egui::{egui, EguiContexts, EguiPlugin, EguiPrimaryContextPass};

const PANEL: egui::Color32 = egui::Color32::from_rgb(228, 221, 205);
const PAPER: egui::Color32 = egui::Color32::from_rgb(243, 236, 222);
const EDGE: egui::Color32 = egui::Color32::from_rgb(147, 135, 125);
const INK: egui::Color32 = egui::Color32::from_rgb(65, 58, 54);

#[derive(Resource)]
struct GenesisState {
    scene: usize,
    active: &'static str,
    brush_size: f32, power: f32, falloff: f32,
    mode: usize,
    circle: usize,
    restricted: bool,
    custom_tip: bool,
    color_panel: bool, color_palette: bool, texture_panel: bool,
    clutter_panel: bool, prop_panel: bool, object_list: bool,
    zone_panel: bool,
    grid: bool, palette_index: usize, texture_index: usize,
    search: String,
    status: String,
    raw_view: bool,
    open_area_dialog: bool,
    area_path: String,
    pending_load: Option<String>,
    area_inspector: bool,
    selected_cell: usize,
}
impl Default for GenesisState {
    fn default() -> Self {
        Self {
            scene: 0, active: "Color Brush",
            brush_size: 0.75, power: 1.0, falloff: 0.58,
            mode: 0, circle: 0, restricted: false, custom_tip: false,
            color_panel: true, color_palette: true, texture_panel: false,
            clutter_panel: false, prop_panel: false, object_list: false,
            zone_panel: false, grid: false, palette_index: 0, texture_index: 0,
            search: String::new(),
            status: "3D AREA Preview: right drag orbit, middle drag pan, wheel zoom".to_string(),
            raw_view: true,
            open_area_dialog: false,
            area_path: String::new(),
            pending_load: None,
            area_inspector: false,
            selected_cell: 0,
        }
    }
}
#[derive(Default)]
struct Viewports { textures: Vec<egui::TextureHandle> }

#[derive(Component)]
struct GenesisCamera;

#[derive(Resource,Default)]
struct LoadedArea {
    tile: Option<area::RawArea>,
    mesh_entity: Option<Entity>,
}
#[derive(Resource)]
struct OrbitCamera {
    focus: Vec3,
    distance: f32,
    yaw: f32,
    pitch: f32,
    rect: Option<[f32;4]>,
}
impl Default for OrbitCamera {
    fn default()->Self {
        Self{focus:Vec3::ZERO,distance:730.0,yaw:0.55,pitch:0.74,rect:None}
    }
}
fn setup_scene(mut commands: Commands, mut state: ResMut<GenesisState>) {
    commands.spawn((
        GenesisCamera,
        Camera3d::default(),
        Transform::from_xyz(450.,500.,550.).looking_at(Vec3::ZERO,Vec3::Y),
    ));
    commands.spawn((
        DirectionalLight {
            illuminance: 8500.0,
            shadow_maps_enabled: false,
            ..default()
        },
        Transform::from_xyz(100.,650.,150.).looking_at(Vec3::ZERO,Vec3::Y),
    ));
    let args:Vec<String>=std::env::args().skip(1).collect();
    let sample=Path::new("../WildStarModelStudio/demo/Hills.area");
    if let Some(path)=args.first().filter(|x|x.ends_with(".area")){
        state.area_path=path.to_string();
        state.pending_load=Some(path.to_string());
    } else if sample.exists() {
        state.area_path=sample.to_string_lossy().into_owned();
        state.pending_load=Some(state.area_path.clone());
    }
}
fn load_raw_area(
    mut state: ResMut<GenesisState>,
    mut loaded: ResMut<LoadedArea>,
    mut orbit: ResMut<OrbitCamera>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
) {
    let Some(path)=state.pending_load.take() else {return;};
    match area::RawArea::from_path(Path::new(&path)) {
        Ok(tile)=>{
            match terrain::terrain_mesh(&tile) {
                Ok((mesh,focus))=>{
                    if let Some(old)=loaded.mesh_entity.take(){
                        commands.entity(old).despawn();
                    }
                    loaded.mesh_entity=Some(commands.spawn((
                        Mesh3d(meshes.add(mesh)),
                        MeshMaterial3d(materials.add(StandardMaterial {
                            base_color:Color::WHITE,
                            perceptual_roughness:1.0,
                            cull_mode:None,
                            ..default()
                        })),
                        Transform::default(),
                    )).id());
                    orbit.focus=focus;
                    orbit.distance=730.;
                    state.raw_view=true;
                    state.status=format!(
                        "AREA RAW | {} cells | {} top chunks | {} props | {}",
                        tile.cell_count(),tile.chunks.len(),tile.prop_count(),path
                    );
                    loaded.tile=Some(tile);
                }
                Err(e)=>state.status=format!("AREA mesh: {e}"),
            }
        }
        Err(e)=>state.status=format!("AREA read: {e}"),
    }
}
fn update_camera(
    orbit: Res<OrbitCamera>,
    state: Res<GenesisState>,
    windows: Query<&Window>,
    mut camera: Query<(&mut Camera,&mut Transform),With<GenesisCamera>>,
) {
    let Ok((mut view,mut transform))=camera.single_mut() else{return;};
    view.is_active=state.raw_view;
    if !view.is_active {return;}
    let p=orbit.pitch.clamp(0.05,1.52);
    let direction=Vec3::new(orbit.yaw.sin()*p.cos(),p.sin(),orbit.yaw.cos()*p.cos());
    *transform=Transform::from_translation(orbit.focus+direction*orbit.distance)
        .looking_at(orbit.focus,Vec3::Y);
    let Ok(window)=windows.single() else{return;};
    if let Some([left,top,right,bottom])=orbit.rect {
        let scale=window.resolution.scale_factor();
        let width=window.resolution.physical_width();
        let height=window.resolution.physical_height();
        let x=((left*scale).max(0.) as u32).min(width.saturating_sub(1));
        let y=((top*scale).max(0.) as u32).min(height.saturating_sub(1));
        let w=(((right-left)*scale).max(1.) as u32).min(width.saturating_sub(x));
        let h=(((bottom-top)*scale).max(1.) as u32).min(height.saturating_sub(y));
        view.viewport=Some(Viewport{physical_position:UVec2::new(x,y),
            physical_size:UVec2::new(w.max(1),h.max(1)),..default()});
    }
}

fn main() {
    App::new()
        .insert_resource(GenesisState::default())
        .insert_resource(LoadedArea::default())
        .insert_resource(OrbitCamera::default())
        .insert_resource(ClearColor(Color::srgb(0.12, 0.09, 0.16)))
        .add_plugins(DefaultPlugins.set(WindowPlugin {
            primary_window: Some(Window {
                title: "NewCentral [106] Map: NewCentral - World Editor - Genesis".into(),
                resolution: (1280, 760).into(),
                resizable: true,
                ..default()
            }),
            ..default()
        }))
        .add_plugins(EguiPlugin::default())
        .add_systems(Startup, setup_scene)
        .add_systems(Update, (load_raw_area, update_camera).chain())
        .add_systems(EguiPrimaryContextPass, editor_ui)
        .run();
}
fn classic_visuals(ctx: &egui::Context) {
    // Tahoma is loaded from the local Windows installation, not distributed.
    if let Ok(bytes) = std::fs::read(r"C:\Windows\Fonts\tahoma.ttf") {
        let mut fonts = egui::FontDefinitions::default();
        fonts.font_data.insert("GenesisTahoma".into(), egui::FontData::from_owned(bytes).into());
        fonts.families.entry(egui::FontFamily::Proportional).or_default()
            .insert(0, "GenesisTahoma".into());
        ctx.set_fonts(fonts);
    }
    ctx.set_theme(egui::Theme::Light);
    let mut style = (*ctx.style_of(egui::Theme::Light)).clone();
    style.visuals = egui::Visuals::light();
    style.visuals.window_fill = PANEL;
    style.visuals.panel_fill = PANEL;
    style.visuals.extreme_bg_color = PAPER;
    style.visuals.window_corner_radius = 0.into();
    style.visuals.menu_corner_radius = 0.into();
    style.visuals.widgets.inactive.bg_fill = PANEL;
    style.visuals.widgets.hovered.bg_fill = PAPER;
    style.visuals.widgets.active.bg_fill = egui::Color32::from_rgb(213, 205, 189);
    for widget in [&mut style.visuals.widgets.inactive, &mut style.visuals.widgets.hovered,
                   &mut style.visuals.widgets.active] {
        widget.fg_stroke.color = INK;
    }
    style.spacing.item_spacing = egui::vec2(2.0, 2.0);
    style.spacing.button_padding = egui::vec2(3.0, 1.0);
    style.text_styles.insert(egui::TextStyle::Body, egui::FontId::proportional(10.0));
    style.text_styles.insert(egui::TextStyle::Button, egui::FontId::proportional(10.0));
    style.text_styles.insert(egui::TextStyle::Small, egui::FontId::proportional(9.0));
    style.text_styles.insert(egui::TextStyle::Heading, egui::FontId::proportional(11.0));
    ctx.set_style_of(egui::Theme::Light,style);
}
fn load_scenes(ctx: &egui::Context, previews: &mut Viewports) {
    // The source image is cropped to the original level viewport at startup.
    let originals: [(&[u8], (u32,u32,u32,u32)); 3] = [
        (include_bytes!("../WILDSTAREDITOR/7.png"), (20,64,1055,606)),
        (include_bytes!("../WILDSTAREDITOR/9.png"), (36,91,954,555)),
        (include_bytes!("../WILDSTAREDITOR/10.png"), (23,65,976,494)),
    ];
    for (i, (source, (x,y,w,h))) in originals.iter().enumerate() {
        if let Ok(image) = image::load_from_memory(source) {
            let rgba = image.crop_imm(*x,*y,*w,*h).to_rgba8();
            let size = [rgba.width() as usize, rgba.height() as usize];
            previews.textures.push(ctx.load_texture(
                format!("genesis-viewport-{i}"),
                egui::ColorImage::from_rgba_unmultiplied(size, &rgba.into_raw()),
                egui::TextureOptions::LINEAR,
            ));
        }
    }
}
fn editor_ui(mut contexts: EguiContexts, mut state: ResMut<GenesisState>,
             mut previews: Local<Viewports>, mut initialized: Local<bool>,
             mut orbit: ResMut<OrbitCamera>, loaded: Res<LoadedArea>) -> Result {
    let ctx = contexts.ctx_mut()?;
    if !*initialized { classic_visuals(ctx); *initialized = true; }
    if previews.textures.is_empty() { load_scenes(ctx, &mut previews); }
    egui::Area::new(egui::Id::new("genesis-main-root"))
        .fixed_pos(egui::Pos2::ZERO)
        .order(egui::Order::Background)
        .show(ctx, |ui| {
            ui.set_min_size(ctx.content_rect().size());
            menu_and_toolbars(ui, &mut state);
            bottom_strip(ui, &mut state);
            viewport(ui, &mut state, &previews, &mut orbit, &loaded);
        });
    floating_panels(ctx, &mut state);
    area_inspector_panel(ctx, &mut state, &loaded);
    if state.open_area_dialog {
        let mut open=true;
        egui::Window::new("Open WildStar AREA")
            .collapsible(false).resizable(false)
            .default_pos(egui::pos2(220.,190.)).open(&mut open)
            .show(ctx, |ui| {
                ui.label("Original .area path (raw binary):");
                ui.add(egui::TextEdit::singleline(&mut state.area_path).desired_width(485.));
                if ui.button("Load AREA").clicked() {
                    state.pending_load=Some(state.area_path.clone());
                    state.open_area_dialog=false;
                }
                ui.label("Input remains unchanged; meshes are rebuilt in memory.");
            });
        if !open {state.open_area_dialog=false;}
    }
    Ok(())
}
fn command(state: &mut GenesisState, name: &'static str) {
    state.active = name;
    state.status = format!("{name} | UI placeholder; no editing operation");
    match name {
        "Color Brush" | "Color Brush Properties" => state.color_panel = true,
        "Color Palette" => state.color_palette = true,
        "Texture Brush" | "Texture Brush Properties" => state.texture_panel = true,
        "Clutter" | "Clutter Preset" => state.clutter_panel = true,
        "Prop Models" | "Snap Points Properties" => state.prop_panel = true,
        "Object List" => state.object_list = true,
        "AREA Inspector" => state.area_inspector = true,
        "Zones" | "Named Region Editor" => state.zone_panel = true,
        "Land Chunk Grid" => state.grid = !state.grid,
        "3D AREA View" => state.raw_view = true,
        "Open AREA..." => state.open_area_dialog = true,
        "Grimvault Preview" => { state.scene = 0; state.raw_view=false; },
        "Aurora Preview" => { state.scene = 1; state.raw_view=false; },
        "Blue Forest Preview" => { state.scene = 2; state.raw_view=false; },
        _ => {}
    }
}
fn icon(ui: &mut egui::Ui, state: &mut GenesisState, name: &'static str,
        glyph: &str, rgb: [u8;3]) {
    let (rect, response) = ui.allocate_exact_size(egui::vec2(17.0,17.0), egui::Sense::click());
    let selected = state.active == name;
    ui.painter().rect_filled(rect, 0.0, if selected {
        egui::Color32::from_rgb(212,193,155)
    } else { PAPER });
    ui.painter().rect_stroke(rect, 0.0, egui::Stroke::new(0.6, EDGE),
                             egui::StrokeKind::Inside);
    ui.painter().rect_filled(rect.shrink(3.0), 1.0,
        egui::Color32::from_rgb(rgb[0],rgb[1],rgb[2]));
    ui.painter().text(rect.center(), egui::Align2::CENTER_CENTER, glyph,
        egui::FontId::monospace(9.0), egui::Color32::WHITE);
    if response.on_hover_text(name).clicked() { command(state, name); }
}
const ICONS: &[(&str,&str,[u8;3])] = &[
    ("New","N",[100,148,168]),("Open","O",[203,148,45]),
    ("Save","S",[64,124,162]),("Save As","S",[91,133,181]),
    ("Undo","<",[119,91,162]),("Redo",">",[118,105,179]),
    ("Select","A",[145,83,98]),("Translate","+",[76,147,152]),
    ("Rotate","R",[204,133,65]),("Scale","#",[133,113,179]),
    ("Height Brush","H",[149,119,96]),("Smooth","M",[151,142,79]),
    ("Flatten","F",[94,143,168]),("Noise","N",[108,107,153]),
    ("Clone","C",[178,98,139]),("Stamp","T",[130,153,93]),
    ("Texture Brush","T",[87,159,109]),("Color Brush","P",[186,87,153]),
    ("Color Palette","P",[205,106,170]),("Clutter","V",[81,151,88]),
    ("Prop Models","P",[151,128,82]),("Prop Interiors","I",[106,122,167]),
    ("Snap Points Properties","S",[156,97,90]),("Water","W",[71,150,197]),
    ("Water Sphere","O",[71,142,190]),("Zones","Z",[164,121,173]),
    ("Land Chunk Grid","#",[171,117,70]),("Land Wireframe","L",[103,138,147]),
    ("Lights","L",[214,168,74]),("Sky","K",[97,154,190]),
    ("Fog","G",[130,145,153]),("Cloud Shadows","C",[150,143,160]),
    ("Land Occlusion Nodes","X",[144,78,130]),
    ("Land Occlusion Lines","/",[157,81,125]),
    ("Occlusion Editor","O",[96,109,139]),
    ("Object List","Q",[137,162,86]),
    ("Land Area Grid","G",[179,143,93]),
    ("Land Layer ID","I",[132,148,82]),
    ("Material Editor","M",[105,114,166]),
    ("Navigation Window","N",[97,164,145]),
    ("Sky Editor","E",[106,136,187]),
    ("Chunk Inspector","I",[190,107,113]),
    ("Particle Editor","P",[180,87,173]),
    ("FX","F",[176,75,139]),
];
fn small_commands(ui: &mut egui::Ui, state: &mut GenesisState, tag: &str,
                  labels: &[&'static str]) {
    egui::ScrollArea::horizontal().id_salt(tag)
        .scroll_bar_visibility(egui::scroll_area::ScrollBarVisibility::AlwaysHidden)
        .show(ui, |ui| {
            ui.horizontal(|ui| {
                ui.spacing_mut().item_spacing.x = 2.0;
                for &label in labels {
                    if ui.add(egui::Button::new(egui::RichText::new(label).size(8.2))
                              .frame(false)).clicked() { command(state,label); }
                }
            });
        });
}
fn menu_and_toolbars(ui_root: &mut egui::Ui, state: &mut GenesisState) {
    egui::Panel::top("genesis-menu-and-ribbon")
        .frame(egui::Frame::default().fill(PAPER)
               .inner_margin(egui::Margin::symmetric(4,2)))
        .show(ui_root, |ui| {
            ui.horizontal(|ui| {
                for (title, entries) in [
                    ("File",&["New","Open","Open AREA...","Save","Save As","Exit"][..]),
                    ("Edit",&["Undo","Redo","Cut","Copy","Paste","Delete"][..]),
                    ("View",&["3D AREA View","Land Wireframe","Land Chunk Grid","Land Edges","Slope",
                              "Grimvault Preview","Aurora Preview","Blue Forest Preview"][..]),
                    ("Tools",&["Height Brush","Texture Brush","Color Brush","Clutter","Prop Models"][..]),
                    ("Window",&["Color Brush Properties","Color Palette","Texture Brush Properties",
                                "Clutter Preset","Object List","Snap Points Properties","AREA Inspector"][..]),
                    ("Help",&["About Genesis","Keyboard Shortcuts"][..]),
                ] {
                    ui.menu_button(egui::RichText::new(title).size(10.0), |ui| {
                        for &entry in entries {
                            if ui.button(entry).clicked() { command(state,entry); ui.close(); }
                        }
                    });
                }
                ui.separator();
                ui.label(egui::RichText::new("World Editor - Genesis").size(9.0).color(EDGE));
            });
            ui.separator();
            egui::ScrollArea::horizontal().id_salt("icon-row")
                .scroll_bar_visibility(egui::scroll_area::ScrollBarVisibility::AlwaysHidden)
                .show(ui, |ui| {
                    ui.horizontal(|ui| {
                        ui.spacing_mut().item_spacing.x = 1.0;
                        for (i,&(name,glyph,color)) in ICONS.iter().enumerate() {
                            if matches!(i, 6|10|16|20|26|33) { ui.separator(); }
                            icon(ui,state,name,glyph,color);
                        }
                    });
                });
            small_commands(ui,state,"ribbon-row-1",&[
                "Double Sided","Slope","Object Wireframe","Land Wireframe",
                "Land Area Grid","Land Chunk Grid","Land Edges","Designer Color",
                "SkyWeights","Land Layer ID","In Flux","Highlight Primary","Align Selection",
                "Normal","Opaque","Navigation Window","Play Now","Sky Editor",
                "Save Package","Cell","Navigation Window",
            ]);
            small_commands(ui,state,"ribbon-row-2",&[
                "Fog","Land","Land Love","Prop Models","Prop Interiors","Hide Canopy",
                "Clutter","Water","Particles","Simple Water","Water Sphere","Water Grid",
                "Water Grid Outer Edge","Selection Mask","Chunk Inspector","Land Shadows",
                "Dynamic Shadows","Plug Mask","Things with No Bounds",
            ]);
            small_commands(ui,state,"ribbon-row-3",&[
                "Sky","FullScreen Effects","Lights","Set Diffuse to Gray",
                "Force Plastic Material","Hide Shadows","Cloud Shadows",
                "Select Sky Override","Selected Sky Gizmos","Hide Land Color",
                "Hide Land Layers","God Rays","Fade Unused Props","Object List",
                "Snap Points Properties","Zones","Named Region Editor",
            ]);
        });
}
fn bottom_strip(ui_root: &mut egui::Ui, state: &mut GenesisState) {
    egui::Panel::bottom("bottom-occlusion-strip")
        .frame(egui::Frame::default().fill(PAPER)
               .inner_margin(egui::Margin::symmetric(5,2)))
        .show(ui_root, |ui| {
            ui.horizontal(|ui| {
                for item in ["Occlusion","Land Occlusion Lines","Land Occlusion Nodes",
                             "Occlusion Editor","Land Occlusion Curtains"] {
                    if ui.add(egui::Button::new(egui::RichText::new(item).size(8.2))
                              .frame(false)).clicked() { command(state,item); }
                }
                ui.separator();
                ui.label(egui::RichText::new(&state.status).size(8.0).color(INK));
            });
        });
}
fn viewport(ui_root:&mut egui::Ui, state:&mut GenesisState,
            previews:&Viewports,orbit:&mut OrbitCamera,loaded:&LoadedArea) {
    egui::CentralPanel::default()
        .frame(egui::Frame::default().fill(if state.raw_view {
            egui::Color32::TRANSPARENT
        } else { egui::Color32::from_rgb(37,24,49) }))
        .show(ui_root, |ui| {
            let rect = ui.available_rect_before_wrap();
            if state.raw_view {
                orbit.rect=Some([rect.left(),rect.top(),rect.right(),rect.bottom()]);
                let response=ui.allocate_rect(rect,egui::Sense::click_and_drag());
                if response.dragged_by(egui::PointerButton::Secondary) {
                    let delta=ui.input(|i|i.pointer.delta());
                    orbit.yaw-=delta.x*0.006;
                    orbit.pitch=(orbit.pitch+delta.y*0.006).clamp(0.05,1.52);
                }
                if response.dragged_by(egui::PointerButton::Middle) {
                    let delta=ui.input(|i|i.pointer.delta());
                    let factor=orbit.distance*0.002;
                    let right=Vec3::new(orbit.yaw.cos(),0.,-orbit.yaw.sin());
                    orbit.focus+=right*delta.x*factor
                        +Vec3::new(0.,1.,0.)*delta.y*factor;
                }
                if response.hovered() {
                    let scroll=ui.input(|i|i.smooth_scroll_delta.y);
                    orbit.distance=(orbit.distance*(-scroll*0.0015).exp()).clamp(3.,5000.);
                    let (up,down,left,right,shift)=ui.input(|i|(
                        i.key_down(egui::Key::W),
                        i.key_down(egui::Key::S),
                        i.key_down(egui::Key::A),
                        i.key_down(egui::Key::D),
                        i.modifiers.shift,
                    ));
                    let speed=orbit.distance*if shift {0.017} else {0.004};
                    let forward=Vec3::new(-orbit.yaw.sin(),0.,-orbit.yaw.cos());
                    let side=Vec3::new(orbit.yaw.cos(),0.,-orbit.yaw.sin());
                    if up {orbit.focus+=forward*speed;}
                    if down {orbit.focus-=forward*speed;}
                    if left {orbit.focus-=side*speed;}
                    if right {orbit.focus+=side*speed;}
                }
                if loaded.tile.is_none() {
                    ui.painter().text(rect.center(),egui::Align2::CENTER_CENTER,
                        "Open AREA...  (File menu) | Raw binary 3D preview",
                        egui::FontId::proportional(15.),
                        egui::Color32::from_rgb(243,236,222));
                } else {
                    ui.painter().text(rect.min+egui::vec2(8.,8.),
                        egui::Align2::LEFT_TOP,
                        "RAW AREA  |  RMB: Orbit  MMB: Pan  Wheel: Zoom  WASD: Move",
                        egui::FontId::proportional(10.),
                        egui::Color32::from_rgb(238,233,219));
                }
            } else {
                orbit.rect=None;
                if let Some(tex)=previews.textures.get(state.scene) {
                    ui.painter().image(tex.id(),rect,
                        egui::Rect::from_min_max(egui::Pos2::ZERO,egui::pos2(1.,1.)),
                        egui::Color32::WHITE);
                }
            }
            if state.grid {
                let mut x=rect.left();
                while x<rect.right(){
                    ui.painter().line_segment(
                        [egui::pos2(x,rect.top()),egui::pos2(x,rect.bottom())],
                        egui::Stroke::new(0.6,egui::Color32::from_rgba_unmultiplied(232,194,113,70)));
                    x+=64.;
                }
                let mut y=rect.top();
                while y<rect.bottom(){
                    ui.painter().line_segment(
                        [egui::pos2(rect.left(),y),egui::pos2(rect.right(),y)],
                        egui::Stroke::new(0.6,egui::Color32::from_rgba_unmultiplied(232,194,113,70)));
                    y+=64.;
                }
            }
        });
}
fn panel_frame() -> egui::Frame {
    egui::Frame::default().fill(PANEL).stroke(egui::Stroke::new(1.0,EDGE))
        .inner_margin(egui::Margin::same(5))
}
fn row_slider(ui: &mut egui::Ui, label: &str, value: &mut f32,
              range: std::ops::RangeInclusive<f32>) {
    ui.horizontal(|ui| {
        ui.add_sized([35.0,14.0],egui::Label::new(egui::RichText::new(label).size(9.0)));
        ui.add_sized([125.0,14.0],egui::Slider::new(value,range).show_value(true));
    });
}
/// Read-only inspection of the original binary AREA data.
//// The parser keeps the raw bytes and unknown blocks for future editing support.
fn area_inspector_panel(
    ctx: &egui::Context,
    state: &mut GenesisState,
    loaded: &LoadedArea,
) {
    if !state.area_inspector {
        return;
    }
    let mut is_open = true;
    egui::Window::new("AREA Inspector")
        .id(egui::Id::new("genesis-area-inspector"))
        .default_pos(egui::pos2(24.0, 155.0))
        .default_size(egui::vec2(340.0, 410.0))
        .open(&mut is_open)
        .collapsible(true)
        .resizable(true)
        .frame(panel_frame())
        .show(ctx, |ui| {
            let Some(area) = loaded.tile.as_ref() else {
                ui.label("No .area tile loaded. Use File -> Open AREA...");
                return;
            };

            ui.label(egui::RichText::new("Original AREA binary").strong());
            egui::Grid::new("area-file-details").num_columns(2).show(ui, |ui| {
                ui.label("Version");
                ui.monospace(area.version.to_string());
                ui.end_row();
                ui.label("Variant");
                ui.monospace(if area.compressed { "AERA / zlib" } else { "area / raw" });
                ui.end_row();
                ui.label("Raw file size");
                ui.monospace(format!("{} bytes", area.original.len()));
                ui.end_row();
                ui.label("LOD prefix");
                ui.monospace(match &area.lod_prefix {
                    Some(bytes) => format!("{} bytes", bytes.len()),
                    None => "none".to_string(),
                });
                ui.end_row();
                ui.label("Terrain cells");
                ui.monospace(area.cell_count().to_string());
                ui.end_row();
            });
            ui.separator();
            ui.collapsing(format!("Top-level chunks ({})", area.chunks.len()), |ui| {
                egui::ScrollArea::vertical().max_height(135.0).show(ui, |ui| {
                    for (index, chunk) in area.chunks.iter().enumerate() {
                        let tag = String::from_utf8_lossy(&chunk.id);
                        ui.monospace(format!(
                            "{index:02} {tag:<4} @ 0x{:08X} | {} bytes",
                            chunk.file_offset,
                            chunk.data.len()
                        ));
                    }
                });
            });
            ui.separator();
            ui.horizontal(|ui| {
                ui.label("Cell index:");
                ui.add(egui::Slider::new(&mut state.selected_cell, 0..=255).show_value(true));
            });
            match area.cells[state.selected_cell].as_ref() {
                Some(cell) => {
                    egui::Grid::new("area-cell-details").num_columns(2).show(ui, |ui| {
                        ui.label("Coordinates");
                        ui.monospace(format!(
                            "x={} y={}", cell.index % 16, cell.index / 16
                        ));
                        ui.end_row();
                        ui.label("Flags");
                        ui.monospace(format!("0x{:08X}", cell.flags));
                        ui.end_row();
                        ui.label("WorldLayer IDs");
                        ui.monospace(format!("{:?}", cell.layers().unwrap_or([0; 4])));
                        ui.end_row();
                        ui.label("WorldZone IDs");
                        ui.monospace(format!("{:?}", cell.zones().unwrap_or([0; 4])));
                        ui.end_row();
                        ui.label("Center height");
                        ui.monospace(match cell.height(8, 8) {
                            Some(metres) => format!("{metres:.3} m"),
                            None => "not present".to_string(),
                        });
                        ui.end_row();
                    });
                    let set_bits: Vec<_> = (0..32)
                        .filter(|bit| cell.block(*bit).is_some())
                        .collect();
                    ui.label(format!("Present blocks: {set_bits:?}"));
                    ui.collapsing(
                        format!("Cell subchunks ({})", cell.subchunks.len()),
                        |ui| {
                            for sub in &cell.subchunks {
                                let name = String::from_utf8_lossy(&sub.id);
                                ui.monospace(format!(
                                    "{name:<4} @ cell+0x{:X} | {} bytes",
                                    sub.file_offset,
                                    sub.data.len()
                                ));
                            }
                        },
                    );
                }
                None => {
                    ui.label("Cell absent from source tile");
                }
            }
            ui.separator();
            ui.label(egui::RichText::new("Read-only: unknown data is preserved").small());
        });
    state.area_inspector = is_open;
}

fn floating_panels(ctx: &egui::Context, state: &mut GenesisState) {
    let right = ctx.content_rect().right() - 193.0;
    if state.color_panel {
        let mut open = true;
        egui::Window::new("Color Brush Properties")
            .id(egui::Id::new("genesis-color-brush"))
            .default_pos(egui::pos2(right,128.0)).default_size(egui::vec2(182.,242.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx, |ui| {
                ui.set_min_width(174.0);
                row_slider(ui,"Size",&mut state.brush_size,0.01..=2.0);
                row_slider(ui,"Power",&mut state.power,0.0..=2.0);
                row_slider(ui,"F/O",&mut state.falloff,0.0..=1.0);
                ui.horizontal(|ui| {
                    ui.radio_value(&mut state.circle,0,"Circle");
                    ui.radio_value(&mut state.circle,1,"Chunk");
                    ui.radio_value(&mut state.circle,2,"Selection");
                });
                if ui.button("Clear Selection").clicked() { command(state,"Clear Selection"); }
                ui.checkbox(&mut state.restricted,"Restrict to Selection");
                ui.horizontal(|ui| {
                    ui.radio_value(&mut state.custom_tip,false,"Normal Tip");
                    ui.radio_value(&mut state.custom_tip,true,"Custom Tip");
                });
                ui.separator();
                ui.label(egui::RichText::new("Advanced Settings").size(9.0).strong());
                ui.horizontal(|ui| {
                    let (rect,_) = ui.allocate_exact_size(egui::vec2(37.,43.),egui::Sense::hover());
                    ui.painter().rect_filled(rect,0.0,PAPER);
                    ui.painter().rect_stroke(rect,0.0,egui::Stroke::new(0.7,EDGE),
                                             egui::StrokeKind::Inside);
                    ui.vertical(|ui| {
                        for (index,label) in ["Normal","Burn Tool","Dodge Tool","Overlay",
                            "Saturate Sponge","Desaturate Sponge","Color"].iter().enumerate() {
                            ui.radio_value(&mut state.mode,index,
                                egui::RichText::new(*label).size(8.5));
                        }
                    });
                });
            });
        state.color_panel = open;
    }
    if state.color_palette {
        let mut open = true;
        egui::Window::new("Color Palette")
            .id(egui::Id::new("genesis-color-palette"))
            .default_pos(egui::pos2(right,398.0)).default_size(egui::vec2(182.,303.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx, |ui| {
                ui.set_min_width(173.);
                ui.horizontal(|ui| {
                    for tab in ["Grimvault Chrs","Grimvault _Idealized","Gr"] {
                        ui.add(egui::Button::new(egui::RichText::new(tab).size(7.4)));
                    }
                });
                ui.add(egui::TextEdit::singleline(&mut state.search)
                    .hint_text("Name").desired_width(162.));
                const SWATCHES: [([u8;3],&str);14] = [
                    ([220,130,172],"GRASS (CORRUPTED)"),
                    ([208,124,174],"Grass_LIGHT_01"),
                    ([227,169,185],"Grass_LIGHT_03"),
                    ([215,154,132],"Grass_MID_01"),
                    ([127,121,170],"Grass_MID_02"),
                    ([112,108,178],"Grass_SHADOW_01"),
                    ([93,77,165],"Grass_SHADOW_02"),
                    ([172,93,158],"GRASS (IDEALIZED TRANSITION)"),
                    ([122,99,154],"Corrupted_Ground_01"),
                    ([122,109,180],"Rock_Moss_01"),
                    ([159,125,165],"Boulder_Dark_01"),
                    ([106,102,148],"Eldan_Surface_01"),
                    ([194,108,161],"Flora_Pink_01"),
                    ([81,110,139],"Dirt_Blue_02"),
                ];
                egui::ScrollArea::vertical().max_height(272.).show(ui,|ui| {
                    for (index,(rgb,name)) in SWATCHES.iter().enumerate() {
                        if !state.search.is_empty() &&
                           !name.to_lowercase().contains(&state.search.to_lowercase()) {
                            continue;
                        }
                        ui.horizontal(|ui| {
                            let (rect,response) = ui.allocate_exact_size(
                                egui::vec2(23.,27.),egui::Sense::click());
                            ui.painter().rect_filled(rect,0.,
                                egui::Color32::from_rgb(rgb[0],rgb[1],rgb[2]));
                            if response.clicked() { state.palette_index=index; }
                            ui.vertical(|ui| {
                                if ui.selectable_label(state.palette_index==index,
                                    egui::RichText::new(*name).size(8.3)).clicked() {
                                    state.palette_index=index;
                                }
                                ui.label(egui::RichText::new(format!("Description: {name}"))
                                    .size(7.0));
                                ui.label(egui::RichText::new("Category: Favorite").size(7.0));
                            });
                        });
                        ui.separator();
                    }
                });
            });
        state.color_palette = open;
    }
    if state.texture_panel {
        let mut open = true;
        egui::Window::new("Texture Brush Properties")
            .default_pos(egui::pos2(right-195.,130.)).default_size(egui::vec2(178.,207.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx,|ui| {
                row_slider(ui,"Size",&mut state.brush_size,0.01..=2.);
                row_slider(ui,"Power",&mut state.power,0.0..=2.);
                row_slider(ui,"F/O",&mut state.falloff,0.0..=1.);
                ui.separator();
                ui.label(egui::RichText::new("Land Texture Layers").strong().size(9.));
                for (i,label) in ["Layer 0","Layer 1","Layer 2","Layer 3"].iter().enumerate() {
                    ui.radio_value(&mut state.texture_index,i,*label);
                }
                ui.checkbox(&mut state.restricted,"Restrict to Selection");
            });
        state.texture_panel=open;
    }
    if state.clutter_panel {
        let mut open = true;
        egui::Window::new("Clutter Preset")
            .default_pos(egui::pos2(right-195.,371.)).default_size(egui::vec2(178.,220.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx,|ui| {
                ui.label("Clutter Presets");
                egui::ScrollArea::vertical().max_height(190.).show(ui,|ui| {
                    for label in ["Aurora_Grass_Shrubs","Aurora_Grass_Tall","Grimvault_Grass_01",
                        "Grimvault_Grass_02","Grimvault_Crystal","Grimvault_Rocks",
                        "Grimvault_Shrubs"] {
                        if ui.button(label).clicked() { command(state,label); }
                    }
                });
            });
        state.clutter_panel=open;
    }
    if state.prop_panel {
        let mut open=true;
        egui::Window::new("Snap Points Properties")
            .default_pos(egui::pos2(24.,146.)).default_size(egui::vec2(211.,172.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx,|ui| {
                for label in ["Position   0.000  0.000  0.000","Rotation   0.000  0.000  0.000",
                    "Scale         1.000  1.000  1.000","Align Selection",
                    "Snap To Terrain","Snap Points"] {
                    if ui.button(label).clicked() { command(state,label); }
                }
            });
        state.prop_panel=open;
    }
    if state.object_list {
        let mut open=true;
        egui::Window::new("Object List")
            .default_pos(egui::pos2(22.,345.)).default_size(egui::vec2(180.,175.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx,|ui| {
                for label in ["World","Land","Props","Clutter","Zones","Water","Lights"] {
                    if ui.selectable_label(false,label).clicked() { command(state,label); }
                }
            });
        state.object_list=open;
    }
    if state.zone_panel {
        let mut open=true;
        egui::Window::new("Named Region Editor")
            .default_pos(egui::pos2(24.,530.)).default_size(egui::vec2(183.,123.))
            .collapsible(false).resizable(false).open(&mut open).frame(panel_frame())
            .show(ctx,|ui| {
                ui.label("Zone ID"); ui.label("Subzone ID");
                if ui.button("Add Region").clicked() { command(state,"Add Region"); }
            });
        state.zone_panel=open;
    }
}
