#include "common.h"

s32 func_00125EB0();
s32 func_0013E6C0();
s32 func_0016BAF0();
s32 func_0016BCC0();
s32 func_0016C260();
s32 func_0016C2A0();
s32 func_0018D990();
extern u8 D_0026AF40[];
extern u16 D_0028E3EC;
extern u16 D_0028E5C0;
extern u16 D_0028E5FC;
extern u16 D_0028E958_as_u16;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016B9B0(void) {
    u32 saved_d7;

    if (!(reg_d1.w & 0x2000)) {
        reg_a6[1] |= 0x20;
        func_0016BCC0();
        if (*(s16 *)(reg_a6 + 0xE) < 0) {
            *(s16 *)(reg_a6 + 4) = 0x1400;
        }
        *(s16 *)(reg_a6 + 0xC) = 0x202;
        *(s16 *)(reg_a6 + 0xE) = 0;
    }
    if (D_0028E958_as_u16 != 0) {
        func_0016C260();
        return;
    }
    if (D_0028E5FC == 0) {
        goto next_1;
    }
block_10:
    saved_d7 = reg_d7.w;
    reg_d0.w = 0x1C;
    reg_d2.w = 5;
    func_00125EB0();
    reg_d7.w = saved_d7;
    func_0016C260();
    return;
next_1:
    reg_d0.h[0] = D_0028E5C0;
    if (reg_d0.h[0] == 5) {
        goto block_10;
    }
    reg_d4.h[0] = 5;
    if (reg_d0.h[0] == 4) {
        if (D_0028E3EC == 0) {
            reg_d4.h[0] = 5;
        }
    }
    reg_d2.w = 0xB5A;
    reg_d5.w = 0xF900FA00;
    if (!(reg_d1.w & 0x1000)) {
        func_0016BAF0();
        return;
    }
    func_0013E6C0();
    func_0018D990();
    reg_a0 = (u8 *)D_0026AF40;
    func_0016C2A0();
    return;
}
