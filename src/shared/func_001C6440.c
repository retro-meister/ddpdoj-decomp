#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u16 D_00262D30[];
extern u16 D_00262D40[];
extern u16 D_00262D60[];
extern u16 D_00262D80[];
extern u16 D_0028E8DC;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C6440(void) {
    reg_a0 = (u8 *)(D_00262D60);
    func_0014E370();
    reg_a0 = (u8 *)(D_00262D40);
    reg_d0.w = 9;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 2;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8DC;
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= reg_d0.b[0];
        if ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
            (*(u8 *)((u8 *)(reg_a6) + (0x1D))) |= 0x40;
            reg_tmp.w = 0x14;
            (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) reg_tmp.h[0];
            (*(s16 *)((u8 *)(reg_a5) + (0x28))) = 0;
        }
        reg_d0.w = (u32) reg_a6;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_tmp.w += reg_d0.w;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) reg_tmp.h[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        reg_a0 = (u8 *)(D_00262D80);
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_a1 = (u8 *)(reg_tmp.w);
        *(u16 *)reg_a1 = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00262D30);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
