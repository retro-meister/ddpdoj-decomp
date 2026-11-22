#include "common.h"

extern u16 D_0028E928;
extern u8 D_0029BF30[];
extern u8 D_0029BF40[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001AF2C0(void) {
    reg_a0 = D_0029BF40;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
        reg_a0 = D_0029BF30;
    }
    reg_d0.b[0] = *reg_a0;
    if (D_0028E928 == 0) {
        reg_d0.h[0] = 0xFFFF;
    }
}
