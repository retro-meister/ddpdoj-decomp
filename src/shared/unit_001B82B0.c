#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_001B8440(void);
void func_001B8D00(void);

extern s16 *reg_a6_as_s16_p;
extern u16 D_0029AA30[];

void func_001B82B0(void) {
    *reg_a6_as_s16_p = 0;
    D_0029AA30[0] -= 1;
}

extern s32 D_0029A530_as_s32_a[];


void func_001B82D0(void) {
    memset(D_0029A530_as_s32_a, 0, 0x502);
}


extern u32 D_0028E52C;
extern u16 g_loop;
extern u16 g_two_player_game;
extern u16 D_0029A530[];

void func_001B82F0(void) {
    u32 tmp;
    s32 tmp2;

    reg_d3.w = reg_d0.w;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    reg_d3.w &= 0xFF;
    if (reg_d3.w != 0) {
        reg_d3.w -= 0x10000;
    }
loop_1:
    reg_a0 = (u8 *)D_0029A530;
    reg_d1.h[0] = 0x13;
    if ((g_loop != 0) || (g_two_player_game == 0)) {
        reg_d1.h[0] = 9;
    }
loop_2:
    if (*(u16 *)reg_a0 != 0) {
        reg_a0 += 0x40;
        tmp2 = reg_d1.h[0] - 1;
        reg_d1.h[0] = tmp2;
        if (((s64) ((s64) (u16) tmp2 << 0x30) >> 0x30) >= 0) {
            goto loop_2;
        }
        reg_d1.w = 0;
        cond_flag = 1;
        reg_d1.h[0] -= 1;
        return;
    }
    D_0028E52C = reg_d0.w;
    func_001B8D00();
    D_0029AA30[0] += 1;
    reg_d0.w = D_0028E52C;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    cond_flag = 0;
}

extern s32 reg_a5_as_s32;

void func_001B8410(void) {
    s32 temp_s0;

    temp_s0 = reg_a5_as_s32;
    func_001B8440();
    reg_a5_as_s32 = temp_s0;
}

typedef void (*Fn)();

s32 func_00201F20();
extern u8 D_00250780[];
extern u8 D_002507A0[];
extern u8 D_00262570[];
extern u8 D_0027F2F0[];
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 D_0028E854_as_u16;
extern u8 D_0029A530_as_u8_a[];
extern u16 D_0029C06C[];
extern u8 *jtbl_0028E3F4_as_u8_p;

void func_001B8440(void) {
    u32 cnt;
    s32 cnt2;
    u16 swp;
    u8 *save;
    u8 *p;
    s32 idx;

    reg_d7.h[0] = D_0029AA30[0];
    if (reg_d7.h[0] == 0) goto block_rts;
    reg_d7.h[0] -= 1;
    if (g_loop != 0) {
        reg_a6 = (u8 *)D_0029A530_as_u8_a;
        goto next_clr;
    }
    reg_d5.w = 0;
    reg_d6.h[0] = D_0028E3E0;
    reg_d6.h[0] *= 0xFFFF;
    reg_tmp.w = reg_d6.w;
    reg_d6.h[0] = D_0028E3EC;
    reg_d6.h[1] = reg_tmp.h[0];
    if (D_0028E854_as_u16 == 0) goto next_1;
    reg_d5.h[0] = 0x8000;
next_1:
    reg_tmp.w = reg_d5.w;
    reg_d5.h[1] = reg_tmp.h[0];
    reg_d5.h[0] = D_0028E3F0;
    reg_a6 = (u8 *)D_0029A530_as_u8_a;
    goto loop_2;
next_2:
    reg_a6 += 0x40;
loop_2:
    reg_d0.b[0] = ENTITY(reg_a6)->flags.b[1];
    if (reg_d0.b[0] == 0) goto next_2;
    reg_a2 = reg_a6 + 2;
    reg_a4 = reg_a6 + 0x1A;
    if (0 <= (s64) ENTITY(reg_a6)->misc.sh) goto next_3;
    if (0 <= (s64) (s32) reg_d5.w) goto next_dir;
    goto next_boss;
next_3:
    reg_d0.b[0] = reg_a4[1];
    if (reg_d0.b[0] == 0) goto next_4;
    reg_d1.w = 1;
    if (reg_d0.b[0] > 8) goto next_5;
    if (reg_d0.b[0] < 6) goto next_6;
    reg_d1.w = 3;
next_5:
    reg_d1.h[0] &= reg_d5.h[0];
    if (reg_d1.h[0] != 0) goto next_6;
    reg_a4[1] -= 1;
next_6:
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = reg_a4[1];
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    goto next_speed;
next_ret:
    *(u16 *)(reg_a2 + 0) += reg_d2.h[0];
    reg_d0.h[0] = reg_d3.h[0];
    reg_d0.h[0] = (s16) reg_d0.h[0] >> 2;
    reg_d3.h[0] -= reg_d0.h[0];
    *(u16 *)(reg_a2 + 2) += reg_d3.h[0];
next_4:
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_d1.w = 0;
    reg_d1.b[0] = reg_a4[1];
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] -= 0x58;
    *(u16 *)(reg_a2 + 0) += reg_d1.h[0];
