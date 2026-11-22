#include "common.h"

extern u16 D_0028E150;
extern u8 *reg_a0;
extern u8 D_002A4430[];

void func_0019D7E0(void) {
    u32 counter;

    reg_a0 = D_002A4430;
    counter = D_0028E150;
    reg_a0 += counter;
    D_0028E150 = counter + 0xC;
}
