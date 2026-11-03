//! Common radial mask + universal Custom Brush Tip loader & sampler.
//! Supports WildStar `.tex`, PNG, TIFF, BMP, TGA, DDS (BC1/BC2/BC3/BC4/RGBA/L8),
//! HDR, ICO, PNM/PGM/PPM, Farbfeld, JPEG/WebP/GIF, RAW/R16/R8/F32 heightfields,
//! ASCII grids, and arbitrary binary files.

use std::path::Path;
use std::sync::{Mutex, OnceLock};

#[derive(Clone, Debug)]
pub struct CustomBrushTip {
    pub name: String,
    pub format_label: String,
    pub width: usize,
    pub height: usize,
    pub weights: Vec<f32>,
    pub preview_rgba: Vec<u8>,
    pub revision: u64,
}

static CUSTOM_TIP: OnceLock<Mutex<Option<CustomBrushTip>>> = OnceLock::new();
static NEXT_REVISION: std::sync::atomic::AtomicU64 = std::sync::atomic::AtomicU64::new(1);

fn tip_slot() -> &'static Mutex<Option<CustomBrushTip>> {
    CUSTOM_TIP.get_or_init(|| Mutex::new(None))
}

pub fn influence(distance:f32,radius:f32,hardness:f32,falloff:f32)->f32 {
    if !distance.is_finite() || !radius.is_finite() || radius<=0.0 ||
       !hardness.is_finite() || !falloff.is_finite() {return 0.0;}
    let d=distance.max(0.0);
    if d>=radius{return 0.0;}
    let h=hardness.clamp(0.0,1.0);
    if d<=h*radius{return 1.0;}
    let t=((d/radius-h)/(1.0-h).max(f32::EPSILON)).clamp(0.0,1.0);
    let smoothed=1.0-t*t*(3.0-2.0*t);
    smoothed.powf(1.0+falloff.clamp(0.0,1.0)*4.0)
}

/// Bilinearly sample the active custom brush tip at normalized coordinates `(u, v)` in `0.0..=1.0`.
/// Falls back to a procedural diamond/organic tip if no external brush file has been loaded.
pub fn sample_tip_uv(u: f32, v: f32) -> f32 {
    if let Ok(guard) = tip_slot().lock() {
        if let Some(tip) = guard.as_ref() {
            return sample_grid_bilinear(&tip.weights, tip.width, tip.height, u, v);
        }
    }
    let cu = (u.clamp(0.0, 1.0) - 0.5) * 2.0;
    let cv = (v.clamp(0.0, 1.0) - 0.5) * 2.0;
    let diamond = (1.0 - (cu.abs() + cv.abs()) * 0.72).clamp(0.0, 1.0);
    let ripple = ((cu * std::f32::consts::PI * 3.0).cos() * (cv * std::f32::consts::PI * 3.0).cos()) * 0.25 + 0.75;
    (diamond * ripple).clamp(0.15, 1.0)
}

fn sample_grid_bilinear(weights: &[f32], w: usize, h: usize, u: f32, v: f32) -> f32 {
    if w == 0 || h == 0 || weights.len() < w * h {
        return 1.0;
    }
    let u = u.clamp(0.0, 1.0);
    let v = v.clamp(0.0, 1.0);
    let fx = u * (w.saturating_sub(1)) as f32;
    let fy = v * (h.saturating_sub(1)) as f32;
    let x0 = (fx.floor() as usize).min(w - 1);
    let y0 = (fy.floor() as usize).min(h - 1);
    let x1 = (x0 + 1).min(w - 1);
    let y1 = (y0 + 1).min(h - 1);
    let sx = fx - x0 as f32;
    let sy = fy - y0 as f32;
    let v00 = weights[y0 * w + x0];
    let v10 = weights[y0 * w + x1];
    let v01 = weights[y1 * w + x0];
    let v11 = weights[y1 * w + x1];
    let top = v00 + (v10 - v00) * sx;
    let bot = v01 + (v11 - v01) * sx;
    (top + (bot - top) * sy).clamp(0.0, 1.0)
}

