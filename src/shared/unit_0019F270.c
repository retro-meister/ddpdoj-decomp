#include "common.h"
#include "entity.h"

void func_0019FCE0(void);
void func_0019FD30(void);
void func_001A0E90(void);
void func_001A1040(void);
void func_001A1360(void);
void func_001A1510(void);
void func_001A17C0(void);
void func_001A1850(void);
void func_001A18B0(void);
void func_001A19B0(void);
void func_001A1AA0(void);
void func_001A1B60(void);
void func_001A2680(void);

s32 entity_draw_keep();                            /* extern */
s32 func_0019DD20();                            /* extern */

void func_0019F270(void) {
    s32 temp_s0;
    s32 temp_s0_2;

    temp_s0 = (s32)reg_a6;
    func_0019DD20();
    reg_a6 = (u8 *)(((s32)reg_a0) - 0x2C);
    entity_draw_keep();
    reg_a6 = (u8 *)temp_s0;
    reg_a6 += 0x20;
    temp_s0_2 = (s32)reg_a6;
    reg_a0 = (u8 *)(((s32)reg_a3));
    func_0019DD20();
    reg_a6 = (u8 *)(((s32)reg_a0) - 0x2C);
    entity_draw_keep();
    reg_a6 = (u8 *)temp_s0_2;
}

void func_0019D390(void);
extern u16 D_0028DFC0;
extern u16 D_0028E3EC;
extern u16 g_loop;
extern u16 g_stage;

void func_0019F2E0(void) {
    if (D_0028DFC0 != 0) return;
    if (D_0028E3EC != 0) return;
    if (g_loop != 0) return;
    if (g_stage == 2) return;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d5.h[0] = 0x1C00;
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d1.h[0] += reg_d5.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d5.h[0] = 0x1400;
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d1.h[0] += reg_d5.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.w += 0xFE00FF00;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d4.b[0] = 0x18;
    reg_d2.w = reg_d6.w;
    func_0019D390();
}

void func_0019F410(void) {
    if ((D_0028DFC0 == 0) && (D_0028E3EC == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FF00;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        reg_d4.b[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x5C);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x5E);
        func_0019D390();
        reg_d1.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FF00;
        reg_d3.h[0] = 0x208;
        reg_d4.h[0] = *(u16 *)(reg_a6 + 0x3C);
        reg_d4.b[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x60);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x62);
        func_0019D390();
    }
}

void func_0019F620(void) {
    if ((D_0028DFC0 == 0) && (g_loop == 0) && (D_0028E3EC == 0) && (g_stage != 2)) {
        reg_d1.h[1] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x5C);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x5E);
        func_0019D390();
    }
}


void func_0019F750(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x43);
    *(u8 *)(reg_a6 + 0x43) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a6 + 0x43) = (u8) *(u8 *)(reg_a6 + 0x42);
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x44);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x46);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x48);
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->draw.h = (u16) reg_d1.h[1];
        ENTITY(reg_a6)->sprite.h = (u16) reg_d1.h[0];
        *(u16 *)(reg_a6 + 0x2A) = (u16) reg_d1.h[1];
        *(u16 *)(reg_a6 + 0x2C) = (u16) reg_d1.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x58);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x5C) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x5E) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x60) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x62) = (u16) reg_d0.h[0];
        *(u16 *)(reg_a6 + 0x44) -= 4;
        if ((s16) *(u16 *)(reg_a6 + 0x44) < 0) {
            *(u16 *)(reg_a6 + 0x44) = (u16) *(u16 *)(reg_a6 + 0x4C);
        }
    }
}


void func_0019F930(void) {
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    (*(u8 *)((u8 *)(reg_a1) + (-2))) = (u8) *(u8 *)(reg_a4 + 0x57);
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
}

extern s32 D_0029D730_as_s32_a[];
extern s16 D_0029F180_as_s16_a[];
extern s32 g_player1_as_s32_a[];

