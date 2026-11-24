#include "common.h"

s32 func_001BF210();
s32 func_001C0A40();
s32 func_00202500();
extern u16 D_0026C1C0[];
extern Reg32 D_0028E474;
extern u16 D_0028E89C;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C1030(void) {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        func_00202500();
        *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        func_00202500();
        *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
        if (*(u8 *)(reg_a4 + 9) == reg_d1.b[0]) {
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
            if (*(u8 *)(reg_a4 + 8) == reg_d1.b[0]) {
                *(u8 *)(reg_a4 + 3) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            if (D_0028E89C == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            if (D_0028E89C == 0) {
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a6 + 0x9A) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0x9A) &= 0x3F;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                *(u8 *)(reg_a6 + 0xBA) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0xBA) &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    D_0028E474.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    D_0028E474.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = D_0028E474.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                    func_001C0A40();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    D_0028E474.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    D_0028E474.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = D_0028E474.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                    func_001C0A40();
                }
                *(u16 *)(reg_a4 + 4) -= 1;
                if (*(u16 *)(reg_a4 + 4) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}
