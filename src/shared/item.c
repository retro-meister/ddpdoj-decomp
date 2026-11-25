#include "common.h"
#include "entity.h"

void func_0016AF30(void);
void func_0016AF90(void);
void func_0016B360(void);
void func_0016B3B0(void);
void func_0016B780(void);
void func_0016B7F0(void);
void func_0016BAF0(void);
void func_0016BCC0(void);
void func_0016BD50(void);
void func_0016BFD0(void);
void func_0016C0B0(void);
void func_0016C0C0(void);
void func_0016C260(void);
void func_0016C2A0(void);
void func_0016C350(void);
void func_0016C410(void);

extern u8 D_002BB4B0[];
extern u8 D_002BB6B0[];
extern u8 D_002BB730[];
extern u8 D_002BB7B0[];
extern u8 D_002BB930[];
extern u8 D_002BBAB0[];

void func_0016A8F0(void) {
    if (reg_d0.h[0] == 0) {
        reg_a0 = (u8 *)D_002BB4B0;
        reg_d2.h[0] = 7;
        return;
    }
    if (reg_d0.h[0] == 4) {
        reg_a0 = (u8 *)D_002BB6B0;
        reg_d2.h[0] = 1;
        return;
    }
    if (reg_d0.h[0] == 8) {
        reg_a0 = (u8 *)D_002BB730;
        reg_d2.h[0] = 1;
        return;
    }
    if (reg_d0.h[0] == 12) {
        reg_a0 = (u8 *)D_002BB7B0;
        reg_d2.h[0] = 5;
        return;
    }
    if (reg_d0.h[0] == 20) {
        reg_a0 = (u8 *)D_002BB930;
        reg_d2.h[0] = 5;
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_002BBAB0;
}


extern void func_0016C770(void);

void func_0016A9B0(void)
{
    func_0016A8F0();
    do {
        if (*(u16 *)reg_a0 == 0) {
            func_0016C770();
            return;
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d2.h[0]) >= 0);

    reg_d2.w = 0;
    cond_flag = 1;
    reg_d2.h[0] -= 1;
}

extern void func_0016CA20(void);

void func_0016AA30(void) {
    func_0016A8F0();
    do {
        if (*(u16 *)reg_a0 == 0) {
            func_0016CA20();
            cond_flag = 0;
            return;
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d2.h[0]) >= 0);
    reg_d2.w = 0;
    cond_flag = 1;
    reg_d2.h[0] -= 1;
}

extern s16 D_0028E7AC_as_s16;
extern s16 D_0028E7B0_as_s16;

void func_0016AAB0(void) {
    u8 *p0;
    u8 *p2;
    u8 *p3;
    u8 *p4;
    u8 *p5;
    s32 n0;
    u8 *p1;
    s32 n1;
    s32 n2;
    s32 n3;
    s32 n4;
    s32 n5;

    n0 = 0;
    do {
        p1 = (D_002BB4B0 + n0);
        p1[0] = 0;
        n0 += 8;
        p1[1] = 0;
        p1[2] = 0;
        p1[3] = 0;
        p1[4] = 0;
        p1[5] = 0;
        p1[6] = 0;
        p1[7] = 0;
    } while (n0 < 0x200);
    n1 = 0;
    do {
        p0 = (D_002BB4B0 + 0x200 + n1);
        p0[0] = 0;
        n1 += 8;
        p0[1] = 0;
        p0[2] = 0;
        p0[3] = 0;
        p0[4] = 0;
        p0[5] = 0;
        p0[6] = 0;
        p0[7] = 0;
    } while (n1 < 0x80);
    n2 = 0;
    do {
        p2 = (D_002BB4B0 + 0x280 + n2);
        p2[0] = 0;
        n2 += 8;
        p2[1] = 0;
        p2[2] = 0;
        p2[3] = 0;
        p2[4] = 0;
        p2[5] = 0;
        p2[6] = 0;
        p2[7] = 0;
    } while (n2 < 0x80);
    n3 = 0;
    do {
        p3 = (D_002BB4B0 + 0x300 + n3);
        p3[0] = 0;
        n3 += 8;
        p3[1] = 0;
        p3[2] = 0;
        p3[3] = 0;
        p3[4] = 0;
        p3[5] = 0;
        p3[6] = 0;
        p3[7] = 0;
    } while (n3 < 0x180);
    n4 = 0;
    do {
        p4 = (D_002BB4B0 + 0x480 + n4);
        p4[0] = 0;
        n4 += 8;
        p4[1] = 0;
        p4[2] = 0;
        p4[3] = 0;
        p4[4] = 0;
        p4[5] = 0;
        p4[6] = 0;
        p4[7] = 0;
    } while (n4 < 0x180);
    n5 = 0;
    do {
        p5 = (D_002BB4B0 + 0x600 + n5);
        p5[0] = 0;
        n5 += 8;
        p5[1] = 0;
        p5[2] = 0;
        p5[3] = 0;
        p5[4] = 0;
        p5[5] = 0;
        p5[6] = 0;
        p5[7] = 0;
    } while (n5 < 0x40);
    D_0028E7B0_as_s16 = 0;
    D_0028E7AC_as_s16 = 0;
}

typedef void (*Fn)();

s32 func_0016C4B0();
extern u8 D_0026ADA0[];
extern u16 D_0028E7B0;
extern u16 g_side_scroll_step[];

void func_0016AC30(void) {
    u32 cnt;
    u8 flags;

    reg_d7.h[0] = D_0028E7B0;
    if (D_0028E7B0 == 0) {
        return;
    }
    reg_d7.h[0] -= 1;
    reg_a6 = (u8 *)D_002BB4B0;
    goto loop_1;
next_1:
    reg_a6 += 0x40;
loop_1:
    reg_d1.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    reg_d0.h[0] = g_side_scroll_step[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    flags = ENTITY(reg_a6)->flags.b[0];
    if ((flags & 0x80) || (flags & 1)) {
        func_0016C4B0();
        goto next_2;
    }
    reg_d0.w = 0x3C;
    reg_d0.h[0] &= reg_d1.h[0];
    ((Fn) *(u32 *)(D_0026ADA0 + (reg_d0.h[0] & ~3)))();
next_2:
    reg_a6 += 0x40;
    cnt = reg_d7.h[0] - 1;
    reg_d7.h[0] = cnt;
    if (((s64) ((s64) (cnt & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}


void item_kind7(void)
{
}


s32 p1_power_up();
s32 p2_power_up();
s32 sfx_item_pickup();
s32 voice_power_up();
s32 sprite_draw_with_items();
extern u32 D_0026ADC0[];
extern u32 D_0026AFC0[];

void item_powerup(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (!(reg_d1.w & 0x2000)) {
        *(u8 *)(reg_a6 + 1) |= 0x20;
        func_0016AF30();
        *(s16 *)(reg_a6 + 0xC) = 0x202;
        *(u16 *)(reg_a6 + 0xE) = 0U;
    }
    t2 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t2;
    if (t2 & 0xFFFF) {
        if (!(reg_d1.w & 0x1000)) goto next_2;
        p1_power_up();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
next_1:
        sfx_item_pickup();
        voice_power_up();
        reg_a0 = (u8 *)(D_0026AFC0);
        func_0016C2A0();
        return;
next_2:
        p2_power_up();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
    }
    func_0016AF90();
    if (cond_flag == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0xF;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFA00 & 0xFFFF;
        reg_tmp1.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = reg_tmp1.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADC0);
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t3 = *(u32 *)reg_a0;
        reg_d2.w = t3;
        reg_d3.h[0] = 0x618;
        reg_d4.h[0] = 0x1B;
        sprite_draw_with_items();
    }
}

extern void rng_next_masked(void);

void func_0016AF30(void)
{
    ((u16 *)((void *)reg_a6))[0xC] = 0x700;
    ((u16 *)((void *)reg_a6))[0xD] = 0xB00;
    rng_next_masked();
    reg_d0.b[0] >>= 1;
    reg_d0.b[0] += 0x10;
    ((u8 *)((void *)reg_a6))[0x1A] = reg_d0.b[0];
}

s32 rng_next();
s32 entity_velocity();
s32 entity_check_bounds();
extern u8 g_boss_present_b1;
extern u16 g_enemies_stopped;

void func_0016AF90(void) {
    s32 func_0016C260();
    if (g_boss_present_b1 & 0x40) {
        goto block_7;
    }
    switch (ENTITY(reg_a6)->hp.h) {
    case 0:
        goto block_7;
    }
    if (g_enemies_stopped == 0) {
        ENTITY(reg_a6)->hp.h -= 1;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x800;
    if (reg_d0.h[0] <= 0xB00) {
        goto block_6;
    }
    if (reg_d0.h[0] < 0x3D00) {
        goto next_2;
    }
    ENTITY(reg_a6)->x.h = 0x3500;
    if (ENTITY(reg_a6)->move.b.dir > 0x20) {
        goto next_2;
    }
    if (ENTITY(reg_a6)->y.h < 0x2B00) {
        goto block_1;
    }
    ENTITY(reg_a6)->move.b.dir = 0x18;
    goto block_1;
block_6:
    ENTITY(reg_a6)->x.h = 0x300;
    if (ENTITY(reg_a6)->move.b.dir < 0x20) {
        goto next_2;
    }
    if (ENTITY(reg_a6)->y.h < 0x2B00) {
        goto block_1;
    }
    ENTITY(reg_a6)->move.b.dir = 0x28;
block_1:
    ENTITY(reg_a6)->move.b.dir *= -1;
    rng_next();
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
next_2:
    if (ENTITY(reg_a6)->y.h >= 0x6D00) {
        goto block_3;
    }
    if (ENTITY(reg_a6)->y.h <= 0x700) {
        goto block_4;
    }
    goto block_7;
block_3:
    if (ENTITY(reg_a6)->move.b.dir < 0x10) {
        goto block_5;
    }
    if (ENTITY(reg_a6)->move.b.dir > 0x30) {
        goto block_5;
    }
    goto block_7;
block_4:
    if (ENTITY(reg_a6)->move.b.dir <= 0x10) {
        goto block_7;
    }
    if (ENTITY(reg_a6)->move.b.dir > 0x30) {
        goto block_7;
    }
block_5:
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir *= -1;
    rng_next();
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
block_7:
    entity_velocity();
    cond_flag = 0;
    entity_check_bounds();
    if (cond_flag != 0) {
        func_0016C260();
    }
}

s32 p1_power_max();
s32 p2_power_max();
extern u32 D_0026ADD0[];

void item_max_powerup(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (!(reg_d1.w & 0x2000)) {
        *(u8 *)(reg_a6 + 1) |= 0x20;
        func_0016B360();
        *(s16 *)(reg_a6 + 0xC) = 0x202;
        *(u16 *)(reg_a6 + 0xE) = 0U;
    }
    t2 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t2;
    if (t2 & 0xFFFF) {
        if (!(reg_d1.w & 0x1000)) goto next_2;
        p1_power_max();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
next_1:
        sfx_item_pickup();
        voice_power_up();
        reg_a0 = (u8 *)(D_0026AFC0);
        func_0016C2A0();
        return;
next_2:
        p2_power_max();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
    }
    func_0016B3B0();
    if (cond_flag == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0xF;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFC00 & 0xFFFF;
        reg_tmp1.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = reg_tmp1.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADD0);
        reg_d1.h[0] += 0x7FFF + 0x7C01;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t3 = *(u32 *)reg_a0;
        reg_d2.w = t3;
        reg_d3.h[0] = 0x420;
        reg_d4.h[0] = 0x1B;
        sprite_draw_with_items();
    }
}

void func_0016B360(void)
{
    *(u16 *)((u8 *)((void *)reg_a6) + 0x18) = 0x700;
    *(u16 *)((u8 *)((void *)reg_a6) + 0x1A) = 0xB00;
    rng_next_masked();
    *((u8 *)((void *)reg_a6) + 0x1A) = reg_d0.b[0];
    *((u8 *)((void *)reg_a6) + 0x1A) |= 8;
}

void func_0016B3B0(void) {
    s32 func_0016C260();
    if (g_boss_present_b1 & 0x40) {
        goto block_7;
    }
    switch (ENTITY(reg_a6)->hp.h) {
    case 0:
        goto block_7;
    }
    if (g_enemies_stopped == 0) {
        ENTITY(reg_a6)->hp.h -= 1;
    }
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x800;
    if (reg_d0.h[0] <= 0xB00) {
        goto block_6;
    }
    if (reg_d0.h[0] < 0x3D00) {
        goto next_2;
    }
    ENTITY(reg_a6)->x.h = 0x3500;
    if (ENTITY(reg_a6)->move.b.dir > 0x20) {
        goto next_2;
    }
    if (ENTITY(reg_a6)->y.h < 0x2B00) {
        goto block_1;
    }
    ENTITY(reg_a6)->move.b.dir = 0x18;
    goto block_1;
block_6:
    ENTITY(reg_a6)->x.h = 0x300;
    if (ENTITY(reg_a6)->move.b.dir < 0x20) {
        goto next_2;
    }
    if (ENTITY(reg_a6)->y.h < 0x3500) {
        goto block_1;
    }
    ENTITY(reg_a6)->move.b.dir = 0x28;
block_1:
    ENTITY(reg_a6)->move.b.dir *= -1;
    rng_next();
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
next_2:
    if (ENTITY(reg_a6)->y.h >= 0x6D00) {
        goto block_3;
    }
    if (ENTITY(reg_a6)->y.h <= 0x700) {
        goto block_4;
    }
    goto block_7;
block_3:
    if (ENTITY(reg_a6)->move.b.dir < 0x10) {
        goto block_5;
    }
    if (ENTITY(reg_a6)->move.b.dir > 0x30) {
        goto block_5;
    }
    goto block_7;
block_4:
    if (ENTITY(reg_a6)->move.b.dir <= 0x10) {
        goto block_7;
    }
    if (ENTITY(reg_a6)->move.b.dir > 0x30) {
        goto block_7;
    }
block_5:
    ENTITY(reg_a6)->move.b.dir += 0x20;
    ENTITY(reg_a6)->move.b.dir *= -1;
    rng_next();
    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
    ENTITY(reg_a6)->move.b.dir &= 0x3F;
block_7:
    entity_velocity();
    cond_flag = 0;
    entity_check_bounds();
    if (cond_flag != 0) {
        func_0016C260();
    }
}

s32 p1_bomb_item_take();
s32 p2_bomb_item_take();
s32 voice_bomb();
extern u32 D_0026ADE0[];
extern u32 D_0026AEC0[];

void item_bomb(void) {
    u32 t1;
    u32 t2;
    u32 t3;

    if (!(reg_d1.w & 0x2000)) {
        *(u8 *)(reg_a6 + 1) |= 0x20;
        func_0016B780();
        *(s16 *)(reg_a6 + 0xC) = 0x202;
        *(u16 *)(reg_a6 + 0xE) = 0U;
    }
    t2 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t2;
    if (t2 & 0xFFFF) {
        if (!(reg_d1.w & 0x1000)) goto next_2;
        p1_bomb_item_take();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
next_1:
        sfx_item_pickup();
        voice_bomb();
        reg_a0 = (u8 *)(D_0026AEC0);
        func_0016C2A0();
        return;
next_2:
        p2_bomb_item_take();
        if (cond_flag == 0) goto next_1;
        func_0016C350();
        return;
    }
    func_0016B7F0();
    if (cond_flag == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0xF;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFA00 & 0xFFFF;
        reg_tmp1.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = reg_tmp1.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADE0);
        reg_d1.h[0] += 0x7FFF + 0x7D01;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t3 = *(u32 *)reg_a0;
        reg_d2.w = t3;
        reg_d3.h[0] = 0x618;
        reg_d4.h[0] = 0x1B;
        sprite_draw_with_items();
    }
}

void func_0016B780(void)
{
    extern void func_002021D0(void);
    u16 savedD1;

    ENTITY(reg_a6)->hp.h = 0x700;
    ENTITY(reg_a6)->move.h = 0xB20;
    savedD1 = reg_d1.h[0];
    reg_d2.h[0] = 0x4600;
    reg_d3.h[0] = 0x1C00;
    func_002021D0();
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    reg_d1.h[0] = savedD1;
    ENTITY(reg_a6)->misc.h = 0x714;
}

s32 func_00202B50();
extern u16 g_frame_mod8;

void func_0016B7F0(void) {
    s32 func_0016C260();
    s32 func_002021D0();
    if (!(g_boss_present_b1 & 0x40)) {
        if (!(ENTITY(reg_a6)->flags.b[1] & 1)) {
            if (g_frame_mod8 == 0) {
                reg_d2.h[0] = 0x4600;
                reg_d3.h[0] = 0x1C00;
                func_002021D0();
                ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
            }
            reg_d2.h[0] = 0x4600;
            reg_d3.h[0] = 0x1C00;
            func_00202B50();
            if ((s32) reg_d0.h[0] < 0x201) {
                ENTITY(reg_a6)->flags.b[1] |= 1;
                ENTITY(reg_a6)->move.sb.speed = 0xA;
                reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
                reg_d0.b[0] -= 8;
                ENTITY(reg_a6)->move.b.dir = 0x40U;
                if (reg_d0.w & 0x10) {
                    ENTITY(reg_a6)->move.b.dir -= 0x10;
                }
                if (reg_d0.w & 0x20) {
                    ENTITY(reg_a6)->move.b.dir -= 0x20;
                } else {
                    ENTITY(reg_a6)->move.b.dir = 0U;
                }
            }
        } else if (g_enemies_stopped == 0) {
            ENTITY(reg_a6)->hp.h -= 1;
            if ((s16) ENTITY(reg_a6)->hp.h >= 0) {
                ENTITY(reg_a6)->misc.b.user -= 1;
                if (ENTITY(reg_a6)->misc.b.user == 0) {
                    ENTITY(reg_a6)->move.b.dir += 0x10;
                    ENTITY(reg_a6)->move.b.dir &= 0x3F;
                    if (g_enemies_stopped == 0) {
                        ENTITY(reg_a6)->misc.b.draw_layer += 8;
                    }
                    ENTITY(reg_a6)->misc.b.user = (u8) ENTITY(reg_a6)->misc.b.draw_layer;
                }
            }
        }
    }
    entity_velocity();
    cond_flag = 0;
    entity_check_bounds();
    if (cond_flag != 0) {
        func_0016C260();
    }
}

s32 func_00125EB0();
s32 p1_hyper_item_take();
s32 sfx_hyper_pickup();
extern u8 D_0026AF40[];
extern u16 g_frame_mod2;
extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_active;
extern u16 D_0028E958_as_u16;

void item_hyper_p1(void) {
    s32 func_0016C260();
    u32 saved_d7;

    if (!(reg_d1.w & 0x2000)) {
        ENTITY(reg_a6)->flags.b[1] |= 0x20;
        func_0016BCC0();
        if (ENTITY(reg_a6)->look.sh < 0) {
            ENTITY(reg_a6)->x.sh = 0x1400;
        }
        ENTITY(reg_a6)->sprite.sh = 0x202;
        ENTITY(reg_a6)->look.sh = 0;
    }
    if (D_0028E958_as_u16 != 0) {
        func_0016C260();
        return;
    }
    if (g_p1_hyper_active == 0) {
        goto next_1;
    }
block_10:
    saved_d7 = reg_d7.w;
    reg_d0.w = 0x1C;
    reg_d2.w = 5;
    func_00125EB0();
    reg_d7.w = saved_d7;
    func_0016C260();
    return;
next_1:
    reg_d0.h[0] = g_p1_hyper_items;
    if (reg_d0.h[0] == 5) {
        goto block_10;
    }
    reg_d4.h[0] = 5;
    if (reg_d0.h[0] == 4) {
        if (g_frame_mod2 == 0) {
            reg_d4.h[0] = 5;
        }
    }
    reg_d2.w = 0xB5A;
    reg_d5.w = 0xF900FA00;
    if (!(reg_d1.w & 0x1000)) {
        func_0016BAF0();
        return;
    }
    p1_hyper_item_take();
    sfx_hyper_pickup();
    reg_a0 = (u8 *)D_0026AF40;
    func_0016C2A0();
    return;
}

extern u32 D_0026ADF0[];

void func_0016BAF0(void) {
    u32 t1;
    u32 t2;

    func_0016BD50();
    if (cond_flag == 0) {
        *(u8 *)(reg_a6 + 0xD) -= 1;
        if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
            *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
            *(u16 *)(reg_a6 + 0xE) += 4;
            *(u16 *)(reg_a6 + 0xE) &= 0x3F;
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = reg_tmp1.h[1];
        reg_tmp5.w = reg_d5.w;
        reg_d5.h[1] = reg_d5.h[0];
        reg_d5.h[0] = reg_tmp5.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d1.h[0] += reg_d5.h[0];
        reg_d3.h[0] = 0x638;
        sprite_draw_with_items();
        if (g_frame_mod2 != 0) {
            reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] += 0xFC00;
            reg_tmp1.w = reg_d1.w;
            reg_d1.h[1] = reg_d1.h[0];
            reg_d1.h[0] = reg_tmp1.h[1];
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d2.w = 0xB5C;
            reg_d1.h[0] += 0xFD00;
            reg_d3.h[0] = 0x418;
            sprite_draw_with_items();
        }
        reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] += 0xFC00;
        reg_tmp1.w = reg_d1.w;
        reg_d1.h[1] = reg_d1.h[0];
        reg_d1.h[0] = reg_tmp1.h[1];
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_a0 = (u8 *)(D_0026ADF0);
        reg_d1.h[0] += 0xFD00;
        t1 = *(u16 *)(reg_a6 + 0xE);
        reg_a0 += t1;
        t2 = *(u32 *)reg_a0;
        reg_d2.w = t2;
        reg_d3.h[0] = 0x418;
        sprite_draw_with_items();
    }
}

extern u8 D_00269490[];

void func_0016BCC0(void) {
    (ENTITY(reg_a6)->hp.sb[0]) = 1;
    reg_d0.h[0] = (ENTITY(reg_a6)->misc.h);
    reg_a0 = D_00269490;
    reg_a0 += reg_d0.h[0];
    (ENTITY(reg_a6)->misc.h) = *(u16 *)reg_a0;
    reg_a0 += 2;
    (ENTITY(reg_a6)->move.h) = *(u16 *)reg_a0;
    reg_a0 += 2;
    (ENTITY(reg_a6)->attr.h) = *(u16 *)reg_a0;
    reg_a0 += 2;
}

extern u16 D_00269490_as_u16_a[];

void func_0016BD50(void) {
    s32 func_0016C260();
    u32 temp_a1;
    u8 temp_v1;

    if (g_enemies_stopped == 0) {
        temp_v1 = ENTITY(reg_a6)->hp.b[0];
        reg_d1.b[0] = temp_v1;
        if (temp_v1 != 0) {
            ENTITY(reg_a6)->y.h -= 0x40;
            if (((s8) reg_d1.b[0] >= 0) && ((s32) ENTITY(reg_a6)->y.h < 0x800)) {
                ENTITY(reg_a6)->hp.b[0] = 0U;
            }
            goto block_7;
        }
        ENTITY(reg_a6)->y.h += 0x18;
        reg_d0.h[0] = ENTITY(reg_a6)->y.h;
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x8800;
        reg_tmp.w = 0;
        reg_tmp.h[0] = reg_d0.h[0];
        temp_a1 = reg_tmp.w;
        reg_tmp.w = temp_a1 + reg_tmp1.w;
        reg_d0.h[0] += 0x7FFF + 0x801;
        if (reg_tmp.h[1] != 0) {
            func_0016C260();
            return;
        }
block_7:
        ENTITY(reg_a6)->misc.b.draw_layer -= 1;
        if (ENTITY(reg_a6)->misc.b.draw_layer == 0) {
            reg_d0.w = 0;
            reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
            reg_a0 = (u8 *)(D_00269490_as_u16_a);
            reg_a0 += reg_d0.h[0];
            ENTITY(reg_a6)->misc.h = *(u16 *)reg_a0;
            reg_a0 += 2;
            ENTITY(reg_a6)->move.h = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            ENTITY(reg_a6)->attr.h = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
        }
        reg_d0.h[0] = ENTITY(reg_a6)->move.h;
        reg_d1.h[0] = ENTITY(reg_a6)->attr.h;
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        ENTITY(reg_a6)->x.h += reg_d1.h[0];
        goto block_10;
    }
block_10:
    reg_d0.w = 0;
    cond_flag = 0;
}

s32 p1_life_add();
s32 p2_life_add();
s32 sfx_extend();
extern u8 D_0026AE40[];

void item_extend(void) {
    u32 temp_v0;

    if (!(reg_d1.w & 0x2000)) {
        ENTITY(reg_a6)->flags.b[1] |= 0x20;
        func_0016C0B0();
        ENTITY(reg_a6)->sprite.sh = 0x202;
        ENTITY(reg_a6)->look.sh = 0;
    }
    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        sfx_extend();
        if (reg_d1.w & 0x1000) {
            p1_life_add();
        } else {
            p2_life_add();
        }
        reg_a0 = D_0026AE40;
        func_0016C2A0();
        return;
    }
    func_0016C0C0();
    if (cond_flag == 0) {
        func_0016BFD0();
    }
}

extern u32 D_0026AE30[];

void func_0016BFD0(void) {
    u16 temp_a1;
    u32 temp_a0;

    *(u8 *)(reg_a6 + 0xD) -= 1;
    if ((s8) *(u8 *)(reg_a6 + 0xD) < 0) {
        *(u8 *)(reg_a6 + 0xD) = (u8) *(u8 *)(reg_a6 + 0xC);
        *(u16 *)(reg_a6 + 0xE) += 4;
        *(u16 *)(reg_a6 + 0xE) &= 0xF;
    }
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] += 0xFC00 & 0xFFFF;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_a0 = (u8 *)(D_0026AE30);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    temp_a1 = *(u16 *)(reg_a6 + 0xE);
    reg_a0 += temp_a1;
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1C;
    sprite_draw_with_items();
}

