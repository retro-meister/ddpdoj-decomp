#include "common.h"

s32 func_001C3290();
s32 func_002010A0();
extern u8 *reg_a4;

void func_001C3210() {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 2;
    func_002010A0();
    reg_d0.b[0] += 0x10;
    (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) reg_d0.b[0];
    func_002010A0();
    reg_d0.b[0] += 0x30;
    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0x40;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
    func_001C3290();
}
