#include "common.h"

extern s16 bcd_result;
extern s16 D_0028E49C;
void func_0011C7C0(void);

void func_001AC8E0(void) {
    work_reg_0.h[0] = 0xD4;
    work_reg_1.h[0] = 0x1400;
    bcd_result = 7;
    D_0028E49C = 7;
    func_0011C7C0();
}
