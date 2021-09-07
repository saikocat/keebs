use nom::{
    branch::alt,
    bytes::complete::{tag, take_until},
    character::complete::{
        alphanumeric1, digit1, line_ending, multispace0, multispace1, none_of, one_of, space1,
    },
    combinator::{peek, recognize},
    error::ParseError,
    multi::{many1, separated_list0, separated_list1},
    sequence::{delimited, pair, preceded, terminated, tuple},
    IResult,
};

use super::layout::LayoutMacroKeyEntry;
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
        tag(punctuation::OPENING_PARENTH),
        many1(alt((
            recognize(tuple((multispace0, tag(punctuation::COMMA), multispace0))),
            modsbit_keycode,
            digit1,
            keycode,
        ))),
        tag(punctuation::CLOSING_PARENTH),
    )))(input);
}

/// Layout Macro Alias
///
/// To find defined aliases for layouts
pub fn layout_macro_alias(input: &str) -> IResult<&str, (&str, &str)> {
    return delimited(
        recognize(pair(tag("#define"), space1)),
        alt((
            tuple((
                terminated(layout_macro_name_matcher(), space1),
                layout_macro_name_matcher(),
            )),
            tuple((
                terminated(tag("LAYOUT"), space1),
                layout_macro_name_matcher(),
            )),
        )),
        line_ending,
    )(input);
}

/// Layout Macro Def
///
/// Usually inside <keyboard>.h or their rev folder .h file
/// "#define LAYOUT (" or "#define LAYOUT_xxxx_xxx ("
pub fn layout_macro_def(input: &str) -> IResult<&str, &str> {
    return delimited(
        pair(tag("#define"), multispace0),
        alt((layout_macro_name_matcher(), tag("LAYOUT"))),
        pair(multispace0, peek(tag(punctuation::CLOSING_PARENTH))),
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

/// Layout Macro KeyEntry
pub fn layout_macro_keyentry(input: &str) -> IResult<&str, Vec<Vec<LayoutMacroKeyEntry>>> {
    let (rest, rows) = many1(terminated(
        separated_list1(
            tag(punctuation::COMMA),
            recognize(many1(none_of(identifier::MACRO_KEYENTRY_NONEOF))),
        ),
        pair(tag(punctuation::BACKSLASH), line_ending),
    ))(input)?;

    // TODO: lazy to write full nom for now
    // Get 1 entry length, preceding space is used for width_factor later per entry
    let entry_length: usize = rows.iter().fold(1, |mut acc, row| {
        if row[0].len() > acc {
            acc = row[0].trim().len();
        }
        return acc;
    });

    let entry_mapper = |entry: &str| {
        return LayoutMacroKeyEntry {
            label: entry.to_string().trim().to_string(),
            width_factor: (entry.len() / entry_length) as u8,
        };
    };
    let row_mapper = |row: &Vec<&str>| {
        return row
            .iter()
            .map(|entry| entry_mapper(entry))
            .collect::<Vec<LayoutMacroKeyEntry>>();
    };
    let result = rows
        .iter()
        .map(|row| row_mapper(row))
        .collect::<Vec<Vec<LayoutMacroKeyEntry>>>();

    return Ok((rest, result));
}

/// Match any LAYOUT_xxx_xxx macro name
fn layout_macro_name_matcher<'a, E: ParseError<&'a str>>(
) -> impl FnMut(&'a str) -> IResult<&'a str, &'a str, E> {
    return recognize(pair(
        tag("LAYOUT_"),
        many1(one_of(identifier::ACCEPTABLE_CHAR)),
    ));
}
