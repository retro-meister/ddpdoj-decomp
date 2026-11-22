#include "common.h"

extern void *D_0028E450;
extern u16 D_0029A528[];

void func_00209EA0(void) {
    *(u16 *)((u8 *)D_0028E450 - 4) = 0;
    D_0029A528[0] -= 1;
}
