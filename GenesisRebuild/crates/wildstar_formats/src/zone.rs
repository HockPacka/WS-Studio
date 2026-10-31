//! Zone and world coordinate management for streaming WildStar .area tiles.
//!
//! WildStar organizes world maps into a 256x256 tile grid where each tile is
//! exactly 512.0m x 512.0m. The origin (0.0, 0.0) is centered at tile index (64, 64)
//! (hex 0x40, 0x40).
//!
//! Tile naming convention:
//! `<MapName>.<Z_hex><X_hex>.area`
//! e.g. `AdventureGaleras.3747.area`:
//! - `Z_hex = 0x37 = 55` -> `Z_origin = (55 - 64) * 512.0 = -4608.0`
//! - `X_hex = 0x47 = 71` -> `X_origin = (71 - 64) * 512.0 = +3584.0`

use std::collections::HashMap;
use std::fs;
use std::path::{Path, PathBuf};

pub const TILE_SIZE: f32 = 512.0;
pub const TILE_HALF_SIZE: f32 = 256.0;
pub const GRID_CENTER_OFFSET: f32 = 64.0;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct ZoneTileCoords {
    pub z: u8,
    pub x: u8,
}

impl ZoneTileCoords {
    pub const fn new(z: u8, x: u8) -> Self {
        Self { z, x }
    }

    /// Extract tile coordinates from a filename or path string.
    ///
    /// Accepts forms like:
    /// - `"AdventureGaleras.3747.area"`
    /// - `"3747.area"`
    /// - `"3747"`
    /// - `Path::new(".../Map/AdventureGaleras/AdventureGaleras.3747.area")`
    pub fn from_path_or_name(input: &str) -> Option<Self> {
        let name = Path::new(input)
            .file_name()?
            .to_str()?;

        // Strip ".area" if present
        let stem = name.strip_suffix(".area").unwrap_or(name);

        // Look for the last dot-separated part (e.g. "3747" in "AdventureGaleras.3747")
        // or check the last 4 characters
        let hex_slice = if let Some(last_dot) = stem.rfind('.') {
            &stem[last_dot + 1..]
        } else if stem.len() >= 4 {
            &stem[stem.len() - 4..]
        } else {
            return None;
        };

        if hex_slice.len() != 4 {
            return None;
        }

        let z = u8::from_str_radix(&hex_slice[0..2], 16).ok()?;
        let x = u8::from_str_radix(&hex_slice[2..4], 16).ok()?;
        Some(Self { z, x })
    }

    /// Format as 4-hex-digit string (e.g. "3747").
    pub fn to_hex(&self) -> String {
        format!("{:02x}{:02x}", self.z, self.x)
    }

    /// Convert continuous world (X, Z) coordinates to the containing tile coordinates.
    pub fn from_world_pos(world_x: f32, world_z: f32) -> Self {
        let x = ((world_x / TILE_SIZE) + GRID_CENTER_OFFSET)
            .floor()
            .clamp(0.0, 255.0) as u8;
        let z = ((world_z / TILE_SIZE) + GRID_CENTER_OFFSET)
            .floor()
            .clamp(0.0, 255.0) as u8;
        Self { z, x }
    }

    /// Calculate the minimum corner `[min_x, min_z]` in world space for this tile.
    pub fn world_origin(&self) -> [f32; 2] {
        [
            (self.x as f32 - GRID_CENTER_OFFSET) * TILE_SIZE,
            (self.z as f32 - GRID_CENTER_OFFSET) * TILE_SIZE,
        ]
    }

    /// Calculate the center `[center_x, 0.0, center_z]` in world space for this tile.
    pub fn world_center(&self) -> [f32; 3] {
        [
            (self.x as f32 - GRID_CENTER_OFFSET) * TILE_SIZE + TILE_HALF_SIZE,
            0.0,
            (self.z as f32 - GRID_CENTER_OFFSET) * TILE_SIZE + TILE_HALF_SIZE,
        ]
    }

    /// Calculate the world space bounding box `(min [x, z], max [x, z])`.
    pub fn world_bounds(&self) -> ([f32; 2], [f32; 2]) {
        let [min_x, min_z] = self.world_origin();
        ([min_x, min_z], [min_x + TILE_SIZE, min_z + TILE_SIZE])
    }

    /// Chebyshev / King's distance in grid units (maximum of |delta_z| and |delta_x|).
    /// Used for square radius streaming (radius 1 = 3x3 tiles, radius 2 = 5x5 tiles).
    pub fn chebyshev_distance(&self, other: &Self) -> i32 {
        (self.x as i32 - other.x as i32)
            .abs()
            .max((self.z as i32 - other.z as i32).abs())
    }

    /// Euclidean distance squared in world meters between tile centers.
    pub fn distance_squared_to(&self, world_x: f32, world_z: f32) -> f32 {
        let center = self.world_center();
        let dx = center[0] - world_x;
        let dz = center[2] - world_z;
        dx * dx + dz * dz
    }
}

/// Metadata and tile index for a discovered map zone.
#[derive(Debug, Clone)]
pub struct MapDiscovery {
    pub name: String,
    pub dir_path: PathBuf,
    pub tiles: HashMap<ZoneTileCoords, PathBuf>,
    pub min_z: u8,
    pub max_z: u8,
    pub min_x: u8,
    pub max_x: u8,
}

