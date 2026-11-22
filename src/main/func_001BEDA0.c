#include "common.h"

extern u8 *D_0028E450;
extern u8 *work_reg_a4;
void func_001BEDD0(s32 arg0);

void func_001BEDA0(void) {
    D_0028E450[0x1A] = 0x20;
    work_reg_a4[0x3] = 1;
    *(u16 *)&work_reg_a4[0x4] = 0;
    func_001BEDD0(0x20);
}