void func_0016C0B0(void) {
}

s32 func_00201BE0();

void func_0016C0C0() {
    s32 func_0016C260();
    func_00201BE0();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    cond_flag = 0;
    entity_check_bounds();
    if (cond_flag != 0) {
        func_0016C260();
    }
}

s32 p2_hyper_item_take();
extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_active;

void item_hyper_p2(void) {
    s32 func_0016C260();
    u32 saved_d7;

    if (!(reg_d1.w & 0x2000)) {
        ENTITY(reg_a6)->flags.b[1] |= 0x20;
        func_0016BCC0();
        if (ENTITY(reg_a6)->look.sh < 0) {
            ENTITY(reg_a6)->x.sh = 0x2400;
        }
        ENTITY(reg_a6)->sprite.sh = 0x202;
        ENTITY(reg_a6)->look.sh = 0;
    }
    if (D_0028E958_as_u16 != 0) {
        func_0016C260();
        return;
    }
    if (g_p2_hyper_active == 0) {
        goto next_1;
    }
block_10:
    saved_d7 = reg_d7.w;
    reg_d0.w = 0x1C;
    reg_d2.w = 5;
    func_00125EB0();
    reg_d7.w = saved_d7;
    func_0016C260();
    return;
next_1:
    reg_d0.h[0] = g_p2_hyper_items;
    if (reg_d0.h[0] == 5) {
        goto block_10;
    }
    reg_d4.h[0] = 5;
    if (reg_d0.h[0] == 4) {
        if (g_frame_mod2 == 0) {
            reg_d4.h[0] = 5;
        }
    }
    reg_d2.w = 0xB5B;
    reg_d5.w = 0xF900FA00;
    if (!(reg_d1.w & 0x800)) {
        func_0016BAF0();
        return;
    }
    p2_hyper_item_take();
    sfx_hyper_pickup();
    reg_a0 = (u8 *)D_0026AF40;
    func_0016C2A0();
    return;
}

