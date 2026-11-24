#include "common.h"

s32 func_001BEC10();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BEBD0(void) {
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0x20;
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x3B))) = 6;
    func_001BEC10();
}