void func_0019FC70(void) {
    reg_a6 = (u8 *)D_0029F180_as_s16_a;
    reg_a4 = (u8 *)g_player1_as_s32_a;
    reg_a2 = (u8 *)D_0029D730_as_s32_a;
    reg_d7.w = 1;
    if (*(s16 *)reg_a6 < 0) {
        func_0019FD30();
        return;
    }
    reg_d7.w = 0;
    func_0019FCE0();
}

extern s32 D_0029D710_as_s32_a[];
extern s16 D_0029F110_as_s16_a[];
extern s32 g_player2_as_s32_a[];

void func_0019FCE0(void) {
    reg_a6 = (u8 *)D_0029F110_as_s16_a;
    reg_a4 = (u8 *)g_player2_as_s32_a;
    reg_a2 = (u8 *)D_0029D710_as_s32_a;
    if (*(s16 *)reg_a6 < 0) {
        func_0019FD30();
    }
}

typedef void (*Fn)();

extern u8 D_0025F3B0[];
extern u8 D_0025F3C0[];
extern u8 D_0025F400[];
extern u8 D_0025F430[];
extern u8 D_0029F110[];

s32 func_0013C9A0();
s32 func_0013CAB0();
s32 func_0013F800();
s32 func_0013F850();
s32 func_0013F960();
s32 func_0013F990();
extern u8 D_0028E370;
extern s32 D_0028ED70;
extern u8 D_0028ED7C;
extern u8 D_0029D710[];
extern u8 g_player2_as_u8_a[];
extern void (*jtbl_0028E3F4)();

void func_0019FD30(void) {
    u32 temp;
    u8 bits;
    s32 temp2;

    goto next_20;
loop_10:
    reg_a6 = (u8 *)D_0029F110;
    reg_a4 = (u8 *)g_player2_as_u8_a;
    reg_a2 = (u8 *)D_0029D710;
    if (*(s16 *)reg_a6 < 0) goto next_20;
    return;
next_20:
    reg_tmp.b[0] = *(u8 *)reg_a6;
    *(u8 *)reg_a6 |= 1;
    if (reg_tmp.b[0] & 1) goto next_100;
    reg_a0 = (u8 *)D_0025F3B0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1C);
    *(u8 *)(reg_a6 + 0x1C) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x57);
    *(u8 *)(reg_a2 + 0x1C) = (u8) reg_d0.b[0];
    *(u8 *)(reg_a2 + 0x1F) = (u8) reg_d0.b[0];
    *(s16 *)(reg_a2 + 0x16) = 0;
next_100:
    *(u8 *)(reg_a6 + 0x41) = *(u8 *)(reg_a4 + 0x19);
    *(u8 *)(reg_a6 + 0x40) = *(u8 *)(reg_a4 + 0x18);
    reg_d0.h[0] = *(u16 *)reg_a6;
    if (reg_d0.h[0] & 0x200) goto block_e;
    if (*(u8 *)(reg_a4 + 1) & 1) goto block_d;
    if (!(reg_d0.h[0] & 2)) goto block_c;
    if (!(*(u8 *)(reg_a4 + 1) & 0x20)) goto next_210;
    *(u16 *)(reg_a6 + 0x40) = 0;
next_210:
    if (!(*(u8 *)(reg_a6 + 0x41) & 0x10)) goto next_400;
    if (*(u8 *)(reg_a6 + 0x3E) == 0) goto next_310;
    *(u8 *)(reg_a6 + 0x3E) -= 1;
    if (*(u8 *)(reg_a6 + 0x3E) != 0) goto next_470;
    *(u8 *)(reg_a6 + 1) |= 0x40;
next_310:
    func_0013F960();
    if (!(*(u8 *)reg_a6 & 4)) goto next_320;
    func_001A17C0();
    goto block_b;
