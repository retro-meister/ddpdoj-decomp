#include "common.h"

s32 func_0011C7C0();
s32 func_00137AD0();
extern u8 D_00269BA0[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001349A0() {
    if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
        reg_d0.h[0] = 0x8C;
        reg_d1.h[0] = 0x400;
        reg_d2.w = 3;
        reg_d3.w = 0x13;
        func_0011C7C0();
        reg_d0.h[0] = 0x74;
        reg_d1.h[0] = 0xC00;
        reg_d2.w = 7;
        reg_d3.w = 3;
        func_0011C7C0();
        reg_d0.h[0] = 1;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
        reg_d0.h[0] = 0xF;
        reg_d1.h[0] = 0x32;
        reg_a0 = D_00269BA0;
        reg_d2.h[0] = 2;
        func_00137AD0();
    }
    (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
}
