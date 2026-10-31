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
                        // A zero string pointer represents an empty optional
                        // field in client tables (for example unused normal maps).
                        if offset==0{
                            Value::Text(String::new())
                        }else{
                            let str_at=relative(rows_start,offset)?;
                            Value::Text(utf16_string(b,str_at,4096)?)
                        }
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
    /// Exact WorldLayer.tbl columns worldClutterId00..03.
    pub clutter_ids:[u32;4],
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
        let clutter_ids=std::array::from_fn(|n|{
            table.get(row,&format!("worldClutterId0{n}"))
                .and_then(Value::as_id).unwrap_or(0)
        });
        result.insert(id,WorldLayer{id,color_map:color_map.to_string(),
            normal_map:normal_map.to_string(),meters_per_tile,clutter_ids});
    }
    Ok(result)
}
/// WorldClutter.tbl: six weighted M3 asset options per preset.
/// Data is parsed exactly from the named TBL columns, not from AREA bit27
/// directly (that bit selects one of the four WorldLayer clutter IDs).
#[derive(Debug,Clone,Default)]
pub struct ClutterAsset {
    pub path:String,
    pub weight:f32,
    pub min_scale:f32,
    pub rotation_min:f32,
    pub rotation_max:f32,
    pub flags:u32,
    pub emissive_glow:u32,
}
#[derive(Debug,Clone)]
pub struct WorldClutter {
    pub id:u32,
    pub density:f32,
    pub flags:u32,
    pub assets:[ClutterAsset;6],
}
pub fn world_clutters(table:&Table)->Result<HashMap<u32,WorldClutter>,String>{
    // Fail explicitly on the wrong table/schema rather than silently
    // filling in a plausible-looking empty Clutter database.
    for name in ["ID","density","assetPath0","assetWeight0"]{
        if table.column(name).is_none(){
            return Err(format!("WorldClutter: mandatory column {name} absent"));
        }
    }
    let number=|row:&[Value],key:&str,default:f32|->f32{
        table.get(row,key).and_then(Value::as_float).unwrap_or(default)
    };
    let int=|row:&[Value],key:&str|->u32{
        table.get(row,key).and_then(Value::as_id).unwrap_or(0)
    };
    let mut result=HashMap::new();
    for row in &table.rows{
        let Some(id)=table.get(row,"ID").and_then(Value::as_id) else{continue;};
        if id==0 {continue;}
        let density=number(row,"density",0.0);
        let flags=int(row,"clutterFlags");
        let assets=std::array::from_fn(|i|{
            let suffix=if i==0{"0".to_string()}else{format!("0{i}")};
            ClutterAsset{
                path:table.get(row,&format!("assetPath{suffix}"))
                    .and_then(Value::as_text).unwrap_or("").to_string(),
                weight:number(row,&format!("assetWeight{suffix}"),0.0),
                min_scale:number(row,&format!("minScale{suffix}"),1.0),
                rotation_min:number(row,&format!("rotationMin{suffix}"),0.0),
                rotation_max:number(row,&format!("rotationMax{suffix}"),0.0),
                flags:int(row,&format!("flag{suffix}")),
                emissive_glow:int(row,&format!("emissiveGlow0{i}")),
            }
        });
        result.insert(id,WorldClutter{id,density,flags,assets});
    }
    Ok(result)
}

