#include "common.h"

s32 func_00129280();
s32 func_00129370();
extern u8 D_00258740[];
extern s8 D_0028C9C8;
extern u8 D_0028C9D0;
extern u16 D_0028E91C;
extern u8 *reg_a2;
extern s8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_0015A390(void) {
    u16 temp_a0;
    reg_a4 = D_00258740;
    reg_a3 = &D_0028C9C8;
    reg_a2 = &D_0028C9D0;
    reg_d7.w = 5;
    do {
        reg_d1.w = 0;
        reg_d1.b[0] = (u8) *reg_a3;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d4.w = (u32) reg_a6;
        reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
        reg_d3.h[0] = temp_a0;
        if (D_0028E91C != 4) {
            reg_d0.h[0] = 6;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            func_00129370();
        } else {
            reg_d0.h[0] = 0xFFFC;
            reg_tmp.h[0] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d0.h[1] = reg_tmp.h[0];
            func_00129280();
            reg_d0.w += 0x40000;
            func_00129370();
            reg_d0.w += 0x40000;
            func_00129280();
            reg_d0.w += 0x40000;
            func_00129370();
            reg_d0.w += 0x40000;
            func_00129280();
        }
        reg_a4 += 4;
        reg_a3 += 1;
        reg_a2 += 1;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
