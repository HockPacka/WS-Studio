//! Native parser and evaluators for WildStar XSKY v16 atmosphere files.
//!
//! WildStar `.sky` files define atmospheric lighting (ambient, directional sun/moon,
//! spherical harmonic lighting), fog distances, screen post-processing parameters,
//! cloud sets and alpha, sky-associated models (suns, moons, stars, skybox geometry),
//! particulate sets, cubemaps, sun glare, liquid water colors and wind spawn tracks.
//!
//! Offsets are relative to the fixed 0x4C0 header; nested track tables use the
//! 16-byte aligned end of their own table.

use std::collections::HashMap;

pub const HEADER_SIZE: usize = 0x4C0;
pub const MAGIC: &[u8; 4] = b"YKSX";
pub const SUPPORTED_VERSION: u32 = 16;

#[derive(Debug, Clone, PartialEq)]
pub struct Track<T> {
    pub times: Vec<u32>,
    pub values: Vec<T>,
}

impl<T> Default for Track<T> {
    fn default() -> Self {
        Self {
            times: Vec::new(),
            values: Vec::new(),
        }
    }
}

impl<T> Track<T> {
    pub fn is_empty(&self) -> bool {
        self.times.is_empty()
    }

    pub fn len(&self) -> usize {
        self.times.len()
    }
}

impl Track<Vec<f32>> {
    /// Sample a float vector track linearly across day seconds.
    /// Clamps endpoints before the first key and after the last key.
    pub fn sample(&self, time: f32) -> Option<Vec<f32>> {
        if self.times.is_empty() {
            return None;
        }
        let n = self.times.len();
        if time <= self.times[0] as f32 {
            return Some(self.values[0].clone());
        }
        if time >= self.times[n - 1] as f32 {
            return Some(self.values[n - 1].clone());
        }
        let t_u32 = time as u32;
        let idx = match self.times.binary_search(&t_u32) {
            Ok(i) => return Some(self.values[i].clone()),
            Err(i) => i,
        };
        let t0 = self.times[idx - 1] as f32;
        let t1 = self.times[idx] as f32;
        let factor = if (t1 - t0).abs() > 1e-6 {
            (time - t0) / (t1 - t0)
        } else {
            0.0
        };
        let v0 = &self.values[idx - 1];
        let v1 = &self.values[idx];
        let mut out = Vec::with_capacity(v0.len());
        for (a, b) in v0.iter().zip(v1.iter()) {
            out.push(a + (b - a) * factor);
        }
        Some(out)
    }
}

impl Track<u32> {
    /// Sample resource IDs cyclically across a 86,400-second day (WildStar FUN_1407d5f20).
    /// Returns up to two IDs with their blend weights.
    pub fn sample_resources(&self, mut time: u32) -> Vec<(u32, f32)> {
        if self.times.is_empty() {
            return Vec::new();
        }
        time %= 86400;
        let n = self.times.len();
        if n == 1 {
            return vec![(self.values[0], 1.0)];
        }
        for (i, &t) in self.times.iter().enumerate() {
            if t == time {
                return vec![(self.values[i], 1.0)];
            }
        }
        let idx = match self.times.binary_search(&time) {
            Ok(i) => return vec![(self.values[i], 1.0)],
            Err(i) => i,
        };
        let (left, right) = if idx == 0 {
            (n - 1, 0)
        } else {
            (idx - 1, idx % n)
        };
        let start = self.times[left] as f32;
        let mut end = self.times[right] as f32;
        let mut cur = time as f32;
        if right <= left {
            end += 86400.0;
            if idx == 0 {
                cur += 86400.0;
            }
        }
        let t = if (end - start).abs() > 1e-6 {
            (cur - start) / (end - start)
        } else {
            0.0
        };
        let a = self.values[left];
        let b = self.values[right];
        if a == b {
            vec![(a, 1.0)]
        } else {
            vec![(a, 1.0 - t), (b, t)]
        }
    }
}

