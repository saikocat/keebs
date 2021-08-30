extern crate serde;

use serde::{Deserialize, Serialize};

#[derive(Serialize, Deserialize, Clone, Debug)]
pub struct Layout {
    name: &'static str,
    key_count: u8,
    layout: Vec<String>,
}
