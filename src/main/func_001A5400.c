#include "common.h"

extern s16 bcd_result;
extern s16 D_0028E49C;
extern s32 D_0028E498;
extern void func_0011C4A0(void);

void func_001A5400(void) {
    work_reg_0.h[0] = 0xD4;
    work_reg_1.h[0] = 0x200;
    bcd_result = 2;
    D_0028E49C = 5;
    D_0028E498 = 0x54F000A;
    func_0011C4A0();
}
