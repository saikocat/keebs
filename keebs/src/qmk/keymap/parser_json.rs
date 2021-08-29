extern crate serde_json;

use serde_json::Result;
use super::Keymap;

pub fn from_str(data: &str) -> Result<Keymap> {
    let keymap: Keymap = serde_json::from_str(data)?;
    Ok(keymap)
}
