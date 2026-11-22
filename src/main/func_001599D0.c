#include "common.h"

extern u8 *reg_a5;

void func_001599D0(void) {
    (*(s16 *)((u8 *)(reg_a5) + (0x2C))) = 0;
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) += 1;
    if ((*(u16 *)((u8 *)(reg_a5) + (0x2A))) == 2) {
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = 0U;
    }
}
