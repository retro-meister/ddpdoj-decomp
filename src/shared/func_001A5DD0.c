#include "common.h"

s32 func_001A5430();
s32 func_001A5490();
s32 func_001A6510();
s32 func_001A7520();
s32 func_001A7C60();
s32 func_001A8510();
s32 func_001A8A40();
s32 func_001A8A60();
s32 func_001A8E00();
extern u16 D_0028E070;
extern u16 D_0028E3F0;
extern u8 D_0028E5D8_as_u8;
extern u8 D_0028E5D9;
extern u16 D_0028E5F8;
extern u16 D_0028E610;
extern s8 D_0028E634;
extern u16 D_0028E65C;
extern u32 D_0028E66C_as_u32;
extern u16 D_0028E670;
extern u16 D_0028E674;
extern u16 D_0028E678_as_u16;
extern u16 D_0028E688;
extern u32 D_0028E690_as_u32;
extern u32 D_0028E6F0_as_u32;
extern u32 D_0028E6FC_as_u32;
extern u8 D_0028E708;
extern u8 D_0028E854;
extern s16 D_0028E8C0_as_s16;
extern u16 D_0029CD8E[];
extern u8 D_0029F1F1[];
void func_001A5DD0(void) {
    if (D_0028E8C0_as_s16 < 0) {
        func_001A6510();
        return;
    }
    func_001A8510();
    if (!(D_0028E854 & 1) || (D_0028E634 < 0)) {
        if (D_0028E5F8 != 0) {
            if (!(D_0028E708 & 1)) {
                D_0028E708 |= 1;
                func_001A5430();
                func_001A5490();
            }
            reg_d1.w = 0x64C02800;
            reg_d2.w = D_0028E6FC_as_u32;
            func_001A8A40();
        } else {
            D_0028E708 &= 0xFE;
            if (D_0028E3F0 & 0x40) {
                if (!(D_0029F1F1[0] & 0x40) && (reg_d6.h[0] = D_0029CD8E[0], (D_0029CD8E[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= D_0028E3F0;
                    if ((s32) reg_d0.h[0] < 0x2C) {
                        func_001A5430();
                        reg_d1.w = 0x64C02800;
                        reg_d2.w = D_0028E6F0_as_u32;
                        func_001A8A40();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x1400;
                        reg_d5.h[0] = D_0028E070;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x1400;
                reg_d6.h[0] = D_0028E610;
                func_001A8E00();
            }
        }
    }
    if (D_0028E678_as_u16 != 0) {
        D_0028E678_as_u16 -= 1;
        reg_d1.h[0] = 0x1FC0;
        reg_d6.w = 0;
        reg_d0.h[0] = D_0028E65C;
        reg_d6.h[0] = D_0028E670;
        D_0028E670 += 1;
        reg_d3.h[0] = D_0028E678_as_u16;
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] -= reg_d3.h[0];
        }
        reg_d2.h[0] = D_0028E674;
        if (D_0028E674 != 0) {
            D_0028E674 -= 1;
        }
        reg_d4.h[0] = 8;
        func_001A7520();
    }
    reg_d6.h[0] = D_0028E688;
    if (D_0028E688 != 0) {
        if (D_0028E5F8 != 0) {
            D_0028E5D9 -= 1;
            if ((s8) D_0028E5D9 < 0) {
                D_0028E5D9 = D_0028E5D8_as_u8;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        D_0028E688 -= 1;
        if (D_0028E688 == 0) {
            reg_d0.w = 0;
            D_0028E690_as_u32 = reg_d0.w;
            D_0028E66C_as_u32 = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC03400;
            reg_d4.h[0] = 0x4009;
            func_001A7C60();
        }
    }
    func_001A6510();
}
