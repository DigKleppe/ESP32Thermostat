/*******************************************************************************
 * Size: 25 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef DEJAVUSANSMONO25
#define DEJAVUSANSMONO25 1
#endif

#if DEJAVUSANSMONO25

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff, 0x3, 0xf0,

    /* U+0022 "\"" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0x80,

    /* U+0023 "#" */
    0x3, 0x1c, 0x6, 0x30, 0xc, 0x60, 0x30, 0xc0,
    0x63, 0xf, 0xff, 0xdf, 0xff, 0x86, 0x18, 0xc,
    0x60, 0x18, 0xc0, 0x31, 0x87, 0xff, 0xef, 0xff,
    0xc3, 0x18, 0xe, 0x30, 0x18, 0xe0, 0x31, 0x80,
    0x63, 0x0,

    /* U+0024 "$" */
    0x4, 0x0, 0x80, 0x10, 0xf, 0xc7, 0xfd, 0xc8,
    0xb1, 0x6, 0x20, 0xc4, 0xe, 0x80, 0xfc, 0x7,
    0xe0, 0x4c, 0x8, 0xc1, 0x18, 0x23, 0xc4, 0xff,
    0xf8, 0xfc, 0x2, 0x0, 0x40, 0x8, 0x1, 0x0,

    /* U+0025 "%" */
    0x3c, 0x1, 0xf8, 0xe, 0x70, 0x30, 0xc0, 0xc3,
    0x3, 0xc, 0xe, 0x70, 0x9f, 0x8e, 0x3d, 0xe0,
    0x1e, 0x3, 0xcf, 0x18, 0x7e, 0x3, 0x9c, 0xc,
    0x30, 0x30, 0xc0, 0xe7, 0x1, 0xf8, 0x3, 0xc0,

    /* U+0026 "&" */
    0xf, 0x80, 0x7f, 0x3, 0x84, 0xc, 0x0, 0x30,
    0x0, 0xc0, 0x1, 0x80, 0x7, 0x0, 0x36, 0x1,
    0x9c, 0x3c, 0x38, 0xf0, 0x63, 0xc0, 0xcf, 0x3,
    0xee, 0x7, 0x1c, 0x3e, 0x3f, 0xd8, 0x7e, 0x70,

    /* U+0027 "'" */
    0xff, 0xfc,

    /* U+0028 "(" */
    0x19, 0x8c, 0x66, 0x31, 0x98, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0x63, 0x18, 0x63, 0xc, 0x60,

    /* U+0029 ")" */
    0xc3, 0x18, 0xc3, 0x18, 0xc3, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x31, 0x8c, 0xc6, 0x63, 0x0,

    /* U+002A "*" */
    0x6, 0x0, 0x60, 0x46, 0x26, 0x66, 0x1f, 0x80,
    0x60, 0x1f, 0x86, 0x66, 0x46, 0x20, 0x60, 0x6,
    0x0,

    /* U+002B "+" */
    0x6, 0x0, 0x30, 0x1, 0x80, 0xc, 0x0, 0x60,
    0x3, 0x3, 0xff, 0xff, 0xff, 0x6, 0x0, 0x30,
    0x1, 0x80, 0xc, 0x0, 0x60, 0x0,

    /* U+002C "," */
    0x77, 0x76, 0xec, 0xc0,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x0, 0x30, 0x6, 0x0, 0x60, 0xe, 0x0, 0xc0,
    0x1c, 0x1, 0x80, 0x38, 0x3, 0x0, 0x70, 0x6,
    0x0, 0xe0, 0xc, 0x0, 0xc0, 0x18, 0x1, 0x80,
    0x30, 0x3, 0x0, 0x70, 0x6, 0x0, 0xe0, 0x0,

    /* U+0030 "0" */
    0xf, 0x3, 0xfc, 0x70, 0xe6, 0x6, 0x60, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x36, 0x6, 0x60, 0x67, 0xe,
    0x3f, 0xc1, 0xf0,

    /* U+0031 "1" */
    0x3e, 0x1f, 0xc3, 0xd8, 0x3, 0x0, 0x60, 0xc,
    0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18, 0x3,
    0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x7f, 0xef,
    0xfc,

    /* U+0032 "2" */
    0x3f, 0x1f, 0xf3, 0x83, 0x0, 0x30, 0x6, 0x0,
    0xc0, 0x18, 0x6, 0x1, 0xc0, 0x30, 0xc, 0x3,
    0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xff, 0xff,
    0xfc,

    /* U+0033 "3" */
    0x3f, 0x7, 0xfc, 0x40, 0xc0, 0x6, 0x0, 0x60,
    0x6, 0x0, 0xe0, 0xfc, 0xf, 0x0, 0xc, 0x0,
    0x60, 0x3, 0x0, 0x30, 0x3, 0x0, 0x7c, 0xe,
    0xff, 0xc3, 0xf8,

    /* U+0034 "4" */
    0x1, 0xc0, 0xe, 0x0, 0xf0, 0xd, 0x80, 0x6c,
    0x6, 0x60, 0x33, 0x3, 0x18, 0x30, 0xc1, 0x86,
    0x18, 0x30, 0xc1, 0x8f, 0xff, 0xff, 0xfc, 0x3,
    0x0, 0x18, 0x0, 0xc0, 0x6, 0x0,

    /* U+0035 "5" */
    0x7f, 0xcf, 0xf9, 0x80, 0x30, 0x6, 0x0, 0xc0,
    0x1f, 0xc3, 0xfc, 0x41, 0xc0, 0x1c, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x3e, 0xe, 0xff, 0x8f,
    0xe0,

    /* U+0036 "6" */
    0xf, 0xc1, 0xfe, 0x38, 0x26, 0x0, 0x60, 0xc,
    0x0, 0xcf, 0x8d, 0xfc, 0xf0, 0xee, 0x7, 0xe0,
    0x3c, 0x3, 0xc0, 0x3e, 0x3, 0x60, 0x77, 0xe,
    0x3f, 0xc1, 0xf8,

    /* U+0037 "7" */
    0xff, 0xff, 0xfc, 0x3, 0x0, 0x60, 0x1c, 0x3,
    0x0, 0x60, 0x1c, 0x3, 0x0, 0xe0, 0x1c, 0x3,
    0x0, 0xe0, 0x18, 0x3, 0x0, 0xe0, 0x18, 0x7,
    0x0,

    /* U+0038 "8" */
    0x1f, 0x83, 0xfc, 0x70, 0xe6, 0x6, 0x60, 0x66,
    0x6, 0x70, 0xc3, 0xf8, 0xf, 0xc3, 0xe, 0x60,
    0x7c, 0x3, 0xc0, 0x3c, 0x3, 0xe0, 0x77, 0xe,
    0x7f, 0xe1, 0xf8,

    /* U+0039 "9" */
    0x1f, 0x3, 0xfc, 0x70, 0xee, 0x6, 0xc0, 0x7c,
    0x3, 0xc0, 0x3c, 0x7, 0xe0, 0x77, 0xf, 0x3f,
    0xb1, 0xf3, 0x0, 0x30, 0x6, 0x0, 0x64, 0x1c,
    0x7f, 0x83, 0xf0,

    /* U+003A ":" */
    0xff, 0x80, 0x0, 0x3, 0xfe,

    /* U+003B ";" */
    0x77, 0x70, 0x0, 0x0, 0x7, 0x77, 0x6e, 0xcc,

    /* U+003C "<" */
    0x0, 0x8, 0x3, 0xc0, 0x7c, 0x1f, 0x83, 0xe0,
    0x78, 0x3, 0x80, 0xf, 0x80, 0x1f, 0x80, 0x1f,
    0x80, 0x3e, 0x0, 0x30,

    /* U+003D "=" */
    0xff, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xe0,

    /* U+003E ">" */
    0x80, 0x7, 0x80, 0x1f, 0x0, 0x3f, 0x0, 0x3e,
    0x0, 0x3c, 0x0, 0xe0, 0x3e, 0xf, 0xc3, 0xf0,
    0x3e, 0x1, 0x80, 0x0,

    /* U+003F "?" */
    0x3e, 0x7f, 0xb0, 0xe0, 0x30, 0x18, 0xc, 0xc,
    0xc, 0xc, 0xe, 0x6, 0x3, 0x1, 0x80, 0x0,
    0x0, 0x30, 0x18, 0xc, 0x0,

    /* U+0040 "@" */
    0x7, 0xe0, 0x3f, 0xc1, 0xc3, 0x8c, 0x7, 0x70,
    0xd, 0x87, 0xbe, 0x3f, 0xf0, 0xc7, 0xc6, 0xf,
    0x18, 0x3c, 0x60, 0xf1, 0x83, 0xc6, 0xf, 0xc,
    0x76, 0x3f, 0xd8, 0x7b, 0x70, 0x0, 0xe0, 0x1,
    0xc0, 0x3, 0xfc, 0x3, 0xf0,

    /* U+0041 "A" */
    0x3, 0x80, 0x7, 0x0, 0x1b, 0x0, 0x36, 0x0,
    0x6c, 0x1, 0x8c, 0x3, 0x18, 0x6, 0x30, 0x1c,
    0x70, 0x30, 0x60, 0x60, 0xc1, 0xff, 0xc3, 0xff,
    0x86, 0x3, 0xc, 0x7, 0x38, 0xe, 0x60, 0xc,
    0xc0, 0x18,

    /* U+0042 "B" */
    0xff, 0xf, 0xfc, 0xc0, 0xec, 0x6, 0xc0, 0x6c,
    0x6, 0xc0, 0xef, 0xfc, 0xff, 0xcc, 0xe, 0xc0,
    0x7c, 0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0xe,
    0xff, 0xef, 0xf8,

    /* U+0043 "C" */
    0x7, 0xc1, 0xff, 0x38, 0x37, 0x0, 0x60, 0xc,
    0x0, 0xc0, 0xc, 0x0, 0xc0, 0xc, 0x0, 0xc0,
    0xc, 0x0, 0xc0, 0x6, 0x0, 0x70, 0x3, 0x83,
    0x1f, 0xf0, 0x7c,

    /* U+0044 "D" */
    0xfe, 0xf, 0xf8, 0xc1, 0xcc, 0x6, 0xc0, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x3c, 0x6, 0xc0, 0xec, 0x1c,
    0xff, 0x8f, 0xe0,

    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x7, 0xff, 0xff, 0xf8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xff, 0xff,
    0xfc,

    /* U+0046 "F" */
    0xff, 0xff, 0xff, 0x0, 0x60, 0xc, 0x1, 0x80,
    0x30, 0x7, 0xfe, 0xff, 0xd8, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x0,

    /* U+0047 "G" */
    0xf, 0xc1, 0xfe, 0x38, 0x26, 0x0, 0x60, 0xc,
    0x0, 0xc0, 0xc, 0x0, 0xc1, 0xfc, 0x1f, 0xc0,
    0x3c, 0x3, 0xc0, 0x36, 0x3, 0x60, 0x33, 0x87,
    0x1f, 0xf0, 0xfc,

    /* U+0048 "H" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1f, 0xff, 0xff, 0xf8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1e, 0x3, 0xc0, 0x78,
    0xc,

    /* U+0049 "I" */
    0xff, 0xff, 0xf0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x1f, 0xc7, 0xf0, 0xc, 0x3, 0x0, 0xc0, 0x30,
    0xc, 0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x38, 0xf, 0x6, 0xff, 0x9f, 0xc0,

    /* U+004B "K" */
    0xc0, 0x76, 0x7, 0x30, 0x71, 0x87, 0xc, 0x70,
    0x67, 0x3, 0x70, 0x1f, 0x80, 0xfc, 0x7, 0x70,
    0x31, 0xc1, 0x86, 0xc, 0x38, 0x60, 0xe3, 0x7,
    0x18, 0x1c, 0xc0, 0x76, 0x3, 0x80,

    /* U+004C "L" */
    0xc0, 0xc, 0x0, 0xc0, 0xc, 0x0, 0xc0, 0xc,
    0x0, 0xc0, 0xc, 0x0, 0xc0, 0xc, 0x0, 0xc0,
    0xc, 0x0, 0xc0, 0xc, 0x0, 0xc0, 0xc, 0x0,
    0xff, 0xff, 0xff,

    /* U+004D "M" */
    0xe0, 0x3f, 0x83, 0xfc, 0x1f, 0xa0, 0xbd, 0x8d,
    0xec, 0x6f, 0x36, 0x79, 0xb3, 0xcd, 0x9e, 0x38,
    0xf1, 0xc7, 0x8e, 0x3c, 0x1, 0xe0, 0xf, 0x0,
    0x78, 0x3, 0xc0, 0x1e, 0x0, 0xc0,

    /* U+004E "N" */
    0xe0, 0x7c, 0xf, 0xc1, 0xf8, 0x3d, 0x87, 0xb0,
    0xf7, 0x1e, 0x63, 0xcc, 0x78, 0xcf, 0x19, 0xe3,
    0xbc, 0x37, 0x86, 0xf0, 0x7e, 0xf, 0xc0, 0xf8,
    0x1c,

    /* U+004F "O" */
    0x1f, 0x83, 0xfc, 0x70, 0xe6, 0x6, 0xe0, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x3e, 0x6, 0x60, 0x67, 0xe,
    0x3f, 0xc1, 0xf0,

    /* U+0050 "P" */
    0xff, 0x1f, 0xfb, 0x7, 0x60, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x7, 0xc1, 0xdf, 0xfb, 0xfc, 0x60,
    0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x0,

    /* U+0051 "Q" */
    0x1f, 0x83, 0xfc, 0x70, 0xe6, 0x6, 0xe0, 0x6c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0xc0,
    0x3c, 0x3, 0xc0, 0x3e, 0x7, 0x60, 0x67, 0xe,
    0x3f, 0xc0, 0xf8, 0x1, 0xc0, 0xe, 0x0, 0x40,

    /* U+0052 "R" */
    0xff, 0x7, 0xfe, 0x30, 0x71, 0x80, 0xcc, 0x6,
    0x60, 0x33, 0x1, 0x98, 0x18, 0xff, 0xc7, 0xf0,
    0x30, 0xe1, 0x83, 0x8c, 0xc, 0x60, 0x73, 0x1,
    0x98, 0xe, 0xc0, 0x36, 0x1, 0xc0,

    /* U+0053 "S" */
    0x1f, 0x8f, 0xf9, 0x83, 0x60, 0xc, 0x1, 0x80,
    0x38, 0x3, 0xc0, 0x3f, 0x1, 0xf8, 0x7, 0x0,
    0x30, 0x6, 0x0, 0xc0, 0x1e, 0xe, 0xff, 0xc7,
    0xe0,

    /* U+0054 "T" */
    0xff, 0xff, 0xff, 0xf0, 0x30, 0x0, 0xc0, 0x3,
    0x0, 0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0,
    0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc,
    0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc, 0x0,

    /* U+0055 "U" */
    0xc0, 0x78, 0xf, 0x1, 0xe0, 0x3c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1b, 0x6, 0x7f, 0xc3,
    0xe0,

    /* U+0056 "V" */
    0xc0, 0x1f, 0x1, 0xf8, 0xe, 0xc0, 0x66, 0x3,
    0x38, 0x38, 0xc1, 0x86, 0xc, 0x30, 0x60, 0xc7,
    0x6, 0x30, 0x31, 0x81, 0xdc, 0x6, 0xc0, 0x36,
    0x1, 0xb0, 0x7, 0x0, 0x38, 0x0,

    /* U+0057 "W" */
    0xc0, 0x7, 0xc0, 0x1f, 0x80, 0x3b, 0x0, 0x76,
    0x38, 0xcc, 0x71, 0x98, 0xe3, 0x31, 0x46, 0x66,
    0xcc, 0xed, 0xb8, 0xdb, 0x61, 0xa2, 0xc3, 0x47,
    0x87, 0x8f, 0xf, 0x1e, 0x1e, 0x3c, 0x38, 0x38,
    0x30, 0x60,

    /* U+0058 "X" */
    0x70, 0x1c, 0x70, 0x30, 0x60, 0xe0, 0xe1, 0x80,
    0xc7, 0x1, 0xdc, 0x1, 0xf0, 0x1, 0xe0, 0x3,
    0x80, 0x7, 0x80, 0x1f, 0x0, 0x77, 0x0, 0xc6,
    0x3, 0x86, 0xe, 0xe, 0x18, 0xc, 0x70, 0x1c,
    0xc0, 0x1c,

    /* U+0059 "Y" */
    0xe0, 0x1d, 0xc0, 0xe3, 0x3, 0xe, 0x1c, 0x18,
    0x60, 0x73, 0x80, 0xcc, 0x1, 0xe0, 0x7, 0x80,
    0xc, 0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc,
    0x0, 0x30, 0x0, 0xc0, 0x3, 0x0, 0xc, 0x0,

    /* U+005A "Z" */
    0xff, 0xff, 0xff, 0x0, 0x70, 0xe, 0x1, 0xc0,
    0x1c, 0x3, 0x80, 0x30, 0x6, 0x0, 0xe0, 0xc,
    0x1, 0x80, 0x38, 0x3, 0x0, 0x60, 0xe, 0x0,
    0xff, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0xc6, 0x31, 0x8c, 0x7f, 0xe0,

    /* U+005C "\\" */
    0xe0, 0x6, 0x0, 0x70, 0x3, 0x0, 0x38, 0x1,
    0x80, 0x1c, 0x0, 0xc0, 0xe, 0x0, 0x60, 0x6,
    0x0, 0x30, 0x3, 0x0, 0x18, 0x1, 0x80, 0xc,
    0x0, 0xc0, 0xe, 0x0, 0x60, 0x7, 0x0, 0x30,

    /* U+005D "]" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0xff, 0xe0,

    /* U+005E "^" */
    0x0,

    /* U+005F "_" */
    0xff, 0xfe,

    /* U+0060 "`" */
    0xe1, 0xc3, 0x6, 0xc,

    /* U+0061 "a" */
    0x3f, 0xf, 0xf9, 0x3, 0x0, 0x30, 0x6, 0x3f,
    0xdf, 0xff, 0x3, 0xc0, 0x78, 0xf, 0x3, 0xf0,
    0xf7, 0xf6, 0x7c, 0xc0,

    /* U+0062 "b" */
    0xc0, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x9e,
    0x3f, 0xe7, 0x8e, 0xe0, 0xd8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1f, 0x6, 0xf1, 0xdf,
    0xf3, 0x3c, 0x0,

    /* U+0063 "c" */
    0xf, 0x87, 0xfd, 0xc1, 0xb0, 0xc, 0x1, 0x80,
    0x30, 0x6, 0x0, 0xc0, 0x18, 0x1, 0x80, 0x38,
    0x33, 0xfe, 0x1f, 0x0,

    /* U+0064 "d" */
    0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x3c,
    0xcf, 0xfb, 0x8f, 0x60, 0xf8, 0xf, 0x1, 0xe0,
    0x3c, 0x7, 0x80, 0xf0, 0x1b, 0x7, 0x71, 0xe7,
    0xfc, 0x79, 0x80,

    /* U+0065 "e" */
    0xf, 0x83, 0xfc, 0x70, 0x66, 0x3, 0xc0, 0x3f,
    0xff, 0xff, 0xfc, 0x0, 0xc0, 0xc, 0x0, 0x60,
    0x7, 0x7, 0x3f, 0xf0, 0xfc,

    /* U+0066 "f" */
    0x3, 0xe0, 0xfc, 0x30, 0x6, 0x0, 0xc1, 0xff,
    0xff, 0xf8, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6,
    0x0, 0xc0, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1,
    0x80, 0x30, 0x0,

    /* U+0067 "g" */
    0x1e, 0x67, 0xfd, 0xc7, 0xb0, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xd, 0x83, 0xb8,
    0xf3, 0xf6, 0x3c, 0xc0, 0x18, 0x3, 0x60, 0xcf,
    0xf0, 0xfc, 0x0,

    /* U+0068 "h" */
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x33, 0xcd,
    0xfb, 0xc7, 0xe0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xc,

    /* U+0069 "i" */
    0x6, 0x0, 0xc0, 0x18, 0x0, 0x0, 0x0, 0xfc,
    0x1f, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18, 0x3,
    0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x1f,
    0xff, 0xff, 0x80,

    /* U+006A "j" */
    0x6, 0xc, 0x18, 0x0, 0xf, 0xdf, 0x83, 0x6,
    0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc,
    0x18, 0x30, 0x61, 0xff, 0x7c,

    /* U+006B "k" */
    0xc0, 0x18, 0x3, 0x0, 0x60, 0xc, 0x1, 0x83,
    0xb0, 0xe6, 0x38, 0xce, 0x1b, 0x83, 0xe0, 0x7e,
    0xe, 0xe1, 0x8e, 0x30, 0xc6, 0x1c, 0xc1, 0xd8,
    0x1b, 0x3, 0x80,

    /* U+006C "l" */
    0xfc, 0x1f, 0x80, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x3, 0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6,
    0x0, 0xc0, 0x18, 0x3, 0x0, 0x60, 0xe, 0x0,
    0xfc, 0xf, 0x80,

    /* U+006D "m" */
    0xdc, 0xef, 0xfe, 0xce, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6,
    0x3c, 0x63, 0xc6, 0x3c, 0x63,

    /* U+006E "n" */
    0xcf, 0x37, 0xef, 0x1f, 0x83, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0,
    0xf0, 0x30,

    /* U+006F "o" */
    0x1f, 0x83, 0xfc, 0x70, 0xe6, 0x6, 0xc0, 0x3c,
    0x3, 0xc0, 0x3c, 0x3, 0xc0, 0x3c, 0x3, 0x60,
    0x67, 0xe, 0x3f, 0xc1, 0xf8,

    /* U+0070 "p" */
    0xcf, 0x1f, 0xf3, 0xc7, 0x70, 0x6c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xf, 0x83, 0x78,
    0xef, 0xf9, 0x9e, 0x30, 0x6, 0x0, 0xc0, 0x18,
    0x3, 0x0, 0x0,

    /* U+0071 "q" */
    0x1e, 0x67, 0xfd, 0xc7, 0xb0, 0x7c, 0x7, 0x80,
    0xf0, 0x1e, 0x3, 0xc0, 0x78, 0xd, 0x83, 0xb8,
    0xf3, 0xfe, 0x3c, 0xc0, 0x18, 0x3, 0x0, 0x60,
    0xc, 0x1, 0x80,

    /* U+0072 "r" */
    0xcf, 0xb7, 0xff, 0x7, 0x80, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0x0,

    /* U+0073 "s" */
    0x3f, 0x1f, 0xee, 0xb, 0x0, 0xc0, 0x38, 0x7,
    0xe0, 0x3e, 0x1, 0xc0, 0x30, 0xf, 0x7, 0xff,
    0x9f, 0xc0,

    /* U+0074 "t" */
    0xc, 0x1, 0x80, 0x30, 0x6, 0xf, 0xff, 0xff,
    0xc3, 0x0, 0x60, 0xc, 0x1, 0x80, 0x30, 0x6,
    0x0, 0xc0, 0x18, 0x3, 0x0, 0x70, 0x7, 0xe0,
    0x7c,

    /* U+0075 "u" */
    0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x3, 0xc0, 0xf0, 0x3c, 0x1f, 0x8f, 0x7e,
    0xcf, 0x30,

    /* U+0076 "v" */
    0xe0, 0x3b, 0x1, 0x98, 0xc, 0xe0, 0xe3, 0x6,
    0x18, 0x30, 0xe3, 0x83, 0x18, 0x18, 0xc0, 0x6e,
    0x3, 0x60, 0x1b, 0x0, 0x78, 0x3, 0x80,

    /* U+0077 "w" */
    0xc0, 0x7, 0xc0, 0x1d, 0x80, 0x33, 0x0, 0x66,
    0x38, 0xcc, 0x71, 0x9c, 0xa7, 0x19, 0x4c, 0x36,
    0xd8, 0x6d, 0xb0, 0xd1, 0x60, 0xe3, 0x81, 0xc7,
    0x3, 0x86, 0x0,

    /* U+0078 "x" */
    0x60, 0x33, 0x83, 0x8e, 0x38, 0x31, 0x80, 0xd8,
    0x7, 0xc0, 0x1c, 0x0, 0xe0, 0xd, 0x80, 0xee,
    0xe, 0x38, 0x60, 0xc7, 0x7, 0x70, 0x1c,

    /* U+0079 "y" */
    0xe0, 0x3b, 0x1, 0x98, 0x1c, 0xe0, 0xc3, 0x6,
    0x18, 0x70, 0x63, 0x3, 0x18, 0x1d, 0xc0, 0x6c,
    0x3, 0x60, 0xe, 0x0, 0x70, 0x3, 0x80, 0x18,
    0x1, 0xc0, 0xc, 0x3, 0xe0, 0x1e, 0x0,

    /* U+007A "z" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x1, 0x80,
    0xe0, 0x70, 0x18, 0xc, 0x6, 0x3, 0x80, 0xff,
    0xff, 0xf0,

    /* U+007B "{" */
    0x3, 0xc1, 0xf0, 0xe0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x1, 0xc3, 0xe0, 0xf8,
    0x7, 0x0, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0xe, 0x1, 0xf0, 0x3c,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf0, 0x3e, 0x1, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xe0, 0x1f, 0x7,
    0xc3, 0x80, 0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0,
    0x30, 0x1c, 0x3f, 0xf, 0x80,

    /* U+007E "~" */
    0x3c, 0xf, 0xf8, 0xf0, 0xfe, 0x3, 0xc0,

    /* U+00B0 "°" */
    0x3c, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+03A9 "Ω" */
    0xf, 0x81, 0xfe, 0xe, 0x38, 0xc0, 0x66, 0x3,
    0x60, 0xf, 0x0, 0x78, 0x3, 0xc0, 0x1e, 0x0,
    0xf0, 0x7, 0x80, 0x36, 0x3, 0x30, 0x19, 0xc1,
    0xc7, 0xc, 0xfc, 0xff, 0xe7, 0xc0,

    /* U+03BC "μ" */
    0xc0, 0xcc, 0xc, 0xc0, 0xcc, 0xc, 0xc0, 0xcc,
    0xc, 0xc0, 0xcc, 0xc, 0xc0, 0xcc, 0xc, 0xc1,
    0xce, 0x1c, 0xff, 0xfd, 0xe7, 0xc0, 0xc, 0x0,
    0xc0, 0xc, 0x0, 0xc0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 241, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 241, .box_w = 2, .box_h = 18, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 241, .box_w = 7, .box_h = 7, .ofs_x = 4, .ofs_y = 11},
    {.bitmap_index = 13, .adv_w = 241, .box_w = 15, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 241, .box_w = 11, .box_h = 23, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 79, .adv_w = 241, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 111, .adv_w = 241, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 241, .box_w = 2, .box_h = 7, .ofs_x = 6, .ofs_y = 11},
    {.bitmap_index = 145, .adv_w = 241, .box_w = 5, .box_h = 23, .ofs_x = 5, .ofs_y = -4},
    {.bitmap_index = 160, .adv_w = 241, .box_w = 5, .box_h = 23, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 175, .adv_w = 241, .box_w = 12, .box_h = 11, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 192, .adv_w = 241, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 214, .adv_w = 241, .box_w = 4, .box_h = 7, .ofs_x = 5, .ofs_y = -3},
    {.bitmap_index = 218, .adv_w = 241, .box_w = 6, .box_h = 2, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 220, .adv_w = 59, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 241, .box_w = 12, .box_h = 21, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 254, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 465, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 59, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 524, .adv_w = 241, .box_w = 4, .box_h = 16, .ofs_x = 5, .ofs_y = -3},
    {.bitmap_index = 532, .adv_w = 241, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 552, .adv_w = 241, .box_w = 13, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 564, .adv_w = 241, .box_w = 13, .box_h = 12, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 584, .adv_w = 241, .box_w = 9, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 241, .box_w = 14, .box_h = 21, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 642, .adv_w = 241, .box_w = 15, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 757, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 834, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 241, .box_w = 10, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 882, .adv_w = 241, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 905, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 962, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 992, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1017, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1044, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1069, .adv_w = 241, .box_w = 12, .box_h = 21, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1101, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1131, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1156, .adv_w = 241, .box_w = 14, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1188, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 241, .box_w = 15, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1277, .adv_w = 241, .box_w = 15, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1311, .adv_w = 241, .box_w = 14, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1343, .adv_w = 241, .box_w = 12, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1370, .adv_w = 241, .box_w = 5, .box_h = 23, .ofs_x = 6, .ofs_y = -4},
    {.bitmap_index = 1385, .adv_w = 241, .box_w = 12, .box_h = 21, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1417, .adv_w = 241, .box_w = 5, .box_h = 23, .ofs_x = 4, .ofs_y = -4},
    {.bitmap_index = 1432, .adv_w = 39, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1433, .adv_w = 241, .box_w = 15, .box_h = 1, .ofs_x = 0, .ofs_y = -6},
    {.bitmap_index = 1435, .adv_w = 241, .box_w = 6, .box_h = 5, .ofs_x = 3, .ofs_y = 15},
    {.bitmap_index = 1439, .adv_w = 241, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1459, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1486, .adv_w = 241, .box_w = 11, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1506, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1533, .adv_w = 241, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1554, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1581, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1608, .adv_w = 241, .box_w = 10, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1632, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1659, .adv_w = 241, .box_w = 7, .box_h = 24, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1680, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1707, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1734, .adv_w = 241, .box_w = 12, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1755, .adv_w = 241, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1773, .adv_w = 241, .box_w = 12, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1794, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1821, .adv_w = 241, .box_w = 11, .box_h = 19, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1848, .adv_w = 241, .box_w = 10, .box_h = 14, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1866, .adv_w = 241, .box_w = 10, .box_h = 14, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1884, .adv_w = 241, .box_w = 11, .box_h = 18, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1909, .adv_w = 241, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1927, .adv_w = 241, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1950, .adv_w = 241, .box_w = 15, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1977, .adv_w = 241, .box_w = 13, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2000, .adv_w = 241, .box_w = 13, .box_h = 19, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 2031, .adv_w = 241, .box_w = 10, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2049, .adv_w = 241, .box_w = 10, .box_h = 23, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 2078, .adv_w = 241, .box_w = 2, .box_h = 25, .ofs_x = 6, .ofs_y = -6},
    {.bitmap_index = 2085, .adv_w = 241, .box_w = 10, .box_h = 23, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 2114, .adv_w = 241, .box_w = 13, .box_h = 4, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 2121, .adv_w = 241, .box_w = 8, .box_h = 8, .ofs_x = 4, .ofs_y = 11},
    {.bitmap_index = 2129, .adv_w = 241, .box_w = 13, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2159, .adv_w = 241, .box_w = 12, .box_h = 19, .ofs_x = 2, .ofs_y = -5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x2f9, 0x30c
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 781, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 3, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t dejaVuSansMono25 = {
#else
lv_font_t dejaVuSansMono25 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 26,          /*The maximum line height required by the font*/
    .base_line = 6,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if DEJAVUSANSMONO25*/
