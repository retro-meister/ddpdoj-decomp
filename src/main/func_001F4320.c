#include "common.h"

s32 func_001F4370();
s32 func_00201160();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F4320() {
    reg_d0.w = 0;
    (*(u8 *)((u8 *)(reg_a4) + (1))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0))) = (u8) reg_d0.b[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 6;
    func_00201160();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_001F4370();
}
