#include "common.h"

s32 func_0014C590();
extern u16 D_0029C066[];
extern u16 D_0029C080[];
extern u16 *reg_a1_as_u16_p;

void func_0014CF10(void) {
    u16 *temp_a0;
    u16 temp_a1;

    reg_d0.h[0] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    reg_d1.h[1] = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
    temp_a1 = *reg_a1_as_u16_p;
    temp_a0 = reg_a1_as_u16_p + 1;
    reg_d1.h[0] = temp_a1;
    reg_a1_as_u16_p = temp_a0;
    if (D_0029C080[0] == 0) {
        reg_d1.h[0] -= 0x800;
        reg_d1.h[0] -= D_0029C066[0];
        func_0014C590();
    }
}
