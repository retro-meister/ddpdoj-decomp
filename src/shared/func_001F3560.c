#include "common.h"

s32 func_001F35B0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F3560(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x40;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
    func_001F35B0();
}
