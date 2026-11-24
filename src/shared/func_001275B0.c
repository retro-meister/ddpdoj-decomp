#include "common.h"

extern s8 D_0028E408;
extern void *reg_a0;

void func_001275B0(void) {
    *(u16 *)((u8 *)reg_a0 + 0x1E) = 0x9601;
    D_0028E408 = 0;
}
