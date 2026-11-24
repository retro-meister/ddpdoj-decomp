#include "common.h"

s32 func_0019C730();
s32 func_0019C9C0();
extern u8 D_0025BF10[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_00199A50(void) {
    u32 temp_a1;

    reg_d1.h[0] = 0x4840;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x380;
    reg_d1.h[1] = reg_tmp.h[0];
    if ((*(u16 *)((u8 *)(reg_a4) + (0x2C))) != 0) {
        reg_d1.h[0] = 0x2240;
    }
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 4;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x30)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x32)));
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
    if (reg_d7.h[0] != 0) {
        reg_d7.h[0] -= 1;
        do {
            temp_a1 = *(u32 *)reg_a0;
            reg_d0.w = temp_a1;
            reg_a0 += 4;
            reg_a1 = (u8 *)D_0025BF10;
            reg_a1 += reg_d0.h[0];
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d6.w = 0x40004000;
            func_0019C9C0();
            reg_d1.h[0] += 0x600;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if ((*(u16 *)((u8 *)(reg_a4) + (0x16))) != 3) {
        reg_a1 = (u8 *)D_0025BF10;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        func_0019C730();
        if ((s32) (*(u16 *)((u8 *)(reg_a4) + (0x16))) < 2) {
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x3E)));
            (*(u16 *)((u8 *)(reg_a4) + (0x3E))) += 4;
            if (reg_d0.h[0] == 0x68) {
                (*(u16 *)((u8 *)(reg_a4) + (0x3E))) = 0U;
            }
            reg_a1 = (u8 *)D_0025BF10;
            reg_d7.h[0] = 1;
            reg_d7.h[0] -= (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            do {
                reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
                reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d1.h[0] += 0x600;
                reg_d6.w = 0x40004000;
                func_0019C9C0();
                reg_d0.h[0] += 0x34;
                if ((s32) reg_d0.h[0] >= 0x6C) {
                    reg_d0.h[0] -= 0x6C;
                }
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
}
