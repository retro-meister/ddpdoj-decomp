#include "common.h"

extern s16 *reg_a4;
extern u8 *reg_a6;
extern void func_001BAEC0(void);

void func_001BB460(void) {
    u8 value;

    *reg_a4 = 0;
    value = reg_a6[0x1B];
    ((u8 *)reg_a4)[3] = value;
    func_001BAEC0();
}