/// A Spherical Harmonics lighting group (each 0x98 bytes in the header).
#[derive(Debug, Clone, Default)]
pub struct SkyGroup {
    pub flags: [u32; 2],
    pub ambient_tracks: Vec<Track<Vec<f32>>>,     // 0x08: AP of Track16
    pub directional_tracks: Vec<Track<Vec<f32>>>, // 0x18: AP of Track32
    pub hemisphere_tracks: Vec<Track<Vec<f32>>>,  // 0x28: AP of Track48
    pub cone_tracks: Vec<Track<Vec<f32>>>,        // 0x38: AP of Track48
    pub array_0x48: Vec<Track<Vec<f32>>>,         // 0x48: AP of Track48
    pub array_0x58: Vec<Track<Vec<f32>>>,         // 0x58: AP of Track108
    pub sh_track: Track<Vec<f32>>,                // 0x68: Track108
    pub record_110_track: Track<Vec<f32>>,        // 0x80: Track272
}

/// Sky-associated model record (suns, moons, stars, skybox geometry).
#[derive(Debug, Clone)]
pub struct SkyModel {
    pub header_words: [u32; 2],
    pub path: String,
    pub track: Track<Vec<f32>>, // 32-byte track
}

/// Wind spawn record (0x4A0).
#[derive(Debug, Clone)]
pub struct WindSpawnTrack {
    pub times: Vec<u32>,
    pub wind_pairs: Vec<(u32, u32)>, // (WindSpawn.tbl id, Wind.tbl id)
}

/// Complete parsed WildStar XSKY v16 file.
#[derive(Debug, Clone)]
pub struct SkyFile {
    pub version: u32,
    pub source_xml: String,
    pub header_words: [u32; 4],
    pub header_10_float: f32,

    // Four SH groups: LightingSH (0x28), SkySH (0xC0), FogSH (0x158), CloudSH (0x1F0)
    pub lighting_group: SkyGroup,
    pub sky_group: SkyGroup,
    pub fog_group: SkyGroup,
    pub cloud_group: SkyGroup,

    // Top-level tracks
    pub ambient: Track<Vec<f32>>,        // 0x288, 16-byte values: RGBA
    pub sun_diffuse: Track<Vec<f32>>,    // 0x2A0, 32-byte values: elevationDeg, azimuthDeg, _, _, RGBA
    pub sun_specular: Track<Vec<f32>>,   // 0x2B8, 16-byte values: RGBA
    pub fog_distance: Track<Vec<f32>>,   // 0x2D0, 24-byte values: FogStart, FogEnd, SkyStart, SkyEnd, CloudFog, SkyFog
    pub models: Vec<SkyModel>,           // 0x2E8, 48-byte structs
    pub screen: Track<Vec<f32>>,         // 0x2F8, 96-byte values: 24 floats (Sepia, Saturation, Contrast, Bloom...)
    pub cloud_set_id: Track<u32>,        // 0x310, u32 values: SkyCloudSet.tbl ID
    pub cloud_alpha: Track<Vec<f32>>,    // 0x328, 4-byte values: float alpha multiplier
    pub particulates: Vec<String>,       // 0x340, AP of string APs
    pub env_map_tex: String,             // 0x350, string: cubemap .tex
    pub sun_glare: Track<Vec<f32>>,      // 0x360, 16-byte values: RGBA
    pub sun_glare_model1: String,        // 0x378, string: .m3
    pub sun_glare_model2: String,        // 0x388, string: .m3
    pub window_glow: Track<Vec<f32>>,    // 0x398, 4-byte values: float
    pub night_ambient: Track<Vec<f32>>,  // 0x3B0, 16-byte values: RGBA (added to SH DC term)
    pub horizon_fog_mod: Track<Vec<f32>>,// 0x3C8, 16-byte values: RGBA
    pub liquid_colors: [Track<Vec<f32>>; 8], // 0x3E0 + 24*i, 32-byte values: 2 RGBA colors each
    pub wind_spawns: Vec<WindSpawnTrack>, // 0x4A0, AP of Track8
    pub color_lut_tex: String,           // 0x4B0, string: color grading LUT .tex
}

