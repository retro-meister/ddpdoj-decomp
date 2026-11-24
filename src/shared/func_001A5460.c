#include "common.h"

extern void func_0011C4A0(void);

void func_001A5460(void) {
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    reg_d2.sh[0] = 2;
    reg_d3.sh[0] = 5;
    reg_d4.sw = 0x414000A;
    func_0011C4A0();
}
