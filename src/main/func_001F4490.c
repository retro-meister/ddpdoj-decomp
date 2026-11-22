#include "common.h"

s32 func_001F44E0();                            /* extern */
s32 func_002010A0();                            /* extern */
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F4490(void) {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    func_002010A0();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F44E0();
}
