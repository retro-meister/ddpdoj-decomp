#include "common.h"
#include "fade.h"

void fade_in_start(void);
void fade_out_start(void);
void fade_to_black_start(void);
void fade_release(void);
void fade_step(void);

void color_to_rgb(void) {
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0xA;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d2.h[0] &= 0x7C00;
    reg_d3.h[0] &= 0x3E0;
    reg_d4.h[0] &= 0x1F;
    reg_d2.h[0] >>= 0xA;
    reg_d3.h[0] >>= 5;
}

void rgb_to_color(void) {
    reg_d1.w = 0;
    reg_d0.w = 0xA;
    reg_d2.h[0] <<= 0xA;
    reg_d3.h[0] <<= 5;
    reg_d4.h[0] &= 0x1F;
    reg_d2.h[0] &= 0x7C00;
    reg_d3.h[0] &= 0x3E0;
    reg_d1.h[0] |= reg_d2.h[0];
    reg_d1.h[0] |= reg_d3.h[0];
    reg_d1.h[0] |= reg_d4.h[0];
}


void color_at_brightness(void) {
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d7.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    color_to_rgb();
    reg_d2.h[0] = (s16)reg_d2.h[0] << 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] << 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] << 8;
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 5;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 5;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 5;
    reg_d2.h[0] = (s16)reg_d2.h[0] * (s16)reg_d7.h[0];
    reg_d3.h[0] = (s16)reg_d3.h[0] * (s16)reg_d7.h[0];
    reg_d4.h[0] = (s16)reg_d4.h[0] * (s16)reg_d7.h[0];
    reg_d2.h[0] = (s16)reg_d2.h[0] >> 8;
    reg_d3.h[0] = (s16)reg_d3.h[0] >> 8;
    reg_d4.h[0] = (s16)reg_d4.h[0] >> 8;
    reg_d2.h[0] &= 0x7FFF;
    reg_d3.h[0] &= 0x7FFF;
    reg_d4.h[0] &= 0x7FFF;
    if ((s16)reg_d2.h[0] > 0x1F) {
        reg_d2.h[0] = 0x1F;
    }
    if ((s16)reg_d3.h[0] > 0x1F) {
        reg_d3.h[0] = 0x1F;
    }
    if ((s16)reg_d4.h[0] > 0x1F) {
        reg_d4.h[0] = 0x1F;
    }
    rgb_to_color();
    reg_d0.h[0] = reg_d1.h[0];
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

extern s32 D_0028DF20;
extern s32 D_0028DF24;
extern s32 D_0028DF28;
extern s32 g_fade_step_blue;
extern s32 g_fade_step_green;
extern s32 g_fade_step_red;
extern s32 fades_reset_state;
extern u8 D_0029C0C0[];
extern u8 D_0029C150[];

void fades_reset(void) {
    s32 i;

    for (i = 0; i < 0x8C0; i++) {
        D_0029C150[i] = 0;
    }
    for (i = 0; i < 0x90; i++) {
        D_0029C0C0[i] = 0;
    }
    reg_a0 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
    fades_reset_state = 0;
    g_fade_step_red = 0;
    g_fade_step_green = 0;
    g_fade_step_blue = 0;
    D_0028DF28 = 0;
    D_0028DF24 = 0;
    D_0028DF20 = 0;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        *(s16 *)(reg_a0 + 0x2C) = 0;
        *(s16 *)(reg_a0 + 0x2E) = 0;
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.h[0] = 0x13;
    reg_a0 = (u8 *)D_0029C150;
    do {
        *(s16 *)reg_a0 = 0;
        *(s16 *)(reg_a0 + 0x2C) = 0;
        *(s16 *)(reg_a0 + 0x2E) = 0;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;
#ifdef DDPDOJ_PC
static u8 *fade_saved_addresses[5];
#else
extern s32 reg_save_a4;
extern s32 reg_save_a3;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern s32 reg_save_a0;
#endif


#ifdef DDPDOJ_PC
#define FADE_SAVE_ADDRESSES() { \
    fade_saved_addresses[0] = reg_a0; \
    fade_saved_addresses[1] = reg_a1; \
    fade_saved_addresses[2] = reg_a2; \
    fade_saved_addresses[3] = reg_a3; \
    fade_saved_addresses[4] = reg_a4; \
}
#define FADE_RESTORE_ADDRESSES() { \
    reg_a0 = fade_saved_addresses[0]; \
    reg_a1 = fade_saved_addresses[1]; \
    reg_a2 = fade_saved_addresses[2]; \
    reg_a3 = fade_saved_addresses[3]; \
    reg_a4 = fade_saved_addresses[4]; \
}
#else
#define FADE_SAVE_ADDRESSES() { \
    reg_save_a0 = (s32)reg_a0; \
    (*(s32 *)&reg_save_a1) = (s32)reg_a1; \
    (*(s32 *)&reg_save_a2) = (s32)reg_a2; \
    reg_save_a3 = (s32)reg_a3; \
    reg_save_a4 = (s32)reg_a4; \
}
#define FADE_RESTORE_ADDRESSES() { \
    reg_a0 = (u8 *) (*(u16 **)&reg_save_a0); \
    reg_a1 = (u8 *)reg_save_a1; \
    reg_a2 = (u8 *)reg_save_a2; \
    reg_a3 = (u8 *) (u32)reg_save_a3; \
    reg_a4 = (u8 *) (*(u16 **)&reg_save_a4); \
}
#endif

