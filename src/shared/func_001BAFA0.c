#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
extern void func_001BAEC0(void);

void func_001BAFA0(void) {
    *(u16 *)reg_a4 = 0;
    *(u16 *)(reg_a6 + 0x1A) = 0x20;
    reg_a4[3] = reg_a6[0x1B];
    func_001BAEC0();
}
