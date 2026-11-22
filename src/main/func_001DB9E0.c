#include "common.h"

s32 func_001DBA40();                            /* extern */
s32 func_002026F0(s32);                     /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DB9E0(void) {
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0xC20;
    (*(s8 *)((u8 *)(reg_a4) + (7))) = 7;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x102)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x104)));
    func_002026F0(0xC20);
    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d1.b[0];
    func_001DBA40();
}
