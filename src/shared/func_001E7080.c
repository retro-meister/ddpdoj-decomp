#include "common.h"

extern void *reg_a4_as_void_p;

void func_001E70A0(void);

void func_001E7080(void) {
    *(u16 *)((u8 *)reg_a4_as_void_p + 2) = 2;
    *(u16 *)((u8 *)reg_a4_as_void_p + 4) = 0;
    func_001E70A0();
}
