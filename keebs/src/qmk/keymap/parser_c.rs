use nom::{
    branch::alt,
    bytes::complete::{tag, take_until},
    character::complete::{
        alphanumeric1, digit1, line_ending, multispace0, multispace1, none_of, one_of,
    },
    combinator::recognize,
    error::ParseError,
    multi::{many1, separated_list0, separated_list1},
    sequence::{delimited, pair, preceded, terminated, tuple},
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

/// Layout Macro Def
///
/// Usually inside <keyboard>.h or their rev folder .h file
/// "#define LAYOUT (" or "#define LAYOUT_xxxx_xxx ("
pub fn layout_macro_def(input: &str) -> IResult<&str, &str> {
    return preceded(
        pair(tag("#define"), multispace0),
        alt((
            recognize(pair(
                tag("LAYOUT_"),
                many1(one_of(identifier::ACCEPTABLE_CHAR)),
            )),
            tag("LAYOUT"),
        )),
    )(input);
}

/// Layout Macro Layout
///
/// Content of the macro layout - switches position parts
/// "( \
/// k1, k2, k3 \
/// k4, k5, k6 \
/// )"
pub fn layout_macro_layout(input: &str) -> IResult<&str, &str> {
    return delimited(
        tuple((
            tag(punctuation::OPENING_PARENTH),
            multispace0,
            tag(punctuation::BACKSLASH),
            line_ending,
        )),
        recognize(many1(none_of(punctuation::CLOSING_PARENTH))),
        tag(punctuation::CLOSING_PARENTH),
    )(input);
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

/// Match any LAYOUT_xxx_xxx macro name
fn layout_macro_name_matcher<'a, E: ParseError<&'a str>>(
) -> impl FnMut(&'a str) -> IResult<&'a str, &'a str, E> {
    return recognize(pair(
        tag("LAYOUT_"),
        many1(one_of(identifier::ACCEPTABLE_CHAR)),
    ));
}
