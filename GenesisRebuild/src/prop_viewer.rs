//! Searchable, read-only WildStar M3/I3 prop library and viewport inspector.
//! Uses the same asset index, model cache and scene renderer as AREA props.
use std::path::PathBuf;
use bevy::prelude::*;
use bevy_egui::egui;
use wildstar_formats::assets::AssetIndex;
use crate::{OrbitCamera, props};

const PAGE_SIZE: usize = 60;

pub struct PreviewInfo {
    pub path: String,
    pub root: Entity,
    pub parts: Vec<Entity>,
    pub visible: Vec<bool>,
    pub min: Vec3,
    pub max: Vec3,
}
impl PreviewInfo {
    pub fn center(&self) -> Vec3 { (self.min + self.max) * 0.5 }
    pub fn diagonal(&self) -> f32 { (self.max - self.min).length().max(1.0) }
}

#[derive(Resource)]
pub struct PropViewer {
    paths: Vec<String>,
    filtered: Vec<usize>,
    client_root: Option<PathBuf>,
    file_count: usize,
    pub search: String,
    pub kind: usize, // 0: all, 1: M3, 2: I3
    pub page: usize,
    last_search: String,
    last_kind: usize,
    pub preview: Option<PreviewInfo>,
    pub spin: bool,
    pub spin_speed: f32,
    pub request_reframe: bool,
    pub request_reset_rotation: bool,
}
impl Default for PropViewer {
    fn default() -> Self {
        Self {
            paths: Vec::new(), filtered: Vec::new(), client_root: None, file_count: 0,
            search: String::new(), kind: 0, page: 0,
            last_search: String::new(), last_kind: 0,
            preview: None, spin: false, spin_speed: 20.0,
            request_reframe: false, request_reset_rotation: false,
        }
    }
}

fn accepts(path: &str, search: &str, kind: usize) -> bool {
    let is_m3 = path.ends_with(".m3");
    let is_i3 = path.ends_with(".i3");
    if !(is_m3 || is_i3) { return false; }
    if kind == 1 && !is_m3 { return false; }
    if kind == 2 && !is_i3 { return false; }
    path.contains(search)
}

impl PropViewer {
    pub fn clear_preview(&mut self) {
        self.preview = None;
        self.spin = false;
        self.request_reframe = false;
        self.request_reset_rotation = false;
    }

    pub fn set_preview(&mut self, path: String, scene: &props::PreviewScene) {
        self.preview = Some(PreviewInfo {
            path,
            root: scene.root,
            parts: scene.parts.clone(),
            visible: vec![true; scene.parts.len()],
            min: Vec3::from_array(scene.min),
            max: Vec3::from_array(scene.max),
        });
        self.spin = false;
        self.request_reframe = true;
        self.request_reset_rotation = false;
    }

    fn ensure_index(&mut self, index: &AssetIndex) {
        let root = index.roots.as_ref().map(|r|r.client_data.clone());
        if root == self.client_root && self.file_count == index.file_count() {
            return;
        }
        self.client_root = root;
        self.file_count = index.file_count();
        self.paths = index.files.keys()
            .filter(|path|path.ends_with(".m3") || path.ends_with(".i3"))
            .cloned().collect();
        self.paths.sort_unstable();
        self.last_search = String::from("\u{0}");
        self.rebuild_matches();
    }

    fn rebuild_matches(&mut self) {
        let query = self.search.trim().to_lowercase().replace('\\', "/");
        self.filtered = self.paths.iter().enumerate()
            .filter_map(|(i, path)| accepts(path, &query, self.kind).then_some(i))
            .collect();
        self.page = 0;
        self.last_search = self.search.clone();
        self.last_kind = self.kind;
    }

