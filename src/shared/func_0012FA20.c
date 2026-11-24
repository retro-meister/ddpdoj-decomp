#include "common.h"

extern s16 D_0028E23C;
extern s16 D_0028E240;
extern s16 *reg_a0_as_s16_p;

void func_0012FA20(void) {
    reg_a0_as_s16_p = &D_0028E23C;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = &D_0028E240;
    *reg_a0_as_s16_p = 1;
}
