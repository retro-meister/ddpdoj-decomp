#include "common.h"

s32 func_0011BEA0();
s32 func_0012FAB0();
s32 func_00137910();
s32 func_00168BA0();
s32 func_001A2FA0();
extern u8 D_00269140[];
extern u8 D_0026A880[];
extern u8 D_0028DF84_as_u8;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001694F0() {
    u16 temp_v1;
    u16 temp_v1_2;

    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        D_0028DF84_as_u8 = 0;
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        func_0012FAB0();
        reg_d0.w = 0;
        reg_a0 = D_00269140;
        func_001A2FA0();
        (*(u16 *)((u8 *)(reg_a5) + (6))) = 0U;
        (*(u16 *)((u8 *)(reg_a5) + (8))) = 0xB8U;
        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = 1U;
        (*(u16 *)((u8 *)(reg_a5) + (4))) = 0x12CU;
        func_0011BEA0();
        return;
    }
    if (((*(u16 *)((u8 *)(reg_a5) + (6))) != 0x1C0) && ((temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0xA))), (temp_v1 == 0)) || ((*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) (temp_v1 - 1), ((*(u16 *)((u8 *)(reg_a5) + (0xA))) == 0)))) {
        reg_a0 = D_0026A880;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (6)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_d1.h[0] = 0;
        reg_d2.h[0] = 0;
        func_00137910();
        (*(u16 *)((u8 *)(reg_a5) + (8))) -= 0xC;
        (*(u16 *)((u8 *)(reg_a5) + (6))) += 0x20;
    }
    temp_v1_2 = (*(u16 *)((u8 *)(reg_a5) + (4)));
    if (temp_v1_2 != 0) {
        (*(u16 *)((u8 *)(reg_a5) + (4))) = (u16) (temp_v1_2 - 1);
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
        if ((*(u16 *)((u8 *)(reg_a5) + (4))) == 0) {
            reg_d0.h[0] = 2;
            func_00168BA0();
            func_0012FAB0();
        }
    }
}
