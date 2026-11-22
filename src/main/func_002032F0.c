#include "common.h"

extern s8 D_0028E408;
extern s16 *D_0028E44C;
extern s16 *reg_a0;
extern s16 *reg_a1;

void func_002032F0(void) {
    s16 *temp_a0;

    temp_a0 = reg_a0;
    if (*temp_a0 >= 0) {
        if (*reg_a1 >= 0) {
            D_0028E408 = 1;
            return;
        }
        reg_a0 = reg_a1;
        D_0028E44C = temp_a0;
        reg_a1 = temp_a0;
        goto block_4;
    }
block_4:
    D_0028E408 = 0;
}
