#include "common.h"

extern void *reg_a4;

void func_001E70A0(void);

void func_001E7080(void) {
    *(u16 *)((u8 *)reg_a4 + 2) = 2;
    *(u16 *)((u8 *)reg_a4 + 4) = 0;
    func_001E70A0();
}
