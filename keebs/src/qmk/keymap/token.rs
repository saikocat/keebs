pub mod punctuation {
    pub const OPENING_BRACE: &'static str = "{";
    pub const CLOSING_BRACE: &'static str = "}";
    pub const OPENING_PARENTH: &'static str = "(";
    pub const CLOSING_PARENTH: &'static str = ")";
    pub const PIPE: &'static str = "|";
    pub const COMMA: &'static str = ",";
}

pub mod identifier {
    pub const KEYCODE_NOT_STARTSWITH: &'static str = "|0123456789";
    pub const KEYCODE_ONEOF: &'static str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
}
