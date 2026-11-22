#include "common.h"
extern void func_0019C430(void);
extern s32 reg_d2;
extern s16 reg_d4;
extern s16 reg_d3;
void func_0012F9F0(void) {
    reg_d1.w = 0x20000E00;
    reg_d4 = 0;
    reg_d2 = 0x155D;
    reg_d3 = 0x1870;
    func_0019C430();
}
