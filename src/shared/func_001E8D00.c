#include "common.h"

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;
void func_001E8D20(void);

void func_001E8D00(void) {
    ((u16 *)reg_a4_as_void_p)[1] = 1;
    *(u16 *)((u8 *)reg_a6_as_void_p + 0x12C) = 0;
    func_001E8D20();
}
