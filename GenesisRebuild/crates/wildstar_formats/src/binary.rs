//! Bounds-checked little-endian helpers shared by the .m3 and .i3 readers.
pub(crate) fn align16(x:usize)->usize{(x+15)&!15}
pub(crate) fn u16_at(d:&[u8],at:usize)->Option<u16>{
    Some(u16::from_le_bytes(d.get(at..at.checked_add(2)?)?.try_into().ok()?))
}
pub(crate) fn u32_at(d:&[u8],at:usize)->Option<u32>{
    Some(u32::from_le_bytes(d.get(at..at.checked_add(4)?)?.try_into().ok()?))
}
pub(crate) fn u64_at(d:&[u8],at:usize)->Option<u64>{
    Some(u64::from_le_bytes(d.get(at..at.checked_add(8)?)?.try_into().ok()?))
}
pub(crate) fn f32_at(d:&[u8],at:usize)->Option<f32>{u32_at(d,at).map(f32::from_bits)}
/// Byte range `[start, start+count*stride)` if it lies inside `len`.
pub(crate) fn range(len:usize,base:usize,offset:u64,count:u64,stride:usize)->Option<usize>{
    let start=(base as u64).checked_add(offset)?;
    let end=start.checked_add(count.checked_mul(stride as u64)?)?;
    if start>len as u64||end>len as u64{return None;}
    Some(start as usize)
}
pub(crate) fn half_to_f32(h:u16)->f32{
    let sign=if h&0x8000!=0{-1.0}else{1.0};
    let exp=((h>>10)&0x1F) as i32;
    let man=(h&0x3FF) as f32;
    sign*match exp{
        0=>man*2f32.powi(-24),
        31=>if man==0.0{f32::INFINITY}else{f32::NAN},
        _=>(man+1024.0)*2f32.powi(exp-25),
    }
}
/// UTF-16 string (stored as `count` code units); non-ASCII becomes `_`.
pub(crate) fn utf16(d:&[u8],at:usize,count:usize)->String{
    let mut s=String::new();
    for i in 0..count{
        let Some(c)=u16_at(d,at+i*2) else{break;};
        if c==0{break;}
        s.push(if c<128{c as u8 as char}else{'_'});
    }
    s
}
