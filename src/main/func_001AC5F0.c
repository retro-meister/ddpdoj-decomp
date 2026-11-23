#include "common.h"

s32 func_0011C4A0();
s32 func_0011C7C0();
extern u16 D_0028DB00[];
extern s8 D_0028E634;
extern u8 D_0028E635;
extern u8 D_0028E854;
extern u16 D_0028E8C0;
extern u16 D_0028E934;
extern u8 *reg_a0;

void func_001AC5F0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xC0;
            reg_d1.h[0] = 0x1B00;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 1;
        reg_d3.h[0] = 0;
        reg_d7.w = 5;
        reg_d6.h[0] = D_0028E8C0;
        if (D_0028E8C0 != 0) {
            reg_d6.h[0] -= 1;
            reg_d7.h[0] -= 1;
            if ((s32) reg_d6.h[0] > 5) {
                reg_d6.w = 5;
            }
            reg_a0 = (u8 *)(D_0028DB00);
            reg_d7.h[0] -= reg_d6.h[0];
            reg_d4.h[0] = D_0028E934;
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.h[0] = reg_d1.h[0];
            do {
                func_0011C4A0();
                reg_d1.h[0] -= 0x100;
            } while ((s16)(--reg_d6.h[0]) >= 0);
            if ((s16) reg_d7.h[0] < 0) {
                goto block_end;
            }
        }
        do {
            func_0011C7C0();
            reg_d1.h[0] -= 0x100;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
block_end:
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
}
