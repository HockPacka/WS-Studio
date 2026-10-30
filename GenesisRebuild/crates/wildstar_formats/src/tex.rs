//! Native WildStar TEX preview decoder, verified layout from WS-Tools.
//! Supports uncompressed, BC1/BC2/BC3 and proprietary JPG-like TYPE1/2/3.
mod jpg;
#[derive(Debug,Clone)]
pub struct RgbaImage {
    pub width:usize,
    pub height:usize,
    pub rgba:Vec<u8>,
}
impl RgbaImage {
    pub fn sample_wrapped(&self,u:f32,v:f32)->[u8;4]{
        if self.width==0||self.height==0{return [255,0,255,255];}
        let x=(u.rem_euclid(1.)*self.width as f32) as usize%self.width;
        let y=(v.rem_euclid(1.)*self.height as f32) as usize%self.height;
        let p=(y*self.width+x)*4;
        self.rgba[p..p+4].try_into().unwrap()
    }
    #[inline]
    pub fn sample_bilinear(&self, u: f32, v: f32) -> [u8; 4] {
        if self.width == 0 || self.height == 0 { return [255, 0, 255, 255]; }
        let u_norm = u - u.floor();
        let v_norm = v - v.floor();
        let fx = u_norm * self.width as f32 - 0.5;
        let fy = v_norm * self.height as f32 - 0.5;
        let x0 = fx.floor();
        let y0 = fy.floor();
        let s = fx - x0;
        let t = fy - y0;
        let w = self.width as isize;
        let h = self.height as isize;
        let ix0 = (x0 as isize).rem_euclid(w) as usize;
        let iy0 = (y0 as isize).rem_euclid(h) as usize;
        let ix1 = if ix0 + 1 < self.width { ix0 + 1 } else { 0 };
        let iy1 = if iy0 + 1 < self.height { iy0 + 1 } else { 0 };

        let p00 = (iy0 * self.width + ix0) * 4;
        let p10 = (iy0 * self.width + ix1) * 4;
        let p01 = (iy1 * self.width + ix0) * 4;
        let p11 = (iy1 * self.width + ix1) * 4;

        if p11 + 3 >= self.rgba.len() {
            return [255, 0, 255, 255];
        }

        let one_minus_s = 1.0 - s;
        let one_minus_t = 1.0 - t;
        let w00 = one_minus_s * one_minus_t;
        let w10 = s * one_minus_t;
        let w01 = one_minus_s * t;
        let w11 = s * t;

        let mut out = [0u8; 4];
        for c in 0..4 {
            let val = self.rgba[p00 + c] as f32 * w00
                + self.rgba[p10 + c] as f32 * w10
                + self.rgba[p01 + c] as f32 * w01
                + self.rgba[p11 + c] as f32 * w11;
            out[c] = val.round().clamp(0.0, 255.0) as u8;
        }
        out
    }
}
fn number(data:&[u8],at:usize)->Result<usize,String>{
    Ok(u32::from_le_bytes(data.get(at..at+4).ok_or("TEX: truncated header")?
        .try_into().unwrap()) as usize)
}
fn c565(c:u16)->[u8;3]{
    let r=((c>>11)&31) as u8;
    let g=((c>>5)&63) as u8;
    let b=(c&31) as u8;
    [(r<<3)|(r>>2),(g<<2)|(g>>4),(b<<3)|(b>>2)]
}
fn color_table(block:&[u8],force_four:bool)->([[u8;4];4],u32){
    let a=u16::from_le_bytes([block[0],block[1]]);
    let b=u16::from_le_bytes([block[2],block[3]]);
    let ca=c565(a);let cb=c565(b);
    let mut colors=[[0u8;4];4];
    colors[0]=[ca[0],ca[1],ca[2],255];
    colors[1]=[cb[0],cb[1],cb[2],255];
    if a>b||force_four{
        for ch in 0..3{
            colors[2][ch]=((2*ca[ch] as u16+cb[ch] as u16)/3) as u8;
            colors[3][ch]=((ca[ch] as u16+2*cb[ch] as u16)/3) as u8;
        }
        colors[2][3]=255;colors[3][3]=255;
    }else{
        for ch in 0..3 {colors[2][ch]=((ca[ch] as u16+cb[ch] as u16)/2) as u8;}
        colors[2][3]=255;colors[3][3]=0;
    }
    (colors,u32::from_le_bytes(block[4..8].try_into().unwrap()))
}
fn decode_bc(input:&[u8],w:usize,h:usize,kind:usize)->Result<Vec<u8>,String>{
    let blocks_x=w.div_ceil(4);let blocks_y=h.div_ceil(4);
    let stride=if kind==1{8}else{16};
    let needed=blocks_x.checked_mul(blocks_y).and_then(|v|v.checked_mul(stride))
        .ok_or("TEX BC: overflow")?;
    if input.len()<needed{return Err("TEX BC: truncated block data".into());}
    let mut out=vec![0u8;w*h*4];
    for by in 0..blocks_y{
        for bx in 0..blocks_x{
            let block=&input[(by*blocks_x+bx)*stride..(by*blocks_x+bx+1)*stride];
            let color=if kind==1{block}else{&block[8..]};
            let (palette,indices)=color_table(color,kind!=1);
            let mut alpha_palette=[0u8;8];
            let mut alpha_bits=0u64;
            if kind==5 {
                let a=block[0];let b=block[1];
                alpha_palette[0]=a;alpha_palette[1]=b;
                if a>b{
                    for i in 1..7{
                        alpha_palette[i+1]=(((7-i) as u16*a as u16+i as u16*b as u16)/7) as u8;
                    }
                }else{
                    for i in 1..5{
                        alpha_palette[i+1]=(((5-i) as u16*a as u16+i as u16*b as u16)/5) as u8;
                    }
                    alpha_palette[6]=0;alpha_palette[7]=255;
                }
                for i in 0..6{alpha_bits|=(block[2+i] as u64)<<(8*i);}
            }
            for py in 0..4{
                for px in 0..4{
                    let x=bx*4+px;let y=by*4+py;
                    if x>=w||y>=h{continue;}
                    let cell=py*4+px;
                    let ci=((indices>>(2*cell))&3) as usize;
                    let mut rgba=palette[ci];
                    if kind==3 {
                        let nibble=if cell%2==0{block[cell/2]&15}else{block[cell/2]>>4};
                        rgba[3]=nibble*17;
                    }else if kind==5 {
                        rgba[3]=alpha_palette[((alpha_bits>>(3*cell))&7) as usize];
                    }
                    out[(y*w+x)*4..(y*w+x+1)*4].copy_from_slice(&rgba);
                }
            }
        }
    }
    Ok(out)
}
pub fn decode_tex(bytes:&[u8],max_size:usize)->Result<RgbaImage,String>{
    const HEADER:usize=112;
    if bytes.len()<HEADER||!(bytes.get(1..4)==Some(b"GFX")||
        bytes.get(0..3)==Some(b"XFG")) {
        return Err("TEX: invalid WildStar GFX signature".into());
    }
    if number(bytes,4)?!=3{return Err("TEX: unsupported version (expected 3)".into());}
    let full_w=number(bytes,8)?;
    let full_h=number(bytes,12)?;
    if full_w==0||full_h==0||full_w>16384||full_h>16384{
        return Err("TEX: invalid dimensions".into());
    }
    let jpg=number(bytes,32)?!=0;
    if jpg {
        return jpg::decode_jpg_tex(bytes,max_size);
    }
    let fmt=number(bytes,28)?;
    let mips=number(bytes,24)?;
    if !(1..=13).contains(&mips){return Err("TEX: invalid mip count".into());}
    let bpp=match fmt{0|1=>4,5=>2,6=>1,13=>8,14|15=>16,
        _=>return Err(format!("TEX: unsupported storage format {fmt}"))};
    let mut offset=HEADER;
    let mut selected=None;
    for i in 0..mips{
        // Mips are smallest first. Choose largest <= max_size when available.
        let shift=mips-1-i;
        let w=(full_w>>shift).max(1);
        let h=(full_h>>shift).max(1);
        let size=if fmt>=13 {
            w.div_ceil(4).checked_mul(h.div_ceil(4))
                .and_then(|v|v.checked_mul(bpp))
        }else{w.checked_mul(h).and_then(|v|v.checked_mul(bpp))};
        let size=size.ok_or("TEX: mip size overflow")?;
        let end=offset.checked_add(size).ok_or("TEX: offset overflow")?;
        if end>bytes.len(){return Err("TEX: mip data exceeds file".into());}
        if w.max(h)<=max_size.max(1){selected=Some((w,h,offset,end));}
        offset=end;
    }
    let (w,h,start,end)=selected.ok_or("TEX: no suitable mip")?;
    let input=&bytes[start..end];
    let rgba=match fmt{
        13=>decode_bc(input,w,h,1)?,
        14=>decode_bc(input,w,h,3)?,
        15=>decode_bc(input,w,h,5)?,
        0|1=>input.chunks_exact(4).flat_map(|p|[p[2],p[1],p[0],p[3]]).collect(),
        5=>input.chunks_exact(2).flat_map(|p|{
            let rgb=c565(u16::from_le_bytes([p[0],p[1]]));
            [rgb[0],rgb[1],rgb[2],255]
        }).collect(),
        6=>input.iter().flat_map(|&g|[g,g,g,255]).collect(),
        _=>unreachable!(),
    };
    Ok(RgbaImage{width:w,height:h,rgba})
}
#[cfg(test)]
mod tests{
    use super::*;
    fn sample(fmt:u32,block:&[u8])->Vec<u8>{
        let mut header=vec![0u8;112];
        header[..4].copy_from_slice(b"\0GFX");
        header[4..8].copy_from_slice(&3u32.to_le_bytes());
        header[8..12].copy_from_slice(&4u32.to_le_bytes());
        header[12..16].copy_from_slice(&4u32.to_le_bytes());
        header[24..28].copy_from_slice(&1u32.to_le_bytes());
        header[28..32].copy_from_slice(&fmt.to_le_bytes());
        header.extend_from_slice(block);
        header
    }
    #[test]
    fn decodes_bgra_and_rgb565(){
        let bgra=sample(0,&[3u8,2,1,255].repeat(16));
        let image=decode_tex(&bgra,256).unwrap();
        assert_eq!(image.sample_wrapped(0.,0.),[1,2,3,255]);
        let raw=sample(5,&[0u8,0xf8].repeat(16));
        assert_eq!(decode_tex(&raw,256).unwrap().sample_wrapped(0.,0.),[255,0,0,255]);
    }
    #[test]
    fn bc1_rgb565_and_invalid_jpg(){
        let mut block=[0u8;8];
        block[0]=0x00;block[1]=0xF8;
        block[2]=0xE0;block[3]=0x07;
        let tex=sample(13,&block);
        assert_eq!(decode_tex(&tex,256).unwrap().sample_wrapped(0.,0.),[255,0,0,255]);
        let mut jpg=tex.clone();jpg[32]=1;
        assert!(decode_tex(&jpg,256).is_err()); // synthetic header lacks JPEG mip count
    }
    #[test]
    fn reject_truncated(){
        assert!(decode_tex(b"foo",256).is_err());
        let b=sample(15,&[0;4]);
        assert!(decode_tex(&b,256).is_err());
    }
}
