#include "common.h"

/* Printing strings on the text plane; reg_a0 has the string, reg_d0 and reg_d1 the position. */

s32 deferred_text_put_sheet();

/* The cell of each character from 0x20 up in the large font. */
u16 g_wide_font_codes[96] = {
    0x0080, 0x0081, 0x0082, 0x0083, 0x0084, 0x0085, 0x0086, 0x0087,
    0x0088, 0x0089, 0x008A, 0x008B, 0x008C, 0x008D, 0x008E, 0x008F,
    0x00A0, 0x00A1, 0x00A2, 0x00A3, 0x00A4, 0x00A5, 0x00A6, 0x00A7,
    0x00A8, 0x00A9, 0x00AA, 0x00AB, 0x00AC, 0x00AD, 0x00AE, 0x00AF,
    0x00C0, 0x00C1, 0x00C2, 0x00C3, 0x00C4, 0x00C5, 0x00C6, 0x00C7,
    0x00C8, 0x00C9, 0x00CA, 0x00CB, 0x00CC, 0x00CD, 0x00CE, 0x00CF,
    0x00E0, 0x00E1, 0x00E2, 0x00E3, 0x00E4, 0x00E5, 0x00E6, 0x00E7,
    0x00E8, 0x00E9, 0x00EA, 0x00EB, 0x00EC, 0x00ED, 0x00EE, 0x00EF,
    0x0100, 0x0101, 0x0102, 0x0103, 0x0104, 0x0105, 0x0106, 0x0107,
    0x0108, 0x0109, 0x010A, 0x010B, 0x010C, 0x010D, 0x010E, 0x010F,
    0x0120, 0x0121, 0x0122, 0x0123, 0x0124, 0x0125, 0x0126, 0x0127,
    0x0128, 0x0129, 0x012A, 0x012B, 0x012C, 0x012D, 0x012E, 0x012F,
};

/* Prints with the large font, through the queue of deferred writes. */

void text_layer_print_wide(void) {
    u32 sv_d0;
    u32 sv_d1;
    u32 sv_d2;
    u32 sv_d3;
    u32 sv_d4;
    u32 sv_d5;
    u32 sv_d6;
    u32 sv_d7;
    s8 *sv_a0;
    u8 *sv_a1;
    u8 *sv_a2;
    u8 *sv_a3;
    u8 *sv_a4;
    u8 *sv_a5;
    u8 *sv_a6;
    sv_d0 = reg_d0.w;
    sv_d5 = reg_d5.w;
    sv_d7 = reg_d7.w;
    sv_a0 = (s8 *)reg_a0;
    sv_a1 = reg_a1;
    sv_a2 = reg_a2;
    sv_d1 = reg_d1.w;
    sv_a3 = reg_a3;
    sv_a4 = reg_a4;
    sv_a5 = reg_a5;
    sv_a6 = reg_a6;
    sv_d2 = reg_d2.w;
    reg_d2.h[0] = 0;
    sv_d3 = reg_d3.w;
    reg_d3.w = 0;
    sv_d4 = reg_d4.w;
    sv_d6 = reg_d6.w;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 1;
next_character:
    reg_d4.w = 0;
    reg_d4.b[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] == 0) goto end_of_string;
    reg_a1 = (u8 *) g_wide_font_codes;
    reg_d4.h[0] &= 0xFF;
    reg_d4.h[0] -= 0x20;
    reg_d4.h[0] += reg_d4.h[0];
    reg_a1 += reg_d4.h[0];
    reg_d4.h[1] = *(u16 *) reg_a1;
    reg_d4.h[0] = reg_d5.h[0];
    sv_d5 = reg_d5.w;
    reg_d5.h[0] = 0x10;
    deferred_text_put_sheet();
    reg_d5.w = sv_d5;
    reg_d1.h[0] += 0x100;
    goto next_character;
end_of_string:
    reg_d5.w = sv_d5;
    reg_d7.w = sv_d7;
    reg_a0 = (u8 *)sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_d0.w = sv_d0;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d6.w = sv_d6;
}

s32 text_layer_put();

void text_layer_print(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s8 *temp_s5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    temp_s5 = (s8 *)((s8 *)reg_a0);
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
next_character:
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] != 0) {
        reg_d4.h[0] = reg_d4.w & 0xFF;
        reg_tmp4.w = reg_d4.w;
        reg_d4.h[1] = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        text_layer_put();
        reg_d0.h[0] += 1;
        goto next_character;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_a0 = (u8 *)temp_s5;
}

/* The number printers of the debug display are empty in this build (row, column, palette and value come in
   reg_d0 to reg_d3). */
void debug_print_hex8_stub(void) {
}

void debug_print_hex_short_stub(void) {
}

void debug_print_hex4_stub(void) {
}
