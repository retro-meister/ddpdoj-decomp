#include "common.h"

extern s16 bcd_result;
extern s16 D_0028E49C;
void func_0011C7C0(void);

void func_001AC8C0(void) {
    work_reg_0.h[0] = 0xD4;
    bcd_result = 7;
    D_0028E49C = 7;
    work_reg_1.h[0] = 0;
    func_0011C7C0();
}
