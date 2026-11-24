#include "common.h"

extern u8 *reg_a6;

void func_001B4B90(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0xAA))) += 4;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xAA))) >= 0x1C) {
        (*(u16 *)((u8 *)(reg_a6) + (0xAA))) = 0U;
    }
}
