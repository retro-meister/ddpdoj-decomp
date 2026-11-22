#include "common.h"

extern void func_0011C4A0(void);

void func_001AC9D0(void) {
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1A00;
    reg_d2.sh[0] = 7;
    reg_d3.sh[0] = 1;
    reg_d4.sw = 0x3EE000A;
    func_0011C4A0();
}
