#include "common.h"

extern void *reg_a4;
void func_001F3860(s32 value);

void func_001F3840(void) {
    ((s16 *)reg_a4)[1] = 0x60;
    ((s16 *)reg_a4)[2] = 0x40;
    func_001F3860(0x60);
}
