#include "common.h"

extern void *reg_a6;

void func_00201FE0(void);

void func_00201FC0(void) {
    u8 *base = (u8 *)reg_a6;

    reg_d0.w = 0;
    reg_d0.b[0] = base[0x1B];
    reg_d1.w = 0;
    reg_d1.b[0] = base[0x1A];
    func_00201FE0();
}
