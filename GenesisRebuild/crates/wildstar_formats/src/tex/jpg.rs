//! WildStar proprietary JPEG-like TEX entropy / DCT decoder.
//! Native implementation based on the observed TYPE1/TYPE2/TYPE3 layout.
//! Four channels; TYPE1 has 16x16 MCUs and half-resolution chroma.
use super::RgbaImage;
use std::sync::OnceLock;

const DL_$2UMB_$2ITS: [u8; 16] = [0, 1, 5, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0];
const AL_$2UMB_$2ITS: [u8; 16] = [0, 2, 1, 3, 3, 2, 4, 3, 5, 5, 4, 4, 0, 0, 1, 125];
const AL_$2UMV_$2ALS: [u8; 162] = [0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12, 0x21, 0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08, 0x23, 0x42, 0xb1, 0xc1, 0x15, 0x52, 0xd1, 0xf0, 0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0a, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa];
const DC_$2HROMB_$2ITS: [u8; 16] = [0, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0];
const AC_$2HROMB_$2ITS: [u8; 16] = [0, 2, 1, 2, 4, 4, 3, 4, 7, 5, 4, 4, 0, 1, 2, 119];
const AC_$2HROMV_$2ALS: [u8; 162] = [0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71, 0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91, 0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0, 0x15, 0x62, 0x72, 0xd1, 0x0a, 0x16, 0x24, 0x34, 0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa];
const QUANT_LUMA:[i32;64]=[
16,11,10,16,24,40,51,61, 12,12,14,19,26,58,60,55,
14,13,16,24,40,57,69,56, 14,17,22,29,51,87,80,62,
18,22,37,56,68,109,103,77, 24,35,55,64,81,104,113,92,
49,64,78,87,103,121,120,101, 72,92,95,98,112,100,103,99,
];
const QUANT_CHROMA_FIRST:[i32;32]=[
17,18,24,47,99,99,99,99,18,21,26,66,99,99,99,99,
24,26,56,99,99,99,99,99,47,66,99,99,99,99,99,99,
];

