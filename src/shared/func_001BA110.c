#include "common.h"

extern u8 *reg_a4;

void func_001BA110(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x80;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x40;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x404;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0x6060;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x404;
}
