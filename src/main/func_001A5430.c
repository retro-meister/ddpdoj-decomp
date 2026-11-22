#include "common.h"

extern void func_0011C4A0(void);
extern s16 reg_d3;
extern s16 reg_d2;
extern s32 reg_d4;

void func_001A5430(void) {
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0x1400;
    reg_d2 = 2;
    reg_d3 = 5;
    reg_d4 = 0x54F000A;
    func_0011C4A0();
}