void fade_in_and_release(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();

    reg_d6.h[0] = 1;
    fade_in_start();
}

void fade_in(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();
    reg_d6.h[0] = 0;
    fade_in_start();
}

extern u16 fade_speeds[32][2];
extern FadeArea fade_areas[3];
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;

void fade_in_start(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 0x1E) = 0;
    *(s16 *)(reg_a2 + 2) = 0;
    *(u16 *)(reg_a2 + 0x12) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
#ifdef DDPDOJ_PC
    const FadeArea *area = &fade_areas[reg_d2.h[0] / 8];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(area->changed);
#else
    reg_tmp.w = (*(u32 *)((u8 *)(((u8 *)fade_areas + (reg_d2.h[0] & ~3))) + (4)));
#endif
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
#ifdef DDPDOJ_PC
    reg_a3 = area->colors;
#else
    reg_a3 = *(u8 **)((u8 *)fade_areas + (reg_d2.h[0] & ~3));
#endif
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a3);
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)fade_speeds;
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 8);
    reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    *(u16 *)reg_a4 = 1;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d2.h[0] = *(u16 *)(reg_a2 + 4);
    reg_d3.h[0] = *(u16 *)(reg_a2 + 0x12);
    do {
        *(u16 *)reg_a4 = reg_d3.h[0];
        reg_a4 += 2;
    } while ((s16)(--reg_d2.h[0]) >= 0);
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    fade_release();
    goto next_5;
next_4:
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
}




void fade_out_and_release(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_d6.h[0] = 1;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();
    fade_out_start();
}

void fade_out(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();
    reg_d6.h[0] = 0;
    fade_out_start();
}

void fade_out_start(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 0x1E) = 0;
    *(s16 *)(reg_a2 + 2) = 0;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
#ifdef DDPDOJ_PC
    const FadeArea *area = &fade_areas[reg_d2.h[0] / 8];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(area->changed);
#else
    reg_tmp.w = (*(u32 *)((u8 *)(((u8 *)fade_areas + (reg_d2.h[0] & ~3))) + (4)));
#endif
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
#ifdef DDPDOJ_PC
    reg_a3 = area->colors;
#else
    reg_a3 = *(u8 **)((u8 *)fade_areas + (reg_d2.h[0] & ~3));
#endif
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a3);
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 0xA) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 0xC) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)fade_speeds;
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    fade_release();
    goto next_5;
next_4:
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
}




void fade_to_black_and_release(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();
    reg_d6.h[0] = 1;
    fade_to_black_start();
}

void fade_to_black(void)
{
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    FADE_SAVE_ADDRESSES();
    reg_d6.h[0] = 0;
    fade_to_black_start();
}


void fade_to_black_start(void) {
    u8 *saved_a0;
    u8 *saved_a1;
    u32 t;
    u16 t5;

    reg_a1 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
loop_1:
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_3;
    *(u16 *)(reg_a1 + 0) = 0x8000;
    *(u16 *)(reg_a1 + 4) = reg_d6.h[0];
    saved_a0 = reg_a0;
    saved_a1 = reg_a1;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d6.h[0] = 0x13;
    reg_a2 = (u8 *)D_0029C150;
loop_2:
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0);
    if ((s16) reg_tmp.h[0] < 0) goto next_1;
    *(u16 *)(reg_a2 + 0) = 0x8000U;
    *(s16 *)(reg_a2 + 0x20) = 0;
    *(s16 *)(reg_a2 + 0x2C) = 0;
    *(s16 *)(reg_a2 + 0x2E) = 0;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
    *(u16 *)(reg_a1 + 0x2C) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 0x2E) = reg_tmp.h[0];
    reg_a1 = reg_a2;
    *(s16 *)(reg_a2 + 2) = 0;
    *(s16 *)(reg_a2 + 0x1E) = 1;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
