#include "common.h"

s32 func_001DB480();
extern u8 *reg_a4;

void func_001DB420(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x4008;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 4;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0xA;
    (*(s8 *)((u8 *)(reg_a4) + (0xB))) = 8;
    (*(s8 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 0;
    func_001DB480();
}
