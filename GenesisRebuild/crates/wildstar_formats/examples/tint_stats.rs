//! `cargo run -p wildstar_formats --example tint_stats -- file.area` : statistics of the terrain colour map.
use wildstar_formats::area::RawArea;
fn main(){
    let path=std::env::args().nth(1).expect("usage: tint_stats <file.area>");
    let area=RawArea::from_path(std::path::Path::new(&path)).expect("read area");
    let (mut n,mut sum,mut lo,mut hi)=(0u64,[0f64;3],[255u8;3],[0u8;3]);
    let mut buckets=std::collections::BTreeMap::<[u8;3],u64>::new();
    let mut with_565=0;let mut with_bc2=0;
    for cell in area.cells.iter().flatten(){
        if cell.color_rgb565(0,0).is_some(){with_565+=1;} else if cell.terrain_color(0,0).is_some(){with_bc2+=1;}
        for z in 0..65{for x in 0..65{
            let Some(c)=cell.terrain_color(x,z) else{continue};
            n+=1;
            for k in 0..3{sum[k]+=c[k] as f64;lo[k]=lo[k].min(c[k]);hi[k]=hi[k].max(c[k]);}
            *buckets.entry([c[0]/32*32,c[1]/32*32,c[2]/32*32]).or_default()+=1;
        }}
    }
    println!("cells with RGB565: {with_565}, BC2 only: {with_bc2}, samples {n}");
    if n>0{println!("mean {:.1} {:.1} {:.1}  min {lo:?} max {hi:?}",sum[0]/n as f64,sum[1]/n as f64,sum[2]/n as f64);}
    let mut v:Vec<_>=buckets.into_iter().collect();v.sort_by_key(|(_,c)|std::cmp::Reverse(*c));
    for (b,c) in v.iter().take(8){println!("bucket {b:?}: {:.1}%",*c as f64*100.0/n as f64);}
}
