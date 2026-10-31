# WildStar Database Table (.tbl) Format Specification
**Decompiled from `WildStar64.exe` (`FUN_1407beb20`, `FUN_1407c15c0`, `FUN_1407c1f00`)**

WildStar stores all game database definitions (creatures, spells, items, displays, world maps) in binary `.tbl` files.

## 1. Table Header (96 bytes / 0x60)

| Offset | Type | Field | Description |
|---|---|---|---|
| `0x00` | `uint32` | `magic` | `'LBTD'` (`0x4454424C`, little-endian "DTBL") |
| `0x04` | `uint32` | `version` | Table format version |
| `0x08` | `uint64` | `name_chars` | Length of table name string in UTF-16 code units |
| `0x10` | `uint64` | `name_offset` | Offset to UTF-16 table name string |
| `0x18` | `uint64` | `record_size`| Row stride in bytes (size of each record) |
| `0x20` | `uint64` | `column_count`| Number of field/column definitions |
| `0x28` | `uint64` | `column_offset`| Offset to array of column descriptors (stride: 24 bytes) |
| `0x30` | `uint64` | `row_count` | Total number of data rows in the table |
| `0x38` | `uint64` | `max_id` | Maximum primary key ID in the table |
| `0x40` | `uint64` | `data_offset`| Offset to row data block (`row_count * record_size`) |
| `0x48` | `uint64` | `index_count`| Number of primary key index entries |
| `0x50` | `uint64` | `index_offset`| Offset to ID lookup table |
| `0x58` | `uint64` | `string_offset`| Offset to variable-length string / blob pool |

---

## 2. Column Descriptor (24 bytes / 0x18)

| Offset | Type | Field | Description |
|---|---|---|---|
| `0x00` | `uint64` | `name_chars` | Column name length in UTF-16 code units |
| `0x08` | `uint64` | `name_offset`| Offset to UTF-16 column name string |
| `0x10` | `uint16` | `type` | Field data type enum: <br> `0x03` = `int32` <br> `0x04` = `uint32` <br> `0x14` = `float` <br> `0x80` = Localized string ID / Foreign key <br> `0x82` = String offset into string pool |
| `0x12` | `uint16` | `flags` | Column flags |
| `0x14` | `uint32` | `byte_offset`| Byte offset of this column within the row record (`0..record_size-1`) |
