#include "common.h"

extern s8 D_0028E408;

s32 func_0013B2E0();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_0018DAD0();
s32 func_002026F0();
extern u16 D_002590F0[];
extern u8 D_00263000[];
extern u8 D_00263030[];
extern u8 D_002630D0[];
extern s16 D_0028E894_as_s16;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CBD60(void) {
    reg_a0 = D_00263030;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263000;
    reg_d0.w = 0x14;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0)));
        reg_d0.h[0] &= 0xE7FF;
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x20)));
        reg_d2.h[0] &= 0xDFFE;
        reg_d0.h[0] |= reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d0.h[0];
        reg_a3 = (u8 *)(D_002590F0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x780;
        func_002026F0();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2C))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        (*(u16 *)((u8 *)(reg_a5) + (0x28))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0xAC0;
        reg_d1.h[0] += 0x7FFF + 0x7881;
        func_002026F0();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d1.b[0] *= 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0xF8;
        reg_d1.h[0] >>= 1;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d0.b[0] = 0x10;
        reg_d1.b[0] = 2;
        reg_d2.b[0] = 0x18;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 2;
            reg_d2.b[0] = 0x18;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x35))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x34))) = (u8) reg_d1.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x3D))) = (u8) reg_d2.b[0];
        reg_a0 = D_002630D0;
        func_0013B2E0();
        D_0028E894_as_s16 = 1;
        func_0018DAD0();
        D_00299768[0] = 1;
        if (D_0028E910 != 0) {
            D_0029976A[0] = 1;
        }
    }
}
