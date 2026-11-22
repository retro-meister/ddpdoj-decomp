#include "common.h"

extern void *reg_a4;
extern void *reg_a6;
void func_001E8D20(void);

void func_001E8D00(void) {
    ((u16 *)reg_a4)[1] = 1;
    *(u16 *)((u8 *)reg_a6 + 0x12C) = 0;
    func_001E8D20();
}
