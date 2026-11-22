#include "common.h"

extern s16 reg_d2;
extern s16 reg_d3;
void func_0011C7C0(void);

void func_001AC8E0(void) {
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2 = 7;
    reg_d3 = 7;
    func_0011C7C0();
}
