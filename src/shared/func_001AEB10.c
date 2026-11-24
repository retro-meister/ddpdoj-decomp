#include "common.h"

extern s8 D_0028E408;

s32 func_0018D9B0();
s32 func_001AAC00();
s32 func_001AC3A0();
s32 func_001AC5F0();
s32 func_001AE9A0();
s32 func_001AED30();
s32 func_001AED60();
extern u8 D_0028E304;
extern u16 D_0028E710;
extern s32 D_0028E714;
extern u16 D_0028E74C;
extern u16 D_0028E754;
extern u32 D_0028E760_as_u32;
extern u8 D_0028ED80;
extern u16 D_006E5C06[];
#ifdef DEATH_LABEL
extern u8 death_D_00290DBC;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u16 death_D_0068DAA6[];
extern u16 death_D_0068DAA8[];
extern u16 death_D_0068DAB0[];
extern u16 death_D_0068DAB2[];
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u32 D_0028ED50_as_u32;
extern u16 D_0028ED4C;
extern u32 D_0028ED44_as_u32;
extern u16 D_0028ED40;
extern u32 D_0028E768;
extern u16 D_0028E75C;
extern u32 D_0028E764;
extern u16 D_0028E758;
#endif
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_001AEB10(void) {
    u16 t1;
    u16 t2;
    u32 *t3;

#ifdef DEATH_LABEL
    if (death_D_00290DBC != 0) {
        if (D_0029F260[0] < 0) {
            death_D_0068DAA8[0] = 0;
            D_002BAF30[0] = 1;
            death_D_0068DAA6[0] = 0xC030;
            D_0028E768 = D_0028ED50_as_u32;
            D_0028E75C = D_0028ED4C;
        }
        if (D_0029F1F0[0] < 0) {
            death_D_0068DAB2[0] = 0;
            D_002BAF3A[0] = 1;
            death_D_0068DAB0[0] = 0xC030;
            D_0028E764 = D_0028ED44_as_u32;
            D_0028E758 = D_0028ED40;
        }
        D_0028E710 = 0;
        D_0028E714 = 0;
        goto no_extend;
    }
#endif
    t3 = (u32 *)(reg_a1);
    reg_a1 = (u8 *)t3 + 4;
    switch (*(u32 *)t3) {
    case 0:
        break;
    default:
        if (*(s16 *)reg_a3 < 0) {
            reg_d6.w = 0;
            *(u32 *)(reg_a1 - 4) = (u32) reg_d6.w;
            return;
        }
        D_0028E714 = *(s32 *)(reg_a0 - 4);
        D_0028E710 = *(u16 *)reg_a6;
        reg_a0 -= 4;
        reg_a1 -= 4;
        D_0028E408 = 0;
        reg_d6.h[0] = 0;
        if (func_001AE9A0(reg_a1, reg_a0) != 0) {
            *(u16 *)reg_a6 += 1;
            if (*(u16 *)reg_a6 == 0xA) {
                *(u32 *)reg_a0 = 0x99999999U;
                *(u16 *)reg_a6 = 9;
            }
        } else {
#ifdef DEATH_LABEL
no_extend:
#endif
            reg_d0.w = *(u32 *)reg_a2;
            if (((D_0028ED80 == 0) || (D_006E5C06[0] != 0x14)) && (D_0028E304 == 0) && (reg_d0.w != -1U) && ((u32) *(u32 *)reg_a0 >= (u32) reg_d0.w)) {
                t2 = (u16) *(s16 *)reg_a3;
                if (t2 != 0x14) {
                    *(s16 *)reg_a3 = t2 + 1;
                    func_001AAC00();
                    func_0018D9B0();
                    if (reg_d7.h[0] == 0) {
                        func_001AC3A0();
                    } else {
                        func_001AC5F0();
                    }
                }
            }
        }
        reg_d6.w = 0;
        *(u32 *)reg_a1 = reg_d6.w;
        reg_a1 += 4;
        if (reg_d7.h[0] == 0) {
            func_001AED30();
        } else {
            func_001AED60();
        }
        reg_d0.h[0] = D_0028E754;
        t1 = *(u16 *)reg_a6;
        if ((s32) t1 >= (s32) reg_d0.h[0]) {
            if (t1 != reg_d0.h[0]) {
                D_0028E754 = t1;
                goto next_1;
            }
            reg_d0.w = D_0028E760_as_u32;
            if ((u32) reg_d4.w > (u32) reg_d0.w) {
next_1:
                D_0028E760_as_u32 = reg_d4.w;
                D_0028E74C = reg_d6.h[0];
            }
        }
    }
}
