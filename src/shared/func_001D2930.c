#include "common.h"

typedef void (*Fn)();

s32 func_00124510();
s32 func_00124E80();
s32 func_00125410();
s32 func_00125440();
s32 func_0013A780();
s32 func_0013AAB0();
s32 func_0013B2E0();
s32 func_0018D500();
s32 func_0018D520();
s32 func_0018D560();
s32 func_0018D660();
s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();
extern u16 D_0026D810[];
extern u16 D_0026D8A0[];
extern s8 D_0028E408;
extern Reg32 D_0028E480;
extern void (*jtbl_0028E3F4)();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D2930(void) {
    u8 bits;

    if (*(u16 *)(reg_a4 + 2) != 4) goto next_s3;
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) != 0) goto next_s4rts;
    func_00124510();
    *(u16 *)reg_a4 = 0;
next_s4rts:
    return;
next_s3:
    if (*(u16 *)(reg_a4 + 2) != 3) goto next_s2;
    reg_d6.w = 0;
    reg_a1 = (u8 *) D_0026D810;
loop_10:
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if ((s16) reg_d0.h[0] == -1) goto next_20;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    func_002010A0();
    reg_d0.b[0] += 4;
    reg_d0.b[0] += reg_a4[0xD];
    reg_a0[0x1B] = reg_d0.b[0];
    func_002011A0();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x18) = reg_d6.h[0];
    reg_d6.h[0] += 1;
    goto loop_10;
next_20:
    *(u16 *)(reg_a4 + 4) = 0x80;
    *(u16 *)(reg_a4 + 2) = 4;
    func_0018D660();
    return;
next_s2:
    if (*(u16 *)(reg_a4 + 2) != 2) goto next_s1;
    func_00125440();
    if (D_0028E408 != 0) goto next_s1;
    reg_a0 = (u8 *) D_0026D8A0;
    func_0013B2E0();
    func_00124E80();
    *(u16 *)(reg_a4 + 0xA) = 1;
    *(u16 *)(reg_a4 + 2) = 3;
    return;
next_s1:
    if (*(u16 *)(reg_a4 + 2) != 1) goto next_s0;
    reg_tmp.b[0] = reg_a4[0x11];
    reg_a4[0x11] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_reon;
    reg_a4[0x11] = reg_a4[0x10];
    func_002011A0();
    reg_d1.b[0] = reg_d0.b[0];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d2.h[0] += reg_d0.h[0];
    D_0028E480.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = D_0028E480.h[1];
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d2.h[0] += reg_d0.h[0];
    reg_d2.h[0] -= 0x1000;
    D_0028E480.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = D_0028E480.h[1];
    reg_d3.h[0] = 8;
    reg_d0.h[0] = 0;
    func_0013AAB0();
    if (reg_a4[6] == 2) goto next_reon;
    func_0018D560();
next_reon:
    reg_tmp.b[0] = reg_a4[0xF];
    reg_a4[0xF] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec;
    reg_a4[0xF] = reg_a4[0xE];
    if (reg_a4[6] == 2) goto next_intdec;
    reg_a4[6] -= 1;
    reg_a4[0xD] += 1;
next_intdec:
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_s0;
    reg_a4[7] = reg_a4[6];
    if (reg_a4[6] == 2) goto next_intdec20;
    reg_tmp.b[0] = reg_a4[0x12];
    reg_a4[0x12] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_intdec20;
    reg_a4[0x12] = 4;
    func_0018D520();
next_intdec20:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a0 + 0x1E) = 8;
    func_002010A0();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 2;
    reg_d0.b[0] += 2;
    reg_d1.b[0] = reg_a4[0xD];
    reg_d1.b[0] = (s8) reg_d1.b[0] >> 1;
    reg_d0.b[0] += reg_d1.b[0];
    reg_a0[0x1B] = reg_d0.b[0];
    func_002011A0();
    reg_a0[0x1A] = reg_d0.b[0];
    *(u16 *)(reg_a4 + 8) += 8;
    if (*(u16 *)(reg_a4 + 8) != 0x80) goto next_s0;
    *(u16 *)(reg_a4 + 8) = 0;
    if (reg_a4[6] != 2) goto next_s0;
    reg_d0.h[0] = 0xA;
    func_00125410();
    *(u16 *)(reg_a4 + 2) = 2;
    return;
next_s0:
    if (*(u16 *)(reg_a4 + 2) != 0) goto block_rts;
    reg_tmp.b[0] = reg_a4[7];
    reg_a4[7] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    reg_a4[7] = reg_a4[6];
    bits = reg_a4[0x13];
    if (bits & 1) {
        reg_a4[0x13] = bits & 0xFE;
        goto next_40;
    }
    reg_a4[0x13] = bits | 1;
    reg_a0 = (u8 *) func_0018D500;
    func_002011A0();
    if (reg_d0.sb[0] >= 0) goto next_30;
    reg_a0 = (u8 *) func_0018D520;
next_30:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
next_40:
    reg_a1 = (u8 *) D_0026D810;
    reg_a1 += *(u16 *)(reg_a4 + 8);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_0013A780();
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0[0x1D] = reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x26) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 0x28) = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = *(u16 *)(reg_a6 + 2);
    *(u16 *)(reg_a0 + 4) = *(u16 *)(reg_a6 + 4);
    *(u16 *)(reg_a0 + 0x1E) = 8;
    *(u16 *)(reg_a0 + 0x12) = 0;
    *(u16 *)(reg_a0 + 0x14) = 0;
    *(u16 *)(reg_a4 + 8) += 8;
    if ((s32) *(u16 *)(reg_a4 + 8) < 0x80) goto block_rts;
    *(u16 *)(reg_a4 + 8) = 0;
    *(u16 *)(reg_a4 + 0xA) -= 1;
    if (*(u16 *)(reg_a4 + 0xA) != 0) goto block_rts;
    *(u16 *)(reg_a4 + 6) = 0x2010;
    *(u16 *)(reg_a4 + 0xE) = 0x1111;
    *(u16 *)(reg_a4 + 2) = 1;
block_rts:
    return;
}