#[cfg(test)]
mod tests{
    use super::*;
    #[test]
    fn maps_worldlayer_4_native_clutter_ids(){
        let mut cols=vec!["ID".into(),"ColorMapPath".into()];
        cols.extend((0..4).map(|k|format!("worldClutterId0{k}")));
        let table=Table{columns:cols,rows:vec![vec![
            Value::Integer(42),Value::Text("Terrain/Grass.tex".into()),
            Value::Integer(100),Value::Integer(101),Value::Integer(0),
            Value::Integer(103),
        ]]};
        let data=world_layers(&table).unwrap();
        assert_eq!(data[&42].clutter_ids,[100,101,0,103]);
    }
    #[test]
    fn six_weighted_worldclutter_assets_use_exact_column_names(){
        let mut columns=vec![
            "ID".to_string(),"density".to_string(),
            "clutterFlags".to_string()
        ];
        let mut row=vec![
            Value::Integer(88),Value::Float(125.0),Value::Integer(3)
        ];
        for i in 0..6{
            let suffix=if i==0{"0".into()}else{format!("0{i}")};
            columns.extend([
                format!("assetPath{suffix}"),
                format!("assetWeight{suffix}"),
                format!("minScale{suffix}"),
                format!("rotationMin{suffix}"),
                format!("rotationMax{suffix}"),
                format!("flag{suffix}"),
                format!("emissiveGlow0{i}"),
            ]);
            row.extend([
                Value::Text(format!("Art/Clutter/{i}.m3")),
                Value::Float((i+1) as f32),
                Value::Float(0.3),
                Value::Float(-1.0),
                Value::Float(1.0),
                Value::Integer(i as i64),
                Value::Integer((i*2) as i64),
            ]);
        }
        let data=world_clutters(&Table{columns,rows:vec![row]}).unwrap();
        assert_eq!(data[&88].density,125.0);
        assert_eq!(data[&88].flags,3);
        assert_eq!(data[&88].assets[0].path,"Art/Clutter/0.m3");
        assert_eq!(data[&88].assets[5].weight,6.0);
        assert_eq!(data[&88].assets[5].flags,5);
        assert_eq!(data[&88].assets[5].emissive_glow,10);
        assert_eq!(data[&88].assets[2].rotation_min,-1.0);
        assert!(world_clutters(&Table{columns:vec!["ID".into()],
            rows:vec![]}).unwrap_err().contains("density"));
    }
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
    fn decodes_synthetic_lbtd_with_inline_utf16_names_and_row_string() {
        const H:usize=96;
        let mut data=vec![0u8;512];
        data[..4].copy_from_slice(b"LBTD");
        // Field descriptors at H+0x30; two 24-byte records.
        data[24..32].copy_from_slice(&16u64.to_le_bytes()); // record size
        data[32..40].copy_from_slice(&2u64.to_le_bytes());  // field count
        data[40..48].copy_from_slice(&48u64.to_le_bytes()); // descriptors
        data[48..56].copy_from_slice(&1u64.to_le_bytes());  // rows
        data[64..72].copy_from_slice(&160u64.to_le_bytes());// row offset
        let field_start=H+48;
        let names_start=192;
        let names=["ID","ColorMapPath"];
        let mut next=0usize;
        for (i,name) in names.iter().enumerate(){
            let p=field_start+i*24;
            data[p..p+4].copy_from_slice(&((name.len()+1) as u32).to_le_bytes());
            data[p+8..p+16].copy_from_slice(&(next as u64).to_le_bytes());
            let kind=if i==0{3u16}else{130u16};
            data[p+16..p+18].copy_from_slice(&kind.to_le_bytes());
            for c in name.encode_utf16().chain(std::iter::once(0)){
                data[names_start+next..names_start+next+2].copy_from_slice(&c.to_le_bytes());
                next+=2;
            }
        }
        let start=H+160;
        data[start..start+4].copy_from_slice(&77i32.to_le_bytes());
        data[start+8..start+16].copy_from_slice(&32u64.to_le_bytes());
        let value="Art/Terrain/Sample.tex";
        let mut p=start+32;
        for c in value.encode_utf16().chain(std::iter::once(0)){
            data[p..p+2].copy_from_slice(&c.to_le_bytes());
            p+=2;
        }
        let table=Table::from_bytes(&data).unwrap();
        assert_eq!(table.columns,vec!["ID","ColorMapPath"]);
        let layers=world_layers(&table).unwrap();
        assert_eq!(layers[&77].color_map,value);
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

#[derive(Debug, Clone)]
pub struct WorldSky {
    pub id: u32,
    pub asset_path: String,
    pub asset_path_in_flux: String,
    pub description: String,
}

pub fn world_skies(table: &Table) -> Result<HashMap<u32, WorldSky>, String> {
    for mandatory in ["ID", "assetPath"] {
        if table.column(mandatory).is_none() {
            return Err(format!("WorldSky: mandatory column {mandatory} absent"));
        }
    }
    let mut result = HashMap::new();
    for row in &table.rows {
        let Some(id) = table.get(row, "ID").and_then(Value::as_id) else { continue; };
        let Some(asset_path) = table.get(row, "assetPath").and_then(Value::as_text) else { continue; };
        let asset_path_in_flux = table.get(row, "assetPathInFlux").and_then(Value::as_text).unwrap_or("");
        let description = table.get(row, "description").and_then(Value::as_text).unwrap_or("");
        result.insert(
            id,
            WorldSky {
                id,
                asset_path: asset_path.to_string(),
                asset_path_in_flux: asset_path_in_flux.to_string(),
                description: description.to_string(),
            },
        );
    }
    Ok(result)
}

#[test]
fn extracts_world_sky_metadata() {
    let table = Table {
        columns: vec!["ID".into(), "assetPath".into(), "assetPathInFlux".into(), "description".into()],
        rows: vec![
            vec![
                Value::Integer(14),
                Value::Text("Sky/Western_Ellevar.sky".into()),
                Value::Text("Sky/Western_Ellevar_Flux.sky".into()),
                Value::Text("Ellevar Open Sky".into()),
            ],
            vec![
                Value::Integer(16),
                Value::Text("Sky/Western_CreepyForest.sky".into()),
                Value::Text("".into()),
                Value::Text("Creepy Forest".into()),
            ],
        ],
    };
    let skies = world_skies(&table).expect("valid world skies table");
    assert_eq!(skies.len(), 2);
    let s14 = skies.get(&14).unwrap();
    assert_eq!(s14.asset_path, "Sky/Western_Ellevar.sky");
    assert_eq!(s14.asset_path_in_flux, "Sky/Western_Ellevar_Flux.sky");
    assert_eq!(s14.description, "Ellevar Open Sky");
}

#[derive(Debug, Clone)]
pub struct WorldZone {
    pub id: u32,
    pub localized_text_id_name: u32,
    pub parent_zone_id: u32,
    pub color: i32,
    pub flags: u32,
}

pub fn world_zones(table: &Table) -> Result<HashMap<u32, WorldZone>, String> {
    if table.column("ID").is_none() {
        return Err("WorldZone: mandatory column ID absent".into());
    }
    let mut result = HashMap::new();
    for row in &table.rows {
        let Some(id) = table.get(row, "ID").and_then(Value::as_id) else { continue; };
        let localized_text_id_name = table.get(row, "localizedTextIdName").and_then(Value::as_id).unwrap_or(0);
        let parent_zone_id = table.get(row, "parentZoneId").and_then(Value::as_id).unwrap_or(0);
        let color = table.get(row, "color").and_then(|v| match v {
            Value::Integer(n) => Some(*n as i32),
            _ => None,
        }).unwrap_or(0);
        let flags = table.get(row, "flags").and_then(Value::as_id).unwrap_or(0);
        result.insert(id, WorldZone {
            id,
            localized_text_id_name,
            parent_zone_id,
            color,
            flags,
        });
    }
    Ok(result)
}

#[derive(Debug, Clone)]
pub struct MapZone {
    pub id: u32,
    pub folder: String,
    pub map_zone_id_parent: u32,
    pub world_zone_id: u32,
}

pub fn map_zones(table: &Table) -> Result<HashMap<u32, MapZone>, String> {
    if table.column("ID").is_none() {
        return Err("MapZone: mandatory column ID absent".into());
    }
    let mut result = HashMap::new();
    for row in &table.rows {
        let Some(id) = table.get(row, "ID").and_then(Value::as_id) else { continue; };
        let folder = table.get(row, "folder").and_then(Value::as_text).unwrap_or("");
        let map_zone_id_parent = table.get(row, "mapZoneIdParent").and_then(Value::as_id).unwrap_or(0);
        let world_zone_id = table.get(row, "worldZoneId").and_then(Value::as_id).unwrap_or(0);
        result.insert(id, MapZone {
            id,
            folder: folder.to_string(),
            map_zone_id_parent,
            world_zone_id,
        });
    }
    Ok(result)
}

#[test]
fn extracts_world_zone_and_map_zone_metadata() {
    let ztable = Table {
        columns: vec!["ID".into(), "localizedTextIdName".into(), "parentZoneId".into(), "color".into(), "flags".into()],
        rows: vec![
            vec![Value::Integer(4762), Value::Integer(682475), Value::Integer(0), Value::Integer(14587681), Value::Integer(0)],
            vec![Value::Integer(6002), Value::Integer(750136), Value::Integer(4762), Value::Integer(526344), Value::Integer(212)],
        ],
    };
    let zones = world_zones(&ztable).unwrap();
    assert_eq!(zones.len(), 2);
    assert_eq!(zones[&4762].parent_zone_id, 0);
    assert_eq!(zones[&6002].parent_zone_id, 4762);

    let mtable = Table {
        columns: vec!["ID".into(), "folder".into(), "mapZoneIdParent".into(), "worldZoneId".into()],
        rows: vec![
            vec![Value::Integer(476), Value::Text("Arcterra".into()), Value::Integer(0), Value::Integer(0)],
            vec![Value::Integer(531), Value::Text("ArcterraIcebloodBarrow".into()), Value::Integer(476), Value::Integer(4865)],
        ],
    };
    let mzones = map_zones(&mtable).unwrap();
    assert_eq!(mzones[&476].folder, "Arcterra");
    assert_eq!(mzones[&531].world_zone_id, 4865);
}
