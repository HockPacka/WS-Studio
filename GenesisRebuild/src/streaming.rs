//! Dynamic World Streaming and Multi-Tile Zone Loader for WildStar .area maps.
//!
//! WildStar zones consist of multiple 512m x 512m .area tiles on a 256x256 grid.
//! WorldStreaming maintains active tiles around the camera focus position, loads
//! missing tiles via background threads with cached textures, and despawns distant
//! tiles beyond the streaming radius.

use std::collections::{HashMap, HashSet};
use std::path::PathBuf;
use std::sync::mpsc::{self, Receiver, Sender};
use std::sync::{Arc, Mutex};
use std::thread;

use bevy::prelude::*;
use wildstar_formats::area::{AreaProp, RawArea};
use wildstar_formats::assets::AssetIndex;
use wildstar_formats::tbl::WorldLayer;
use wildstar_formats::zone::{MapDiscovery, ZoneTileCoords};

use crate::client_data::ClientFiles;
use crate::props;
use crate::terrain;
use crate::terrain_material::{self, AtlasResult, TextureCache};
use crate::water;
use crate::{GenesisState, OrbitCamera};

/// Request sent to the background streaming worker thread.
pub struct TileLoadRequest {
    pub coords: ZoneTileCoords,
    pub path: PathBuf,
    pub preview: usize,
    pub layer_index: usize,
}

/// Baked data produced in the background thread without main-thread blocking.
#[allow(dead_code)]
pub struct TileBakedData {
    pub coords: ZoneTileCoords,
    pub path: PathBuf,
    pub terrain_mesh: Mesh,
    pub visual_mid: f32,
    pub atlas: Option<AtlasResult>,
    pub water_mesh: Option<Mesh>,
    pub props: Vec<AreaProp>,
    pub cell_count: usize,
    pub water_count: usize,
    pub layer_status: String,
}

/// Response returned from the background worker.
pub struct TileLoadResponse {
    pub coords: ZoneTileCoords,
    pub result: Result<TileBakedData, String>,
}

/// An actively rendered tile in the Bevy ECS.
#[allow(dead_code)]
pub struct StreamedTile {
    pub coords: ZoneTileCoords,
    pub path: PathBuf,
    pub terrain_entity: Entity,
    pub water_entity: Option<Entity>,
    pub prop_entities: Vec<Entity>,
    pub props: Vec<AreaProp>,
    pub cell_count: usize,
    pub water_count: usize,
    pub layer_status: String,
}

#[derive(Resource)]
#[allow(dead_code)]
pub struct WorldStreaming {
    pub active_map: Option<MapDiscovery>,
    pub loaded_tiles: HashMap<ZoneTileCoords, StreamedTile>,
    pub in_flight: HashSet<ZoneTileCoords>,
    pub streaming_radius: i32,
    pub unload_hysteresis: i32,
    pub camera_tile: Option<ZoneTileCoords>,
    pub status_message: String,
    pub zone_browser_open: bool,
    pub available_maps: Vec<String>,
    pub map_search: String,
    pub total_streamed_count: usize,

    // Background thread channels (Mutex allows Receiver to be Sync as required by Bevy Resource)
    sender: Option<Sender<TileLoadRequest>>,
    receiver: Option<Mutex<Receiver<TileLoadResponse>>>,
    _workers: Vec<thread::JoinHandle<()>>,
    cached_layers: Option<Arc<HashMap<u32, WorldLayer>>>,
    cached_index: Option<Arc<AssetIndex>>,
}

impl Default for WorldStreaming {
    fn default() -> Self {
        Self {
            active_map: None,
            loaded_tiles: HashMap::new(),
            in_flight: HashSet::new(),
            streaming_radius: 1, // 3x3 tiles = 1536m x 1536m active area
            unload_hysteresis: 1, // Unload at radius + 1
            camera_tile: None,
            status_message: "World streaming idle. Open a zone to start.".to_string(),
            zone_browser_open: false,
            available_maps: Vec::new(),
            map_search: String::new(),
            total_streamed_count: 0,
            sender: None,
            receiver: None,
            _workers: Vec::new(),
            cached_layers: None,
            cached_index: None,
        }
    }
}

