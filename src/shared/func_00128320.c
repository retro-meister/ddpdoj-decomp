#include "common.h"

void func_0019D2C0(void);
void func_0019D2F0(void);
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 *reg_a6;

void func_00128320(void) {
    u32 sd6;
    u32 sd7;

    reg_d1.h[0] += 0x7FFF + 0x7DC1;
    reg_d1.h[1] += 0x200;
    reg_d2.w = 0x11E0;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    func_0019D2C0();
    reg_d3.h[0] = 0x410;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x7FFF + 0x7F41;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    reg_d7.w = 1;
    reg_d6.w = 0;
    do {
        reg_d5.w = 0x1046;
        reg_d2.w = 0xF;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        reg_d4.w = 0;
        if (reg_d2.h[0] == 0 && reg_d6.h[0] == 0) {
            reg_d5.w = 0x103C;
        } else {
            reg_d4.h[0] = reg_d2.h[0] * 0xA;
        }
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d2.w = 0xF;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        if (reg_d2.h[0] != 0 || reg_d4.h[0] != 0 || reg_d6.h[0] != 0) {
            reg_d6.w = 1;
            reg_d2.w += reg_d4.w;
            if (reg_d5.w == 0x103C) {
                reg_d1.h[0] += 0x7FFF + 0x7E01;
            }
            reg_d2.w += reg_d5.w;
            reg_d4.h[0] = 0x1D;
            func_0019D2F0();
            reg_d1.h[0] += 0x400;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    if (D_0028E91C != 0 || D_0028E910 != 0) {
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        return;
    }
    reg_d2.w = 0x11E1;
    reg_d1.h[0] += 0x400;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    reg_d1.h[1] += 0xC0;
    func_0019D2F0();
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_d1.w += 0xFF400000;
}
