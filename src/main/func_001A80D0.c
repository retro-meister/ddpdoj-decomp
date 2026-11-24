#include "common.h"

s32 func_001A53D0();
s32 func_001A53E0();
s32 func_001A53F0();
extern u8 D_0026BDE0[];
extern u8 D_0026BEA0[];
extern Reg32 D_0028E484;
extern u16 D_0028E5B0;
extern u16 D_0028E5B8;
extern u16 D_0028E5E4;
extern u16 D_0028E5F4;
extern u16 D_0028E5FC;
extern u16 D_0028E628;
extern u16 D_0028E62C;
extern s8 D_0028E634;
extern u8 D_0028E635;
extern u8 D_0028E854;
extern u8 D_0028E855;
extern u8 *reg_a0;

void func_001A80D0(void) {
    u32 t1;

    switch (D_0028E5FC) {
    case 0:
        goto next_0;
    }
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5F4;
    reg_d2.h[0] *= 0x16;
    reg_d2.h[1] = 0;
    reg_d2.h[0] /= 0x4B0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BDE0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d1.h[0] = 0x5EC0;
    D_0028E484.w = reg_d1.w;
    t1 = reg_d1.h[0];
    reg_d1.h[1] = t1;
    reg_d1.h[0] = 0x400;
    if (!(D_0028E854 & 1)) goto next_1;
    if (D_0028E634 < 0) goto next_1;
    if (D_0028E635 & 0x10) goto next_2;
    reg_d1.h[0] = 0x60C0;
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 7;
    reg_d1.h[0] += reg_d0.h[0];
    goto next_1;
next_2:
    if (D_0028E855 & 8) goto next_3;
    reg_d1.h[0] = 0x60C0;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    goto next_1;
next_3:
    reg_d0.h[0] = D_0028E62C;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] = t1 + reg_d0.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x400;
    reg_d0.h[0] = D_0028E628;
    reg_d0.h[0] <<= 6;
    reg_d1.h[0] -= reg_d0.h[0];
next_1:
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    func_001A53D0();
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d2.w = 0xCFF;
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    reg_d0.h[0] = D_0028E5B8;
    if (D_0028E5B8 == 0) goto next_4;
    reg_d0.h[0] -= 1;
loop_0:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
next_4:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E4;
    if (D_0028E5E4 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BEA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
    return;
next_0:
    reg_d1.h[0] = 0x5FC0;
    reg_d1.h[0] -= reg_d7.h[0];
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0x1000;
    reg_d1.h[0] += reg_d6.h[0];
    reg_d3.h[0] = 0x608;
    reg_d4.h[0] = 9;
    if (D_0028E5B0 == 0) goto next_5;
    reg_d0.h[0] = D_0028E5B8;
    if (D_0028E5B8 == 0) goto next_5;
    reg_d0.h[0] -= 1;
    reg_d2.w = 0xCFF;
loop_1:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_1;
next_5:
    reg_d2.w = 0;
    reg_d2.h[0] = D_0028E5E4;
    if (D_0028E5E4 == 0) return;
    reg_d2.h[0] <<= 4;
    reg_d2.h[0] /= 0x4B0;
    reg_a0 = (u8 *)D_0026BEA0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53E0();
}
