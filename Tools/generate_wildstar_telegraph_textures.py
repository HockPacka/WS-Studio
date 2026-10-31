import struct
import numpy as np
from PIL import Image
import os

def write_blp_with_mips(filepath, base_rgba):
    """
    Writes a valid BLP2 (COLOR_RAW = 3, ARGB8888 = 1) file with full mipmap chain
    from 512x512 down to 1x1 (10 levels).
    Eliminates moiré patterns, shimmering, and aliasing in DirectX 9.
    """
    w, h = 512, 512
    img = Image.fromarray(base_rgba, 'RGBA')
    
    header_size = 148 + 1024 # 1172 bytes
    header = bytearray(header_size)
    
    mip_data_list = []
    mip_offsets = [0] * 16
    mip_sizes = [0] * 16
    
    cur_offset = header_size
    cur_w, cur_h = w, h
    cur_img = img
    
    for level in range(10): # 512 -> 256 -> 128 -> 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
        if level > 0:
            cur_img = cur_img.resize((cur_w, cur_h), Image.Resampling.LANCZOS)
        
        arr = np.array(cur_img, dtype=np.uint8)
        # Convert RGBA to BGRA for Direct3D 9 ARGB8888 format
        bgra = np.zeros_like(arr)
        bgra[:, :, 0] = arr[:, :, 2] # B
        bgra[:, :, 1] = arr[:, :, 1] # G
        bgra[:, :, 2] = arr[:, :, 0] # R
        bgra[:, :, 3] = arr[:, :, 3] # A
        
        raw_bytes = bgra.tobytes()
        mip_offsets[level] = cur_offset
        mip_sizes[level] = len(raw_bytes)
        cur_offset += len(raw_bytes)
        mip_data_list.append(raw_bytes)
        
        cur_w = max(1, cur_w // 2)
        cur_h = max(1, cur_h // 2)

    # Pack BLP2 Header:
    # m_magic: 'BLP2', formatVersion: 1, colorEncoding: 3 (RAW), alphaSize: 8, preferredFormat: 1, hasMips: 1, width: 512, height: 512
    struct.pack_into('<4sIBBBBI I', header, 0, b'BLP2', 1, 3, 8, 1, 1, w, h)
    
    for i in range(16):
        struct.pack_into('<I', header, 0x14 + i * 4, mip_offsets[i])
    for i in range(16):
        struct.pack_into('<I', header, 0x54 + i * 4, mip_sizes[i])

    with open(filepath, 'wb') as f:
        f.write(header)
        for d in mip_data_list:
            f.write(d)
            
    print(f"[+] Wrote HD Mipmapped BLP: {filepath} ({len(header) + sum(mip_sizes)} bytes, 10 mip levels)")

def draw_laser_line(canvas, d_line, line_width=6.0, intensity=1.0):
    """
    Authentic WildStar Laser Neon Line:
    - Hot white-yellow core with exponential decay
    - Glowing vibrant neon red-orange bloom halo
    - Silky smooth anti-aliased edge
    """
    bloom = np.exp(- (d_line / (line_width * 0.55))**2)
    core = np.exp(- (d_line / (line_width * 0.20))**2)
    
    neon_orange = np.array([255.0, 75.0, 10.0])   # Blazing neon red-orange
    hot_yellow  = np.array([255.0, 250.0, 190.0]) # Brilliant laser core
    
    rim_rgb = neon_orange * (1.0 - core[:, :, None]) + hot_yellow * core[:, :, None]
    rim_alpha = (bloom * 0.75 + core * 0.25) * 255.0 * intensity
    
    is_affected = d_line < (line_width * 2.5)
    canvas[is_affected, :3] = np.maximum(canvas[is_affected, :3], rim_rgb[is_affected])
    canvas[is_affected, 3] = np.maximum(canvas[is_affected, 3], rim_alpha[is_affected])

def create_shape_textures():
    SIZE = 512
    y_coords, x_coords = np.mgrid[:SIZE, :SIZE]

    # Authentic WildStar translucent warm orange-red fill (~26% opacity)
    FILL_RGB = np.array([230.0, 50.0, 15.0])
    FILL_ALPHA = 66.0

    # =========================================================================
    # 1. RECTANGLE TELEGRAPH (Corridor with Glowing Laser Rim + Center Spine)
    # =========================================================================
    margin_x = 8.0
    margin_y = 4.0
    dx = np.minimum(x_coords - margin_x, (SIZE - margin_x) - x_coords)
    dy = np.minimum(y_coords - margin_y, (SIZE - margin_y) - y_coords)

    rect_rgba = np.zeros((SIZE, SIZE, 4), dtype=np.float32)
    inside_rect = np.clip((np.minimum(dx, dy) + 1.5) / 3.0, 0.0, 1.0)
    rect_rgba[:, :, :3] = FILL_RGB
    rect_rgba[:, :, 3] = FILL_ALPHA * inside_rect

    # Outer perimeter laser glow
    d_rim_x = np.minimum(np.abs(x_coords - margin_x), np.abs((SIZE - margin_x) - x_coords))
    d_rim_y = np.minimum(np.abs(y_coords - margin_y), np.abs((SIZE - margin_y) - y_coords))
    d_outer_rim = np.minimum(d_rim_x, d_rim_y).astype(np.float32)
    draw_laser_line(rect_rgba, d_outer_rim, line_width=6.0, intensity=1.0)

    # Center spine laser divider (X = 256) running straight down the middle
    d_center = np.abs(x_coords - (SIZE * 0.5)).astype(np.float32)
    draw_laser_line(rect_rgba, d_center, line_width=4.5, intensity=0.85)

    rect_rgba[:, :, 3] *= inside_rect
    rect_rgba = np.clip(rect_rgba, 0.0, 255.0).astype(np.uint8)

    # =========================================================================
    # 2. ADVANCING WAVE RECTANGLE (Charging fill with glowing crest)
    # =========================================================================
    wave_rgba = np.zeros((SIZE, SIZE, 4), dtype=np.float32)
    # Ramp from caster (y = 512) toward wave crest (y = 0)
    wave_gradient = np.clip(1.0 - (y_coords / (SIZE * 0.95)), 0.0, 1.0)
    wave_rgba[:, :, :3] = FILL_RGB * 1.15
    wave_rgba[:, :, 3] = 95.0 * wave_gradient * inside_rect

    draw_laser_line(wave_rgba, d_outer_rim, line_width=6.0, intensity=0.9)
    draw_laser_line(wave_rgba, d_center, line_width=4.5, intensity=0.7)
    
    # Blazing wavefront crest at y = margin_y
    d_crest = np.abs(y_coords - margin_y).astype(np.float32)
    draw_laser_line(wave_rgba, d_crest, line_width=7.5, intensity=1.0)
    
    wave_rgba[:, :, 3] *= inside_rect
    wave_rgba = np.clip(wave_rgba, 0.0, 255.0).astype(np.uint8)

    # =========================================================================
    # 3. CIRCLE TELEGRAPH
    # =========================================================================
    cx, cy = SIZE * 0.5, SIZE * 0.5
    radius = (SIZE * 0.5) - 8.0
    r = np.sqrt((x_coords - cx)**2 + (y_coords - cy)**2).astype(np.float32)
    dist_circle = radius - r

    circle_rgba = np.zeros((SIZE, SIZE, 4), dtype=np.float32)
    inside_circle = np.clip((dist_circle + 1.5) / 3.0, 0.0, 1.0)
    circle_rgba[:, :, :3] = FILL_RGB
    circle_rgba[:, :, 3] = FILL_ALPHA * inside_circle

    # Outer glowing laser ring
    d_circle_rim = np.abs(dist_circle - 2.5)
    draw_laser_line(circle_rgba, d_circle_rim, line_width=6.5, intensity=1.0)
    circle_rgba[:, :, 3] *= inside_circle
    circle_rgba = np.clip(circle_rgba, 0.0, 255.0).astype(np.uint8)

    # =========================================================================
    # 4. RING TELEGRAPH (Donut)
    # =========================================================================
    r_in = radius * 0.38
    r_out = radius
    dist_ring = np.minimum(r - r_in, r_out - r).astype(np.float32)

    ring_rgba = np.zeros((SIZE, SIZE, 4), dtype=np.float32)
    inside_ring = np.clip((dist_ring + 1.5) / 3.0, 0.0, 1.0)
    ring_rgba[:, :, :3] = FILL_RGB
    ring_rgba[:, :, 3] = FILL_ALPHA * inside_ring

    d_ring_out = np.abs((r_out - r) - 2.5)
    d_ring_in = np.abs((r - r_in) - 2.5)
    draw_laser_line(ring_rgba, d_ring_out, line_width=6.0, intensity=1.0)
    draw_laser_line(ring_rgba, d_ring_in, line_width=6.0, intensity=1.0)
    ring_rgba[:, :, 3] *= inside_ring
    ring_rgba = np.clip(ring_rgba, 0.0, 255.0).astype(np.uint8)

    # =========================================================================
    # 5. CONE TELEGRAPH (60 degrees with Center Spine)
    # =========================================================================
    ox, oy = SIZE * 0.5, SIZE - 12.0
    cone_r = SIZE - 24.0
    vx = x_coords - ox
    vy = oy - y_coords
    pix_r = np.sqrt(vx**2 + vy**2).astype(np.float32)
    pix_angle = np.abs(np.arctan2(vx, np.maximum(vy, 1e-4)))
    half_cone = np.radians(30.0)

    dist_arc = cone_r - pix_r
    dist_ray = pix_r * np.sin(half_cone - pix_angle)
    dist_base = vy.astype(np.float32)
    dist_cone = np.minimum(np.minimum(dist_arc, dist_ray), dist_base).astype(np.float32)
    dist_cone[pix_angle > half_cone + 0.08] = -10.0

    cone_rgba = np.zeros((SIZE, SIZE, 4), dtype=np.float32)
    inside_cone = np.clip((dist_cone + 1.5) / 3.0, 0.0, 1.0)
    cone_rgba[:, :, :3] = FILL_RGB
    cone_rgba[:, :, 3] = FILL_ALPHA * inside_cone

    d_cone_rim = np.abs(dist_cone - 2.5)
    draw_laser_line(cone_rgba, d_cone_rim, line_width=6.5, intensity=1.0)

    # Center ray for cone
    d_cone_center = np.abs(vx).astype(np.float32)
    is_in_cone_length = (pix_r < cone_r) & (vy > 0)
    d_cone_center[~is_in_cone_length] = 100.0
    draw_laser_line(cone_rgba, d_cone_center, line_width=4.0, intensity=0.7)

    cone_rgba[:, :, 3] *= inside_cone
    cone_rgba = np.clip(cone_rgba, 0.0, 255.0).astype(np.uint8)

    # Write output to both client directories
    out_dirs = [
        os.path.join('WoWClient', 'WoWOverride', 'Textures', 'Telegraph'),
        os.path.join('WoWClient', 'Textures', 'Telegraph')
    ]
    for d in out_dirs:
        os.makedirs(d, exist_ok=True)
        write_blp_with_mips(os.path.join(d, 'Telegraph_Rect_Detrimental.blp'), rect_rgba)
        write_blp_with_mips(os.path.join(d, 'Telegraph_Wave_Detrimental.blp'), wave_rgba)
        write_blp_with_mips(os.path.join(d, 'Telegraph_Circle_Detrimental.blp'), circle_rgba)
        write_blp_with_mips(os.path.join(d, 'Telegraph_Ring_Detrimental.blp'), ring_rgba)
        write_blp_with_mips(os.path.join(d, 'Telegraph_Cone_Detrimental.blp'), cone_rgba)

    print("\n[SUCCESS] Authentic WildStar HD telegraph textures generated!")

if __name__ == '__main__':
    create_shape_textures()
