#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_002010A0();
s32 func_002011A0();
s32 func_00201230();
s32 func_00201270();
s32 func_002013F0();
extern u16 D_00263EA0[];
extern u16 D_00263EB8[];
extern u16 D_00263ED0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E3FC0(void) {
    reg_a0 = (u8 *)(D_00263ED0);
    func_0014E370();
    reg_a0 = (u8 *)(D_00263EB8);
    reg_d0.w = 6;
    func_0014E300();
    reg_tmp.w = 0x1C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    func_002013F0();
    (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_d0.h[0];
    func_002010A0();
    reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
    reg_d0.b[0] += 0x70;
    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) reg_d0.b[0];
    func_002011A0();
    reg_d0.h[0] &= 0x7F;
    reg_d0.b[0] += 0x40;
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d0.b[0];
    func_00201230();
    reg_a0 = (u8 *)(D_00263EA0);
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) *(u16 *)reg_a0;
    reg_d0.w = 0;
    reg_a0 += 2;
    func_00201270();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
    reg_tmp.w += reg_d0.w;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
}
