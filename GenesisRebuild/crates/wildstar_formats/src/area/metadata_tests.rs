#[cfg(test)]
mod tests {
    use super::*;
    fn sample_cell() -> AreaCell {
        let mut blocks=vec![None;32];
        blocks[1]=Some([11u32,12,13,14].into_iter().flat_map(u32::to_le_bytes).collect());
        blocks[28]=Some([101u32,102,103,104].into_iter().flat_map(u32::to_le_bytes).collect());
        let mut flags=vec![0u8;4096];
        flags[0]=0x20|(2<<3)|1;
        flags[1]=1<<3;
        blocks[16]=Some(flags);
        blocks[27]=Some(vec![0b11100100u8;4096]);
        blocks[6]=Some((0..16u32).flat_map(u32::to_le_bytes).collect());
        blocks[7]=Some((0..16u8).collect());
        blocks[29]=Some(vec![0x21,0xC0].into_iter().cycle().take(8450).collect());
        blocks[2]=Some(vec![0xF0,0x00].into_iter().cycle().take(8450).collect());
        blocks[3]=Some(vec![0x00,0xF8].into_iter().cycle().take(8450).collect());
        AreaCell{index:0,flags:0,blocks,subchunks:Vec::new()}
    }
    #[test]
    fn cell_metadata_decoding() {
        let c=sample_cell();
        assert_eq!(c.layers(),Some([11,12,13,14]));
        assert_eq!(c.zone_id_at(0,0),Some(103));
        assert_eq!(c.zone_id_at(1,0),Some(102));
        let zone=c.zone_summary().unwrap();
        assert_eq!(zone.road_samples,1);
        assert_eq!(zone.suppress_clutter_samples,1);
        assert_eq!(zone.slot_counts.iter().sum::<usize>(),4096);
        assert_eq!(c.clutter_selector(0,0,0),Some(0));
        assert_eq!(c.clutter_selector(0,0,1),Some(1));
        assert_eq!(c.clutter_selector(0,0,2),Some(2));
        assert_eq!(c.clutter_selector(0,0,3),Some(3));
        assert_eq!(c.normalized_weights(0,0),Some([1,2,0,12]));
        assert_eq!(c.authoring_weights(0,0),Some([0,15,0,0]));
        assert_eq!(c.color_rgb565(0,0),Some([255,0,0]));
        assert_eq!(c.sky_ids().unwrap()[0],[0,1,2,3]);
        assert_eq!(c.sky_weights().unwrap()[3],[12,13,14,15]);
        assert!(c.zone_flag(64,0).is_none());
        assert_eq!(c.clutter_selector_histogram().unwrap()[3][3],4096);
    }
    #[test]
    fn props_path_and_transform() {
        let mut data=vec![0u8;112];
        data[..4].copy_from_slice(&1u32.to_le_bytes());
        data[24..28].copy_from_slice(&112u32.to_le_bytes()); // +16
        data[32..36].copy_from_slice(&1.5f32.to_le_bytes()); // +24
        data[36..40].copy_from_slice(&0.25f32.to_le_bytes()); // rot x
        data[52..56].copy_from_slice(&125f32.to_le_bytes()); // position x
        data[84..88].copy_from_slice(&0x12345678u32.to_le_bytes());
        for letter in "Art/Creature/Test.m3".encode_utf16(){
            data.extend(letter.to_le_bytes());
        }
        data.extend(0u16.to_le_bytes());
        let props=decode_props(&data).unwrap();
        assert_eq!(props.len(),1);
        assert_eq!(props[0].model_path.as_deref(),Some("Art/Creature/Test.m3"));
        assert_eq!(props[0].scale,1.5);
        assert_eq!(props[0].position_xyz[0],125.);
        assert_eq!(props[0].tint,0x12345678);
        assert_eq!(props[0].raw_record.len(),104);
        data[..4].copy_from_slice(&u32::MAX.to_le_bytes());
        assert!(decode_props(&data).is_err());
    }
    #[test]
    fn real_tile_is_still_readable() {
        let bytes=include_bytes!("../../../../../WildStarModelStudio/demo/Hills.area");
        let area=RawArea::from_bytes(bytes.to_vec()).unwrap();
        assert_eq!(area.cell_count(),256);
        assert_eq!(area.block_occurrences()[0],256);
        assert_eq!(area.prop_placements().unwrap().len(),0);
    }
}
