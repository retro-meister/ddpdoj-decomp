#include "common.h"

extern u16 *reg_a4;
void func_001BF2A0(s32, s32);

void func_001BF270(void) {
    reg_a4[1] = 0x808;
    reg_a4[3] = 1;
    reg_a4[4] = 2;
    func_001BF2A0(1, 0x808);
}
