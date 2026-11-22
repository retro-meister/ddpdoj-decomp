#include "common.h"


extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u16 D_00259170[];
extern u8 D_0025A490[];
extern u8 D_0025A4B0[];
extern u16 D_0028E8D4;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00161CC0(void) {
    reg_a0 = D_0025A4B0;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_0025A490;
    reg_d0.w = 0xA;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_00259170);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x7FFF + 0x7901;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x28))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = D_0028E8D4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
    }
}
