#include "common.h"

s32 func_001A54C0();
s32 func_001A5600();
s32 func_001A5740();
s32 func_001A5850();
s32 func_001AA8F0();
s32 func_001AAA20();
extern Reg32 D_0028E484;
extern u16 D_0028E628;
extern u16 D_0028E62C;
extern u16 D_0028E630;
extern u8 D_0028E634_as_u8;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;

void func_001A6E70(void) {
    reg_d1.h[0] = 0x5DC0;
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] += reg_d0.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    if ((D_0028E634_as_u8 & 8) && ((s32) D_0028E630 < 0x11)) {
        D_0028E628 -= 1;
        if ((s16) D_0028E628 < 0) {
            D_0028E628 = 0;
        }
    }
    reg_d6.h[0] = D_0028E628;
    reg_d0.h[0] = D_0028E8C4;
    reg_d6.h[0] <<= 6;
    if ((s16)(D_0028E8C4) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x500;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] -= reg_d6.h[0];
        func_001A54C0();
        if ((s8) D_0028E634_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x200;
            func_001A5740();
            func_001AA8F0();
        }
    }
    reg_d0.h[0] = D_0028E8C0;
    if ((s16)(D_0028E8C0) >= 0) {
        reg_tmp.w = (u32) reg_d0.h[0];
        reg_tmp.w -= 1;
        reg_d0.h[0] = reg_tmp.h[0];
        if (reg_tmp.h[1] == 0) {
            if ((s32) reg_d0.h[0] > 5) {
                reg_d0.w = 5;
            }
        }
        reg_d1.h[0] = 0x3300;
        reg_d7.h[0] = reg_d0.h[0];
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] += reg_d6.h[0];
        func_001A5600();
        if ((s8) D_0028E634_as_u8 < 0) {
            reg_d0.h[0] = 0xBC;
            reg_d1.h[0] = 0x1900;
            func_001A5850();
            func_001AAA20();
        }
    }
    D_0028E62C -= 1;
    if ((s16) D_0028E62C < 0) {
        D_0028E62C = 0;
    }
}
