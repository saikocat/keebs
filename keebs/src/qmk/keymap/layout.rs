extern crate serde;

use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Clone, Debug)]
pub struct LayoutMacro {
    name: &'static str,
    key_count: u8,
    layout: Vec<String>,
    aliases: Vec<String>,
    // matrix is not needed for now
}

/// LayoutMacroKeyEntry
///
/// width_factor will determine the key entry display size on the final format
#[derive(Clone, Debug)]
pub struct LayoutMacroKeyEntry {
    pub label: String,
    pub width_factor: u8,
}
