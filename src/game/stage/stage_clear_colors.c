#include "common.h"

extern void *D_0026B230[8];
struct D0026b250Record { u16 w0[2]; void *p1; u16 w2[2]; void *p3; u16 w4[2]; void *p5; u16 w6[2]; void *p7; u16 w8[2]; void *p9; u16 w10[4]; };
extern struct D0026b250Record D_0026B250;

s32 rng_next_unsigned();
extern s8 D_0026B210[];
extern u16 g_game_frame;
extern s8 D_002BB430[];

void func_00171ED0(void) {
    reg_d6.w = 0;
    (*(s8 **)&reg_a4) = (s8 *)D_002BB430;
    reg_d7.w = 4;
    do {
loop_1:
        rng_next_unsigned();
        (*(s8 **)&reg_a0) = (s8 *)D_0026B210;
        reg_d0.h[0] += g_game_frame;
        reg_d0.h[0] &= 0x1F;
        (*(s8 **)&reg_a0) = &(*(s8 **)&reg_a0)[reg_d0.h[0]];
        reg_d0.w = 0;
        reg_d0.b[0] = *((s8 *)reg_a0);
        if ((1 << reg_d0.b[0]) & reg_d6.w) goto loop_1;
        reg_d6.w = reg_d6.w | (1 << reg_d0.w);
        ((s8 *)reg_a4)[7] = reg_d0.b[0];
        (*(s8 **)&reg_a4) += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 4;
    (*(s8 **)&reg_a4) = (s8 *)D_002BB430;
    do {
        (*(s8 **)&reg_a3) = ((s8 *)reg_a4);
        (*(s8 **)&reg_a3) += 7;
        reg_d5.b[0] = *((s8 *)reg_a3);
        reg_d6.w = 4;
        do {
            (*(s8 **)&reg_a3) -= 1;
            reg_d5.b[0] -= 1;
            if (0 > (s8) reg_d5.b[0]) {
                reg_d5.b[0] = 4;
            }
            *(*(s8 **)&reg_a3) = reg_d5.b[0];
        } while ((s16)(--reg_d6.h[0]) >= 0);
        (*(s8 **)&reg_a4) += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_0028E29C;
extern s16 D_0028E784;
extern u16 D_0028E788;
extern u16 D_0028E78C;
extern u8 D_0028E790;
extern u16 D_0028E794;
extern u16 g_stage_x4;

void func_00172060(void) {
    D_0028E784 = 0;
    (*(s16 *)&D_0028E790) = 0x707;
    D_0028E794 = 0;
    D_0028E78C = 7;
    D_0028E788 = 4;
    D_0028E29C = g_stage_x4;
}

extern u16 D_0028E788;

void func_00172090(void)
{
    reg_d0.w = 0;
    reg_a0 = (u8 *)(*(s8 **)((u8 *)((u8 *)D_0026B230) + (D_0028E29C & ~3)));
    reg_a0 += 7;
    reg_a0 -= D_0028E788;
    reg_d0.b[0] = (u8)*(s8 *)reg_a0;
}


s32 sprite_palette_load();
extern u16 D_0028E78C;
extern u8 D_0028E790;
extern u8 D_0028E791;
extern u16 D_0028E794;

void func_001720E0(void) {
    s32 temp_a0;
    s32 temp_a0_3;

    if (D_0028E794 == 0) {
        D_0028E794 = 1;
        func_00172090();
        reg_d0.h[0] *= 2;
        reg_d0.h[0] += 1;
        temp_a0 = reg_d0.h[0] * 4;
        reg_a0 = *(u8 **)((u8 *)((u8 *)&D_0026B250) + temp_a0);
        reg_d0.h[0] = 0x17;
        sprite_palette_load();
    }
    if (D_0028E794 == 1) {
        D_0028E78C -= 1;
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E78C = 7;
            D_0028E791 = D_0028E790;
            D_0028E788 -= 1;
            func_00172090();
            reg_d0.h[0] *= 2;
            reg_d0.h[0] += 1;
            temp_a0_3 = reg_d0.h[0] * 4;
            reg_a0 = *(u8 **)((u8 *)((u8 *)&D_0026B250) + temp_a0_3);
            reg_d0.h[0] = 0x17;
            sprite_palette_load();
            if (D_0028E788 == 0) {
                D_0028E791 = 0x20;
                D_0028E794 = 2;
            }
        }
    }
    if (D_0028E794 == 2) {
        if (D_0028E78C != 0) {
            D_0028E78C -= 1;
        }
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E784 = 1;
            goto block_z;
        }
    }
    cond_flag = 1;
    return;
block_z:
    cond_flag = 0;
}

extern u16 D_0028E784_as_u16;

void func_00172250(void) {
    D_0028E784_as_u16 = 0xFFFF;
}

s32 sprite_draw_layer1();
s32 sprite_draw_with_bullets_zoom();
extern u8 D_0026B280[];

void func_00172260(void) {
    u32 temp_a3;

    if (D_0028E784 != -1) {
        func_00172090();
        reg_d0.h[0] *= 2;
        temp_a3 = *(u32 *)(((u8 *)&D_0026B250) + (reg_d0.h[0] * 4));
        reg_d1.w = 0x38001C00;
        reg_d1.w += 0xC800E400;
        reg_d2.w = temp_a3;
        reg_d3.h[0] = 0x38E0;
        reg_d4.h[0] = 0x17;
        if ((u16) D_0028E784 == 0) {
            reg_d6.w = *(u32 *)(D_0026B280 + (D_0028E78C * 4));
            sprite_draw_with_bullets_zoom();
            return;
        }
        sprite_draw_layer1();
    }
}

extern u8 D_002BB438[];
extern u8 D_002BB440[];
extern u8 D_002BB448[];
extern u8 D_002BB450[];
extern u8 D_002620F0[];
extern u8 D_00262130[];
extern u8 D_00262170[];
extern u8 D_002621B0[];
extern u8 D_002621F0[];

s8 D_0026B210[32] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00,
    0x01, 0x02, 0x03, 0x04, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x01,
};

void *D_0026B230[8] = {
    D_002BB430,
    D_002BB438,
    D_002BB440,
    D_002BB448,
    D_002BB450,
    0,
    0,
    0,
};

struct D0026b250Record D_0026B250 = {
    { 0x14B5, 0x0000 },
    D_002620F0,
    { 0x14B6, 0x0000 },
    D_00262130,
    { 0x14B7, 0x0000 },
    D_00262170,
    { 0x14B8, 0x0000 },
    D_002621B0,
    { 0x14B9, 0x0000 },
    D_002621F0,
    { 0x0000, 0x0000, 0x0000, 0x0000 },
};

u8 D_0026B280[32] = {
    0x00, 0x80, 0x00, 0x80, 0x00, 0x90, 0x00, 0x90, 0x00, 0xA0, 0x00, 0xA0, 0x00, 0xB0, 0x00, 0xB0,
    0x00, 0xC0, 0x00, 0xC0, 0x00, 0xD0, 0x00, 0xD0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xF0, 0x00, 0xF0,
};

/* .sbss (the compiler lays these out in reverse) */
u16 D_0028E794 __attribute__((aligned(4)));
u8 D_0028E791;
u8 D_0028E790 __attribute__((aligned(4)));
u16 D_0028E78C __attribute__((aligned(4)));
u16 D_0028E788 __attribute__((aligned(4)));
s16 D_0028E784 __attribute__((aligned(4)));

/* .bss (the compiler lays these out in reverse) */
u8 D_002BB470[64];
s16 D_002BB460[8];
s8 D_002BB430[48];
