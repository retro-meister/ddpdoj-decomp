#include "common.h"
extern void func_0019C430(void);
extern s32 reg_d2;
extern s16 reg_d4;
extern s16 reg_d3;
void func_0015C2E0(void) {
    reg_d1.w = 0x64003000;
    reg_d2 = 0x1558;
    reg_d4 = 0;
    reg_d3 = 0x410;
    func_0019C430();
}
