#include "common.h"

extern u8 *work_reg_a4;
extern u8 *D_0028E450;
extern void func_001E8840(void);

void func_001E8820(void) {
    *(s16 *)(work_reg_a4 + 2) = 1;
    *(s16 *)(D_0028E450 + 0x126) = 0;
    func_001E8840();
}
