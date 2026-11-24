#include "common.h"

extern u8 death_D_006901D0[];
extern u8 *reg_a6;

s32 death_func_0021B180(void) {
    return reg_a6 == death_D_006901D0;
}
