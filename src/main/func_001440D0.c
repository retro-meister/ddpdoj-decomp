#include "common.h"

s32 func_00125E40();
s32 func_00125E60();
s32 func_00138A00();
s32 func_0013C9A0();
s32 func_0013CAB0();
s32 func_0013E8E0();
s32 func_0013E970();
s32 func_0013EBD0();
s32 func_0013FCA0();
s32 func_0013FCE0();
s32 func_0016A9B0();
s32 func_0018D6D0();
s32 func_001A7E90();
s32 func_001A8070();
s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001ABF90();
s32 func_001AC160();
s32 func_001ACB00();
s32 func_001ACB50();
s32 func_00217BB0();
s32 func_00217C20();
extern u8 D_00255EE0[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u16 D_0028E020;
extern u16 D_0028E024;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u16 D_0028E030;
extern u16 D_0028E034;
extern s16 D_0028E038;
extern s16 D_0028E03C;
extern s16 D_0028E040;
extern s16 D_0028E044;
extern s16 D_0028E060;
extern s16 D_0028E064;
extern s16 D_0028E068;
extern s16 D_0028E06C;
extern s16 D_0028E070;
extern s16 D_0028E074;
extern s16 D_0028E3A0;
extern u16 D_0028E46C;
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;
extern u8 D_0028ED80;
extern s16 D_0068DEDE[];
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001440D0(void) {
    u32 tmp;
    u16 t1;
    u16 t2;
    u32 saved1;
    u32 saved2;

    func_00138A00();
    if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x40)) {
        func_0013EBD0();
    }
    func_0018D6D0();
    D_0028E3A0 = 1;
    if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
        func_00217BB0(0xC8, 0x28);
        func_0013C9A0();
        D_0028E044 = 1;
        D_0028E03C = 1;
        D_0028E024 += 2;
        func_00125E40();
        func_001ACB00();
        func_001ABF90();
        D_0028E074 = 0;
        D_0028E06C = 8;
        D_0028E068 = 8;
        D_0028DFB8 = D_0028E5FC;
        func_001A7E90();
        reg_d0.h[0] = D_0028E5EC;
        reg_d0.h[0] >>= 2;
        t1 = reg_d0.h[0];
        reg_d0.h[0] = D_0028E5C0;
        D_0028E5EC = t1;
        if (reg_d0.h[0] != 0) {
            D_0028E5C0 = 0;
            func_001AA8F0();
        }
        reg_d1.h[0] = D_0028E8C4;
        if (reg_d1.h[0] == 0) {
            func_0013FCA0();
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 2;
        saved1 = reg_d1.w;
        func_0013E8E0();
        reg_d1.w = saved1;
        reg_a1 = (u8 *) &D_0028E034;
        reg_a3 = (u8 *) &D_0028E02C;
    } else {
        func_00217C20(0xC8, 0x28);
        func_0013CAB0();
        D_0028E040 = 1;
        D_0028E038 = 1;
        D_0028E020 += 2;
        func_00125E60();
        func_001ACB50();
        func_001AC160();
        D_0028E070 = 0;
        D_0028E064 = 8;
        D_0028E060 = 8;
        D_0028DFB4 = D_0028E5F8;
        func_001A8070();
        reg_d0.h[0] = D_0028E5E8;
        reg_d0.h[0] >>= 2;
        t2 = reg_d0.h[0];
        reg_d0.h[0] = D_0028E5BC;
        D_0028E5E8 = t2;
        if (reg_d0.h[0] != 0) {
            D_0028E5BC = 0;
            func_001AAA20();
        }
        reg_d1.h[0] = D_0028E8C0;
        if (reg_d1.h[0] == 0) {
            func_0013FCE0();
        }
        (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 3;
        saved2 = reg_d1.w;
        func_0013E970();
        reg_d1.w = saved2;
        reg_a1 = (u8 *) &D_0028E030;
        reg_a3 = (u8 *) &D_0028E028;
    }
    if (D_0028ED80 != 0) goto next_1;
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] == 0) goto loop_1;
    reg_d0.w = 0;
    reg_d7.w = 2;
    if (*(u16 *) reg_a1 != 0) goto loop_1;
    goto next_3;
next_1:
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] != 0) goto next_2;
    if (D_0068DEDE[0] != 0x14) goto loop_1;
next_2:
    reg_d0.w = 0;
    reg_d7.w = 2;
next_3:
    reg_d7.h[0] = *(u16 *) reg_a3;
    *(u16 *) reg_a3 += 1;
    D_0028E46C = reg_d7.h[0];
    reg_d7.h[0] -= 1;
    if (D_0028E46C == 0) goto next_4;
loop_1:
    func_0016A9B0();
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_4:
    (*(u16 *)((u8 *)(reg_a6) + (0))) &= 0x2000;
    (*(u8 *)((u8 *)(reg_a6) + (1))) |= 1;
    reg_tmp.w = (u32) D_00255EE0;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 6;
}
