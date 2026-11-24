#include "common.h"

extern s8 D_0028E408;

s32 func_00129410();
s32 func_001D5670();
s32 func_001D6690();
s32 func_00202730();
extern u16 D_00259970[];
extern u16 D_0028E8C8;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6410(void) {
    u8 t1;

    if (*(u8 *)(reg_a5 + 0x1B) == 0) {
        *(u8 *)(reg_a5 + 0x1B) = 1U;
        *(s16 *)(reg_a6 + 0xCE) = 0x810;
        *(s16 *)(reg_a6 + 0xD0) = 0x20;
        *(u8 *)(reg_a6 + 0xD7) = 1U;
        *(u8 *)(reg_a6 + 0xD9) = 0U;
        *(s8 *)(reg_a6 + 0xD5) = 0;
        *(s16 *)(reg_a6 + 0xC) = 0x3001;
        func_001D6690();
    }
    func_001D5670();
    if (*(u8 *)(reg_a5 + 0x25) == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0xCF);
        *(u8 *)(reg_a6 + 0xCF) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            reg_d0.h[0] = 0x10;
            reg_d1.h[0] = D_0028E8C8;
            reg_d1.h[0] >>= 2;
            reg_d0.b[0] -= reg_d1.b[0];
            *(u8 *)(reg_a6 + 0xCF) = (u8) reg_d0.b[0];
            func_00202730();
            if (D_0028E408 == 0) {
                reg_d0.w = 0x70004;
                t1 = 0xF6000000;
                reg_d1.h[0] -= 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d5.w = 0xF6000000;
                reg_d7.w = 8;
                reg_a0 = (u8 *)(D_00259970);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w += reg_d5.w;
                    func_00129410();
                    reg_d1.b[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                reg_d0.b[0] = *(u8 *)(reg_a6 + 0xD7);
                *(u8 *)(reg_a6 + 0xD9) += reg_d0.b[0];
                if ((s8) reg_d0.b[0] < 0) {
                    if (*(s8 *)(reg_a6 + 0xD9) < -4) {
                        *(u8 *)(reg_a6 + 0xD7) *= -1;
                    }
                } else if (*(s8 *)(reg_a6 + 0xD9) > 4) {
                    *(u8 *)(reg_a6 + 0xD7) *= -1;
                }
            }
        }
    }
}
