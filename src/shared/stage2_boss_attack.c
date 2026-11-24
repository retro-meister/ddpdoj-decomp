#include "common.h"
#include "entity.h"

void func_001BF2A0();
void func_001BF730(void);
void func_001BFEC0(void);
void func_001C00C0(void);
void func_001C0720(void);
void func_001C1030(void);
void func_001C1A30(void);
void func_001C2230(void);
void func_001C2D10(void);
void func_001C3080(void);
void func_001C3290(void);
void func_001C3450(void);
void func_001C3520(void);
void func_001C3730(void);
void func_001C3800();
void func_001C3C80(void);

s32 bullet_fire_fixed();                            /* extern */
extern u16 g_loop;

void func_001BF210(void) {
    if (g_loop != 0) {
        bullet_fire_fixed();
        reg_d1.b[0] -= 1;
        bullet_fire_fixed();
        reg_d1.b[0] += 2;
    }
    bullet_fire_fixed();
}

void func_001BF260(void)
{
    void bullet_fire_fixed(void);
    bullet_fire_fixed();
}

extern u16 *reg_a4_as_u16_p;

void func_001BF270(void) {
    reg_a4_as_u16_p[1] = 0x808;
    reg_a4_as_u16_p[3] = 1;
    reg_a4_as_u16_p[4] = 2;
    func_001BF2A0(1, 0x808);
}

typedef void (*Fn)();

extern u16 D_0026C140[];
extern u16 D_0026C1C0[];
extern u16 D_0028DB08[];
extern void (*jtbl_0028E3F4)();

void func_001BF2A0() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 3) = *(u8 *)(reg_a4 + 2);
    if (*(s16 *)(reg_a4 + 6) >= 0) goto next_1;
    reg_a0 = (u8 *)(D_0026C1C0);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_tmp2.h[1] = *(u16 *)(reg_a6 + 0x82);
    reg_tmp2.h[0] = *(u16 *)(reg_a6 + 0x84);
    reg_d2.w = *(u32 *)&reg_tmp2.h[0];
    goto next_2;
next_1:
    reg_a0 = (u8 *)(D_0026C140);
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
    reg_d1.b[0] += 1;
    reg_d1.h[0] &= 0x3E;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
next_2:
    reg_a0 = (u8 *)(D_0028DB08);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 4);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
    jtbl_0028E3F4 = *(Fn *)reg_tmp.w;
    jtbl_0028E3F4();
    *(u16 *)(reg_a4 + 6) *= 0xFFFF;
    *(u16 *)(reg_a4 + 8) -= 1;
    if (*(u16 *)(reg_a4 + 8) != 0) goto block_rts;
    *(s16 *)(reg_a4 + 0) = 0;
block_rts:
    return;
}

s32 bullet_fire256();
void func_001BF570(void) {
    reg_d0.w = 0xFFFE0001;
    reg_d7.b[0] = reg_d1.b[0];
    reg_d6.h[0] = 0x10;
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
}

void func_001BF630(void) {
    reg_d0.w = 0x40001;
    reg_d7.b[0] = reg_d1.b[0];
    reg_d6.h[0] = 2;
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256();
}

s32 rng_next_bit();

void func_001BF6C0(void) {
    *(s16 *)(reg_a4 + 2) = 5;
    *(s8 *)(reg_a4 + 8) = 0;
    *(u8 *)(reg_a4 + 9) = 1U;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        func_001BF730();
        return;
    }
    *(u8 *)(reg_a4 + 9) *= -1;
    func_001BF730();
}


s32 bullet_fire256_fixed();
s32 rng_next();
s32 aim_at_player();
extern u16 D_00259770[];

