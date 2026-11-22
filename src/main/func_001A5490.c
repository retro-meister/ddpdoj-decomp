#include "common.h"

extern s16 bcd_result;
extern s16 D_0028E49C;
extern s32 D_0028E498;

void func_0011C4A0(void);

void func_001A5490(void) {
    work_reg_0.h[0] = 0xC8;
    work_reg_1.h[0] = 0x1400;
    bcd_result = 2;
    D_0028E49C = 5;
    D_0028E498 = 0x414000A;
    func_0011C4A0();
}
