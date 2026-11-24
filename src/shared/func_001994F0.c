#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001994F0(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x2C)));
    (*(u8 *)((u8 *)(reg_a5) + (4))) &= (~(1 << (s8) reg_d0.b[0]) & 0xFF);
    if ((*(u8 *)((u8 *)(reg_a5) + (4))) == 0) {
        (*(s8 *)((u8 *)(reg_a5) + (3))) = 2;
    }
}
