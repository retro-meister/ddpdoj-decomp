#include "common.h"

s32 func_00124D90();                            /* extern */
s32 func_0013B8B0();                            /* extern */
s32 func_001C7F70(s32, s32, s32);   /* extern */
extern s32 D_0026C7B0[];
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a4;

void func_001C7EE0(void) {
    reg_d0.w = 1;
    func_00124D90();
    reg_a0_as_s32_p = D_0026C7B0;
    func_0013B8B0();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x101;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0xD))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x2020;
    (*(s16 *)((u8 *)(reg_a4) + (0x12))) = 4;
    (*(s16 *)((u8 *)(reg_a4) + (0x14))) = 0;
    func_001C7F70(0x2020, 1, 0x101);
}