#ifdef DDPDOJ_PC
    const FadeArea *area = &fade_areas[reg_d2.h[0] / 8];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(area->changed);
#else
    reg_tmp.w = (*(u32 *)((u8 *)(((u8 *)fade_areas + (reg_d2.h[0] & ~3))) + (4)));
#endif
    *(u16 *)(reg_a2 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 8) = reg_tmp.h[0];
#ifdef DDPDOJ_PC
    reg_a3 = area->colors;
#else
    reg_a3 = *(u8 **)((u8 *)fade_areas + (reg_d2.h[0] & ~3));
#endif
    t5 = *(u16 *)reg_a0;
    reg_a3 += t5;
    reg_a0 += 2;
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a3);
    *(u16 *)(reg_a2 + 0xE) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x10) = reg_tmp.h[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(palette_black);
    *(u16 *)(reg_a2 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a2 + 4) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a3 = (u8 *)fade_speeds;
    reg_d3.h[0] &= 0x1F;
    reg_d3.h[0] *= 4;
    reg_a3 += reg_d3.h[0];
    *(u16 *)(reg_a2 + 0x16) = *(u16 *)reg_a3;
    reg_a3 += 2;
    *(u16 *)(reg_a2 + 0x14) = *(u16 *)(reg_a2 + 0x16);
    *(u16 *)(reg_a2 + 0x1C) = *(u16 *)reg_a3;
    reg_tmp.w = 0xFFFF0000;
    *(u16 *)(reg_a2 + 0x18) = reg_tmp.h[1];
    *(u16 *)(reg_a2 + 0x1A) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 0x10);
    reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d4.h[0] = *(u16 *)(reg_a2 + 4);
    reg_a4 = (u8 *)(reg_a2 + 0x30);
    do {
        *(u16 *)reg_a4 = *(u16 *)reg_a3;
        reg_a3 += 2;
        reg_a4 += 2;
    } while ((s16)(--reg_d4.h[0]) >= 0);
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] == 0) goto next_2;
next_1:
    reg_a2 += 0x70;
    t = reg_d6.h[0] - 1;
    reg_d6.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.w = -1;
next_2:
    reg_a0 = saved_a0;
    reg_a1 = saved_a1;
    if ((s16) reg_d0.h[0] >= 0) goto next_4;
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    fade_release();
    goto next_5;
next_4:
    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
    return;
next_3:
    reg_a1 += 0x30;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_5:
    reg_d0.w = -1;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    FADE_RESTORE_ADDRESSES();
}


void fade_release(void)
{
#ifdef DDPDOJ_PC
    if (reg_d0.w == 0 || reg_d0.w == (u32)-1) {
        return;
    }
#endif
    u32 saved_data_register = reg_d0.w;
    u8 *saved_address_register = reg_a0;
    u16 *entry;

    do {
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
#ifdef DDPDOJ_PC
        entry = (u16 *)reg_a0;
        entry[0] = 0;
        entry[2] = 0;
#else
        ((u16 *)((u32)reg_a0))[0] = 0;
        ((u16 *)((u32)reg_a0))[2] = 0;
        entry = (u16 *)((u32)reg_a0);
#endif
        reg_d0.h[1] = entry[0x16];
        reg_d0.h[0] = entry[0x17];
    } while (reg_d0.w != 0);

    reg_a0 = (u8 *)saved_address_register;
    reg_d0.w = saved_data_register;
}


