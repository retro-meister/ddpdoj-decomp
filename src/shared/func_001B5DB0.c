#include "common.h"

s32 func_001713B0();
s32 func_001B5CD0();
s32 func_001B5E70();
s32 func_002010A0();
extern u8 D_0028DC38[];
extern u8 *reg_a4;

void func_001B5DB0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0x38;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 8;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0x40U;
    func_002010A0();
    reg_d0.b[0] = reg_d0.sb[0] * 4;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a4) + (0xE))) = 0x404;
    (*(s16 *)((u8 *)(reg_a4) + (0x10))) = 0x505;
    (*(s8 *)((u8 *)(reg_a4) + (0x13))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0x12))) = 0;
    func_001B5CD0();
    func_001713B0();
    (*(u8 *)((u8 *)(reg_a4) + (0x10))) = *(D_0028DC38 + reg_d0.b[0]);
    func_001B5E70();
}
