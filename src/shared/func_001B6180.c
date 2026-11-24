#include "common.h"

extern u8 *reg_a4;

void func_001B6180(void) {
    (*(s8 *)((u8 *)(reg_a4) + (5))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (4))) = 0x20;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x202;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = 8;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 6;
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0xFFF8;
}
