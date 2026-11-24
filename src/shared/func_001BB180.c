#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;
void func_001BAEC0(void);

void func_001BB180(void) {
    *(u16 *)reg_a4 = 0;
    reg_a4[3] = reg_a6[0x1B];
    func_001BAEC0();
}
