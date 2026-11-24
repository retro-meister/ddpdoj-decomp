#include "common.h"

extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002021F0();
extern u16 D_00258FF0[];
extern u16 D_0025B690[];
extern u16 D_0025B6A0[];
extern u16 D_0025B6C0[];
extern u16 D_0025B740[];
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016EAA0(void) {
    reg_a0 = (u8 *)(D_0025B6C0);
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025B6A0);
    reg_d0.w = 0xE;
    func_0014E300();
    reg_d0.b[0] = 4;
    reg_d2.b[0] = 2;
    reg_d1.b[0] = 4;
    if ((s32) D_0028E91C > 1) {
        reg_d0.b[0] = 3;
        reg_d1.b[0] = 6;
        reg_d2.b[0] = 1;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x2A))) = (u8) reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x31))) = (u8) reg_d2.b[0];
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0 = (u8 *)(D_00258FF0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0xB00;
        func_002021F0();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x28))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
        reg_a0 = (u8 *)(D_0025B740);
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B690);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
