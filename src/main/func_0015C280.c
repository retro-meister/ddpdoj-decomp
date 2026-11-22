#include "common.h"

extern Reg32 reg_d1;
extern s32 reg_d2;
extern s16 reg_d4;
extern s16 reg_d3;
void func_0019C430(void);

void func_0015C280(void) {
    reg_d1.w = 0x1A000800;
    reg_d2 = 0x155A;
    reg_d3 = 0x20A0;
    reg_d4 = 1;
    func_0019C430();
}
