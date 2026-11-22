#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
extern void func_001E8840(void);

void func_001E8820(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    *(s16 *)(reg_a6 + 0x126) = 0;
    func_001E8840();
}
