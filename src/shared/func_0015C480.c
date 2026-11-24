#include "common.h"

extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u16 D_002592F0[];
extern s8 D_0025A070[];
extern s8 D_0025A080[];
extern s8 D_0025A0B0[];
extern u16 D_0028E8CC;
extern u16 D_0028E910;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015C480(void) {
    reg_a0_as_s8_p = D_0025A0B0;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A080;
    reg_d0.w = 0x10;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if (D_0028E910 != 0) {
            reg_d0.h[0] = 0x1200;
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
        }
        reg_a2 = (u8 *)(D_002592F0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x500;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2C))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x680;
        reg_d1.h[0] += 0x7FFF + 0x7B01;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 4;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x35))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x34))) = (u8) reg_d1.b[0];
        if (D_0028E91C == 4) {
            reg_d0.h[0] = 5;
            (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) = (u8) reg_d0.b[0];
            reg_d0.h[0] = 8;
            (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a5) + (0x24))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a5) + (0x35))) = 0xCU;
            reg_d0.h[0] = 0x7FFF;
            (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
            (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
            (*(s16 *)((u8 *)(reg_a5) + (0x36))) = 0x30;
        }
        reg_d0.h[0] = D_0028E8CC;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8CC;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A070;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}
