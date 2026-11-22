#include "common.h"

extern u8 *reg_a0;
extern u8 *reg_a6;

extern u8 D_00269490[];

void func_0016BCC0(void) {
    (*(s8 *)(reg_a6 + 0x18)) = 1;
    reg_d0.h[0] = (*(u16 *)(reg_a6 + 0x1E));
    reg_a0 = D_00269490;
    reg_a0 += reg_d0.h[0];
    (*(u16 *)(reg_a6 + 0x1E)) = *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)(reg_a6 + 0x1A)) = *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)(reg_a6 + 0x1C)) = *(u16 *)reg_a0;
    reg_a0 += 2;
}
