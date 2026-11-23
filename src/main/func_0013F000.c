#include "common.h"

s32 func_0011C4A0();
s32 func_0011C610();
s32 func_0013EAD0();
void func_0013F000(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    func_0013EAD0();
    reg_d3.w = 0;
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d5.h[0] = 2;
    func_0011C610();
    reg_d3.w = 1;
    reg_d1.h[0] -= 0x200;
    reg_d4.w = 0x02C6000A;
    reg_d7.w = 5;
    do {
        func_0011C4A0();
        reg_d1.h[0] -= 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d4.w = 0x02D2000A;
    func_0011C4A0();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}