next_320:
    if (*(u8 *)(reg_a6 + 0x1A) != 0) goto next_330;
    func_001A17C0();
    func_001A18B0();
    if (cond_flag == 0) goto block_b;
    *(u8 *)reg_a6 |= 4;
    *(s16 *)(reg_a6 + 0x4E) = 0;
    if (*(u8 *)reg_a4 & 1) goto next_328;
    if (*(u8 *)(reg_a4 + 0x5A) & 4) goto next_326;
    func_001A19B0();
    goto block_b;
next_326:
    reg_a0 = (u8 *)D_0025F400;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d0.h[0] == 0) goto next_327;
    reg_d0.w = 0x14;
next_327:
    reg_a0 = (u8 *)D_0025F400;
    reg_a0 += reg_d0.h[0];
    func_001A1AA0();
    goto block_b;
next_328:
    reg_a0 = (u8 *)D_0025F430;
    func_001A1AA0();
    goto block_b;
next_330:
    if (*(u16 *)(reg_a6 + 0x10) != 4) goto next_350;
    if (*(u8 *)(reg_a6 + 1) & 4) goto next_340;
    *(u8 *)(reg_a6 + 1) |= 8;
    if (*(u8 *)(reg_a6 + 0x14) == 0x10) goto next_340;
    if (*(u8 *)(reg_a6 + 0x14) != 0x30) goto block_b;
    bits = *(u8 *)(reg_a6 + 0x1D);
    if (!(bits & 0x40)) goto next_332;
    *(u8 *)(reg_a6 + 0x1D) = bits & 0xBF;
    goto next_334;
next_332:
    *(u8 *)(reg_a6 + 0x1D) = bits | 0x40;
next_334:
    bits = *(u8 *)(reg_a6 + 0x3D);
    if (!(bits & 0x40)) goto next_336;
    *(u8 *)(reg_a6 + 0x3D) = bits & 0xBF;
    goto next_338;
next_336:
    *(u8 *)(reg_a6 + 0x3D) = bits | 0x40;
next_338:
    *(u8 *)(reg_a6 + 0x14) = 0x10;
    *(u8 *)(reg_a6 + 0x34) = 0x30;
next_340:
    *(u8 *)(reg_a6 + 1) &= 0xF7;
    *(u8 *)(reg_a6 + 1) |= 4;
next_350:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x3F);
    *(u8 *)(reg_a6 + 0x1A) -= reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) += reg_d0.b[0];
    if ((s32) *(u8 *)(reg_a6 + 0x3A) < 0x40) goto block_b;
    *(u8 *)(reg_a6 + 1) |= 0x10;
    reg_d0.w = 0;
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x4B) = 8;
    *(u8 *)(reg_a6 + 0x4A) = 4;
    *(u16 *)(reg_a6 + 0x16) = *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x18) = *(u16 *)(reg_a6 + 0x32);
    func_001A18B0();
    *(u16 *)(reg_a6 + 0xE) = 0x418;
    reg_tmp.w = 0xFC00FD00;
    *(u16 *)(reg_a6 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 8) = reg_tmp.h[0];
    *(u8 *)(reg_a4 + 0x3E) = 1;
    reg_a0 = (u8 *) func_0013F800;
    if (reg_d7.h[0] != 0) goto next_360;
    reg_a0 = (u8 *) func_0013F850;
next_360:
    jtbl_0028E3F4 = (Fn) reg_a0;
    jtbl_0028E3F4();
    goto block_b;
next_400:
    if (*(s8 *)reg_a4 >= 0) goto next_410;
    func_001A17C0();
    goto block_b;
next_410:
    func_0013F990();
    func_001A1850();
    *(u8 *)(reg_a6 + 0x3E) = 0xA;
    if (!(*(u8 *)(reg_a6 + 1) & 0x40)) goto block_b;
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 0x2B) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x2A) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x35) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x34) = reg_d0.b[0];
    *(u8 *)(reg_a4 + 0x3E) = reg_d0.b[0];
    if (reg_d7.h[0] == 0) goto next_430;
    func_0013C9A0();
    goto next_440;
