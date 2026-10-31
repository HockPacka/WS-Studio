//! Visual-only reconstruction of the classic WildStar Genesis editor in Bevy.
//! Screenshots under WILDSTAREDITOR remain the visual references. No world edits yet.
use wildstar_formats::area;
use wildstar_formats::zone::{MapDiscovery, ZoneTileCoords};
mod area_ui;
mod client_data;
mod props;
mod terrain_splat;
mod splat_demo;
mod streaming;
mod terrain;
mod terrain_material;
mod water;
use bevy::prelude::*;
use bevy::pbr::ExtendedMaterial;
use bevy::camera::Viewport;
use std::path::Path;
use bevy_egui::{egui, EguiContexts, EguiGlobalSettings, EguiPlugin,
               EguiPrimaryContextPass, PrimaryEguiContext};

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
    open_area_path_dialog: bool,
    open_zone_dialog: bool,
    change_client_root: bool,
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
    terrain_view: usize,
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
            open_area_path_dialog: false,
            open_zone_dialog: false,
            change_client_root: false,
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
            terrain_view: 5,
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
    props: Vec<area::AreaProp>,
    prop_entities: Vec<Entity>,
    prop_issue: Option<String>,
    last_preview: (usize, usize),
    terrain_albedo: Option<Handle<Image>>,
    terrain_normal: Option<Handle<Image>>,
    /// The terrain material carries runtime splat data (see `terrain_splat`).
    terrain_splat: bool,
    water_entity: Option<Entity>,
    water_count: usize,
    layer_status: String,
    layer_notes: Vec<String>,
    missing_textures: Vec<String>,
}
#[derive(Resource)]
pub struct OrbitCamera {
    pub eye: Vec3,
    pub focus: Vec3,
    pub distance: f32,
    pub yaw: f32,
    pub pitch: f32,
    pub fly_speed: f32,
    pub is_first_person: bool,
    pub rect: Option<[f32; 4]>,
    pub ui_pixels_per_point: f32,
}
impl OrbitCamera {
    /// Returns the world origin position where rendering and world streaming are centered.
    pub fn origin(&self) -> Vec3 {
        if self.is_first_person {
            self.eye
        } else {
            self.focus
        }
    }

