#include "common.h"

s32 func_0011C4A0();
s32 func_0018DD00();
s32 func_001A3020();
s32 func_001A53D0();
s32 func_001A5960();
s32 func_001A59B0();
s32 func_001A6510();
s32 func_001A6650();
s32 func_001A6B70();
s32 func_001A6BE0();
s32 func_001A6C60();
s32 func_001AC8C0();
s32 func_001AC8E0();
extern u8 D_00261C30[];
extern u8 D_00261C70[];
extern u32 D_0028E46C_as_u32;
extern Reg32 D_0028E484;
extern u8 D_0028E61D;
extern u8 *D_0028E620;
extern u32 D_0028E624_as_u32;
extern u16 D_0028E628;
extern u16 D_0028E62C;
extern u16 D_0028E630;
extern u8 D_0028E635;
extern u8 D_0028E855;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u16 D_0029CEA0[];
extern u8 *reg_a0;

void func_001A6050(void) {
    s32 flag;
    s32 bits;

    if (D_0028E855 & 8) {
        func_001A6650();
        return;
    }
    flag = D_0028E635;
    if ((s8) flag < 0) goto next_160;
    bits = flag & 0xFF;
    if (bits & 0x10) goto next_120;
    if (bits & 8) goto next_80;
    if (bits & 1) goto next_40;
    D_0028E635 = flag | 1;
    D_0028E630 = 0x32;
    D_0028E628 = 8;
    D_0028E62C = 8;
    if (!(D_0028E635 & 2)) {
        D_0028E635 |= 2;
        goto next_20;
    }
    if (!(D_0028E635 & 4)) {
        D_0028E635 |= 4;
        goto next_20;
    }
    func_001AC8C0();
    func_001AC8E0();
    reg_a0 = (u8 *)D_00261C30;
    reg_d0.h[0] = 7;
    func_001A3020();
    reg_a0 = (u8 *)D_00261C70;
    reg_d0.h[0] = 8;
    func_001A3020();
    goto next_40;
next_20:
    D_0028E635 &= 0xFE;
next_40:
    reg_d1.h[0] = 0x5BC0;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d3.h[0] = 0x840;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] -= 0x32;
    reg_d6.h[0] <<= 7;
    func_001A6B70();
    func_001A6BE0();
    func_001A6C60();
    D_0028E630 -= 1;
    if (D_0028E630 != 0x11) {
        func_001A6510();
        return;
    }
    D_0028E635 |= 8;
    D_0028E630 = 0x38;
    func_001A6510();
    return;
next_80:
    reg_d1.h[0] = 0x67C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_tmp.h[0] = D_0028E630;
    D_0028E630 -= 1;
    if (reg_tmp.h[0] == 0) goto next_100;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] += reg_d6.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    func_001A53D0();
    reg_d7.h[0] = 0xE00;
    reg_d7.h[0] -= reg_d6.h[0];
    func_001A5960();
    func_001A59B0();
    func_001A6C60();
    func_001A6510();
    return;
next_100:
    D_0028E635 = flag | 0x10;
    func_001A6C60();
    D_0028E630 = 0xFFE2;
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 1;
    reg_d3.w = 0x1B;
    reg_d4.w = 0x03B6000A;
    func_0011C4A0();
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    func_001A6510();
    return;
next_120:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
    D_0028E630 += 1;
    if ((s16) D_0028E630 < 0) {
        func_001A6510();
        return;
    }
    reg_d1.w = 0x67C00000;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
loop_140:
    reg_d3.h[0] += 2;
    if ((s16) --reg_d6.h[0] >= 0) goto loop_140;
    if (D_0028E630 != 0x6F) goto next_280;
    D_0028E635 |= 0x80;
    goto next_180;
next_160:
    reg_d7.h[0] = 0xE00;
    func_001A5960();
    func_001A59B0();
next_180:
    reg_a0 = (u8 *)D_0028E620;
    reg_d7.h[1] = *(u16 *) (reg_a0 + 0);
    reg_d7.h[0] = *(u16 *) (reg_a0 + 2);
    if ((s32) reg_d7.w < 0) {
        func_001A6510();
        return;
    }
    reg_d4.h[0] = 9;
    if ((u32) reg_d7.w > 0x6FB8U) goto next_240;
    if (D_0028E910 == 0) goto next_200;
    if (D_0028E91C == 4) goto next_240;
next_200:
    reg_d4.h[0] = 0x19;
    reg_d2.h[0] = D_0029CEA0[0];
    if ((s16) reg_d2.h[0] >= 0) goto next_220;
    if (reg_d2.w & 1) goto next_240;
next_220:
    if (D_0028E61D & 1) goto next_240;
    D_0028E61D |= 1;
    func_0018DD00();
next_240:
    reg_d1.w = 0x67C001C0;
    reg_d2.w = 0xCA1;
    reg_d3.h[0] = 0x200;
    reg_d0.w = D_0028E624_as_u32;
loop_260:
    D_0028E46C_as_u32 = reg_d7.w;
    reg_d7.w -= reg_d0.w;
    if ((u32) reg_d0.w <= (u32) D_0028E46C_as_u32) {
        reg_d3.h[0] += 1;
        goto loop_260;
    }
next_280:
    if (reg_d3.h[0] == 0x200) {
        func_001A6510();
        return;
    }
    func_001A53D0();
    func_001A6510();
}