next_7:
    reg_d1.h[0] = D_0029C06C[0];
    *(u16 *)(reg_a2 + 2) -= reg_d1.h[0];
    if (0 > (s64) (s32) reg_d6.w) goto next_anim;
    reg_d1.h[1] = *(u16 *)(reg_a2 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_d1.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += 0x7FFF + 0x4001;
    if (reg_tmp.h[1] != 0) goto next_clr;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x8400;
    reg_tmp.w = reg_d1.w;
    swp = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d1.h[1] = swp;
    reg_d1.h[0] += 0x600;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += 0x7FFF + 0x401;
    if (reg_tmp.h[1] != 0) goto next_clr;
    goto next_anim;
next_set:
    if (*(u16 *)(reg_a6 + 0x22) == 0) goto next_8;
    *(u16 *)(reg_a6 + 0x22) -= 1;
    reg_a0 = (u8 *)D_00250780;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn) jtbl_0028E3F4_as_u8_p)();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_8:
    ENTITY(reg_a6)->hp.b[0] -= 1;
    if (ENTITY(reg_a6)->hp.b[0] == 0) goto next_clr;
    if (reg_d6.h[0] == 0) goto next_9;
    reg_a0 = (u8 *)D_00250780;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    jtbl_0028E3F4_as_u8_p = reg_a0;
    ((Fn) jtbl_0028E3F4_as_u8_p)();
next_9:
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_clr:
    func_001B82B0();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_dir:
    if (reg_a4[1] <= 2) goto next_10;
    reg_d1.w = 0;
    if (reg_a4[1] > 8) goto next_11;
    if (reg_a4[1] < 6) goto next_12;
    reg_d1.w = 3;
next_11:
    reg_d1.h[0] &= reg_d5.h[0];
    if (reg_d1.h[0] != 0) goto next_12;
    reg_a4[1] -= 1;
next_12:
    save = reg_a2;
    func_00201F20();
    reg_a2 = save;
next_10:
    *(u16 *)(reg_a2 + 0) -= 0x20;
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    goto next_7;
next_boss:
    save = reg_a2;
    func_00201F20();
    reg_a2 = save;
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_d1.w = 0;
    reg_d0.h[0] = ~(s16) reg_d0.h[0];
    reg_d1.b[0] = reg_a6[0x21];
    *(u16 *)(save + 0) -= reg_d1.h[0];
    if (0 > (s64) (s32) reg_d6.w) goto next_anim;
    reg_d1.h[1] = *(u16 *)(reg_a2 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC000;
    reg_d1.h[0] += 0x400;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += 0x7FFF + 0x4001;
    if (reg_tmp.h[1] != 0) goto next_13;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.w = reg_d1.w;
    swp = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d1.h[1] = swp;
    reg_tmp.h[0] = reg_d1.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d1.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] != 0) goto next_13;
    goto next_anim;
