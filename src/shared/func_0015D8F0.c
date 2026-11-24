#include "common.h"

extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u16 D_00259170[];
extern s8 D_0025A128[];
extern s8 D_0025A140[];
extern s8 D_0025A160[];
extern u16 D_0028E8E0;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015D8F0(void) {
    reg_a0_as_s8_p = D_0025A160;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A140;
    reg_d0.w = 0xA;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_00259170);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0xA40;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x2A))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x26))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x5C0;
        reg_d1.h[0] += 0x7FFF + 0x7601;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a6) + (0x30))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a6) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 8;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 8;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x28))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8E0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_0025A128;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        reg_a0_as_s8_p += 1;
    }
}
