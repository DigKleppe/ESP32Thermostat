/*******************************************************************************
 * Size: 75 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef INSOLATA75
#define INSOLATA75 1
#endif

#if INSOLATA75

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002C "," */
    0x38, 0xf9, 0xfb, 0xf7, 0xe7, 0xc7, 0x8f, 0x1c,
    0x38, 0x70, 0xc3, 0x86, 0x1c, 0x70, 0xc0, 0x80,

    /* U+002D "-" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+002E "." */
    0x1, 0xef, 0xff, 0xfd, 0xe0, 0x0,

    /* U+0030 "0" */
    0x0, 0x7c, 0x0, 0x3, 0xfe, 0x0, 0x1f, 0xff,
    0x0, 0x3c, 0x3e, 0x0, 0xf0, 0x1e, 0x3, 0xc0,
    0x1e, 0x7, 0x0, 0x3c, 0x1c, 0x0, 0x3c, 0x38,
    0x0, 0x78, 0x70, 0x0, 0x71, 0xc0, 0x0, 0xf3,
    0x80, 0x1, 0xe7, 0x0, 0x7, 0xce, 0x0, 0xf,
    0x9c, 0x0, 0x3f, 0x70, 0x0, 0xf7, 0xe0, 0x1,
    0xcf, 0xc0, 0x7, 0x9f, 0x80, 0x1e, 0x3f, 0x0,
    0x38, 0x7e, 0x0, 0xf0, 0xfc, 0x1, 0xc1, 0xf8,
    0x7, 0x83, 0xf0, 0x1e, 0x7, 0xe0, 0x38, 0xf,
    0xc0, 0xf0, 0x1f, 0x83, 0xc0, 0x3f, 0x7, 0x0,
    0x7e, 0x1e, 0x0, 0xfc, 0x78, 0x1, 0xf8, 0xe0,
    0x3, 0xf3, 0xc0, 0x7, 0xe7, 0x0, 0xe, 0xfe,
    0x0, 0x39, 0xf8, 0x0, 0x73, 0xe0, 0x0, 0xe7,
    0xc0, 0x1, 0xcf, 0x0, 0x3, 0x8f, 0x0, 0xe,
    0x1e, 0x0, 0x1c, 0x3c, 0x0, 0x78, 0x3c, 0x0,
    0xe0, 0x7c, 0x3, 0xc0, 0x7c, 0xf, 0x0, 0x7f,
    0xfc, 0x0, 0x7f, 0xf0, 0x0, 0x7f, 0xc0, 0x0,
    0x8, 0x0,

    /* U+0031 "1" */
    0x0, 0x70, 0xf, 0x3, 0xf0, 0x7f, 0x1f, 0xf7,
    0xe7, 0xf8, 0x7e, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7,
    0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70,
    0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7,
    0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70,
    0x7, 0x0, 0x70, 0x7, 0x0, 0x70, 0x7, 0x0,
    0x70, 0x7, 0x0, 0x70, 0x7, 0x0, 0x70,

    /* U+0032 "2" */
    0x0, 0xfe, 0x0, 0xf, 0xfe, 0x0, 0x7f, 0xfc,
    0x3, 0xe0, 0xf8, 0x1e, 0x0, 0xf0, 0xf0, 0x1,
    0xc7, 0x80, 0x3, 0x9c, 0x0, 0xe, 0xf0, 0x0,
    0x3b, 0x80, 0x0, 0x72, 0x0, 0x1, 0xc0, 0x0,
    0x7, 0x0, 0x0, 0x1c, 0x0, 0x0, 0x70, 0x0,
    0x1, 0xc0, 0x0, 0x7, 0x0, 0x0, 0x1c, 0x0,
    0x0, 0xf0, 0x0, 0x3, 0x80, 0x0, 0xe, 0x0,
    0x0, 0x38, 0x0, 0x1, 0xc0, 0x0, 0x7, 0x0,
    0x0, 0x38, 0x0, 0x0, 0xe0, 0x0, 0x7, 0x0,
    0x0, 0x3c, 0x0, 0x0, 0xe0, 0x0, 0x7, 0x80,
    0x0, 0x3c, 0x0, 0x0, 0xe0, 0x0, 0x7, 0x80,
    0x0, 0x3c, 0x0, 0x1, 0xe0, 0x0, 0x7, 0x0,
    0x0, 0x3c, 0x0, 0x1, 0xe0, 0x0, 0xf, 0x0,
    0x0, 0x78, 0x0, 0x1, 0xe0, 0x0, 0xf, 0x0,
    0x0, 0x78, 0x0, 0x3, 0xc0, 0x0, 0xf, 0x0,
    0x1, 0x7f, 0xff, 0xfd, 0xff, 0xff, 0xf7, 0xff,
    0xff, 0xc0,

    /* U+0033 "3" */
    0x1, 0xfc, 0x0, 0x3f, 0xf8, 0x3, 0xff, 0xe0,
    0x3e, 0xf, 0x83, 0xc0, 0x1e, 0x3c, 0x0, 0x70,
    0x40, 0x3, 0x80, 0x0, 0xe, 0x0, 0x0, 0x70,
    0x0, 0x3, 0x80, 0x0, 0x1c, 0x0, 0x0, 0xe0,
    0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x3, 0xc0,
    0x0, 0x1c, 0x0, 0x0, 0xe0, 0x0, 0xf, 0x0,
    0x0, 0xf0, 0x0, 0xf, 0x0, 0x1, 0xf0, 0x1,
    0xff, 0x0, 0xf, 0xf0, 0x0, 0x7f, 0xe0, 0x0,
    0xf, 0x80, 0x0, 0x1e, 0x0, 0x0, 0x78, 0x0,
    0x1, 0xe0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0,
    0x1, 0xc0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0,
    0x3, 0x80, 0x0, 0x1c, 0x0, 0x1, 0xe0, 0x0,
    0xe, 0x20, 0x0, 0x73, 0x80, 0x7, 0x9e, 0x0,
    0x78, 0x78, 0x7, 0x81, 0xff, 0xfc, 0x7, 0xff,
    0xc0, 0x1f, 0xf8, 0x0, 0xc, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x70, 0x0, 0x0, 0x38, 0x0, 0x0,
    0x3c, 0x0, 0x0, 0x1e, 0x0, 0x0, 0x1f, 0x0,
    0x0, 0xf, 0x80, 0x0, 0xf, 0xc0, 0x0, 0x7,
    0xe0, 0x0, 0x7, 0xf0, 0x0, 0x3, 0xb8, 0x0,
    0x3, 0xdc, 0x0, 0x3, 0xce, 0x0, 0x1, 0xe7,
    0x0, 0x1, 0xe3, 0x80, 0x0, 0xe1, 0xc0, 0x0,
    0xf0, 0xe0, 0x0, 0x70, 0x70, 0x0, 0x78, 0x38,
    0x0, 0x38, 0x1c, 0x0, 0x3c, 0xe, 0x0, 0x1c,
    0x7, 0x0, 0x1e, 0x3, 0x80, 0x1e, 0x1, 0xc0,
    0xe, 0x0, 0xe0, 0xf, 0x0, 0x70, 0x7, 0x0,
    0x38, 0x7, 0x80, 0x1c, 0x3, 0x80, 0xe, 0x3,
    0xc0, 0x7, 0x1, 0xc0, 0x3, 0x81, 0xe0, 0x1,
    0xc0, 0xe0, 0x0, 0xe0, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x0, 0xe,
    0x0, 0x0, 0x7, 0x0, 0x0, 0x3, 0x80, 0x0,
    0x1, 0xc0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0x70,
    0x0, 0x0, 0x38, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe, 0x0, 0x0, 0x7, 0x0, 0x0, 0x3, 0x80,
    0x0, 0x1, 0xc0,

    /* U+0035 "5" */
    0x3f, 0xff, 0xf8, 0xff, 0xff, 0xe3, 0xff, 0xff,
    0x8e, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0x3, 0x80, 0x0, 0xe, 0x0, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0x3, 0x80, 0x0, 0xe, 0x0,
    0x0, 0x38, 0x0, 0x0, 0xe0, 0x0, 0x3, 0x80,
    0x0, 0xe, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe1,
    0xf8, 0x7, 0x9f, 0xf8, 0x1f, 0xff, 0xf0, 0x7f,
    0x3, 0xe1, 0xf0, 0x7, 0xc7, 0x80, 0xf, 0x1c,
    0x0, 0x1e, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe0,
    0x0, 0x3, 0xc0, 0x0, 0x7, 0x0, 0x0, 0x1c,
    0x0, 0x0, 0x70, 0x0, 0x1, 0xc0, 0x0, 0x7,
    0x0, 0x0, 0x1c, 0x0, 0x0, 0x70, 0x0, 0x1,
    0xc0, 0x0, 0x7, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0xe0, 0x0, 0x3, 0x98, 0x0, 0xe, 0xf0, 0x0,
    0x7b, 0xc0, 0x1, 0xc7, 0x80, 0xf, 0xf, 0x80,
    0xf8, 0x1f, 0xff, 0xc0, 0x3f, 0xfe, 0x0, 0x3f,
    0xe0, 0x0, 0x8, 0x0,

    /* U+0036 "6" */
    0x0, 0x3f, 0x0, 0x3, 0xff, 0x0, 0x1f, 0xff,
    0x0, 0xf8, 0x3e, 0x7, 0x80, 0x78, 0x3c, 0x0,
    0xc0, 0xe0, 0x1, 0x7, 0x0, 0x0, 0x18, 0x0,
    0x0, 0xe0, 0x0, 0x3, 0x80, 0x0, 0xc, 0x0,
    0x0, 0x70, 0x0, 0x1, 0xc0, 0x0, 0x7, 0x0,
    0x0, 0x18, 0x0, 0x0, 0x60, 0x0, 0x3, 0x81,
    0xf8, 0xe, 0x1f, 0xf8, 0x39, 0xff, 0xf0, 0xef,
    0x83, 0xe3, 0xb8, 0x7, 0xcf, 0xc0, 0xf, 0x3e,
    0x0, 0x1e, 0xf8, 0x0, 0x3b, 0xc0, 0x0, 0xee,
    0x0, 0x3, 0xb8, 0x0, 0x7, 0xe0, 0x0, 0x1f,
    0x80, 0x0, 0x7e, 0x0, 0x1, 0xf8, 0x0, 0x7,
    0xe0, 0x0, 0x1f, 0xc0, 0x0, 0x77, 0x0, 0x1,
    0xdc, 0x0, 0x7, 0x70, 0x0, 0x1d, 0xc0, 0x0,
    0xe3, 0x80, 0x3, 0x8e, 0x0, 0xe, 0x3c, 0x0,
    0x70, 0x70, 0x1, 0xc1, 0xe0, 0xe, 0x3, 0xc0,
    0x78, 0x7, 0xff, 0xc0, 0xf, 0xfe, 0x0, 0x1f,
    0xe0, 0x0, 0x4, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x0, 0x0, 0xf0, 0x0, 0x7, 0x0, 0x0, 0x78,
    0x0, 0x3, 0xc0, 0x0, 0x1c, 0x0, 0x1, 0xe0,
    0x0, 0xf, 0x0, 0x0, 0x70, 0x0, 0x7, 0x80,
    0x0, 0x3c, 0x0, 0x1, 0xc0, 0x0, 0xe, 0x0,
    0x0, 0xf0, 0x0, 0x7, 0x80, 0x0, 0x38, 0x0,
    0x3, 0xc0, 0x0, 0x1e, 0x0, 0x0, 0xe0, 0x0,
    0x7, 0x0, 0x0, 0x78, 0x0, 0x3, 0xc0, 0x0,
    0x1c, 0x0, 0x0, 0xe0, 0x0, 0xf, 0x0, 0x0,
    0x70, 0x0, 0x3, 0x80, 0x0, 0x3c, 0x0, 0x1,
    0xe0, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x7,
    0x80, 0x0, 0x3c, 0x0, 0x1, 0xc0, 0x0, 0xe,
    0x0, 0x0, 0xf0, 0x0, 0x7, 0x80, 0x0, 0x38,
    0x0, 0x1, 0xc0, 0x0, 0x1e, 0x0, 0x0, 0xf0,
    0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x3, 0xc0,
    0x0,

    /* U+0038 "8" */
    0x0, 0xfe, 0x0, 0xf, 0xfe, 0x0, 0x7f, 0xfc,
    0x3, 0xe0, 0xf8, 0x1e, 0x0, 0xf0, 0x70, 0x1,
    0xc1, 0xc0, 0x7, 0xe, 0x0, 0x1e, 0x38, 0x0,
    0x38, 0xe0, 0x0, 0xe3, 0x80, 0x3, 0x8e, 0x0,
    0xe, 0x38, 0x0, 0x38, 0xe0, 0x0, 0xe1, 0xc0,
    0x7, 0x7, 0x0, 0x1c, 0x1e, 0x0, 0xe0, 0x3c,
    0x7, 0x80, 0x78, 0x3c, 0x0, 0xf1, 0xe0, 0x1,
    0xff, 0x0, 0x3, 0xf8, 0x0, 0x1f, 0xe0, 0x0,
    0xff, 0xe0, 0x7, 0x87, 0xc0, 0x3c, 0xf, 0x81,
    0xe0, 0x1e, 0xf, 0x0, 0x3c, 0x38, 0x0, 0x79,
    0xc0, 0x0, 0xe7, 0x0, 0x3, 0xbc, 0x0, 0xf,
    0xe0, 0x0, 0x1f, 0x80, 0x0, 0x7e, 0x0, 0x1,
    0xf8, 0x0, 0x7, 0xe0, 0x0, 0x1f, 0x80, 0x0,
    0x7e, 0x0, 0x1, 0xfc, 0x0, 0xe, 0x70, 0x0,
    0x39, 0xe0, 0x1, 0xe3, 0xc0, 0xf, 0xf, 0x80,
    0x7c, 0x1f, 0xff, 0xe0, 0x3f, 0xff, 0x0, 0x3f,
    0xf0, 0x0, 0xc, 0x0,

    /* U+0039 "9" */
    0x0, 0xfc, 0x0, 0xf, 0xfc, 0x0, 0xff, 0xf8,
    0x7, 0xc1, 0xf0, 0x1e, 0x1, 0xe0, 0xf0, 0x3,
    0x83, 0x80, 0x7, 0x1c, 0x0, 0x1c, 0x70, 0x0,
    0x39, 0xc0, 0x0, 0xee, 0x0, 0x3, 0xb8, 0x0,
    0xe, 0xe0, 0x0, 0x3b, 0x80, 0x0, 0x7e, 0x0,
    0x1, 0xf8, 0x0, 0x7, 0xe0, 0x0, 0x1f, 0x80,
    0x0, 0x7e, 0x0, 0x1, 0xdc, 0x0, 0x7, 0x70,
    0x0, 0x1d, 0xe0, 0x0, 0xf3, 0x80, 0x7, 0xcf,
    0x0, 0x3f, 0x1f, 0x3, 0xfc, 0x3f, 0xff, 0x70,
    0x7f, 0xf1, 0xc0, 0x3f, 0x7, 0x0, 0x0, 0x1c,
    0x0, 0x0, 0x70, 0x0, 0x1, 0x80, 0x0, 0x6,
    0x0, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0, 0x3,
    0x80, 0x0, 0xe, 0x0, 0x0, 0x70, 0x0, 0x1,
    0xc0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x0,
    0xe0, 0x80, 0x7, 0x87, 0x0, 0x3c, 0x1e, 0x1,
    0xe0, 0x3f, 0xff, 0x0, 0x7f, 0xf8, 0x0, 0xff,
    0xc0, 0x0, 0x30, 0x0,

    /* U+0041 "A" */
    0x0, 0x6, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0,
    0x6, 0x0, 0x0, 0x0, 0x60, 0x0, 0x0, 0xf,
    0x0, 0x0, 0x0, 0xf0, 0x0, 0x0, 0xf, 0x0,
    0x0, 0x0, 0xf8, 0x0, 0x0, 0x1f, 0x80, 0x0,
    0x1, 0xf8, 0x0, 0x0, 0x1f, 0x80, 0x0, 0x3,
    0x9c, 0x0, 0x0, 0x39, 0xc0, 0x0, 0x3, 0x9c,
    0x0, 0x0, 0x39, 0xc0, 0x0, 0x7, 0xe, 0x0,
    0x0, 0x70, 0xe0, 0x0, 0x7, 0xe, 0x0, 0x0,
    0xf0, 0xf0, 0x0, 0xe, 0x7, 0x0, 0x0, 0xe0,
    0x70, 0x0, 0xe, 0x7, 0x0, 0x1, 0xc0, 0x38,
    0x0, 0x1c, 0x3, 0x80, 0x1, 0xc0, 0x38, 0x0,
    0x1c, 0x3, 0x80, 0x3, 0x80, 0x1c, 0x0, 0x38,
    0x1, 0xc0, 0x3, 0x80, 0x1c, 0x0, 0x78, 0x1,
    0xe0, 0x7, 0xff, 0xfe, 0x0, 0x7f, 0xff, 0xe0,
    0x7, 0xff, 0xfe, 0x0, 0xf0, 0x0, 0xf0, 0xe,
    0x0, 0x7, 0x0, 0xe0, 0x0, 0x70, 0xe, 0x0,
    0x7, 0x1, 0xc0, 0x0, 0x78, 0x1c, 0x0, 0x3,
    0x81, 0xc0, 0x0, 0x38, 0x3c, 0x0, 0x3, 0xc3,
    0x80, 0x0, 0x1c, 0x38, 0x0, 0x1, 0xc3, 0x80,
    0x0, 0x1c, 0x78, 0x0, 0x1, 0xe7, 0x0, 0x0,
    0xe, 0x70, 0x0, 0x0, 0xe7, 0x0, 0x0, 0xe,

    /* U+0045 "E" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0xe0, 0x0, 0x3, 0x80, 0x0,
    0xe, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0x3, 0x80, 0x0, 0xe, 0x0, 0x0, 0x38, 0x0,
    0x0, 0xe0, 0x0, 0x3, 0x80, 0x0, 0xe, 0x0,
    0x0, 0x38, 0x0, 0x0, 0xe0, 0x0, 0x3, 0x80,
    0x0, 0xe, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe0,
    0x0, 0x3, 0xff, 0xff, 0x8f, 0xff, 0xfe, 0x3f,
    0xff, 0xf8, 0xe0, 0x0, 0x3, 0x80, 0x0, 0xe,
    0x0, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0, 0x3,
    0x80, 0x0, 0xe, 0x0, 0x0, 0x38, 0x0, 0x0,
    0xe0, 0x0, 0x3, 0x80, 0x0, 0xe, 0x0, 0x0,
    0x38, 0x0, 0x0, 0xe0, 0x0, 0x3, 0x80, 0x0,
    0xe, 0x0, 0x0, 0x38, 0x0, 0x0, 0xe0, 0x0,
    0x3, 0x80, 0x0, 0xe, 0x0, 0x0, 0x38, 0x0,
    0x0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0,

    /* U+0047 "G" */
    0x0, 0x3f, 0x80, 0x0, 0xff, 0xe0, 0x1, 0xff,
    0xf0, 0x3, 0xe0, 0xf8, 0x7, 0x80, 0x3c, 0xe,
    0x0, 0x1e, 0x1e, 0x0, 0xe, 0x1c, 0x0, 0x7,
    0x38, 0x0, 0x6, 0x38, 0x0, 0x4, 0x38, 0x0,
    0x0, 0x70, 0x0, 0x0, 0x70, 0x0, 0x0, 0x70,
    0x0, 0x0, 0x70, 0x0, 0x0, 0x60, 0x0, 0x0,
    0xe0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0xe0, 0x0,
    0x0, 0xe0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0xe0,
    0x0, 0x0, 0xe0, 0x0, 0x0, 0xe0, 0x0, 0x0,
    0xe0, 0x0, 0x0, 0xe0, 0x7, 0xff, 0xe0, 0x7,
    0xff, 0xe0, 0x7, 0xff, 0xe0, 0x0, 0x7, 0xe0,
    0x0, 0x7, 0xe0, 0x0, 0x7, 0xf0, 0x0, 0x7,
    0x70, 0x0, 0x7, 0x70, 0x0, 0x7, 0x70, 0x0,
    0x7, 0x70, 0x0, 0x7, 0x78, 0x0, 0x7, 0x38,
    0x0, 0x7, 0x3c, 0x0, 0x7, 0x1c, 0x0, 0x7,
    0x1e, 0x0, 0x7, 0xe, 0x0, 0x7, 0xf, 0x0,
    0xf, 0x7, 0xc0, 0x3e, 0x3, 0xff, 0xfc, 0x1,
    0xff, 0xf0, 0x0, 0x7f, 0xc0, 0x0, 0x4, 0x0,

    /* U+0048 "H" */
    0xf0, 0x0, 0xf, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe,
    0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe,
    0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xff, 0xff, 0xfe, 0xff,
    0xff, 0xfe, 0xff, 0xff, 0xfe, 0xe0, 0x0, 0xe,
    0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe,
    0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe,
    0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0,
    0xe, 0xe0, 0x0, 0xe, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe,

    /* U+004D "M" */
    0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7, 0xf0, 0x0,
    0x7, 0xf0, 0x0, 0xf, 0xf0, 0x0, 0xf, 0xf8,
    0x0, 0x1f, 0xf8, 0x0, 0x1f, 0xfc, 0x0, 0x3f,
    0xfc, 0x0, 0x3f, 0xfc, 0x0, 0x3f, 0xfe, 0x0,
    0x77, 0xee, 0x0, 0x77, 0xef, 0x0, 0xf7, 0xe7,
    0x0, 0xe7, 0xe7, 0x0, 0xe7, 0xe3, 0x81, 0xc7,
    0xe3, 0x81, 0xc7, 0xe3, 0xc3, 0x87, 0xe1, 0xc3,
    0x87, 0xe1, 0xe7, 0x87, 0xe0, 0xe7, 0x7, 0xe0,
    0xe7, 0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x7e, 0x7,
    0xe0, 0x7c, 0x7, 0xe0, 0x3c, 0x7, 0xe0, 0x38,
    0x7, 0xe0, 0x18, 0x7, 0xe0, 0x18, 0x7, 0xe0,
    0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7,
    0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0,
    0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0,
    0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7,
    0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0,
    0x7, 0xe0, 0x0, 0x7, 0xe0, 0x0, 0x7, 0xe0,
    0x0, 0x7, 0xe0, 0x0, 0x7,

    /* U+004E "N" */
    0xe0, 0x0, 0xf, 0xf0, 0x0, 0xe, 0xf0, 0x0,
    0xe, 0xf8, 0x0, 0xe, 0xf8, 0x0, 0xe, 0xf8,
    0x0, 0xe, 0xfc, 0x0, 0xe, 0xfc, 0x0, 0xe,
    0xfe, 0x0, 0xe, 0xee, 0x0, 0xe, 0xef, 0x0,
    0xe, 0xe7, 0x0, 0xe, 0xe7, 0x80, 0xe, 0xe3,
    0x80, 0xe, 0xe3, 0xc0, 0xe, 0xe3, 0xc0, 0xe,
    0xe1, 0xc0, 0xe, 0xe1, 0xe0, 0xe, 0xe0, 0xe0,
    0xe, 0xe0, 0xf0, 0xe, 0xe0, 0x70, 0xe, 0xe0,
    0x78, 0xe, 0xe0, 0x38, 0xe, 0xe0, 0x3c, 0xe,
    0xe0, 0x1c, 0xe, 0xe0, 0x1e, 0xe, 0xe0, 0x1e,
    0xe, 0xe0, 0xe, 0xe, 0xe0, 0xf, 0xe, 0xe0,
    0x7, 0xe, 0xe0, 0x7, 0x8e, 0xe0, 0x3, 0x8e,
    0xe0, 0x3, 0xce, 0xe0, 0x1, 0xce, 0xe0, 0x1,
    0xee, 0xe0, 0x1, 0xee, 0xe0, 0x0, 0xfe, 0xe0,
    0x0, 0xfe, 0xe0, 0x0, 0x7e, 0xe0, 0x0, 0x7e,
    0xe0, 0x0, 0x3e, 0xe0, 0x0, 0x3e, 0xe0, 0x0,
    0x1e, 0xe0, 0x0, 0x1e, 0xe0, 0x0, 0xe, 0xe0,
    0x0, 0xe, 0xe0, 0x0, 0xe,

    /* U+004F "O" */
    0x0, 0x3f, 0x0, 0x0, 0x7f, 0xf8, 0x0, 0x3f,
    0xff, 0x0, 0x1f, 0x3, 0xe0, 0xf, 0x0, 0x7c,
    0x3, 0x80, 0x7, 0x1, 0xe0, 0x1, 0xe0, 0x70,
    0x0, 0x38, 0x38, 0x0, 0x7, 0xe, 0x0, 0x1,
    0xc7, 0x80, 0x0, 0x71, 0xc0, 0x0, 0xe, 0x70,
    0x0, 0x3, 0x9c, 0x0, 0x0, 0xe7, 0x0, 0x0,
    0x3b, 0xc0, 0x0, 0xe, 0xe0, 0x0, 0x1, 0xf8,
    0x0, 0x0, 0x7e, 0x0, 0x0, 0x1f, 0x80, 0x0,
    0x7, 0xe0, 0x0, 0x1, 0xf8, 0x0, 0x0, 0x7e,
    0x0, 0x0, 0x1f, 0x80, 0x0, 0x7, 0xe0, 0x0,
    0x1, 0xf8, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x1f,
    0x80, 0x0, 0x7, 0xe0, 0x0, 0x1, 0xf8, 0x0,
    0x0, 0x7e, 0x0, 0x0, 0x1f, 0x80, 0x0, 0x7,
    0xf0, 0x0, 0x3, 0x9c, 0x0, 0x0, 0xe7, 0x0,
    0x0, 0x39, 0xc0, 0x0, 0xe, 0x70, 0x0, 0x3,
    0x8e, 0x0, 0x1, 0xc3, 0x80, 0x0, 0x70, 0xf0,
    0x0, 0x3c, 0x1c, 0x0, 0xe, 0x7, 0x80, 0x7,
    0x80, 0xf0, 0x3, 0xc0, 0x3e, 0x1, 0xe0, 0x7,
    0xff, 0xf8, 0x0, 0x7f, 0xf8, 0x0, 0xf, 0xfc,
    0x0, 0x0, 0x20, 0x0,

    /* U+0052 "R" */
    0xff, 0xfc, 0x1, 0xff, 0xff, 0x3, 0xff, 0xff,
    0x7, 0x0, 0x1f, 0xe, 0x0, 0xf, 0x1c, 0x0,
    0xf, 0x38, 0x0, 0xe, 0x70, 0x0, 0x1c, 0xe0,
    0x0, 0x3d, 0xc0, 0x0, 0x3b, 0x80, 0x0, 0x77,
    0x0, 0x0, 0xee, 0x0, 0x1, 0xdc, 0x0, 0x3,
    0xb8, 0x0, 0x7, 0x70, 0x0, 0xe, 0xe0, 0x0,
    0x3d, 0xc0, 0x0, 0x73, 0x80, 0x0, 0xe7, 0x0,
    0x3, 0x8e, 0x0, 0xf, 0x1c, 0x0, 0x7c, 0x3f,
    0xff, 0xf0, 0x7f, 0xff, 0xc0, 0xff, 0xfe, 0x1,
    0xc0, 0x3c, 0x3, 0x80, 0x78, 0x7, 0x0, 0x70,
    0xe, 0x0, 0xf0, 0x1c, 0x0, 0xe0, 0x38, 0x1,
    0xe0, 0x70, 0x3, 0xc0, 0xe0, 0x3, 0x81, 0xc0,
    0x7, 0x83, 0x80, 0x7, 0x7, 0x0, 0xe, 0xe,
    0x0, 0x1e, 0x1c, 0x0, 0x1c, 0x38, 0x0, 0x3c,
    0x70, 0x0, 0x38, 0xe0, 0x0, 0x71, 0xc0, 0x0,
    0x73, 0x80, 0x0, 0xe7, 0x0, 0x1, 0xee, 0x0,
    0x1, 0xdc, 0x0, 0x3, 0xb8, 0x0, 0x3, 0x80,

    /* U+0056 "V" */
    0xe0, 0x0, 0x1, 0xfc, 0x0, 0x0, 0x77, 0x0,
    0x0, 0x3d, 0xc0, 0x0, 0xe, 0x78, 0x0, 0x3,
    0x9e, 0x0, 0x0, 0xe3, 0x80, 0x0, 0x78, 0xe0,
    0x0, 0x1c, 0x3c, 0x0, 0x7, 0xf, 0x0, 0x1,
    0xc1, 0xc0, 0x0, 0xf0, 0x70, 0x0, 0x38, 0x1e,
    0x0, 0xe, 0x3, 0x80, 0x3, 0x80, 0xe0, 0x1,
    0xe0, 0x38, 0x0, 0x70, 0xf, 0x0, 0x1c, 0x1,
    0xc0, 0x7, 0x0, 0x70, 0x3, 0xc0, 0x1c, 0x0,
    0xe0, 0x7, 0x80, 0x38, 0x0, 0xe0, 0xe, 0x0,
    0x38, 0x7, 0x0, 0xe, 0x1, 0xc0, 0x3, 0xc0,
    0x70, 0x0, 0x70, 0x1c, 0x0, 0x1c, 0xe, 0x0,
    0x7, 0x3, 0x80, 0x1, 0xe0, 0xe0, 0x0, 0x38,
    0x38, 0x0, 0xe, 0x1c, 0x0, 0x3, 0xc7, 0x0,
    0x0, 0x71, 0xc0, 0x0, 0x1c, 0x70, 0x0, 0x7,
    0x38, 0x0, 0x1, 0xee, 0x0, 0x0, 0x3b, 0x80,
    0x0, 0xe, 0xe0, 0x0, 0x3, 0xf0, 0x0, 0x0,
    0xfc, 0x0, 0x0, 0x1f, 0x0, 0x0, 0x7, 0xc0,
    0x0, 0x1, 0xe0, 0x0, 0x0, 0x78, 0x0, 0x0,
    0xe, 0x0, 0x0, 0x3, 0x80, 0x0, 0x0, 0xc0,
    0x0,

    /* U+005E "^" */
    0x0,

    /* U+006B "k" */
    0xf0, 0x0, 0x1, 0xc0, 0x0, 0x3, 0x80, 0x0,
    0x7, 0x0, 0x0, 0xe, 0x0, 0x0, 0x1c, 0x0,
    0x0, 0x38, 0x0, 0x0, 0x70, 0x0, 0x0, 0xe0,
    0x0, 0x1, 0xc0, 0x0, 0x3, 0x80, 0x0, 0x7,
    0x0, 0x0, 0xe, 0x0, 0x0, 0x1c, 0x0, 0x0,
    0x38, 0x0, 0x0, 0x70, 0x0, 0x0, 0xe0, 0x0,
    0x79, 0xc0, 0x0, 0xe3, 0x80, 0x3, 0x87, 0x0,
    0xf, 0xe, 0x0, 0x3c, 0x1c, 0x0, 0xf0, 0x38,
    0x3, 0xc0, 0x70, 0xf, 0x0, 0xe0, 0x3c, 0x1,
    0xc0, 0xf0, 0x3, 0x83, 0xc0, 0x7, 0xf, 0x0,
    0xe, 0x3c, 0x0, 0x1c, 0x70, 0x0, 0x39, 0xf0,
    0x0, 0x77, 0xf0, 0x0, 0xff, 0xe0, 0x1, 0xf9,
    0xe0, 0x3, 0xe1, 0xe0, 0x7, 0x83, 0xc0, 0xe,
    0x3, 0xc0, 0x1c, 0x3, 0xc0, 0x38, 0x7, 0x80,
    0x70, 0x7, 0x80, 0xe0, 0x7, 0x81, 0xc0, 0x7,
    0x83, 0x80, 0xf, 0x7, 0x0, 0xf, 0xe, 0x0,
    0xf, 0x1c, 0x0, 0x1e, 0x38, 0x0, 0x1e, 0x70,
    0x0, 0x1e, 0xe0, 0x0, 0x3d, 0xc0, 0x0, 0x3c,

    /* U+006D "m" */
    0x1, 0xe0, 0x7c, 0x73, 0xf8, 0x7f, 0x3b, 0xfe,
    0x7f, 0xdd, 0x8f, 0x79, 0xef, 0x83, 0xb0, 0x7f,
    0xc0, 0xd8, 0x1f, 0xc0, 0x78, 0xf, 0xe0, 0x3c,
    0x7, 0xe0, 0x1c, 0x3, 0xf0, 0xe, 0x1, 0xf8,
    0x7, 0x0, 0xfc, 0x3, 0x80, 0x7e, 0x1, 0xc0,
    0x3f, 0x0, 0xe0, 0x1f, 0x80, 0x70, 0xf, 0xc0,
    0x38, 0x7, 0xe0, 0x1c, 0x3, 0xf0, 0xe, 0x1,
    0xf8, 0x7, 0x0, 0xfc, 0x3, 0x80, 0x7e, 0x1,
    0xc0, 0x3f, 0x0, 0xe0, 0x1f, 0x80, 0x70, 0xf,
    0xc0, 0x38, 0x7, 0xe0, 0x1c, 0x3, 0xf0, 0xe,
    0x1, 0xf8, 0x7, 0x0, 0xfc, 0x3, 0x80, 0x7e,
    0x1, 0xc0, 0x3f, 0x0, 0xe0, 0x1f, 0x80, 0x70,
    0xf, 0xc0, 0x38, 0x7, 0xe0, 0x1c, 0x3, 0xf0,
    0xe, 0x1, 0xf8, 0x7, 0x0, 0xe0,

    /* U+006E "n" */
    0x0, 0x3f, 0x7, 0x7, 0xfc, 0x38, 0xff, 0xf1,
    0xcf, 0x7, 0xce, 0xf0, 0xf, 0x77, 0x0, 0x7b,
    0xf0, 0x1, 0xdf, 0x0, 0xe, 0xf0, 0x0, 0x3f,
    0x80, 0x1, 0xfc, 0x0, 0xf, 0xc0, 0x0, 0x7e,
    0x0, 0x3, 0xf0, 0x0, 0x1f, 0x80, 0x0, 0xfc,
    0x0, 0x7, 0xe0, 0x0, 0x3f, 0x0, 0x1, 0xf8,
    0x0, 0xf, 0xc0, 0x0, 0x7e, 0x0, 0x3, 0xf0,
    0x0, 0x1f, 0x80, 0x0, 0xfc, 0x0, 0x7, 0xe0,
    0x0, 0x3f, 0x0, 0x1, 0xf8, 0x0, 0xf, 0xc0,
    0x0, 0x7e, 0x0, 0x3, 0xf0, 0x0, 0x1f, 0x80,
    0x0, 0xfc, 0x0, 0x7, 0xe0, 0x0, 0x3f, 0x0,
    0x1, 0xf8, 0x0, 0xe,

    /* U+007A "z" */
    0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xf8, 0xff, 0xff,
    0xf0, 0x0, 0x1, 0xc0, 0x0, 0x7, 0x80, 0x0,
    0xe, 0x0, 0x0, 0x3c, 0x0, 0x0, 0xf0, 0x0,
    0x1, 0xc0, 0x0, 0x7, 0x80, 0x0, 0xe, 0x0,
    0x0, 0x3c, 0x0, 0x0, 0xf0, 0x0, 0x1, 0xc0,
    0x0, 0x7, 0x80, 0x0, 0x1e, 0x0, 0x0, 0x3c,
    0x0, 0x0, 0xf0, 0x0, 0x1, 0xc0, 0x0, 0x7,
    0x80, 0x0, 0x1e, 0x0, 0x0, 0x38, 0x0, 0x0,
    0xf0, 0x0, 0x3, 0xc0, 0x0, 0x7, 0x80, 0x0,
    0x1e, 0x0, 0x0, 0x38, 0x0, 0x0, 0xf0, 0x0,
    0x3, 0xc0, 0x0, 0x7, 0x80, 0x0, 0x1e, 0x0,
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfc,

    /* U+03A9 "Ω" */
    0x0, 0xf, 0xe0, 0x0, 0x0, 0x7f, 0xf8, 0x0,
    0x3, 0xff, 0xfc, 0x0, 0xf, 0xff, 0xfc, 0x0,
    0x3f, 0x81, 0xfc, 0x0, 0xfc, 0x0, 0xfc, 0x3,
    0xe0, 0x0, 0xfc, 0x7, 0x80, 0x0, 0xf8, 0x1e,
    0x0, 0x0, 0xf8, 0x3c, 0x0, 0x0, 0xf0, 0xf0,
    0x0, 0x0, 0xf1, 0xe0, 0x0, 0x1, 0xe7, 0x80,
    0x0, 0x3, 0xcf, 0x0, 0x0, 0x3, 0x9e, 0x0,
    0x0, 0x7, 0xbc, 0x0, 0x0, 0xf, 0x78, 0x0,
    0x0, 0x1e, 0xf0, 0x0, 0x0, 0x3d, 0xc0, 0x0,
    0x0, 0x7b, 0x80, 0x0, 0x0, 0xf7, 0x80, 0x0,
    0x1, 0xef, 0x0, 0x0, 0x3, 0xde, 0x0, 0x0,
    0x7, 0xbc, 0x0, 0x0, 0xf, 0x78, 0x0, 0x0,
    0x1e, 0x70, 0x0, 0x0, 0x7c, 0xf0, 0x0, 0x0,
    0xf1, 0xe0, 0x0, 0x1, 0xe3, 0xc0, 0x0, 0x3,
    0xc3, 0xc0, 0x0, 0xf, 0x87, 0x80, 0x0, 0x1e,
    0x7, 0x80, 0x0, 0x3c, 0xf, 0x0, 0x0, 0xf8,
    0x1e, 0x0, 0x1, 0xe0, 0x1e, 0x0, 0x7, 0xc0,
    0x3e, 0x0, 0xf, 0x0, 0x3c, 0x0, 0x3e, 0x0,
    0x3c, 0x0, 0x78, 0x0, 0x78, 0x1, 0xf0, 0x0,
    0x78, 0x7, 0xc0, 0x0, 0x78, 0xf, 0x0, 0x0,
    0x70, 0x3e, 0x1, 0xff, 0xf0, 0x7f, 0xf3, 0xff,
    0xe0, 0xff, 0xe7, 0xff, 0xc1, 0xff, 0xcf, 0xff,
    0x83, 0xff, 0x9f, 0xff, 0x7, 0xff, 0x0,

    /* U+03BC "μ" */
    0xf0, 0x0, 0x70, 0x1e, 0x0, 0xe, 0x3, 0xc0,
    0x1, 0xc0, 0x78, 0x0, 0x38, 0xf, 0x0, 0x7,
    0x1, 0xe0, 0x0, 0xe0, 0x3c, 0x0, 0x1c, 0x7,
    0x80, 0x3, 0x80, 0xf0, 0x0, 0x70, 0x1e, 0x0,
    0xe, 0x3, 0xc0, 0x1, 0xc0, 0x78, 0x0, 0x38,
    0xf, 0x0, 0x7, 0x1, 0xe0, 0x0, 0xe0, 0x3c,
    0x0, 0x1c, 0x7, 0x80, 0x3, 0x80, 0xf0, 0x0,
    0x70, 0x1e, 0x0, 0xe, 0x3, 0xc0, 0x1, 0xc0,
    0x78, 0x0, 0x38, 0xf, 0x0, 0x7, 0x1, 0xe0,
    0x0, 0xe0, 0x3c, 0x0, 0x1c, 0x7, 0x80, 0x3,
    0x80, 0xf0, 0x0, 0x70, 0x1f, 0x0, 0x1e, 0x3,
    0xe0, 0x3, 0xc0, 0x7c, 0x0, 0x78, 0xf, 0x80,
    0x1f, 0x1, 0xf8, 0x3, 0x60, 0x7f, 0x80, 0xee,
    0x1f, 0x78, 0x39, 0xe7, 0xe7, 0xff, 0x3f, 0xfc,
    0x7f, 0xc3, 0xfb, 0x87, 0xe0, 0x3e, 0x70, 0x0,
    0x0, 0xe, 0x0, 0x0, 0x1, 0xc0, 0x0, 0x0,
    0x38, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0xe0,
    0x0, 0x0, 0x1c, 0x0, 0x0, 0x3, 0x80, 0x0,
    0x0, 0x70, 0x0, 0x0, 0xe, 0x0, 0x0, 0x1,
    0xc0, 0x0, 0x0, 0x38, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 479, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 479, .box_w = 7, .box_h = 18, .ofs_x = 11, .ofs_y = -13},
    {.bitmap_index = 17, .adv_w = 479, .box_w = 16, .box_h = 3, .ofs_x = 7, .ofs_y = 22},
    {.bitmap_index = 23, .adv_w = 173, .box_w = 6, .box_h = 7, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 29, .adv_w = 479, .box_w = 23, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 167, .adv_w = 479, .box_w = 12, .box_h = 47, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 479, .box_w = 22, .box_h = 47, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 368, .adv_w = 479, .box_w = 21, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 494, .adv_w = 479, .box_w = 25, .box_h = 47, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 479, .box_w = 22, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 773, .adv_w = 479, .box_w = 22, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 905, .adv_w = 479, .box_w = 21, .box_h = 46, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 1026, .adv_w = 479, .box_w = 22, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 1158, .adv_w = 479, .box_w = 22, .box_h = 48, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 1290, .adv_w = 479, .box_w = 28, .box_h = 48, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1458, .adv_w = 479, .box_w = 22, .box_h = 47, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1588, .adv_w = 479, .box_w = 24, .box_h = 48, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1732, .adv_w = 479, .box_w = 24, .box_h = 47, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 1873, .adv_w = 479, .box_w = 24, .box_h = 47, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2014, .adv_w = 479, .box_w = 24, .box_h = 47, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2155, .adv_w = 479, .box_w = 26, .box_h = 48, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 2311, .adv_w = 479, .box_w = 23, .box_h = 47, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2447, .adv_w = 479, .box_w = 26, .box_h = 47, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2600, .adv_w = 32, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2601, .adv_w = 479, .box_w = 23, .box_h = 50, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 2745, .adv_w = 479, .box_w = 25, .box_h = 35, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 2855, .adv_w = 479, .box_w = 21, .box_h = 35, .ofs_x = 5, .ofs_y = 0},
    {.bitmap_index = 2947, .adv_w = 479, .box_w = 23, .box_h = 34, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3045, .adv_w = 491, .box_w = 31, .box_h = 47, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3228, .adv_w = 479, .box_w = 27, .box_h = 47, .ofs_x = 2, .ofs_y = -13}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xc, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x21, 0x25,
    0x27, 0x28, 0x2d, 0x2e, 0x2f, 0x32, 0x36, 0x3e,
    0x4b, 0x4d, 0x4e, 0x5a, 0x389, 0x39c
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 925, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 30, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .cmap_num = 1,
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
const lv_font_t insolata75 = {
#else
lv_font_t insolata75 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 63,          /*The maximum line height required by the font*/
    .base_line = 13,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -15,
    .underline_thickness = 4,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if INSOLATA75*/
