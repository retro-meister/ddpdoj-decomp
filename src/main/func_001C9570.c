#include "common.h"

s32 func_00124B20();
s32 func_00124D80();
s32 func_001C9640();
extern u8 *reg_a1;
extern u8 *reg_a4;

void func_001C9570(void) {
    u16 temp_a0_2;
    u8 temp_a0;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if ((temp_a0 == 1) && (func_00124D80(temp_a0), (reg_d0.h[0] == 5))) {
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        reg_a1 = (u8 *)(reg_tmp.w);
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a4) + (6)));
        reg_a1 += temp_a0_2;
        if (*(s16 *)reg_a1 != -1) {
            func_001C9640();
            return;
        }
        reg_d0.w = 4;
        func_00124B20();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}