fn le_u32(b:&[u8],at:usize)->Result<usize,String>{
    Ok(u32::from_le_bytes(b.get(at..at+4).ok_or("JPG TEX header truncated")?
        .try_into().unwrap()) as usize)
}
fn huff_table(length_counts:&[u8;16],values:Option<&[u8]>)->Vec<u16>{
    let mut lut=vec![0u16;65536];
    let mut code=0usize;
    let mut pos=0usize;
    for (len_idx,&count) in length_counts.iter().enumerate(){
        let bits=len_idx+1;
        for _ in 0..count{
            let value=values.map(|arr|arr[pos]).unwrap_or(pos as u8);
            let start=code<<(16-bits);
            let finish=start+(1usize<<(16-bits));
            for entry in &mut lut[start..finish]{*entry=((bits as u16)<<8)|(value as u16);}
            code+=1;
            pos+=1;
        }
        code<<=1;
    }
    lut
}
fn huffman_tables()->&'static [Vec<u16>;4]{
    static TABLES:OnceLock<[Vec<u16>;4]>=OnceLock::new();
    TABLES.get_or_init(||[
        huff_table(&DC_LUMA_BITS,None),
        huff_table(&AC_LUMA_BITS,Some(&AC_LUMA_VALS)),
        huff_table(&DC_CHROMA_BITS,None),
        huff_table(&AC_CHROMA_BITS,Some(&AC_CHROMA_VALS)),
    ])
}
struct Bits {
    bytes:Vec<u8>,
    pos:usize,
    total:usize,
}
impl Bits {
    fn new(raw:&[u8])->Self{
        let mut bytes=raw.to_vec();
        bytes.extend_from_slice(&[0;4]);
        Self{bytes,pos:0,total:raw.len()*8}
    }
    fn peek16(&self)->Result<usize,String>{
        if self.pos>self.total+7{return Err("JPG TEX: entropy stream exhausted".into());}
        let p=self.pos/8;
        if p+2>=self.bytes.len(){return Err("JPG TEX: truncated entropy".into());}
        let v=((self.bytes[p] as u32)<<16)
            |((self.bytes[p+1] as u32)<<8)
            |(self.bytes[p+2] as u32);
        Ok(((v>>(8-(self.pos%8)))&65535) as usize)
    }
    fn read(&mut self,n:usize)->Result<i32,String>{
        if n==0{return Ok(0);}
        if n>16||self.pos+n>self.total+7 {
            return Err("JPG TEX: bitstream out of bounds".into());
        }
        let p=self.pos/8;
        let val=((self.bytes[p] as u32)<<24)
            |((self.bytes[p+1] as u32)<<16)
            |((self.bytes[p+2] as u32)<<8)
            |(self.bytes[p+3] as u32);
        let mask=(1u32<<n)-1;
        let bits=(val>>(32-self.pos%8-n))&mask;
        self.pos+=n;
        Ok(bits as i32)
    }
    fn symbol(&mut self,lut:&[u16])->Result<i32,String>{
        let code=lut[self.peek16()?];
        if code==0{return Err("JPG TEX: invalid Huffman code".into());}
        self.pos+=(code>>8) as usize;
        Ok((code&255) as i32)
    }
}
fn zigzag()->[usize;64]{
    let(mut i,mut j,mut d)=(0i32,0i32,1i32);
    let mut map=[0usize;64];
    for n in 0..64{
        map[i as usize+j as usize*8]=n;
        i+=d;j-=d;
        if d>0{
            if i>=8{i=7;j+=2;d=-d;}
            else if j<0{j=0;d=-d;}
        }else if j>=8{j=7;i+=2;d=-d;}
        else if i<0{i=0;d=-d;}
    }
    map
}
fn signed_value(raw:i32,bits:usize)->i32{
    if bits==0{0}
    else if raw >= (1i32<<(bits-1)){raw}
    else {raw-((1i32<<bits)-1)}
}
fn decode_one(bits:&mut Bits,is_luma:bool,dc:&mut i32,
              zig:&[usize;64])->Result<[i32;64],String>{
    let tables=huffman_tables();
    let n=bits.symbol(&tables[if is_luma{0}else{2}])? as usize;
    if n>16{return Err("JPG TEX: oversized DC code".into());}
    let raw=bits.read(n)?;
    *dc+=signed_value(raw,n);
    let mut coeff=[0i32;64];
    coeff[0]=*dc;
    let mut k=1usize;
    while k<64{
        let sym=bits.symbol(&tables[if is_luma{1}else{3}])? as usize;
        if sym==0{break;}
        if sym==0xf0 {k+=16;continue;}
        k+=sym>>4;
        let nb=sym&15;
        let val=signed_value(bits.read(nb)?,nb);
        if k<64 {coeff[k]=val;}
        k+=1;
    }
    let mut natural=[0i32;64];
    for n in 0..64{natural[n]=coeff[zig[n]];}
    Ok(natural)
}
fn dct_matrix()->&'static [[f32;8];8]{
    static MATRIX:OnceLock<[[f32;8];8]>=OnceLock::new();
    MATRIX.get_or_init(||{
        let mut matrix=[[0f32;8];8];
        for (k,row) in matrix.iter_mut().enumerate(){
            for (n,val) in row.iter_mut().enumerate(){
                let scale=if k==0{(0.125f32).sqrt()}else{0.5f32};
                *val=scale*((2*n+1) as f32*k as f32*std::f32::consts::PI/16.).cos();
            }
        }
        matrix
    })
}
fn inverse_dct(coef:&[i32;64],quant:&[f32;64],luma:bool)->[i32;64]{
    let mat=dct_matrix();
    let mut intermediate=[[0f32;8];8];
    for k in 0..8{for v in 0..8{
        let mut sum=0f32;
        for u in 0..8{
            sum+=mat[u][k]*(coef[u*8+v] as f32*quant[u*8+v]).trunc();
        }
        intermediate[k][v]=sum;
    }}
    let mut pixels=[0i32;64];
    for k in 0..8{for l in 0..8{
        let mut sum=0f32;
        for v in 0..8{sum+=intermediate[k][v]*mat[v][l];}
        let value=sum.round_ties_even() as i32;
        pixels[k*8+l]=if luma{(value+128).clamp(0,255)}else{value.clamp(-256,255)};
    }}
    pixels
}
pub fn decode_jpg_tex(bytes:&[u8],limit:usize)->Result<RgbaImage,String>{
    const HEADER:usize=112;
    if bytes.len()<HEADER{return Err("JPG TEX: short header".into());}
    let kind=le_u32(bytes,36)?;
    let width=le_u32(bytes,8)?;
    let height=le_u32(bytes,12)?;
    let mip_count=le_u32(bytes,52)?;
    if kind>2||mip_count==0||mip_count>13||width==0||height==0 {
        return Err("JPG TEX: invalid kind, dimensions or mip count".into());
    }
    let mut offset=HEADER;
    let mut selected=None;
    for mip in 0..mip_count{
        let bytes_len=le_u32(bytes,56+mip*4)?;
        let end=offset.checked_add(bytes_len).ok_or("JPG TEX: size overflow")?;
        if end>bytes.len(){return Err("JPG TEX: mip out of bounds".into());}
        let w=(width>>(mip_count-1-mip)).max(1);
        let h=(height>>(mip_count-1-mip)).max(1);
        if w.max(h)<=limit.max(1){selected=Some((w,h,offset,end));}
        offset=end;
    }
    let (w,h,start,end)=selected.ok_or("JPG TEX: no mip within size limit")?;
    let align=if kind==0{16usize}else{8usize};
    let cw=w.div_ceil(align)*align;
    let ch=h.div_ceil(align)*align;
    let bpr=cw/8;
    let bpc=ch/8;
    let blocks=bpr.checked_mul(bpc).ok_or("JPG TEX: block count overflow")?;
    let mut coeffs:[Vec<[i32;64]>;4]=std::array::from_fn(|c|{
        let count=if kind==0&&(c==1||c==2){blocks/4}else{blocks};
        vec![[0i32;64];count]
    });
    let mut is_luma=[true,false,false,true];
    if kind==1{is_luma=[true,true,true,true];}
    let mut quant=[[0f32;64];4];
    let mut default=[None;4];
    for c in 0..4{
        let pos=40+3*c;
        if bytes[pos+1]!=0{default[c]=Some(bytes[pos+2] as i32);}
        let quality=bytes[pos] as f32;
        let factor=(200.-2.*quality)/100.;
        for i in 0..64{
            let base=if is_luma[c]{QUANT_LUMA[i]}else{
                if i<32{QUANT_CHROMA_FIRST[i]}else{99}
            };
            quant[c][i]=(base as f32*factor).clamp(1.,255.);
        }
    }
    let mut bits=Bits::new(&bytes[start..end]);
    let zig=zigzag();
    let mut dcs=[0i32;4];
    if kind==0{
        let mbw=bpr/2;
        for my in 0..(bpc/2){for mx in 0..mbw{
            let block=(my*2)*bpr+mx*2;
            let positions=[block,block+1,block+bpr,block+bpr+1];
            for &idx in &positions {
                if default[0].is_none(){
                    coeffs[0][idx]=decode_one(&mut bits,is_luma[0],&mut dcs[0],&zig)?;
                }
            }
            let sub_idx=my*mbw+mx;
            for c in 1..3{
                if default[c].is_none(){
                    coeffs[c][sub_idx]=decode_one(&mut bits,is_luma[c],&mut dcs[c],&zig)?;
                }
            }
            for &idx in &positions {
                if default[3].is_none(){
                    coeffs[3][idx]=decode_one(&mut bits,is_luma[3],&mut dcs[3],&zig)?;
                }
            }
        }}
    }else{
        for block in 0..blocks{
            for c in 0..4{
                if default[c].is_none(){
                    coeffs[c][block]=decode_one(&mut bits,is_luma[c],&mut dcs[c],&zig)?;
                }
            }
        }
    }
    // Expand each 8x8 DCT block to a raster, upsample TYPE1 chroma by 2.
    let mut planes:Vec<Vec<i32>>=Vec::with_capacity(4);
    for c in 0..4{
        let mut plane=vec![default[c].unwrap_or(0);cw*ch];
        if default[c].is_none(){
            let subsampled=kind==0&&(c==1||c==2);
            let bw=if subsampled{bpr/2}else{bpr};
            for (idx,coeff) in coeffs[c].iter().enumerate(){
                let pix=inverse_dct(coeff,&quant[c],is_luma[c]);
                let bx=idx%bw;let by=idx/bw;
                for y in 0..8{for x in 0..8{
                    if subsampled{
                        let px=(bx*8+x)*2;
                        let py=(by*8+y)*2;
                        for dy in 0..2{for dx in 0..2{
                            plane[(py+dy)*cw+px+dx]=pix[y*8+x];
                        }}
                    }else{
                        plane[(by*8+y)*cw+bx*8+x]=pix[y*8+x];
                    }
                }}
            }
        }
        planes.push(plane);
    }
    let mut rgba=vec![0u8;w*h*4];
    for y in 0..h{for x in 0..w{
        let p=y*cw+x;
        let a=planes[3][p];
        let (r,g,b,alpha)=if kind==1{
            (planes[3][p],planes[1][p],planes[2][p],planes[0][p])
        }else{
            let red1=planes[0][p]-(planes[2][p]>>1);
            let green=(red1+planes[2][p]).clamp(0,255);
            let blue=(red1-(planes[1][p]>>1)).clamp(0,255);
            let red=(blue+planes[1][p]).clamp(0,255);
            (red,green,blue,a)
        };
        let out=(y*w+x)*4;
        rgba[out]=r.clamp(0,255) as u8;
        rgba[out+1]=g.clamp(0,255) as u8;
        rgba[out+2]=b.clamp(0,255) as u8;
        rgba[out+3]=alpha.clamp(0,255) as u8;
    }}
    Ok(RgbaImage{width:w,height:h,rgba})
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn decodes_type2_real_huffman_entropy_with_zero_dct_blocks(){
        // Standard JPEG canonical Huffman: Luma DC category 0 = '00',
        // AC end-of-block = '1010'. One (DC0,EOB) per channel, 4 channels.
        // TYPE2 ("LLLL") yields RGBA 128/128/128/128 after the IDCT.
        let mut bytes=vec![0u8;112];
        bytes[..4].copy_from_slice(b"\0GFX");
        bytes[4..8].copy_from_slice(&3u32.to_le_bytes());
        bytes[8..12].copy_from_slice(&8u32.to_le_bytes());
        bytes[12..16].copy_from_slice(&8u32.to_le_bytes());
        bytes[32..36].copy_from_slice(&1u32.to_le_bytes());
        bytes[36..40].copy_from_slice(&1u32.to_le_bytes());
        bytes[52..56].copy_from_slice(&1u32.to_le_bytes());
        bytes[56..60].copy_from_slice(&3u32.to_le_bytes());
        for c in 0..4{bytes[40+3*c]=50;}
        bytes.extend_from_slice(&[0b00101000,0b10100010,0b10001010]);
        let decoded=decode_jpg_tex(&bytes,256).unwrap();
        assert_eq!((decoded.width,decoded.height),(8,8));
        assert_eq!(decoded.rgba[0..4],[128,128,128,128]);
        assert!(decoded.rgba.chunks_exact(4).all(|p|p==[128,128,128,128]));
    }
    #[test]
    fn decodes_default_channel_type1_and_type2_mips(){
        for kind in 0..3u32 {
            let mut bytes=vec![0u8;112];
            bytes[..4].copy_from_slice(b"\0GFX");
            bytes[4..8].copy_from_slice(&3u32.to_le_bytes());
            bytes[8..12].copy_from_slice(&4u32.to_le_bytes());
            bytes[12..16].copy_from_slice(&4u32.to_le_bytes());
            bytes[32..36].copy_from_slice(&1u32.to_le_bytes());
            bytes[36..40].copy_from_slice(&kind.to_le_bytes());
            bytes[52..56].copy_from_slice(&1u32.to_le_bytes());
            for c in 0..4 {
                bytes[40+c*3]=50;
                bytes[41+c*3]=1;
                bytes[42+c*3]=if c==0{128}else{255};
            }
            let image=decode_jpg_tex(&bytes,256).unwrap();
            assert_eq!((image.width,image.height),(4,4));
            assert_eq!(image.rgba.len(),4*4*4);
        }
    }
}