void func_001BF730(void) {
    u8 t1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        t1 = *(u8 *)(reg_a4 + 9);
        reg_d7.b[0] = t1;
        if ((s8)(t1) < 0) {
            *(u8 *)(reg_a4 + 8) += reg_d7.b[0];
            if (0 >= (s8) *(u8 *)(reg_a4 + 8)) {
                *(u8 *)(reg_a4 + 9) *= -1;
            }
        } else {
            *(u8 *)(reg_a4 + 8) += reg_d7.b[0];
            if (0 <= (s64)*(s8 *)(reg_a4 + 8)) {
                *(u8 *)(reg_a4 + 9) *= -1;
            }
        }
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_d1.h[0] = ENTITY(reg_a6)->x.h;
        reg_d0.h[0] += 0x800;
        aim_at_player();
        if (cond_flag == 0) {
            reg_d1.b[0] += *(u8 *)(reg_a4 + 8);
            reg_d5.w = 0x08000100;
            if (*(s8 *)(reg_a4 + 5) < 0) {
                reg_d5.w = 0x07FFFF00;
            }
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_d1.h[0] += reg_d1.h[0];
            reg_d4.w = 0;
            reg_d1.h[0] += reg_d1.h[0];
            rng_next();
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.w = 0x80013;
            reg_a0 = (u8 *)(D_00259770);
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0xC;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d1.b[0] -= 0x18;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            if (g_loop != 0) {
                reg_d1.b[0] -= 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_tmp3.h[0] = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&reg_tmp3.h[0];
                reg_d3.w += reg_d5.w;
                bullet_fire256_fixed();
            }
        }
        *(u16 *)(reg_a4 + 6) -= 1;
        if (*(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}


void func_001BFE60() {
    *(s16 *)(reg_a4 + 2) = 1;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 0x1010;
    rng_next();
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
    func_001BFEC0();
}

extern u8 D_0026C240[];

void func_001BFEC0(void) {
    s32 bullet_fire();
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        if (*(s16 *)(reg_a4 + 8) >= 0) {
            rng_next();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x10;
            reg_d1.b[0] = reg_d0.b[0];
        } else {
            rng_next();
            reg_d1.w = 0;
            reg_d0.b[0] += 0x30;
            reg_d1.b[0] = reg_d0.b[0];
        }
        reg_a0 = (u8 *)D_0026C240;
        reg_a0 += *(u16 *)(reg_a4 + 4);
        reg_d3.h[1] = *(u16 *)reg_a0;
        reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
        *(u16 *)(reg_a4 + 4) += 4;
        *(u16 *)(reg_a4 + 4) &= 0xF;
        reg_d4.h[0] = 0x140;
        reg_d0.w = 0xFFEC0012;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_d0.w += 0x20000;
        reg_d4.h[0] -= 0x60;
        bullet_fire();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a4 + 7) += reg_d0.b[0];
            *(u8 *)(reg_a4 + 3) = 0x18U;
        }
    }
}


void func_001C00A0(void) {
    reg_a4_as_u16_p[1] = 4;
    reg_a4_as_u16_p[2] = 0;
    reg_a4_as_u16_p[3] = 4;
    func_001C00C0();
}


