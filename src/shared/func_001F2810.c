#include "common.h"

s32 func_0013B8B0();                            /* extern */
s32 func_001A3020();                            /* extern */
s32 func_001F28A0(s32, s32);            /* extern */
extern s32 D_002554B0_as_s32_a[];
extern s32 D_00264E80[];
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a4;

void func_001F2810(void) {
    reg_d0.h[0] = 0xE;
    reg_a0_as_s32_p = D_002554B0_as_s32_a;
    func_001A3020();
    reg_a0_as_s32_p = D_00264E80;
    func_0013B8B0();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x101;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0xD))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x2020;
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 0;
    func_001F28A0(1, 0x101);
}
