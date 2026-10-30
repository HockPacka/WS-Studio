//! WildStar LBTD table decoder; offsets verified against the WS-Tools Area3 Tbl
//! reader and tools/tbl_dump.py. Only supported typed fields are decoded.
use std::collections::HashMap;
use std::path::Path;

fn u16_at(b:&[u8],p:usize)->Result<u16,String>{
    Ok(u16::from_le_bytes(b.get(p..p+2).ok_or("TBL: short u16")?.try_into().unwrap()))
}
fn u32_at(b:&[u8],p:usize)->Result<u32,String>{
    Ok(u32::from_le_bytes(b.get(p..p+4).ok_or("TBL: short u32")?.try_into().unwrap()))
}
fn u64_at(b:&[u8],p:usize)->Result<u64,String>{
    Ok(u64::from_le_bytes(b.get(p..p+8).ok_or("TBL: short u64")?.try_into().unwrap()))
}
fn add(a:usize,b:usize)->Result<usize,String>{a.checked_add(b).ok_or("TBL: offset overflow".into())}
fn relative(base:usize,off:u64)->Result<usize,String>{
    add(base,usize::try_from(off).map_err(|_|"TBL: offset out of range")?)
}
fn utf16_string(b:&[u8],at:usize,max_units:usize)->Result<String,String>{
    let mut units=Vec::new();
    for i in 0..max_units {
        let c=u16_at(b,add(at,i.checked_mul(2).ok_or("TBL: overflow")?)?)?;
        if c==0{return String::from_utf16(&units).map_err(|e|format!("TBL UTF16: {e}"));}
        units.push(c);
    }
    Err("TBL: string not terminated in bounds".into())
}
#[derive(Debug,Clone)]
pub enum Value { Integer(i64),Float(f32),Text(String) }
impl Value {
    pub fn as_id(&self)->Option<u32>{
        match self{Self::Integer(n)=>u32::try_from(*n).ok(),_=>None}
    }
    pub fn as_text(&self)->Option<&str>{
        match self{Self::Text(s)=>Some(s),_=>None}
    }
    pub fn as_float(&self)->Option<f32>{
        match self{Self::Float(f)=>Some(*f),Self::Integer(i)=>Some(*i as f32),_=>None}
    }
}
#[derive(Debug)]
pub struct Table {
    pub columns:Vec<String>,
    pub rows:Vec<Vec<Value>>,
}
impl Table {
    pub fn read_file(path:&Path)->Result<Self,String>{
        Self::from_bytes(&std::fs::read(path).map_err(|e|format!("{}: {e}",path.display()))?)
    }
    pub fn column(&self,name:&str)->Option<usize>{
        self.columns.iter().position(|s|s.eq_ignore_ascii_case(name))
    }
    pub fn get<'a>(&'a self,row:&'a [Value],name:&str)->Option<&'a Value>{
        row.get(self.column(name)?)
    }
    pub fn from_bytes(b:&[u8])->Result<Self,String>{
        const H:usize=96;
        if b.len()<H||&b[..4]!=b"LBTD"{return Err("TBL: expected LBTD header".into());}
        let record_size=usize::try_from(u64_at(b,24)?).map_err(|_|"record size overflow")?;
        let field_count=usize::try_from(u64_at(b,32)?).map_err(|_|"field count overflow")?;
        let field_off=u64_at(b,40)?;
        let row_count=usize::try_from(u64_at(b,48)?).map_err(|_|"row count overflow")?;
        let row_off=u64_at(b,64)?;
        if field_count>4096||row_count>10_000_000||record_size==0{
            return Err("TBL: unreasonable table dimensions".into());
        }
        let field_start=relative(H,field_off)?;
        let fields_end=add(field_start,field_count.checked_mul(24).ok_or("TBL: fields overflow")?)?;
        if fields_end>b.len(){return Err("TBL: field descriptors out of bounds".into());}
        let names_start=add(fields_end,15)?&!15;
        let rows_start=relative(H,row_off)?;
        let rows_end=add(rows_start,row_count.checked_mul(record_size).ok_or("TBL: rows overflow")?)?;
        if rows_end>b.len(){return Err("TBL: rows beyond file".into());}
        let mut names=Vec::with_capacity(field_count);
        let mut types=Vec::with_capacity(field_count);
        for i in 0..field_count {
            let field=add(field_start,i*24)?;
            let name_units=u32_at(b,field)?;
            let name_offset=u64_at(b,field+8)?;
            let type_id=u16_at(b,field+16)?;
            if name_units==0||name_units>1025{return Err("TBL: invalid field name".into());}
            let at=relative(names_start,name_offset)?;
            names.push(utf16_string(b,at,name_units as usize)?);
            types.push(type_id);
        }
        let mut rows=Vec::with_capacity(row_count);
        for row in 0..row_count{
            let start=add(rows_start,row*record_size)?;
            let end=add(start,record_size)?;
            let mut pos=start;
            let mut values=Vec::with_capacity(field_count);
            for &t in &types{
                let value=match t {
                    3|11=>{let v=u32_at(b,pos)? as i32;pos+=4;Value::Integer(v as i64)},
                    4=>{let v=f32::from_bits(u32_at(b,pos)?);pos+=4;Value::Float(v)},
                    20=>{let v=u64_at(b,pos)? as i64;pos+=8;Value::Integer(v)},
                    130=>{
                        // Field's value is 8-byte aligned within its row.
                        if (pos-start)%8!=0{pos=add(pos,4)?;}
                        let offset=u64_at(b,pos)?;pos+=8;
                        let str_at=relative(rows_start,offset)?;
                        Value::Text(utf16_string(b,str_at,4096)?)
                    },
                    other=>return Err(format!("TBL: unsupported field type {other}")),
                };
                if pos>end {return Err("TBL: row layout overflows record".into());}
                values.push(value);
            }
            rows.push(values);
        }
        Ok(Self{columns:names,rows})
    }
}
#[derive(Debug,Clone)]
pub struct WorldLayer {
    pub id:u32,
    pub color_map:String,
    pub normal_map:String,
    pub meters_per_tile:f32,
}
pub fn world_layers(table:&Table)->Result<HashMap<u32,WorldLayer>,String>{
    for mandatory in ["ID","ColorMapPath"]{
        if table.column(mandatory).is_none(){
            return Err(format!("WorldLayer: mandatory column {mandatory} absent"));
        }
    }
    let mut result=HashMap::new();
    for row in &table.rows {
        let Some(id)=table.get(row,"ID").and_then(Value::as_id) else{continue;};
        let Some(color_map)=table.get(row,"ColorMapPath").and_then(Value::as_text) else{continue;};
        let normal_map=table.get(row,"NormalMapPath").and_then(Value::as_text).unwrap_or("");
        let meters=table.get(row,"MetersPerTextureTile").and_then(Value::as_float).unwrap_or(8.);
        let meters_per_tile=if meters.is_finite()&&meters>0.001{meters}else{8.};
        result.insert(id,WorldLayer{id,color_map:color_map.to_string(),
            normal_map:normal_map.to_string(),meters_per_tile});
    }
    Ok(result)
}
#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn rejects_short_or_invalid_tables(){
        assert!(Table::from_bytes(b"LBTD").is_err());
        let mut data=vec![0u8;96];
        data[..4].copy_from_slice(b"LBTD");
        data[24..32].copy_from_slice(&8u64.to_le_bytes());
        data[32..40].copy_from_slice(&5000u64.to_le_bytes());
        assert!(Table::from_bytes(&data).is_err());
    }
    #[test]
    fn extracts_world_layer_metadata(){
        let table=Table{columns:vec!["ID".into(),"ColorMapPath".into(),
            "NormalMapPath".into(),"MetersPerTextureTile".into()],rows:vec![
            vec![Value::Integer(11),Value::Text("Art/Terrain/Grass.tex".into()),
                Value::Text("Art/Terrain/Grass_N.tex".into()),Value::Float(4.)]
            ]};
        let layers=world_layers(&table).unwrap();
        assert_eq!(layers[&11].color_map,"Art/Terrain/Grass.tex");
        assert_eq!(layers[&11].meters_per_tile,4.);
    }
}
