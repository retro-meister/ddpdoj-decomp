#include "common.h"

extern s16 D_0028E23C;
extern s16 D_0028E240;
extern s16 *reg_a0;

void func_0012FA20(void) {
    reg_a0 = &D_0028E23C;
    *reg_a0 = 0;
    reg_a0 = &D_0028E240;
    *reg_a0 = 1;
}
