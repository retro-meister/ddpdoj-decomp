#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u16 D_00260330[];
extern u16 D_00260370[];
extern u16 D_002603B0[];
extern u16 D_00263370[];
extern u16 D_00263390[];
extern s16 D_0028E85C_as_s16;
extern s16 D_0028E884_as_s16;
extern u16 D_002BDA80_as_u16_a[];
extern u16 *reg_a0_as_u16_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D47C0(void) {
    reg_a0_as_u16_p = D_00263390;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_u16_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_00263370;
    reg_d0.h[0] = 0xE;
    func_0014E300();
    reg_tmp.w = 0xF0001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_a0_as_u16_p = D_002BDA80_as_u16_a;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 9;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = 0;
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = 0x12;
    D_0028E85C_as_s16 = 1;
    D_0028E884_as_s16 = 1;
    reg_a0_as_u16_p = D_00260330;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0_as_u16_p = D_00260370;
    func_001A3020();
    reg_d0.h[0] = 0xA;
    reg_a0_as_u16_p = D_002603B0;
    func_001A3020();
}