impl WorldStreaming {
    /// Initialize or restart the background streaming worker thread with current index and tables.
    pub fn ensure_worker(&mut self, index: &AssetIndex) {
        if self.sender.is_some() && self.cached_index.is_some() {
            return;
        }

        let arc_index = Arc::new(index.clone());
        let layers = match terrain_material::decode_layers(index) {
            Ok(l) => Arc::new(l),
            Err(e) => {
                self.status_message = format!("WorldLayer.tbl decode failed: {e}");
                Arc::new(HashMap::new())
            }
        };

        self.cached_index = Some(arc_index.clone());
        self.cached_layers = Some(layers.clone());

        let (req_tx, req_rx) = mpsc::channel::<TileLoadRequest>();
        let (resp_tx, resp_rx) = mpsc::channel::<TileLoadResponse>();

        self.sender = Some(req_tx);
        self.receiver = Some(Mutex::new(resp_rx));

        let shared_rx = Arc::new(Mutex::new(req_rx));
        let shared_cache = Arc::new(Mutex::new(TextureCache::default()));

        // Scale worker pool across available CPU cores (e.g. 6-8 threads on Ryzen)
        let worker_count = thread::available_parallelism()
            .map(|n| n.get())
            .unwrap_or(4)
            .clamp(2, 8);

        let mut workers = Vec::with_capacity(worker_count);
        for id in 0..worker_count {
            let rx = Arc::clone(&shared_rx);
            let tx = resp_tx.clone();
            let thread_index = Arc::clone(&arc_index);
            let thread_layers = Arc::clone(&layers);
            let cache = Arc::clone(&shared_cache);

            let handle = thread::Builder::new()
                .name(format!("genesis-streamer-{id}"))
                .spawn(move || {
                    loop {
                        let req = {
                            let Ok(lock) = rx.lock() else { break; };
                            match lock.recv() {
                                Ok(r) => r,
                                Err(_) => break,
                            }
                        };
                        let result = Self::load_and_bake_tile(
                            &req,
                            &thread_index,
                            &thread_layers,
                            &cache,
                        );
                        let _ = tx.send(TileLoadResponse {
                            coords: req.coords,
                            result,
                        });
                    }
                })
                .expect("Failed to spawn area streaming worker thread");
            workers.push(handle);
        }

        self._workers = workers;
    }

    /// Background worker function: reads file, generates geometry, bakes textures with caching.
    fn load_and_bake_tile(
        req: &TileLoadRequest,
        index: &AssetIndex,
        layers: &HashMap<u32, WorldLayer>,
        cache: &Mutex<TextureCache>,
    ) -> Result<TileBakedData, String> {
        let area = RawArea::from_path(&req.path)
            .map_err(|e| format!("AREA parse error in {}: {e}", req.path.display()))?;

        // 1. Terrain Mesh
        let (terrain_mesh, visual_mid) =
            terrain::terrain_mesh(&area, req.preview, req.layer_index)
                .map_err(|e| format!("Terrain mesh error: {e}"))?;

        // 2. Material Atlas (Albedo + Tangent Normal Map)
        let (atlas, layer_status) =
            match terrain_material::bake_with_cache(&area, index, layers, cache) {
                Ok(a) => {
                    let msg = format!(
                        "WorldLayer: {} IDs, {} decoded ({} unresolved)",
                        a.layers,
                        a.textures,
                        a.unresolved.len()
                    );
                    (Some(a), msg)
                }
                Err(err) => (None, format!("WorldLayer unavailable: {err}")),
            };

        // 3. Water Mesh
        let water_bodies = area.all_water_bodies();
        let water_count = water_bodies.len();
        let water_mesh = water::water_mesh(&water_bodies);

        // 4. Props
        let props = area.prop_placements().unwrap_or_default();
        let cell_count = area.cell_count();

        Ok(TileBakedData {
            coords: req.coords,
            path: req.path.clone(),
            terrain_mesh,
            visual_mid: visual_mid.y,
            atlas,
            water_mesh,
            props,
            cell_count,
            water_count,
            layer_status,
        })
    }

