#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_00201200();
s32 func_00202140();
s32 func_00202500();
extern u16 D_0026E0C0[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B54B0(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) = 1U;
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
            func_00202140();
            if (D_0028E408 == 0) {
                if ((s8) reg_d1.b[0] > 0x27) {
                    reg_d1.w = 0x27;
                }
                if ((s8) reg_d1.b[0] < 0x19) {
                    reg_d1.w = 0x19;
                }
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) reg_d1.b[0];
            }
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (5)));
    if (temp_a0 == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
            reg_d0.h[0] += 0x20;
            func_00202500();
            reg_d0.h[0] = reg_d1.h[0];
            reg_d0.h[0] = (u16) reg_d0.b[0];
            reg_d0.h[0] -= 0x20;
            (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = (u16) reg_d0.h[0];
            if ((*(u8 *)((u8 *)(reg_a4) + (4))) == reg_d1.b[0]) {
                (*(u8 *)((u8 *)(reg_a4) + (5))) = 2U;
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(u8 *)((u8 *)(reg_a4) + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            reg_d0.h[0] += 0x14;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 7;
            func_00201200();
            reg_d5.b[0] -= 1;
            reg_d5.b[0] += (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_a0 = (u8 *)(D_0026E0C0);
            reg_d5.h[0] &= 0x3F;
            reg_d1.h[0] = reg_d5.h[0];
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
            reg_d2.h[0] += 7;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
            reg_tmp.h[1] = temp_a0_2;
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
            reg_d3.w = 0;
            reg_d4.w = 0;
            reg_d2.w += reg_tmp.w;
            func_00129280();
            (*(u16 *)((u8 *)(reg_a4) + (0xC))) += 2;
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) -= 1;
            if ((*(u16 *)((u8 *)(reg_a4) + (0xA))) == 0) {
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            }
        }
    }
}
