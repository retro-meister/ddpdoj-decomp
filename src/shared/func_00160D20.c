#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u16 D_0025A380[];
extern u16 D_0025A390[];
extern u16 D_0025A3B0[];
extern u16 D_0025A430[];
extern u16 D_0028E8E4;
extern u16 D_0028E8F0;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00160D20(void) {
    reg_a0 = (u8 *)(D_0025A3B0);
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A390);
    reg_d0.w = 0xD;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        reg_d1.b[0] = 5;
        if ((s32) D_0028E91C > 1) {
            reg_d1.b[0] = 5;
            reg_d0.b[0] = 2;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x2A))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
        reg_a0 = (u8 *)(D_0025A430);
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = D_0028E8F0;
        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8E4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A380);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            (*(s16 *)((u8 *)(reg_a6) + (0x30))) = 1;
            reg_d0.w = 0;
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
            reg_d0.b[0] -= 1;
            (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d0.h[0];
            if (reg_d0.h[0] == 0) {
                reg_a0 = (u8 *)reg_a6 + 0x12;
            } else {
                reg_a0 = (u8 *)reg_a6 + 0x10;
            }
            *(u16 *)reg_a0 = 0xF000;
            (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
        }
        if (D_0028E91C == 4) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x1400;
        }
    }
}
