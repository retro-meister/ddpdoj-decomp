#include "common.h"

typedef void (*Fn)();

s32 func_0014DCA0();
extern u8 D_002589F0[];
extern u8 D_002589F4[];
extern u8 D_00258DF0[];
extern u8 D_00259A70[];
extern u8 D_00259A74[];
extern u8 D_00259E70[];
extern u16 D_0029C068[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014DDB0(void) {
    s8 temp_s0;
    s64 var_a0;

    reg_d7.w = 0;
    reg_d7.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xD)));
    var_a0 = 0;
    if ((s16)(reg_d7.h[0]) >= 0x80) {
        var_a0 = 1;
        reg_d7.h[0] -= 0x80;
    }
    temp_s0 = var_a0;
    if (temp_s0 == 0) {
        ((Fn)*(u32 *)((u8 *)D_00258DF0 + (reg_d7.h[0] * 4)))();
    } else {
        ((Fn)*(u32 *)((u8 *)D_00259E70 + (reg_d7.h[0] * 4)))();
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
    if (func_0014DCA0() == 0) {
        reg_tmp.w = (u32)reg_a6;
        (*(u16 *)((u8 *)(reg_a5) + (6))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[0];
        reg_d7.h[0] *= 2;
        if (temp_s0 == 0) {
            reg_tmp.w = *(u32 *)(D_002589F4 + (reg_d7.h[0] * 4));
        } else {
            reg_tmp.w = *(u32 *)(D_00259A74 + (reg_d7.h[0] * 4));
        }
        (*(u16 *)((u8 *)(reg_a5) + (0x4C))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x4E))) = (u16) reg_tmp.h[0];
        reg_a0 = (u8 *)D_0029F260_as_u8_a;
        reg_d0.w = 0;
        if ((*(u8 *)((u8 *)(reg_a5) + (0))) & 1) {
            reg_a0 = (u8 *)D_0029F1F0_as_u8_a;
            reg_d0.w = 1;
        }
        (*(u8 *)((u8 *)(reg_a5) + (2))) = (u8) reg_d0.b[0];
        (*(s16 *)((u8 *)(reg_a5) + (0x3E))) = 0;
        if (temp_s0 == 0) {
            ((Fn)*(u32 *)((u8 *)D_002589F0 + (reg_d7.h[0] * 4)))();
        } else {
            ((Fn)*(u32 *)((u8 *)D_00259A70 + (reg_d7.h[0] * 4)))();
        }
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0xC)));
        if (reg_d0.b[0] & 1) {
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
            reg_d0.h[0] = D_0029C068[0];
            reg_a6 = (u8 *)reg_tmp.w;
            (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
        reg_d0.h[0] += 1;
        return;
    }
    (*(u16 *)((u8 *)(reg_a5) + (0))) = 0;
}
