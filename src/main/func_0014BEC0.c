#include "common.h"

s32 func_0012FA80();
s32 func_0012FAB0();
s32 func_0012FB00();
s32 func_0013B2E0(s32, s32, s32, s32);
s32 func_00219570();
extern u8 D_0026A3F0[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 D_0028ED74;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_0014BEC0(void) {
    D_0028ED74 = 2;
    D_0028E378 = 0xFF;
    D_0028E368 = 0;
    func_0012FA80();
    func_0012FAB0();
    func_0012FB00();
    func_00219570();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s16 *)((u8 *)(reg_a5) + (8))) = 0x4400;
    (*(s16 *)((u8 *)(reg_a5) + (0xA))) = 0x1C00;
    (*(s16 *)((u8 *)(reg_a5) + (0x14))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x12))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x10))) = 0;
    (*(s8 *)((u8 *)(reg_a5) + (0x17))) = 1;
    (*(s8 *)((u8 *)(reg_a5) + (0x16))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0;
    (*(s16 *)((u8 *)(reg_a5) + (4))) = 0x1E0;
    reg_a0 = D_0026A3F0;
    func_0013B2E0(0x1E0, 0x1C00, 0x4400, 1);
    (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0x20;
    (*(s16 *)((u8 *)(reg_a5) + (0x1C))) = 0x20;
}