void func_001C00C0() {
    s32 bullet_fire();
    u8 temp_a1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        temp_a1 = *(u8 *)(reg_a4 + 2);
        *(u8 *)(reg_a4 + 3) = temp_a1;
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0xE2);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0xE4);
        reg_d3.w = 0xF7000080;
        bullet_fire();
        reg_d0.w = 7;
        reg_d1.w = 0x20;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0xC2);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC4);
        reg_d3.w = 0xF6FFFF80;
        bullet_fire();
        *(u16 *)(reg_a4 + 6) -= 1;
        if (*(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 func_0014E030();

void func_001C0190(void) {
    reg_d0.w = 0x32;
    func_0014E030();
    if (*(s16 *)(reg_a4 + 8) >= 0) {
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    } else {
        reg_tmp2.h[1] = *(u16 *)(reg_a6 + 0xA2);
        reg_tmp2.h[0] = *(u16 *)(reg_a6 + 0xA4);
        reg_d2.w = reg_tmp2.w;
        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
        *(s8 *)(reg_a0 + 0x1B) = 0x30;
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        reg_d0.b[0] += 0x20;
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a0 + 0x1A) = reg_d0.b[0];
    }
    *(s16 *)reg_a4 = 0;
}

void func_001C02B0(void) {
    reg_d6.b[0] = *(u8 *)(reg_a6 + 0x9A);
    reg_d6.b[0] += 0x20;
    reg_d6.b[0] &= 0x3F;
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
    reg_d0.w = 0x32;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    *(u16 *)(reg_a0 + 0x16) = (u16) reg_d2.h[1];
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d2.h[0];
    *(s8 *)(reg_a0 + 0x1B) = 0x18;
    reg_d6.h[0] += 2;
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d6.b[0];
    *(s16 *)reg_a4 = 0;
}

void func_001C0460(void) {
    s32 bullet_fire_fixed();
    reg_d5.b[0] = 2;
    if (g_loop != 0) {
        reg_d5.b[0] = 3;
    }
    reg_d0.w = 0xFFFC0007;
    reg_d1.b[0] -= reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    reg_d0.w = 0xFFFD0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    reg_d0.w = 0xFFFE0007;
    reg_d1.b[0] += reg_d5.b[0];
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    bullet_fire_fixed();
    if (g_loop != 0) {
        reg_d0.w = 0xFFFF0007;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        bullet_fire_fixed();
        reg_d0.w = 7;
        reg_d1.b[0] += reg_d5.b[0];
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.h[0] < 0x10) || ((s32) reg_d1.h[0] > 0x30)) {
            reg_d0.w += 0x80000;
        }
        bullet_fire_fixed();
    }
}


void func_001C0650() {
    *(u8 *)(reg_a4 + 3) = 0;
    *(u8 *)(reg_a4 + 0xB) = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xB) = 0xFF;
    }
    *(u8 *)(reg_a4 + 0xA) = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xA) = 0xFF;
    }
    *(s16 *)(reg_a4 + 6) = 0x1000;
    *(u8 *)(reg_a4 + 9) = 0x20U;
    do {
        rng_next();
    } while (reg_d0.b[0] == 0);
    reg_d0.b[0] += reg_d0.b[0];
    *(u8 *)(reg_a4 + 9) += reg_d0.b[0];
    func_001C0720();
}

s32 direction_turn_toward();
extern u16 g_bullets_blocked;

void func_001C0720(void) {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
        *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
        if (*(u8 *)(reg_a4 + 9) == reg_d1.b[0]) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a6 + 0x9A) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0x9A) &= 0x3F;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                *(u8 *)(reg_a6 + 0xBA) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0xBA) &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += reg_d3.h[0];
                    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w = reg_tmp3.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                    func_001C0460();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += reg_d3.h[0];
                    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d3.w = reg_tmp3.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                    func_001C0460();
                }
                *(u16 *)(reg_a4 + 4) -= 1;
                if (*(u16 *)(reg_a4 + 4) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}

s32 bullet_fire_2way();
extern u16 D_00259870[];

void func_001C0A40(void) {
    reg_a0 = (u8 *)(D_00259870);
    reg_d0.w = 0xFFFA0007;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] += 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] += 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] -= 0x12;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
    reg_d0.w = 0xFFFA0007;
    reg_d1.b[0] -= 6;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] &= 0x3F;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire_2way();
}

s32 rng_next_masked();

void func_001C0F80(void) {
    *(u8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 6) = 0x1002;
    *(s16 *)(reg_a4 + 0xC) = 0x2018;
    *(u8 *)(reg_a4 + 0xB) = 1;
    rng_next_bit(0x2018, 0x1002);
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xB) = 0xFF;
    }
    *(u8 *)(reg_a4 + 0xA) = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xA) = 0xFF;
    }
    rng_next_masked();
    *(u8 *)(reg_a4 + 9) = (u8) reg_d0.b[0];
    rng_next_masked();
    *(u8 *)(reg_a4 + 8) = (u8) reg_d0.b[0];
    func_001C1030();
}


