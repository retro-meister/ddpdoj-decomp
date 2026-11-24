#include "common.h"

s32 func_0014E290();
s32 func_0019C150();
s32 func_00201D10();
extern u8 D_00258450[];
extern Reg32 D_0028E484;
extern u16 D_0028E85C;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00157F10(void) {
    u16 t1;

    if (D_0028E8A8 == 0x118) {
        func_0014E290();
        return;
    }
    if (D_0028E8A0 == 0) {
        if (*(s16 *)(reg_a5 + 0x1E) < 2) {
            reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x21);
            *(u8 *)(reg_a5 + 0x21) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a5 + 0x21) = (u8) *(u8 *)(reg_a5 + 0x20);
            }
        }
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
        func_00201D10();
        *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) += reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x24) = (u16) *(u16 *)(reg_a6 + 4);
        *(u16 *)(reg_a5 + 0x18) += reg_d2.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
        reg_d0.h[0] *= -1;
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7000;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] -= 0x7000;
        reg_tmp.w -= D_0028E484.sw;
        if (reg_tmp.h[1] == 0) {
            reg_d0.h[0] *= -1;
            *(u16 *)(reg_a5 + 0x18) = (u16) reg_d0.h[0];
            reg_a0 = reg_a6;
            reg_a0 += *(u16 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x1A) += 0x20;
            *(u16 *)(reg_a5 + 0x1A) &= 0x3F;
            *(s8 *)(reg_a0 + 0x1E) = 1;
            reg_d1.h[0] = 0x7000;
            reg_d1.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a0 + 2) = (u16) reg_d1.h[0];
            reg_a1 = (u8 *)D_00258450;
            reg_a1 += *(u16 *)(reg_a5 + 0x1C);
            *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)reg_a1;
            *(u16 *)(reg_a0 + 0xC) = (u16) *(u16 *)(reg_a1 + 2);
            if ((*(u16 *)(reg_a5 + 0x1C) == 0) && (D_0028E85C == 0)) {
                t1 = *(u16 *)(reg_a5 + 0x1E);
                if (t1 != 0) {
                    *(s16 *)(reg_a5 + 0x1E) = (s16) (t1 - 1);
                    if (*(u16 *)(reg_a5 + 0x1E) == 0) {
                        *(u16 *)(reg_a5 + 0x22) = 1U;
                    }
                }
            }
            *(u16 *)(reg_a5 + 0x1C) += 4;
            *(u16 *)(reg_a5 + 0x1C) &= 0xF;
            if (*(u16 *)(reg_a5 + 0x22) != 0) {
                *(s8 *)(reg_a0 + 0x1E) = 0;
            }
        }
    }
    reg_d7.w = 1;
    do {
        if (*(u8 *)(reg_a6 + 0x1E) != 0) {
            func_0019C150();
        }
        reg_a6 += 0x20;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
