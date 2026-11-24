#include "common.h"

typedef void (*Fn)();

s32 func_0014E260();
extern u8 D_0026A350[];
extern u16 D_0028E8A4;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014E7E0(void) {
    s8 t;

    enemy_move_end_requested = 0;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x14);
    if (reg_d0.w == 0) {
        func_0014E260();
        return;
    }
    reg_a0 = (u8 *)(reg_d0.w);
    if (*(u8 *)(reg_a5 + 3) & 0x40) {
        *(u16 *)(reg_a6 + 2) = *(u16 *)(reg_a5 + 0x48);
        *(u16 *)(reg_a6 + 4) = *(u16 *)(reg_a5 + 0x4A);
        reg_d0.h[0] = D_0029C068[0];
        *(u16 *)(reg_a6 + 4) += reg_d0.sh[0];
    } else {
        reg_d0.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_d0.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(u16 *)(reg_a6 + 2) = reg_d0.h[0];
        reg_tmp.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];
    }
    if ((s32) *(u8 *)(reg_a6 + 5) >= 0x80) {
        *(u8 *)(reg_a6 + 5) |= 0x80;
    }
loop_1:
    t = *(s8 *)reg_a0;
    reg_d1.b[0] = t;
    if (t >= 0) goto next_1;
    reg_a0 += 1;
    if ((s32) reg_d1.b[0] >= 0xC0) {
        *(s8 *)(reg_a6 + 0x1B) = *(s8 *)reg_a0;
        reg_a0 += 1;
        goto loop_1;
    }
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
    ((Fn)*(u32 *)((u8 *)D_0026A350 + (reg_d1.h[0] * 4)))();
    if (enemy_move_end_requested == 0) goto loop_1;
    return;
next_1:
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = (u16) reg_tmp.h[0];
    *(u8 *)(reg_a6 + 0x1A) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d0.h[0] -= D_0028E8A4;
    reg_d0.h[0] &= 0x7F;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] >>= 7;
    reg_d0.h[0] |= ((s16) reg_tmp.h[0] << 9) & 0xFFFF;
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) -= 0x800;
    reg_d1.w = 0;
    *(u16 *)(reg_a5 + 0x10) = (u16) reg_d1.h[0];
    *(u8 *)(reg_a5 + 3) |= 0x20;
}
