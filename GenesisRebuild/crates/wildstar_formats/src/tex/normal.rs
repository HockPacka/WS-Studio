//! Normal-map channel interpretation for WildStar TEX model materials.
//! Unlike the old per-pixel heuristic, encoding is selected once per image:
//! an RGB normal must not switch to alpha/green interpretation on a single
//! gray pixel or a pixel whose alpha is below 255.
//!
//! DXT5nm-style maps store tangent X in A and Y in G; Z is reconstructed.
//! In the original client these may also be stored uncompressed. We infer
//! packing conservatively from channel statistics, never compression alone.
use super::{decode_tex, RgbaImage};

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum NormalEncoding {
    /// RGB channels carry the tangent-space XYZ normal.
    Rgb,
    /// Alpha carries X; green carries Y; Z is reconstructed.
    AlphaGreen,
}

/// Classification across the whole image. Packed maps tend to leave red
/// and blue as (nearly) constant high/low dummy channels, while alpha
/// carries actual X variation. A constant non-opaque alpha near 128 is
/// also valid for an almost-flat packed map. Ambiguity defaults to RGB.
pub fn classify_normal_encoding(img: &RgbaImage) -> NormalEncoding {
    if img.rgba.len() < 4 {
        return NormalEncoding::Rgb;
    }
    let pixels = img.rgba.chunks_exact(4);
    let stride = pixels.len().div_ceil(16_384).max(1);
    let mut lo = [255_u8; 4];
    let mut hi = [0_u8; 4];
    let mut samples = 0_usize;
    for pixel in pixels.step_by(stride) {
        for channel in 0..4 {
            lo[channel] = lo[channel].min(pixel[channel]);
            hi[channel] = hi[channel].max(pixel[channel]);
        }
        samples += 1;
    }
    if samples == 0 {
        return NormalEncoding::Rgb;
    }
    let red_dummy = hi[0].saturating_sub(lo[0]) <= 20
        && (lo[0] >= 230 || hi[0] <= 24);
    let blue_dummy = hi[2].saturating_sub(lo[2]) <= 20
        && (lo[2] >= 230 || hi[2] <= 24);
    let alpha_range = hi[3].saturating_sub(lo[3]);
    let alpha_has_normal = lo[3] < 240 &&
        (alpha_range > 8 || (lo[3] >= 96 && hi[3] <= 160));
    if red_dummy && blue_dummy && alpha_has_normal {
        NormalEncoding::AlphaGreen
    } else {
        NormalEncoding::Rgb
    }
}

fn unit_normal(px: [u8; 4], encoding: NormalEncoding) -> [f32; 3] {
    let (mut x, mut y, mut z) = match encoding {
        NormalEncoding::Rgb => (
            px[0] as f32 / 127.5 - 1.0,
            px[1] as f32 / 127.5 - 1.0,
            px[2] as f32 / 127.5 - 1.0,
        ),
        NormalEncoding::AlphaGreen => {
            let x = px[3] as f32 / 127.5 - 1.0;
            let y = px[1] as f32 / 127.5 - 1.0;
            (x, y, (1.0 - x * x - y * y).max(0.0).sqrt())
        },
    };
    let size = (x * x + y * y + z * z).sqrt();
    if size <= 1.0e-6 || !size.is_finite() {
        return [0.0, 0.0, 1.0];
    }
    x /= size;
    y /= size;
    z /= size;
    [x, y, z]
}

/// Re-encode tangent-space normals into *linear*, Bevy-compatible RGBA.
/// This only operates on model normal-map assets, not diffuse alpha or
/// terrain textures. The resulting texture must use Rgba8Unorm (not sRGB).
pub fn convert_normal_image(image: &mut RgbaImage, mode: NormalEncoding) {
    for pixel in image.rgba.chunks_exact_mut(4) {
        let original = [pixel[0], pixel[1], pixel[2], pixel[3]];
        let n = unit_normal(original, mode);
        for axis in 0..3 {
            pixel[axis] = ((n[axis] * 0.5 + 0.5) * 255.0)
                .round().clamp(0.0, 255.0) as u8;
        }
        pixel[3] = 255;
    }
}

/// Decode an ordinary WildStar TEX and convert its normals with one
/// texture-wide encoding decision. Return that decision for diagnostics.
pub fn decode_normal_tex(bytes: &[u8], max_size: usize)
    -> Result<(RgbaImage, NormalEncoding), String>
{
    let mut image = decode_tex(bytes, max_size)?;
    let mode = classify_normal_encoding(&image);
    convert_normal_image(&mut image, mode);
    Ok((image, mode))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn image(pixels: &[[u8; 4]]) -> RgbaImage {
        RgbaImage {
            width: pixels.len(), height: 1,
            rgba: pixels.iter().flatten().copied().collect(),
        }
    }

    #[test]
    fn rgb_gray_pixel_does_not_switch_encoding() {
        let mut map = image(&[
            [128, 128, 128, 255], [140, 110, 244, 100],
            [128, 128, 255, 255], [90, 150, 238, 64],
        ]);
        assert_eq!(classify_normal_encoding(&map), NormalEncoding::Rgb);
        convert_normal_image(&mut map, NormalEncoding::Rgb);
        // The gray pixel must be interpreted as RGB, not as packed XY.
        assert_eq!(&map.rgba[..4], &[147, 147, 147, 255]);
    }

    #[test]
    fn packed_alpha_green_is_chosen_once_for_all_pixels() {
        let mut map = image(&[
            [255, 128, 255, 64], [255, 128, 255, 255],
            [255, 128, 255, 192], [255, 128, 255, 128],
        ]);
        let mode = classify_normal_encoding(&map);
        assert_eq!(mode, NormalEncoding::AlphaGreen);
        convert_normal_image(&mut map, mode);
        // A pixel with alpha=255 still follows the *same* map packing.
        assert!(map.rgba[4] >= 250);
        assert!(map.rgba[6] <= 140);
        // Flat normal in the same packed texture points +Z.
        assert!(map.rgba[12].abs_diff(128) <= 1);
        assert!(map.rgba[14] >= 254);
    }

    #[test]
    fn rgb_opaque_map_keeps_rgb_encoding() {
        let map = image(&[[128, 128, 255, 255]; 4]);
        assert_eq!(classify_normal_encoding(&map), NormalEncoding::Rgb);
    }

    #[test]
    fn packed_xy_out_of_disc_produces_finite_unit_normal() {
        let mut map = image(&[[255, 255, 255, 255]]);
        convert_normal_image(&mut map, NormalEncoding::AlphaGreen);
        assert!(map.rgba[0] >= 218 && map.rgba[1] >= 218);
        assert_eq!(map.rgba[3], 255);
    }

    #[test]
    fn rejects_invalid_tex_container() {
        assert!(decode_normal_tex(b"invalid", 512).is_err());
    }
}