next_13:
    func_001B82B0();
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto block_rts;
next_speed:
    idx = reg_d1.h[0] * 2;
    reg_d3.h[0] = *(u16 *)(D_002507A0 + idx);
    p = D_00262570 + reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(p + 0);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(p + 2);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d1.h[0] &= 0xC0;
    reg_d3.w = (s32) reg_d3.w >> 4;
    if (reg_d1.h[0] == 0) goto next_ret;
    if (reg_d1.h[0] != 0x40) goto next_14;
    reg_d2.h[0] *= 0xFFFF;
    goto next_ret;
next_14:
    if (reg_d1.h[0] != 0x80) goto next_15;
    reg_d2.h[0] *= 0xFFFF & 0xFFFF;
    reg_d3.h[0] *= 0xFFFF;
    goto next_ret;
next_15:
    if (reg_d1.h[0] != 0xC0) goto next_16;
    reg_d3.h[0] *= 0xFFFF;
    goto next_ret;
next_16:
    printf((const char *)D_0027F2F0);
    goto block_rts;
next_anim:
    reg_d2.w = 3;
    if (reg_a4[1] > 0xD) goto next_17;
    reg_d2.w = 1;
    if (reg_a4[1] > 9) goto next_17;
    reg_d2.w = 0;
next_17:
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    idx = reg_d0.h[0] + 2;
    ENTITY(reg_a6)->sprite.h = (idx) ? *(u16 *)(reg_a0 + ((s16) idx & ~1)) : *(u16 *)reg_a0;
loop_18:
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
    ENTITY(reg_a6)->hit_y_plus.h -= 4;
    if (reg_tmp.h[0] > 3) goto next_19;
    ENTITY(reg_a6)->hit_y_plus.h = ENTITY(reg_a6)->hit_y_minus.h;
next_19:
    cnt2 = reg_d2.h[0] - 1;
    reg_d2.h[0] = cnt2;
    if (((s64) ((s64) (u16) cnt2 << 0x30) >> 0x30) >= 0) goto loop_18;
    goto next_set;
block_rts:
    return;
}

extern u8 D_002509E0[];
s32 rng_next();
s32 func_00201130();
s32 rng_next_masked();
s32 rng_next_unsigned();
s32 rng_next_bit();
s32 func_00201390();
extern u16 D_00250CE0[];
extern u8 D_0028E52F;
extern void (*jtbl_0028E3F4)();

