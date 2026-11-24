#include "common.h"

s32 func_0019E5B0();
s32 func_0019F410();
s32 func_001A1510();
s32 func_001A2680();
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001A1040(void) {
    u32 t;
    u8 *p0;

    if (*(u8 *)(reg_a6 + 1) & 4) {
        func_001A2680();
        reg_a6 += 0x20;
        func_001A2680();
        reg_a6 -= 0x20;
        func_0019F410();
    } else {
        reg_d3.w = 0;
        if (*(u8 *)(reg_a6 + 1) & 8) {
            reg_d3.w = 3;
        }
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
loop_5:
        reg_d0.b[0] += 1;
        reg_d0.b[0] &= 0x3F;
        if (reg_d0.b[0] == 0x10) goto next_6;
        if (reg_d0.b[0] == 0x30) goto next_6;
        t = reg_d3.h[0] - 1;
        reg_d3.h[0] = t;
        if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
next_6:
        *(u8 *)(reg_a6 + 0x14) = (u8) reg_d0.b[0];
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        *(u8 *)(reg_a6 + 0x34) = (u8) reg_d1.b[0];
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x46);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x48);
        reg_a2 = (u8 *)reg_tmp.w;
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x14);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x58);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_a3 = (u8 *)reg_tmp.w;
        func_001A1510();
        *(u16 *)(reg_a6 + 0x5C) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x5E) = (u16) reg_d6.h[0];
        p0 = (u8 *)(reg_a6);
        reg_d1.b[0] = *(u8 *)(p0 + 0x34);
        reg_tmp.h[1] = *(u16 *)(p0 + 0x58);
        reg_tmp.h[0] = *(u16 *)(p0 + 0x5A);
        reg_a6 = p0 + 0x20;
        reg_a3 = (u8 *)reg_tmp.w;
        func_001A1510();
        reg_a6 -= 0x20;
        *(u16 *)(reg_a6 + 0x60) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x62) = (u16) reg_d6.h[0];
    }
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            *(u8 *)reg_a6 |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_19;
        }
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_19;
    }
    *(u8 *)reg_a6 &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            *(u8 *)reg_a6 |= 0x10;
block_19:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_22;
                }
            } else {
block_22:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            func_0019E5B0();
        }
    }
}
