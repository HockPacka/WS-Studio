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
    dock_visible: bool,
    floating_mode: bool,
    bottom_visible: bool,
    toolbars_visible: bool,
    ui_zoom: f32,
    dock_tab: usize,
    bottom_tab: usize,
    ribbon_tab: usize,
    time_of_day: f32,
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
            dock_visible: true,
            floating_mode: false,
            bottom_visible: true,
            toolbars_visible: true,
            ui_zoom: 1.0,
            dock_tab: 0,
            bottom_tab: 0,
            ribbon_tab: 0,
            time_of_day: 12.0,
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
    ui_pixels_per_point: f32,
}
impl Default for OrbitCamera {
    fn default()->Self {
        Self{focus:Vec3::ZERO,distance:730.0,yaw:0.55,pitch:0.74,rect:None,ui_pixels_per_point:1.0}
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
        // Egui coordinates are logical points: include its user-selected zoom factor.
        let scale=orbit.ui_pixels_per_point;
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
    // Reserve the dynamically measured window area before arranging nested panels.
    if (ctx.zoom_factor() - state.ui_zoom).abs() > 0.001 {
        ctx.set_zoom_factor(state.ui_zoom);
    }
    orbit.ui_pixels_per_point = ctx.pixels_per_point();
    // egui 0.36 panels operate within Ui. The outer area is remeasured
    // each frame from the current logical window rect; the inner panels
    // consume top/right/bottom space before the terrain viewport.
    egui::Area::new(egui::Id::new("genesis-main-root"))
        .fixed_pos(ctx.content_rect().min)
        .order(egui::Order::Background)
        .show(ctx, |root| {
            // Clamp the root to the CURRENT frame, including when shrinking a window.
            root.set_width(ctx.content_rect().width());
            root.set_height(ctx.content_rect().height());
            egui::CentralPanel::no_frame().show(root, |ui| {
                menu_and_toolbars(ui, &mut state);
                bottom_strip(ui, &mut state, &loaded, &orbit);
                if state.dock_visible && !state.floating_mode {
                    dock_panels(ui, &mut state, &loaded);
                }
                viewport(ui, &mut state, &previews, &mut orbit, &loaded);
            });
        });
    if state.floating_mode { floating_panels(ctx, &mut state); }
    area_inspector_panel(ctx, &mut state, &loaded);
    if state.open_area_dialog {
        let mut open=true;
        egui::Window::new("Open WildStar AREA")
            .collapsible(false).resizable(false)
            .default_pos(egui::pos2(220.,190.)).open(&mut open)
            .show(ctx, |ui| {
                ui.label("Original .area path (raw binary):");
                ui.add(egui::TextEdit::singleline(&mut state.area_path).desired_width((ctx.content_rect().width()-60.0).clamp(150.0, 485.0)));
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
        "Color Brush" | "Color Brush Properties" => { state.color_panel = true; state.dock_tab = 0; },
        "Color Palette" => { state.color_palette = true; state.dock_tab = 1; },
        "Texture Brush" | "Texture Brush Properties" => { state.texture_panel = true; state.dock_tab = 2; },
        "Clutter" | "Clutter Preset" => { state.clutter_panel = true; state.dock_tab = 3; },
        "Prop Models" | "Snap Points Properties" => { state.prop_panel = true; state.dock_tab = 4; },
        "Object List" => { state.object_list = true; state.dock_tab = 4; },
        "AREA Inspector" => { state.area_inspector = true; state.dock_tab = 6; },
        "Dock Properties" => { state.dock_visible = true; state.floating_mode = false; },
        "Float Properties" => { state.floating_mode = true; state.dock_visible = false; },
        "Hide Properties" => { state.dock_visible = false; state.floating_mode = false; },
        "Bottom Workspace" => state.bottom_visible = !state.bottom_visible,
        "Header Toolbars" => state.toolbars_visible = !state.toolbars_visible,
        "UI 80%" => state.ui_zoom = 0.8,
        "UI 100%" => state.ui_zoom = 1.0,
        "UI 125%" => state.ui_zoom = 1.25,
        "UI 150%" => state.ui_zoom = 1.5,
        "Zones" | "Named Region Editor" => { state.zone_panel = true; state.dock_tab = 5; },
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
    ("3D AREA View","3D",[59,121,166]),("AREA Inspector","I",[171,130,75]),
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
// Classic Genesis chrome: menu header, multiple toolbars and bottom workspace.
// All layout regions are nested in the top-level CentralPanel and therefore resize.
fn menu_and_toolbars(ui_root:&mut egui::Ui, state:&mut GenesisState) {
    egui::Panel::top("genesis-menu-and-ribbon")
        .frame(egui::Frame::default().fill(PAPER)
            .inner_margin(egui::Margin::symmetric(4,2)))
        .show(ui_root,|ui| {
            ui.horizontal_wrapped(|ui| {
                ui.spacing_mut().item_spacing.x=5.0;
                for (title, entries) in [
                    ("File",&["New","Open AREA...","Save","Save As","Save Package","Exit"][..]),
                    ("Edit",&["Undo","Redo","Cut","Copy","Paste","Delete","Select","Align Selection"][..]),
                    ("View",&["3D AREA View","Land Wireframe","Object Wireframe","Land Chunk Grid",
                        "Land Area Grid","Land Layer ID","Hide Land Color","Hide Land Layers",
                        "Hide Shadows","Dynamic Shadows","UI 80%","UI 100%","UI 125%","UI 150%",
                        "Grimvault Preview","Aurora Preview","Blue Forest Preview"][..]),
                    ("Select",&["Select","Selection Mask","Highlight Primary",
                        "Align Selection","Group","Ungroup"][..]),
                    ("Terrain",&["Height Brush","Smooth","Flatten","Noise","Clone","Stamp",
                        "Texture Brush","Color Brush","Land Chunk Grid","Chunk Inspector"][..]),
                    ("Objects",&["Prop Models","Prop Interiors","Object List",
                        "Snap Points Properties","Group","Ungroup"][..]),
                    ("Clutter",&["Clutter Preset","Clutter","Hide Canopy","Fade Unused Props"][..]),
                    ("Water",&["Water","Simple Water","Water Grid","Water Sphere",
                        "Water Grid Outer Edge"][..]),
                    ("Environment",&["Sky","Sky Editor","Fog","Lights","Cloud Shadows",
                        "God Rays","Dynamic Shadows","Time of Day"][..]),
                    ("Zones",&["Zones","Named Region Editor","Navigation Window",
                        "Land Layer ID"][..]),
                    ("Window",&["Dock Properties","Float Properties","Hide Properties",
                        "Bottom Workspace","Header Toolbars","Color Brush Properties",
                        "Color Palette","Texture Brush Properties","Clutter Preset",
                        "Object List","AREA Inspector","Named Region Editor"][..]),
                    ("Help",&["About Genesis","Keyboard Shortcuts"][..]),
                ] {
                    ui.menu_button(egui::RichText::new(title).size(10.0),|ui| {
                        for &entry in entries {
                            if ui.button(entry).clicked() {
                                command(state,entry);
                                ui.close();
                            }
                        }
                    });
                }
                if ui.available_width()>150.0 {
                    ui.separator();
                    ui.label(egui::RichText::new("World Editor - Genesis")
                        .size(9.0).color(EDGE));
                }
            });
            ui.separator();
            ui.horizontal_wrapped(|ui| {
                ui.label(egui::RichText::new("World").size(9.).strong());
                ui.add_sized([83.,17.],egui::Button::new("NewCentral").frame(true));
                ui.label(egui::RichText::new("Map").size(9.).strong());
                ui.add_sized([52.,17.],egui::Button::new("Area 106").frame(true));
                if ui.button("Open AREA...").clicked() {command(state,"Open AREA...");}
                if ui.button("3D View").clicked() {command(state,"3D AREA View");}
                ui.separator();
                ui.label(egui::RichText::new("Time of Day").size(9.));
                ui.add(egui::Slider::new(&mut state.time_of_day,0.0..=24.0)
                    .show_value(true).custom_formatter(|v,_|format!("{v:04.1}")));
            });
            if !state.toolbars_visible {return;}
            ui.separator();
            let compact=ui.available_width()<1000.0;
            if compact {
                ui.horizontal(|ui| {
                    ui.label(egui::RichText::new("Tools").strong().size(9.));
                    for (i,label) in ["Main","Terrain","Props","Environment","Zones"].iter().enumerate() {
                        if ui.selectable_label(state.ribbon_tab==i,
                            egui::RichText::new(*label).size(9.)).clicked() {
                            state.ribbon_tab=i;
                        }
                    }
                });
            }
            egui::ScrollArea::horizontal()
                .id_salt("genesis-icon-toolbar")
                .scroll_bar_visibility(egui::scroll_area::ScrollBarVisibility::AlwaysHidden)
                .show(ui,|ui| {
                    ui.horizontal(|ui| {
                        ui.spacing_mut().item_spacing.x=1.0;
                        for (i,&(name,glyph,color)) in ICONS.iter().enumerate() {
                            if compact {
                                let group=if i<10 {0} else if i<20 {1}
                                    else if i<27 {2} else if i<34 {3} else {4};
                                if group!=state.ribbon_tab {continue;}
                            }
                            if matches!(i,6|10|16|20|26|33) {ui.separator();}
                            icon(ui,state,name,glyph,color);
                        }
                    });
                });
            let terrain:&[&'static str]=&[
                "Double Sided","Slope","Object Wireframe","Land Wireframe",
                "Land Area Grid","Land Chunk Grid","Land Edges","Designer Color",
                "SkyWeights","Land Layer ID","In Flux","Highlight Primary","Align Selection",
                "Normal","Opaque","Navigation Window","Play Now","Sky Editor",
                "Save Package","Cell",
            ];
            let art:&[&'static str]=&[
                "Fog","Land","Land Love","Prop Models","Prop Interiors","Hide Canopy",
                "Clutter","Water","Particles","Simple Water","Water Sphere","Water Grid",
                "Water Grid Outer Edge","Selection Mask","Chunk Inspector","Land Shadows",
                "Dynamic Shadows","Plug Mask","Things with No Bounds",
            ];
            let environment:&[&'static str]=&[
                "Sky","FullScreen Effects","Lights","Set Diffuse to Gray",
                "Force Plastic Material","Hide Shadows","Cloud Shadows",
                "Select Sky Override","Selected Sky Gizmos","Hide Land Color",
                "Hide Land Layers","God Rays","Fade Unused Props","Object List",
                "Snap Points Properties","Zones","Named Region Editor",
            ];
            if compact {
                let row=match state.ribbon_tab {
                    0|1=>terrain,2=>art,3=>environment,_=>&[
                        "Zones","Named Region Editor","Navigation Window",
                        "Land Occlusion Lines","Occlusion Editor"][..],
                };
                small_commands(ui,state,"compact-genesis-command-row",row);
            } else {
                small_commands(ui,state,"genesis-tool-row-1",terrain);
                small_commands(ui,state,"genesis-tool-row-2",art);
                small_commands(ui,state,"genesis-tool-row-3",environment);
            }
        });
}

fn bottom_strip(ui_root:&mut egui::Ui, state:&mut GenesisState, loaded:&LoadedArea,
                orbit:&OrbitCamera) {
    // The status bar is always visible, while the workspace can be collapsed.
    egui::Panel::bottom("genesis-bottom-status")
        .frame(egui::Frame::default().fill(PAPER)
            .inner_margin(egui::Margin::symmetric(6,3)))
        .show(ui_root,|ui| {
            ui.horizontal(|ui| {
                if ui.small_button(if state.bottom_visible {"▾"} else {"▴"}).clicked() {
                    state.bottom_visible=!state.bottom_visible;
                }
                let max_chars=(ui.available_width()/6.0).floor().clamp(24.0,110.0) as usize;
                let short_status=if state.status.chars().count()>max_chars {
                    format!("{}…",state.status.chars().take(max_chars.saturating_sub(1))
                        .collect::<String>())
                } else {state.status.clone()};
                ui.label(egui::RichText::new(short_status).size(9.))
                    .on_hover_text(&state.status);
                if ui.available_width()>210.0 {
                    ui.separator();
                    ui.label(egui::RichText::new(format!(
                        "XYZ {:>5.1} / {:>5.1} / {:>5.1}",
                        orbit.focus.x,orbit.focus.y,orbit.focus.z)).size(9.));
                    ui.label(egui::RichText::new(format!(
                        "{} cells",loaded.tile.as_ref().map(|t|t.cell_count()).unwrap_or(0)))
                        .size(9.));
                }
            });
        });
    if !state.bottom_visible {return;}
    egui::Panel::bottom("genesis-bottom-workspace")
        .frame(egui::Frame::default().fill(PANEL)
            .stroke(egui::Stroke::new(1.,EDGE))
            .inner_margin(egui::Margin::symmetric(5,3)))
        .resizable(true).default_size(62.0).min_size(46.0).max_size(190.0)
        .show(ui_root,|ui| {
            ui.horizontal_wrapped(|ui| {
                for (i,label) in ["Occlusion","Layers","Selection","Navigation","Output"].iter().enumerate() {
                    if ui.selectable_label(state.bottom_tab==i,
                        egui::RichText::new(*label).size(9.)).clicked(){
                        state.bottom_tab=i;
                    }
                }
                ui.separator();
                if ui.small_button("Hide").clicked(){state.bottom_visible=false;}
            });
            ui.separator();
            egui::ScrollArea::vertical().auto_shrink([false,false]).show(ui,|ui| {
                ui.horizontal_wrapped(|ui| {
                    let commands:&[&'static str]=match state.bottom_tab {
                        0=>&["Occlusion","Land Occlusion Lines","Land Occlusion Nodes",
                             "Occlusion Editor","Land Occlusion Curtains"],
                        1=>&["Land","Land Layer ID","Land Chunk Grid",
                             "Land Area Grid","Chunk Inspector"],
                        2=>&["Select","Selection Mask","Align Selection",
                             "Group","Ungroup","Clear Selection"],
                        3=>&["Navigation Window","Named Region Editor",
                             "Zones","Waypoints"],
                        _=>&["Open AREA...","AREA Inspector","Save Package"],
                    };
                    for &name in commands {
                        if ui.add(egui::Button::new(egui::RichText::new(name).size(9.)))
                            .clicked(){command(state,name);}
                    }
                });
                if state.bottom_tab==4 {
                    ui.label(egui::RichText::new(&state.status).size(9.).color(INK));
                }
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
                    // Keep reference screenshot proportions intact on resize.
                    let image_size=tex.size_vec2();
                    let scale=(rect.width()/image_size.x)
                        .min(rect.height()/image_size.y).max(0.0);
                    let target=egui::Rect::from_center_size(
                        rect.center(),image_size*scale);
                    ui.painter().image(tex.id(),target,
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

// A resizable dock replaces fixed-position floating tools in the default layout.
// Classic floating property windows can still be enabled from Window > Float Properties.
fn dock_panels(ui_root:&mut egui::Ui, state:&mut GenesisState, loaded:&LoadedArea) {
    if ui_root.available_width()<610.0 {
        // Keep the entire center visible on small windows. Open floating mode if needed.
        return;
    }
    egui::Panel::right("genesis-properties-dock")
        .resizable(true)
        .default_size(232.0)
        .min_size(188.0).max_size(440.0)
        .frame(panel_frame())
        .show(ui_root,|ui| {
            ui.horizontal_wrapped(|ui| {
                ui.label(egui::RichText::new("Genesis").strong().size(10.));
                if ui.small_button("Float").clicked() {
                    state.floating_mode=true;
                    state.dock_visible=false;
                }
                if ui.small_button("×").clicked(){state.dock_visible=false;}
            });
            ui.separator();
            ui.horizontal_wrapped(|ui| {
                ui.spacing_mut().item_spacing.x=3.;
                for (i,title) in ["Brush","Palette","Texture","Clutter",
                    "Objects","World","AREA"].iter().enumerate() {
                    if ui.selectable_label(state.dock_tab==i,
                        egui::RichText::new(*title).size(9.)).clicked() {
                        state.dock_tab=i;
                    }
                }
            });
            ui.separator();
            egui::ScrollArea::vertical()
                .id_salt("genesis-property-dock-scroll")
                .auto_shrink([false,false])
                .show(ui,|ui| {
                    match state.dock_tab {
                        0=>dock_brush(ui,state),
                        1=>dock_palette(ui,state),
                        2=>dock_texture(ui,state),
                        3=>dock_clutter(ui,state),
                        4=>dock_objects(ui,state),
                        5=>dock_world(ui,state),
                        _=>dock_area(ui,state,loaded),
                    }
                });
        });
}
fn dock_brush(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("Color Brush Properties").strong().size(10.));
    ui.separator();
    row_slider(ui,"Size",&mut state.brush_size,0.01..=2.);
    row_slider(ui,"Power",&mut state.power,0.0..=2.);
    row_slider(ui,"F/O",&mut state.falloff,0.0..=1.);
    ui.horizontal_wrapped(|ui| {
        for (i,title) in ["Circle","Chunk","Selection"].iter().enumerate() {
            ui.radio_value(&mut state.circle,i,*title);
        }
    });
    ui.checkbox(&mut state.restricted,"Restrict to Selection");
    ui.horizontal(|ui| {
        ui.radio_value(&mut state.custom_tip,false,"Normal Tip");
        ui.radio_value(&mut state.custom_tip,true,"Custom Tip");
    });
    ui.separator();
    ui.label(egui::RichText::new("Advanced Settings").strong().size(9.));
    for (i,title) in [
        "Normal","Burn Tool","Dodge Tool","Overlay","Saturate Sponge",
        "Desaturate Sponge","Color"].iter().enumerate() {
        ui.radio_value(&mut state.mode,i,*title);
    }
    ui.separator();
    if ui.button("Clear Selection").clicked(){command(state,"Clear Selection");}
    ui.label(egui::RichText::new("Brush functions are UI placeholders").size(9.).color(EDGE));
}
fn dock_palette(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("Color Palette").strong().size(10.));
    ui.horizontal_wrapped(|ui| {
        for name in ["Grimvault Chrs","Grimvault Idealized","Grimvault"] {
            ui.add(egui::Button::new(egui::RichText::new(name).size(8.)));
        }
    });
    ui.add(egui::TextEdit::singleline(&mut state.search)
        .hint_text("Name").desired_width(ui.available_width().max(70.)));
    let swatches:[([u8;3],&str);14]=[
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
    for (i,(rgb,label)) in swatches.iter().enumerate() {
        if !state.search.is_empty() &&
            !label.to_lowercase().contains(&state.search.to_lowercase()) {
            continue;
        }
        ui.horizontal(|ui| {
            let (rect,response)=ui.allocate_exact_size(
                egui::vec2(24.,27.),egui::Sense::click());
            ui.painter().rect_filled(rect,0.,
                egui::Color32::from_rgb(rgb[0],rgb[1],rgb[2]));
            if response.clicked(){state.palette_index=i;}
            ui.vertical(|ui| {
                if ui.selectable_label(state.palette_index==i,
                    egui::RichText::new(*label).size(9.)).clicked(){
                    state.palette_index=i;
                }
                ui.label(egui::RichText::new("Category: Favorite").size(8.).color(INK));
            });
        });
        ui.separator();
    }
}
fn dock_texture(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("Texture Brush Properties").strong().size(10.));
    row_slider(ui,"Size",&mut state.brush_size,0.01..=2.);
    row_slider(ui,"Power",&mut state.power,0.0..=2.);
    row_slider(ui,"F/O",&mut state.falloff,0.0..=1.);
    ui.separator();
    ui.label("Land Texture Layers");
    for i in 0..4 {
        ui.radio_value(&mut state.texture_index,i,format!("WorldLayer slot {i}"));
    }
    ui.checkbox(&mut state.restricted,"Restrict to Selection");
    ui.separator();
    ui.label(egui::RichText::new("Height-based blending: placeholder")
        .color(EDGE).size(9.));
}
fn dock_clutter(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("Clutter Preset").strong().size(10.));
    for name in [
        "Aurora_Grass_Shrubs","Aurora_Grass_Tall",
        "Grimvault_Grass_01","Grimvault_Grass_02",
        "Grimvault_Crystal","Grimvault_Rocks","Grimvault_Shrubs"
    ] {
        if ui.selectable_label(state.active==name,name).clicked() {
            command(state,name);
        }
    }
    ui.separator();
    ui.label("Density");
    ui.add(egui::Slider::new(&mut state.power,0.0..=2.0));
}
fn dock_objects(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("Object List / Snap Points").strong().size(10.));
    for name in ["World","Land","Props","Clutter","Zones","Water","Lights","FX"] {
        ui.collapsing(name,|ui| {
            if ui.selectable_label(false,format!("{name} (placeholder)")).clicked(){
                state.status=format!("{name}: selection placeholder");
            }
        });
    }
    ui.separator();
    ui.label("Transform");
    for name in ["Position  0.000  0.000  0.000",
        "Rotation  0.000  0.000  0.000","Scale  1.000  1.000  1.000"] {
        ui.label(egui::RichText::new(name).monospace().size(9.));
    }
    if ui.button("Align Selection").clicked(){command(state,"Align Selection");}
    if ui.button("Snap Points Properties").clicked(){
        command(state,"Snap Points Properties");
    }
}
fn dock_world(ui:&mut egui::Ui,state:&mut GenesisState) {
    ui.label(egui::RichText::new("World / Environment").strong().size(10.));
    ui.collapsing("Zones / Regions",|ui| {
        for name in ["Zones","Named Region Editor","Navigation Window"] {
            if ui.button(name).clicked(){command(state,name);}
        }
    });
    ui.collapsing("Sky / Lighting",|ui| {
        ui.label("Time of Day");
        ui.add(egui::Slider::new(&mut state.time_of_day,0.0..=24.0));
        for name in ["Sky","Sky Editor","Fog","Lights","God Rays",
            "Cloud Shadows","Dynamic Shadows"]{
            if ui.button(name).clicked(){command(state,name);}
        }
    });
    ui.collapsing("Water",|ui| {
        for name in ["Water","Simple Water","Water Sphere","Water Grid"] {
            if ui.button(name).clicked(){command(state,name);}
        }
    });
    ui.collapsing("Streaming",|ui| {
        ui.label("Chunk: 32 m");
        ui.label("AREA tile: 512 m");
        ui.label(egui::RichText::new("World streaming: placeholder").size(9.).color(EDGE));
    });
}
fn dock_area(ui:&mut egui::Ui,state:&mut GenesisState,loaded:&LoadedArea) {
    ui.label(egui::RichText::new("AREA Inspector").strong().size(10.));
    let Some(area)=loaded.tile.as_ref() else {
        ui.label("No AREA tile loaded.");
        if ui.button("Open AREA...").clicked(){command(state,"Open AREA...");}
        return;
    };
    ui.monospace(format!("Version: {}",area.version));
    ui.monospace(format!("Binary: {} bytes",area.original.len()));
    ui.monospace(format!("Cells: {}",area.cell_count()));
    ui.monospace(format!("Chunks: {}",area.chunks.len()));
    ui.monospace(format!("Compression: {}",area.compressed));
    ui.separator();
    ui.label("Cell:");
    ui.add(egui::Slider::new(&mut state.selected_cell,0..=255));
    if let Some(cell)=area.cells[state.selected_cell].as_ref(){
        ui.monospace(format!("Index: {}",cell.index));
        ui.monospace(format!("Flags: {:08X}",cell.flags));
        ui.monospace(format!("Layers: {:?}",cell.layers()));
        ui.monospace(format!("Zones: {:?}",cell.zones()));
        if let Some(h)=cell.height(8,8) {
            ui.monospace(format!("Height: {h:.3} m"));
        }
        for (bit,block) in cell.blocks.iter().enumerate() {
            if let Some(data)=block {
                ui.label(egui::RichText::new(format!(
                    "bit {bit:02} | {} bytes",data.len())).size(8.));
            }
        }
    } else {
        ui.label("Cell absent");
    }
    ui.separator();
    ui.collapsing("Top-level chunks",|ui|{
        for chunk in &area.chunks {
            ui.monospace(format!("{} +0x{:X} ({} bytes)",
                String::from_utf8_lossy(&chunk.id),
                chunk.file_offset,chunk.data.len()));
        }
    });
    ui.label(egui::RichText::new("Read-only raw AREA data").size(9.).color(EDGE));
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
