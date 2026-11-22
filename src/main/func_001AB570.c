#include "common.h"

s32 func_001AB500(u16);
extern s16 D_0028E748;
extern u8 D_002BAF3A[];
extern u8 *reg_a0;

void func_001AB570(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = D_0028E748;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        D_0028E748 = temp_a0 + 1;
        reg_a0 = D_002BAF3A;
        func_001AB500(temp_a0);
        reg_a0 = temp_s0;
    }
}