next_430:
    func_0013CAB0();
next_440:
    *(u8 *)(reg_a6 + 0x4B) = 8;
    *(u8 *)(reg_a6 + 0x4A) = 4;
    *(u16 *)reg_a6 &= 0xDFDB;
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 1);
    *(u8 *)(reg_a6 + 1) &= 0xEF;
    if (!(reg_tmp.b[0] & 0x10)) goto next_470;
    *(u16 *)(reg_a6 + 0xA) = *(u16 *)(reg_a6 + 0x2A);
    *(u16 *)(reg_a6 + 0xC) = *(u16 *)(reg_a6 + 0x2C);
    *(u16 *)(reg_a6 + 0xE) = *(u16 *)(reg_a6 + 0x2E);
    *(u16 *)(reg_a6 + 6) = *(u16 *)(reg_a6 + 0x26);
    *(u16 *)(reg_a6 + 8) = *(u16 *)(reg_a6 + 0x28);
next_470:
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x37);
    if ((s32) *(u8 *)(reg_a6 + 0x1A) < (s32) reg_d0.b[0]) goto next_480;
    *(u8 *)(reg_a6 + 0x1A) = reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x3A) = *(u8 *)(reg_a6 + 0x36);
    *(u8 *)(reg_a6 + 1) &= 0xB3;
    goto block_b;
next_480:
    *(u8 *)(reg_a6 + 0x1A) += 2;
    *(u8 *)(reg_a6 + 0x3A) -= 2;
    *(u8 *)(reg_a6 + 0x3A) &= 0x3F;
block_b:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    if (*(u8 *)(reg_a6 + 0x1A) == 0) goto next_530;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    if (D_0028E370 == 0) goto next_520;
    if (D_0028ED7C != 2) goto next_510;
    if (D_0028ED70 == 0) goto next_520;
next_510:
    switch ((s32) reg_d0.h[0] >> 1) {
    case 0:
        func_001A0E90();
        break;
    case 1:
        func_001A1040();
        break;
    case 2:
        func_001A1360();
        break;
    }
next_520:
    reg_a6 += 0x20;
    goto next_540;
next_530:
    func_001A2680();
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    func_001A1B60();
next_540:
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_c:
    if (D_0028E370 == 0) goto block_rts;
    if (D_0028ED7C != 2) goto next_610;
    if (D_0028ED70 == 0) goto block_rts;
next_610:
    *(u8 *)(reg_a6 + 0x1B) += 8;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d1.h[0] == 0) goto next_620;
    reg_d1.w = 6;
next_620:
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d1.h[0];
    reg_a0 = (u8 *)D_0025F3C0;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    if (*(u8 *)(reg_a6 + 0x1B) != reg_d0.b[0]) goto next_630;
    *(u8 *)reg_a6 = 3;
next_630:
    *(u8 *)(reg_a6 + 0x3B) = *(u8 *)(reg_a6 + 0x1B);
    if (*(u16 *)(reg_a4 + 0x5A) == 4) goto next_640;
    func_0019F750();
next_640:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 4) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x22) = reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_d0.h[0];
    func_0019F410();
    func_001A2680();
    reg_a6 += 0x20;
    func_001A2680();
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_d:
    reg_d0.w = 0x31;
    reg_d1.w = 0;
    reg_a0 = reg_a6;
loop_710:
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    temp2 = reg_d0.h[0] - 1;
    reg_d0.h[0] = temp2;
    if (((s64) ((s64) (u16) temp2 << 0x30) >> 0x30) >= 0) goto loop_710;
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
    return;
