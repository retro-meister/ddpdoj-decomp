#include "common.h"

extern Reg32 work_reg_0;
extern Reg32 work_reg_1;
extern s16 bcd_result;
extern s16 D_0028E49C;
extern s32 D_0028E498;
extern void func_0011C4A0(void);

void func_001AC950(void) {
    work_reg_0.h[0] = 0xD4;
    bcd_result = 7;
    D_0028E49C = 1;
    D_0028E498 = 0x0404000A;
    work_reg_1.h[0] = 0;
    func_0011C4A0();
}