    /// Open a zone map by name, discovery all its tiles, and set camera focus to center.
    pub fn open_map(
        &mut self,
        map_name: &str,
        client_files: &ClientFiles,
        orbit: &mut OrbitCamera,
        commands: &mut Commands,
    ) -> Result<(), String> {
        let Some(index) = client_files.index.as_ref() else {
            return Err("ClientData is not indexed yet".into());
        };

        let map_root = client_files
            .client_data_dir()
            .ok_or("ClientData directory not resolved")?
            .join("Map")
            .join(map_name);

        let discovery = MapDiscovery::scan_dir(&map_root)?;
        self.ensure_worker(index);

        // Unload any previously loaded tiles
        self.clear_all(commands);

        let center_tile = discovery.center_tile();
        let center_pos = center_tile.world_center();

        orbit.eye = Vec3::new(center_pos[0], 120.0, center_pos[2] + 40.0);
        orbit.focus = Vec3::new(center_pos[0], 0.0, center_pos[2]);
        orbit.distance = 730.0;

        self.active_map = Some(discovery);
        self.camera_tile = Some(center_tile);
        self.status_message = format!(
            "Opened map '{map_name}' ({} tiles). Streaming around {:?}.",
            self.active_map.as_ref().unwrap().tiles.len(),
            center_tile.to_hex()
        );

        Ok(())
    }

    /// Clear all loaded tiles and despawn their entities.
    pub fn clear_all(&mut self, commands: &mut Commands) {
        for (_, tile) in self.loaded_tiles.drain() {
            commands.entity(tile.terrain_entity).despawn();
            if let Some(w) = tile.water_entity {
                commands.entity(w).despawn();
            }
            for p in tile.prop_entities {
                commands.entity(p).despawn();
            }
        }
        self.in_flight.clear();
    }

    /// Scan and refresh the list of all available zones in ClientData/Map.
    pub fn refresh_available_maps(&mut self, client_files: &ClientFiles) {
        if let Some(client_dir) = client_files.client_data_dir() {
            let map_dir = client_dir.join("Map");
            self.available_maps = MapDiscovery::list_maps(&map_dir);
        }
    }
}

