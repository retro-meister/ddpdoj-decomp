#include "common.h"

s32 func_00202040();
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_00201FE0(void) {
    if (D_0028E8A0 == 0) {
        func_00202040();
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}
