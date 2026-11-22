#include "common.h"

extern u8 *reg_a4;

void func_001B5460(void) {
    (*(u16 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (5))) = 0;
    (*(s8 *)((u8 *)(reg_a4) + (4))) = 0x20;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x101;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = 4;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0x10;
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0xFFFC;
}
