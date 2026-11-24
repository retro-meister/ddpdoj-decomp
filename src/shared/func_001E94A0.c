#include "common.h"


s32 func_001E9420();
extern u16 D_00264140[];
extern u32 D_0028D9CC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E94A0(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264140);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9CC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_001E9420();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C9)));
    (*(u8 *)((u8 *)(reg_a4) + (9))) -= reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C8)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1CA)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
}