void func_001C1030(void) {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
        if (*(u8 *)(reg_a4 + 9) == reg_d1.b[0]) {
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
            if (*(u8 *)(reg_a4 + 8) == reg_d1.b[0]) {
                *(u8 *)(reg_a4 + 3) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a6 + 0x9A) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0x9A) &= 0x3F;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                *(u8 *)(reg_a6 + 0xBA) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0xBA) &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                    func_001C0A40();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                    func_001C0A40();
                }
                *(u16 *)(reg_a4 + 4) -= 1;
                if (*(u16 *)(reg_a4 + 4) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}

void func_001C1450(void) {
    reg_a0 = (u8 *)(D_00259870);
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] -= 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d0.w = 0xFFFF0007;
    reg_d1.b[0] += 2;
    if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
        reg_d0.w += 0x80000;
    }
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    if (g_loop != 0) {
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] += 1;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        reg_d0.w = 0xFFFD0007;
        reg_d1.b[0] -= 6;
        if (((s32) reg_d1.b[0] < 0x40) || ((s32) reg_d1.b[0] > 0xC0)) {
            reg_d0.w += 0x80000;
        }
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
    }
}


void func_001C1930() {
    *(u8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 6) = 0x1000;
    *(s16 *)(reg_a4 + 0xC) = 0x2010;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x82);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x84);
    aim_at_player();
    reg_d1.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
    aim_at_player();
    reg_d1.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 8) = (u8) reg_d1.b[0];
    *(u8 *)(reg_a4 + 0xB) = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xB) = 0xFF;
    }
    *(u8 *)(reg_a4 + 0xA) = 1;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        func_001C1A30();
        return;
    }
    *(u8 *)(reg_a4 + 0xA) = 0xFF;
    func_001C1A30();
}


void func_001C1A30(void) {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
        reg_d1.b[0] = reg_a6[0x9A];
        if (reg_a4[9] == reg_d1.b[0]) {
            reg_d1.b[0] = reg_a6[0xBA];
            if (reg_a4[8] == reg_d1.b[0]) {
                reg_a4[3] = 1;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
                reg_d1.w = 0;
                reg_d0.w = 0x6000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF210();
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a6 + 0x9A) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0x9A) &= 0x3F;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                *(u8 *)(reg_a6 + 0xBA) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0xBA) &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                    func_001C1450();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d1.b[0] += reg_d1.b[0];
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                    func_001C1450();
                }
                *(u16 *)(reg_a4 + 4) -= 1;
                if (*(u16 *)(reg_a4 + 4) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}

void func_001C1E80(void) {
    s32 bullet_fire_fixed();
    u32 var_a1;
    reg_a0 = (u8 *)(D_00259870);
    reg_d0.w = 7;
    reg_d7.w = 3;
    reg_d1.h[0] &= 0x3F;
    if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
        reg_d0.w = 0x170007;
        reg_d7.w = 1;
    }
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] &= 0x3F;
        reg_d3.h[0] += reg_d3.h[0];
        reg_d3.h[0] += reg_d3.h[0];
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire_fixed();
        var_a1 = reg_d0.w;
        reg_d0.w = var_a1 + 0x20000;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    if (g_loop != 0) {
        reg_d0.w = 7;
        reg_d1.b[0] += 4;
        reg_d7.w = 1;
        reg_d1.h[0] &= 0x3F;
        if (((s32) reg_d1.b[0] < 0x10) || ((s32) reg_d1.b[0] > 0x30)) {
            reg_d7.w = 0;
            reg_d0.w = 0x170007;
        }
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire_fixed();
            var_a1 = reg_d0.w;
            reg_d0.w = var_a1 + 0x20000;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}


