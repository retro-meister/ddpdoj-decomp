#include "common.h"

s32 func_001BE5F0();                            /* extern */
s32 func_001E8710(s32, s32, s32, s32); /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BE560(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x20;
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0x280;
    (*(s8 *)((u8 *)(reg_a4) + (0xB))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x101;
    (*(s16 *)((u8 *)(reg_a6) + (0x126))) = 0x1C;
    (*(s16 *)((u8 *)(reg_a6) + (0x128))) = 0;
    func_001E8710(0x101, 1, 0x280, 0x20);
    func_001BE5F0();
}
