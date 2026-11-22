#include "common.h"

extern u32 D_0028E450;
extern u32 D_0028E468;

void func_001CBC70(void) {
    D_0028E468 = D_0028E450;
    D_0028E468 += work_reg_0.h[0];
    *(u16 *)D_0028E468 = 0xA000;
}
