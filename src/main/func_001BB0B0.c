#include "common.h"

extern void *D_0028E450;
extern void *work_reg_a4;

void func_001BB0B0(void) {
    *(u16 *)work_reg_a4 = 0;
    ((u8 *)work_reg_a4)[3] = ((u8 *)D_0028E450)[0x1B];
}
