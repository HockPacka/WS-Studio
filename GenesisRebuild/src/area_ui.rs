//! Read-only Genesis AREA metadata view. Every value comes from wildstar_formats,
//! and fields not yet understood are described as unknown, never invented.
use bevy_egui::egui;
use wildstar_formats::area::{RawArea,AreaProp,block_description,block_expected_bytes};

pub fn show(
    ui:&mut egui::Ui,
    selected_cell:&mut usize,
    tile:&RawArea,
    props:&[AreaProp],
    prop_issue:Option<&str>,
) {
    ui.label(egui::RichText::new("Original WildStar .area").strong());
    ui.monospace(format!(
        "version {} | {} | {} bytes",
        tile.version,if tile.compressed {"AERA zlib"} else {"AREA raw"},tile.original.len()
    ));
    ui.monospace(format!(
        "{} terrain cells | {} top chunks | {} props",
        tile.cell_count(),tile.chunks.len(),props.len()
    ));
    if let Some(prefix)=tile.lod_prefix.as_ref(){
        ui.monospace(format!("Special LOD entry: {} bytes",prefix.len()));
    }
    if let Some(issue)=prop_issue{
        ui.colored_label(egui::Color32::DARK_RED,format!("Props: {issue}"));
    }
    ui.separator();

    ui.collapsing("Raw top chunks",|ui|{
        for (n,chunk) in tile.chunks.iter().enumerate(){
            let id=String::from_utf8_lossy(&chunk.id);
            let hint=match &chunk.id{
                b"KNHC" | b"CHNK"=>"CHNK terrain cells",
                b"pORP"=>"PROP placements",
                b"TRUC"=>"CURT curves (unresolved)",
                b"OMHD"=>"DHMO (unresolved)",
                _=>"unknown",
            };
            ui.monospace(format!("{n:02} {id} @0x{:X} +{} | {hint}",
                chunk.file_offset,chunk.data.len()));
        }
    });
    ui.collapsing("Block usage across tile",|ui|{
        for (bit,count) in tile.block_occurrences().iter().enumerate(){
            if *count==0{continue;}
            ui.label(format!(
                "bit {bit:02} | {count:3} cells | {} bytes/cell",
                block_expected_bytes(bit).unwrap_or(0)
            )).on_hover_text(block_description(bit));
        }
    });
    ui.separator();

    ui.horizontal(|ui|{
        ui.label("Cell");
        ui.add(egui::Slider::new(selected_cell,0..=255).show_value(true));
    });
    let Some(cell)=tile.cells[*selected_cell].as_ref() else{
        ui.label("Cell absent in original file");
        return;
    };
    ui.monospace(format!(
        "x={}  z={}  flags=0x{:08X}",
        cell.index%16,cell.index/16,cell.flags
    ));
    if let Some(h)=cell.height(8,8){
        ui.monospace(format!("Height center: {h:.3} m"));
    }
    if let Some(ids)=cell.layers(){
        ui.collapsing("WorldLayer IDs",|ui|{
            for (slot,id) in ids.iter().enumerate(){
                ui.monospace(format!("Layer {slot}: {id}"));
            }
            ui.label("WorldLayer.csv resolves IDs to terrain materials.");
        });
    }
    if let Some(colors)=cell.color_rgb565(32,32){
        ui.horizontal(|ui|{
            ui.label("RGB565 color (center):");
            let c=egui::Color32::from_rgb(colors[0],colors[1],colors[2]);
            ui.colored_label(c,format!("{colors:?}"));
        });
    }
    if let Some(weights)=cell.normalized_weights(32,32){
        ui.monospace(format!("Normalized blend weights 32,32: {weights:?}"));
    }
    if let Some(weights)=cell.authoring_weights(32,32){
        ui.monospace(format!("Raw authoring weights 32,32: {weights:?}"));
    }
    if let Some(zone)=cell.zone_summary(){
        ui.collapsing("WorldZone and flags (64x64)",|ui|{
            for (i,id) in zone.ids.iter().enumerate(){
                ui.monospace(format!(
                    "slot {i}: zone {id} / {} samples",
                    zone.slot_counts[i]
                ));
            }
            ui.monospace(format!("Dominant zone: {:?}",zone.dominant_id));
            ui.monospace(format!("Road samples (bit 0): {}",zone.road_samples));
            ui.monospace(format!("Clutter suppressed (0x20): {}",zone.suppress_clutter_samples));
        });
    }
    if let Some(sky)=cell.sky_ids(){
        ui.collapsing("WorldSky corners (2x2)",|ui|{
            let weights=cell.sky_weights();
            for (corner,ids) in sky.iter().enumerate(){
                ui.monospace(format!("Corner {corner}: {ids:?}"));
                if let Some(w)=weights{ui.monospace(format!("weights: {:?}",w[corner]));}
            }
        });
    }
    if let Some(hist)=cell.clutter_selector_histogram(){
        ui.collapsing("Clutter preset selectors (64x64)",|ui|{
            for (slot,counts) in hist.iter().enumerate(){
                ui.monospace(format!("Layer {slot}: {counts:?}"));
            }
        });
    }
    ui.collapsing("Raw blocks including unknown fields",|ui|{
        for bit in cell.active_bits(){
            let size=cell.block(bit).map(|b|b.len()).unwrap_or(0);
            ui.label(format!("bit {bit:02} | {size} bytes: {}",block_description(bit)));
        }
    });
    if !cell.subchunks.is_empty(){
        ui.collapsing("Cell subchunks (raw)",|ui|{
            for chunk in &cell.subchunks{
                ui.monospace(format!("{} cell+0x{:X}, {} bytes",
                    String::from_utf8_lossy(&chunk.id),
                    chunk.file_offset,chunk.data.len()));
            }
        });
    }
    if !props.is_empty(){
        ui.separator();
        ui.collapsing(format!("Top-level prop placements ({})",props.len()),|ui|{
            egui::ScrollArea::vertical().max_height(220.0).show(ui,|ui|{
                for prop in props.iter().take(80){
                    ui.collapsing(format!("{}: {}",
                        prop.index,prop.model_path.as_deref().unwrap_or("<invalid name>")),|ui|{
                        ui.monospace(format!("position XYZ: {:?}",prop.position_xyz));
                        ui.monospace(format!("rotation XYZW: {:?}",prop.rotation_xyzw));
                        ui.monospace(format!("scale: {}",prop.scale));
                        ui.monospace(format!("tint: 0x{:08X}",prop.tint));
                    });
                }
                if props.len()>80{ui.label(format!("{} more records",props.len()-80));}
            });
        });
    }
    ui.separator();
    ui.label(egui::RichText::new(
        "Read-only metadata. BC1/BC2 payloads and unresolved fields are preserved.")
        .small());
}
