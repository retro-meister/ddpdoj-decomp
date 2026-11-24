#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E6EF0(void) {
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
    (*(u8 *)((u8 *)(reg_a6) + (0x11A))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x11A))) &= 0x3F;
}