    pub fn show(
        &mut self, ui: &mut egui::Ui, index: Option<&AssetIndex>,
        report: &[String], commands: &mut Commands, pending: &mut Option<String>,
    ) {
        ui.label(egui::RichText::new("Prop Viewer / Asset Library").strong());
        let Some(index) = index else {
            ui.label("First choose the WildStar ClientData root and let indexing finish.");
            return;
        };
        self.ensure_index(index);
        ui.horizontal(|ui| {
            ui.label("Filter");
            ui.add(egui::TextEdit::singleline(&mut self.search)
                .hint_text("Model name / folder").desired_width(ui.available_width().max(80.0)));
            if ui.small_button("X").clicked() { self.search.clear(); }
        });
        ui.horizontal_wrapped(|ui| {
            ui.radio_value(&mut self.kind, 0, "M3 + I3");
            ui.radio_value(&mut self.kind, 1, "M3");
            ui.radio_value(&mut self.kind, 2, "I3");
        });
        if self.search != self.last_search || self.kind != self.last_kind {
            self.rebuild_matches();
        }
        let pages = self.filtered.len().div_ceil(PAGE_SIZE).max(1);
        self.page = self.page.min(pages - 1);
        ui.horizontal(|ui| {
            ui.label(format!("{} models | page {} / {}", self.filtered.len(), self.page + 1, pages));
            if ui.small_button("<").clicked() && self.page > 0 { self.page -= 1; }
            if ui.small_button(">").clicked() && self.page + 1 < pages { self.page += 1; }
        });
        ui.separator();
        let start = self.page * PAGE_SIZE;
        let end = (start + PAGE_SIZE).min(self.filtered.len());
        egui::ScrollArea::vertical().id_salt("genesis-prop-library")
            .max_height(215.0).show(ui, |ui| {
                for &idx in &self.filtered[start..end] {
                    let path = &self.paths[idx];
                    let leaf = path.rsplit('/').next().unwrap_or(path);
                    let active = self.preview.as_ref().is_some_and(|p|p.path==*path);
                    let response = ui.selectable_label(active, leaf).on_hover_text(path);
                    if response.clicked() { *pending = Some(path.clone()); }
                }
            });
        ui.separator();
        let Some(preview) = self.preview.as_mut() else {
            ui.label("Select a model above to load it into the 3D viewport.");
            return;
        };
        ui.label(egui::RichText::new("Selected Model").strong());
        ui.monospace(&preview.path);
        ui.label(format!("{} parts | bounds {:.2} x {:.2} x {:.2}",
            preview.parts.len(),
            (preview.max - preview.min).x,
            (preview.max - preview.min).y,
            (preview.max - preview.min).z));
        ui.horizontal(|ui| {
            if ui.button("Frame").clicked() { self.request_reframe = true; }
            if ui.button("Reset rotation").clicked() { self.request_reset_rotation = true; }
        });
        ui.horizontal(|ui| {
            ui.checkbox(&mut self.spin, "Turntable");
            if self.spin { ui.add(egui::Slider::new(&mut self.spin_speed, 5.0..=120.0).suffix(" deg/s")); }
        });
        ui.collapsing(format!("Render Parts ({})", preview.parts.len()), |ui| {
            ui.horizontal(|ui| {
                if ui.small_button("Show all").clicked() {
                    for (entity, enabled) in preview.parts.iter().zip(&mut preview.visible) {
                        *enabled = true;
                        commands.entity(*entity).insert(Visibility::Visible);
                    }
                }
                if ui.small_button("Hide all").clicked() {
                    for (entity, enabled) in preview.parts.iter().zip(&mut preview.visible) {
                        *enabled = false;
                        commands.entity(*entity).insert(Visibility::Hidden);
                    }
                }
            });
            for (i, (entity, enabled)) in preview.parts.iter().zip(&mut preview.visible).enumerate() {
                if ui.checkbox(enabled, format!("Part {}", i + 1)).changed() {
                    commands.entity(*entity).insert(if *enabled {
                        Visibility::Visible
                    } else { Visibility::Hidden });
                }
            }
        });
        ui.collapsing("Model metadata / references", |ui| {
            if report.is_empty() {
                ui.label("No model metadata.");
            } else {
                for line in report { ui.monospace(line); }
            }
        });
    }
}

/// Animation updates only the current standalone root, not any world prop.
/// Reframe and reset flags are consumed once, from the main Bevy update loop.
pub fn update(
    time: Res<Time>,
    mut viewer: ResMut<PropViewer>,
    mut orbit: ResMut<OrbitCamera>,
    mut transforms: Query<&mut Transform>,
) {
    let Some(preview) = viewer.preview.as_ref() else { return; };
    let root = preview.root;
    let center = preview.center();
    let diagonal = preview.diagonal();
    let reframe = std::mem::take(&mut viewer.request_reframe);
    let reset = std::mem::take(&mut viewer.request_reset_rotation);
    let spin = viewer.spin;
    let spin_speed = viewer.spin_speed;
    if reframe {
        orbit.is_first_person = false;
        orbit.focus = center;
        orbit.distance = (diagonal * 1.75).clamp(3.0, 5000.0);
        orbit.yaw = 0.5;
        orbit.pitch = 0.25;
    }
    if let Ok(mut transform) = transforms.get_mut(root) {
        if reset { transform.rotation = Quat::IDENTITY; }
        if spin {
            transform.rotate_y(spin_speed.to_radians() * time.delta_secs());
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn library_filter_matches_extension_and_folder() {
        assert!(accepts("art/creature/avatus.m3", "avatus", 1));
        assert!(accepts("art/building/tower.i3", "building", 2));
        assert!(!accepts("art/building/tower.i3", "building", 1));
        assert!(!accepts("art/material/avatus.tex", "avatus", 0));
    }
}
