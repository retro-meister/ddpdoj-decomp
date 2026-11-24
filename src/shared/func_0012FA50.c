#include "common.h"

extern s16 D_0028E234;
extern s16 D_0028E238;
extern s16 *reg_a0_as_s16_p;

void func_0012FA50(void) {
    reg_a0_as_s16_p = &D_0028E234;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = &D_0028E238;
    *reg_a0_as_s16_p = 0;
}
