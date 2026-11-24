#include "common.h"

extern void *reg_a4;
void func_001F1680(s32 value);

void func_001F1660(void) {
    ((u16 *)reg_a4)[1] = 0xC0;
    ((u16 *)reg_a4)[2] = 0x303;
    func_001F1680(0xC0);
}