void func_001C2120() {
    *(u8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 6) = 0x4400;
    *(s16 *)(reg_a4 + 0xC) = 0x1802;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x82);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x84);
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    *(u8 *)(reg_a4 + 8) = (u8) reg_d1.b[0];
    *(u8 *)(reg_a4 + 0xB) = 1;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 0xB) = 0xFF;
    }
    *(u8 *)(reg_a4 + 0xA) = 1;
    rng_next_bit();
    if (reg_d0.h[0] != 0) {
        func_001C2230();
        return;
    }
    *(u8 *)(reg_a4 + 0xA) = 0xFF;
    func_001C2230();
}


void func_001C2230(void) {
    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a4 + 8);
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
        if (*(u8 *)(reg_a4 + 9) == reg_d1.b[0]) {
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
            if (*(u8 *)(reg_a4 + 8) == reg_d1.b[0]) {
                *(u8 *)(reg_a4 + 3) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            if (g_bullets_blocked == 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x7000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF260();
                reg_d1.w = 0;
                reg_d0.w = 0x7000B;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 0x20;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_001BF260();
            }
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            if (g_bullets_blocked == 0) {
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xB);
                *(u8 *)(reg_a6 + 0x9A) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0x9A) &= 0x3F;
                reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
                *(u8 *)(reg_a6 + 0xBA) += reg_d1.b[0];
                *(u8 *)(reg_a6 + 0xBA) &= 0x3F;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.w = 0;
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
                    func_001C1E80();
                }
                reg_d1.w = 0;
                reg_a0 = (u8 *)(D_0026C1C0);
                reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
                reg_d1.b[0] += 1;
                if (!(reg_d1.w & 1)) {
                    reg_d1.h[0] &= 0x3E;
                    reg_d5.h[0] = reg_d1.h[0];
                    reg_d5.h[0] += reg_d5.h[0];
                    reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
                    reg_d5.w = reg_tmp5.w;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
                    func_001C1E80();
                }
                *(u16 *)(reg_a4 + 4) -= 1;
                if (*(u16 *)(reg_a4 + 4) == 0) {
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}

void func_001C2650(void) {
    reg_a0 = (u8 *)(D_00259770);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    bullet_fire256_fixed();
    reg_d7.h[0] = reg_d1.h[0];
    if (g_loop != 0) {
        reg_d1.b[0] -= 2;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        reg_d1.b[0] += 4;
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
    }
    reg_d6.h[0] = *(u16 *)(reg_a4 + 0x12);
    do {
        reg_d1.b[0] += *(u8 *)(reg_a4 + 0x15);
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        if (g_loop != 0) {
            reg_d0.w += 0xFFFC0000;
            reg_d1.b[0] -= 4;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            reg_d1.b[0] += 4;
        }
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d1.h[0] = reg_d7.h[0];
    reg_d6.h[0] = *(u16 *)(reg_a4 + 0x12);
    do {
        reg_d1.b[0] -= *(u8 *)(reg_a4 + 0x15);
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fixed();
        if (g_loop != 0) {
            reg_d0.w += 0xFFFC0000;
            reg_d1.b[0] += 4;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&reg_tmp3.h[0];
            reg_d3.w += reg_d5.w;
            bullet_fire256_fixed();
            reg_d0.w += 0x40000;
            reg_d1.b[0] -= 4;
        }
    } while ((s16)(--reg_d6.h[0]) >= 0);
}

extern void *reg_a4_as_void_p;

void func_001C2CB0(void)
{
    *((u8 *)reg_a4_as_void_p + 0x03) = 0;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x06) = 0x1004;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x0C) = 0xFFFF;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x0E) = 1;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x10) = 0x0606;
    *(u16 *)((u8 *)reg_a4_as_void_p + 0x12) = 0;
    *((u8 *)reg_a4_as_void_p + 0x15) = 0x0C;
    *((u8 *)reg_a4_as_void_p + 0x14) = 0x0C;
    func_001C2D10();
}

