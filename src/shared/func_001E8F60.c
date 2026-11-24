#include "common.h"

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;
extern void func_001E8F80(void);

void func_001E8F60(void) {
    ((s16 *)reg_a4_as_void_p)[1] = 1;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x138) = 0;
    func_001E8F80();
}
