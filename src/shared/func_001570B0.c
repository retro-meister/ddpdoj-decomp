#include "common.h"

s32 func_00128930();
s32 func_00201160();
extern u8 *reg_a6;

void func_001570B0(void) {
    u8 var_a0;

    func_00201160();
    var_a0 = reg_d0.b[0];
    reg_d1.b[0] = var_a0;
    reg_d0.w = 0xFFFC0005;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d7.w = 0xF;
    reg_d3.w = 0;
    reg_d4.w = 0;
    do {
        func_00128930();
        reg_d1.b[0] += 4;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
