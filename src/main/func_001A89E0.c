#include "common.h"

extern s32 D_0026BAB0[];
extern u16 D_0028E3F0;
extern s32 D_0028E6F0;
extern u8 *reg_a0;

void func_001A89E0(void) {
    reg_d0.w = 0x3F;
    reg_a0 = (u8 *)D_0026BAB0;
    reg_d0.h[0] &= D_0028E3F0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    D_0028E6F0 = *(s32 *)(reg_a0 + reg_d0.h[0]);
}
