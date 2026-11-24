#include "common.h"

extern u8 *reg_a6;
extern u8 *reg_a4;
void func_001BEDD0(s32 arg0);

void func_001BEDA0(void) {
    reg_a6[0x1A] = 0x20;
    reg_a4[0x3] = 1;
    *(u16 *)&reg_a4[0x4] = 0;
    func_001BEDD0(0x20);
}
