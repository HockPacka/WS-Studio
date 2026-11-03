//! Visual-only reconstruction of the classic WildStar Genesis editor in Bevy.
//! Screenshots under WILDSTAREDITOR remain the visual references. No world edits yet.
use wildstar_formats::area;
use wildstar_formats::zone::{MapDiscovery, ZoneTileCoords};
mod area_ui;
mod client_data;
mod props;
mod m3_layers;
mod prop_viewer;
mod terrain_splat;
mod splat_demo;
mod streaming;
mod terrain;
mod terrain_edit;
mod terrain_paint;
mod terrain_bundle;
mod clutter;
mod clutter_native;
mod clutter_rebuild;
mod clutter_wind;
mod clutter_paint;
mod terrain_material;
mod water;
mod sky;
mod genesis_icons;
mod brush_profile;
mod new_area;
use bevy::prelude::*;
use bevy::pbr::ExtendedMaterial;
use bevy::light::CascadeShadowConfigBuilder;
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
    sculpt_tool: &'static str,
    paint_tool: &'static str,
    brush_size: f32, power: f32, hardness: f32, falloff: f32,
    mode: usize,
    circle: usize,
    restricted: bool,
    custom_tip: bool,
    color_panel: bool, color_palette: bool, texture_panel: bool,
    clutter_panel: bool, prop_panel: bool, object_list: bool,
    clutter_preview_enabled: bool,
    clutter_native_mode: bool,
    clutter_brush_enabled: bool,
    clutter_brush_action: u8,
    clutter_auto_refresh: bool,
    clutter_preview_request: u64,
    clutter_model_path: String,
    clutter_layer: usize,
    clutter_selector: u8,
    clutter_density: u32,
    clutter_instance_limit: u32,
    clutter_view_distance: f32,
    clutter_lod_distance: f32,
    clutter_wind_enabled: bool,
    clutter_wind_strength: f32,
    clutter_wind_speed: f32,
    clutter_wind_direction: Vec2,
    zone_panel: bool,
    grid: bool, palette_index: usize, texture_index: usize,
    tint: terrain_splat::TintSettings,
    search: String,
    status: String,
    raw_view: bool,
    open_area_dialog: bool,
    new_area_dialog: bool,
    new_area_options: new_area::Options,
    open_area_path_dialog: bool,
    open_model_dialog: bool,
    pending_model_load: Option<String>,
    open_zone_dialog: bool,
    change_client_root: bool,
    area_path: String,
    pending_load: Option<String>,
    area_inspector: bool,
    selected_cell: usize,
    weight_research_report: Option<area::weight_research::AreaWeightResearch>,
    dock_visible: bool,
    floating_mode: bool,
    bottom_visible: bool,
    toolbars_visible: bool,
    ui_zoom: f32,
    dock_tab: usize,
    bottom_tab: usize,
    time_of_day: f32,
    /// Render-preview controls: never write to native .sky/.area assets.
    shadow_preview_enabled: bool,
    ambient_light_scale: f32,
    sun_light_scale: f32,
    terrain_view: usize,
    area_standalone: bool,
    terrain_save_dialog: bool,
    terrain_bundle_dialog: bool,
    terrain_undo_request: bool,
    terrain_redo_request: bool,
}
impl Default for GenesisState {
    fn default() -> Self {
        Self {
            scene: 0, active: "Terrain Sculpt",
            sculpt_tool: "Height Brush",
            paint_tool: "Texture Brush",
            brush_size: 0.75, power: 1.0, hardness: 0.58, falloff: 0.58,
            mode: 0, circle: 0, restricted: false, custom_tip: false,
            color_panel: true, color_palette: true, texture_panel: false,
            clutter_panel: false, prop_panel: false, object_list: false,
            clutter_preview_enabled: false,
            clutter_native_mode: true,
            clutter_brush_enabled: false,
            clutter_brush_action: 0,
            clutter_auto_refresh: true,
            clutter_preview_request: 0,
            clutter_model_path: String::new(),
            clutter_layer: 0,
            clutter_selector: 0,
            clutter_density: 24,
            clutter_instance_limit: 2048,
            clutter_view_distance: 180.0,
            clutter_lod_distance: 90.0,
            clutter_wind_enabled: true,
            clutter_wind_strength: 0.13,
            clutter_wind_speed: 1.5,
            clutter_wind_direction: Vec2::new(0.8,0.6),
            zone_panel: false,
            grid: false, palette_index: 0, texture_index: 0,
            tint: terrain_splat::TintSettings::default(),
            search: String::new(),
            status: "WildStar Genesis World Editor".to_string(),
            raw_view: true,
            open_area_dialog: false,
            new_area_dialog: false,
            new_area_options: new_area::Options::default(),
            open_area_path_dialog: false,
            open_model_dialog: false,
            pending_model_load: None,
            open_zone_dialog: false,
            change_client_root: false,
            area_path: String::new(),
            pending_load: None,
            area_inspector: false,
            selected_cell: 0,
            weight_research_report: None,
            dock_visible: true,
            floating_mode: false,
            bottom_visible: true,
            toolbars_visible: true,
            ui_zoom: 1.0,
            dock_tab: 0,
            bottom_tab: 0,
            time_of_day: 12.0,
            shadow_preview_enabled: false,
            ambient_light_scale: 1.0,
            sun_light_scale: 1.0,
            terrain_view: 5,
            area_standalone: true,
            terrain_save_dialog: false,
            terrain_bundle_dialog: false,
            terrain_undo_request: false,
            terrain_redo_request: false,
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
    preview_model: Option<String>,
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
            self.pitch.clamp(-1.52, 1.52)
        } else {
            self.pitch.clamp(0.05, 1.50)
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
        Projection::Perspective(PerspectiveProjection {
            near: 0.5,
            far: 50_000.0,
            ..default()
        }),
        DistanceFog {
            color: Color::srgb(0.7, 0.8, 0.9),
            falloff: FogFalloff::Linear {
                start: 100.0,
                end: 2000.0,
            },
            ..default()
        },
        Camera {
            order: 0,
            clear_color: ClearColorConfig::Custom(Color::srgb(0.15, 0.2, 0.3)),
            ..default()
        },
        Transform::from_xyz(450.,500.,550.).looking_at(Vec3::ZERO,Vec3::Y),
    ));
    commands.spawn((
        sky::GenesisSun,
        DirectionalLight {
            illuminance: 8500.0,
            shadow_maps_enabled: false,
            ..default()
        },
        Transform::from_xyz(100.,650.,150.).looking_at(Vec3::ZERO,Vec3::Y),
        // Three cascades cover near props and terrain without drawing
        // a single wastefully huge shadow map over streamed zones.
        CascadeShadowConfigBuilder {
            num_cascades: 3,
            first_cascade_far_bound: 96.0,
            maximum_distance: 600.0,
            ..default()
        }.build(),
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
    // Normal editor startup never prompts for ClientData. A saved client
    // root still indexes automatically; optional setup lives under Settings.

}
fn load_raw_area(
    mut state: ResMut<GenesisState>,
    mut edit: ResMut<terrain_edit::TerrainEdit>,
    mut paint: ResMut<terrain_paint::TerrainPaint>,
    mut clutter_paint: ResMut<clutter_paint::ClutterPaint>,
    mut viewer: ResMut<prop_viewer::PropViewer>,
    client: Res<client_data::ClientFiles>,
    mut loaded: ResMut<LoadedArea>,
    mut orbit: ResMut<OrbitCamera>,
    mut streaming: ResMut<streaming::WorldStreaming>,
    mut sky_mgr: ResMut<sky::SkyManager>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut layered_materials: ResMut<Assets<m3_layers::M3LayerMaterial>>,
    mut terrain_materials: ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mut images: ResMut<Assets<Image>>,
) {
    // Standalone .area terrain is decoded without ClientData; referenced
    // WorldLayers, textures and props are only resolved when an index exists.
    let Some(path)=state.pending_load.take() else {return;};
    sky_mgr.current_sky_id = None;
    let path_buf = Path::new(&path);
    let tile_coords = ZoneTileCoords::from_path_or_name(&path);

    // If this file belongs to a known Map folder, initiate WorldStreaming focused on this tile
    let is_map_folder = path_buf.parent().and_then(|p| {
        p.file_name().and_then(|n| n.to_str()).map(|name| (p, name.to_string()))
    });

    let mut is_streaming = false;
    if !state.area_standalone { if let Some((parent, map_name)) = is_map_folder {
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
    }}

    match area::RawArea::from_path(Path::new(&path)) {
        Ok(tile)=>{
            paint.reset();
            clutter_paint.reset();
            state.weight_research_report=None;
            loaded.preview_model=None;
            viewer.clear_preview();
            if !is_streaming {
                streaming.clear_all(&mut commands);
                streaming.active_map = None;
                streaming.camera_tile = None;
            }
            let water_bodies=tile.all_water_bodies();
            loaded.water_count=water_bodies.len();
            let decoded_props=tile.prop_placements();
            loaded.prop_issue=decoded_props.as_ref().err().cloned();
            loaded.props=decoded_props.unwrap_or_default();
            loaded.tile=Some(tile.clone());

            // Verify tile coordinates against props if available so terrain and props never desync
            let prop_tile = loaded.props.first().map(|pr| {
                ZoneTileCoords::from_world_pos(pr.position_xyz[0], pr.position_xyz[2])
            });
            let effective_coords = match (tile_coords, prop_tile) {
                (Some(tc), Some(pt)) if tc.chebyshev_distance(&pt) <= 2 => Some(tc),
                (_, Some(pt)) => Some(pt),
                (Some(tc), None) => Some(tc),
                (None, None) => None,
            };
            let world_center = effective_coords
                .map(|c| c.world_center())
                .unwrap_or([0.0, 0.0, 0.0]);

            if is_streaming { edit.reset();clutter_paint.reset(); } else {
                let origin=Vec2::new(world_center[0], world_center[2]);
                edit.load(Path::new(&path), &tile, origin);
                clutter_paint.load(Path::new(&path),&tile,origin);
            }
            let preview=if state.terrain_view==5 && loaded.terrain_albedo.is_none(){
                1
            }else{state.terrain_view};

            match terrain::terrain_mesh(&tile,preview,state.texture_index) {
                Ok((mesh,focus))=>{
                    // Frame the full AREA on every load. An old FPS yaw/pitch
                    // can otherwise aim the 3D camera completely away from the
                    // new flat tile even though the file and mesh are valid.
                    orbit.focus = Vec3::new(world_center[0], focus.y, world_center[2]);
                    orbit.is_first_person = false;
                    orbit.yaw = 0.25;
                    orbit.pitch = 0.75;
                    orbit.distance = 890.0;
                    orbit.eye = orbit.focus + Vec3::new(161.0, 607.0, 631.0);
                    state.raw_view = true;

                    // Despawn any standalone entities
                    if let Some(old)=loaded.mesh_entity.take(){
                        if let Ok(mut ent) = commands.get_entity(old) { ent.despawn(); }
                    }
                    if let Some(old_water)=loaded.water_entity.take(){
                        if let Ok(mut ent) = commands.get_entity(old_water) { ent.despawn(); }
                    }
                    for old_prop in loaded.prop_entities.drain(..) {
                        if let Ok(mut ent) = commands.get_entity(old_prop) { ent.despawn(); }
                    }

                    if is_streaming {
                        // WorldStreaming is actively streaming around camera focus!
                        state.status = format!(
                            "Streaming zone around tile {} | {} cells | {} props | {}",
                            effective_coords.map(|c| c.to_hex()).unwrap_or_default(),
                            tile.cell_count(), loaded.props.len(), path
                        );
                        state.dock_tab = 6; // World tab with radar
                    } else {
                        // Standalone single-tile mode: spawn terrain at world_center, water and props
                        loaded.terrain_albedo=None;
                        loaded.terrain_splat=false;
                        let mut splat_ext=terrain_splat::fallback_extension(&mut images);
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
                                if let Some(bytes)=data.weights.data.as_deref(){
                                    if let Err(error)=paint.load(&tile,bytes,
                                            Vec2::new(world_center[0],world_center[2])) {
                                        state.status=format!("Texture paint initialization: {error}");
                                    }
                                }
                                if paint.ready() {
                                    if let Some(colors)=data.tint.data.as_deref() {
                                        if let Err(error)=paint.load_colors(colors,&tile){
                                            state.status=format!("Terrain color initialization: {error}");
                                        }
                                    }
                                }
                                splat_ext=data.into_extension(&mut images,state.terrain_view==5);
                                state.tint.configure_params(&mut splat_ext.params);
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

                        // No ClientData or WorldLayer textures? Render the
                        // actual terrain mesh with an unlit vertex-colour
                        // StandardMaterial, bypassing custom WESL splatting.
                        // This keeps a new AREA clearly visible while offline.
                        let mesh_handle=meshes.add(mesh);
                        let transform=Transform::from_xyz(world_center[0],0.0,world_center[2]);
                        if !loaded.terrain_splat && loaded.terrain_albedo.is_none() {
                            loaded.mesh_entity=Some(commands.spawn((
                                Mesh3d(mesh_handle),
                                MeshMaterial3d(materials.add(StandardMaterial{
                                    base_color:Color::WHITE,
                                    unlit:true,
                                    cull_mode:None,
                                    ..default()
                                })),
                                transform,
                            )).id());
                            loaded.layer_status="Terrain-only vertex-colour preview (no WorldLayer textures)".into();
                        } else {
                            loaded.mesh_entity=Some(commands.spawn((
                                Mesh3d(mesh_handle),
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
                                transform,
                            )).id());
                        }

                        if let Some(wmesh)=water::water_mesh(&water_bodies){
                            let water_ent=commands.spawn((
                                water::GenesisWater,
                                Mesh3d(meshes.add(wmesh)),
                                MeshMaterial3d(materials.add(water::water_material())),
                                Transform::default(),
                            )).id();
                            loaded.water_entity=Some(water_ent);
                        }

                        loaded.prop_entities=props::spawn_props(&mut commands, &loaded.props, &mut meshes, &mut materials, &mut layered_materials, &mut images,
                            client.index.as_ref(), &client.prop_models);

                        state.status=format!(
                            "AREA | {} cells | {} props | {} water | {} | {}",
                            tile.cell_count(),loaded.props.len(),loaded.water_count,loaded.layer_status,path
                        );
                        state.dock_tab=8;
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
/// Open a single model in the world viewport independently of an AREA tile.
fn load_model_preview(
    mut state: ResMut<GenesisState>,
    mut edit: ResMut<terrain_edit::TerrainEdit>,
    mut paint: ResMut<terrain_paint::TerrainPaint>,
    mut viewer: ResMut<prop_viewer::PropViewer>,
    client: Res<client_data::ClientFiles>,
    mut loaded: ResMut<LoadedArea>,
    mut orbit: ResMut<OrbitCamera>,
    mut streaming: ResMut<streaming::WorldStreaming>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut layered_materials: ResMut<Assets<m3_layers::M3LayerMaterial>>,
    mut images: ResMut<Assets<Image>>,
) {
    let Some(requested) = state.pending_model_load.take() else { return; };
    let Some(index) = client.index.as_ref() else {
        state.status = "Choose and index the WildStar ClientData root before opening models.".into();
        return;
    };
    let path = Path::new(&requested);
    // Convert the Windows file picker path back to the game's relative virtual path.
    let virtual_path = if index.resolve(&requested).is_some() {
        wildstar_formats::assets::virtual_key(&requested)
    } else {
        let relative = index.roots.as_ref().and_then(|r| {
            path.strip_prefix(&r.client_data).ok()
                .or_else(|| r.client_data_en.as_ref()
                    .and_then(|en| path.strip_prefix(en).ok()))
        });
        let Some(relative) = relative else {
            state.status = "The selected model must be located inside indexed ClientData/ClientDataEN.".into();
            return;
        };
        wildstar_formats::assets::virtual_key(&relative.to_string_lossy())
    };
    if index.resolve(&virtual_path).is_none() {
        state.status = format!("Model not found in the ClientData asset index: {virtual_path}");
        return;
    }
    match props::spawn_model_preview(&mut commands, &mut meshes, &mut materials,
        &mut layered_materials, &mut images, index, &client.prop_models, &virtual_path) {
        Ok(scene) => {
            let min = scene.min;
            let max = scene.max;
            streaming.clear_all(&mut commands);
            streaming.active_map = None;
            streaming.camera_tile = None;
            if let Some(old) = loaded.mesh_entity.take() {
                if let Ok(mut e) = commands.get_entity(old) { e.despawn(); }
            }
            if let Some(old) = loaded.water_entity.take() {
                if let Ok(mut e) = commands.get_entity(old) { e.despawn(); }
            }
            for old in loaded.prop_entities.drain(..) {
                if let Ok(mut e) = commands.get_entity(old) { e.despawn(); }
            }
            loaded.prop_entities = scene.entities.clone();
            edit.reset();
            paint.reset();
            viewer.set_preview(virtual_path.clone(), &scene);
            loaded.tile = None;
            loaded.props.clear();
            loaded.preview_model = Some(virtual_path.clone());
            loaded.terrain_albedo = None;
            loaded.terrain_normal = None;
            loaded.terrain_splat = false;
            let center = (Vec3::from_array(min) + Vec3::from_array(max)) * 0.5;
            let diameter = (Vec3::from_array(max) - Vec3::from_array(min)).length().max(1.0);
            orbit.focus = center;
            orbit.distance = (diameter * 2.0).clamp(3.0, 5000.0);
            orbit.is_first_person = false;
            orbit.eye = center + Vec3::new(0.0, orbit.distance * 0.25, orbit.distance);
            state.raw_view = true;
            state.dock_tab = 10; // Dedicated Prop Viewer
            state.status = format!("MODEL PREVIEW | {virtual_path} | bounds {min:?} .. {max:?}");
        }
        Err(error) => state.status = format!("MODEL: {error} | {virtual_path}"),
    }
}
/// Replace only the mesh asset when an AREA debug-view option changes.
/// Rebuild the standalone AREA mesh after in-memory height edits or Undo/Redo.
/// The raw AREA remains intact until Save As. One asset is replaced, not
/// reloaded from disk, so texture splatting and prop entities remain attached.
fn refresh_edited_terrain(
    state: Res<GenesisState>,
    loaded: Res<LoadedArea>,
    mut edit: ResMut<terrain_edit::TerrainEdit>,
    mut meshes: ResMut<Assets<Mesh>>,
    mesh_entities: Query<&Mesh3d>,
) {
    if !edit.is_ready() || edit.revision == edit.mesh_revision { return; }
    let (Some(area),Some(entity))=(loaded.tile.as_ref(), loaded.mesh_entity) else {return;};
    let Ok(mesh_handle)=mesh_entities.get(entity) else {return;};
    let Some(grid)=edit.grid() else {return;};
    let preview=if state.terrain_view==5 && loaded.terrain_albedo.is_none(){
        1
    }else{state.terrain_view};
    if let Ok((mesh,_))=terrain::terrain_mesh_from_grid(area,preview,state.texture_index,&grid) {
        if let Some(mut asset)=meshes.get_mut(&mesh_handle.0){
            *asset = mesh;
            edit.mesh_revision = edit.revision;
        }
    }
}
/// Upload changed 1024² RGBA8 splat pixels to the standalone terrain material.
fn refresh_painted_splat(
    state: Res<GenesisState>,
    loaded: Res<LoadedArea>,
    client: Res<client_data::ClientFiles>,
    mut paint: ResMut<terrain_paint::TerrainPaint>,
    mut images: ResMut<Assets<Image>>,
    mut materials: ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mesh_materials: Query<&MeshMaterial3d<terrain_splat::TerrainMaterial>>,
    mut last_source: Local<Option<u32>>,
    mut last_entity: Local<Option<Entity>>,
) {
    if !paint.ready() || !loaded.terrain_splat {return;}
    let (Some(source),Some(entity))=(loaded.tile.as_ref(),loaded.mesh_entity) else{return;};
    if paint.revision==paint.gpu_revision && !paint.rebuild_pending &&
        *last_source==Some(state.tint.color_source) && *last_entity==Some(entity) {
        return;
    }
    let Ok(component)=mesh_materials.get(entity) else{return;};
    let Some(mut material)=materials.get_mut(&component.0) else{return;};
    if paint.rebuild_pending {
        let Some(index)=client.index.as_ref() else{return;};
        let preview=paint.preview_area(source);
        match terrain_material::bake(&preview,index) {
            Ok(mut atlas)=>{
                let Some(mut data)=atlas.splat.take() else{
                    paint.error="Rebake failed: no runtime splat available".into();
                    return;
                };
                data.weights.data=Some(paint.weights.clone());
                if paint.colors_ready(){
                    data.tint.data=Some(paint.render_tint(state.tint.color_source));
                }
                material.extension=data.into_extension(&mut images,state.terrain_view==5);
                state.tint.configure_params(&mut material.extension.params);
                paint.rebuild_pending=false;
                paint.gpu_revision=paint.revision;
                paint.error.clear();
            }
            Err(err)=>{paint.error=format!("WorldLayer preview rebuild failed: {err}");}
        }
    }else{
        let mut uploaded=false;
        if let Some(handle)=material.extension.weights.as_ref(){
            if let Some(mut image)=images.get_mut(handle){
                image.data=Some(paint.weights.clone());
                uploaded=true;
            }
        }
        if paint.colors_ready(){
            if let Some(handle)=material.extension.tint.as_ref(){
                if let Some(mut image)=images.get_mut(handle){
                    image.data=Some(paint.render_tint(state.tint.color_source));
                }else{uploaded=false;}
            }else{uploaded=false;}
        }
        if uploaded{paint.gpu_revision=paint.revision;}
    }
    *last_source=Some(state.tint.color_source);
    *last_entity=Some(entity);
}
/// Push the macro tint settings to every terrain material (single tile and streamed tiles).
fn apply_tint_settings(
    state:Res<GenesisState>,
    mut materials:ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mut last:Local<Option<terrain_splat::TintSettings>>,
    mut known:Local<usize>,
){
    // Also re-apply when new tiles were added, so they pick up the current settings.
    let count=materials.len();
    if *last==Some(state.tint) && *known==count{return;}
    *last=Some(state.tint);
    *known=count;
    state.tint.apply(&mut materials);
}
fn refresh_terrain_view(
    state:Res<GenesisState>,
    edit: Res<terrain_edit::TerrainEdit>,
    mut loaded:ResMut<LoadedArea>,
    mut meshes:ResMut<Assets<Mesh>>,
    mut materials:ResMut<Assets<terrain_splat::TerrainMaterial>>,
    mut mesh_components:Query<&mut Mesh3d>,
    terrain_material_query:Query<&MeshMaterial3d<terrain_splat::TerrainMaterial>>,
){
    let target=(state.terrain_view,state.texture_index);
    if loaded.last_preview==target{return;}
    let Some(tile)=loaded.tile.as_ref() else{return;};
    let Some(entity)=loaded.mesh_entity else{return;};
    let preview=if target.0==5 && loaded.terrain_albedo.is_none(){1}else{target.0};
    let Ok((mesh,_))=(if let Some(grid)=edit.grid() {
        terrain::terrain_mesh_from_grid(tile,preview,target.1,&grid)
    } else {
        terrain::terrain_mesh(tile,preview,target.1)
    }) else{return;};
    if let Ok(mut component)=mesh_components.get_mut(entity) {
        // Both the layered PBR terrain and the offline StandardMaterial
        // fallback have Mesh3d, so debug views must work on either.
        if let Ok(material)=terrain_material_query.get(entity) {
            if let Some(terrain)=materials.get_mut(&material.0){
                let textured=target.0==5;
                terrain.extension.params.enabled=(textured && loaded.terrain_splat) as u32;
                terrain.base.base_color_texture=if textured && !loaded.terrain_splat{
                    loaded.terrain_albedo.clone()
                }else{None};
                terrain.base.normal_map_texture=if textured && !loaded.terrain_splat{
                    loaded.terrain_normal.clone()
                }else{None};
            }
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
        let up = if forward.dot(Vec3::Y).abs() > 0.98 { Vec3::Z } else { Vec3::Y };
        *transform = Transform::from_translation(orbit.eye)
            .looking_at(orbit.eye + forward, up);
    } else {
        let p = orbit.pitch.clamp(0.05, 1.50);
        let direction = Vec3::new(orbit.yaw.sin() * p.cos(), p.sin(), orbit.yaw.cos() * p.cos());
        let norm_dir = direction.normalize_or_zero();
        let up = if norm_dir.dot(Vec3::Y).abs() > 0.98 { Vec3::Z } else { Vec3::Y };
        *transform = Transform::from_translation(orbit.focus + direction * orbit.distance)
            .looking_at(orbit.focus, up);
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
    if let (Some(out),Some(model))=(std::env::var_os("GENESIS_PROP_DEMO"),std::env::var_os("GENESIS_PROP_MODEL")){
        splat_demo::run_prop(model.to_string_lossy().into_owned(),out.to_string_lossy().into_owned());
        return;
    }
    if let Some(out)=std::env::var_os("GENESIS_SPLAT_DEMO"){
        splat_demo::run(out.to_string_lossy().into_owned());
        return;
    }
    std::panic::set_hook(Box::new(|panic_info| {
        let msg = format!("Genesis Crash Panic:\n{panic_info}\n");
        eprintln!("{msg}");
        let _ = std::fs::write("genesis_crash.log", msg);
    }));
    App::new()
        .insert_resource(GenesisState::default())
        .insert_resource(LoadedArea::default())
        .insert_resource(clutter::ClutterPreview::default())
        .insert_resource(clutter_paint::ClutterPaint::default())
        .insert_resource(terrain_edit::TerrainEdit::default())
        .insert_resource(terrain_paint::TerrainPaint::default())
        .insert_resource(OrbitCamera::default())
        .insert_resource(client_data::ClientFiles::default())
        .insert_resource(prop_viewer::PropViewer::default())
        .insert_resource(streaming::WorldStreaming::default())
        .init_resource::<sky::SkyManager>()
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
        .add_plugins(m3_layers::M3LayerPlugin)
        .add_plugins(MaterialPlugin::<clutter_wind::WindMaterial>::default())
        .insert_resource(clutter_wind::WindMaterialCache::default())
        .add_systems(Startup, setup_scene)
        .add_systems(Update, (client_data::poll_system, load_raw_area, load_model_preview,
            prop_viewer::update,
            streaming::update_world_streaming,
            update_camera, refresh_edited_terrain, clutter::update_preview, refresh_painted_splat,
            refresh_terrain_view, apply_tint_settings, sky::update_sky_lighting, sky::update_skybox_position, sky::update_skybox_celestials, sky::update_camera_fog, water::update_water_color).chain())
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
             mut edit: ResMut<terrain_edit::TerrainEdit>,
             mut paint: ResMut<terrain_paint::TerrainPaint>,
             mut clutter_paint: ResMut<clutter_paint::ClutterPaint>,
             camera_query: Query<(&Camera,&GlobalTransform),With<GenesisCamera>>,
             mut previews: Local<Viewports>, mut initialized: Local<bool>,
             mut orbit: ResMut<OrbitCamera>, mut loaded: ResMut<LoadedArea>,
             mut streaming: ResMut<streaming::WorldStreaming>,
             sky_mgr: Res<sky::SkyManager>,
             mut commands: Commands,
             mut client: ResMut<client_data::ClientFiles>,
             mut viewer: ResMut<prop_viewer::PropViewer>,
             clutter_preview: Res<clutter::ClutterPreview>) -> Result {
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
                    dock_panels(ui, &mut state, &loaded, &client, paint.as_mut(), clutter_paint.as_mut(), viewer.as_mut(), streaming.as_mut(), orbit.as_mut(), &sky_mgr, &clutter_preview, &mut commands);
                }
                viewport(ui, &mut state, &previews, orbit.as_mut(), &loaded, streaming.as_ref(), &sky_mgr,
                    edit.as_mut(), paint.as_mut(), clutter_paint.as_mut(), &camera_query);
            });
        });
    // Keyboard undo/redo when no text editor is focused.
    if !ctx.egui_wants_keyboard_input() {
        let (undo,redo)=ctx.input(|i|(
            i.modifiers.command && i.key_pressed(egui::Key::Z) && !i.modifiers.shift,
            (i.modifiers.command && i.key_pressed(egui::Key::Y)) ||
            (i.modifiers.command && i.modifiers.shift && i.key_pressed(egui::Key::Z)),
        ));
        state.terrain_undo_request |= undo;
        state.terrain_redo_request |= redo;
    }
    if state.terrain_undo_request {
        state.terrain_undo_request=false;
        state.status=if state.dock_tab==1 && (state.paint_tool=="Texture Brush" || state.paint_tool=="Color Brush") {
            if paint.undo(){"Texture Undo".into()}else{"Nothing to undo".into()}
        }else if state.dock_tab==2 && state.clutter_brush_enabled{
            if clutter_paint.undo(){"Clutter Undo".into()}else{"Nothing to undo".into()}
        }else if edit.undo(){"Height Undo".into()}else{"Nothing to undo".into()};
    }
    if state.terrain_redo_request {
        state.terrain_redo_request=false;
        state.status=if state.dock_tab==1 && (state.paint_tool=="Texture Brush" || state.paint_tool=="Color Brush") {
            if paint.redo(){"Texture Redo".into()}else{"Nothing to redo".into()}
        }else if state.dock_tab==2 && state.clutter_brush_enabled{
            if clutter_paint.redo(){"Clutter Redo".into()}else{"Nothing to redo".into()}
        }else if edit.redo(){"Height Redo".into()}else{"Nothing to redo".into()};
    }
    if state.terrain_save_dialog {
        state.terrain_save_dialog = false;
        if let (Some(area),Some(source))=(loaded.tile.as_ref(),edit.source.as_ref()) {
            let suggested=source.file_stem().and_then(|s|s.to_str()).unwrap_or("terrain");
            let mut picker=rfd::FileDialog::new()
                .set_title("Export edited WildStar AREA (never overwrites originals)")
                .add_filter("WildStar AREA", &["area"])
                .set_file_name(format!("{suggested}_edited.area"));
            if let Some(parent)=source.parent(){picker=picker.set_directory(parent);}
            if let Some(out)=picker.save_file(){
                if clutter_paint.dirty(){
                    let heights=edit.changes();
                    state.status=match clutter_paint.export_as(
                        area,paint.as_mut(),&heights,&out
                    ){
                        Ok(edits)=>format!("Saved {} native Clutter edits to {}",
                            edits,out.display()),
                        Err(err)=>format!("Native Clutter export blocked: {err}"),
                    };
                }else if paint.dirty() {
                    let heights=edit.changes();
                    state.status=match paint.save_native_as(area,&heights,&out){
                        Ok((vertices,cells))=>format!(
                            "Saved {vertices} height vertices and {cells} texture cells to {}",
                            out.display()),
                        Err(err)=>format!("AREA texture export blocked: {err}"),
                    };
                }else{
                    state.status=match edit.save_as(area,&out){
                        Ok(vertices)=>format!("Saved {vertices} edited height vertices to {}",out.display()),
                        Err(err)=>format!("AREA save failed: {err}"),
                    };
                }
            }
        } else {
            state.status="Open a standalone AREA before using Save As".into();
        }
    }
    if state.terrain_bundle_dialog {
        state.terrain_bundle_dialog=false;
        if let (Some(area),Some(source))=(loaded.tile.as_ref(),edit.source.as_ref()){
            let mut picker=rfd::FileDialog::new()
                .set_title("Choose a parent folder for a NEW seam-safe AREA bundle");
            if let Some(parent)=source.parent(){picker=picker.set_directory(parent);}
            if let Some(parent)=picker.pick_folder(){
                let heights=edit.changes();
                state.status=match terrain_bundle::export_bundle(
                    paint.as_mut(),clutter_paint.as_ref(),area,source,&heights,&parent,
                ){
                    Ok(paths)=>format!("Exported {} AREA tiles into new isolated bundle: {}",
                        paths.len(),paths.first().and_then(|p|p.parent())
                            .map(|p|p.display().to_string()).unwrap_or_default()),
                    Err(err)=>format!("AREA bundle export blocked: {err}"),
                };
            }
        }else{
            state.status="Open an editable standalone AREA first".into();
        }
    }
    if state.floating_mode { floating_panels(ctx, &mut state); }
    area_inspector_panel(ctx, &mut state, &loaded);
    if state.change_client_root {
        client.settings_open=true;
        state.change_client_root=false;
    }
    let new_path={
        let state_ref=state.as_mut();
        new_area::show(ctx,&mut state_ref.new_area_dialog,&mut state_ref.new_area_options)
    };
    if let Some(path)=new_path{
        state.area_standalone=true;
        state.terrain_view=0; // visible native height preview without ClientData
        state.area_path=path.to_string_lossy().into_owned();
        state.pending_load=Some(state.area_path.clone());
        state.status=format!("Created AREA: {}. Loading terrain...",path.display());
    }
    if state.open_area_dialog {
        // Native file picker works offline, too. Only asset resolution/zone
        // streaming require a configured ClientData root.
        state.open_area_dialog=false;
        if let Some(file)=client.choose_area(&state.area_path) {
            state.area_path=file.to_string_lossy().into_owned();
            state.pending_load=Some(state.area_path.clone());
        }
    }
    if state.open_model_dialog {
        state.open_model_dialog = false;
        if client.ready() {
            let mut picker = rfd::FileDialog::new()
                .set_title("Open WildStar M3/I3 model")
                .add_filter("WildStar models", &["m3", "i3"]);
            if let Some(root) = client.client_data_dir() { picker = picker.set_directory(root); }
            if let Some(file) = picker.pick_file() {
                state.pending_model_load = Some(file.to_string_lossy().into_owned());
            }
        } else {
            client.settings_open = true;
            state.status = "For M3/I3 assets, configure Settings > ClientData Settings...".into();
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
                    state.pending_load=Some(state.area_path.clone());
                    state.open_area_path_dialog=false;
                }
            });
        if !open{state.open_area_path_dialog=false;}
    }
    zone_browser_dialog(ctx, &mut state, streaming.as_mut(), &client, orbit.as_mut(), &mut commands,
        loaded.as_mut(), viewer.as_mut(), edit.as_mut(), paint.as_mut());
    client_data::settings_panel(ctx,&mut client);
    Ok(())
}
fn command(state: &mut GenesisState, name: &'static str) {
    state.active = name;
    state.status = format!("{name}");
    match name {
        "New" | "New AREA..." => {
            state.new_area_dialog=true;
            state.new_area_options.error.clear();
        }
        "Undo" => {state.terrain_undo_request = true;}
        "Redo" => {state.terrain_redo_request = true;}
        "Save" | "Save As" | "Save Package" => {state.terrain_save_dialog = true;}
        "Terrain Sculpt" | "Sculpt" => {
            state.dock_tab = 0;
            state.dock_visible = true;
        }
        "Terrain Paint" | "Paint" => {
            state.dock_tab = 1;
            state.dock_visible = true;
        }
        "Height Brush" | "Smooth" | "Flatten" | "Noise" | "Clone" | "Stamp" => {
            state.sculpt_tool = name;
            state.mode = match name {
                "Smooth" => 1, "Flatten" => 2, "Noise" => 3,
                "Clone" => 4, "Stamp" => 5, _ => 0,
            };
            state.dock_tab = 0;
            state.dock_visible = true;
        }
        "Texture Brush" | "Texture Brush Properties" => {
            state.paint_tool = "Texture Brush";
            state.dock_tab = 1;
            state.dock_visible = true;
        }
        "Color Brush" | "Color Brush Properties" => {
            state.paint_tool = "Color Brush";
            state.dock_tab = 1;
            state.dock_visible = true;
        }
        "Color Palette" => {
            state.paint_tool = "Color Palette";
            state.dock_tab = 1;
            state.dock_visible = true;
        }
        "Clutter" | "Clutter Preset" => {
            state.clutter_panel = true;
            state.dock_tab = 2;
            state.dock_visible = true;
        }
        "Props" | "Prop Models" | "Snap Points Properties" => {
            state.prop_panel = true;
            state.dock_tab = 3;
            state.dock_visible = true;
        }
        "Object List" => {
            state.object_list = true;
            state.dock_tab = 3;
            state.dock_visible = true;
        }
        "Water" | "Simple Water" | "Water Grid" | "Water Sphere" | "Water Grid Outer Edge" => {
            state.dock_tab = 4;
            state.dock_visible = true;
        }
        "Environment" | "Sky" | "Fog" | "Lights" | "Sky Editor" | "Cloud Shadows" | "God Rays" | "FullScreen Effects" => {
            state.dock_tab = 5;
            state.dock_visible = true;
        }
        "World" => {
            state.dock_tab = 6;
            state.dock_visible = true;
        }
        "Zones" | "Named Region Editor" | "Navigation Window" => {
            state.zone_panel = true;
            state.dock_tab = 7;
            state.dock_visible = true;
        }
        "AREA Inspector" | "Chunk Inspector" | "Inspect" => {
            state.area_inspector = true;
            state.dock_tab = 8;
            state.dock_visible = true;
        }
        "Dock Properties" => { state.dock_visible = true; state.floating_mode = false; }
        "Float Properties" => { state.floating_mode = true; state.dock_visible = false; }
        "Hide Properties" => { state.dock_visible = false; state.floating_mode = false; }
        "Bottom Workspace" => state.bottom_visible = !state.bottom_visible,
        "Header Toolbars" => state.toolbars_visible = !state.toolbars_visible,
        "UI 80%" => state.ui_zoom = 0.8,
        "UI 100%" => state.ui_zoom = 1.0,
        "UI 125%" => state.ui_zoom = 1.25,
        "UI 150%" => state.ui_zoom = 1.5,
        "Land Chunk Grid" => state.grid = !state.grid,
        "3D AREA View" => state.raw_view = true,
        "Open Zone..." | "Open Zone (World Streaming)..." => {
            state.open_zone_dialog = true;
        }
        "Open AREA..." => state.open_area_dialog = true,
        "Open Model (.m3/.i3)..." => state.open_model_dialog = true,
        "Prop Viewer" => {
            state.dock_tab = 10;
            state.dock_visible = true;
            state.floating_mode = false;
        },
        "Open AREA by path..." => state.open_area_path_dialog = true,
        "Choose Client Root..." | "ClientData Settings..." => state.change_client_root = true,
        "Grimvault Preview" => { state.scene = 0; state.raw_view = false; }
        "Aurora Preview" => { state.scene = 1; state.raw_view = false; }
        "Blue Forest Preview" => { state.scene = 2; state.raw_view = false; }
        _ => {}
    }
}
fn icon(ui: &mut egui::Ui, state: &mut GenesisState, name: &'static str) {
    let (rect, response) = ui.allocate_exact_size(egui::vec2(26.0, 26.0), egui::Sense::click());
    let selected = state.active == name;
    ui.painter().rect_filled(rect, 0.0, if selected {
        egui::Color32::from_rgb(212, 193, 155)
    } else { PAPER });
    ui.painter().rect_stroke(rect, 0.0, egui::Stroke::new(0.6, EDGE),
                             egui::StrokeKind::Inside);
    genesis_icons::paint(ui, name, rect.shrink(3.3));
    if response.on_hover_text(name).clicked() { command(state, name); }
}
const ICONS: &[&str] = &[
    "Select", "Translate", "Rotate", "Scale", "Terrain Sculpt",
    "Terrain Paint", "Clutter", "Props", "Water", "Environment",
    "Zones", "3D AREA View", "Object List", "AREA Inspector",
];
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
                    ("File",&["New","New AREA...","Open Zone (World Streaming)...","Open AREA...","Open Model (.m3/.i3)...","Open AREA by path...",
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
                    ("Objects",&["Prop Viewer","Prop Models","Prop Interiors","Object List",
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
                        "Object List","Prop Viewer","AREA Inspector","Named Region Editor"][..]),
                    ("Settings",&["ClientData Settings..."][..]),
                    ("Help",&["About Genesis","Keyboard Shortcuts"][..]),
                ] {
                    ui.menu_button(egui::RichText::new(title).size(10.0),|ui| {
                        for &entry in entries {
                            if genesis_icons::menu_item(ui, entry).clicked() {
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
                if ui.add_sized([83.,17.],egui::Button::new("NewCentral").frame(true))
                    .on_hover_text("Create new editable AREA").clicked() {
                    command(state,"New");
                }
                ui.label(egui::RichText::new("Map").size(9.).strong());
                ui.add_sized([52.,17.],egui::Button::new("Area 106").frame(true));
                if ui.button("Open Zone...").clicked() {command(state,"Open Zone...");}
                if ui.button("Open AREA...").clicked() {command(state,"Open AREA...");}
                if ui.button("Open Model...").clicked() {command(state,"Open Model (.m3/.i3)...");}
                if ui.button("Prop Viewer").clicked() {command(state,"Prop Viewer");}
                if ui.button("3D View").clicked() {command(state,"3D AREA View");}
                ui.separator();
                ui.label(egui::RichText::new("Time of Day").size(9.));
                ui.add(egui::Slider::new(&mut state.time_of_day,0.0..=24.0)
                    .show_value(true).custom_formatter(|v,_|format!("{v:04.1}")));
            });
            if !state.toolbars_visible {return;}
            ui.separator();
            egui::ScrollArea::horizontal()
                .id_salt("genesis-icon-toolbar")
                .scroll_bar_visibility(egui::scroll_area::ScrollBarVisibility::AlwaysHidden)
                .show(ui, |ui| {
                    ui.horizontal(|ui| {
                        ui.spacing_mut().item_spacing.x = 2.0;
                        for (i, &name) in ICONS.iter().enumerate() {
                            if matches!(i, 4 | 7 | 11) {
                                ui.separator();
                            }
                            icon(ui, state, name);
                        }
                    });
                });
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

/// Two concentric rings: outer radius and inner full-strength hardness core.
fn paint_brush_rings(ui:&egui::Ui, pointer:egui::Pos2, radius:f32,
                     hardness:f32, tint:egui::Color32){
    ui.painter().circle_stroke(pointer,radius,egui::Stroke::new(1.4,tint));
    let h=hardness.clamp(0.0,1.0);
    if (0.04..=0.96).contains(&h){
        ui.painter().circle_stroke(pointer,radius*h,
            egui::Stroke::new(1.1,egui::Color32::from_rgba_unmultiplied(250,250,250,215)));
    }
}

fn viewport(ui_root:&mut egui::Ui, state:&mut GenesisState,
            previews:&Viewports,orbit:&mut OrbitCamera,loaded:&LoadedArea,
            streaming:&streaming::WorldStreaming,
            sky_mgr:&sky::SkyManager,
            edit:&mut terrain_edit::TerrainEdit,
            paint:&mut terrain_paint::TerrainPaint,
            clutter_paint:&mut clutter_paint::ClutterPaint,
            camera_query:&Query<(&Camera,&GlobalTransform),With<GenesisCamera>>) {
    egui::CentralPanel::default()
        .frame(egui::Frame::default().fill(if state.raw_view {
            egui::Color32::TRANSPARENT
        } else { egui::Color32::from_rgb(37,24,49) }))
        .show(ui_root, |ui| {
            let rect = ui.available_rect_before_wrap();
            if state.raw_view {
                orbit.rect=Some([rect.left(),rect.top(),rect.right(),rect.bottom()]);
                let response=ui.allocate_rect(rect,egui::Sense::click_and_drag());
                if !ui.input(|i| i.pointer.primary_down()) {
                    edit.end_stroke();
                    paint.end();
                    clutter_paint.end();
                }
                if edit.is_ready() && streaming.active_map.is_none() &&
                    state.dock_tab==0 && state.mode<=3 && response.hovered() {
                    if let Some(pointer)=ui.input(|i|i.pointer.interact_pos()) {
                        let (primary,shift,dt)=ui.input(|i|
                            (i.pointer.primary_down(),i.modifiers.shift,i.stable_dt));
                        let physical=(pointer-rect.min)*orbit.ui_pixels_per_point;
                        if let Ok((camera, transform))=camera_query.single() {
                            if let Ok(ray)=camera.viewport_to_world(transform,
                                Vec2::new(physical.x,physical.y)) {
                                if let Some(hit)=edit.raycast(ray) {
                                    let radius=(state.brush_size*10.0).clamp(1.0,50.0);
                                    let mode=match state.mode {
                                        1=>terrain_edit::BrushMode::Smooth,
                                        2=>terrain_edit::BrushMode::Flatten,
                                        3=>terrain_edit::BrushMode::Noise,
                                        _=>terrain_edit::BrushMode::Raise,
                                    };
                                    if primary {
                                        let point=Vec2::new(hit.x,hit.z);
                                        edit.begin_stroke(point);
                                        let signed_power=if shift {-state.power}else{state.power};
                                        edit.brush(point,radius,signed_power,state.hardness,state.falloff,dt,mode);
                                    }
                                    // Screen-space guide; actual brush influence uses metres.
                                    let pixel_radius=(radius /
                                        (orbit.origin()-hit).length().max(1.0) *
                                        rect.height()*1.20).clamp(4.0,160.0);
                                    paint_brush_rings(ui,pointer,pixel_radius,state.hardness,
                                        egui::Color32::from_rgb(250,209,99));
                                }
                            }
                        }
                    }
                }
                if paint.ready() && edit.is_ready() && streaming.active_map.is_none() &&
                    state.dock_tab==1 && (state.paint_tool=="Texture Brush" || state.paint_tool=="Color Brush")
                    && response.hovered() {
                    if let Some(pointer)=ui.input(|i|i.pointer.interact_pos()) {
                        let physical=(pointer-rect.min)*orbit.ui_pixels_per_point;
                        if let Ok((camera,transform))=camera_query.single() {
                            if let Ok(ray)=camera.viewport_to_world(transform,Vec2::new(physical.x,physical.y)) {
                                if let Some(hit)=edit.raycast(ray){
                                    let world=Vec2::new(hit.x,hit.z);
                                    let (primary,dt)=ui.input(|i|(i.pointer.primary_down(),i.stable_dt));
                                    let selected_before=state.selected_cell.min(255);
                                    if !primary{
                                        if let Some(cell)=paint.cell_at(world) {
                                            state.selected_cell=cell;
                                        }
                                    }
                                    let radius=(state.brush_size*10.0).clamp(1.0,50.0);
                                    if primary {
                                        let restricted=if state.restricted{Some(selected_before)}else{None};
                                        if state.paint_tool=="Color Brush"{
                                            if paint.colors_ready(){
                                                paint.begin();
                                                paint.color_brush(world,radius,state.power.abs(),
                                                    state.hardness,state.falloff,dt,restricted);
                                            }
                                        }else if let Some(id)=paint.selected_id{
                                            paint.begin();
                                            paint.brush(world,id,radius,state.power.abs(),
                                                state.hardness,state.falloff,dt,restricted);
                                        }
                                    }
                                    let visual_radius=(radius/(orbit.origin()-hit).length().max(1.0)
                                        *rect.height()*1.20).clamp(4.0,160.0);
                                    paint_brush_rings(ui,pointer,visual_radius,state.hardness,
                                        egui::Color32::from_rgb(110,224,151));
                                }
                            }
                        }
                    }
                }
                if clutter_paint.ready() && edit.is_ready() &&
                    streaming.active_map.is_none() && state.dock_tab==2 &&
                    state.clutter_brush_enabled && response.hovered()
                {
                    if let Some(pointer)=ui.input(|i|i.pointer.interact_pos()){
                        let physical=(pointer-rect.min)*orbit.ui_pixels_per_point;
                        if let Ok((camera,transform))=camera_query.single(){
                            if let Ok(ray)=camera.viewport_to_world(
                                transform,Vec2::new(physical.x,physical.y)
                            ){
                                if let Some(hit)=edit.raycast(ray){
                                    let primary=ui.input(|i|i.pointer.primary_down());
                                    let radius=(state.brush_size*10.0).clamp(1.0,50.0);
                                    if primary{
                                        clutter_paint.begin();
                                        clutter_paint.brush(
                                            Vec2::new(hit.x,hit.z),radius,
                                            state.clutter_layer,state.clutter_selector,
                                            state.clutter_brush_action
                                        );
                                    }
                                    let pixel_radius=(radius/
                                        (orbit.origin()-hit).length().max(1.0)*
                                        rect.height()*1.20).clamp(4.0,160.0);
                                    ui.painter().circle_stroke(pointer,pixel_radius,
                                        egui::Stroke::new(1.5,
                                            egui::Color32::from_rgb(176,232,120)));
                                }
                            }
                        }
                    }
                }
                if response.dragged_by(egui::PointerButton::Secondary) {
                    let delta=ui.input(|i|i.pointer.delta());
                    orbit.yaw -= delta.x * 0.003;
                    if orbit.is_first_person {
                        orbit.pitch = (orbit.pitch - delta.y * 0.003).clamp(-1.52, 1.52);
                    } else {
                        orbit.pitch = (orbit.pitch + delta.y * 0.006).clamp(0.05, 1.50);
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
                    let zone_str = sky_mgr.current_zone_id.map(|z| format!(" | Zone: #{}", z)).unwrap_or_default();
                    let sky_str = sky_mgr.current_sky_path.as_deref().map(|p| {
                        let name = std::path::Path::new(p).file_stem().and_then(|s| s.to_str()).unwrap_or(p);
                        format!(" | Sky: {}", name)
                    }).unwrap_or_default();
                    let overlay = format!(
                        "STREAMING: {} | {}/{} tiles | Origin: [{:.0}, {:.0}, {:.0}] | {}{}{} | Spd: {:.0}m/s",
                        map.name, streaming.loaded_tiles.len(), map.tiles.len(),
                        orbit.origin().x, orbit.origin().y, orbit.origin().z,
                        mode_str, zone_str, sky_str, orbit.fly_speed
                    );
                    let box_rect = egui::Rect::from_min_size(rect.min + egui::vec2(8., 8.),
                        egui::vec2((rect.width() - 16.).clamp(40., 820.), 26.));
                    ui.painter().rect_filled(box_rect, 3.,
                        egui::Color32::from_rgba_unmultiplied(20, 20, 27, 210));
                    ui.painter().text(box_rect.left_center() + egui::vec2(9., 0.),
                        egui::Align2::LEFT_CENTER, overlay,
                        egui::FontId::proportional(11.), egui::Color32::from_rgb(120, 230, 160));
                } else if let Some(model) = loaded.preview_model.as_deref() {
                    let box_rect = egui::Rect::from_min_size(rect.min + egui::vec2(8., 8.),
                        egui::vec2((rect.width() - 16.).clamp(40., 820.), 26.));
                    ui.painter().rect_filled(box_rect, 3.,
                        egui::Color32::from_rgba_unmultiplied(20, 20, 27, 210));
                    ui.painter().text(box_rect.left_center() + egui::vec2(9., 0.),
                        egui::Align2::LEFT_CENTER, format!("MODEL PREVIEW | {model}"),
                        egui::FontId::proportional(11.), egui::Color32::from_rgb(238, 233, 219));
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
const DOCK_TABS: &[&str] = &[
    "Sculpt", "Paint", "Clutter", "Props", "Water", "Env", "World", "Zones", "Inspect", "Assets", "Prop Viewer", "Render"
];

fn dock_panels(
    ui_root: &mut egui::Ui,
    state: &mut GenesisState,
    loaded: &LoadedArea,
    client: &client_data::ClientFiles,
    paint: &mut terrain_paint::TerrainPaint,
    clutter_paint: &mut clutter_paint::ClutterPaint,
    viewer: &mut prop_viewer::PropViewer,
    streaming: &mut streaming::WorldStreaming,
    orbit: &mut OrbitCamera,
    sky_mgr: &sky::SkyManager,
    clutter_preview: &clutter::ClutterPreview,
    commands: &mut Commands,
) {
    if ui_root.available_width() < 610.0 {
        // Keep the entire center visible on small windows. Open floating mode if needed.
        return;
    }
    egui::Panel::right("genesis-properties-dock")
        .resizable(true)
        .default_size(242.0)
        .min_size(190.0).max_size(480.0)
        .frame(panel_frame())
        .show(ui_root, |ui| {
            ui.horizontal_wrapped(|ui| {
                ui.label(egui::RichText::new("Genesis Tools").strong().size(10.5));
                if ui.small_button("Float").clicked() {
                    state.floating_mode = true;
                    state.dock_visible = false;
                }
                if ui.small_button("×").clicked() { state.dock_visible = false; }
            });
            ui.separator();
            ui.horizontal_wrapped(|ui| {
                ui.spacing_mut().item_spacing.x = 2.5;
                for (i, title) in DOCK_TABS.iter().enumerate() {
                    if ui.selectable_label(state.dock_tab == i,
                        egui::RichText::new(*title).size(9.0)).clicked() {
                        state.dock_tab = i;
                    }
                }
            });
            ui.separator();
            egui::ScrollArea::vertical()
                .id_salt("genesis-property-dock-scroll")
                .auto_shrink([false, false])
                .show(ui, |ui| {
                    match state.dock_tab {
                        0 => dock_sculpt(ui, state),
                        1 => dock_paint(ui, state, loaded, client, paint),
                        2 => dock_clutter(ui, state, clutter_paint, clutter_preview),
                        3 => dock_objects(ui, state, loaded, client),
                        4 => dock_water(ui, state, loaded),
                        5 => dock_environment(ui, state, sky_mgr),
                        6 => dock_world(ui, state, loaded, streaming, orbit, commands),
                        7 => dock_zones(ui, state, sky_mgr),
                        8 => dock_area(ui, state, loaded),
                        11 => dock_terrain_render(ui,state,loaded,streaming),
                        10 => {
                            let report = viewer.preview.as_ref().and_then(|preview| {
                                client.index.as_ref().map(|index| {
                                    client.prop_models.report(index, &preview.path)
                                })
                            }).unwrap_or_default();
                            viewer.show(ui, client.index.as_ref(), &report, commands,
                                &mut state.pending_model_load);
                        },
                        _ => {
                            if ui.button("ClientData Settings...").clicked() {
                                command(state, "ClientData Settings...");
                            }
                            client_data::asset_summary(ui, client, loaded.tile.as_ref());
                        }
                    }
                });
        });
}

fn dock_sculpt(ui: &mut egui::Ui, state: &mut GenesisState) {
    ui.label(egui::RichText::new("Terrain Sculpt Properties").strong().size(10.5));
    ui.separator();
    ui.label(egui::RichText::new("Sculpt Tools").strong().size(9.0));
    ui.horizontal_wrapped(|ui| {
        for tool in ["Height Brush", "Smooth", "Flatten", "Noise", "Clone", "Stamp"] {
            let selected = state.sculpt_tool == tool;
            if ui.selectable_label(selected, egui::RichText::new(tool).size(9.0)).clicked() {
                state.sculpt_tool = tool;
                state.status = format!("Sculpt Tool: {tool}");
            }
        }
    });
    ui.separator();
    ui.label(egui::RichText::new(format!("Active Tool: {}", state.sculpt_tool)).strong().size(9.5).color(INK));
    row_slider(ui, "Size", &mut state.brush_size, 0.1..=5.0);
    row_slider(ui, "Power", &mut state.power, -2.0..=2.0);
    row_slider(ui,"Hardness",&mut state.hardness,0.0..=1.0);
    row_slider(ui, "F/O", &mut state.falloff, 0.0..=1.0);
    ui.horizontal_wrapped(|ui| {
        for (i, title) in ["Circle", "Chunk", "Selection"].iter().enumerate() {
            ui.radio_value(&mut state.circle, i, *title);
        }
    });
    ui.checkbox(&mut state.restricted, "Restrict to Selection");
    ui.horizontal(|ui| {
        ui.radio_value(&mut state.custom_tip, false, "Normal Tip");
        ui.radio_value(&mut state.custom_tip, true, "Custom Tip");
    });
    ui.separator();
    ui.label(egui::RichText::new("Sculpt Modes").strong().size(9.0));
    for (i, title) in [
        "Normal (Raise / Lower)", "Smooth", "Flatten to Height",
        "Add Noise", "Clone Height", "Stamp Geometry"
    ].iter().enumerate() {
        ui.radio_value(&mut state.mode, i, *title);
    }
    ui.separator();
    ui.horizontal(|ui| {
        if ui.button("Clear Selection").clicked() { command(state, "Clear Selection"); }
        if ui.button("Invert Brush").clicked() { state.power = -state.power; }
    });
    ui.label(egui::RichText::new("Left drag: sculpt | Shift: reverse height brush").size(8.5).color(INK));
    ui.label("Radius = Size x 10 m. 1 height step = 0.125 m.");
    if state.mode >= 4 {
        ui.colored_label(egui::Color32::DARK_RED,
            "Clone and Stamp are not implemented yet.");
    }
    ui.horizontal(|ui| {
        if ui.button("Undo").clicked(){command(state,"Undo");}
        if ui.button("Redo").clicked(){command(state,"Redo");}
        if ui.button("Save AREA As...").clicked(){command(state,"Save As");}
        if ui.button("Export AREA Bundle...").clicked(){
            state.terrain_bundle_dialog=true;
        }
    });
}

fn dock_paint(ui: &mut egui::Ui, state: &mut GenesisState, loaded: &LoadedArea,
    client: &client_data::ClientFiles, paint: &mut terrain_paint::TerrainPaint) {
    if (state.paint_tool=="Texture Brush" || state.paint_tool=="Color Brush") && paint.ready() {state.terrain_view=5;}
    ui.horizontal(|ui|{
        ui.label(egui::RichText::new("Terrain Paint Properties").strong().size(10.5));
        if ui.small_button("Render Options").clicked(){state.dock_tab=11;}
    });
    ui.separator();
    ui.label(egui::RichText::new("Paint Tools").strong().size(9.0));
    ui.horizontal_wrapped(|ui| {
        for tool in ["Texture Brush", "Color Brush", "Color Palette"] {
            let selected = state.paint_tool == tool;
            if ui.selectable_label(selected, egui::RichText::new(tool).size(9.0)).clicked() {
                state.paint_tool = tool;
                state.status = format!("Paint Tool: {tool}");
            }
        }
    });
    ui.separator();
    if let Some(area)=loaded.tile.as_ref(){
        ui.collapsing("Native AREA Format Status",|ui|{
            let cells=area.cells.iter().flatten().count();
            let mut native_weight=0usize;
            let mut unknown_companion=0usize;
            let mut color=0usize;
            let mut bc2=0usize;
            for cell in area.cells.iter().flatten(){
                let uncertain=cell.block(19).is_some()||cell.block(20).is_some();
                if uncertain{unknown_companion+=1;}
                if !uncertain && (cell.block(2).is_some()||
                    cell.block(29).is_some()||cell.block(17).is_some()){
                    native_weight+=1;
                }
                if cell.block(3).is_some() || cell.block(13).is_some(){color+=1;}
                if cell.block(13).is_some(){bc2+=1;}
            }
            ui.label(format!("Cells: {cells} | Writable weights: {native_weight}"));
            ui.label(format!("Unresolved 19/20 companions: {unknown_companion}"));
            ui.label(format!("Writable macro-color cells: {color} (BC2: {bc2})"));
            if let Some(cell)=area.cells.get(state.selected_cell.min(255))
                .and_then(Option::as_ref){
                let blocks=[1usize,2,3,13,17,18,19,20,29];
                let present=blocks.iter().filter(|&&bit|cell.block(bit).is_some())
                    .map(|bit|bit.to_string()).collect::<Vec<_>>().join(", ");
                ui.label(format!("Selected cell {}: bits [{}]",cell.index,present));
                let weight_blocked=cell.block(19).is_some()||
                    cell.block(20).is_some();
                if weight_blocked{
                    ui.colored_label(egui::Color32::DARK_RED,
                        "Weight export blocked here: bit 19/20 not decoded.");
                }
                if cell.block(3).is_none() && cell.block(13).is_none(){
                    ui.label("No native RGB color attributes for this cell.");
                }
            }
        });
    }
    match state.paint_tool {
        "Texture Brush" => {
            ui.label(egui::RichText::new("Texture Layer Splatting").strong().size(9.5).color(INK));
            row_slider(ui, "Size", &mut state.brush_size, 0.01..=5.0);
            row_slider(ui, "Power", &mut state.power, 0.0..=2.0);
            row_slider(ui,"Hardness",&mut state.hardness,0.0..=1.0);
            row_slider(ui, "F/O", &mut state.falloff, 0.0..=1.0);
            ui.separator();
            paint.browser(ui,client,state.selected_cell,&mut state.texture_index);
            ui.horizontal(|ui|{
                if ui.button("Undo Paint").clicked() {
                    state.status=if paint.undo(){"Texture Undo".into()}else{"Nothing to undo".into()};
                }
                if ui.button("Redo Paint").clicked() {
                    state.status=if paint.redo(){"Texture Redo".into()}else{"Nothing to redo".into()};
                }
            });
            ui.checkbox(&mut state.restricted, "Restrict to Selection");
            ui.separator();
            ui.label(egui::RichText::new("Macro Tint & Blending").strong().size(9.0));
            ui.horizontal(|ui| {
                ui.label("Macro tint");
                ui.add(egui::Slider::new(&mut state.tint.strength, 0.0..=1.0));
            });
            ui.checkbox(&mut state.tint.gamma_space, "Tint in gamma space");
            ui.label(egui::RichText::new(&loaded.layer_status).small().strong());
            if loaded.terrain_albedo.is_none() {
                ui.colored_label(egui::Color32::DARK_RED, "No texture atlas: showing RGB565 fallback.");
            }
            if !loaded.missing_textures.is_empty() {
                ui.collapsing(format!("Missing textures ({})", loaded.missing_textures.len()), |ui| {
                    for issue in loaded.missing_textures.iter().take(20) {
                        ui.monospace(issue);
                    }
                });
            }
        }
        "Color Brush" => {
            ui.label(egui::RichText::new("Color Brush Properties").strong().size(9.5).color(INK));
            row_slider(ui, "Size", &mut state.brush_size, 0.01..=5.0);
            row_slider(ui, "Power", &mut state.power, 0.0..=2.0);
            row_slider(ui,"Hardness",&mut state.hardness,0.0..=1.0);
            row_slider(ui, "F/O", &mut state.falloff, 0.0..=1.0);
            ui.horizontal(|ui|{
                ui.label("RGB Brush");
                ui.color_edit_button_srgb(&mut paint.color);
            });
            ui.horizontal_wrapped(|ui|{
                ui.radio_value(&mut paint.color_mode,terrain_paint::ColorMode::Color,"Color");
                ui.radio_value(&mut paint.color_mode,terrain_paint::ColorMode::Darken,"Darken");
                ui.radio_value(&mut paint.color_mode,terrain_paint::ColorMode::Lighten,"Lighten");
                ui.radio_value(&mut paint.color_mode,terrain_paint::ColorMode::Smooth,"Smooth");
            });
            ui.checkbox(&mut state.restricted,"Restrict to Selection");
            ui.label("Color edits native RGB565 / BC2 only; BC2 alpha stays unchanged.");
            ui.label(format!("Tint map: {}",if paint.colors_ready(){"ready"}else{"unavailable"}));
            ui.horizontal(|ui|{
                if ui.button("Undo Color").clicked(){
                    state.status=if paint.undo(){"Paint Undo".into()}else{"Nothing to undo".into()};
                }
                if ui.button("Redo Color").clicked(){
                    state.status=if paint.redo(){"Paint Redo".into()}else{"Nothing to redo".into()};
                }
            });
            if !paint.error.is_empty(){ui.colored_label(egui::Color32::DARK_RED,&paint.error);}
            ui.label("Save AREA As exports supported RGB changes into a new AREA.");
        }
        "Color Palette" => {
            dock_palette(ui, state);
        }
        _ => {}
    }
    ui.separator();
    if ui.button("Export AREA Bundle (sync neighbour borders)...").clicked(){
        state.terrain_bundle_dialog=true;
    }
    ui.label("Creates a NEW folder. Never overwrites original AREA files.");
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
fn dock_clutter(ui:&mut egui::Ui,state:&mut GenesisState,
    clutter_paint:&mut clutter_paint::ClutterPaint,
    preview:&clutter::ClutterPreview)
{
    ui.label(egui::RichText::new("Clutter GPU Instancing").strong());
    ui.label("Native: WorldLayer.tbl → WorldClutter.tbl → weighted M3 models.");
    ui.label("AREA Bit27 selects presets; Bit16 suppresses clutter.");
    ui.separator();
    ui.checkbox(&mut state.clutter_native_mode,"Native TBL-driven placement");
    if !state.clutter_native_mode{
        ui.label("Manual diagnostic M3 path");
        ui.add(egui::TextEdit::singleline(&mut state.clutter_model_path)
            .hint_text("Art/..../GroundPlant.m3"));
        ui.horizontal(|ui|{
            ui.label("WorldLayer slot");
            ui.add(egui::DragValue::new(&mut state.clutter_layer).range(0..=3));
        });
        ui.horizontal(|ui|{
            ui.label("Bit27 preset");
            ui.add(egui::DragValue::new(&mut state.clutter_selector).range(0..=3));
        });
    }
    ui.separator();
    ui.checkbox(&mut state.clutter_auto_refresh,
        "Auto-regenerate after Terrain/Clutter edits");
    ui.checkbox(&mut state.clutter_brush_enabled,
        "Paint native AREA Clutter data");
    if state.clutter_brush_enabled{
        ui.horizontal_wrapped(|ui|{
            ui.label("Brush mode");
            ui.selectable_value(&mut state.clutter_brush_action,0,"Preset");
            ui.selectable_value(&mut state.clutter_brush_action,1,"Exclude");
            ui.selectable_value(&mut state.clutter_brush_action,2,"Restore");
        });
        ui.horizontal(|ui|{
            ui.label("WorldLayer slot");
            ui.add(egui::DragValue::new(&mut state.clutter_layer).range(0..=3));
        });
        ui.horizontal(|ui|{
            ui.label("Preset 0-3");
            ui.add(egui::DragValue::new(&mut state.clutter_selector).range(0..=3));
        });
        ui.add(egui::Slider::new(&mut state.brush_size,0.1..=5.0)
            .text("Brush radius"));
        ui.horizontal(|ui|{
            if ui.button("Undo Clutter").clicked(){
                state.status=if clutter_paint.undo(){"Clutter Undo".into()}
                    else{"Nothing to undo".into()};
            }
            if ui.button("Redo Clutter").clicked(){
                state.status=if clutter_paint.redo(){"Clutter Redo".into()}
                    else{"Nothing to redo".into()};
            }
        });
        ui.label(if clutter_paint.dirty(){
            "Native Clutter edits: UNSAVED"
        }else{"Native Clutter edits: none"});
        if ui.button("Save AREA As...").clicked(){
            state.terrain_save_dialog=true;
        }
        if ui.button("Export AREA Bundle...").clicked(){
            state.terrain_bundle_dialog=true;
        }
        ui.small("Preset modifies only one Bit27 two-bit slot; Exclude/Restore toggles only Bit16 0x20. Originals remain read-only.");
    }
    ui.label("Candidates per cell");
    ui.add(egui::Slider::new(&mut state.clutter_density,0..=128));
    ui.label("Maximum instances");
    ui.add(egui::Slider::new(&mut state.clutter_instance_limit,0..=8192));
    ui.label("Group view distance (m)");
    if ui.add(egui::Slider::new(&mut state.clutter_view_distance,32.0..=1024.0))
        .changed() && state.clutter_preview_enabled {
        state.clutter_preview_request=state.clutter_preview_request.wrapping_add(1);
    }
    ui.label("Secondary M3 parts disappear after distance (m)");
    if ui.add(egui::Slider::new(&mut state.clutter_lod_distance,8.0..=512.0))
        .changed() && state.clutter_preview_enabled {
        state.clutter_preview_request=state.clutter_preview_request.wrapping_add(1);
    }
    ui.separator();
    if ui.checkbox(&mut state.clutter_wind_enabled,
        "GPU Wind (vegetation only)").changed() &&
        state.clutter_preview_enabled {
        state.clutter_preview_request=state.clutter_preview_request.wrapping_add(1);
    }
    if state.clutter_wind_enabled {
        ui.add(egui::Slider::new(&mut state.clutter_wind_strength,0.0..=1.2)
            .text("Wind displacement (m)"));
        ui.add(egui::Slider::new(&mut state.clutter_wind_speed,0.0..=5.0)
            .text("Wind frequency"));
        ui.horizontal(|ui|{
            ui.label("Wind direction");
            ui.add(egui::DragValue::new(&mut state.clutter_wind_direction.x)
                .speed(0.05).range(-1.0..=1.0));
            ui.add(egui::DragValue::new(&mut state.clutter_wind_direction.y)
                .speed(0.05).range(-1.0..=1.0));
        });
    }
    ui.small("Bevy automatic instancing + GPU vertex wind. LOD is per M3 part (not simplified geometry). Actual draw calls require GPU profiling.");
    ui.horizontal(|ui|{
        if ui.button(if state.clutter_native_mode {"Build Native Instanced Clutter"}
            else {"Build Manual Instanced Preview"}).clicked(){
            state.clutter_preview_enabled=true;
            state.clutter_preview_request=state.clutter_preview_request.wrapping_add(1);
        }
        if ui.button("Clear").clicked(){
            state.clutter_preview_enabled=false;
            state.clutter_preview_request=state.clutter_preview_request.wrapping_add(1);
        }
    });
    ui.separator();
    ui.label(format!("Instances: {} | Mesh parts/instance: {}",
        preview.instances,preview.parts_per_instance));
    ui.label(format!(
        "CPU cells regenerated: {} / 256 | GPU instanced groups rebuilt: {} | retained: {} | new instances: {}",
        preview.cpu_recalculated_cells,preview.rebuilt_cells,
        preview.retained_cells,preview.last_spawned
    ));
    ui.label(format!("Opaque/masked parts: {} | transparent excluded: {}",
        preview.opaque_parts,preview.transparent_parts));
    ui.label(format!("Rejected: no-clutter {}, selector {}, weights {}, slope {}",
        preview.rejected_by_mask,preview.rejected_by_selector,
        preview.rejected_by_weight,preview.rejected_by_slope));
    ui.label(&preview.status);
    ui.small("Native TBL values drive model selection. Placement RNG and density are preview approximations; final draw calls require GPU profiling.");
}
fn dock_objects(ui:&mut egui::Ui,state:&mut GenesisState,loaded:&LoadedArea,
                client:&client_data::ClientFiles) {
    ui.label(egui::RichText::new("Object List / Snap Points").strong().size(10.));
    if let Some(path) = loaded.preview_model.as_deref() {
        ui.collapsing(format!("Open model: {path}"), |ui| {
            if let Some(index) = client.index.as_ref() {
                for line in client.prop_models.report(index, path) { ui.monospace(line); }
            }
        });
    }
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
                        if ui.button("View model separately").clicked() {
                            state.pending_model_load = Some(path.to_owned());
                            state.dock_tab = 10;
                        }
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

/// Diagnostic and artistic render controls; does not mutate native AREA blocks.
fn dock_terrain_render(
    ui:&mut egui::Ui,
    state:&mut GenesisState,
    loaded:&LoadedArea,
    streaming:&streaming::WorldStreaming,
){
    ui.label(egui::RichText::new("Terrain Render Options").strong().size(10.5));
    if state.terrain_view!=5 && loaded.terrain_splat {
        if ui.button("Activate Textured Terrain").clicked(){state.terrain_view=5;}
    }
    if !loaded.terrain_splat && streaming.active_map.is_none(){
        ui.colored_label(egui::Color32::DARK_RED,
            "Load a standalone AREA with decoded WorldLayer textures first.");
    }
    ui.separator();
    ui.label(egui::RichText::new("Macro Color Source (standalone AREA)").strong());
    let options=["Auto (Bit 3, fallback 13)","Bit 3 RGB565 only","Bit 13 BC2/DXT3 only"];
    ui.horizontal_wrapped(|ui|{
        for (id,label) in options.iter().enumerate(){
            ui.radio_value(&mut state.tint.color_source,id as u32,*label);
        }
    });
    if streaming.active_map.is_some(){
        ui.label("Source selection currently affects standalone AREA tiles only.");
    }
    if let Some(area)=loaded.tile.as_ref(){
        let (mut bit3,mut bit13,mut both)=(0usize,0usize,0usize);
        for cell in area.cells.iter().flatten(){
            let b3=cell.block(3).is_some();
            let b13=cell.block(13).is_some();
            if b3{bit3+=1;}
            if b13{bit13+=1;}
            if b3&&b13{both+=1;}
        }
        ui.label(format!("Bit 3: {bit3} cells | Bit 13: {bit13} cells | Both: {both}"));
        ui.label("Missing color source = neutral color, not an invented blend.");
        ui.collapsing("Bit 19/20 Weight Research (read-only)",|ui|{
            use area::weight_research::CorrectionHypothesis;
            let pairs=area.cells.iter().flatten()
                .filter(|c|c.block(19).is_some() && c.block(20).is_some()).count();
            ui.label(format!("19/20 BC1 pairs: {pairs} cells"));
            ui.label("Full 65x65 scan, 4 hypotheses: direct/half correction, with/without BC1 coverage.");
            ui.label("Includes BC1 three-color/transparent endpoint mode. Never writes native data.");
            if ui.button("Analyze full AREA (read-only)").clicked(){
                state.weight_research_report=Some(
                    area::weight_research::AreaWeightResearch::inspect(area)
                );
                state.status="Bit 19/20 research finished (no AREA data modified)".into();
            }
            if let Some(report)=state.weight_research_report.as_ref(){
                ui.separator();
                ui.label(format!(
                    "19/20: {} cells | With Bit29: {} | Compared: {} samples",
                    report.present_pairs,report.paired_with_bit29,report.compared_samples
                ));
                if let Some(best)=report.best_model{
                    ui.label(format!("Lowest aggregate MAE: {} (HYPOTHESIS only)",best.label()));
                }else if report.compared_samples>0 {
                    ui.label("Models tied within tolerance: no unique best fit.");
                }else{
                    ui.label("No comparable Bit29/19+20 samples in this AREA.");
                }
                egui::Grid::new("genesis_19_20_research")
                    .striped(true).show(ui,|ui|{
                        ui.strong("Model");
                        ui.strong("MAE");
                        ui.strong("Max");
                        ui.strong("Within 10/255");
                        ui.end_row();
                        for model in CorrectionHypothesis::ALL{
                            let m=report.aggregate[model.index()];
                            ui.label(model.label());
                            ui.label(if m.sample_count>0{format!("{:.5}",m.mean_abs_error)}
                                else{"n/a".into()});
                            ui.label(if m.sample_count>0{format!("{:.5}",m.max_abs_error)}
                                else{"n/a".into()});
                            ui.label(if m.sample_count>0{
                                format!("{:.1}%",m.within_10_of_255 as f64*100.0
                                    /m.sample_count as f64)
                            }else{"n/a".into()});
                            ui.end_row();
                        }
                    });
                if let Some(cell)=report.cells.iter()
                    .find(|c|c.index==state.selected_cell.min(255)){
                    ui.separator();
                    ui.label(format!("Selected cell {}: {} compared samples",
                        cell.index,cell.compared_samples));
                    ui.label(format!(
                        "3-color BC1 blocks base/correction: {}/{} | transparent samples: {}",
                        cell.pair19_base_3color_blocks,
                        cell.pair19_corr_3color_blocks,
                        cell.pair19_base_transparent_samples
                    ));
                    if let Some(best)=cell.best_model{
                        ui.label(format!("Selected cell best-fit: {}",best.label()));
                    }
                }
                if ui.button("Export research CSV...").clicked(){
                    let csv=report.csv();
                    let target=rfd::FileDialog::new()
                        .add_filter("CSV", &["csv"])
                        .set_file_name("Genesis_Bit19_20_Research.csv")
                        .save_file();
                    if let Some(path)=target{
                        state.status=if path.extension().and_then(|s|s.to_str())
                            .is_some_and(|s|s.eq_ignore_ascii_case("csv")){
                            match std::fs::OpenOptions::new().write(true)
                                .create_new(true).open(&path){
                                Ok(mut file)=>{
                                    use std::io::Write;
                                    match file.write_all(csv.as_bytes())
                                        .and_then(|_|file.sync_all()){
                                        Ok(())=>format!("Research CSV exported: {}",path.display()),
                                        Err(e)=>{
                                            drop(file);
                                            let _=std::fs::remove_file(&path);
                                            format!("Research CSV write failed: {e}")
                                        }
                                    }
                                },
                                Err(e)=>format!("CSV Save As blocked (no overwrite): {e}"),
                            }
                        }else{"Research CSV requires .csv extension".into()};
                    }
                }
            }
            ui.colored_label(egui::Color32::DARK_RED,
                "No native Bit19/20 writer. Closest fit is not shader proof.");
        });
    }
    ui.separator();
    ui.label(egui::RichText::new("Macro Tint").strong());
    ui.add(egui::Slider::new(&mut state.tint.strength,0.0..=1.0).text("Tint Strength"));
    ui.checkbox(&mut state.tint.gamma_space,"Multiply tint in gamma space");
    ui.separator();
    ui.label(egui::RichText::new("WorldLayer Textures").strong());
    ui.add(egui::Slider::new(&mut state.tint.tiling_scale,0.25..=8.0)
        .logarithmic(true).text("Texture Repeats"));
    ui.checkbox(&mut state.tint.show_normals,"Use normal maps");
    if state.tint.show_normals {
        ui.add(egui::Slider::new(&mut state.tint.normal_strength,0.0..=2.0)
            .text("Normal Strength"));
    }
    ui.separator();
    ui.label(egui::RichText::new("Render / Debug View").strong());
    for (id,label) in [
        "Lit WorldLayer + PBR",
        "Unlit WorldLayer albedo",
        "Weightmap RGB (slots 0-2)",
        "Selected layer weight (grayscale)",
        "Macro-color RGB",
        "Bit 13 BC2 alpha (raw)",
        "Surface normals (world space)",
    ].iter().enumerate(){
        ui.radio_value(&mut state.tint.debug_mode,id as u32,*label);
    }
    if state.tint.debug_mode==3 {
        ui.horizontal_wrapped(|ui|{
            for slot in 0..4{
                ui.radio_value(&mut state.tint.debug_slot,slot,format!("Slot {slot}"));
            }
        });
    }
    if state.tint.debug_mode==5 {
        ui.colored_label(egui::Color32::DARK_RED,
            "BC2 alpha is diagnostic only; its original terrain meaning is unresolved.");
    }
    ui.separator();
    if ui.button("Reset Render Options").clicked(){
        state.tint=terrain_splat::TintSettings::default();
    }
    ui.label("Preview-only settings: AREA files, layer IDs and texture weights are not changed.");
}

fn dock_water(ui: &mut egui::Ui, state: &mut GenesisState, loaded: &LoadedArea) {
    ui.label(egui::RichText::new("Water Properties").strong().size(10.5));
    ui.separator();
    ui.label(egui::RichText::new(format!("Active Water Bodies: {}", loaded.water_count)).size(9.0));
    ui.separator();
    ui.label(egui::RichText::new("Water Tools").strong().size(9.0));
    for tool in ["Simple Water", "Water Grid", "Water Sphere", "Water Grid Outer Edge"] {
        if ui.button(tool).clicked() {
            command(state, tool);
        }
    }
    ui.separator();
    ui.label(egui::RichText::new("Shading & Surface").strong().size(9.0));
    ui.label("WildStar oceanic and river surface shader active.");
}

fn dock_environment(ui: &mut egui::Ui, state: &mut GenesisState, sky_mgr: &sky::SkyManager) {
    ui.label(egui::RichText::new("Environment & Sky").strong().size(10.5));
    ui.separator();
    ui.label(egui::RichText::new("Time of Day").strong().size(9.0));
    ui.add(egui::Slider::new(&mut state.time_of_day, 0.0..=24.0)
        .show_value(true).custom_formatter(|v, _| format!("{v:04.1} h")));
    ui.separator();
    ui.label(egui::RichText::new("Sky Lighting Preview").strong().size(9.0));
    ui.checkbox(&mut state.shadow_preview_enabled, "Directional shadows (3 cascades / 600 m)");
    ui.add(egui::Slider::new(&mut state.ambient_light_scale, 0.0..=2.0)
        .text("Sky ambient intensity"));
    ui.add(egui::Slider::new(&mut state.sun_light_scale, 0.0..=2.0)
        .text("Sun illuminance"));
    if let Some(eval) = sky_mgr.current_evaluated.as_ref() {
        ui.small(format!("Sun elevation: {:.1} deg | Fog: {:.0} - {:.0} m",
            eval.sun_elevation_deg, eval.fog_start, eval.fog_end));
        ui.small("SunSpecular is parsed but does not yet override Bevy PBR specular.");
    } else {
        ui.small("Load ClientData and an AREA to sample native .sky lighting.");
    }
    ui.small("Read-only visual settings; original .sky and AREA data stay unchanged.");
    ui.separator();
    ui.label(egui::RichText::new("Current Sky Context").strong().size(9.0));
    if let Some(zone) = sky_mgr.current_zone_id {
        ui.monospace(format!("Zone ID: #{}", zone));
    }
    if let Some(sky_path) = sky_mgr.current_sky_path.as_ref() {
        ui.monospace(format!("Sky: {}", sky_path));
    }
    ui.separator();
    ui.label(egui::RichText::new("Sky Environment Tools").strong().size(9.0));
    for tool in ["Sky Editor", "Fog Settings", "Cloud Shadows", "God Rays", "FullScreen Effects"] {
        if ui.button(tool).clicked() {
            command(state, tool);
        }
    }
}

fn dock_zones(ui: &mut egui::Ui, state: &mut GenesisState, sky_mgr: &sky::SkyManager) {
    ui.label(egui::RichText::new("Zones & Named Regions").strong().size(10.5));
    ui.separator();
    if let Some(zone) = sky_mgr.current_zone_id {
        ui.label(egui::RichText::new(format!("Current Zone ID: #{}", zone)).strong());
    } else {
        ui.label("No active zone sampled.");
    }
    ui.separator();
    ui.label(egui::RichText::new("Zone Tools").strong().size(9.0));
    for tool in ["Named Region Editor", "Navigation Window", "Land Layer ID", "Land Occlusion Lines"] {
        if ui.button(tool).clicked() {
            command(state, tool);
        }
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

    ui.checkbox(&mut state.area_standalone, "Open AREA standalone (editable)");
    ui.label(egui::RichText::new("Streaming zone tiles are read-only. Standalone AREA supports sculpting.").small());
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
            let ids = area.all_sky_ids();
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
    loaded: &mut LoadedArea,
    viewer: &mut prop_viewer::PropViewer,
    edit: &mut terrain_edit::TerrainEdit,
    paint: &mut terrain_paint::TerrainPaint,
) {
    if !state.open_zone_dialog {
        return;
    }
    if !client.ready() {
        state.open_zone_dialog = false;
        state.status = "World streaming requires Settings > ClientData Settings...".to_string();
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
                                    // A zone and standalone model must not coexist in the viewport.
                                    for entity in loaded.prop_entities.drain(..) {
                                        if let Ok(mut e) = commands.get_entity(entity) { e.despawn(); }
                                    }
                                    if let Some(entity) = loaded.mesh_entity.take() {
                                        if let Ok(mut e) = commands.get_entity(entity) { e.despawn(); }
                                    }
                                    if let Some(entity) = loaded.water_entity.take() {
                                        if let Ok(mut e) = commands.get_entity(entity) { e.despawn(); }
                                    }
                                    loaded.tile = None;
                                    loaded.props.clear();
                                    loaded.preview_model = None;
                                    viewer.clear_preview();
                                    edit.reset();
                                    paint.reset();
                                    state.status = format!("Loaded zone {map_name}");
                                    state.dock_tab = 6;
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
fn dock_area(ui: &mut egui::Ui, state: &mut GenesisState, loaded: &LoadedArea) {
    ui.label(egui::RichText::new("AREA Binary Inspector").strong().size(10.5));
    ui.separator();
    if let Some(area) = loaded.tile.as_ref() {
        area_ui::show(ui, &mut state.selected_cell, area,
            &loaded.props, loaded.prop_issue.as_deref());
    } else {
        ui.label("No AREA tile loaded.");
        if ui.button("Open AREA...").clicked() { command(state, "Open AREA..."); }
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
                row_slider(ui,"Hardness",&mut state.hardness,0.0..=1.0);
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
                row_slider(ui,"Hardness",&mut state.hardness,0.0..=1.0);
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
