#include "common.h"

extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u16 D_00258FF0[];
extern s8 D_0025AD50[];
extern s8 D_0025AD60[];
extern s8 D_0025AD90[];
extern u16 D_0028E8E4;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00167430(void) {
    u16 temp_a0;
    reg_a0 = (s8 *)D_0025AD90;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = (s8 *)D_0025AD60;
    reg_d0.w = 0x10;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1D))) |= 0x40;
            (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = 0x280U;
        }
        reg_a2 = (u8 *)(D_00258FF0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        temp_a0 = (u32)reg_d0.h[0] + 0x440;
        reg_d0.h[0] = temp_a0;
        reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2E)));
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x28))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 3;
        if ((s32) D_0028E91C > 1) {
            reg_d1.b[0] = 3;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2B))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8E4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_a0 = (s8 *)D_0025AD50;
        reg_d0.h[0] = D_0028E918;
        reg_a0 = &reg_a0[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0;
        reg_a0 += 1;
        if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            (*(s16 *)((u8 *)(reg_a5) + (0x30))) = 1;
            reg_d0.w = 0;
            (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
            if ((*(u8 *)((u8 *)(reg_a5) + (0x32))) == 0) {
                reg_a0 = (s8 *)(reg_a6 + 0x16);
            } else {
                reg_a0 = (s8 *)(reg_a6 + 0x14);
            }
            *(u16 *)reg_a0 = 0xF800;
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
    }
}
