#include "common.h"

extern u8 *reg_a4;

void func_001D9090(void) {
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x4000;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x909;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 7;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
}
