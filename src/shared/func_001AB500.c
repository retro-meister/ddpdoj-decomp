#include "common.h"

extern u8 *reg_a0;

void func_001AB500(void) {
    *(u16 *)(reg_a0 + 6) += 1;
    *(u16 *)reg_a0 = 1;
}