block_e:
    reg_a6 += 0x20;
    temp = reg_d7.h[0] - 1;
    reg_d7.h[0] = temp;
    if (((s64) ((s64) (temp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_10;
block_rts:
    return;
}

s32 func_0019E130();

void func_001A0E90(void) {
    func_0019F750();
    func_001A2680();
    reg_a6 += 0x20;
    func_001A2680();
    reg_a6 -= 0x20;
    func_0019F410();
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_10;
        }
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_10;
    }
    ENTITY(reg_a6)->flags.b[0] &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
block_10:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_13;
                }
            } else {
block_13:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            func_0019E130();
        }
    }
}

s32 func_0019E5B0();

void func_001A1040(void) {
    u32 t;
    u8 *p0;

    if (*(u8 *)(reg_a6 + 1) & 4) {
        func_001A2680();
        reg_a6 += 0x20;
        func_001A2680();
        reg_a6 -= 0x20;
        func_0019F410();
    } else {
        reg_d3.w = 0;
        if (*(u8 *)(reg_a6 + 1) & 8) {
            reg_d3.w = 3;
        }
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x14);
loop_5:
        reg_d0.b[0] += 1;
        reg_d0.b[0] &= 0x3F;
        if (reg_d0.b[0] == 0x10) goto next_6;
        if (reg_d0.b[0] == 0x30) goto next_6;
        t = reg_d3.h[0] - 1;
        reg_d3.h[0] = t;
        if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
next_6:
        *(u8 *)(reg_a6 + 0x14) = (u8) reg_d0.b[0];
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        *(u8 *)(reg_a6 + 0x34) = (u8) reg_d1.b[0];
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x46);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x48);
        reg_a2 = (u8 *)reg_tmp.w;
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x14);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x58);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_a3 = (u8 *)reg_tmp.w;
        func_001A1510();
        *(u16 *)(reg_a6 + 0x5C) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x5E) = (u16) reg_d6.h[0];
        p0 = (u8 *)(reg_a6);
        reg_d1.b[0] = *(u8 *)(p0 + 0x34);
        reg_tmp.h[1] = *(u16 *)(p0 + 0x58);
        reg_tmp.h[0] = *(u16 *)(p0 + 0x5A);
        reg_a6 = p0 + 0x20;
        reg_a3 = (u8 *)reg_tmp.w;
        func_001A1510();
        reg_a6 -= 0x20;
        *(u16 *)(reg_a6 + 0x60) = (u16) reg_d6.h[1];
        *(u16 *)(reg_a6 + 0x62) = (u16) reg_d6.h[0];
    }
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            *(u8 *)reg_a6 |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_19;
        }
        reg_tmp.b[0] = *(u8 *)reg_a6;
        *(u8 *)reg_a6 &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_19;
    }
    *(u8 *)reg_a6 &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            *(u8 *)reg_a6 |= 0x10;
block_19:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_22;
                }
            } else {
block_22:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            func_0019E5B0();
        }
    }
}

s32 func_0019EF20();

void func_001A1360(void) {
    func_0019F750();
    func_001A2680();
    reg_a6 += 0x20;
    func_001A2680();
    reg_a6 -= 0x20;
    func_0019F410();
    if (*(u8 *)(reg_a6 + 0x40) & 0x10) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x20);
        if (*(u8 *)reg_a4 & 1) {
            reg_d0.h[0] = 8;
        }
        reg_d0.b[0] >>= 1;
        reg_d0.b[0] += *(u8 *)(reg_a4 + 0x36);
        *(u8 *)(reg_a4 + 0x34) = (u8) reg_d0.b[0];
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xF7;
        if (reg_tmp.b[0] & 8) {
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
            *(u8 *)(reg_a4 + 0x34) = 0U;
            goto block_10;
        }
        reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
        ENTITY(reg_a6)->flags.b[0] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            *(u8 *)(reg_a4 + 0x35) = 1U;
            return;
        }
        goto block_10;
    }
    ENTITY(reg_a6)->flags.b[0] &= 0xEF;
    if (*(u8 *)(reg_a4 + 0x34) != 0) {
        *(u8 *)(reg_a4 + 0x35) -= 1;
        if (*(u8 *)(reg_a4 + 0x35) == 0) {
            *(u8 *)(reg_a4 + 0x34) -= 1;
            ENTITY(reg_a6)->flags.b[0] |= 0x10;
block_10:
            reg_d0.b[0] = *(u8 *)(reg_a4 + 0x37);
            if (!(*(u8 *)reg_a4 & 1)) {
                if ((u16) *(u16 *)(reg_a4 + 0x20) == 8) {
                    goto block_13;
                }
            } else {
block_13:
                reg_d0.w = 2;
            }
            *(u8 *)(reg_a4 + 0x35) = (u8) reg_d0.b[0];
            func_0019EF20();
        }
    }
}

