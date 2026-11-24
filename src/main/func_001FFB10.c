#include "common.h"

extern s8 D_0028E408;

s32 func_0014D220();
s32 func_0014E290();
s32 func_0019C7F0();
s32 func_0019D710();
s32 func_00201D10();
s32 func_00203060();
extern u8 D_00266400[];
extern u8 D_0028E2E4;
extern u16 D_0028E3E4;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FFB10(void) {
    u8 *t1;
    u16 t2;
    u8 t3;
    u8 t4;
    u8 t5;

    if (D_0028E2E4 != 0) goto block_end1;
    {
        func_00203060();
        if (D_0028E408 != 0) {
            if (*(u8 *)(reg_a5 + 0x17) == 0) goto next_1;
block_end1:
            func_0014E290();
            return;
        }
        *(u8 *)(reg_a5 + 0x17) = 1U;
next_1:
        reg_d1.w = 0;
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1B);
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
        func_00201D10();
        *(u16 *)(reg_a6 + 2) += reg_d2.h[0];
        t1 = (u8 *)(reg_a6);
        (*(u16 *)((u8 *)(t1) + (4))) += reg_d3.h[0];
        if (*(u8 *)(reg_a5 + 0x16) == 0) {
            *(u8 *)(reg_a6 + 0x1B) -= 1;
            if (*(u8 *)(reg_a6 + 0x1B) == 0) {
                t1 = (u8 *)0x20;
                *(u8 *)(reg_a5 + 0x16) = 1U;
                *(u8 *)(reg_a6 + 0x1A) = 0x20U;
                *(u16 *)reg_a6 = 0x8001;
            }
        } else if (D_0028E910 == 0) {
            t1 = (u8 *)(reg_a6 + 0x1B);
            t5 = *(u8 *)(reg_a6 + 0x1B);
            if (t5 != 0x1C) {
                *(u8 *)(reg_a6 + 0x1B) = (u8) (t5 + 1);
            }
        } else {
            t4 = *(u8 *)(reg_a6 + 0x1B);
            if ((s32) t4 < 0x3C) {
                *(u8 *)(reg_a6 + 0x1B) = (u8) (t4 + 4);
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1B);
        *(u8 *)(reg_a5 + 0x1B) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a5 + 0x1B) = (u8) *(u8 *)(reg_a5 + 0x1A);
            *(u16 *)(reg_a5 + 0x18) += 4;
            if ((s32) *(u16 *)(reg_a5 + 0x18) >= 0x38) {
                *(u16 *)(reg_a5 + 0x18) = 0x28U;
            }
        }
        reg_a0 = reg_a6;
        func_0014D220();
        reg_a0 = (u8 *)D_00266400;
        reg_a0 += *(u16 *)(reg_a5 + 0x18);
        reg_d2.h[1] = *(u16 *)reg_a0;
        reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
        reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
        t2 = *(u16 *)(reg_a6 + 4);
        reg_d1.h[0] = t2;
        reg_d1.w += 0xF600FA00;
        reg_d3.h[0] = 0xA30;
        reg_d4.w = 0;
        t3 = *(u8 *)(reg_a6 + 0x1C);
        reg_d4.b[0] = t3;
        reg_d6.w = 0xF800F800;
        if (D_0028E3E4 != 0) {
            func_0019D710();
        } else {
            func_0019C7F0();
        }
    }
}
