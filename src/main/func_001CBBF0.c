#include "common.h"
extern u8 *D_0028E450;
void func_001CBBF0(void) {
    work_reg_0.h[0] = 0xA000;
    *(u16 *)(D_0028E450 + 0x100) |= work_reg_0.h[0];
}
