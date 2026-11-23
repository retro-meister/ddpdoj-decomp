#include "common.h"

s32 func_001A5400();
s32 func_001A5460();
s32 func_001A5DD0();
s32 func_001A7520();
s32 func_001A7C60();
s32 func_001A80C0();
s32 func_001A8A40();
s32 func_001A8A60();
s32 func_001A8E00();
extern u16 D_0028E074;
extern u16 D_0028E3F0;
extern u8 D_0028E5DC;
extern u8 D_0028E5DD;
extern u16 D_0028E5FC;
extern u16 D_0028E614;
extern s8 D_0028E634;
extern u16 D_0028E69C;
extern u32 D_0028E6AC;
extern u16 D_0028E6B0;
extern u16 D_0028E6B4;
extern u16 D_0028E6B8;
extern u16 D_0028E6C8;
extern u32 D_0028E6D0;
extern u32 D_0028E6F0;
extern u32 D_0028E6FC;
extern u8 D_0028E70C;
extern u8 D_0028E854;
extern s16 D_0028E8C4;
extern u16 D_0029CD9E[];
extern u8 D_0029F261[];
void func_001A5B50(void) {
    if (D_0028E8C4 < 0) {
        func_001A5DD0();
        return;
    }
    func_001A80C0();
    if (!(D_0028E854 & 1) || (D_0028E634 < 0)) {
        if (D_0028E5FC != 0) {
            if (!(D_0028E70C & 1)) {
                D_0028E70C |= 1;
                func_001A5400();
                func_001A5460();
            }
            reg_d1.w = 0x64C00400;
            reg_d2.w = D_0028E6FC;
            func_001A8A40();
        } else {
            D_0028E70C &= 0xFE;
            if (D_0028E3F0 & 0x40) {
                if (!(D_0029F261[0] & 0x40) && (reg_d6.h[0] = D_0029CD9E[0], (D_0029CD9E[0] != 0))) {
                    reg_d0.w = 0x3F;
                    reg_d0.h[0] &= D_0028E3F0;
                    if ((s32) reg_d0.h[0] < 0x14) {
                        func_001A5400();
                        reg_d1.w = 0x64C00400;
                        reg_d2.w = D_0028E6F0;
                        func_001A8A40();
                    } else {
                        reg_d0.h[0] = 0xD4;
                        reg_d1.h[0] = 0x200;
                        reg_d5.h[0] = D_0028E074;
                        func_001A8A60();
                    }
                } else {
                    goto block_15;
                }
            } else {
block_15:
                reg_d0.h[0] = 0xD4;
                reg_d1.h[0] = 0x200;
                reg_d6.h[0] = D_0028E614;
                func_001A8E00();
            }
        }
    }
    if (D_0028E6B8 != 0) {
        D_0028E6B8 -= 1;
        reg_d1.h[0] = 0x40;
        reg_d6.w = 0;
        reg_d0.h[0] = D_0028E69C;
        reg_d6.h[0] = D_0028E6B0;
        D_0028E6B0 += 1;
        reg_d3.h[0] = D_0028E6B8;
        if ((s32) reg_d3.h[0] < 0x2A) {
            reg_d3.h[0] -= 0x2A;
            reg_d3.h[0] <<= 7;
            reg_d1.h[0] += reg_d3.h[0];
        }
        reg_d2.h[0] = D_0028E6B4;
        if (D_0028E6B4 != 0) {
            D_0028E6B4 -= 1;
        }
        reg_d4.h[0] = 7;
        func_001A7520();
    }
    reg_d6.h[0] = D_0028E6C8;
    if (D_0028E6C8 != 0) {
        if (D_0028E5FC != 0) {
            D_0028E5DD -= 1;
            if ((s8) D_0028E5DD < 0) {
                D_0028E5DD = D_0028E5DC;
                goto block_26;
            }
            goto block_29;
        }
block_26:
        D_0028E6C8 -= 1;
        if (D_0028E6C8 == 0) {
            reg_d0.w = 0;
            D_0028E6D0 = reg_d0.w;
            D_0028E6AC = reg_d0.w;
        } else {
block_29:
            reg_d1.w = 0x5BC00000;
            reg_d4.h[0] = 9;
            func_001A7C60();
        }
    }
    func_001A5DD0();
}