s32 func_0019D4D0();
extern u16 D_0025F1D0[];

void func_001A1510(void) {
    u32 p0;
    ENTITY(reg_a6)->y.h = (u16) *(u16 *)(reg_a4 + 2);
    ENTITY(reg_a6)->x.h = (u16) *(u16 *)(reg_a4 + 4);
    reg_d2.w = 0;
    reg_d1.h[0] &= 0x3F;
    reg_d5.h[0] = reg_d1.h[0];
    ENTITY(reg_a6)->attr.b.flip &= 0xBF;
    if ((s32) reg_d5.b[0] > 0x20) {
        ENTITY(reg_a6)->attr.b.flip |= 0x40;
        reg_d5.b[0] *= -1;
        reg_d2.w = 1;
        reg_d5.h[0] &= 0x3F;
    }
    reg_d5.h[0] *= 4;
    ENTITY(reg_a6)->draw.h = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a2;
    ENTITY(reg_a6)->sprite.h = ((reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d6.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d6.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    reg_a3 = (u8 *)(D_0025F1D0);
    reg_d0.h[0] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_d5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
    if (*(u8 *)reg_a4 & 1) {
        reg_d1.h[0] = reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 2);
        reg_d5.h[0] += reg_d1.h[0];
    }
    if (reg_d2.h[0] != 0) {
        reg_d5.h[0] *= 0xFFFF;
    }
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    p0 = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h = (u16) (p0 + reg_d5.h[0]);
    if (D_0028DFC0 == 0) {
        func_0019F2E0();
        func_0019D4D0();
    }
}

void func_001A17C0(void) {
    reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1B);
    if (*(u8 *)(reg_a4 + 0x39) != reg_d0.b[0]) {
        *(u8 *)(reg_a6 + 0x4A) -= 1;
        if (*(u8 *)(reg_a6 + 0x4A) == 0) {
            *(u8 *)(reg_a4 + 0x1B) -= 1;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x5A);
            reg_d0.h[0] -= 2;
            reg_d0.h[0] >>= 1;
            reg_d0.h[0] += 4;
            *(u8 *)(reg_a6 + 0x4A) = (u8) reg_d0.b[0];
        }
    }
}

extern u16 D_0029CEA0[];

void func_001A1850(void) {
    if ((D_0029CEA0[0] == 0) || !(*(u8 *)reg_a4 & 0x40)) {
        reg_d0.b[0] = *(u8 *)(reg_a4 + 0x1B);
        if (*(u8 *)(reg_a4 + 0x38) != reg_d0.b[0]) {
            *(u8 *)(reg_a4 + 0x1B) += 1;
        }
    }
}

void func_001A18B0(void) {
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hp.h;
    reg_a0 = (u8 *)(reg_tmp.w);
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x5C) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x5E) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->misc.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hit_y_minus.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16) ENTITY(reg_a6)->hit_y_minus.h >= 0) {
        reg_tmp.w = (u32)reg_a0;
        ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
        cond_flag = 0;
        return;
    }
    cond_flag = 1;
}

extern u16 D_0025F3D0[];
extern u8 D_0029DCD0[];
extern u8 D_0029E2D0[];

