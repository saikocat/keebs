extern crate serde;

use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Debug)]
pub struct Keymap {
    pub version: u8,
    pub keyboard: String,
    pub keymap: String,
    pub layout: String,
    pub layers: Vec<Vec<String>>
}