void func_001B8D00(void) {
    u8 flag;

    reg_a2 = (u8 *)(D_00250CE0);
    reg_d4.h[0] = 0x8000;
    reg_d0.h[0] >>= 8;
    reg_d1.b[0] = reg_d0.b[0];
    if (0 > reg_d1.sb[0]) {
        reg_d0.b[0] = ~(s8)(reg_d0.b[0]);
        if (reg_d0.h[0] & 1) {
            reg_d0.h[0] &= 0xFFFE;
            reg_d4.h[0] |= 0x400;
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] = ~(s8) reg_d1.b[0];
        }
    }
    reg_d1.h[0] = (u16) (s8) reg_d1.b[0];
    reg_d0.h[0] &= 0x1C;
    reg_d2.h[0] = reg_d0.h[0];
    reg_a2 = *(u8 **)((u8 *)D_00250CE0 + (reg_d0.h[0] & ~3));
    *(u16 *)reg_a0 = reg_d4.h[0];
    *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
    *(u16 *)(reg_a0 + 4) = (u16) ENTITY(reg_a6)->x.h;
    if (0 > (s32) reg_d3.w) {
        func_00201390();
        *(u16 *)(reg_a0 + 4) += reg_d4.h[0];
    }
    *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = reg_d0.h[0];
    reg_d4.h[0] &= 0xFF00;
    rng_next_bit();
    if (reg_d0.b[0] == 0) {
        reg_d4.h[0] |= 0x1000;
    }
    reg_d4.h[0] <<= 8;
    reg_d4.h[0] = (u16) reg_d4.b[0];
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_d4.h[0];
    *(u8 *)(reg_a0 + 0x1D) = 0U;
    *(s8 *)(reg_a0 + 0x1C) = 0x1E;
    reg_d0.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 0xE) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a0 + 0x14) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 0x20) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    *(u16 *)(reg_a0 + 0x18) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    rng_next_unsigned();
    reg_d0.b[0] &= 0xF;
    reg_d0.b[0] += 0x1A;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
    *(u16 *)(reg_a0 + 0x10) = (u16) *(u16 *)reg_a2;
    *(u16 *)(reg_a0 + 0x12) = (u16) *(u16 *)reg_a2;
    reg_a2 += 2;
    func_00201130();
    reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
    reg_d0.h[0] += 0x30;
    *(u16 *)(reg_a0 + 0x22) = (u16) reg_d0.h[0];
    reg_a1 = (u8 *)D_002509E0;
    reg_a1 += reg_d2.h[0];
    reg_a1 = *(u8 **)reg_a1;
    jtbl_0028E3F4 = (Fn)(reg_a1);
    jtbl_0028E3F4();
    if (0 > (s16) reg_d1.h[0]) {
        reg_d0.h[0] = *(u16 *)(reg_a0 + 0x20);
        reg_d0.b[0] += 0x10;
        *(u8 *)(reg_a0 + 0x21) = (u8) reg_d0.b[0];
        rng_next_unsigned();
        reg_d0.h[0] &= 0xF;
        if (*(u8 *)(reg_a0 + 1) & 4) {
            reg_d0.b[0] >>= 1;
            *(u8 *)(reg_a0 + 0x1B) -= 8;
        }
        *(u8 *)(reg_a0 + 0x1B) += reg_d0.b[0];
        reg_d0.b[0] = *(u8 *)(reg_a0 + 0x1B);
        reg_d0.b[0] += 0x20;
        *(u8 *)(reg_a0 + 0x27) = (u8) reg_d0.b[0];
        rng_next();
        reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
        reg_d0.b[0] += D_0028E52F;
    } else {
        rng_next_masked();
        if (((s32) reg_d0.h[0] > 0x15) && ((s32) reg_d0.h[0] < 0x2B)) {
            reg_d0.h[0] += 0x20;
            reg_d0.h[0] &= 0x3F;
        }
        flag = *(u8 *)(reg_a0 + 0x1E);
        if (flag & 0x20) {
            *(u8 *)(reg_a0 + 0x1E) = flag & 0xDF;
            reg_d0.h[0] += 0x16;
            reg_d0.h[0] &= 0x3F;
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
            reg_d0.h[0] += 0x15;
        }
    }
    reg_d1.h[0] = reg_d0.h[0];
    if ((s32) reg_d1.b[0] >= 0x20) {
        *(u8 *)(reg_a0 + 0x1D) |= 0x20;
    }
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d1.b[0];
}

s32 func_00201270();
extern u8 D_00250CD0[];

void func_001B91C0(void) {
    func_00201270();
    reg_a1 = D_00250CD0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    *(u16 *)(reg_a0 + 0x14) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a1 + 2);
    func_00201270();
    reg_d0.h[0] += 1;
    reg_d0.h[0] <<= 5;
    reg_d0.h[0] -= 4;
    *(u16 *)(reg_a0 + 0x10) -= reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x14);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x16);
    reg_a1 = (u8 *) reg_tmp.w;
    *(u16 *)(reg_a0 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
}

void func_001B9300(void) {
    func_00201270();
    reg_d0.h[0] += 1;
    reg_d0.h[0] <<= 5;
    reg_d0.h[0] -= 4;
    *(u16 *)(reg_a0 + 0x10) -= reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x14);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x16);
    reg_a1 = (u8 *)(reg_tmp.w);
    *(u16 *)(reg_a0 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    *(u16 *)(reg_a0 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
}
