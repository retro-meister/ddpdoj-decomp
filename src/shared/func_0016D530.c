#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_0016CDD0();
extern u16 D_0025B170[];
extern u16 D_0025B180[];
extern u16 D_0025B1A0[];
extern u16 D_0025B3C0[];
extern u16 D_0028E8C8;
extern u16 D_0028E8D8;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016D530(void) {
    reg_a0 = (u8 *)(D_0025B1A0);
    func_0014E370();
    reg_a0 = (u8 *)(D_0025B180);
    reg_d0.w = 0xF;
    func_0014E300();
    reg_d0.h[0] = D_0028E91C;
    reg_d0.h[0] >>= 1;
    reg_d0.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1C))) = (u8) reg_d0.b[0];
    reg_d0.h[0] = D_0028E8D8;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= reg_d0.b[0];
    reg_d0.h[0] = D_0028E8C8;
    reg_d0.h[0] >>= 4;
    (*(u8 *)((u8 *)(reg_a5) + (0x18))) -= reg_d0.b[0];
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if ((s32) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x7600) {
            (*(s8 *)((u8 *)(reg_a5) + (0x33))) = 1;
        }
        if (D_0028E91C == 2) {
            (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 2;
        }
        func_0016CDD0();
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B3C0);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B170);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x35))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x34))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
