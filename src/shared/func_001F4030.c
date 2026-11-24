#include "common.h"

extern u8 *reg_a6;

void func_001F4050(s32 value);

void func_001F4030(void) {
    reg_a6[0x1B] = 3;
    reg_a6[0x1A] = 0x20;
    func_001F4050(3);
}