pub fn clear_custom_tip() {
    if let Ok(mut guard) = tip_slot().lock() {
        *guard = None;
    }
}

pub fn custom_tip_info() -> Option<(String, String, u64)> {
    let guard = tip_slot().lock().ok()?;
    let tip = guard.as_ref()?;
    Some((tip.name.clone(), tip.format_label.clone(), tip.revision))
}

pub fn custom_tip_preview() -> Option<(u64, usize, usize, Vec<u8>)> {
    let guard = tip_slot().lock().ok()?;
    let tip = guard.as_ref()?;
    Some((tip.revision, tip.width, tip.height, tip.preview_rgba.clone()))
}

pub fn load_custom_tip_from_path(path: &Path) -> Result<String, String> {
    let bytes = std::fs::read(path)
        .map_err(|e| format!("Failed to read {}: {e}", path.display()))?;
    let name = path
        .file_name()
        .and_then(|s| s.to_str())
        .unwrap_or("brush_tip")
        .to_string();
    load_custom_tip_from_bytes(&name, &bytes)
}

pub fn load_custom_tip_from_bytes(name: &str, bytes: &[u8]) -> Result<String, String> {
    let tip = decode_any_brush_tip(name, bytes)?;
    let summary = format!("{} ({})", tip.name, tip.format_label);
    if let Ok(mut guard) = tip_slot().lock() {
        *guard = Some(tip);
    }
    Ok(summary)
}

pub fn decode_any_brush_tip(name: &str, bytes: &[u8]) -> Result<CustomBrushTip, String> {
    if bytes.is_empty() {
        return Err("Brush file is empty (0 bytes)".into());
    }

    // 1. Native WildStar .tex format (\0GFX or XFG\0)
    if bytes.len() >= 112 && (bytes.get(1..4) == Some(b"GFX") || bytes.get(0..3) == Some(b"XFG")) {
        if let Ok(img) = wildstar_formats::tex::decode_tex(bytes, 512) {
            return Ok(build_tip_from_rgba(
                name,
                format!("WildStar TEX {}×{}", img.width, img.height),
                img.width,
                img.height,
                &img.rgba,
            ));
        }
    }

    // 2. Standard image formats via `image` crate (PNG, TIFF, BMP, TGA, DDS, HDR, ICO, PNM, Farbfeld)
    if let Ok(dyn_img) = image::load_from_memory(bytes) {
        let rgba = dyn_img.to_rgba8();
        let w = rgba.width() as usize;
        let h = rgba.height() as usize;
        if w > 0 && h > 0 {
            let resized = if w > 512 || h > 512 {
                let scaled = image::imageops::resize(
                    &rgba,
                    w.min(512) as u32,
                    h.min(512) as u32,
                    image::imageops::FilterType::Triangle,
                );
                let sw = scaled.width() as usize;
                let sh = scaled.height() as usize;
                return Ok(build_tip_from_rgba(
                    name,
                    format!("Image {}×{}", w, h),
                    sw,
                    sh,
                    scaled.as_raw(),
                ));
            } else {
                rgba
            };
            return Ok(build_tip_from_rgba(
                name,
                format!("Image {}×{}", w, h),
                w,
                h,
                resized.as_raw(),
            ));
        }
    }

    // 3. Explicit TGA / BMP / DDS fallback decoders (in case header variants or BC formats were skipped)
    if bytes.starts_with(b"DDS ") {
        if let Ok((w, h, rgba, kind)) = decode_dds_fallback(bytes) {
            return Ok(build_tip_from_rgba(
                name,
                format!("DDS {kind} {w}×{h}"),
                w,
                h,
                &rgba,
            ));
        }
    }
    if let Some(ext) = Path::new(name).extension().and_then(|s| s.to_str()) {
        if ext.eq_ignore_ascii_case("tga") {
            if let Ok(img) = image::load_from_memory_with_format(bytes, image::ImageFormat::Tga) {
                let rgba = img.to_rgba8();
                return Ok(build_tip_from_rgba(
                    name,
                    format!("TGA {}×{}", rgba.width(), rgba.height()),
                    rgba.width() as usize,
                    rgba.height() as usize,
                    rgba.as_raw(),
                ));
            }
        }
    }

    // 4. ASCII / text height grids (.asc, .csv, .txt, .json, .pgm, .svg)
    if let Some(tip) = try_decode_ascii_grid(name, bytes) {
        return Ok(tip);
    }

    // 5. Raw square heightfields (.r16, .raw, .r8, .f32) & universal binary fallback
    Ok(decode_raw_or_universal_binary(name, bytes))
}

