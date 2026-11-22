#include "common.h"

extern u8 *reg_a4;

void func_0013F960(void) {
    u16 *speed_field = (u16 *)(reg_a4 + 0x60);
    u16 speed = *speed_field;

    if (speed != 0x80) {
        *speed_field = speed + 4;
    }
}
