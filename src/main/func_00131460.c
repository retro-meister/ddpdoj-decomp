#include "common.h"

extern s16 D_0028E22C;
extern s16 D_0028E3C8;

void func_00131460(void) {
    work_reg_0.h[0] = (u16) D_0028E22C;
    D_0028E3C8 = 0;
    if (!(work_reg_0.w & 0x80)) {
        D_0028E3C8 = 1;
    }
}
