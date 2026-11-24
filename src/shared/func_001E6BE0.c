#include "common.h"

extern void *reg_a6_as_void_p;
void func_001E6C00(void);

void func_001E6BE0(void) {
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x26) = 2;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x28) = 0;
    func_001E6C00();
}
