#include "common.h"

s32 func_00202500();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B45F0() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_d1.w = 0;
        reg_d1.b[0] = 0x20;
        reg_d0.w = 0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
        reg_d0.h[0] += 0x20;
        func_00202500();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] -= 0x20;
        (*(u16 *)((u8 *)(reg_a6) + (0xAC))) = (u16) reg_d0.h[0];
        if (reg_d1.b[0] == 0x20) {
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
