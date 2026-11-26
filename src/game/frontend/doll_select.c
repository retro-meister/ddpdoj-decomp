#include "common.h"
#include "entity.h"
#include "doll_select.h"

extern u16 g_loop;
void doll_select_first_free(void)
{
    reg_a0 = (u8 *)doll_select_order_p1;
    if (reg_d7.h[0] == 0) {
        reg_a0 = (u8 *)doll_select_order_p2;
    }

    reg_d1.w = 2;
    do {
        if (*(u16 *)reg_a0 != reg_d0.h[0]) {
            break;
        }
        reg_a0 += 2;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    reg_d0.h[0] = *(u16 *)reg_a0;
}


void doll_select_start(void) {
    if (reg_d7.h[0] == 0) {
        goto next_3;
    }
    reg_d0.w = 0;
    reg_a4 = (u8 *)&doll_select_p1;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 6);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 0;
        *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    doll_select_first_free();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
    goto next_5;
next_3:
    reg_d0.w = 0;
    reg_a4 = (u8 *)&doll_select_p2;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 7);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 2;
        *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    doll_select_first_free();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
next_5:
    *(s16 *) (reg_a6 + 0x16) = 0x60;
    *(s16 *) (reg_a6 + 0x18) = 0xC00;
    *(s16 *) (reg_a6 + 0x1C) = 0x60;
    *(s16 *) (reg_a6 + 0x1E) = 0xC00;
    *(s16 *) (reg_a6 + 0x22) = 0x60;
    *(s16 *) (reg_a6 + 0x24) = 0xC00;
    *(s16 *) (reg_a6 + 0x2A) = 0xB4;
    *(s16 *) (reg_a6 + 0x2E) = 0x599;
    *(s8 *) (reg_a6 + 0x30) = 2;
    *(s8 *) (reg_a6 + 0x31) = 0;
    *(s8 *) reg_a6 = 4;
}

s32 text_layer_print();

void doll_select_confirm(void) {
    u16 temp_a0;
    if (g_loop == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 4);
        reg_a0 = (u8 *)doll_select_values;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        if (reg_d7.h[0] != 0) {
            *(u8 *)(reg_a5 + 5) = (u8) reg_d0.b[0];
        } else {
            *(u8 *)(reg_a5 + 4) = (u8) reg_d0.b[0];
        }
    }
    temp_a0 = *(u16 *)(reg_a4 + 0xA);
    reg_d1.h[0] = temp_a0;
    reg_d0.h[0] = 8;
    reg_a0 = (u8 *)doll_select_blank;
    reg_d2.h[0] = 0;
    reg_d1.h[0] >>= 6;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] += 8;
    text_layer_print();
    *(s8 *)reg_a6 = 6;
}

typedef void (*Fn)();

s32 sfx_confirm();
s32 sfx_cursor_move();
s32 select_panel_piece_0_draw();
s32 select_panel_piece_1_draw();
s32 select_panel_piece_4_draw();
s32 select_panel_piece_5_draw();
s32 select_panel_piece_6_draw();
s32 select_other_side_piece_draw();
s32 select_panel_piece_9_draw();
extern u8 *reg_call_target_as_u8_p;

void doll_select_input(void) {
    u8 *temp_s0;
    s8 var_s0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (reg_d7.h[0] != 0) {
        reg_a4 = (u8 *)&doll_select_p1;
        reg_a3 = reg_a5 + 7;
        var_s0 = *(s8 *)(reg_a5 + 6);
    } else {
        reg_a4 = (u8 *)&doll_select_p2;
        reg_a3 = reg_a5 + 6;
        var_s0 = *(s8 *)(reg_a5 + 7);
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (reg_d0.w & 4) {
        sfx_cursor_move();
        *(s16 *)(reg_a6 + 0x28) = 1;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        do {
            reg_d1.h[0] -= 1;
            if (0 > (s16) reg_d1.h[0]) {
                reg_d1.h[0] = 2;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 4) = (u16) reg_d1.h[0];
    }
    if (reg_d0.w & 8) {
        sfx_cursor_move();
        *(s16 *)(reg_a6 + 0x28) = 1;
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        do {
            reg_d1.h[0] += 1;
            if ((s16) reg_d1.h[0] > 2) {
                reg_d1.w = 0;
            }
        } while ((s8)(var_s0) == reg_d1.b[0]);
        *(u16 *)(reg_a6 + 4) = (u16) reg_d1.h[0];
    }
    if (reg_d7.h[0] != 0) {
        *(s8 *)(reg_a5 + 7) = (s8) *(u8 *)(reg_a6 + 4);
    } else {
        *(s8 *)(reg_a5 + 6) = (s8) *(u8 *)(reg_a6 + 4);
    }
    if ((*(u8 *)(reg_a6 + 0x31) != 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        *(s8 *)reg_a6 = 5;
        *(s16 *)(reg_a6 + 0x2E) = 0;
    }
    temp_v1 = *(u8 *)(reg_a5 + 2);
    temp_s0 = (u8 *)(reg_a4);
    if (temp_v1 & 1) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1 | 1);
        select_panel_piece_0_draw();
        select_panel_piece_1_draw();
    }
    temp_v1_2 = *(u8 *)(reg_a5 + 2);
    if (temp_v1_2 & 2) {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
    } else {
        *(u8 *)(reg_a5 + 2) = (u8) (temp_v1_2 | 2);
        select_panel_piece_4_draw();
    }
    select_panel_piece_5_draw();
    select_panel_piece_6_draw();
    select_other_side_piece_draw();
    select_panel_piece_9_draw();
    reg_a4 = temp_s0;
}