void fade_is_running(void) {
#ifdef DDPDOJ_PC
    if (reg_d0.w == 0 || reg_d0.w == (u32)-1) {
        cond_flag = 0;
        return;
    }
#endif
    u32 temp_d0;
    u32 temp_d1;
    u8 *temp_a0;

    temp_d0 = reg_d0.w;
    temp_d1 = reg_d1.w;
    temp_a0 = reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
    reg_d1.w = 0;
    reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
    reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
    if (reg_d0.w != 0) {
        do {
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
            reg_d1.h[0] += (*(u16 *)(reg_a0 + 0x18));
            reg_d0.h[1] = (*(u16 *)(reg_a0 + 0x2C));
            reg_d0.h[0] = (*(u16 *)(reg_a0 + 0x2E));
        } while (reg_d0.w != 0);
        reg_d0.h[0] = reg_d1.h[0];
    }
    if (reg_d0.h[0] != 0) {
        cond_flag = 1;
    } else {
        cond_flag = 0;
    }
    reg_d0.w = temp_d0;
    reg_d1.w = temp_d1;
    reg_a0 = temp_a0;
}


void fades_update(void) {
    u16 temp_a0;
    reg_d7.w = 2;
    reg_a0 = D_0029C0C0;
    do {
        reg_tmp.h[0] = *(u16 *)reg_a0;
        if ((s16) reg_tmp.h[0] < 0) {
            reg_d0.h[1] = *(u16 *)(reg_a0 + 0x2C);
            reg_d0.h[0] = *(u16 *)(reg_a0 + 0x2E);
            fade_step();
            temp_a0 = *(u16 *)(reg_a0 + 4);
            if ((temp_a0 != 0) && (temp_a0 == 1)) {
                reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a0);
                fade_is_running();
                if (cond_flag == 0) {
                    reg_d0.w = ARCADE_ADDRESS_ENCODE(reg_a0);
                    fade_release();
                }
            }
        }
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}


void fade_step(void) {
loop_1:
    reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0);
    if (reg_tmp.h[0] == 0) goto block_next;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d5.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d6.w = 0;
    if (*(u16 *)(reg_a4 + 0x1E) != 0) goto skip_1;
    reg_d6.w = 2;
skip_1:
    if (*(u16 *)(reg_a4 + 0x18) == 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) -= 1;
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
    if ((s16)reg_tmp.h[0] >= 0) goto block_next;
    *(u16 *)(reg_a4 + 0x14) = *(u16 *)(reg_a4 + 0x16);
    if (*(u16 *)(reg_a4 + 0x20) == 0x20) goto block_next;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
    *(u16 *)(reg_a4 + 0x20) += reg_d0.h[0];
    if (*(s16 *)(reg_a4 + 0x20) < 0x20) goto skip_2;
    *(u16 *)(reg_a4 + 0x18) = 0;
    *(u16 *)(reg_a4 + 0) = 0;
skip_2:
    reg_a5 = reg_a4 + 0x30;
loop_2:
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_d1.h[0] &= 0x7FFF;
    reg_d2.h[0] &= 0x7FFF;
    if (reg_d2.h[0] == reg_d1.h[0]) goto next_1;
    reg_d1.h[0] = *(u16 *)reg_a3;
    color_to_rgb();
    g_fade_step_red = reg_d2.h[0];
    g_fade_step_green = reg_d3.h[0];
    g_fade_step_blue = reg_d4.h[0];
    reg_d1.h[0] = *(u16 *)reg_a2;
    color_to_rgb();
    D_0028DF28 = reg_d2.h[0];
    D_0028DF24 = reg_d3.h[0];
    D_0028DF20 = reg_d4.h[0];
    reg_d2.h[0] -= *(u16 *)&g_fade_step_red;
    reg_d3.h[0] -= *(u16 *)&g_fade_step_green;
    reg_d4.h[0] -= *(u16 *)&g_fade_step_blue;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
loop_3:
    if (reg_d2.h[0] == 0) goto skip_r;
    if ((s16)reg_d2.h[0] >= 0) goto next_r2;
    if (D_0028DF28 != 0x10) goto skip_r1;
    if (g_fade_step_red == 0xF) goto skip_r;
skip_r1:
    g_fade_step_red -= 1;
    if (g_fade_step_red == 0x10) goto skip_r1;
    if (0 < g_fade_step_red) goto skip_r;
    g_fade_step_red = 0;
    goto skip_r;
next_r2:
    if (D_0028DF28 != 0x10) goto next_r3;
    if (g_fade_step_red == 0x11) goto skip_r;
next_r3:
    g_fade_step_red += 1;
    if (g_fade_step_red == 0x10) goto next_r2;
    if ((s16)g_fade_step_red < 0x1F) goto skip_r;
    g_fade_step_red = 0x1F;
