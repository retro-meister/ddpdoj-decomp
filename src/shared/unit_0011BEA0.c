#include "common.h"

void func_0011C230(void);
void func_0011C240(void);

s32 func_0011C920();                            /* extern */
extern s32 D_0028E0D8_as_s32_a[];
extern s32 D_0028E0DC_as_s32_a[];
extern s16 D_0028E0E0_as_s16_a[];
extern s16 D_0028E0E2_as_s16_a[];
extern s32 D_0028E0E8[];
extern s32 D_0028E0EC[];
extern s32 D_0028E0F8_as_s32_a[];
extern s32 D_0028E0FC_as_s32_a[];
extern s16 D_0028E100_as_s16_a[];
extern s16 D_0028E102_as_s16_a[];
extern s32 D_0028E108[];
extern s32 D_0028E10C[];

void func_0011BEA0(void) {
    reg_d0.w = 0;
    func_0011C230();
    D_0028E108[0] = 0;
    reg_d0.w = 1;
    D_0028E10C[0] = 0;
    D_0028E0F8_as_s32_a[0] = 0;
    D_0028E0FC_as_s32_a[0] = 0;
    D_0028E100_as_s16_a[0] = 0;
    D_0028E102_as_s16_a[0] = 0;
    func_0011C240();
    D_0028E0E8[0] = 0;
    D_0028E0EC[0] = 0;
    D_0028E0D8_as_s32_a[0] = 0;
    D_0028E0DC_as_s32_a[0] = 0;
    D_0028E0E0_as_s16_a[0] = 0;
    D_0028E0E2_as_s16_a[0] = 0;
    func_0011C920();
}

extern u32 D_0028E0F8[];
extern u32 D_0028E0FC[];
extern u16 D_0028E100[];
extern u16 D_0028E102[];
extern u16 D_0028E104[];
extern u16 D_0028E106[];

void func_0011BF30(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    D_0028E0F8[0] += reg_d0.w;
    reg_d2.w = D_0028E0F8[0];
    reg_d2.w &= ~0x3F;
    D_0028E108[0] += reg_d2.w;
    D_0028E0F8[0] &= 0x3F;
    D_0028E0FC[0] += (s16) reg_d1.h[0];
    reg_d2.w = D_0028E0FC[0];
    reg_d2.w &= ~0x3F;
    D_0028E10C[0] += reg_d2.w;
    D_0028E0FC[0] &= 0x3F;
    D_0028E100[0] += reg_d0.h[0];
    reg_d0.h[0] = D_0028E100[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    D_0028E104[0] = reg_d0.h[0];
    D_0028E100[0] &= 0x3F;
    D_0028E102[0] += reg_d1.h[0];
    reg_d1.h[0] = D_0028E102[0];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    D_0028E106[0] = reg_d1.h[0];
    D_0028E102[0] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}

extern u32 D_0028E0D8[];
extern u32 D_0028E0DC[];
extern u16 D_0028E0E0[];
extern u16 D_0028E0E2[];
extern u16 D_0028E0E4[];
extern u16 D_0028E0E6[];

void func_0011C0B0(void) {
    u32 sv_d0;
    u32 sv_d1;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    D_0028E0D8[0] += reg_d0.w;
    reg_d2.w = D_0028E0D8[0];
    reg_d2.w &= ~0x3F;
    D_0028E0E8[0] += reg_d2.w;
    D_0028E0D8[0] &= 0x3F;
    D_0028E0DC[0] += (s16) reg_d1.h[0];
    reg_d2.w = D_0028E0DC[0];
    reg_d2.w &= ~0x3F;
    D_0028E0EC[0] += reg_d2.w;
    D_0028E0DC[0] &= 0x3F;
    D_0028E0E0[0] += reg_d0.h[0];
    reg_d0.h[0] = D_0028E0E0[0];
    reg_d0.h[0] &= 0xFFC0 & 0xFFFF;
    reg_d0.h[0] *= 0xFFFF & 0xFFFF;
    D_0028E0E4[0] = reg_d0.h[0];
    D_0028E0E0[0] &= 0x3F;
    D_0028E0E2[0] += reg_d1.h[0];
    reg_d1.h[0] = D_0028E0E2[0];
    reg_d1.h[0] &= 0xFFC0;
    reg_d1.h[0] *= 0xFFFF;
    D_0028E0E6[0] = reg_d1.h[0];
    D_0028E0E2[0] &= 0x3F;
    reg_d1.w = sv_d1;
    reg_d0.w = sv_d0;
}

extern u16 D_0028E110;

void func_0011C230(void) {
    D_0028E110 = reg_d0.h[0];
}

extern u16 D_0028E0F0;

void func_0011C240(void) {
    D_0028E0F0 = reg_d0.h[0];
}

extern u32 D_0028E108_as_u32_a[];
extern u32 D_0028E10C_as_u32_a[];
extern u16 g_bg_scroll_y_as_u16;
extern u16 g_bg_scroll_x_as_u16;
extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;

void func_0011C250(void) {
    reg_a1_as_u16_p = &g_bg_scroll_y_as_u16;
    reg_a2_as_u16_p = &g_bg_scroll_x_as_u16;
    reg_d0.w = D_0028E108_as_u32_a[0];
    reg_d1.w = D_0028E10C_as_u32_a[0];
    reg_d0.w = (u32) reg_d0.w >> 6;
    reg_d1.w = (u32) reg_d1.w >> 6;
    *reg_a2_as_u16_p = reg_d0.h[0];
    *reg_a1_as_u16_p = reg_d1.h[0];
}

extern u8 g_text_layer[];

void func_0011C2B0(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)g_text_layer;
    reg_d4.h[0] = (s16) reg_d4.h[0] * 2;
loop_1:
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d2.h[0];
loop_2:
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] <<= 6;
    reg_d5.h[0] += reg_d1.h[0];
    *(u32 *)(reg_a0 + reg_d5.h[0] * 4) = reg_d4.w;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 1;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d1.h[0] -= 1;
    t = reg_d3.h[0] - 1;
    reg_d3.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}

