#include "common.h"

s32 func_0019C5B0();
extern u8 D_0026A400[];
extern u8 D_0026A440[];
extern u8 *reg_a4;

void func_0015BB60() {
    u8 *var_s0;
    u32 temp_a0;
    u32 temp_a0_2;

    reg_a4 = D_0026A400;
    var_s0 = D_0026A440;
loop_1:
    temp_a0 = (*(u32 *)((u8 *)(var_s0) + (0)));
    if (temp_a0 != -1U) {
        reg_d1.w = temp_a0;
        temp_a0_2 = (*(u32 *)((u8 *)(var_s0) + (4)));
        reg_d2.w = temp_a0_2;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = 2;
        func_0019C5B0();
        var_s0 += 8;
        goto loop_1;
    }
}
