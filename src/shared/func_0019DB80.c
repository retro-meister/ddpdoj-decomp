#include "common.h"

extern u16 D_0028E12C;
extern u8 *reg_a0;
extern u8 D_002A3D30[];

void func_0019DB80(void) {
    u32 temp;

    reg_a0 = D_002A3D30;
    temp = D_0028E12C;
    reg_a0 += temp;
    D_0028E12C = temp + 0xC;
}
