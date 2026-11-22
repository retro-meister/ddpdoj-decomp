#include "common.h"

extern u8 *reg_a6;

void func_001FB630(void) {
    u8 *object = reg_a6;

    if (*(u16 *)(object + 0x68) == 0) {
        *(u16 *)(object + 0x1A) = 0x480;
    }
}