s32 enemy_switch_target_player();
extern u16 D_00259570[];

void func_001C2D10(void) {
    u16 t1;
    u16 t2;
    if (*(s16 *)(reg_a4 + 0xE) < 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x42);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x44);
        aim_at_player();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x5A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x5A) = (u8) reg_d1.b[0];
    } else {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x62);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x64);
        aim_at_player();
        reg_d0.b[0] = *(u8 *)(reg_a6 + 0x7A);
        direction_turn_toward();
        *(u8 *)(reg_a6 + 0x7A) = (u8) reg_d1.b[0];
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
        enemy_switch_target_player();
        if (*(s16 *)(reg_a4 + 0xE) >= 0) {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0x5A);
            t1 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t1;
            reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = reg_tmp5.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x42);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x44);
            func_001C2650();
        } else {
            reg_d1.w = 0;
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.b[0] = *(u8 *)(reg_a6 + 0x7A);
            t2 = reg_d1.h[0];
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d5.h[0] = reg_d1.h[0];
            reg_d5.h[0] += reg_d5.h[0];
            reg_d6.h[0] = t2;
            reg_tmp5.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_tmp5.h[0] = (((reg_d5.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d5.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d5.w = reg_tmp5.w;
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x64);
            func_001C2650();
        }
        *(u8 *)(reg_a4 + 0x15) += 0xA;
        *(u8 *)(reg_a4 + 0x11) -= 1;
        if (*(u8 *)(reg_a4 + 0x11) == 0) {
            *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
            *(u8 *)(reg_a4 + 0x15) = (u8) *(u8 *)(reg_a4 + 0x14);
            *(u16 *)(reg_a4 + 0xE) *= -1;
            *(u16 *)(reg_a4 + 4) -= 1;
            if (*(u16 *)(reg_a4 + 4) == 0) {
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void func_001C3070(void) {
    reg_a4[3] = 0;
    func_001C3080();
}

void func_001C3080(void) {
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x82);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x84);
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x9A);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0x9A) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xA2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xA4);
    aim_at_player();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0xBA);
    direction_turn_toward();
    *(u8 *)(reg_a6 + 0xBA) = (u8) reg_d1.b[0];
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
    *(u8 *)(reg_a4 + 0xD) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
        reg_d0.w = 0x6000B;
        reg_d1.w = 0;
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0x9A);
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x82);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x84);
        reg_d3.w = 0;
        reg_d4.w = 0;
        func_001BF210();
        reg_d1.w = 0;
        reg_d0.w = 0x6000B;
        reg_d1.b[0] = *(u8 *)(reg_a6 + 0xBA);
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0xA2);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0xA4);
        reg_d3.w = 0;
        reg_d4.w = 0;
        func_001BF210();
        *(s16 *)reg_a4 = 0;
    }
}


void func_001C3210() {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 2;
    rng_next();
    reg_d0.b[0] += 0x10;
    *(u8 *)(reg_a4 + 7) = (u8) reg_d0.b[0];
    rng_next();
    reg_d0.b[0] += 0x30;
    *(u8 *)(reg_a4 + 6) = (u8) reg_d0.b[0];
    *(s16 *)(reg_a4 + 0xA) = 0x40;
    *(s16 *)(reg_a4 + 0xC) = 0;
    func_001C3290();
}


