#include "common.h"

extern u8 *D_0028E450;
extern u8 *D_0028E468;

void func_001E8760(void) {
    D_0028E468 = D_0028E450;
    D_0028E468 += work_reg_0.h[0];
    *(u16 *)D_0028E468 = 0x8000;
}
