#include "common.h"

extern void *reg_a4_as_void_p;
void func_001F3190(s32 value);

void func_001F3170(void) {
    ((s16 *)reg_a4_as_void_p)[1] = 0x60;
    ((s16 *)reg_a4_as_void_p)[2] = 0x40;
    func_001F3190(0x60);
}
