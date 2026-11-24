#include "common.h"
#include "entity.h"

extern void bullet_fire_fast(void);

void func_002009C0(void)
{
    u32 savedD0;
    s8 command;

    savedD0 = reg_d0.w;
    command = (s8)reg_d1.b[0];
    if (command < 0x34 && command > 0xC) {
        bullet_fire_fast();
    }
    reg_d0.w = savedD0;
}

extern s16 D_0028DE80_as_s16_a4[4];
extern s16 D_002BDA80_as_s16_a[];
extern s16 *reg_a6_as_s16_p;

void func_00200A10(void)
{
    reg_a6_as_s16_p = D_002BDA80_as_s16_a;
    reg_d7.w = 0x31;

    do {
        *reg_a6_as_s16_p = 0;
        reg_a6_as_s16_p += 0x10;
    } while ((s16)(--reg_d7.h[0]) >= 0);

    D_0028DE80_as_s16_a4[0] = 0;
    D_0028DE80_as_s16_a4[2] = 0x20;
    D_0028DE80_as_s16_a4[1] = 0;
}

#ifndef DEATH_LABEL
s32 func_0019C5B0();
extern u8 D_0024E2E0[];
extern u8 D_0024E440[];
extern u8 D_0024E5C0[];
extern u16 D_0028DE80_as_u16_a4[4];
extern u8 D_002BDA80[];

void func_00200A70(void) {
    u32 tmp;

    reg_a4 = (u8 *)D_0024E2E0;
    reg_a4 += D_0028DE80_as_u16_a4[0];
    reg_d0.h[0] = *(u16 *)reg_a4;
    if ((s16) reg_d0.h[0] == -1) goto next_3;
    reg_d1.h[0] = D_0028DE80_as_u16_a4[1];
    if (reg_d1.h[0] == (reg_d0.h[0] & 0xFFFF)) goto next_1;
    D_0028DE80_as_u16_a4[1] += 1;
    goto next_3;
next_1:
    D_0028DE80_as_u16_a4[1] = 0;
    reg_a6 = (u8 *)D_002BDA80;
    reg_d7.w = 0x31;
loop_2:
    if (ENTITY(reg_a6)->flags.h != 0) goto next_2;
    ENTITY(reg_a6)->flags.h = 0x8000;
    ENTITY(reg_a6)->y.h = 0xF800;
    ENTITY(reg_a6)->x.h = *(u16 *)(reg_a4 + 2);
    ENTITY(reg_a6)->offset_y.h = *(u16 *)(reg_a4 + 4);
    ENTITY(reg_a6)->hit_y_plus.h = *(u16 *)(reg_a4 + 6);
    ENTITY(reg_a6)->hit_y_minus.h = *(u16 *)(reg_a4 + 8);
    D_0028DE80_as_u16_a4[0] += 0xA;
    goto next_3;
next_2:
    reg_a6 += 0x20;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_3:
    reg_a6 = (u8 *)D_002BDA80;
    reg_d7.w = 0x31;
loop_4:
    if (ENTITY(reg_a6)->flags.h == 0) goto next_9;
    reg_d0.h[0] = D_0028DE80_as_u16_a4[2];
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    if (ENTITY(reg_a6)->y.sh < 0x7800) goto next_5;
    ENTITY(reg_a6)->flags.h = 0;
    goto next_9;
next_5:
    reg_d0.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    if (reg_d0.w != 0xFFFFFFFF) goto next_6;
    D_0028DE80_as_u16_a4[2] = 0;
    goto next_9;
next_6:
    reg_a3 = (u8 *)reg_d0.w;
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 2;
    reg_a2 = (u8 *)D_0024E5C0;
    if (ENTITY(reg_a6)->offset_y.h != 0) goto loop_7;
    reg_a2 = (u8 *)D_0024E440;
    reg_d3.h[0] = 0x210;
loop_7:
    reg_d6.b[0] = *(s8 *)reg_a3;
    reg_a3 += 1;
    if (reg_d6.b[0] == 0) goto next_9;
    reg_d6.h[0] &= 0xFF;
    reg_d6.h[0] -= 0x20;
    reg_d6.h[0] += reg_d6.h[0];
    reg_d6.h[0] += reg_d6.h[0];
    reg_d2.w = *(u32 *)(reg_a2 + reg_d6.h[0]);
    func_0019C5B0();
    if (ENTITY(reg_a6)->offset_y.h != 0) goto next_8;
    reg_d1.h[0] += 0x400;
    goto loop_7;
next_8:
    reg_d1.h[0] += 0x200;
    goto loop_7;
next_9:
    reg_a6 += 0x20;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_4;
}
#endif
