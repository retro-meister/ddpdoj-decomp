#include "common.h"

extern s32 D_0028E49C;
extern u16 D_0028E910;
extern u16 D_0028E928;

void func_00211470(void) {
    D_0028E49C = 0x1D;
    if (D_0028E910 == 0) {
        if (D_0028E928 == 0) {
            goto block_3;
        }
    } else {
block_3:
        D_0028E49C = 0xE;
    }
}
