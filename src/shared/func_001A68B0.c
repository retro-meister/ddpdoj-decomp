#include "common.h"

s32 func_001A5400();
s32 func_001A5430();
s32 func_001A54C0();
s32 func_001A5600();
s32 func_001A5740();
s32 func_001A5850();
s32 func_001A5AD0();
s32 func_001A6B70();
s32 func_001A6BE0();
s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001AC3A0();
s32 func_001AC5F0();
s32 func_001AC950();
s32 func_001AC9D0();
extern Reg32 D_0028E46C;
extern s16 D_0028E59C;
extern u16 D_0028E630;
extern u8 D_0028E854;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;

void func_001A68B0(void) {
    if (!(D_0028E854 & 1)) goto next_2;
    if ((s16)D_0028E8C4 < 0) goto next_0;
    func_001AA8F0();
    func_001AC3A0();
next_0:
    if ((s16)D_0028E8C0 < 0) goto next_1;
    func_001AAA20();
    func_001AC5F0();
next_1:
    D_0028E59C = 0;
    func_001A5AD0();
    return;
next_2:
    if (D_0028E630 == 0) goto next_7;
    D_0028E630 -= 1;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
    reg_d0.h[0] = D_0028E8C4;
    if ((s16)D_0028E8C4 < 0) goto next_4;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_3;
    if (reg_d0.h[0] <= 5) goto next_3;
    reg_d0.w = 5;
next_3:
    reg_d1.w = 0x5DC00500;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    func_001A54C0();
    func_001A6B70();
next_4:
    reg_d0.h[0] = D_0028E8C0;
    if ((s16)D_0028E8C0 < 0) goto next_6;
    reg_tmp.w = reg_d0.h[0];
    reg_tmp.w -= 1;
    reg_d0.h[0] = reg_tmp.h[0];
    if (reg_tmp.h[1] != 0) goto next_5;
    if (reg_d0.h[0] <= 5) goto next_5;
    reg_d0.w = 5;
next_5:
    reg_d1.w = 0x5DC03300;
    reg_d1.h[0] -= reg_d6.h[0];
    reg_d3.h[0] = 0x208;
    func_001A5600();
    func_001A6BE0();
next_6:
    return;
next_7:
    reg_d7.h[0] = D_0028E8C4;
    if ((s16)D_0028E8C4 < 0) goto next_10;
    D_0028E46C.w = reg_d7.h[0];
    D_0028E46C.w -= 1;
    reg_d7.h[0] = D_0028E46C.h[0];
    if (D_0028E46C.h[1] != 0) goto next_9;
    if (reg_d7.h[0] <= 5) goto next_8;
    reg_d7.w = 5;
next_8:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x200;
    func_001A5740();
next_9:
    func_001AA8F0();
    func_001AC950();
    func_001A5400();
next_10:
    reg_d7.h[0] = D_0028E8C0;
    if ((s16)D_0028E8C0 < 0) goto next_13;
    D_0028E46C.w = reg_d7.h[0];
    D_0028E46C.w -= 1;
    reg_d7.h[0] = D_0028E46C.h[0];
    if (D_0028E46C.h[1] != 0) goto next_12;
    if (reg_d7.h[0] <= 5) goto next_11;
    reg_d7.w = 5;
next_11:
    reg_d0.h[0] = 0xBC;
    reg_d1.h[0] = 0x1900;
    func_001A5850();
next_12:
    func_001AAA20();
    func_001AC9D0();
    func_001A5430();
next_13:
    D_0028E59C = 0;
}
