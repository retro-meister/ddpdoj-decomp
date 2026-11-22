#include "common.h"

extern u8 *reg_a4;
extern void func_001CA1F0(void);

void func_001CA1D0(void) {
    reg_a4[3] = 0;
    reg_a4[2] = 0;
    *(s16 *)(reg_a4 + 4) = 0x404;
    func_001CA1F0();
}
