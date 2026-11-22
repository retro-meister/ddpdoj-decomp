#include "common.h"

extern u8 *reg_a6;
extern u8 *reg_a4;
void func_001BEE10(void);

void func_001BEDE0(void) {
    reg_a6[0x1B] = 0;
    reg_a6[0x1A] = 0x20;
    reg_a4[3] = 0;
    *(u16 *)&reg_a4[4] = 0;
    func_001BEE10();
}
