#include "common.h"

s32 func_0014E370();
extern u8 D_0025F690[];
extern u8 D_0028E489;
extern s8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001A4FB0(void) {
    s8 temp_a1;
    s8 temp_a3;
    u32 temp_a2;

    reg_a0 = (s8 *)D_0025F690;
    func_0014E370();
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x12)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x14)));
    reg_a0 = (s8 *) reg_tmp.w;
    D_0028E489 = *reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[0];
    D_0028E489 = *reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = 0xFF;
    temp_a2 = reg_d0.h[0];
    reg_d1.h[0] = temp_a2;
    reg_d2.h[0] = temp_a2;
    temp_a1 = *reg_a0;
    reg_a0 += 1;
    D_0028E489 = temp_a1;
    reg_tmp.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    if (reg_d0.h[0] == 2) {
        (*(s16 *)((u8 *)(reg_a6) + (8))) = 1;
        reg_d0.h[0] = 0xFF;
        D_0028E489 = *reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = (u8) *reg_a0;
        reg_a0 += 1;
        reg_d0.h[0] = temp_a2 & reg_tmp.h[0];
    }
    D_0028E489 = *reg_a0;
    reg_a0 += 1;
    reg_tmp.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= reg_tmp.h[0];
    temp_a3 = *reg_a0;
    reg_a0 += 1;
    D_0028E489 = temp_a3;
    reg_tmp.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= reg_tmp.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = (u16) reg_d2.h[0];
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x12))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x14))) = (u16) reg_tmp.h[0];
}