skip_r:
    if (reg_d3.h[0] == 0) goto skip_g;
    if ((s16)reg_d3.h[0] >= 0) goto next_g2;
    if (D_0028DF24 != 0x10) goto next_g1;
    if (g_fade_step_green == 0xF) goto skip_g;
next_g1:
    g_fade_step_green -= 1;
    if (g_fade_step_green == 0x10) goto next_g1;
    if (0 < g_fade_step_green) goto skip_g;
    g_fade_step_green = 0;
    goto skip_g;
next_g2:
    if (D_0028DF24 != 0x10) goto next_g3;
    if (g_fade_step_green == 0x11) goto skip_g;
next_g3:
    g_fade_step_green += 1;
    if (g_fade_step_green == 0x10) goto next_g2;
    if ((s16)g_fade_step_green < 0x1F) goto skip_g;
    g_fade_step_green = 0x1F;
skip_g:
    if (reg_d4.h[0] == 0) goto skip_b;
    if ((s16)reg_d4.h[0] >= 0) goto next_b2;
    if (D_0028DF20 != 0x10) goto next_b1;
    if (g_fade_step_blue == 0xF) goto skip_b;
next_b1:
    g_fade_step_blue -= 1;
    if (g_fade_step_blue == 0x10) goto next_b1;
    if (0 < g_fade_step_blue) goto skip_b;
    g_fade_step_blue = 0;
    goto skip_b;
next_b2:
    if (D_0028DF20 != 0x10) goto next_b3;
    if (g_fade_step_blue == 0x11) goto skip_b;
next_b3:
    g_fade_step_blue += 1;
    if (g_fade_step_blue == 0x10) goto next_b2;
    if ((s16)g_fade_step_blue < 0x1F) goto skip_b;
    g_fade_step_blue = 0x1F;
skip_b:
    reg_d0.h[0] -= 1;
    if (reg_d0.h[0] != 0) goto loop_3;
    reg_d2.h[0] = *(u16 *)&g_fade_step_red;
    reg_d3.h[0] = *(u16 *)&g_fade_step_green;
    reg_d4.h[0] = *(u16 *)&g_fade_step_blue;
    rgb_to_color();
    *(u16 *)reg_a3 = reg_d1.h[0];
    *(u16 *)reg_a1 = 1;
next_1:
    reg_a3 += 2;
    reg_a5 += 2;
    reg_a2 += reg_d6.h[0];
    if ((s16)(--reg_d5.h[0]) >= 0) goto loop_2;
block_next:
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2E);
    if (reg_d0.w != 0) goto loop_1;
}

extern u8 g_palette_bank_b[];
extern u8 fade_areas_1[];
extern u8 g_palette_bank_a[];
extern u8 fade_areas_3[];
extern u8 fade_areas_4[];
extern u8 fade_areas_5[];

/* How fast a fade runs: the frames between two steps and the brightness added at a step. */
u16 fade_speeds[32][2] = {
    { 0, 4 },
    { 0, 3 },
    { 0, 2 },
    { 0, 1 },
    { 1, 1 },
    { 2, 1 },
    { 3, 1 },
    { 4, 1 },
    { 5, 1 },
    { 6, 1 },
    { 7, 1 },
    { 8, 1 },
    { 9, 1 },
    { 10, 1 },
    { 11, 1 },
    { 12, 1 },
    { 13, 1 },
    { 14, 1 },
    { 15, 1 },
    { 16, 1 },
    { 17, 1 },
    { 18, 1 },
    { 19, 1 },
    { 20, 1 },
    { 21, 1 },
    { 22, 1 },
    { 23, 1 },
    { 24, 1 },
    { 25, 1 },
    { 26, 1 },
    { 27, 1 },
    { 28, 1 },
};

u16 palette_black[32] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 palette_white[32] = {
    0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
    0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
    0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
    0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
};

/* The colours a fade can work on, and the flag that says they changed. */
FadeArea fade_areas[3] = {
    { g_palette_bank_b, fade_areas_1 },
    { g_palette_bank_a, fade_areas_3 },
    { fade_areas_4, fade_areas_5 },
};

/* .sbss (the compiler lays these out in reverse) */
s32 fades_reset_state;
s32 g_fade_step_red;
s32 g_fade_step_green;
s32 g_fade_step_blue;
s32 D_0028DF28;
s32 D_0028DF24;
s32 D_0028DF20;

/* .bss (the compiler lays these out in reverse) */
u8 D_0029C150[2240];
u8 D_0029C0C0[144];