struct Reader<'a> {
    data: &'a [u8],
}

impl<'a> Reader<'a> {
    fn new(data: &'a [u8]) -> Self {
        Self { data }
    }

    fn u16_at(&self, at: usize) -> Result<u16, String> {
        let b = self.data.get(at..at + 2).ok_or("SKY: short u16")?;
        Ok(u16::from_le_bytes(b.try_into().unwrap()))
    }

    fn u32_at(&self, at: usize) -> Result<u32, String> {
        let b = self.data.get(at..at + 4).ok_or("SKY: short u32")?;
        Ok(u32::from_le_bytes(b.try_into().unwrap()))
    }

    fn u64_at(&self, at: usize) -> Result<u64, String> {
        let b = self.data.get(at..at + 8).ok_or("SKY: short u64")?;
        Ok(u64::from_le_bytes(b.try_into().unwrap()))
    }

    fn f32_at(&self, at: usize) -> Result<f32, String> {
        self.u32_at(at).map(f32::from_bits)
    }

    fn ap(&self, p: usize, stride: usize, base: usize) -> Result<(usize, usize), String> {
        if p + 16 > self.data.len() {
            return Err(format!("SKY: AP descriptor at {p:#x} out of bounds"));
        }
        let count = self.u32_at(p)? as usize;
        let offset = self.u64_at(p + 8)? as usize;
        let start = base.checked_add(offset).ok_or("SKY: AP offset overflow")?;
        let bytes = count.checked_mul(stride).ok_or("SKY: AP length overflow")?;
        let end = start.checked_add(bytes).ok_or("SKY: AP end overflow")?;
        if end > self.data.len() {
            return Err(format!("SKY: AP range [{start:#x}..{end:#x}) exceeds file size {:#x}", self.data.len()));
        }
        Ok((count, start))
    }

    fn string(&self, p: usize, base: usize) -> Result<String, String> {
        let (count, start) = self.ap(p, 2, base)?;
        let mut units = Vec::with_capacity(count);
        for i in 0..count {
            let u = self.u16_at(start + i * 2)?;
            if u == 0 {
                break;
            }
            units.push(u);
        }
        String::from_utf16(&units).map_err(|e| format!("SKY: invalid UTF-16 at {p:#x}: {e}"))
    }

    fn track_floats(&self, p: usize, stride: usize, base: usize) -> Result<Track<Vec<f32>>, String> {
        if p + 24 > self.data.len() {
            return Err(format!("SKY: Track descriptor at {p:#x} out of bounds"));
        }
        let count = self.u32_at(p)? as usize;
        let times_offset = self.u64_at(p + 8)? as usize;
        let values_offset = self.u64_at(p + 16)? as usize;
        if count == 0 {
            return Ok(Track::default());
        }
        let t_start = base.checked_add(times_offset).ok_or("SKY: times overflow")?;
        let t_end = t_start.checked_add(count.checked_mul(4).ok_or("SKY: times overflow")?).ok_or("SKY: overflow")?;
        let v_start = base.checked_add(values_offset).ok_or("SKY: values overflow")?;
        let v_end = v_start.checked_add(count.checked_mul(stride).ok_or("SKY: values overflow")?).ok_or("SKY: overflow")?;

        if t_end > self.data.len() || v_end > self.data.len() {
            return Err(format!("SKY: Track data at {p:#x} exceeds file bounds"));
        }

        let mut times = Vec::with_capacity(count);
        for i in 0..count {
            times.push(self.u32_at(t_start + i * 4)?);
        }

        let floats_per_key = stride / 4;
        let mut values = Vec::with_capacity(count);
        for i in 0..count {
            let mut record = Vec::with_capacity(floats_per_key);
            let row_start = v_start + i * stride;
            for j in 0..floats_per_key {
                record.push(self.f32_at(row_start + j * 4)?);
            }
            values.push(record);
        }

        Ok(Track { times, values })
    }

