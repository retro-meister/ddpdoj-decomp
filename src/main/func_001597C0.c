#include "common.h"

s32 func_00129370();
s32 func_00159740();
extern u16 D_002586C0[];
extern s8 D_0028C9C0;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001597C0(void) {
    u32 temp_a1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x47))) == 0) {
        func_00159740();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x49)));
    (*(u8 *)((u8 *)(reg_a6) + (0x49))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x49))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x48)));
        reg_a4 = reg_a6 + 0x66;
        reg_a4 += (*(u16 *)((u8 *)(reg_a6) + (0x4A)));
        (*(u8 *)((u8 *)(reg_a4) + (1))) = 4U;
        (*(s16 *)((u8 *)(reg_a4) + (2))) = 4;
        (*(u16 *)((u8 *)(reg_a6) + (0x4A))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x4A))) >= 0x18) {
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = 0U;
        }
    }
    reg_a4 = reg_a6 + 0x66;
    reg_d7.w = 5;
    do {
        if ((*(u8 *)((u8 *)(reg_a4) + (1))) != 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (*(u8 *)((u8 *)(reg_a4) + (2)));
                reg_d6.h[0] = reg_d7.h[0];
                temp_a1 = reg_d6.h[0];
                reg_d1.b[0] = *(&D_0028C9C0 + temp_a1);
                reg_a0 = (u8 *)(D_002586C0);
                reg_d6.h[0] = temp_a1 * 4;
                reg_d3.h[1] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = (((reg_d6.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d6.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d4.w = 0;
                reg_d0.w = 5;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                func_00129370();
                (*(u8 *)((u8 *)(reg_a4) + (1))) -= 1;
            }
        }
        reg_a4 += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
