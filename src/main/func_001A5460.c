#include "common.h"

extern void func_0011C4A0(void);
extern s16 reg_d2;
extern s16 reg_d3;
extern s32 reg_d4;

void func_001A5460(void) {
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x200;
    reg_d2 = 2;
    reg_d3 = 5;
    reg_d4 = 0x414000A;
    func_0011C4A0();
}