    fn track_u32(&self, p: usize, base: usize) -> Result<Track<u32>, String> {
        if p + 24 > self.data.len() {
            return Err(format!("SKY: Track descriptor at {p:#x} out of bounds"));
        }
        let count = self.u32_at(p)? as usize;
        let times_offset = self.u64_at(p + 8)? as usize;
        let values_offset = self.u64_at(p + 16)? as usize;
        if count == 0 {
            return Ok(Track::default());
        }
        let t_start = base.checked_add(times_offset).ok_or("SKY: times overflow")?;
        let t_end = t_start.checked_add(count.checked_mul(4).ok_or("SKY: times overflow")?).ok_or("SKY: overflow")?;
        let v_start = base.checked_add(values_offset).ok_or("SKY: values overflow")?;
        let v_end = v_start.checked_add(count.checked_mul(4).ok_or("SKY: values overflow")?).ok_or("SKY: overflow")?;

        if t_end > self.data.len() || v_end > self.data.len() {
            return Err(format!("SKY: Track data at {p:#x} exceeds file bounds"));
        }

        let mut times = Vec::with_capacity(count);
        let mut values = Vec::with_capacity(count);
        for i in 0..count {
            times.push(self.u32_at(t_start + i * 4)?);
            values.push(self.u32_at(v_start + i * 4)?);
        }

        Ok(Track { times, values })
    }

    fn track_array(&self, p: usize, stride: usize) -> Result<Vec<Track<Vec<f32>>>, String> {
        let (count, start) = self.ap(p, 24, HEADER_SIZE)?;
        if count == 0 {
            return Ok(Vec::new());
        }
        // Nested track arrays use 16-byte aligned end of their own descriptor array as payload base
        let base = (start + count * 24 + 15) & !15;
        let mut tracks = Vec::with_capacity(count);
        for i in 0..count {
            tracks.push(self.track_floats(start + i * 24, stride, base)?);
        }
        Ok(tracks)
    }

    fn read_group(&self, g: usize) -> Result<SkyGroup, String> {
        let flags = [self.u32_at(g)?, self.u32_at(g + 4)?];
        let ambient_tracks = self.track_array(g + 0x08, 16)?;
        let directional_tracks = self.track_array(g + 0x18, 32)?;
        let hemisphere_tracks = self.track_array(g + 0x28, 48)?;
        let cone_tracks = self.track_array(g + 0x38, 48)?;
        let array_0x48 = self.track_array(g + 0x48, 48)?;
        let array_0x58 = self.track_array(g + 0x58, 108)?;
        let sh_track = self.track_floats(g + 0x68, 108, HEADER_SIZE)?;
        let record_110_track = self.track_floats(g + 0x80, 272, HEADER_SIZE)?;

        Ok(SkyGroup {
            flags,
            ambient_tracks,
            directional_tracks,
            hemisphere_tracks,
            cone_tracks,
            array_0x48,
            array_0x58,
            sh_track,
            record_110_track,
        })
    }
}

