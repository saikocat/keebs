use nom::{
    branch::alt,
    bytes::complete::tag,
    character::complete::{alphanumeric1, digit1, multispace0, none_of, one_of},
    combinator::recognize,
    multi::{many1, separated_list1},
    sequence::tuple,
    IResult,
};

use super::token::{identifier, punctuation};

/// Keycode Parsing
///
/// QMK Keycode has at least 2 chars, uppercase, underscore allows (like KC_XXXXXX)
pub fn keycode(input: &str) -> IResult<&str, &str> {
    return recognize(tuple((
        none_of(identifier::KEYCODE_NOT_STARTSWITH),
        many1(one_of(identifier::KEYCODE_ONEOF)),
    )))(input);
}

/// Modifier Keycode
///
/// LCTL(KC)
pub fn modifier_keycode(input: &str) -> IResult<&str, &str> {
    return recognize(tuple((
        keycode,
        tag(punctuation::OPENING_PARENTH),
        keycode,
        tag(punctuation::CLOSING_PARENTH),
    )))(input);
}

/// Modifier bitwise Keycode
///
/// MOD_LCTL | MOD_LSFT
pub fn modsbit_keycode(input: &str) -> IResult<&str, &str> {
    return recognize(separated_list1(
        recognize(tuple((multispace0, tag(punctuation::PIPE), multispace0))),
        keycode,
    ))(input);
}

/// Advanced Keycode
///
/// Layer & Mod-Tap Keycodes, and can contains other punctuation (mods_bit, etc.)
/// - MT(MOD_LCTL | MOD_LSFT, KC_ESC)
/// - LM(_LAYER2, MOD_LALT)
/// - LM(_LAYER2, MOD_LCTL | MOD_LALT)
pub fn advanced_keycode(input: &str) -> IResult<&str, &str> {
    return recognize(tuple((
        keycode,
        tag("("),
        many1(alt((
            recognize(tuple((multispace0, tag(","), multispace0))),
            modsbit_keycode,
            digit1,
            keycode,
        ))),
        tag(")"),
    )))(input);
}
