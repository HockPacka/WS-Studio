//! Reusable native Rust readers for original WildStar file formats.
//! No Bevy dependency; no intermediary JSON, CSV or DLL.
pub mod area;
pub(crate) mod binary;
pub mod assets;
pub mod i3;
pub mod m3;
pub mod sky;
pub mod tbl;
pub mod tex;
pub mod zone;