fn build_tip_from_rgba(
    name: &str,
    format_label: String,
    width: usize,
    height: usize,
    rgba: &[u8],
) -> CustomBrushTip {
    let count = width * height;
    let mut lum = Vec::with_capacity(count);
    let mut alpha = Vec::with_capacity(count);
    let mut min_a = 255u8;
    let mut max_a = 0u8;
    let mut min_l = 1.0f32;
    let mut max_l = 0.0f32;

    for px in rgba.chunks_exact(4).take(count) {
        let l = (0.299 * px[0] as f32 + 0.587 * px[1] as f32 + 0.114 * px[2] as f32) / 255.0;
        let a = px[3];
        min_a = min_a.min(a);
        max_a = max_a.max(a);
        min_l = min_l.min(l);
        max_l = max_l.max(l);
        lum.push(l);
        alpha.push(a as f32 / 255.0);
    }

    let use_alpha = (max_a.saturating_sub(min_a)) > 12;
    let use_lum = (max_l - min_l) > 0.04;

    let mut weights = Vec::with_capacity(count);
    let mut w_min = f32::INFINITY;
    let mut w_max = f32::NEG_INFINITY;
    for i in 0..count {
        let v = match (use_lum, use_alpha) {
            (true, true) => lum[i] * alpha[i],
            (false, true) => alpha[i],
            (true, false) => lum[i],
            (false, false) => 1.0,
        };
        w_min = w_min.min(v);
        w_max = w_max.max(v);
        weights.push(v);
    }

    let span = w_max - w_min;
    if span > 1e-4 {
        for w in &mut weights {
            *w = ((*w - w_min) / span).clamp(0.0, 1.0);
        }
    }

    build_tip_from_weights(name, format_label, width, height, weights)
}

fn build_tip_from_weights(
    name: &str,
    format_label: String,
    width: usize,
    height: usize,
    weights: Vec<f32>,
) -> CustomBrushTip {
    let mut preview_rgba = Vec::with_capacity(width * height * 4);
    for &w in &weights {
        let v = (w.clamp(0.0, 1.0) * 255.0).round() as u8;
        // Warm gold-tinted grayscale preview matching Genesis brush styling
        let r = v;
        let g = ((v as u16 * 225) / 255) as u8;
        let b = ((v as u16 * 155) / 255) as u8;
        preview_rgba.extend_from_slice(&[r, g, b, 255]);
    }
    let revision = NEXT_REVISION.fetch_add(1, std::sync::atomic::Ordering::Relaxed);
    CustomBrushTip {
        name: name.to_string(),
        format_label,
        width,
        height,
        weights,
        preview_rgba,
        revision,
    }
}

fn decode_dds_fallback(bytes: &[u8]) -> Result<(usize, usize, Vec<u8>, &'static str), String> {
    if bytes.len() < 128 || &bytes[0..4] != b"DDS " {
        return Err("Not a valid DDS header".into());
    }
    let height = (u32::from_le_bytes(bytes[12..16].try_into().unwrap()) as usize).clamp(1, 4096);
    let width = (u32::from_le_bytes(bytes[16..20].try_into().unwrap()) as usize).clamp(1, 4096);
    let fourcc = &bytes[84..88];
    let rgb_bits = u32::from_le_bytes(bytes[88..92].try_into().unwrap()) as usize;
    let data_offset = if fourcc == b"DX10" && bytes.len() >= 148 { 148 } else { 128 };
    let payload = &bytes[data_offset..];

    if fourcc == b"DXT1" {
        let rgba = decode_dxt_blocks(payload, width, height, 1)?;
        return Ok((width, height, rgba, "DXT1"));
    } else if fourcc == b"DXT3" {
        let rgba = decode_dxt_blocks(payload, width, height, 3)?;
        return Ok((width, height, rgba, "DXT3"));
    } else if fourcc == b"DXT5" {
        let rgba = decode_dxt_blocks(payload, width, height, 5)?;
        return Ok((width, height, rgba, "DXT5"));
    } else if rgb_bits == 8 && payload.len() >= width * height {
        let rgba = payload[..width * height]
            .iter()
            .flat_map(|&g| [g, g, g, 255])
            .collect();
        return Ok((width, height, rgba, "L8"));
    } else if rgb_bits == 32 && payload.len() >= width * height * 4 {
        let rgba = payload[..width * height * 4]
            .chunks_exact(4)
            .flat_map(|p| [p[2], p[1], p[0], p[3]])
            .collect();
        return Ok((width, height, rgba, "RGBA8"));
    }
    Err("Unsupported DDS subformat".into())
}

