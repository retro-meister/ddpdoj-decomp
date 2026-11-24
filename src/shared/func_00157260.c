#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_001293C0();
s32 func_00129410();
s32 func_0013A780();
s32 func_0014E290();
s32 func_00157740();
s32 func_0018D540();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_00201C60();
s32 func_00202490();
s32 func_00203060();
extern u8 D_00259970[];
extern u16 D_0028E8A0;
extern u16 D_0028E8D0;
extern u16 D_0028E91C;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00157260(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a1;
    u16 temp_v1;

    func_00203060();
    if (D_0028E408 != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_4;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_4:
    func_00201C60();
    temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    if ((temp_v1 != 0) && (D_0028E8A0 == 0)) {
        (*(u16 *)((u8 *)(reg_a5) + (0x1C))) = (u16) (temp_v1 - 1);
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            func_00202490();
        }
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    reg_d1.b[0] |= (*(u8 *)((u8 *)(reg_a6) + (0x21)));
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x21))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        reg_d2.w = 0x7FFF;
        reg_d2.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x18)));
        reg_d3.w = 0x7FFF;
        reg_d3.h[0] -= (*(u16 *)((u8 *)(reg_a6) + (0x38)));
        if ((s32) reg_d2.w < (s32) reg_d3.w) {
            reg_d2.w = reg_d3.w;
        }
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_tmp.w -= reg_d2.w;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) reg_tmp.h[1];
        temp_a0 = reg_tmp.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = temp_a0;
        reg_d0.h[0] = 0x7FFF;
        (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x38))) = (u16) reg_d0.h[0];
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        if ((s32) reg_tmp.w < 0) {
            reg_d0.w = 0x19;
            func_001A91A0();
            reg_d0.h[0] = 0x82;
            func_0013A780();
            (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            (*(u16 *)((u8 *)(reg_a0) + (4))) = temp_a0_2;
            (*(s16 *)((u8 *)(reg_a0) + (0x1E))) = 0x10;
            (*(s16 *)((u8 *)(reg_a0) + (0x12))) = 0;
            (*(s16 *)((u8 *)(reg_a0) + (0x14))) = 0;
            (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
            reg_d0.b[0] *= 4;
            (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d0.b[0];
            func_0018D540();
            func_0014E290();
            return;
        }
        goto block_14;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_14:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        reg_d0.h[0] = 0x30;
        reg_d0.h[0] -= D_0028E8D0;
        reg_d0.h[0] += 0xA;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x22)));
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) >= 0x2800) {
            reg_d1.w = 0;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x16)));
            reg_d1.b[0] *= 4;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a1;
            reg_a0 = (u8 *)D_00259970;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            (*(u8 *)((u8 *)(reg_a5) + (0x23))) -= 1;
            if (D_0028E91C != 4) {
                reg_d0.w = 0x2000C;
                func_001293C0();
                reg_d1.b[0] += 8;
                func_00129280();
                reg_d1.b[0] -= 0x10;
                func_00129280();
            } else {
                reg_d0.w = 0x6000C;
                reg_d7.h[0] = reg_d1.h[0];
                func_00129410();
                reg_d1.b[0] += 8;
                func_00129410();
                reg_d1.b[0] -= 0x10;
                func_00129410();
                reg_d0.w = 0x4000D;
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] += 4;
                func_00129410();
                reg_d1.h[0] = reg_d7.h[0];
                reg_d1.b[0] -= 4;
                func_00129410();
            }
        }
    }
    func_00157740();
}