void func_001A19B0(void) {
    reg_a1 = D_0029E2D0;
    if (reg_d7.h[0] == 0) {
        reg_a1 = D_0029DCD0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x58);
    if (reg_d0.h[0] != 0) {
        reg_d0.w = 0x14;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_a0 = (u8 *)(D_0025F3D0);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d0.h[0] += reg_d1.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    func_0019F930();
}

void func_001A1AA0(void) {
    reg_a1 = D_0029E2D0;
    if (reg_d7.h[0] == 0) {
        reg_a1 = D_0029DCD0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    func_0019F930();
}

extern u16 D_0025F490[];
extern u16 D_0025F4B0[];
extern u16 D_0025F550[];
extern u16 D_0028D968_as_u16;
extern u16 D_0028D970_as_u16;
extern u16 D_0028D978_as_u16;
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029D790[];
extern u8 D_0029DD90[];
extern u16 D_0029F220[];
extern u16 D_0029F290[];


void func_001A1B60(void) {
    u32 cnt;

    switch (ENTITY(reg_a6)->flags.b[1] & 0x20) {
    case 0:
        goto next_100;
    }
    reg_a0 = (u8 *)&D_0028DFD8;
    reg_a1 = (u8 *)D_0029DD90;
    reg_a2 = (u8 *)D_0029D730;
    reg_a3 = (u8 *)D_0029D770;
    reg_d4.h[0] = D_0029F290[0];
    if (reg_d7.h[0] != 0) goto next_10;
    reg_a0 = (u8 *)&D_0028DFD4;
    reg_a1 = (u8 *)D_0029D790;
    reg_a2 = (u8 *)D_0029D710;
    reg_a3 = (u8 *)D_0029D750;
    reg_d4.h[0] = D_0029F220[0];
next_10:
    reg_d4.h[0] += 0x300;
    reg_d0.h[1] = *(u16 *)(reg_a4 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d0.w += 0x8000000;
    *(u16 *)(reg_a3 + 2) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[0];
    if (reg_a3[1] & 0x10) goto next_30;
    if (*(u16 *)(reg_a3 + 0xC) != 0) goto next_40;
    if (*(u16 *)(reg_a2 + 0x16) == 0) goto next_20;
    *(u16 *)(reg_a2 + 0x16) -= 1;
    if (*(u16 *)(reg_a2 + 0x16) != 0) goto next_60;
next_20:
    *(u16 *)(reg_a3 + 6) += 0x800;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[0];
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    if (!(reg_tmp.b[0] & 0x80)) goto block_sen;
    goto next_60;
next_30:
    *(u16 *)(reg_a6 + 0x4E) = 0;
    *(u16 *)(reg_a3 + 0xE) = *(u16 *)(reg_a3 + 0x1C);
    *(u16 *)(reg_a3 + 0xC) = 0;
next_40:
    ENTITY(reg_a6)->flags.b[0] &= 0x7F;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x10);
    reg_d1.h[0] = reg_d0.h[0];
    *(u16 *)reg_a0 = reg_d1.h[0];
    *(u16 *)(reg_a3 + 0x12) = reg_d1.h[0];
    reg_d0.h[0] -= *(u16 *)(reg_a3 + 2);
    if ((s16)reg_d0.h[0] >= 0) goto next_50;
    reg_d0.w = 0;
next_50:
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
next_60:
    reg_d0.w = 0x1D;
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)D_0025F4B0;
        goto next_64;
    }
    reg_a0 = (u8 *)D_0025F490;
    if (reg_a4[0x5A] & 4) goto next_64;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&D_0028D968_as_u16;
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
next_64:
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
loop_70:
    if (*(s16 *)reg_a1 >= 0) goto next_80;
    reg_a1 += 0x30;
    cnt = reg_d0.h[0] - 1;
    reg_d0.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_70;
    goto next_100;
next_80:
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->y.h;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->x.h;
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= reg_d4.h[0];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x50);
    *(u16 *)reg_a1 = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xA;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    reg_a1[1] = 0;
    reg_a1[0] = reg_a4[0x57];
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x50) += 4;
    if (*(u16 *)(reg_a6 + 0x50) != reg_d1.h[0]) goto next_100;
    *(u16 *)(reg_a6 + 0x50) = 0;