/// Decode a `.sky` file from raw binary bytes.
pub fn read_sky(data: &[u8]) -> Result<SkyFile, String> {
    if data.len() < HEADER_SIZE {
        return Err(format!("SKY: file length {} too small for header 0x4C0", data.len()));
    }
    if &data[..4] != MAGIC {
        return Err(format!("SKY: invalid magic {:?}, expected YKSX", &data[..4]));
    }
    let reader = Reader::new(data);
    let version = reader.u32_at(4)?;
    if version != SUPPORTED_VERSION {
        return Err(format!("SKY: unsupported version {version}, expected {SUPPORTED_VERSION}"));
    }

    let source_xml = reader.string(0x18, HEADER_SIZE)?;
    let header_words = [
        reader.u32_at(8)?,
        reader.u32_at(12)?,
        reader.u32_at(16)?,
        reader.u32_at(20)?,
    ];
    let header_10_float = reader.f32_at(16)?;

    let lighting_group = reader.read_group(0x28)?;
    let sky_group = reader.read_group(0xC0)?;
    let fog_group = reader.read_group(0x158)?;
    let cloud_group = reader.read_group(0x1F0)?;

    let ambient = reader.track_floats(0x288, 16, HEADER_SIZE)?;
    let sun_diffuse = reader.track_floats(0x2A0, 32, HEADER_SIZE)?;
    let sun_specular = reader.track_floats(0x2B8, 16, HEADER_SIZE)?;
    let fog_distance = reader.track_floats(0x2D0, 24, HEADER_SIZE)?;

    // Models: AP of 48-byte structs at 0x2E8. Base = end of descriptor array
    let (model_count, model_start) = reader.ap(0x2E8, 48, HEADER_SIZE)?;
    let model_base = model_start + model_count * 48;
    let mut models = Vec::with_capacity(model_count);
    for i in 0..model_count {
        let p = model_start + i * 48;
        let header_words = [reader.u32_at(p)?, reader.u32_at(p + 4)?];
        let path = reader.string(p + 8, model_base)?;
        let track = reader.track_floats(p + 24, 32, model_base)?;
        models.push(SkyModel {
            header_words,
            path,
            track,
        });
    }

    let screen = reader.track_floats(0x2F8, 96, HEADER_SIZE)?;
    let cloud_set_id = reader.track_u32(0x310, HEADER_SIZE)?;
    let cloud_alpha = reader.track_floats(0x328, 4, HEADER_SIZE)?;

    // Particulates: AP of 16-byte string APs at 0x340. Base = end of descriptor array
    let (part_count, part_start) = reader.ap(0x340, 16, HEADER_SIZE)?;
    let part_base = part_start + part_count * 16;
    let mut particulates = Vec::with_capacity(part_count);
    for i in 0..part_count {
        let p = part_start + i * 16;
        particulates.push(reader.string(p, part_base)?);
    }

    let env_map_tex = reader.string(0x350, HEADER_SIZE)?;
    let sun_glare = reader.track_floats(0x360, 16, HEADER_SIZE)?;
    let sun_glare_model1 = reader.string(0x378, HEADER_SIZE)?;
    let sun_glare_model2 = reader.string(0x388, HEADER_SIZE)?;
    let window_glow = reader.track_floats(0x398, 4, HEADER_SIZE)?;
    let night_ambient = reader.track_floats(0x3B0, 16, HEADER_SIZE)?;
    let horizon_fog_mod = reader.track_floats(0x3C8, 16, HEADER_SIZE)?;

    let liquid_colors = [
        reader.track_floats(0x3E0 + 24 * 0, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 1, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 2, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 3, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 4, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 5, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 6, 32, HEADER_SIZE)?,
        reader.track_floats(0x3E0 + 24 * 7, 32, HEADER_SIZE)?,
    ];

    // Wind spawns at 0x4A0 (AP of Track8)
    let (wind_count, wind_start) = reader.ap(0x4A0, 24, HEADER_SIZE)?;
    let wind_base = (wind_start + wind_count * 24 + 15) & !15;
    let mut wind_spawns = Vec::with_capacity(wind_count);
    for i in 0..wind_count {
        let p = wind_start + i * 24;
        let count = reader.u32_at(p)? as usize;
        let times_offset = reader.u64_at(p + 8)? as usize;
        let values_offset = reader.u64_at(p + 16)? as usize;
        if count == 0 {
            wind_spawns.push(WindSpawnTrack { times: Vec::new(), wind_pairs: Vec::new() });
            continue;
        }
        let t_start = wind_base.checked_add(times_offset).ok_or("SKY: wind times overflow")?;
        let v_start = wind_base.checked_add(values_offset).ok_or("SKY: wind values overflow")?;
        let mut times = Vec::with_capacity(count);
        let mut wind_pairs = Vec::with_capacity(count);
        for j in 0..count {
            times.push(reader.u32_at(t_start + j * 4)?);
            let w0 = reader.u32_at(v_start + j * 8)?;
            let w1 = reader.u32_at(v_start + j * 8 + 4)?;
            wind_pairs.push((w0, w1));
        }
        wind_spawns.push(WindSpawnTrack { times, wind_pairs });
    }

    let color_lut_tex = reader.string(0x4B0, HEADER_SIZE)?;

    Ok(SkyFile {
        version,
        source_xml,
        header_words,
        header_10_float,
        lighting_group,
        sky_group,
        fog_group,
        cloud_group,
        ambient,
        sun_diffuse,
        sun_specular,
        fog_distance,
        models,
        screen,
        cloud_set_id,
        cloud_alpha,
        particulates,
        env_map_tex,
        sun_glare,
        sun_glare_model1,
        sun_glare_model2,
        window_glow,
        night_ambient,
        horizon_fog_mod,
        liquid_colors,
        wind_spawns,
        color_lut_tex,
    })
}