fn decode_dxt_blocks(input: &[u8], w: usize, h: usize, kind: usize) -> Result<Vec<u8>, String> {
    let bx_count = w.div_ceil(4);
    let by_count = h.div_ceil(4);
    let stride = if kind == 1 { 8 } else { 16 };
    let needed = bx_count.saturating_mul(by_count).saturating_mul(stride);
    if input.len() < needed {
        return Err("Truncated DXT payload".into());
    }
    let mut out = vec![0u8; w * h * 4];
    let c565 = |c: u16| -> [u8; 3] {
        let r = ((c >> 11) & 31) as u8;
        let g = ((c >> 5) & 63) as u8;
        let b = (c & 31) as u8;
        [(r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)]
    };
    for by in 0..by_count {
        for bx in 0..bx_count {
            let block = &input[(by * bx_count + bx) * stride..(by * bx_count + bx + 1) * stride];
            let color = if kind == 1 { block } else { &block[8..] };
            let a = u16::from_le_bytes([color[0], color[1]]);
            let b = u16::from_le_bytes([color[2], color[3]]);
            let ca = c565(a);
            let cb = c565(b);
            let mut pal = [[0u8; 4]; 4];
            pal[0] = [ca[0], ca[1], ca[2], 255];
            pal[1] = [cb[0], cb[1], cb[2], 255];
            for ch in 0..3 {
                pal[2][ch] = ((2 * ca[ch] as u16 + cb[ch] as u16) / 3) as u8;
                pal[3][ch] = ((ca[ch] as u16 + 2 * cb[ch] as u16) / 3) as u8;
            }
            pal[2][3] = 255;
            pal[3][3] = 255;
            let indices = u32::from_le_bytes(color[4..8].try_into().unwrap());
            for py in 0..4 {
                for px in 0..4 {
                    let x = bx * 4 + px;
                    let y = by * 4 + py;
                    if x >= w || y >= h { continue; }
                    let cell = py * 4 + px;
                    let ci = ((indices >> (2 * cell)) & 3) as usize;
                    out[(y * w + x) * 4..(y * w + x + 1) * 4].copy_from_slice(&pal[ci]);
                }
            }
        }
    }
    Ok(out)
}

fn try_decode_ascii_grid(name: &str, bytes: &[u8]) -> Option<CustomBrushTip> {
    if bytes.iter().take(256).any(|&b| b == 0) {
        return None;
    }
    let text = std::str::from_utf8(bytes).ok()?;
    let mut vals = Vec::new();
    for token in text.split(|c: char| !(c.is_ascii_digit() || c == '.' || c == '-' || c == '+')) {
        if token.is_empty() || token == "-" || token == "+" || token == "." {
            continue;
        }
        if let Ok(v) = token.parse::<f32>() {
            if v.is_finite() {
                vals.push(v);
            }
        }
        if vals.len() >= 262_144 {
            break;
        }
    }
    if vals.len() < 16 {
        return None;
    }
    let side = (vals.len() as f32).sqrt().floor() as usize;
    let side = side.clamp(4, 512);
    let count = side * side;
    let slice = &vals[..count];
    let min_v = slice.iter().copied().fold(f32::INFINITY, f32::min);
    let max_v = slice.iter().copied().fold(f32::NEG_INFINITY, f32::max);
    let span = (max_v - min_v).max(1e-5);
    let weights: Vec<f32> = slice.iter().map(|&v| ((v - min_v) / span).clamp(0.0, 1.0)).collect();
    Some(build_tip_from_weights(
        name,
        format!("ASCII Grid {side}×{side}"),
        side,
        side,
        weights,
    ))
}

