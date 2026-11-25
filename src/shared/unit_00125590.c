#include "common.h"
#include "layers.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00125EC0(void);
void func_00125EF0(void);
void func_00125F00(void);
void func_00125FF0(void);
void func_00126F10(void);
void func_001273D0(void);
void func_00127400(void);
void func_001278A0(void);
void func_001278D0(void);
void func_00127CA0(void);
void func_00127FA0(void);
void func_00128130(void);
void func_00128320(void);
void func_001285A0(void);
void bullet_fire_loop2_double();
void bullet_fire_loop2_3way();
void bullet_fire_direct(void);
void bullet_spawn(void);
void func_00128F70(void);
void bullet_fire256_loop2_double();
void bullet_fire256_loop2_3way();
void bullet_fire256_direct(void);
void bullet_spawn256(void);
void bullet_type_setup_32(void);
void bullet_type_setup_31(void);

extern u16 g_frame_mod2;
extern u16 g_bullet_count;

void func_00125590(u16 arg0) {
    extern void entity_draw_with_special_items(u16);
    if (g_bullet_count >= 0x34) {
        reg_d0.w = 1;
        reg_d0.h[0] &= reg_d7.h[0];
        arg0 = g_frame_mod2;
        if (arg0 == reg_d0.h[0]) {
            return;
        }
    }
    entity_draw_with_special_items(arg0);
}


void func_001255F0(void) {
    s32 entity_draw_with_special_items();
    u16 t;

    if (g_bullet_count < 35) goto call;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] -= reg_d2.h[0];
    t = reg_d0.h[0];
    if (((s64) ((s64) t << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] = (t << 16) - t;
    }
    if (reg_d0.h[0] < 0x600) goto call;
    reg_d0.w = 1;
    reg_d0.h[0] &= reg_d7.h[0];
    if (g_frame_mod2 != reg_d0.h[0]) {
call:
        entity_draw_with_special_items();
        return;
    }
}

extern u16 g_side_scroll_x[];

void func_001256C0(void) {
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += g_side_scroll_x[0];
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x7FFF + 0x1001;
    if (reg_tmp.h[1] == 0) {
        reg_tmp1.w = 0;
        reg_tmp1.h[0] = 0x7800;
        reg_tmp.w = reg_d0.w;
        reg_d0.h[1] = reg_d0.h[0];
        reg_d0.h[0] = reg_tmp.h[1];
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += reg_tmp1.sw;
        reg_d0.h[0] += 0x7800;
    }
    cond_flag = 0;
    switch (reg_tmp.h[1]) {
    case 0:
        break;
    default:
        cond_flag = 1;
    }
}

extern u16 g_enemies_stopped;
void func_001257B0(void) {
    if (g_enemies_stopped == 0) {
        reg_d0.h[0] = g_layer_b_shift[0];
        *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    }
}

void bullet_release(void) {
    reg_d0.w = 0;
    *(u16 *)reg_a6 = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 2) = (u16) reg_d0.h[0];
    g_bullet_count -= 1;
}

extern u16 g_p2_stage_stars_small;
extern u16 g_p1_stage_stars_small;
extern u16 *reg_a0_as_u16_p;

