#include "common.h"

extern s8 D_0028E408;

s32 func_0013A780();
s32 func_0014E290();
s32 func_0019BFC0();
s32 func_00201C60();
s32 func_00203060();
extern u8 D_0028DB10[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C4C90(void) {
    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x28)));
        reg_d0.h[0] = 6;
        func_0013A780();
        (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2E)));
        reg_d0.w = 0xFFFA0007;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.w = 1;
        reg_d3.w = 0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.b[0] += 0x10;
        reg_d1.b[0] &= 0x3F;
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
        reg_a0 = D_0028DB10;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x20)));
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) += 4;
        (*(u16 *)((u8 *)(reg_a5) + (0x20))) &= 7;
    }
    func_0019BFC0();
}
