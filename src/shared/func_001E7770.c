#include "common.h"

s32 func_0016A8B0();
s32 func_0019C5B0();
s32 func_002093F0();
extern u32 D_00264050[];
void func_001E7770(void) {
    u32 *var_s0;
    u32 *var_s0_2;
    u32 *var_s0_3;
    u32 *var_s0_4;
    u32 temp_a0;

    reg_d6.w = 0x50000E00;
    reg_d4.h[0] = 0;
    var_s0 = (u32 *)(D_00264050);
    reg_d3.h[0] = 0x208;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        var_s0 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_2 = (u32 *)(D_00264050);
    reg_d6.w = 0x48000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 1;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_2;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        var_s0_2 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_3 = (u32 *)(D_00264050);
    reg_d6.w = 0x40000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 2;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_3;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        var_s0_3 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    var_s0_4 = (u32 *)(D_00264050);
    reg_d6.w = 0x38000E00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 3;
    reg_d7.w = 0xE;
    do {
        reg_d1.w = reg_d6.w;
        reg_d2.w = *var_s0_4;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        reg_d1.w += 0xFE000000;
        func_0019C5B0();
        var_s0_4 += 1;
        reg_d6.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    func_0016A8B0();
    temp_a0 = reg_d0.w;
    if ((temp_a0 & 0x8000) && (temp_a0 & 0x10)) {
        reg_d0.w = 0;
        func_002093F0();
    }
    reg_d0.w = 0;
}
