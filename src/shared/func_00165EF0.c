#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202180();
extern u16 D_00259270[];
extern u16 D_0025AC80[];
extern u16 D_0025AC90[];
extern u16 D_0025ACA0[];
extern u16 D_0028E8D4;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00165EF0(void) {
    reg_a0 = (u8 *)(D_0025ACA0);
    func_0014E370();
    reg_a0 = (u8 *)(D_0025AC90);
    reg_d0.w = 5;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        func_00202180();
        reg_a0 = (u8 *)(D_00259270);
        (*(u8 *)((u8 *)(reg_a5) + (0x20))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.b[0] = 4;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8D4;
        reg_d0.h[0] -= 4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AC80);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x19))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
