#include "common.h"

s32 func_001AB500(u16);
extern s16 D_0028E750;
extern u8 D_002BAF30[];
extern u8 *reg_a0;

void func_001AB520(void) {
    u8 *temp_s0;
    u16 temp_a0;

    temp_a0 = D_0028E750;
    if (temp_a0 != 9) {
        temp_s0 = reg_a0;
        D_0028E750 = temp_a0 + 1;
        reg_a0 = D_002BAF30;
        func_001AB500(temp_a0);
        reg_a0 = temp_s0;
    }
}
