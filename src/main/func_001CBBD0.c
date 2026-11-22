#include "common.h"

extern u8 *reg_a6;

void func_001CBBD0(void) {
    *(s16 *)(reg_a6 + 0x148) = 1;
}
