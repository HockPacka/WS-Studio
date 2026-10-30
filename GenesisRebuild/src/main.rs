//! Visual-only reconstruction of the classic WildStar Genesis editor in Bevy.
//! Screenshots under WILDSTAREDITOR remain the visual references. No world edits yet.
use bevy::prelude::*;
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
            status: "World Editor - Genesis | Visual UI placeholders".to_string(),
        }
    }
}
#[derive(Default)]
struct Viewports { textures: Vec<egui::TextureHandle> }

fn main() {
    App::new()
        .insert_resource(GenesisState::default())
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
        .add_systems(Startup, |mut commands: Commands| { commands.spawn(Camera2d); })
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
    let mut style = (*ctx.style()).clone();
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
    ctx.set_style(style);
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
             mut previews: Local<Viewports>, mut initialized: Local<bool>) -> Result {
    let ctx = contexts.ctx_mut()?;
    if !*initialized { classic_visuals(ctx); *initialized = true; }
    if previews.textures.is_empty() { load_scenes(ctx, &mut previews); }
    menu_and_toolbars(ctx, &mut state);
    bottom_strip(ctx, &mut state);
    viewport(ctx, &state, &previews);
    floating_panels(ctx, &mut state);
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
        "Zones" | "Named Region Editor" => state.zone_panel = true,
        "Land Chunk Grid" => state.grid = !state.grid,
        "Grimvault Preview" => state.scene = 0,
        "Aurora Preview" => state.scene = 1,
        "Blue Forest Preview" => state.scene = 2,
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
fn menu_and_toolbars(ctx: &egui::Context, state: &mut GenesisState) {
    egui::TopBottomPanel::top("genesis-menu-and-ribbon")
        .frame(egui::Frame::default().fill(PAPER)
               .inner_margin(egui::Margin::symmetric(4,2)))
        .show(ctx, |ui| {
            ui.horizontal(|ui| {
                for (title, entries) in [
                    ("File",&["New","Open","Save","Save As","Exit"][..]),
                    ("Edit",&["Undo","Redo","Cut","Copy","Paste","Delete"][..]),
                    ("View",&["Land Wireframe","Land Chunk Grid","Land Edges","Slope",
                              "Grimvault Preview","Aurora Preview","Blue Forest Preview"][..]),
                    ("Tools",&["Height Brush","Texture Brush","Color Brush","Clutter","Prop Models"][..]),
                    ("Window",&["Color Brush Properties","Color Palette","Texture Brush Properties",
                                "Clutter Preset","Object List","Snap Points Properties"][..]),
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
fn bottom_strip(ctx: &egui::Context, state: &mut GenesisState) {
    egui::TopBottomPanel::bottom("bottom-occlusion-strip")
        .frame(egui::Frame::default().fill(PAPER)
               .inner_margin(egui::Margin::symmetric(5,2)))
        .show(ctx, |ui| {
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
fn viewport(ctx: &egui::Context, state: &GenesisState, previews: &Viewports) {
    egui::CentralPanel::default()
        .frame(egui::Frame::default().fill(egui::Color32::from_rgb(37,24,49)))
        .show(ctx, |ui| {
            let rect = ui.available_rect_before_wrap();
            if let Some(tex) = previews.textures.get(state.scene) {
                ui.painter().image(tex.id(),rect,
                    egui::Rect::from_min_max(egui::Pos2::ZERO, egui::pos2(1.,1.)),
                    egui::Color32::WHITE);
            }
            if state.grid {
                let mut x = rect.left();
                while x < rect.right() {
                    ui.painter().line_segment([egui::pos2(x,rect.top()),egui::pos2(x,rect.bottom())],
                        egui::Stroke::new(0.6, egui::Color32::from_rgba_unmultiplied(232,194,113,70)));
                    x += 64.0;
                }
                let mut y = rect.top();
                while y < rect.bottom() {
                    ui.painter().line_segment([egui::pos2(rect.left(),y),egui::pos2(rect.right(),y)],
                        egui::Stroke::new(0.6, egui::Color32::from_rgba_unmultiplied(232,194,113,70)));
                    y += 64.0;
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
