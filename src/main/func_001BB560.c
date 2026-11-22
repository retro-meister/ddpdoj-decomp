#include "common.h"

extern u8 *D_0028E450;
extern u8 *work_reg_a4;

void func_001BB560(void) {
    *(u16 *)work_reg_a4 = 0;
    work_reg_a4[3] = D_0028E450[0x1B];
}