void func_001C3290(void) {
    u32 temp_v1;
    u8 temp_v1_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 0xA) < 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u8 *)(reg_a4 + 7) += 1;
        *(u8 *)(reg_a4 + 6) -= 1;
        *(u8 *)(reg_a4 + 0xD) += 1;
        temp_v1 = *(u8 *)(reg_a4 + 0xD) & 0x3F;
        *(u8 *)(reg_a4 + 0xD) = temp_v1;
        if ((temp_v1 == 0) && ((temp_v1_2 = *(u8 *)(reg_a4 + 2), (temp_v1_2 == 0)) || (*(u8 *)(reg_a4 + 2) = (u8) (temp_v1_2 - 1), (*(u8 *)(reg_a4 + 2) == 0)))) {
            *(s16 *)reg_a4 = 0;
            return;
        }
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_d7.b[0] = 0x28;
        reg_d6.b[0] = *(u8 *)(reg_a4 + 6);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x03FFFF00;
        func_001C3450();
        if (*(u8 *)(reg_a4 + 2) != 0) {
            reg_d6.b[0] -= 4;
            func_001C3450();
        }
        reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0x04000100;
        func_001C3450();
        if (*(u8 *)(reg_a4 + 2) != 0) {
            reg_d6.b[0] += 4;
            func_001C3450();
        }
    }
}

void func_001C3450(void)
{
    extern void bullet_fire(u32, u16);
    u32 savedD6;
    u32 adjustedD0;
    u16 lowD6;

    reg_d0.h[0] = 0xFFEA;
    savedD6 = reg_d6.w;
    reg_d3.w = 0;
    reg_d4.w = 0;
    reg_d0.h[0] += reg_d7.h[0];
    adjustedD0 = reg_d0.w;
    lowD6 = reg_d6.h[0];
    reg_d1.h[0] = lowD6;
    reg_tmp.w = adjustedD0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 7;
    bullet_fire(adjustedD0, lowD6);
    reg_d6.w = savedD6;
}


void func_001C34C0(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 4;
    if (g_loop == 0) {
        func_001C3520();
        return;
    }
    *(s16 *)(reg_a4 + 4) = 2;
    func_001C3520();
}

extern u16 D_0026C250[];
extern u16 D_0026C252[];
extern u16 D_0026C254[];
extern u16 D_0026C256[];
extern u16 D_0026C260[];
extern u16 D_0026C262[];
extern u16 D_0026C264[];
extern u16 D_0026C266[];