extern u8 g_bg_layer[];

void func_0011C3C0(void) {
    u8 *a0 = reg_a0;
    u32 d0 = reg_d0.w;
    u32 d1 = reg_d1.w;
    u32 d2 = reg_d2.w;
    u32 d3 = reg_d3.w;
    u32 d4 = reg_d4.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = g_bg_layer;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    *(u32 *)reg_a0 = reg_d4.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_a0 = a0;
}

void func_0011C440(void) {
    u32 d0 = reg_d0.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = g_bg_layer;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.w = d0;
    reg_d1.w = (u32)reg_d1.w;
}

extern u32 D_002A17C0[];
extern u8 D_002A3C80[];

void func_0011C4A0(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)D_002A17C0[0];
    reg_tmp.w = (u32)reg_a0;
    if (reg_tmp.w == (u32)D_002A3C80) goto block_rts;
    reg_d5.w = 0;
loop_1:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
loop_2:
    reg_tmp.w = (u32)g_text_layer;
    *(u32 *)reg_a0 = (u32)g_text_layer;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u32 *)reg_a0 = -1;
    D_002A17C0[0] = (u32)reg_a0;
block_rts:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}

extern u32 D_0028E0D4;

void func_0011C610(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)D_002A17C0[0];
    reg_tmp.w = (u32)reg_a0;
    if (reg_tmp.w == (u32)D_002A3C80) goto block_rts;
    reg_d5.h[0] -= reg_d3.h[0];
    reg_d5.h[0] -= 1;
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.h[0] = 0;
    D_0028E0D4 = reg_d5.w;
    reg_d5.w = 0;
loop_1:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
loop_2:
    reg_tmp.w = (u32)g_text_layer;
    *(u32 *)reg_a0 = (u32)g_text_layer;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d4.w += D_0028E0D4;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u32 *)reg_a0 = -1;
    D_002A17C0[0] = (u32)reg_a0;
block_rts:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}