void stage_stars_small_add(void) {
    reg_a0_as_u16_p = &g_p1_stage_stars_small;
    if (!(reg_d1.w & 0x1000)) {
        reg_a0_as_u16_p = &g_p2_stage_stars_small;
    }
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

extern u16 g_p2_stage_stars_large;
extern u16 g_p1_stage_stars_large;

void stage_stars_large_add(void) {
    reg_a0_as_u16_p = &g_p1_stage_stars_large;
    if (!(reg_d1.w & 0x1000)) {
        reg_a0_as_u16_p = &g_p2_stage_stars_large;
    }
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

void p1_stage_stars_small_add(void) {
    reg_a0_as_u16_p = &g_p1_stage_stars_small;
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

void p2_stage_stars_small_add(void) {
    reg_a0_as_u16_p = &g_p2_stage_stars_small;
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}

extern u16 g_frame_mod8;

void func_00125930(void) {
    s32 func_00201D10();
    if (g_frame_mod8 == 0) {
        if (g_enemies_stopped == 0) {
            ENTITY(reg_a6)->move.b.speed += 1;
        }
        reg_d0.w = 0;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
        reg_d1.w = 0x3F;
        reg_d1.b[0] &= ENTITY(reg_a6)->move.b.dir;
        func_00201D10();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
    }
    reg_d2.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->x.h += reg_d2.h[0];
    reg_tmp2.w = reg_d2.w;
    reg_d2.h[1] = reg_d2.h[0];
    reg_d2.h[0] = reg_tmp2.h[1];
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
}

void func_00125A00(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBCF) {
            reg_tmp.w = 0xBBF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125AA0(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBDF) {
            reg_tmp.w = 0xBCF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125B40(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBEF) {
            reg_tmp.w = 0xBDF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void func_00125BE0(void) {
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = (u8) ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        if (reg_tmp.w == 0xBFF) {
            reg_tmp.w = 0xBEF;
            *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
        }
    }
}

void velocity_from_dir256(void);
void func_00202760(void);

void func_00125C80(void) {
    if (ENTITY(reg_a6)->misc.b.user == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        func_00202760();
        ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
        reg_d0.w = 0x40;
        velocity_from_dir256();
        *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
        *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        ENTITY(reg_a6)->misc.b.user = 1;
    }
    reg_d0.h[0] = g_frame_mod8;
    if ((reg_d0.b[0] &= ENTITY(reg_a6)->move.b.speed) == 0) {
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(s16 *)reg_a0 >= 0) {
            bullet_release();
            return;
        }
        func_00202760();
        if (ENTITY(reg_a6)->move.b.dir != reg_d1.b[0]) {
            ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
            reg_d0.w = 0x40;
            velocity_from_dir256();
            *(u16 *)(reg_a6 + 0x20) = reg_d2.h[0];
            *(u16 *)(reg_a6 + 0x22) = reg_d3.h[0];
        }
    }
    reg_d2.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d3.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
}

extern s16 g_p2_stage_stars_small_as_s16;
extern s16 g_p2_stage_stars_large_as_s16;
extern s16 g_p1_stage_stars_small_as_s16;
extern s16 g_p1_stage_stars_large_as_s16;
extern s16 g_bee_value_step_as_s16;
extern s16 g_stage_bees_collected_as_s16;
extern s16 g_bullet_count_as_s16;
extern u8 D_002BF4F0[];
void func_00125DE0(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BF4F0 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0xC08);
    g_p2_stage_stars_small_as_s16 = 0;
    g_p2_stage_stars_large_as_s16 = 0;
    g_p1_stage_stars_small_as_s16 = 0;
    g_p1_stage_stars_large_as_s16 = 0;
    g_bee_value_step_as_s16 = 0;
    g_stage_bees_collected_as_s16 = 0;
    g_bullet_count_as_s16 = 0;
}

extern u16 g_stage_bees_collected;

void p1_stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p1_stage_stars_large = reg_d0.h[0];
    g_p1_stage_stars_small = reg_d0.h[0];
}

void p2_stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p2_stage_stars_large = reg_d0.h[0];
    g_p2_stage_stars_small = reg_d0.h[0];
}

void stage_counts_reset(void) {
    reg_d0.w = 0;
    g_stage_bees_collected = reg_d0.h[0];
    g_p1_stage_stars_large = reg_d0.h[0];
    g_p1_stage_stars_small = reg_d0.h[0];
    g_p2_stage_stars_large = reg_d0.h[0];
    g_p2_stage_stars_small = reg_d0.h[0];
}


void bee_counts_reset(void) {
    g_bee_value_step_as_s16 = 0;
    stage_counts_reset();
}


void func_00125EB0(void) {
    reg_d1.w = 0;
    func_00125EC0();
}

void func_00125EC0(void) {
    reg_d2.h[0] = (u8)reg_d2.h[0];
    reg_d2.h[0] <<= 2;
    func_00125F00();
}


void func_00125EE0(void) {
    reg_d1.w = 0;
    func_00125EF0();
}


void func_00125EF0(void) {
    reg_d2.sw = 0;
    func_00125F00();
}

extern u8 *D_0028DE8C;
extern u32 D_0028DE90;
extern u16 D_002BF4F0_as_u16_a[];

void func_00125F00(void) {
    u32 tmp;

    D_0028DE90 = reg_d7.w;
    D_0028DE8C = reg_a0;
    reg_a0 = (u8 *) D_002BF4F0_as_u16_a;
    reg_d7.h[0] = 0x45;
loop_1:
    if (*(u16 *) reg_a0 != 0) goto next_1;
    func_00126F10();
    cond_flag = 0;
    return;
next_1:
    reg_a0 += 0x2C;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
    cond_flag = 1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

extern u16 g_side_scroll_step[];
extern s32 D_002BF4F0_as_s32_a[];

void func_00125FA0(void) {
    reg_d7.h[0] = g_bullet_count;
    if (reg_d7.h[0] != 0) {
        reg_a6 = (u8 *)D_002BF4F0_as_s32_a;
        reg_d7.w -= 1;
        reg_d6.h[0] = g_side_scroll_step[0];
        func_00125FF0();
    }
}

typedef void (*Fn)();

extern u8 D_002693E0[];

void func_00125FF0(void) {
    u32 t1;

loop_1:
    reg_d1.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d1.h[0] == 0) {
        reg_a6 += 0x2C;
        goto loop_1;
    }
    ENTITY(reg_a6)->x.h -= reg_d6.h[0];
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d1.h[0];
    if ((s8) reg_d1.b[0] < 0) {
        func_00127FA0();
        return;
    }
    ((Fn)*(u32 *)((u8 *)D_002693E0 + (reg_d0.h[0] & ~3)))();
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64) ((s64) (t1 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

s32 sfx_score_item_pickup();
s32 func_001A9130();

void func_001260B0() {
    reg_d0.w = 1;
    stage_stars_small_add();
    reg_tmp.w = 0x50000;
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    func_001A9130();
    sfx_score_item_pickup();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    func_00127CA0();
}


void func_00126120(void) {
    void func_00125590(void);
    void bullet_release(void);
    void func_00125930(void);
    void func_00125A00(void);
    if ((u16)(reg_d1.h[0] &= 0x1800) != 0) {
        func_001260B0();
        return;
    }
    func_00125A00();
    func_00125930();
    if (0 <= (s64)ENTITY(reg_a6)->y.sh) {
        func_00125590();
    } else {
        bullet_release();
    }
}



s32 func_00170DF0();
s32 func_00170F80();
s32 func_00171100();
s32 sfx_bee_pickup();
extern u8 D_00269490[];
extern u8 *reg_call_target_as_u8_p;

void func_001261A0(void) {
    s32 entity_draw_with_special_items();
    s32 bullet_release();
    u32 t;

    if (reg_d1.w & 1) {
        func_00128130();
        return;
    }
    reg_d0.w = 0;
    if (reg_d1.w & 0x1000) goto next_1;
    if (!(reg_d1.w & 0x800)) goto next_3;
    func_00170F80();
    goto next_2;
next_1:
    func_00170DF0();
next_2:
    func_00171100();
    sfx_bee_pickup();
    ENTITY(reg_a6)->flags.b[0] |= 1;
    func_00127CA0();
    return;
block_1:
    bullet_release();
    return;
next_3:
    reg_tmp.w = 0xBBD;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hp.h -= 1;
    if ((s16) ENTITY(reg_a6)->hp.h >= 0) goto next_4;
    ENTITY(reg_a6)->hp.h = 2;
    reg_tmp.w = 0xBBE;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
next_4:
    func_001256C0();
    if (cond_flag != 0) goto block_1;
    reg_d0.w = 4;
    reg_d1.h[0] &= reg_d0.h[0];
    t = reg_d1.h[0] ^ reg_d0.h[0];
    reg_d1.h[0] = t;
    if (t & 0xFFFF) goto next_5;
    func_001257B0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    return;
next_5:
    ENTITY(reg_a6)->y.h -= 0x60;
    ENTITY(reg_a6)->misc.b.draw_layer -= 1;
    if (ENTITY(reg_a6)->misc.b.draw_layer != 0) goto next_6;
    reg_d0.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->misc.b.user;
    reg_a0 = (u8 *)(D_00269490);
    reg_a0 += reg_d0.h[0];
    ENTITY(reg_a6)->misc.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    entity_draw_with_special_items();
}

extern u8 g_boss_present_b1;

void func_00126410(void) {
    s32 bullet_release();
    u32 t;

    if ((s16)(g_boss_present_b1) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 1;
    stage_stars_large_add();
    reg_tmp.w = 0x50000;
    ENTITY(reg_a6)->hit_y_plus.h = reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = reg_tmp.h[0];
    reg_d0.w = 0x50;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    func_001A9130();
    sfx_score_item_pickup();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    func_00127CA0();
    return;
next_2:
    bullet_release();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (cond_flag != 0) goto next_2;
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC0F) {
            reg_tmp.w = 0xBFF;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            ENTITY(reg_a6)->hp.b[1] = 1;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
}

s32 sfx_score_item_pickup_2();

void func_001265B0(void) {
    s32 bullet_release();
    u32 t;

    if ((s16)(g_boss_present_b1) < 0) goto next_2;
    t = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = t;
    if (!(t & 0xFFFF)) goto next_1;
    reg_d0.w = 2;
    stage_stars_large_add();
    reg_tmp.w = 0x10008;
    ENTITY(reg_a6)->hit_y_plus.h = reg_tmp.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = reg_tmp.h[0];
    reg_d0.w = 0x1000;
    reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
    func_001A9130();
    sfx_score_item_pickup_2();
    ENTITY(reg_a6)->flags.b[0] = 0x84;
    func_00127CA0();
    return;
next_2:
    bullet_release();
    return;
next_1:
    func_001257B0();
    func_001256C0();
    if (cond_flag != 0) goto next_2;
    ENTITY(reg_a6)->hp.b[1] -= 1;
    if ((s8) ENTITY(reg_a6)->hp.b[1] < 0) {
        ENTITY(reg_a6)->hp.b[1] = ENTITY(reg_a6)->hp.b[0];
        reg_a0 = reg_a6 + 0xA;
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp.w += 1;
        *(u16 *)reg_a0 = reg_tmp.h[1];
        *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
        if (reg_tmp.w == 0xC2F) {
            reg_tmp.w = 0xC1F;
            *(u16 *)reg_a0 = reg_tmp.h[1];
            *(u16 *)(reg_a0 + 2) = reg_tmp.h[0];
            ENTITY(reg_a6)->hp.b[1] = 2;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
}


void func_00126760(void) {
    s32 func_00125590();
    s32 bullet_release();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 2;
        stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        func_00127CA0();
        return;
    }
    func_00125AA0();
    func_00125930();
    if (ENTITY(reg_a6)->y.sh >= -0x200) {
        func_00125590();
        return;
    }
    bullet_release();
}


void func_00126830(void) {
    s32 func_00125590();
    s32 bullet_release();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 4;
        stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        func_00127CA0();
        return;
    }
    func_00125B40();
    func_00125930();
    if (ENTITY(reg_a6)->y.sh >= -0x400) {
        func_00125590();
        return;
    }
    bullet_release();
}


void func_00126900(void) {
    s32 func_00125590();
    s32 bullet_release();
    s32 func_00125930();
    u32 temp_v0;

    temp_v0 = reg_d1.h[0] & 0x1800;
    reg_d1.h[0] = temp_v0;
    if (temp_v0 & 0xFFFF) {
        reg_d0.w = 8;
        stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup_2();
        ENTITY(reg_a6)->flags.b[0] = 0x84;
        func_00127CA0();
        return;
    }
    func_00125BE0();
    func_00125930();
    if (ENTITY(reg_a6)->y.sh >= -0x600) {
        func_00125590();
        return;
    }
    bullet_release();
}


void func_001269D0() {
    s32 bullet_release();
    s32 func_00125A00();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 1;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x50000;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126A70() {
    s32 bullet_release();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 2;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126B10() {
    s32 bullet_release();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 4;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126BB0() {
    s32 bullet_release();
    if (reg_d1.w & 0x1000) {
        reg_d0.w = 8;
        p1_stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}


void func_00126C50() {
    s32 bullet_release();
    s32 func_00125A00();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 1;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x50000;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x50;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125A00();
    func_001255F0();
}

void func_00126CF0() {
    s32 bullet_release();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 2;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x10004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x100;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125AA0();
    func_001255F0();
}

void func_00126D90() {
    s32 bullet_release();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 4;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x50004;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x500;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125B40();
    func_001255F0();
}

void func_00126E30() {
    s32 bullet_release();
    if (reg_d1.w & 0x800) {
        reg_d0.w = 8;
        p2_stage_stars_small_add();
        reg_tmp.w = 0x10008;
        ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_tmp.h[1];
        ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_tmp.h[0];
        reg_d0.w = 0x1000;
        reg_d1.b[0] = ENTITY(reg_a6)->flags.b[1];
        func_001A9130();
        sfx_score_item_pickup();
        bullet_release();
        return;
    }
    func_00125C80();
    func_00125BE0();
    func_001255F0();
}

extern void *D_0028DE8C_as_void_p;
extern u32 D_0028DE94;

void func_00126ED0(void) {
    reg_d1.w = D_0028DE94;
    g_bullet_count -= 1;
    (*(s16 *)((u8 *)(reg_a0) + (-6))) = 0;
    cond_flag = 0;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C_as_void_p;
}

extern u8 entity_draw_layer_routines_as_u8_a[];
extern u8 D_00269550[];
extern u8 D_002695E0[];

void func_00126F10(void) {
    u8 *save_a1;

    reg_a3 = (u8 *)D_002695E0;
    g_bullet_count += 1;
    reg_a3 = *(u8 **) (D_002695E0 + (reg_d0.h[0] & ~3));
    *(u16 *) reg_a0 = reg_d0.h[0];
    *(u16 *) reg_a0 |= 0x8000;
    reg_a0 += 2;
    D_0028DE94 = reg_d1.w;
    reg_tmp1.h[1] = *(u16 *) (reg_a6 + 2);
    reg_tmp1.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d1.w += reg_tmp1.w;
    reg_d1.h[0] += (s32) g_side_scroll_step[0];
    *(u16 *) reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xAC00;
    reg_d1.h[0] += 0xE00;
    reg_d1.h[0] += (s32) g_side_scroll_x[0];
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[0] += 0xAC00;
    if (reg_tmp1.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x6000;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp1.w = 0;
    reg_d1.h[0] += 0x800;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x6000;
    reg_tmp1.w += (s32) reg_tmp.w;
    if (reg_tmp1.h[1] != 0) {
        func_00126ED0();
        return;
    }
    reg_d1.w = D_0028DE94;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a3;
    reg_a0 += 2;
    reg_a0 -= 0x1E;
    save_a1 = reg_a1;
    reg_a1 = (u8 *)entity_draw_layer_routines_as_u8_a;
    reg_a1 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 0x28) = *(u16 *) (reg_a1 + 2);
    *(u16 *) (reg_a0 + 0x2A) = *(u16 *) (reg_a1 + 0);
    ((Fn) *(u32 *) (D_00269550 + (reg_d0.h[0] & ~3)))();
    reg_a1 = save_a1;
    reg_d7.w = D_0028DE90;
    reg_a0 = D_0028DE8C;
}

s32 rng_next_unsigned();
extern u16 D_002695D0[];

void func_00127310(void) {
    u8 *sa1;

    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_d0.h[0] &= 0xE;
    sa1 = reg_a1;
    reg_d1.w = 0;
    reg_a1 = (u8 *)D_002695D0;
    reg_a1 += reg_d0.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 = sa1;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w += reg_d1.w;
    *(u16 *)(reg_a0 + 0xA) = reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    func_001273D0();
}

s32 func_00201270();
void func_001273D0(void) {
    func_00201270();
    reg_d0.h[0] >>= 1;
    func_00127400();
}

s32 rng_next_bit();

void func_00127400(void) {
    s32 func_00201D10();
    u32 save_d0;
    u32 save_d2;
    u32 save_d3;
    u8 *temp_a1;

    *(u8 *)(reg_a0 + 0x1B) += reg_d0.b[0];
    save_d0 = reg_d0.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    rng_next_bit();
    reg_d0.h[0] += 1;
    reg_d1.h[0] = reg_d0.h[0];
    func_00201270();
    reg_d0.b[0] -= reg_d1.b[0];
    *(u8 *)(reg_a0 + 0x1A) += reg_d0.b[0];
    temp_a1 = (u8 *)(reg_a0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(temp_a1) + (0x1B)));
    reg_d1.w = 0x3F;
    reg_d0.h[0] = (u16) reg_d0.b[0];
    reg_d1.b[0] &= (*(u8 *)((u8 *)(temp_a1) + (0x1A)));
    reg_a0 = reg_a6;
    reg_atmp = temp_a1;
    reg_a6 = temp_a1;
    func_00201D10();
    reg_atmp = (u8 *)reg_a0;
    reg_a0 = reg_a6;
    reg_a6 = (u8 *)reg_atmp;
    *(u16 *)(reg_a0 + 0x20) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a0 + 0x22) = (u16) reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    cond_flag = 0;
    reg_d1.w = reg_d7.w;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
}

extern void rng_next(void);

void func_00127530(void) {
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(u16 *)((u8 *)((void *)reg_a0) + 0x1A) = 0x420;
    rng_next();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] = (s8)reg_d0.b[0];
    reg_d0.h[0] >>= 1;
    func_00127400();
}

void func_001275B0(void) {
    *(u16 *)((u8 *)((void *)reg_a0) + 0x1E) = 0x9601;
    cond_flag = 0;
}

s32 rng_next_masked();

void func_001275D0(void) {
    reg_d7.w = reg_d0.w;
    rng_next_masked();
    reg_d0.h[0] &= 0x1F;
    *(u8 *)(reg_a0 + 0x19) += reg_d0.b[0];
    *(s16 *)(reg_a0 + 0x20) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void func_00127630(void) {
    reg_d7.w = reg_d0.w;
    rng_next_masked();
    reg_d0.h[0] &= 0x1F;
    *(u8 *)(reg_a0 + 0x19) += reg_d0.b[0];
    *(s16 *)(reg_a0 + 0x20) = 0;
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}


void func_00127690(void) {
    func_00127530();
    *(s8 *)reg_a0 = 0;
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void func_001276D0(void) {
    func_00127530();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void func_00127700(void) {
    func_00127530();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

void func_00127730(void) {
    func_00127530();
    *(u8 *)(reg_a0 + 0x1B) += 5;
    cond_flag = 0;
}

extern u8 D_002695D0_as_u8_a[];
extern u8 g_player2_as_u8_a[];

void func_00127760(void) {
    reg_a3 = D_002695D0_as_u8_a;
    reg_tmp.w = (u32) g_player2_as_u8_a;
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695A0_as_u8_a[];

void func_001277A0(void) {
    reg_a3 = D_002695A0_as_u8_a;
    reg_tmp.w = (u32) g_player2_as_u8_a;
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695B0_as_u8_a[];

void func_001277E0(void) {
    reg_a3 = D_002695B0_as_u8_a;
    reg_tmp.w = (u32) g_player2_as_u8_a;
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    func_001278D0();
}

extern u8 D_002695C0_as_u8_a[];

void func_00127820(void) {
    reg_a3 = D_002695C0_as_u8_a;
    reg_tmp.w = (u32) g_player2_as_u8_a;
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[0];
    func_001278D0();
}



void func_00127860(void) {
    reg_a3 = (u8 *)D_002695D0;
    func_001278A0();
}

extern u16 D_002695A0[];


void func_00127870(void) {
    reg_a3 = (u8 *)D_002695A0;
    func_001278A0();
}

extern u16 D_002695B0[];


void func_00127880(void) {
    reg_a3 = (u8 *)D_002695B0;
    func_001278A0();
}

extern u16 D_002695C0[];

void func_00127890(void)
{
    reg_a3 = (u8 *)D_002695C0;
    func_001278A0();
}

extern u8 g_player1_as_u8_a[];
void func_001278A0(void) {
    reg_tmp.w = (u32)g_player1_as_u8_a;
    *(u16 *)(reg_a0 + 0x24) = reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0x26) = reg_tmp.h[0];
    func_001278D0();
}

void func_001278D0(void) {
    reg_d7.h[0] &= 0xF;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d7.b[0];
    *(s8 *)(reg_a0 + 0x1F) = 0;
    reg_d7.w = reg_d0.w;
    rng_next_unsigned();
    reg_d0.w &= 0xE;
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)((u16 *)reg_a3) + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_tmp.h[0];
    cond_flag = 0;
    reg_d0.w = reg_d7.w;
}

void func_001279A0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(D_002695A0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    func_001273D0();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x14;
}

void func_00127AA0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(D_002695B0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    func_001273D0();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x18;
}

void func_00127BA0(void) {
    u16 temp_a1;
    temp_a1 = reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = temp_a1;
    reg_d7.w = reg_d1.w;
    reg_d0.h[0] = reg_tmp.h[1];
    *(s16 *)(reg_a0 + 0x1A) = 0x420;
    rng_next_unsigned();
    reg_a3 = (u8 *)(D_002695C0);
    reg_d0.h[0] &= 0xE;
    reg_d1.w = 0;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
    reg_tmp1.h[1] = *(u16 *)(reg_a0 + 0xA);
    reg_tmp1.h[0] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp1.w = (s32) ((s32) reg_tmp1.w + reg_d1.w);
    *(u16 *)(reg_a0 + 0xA) = (u16) reg_tmp1.h[1];
    *(u16 *)(reg_a0 + 0xC) = reg_tmp1.h[0];
    func_001273D0();
    *(u16 *)reg_a0 &= 0xFF83;
    *(u16 *)reg_a0 |= 0x1C;
}

void rng_next(void);
extern u8 D_00269708[];

void func_00127CA0(void) {
    void func_00201D10(void);
    reg_d0.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = (u8 *)D_00269708;
    reg_a0 = *(u8 **)(D_00269708 + (reg_d0.h[0] & ~3));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 = reg_a6;
    reg_a2 = (u8 *)reg_tmp.w;
    ENTITY(reg_a6)->flags.h &= 0xF8DF;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 0x06000000;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[0];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    ENTITY(reg_a6)->hit_y_minus.h = 0x10;
    ENTITY(reg_a6)->hit_x_plus.sh = 0x202;
    ENTITY(reg_a6)->hit_x_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->hp.sb[1] = 7;
    ENTITY(reg_a6)->hp.sb[0] = 0xF;
    ENTITY(reg_a6)->attr.sh = 0x1D;
    reg_d0.h[0] = g_side_scroll_step[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] + ENTITY(reg_a6)->x.sh;
    reg_d1.w = 0x30;
    if ((s32)reg_d0.h[0] < 0x1C00) {
        reg_d1.w = 0x10;
    }
    rng_next();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 6;
    func_00201D10();
    ENTITY(reg_a6)->move.h = reg_d3.h[0];
}

void entity_draw_layer5_zoom(void);

void func_00127FA0(void) {
    u32 sd6;
    u8 t;
    u32 t1;

    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    switch (*(u8 *)(reg_a6 + 0x18)) {
        case 0:
            goto block_3;
    }
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    entity_draw_layer5_zoom();
    reg_d6.w = sd6;
    goto block_4;
block_3:
    bullet_release();
block_4:
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) {
        func_00125FF0();
    }
}


void func_00128130(void) {
    u32 sd6;
    u8 t;

    if ((reg_d1.w & 0x2000) && (g_frame_mod2 != 0)) {
        *(u8 *)(reg_a6 + 0x1C) ^= 0x10;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    if (*(u8 *)(reg_a6 + 0x18) == 0) goto block_3;
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    entity_draw_layer5_zoom();
    reg_d6.w = sd6;
    if ((s32)*(u8 *)(reg_a6 + 0x15) < 3) return;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 8);
    reg_d1.h[1] += *(u16 *)(reg_a6 + 6);
    func_00128320();
    if (*(u8 *)(reg_a6 + 1) & 0x20) {
        func_001285A0();
    }
    return;
block_3:
    bullet_release();
}

void sprite_draw_with_special_items_keep(void);
extern u16 g_loop;
extern u16 g_stage;

void func_00128320(void) {
    void sprite_draw_with_special_items(void);
    u32 sd6;
    u32 sd7;

    reg_d1.h[0] += 0x7FFF + 0x7DC1;
    reg_d1.h[1] += 0x200;
    reg_d2.w = 0x11E0;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_special_items();
    reg_d3.h[0] = 0x410;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    reg_d1.h[0] += 0x480;
    reg_d1.h[1] += 0x7FFF + 0x7F41;
    reg_d0.h[0] = ENTITY(reg_a6)->misc.h;
    reg_d7.w = 1;
    reg_d6.w = 0;
    do {
        reg_d5.w = 0x1046;
        reg_d2.w = 0xF;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        reg_d4.w = 0;
        if (reg_d2.h[0] == 0 && reg_d6.h[0] == 0) {
            reg_d5.w = 0x103C;
        } else {
            reg_d4.h[0] = reg_d2.h[0] * 0xA;
        }
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] <<= 4;
        reg_d2.w = 0xF;
        reg_d0.h[0] |= (u16)((s32)reg_tmp.h[0] >> 0xC);
        reg_d2.h[0] &= reg_d0.h[0];
        if (reg_d2.h[0] != 0 || reg_d4.h[0] != 0 || reg_d6.h[0] != 0) {
            reg_d6.w = 1;
            reg_d2.w += reg_d4.w;
            if (reg_d5.w == 0x103C) {
                reg_d1.h[0] += 0x7FFF + 0x7E01;
            }
            reg_d2.w += reg_d5.w;
            reg_d4.h[0] = 0x1D;
            sprite_draw_with_special_items_keep();
            reg_d1.h[0] += 0x400;
        }
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    if (g_stage != 0 || g_loop != 0) {
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        return;
    }
    reg_d2.w = 0x11E1;
    reg_d1.h[0] += 0x400;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 0x1D;
    reg_d1.h[1] += 0xC0;
    sprite_draw_with_special_items_keep();
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_d1.w += 0xFF400000;
}

extern u32 D_002697E0[];

void func_001285A0(void) {
    s32 sprite_draw_with_special_items();
    u16 temp_a2;
    u16 temp_a3;
    u32 temp_a0;

    temp_a3 = (u32)reg_d1.h[0] + 0x400;
    reg_d1.h[0] = temp_a3;
    temp_a2 = (u32)reg_d1.h[1] + 0x40;
    reg_d1.h[1] = temp_a2;
    reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = (u8 *)(D_002697E0);
    reg_a0 += reg_d0.h[0];
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1D;
    sprite_draw_with_special_items();
    ENTITY(reg_a6)->hit_y_minus.h -= 4;
    if ((s16) ENTITY(reg_a6)->hit_y_minus.h < 0) {
        ENTITY(reg_a6)->hit_y_minus.h = 0x10U;
    }
}

#ifdef DEATH_LABEL
s32 death_func_001271E0(void) {
    return (*(u16 *)reg_a6 & 0x3F) == 0x24;
}
#endif

void func_00128640(void) {
    *(u16 *)reg_a6 = 0;
    *(u16 *)(reg_a6 + 2) = 0xFFFF;
}

extern u8 D_002962E0[];

void func_00128660(void) {
    memset(D_002962E0, 0, MAIN_OR_DEATH_LABEL(0x3494, 0x10694));
    reg_a0 = D_002962E0 + 2;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        *(u16 *)reg_a0 = 0xFFFF;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void func_001286D0(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    bullet_fire_loop2_double();
}

extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;

void bullet_fire_loop2_double() {
    bullet_fire_direct();
    reg_d0.w += 0x60000;
    bullet_fire_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}

extern u8 *D_0028DE98_as_u8_p;

void bullet_fire_loop2(void) {
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98_as_u8_p = reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        func_001286D0();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        bullet_fire_loop2_double();
        return;
    }
    bullet_fire_loop2_3way();
}


void bullet_fire_loop2_3way() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d0.w += 0x20000;
    reg_d1.b[0] += reg_d1.b[0];
    bullet_fire256_direct();
    reg_d0.w -= 0x20000;
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}

void bullet_fire_loop2_2way() {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}


void bullet_fire_fixed(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    bullet_fire_direct();
}

void bullet_fire_fast(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    reg_d0.w += 0x40000;
    bullet_fire_direct();
    reg_d0.w += 0xFFFC0000;
}


void bullet_fire_double(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire_loop2_double(reg_d0.w);
}


void bullet_fire_2way(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire_loop2_2way(reg_d0.w);
}


void bullet_fire_3way(void) {
    if (g_loop == 0) {
        bullet_spawn();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire_loop2_3way(reg_d0.w);
}


void bullet_fire(void) {
    if (g_loop != 0) {
        bullet_fire_loop2();
        return;
    }
    bullet_spawn();
}


void bullet_fire_direct(void) {
    bullet_spawn();
}

extern u16 bullet_type_records[];
extern u32 D_0028DEA4;
extern u32 D_0028DEA8;
extern u16 *D_0028DEB0_as_u16_p;
extern u8 *D_0028DEB4_as_u8_p;
extern u16 g_hyper_bullet_speed;
extern u8 D_0028E2E4;
extern u16 D_0028E7F0;
extern u16 g_bullets_blocked;
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u16 D_0029CEA0[];
#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif

void bullet_spawn(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((g_attract_demo == 0) && (D_0028E2E4 != 0)) {
        return;
    }
#else
    if (D_0028E2E4 != 0) {
        return;
    }
#endif
    D_0028DEA4 = reg_d7.w;
    D_0028DEB4_as_u8_p = reg_a0;
    D_0028DEB0_as_u16_p = (u16 *) reg_a1;
    reg_d7.h[0] = g_bullets_blocked;
    reg_d7.h[0] += g_enemies_stopped;
    reg_d7.h[0] += D_0029CEA0[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)D_002962E0;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (D_0029976C[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (D_0029976E[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) D_0029CEA0[0]) {
        goto next_4;
    }
    if (*(u8 *) D_0029CEA0 & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 0;
    return;
next_5:
    D_0028DEA8 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) bullet_type_records;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += D_0028E7F0;
    reg_d7.h[0] += g_hyper_bullet_speed;
#ifdef DEATH_LABEL
    if ((death_D_0029085C == 2) && (reg_d7.h[0] > death_D_00290858)) {
        reg_d7.h[0] = death_D_00290858;
    }
#endif
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    reg_d1.b[0] >>= 2;
    func_00128F70();
}

extern u8 bullet_type_setup_routines[];
extern u8 *D_0028DEB0_as_u8_p;

void func_00128F70(void) {
    if (reg_d3.w == 0) {
        goto next_1;
    }
    *(u16 *) (reg_a0 - 0xC) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    *(u16 *) (reg_a0 - 0xE) += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
next_1:
    if (*(s16 *) reg_a1 == 0) {
        goto next_2;
    }
    reg_a1 = (u8 *)bullet_type_setup_routines;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_tmp.h[0] = *(u16 *) (reg_a1 + 2);
    reg_a1 = (u8 *) reg_tmp.w;
    reg_call_target = (Fn) reg_a1;
    reg_call_target();
    return;
next_2:
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *)D_0028DEB0_as_u8_p;
    cond_flag = 0;
}


void func_00129070(void) {
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    bullet_fire256_loop2_double();
}


void bullet_fire256_loop2_double() {
    bullet_fire256_direct();
    reg_d0.w += 0x60000;
    bullet_fire256_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}


void bullet_fire256_loop2(void) {
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98_as_u8_p = reg_a0;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[0] = 0x81;
    reg_d1.h[1] = reg_tmp1.h[0];
    if ((reg_d1.b[0] &= *(u8 *)(reg_a5 + 0xC)) != 0) {
        func_00129070();
        return;
    }
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
    reg_a0 = (u8 *)reg_tmp.w;
    if (!(*(u8 *)(reg_a0 + 1) & 2)) {
        bullet_fire256_loop2_double();
        return;
    }
    bullet_fire256_loop2_3way();
}

void bullet_fire256_loop2_3way() {
    bullet_fire256_direct();
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}

void bullet_fire256_loop2_2way() {
    reg_d1.b[0] -= 8;
    bullet_fire256_direct();
    reg_d1.b[0] += 0x10;
    bullet_fire256_direct();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}


void bullet_fire256_fixed(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    bullet_fire256_direct();
}

void bullet_fire256_fast(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    reg_d0.w += 0x40000;
    bullet_fire256_direct();
    reg_d0.w += 0xFFFC0000;
}


void bullet_fire256_double(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire256_loop2_double(reg_d0.w);
}


void bullet_fire256_2way(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire256_loop2_2way(reg_d0.w);
}


void bullet_fire256_3way(void) {
    if (g_loop == 0) {
        bullet_spawn256();
        return;
    }
    D_0028DEA0 = reg_d0.w;
    D_0028DE9C = reg_d1.w;
    D_0028DE98 = (s32)reg_a0;
    bullet_fire256_loop2_3way(reg_d0.w);
}


void bullet_fire256(void) {
    if (g_loop != 0) {
        bullet_fire256_loop2();
        return;
    }
    bullet_spawn256();
}

#ifdef DEATH_LABEL
extern u8 death_D_00290854;
extern u8 death_D_0029085C;
extern s32 death_D_0029040C;
extern s32 death_D_00290410;
extern u8 death_D_006901D0[];
#endif

void bullet_fire256_direct(void) {
#ifdef DEATH_LABEL
    if (death_D_0029085C == 2) {
        if (death_D_00290854 != 0) {
            if (reg_a6 == death_D_006901D0) {
                death_D_0029040C += 1;
                if (death_D_0029040C & 1) {
                    return;
                }
            } else {
                death_D_00290410 += 1;
                if (!(death_D_00290410 & 1)) {
                    return;
                }
            }
        }
    } else {
        death_D_00290410 = 0;
        death_D_0029040C = 0;
    }
#endif
    bullet_spawn256();
}

#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif

void bullet_spawn256(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((g_attract_demo == 0) && (D_0028E2E4 != 0)) {
        return;
    }
#else
    if (D_0028E2E4 != 0) {
        return;
    }
#endif
    D_0028DEA4 = reg_d7.w;
    D_0028DEB4_as_u8_p = reg_a0;
    D_0028DEB0_as_u16_p = (u16 *) reg_a1;
    reg_d7.h[0] = g_bullets_blocked;
    reg_d7.h[0] += g_enemies_stopped;
    reg_d7.h[0] += D_0029CEA0[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)D_002962E0;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (D_0029976C[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (D_0029976E[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 1;
    return;
next_3:
    if (0 <= (s64) (s16) D_0029CEA0[0]) {
        goto next_4;
    }
    if (*(u8 *) D_0029CEA0 & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4_as_u8_p;
    reg_a1 = (u8 *) D_0028DEB0_as_u16_p;
    cond_flag = 0;
    return;
next_5:
    D_0028DEA8 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) bullet_type_records;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.w |= 0x200;
    *(u16 *) reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += D_0028E7F0;
    reg_d7.h[0] += g_hyper_bullet_speed;
#ifdef DEATH_LABEL
    if ((death_D_0029085C == 2) && (reg_d7.h[0] > death_D_00290858)) {
        reg_d7.h[0] = death_D_00290858;
    }
#endif
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    func_00128F70();
}

extern s32 D_0028DEA4_as_s32;
extern s32 D_0028DEB0;
extern s32 D_0028DEB4_as_s32;

void bullet_type_setup_00(void) {
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.sw = D_0028DEA4_as_s32;
    reg_a0 = (u8 *)D_0028DEB4_as_s32;
    reg_a1 = (u8 *)D_0028DEB0;
}

extern void *D_0028DEB4;

void bullet_type_setup_03(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

void bullet_type_setup_17(void) {
    *(u8 *)(reg_a0 + 0x25) = (u8) reg_d4.b[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

void bullet_type_setup_18(void) {
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

void bullet_type_setup_19(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

void bullet_type_setup_23(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}


void bullet_type_setup_27(void) {
    bullet_type_setup_32();
}

extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;

void bullet_type_setup_32(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) g_enemy_signal_0;
    *(u16 *)(reg_a0 + 0x1A) = (u16) g_enemy_signal_1;
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(s8 *)(reg_a0 + 0x25) = 0;
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[1];
    *(u16 *)(reg_a0 + 0x28) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

void func_00129B10(void) {
    *(u8 *)(reg_a0 + 0x1B) = (u8) *(u8 *)(reg_a5 + 2);
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}


void bullet_type_setup_30(void) {
    bullet_type_setup_31();
}

void bullet_type_setup_31(void) {
    *(u16 *)(reg_a0 + 0x18) = (u16) reg_d3.h[1];
    *(u16 *)(reg_a0 + 0x1A) = (u16) reg_d3.h[0];
    *(u16 *)(reg_a0 + 0x1C) = (u16) reg_d4.h[1];
    *(u16 *)(reg_a0 + 0x1E) = (u16) reg_d4.h[0];
    *(u16 *)(reg_a0 + 0x24) = (u16) reg_d5.h[1];
    *(u16 *)(reg_a0 + 0x26) = (u16) reg_d5.h[0];
    cond_flag = 0;
    reg_d0.w = D_0028DEA8;
    reg_d7.w = D_0028DEA4;
    reg_a0 = D_0028DEB4;
    reg_a1 = (u8 *)D_0028DEB0;
}

extern u16 D_00299764[];

#ifdef DEATH_LABEL
s32 death_func_00128A90();
#endif

void func_00129BE0(void) {
    u32 t;

    if (D_00299764[0] == 0) {
        return;
    }
    reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
    if ((s16) reg_d0.h[0] < 0) {
        goto next_3;
    }
    reg_a6 = (u8 *)D_002962E0;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_1:
    if (0 > (s64) *(s8 *) (reg_a6 + 1)) {
        D_0028DEA4 = reg_d7.w;
        reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
        MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
        reg_d7.w = D_0028DEA4;
        func_00128640();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_3:
    reg_a6 = (u8 *)D_002962E0;
    reg_d2.w = 0x40;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_4:
    t = *(u8 *) (reg_a6 + 1);
    if (0 > (s8) t) {
        *(u8 *) (reg_a6 + 1) = t | reg_d2.b[0];
        *(u16 *) (reg_a6 + 0x3C) = 0xFFFF;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_4;
    }
}
