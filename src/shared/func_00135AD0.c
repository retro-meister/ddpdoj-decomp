#include "common.h"

s32 func_00135120();
s32 func_001A33C0();
s32 func_001A35F0();
s32 func_001AAB50();
s32 func_001AAB70();
s32 func_002071C0();
extern u16 D_0024F3A8[];
extern u8 D_0028E384;
extern u16 D_0028E910;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 D_0028ED80;
extern u16 D_006E5C06[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00135AD0(void) {
    u16 temp_a0;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d0.b[0] = D_0028E384;
    reg_a1 = (u8 *)(D_0024F3A8);
    reg_tmp.h[0] = temp_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    if (D_0028E910 != 0) {
        (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
    }
    if (D_0028ED80 == 1) {
        if (D_006E5C06[0] == 0x14) {
            (*(u16 *)((u8 *)(reg_a0) + (0))) = 0U;
        } else {
            (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) D_006E5C06[0];
        }
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x14)));
    func_002071C0();
    (*(u16 *)((u8 *)(reg_a6) + (0x18))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) reg_d0.h[0];
    (*(u8 *)((u8 *)(reg_a0) + (7))) = (u8) D_0028E910;
    (*(u8 *)((u8 *)(reg_a0) + (6))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x16)));
    (*(u16 *)((u8 *)(reg_a0) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x10)));
    (*(u16 *)((u8 *)(reg_a0) + (0xA))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x12)));
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x16)));
    if (reg_d0.h[0] == 0) {
        reg_d1.h[0] = D_0028E938;
        func_001A33C0();
        if (D_0028E910 == 0) {
            func_001AAB50();
        }
    } else {
        reg_d1.h[0] = D_0028E934;
        func_001A33C0();
        if (D_0028E910 == 0) {
            func_001AAB70();
        }
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x16)));
    func_001A35F0();
    (*(s16 *)((u8 *)(reg_a6) + (0))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (2))) = 0;
    func_00135120();
}