fn decode_raw_or_universal_binary(name: &str, bytes: &[u8]) -> CustomBrushTip {
    let len = bytes.len();
    // Check if exact square 16-bit heightfield (.r16 / .raw)
    if len >= 32 && len % 2 == 0 {
        let samples = len / 2;
        let side = (samples as f64).sqrt().round() as usize;
        if side >= 4 && side <= 4096 && side * side == samples {
            let mut vals = Vec::with_capacity(samples);
            let mut min_v = u16::MAX;
            let mut max_v = u16::MIN;
            for c in bytes.chunks_exact(2) {
                let v = u16::from_le_bytes([c[0], c[1]]);
                min_v = min_v.min(v);
                max_v = max_v.max(v);
                vals.push(v);
            }
            let span = (max_v.saturating_sub(min_v)).max(1) as f32;
            let weights: Vec<f32> = vals
                .into_iter()
                .map(|v| ((v.saturating_sub(min_v)) as f32 / span).clamp(0.0, 1.0))
                .collect();
            let capped = downsample_if_needed(&weights, side, side, 512);
            return build_tip_from_weights(
                name,
                format!("RAW 16-bit {}×{}", capped.1, capped.2),
                capped.1,
                capped.2,
                capped.0,
            );
        }
    }

    // Check if exact square 8-bit grayscale heightfield (.r8 / .raw)
    if len >= 16 {
        let side = (len as f64).sqrt().round() as usize;
        if side >= 4 && side <= 4096 && side * side == len {
            let min_v = *bytes.iter().min().unwrap_or(&0);
            let max_v = *bytes.iter().max().unwrap_or(&255);
            let span = (max_v.saturating_sub(min_v)).max(1) as f32;
            let weights: Vec<f32> = bytes
                .iter()
                .map(|&v| ((v.saturating_sub(min_v)) as f32 / span).clamp(0.0, 1.0))
                .collect();
            let capped = downsample_if_needed(&weights, side, side, 512);
            return build_tip_from_weights(
                name,
                format!("RAW 8-bit {}×{}", capped.1, capped.2),
                capped.1,
                capped.2,
                capped.0,
            );
        }
    }

    // Universal binary resampler: converts ANY arbitrary file into a smooth 64×64 brush tip mask
    let side = 64usize;
    let count = side * side;
    let mut weights = vec![0.0f32; count];
    let mut min_v = f32::INFINITY;
    let mut max_v = f32::NEG_INFINITY;
    for i in 0..count {
        let src_idx = (i * len) / count;
        let b0 = bytes[src_idx.min(len - 1)] as f32;
        let b1 = bytes[(src_idx + 1).min(len - 1)] as f32;
        let v = (b0 * 0.7 + b1 * 0.3) / 255.0;
        min_v = min_v.min(v);
        max_v = max_v.max(v);
        weights[i] = v;
    }
    let span = (max_v - min_v).max(1e-4);
    for y in 0..side {
        for x in 0..side {
            let idx = y * side + x;
            let norm = ((weights[idx] - min_v) / span).clamp(0.0, 1.0);
            // Apply radial envelope so arbitrary binary files still have clean brush edges
            let dx = (x as f32 / (side - 1) as f32) * 2.0 - 1.0;
            let dy = (y as f32 / (side - 1) as f32) * 2.0 - 1.0;
            let radial = (1.0 - (dx * dx + dy * dy).sqrt().clamp(0.0, 1.0)).powf(0.6);
            weights[idx] = (norm * 0.75 + 0.25) * radial;
        }
    }
    build_tip_from_weights(
        name,
        format!("Custom Binary {side}×{side}"),
        side,
        side,
        weights,
    )
}

