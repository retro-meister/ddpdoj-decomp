#include "common.h"

extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00147F30(void) {
    reg_a0 = D_0029D770;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x1A))) == 0) {
        reg_a0 = D_0029D750;
    }
    if ((*(u16 *)((u8 *)(reg_a0) + (0xC))) == 0) {
        (*(u8 *)((u8 *)(reg_a0) + (0))) |= 1;
        (*(u16 *)((u8 *)(reg_a0) + (0xC))) = 1U;
    }
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
}
