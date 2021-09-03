pub mod punctuation {
    pub const OPENING_BRACE: &'static str = "{";
    pub const CLOSING_BRACE: &'static str = "}";
    pub const OPENING_PARENTH: &'static str = "(";
    pub const CLOSING_PARENTH: &'static str = ")";
    pub const PIPE: &'static str = "|";
    pub const COMMA: &'static str = ",";
    pub const BACKSLASH: &'static str = "\\";
    pub const UNDERSCORE: &'static str = "_";
}

pub mod identifier {
    pub const KEYCODE_NOT_STARTSWITH: &'static str = "|0123456789";
    pub const KEYCODE_ONEOF: &'static str = "0123456789_";
    pub const MACRO_KEYENTRY_NONEOF: &'static str = ",\\";
    pub const ACCEPTABLE_CHAR: &'static str =
        "abcdefghijklmnopqrstuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
}
