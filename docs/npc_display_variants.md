# NPC display variants (dbg98)

Until dbg97 every NPC showed the default mesh group and default textures of its model. WildStar selects both per display row.

## Table chain

`Creature2` -> `creature2DisplayGroupId` -> `Creature2DisplayGroupEntry` (weight) -> `Creature2DisplayInfo`
`Creature2` -> `creature2ModelInfoId` -> `Creature2ModelInfo` (fallback when the group has no model path)

Both display tables carry `assetPath`, `modelMeshIdNN` and texture overrides (`assetTextureNN` + `modelTextureIdNN`). Links found by `tools/tbl_relations.py`.

## Meaning of the fields

* `modelMeshIdNN` is a ModelMesh id. The M3 header array 0x200 lists `(ModelMesh id, default flag)`; `mesh.group` is the **index** in that list (255 = always drawn). Example: Canimid list `77, 79, 78, 74 (default), 80` -> id 74 = group 3, id 77 = group 0.
* `modelTextureIdNN` is the id stored in the M3 texture record (`Texture::modelTextureId`); the texture is replaced by `assetTextureNN`.

## Implementation

* Model path suffix `~d<Creature2DisplayInfo id>` or `~i<Creature2ModelInfo id>` (`Model3/ModelList`, `VariantSpec::displayKind / displayId`).
* `CM2Shared::LoadM3` reads the row from `ClientData/DB/*.tbl` (`LoadDisplayVariant`) and fills `ConvertOptions::meshIds` / `textureById`; `M3ToM2.cpp` maps ids to groups and replaces the textures. An id that matches no mesh keeps the default selection.
* `tools/ws_npc_patch.py` `variant_list()`: one variant per distinct (model, mesh ids, textures); 2127 variants for 2642 rows. Display id of variant k = `200000 + number of models + k`, `CreatureModelData` name `WS\<model>~d<id>.m3`. `display_count()` is the number of owned ids (used by `ws_plugin_package.py`).
* `tools/ws_spawns.py` `resolve()`: entity display, else the creature's display group (every entry becomes a `creature_template_model` row with its weight as probability), else the model info.
* `tools/m3_to_m2_cli` accepts `--mesh id,id` and `--tex modelTextureId=path` for offline checks: Canimid ids 74 / 77 / 78 / 80 give 13260 / 23958 / 26976 / 38256 indices.

## Not covered

Humanoid displays (race + outfit, `~c` models), colour shift texture and skin / armour colour data, item displays of NPCs, selection of a variant by a spawn-specific display other than the entity display field. Generated DBCs and SQL are in the staging directory only; installing them into the client or server is a separate step.