void item_kind6(void) {
    void func_0016C260(void);
    func_0016C260();
}

void func_0016C260(void) {
    reg_d0.w = 0;
    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
    cond_flag = 1;
    D_0028E7B0 -= 1;
}

s32 func_001A9130();

void func_0016C2A0() {
    u32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_d1.w;
    temp_s1 = (u32)reg_a0;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d0.w = 0x10;
    func_001A9130();
    reg_d1.w = temp_s0;
    reg_a0 = (u8 *)temp_s1;
    ENTITY(reg_a6)->flags.b[1] = 0x80U;
    ENTITY(reg_a6)->flags.b[0] |= 1;
    ENTITY(reg_a6)->sprite.sh = 0x202;
    reg_tmp.w = (u32)reg_a0;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->draw.sh = 0;
    ENTITY(reg_a6)->look.sb.size = 0;
    func_0016C410();
}

extern u8 D_0026B040[];

void func_0016C350(void) {
    u32 temp_s0;
    u8 *temp_s1;

    sfx_item_pickup();
    temp_s0 = reg_d1.w;
    temp_s1 = (u8 *)(reg_a0);
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    reg_d0.w = 0x1000;
    func_001A9130();
    reg_d1.w = temp_s0;
    reg_a0 = temp_s1;
    ENTITY(reg_a6)->flags.b[1] = 0x80U;
    ENTITY(reg_a6)->flags.b[0] |= 0x80;
    reg_a0 = (u8 *)D_0026B040;
    reg_tmp.w = (u32) reg_a0;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->draw.sh = 0;
    ENTITY(reg_a6)->sprite.sh = 0x202;
    ENTITY(reg_a6)->look.sb.size = 0;
    func_0016C410();
}

void func_0016C410() {
    s16 temp_a0;

    reg_d1.h[0] = g_side_scroll_step[0];
    temp_a0 = ENTITY(reg_a6)->x.sh;
    reg_d1.h[0] = (s16) reg_d1.h[0] + temp_a0;
    ENTITY(reg_a6)->move.sb.dir = 0x30;
    if ((s32) reg_d1.h[0] < 0x1C00) {
        ENTITY(reg_a6)->move.sb.dir = 0x10;
    }
    rng_next();
    if (((s64) ((s64) reg_d0.b[0] << 0x38) >> 0x38) < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 7;
    ENTITY(reg_a6)->move.b.speed = (u8) reg_d0.b[0];
}
