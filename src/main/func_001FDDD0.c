#include "common.h"

extern void *D_0028E450;

void func_001FDDD0(void) {
    if (((u16 *)D_0028E450)[0x26 / 2] != work_reg_0.h[0]) {
        ((u16 *)D_0028E450)[0x26 / 2] = (u16) work_reg_0.h[0];
        ((u16 *)D_0028E450)[0x28 / 2] = 0;
    }
}