next_100:
    if ((s8)reg_a4[0] < 0) return;
    func_0019F620();
    func_0019D4D0();
    return;
block_sen:
    reg_a2 = reg_a1;
    reg_a1 += 0x510;
    reg_d3.h[0] = *(u16 *)(reg_a4 + 0x58);
    reg_a0 = (u8 *)&D_0028D970_as_u16;
    reg_d3.h[0] += reg_d3.h[0];
    if (reg_a4[0x5A] & 4) {
        reg_a0 = (u8 *)&D_0028D978_as_u16;
    }
    reg_tmp.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x22);
    reg_d2.h[0] = reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    if (reg_a4[0] & 1) {
        reg_a0 = (u8 *)D_0025F550;
    }
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->y.h;
    reg_a1 += 2;
    *(u16 *)reg_a1 = ENTITY(reg_a6)->x.h;
    reg_a1 += 2;
    *(u16 *)(reg_a1 - 4) -= 0x600;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1[-2] = reg_a4[0x57];
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.b[0] = reg_a3[0];
    reg_a3[0] |= 1;
    if (!(reg_tmp.b[0] & 1)) goto next_sen10;
    reg_a1[-0x28] |= 0x80;
    reg_d0.h[0] = *(u16 *)(reg_a3 + 0x12);
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] += 0x400;
    *(u16 *)(reg_a1 - 0x26) = reg_d0.h[0];
    reg_a1 = reg_a2;
    goto next_60;
next_sen10:
    *(u16 *)(reg_a6 + 0x4E) = 2;
    func_0019F620();
    func_0019D4D0();
}

s32 func_00201C20();
s32 func_00201D10();
extern u16 D_0025F5A8[];
extern u16 D_0025F5C0[];

void func_001A2680(void) {
    u32 temp_a0;
    u32 temp_a0_2;
    reg_d1.w = 0x3F;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] &= ENTITY(reg_a6)->move.b.dir;
    func_00201D10();
    reg_d0.h[0] = reg_d2.h[0];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
    reg_d2.h[0] -= reg_d0.h[0];
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    if (*(u8 *)reg_a4 & 1) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d3.h[0] += reg_d0.h[0];
    }
    if (*(u16 *)(reg_a4 + 0x5A) != 6) {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
    } else {
        reg_d0.h[0] = reg_d3.h[0];
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    }
    reg_d3.h[0] += reg_d0.h[0];
    temp_a0 = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)->x.h = (u16) (temp_a0 + reg_d3.h[0]);
    if (D_0028DFC0 == 0) {
        if ((s8) *(u8 *)reg_a4 >= 0) {
            func_0019D4D0();
            return;
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
        switch (reg_d0.h[0]) { case 0: break; default:
            reg_a0 = (u8 *)(D_0025F5C0);
            reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            ENTITY(reg_a6)->y.h -= reg_d0.h[0];
            *(u16 *)(reg_a6 + 0x38) -= 2;
            func_0019F620();
            func_0019D4D0();
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x56);
        *(u16 *)(reg_a6 + 0x56) -= 4;
        if ((s16) *(u16 *)(reg_a6 + 0x56) < 0) {
            *(u16 *)(reg_a6 + 0x56) = 8U;
        }
        temp_a0_2 = reg_d0.h[0];
        reg_a0 = (u8 *)(D_0025F5A8);
        reg_d1.h[0] = ((temp_a0_2 + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(temp_a0_2 + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = (temp_a0_2 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a0_2 & ~1)) : *(u16 *)reg_a0;
        func_00201C20();
        func_0019F620();
        func_0019D4D0();
    }
}