fn downsample_if_needed(weights: &[f32], w: usize, h: usize, max_side: usize) -> (Vec<f32>, usize, usize) {
    if w <= max_side && h <= max_side {
        return (weights.to_vec(), w, h);
    }
    let nw = w.min(max_side);
    let nh = h.min(max_side);
    let mut out = Vec::with_capacity(nw * nh);
    for y in 0..nh {
        let v = y as f32 / (nh.saturating_sub(1).max(1)) as f32;
        for x in 0..nw {
            let u = x as f32 / (nw.saturating_sub(1).max(1)) as f32;
            out.push(sample_grid_bilinear(weights, w, h, u, v));
        }
    }
    (out, nw, nh)
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn full_strength_within_inner_circle_zero_at_outer_circle(){
        for h in [0.0, 0.3, 0.6, 0.95] {
            assert_eq!(influence(0.0, 10.0, h, 0.5), 1.0);
            assert_eq!(influence(10.0 * h, 10.0, h, 0.5), 1.0);
            assert_eq!(influence(10.0, 10.0, h, 0.5), 0.0);
        }
    }
    #[test]
    fn edge_is_smooth_and_falloff_changes_only_feather(){
        assert_eq!(influence(4.0,10.0,0.5,0.0),1.0);
        assert_eq!(influence(4.0,10.0,0.5,1.0),1.0);
        let low=influence(8.0,10.0,0.5,0.0);
        let high=influence(8.0,10.0,0.5,1.0);
        assert!(low>high && high>0.0);
        for d in 0..99 {assert!(influence(d as f32/10.0,10.0,0.5,0.5)
            >=influence((d+1) as f32/10.0,10.0,0.5,0.5));}
    }
    #[test]
    fn invalid_input_is_safe(){
        assert_eq!(influence(1.0,0.0,0.5,0.5),0.0);
        assert_eq!(influence(f32::NAN,10.0,0.5,0.5),0.0);
        assert_eq!(influence(5.0,10.0,f32::NAN,0.5),0.0);
        assert_eq!(influence(9.9,10.0,1.0,0.0),1.0);
    }
    #[test]
    fn loads_custom_brush_from_tex_raw_ascii_and_arbitrary_formats() {
        // 1. WildStar .tex
        let mut tex = vec![0u8; 112];
        tex[..4].copy_from_slice(b"\0GFX");
        tex[4..8].copy_from_slice(&3u32.to_le_bytes());
        tex[8..12].copy_from_slice(&4u32.to_le_bytes());
        tex[12..16].copy_from_slice(&4u32.to_le_bytes());
        tex[24..28].copy_from_slice(&1u32.to_le_bytes());
        tex[28..32].copy_from_slice(&6u32.to_le_bytes()); // L8 grayscale
        for i in 0..16u8 {
            tex.push(i * 16);
        }
        let summary = load_custom_tip_from_bytes("stamp.tex", &tex).unwrap();
        assert!(summary.contains("WildStar TEX"));
        assert!(sample_tip_uv(0.0, 0.0) < sample_tip_uv(1.0, 1.0));

        // 2. 16-bit RAW heightfield (.r16)
        let mut r16 = Vec::new();
        for i in 0..64u16 {
            r16.extend_from_slice(&(i * 1000).to_le_bytes());
        }
        let summary = load_custom_tip_from_bytes("height.r16", &r16).unwrap();
        assert!(summary.contains("RAW 16-bit 8×8"));

        // 3. ASCII grid (.asc / .txt)
        let ascii = b"0.0 0.2 0.5 1.0\n0.1 0.4 0.8 1.0\n0.2 0.6 0.9 1.0\n0.3 0.7 1.0 1.0";
        let summary = load_custom_tip_from_bytes("grid.asc", ascii).unwrap();
        assert!(summary.contains("ASCII Grid 4×4"));

        // 4. Arbitrary unknown binary format (.xyz)
        let arbitrary = vec![42u8, 128, 255, 10, 99, 200, 15, 77, 190];
        let summary = load_custom_tip_from_bytes("any_file.xyz", &arbitrary).unwrap();
        assert!(summary.contains("Custom Binary 64×64"));
        clear_custom_tip();
    }
}

