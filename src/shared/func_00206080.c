#include "common.h"

s32 func_0019C5B0();
s32 func_0019C840();
extern u8 D_00252350[];
extern u8 D_00252380[];
extern u8 D_002523B0[];
extern u16 D_0028E3EC;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00206080(void) {
    reg_a0 = (u8 *)D_00252350;
    reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x38)));
    if (reg_d7.h[0] != 0) goto next_0;
    reg_a0 = (u8 *)D_00252380;
    reg_d5.h[0] *= 0xFFFF;
next_0:
    if ((*(u8 *)((u8 *)(reg_a6) + (0))) < 7) goto next_1;
    reg_a0 += 0x18;
    goto next_2;
next_1:
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if (D_0028E3EC == 0) goto next_3;
    reg_d2.w = 0xA9D;
    if ((*(u8 *)((u8 *)(reg_a6) + (0))) != 4) goto next_4;
    reg_d2.w = 0xA9E;
next_4:
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
next_3:
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x2C))) == 0) goto next_5;
    reg_a1 = (u8 *)D_002523B0;
    reg_a1 += (*(u16 *)((u8 *)(reg_a6) + (0x66)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
    reg_d3.h[0] = 0xE20;
    reg_d4.h[0] = 0x17;
    (*(u16 *)((u8 *)(reg_a6) + (0x66))) += 4;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x66))) != 0x30) goto next_6;
    (*(u16 *)((u8 *)(reg_a6) + (0x66))) = 0;
next_6:
    if (reg_d7.h[0] != 0) goto next_7;
    reg_d4.h[0] |= 0x60;
next_7:
    func_0019C5B0();
next_5:
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (6)));
    reg_d3.h[0] = 0x630;
    reg_d4.h[0] = 0x12;
    if ((*(u8 *)((u8 *)(reg_a6) + (0))) != 1) goto next_8;
    if ((*(u16 *)((u8 *)(reg_a6) + (2))) == 0) goto next_9;
next_8:
    func_0019C5B0();
next_9:
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (8)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0xC)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xE)));
    if ((*(u8 *)((u8 *)(reg_a6) + (0))) != 1) goto next_10;
    if ((*(u16 *)((u8 *)(reg_a6) + (2))) == 1) goto next_11;
next_10:
    func_0019C5B0();
next_11:
    reg_a0 += 0x10;
next_2:
    if (D_0028E910 != 0) return;
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = 0x218;
    reg_d4.h[0] = 0x12;
    func_0019C5B0();
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_d0.h[0] &= 0xF0;
    reg_d0.h[0] >>= 4;
    reg_d2.w += reg_d0.w;
    reg_d3.h[0] = 0x818;
    reg_d4.h[0] = 0x12;
    reg_d6.w = 0x80005000;
    func_0019C840();
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (-4)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (-2)));
    reg_d1.h[0] -= 0x3C0;
    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_d0.h[0] &= 0xF00;
    reg_d0.h[0] >>= 8;
    reg_d2.w += reg_d0.w;
    reg_d6.w = 0x80005000;
    func_0019C840();
    reg_d1.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] += reg_d5.h[0];
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= (*(u16 *)((u8 *)(reg_a6) + (0x2E)));
    reg_d2.w += reg_d0.w;
    reg_d3.h[0] = 0x610;
    reg_d4.h[0] = 0x12;
    reg_d6.w = 0x80005000;
    func_0019C840();
}
