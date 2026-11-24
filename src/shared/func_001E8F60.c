#include "common.h"

extern void *reg_a4;
extern void *reg_a6;
extern void func_001E8F80(void);

void func_001E8F60(void) {
    ((s16 *)reg_a4)[1] = 1;
    *(s16 *)((u8 *)reg_a6 + 0x138) = 0;
    func_001E8F80();
}
