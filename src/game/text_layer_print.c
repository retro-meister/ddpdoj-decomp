#include "common.h"

/* Printing strings on the text plane; reg_a0 has the string, reg_d0 and reg_d1 the position. */

s32 deferred_text_put_sheet();
extern u16 g_wide_font_codes[];

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