impl MapDiscovery {
    /// Scan a map directory (e.g. `<ClientRoot>/ClientData/Map/<MapName>`)
    /// and index all `.area` tiles.
    pub fn scan_dir(dir: &Path) -> Result<Self, String> {
        if !dir.is_dir() {
            return Err(format!("Not a directory: {}", dir.display()));
        }

        let map_name = dir
            .file_name()
            .and_then(|n| n.to_str())
            .unwrap_or("UnknownMap")
            .to_string();

        let entries = fs::read_dir(dir)
            .map_err(|e| format!("Failed to read directory {}: {e}", dir.display()))?;

        let mut tiles = HashMap::new();
        let mut min_z = 255u8;
        let mut max_z = 0u8;
        let mut min_x = 255u8;
        let mut max_x = 0u8;

        for entry in entries.flatten() {
            let path = entry.path();
            if path.extension().and_then(|s| s.to_str()) == Some("area") {
                if let Some(coords) = path
                    .file_name()
                    .and_then(|n| n.to_str())
                    .and_then(ZoneTileCoords::from_path_or_name)
                {
                    min_z = min_z.min(coords.z);
                    max_z = max_z.max(coords.z);
                    min_x = min_x.min(coords.x);
                    max_x = max_x.max(coords.x);
                    tiles.insert(coords, path);
                }
            }
        }

        if tiles.is_empty() {
            return Err(format!("No valid .area tiles found in {}", dir.display()));
        }

        Ok(Self {
            name: map_name,
            dir_path: dir.to_path_buf(),
            tiles,
            min_z,
            max_z,
            min_x,
            max_x,
        })
    }

    /// List all available map zones inside `<ClientRoot>/ClientData/Map/`
    /// that contain at least one `.area` tile.
    pub fn list_maps(map_root: &Path) -> Vec<String> {
        let mut maps = Vec::new();
        let Ok(entries) = fs::read_dir(map_root) else {
            return maps;
        };

        for entry in entries.flatten() {
            let path = entry.path();
            if path.is_dir() {
                // Check if directory has at least one .area file
                let has_area = fs::read_dir(&path)
                    .map(|mut r| {
                        r.any(|e| {
                            e.map(|ent| {
                                ent.path()
                                    .extension()
                                    .and_then(|s| s.to_str())
                                    == Some("area")
                            })
                            .unwrap_or(false)
                        })
                    })
                    .unwrap_or(false);

                if has_area {
                    if let Some(name) = path.file_name().and_then(|n| n.to_str()) {
                        maps.push(name.to_string());
                    }
                }
            }
        }

        maps.sort();
        maps
    }

    /// Return the list of tiles within Chebyshev distance `radius` of `center`.
    pub fn tiles_in_radius(&self, center: ZoneTileCoords, radius: i32) -> Vec<ZoneTileCoords> {
        let mut result = Vec::new();
        let rad = radius.max(0);
        let cz = center.z as i32;
        let cx = center.x as i32;

        for dz in -rad..=rad {
            let z = cz + dz;
            if !(0..=255).contains(&z) {
                continue;
            }
            for dx in -rad..=rad {
                let x = cx + dx;
                if !(0..=255).contains(&x) {
                    continue;
                }
                let coords = ZoneTileCoords::new(z as u8, x as u8);
                if self.tiles.contains_key(&coords) {
                    result.push(coords);
                }
            }
        }

        result
    }

    /// Find the central tile among available tiles in this map.
    pub fn center_tile(&self) -> ZoneTileCoords {
        let mid_z = ((self.min_z as u16 + self.max_z as u16) / 2) as u8;
        let mid_x = ((self.min_x as u16 + self.max_x as u16) / 2) as u8;
        let target = ZoneTileCoords::new(mid_z, mid_x);

        if self.tiles.contains_key(&target) {
            return target;
        }

        // Otherwise find closest available tile
        *self
            .tiles
            .keys()
            .min_by_key(|coords| coords.chebyshev_distance(&target))
            .unwrap_or(&target)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parses_coords_from_filenames() {
        let c1 = ZoneTileCoords::from_path_or_name("AdventureGaleras.3747.area").unwrap();
        assert_eq!(c1.z, 0x37);
        assert_eq!(c1.x, 0x47);

        let c2 = ZoneTileCoords::from_path_or_name("1x1HousingGamblingInterior.403f.area").unwrap();
        assert_eq!(c2.z, 0x40);
        assert_eq!(c2.x, 0x3f);

        let c3 = ZoneTileCoords::from_path_or_name("3747.area").unwrap();
        assert_eq!(c3.z, 0x37);
        assert_eq!(c3.x, 0x47);
    }

    #[test]
    fn world_coordinates_and_roundtrip() {
        let coords = ZoneTileCoords::new(0x37, 0x47);
        // z = 55 -> (55 - 64) * 512 = -4608
        // x = 71 -> (71 - 64) * 512 = 3584
        assert_eq!(coords.world_origin(), [3584.0, -4608.0]);
        assert_eq!(coords.world_center(), [3840.0, 0.0, -4352.0]);

        // Roundtrip from center
        let roundtrip = ZoneTileCoords::from_world_pos(3840.0, -4352.0);
        assert_eq!(roundtrip, coords);

        // Near edges
        let near_min = ZoneTileCoords::from_world_pos(3584.1, -4607.9);
        assert_eq!(near_min, coords);
        let near_max = ZoneTileCoords::from_world_pos(4095.9, -4096.1);
        assert_eq!(near_max, coords);
    }

    #[test]
    fn chebyshev_and_radius() {
        let c1 = ZoneTileCoords::new(55, 71);
        let c2 = ZoneTileCoords::new(56, 72);
        assert_eq!(c1.chebyshev_distance(&c2), 1);

        let c3 = ZoneTileCoords::new(53, 71);
        assert_eq!(c1.chebyshev_distance(&c3), 2);
    }
}