/// Bevy system that continuously processes worker responses, schedules tiles in range,
/// and unloads tiles out of range.
pub fn update_world_streaming(
    mut streaming: ResMut<WorldStreaming>,
    client: Res<ClientFiles>,
    state: Res<GenesisState>,
    mut orbit: ResMut<OrbitCamera>,
    mut commands: Commands,
    mut meshes: ResMut<Assets<Mesh>>,
    mut materials: ResMut<Assets<StandardMaterial>>,
    mut images: ResMut<Assets<Image>>,
) {
    if !client.ready() {
        return;
    }

    // 1. Process responses from background workers (budget of up to 4 tiles per frame for smooth 60 FPS)
    let mut processed_this_frame = 0;
    while processed_this_frame < 4 {
        let resp = match streaming
            .receiver
            .as_ref()
            .and_then(|m| m.lock().ok())
            .and_then(|rx| rx.try_recv().ok())
        {
            Some(r) => r,
            None => break,
        };

        streaming.in_flight.remove(&resp.coords);
        processed_this_frame += 1;

        match resp.result {
            Ok(baked) => {
                // Check if tile is still within unload range of camera origin
                let cam_origin = orbit.origin();
                let current_cam = ZoneTileCoords::from_world_pos(cam_origin.x, cam_origin.z);
                let dist = baked.coords.chebyshev_distance(&current_cam);
                if dist > streaming.streaming_radius + streaming.unload_hysteresis {
                    continue; // Skip spawning, camera has moved away
                }

                let albedo_handle = baked
                    .atlas
                    .as_ref()
                    .map(|a| images.add(a.albedo_image.clone()));
                let normal_handle = baked
                    .atlas
                    .as_ref()
                    .and_then(|a| a.normal_image.as_ref().map(|img| images.add(img.clone())));

                let terrain_mat = materials.add(StandardMaterial {
                    base_color: Color::WHITE,
                    base_color_texture: if state.terrain_view == 5 {
                        albedo_handle
                    } else {
                        None
                    },
                    normal_map_texture: if state.terrain_view == 5 {
                        normal_handle
                    } else {
                        None
                    },
                    perceptual_roughness: 0.85,
                    reflectance: 0.2,
                    cull_mode: None,
                    ..default()
                });

                if streaming.loaded_tiles.is_empty() {
                    // First tile for zone: snap camera origin elevation above terrain surface
                    orbit.focus.y = baked.visual_mid;
                    if orbit.is_first_person && (orbit.eye.y - 120.0).abs() < 1.0 {
                        orbit.eye.y = baked.visual_mid + 35.0;
                    }
                }

                let world_center = baked.coords.world_center();
                let terrain_entity = commands
                    .spawn((
                        Mesh3d(meshes.add(baked.terrain_mesh)),
                        MeshMaterial3d(terrain_mat),
                        Transform::from_xyz(world_center[0], 0.0, world_center[2]),
                    ))
                    .id();

                let water_entity = baked.water_mesh.map(|wmesh| {
                    commands
                        .spawn((
                            Mesh3d(meshes.add(wmesh)),
                            MeshMaterial3d(materials.add(water::water_material())),
                            Transform::default(),
                        ))
                        .id()
                });

                let prop_entities = if !baked.props.is_empty() {
                    props::spawn_props(&mut commands, &baked.props, &mut meshes, &mut materials, &mut images,
                        client.index.as_ref(), &client.prop_models)
                } else {
                    Vec::new()
                };

                streaming.total_streamed_count += 1;
                streaming.loaded_tiles.insert(
                    baked.coords,
                    StreamedTile {
                        coords: baked.coords,
                        path: baked.path,
                        terrain_entity,
                        water_entity,
                        prop_entities,
                        props: baked.props,
                        cell_count: baked.cell_count,
                        water_count: baked.water_count,
                        layer_status: baked.layer_status,
                    },
                );
            }
            Err(e) => {
                eprintln!("Streaming error for {:?}: {e}", resp.coords);
            }
        }
    }

    // 2. Check if an active map is loaded
    let Some(discovery) = streaming.active_map.clone() else {
        return;
    };

    let cam_origin = orbit.origin();
    let cam_tile = ZoneTileCoords::from_world_pos(cam_origin.x, cam_origin.z);
    streaming.camera_tile = Some(cam_tile);

    // 3. Unload tiles outside (radius + hysteresis)
    let max_dist = streaming.streaming_radius + streaming.unload_hysteresis;
    let tiles_to_unload: Vec<ZoneTileCoords> = streaming
        .loaded_tiles
        .keys()
        .filter(|coords| coords.chebyshev_distance(&cam_tile) > max_dist)
        .copied()
        .collect();

    for coords in tiles_to_unload {
        if let Some(tile) = streaming.loaded_tiles.remove(&coords) {
            commands.entity(tile.terrain_entity).despawn();
            if let Some(w) = tile.water_entity {
                commands.entity(w).despawn();
            }
            for p in tile.prop_entities {
                commands.entity(p).despawn();
            }
        }
    }

    // 4. Determine missing tiles within streaming radius, prioritized by distance to camera
    let wanted_tiles = discovery.tiles_in_radius(cam_tile, streaming.streaming_radius);
    let mut missing: Vec<ZoneTileCoords> = wanted_tiles
        .into_iter()
        .filter(|c| !streaming.loaded_tiles.contains_key(c) && !streaming.in_flight.contains(c))
        .collect();

    missing.sort_by(|a, b| {
        let da = a.distance_squared_to(cam_origin.x, cam_origin.z);
        let db = b.distance_squared_to(cam_origin.x, cam_origin.z);
        da.partial_cmp(&db).unwrap_or(std::cmp::Ordering::Equal)
    });

    // Send requests to worker threads (up to 12 in queue across parallel workers)
    if let Some(sender) = streaming.sender.clone() {
        for coords in missing.into_iter().take(12) {
            if let Some(path) = discovery.tiles.get(&coords) {
                streaming.in_flight.insert(coords);
                let _ = sender.send(TileLoadRequest {
                    coords,
                    path: path.clone(),
                    preview: state.terrain_view,
                    layer_index: state.texture_index,
                });
            }
        }
    }
}
