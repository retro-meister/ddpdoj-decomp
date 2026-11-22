#include "common.h"

extern u8 *D_0028E450;
extern u16 D_0029A528[];

void func_00209E80(void) {
    *(u16 *)((u8 *)D_0028E450 - 2) = 0;
    D_0029A528[0] -= 1;
}
