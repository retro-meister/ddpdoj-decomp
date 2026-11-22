#include "common.h"

s32 func_001F3D30();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F3CF0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x808;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x40;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0;
    func_001F3D30();
}
