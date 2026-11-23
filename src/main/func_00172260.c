#include "common.h"

s32 func_00172090();
s32 func_0019C470();
s32 func_0019D710();
extern u8 D_0026B250[];
extern u8 D_0026B280[];
extern s16 D_0028E784;
extern u16 D_0028E78C;

void func_00172260(void) {
    u32 temp_a3;

    if (D_0028E784 != -1) {
        func_00172090();
        reg_d0.h[0] *= 2;
        temp_a3 = *(u32 *)(D_0026B250 + (reg_d0.h[0] * 4));
        reg_d1.w = 0x38001C00;
        reg_d1.w += 0xC800E400;
        reg_d2.w = temp_a3;
        reg_d3.h[0] = 0x38E0;
        reg_d4.h[0] = 0x17;
        if ((u16) D_0028E784 == 0) {
            reg_d6.w = *(u32 *)(D_0026B280 + (D_0028E78C * 4));
            func_0019D710();
            return;
        }
        func_0019C470();
    }
}