void func_001C3520(void) {
    u16 t1;
    u16 t2;
    u16 t3;
    u16 t4;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        reg_d6.h[0] = 0x20;
        reg_d7.h[0] = 0x14;
        if (g_loop != 0) {
            reg_d7.h[0] = 0x28;
        }
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t1 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t1;
        reg_tmp2.h[1] = D_0026C250[0];
        reg_tmp2.h[0] = D_0026C252[0];
        reg_d2.w += reg_tmp2.w;
        func_001C3450();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t2 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t2;
        reg_tmp2.h[1] = D_0026C254[0];
        reg_tmp2.h[0] = D_0026C256[0];
        reg_d2.w += reg_tmp2.w;
        func_001C3450();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t3 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t3;
        reg_tmp2.h[1] = D_0026C260[0];
        reg_tmp2.h[0] = D_0026C262[0];
        reg_d2.w += reg_tmp2.w;
        func_001C3450();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        t4 = ENTITY(reg_a6)->x.h;
        reg_d2.h[0] = t4;
        reg_tmp2.h[1] = D_0026C264[0];
        reg_tmp2.h[0] = D_0026C266[0];
        reg_d2.w += reg_tmp2.w;
        func_001C3450();
        *(u16 *)(reg_a4 + 6) -= 1;
        if (*(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 enemy_switch_target_player();                            /* extern */
s32 func_00202730(s32, s32);            /* extern */

void func_001C36B0(void) {
    enemy_switch_target_player();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 0x10) = 8;
    *(s16 *)(reg_a4 + 0x14) = 2;
    *(u8 *)(reg_a4 + 0x13) = 0x80U;
    func_00202730(2, 8);
    if (cond_flag != 0) {
        func_001C3730();
        return;
    }
    *(u8 *)(reg_a4 + 0x13) = (u8) reg_d1.b[0];
    func_001C3730();
}


void func_001C3730(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x11) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
        reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x16);
        func_001C3800(reg_a4);
        *(u16 *)(reg_a4 + 8) += 0xA;
        *(u8 *)(reg_a4 + 7) += 2;
        *(u16 *)(reg_a4 + 0x16) = (u16) *(u16 *)(reg_a4 + 0x18);
        *(u16 *)(reg_a4 + 0x14) -= 1;
        if (*(u16 *)(reg_a4 + 0x14) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 bullet_fire256_fast();

void func_001C3800() {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 temp_a0;
    u32 temp_a0_2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 0x13);
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d5.w = 0x08000000;
    reg_a0 = (u8 *)(D_00259870);
    reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.w = *(u32 *)&reg_tmp3.h[0];
    reg_d3.w += reg_d5.w;
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d4.w = 0;
    bullet_fire256_fast();
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d6.b[0] = reg_d1.b[0];
    if (*(u16 *)(reg_a4 + 0x16) == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fast();
        if (g_loop != 0) {
            temp_a0 = reg_d0.w;
            reg_d0.w = temp_a0 + 0xFFFC0000;
            reg_d1.b[0] -= 2;
            bullet_fire256_fast();
            reg_d1.b[0] += 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 0;
    reg_d7.b[0] = 9;
    reg_d1.b[0] = reg_d6.b[0];
    if (*(u16 *)(reg_a4 + 0x16) == 4) {
        reg_d7.b[0] = 2;
    }
    do {
        reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_tmp3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp3.h[0] = (((u16)reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.w = *(u32 *)&reg_tmp3.h[0];
        reg_d3.w += reg_d5.w;
        bullet_fire256_fast();
        if (g_loop != 0) {
            temp_a0_2 = reg_d0.w;
            reg_d0.w = temp_a0_2 + 0xFFFC0000;
            reg_d1.b[0] += 2;
            bullet_fire256_fast();
            reg_d1.b[0] -= 2;
            reg_d0.w += 0x40000;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

s32 enemy_switch_target_player();                            /* extern */

void func_001C3C40(void) {
    enemy_switch_target_player();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    func_001C3C80();
}

s32 bullet_fire256_double();
s32 bullet_fire256_2way();
s32 func_002012F0();
s32 func_00202730();
extern u16 D_0028E3EC;

void func_001C3C80(void) {
    u8 t;
    u32 c;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    reg_d6.w = 0;
    reg_d7.w = 0;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (!((s32) reg_tmp.w < 0x2F99)) goto loop_1;
    reg_d6.w = 3;
    if (D_0028E3EC != 0) goto loop_1;
    reg_d7.w = 1;
loop_1:
    func_00202730();
    if (cond_flag != 0) goto block_rts;
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    reg_d3.h[0] = reg_d0.h[0];
    func_002012F0();
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 3;
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.w += 0x06000000;
    rng_next();
    reg_d5.h[0] = reg_d0.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
    reg_d0.b[0] += reg_d4.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    rng_next();
    reg_d0.h[0] = (s8) reg_d0.b[0];
    reg_d5.h[0] = (s8) reg_d5.b[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 1;
    reg_d0.h[0] -= 6;
    if ((s16) reg_d5.h[0] >= 0) goto next_1;
    reg_d5.h[0] *= 0xFFFF;
next_1:
    if (reg_d5.h[0] <= 1) goto next_2;
    reg_d0.h[0] += reg_d5.h[0];
next_2:
    reg_d0.h[0] += reg_d6.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0x16;
    reg_d4.w = 0;
    t = *(u8 *)(reg_a4 + 7);
    if (!(t & 1)) goto next_3;
    *(u8 *)(reg_a4 + 7) = t ^ 1;
    goto next_4;
next_3:
    *(u8 *)(reg_a4 + 7) = t ^ 1;
    bullet_fire256_double();
    goto next_5;
next_4:
    bullet_fire256_2way();
next_5:
    c = reg_d7.h[0] - 1;
    reg_d7.h[0] = c;
    if (((s64) ((s64) (c & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}