    /// Normalized forward direction vector of the camera.
    pub fn forward_direction(&self) -> Vec3 {
        let p = if self.is_first_person {
            self.pitch.clamp(-1.54, 1.54)
        } else {
            self.pitch.clamp(0.05, 1.52)
        };
        let cos_p = p.cos();
        Vec3::new(
            -self.yaw.sin() * cos_p,
            p.sin(),
            -self.yaw.cos() * cos_p,
        ).normalize()
    }
}
impl Default for OrbitCamera {
    fn default() -> Self {
        Self {
            eye: Vec3::new(0.0, 100.0, 0.0),
            focus: Vec3::ZERO,
            distance: 730.0,
            yaw: 0.0,
            pitch: -0.2,
            fly_speed: 80.0,
            is_first_person: true,
            rect: None,
            ui_pixels_per_point: 1.0,
        }
    }
}
fn setup_scene(mut commands: Commands, mut state: ResMut<GenesisState>,
               mut client: ResMut<client_data::ClientFiles>) {
    // Keep egui on a separate full-window camera, not on the terrain camera.
    // Bevy-egui 0.43 automatically selects the first camera unless disabled.
    // The 3D camera later receives a restricted viewport, which would otherwise
    // clip BOTH the interface and its mouse interaction region.
    commands.spawn((
        Camera2d,
        Camera {
            order: 1,
            clear_color: ClearColorConfig::None,
            ..default()
        },
        PrimaryEguiContext,
    ));
    commands.spawn((
        GenesisCamera,
        Camera3d::default(),
        Camera {
            order: 0,
            ..default()
        },
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
    let mut root_arg=None;
    let mut area_arg=None;
    let mut args=std::env::args().skip(1);
    while let Some(arg)=args.next(){
        match arg.as_str(){
            "--client-root" | "--root"=>root_arg=args.next(),
            "--area"=>area_arg=args.next(),
            _ if arg.to_ascii_lowercase().ends_with(".area")=>area_arg=Some(arg),
            _ if root_arg.is_none() && Path::new(&arg).is_dir()=>root_arg=Some(arg),
            _=>{},
        }
    }
    client.initialize(root_arg);
    if let Some(path)=area_arg {
        state.area_path=path.clone();
        state.pending_load=Some(path);
    }
    // A regular editor launch opens the client setup first; AREA files are
    // chosen explicitly using the native Windows Explorer dialog.

}
fn load_raw_area(
    mut state: ResMut<GenesisState>,
    client: Res<client_data::ClientFiles>,
    mut loaded: ResMut<LoadedArea>,
    mut orbit: ResMut<OrbitCamera>,
    mut streaming: ResMut<streaming::WorldStreaming>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut terrain_materials: ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mut images: ResMut<Assets<Image>>,
) {
    // Never load an AREA before its WildStar client asset root is indexed.
    if !client.ready(){return;}
    let Some(path)=state.pending_load.take() else {return;};
    let path_buf = Path::new(&path);
    let tile_coords = ZoneTileCoords::from_path_or_name(&path);

    // If this file belongs to a known Map folder, initiate WorldStreaming focused on this tile
    let is_map_folder = path_buf.parent().and_then(|p| {
        p.file_name().and_then(|n| n.to_str()).map(|name| (p, name.to_string()))
    });

    let mut is_streaming = false;
    if let Some((parent, map_name)) = is_map_folder {
        if let Some(client_dir) = client.client_data_dir() {
            if parent.starts_with(client_dir.join("Map")) {
                if let Ok(()) = streaming.open_map(&map_name, &client, &mut orbit, &mut commands) {
                    if let Some(coords) = tile_coords {
                        let center = coords.world_center();
                        orbit.eye = Vec3::new(center[0], 120.0, center[2] + 40.0);
                        orbit.focus = Vec3::new(center[0], 0.0, center[2]);
                    }
                    is_streaming = true;
                }
            }
        }
    }

    match area::RawArea::from_path(Path::new(&path)) {
        Ok(tile)=>{
            let water_bodies=tile.all_water_bodies();
            loaded.water_count=water_bodies.len();
            let decoded_props=tile.prop_placements();
            loaded.prop_issue=decoded_props.as_ref().err().cloned();
            loaded.props=decoded_props.unwrap_or_default();
            loaded.tile=Some(tile.clone());

            // Compute accurate world center from filename or infer from first prop
            let world_center = tile_coords
                .or_else(|| {
                    loaded.props.first().map(|pr| ZoneTileCoords::from_world_pos(pr.position_xyz[0], pr.position_xyz[2]))
                })
                .map(|c| c.world_center())
                .unwrap_or([0.0, 0.0, 0.0]);

            let preview=if state.terrain_view==5 && loaded.terrain_albedo.is_none(){
                1
            }else{state.terrain_view};

            match terrain::terrain_mesh(&tile,preview,state.texture_index) {
                Ok((mesh,focus))=>{
                    orbit.eye = Vec3::new(world_center[0], focus.y + 40.0, world_center[2] + 60.0);
                    orbit.focus = Vec3::new(world_center[0], focus.y, world_center[2]);
                    orbit.distance = 730.;
                    state.raw_view = true;

                    // Despawn any standalone entities
                    if let Some(old)=loaded.mesh_entity.take(){
                        commands.entity(old).despawn();
                    }
                    if let Some(old_water)=loaded.water_entity.take(){
                        commands.entity(old_water).despawn();
                    }
                    for old_prop in loaded.prop_entities.drain(..) {
                        commands.entity(old_prop).despawn();
                    }

                    if is_streaming {
                        // WorldStreaming is actively streaming around camera focus!
                        state.status = format!(
                            "Streaming zone around tile {} | {} cells | {} props | {}",
                            tile_coords.map(|c| c.to_hex()).unwrap_or_default(),
                            tile.cell_count(), loaded.props.len(), path
                        );
                        state.dock_tab = 5; // World tab with radar
                    } else {
                        // Standalone single-tile mode: spawn terrain at world_center, water and props
                        loaded.terrain_albedo=None;
                        loaded.terrain_splat=false;
                        let mut splat_ext=terrain_splat::SplatExt::default();
                        loaded.layer_notes.clear();
                        loaded.missing_textures.clear();
                        loaded.layer_status=String::from("WorldLayer material unavailable");
                        let atlas=client.index.as_ref().and_then(|index|{
                            match terrain_material::bake(&tile,index){
                                Ok(atlas)=>Some(atlas),
                                Err(error)=>{
                                    loaded.layer_status=format!("WorldLayer preview unavailable: {error}");
                                    None
                                }
                            }
                        });
                        if let Some(mut atlas)=atlas{
                            if let Some(data)=atlas.splat.take(){
                                splat_ext=data.into_extension(&mut images,state.terrain_view==5);
                                loaded.terrain_splat=true;
                            }
                            loaded.layer_status=format!(
                                "WorldLayer: {} IDs, {} decoded textures ({} unresolved)",
                                atlas.layers,atlas.textures,atlas.unresolved.len()
                            );
                            loaded.missing_textures=atlas.unresolved;
                            loaded.layer_notes=atlas.notes;
                            loaded.terrain_albedo=Some(images.add(atlas.albedo_image));
                            loaded.terrain_normal=atlas.normal_image.map(|img| images.add(img));
                        }

                        loaded.mesh_entity=Some(commands.spawn((
                            Mesh3d(meshes.add(mesh)),
                            MeshMaterial3d(terrain_materials.add(ExtendedMaterial{
                                base:StandardMaterial{
                                    base_color:Color::WHITE,
                                    base_color_texture:if state.terrain_view==5 && !loaded.terrain_splat {
                                        loaded.terrain_albedo.clone()
                                    }else{None},
                                    normal_map_texture:if state.terrain_view==5 && !loaded.terrain_splat {
                                        loaded.terrain_normal.clone()
                                    }else{None},
                                    perceptual_roughness:0.85,
                                    reflectance:0.2,
                                    cull_mode:None,
                                    ..default()
                                },
                                extension:splat_ext,
                            })),
                            Transform::from_xyz(world_center[0], 0.0, world_center[2]),
                        )).id());

                        if let Some(wmesh)=water::water_mesh(&water_bodies){
                            let water_ent=commands.spawn((
                                Mesh3d(meshes.add(wmesh)),
                                MeshMaterial3d(materials.add(water::water_material())),
                                Transform::default(),
                            )).id();
                            loaded.water_entity=Some(water_ent);
                        }

                        loaded.prop_entities=props::spawn_props(&mut commands, &loaded.props, &mut meshes, &mut materials, &mut images,
                            client.index.as_ref(), &client.prop_models);

                        state.status=format!(
                            "AREA | {} cells | {} props | {} water | {} | {}",
                            tile.cell_count(),loaded.props.len(),loaded.water_count,loaded.layer_status,path
                        );
                        state.dock_tab=6;
                    }
                    if loaded.terrain_albedo.is_none(){
                        eprintln!("Genesis TEXTURE: {}",loaded.layer_status);
                    }
                    for issue in loaded.missing_textures.iter().take(20){
                        eprintln!("Genesis TEXTURE: {issue}");
                    }
                    loaded.last_preview=(state.terrain_view,state.texture_index);
                    loaded.tile=Some(tile);
                }
                Err(e)=>state.status=format!("AREA mesh: {e}"),
            }
        }
        Err(e)=>state.status=format!("AREA read: {e}"),
    }
}
/// Replace only the mesh asset when an AREA debug-view option changes.
fn refresh_terrain_view(
    state:Res<GenesisState>,
    mut loaded:ResMut<LoadedArea>,
    mut meshes:ResMut<Assets<Mesh>>,
    mut materials:ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mut mesh_components:Query<(&mut Mesh3d,&MeshMaterial3d<terrain_splat::TerrainMaterial>)>,
){
    let target=(state.terrain_view,state.texture_index);
    if loaded.last_preview==target{return;}
    let Some(tile)=loaded.tile.as_ref() else{return;};
    let Some(entity)=loaded.mesh_entity else{return;};
    let preview=if target.0==5 && loaded.terrain_albedo.is_none(){1}else{target.0};
    let Ok((mesh,_))=terrain::terrain_mesh(tile,preview,target.1) else{return;};
    if let Ok((mut component,material))=mesh_components.get_mut(entity) {
        if let Some(mut terrain)=materials.get_mut(&material.0){
            let textured=target.0==5;
            terrain.extension.params.enabled=(textured && loaded.terrain_splat) as u32;
            terrain.base.base_color_texture=if textured && !loaded.terrain_splat{
                loaded.terrain_albedo.clone()
            }else{None};
            terrain.base.normal_map_texture=if textured && !loaded.terrain_splat{
                loaded.terrain_normal.clone()
            }else{None};
        }
        component.0=meshes.add(mesh);
        loaded.last_preview=target;
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

    if orbit.is_first_person {
        let forward = orbit.forward_direction();
        *transform = Transform::from_translation(orbit.eye)
            .looking_at(orbit.eye + forward, Vec3::Y);
    } else {
        let p=orbit.pitch.clamp(0.05,1.52);
        let direction=Vec3::new(orbit.yaw.sin()*p.cos(),p.sin(),orbit.yaw.cos()*p.cos());
        *transform=Transform::from_translation(orbit.focus+direction*orbit.distance)
            .looking_at(orbit.focus,Vec3::Y);
    }
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
    if let Some(out)=std::env::var_os("GENESIS_SPLAT_DEMO"){
        splat_demo::run(out.to_string_lossy().into_owned());
        return;
    }
    App::new()
        .insert_resource(GenesisState::default())
        .insert_resource(LoadedArea::default())
        .insert_resource(OrbitCamera::default())
        .insert_resource(client_data::ClientFiles::default())
        .insert_resource(streaming::WorldStreaming::default())
        // Explicitly attach PrimaryEguiContext to the full-window 2D camera.
        .insert_resource(EguiGlobalSettings {
            auto_create_primary_context: false,
            ..default()
        })
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
        .add_plugins(terrain_splat::TerrainSplatPlugin)
        .add_systems(Startup, setup_scene)
        .add_systems(Update, (client_data::poll_system, load_raw_area,
            streaming::update_world_streaming,
            refresh_terrain_view, update_camera).chain())
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
             mut orbit: ResMut<OrbitCamera>, loaded: Res<LoadedArea>,
             mut streaming: ResMut<streaming::WorldStreaming>,
             mut commands: Commands,
             mut client: ResMut<client_data::ClientFiles>) -> Result {
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
                bottom_strip(ui, &mut state, &loaded, orbit.as_mut(), streaming.as_ref());
                if state.dock_visible && !state.floating_mode {
                    dock_panels(ui, &mut state, &loaded, &client, streaming.as_mut(), orbit.as_mut(), &mut commands);
                }
                viewport(ui, &mut state, &previews, orbit.as_mut(), &loaded, streaming.as_ref());
            });
        });
    if state.floating_mode { floating_panels(ctx, &mut state); }
    area_inspector_panel(ctx, &mut state, &loaded);
    if state.change_client_root {
        client.setup_open=true;
        state.change_client_root=false;
    }
    if state.open_area_dialog {
        // Native Microsoft Windows Explorer file picker, not a hand-typed path.
        state.open_area_dialog=false;
        if client.ready() {
            if let Some(file)=client.choose_area(&state.area_path) {
                state.area_path=file.to_string_lossy().into_owned();
                state.pending_load=Some(state.area_path.clone());
            }
        } else {
            client.setup_open=true;
            state.status="Select and index the WildStar client root before opening AREA.".into();
        }
    }
    if state.open_area_path_dialog {
        let mut open=true;
        egui::Window::new("Open WildStar AREA – manual path")
            .collapsible(false).resizable(true)
            .default_pos(egui::pos2(220.,190.)).open(&mut open)
            .show(ctx,|ui|{
                ui.label("Original .area path:");
                ui.add(egui::TextEdit::singleline(&mut state.area_path)
                    .desired_width((ctx.content_rect().width()-60.).clamp(150.,485.)));
                if ui.button("Load AREA").clicked() {
                    if client.ready(){
                        state.pending_load=Some(state.area_path.clone());
                        state.open_area_path_dialog=false;
                    }else{
                        client.setup_open=true;
                    }
                }
            });
        if !open{state.open_area_path_dialog=false;}
    }
    zone_browser_dialog(ctx, &mut state, streaming.as_mut(), &client, orbit.as_mut(), &mut commands);
    client_data::startup_prompt(ctx,&mut client);
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
        "Open Zone..." | "Open Zone (World Streaming)..." => {
            state.open_zone_dialog = true;
        }
        "Open AREA..." => state.open_area_dialog = true,
        "Open AREA by path..." => state.open_area_path_dialog = true,
        "Choose Client Root..." => state.change_client_root = true,
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
                    ("File",&["New","Open Zone (World Streaming)...","Open AREA...","Open AREA by path...","Choose Client Root...",
                        "Save","Save As","Save Package","Exit"][..]),
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
                        "Object List","AREA Inspector","Choose Client Root...","Named Region Editor"][..]),
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
                if ui.button("Open Zone...").clicked() {command(state,"Open Zone...");}
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
                orbit:&mut OrbitCamera, streaming:&streaming::WorldStreaming) {
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
                    let origin = orbit.origin();
                    ui.label(egui::RichText::new(format!(
                        "XYZ {:>5.1} / {:>5.1} / {:>5.1}",
                        origin.x, origin.y, origin.z)).size(9.));
                    if ui.button(egui::RichText::new(if orbit.is_first_person { "FlyCam" } else { "Orbit" }).size(9.)).clicked() {
                        orbit.is_first_person = !orbit.is_first_person;
                    }
                    ui.label(egui::RichText::new(format!("{:.0} m/s", orbit.fly_speed)).size(9.));
                    if let Some(map) = streaming.active_map.as_ref() {
                        ui.label(egui::RichText::new(format!(
                            "ZONE {} ({}/{} tiles)",
                            map.name, streaming.loaded_tiles.len(), map.tiles.len()
                        )).size(9.).strong().color(egui::Color32::from_rgb(100, 210, 130)));
                    } else {
                        ui.label(egui::RichText::new(format!(
                            "{} cells",loaded.tile.as_ref().map(|t|t.cell_count()).unwrap_or(0)))
                            .size(9.));
                    }
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
            previews:&Viewports,orbit:&mut OrbitCamera,loaded:&LoadedArea,
            streaming:&streaming::WorldStreaming) {
    egui::CentralPanel::default()
        .frame(egui::Frame::default().fill(if state.raw_view {
            egui::Color32::TRANSPARENT
        } else { egui::Color32::from_rgb(37,24,49) }))
        .show(ui_root, |ui| {
            let rect = ui.available_rect_before_wrap();
            if state.raw_view {
                orbit.rect=Some([rect.left(),rect.top(),rect.right(),rect.bottom()]);
                let response=ui.allocate_rect(rect,egui::Sense::click_and_drag());
                if state.terrain_view==5 && loaded.tile.is_some(){
                    let has_texture=loaded.terrain_albedo.is_some();
                    let overlay=if has_texture {
                        format!("TEXTURED | {}",loaded.layer_status)
                    }else{
                        format!("TEXTURED unavailable | RGB565 fallback | {}",loaded.layer_status)
                    };
                    let box_rect=egui::Rect::from_min_size(rect.min+egui::vec2(8.,8.),
                        egui::vec2((rect.width()-16.).clamp(40.,590.),34.));
                    ui.painter().rect_filled(box_rect,3.,
                        egui::Color32::from_rgba_unmultiplied(20,20,27,210));
                    ui.painter().text(box_rect.left_center()+egui::vec2(9.,0.),
                        egui::Align2::LEFT_CENTER,overlay,
                        egui::FontId::proportional(12.),egui::Color32::WHITE);
                }
                if response.dragged_by(egui::PointerButton::Secondary) {
                    let delta=ui.input(|i|i.pointer.delta());
                    orbit.yaw -= delta.x * 0.003;
                    if orbit.is_first_person {
                        orbit.pitch = (orbit.pitch - delta.y * 0.003).clamp(-1.54, 1.54);
                    } else {
                        orbit.pitch = (orbit.pitch + delta.y * 0.006).clamp(0.05, 1.52);
                    }
                }
                if response.dragged_by(egui::PointerButton::Middle) {
                    let delta=ui.input(|i|i.pointer.delta());
                    if orbit.is_first_person {
                        let factor = orbit.fly_speed * 0.015;
                        let right = Vec3::new(orbit.yaw.cos(), 0.0, -orbit.yaw.sin());
                        orbit.eye -= right * delta.x * factor;
                        orbit.eye += Vec3::Y * delta.y * factor;
                    } else {
                        let factor=orbit.distance*0.002;
                        let right=Vec3::new(orbit.yaw.cos(),0.,-orbit.yaw.sin());
                        orbit.focus+=right*delta.x*factor
                            +Vec3::new(0.,1.,0.)*delta.y*factor;
                    }
                }
                if response.hovered() || response.dragged_by(egui::PointerButton::Secondary) || response.dragged_by(egui::PointerButton::Middle) {
                    let scroll=ui.input(|i|i.smooth_scroll_delta.y);
                    if scroll.abs() > 0.1 {
                        if orbit.is_first_person {
                            let speed_factor = (scroll * 0.002).exp();
                            orbit.fly_speed = (orbit.fly_speed * speed_factor).clamp(5.0, 2500.0);
                        } else {
                            orbit.distance=(orbit.distance*(-scroll*0.0015).exp()).clamp(3.,5000.);
                        }
                    }
                    if !ui.ctx().egui_wants_keyboard_input() {
                        let dt = ui.input(|i| i.stable_dt).clamp(0.001, 0.1);
                        let (up,down,left,right,space,c_key,q_key,e_key,shift,ctrl)=ui.input(|i|(
                            i.key_down(egui::Key::W),
                            i.key_down(egui::Key::S),
                            i.key_down(egui::Key::A),
                            i.key_down(egui::Key::D),
                            i.key_down(egui::Key::Space),
                            i.key_down(egui::Key::C),
                            i.key_down(egui::Key::Q),
                            i.key_down(egui::Key::E),
                            i.modifiers.shift,
                            i.modifiers.ctrl,
                        ));

                        let mut speed = orbit.fly_speed;
                        if shift { speed *= 3.5; }
                        if ctrl { speed *= 0.25; }
                        let dist = speed * dt;

                        let forward = orbit.forward_direction();
                        let side = Vec3::new(orbit.yaw.cos(), 0.0, -orbit.yaw.sin());

                        if orbit.is_first_person {
                            if up { orbit.eye += forward * dist; }
                            if down { orbit.eye -= forward * dist; }
                            if left { orbit.eye -= side * dist; }
                            if right { orbit.eye += side * dist; }
                            if space || e_key { orbit.eye += Vec3::Y * dist; }
                            if c_key || q_key { orbit.eye -= Vec3::Y * dist; }
                            orbit.focus = orbit.eye + forward * 100.0;
                        } else {
                            let orbit_speed = orbit.distance * if shift { 0.017 } else { 0.004 };
                            let flat_forward = Vec3::new(-orbit.yaw.sin(), 0.0, -orbit.yaw.cos());
                            if up { orbit.focus += flat_forward * orbit_speed; }
                            if down { orbit.focus -= flat_forward * orbit_speed; }
                            if left { orbit.focus -= side * orbit_speed; }
                            if right { orbit.focus += side * orbit_speed; }
                            if space || e_key { orbit.focus += Vec3::Y * orbit_speed; }
                            if c_key || q_key { orbit.focus -= Vec3::Y * orbit_speed; }
                            orbit.eye = orbit.focus - forward * orbit.distance;
                        }
                    }
                }
                if let Some(map) = streaming.active_map.as_ref() {
                    let mode_str = if orbit.is_first_person { "FlyCam" } else { "Orbit" };
                    let overlay = format!(
                        "STREAMING: {} | {}/{} tiles | Origin: [{:.0}, {:.0}, {:.0}] | {} | WASD/Space/C: Fly | RMB: Look | Spd: {:.0}m/s (Wheel)",
                        map.name, streaming.loaded_tiles.len(), map.tiles.len(),
                        orbit.origin().x, orbit.origin().y, orbit.origin().z,
                        mode_str, orbit.fly_speed
                    );
                    let box_rect = egui::Rect::from_min_size(rect.min + egui::vec2(8., 8.),
                        egui::vec2((rect.width() - 16.).clamp(40., 740.), 26.));
                    ui.painter().rect_filled(box_rect, 3.,
                        egui::Color32::from_rgba_unmultiplied(20, 20, 27, 210));
                    ui.painter().text(box_rect.left_center() + egui::vec2(9., 0.),
                        egui::Align2::LEFT_CENTER, overlay,
                        egui::FontId::proportional(11.), egui::Color32::from_rgb(120, 230, 160));
                } else if loaded.tile.is_none() {
                    ui.painter().text(rect.center(),egui::Align2::CENTER_CENTER,
                        "Open Zone... or Open AREA... (File menu) | WildStar World Streaming",
                        egui::FontId::proportional(15.),
                        egui::Color32::from_rgb(243,236,222));
                } else {
                    let mode_str = if orbit.is_first_person { "FlyCam" } else { "Orbit" };
                    let overlay = format!(
                        "RAW AREA | Origin: [{:.0}, {:.0}, {:.0}] | {} | WASD/Space/C: Fly | RMB: Look | Spd: {:.0}m/s (Wheel)",
                        orbit.origin().x, orbit.origin().y, orbit.origin().z,
                        mode_str, orbit.fly_speed
                    );
                    let box_rect = egui::Rect::from_min_size(rect.min + egui::vec2(8., 8.),
                        egui::vec2((rect.width() - 16.).clamp(40., 680.), 26.));
                    ui.painter().rect_filled(box_rect, 3.,
                        egui::Color32::from_rgba_unmultiplied(20, 20, 27, 210));
                    ui.painter().text(box_rect.left_center() + egui::vec2(9., 0.),
                        egui::Align2::LEFT_CENTER, overlay,
                        egui::FontId::proportional(11.), egui::Color32::from_rgb(238, 233, 219));
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
    ctx:&egui::Context,
    state:&mut GenesisState,
    loaded:&LoadedArea,
){
    if !state.area_inspector{return;}
    let mut opened=true;
    egui::Window::new("AREA Inspector")
        .id(egui::Id::new("genesis-area-inspector"))
        .default_pos(egui::pos2(24.,155.))
        .default_size(egui::vec2(385.,510.))
        .open(&mut opened)
        .resizable(true)
        .frame(panel_frame())
        .show(ctx,|ui|{
            if let Some(area)=loaded.tile.as_ref(){
                egui::ScrollArea::vertical().show(ui,|ui|{
                    area_ui::show(ui,&mut state.selected_cell,area,
                        &loaded.props,loaded.prop_issue.as_deref());
                });
            } else {
                ui.label("No AREA tile loaded. File -> Open AREA...");
            }
        });
    state.area_inspector=opened;
}

// A resizable dock replaces fixed-position floating tools in the default layout.
// Classic floating property windows can still be enabled from Window > Float Properties.
fn dock_panels(ui_root:&mut egui::Ui, state:&mut GenesisState,
              loaded:&LoadedArea,client:&client_data::ClientFiles,
              streaming:&mut streaming::WorldStreaming,
              orbit:&mut OrbitCamera,
              commands:&mut Commands) {
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
                    "Objects","World","AREA","Assets"].iter().enumerate() {
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
                        4=>dock_objects(ui,state,loaded,client),
                        5=>dock_world(ui,state,loaded,streaming,orbit,commands),
                        6=>dock_area(ui,state,loaded),
                        _=>{
                            if ui.button("Choose Client Root...").clicked(){
                                command(state,"Choose Client Root...");
                            }
                            client_data::asset_summary(ui,client,loaded.tile.as_ref());
                        },
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
fn dock_objects(ui:&mut egui::Ui,state:&mut GenesisState,loaded:&LoadedArea,
                client:&client_data::ClientFiles) {
    ui.label(egui::RichText::new("Object List / Snap Points").strong().size(10.));
    if !loaded.props.is_empty() {
        ui.collapsing(format!("AREA Prop Placements ({})",loaded.props.len()),|ui|{
            for prop in loaded.props.iter().take(64) {
                ui.collapsing(format!("{}: {}",prop.index,
                    prop.model_path.as_deref().unwrap_or("<unresolved name>")),|ui|{
                    ui.monospace(format!("XYZ: {:?}",prop.position_xyz));
                    ui.monospace(format!("Rotation: {:?}",prop.rotation_xyzw));
                    ui.monospace(format!("Scale: {:.4}",prop.scale));
                    ui.monospace(format!("Tint: 0x{:08X}",prop.tint));
                    if let (Some(index),Some(path))=(client.index.as_ref(),prop.model_path.as_deref()){
                        ui.separator();
                        for line in client.prop_models.report(index,path){ui.monospace(line);}
                    }
                });
            }
            if loaded.props.len()>64{ui.label("Showing first 64 placements");}
        });
    }
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
fn dock_world(
    ui: &mut egui::Ui,
    state: &mut GenesisState,
    loaded: &LoadedArea,
    streaming: &mut streaming::WorldStreaming,
    orbit: &mut OrbitCamera,
    commands: &mut Commands,
) {
    ui.label(egui::RichText::new("World / Zone Streaming").strong().size(10.));
    ui.separator();

    ui.group(|ui| {
        ui.label(egui::RichText::new("World Streaming").strong().size(10.));
        ui.horizontal(|ui| {
            if ui.button("Open Zone...").clicked() {
                state.open_zone_dialog = true;
            }
            if streaming.active_map.is_some() {
                if ui.button("Unload Zone").clicked() {
                    streaming.clear_all(commands);
                    streaming.active_map = None;
                }
            }
        });

        if let Some(map) = streaming.active_map.as_ref() {
            ui.label(egui::RichText::new(format!("Active Map: {}", map.name)).size(9.).strong());
            ui.label(egui::RichText::new(format!(
                "Loaded: {} / {} tiles ({} loading)",
                streaming.loaded_tiles.len(),
                map.tiles.len(),
                streaming.in_flight.len()
            )).size(9.));

            ui.add(egui::Slider::new(&mut streaming.streaming_radius, 1..=3).text("Radius"));
            let desc = match streaming.streaming_radius {
                1 => "3x3 tiles (1.5 km²)",
                2 => "5x5 tiles (2.5 km²)",
                _ => "7x7 tiles (3.5 km²)",
            };
            ui.label(egui::RichText::new(desc).size(8.).color(EDGE));

            ui.separator();
            ui.horizontal(|ui| {
                ui.label(egui::RichText::new("Cam Mode:").size(9.));
                if ui.selectable_label(orbit.is_first_person, "FlyCam").clicked() {
                    orbit.is_first_person = true;
                }
                if ui.selectable_label(!orbit.is_first_person, "Orbit").clicked() {
                    orbit.is_first_person = false;
                }
            });
            ui.add(egui::Slider::new(&mut orbit.fly_speed, 5.0..=1500.0).logarithmic(true).text("Fly Speed"));

            if let Some(cam) = streaming.camera_tile {
                ui.label(egui::RichText::new(format!(
                    "Camera Tile: [0x{:02x}, 0x{:02x}] ({})",
                    cam.z, cam.x, cam.to_hex()
                )).size(9.));
                let origin = cam.world_origin();
                ui.label(egui::RichText::new(format!(
                    "Tile Origin: X={:.0}, Z={:.0}", origin[0], origin[1]
                )).size(8.).color(EDGE));
            }

            ui.separator();
            ui.label(egui::RichText::new("Zone Radar (Click to Teleport)").size(9.).strong());
            render_zone_radar(ui, map, streaming, orbit);
        } else {
            ui.label(egui::RichText::new("No active map streaming.").size(9.).color(EDGE));
            ui.label(egui::RichText::new("Open a zone or .area file to start streaming.").size(8.).color(EDGE));
        }
    });

    if let Some(area) = loaded.tile.as_ref() {
        ui.collapsing("Focused AREA WorldZone IDs", |ui| {
            let mut ids = std::collections::BTreeSet::new();
            for cell in area.cells.iter().flatten() {
                if let Some(zone_ids) = cell.zones() {
                    for id in zone_ids { if id != 0 { ids.insert(id); } }
                }
            }
            for id in ids.iter().take(64) { ui.monospace(format!("WorldZone {id}")); }
            if ids.is_empty() { ui.label("No decoded WorldZone IDs"); }
        });
        ui.collapsing("Focused AREA WorldSky IDs", |ui| {
            let mut ids = std::collections::BTreeSet::new();
            for cell in area.cells.iter().flatten() {
                if let Some(corners) = cell.sky_ids() {
                    for corner in corners {
                        for id in corner { if id != 0 { ids.insert(id); } }
                    }
                }
            }
            for id in ids.iter().take(64) { ui.monospace(format!("WorldSky {id}")); }
            if ids.is_empty() { ui.label("No decoded WorldSky IDs"); }
        });
    }
    ui.collapsing("Zones / Regions", |ui| {
        for name in ["Zones", "Named Region Editor", "Navigation Window"] {
            if ui.button(name).clicked() { command(state, name); }
        }
    });
    ui.collapsing("Sky / Lighting", |ui| {
        ui.label("Time of Day");
        ui.add(egui::Slider::new(&mut state.time_of_day, 0.0..=24.0));
        for name in ["Sky", "Sky Editor", "Fog", "Lights", "God Rays", "Cloud Shadows", "Dynamic Shadows"] {
            if ui.button(name).clicked() { command(state, name); }
        }
    });
    ui.collapsing("Water", |ui| {
        for name in ["Water", "Simple Water", "Water Sphere", "Water Grid"] {
            if ui.button(name).clicked() { command(state, name); }
        }
    });
}

fn render_zone_radar(
    ui: &mut egui::Ui,
    map: &MapDiscovery,
    streaming: &streaming::WorldStreaming,
    orbit: &mut OrbitCamera,
) {
    let span_x = (map.max_x as i32 - map.min_x as i32 + 1).max(1) as f32;
    let span_z = (map.max_z as i32 - map.min_z as i32 + 1).max(1) as f32;

    let available_w = (ui.available_width() - 8.0).clamp(100.0, 220.0);
    let tile_size = (available_w / span_x.max(span_z)).clamp(2.0, 18.0);
    let radar_w = span_x * tile_size;
    let radar_h = span_z * tile_size;

    let (rect, response) = ui.allocate_exact_size(egui::vec2(radar_w, radar_h), egui::Sense::click());
    ui.painter().rect_filled(rect, 2.0, egui::Color32::from_rgb(25, 25, 30));

    // Teleport on click
    if response.clicked() {
        if let Some(pos) = response.interact_pointer_pos() {
            let rel_x = ((pos.x - rect.left()) / tile_size).floor() as i32;
            let rel_z = ((pos.y - rect.top()) / tile_size).floor() as i32;
            let target_x = (map.min_x as i32 + rel_x).clamp(0, 255) as u8;
            let target_z = (map.min_z as i32 + rel_z).clamp(0, 255) as u8;
            let target_coords = ZoneTileCoords::new(target_z, target_x);
            if map.tiles.contains_key(&target_coords) {
                let center = target_coords.world_center();
                orbit.eye.x = center[0];
                orbit.eye.z = center[2];
                orbit.focus = Vec3::new(center[0], orbit.eye.y, center[2]);
            }
        }
    }

    // Draw tiles
    for (&coords, _) in &map.tiles {
        let tx = (coords.x as i32 - map.min_x as i32) as f32 * tile_size;
        let tz = (coords.z as i32 - map.min_z as i32) as f32 * tile_size;
        let tile_rect = egui::Rect::from_min_size(
            rect.min + egui::vec2(tx, tz),
            egui::vec2((tile_size - 0.5).max(1.0), (tile_size - 0.5).max(1.0)),
        );

        let color = if streaming.loaded_tiles.contains_key(&coords) {
            egui::Color32::from_rgb(50, 200, 120)
        } else if streaming.in_flight.contains(&coords) {
            egui::Color32::from_rgb(230, 160, 40)
        } else {
            egui::Color32::from_rgb(60, 60, 75)
        };

        ui.painter().rect_filled(tile_rect, 0.5, color);
    }

    // Draw camera position and heading
    if let Some(cam) = streaming.camera_tile {
        if cam.x >= map.min_x && cam.x <= map.max_x && cam.z >= map.min_z && cam.z <= map.max_z {
            let cx = (cam.x as i32 - map.min_x as i32) as f32 * tile_size + tile_size * 0.5;
            let cz = (cam.z as i32 - map.min_z as i32) as f32 * tile_size + tile_size * 0.5;
            let center_pt = rect.min + egui::vec2(cx, cz);
            ui.painter().circle_filled(
                center_pt,
                (tile_size * 0.7).clamp(2.5, 6.0),
                egui::Color32::from_rgb(255, 230, 50),
            );

            // Draw look direction heading pointer
            let dir_x = -orbit.yaw.sin();
            let dir_z = -orbit.yaw.cos();
            let pointer_len = (tile_size * 1.3).clamp(5.0, 15.0);
            ui.painter().line_segment(
                [center_pt, center_pt + egui::vec2(dir_x * pointer_len, dir_z * pointer_len)],
                egui::Stroke::new(1.5, egui::Color32::from_rgb(255, 255, 100)),
            );
        }
    }
}

fn zone_browser_dialog(
    ctx: &egui::Context,
    state: &mut GenesisState,
    streaming: &mut streaming::WorldStreaming,
    client: &client_data::ClientFiles,
    orbit: &mut OrbitCamera,
    commands: &mut Commands,
) {
    if !state.open_zone_dialog {
        return;
    }
    if !client.ready() {
        state.open_zone_dialog = false;
        state.status = "Please setup ClientData before opening zones.".to_string();
        return;
    }

    if streaming.available_maps.is_empty() {
        streaming.refresh_available_maps(client);
    }

    let mut open = true;
    egui::Window::new("Open WildStar Zone (World Streaming)")
        .collapsible(false)
        .resizable(true)
        .default_size(egui::vec2(440.0, 520.0))
        .open(&mut open)
        .show(ctx, |ui| {
            ui.horizontal(|ui| {
                ui.label("Search:");
                ui.add(egui::TextEdit::singleline(&mut streaming.map_search).desired_width(220.0));
                if ui.small_button("Clear").clicked() {
                    streaming.map_search.clear();
                }
                if ui.small_button("Refresh").clicked() {
                    streaming.refresh_available_maps(client);
                }
            });
            ui.separator();

            let query = streaming.map_search.trim().to_ascii_lowercase();
            let matches: Vec<String> = streaming
                .available_maps
                .iter()
                .filter(|m| query.is_empty() || m.to_ascii_lowercase().contains(&query))
                .cloned()
                .collect();

            ui.label(egui::RichText::new(format!("Available Zones: {} (showing {})", streaming.available_maps.len(), matches.len())).size(9.).color(EDGE));
            ui.separator();

            egui::ScrollArea::vertical().max_height(380.0).show(ui, |ui| {
                for map_name in matches {
                    ui.horizontal(|ui| {
                        if ui.button(egui::RichText::new(&map_name).strong()).clicked() {
                            match streaming.open_map(&map_name, client, orbit, commands) {
                                Ok(_) => {
                                    state.status = format!("Loaded zone {map_name}");
                                    state.dock_tab = 5;
                                    state.open_zone_dialog = false;
                                }
                                Err(e) => {
                                    state.status = format!("Failed to open {map_name}: {e}");
                                }
                            }
                        }
                    });
                }
            });

            ui.separator();
            ui.horizontal(|ui| {
                if ui.button("Close").clicked() {
                    state.open_zone_dialog = false;
                }
            });
        });

    if !open {
        state.open_zone_dialog = false;
    }
}
fn dock_area(ui:&mut egui::Ui,state:&mut GenesisState,loaded:&LoadedArea){
    ui.label("Terrain preview");
    ui.horizontal_wrapped(|ui|{
        for (i,name) in ["Height","RGB565","Layer IDs","Zone IDs","Blend","Textured"].iter().enumerate(){
            ui.selectable_value(&mut state.terrain_view,i,*name);
        }
    });
    if state.terrain_view>=2 && state.terrain_view!=3 && state.terrain_view!=5{
        ui.horizontal(|ui|{
            ui.label("Layer slot");
            ui.add(egui::Slider::new(&mut state.texture_index,0..=3));
        });
    }
    if state.terrain_view==5{
        ui.label(egui::RichText::new(&loaded.layer_status).small().strong());
        if loaded.terrain_albedo.is_none(){
            ui.colored_label(egui::Color32::DARK_RED,
                "No texture atlas loaded: showing original AREA RGB565 instead.");
        }
        for note in &loaded.layer_notes {
            ui.label(egui::RichText::new(note).small().color(EDGE));
        }
        if !loaded.missing_textures.is_empty(){
            ui.collapsing(format!("Missing / unsupported textures ({})",
                loaded.missing_textures.len()),|ui|{
                for issue in loaded.missing_textures.iter().take(70){
                    ui.monospace(issue);
                }
            });
        }
    }
    if let Some(area)=loaded.tile.as_ref(){
        area_ui::show(ui,&mut state.selected_cell,area,
            &loaded.props,loaded.prop_issue.as_deref());
    }else{
        ui.label("No AREA tile loaded.");
        if ui.button("Open AREA...").clicked(){command(state,"Open AREA...");}
    }
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