/// AREA blocks 6/7: merge corner WorldSky IDs and weights, keeping up to four dominant contributions.
/// `ids_block`: 4 corners * 4 u32 IDs (64 bytes or [[u32; 4]; 4])
/// `weights_block`: 4 corners * 4 u8 weights (16 bytes or [[u8; 4]; 4])
/// `u`, `v`: normalized cell coordinates in 0.0..1.0.
pub fn blend_cell_sky_weights(
    corner_ids: &[[u32; 4]; 4],
    corner_weights: &[[u8; 4]; 4],
    u: f32,
    v: f32,
) -> Vec<(u32, f32)> {
    let u = u.clamp(0.0, 1.0);
    let v = v.clamp(0.0, 1.0);
    let corner_factors = [
        (1.0 - u) * (1.0 - v),
        u * (1.0 - v),
        (1.0 - u) * v,
        u * v,
    ];

    let mut contributions: HashMap<u32, f32> = HashMap::new();
    for (corner_idx, &factor) in corner_factors.iter().enumerate() {
        for slot in 0..4 {
            let id = corner_ids[corner_idx][slot];
            let weight = corner_weights[corner_idx][slot];
            if id != 0 && weight > 0 {
                let spatial_weight = (weight as f32 / 255.0) * factor;
                *contributions.entry(id).or_insert(0.0) += spatial_weight;
            }
        }
    }

    let mut list: Vec<(u32, f32)> = contributions.into_iter().filter(|(_, w)| *w > 0.0).collect();
    // Sort descending by weight
    list.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap_or(std::cmp::Ordering::Equal));
    list.truncate(4);
    list
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rejects_too_short_or_invalid_magic() {
        assert!(read_sky(b"").is_err());
        assert!(read_sky(b"YKSX").is_err());
        let mut d = vec![0u8; 0x4C0];
        assert!(read_sky(&d).is_err()); // bad magic
        d[..4].copy_from_slice(b"YKSX");
        d[4..8].copy_from_slice(&15u32.to_le_bytes());
        assert!(read_sky(&d).is_err()); // unsupported version 15
    }

    #[test]
    fn parses_minimal_valid_sky() {
        let mut d = vec![0u8; 0x4C0];
        d[..4].copy_from_slice(b"YKSX");
        d[4..8].copy_from_slice(&16u32.to_le_bytes()); // version 16
        let sky = read_sky(&d).expect("minimal header should parse");
        assert_eq!(sky.version, 16);
        assert!(sky.source_xml.is_empty());
        assert!(sky.models.is_empty());
        assert!(sky.ambient.is_empty());
    }

    #[test]
    fn track_linear_sampling() {
        let track = Track {
            times: vec![0, 100, 200],
            values: vec![vec![0.0, 10.0], vec![50.0, 20.0], vec![100.0, 40.0]],
        };
        // Clamping
        assert_eq!(track.sample(-10.0).unwrap(), vec![0.0, 10.0]);
        assert_eq!(track.sample(250.0).unwrap(), vec![100.0, 40.0]);
        // Exact
        assert_eq!(track.sample(100.0).unwrap(), vec![50.0, 20.0]);
        // Midpoint
        let mid = track.sample(50.0).unwrap();
        assert!((mid[0] - 25.0).abs() < 1e-5);
        assert!((mid[1] - 15.0).abs() < 1e-5);
    }

    #[test]
    fn resource_track_cyclic_sampling() {
        let track = Track {
            times: vec![10000, 50000],
            values: vec![101, 202],
        };
        // Exact
        assert_eq!(track.sample_resources(10000), vec![(101, 1.0)]);
        // In between
        let mid = track.sample_resources(30000);
        assert_eq!(mid.len(), 2);
        assert_eq!(mid[0].0, 101);
        assert_eq!(mid[1].0, 202);
        assert!((mid[0].1 - 0.5).abs() < 1e-4);
        assert!((mid[1].1 - 0.5).abs() < 1e-4);

        // Cyclic across midnight (e.g. 50000 to next day 10000 => span = 86400 - 50000 + 10000 = 46400)
        let night = track.sample_resources(73200);
        assert_eq!(night.len(), 2);
        assert_eq!(night[0].0, 202);
        assert_eq!(night[1].0, 101);
        assert!((night[0].1 - 0.5).abs() < 1e-4);
        assert!((night[1].1 - 0.5).abs() < 1e-4);
    }

    #[test]
    fn blends_area_corners() {
        let ids = [
            [10, 0, 0, 0],
            [10, 20, 0, 0],
            [30, 0, 0, 0],
            [20, 0, 0, 0],
        ];
        let weights = [
            [255, 0, 0, 0],
            [128, 127, 0, 0],
            [255, 0, 0, 0],
            [255, 0, 0, 0],
        ];
        let blended = blend_cell_sky_weights(&ids, &weights, 0.0, 0.0);
        assert_eq!(blended.len(), 1);
        assert_eq!(blended[0].0, 10);
        assert!((blended[0].1 - 1.0).abs() < 1e-3);
    }
}

    #[test]
    fn parses_synthetic_full_sky() {
        // Construct a synthetic XSKY file with source xml, top tracks, models, particulates, and wind spawns
        let mut d = vec![0u8; 0x4C0 + 512];
        d[..4].copy_from_slice(b"YKSX");
        d[4..8].copy_from_slice(&16u32.to_le_bytes());

        // Source XML string at 0x18: AP count=4, offset=0 (relative to 0x4C0)
        let xml_str = "test\0";
        let xml_utf16: Vec<u16> = xml_str.encode_utf16().collect();
        d[0x18..0x1C].copy_from_slice(&(xml_utf16.len() as u32).to_le_bytes());
        d[0x20..0x28].copy_from_slice(&0u64.to_le_bytes()); // offset 0 -> 0x4C0
        for (i, &unit) in xml_utf16.iter().enumerate() {
            let pos = 0x4C0 + i * 2;
            d[pos..pos + 2].copy_from_slice(&unit.to_le_bytes());
        }

        // Ambient track at 0x288: 1 key at 0x4C0 + 32, value at 0x4C0 + 48
        d[0x288..0x28C].copy_from_slice(&1u32.to_le_bytes());
        d[0x290..0x298].copy_from_slice(&32u64.to_le_bytes()); // times offset
        d[0x298..0x2A0].copy_from_slice(&48u64.to_le_bytes()); // values offset

        // time key = 43200 (12:00)
        d[0x4C0 + 32..0x4C0 + 36].copy_from_slice(&43200u32.to_le_bytes());
        // RGBA floats (1.0, 0.5, 0.25, 1.0)
        let rgba = [1.0f32, 0.5f32, 0.25f32, 1.0f32];
        for (i, &f) in rgba.iter().enumerate() {
            let pos = 0x4C0 + 48 + i * 4;
            d[pos..pos + 4].copy_from_slice(&f.to_le_bytes());
        }

        let sky = read_sky(&d).expect("valid synthetic sky");
        assert_eq!(sky.version, 16);
        assert_eq!(sky.source_xml, "test");
        assert_eq!(sky.ambient.len(), 1);
        assert_eq!(sky.ambient.times[0], 43200);
        let sampled = sky.ambient.sample(43200.0).unwrap();
        assert_eq!(sampled, vec![1.0, 0.5, 0.25, 1.0]);
    }
