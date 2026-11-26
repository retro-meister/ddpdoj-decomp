#include "common.h"
#include "entity.h"
#include "enemy_kinds.h"
#include "stage4_boss.h"

void stage4_boss_fire_basic_start(void);
void stage4_boss_fire_basic(void);
void stage4_boss_fire_right_spinner_start(void);
void stage4_boss_fire_right_spinner(void);
void stage4_boss_fire_left_spinner_start(void);
void stage4_boss_fire_left_spinner(void);
void stage4_boss_fire_aimed_gun_start(void);
void stage4_boss_fire_aimed_gun(void);
void stage4_boss_fire_both_spinners_start(void);
void stage4_boss_fire_both_spinners(void);
void stage4_boss_fire_center_hatch_start(void);
void stage4_boss_fire_center_hatch(void);
void stage4_boss_fire_right_pod_start(void);
void stage4_boss_fire_right_pod(void);
void stage4_boss_fire_left_pod_start(void);
void stage4_boss_fire_left_pod(void);
void stage4_boss_fire_cutter_bay_start(void);
void stage4_boss_fire_cutter_bay(void);
void stage4_boss_fire_cutters_start(void);
void stage4_boss_fire_cutters(void);
void stage4_boss_fire_cutter_bay_b_start(void);
void stage4_boss_fire_cutter_bay_b(void);
void stage4_boss_fire_cutters_b_start(void);
void stage4_boss_fire_cutters_b(void);
void stage4_boss_fire_aimed_gun_b_start(void);
void stage4_boss_fire_aimed_gun_b(void);
void stage4_boss_fire_both_sides_start(void);
void stage4_boss_fire_both_sides(void);
void stage4_boss_fire_rage_wings_start(void);
void stage4_boss_fire_rage_wings(void);

/* The set-up routine and the per-frame routine of every attack, by attack number. */
void (*stage4_boss_fire_routines[])(void) = {
    stage4_boss_fire_basic_start,
    stage4_boss_fire_basic,
    stage4_boss_fire_right_spinner_start,
    stage4_boss_fire_right_spinner,
    stage4_boss_fire_left_spinner_start,
    stage4_boss_fire_left_spinner,
    stage4_boss_fire_aimed_gun_start,
    stage4_boss_fire_aimed_gun,
    stage4_boss_fire_both_spinners_start,
    stage4_boss_fire_both_spinners,
    stage4_boss_fire_center_hatch_start,
    stage4_boss_fire_center_hatch,
    stage4_boss_fire_right_pod_start,
    stage4_boss_fire_right_pod,
    stage4_boss_fire_left_pod_start,
    stage4_boss_fire_left_pod,
    stage4_boss_fire_cutter_bay_start,
    stage4_boss_fire_cutter_bay,
    stage4_boss_fire_cutters_start,
    stage4_boss_fire_cutters,
    stage4_boss_fire_cutter_bay_b_start,
    stage4_boss_fire_cutter_bay_b,
    stage4_boss_fire_cutters_b_start,
    stage4_boss_fire_cutters_b,
    stage4_boss_fire_aimed_gun_b_start,
    stage4_boss_fire_aimed_gun_b,
    stage4_boss_fire_both_sides_start,
    stage4_boss_fire_both_sides,
    stage4_boss_fire_rage_wings_start,
    stage4_boss_fire_rage_wings,
    0,
    0,
};

void stage4_boss_fire_basic(void);
void stage4_boss_fire_right_spinner(void);
void stage4_boss_fire_left_spinner(void);
void stage4_boss_fire_both_spinners(void);
void stage4_boss_fire_center_hatch();
void stage4_boss_fire_right_pod(void);
void stage4_boss_fire_left_pod(void);
void stage4_boss_fire_cutter_bay();
void stage4_boss_fire_4way(void);
void stage4_boss_fire_cutters(void);
void stage4_boss_fire_cutters_b();
void stage4_boss_fire_cutter_bay_b(void);
void stage4_boss_fire_aimed_gun_b(void);
void stage4_boss_fire_both_sides(void);
void stage4_boss_fire_rage_wings(void);


void stage4_boss_right_spinner_turn(void) {
    ENTITY(reg_a6)[6].offset_y.h += 1;
    if ((s16) ENTITY(reg_a6)[6].offset_y.h >= 0x18) {
        ENTITY(reg_a6)[6].offset_y.h = 0U;
    }
}


void stage4_boss_right_spinner_turn_back(void)
{
    *(u16 *)((u8 *)((void *)reg_a6) + 0xC6) -= 1;
    if (0 > *(s16 *)((u8 *)((void *)reg_a6) + 0xC6)) {
        *(u16 *)((u8 *)((void *)reg_a6) + 0xC6) = 0x17;
    }
}

void stage4_boss_left_spinner_turn_back(void)
{
    s16 *frameCounter;

    --*(u16 *)((u8 *)((void *)reg_a6) + 0xE6);

    frameCounter = (s16 *)((u8 *)((void *)reg_a6) + 0xE6);
    if (0 > *frameCounter) {
        *frameCounter = 0x17;
    }
}

extern u16 D_0026EBF0[];
extern u8 D_0026EC60[];

void stage4_boss_spinner_muzzle(void) {
    u8 temp_a1;

    if ((s16)(reg_d0.h[0]) > 0x17) {
        reg_d0.h[0] -= 0x18;
    }
    reg_d1.w = 0;
    temp_a1 = *(D_0026EC60 + reg_d0.h[0]);
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026EBF0);
    reg_d1.b[0] = temp_a1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
}


void stage4_boss_fire_basic_start(void) {
    BASIC(reg_a4)->shot.h = 0;
    stage4_boss_fire_basic();
}

s32 bullet_fire256();

void stage4_boss_fire_basic(void) {
    u16 t;

    reg_tmp.b[0] = BASIC(reg_a4)->shot.t.count;
    BASIC(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        BASIC(reg_a4)->shot.t.count = (u8) BASIC(reg_a4)->shot.t.reload;
        ENTITY(reg_a6)[6].offset_y.h += 1;
        if (ENTITY(reg_a6)[6].offset_y.h == 0x18) {
            ENTITY(reg_a6)[6].offset_y.h = 0U;
        }
        reg_d0.h[0] = ENTITY(reg_a6)[6].offset_y.h;
        t = reg_d0.h[0];
        reg_d1.w = 0;
        reg_d1.b[0] = D_0026EC60[t];
        reg_d0.h[0] = t + t;
        reg_a0 = (u8 *)(D_0026EBF0);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.w = 7;
        reg_d2.h[1] = ENTITY(reg_a6)[6].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[6].x.h;
        bullet_fire256();
    }
}

extern void (*stage4_boss_right_spinner_routines[])(void);

void stage4_boss_fire_right_spinner_start(void)
{
    reg_d0.h[0] = SPINNER(reg_a4)->pattern;
    reg_d0.h[0] <<= 1;
    stage4_boss_right_spinner_routines[(u16)reg_d0.h[0]]();
    stage4_boss_fire_right_spinner();
}

typedef void (*Fn)(void);
extern Fn stage4_boss_right_spinner_routines[];

void stage4_boss_fire_right_spinner(void) {
    reg_d0.h[0] = SPINNER(reg_a4)->pattern;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += 1;
    (*(Fn *)((u8 *)stage4_boss_right_spinner_routines + (reg_d0.h[0] << 2)))();
}

void stage4_boss_spinner_volleys_start(s32 id) {
    SPINNER_VOLLEYS(reg_a4)->shot.h = 0;
    SPINNER_VOLLEYS(reg_a4)->volleys_left = 1;
    SPINNER_VOLLEYS(reg_a4)->speed = 0;
    SPINNER_VOLLEYS(reg_a4)->arm = 0;
    reg_tmp.w = id;
    (*(u8 *)(reg_a6 + reg_tmp.h[0] + ((reg_tmp.h[0] & 1) ? -1 : 1)))++;
}


void stage4_boss_right_spinner_volleys_start(void) {
    stage4_boss_spinner_volleys_start(0x186);
}

typedef void (*Fn)();

extern Fn reg_call_target_as_Fn;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void stage4_boss_spinner_volleys(u32 arg0, u32 arg1, s32 (*arg2)(void *), s32 arg3) {
    reg_tmp.b[0] = SPINNER_VOLLEYS(reg_a4)->shot.t.count;
    SPINNER_VOLLEYS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    SPINNER_VOLLEYS(reg_a4)->shot.t.count = SPINNER_VOLLEYS(reg_a4)->shot.t.reload;
    reg_call_target_as_Fn = (Fn) arg2;
    reg_call_target_as_Fn();
    reg_tmp.w = arg0;
    reg_d0.h[0] = LOOKUP(reg_tmp.h[0]);
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    reg_d7.h[0] = reg_d1.h[0];
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_d7.b[0] += 0x20;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.w -= 0x10000;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d1.b[0] -= 9;
    bullet_fire256();
    reg_d1.b[0] -= 3;
    bullet_fire256();
    SPINNER_VOLLEYS(reg_a4)->arm += 1;
    if ((s16) SPINNER_VOLLEYS(reg_a4)->arm < 3) goto next_1;
    SPINNER_VOLLEYS(reg_a4)->arm = 0;
next_1:
    SPINNER_VOLLEYS(reg_a4)->volleys_left -= 1;
    if ((s16) SPINNER_VOLLEYS(reg_a4)->volleys_left != 0) goto next_2;
    SPINNER_VOLLEYS(reg_a4)->running = 0;
next_2:;
}



void stage4_boss_right_spinner_volleys(void) {
    stage4_boss_spinner_volleys(0xC6, 0xC2, (void *)stage4_boss_right_spinner_turn, 0x186);
}

void stage4_boss_spinner_volleys_b_start(s32 byteOffset)
{
    u8 *counter;

    SPINNER_VOLLEYS(reg_a4)->shot.h = 0;
    SPINNER_VOLLEYS(reg_a4)->volleys_left = 1;
    SPINNER_VOLLEYS(reg_a4)->speed = 0;
    SPINNER_VOLLEYS(reg_a4)->arm = 0;
    counter = reg_a6 + byteOffset + (!(byteOffset & 1) ? 1 : -1);
    *counter += 1;
}


void stage4_boss_right_spinner_volleys_b_start(void) {
    stage4_boss_spinner_volleys_b_start(0x186);
}

s32 bullet_fire256_fast();

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void stage4_boss_spinner_volleys_b(arg0, arg1, arg2)
    u32 arg0;
    u32 arg1;
    s32 (*arg2)(void *);
{
    reg_tmp.b[0] = SPINNER_VOLLEYS(reg_a4)->shot.t.count;
    SPINNER_VOLLEYS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    SPINNER_VOLLEYS(reg_a4)->shot.t.count = SPINNER_VOLLEYS(reg_a4)->shot.t.reload;
    reg_call_target_as_Fn = (Fn) arg2;
    reg_call_target_as_Fn();
    reg_d0.h[0] = LOOKUP(arg0);
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_VOLLEYS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = LOOKUP(arg1);
    reg_d2.h[0] = LOOKUP(arg1 + 2);
    reg_d4.w = 0;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] += 0xA;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0x1E;
    bullet_fire256_fast();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fast();
    SPINNER_VOLLEYS(reg_a4)->arm += 1;
    if ((s16) SPINNER_VOLLEYS(reg_a4)->arm < 3) goto next_1;
    SPINNER_VOLLEYS(reg_a4)->arm = 0;
next_1:
    SPINNER_VOLLEYS(reg_a4)->volleys_left -= 1;
    if ((s16) SPINNER_VOLLEYS(reg_a4)->volleys_left != 0) goto next_2;
    SPINNER_VOLLEYS(reg_a4)->running = 0;
next_2:;
}


void stage4_boss_right_spinner_volleys_b(void) {
    stage4_boss_spinner_volleys_b(0xC6, 0xC2, (void *)(&stage4_boss_right_spinner_turn), 0x186);
}

void stage4_boss_spinner_arms_start(void) {
    SPINNER_ARMS(reg_a4)->shot.h = 0x2020;
    SPINNER_ARMS(reg_a4)->volleys_left = 5;
    SPINNER_ARMS(reg_a4)->speed = 4;
    SPINNER_ARMS(reg_a4)->arm = 0;
}


void stage4_boss_right_spinner_arms_start(void) {
    stage4_boss_spinner_arms_start();
}

s32 rng_next();
s32 rng_next_unsigned();
extern u8 D_0026ECC0[];

void stage4_boss_spinner_arms(s32 arg0, s32 arg1, void *arg2) {
    s32 aim256_at_player();
    u32 saved;
    u32 idx;

    reg_call_target = (Fn)(arg2);
    reg_call_target();
    reg_tmp.b[0] = SPINNER_ARMS(reg_a4)->shot.t.count;
    SPINNER_ARMS(reg_a4)->shot.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    SPINNER_ARMS(reg_a4)->shot.t.count = SPINNER_ARMS(reg_a4)->shot.t.reload;
    if (SPINNER_ARMS(reg_a4)->arm != 0) goto next_0;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    stage4_boss_spinner_muzzle();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = SPINNER_ARMS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_0:
    if (SPINNER_ARMS(reg_a4)->arm != 1) goto next_1;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = SPINNER_ARMS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_1:
    if (SPINNER_ARMS(reg_a4)->arm != 2) goto next_2;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    saved = reg_d3.w;
    reg_d0.h[0] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    reg_d0.h[0] += reg_d3.h[0];
    reg_tmp3.w = reg_d3.w;
    reg_d3.h[1] = reg_d3.h[0];
    reg_d3.h[0] = reg_tmp3.h[1];
    aim256_at_player();
    reg_d3.w = saved;
    rng_next();
    reg_d1.b[0] += reg_d0.b[0];
    rng_next_unsigned();
    reg_d0.h[0] &= 3;
    idx = reg_d0.h[0];
    reg_d0.h[0] = SPINNER_ARMS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 0xB;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    ((Fn)*(u32 *)((u8 *)D_0026ECC0 + (idx * 4)))();
next_2:
    SPINNER_ARMS(reg_a4)->arm += 1;
    if (SPINNER_ARMS(reg_a4)->arm != 3) goto next_3;
    SPINNER_ARMS(reg_a4)->arm = 0;
next_3:
    SPINNER_ARMS(reg_a4)->volleys_left -= 1;
    if ((s16) SPINNER_ARMS(reg_a4)->volleys_left != 0) return;
    SPINNER_ARMS(reg_a4)->running = 0;
}


void stage4_boss_right_spinner_arms(void) {
    stage4_boss_spinner_arms(0xC6, 0xC2, (void *)stage4_boss_right_spinner_turn);
}

s32 bullet_fire256_double();

void stage4_boss_fire_doubles(void) {
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
}

void stage4_boss_fire_doubles_3way(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.sw;
    reg_d7.sw = temp_s0;
    rng_next_unsigned();
    reg_d0.b[0] &= 7;
    reg_d0.b[0] += 3;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.sw = temp_s0;
    reg_d1.b[0] -= reg_d6.b[0];
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.sw = reg_d7.sw;
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_double(reg_d6.b[0]);
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
    reg_d0.sw += 0xFFFE0000;
    bullet_fire256_double();
}

s32 bullet_fire256_2way();
void stage4_boss_fire_2ways_3way(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.w;
    reg_d7.w = temp_s0;
    rng_next_unsigned();
    reg_d0.b[0] &= 0xF;
    reg_d0.b[0] += 6;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.w = temp_s0;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    reg_d1.b[0] += reg_d6.b[0];
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
    reg_d0.w -= 0x20000;
    bullet_fire256_2way();
}

void stage4_boss_spinner_rounds_start(void) {
    SPINNER_ROUNDS(reg_a4)->shot.sh = 0x4000;
    SPINNER_ROUNDS(reg_a4)->rounds.sh = 0x909;
    SPINNER_ROUNDS(reg_a4)->speed = 7;
    SPINNER_ROUNDS(reg_a4)->arm = 0;
    SPINNER_ROUNDS(reg_a4)->pass = 0;
}


void stage4_boss_right_spinner_rounds_start(void) {
    stage4_boss_spinner_rounds_start();
}


void stage4_boss_spinner_rounds(s32 first, s32 second, void (*callback)(void), s8 *table) {
    reg_call_target = (Fn) callback;
    reg_call_target();
    reg_a0 = (u8 *)table;
    reg_a0 += SPINNER_ROUNDS(reg_a4)->pass;
    reg_d7.b[0] = *(s8 *)reg_a0;
    reg_tmp.b[0] = SPINNER_ROUNDS(reg_a4)->shot.t.count;
    SPINNER_ROUNDS(reg_a4)->shot.t.count -= 1;
    if (reg_tmp.b[0] > 0) return;
    SPINNER_ROUNDS(reg_a4)->shot.t.count = SPINNER_ROUNDS(reg_a4)->shot.t.reload;
    if (SPINNER_ROUNDS(reg_a4)->arm != 0) goto next_1;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = SPINNER_ROUNDS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_1:
    if (SPINNER_ROUNDS(reg_a4)->arm != 1) goto next_2;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = SPINNER_ROUNDS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_2:
    if (SPINNER_ROUNDS(reg_a4)->arm != 2) goto next_3;
    reg_d0.h[0] = (first) ? *(u16 *) (reg_a6 + ((s16) first & ~1)) : *(u16 *) reg_a6;
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d0.h[0] = SPINNER_ROUNDS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (second) ? *(u16 *) (reg_a6 + ((s16) second & ~1)) : *(u16 *) reg_a6;
    reg_d2.h[0] = (second + 2) ? *(u16 *) (reg_a6 + ((s16) (second + 2) & ~1)) : *(u16 *) reg_a6;
    reg_d4.w = 0;
    bullet_fire256();
next_3:
    SPINNER_ROUNDS(reg_a4)->speed += 1;
    SPINNER_ROUNDS(reg_a4)->arm += 1;
    if ((s16) SPINNER_ROUNDS(reg_a4)->arm <= 2) goto next_4;
    SPINNER_ROUNDS(reg_a4)->arm = 0;
next_4:
    SPINNER_ROUNDS(reg_a4)->rounds.t.count -= 1;
    if ((s8) SPINNER_ROUNDS(reg_a4)->rounds.t.count != 0) return;
    SPINNER_ROUNDS(reg_a4)->rounds.t.count = SPINNER_ROUNDS(reg_a4)->rounds.t.reload;
    SPINNER_ROUNDS(reg_a4)->shot.t.count = 4;
    SPINNER_ROUNDS(reg_a4)->arm = 0;
    SPINNER_ROUNDS(reg_a4)->speed = 6;
    SPINNER_ROUNDS(reg_a4)->pass += 1;
    if (SPINNER_ROUNDS(reg_a4)->pass != 3) return;
    SPINNER_ROUNDS(reg_a4)->running = 0;
}

extern s32 D_0028DC60[];

void stage4_boss_right_spinner_rounds(void) {
    stage4_boss_spinner_rounds(0xC6, 0xC2, (void *)stage4_boss_right_spinner_turn, (void *)D_0028DC60);
}

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : ENTITY(reg_a6)->flags.h)

void stage4_boss_spinner_sweep_start(arg0, arg1)
    u32 arg0;
    u8 arg1;
{
    s32 aim256_at_player();
    SPINNER_SWEEP(reg_a4)->shot.h = 4;
    SPINNER_SWEEP(reg_a4)->shots_left = 0x50;
    SPINNER_SWEEP(reg_a4)->speed = -4;
    SPINNER_SWEEP(reg_a4)->wait = 0x40;
    SPINNER_SWEEP(reg_a4)->unread_0C = 2;
    SPINNER_SWEEP(reg_a4)->unread_10 = 0;
    SPINNER_SWEEP(reg_a4)->unread_12 = 0xC;
    SPINNER_SWEEP(reg_a4)->unread_14 = 5;
    SPINNER_SWEEP(reg_a4)->step = 0;
    SPINNER_SWEEP(reg_a4)->side = arg1;
    SPINNER_SWEEP(reg_a4)->spread = 1;
    SPINNER_SWEEP(reg_a4)->speed_up.h = 0x808;
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d1.h[0] = LOOKUP(arg0 + 2);
    aim256_at_player();
    SPINNER_SWEEP(reg_a4)->aim = reg_d1.b[0];
    reg_d0.b[0] = SPINNER_SWEEP(reg_a4)->side;
    reg_d0.b[0] = (s8) reg_d0.b[0] * 0x10;
    SPINNER_SWEEP(reg_a4)->aim -= reg_d0.b[0];
}


void stage4_boss_right_spinner_sweep_start(void) {
    stage4_boss_spinner_sweep_start(0xC2, -1);
}

void stage4_boss_spinner_sweep(arg0, arg1, arg2)
    s32 arg0;
    s32 arg1;
    void *arg2;
{
    if (SPINNER_SWEEP(reg_a4)->step != 0) goto next_0;
    if ((s16) SPINNER_SWEEP(reg_a4)->wait <= 0x10) goto next_1;
    reg_call_target = (Fn)(arg2);
    reg_call_target();
next_1:
    SPINNER_SWEEP(reg_a4)->wait -= 1;
    if ((s16) SPINNER_SWEEP(reg_a4)->wait != 0) goto next_0;
    SPINNER_SWEEP(reg_a4)->step = 1;
next_0:
    if (SPINNER_SWEEP(reg_a4)->step != 1) return;
    SPINNER_SWEEP(reg_a4)->spread += 1;
    reg_tmp.b[0] = SPINNER_SWEEP(reg_a4)->shot.t.count;
    SPINNER_SWEEP(reg_a4)->shot.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) return;
    SPINNER_SWEEP(reg_a4)->shot.t.count = SPINNER_SWEEP(reg_a4)->shot.t.reload;
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_SWEEP(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = SPINNER_SWEEP(reg_a4)->spread;
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_SWEEP(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = SPINNER_SWEEP(reg_a4)->spread;
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = ((arg0) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg0) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    reg_d0.h[0] = SPINNER_SWEEP(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 4;
    reg_d2.h[1] = ((arg1) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)((u8 *)reg_a6 + ((s16)(arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    reg_d7.b[0] = SPINNER_SWEEP(reg_a4)->spread;
    reg_d1.b[0] -= reg_d7.b[0];
    bullet_fire256();
    reg_d0.h[0] = 9;
    reg_d0.w -= 0x40000;
    reg_d1.b[0] += reg_d7.b[0];
    reg_d1.b[0] += reg_d7.b[0];
    bullet_fire256();
    reg_tmp.b[0] = SPINNER_SWEEP(reg_a4)->speed_up.t.count;
    SPINNER_SWEEP(reg_a4)->speed_up.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    SPINNER_SWEEP(reg_a4)->speed_up.t.count = SPINNER_SWEEP(reg_a4)->speed_up.t.reload;
    SPINNER_SWEEP(reg_a4)->speed += 1;
next_2:
    SPINNER_SWEEP(reg_a4)->shots_left -= 1;
    if ((s16) SPINNER_SWEEP(reg_a4)->shots_left != 0) return;
    SPINNER_SWEEP(reg_a4)->running = 0;
}



void stage4_boss_right_spinner_sweep(void) {
    stage4_boss_spinner_sweep(0xC6, 0xC2, (void *)stage4_boss_right_spinner_turn_back, 0x188);
}

extern void (*stage4_boss_left_spinner_routines[])(void);

void stage4_boss_fire_left_spinner_start(void)
{
    reg_d0.h[0] = SPINNER(reg_a4)->pattern;
    reg_d0.h[0] *= 2;
    stage4_boss_left_spinner_routines[(u16)reg_d0.h[0]]();
    stage4_boss_fire_left_spinner();
}

extern Fn stage4_boss_left_spinner_routines[];

void stage4_boss_fire_left_spinner(void) {
    reg_d0.h[0] = SPINNER(reg_a4)->pattern;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += 1;
    (*(Fn *)((u8 *)stage4_boss_left_spinner_routines + (reg_d0.h[0] << 2)))();
}

void stage4_boss_left_spinner_volleys_start(void) {
    stage4_boss_spinner_volleys_start(0x187);
}


void stage4_boss_left_spinner_volleys(void) {
    stage4_boss_spinner_volleys(0xE6, 0xE2, (void *)(&stage4_boss_left_spinner_turn_back), 0x187);
}

void stage4_boss_left_spinner_volleys_b_start(void) {
    stage4_boss_spinner_volleys_b_start(0x187);
}



void stage4_boss_left_spinner_volleys_b(void) {
    stage4_boss_spinner_volleys_b(0xE6, 0xE2, (void *)stage4_boss_left_spinner_turn_back, 0x187);
}

void stage4_boss_left_spinner_arms_start(void) {
    stage4_boss_spinner_arms_start();
}


void stage4_boss_left_spinner_arms(void) {
    stage4_boss_spinner_arms(0xE6, 0xE2, (void *)stage4_boss_left_spinner_turn_back);
}

void stage4_boss_left_spinner_rounds_start(void) {
    stage4_boss_spinner_rounds_start();
}

extern s32 D_0028DC64[];

void stage4_boss_left_spinner_rounds(void) {
    stage4_boss_spinner_rounds(0xE6, 0xE2, (void *)stage4_boss_left_spinner_turn_back, (void *)D_0028DC64);
}


void stage4_boss_left_spinner_sweep_start(void) {
    stage4_boss_spinner_sweep_start(0xE2, 1);
}


void stage4_boss_left_spinner_sweep(void) {
    stage4_boss_spinner_sweep(0xE6, 0xE2, (void *)stage4_boss_left_spinner_turn_back, 0x189);
}

void stage4_boss_fire_aimed_gun_start(void) {
    s32 aim256_at_player(s32, s32);
    AIMED_GUN(reg_a4)->shot.sh = 0xC20;
    AIMED_GUN(reg_a4)->spread = 3;
    AIMED_GUN(reg_a4)->outer_spread = 8;
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim256_at_player(3, 0xC20);
    AIMED_GUN(reg_a4)->aim = (u8) reg_d1.b[0];
}

extern u16 g_direction_offsets_500[];
extern u16 g_bullets_blocked;

void stage4_boss_fire_aimed_gun(void) {
    s32 aim256_at_player();
    reg_tmp.b[0] = AIMED_GUN(reg_a4)->shot.t.count;
    AIMED_GUN(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        AIMED_GUN(reg_a4)->shot.t.count = (u8) AIMED_GUN(reg_a4)->shot.t.reload;
        if (g_bullets_blocked == 0) {
            reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
            aim256_at_player();
            AIMED_GUN(reg_a4)->aim = (u8) reg_d1.b[0];
            reg_a0 = (u8 *)(g_direction_offsets_500);
            reg_d1.w = 0;
            reg_d1.b[0] = AIMED_GUN(reg_a4)->aim;
            reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d1.b[0] = AIMED_GUN(reg_a4)->aim;
            reg_d0.w = 0xFFFC000B;
            reg_d2.h[1] = ENTITY(reg_a6)[8].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[8].x.h;
            reg_d4.w = 0;
            bullet_fire256();
            reg_d6.w = 2;
            do {
                reg_d1.b[0] += AIMED_GUN(reg_a4)->spread;
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] += AIMED_GUN(reg_a4)->spread;
            reg_d1.b[0] += AIMED_GUN(reg_a4)->spread;
            reg_d1.b[0] += AIMED_GUN(reg_a4)->spread;
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] += AIMED_GUN(reg_a4)->outer_spread;
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xFFFC000B;
            reg_d1.b[0] = AIMED_GUN(reg_a4)->aim;
            reg_d6.w = 2;
            do {
                reg_d1.b[0] -= AIMED_GUN(reg_a4)->spread;
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] -= AIMED_GUN(reg_a4)->spread;
            reg_d1.b[0] -= AIMED_GUN(reg_a4)->spread;
            reg_d1.b[0] -= AIMED_GUN(reg_a4)->spread;
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] -= AIMED_GUN(reg_a4)->outer_spread;
                bullet_fire256();
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
    }
}

void stage4_boss_spinner_fire_toward(s32 arg0, s32 arg1) {
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = BOTH_SPINNERS(reg_a4)->direction;
    reg_d0.h[0] = BOTH_SPINNERS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 8;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = BOTH_SPINNERS(reg_a4)->direction;
    reg_d0.h[0] = BOTH_SPINNERS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0x10;
    stage4_boss_spinner_muzzle();
    reg_d1.b[0] = BOTH_SPINNERS(reg_a4)->direction;
    reg_d0.h[0] = BOTH_SPINNERS(reg_a4)->speed;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = 5;
    reg_d2.h[1] = (arg1 != 0) ? *(u16 *)(reg_a6 + ((s16) arg1 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg1 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg1 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d4.w = 0;
    bullet_fire256();
    reg_d1.b[0] += 3;
    bullet_fire256();
}


void stage4_boss_fire_both_spinners_start(void) {
    BOTH_SPINNERS(reg_a4)->turn.sh = 0x404;
    BOTH_SPINNERS(reg_a4)->shot.sh = 0x1040;
    BOTH_SPINNERS(reg_a4)->speed = 0x10;
    BOTH_SPINNERS(reg_a4)->volleys = 0;
    BOTH_SPINNERS(reg_a4)->rounds_left = 5;
    BOTH_SPINNERS(reg_a4)->direction = 0;
    stage4_boss_fire_both_spinners();
}


void stage4_boss_fire_both_spinners(void) {
    s32 aim256_at_player();
    u16 t;

    reg_tmp.b[0] = BOTH_SPINNERS(reg_a4)->turn.t.count;
    BOTH_SPINNERS(reg_a4)->turn.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_1;
    BOTH_SPINNERS(reg_a4)->turn.t.count = BOTH_SPINNERS(reg_a4)->turn.t.reload;
    stage4_boss_right_spinner_turn();
    stage4_boss_left_spinner_turn_back();
next_1:
    reg_tmp.b[0] = BOTH_SPINNERS(reg_a4)->shot.t.count;
    BOTH_SPINNERS(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    BOTH_SPINNERS(reg_a4)->shot.t.count = BOTH_SPINNERS(reg_a4)->shot.t.reload;
    reg_d0.h[0] = ENTITY(reg_a6)[6].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[6].x.h;
    aim256_at_player();
    BOTH_SPINNERS(reg_a4)->direction = reg_d1.b[0];
    stage4_boss_spinner_fire_toward(0xC6, 0xC2);
    BOTH_SPINNERS(reg_a4)->direction += 0x18;
    stage4_boss_spinner_fire_toward(0xC6, 0xC2);
    BOTH_SPINNERS(reg_a4)->direction -= 0x30;
    stage4_boss_spinner_fire_toward(0xC6, 0xC2);
    reg_d0.h[0] = ENTITY(reg_a6)[7].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[7].x.h;
    aim256_at_player();
    BOTH_SPINNERS(reg_a4)->direction = reg_d1.b[0];
    stage4_boss_spinner_fire_toward(0xE6, 0xE2);
    BOTH_SPINNERS(reg_a4)->direction += 0x18;
    stage4_boss_spinner_fire_toward(0xE6, 0xE2);
    BOTH_SPINNERS(reg_a4)->direction -= 0x30;
    stage4_boss_spinner_fire_toward(0xE6, 0xE2);
    t = BOTH_SPINNERS(reg_a4)->volleys;
    if (t == 3) goto next_2;
    BOTH_SPINNERS(reg_a4)->volleys = t + 1;
    if ((s16) BOTH_SPINNERS(reg_a4)->volleys < 3) goto block_rts;
    BOTH_SPINNERS(reg_a4)->shot.h = 0x5020;
block_rts:
    return;
next_2:
    BOTH_SPINNERS(reg_a4)->rounds_left -= 1;
    if ((s16) BOTH_SPINNERS(reg_a4)->rounds_left != 0) return;
    BOTH_SPINNERS(reg_a4)->running = 0;
}


void stage4_boss_fire_center_hatch_start(void) {
    CENTER_HATCH(reg_a4)->muzzle = 0;
    stage4_boss_fire_center_hatch();
}

s32 spawn_request_add();
extern u8 D_0026EBD0[];
extern u8 D_0026EBE0[];

void stage4_boss_fire_center_hatch(arg1)
    u8 arg1;
{
    u16 temp_a0;
    u16 temp_a0_3;
    u32 temp_a0_2;
    u32 temp_a0_4;
    u8 var_a1;

    var_a1 = arg1;
    reg_tmp.b[0] = CENTER_HATCH(reg_a4)->shot.t.count;
    CENTER_HATCH(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        CENTER_HATCH(reg_a4)->shot.t.count = (u8) CENTER_HATCH(reg_a4)->shot.t.reload;
        if (CENTER_HATCH(reg_a4)->sides & 1) {
            reg_a3 = (u8 *)D_0026EBD0;
            temp_a0 = CENTER_HATCH(reg_a4)->muzzle;
            reg_a3 += temp_a0;
            reg_d0.w = ENEMY_STAGE4_BOSS_MISSILE;
            spawn_request_add();
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            temp_a0_2 = reg_d2.w;
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d2.w = temp_a0_2 + reg_tmp.w;
            STAGE4_MISSILE(reg_a0)->at_start.y = (u16) reg_d2.h[1];
            STAGE4_MISSILE(reg_a0)->at_start.x = (u16) reg_d2.h[0];
            rng_next();
            reg_d0.b[0] += 0x20;
            STAGE4_MISSILE(reg_a0)->at_start.move.b.speed = (u8) reg_d0.b[0];
            rng_next();
            reg_d1.b[0] = 0x30;
            reg_d1.b[0] += reg_d0.b[0];
            STAGE4_MISSILE(reg_a0)->at_start.move.b.dir = (u8) reg_d1.b[0];
        }
        if (CENTER_HATCH(reg_a4)->sides & 2) {
            reg_a3 = (u8 *)D_0026EBE0;
            temp_a0_3 = CENTER_HATCH(reg_a4)->muzzle;
            reg_a3 += temp_a0_3;
            reg_d0.w = ENEMY_STAGE4_BOSS_MISSILE;
            spawn_request_add();
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            temp_a0_4 = reg_d2.w;
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_d2.w = temp_a0_4 + reg_tmp.w;
            STAGE4_MISSILE(reg_a0)->at_start.y = (u16) reg_d2.h[1];
            STAGE4_MISSILE(reg_a0)->at_start.x = (u16) reg_d2.h[0];
            rng_next();
            reg_d0.b[0] += 0x20;
            STAGE4_MISSILE(reg_a0)->at_start.move.b.speed = (u8) reg_d0.b[0];
            rng_next();
            reg_d1.b[0] = 0x10;
            reg_d1.b[0] += reg_d0.b[0];
            STAGE4_MISSILE(reg_a0)->at_start.move.b.dir = (u8) reg_d1.b[0];
        }
        CENTER_HATCH(reg_a4)->muzzle += 4;
        CENTER_HATCH(reg_a4)->muzzle &= 0xF;
        CENTER_HATCH(reg_a4)->volleys_left -= 1;
        if ((s16) CENTER_HATCH(reg_a4)->volleys_left == 0) {
            CENTER_HATCH(reg_a4)->running = 0;
        }
    }
}

void stage4_boss_pod_aimed_start(s16 arg0) {
    POD_AIMED(reg_a4)->shot.sh = arg0;
    POD_AIMED(reg_a4)->shot.t.count += 0x40;
    POD_AIMED(reg_a4)->burst.sh = 0x202;
}

void stage4_boss_pod_aimed(s32 arg0, s32 arg1) {
    s32 aim256_at_player();
    reg_tmp.b[0] = POD_AIMED(reg_a4)->shot.t.count;
    POD_AIMED(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    POD_AIMED(reg_a4)->shot.t.count = POD_AIMED(reg_a4)->shot.t.reload;
    reg_d0.h[0] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d1.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d0.h[0] += 0xF940;
    reg_d1.h[0] += arg1;
    aim256_at_player();
    reg_d2.h[1] = (arg0 != 0) ? *(u16 *)(reg_a6 + ((s16) arg0 & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d2.h[0] = ((arg0 + 2) != 0) ? *(u16 *)(reg_a6 + ((s16) (arg0 + 2) & ~1)) : ENTITY(reg_a6)->flags.h;
    reg_d3.w = arg1 + 0xF9400000;
    reg_d4.w = 0;
    reg_d0.w = 4;
    bullet_fire256();
    reg_d1.b[0] += 6;
    bullet_fire256();
    reg_d1.b[0] += 6;
    bullet_fire256();
    reg_d1.b[0] -= 0x12;
    bullet_fire256();
    reg_d1.b[0] -= 6;
    bullet_fire256();
    POD_AIMED(reg_a4)->burst.t.count -= 1;
    if ((s8) POD_AIMED(reg_a4)->burst.t.count != 0) goto block_rts;
    POD_AIMED(reg_a4)->burst.t.count = POD_AIMED(reg_a4)->burst.t.reload;
    POD_AIMED(reg_a4)->shot.t.count = 0x40;
block_rts:
    return;
}


void stage4_boss_fire_right_pod_start(void) {
    POD_SPRAY(reg_a4)->unread_03 = 0;
    POD_SPRAY(reg_a4)->shot.sh = 0x303;
    POD_SPRAY(reg_a4)->turn.sh = 0x606;
    POD_SPRAY(reg_a4)->direction_a = 0;
    POD_SPRAY(reg_a4)->direction_b = 0;
    stage4_boss_fire_right_pod();
}

extern u16 g_loop;

void stage4_boss_fire_right_pod(void) {
    s32 bullet_fire256_fixed();
    u16 temp_a1;
    u16 temp_a2;
    u8 temp_a0;

    reg_tmp.b[0] = POD_SPRAY(reg_a4)->shot.t.count;
    POD_SPRAY(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        POD_SPRAY(reg_a4)->shot.t.count = (u8) POD_SPRAY(reg_a4)->shot.t.reload;
        reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
        temp_a1 = ENTITY(reg_a6)[4].x.h;
        reg_d2.h[0] = temp_a1;
        reg_d3.w = 0xF94001C0;
        reg_d4.w = 0;
        reg_d1.w = 0;
        reg_d1.b[0] = POD_SPRAY(reg_a4)->direction_a;
        reg_d0.w = 0xFFFC0016;
        if (g_loop == 0) {
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
        } else {
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
        }
        reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
        temp_a2 = ENTITY(reg_a6)[5].x.h;
        reg_d2.h[0] = temp_a2;
        reg_d3.w = 0xF93FFE40;
        reg_d4.w = 0;
        reg_d1.w = 0;
        temp_a0 = POD_SPRAY(reg_a4)->direction_b;
        reg_d1.b[0] = temp_a0;
        reg_d0.w = 0xFFFC0016;
        if (g_loop == 0) {
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
            reg_d1.b[0] += 0x55;
            bullet_fire256();
        } else {
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
            reg_d1.b[0] += 0x40;
            bullet_fire256_fixed();
        }
        POD_SPRAY(reg_a4)->direction_a -= 4;
        POD_SPRAY(reg_a4)->direction_b += 4;
        reg_tmp.b[0] = POD_SPRAY(reg_a4)->turn.t.count;
        POD_SPRAY(reg_a4)->turn.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            POD_SPRAY(reg_a4)->turn.t.count = (u8) POD_SPRAY(reg_a4)->turn.t.reload;
            POD_SPRAY(reg_a4)->direction_a -= 4;
            POD_SPRAY(reg_a4)->direction_b += 4;
        }
    }
}


void stage4_boss_fire_left_pod_start(void) {
    stage4_boss_pod_aimed_start(0x1020);
    stage4_boss_fire_left_pod();
}

extern s16 *reg_a4_as_s16_p;

void stage4_boss_fire_left_pod(void) {
    if (ENTITY(reg_a6)[4].misc.b.draw_layer != 0) {
        *reg_a4_as_s16_p = 0;
        return;
    }
    stage4_boss_pod_aimed(0xA2, -0x1C0);
}


void stage4_boss_fire_cutter_bay_start(void) {
    CUTTER_BAY(reg_a4)->side[0].wait.sh = 0x40D;
    CUTTER_BAY(reg_a4)->side[0].shot.sh = 0x40;
    CUTTER_BAY(reg_a4)->side[0].burst.sh = 1;
    CUTTER_BAY(reg_a4)->side[1].wait.sh = 0x410;
    CUTTER_BAY(reg_a4)->side[1].shot.sh = 0x10;
    CUTTER_BAY(reg_a4)->side[1].burst.sh = 1;
    CUTTER_BAY(reg_a4)->speed_a = 0;
    CUTTER_BAY(reg_a4)->speed_b = 0;
    CUTTER_BAY(reg_a4)->angle_a = 0;
    CUTTER_BAY(reg_a4)->turn_a = 0x18;
    CUTTER_BAY(reg_a4)->angle_b = 0;
    CUTTER_BAY(reg_a4)->turn_b = 0xEC;
    CUTTER_BAY(reg_a4)->other_17 = 0;
    CUTTER_BAY(reg_a4)->other_16 = 0;
    stage4_boss_fire_cutter_bay(0x18, 0x10, 0x410, 1);
}


void stage4_boss_fire_cutter_bay() {
    s32 aim256_at_player();
    if (CUTTER_BAY(reg_a4)->side[0].burst.t.count == 0) {
        reg_tmp.b[0] = CUTTER_BAY(reg_a4)->side[0].wait.t.count;
        CUTTER_BAY(reg_a4)->side[0].wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            CUTTER_BAY(reg_a4)->side[0].wait.t.count = (u8) CUTTER_BAY(reg_a4)->side[0].wait.t.reload;
            CUTTER_BAY(reg_a4)->side[0].burst.t.count = (u8) CUTTER_BAY(reg_a4)->side[0].burst.t.reload;
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = CUTTER_BAY(reg_a4)->side[0].shot.t.count;
        CUTTER_BAY(reg_a4)->side[0].shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            CUTTER_BAY(reg_a4)->side[0].shot.t.count = (u8) CUTTER_BAY(reg_a4)->side[0].shot.t.reload;
            reg_d0.b[0] = CUTTER_BAY(reg_a4)->turn_a;
            CUTTER_BAY(reg_a4)->angle_a += reg_d0.b[0];
            reg_d1.b[0] = CUTTER_BAY(reg_a4)->angle_a;
            reg_d1.b[0] = 0x40;
            reg_d3.w = 0xF9400200;
            reg_d0.w = 0;
            reg_d0.b[0] = CUTTER_BAY(reg_a4)->speed_a;
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = ENTITY(reg_a6)[4].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[4].x.h;
            reg_d4.w = 0;
            reg_d7.b[0] = CUTTER_BAY(reg_a4)->other_17;
            stage4_boss_fire_4way();
            CUTTER_BAY(reg_a4)->side[0].burst.t.count -= 1;
        }
    }
    if (CUTTER_BAY(reg_a4)->side[1].burst.t.count == 0) {
        reg_tmp.b[0] = CUTTER_BAY(reg_a4)->side[1].wait.t.count;
        CUTTER_BAY(reg_a4)->side[1].wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            CUTTER_BAY(reg_a4)->side[1].wait.t.count = (u8) CUTTER_BAY(reg_a4)->side[1].wait.t.reload;
            CUTTER_BAY(reg_a4)->side[1].burst.t.count = (u8) CUTTER_BAY(reg_a4)->side[1].burst.t.reload;
            reg_d0.b[0] = CUTTER_BAY(reg_a4)->turn_b;
            CUTTER_BAY(reg_a4)->angle_b += reg_d0.b[0];
            goto block_8;
        }
    } else {
block_8:
        reg_tmp.b[0] = CUTTER_BAY(reg_a4)->side[1].shot.t.count;
        CUTTER_BAY(reg_a4)->side[1].shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            CUTTER_BAY(reg_a4)->side[1].shot.t.count = (u8) CUTTER_BAY(reg_a4)->side[1].shot.t.reload;
            reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d0.h[0] += 0xF940;
            reg_d1.h[0] += 0xFE00;
            aim256_at_player();
            reg_d1.b[0] = CUTTER_BAY(reg_a4)->angle_b;
            reg_d1.b[0] = 0xC0;
            reg_d0.w = 0;
            reg_d3.w = 0xF93FFE00;
            reg_d0.b[0] = CUTTER_BAY(reg_a4)->speed_b;
            reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 5;
            reg_d2.h[1] = ENTITY(reg_a6)[5].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[5].x.h;
            reg_d4.w = 0;
            reg_d7.b[0] = CUTTER_BAY(reg_a4)->other_16;
            stage4_boss_fire_4way();
            CUTTER_BAY(reg_a4)->side[1].burst.t.count -= 1;
        }
    }
}

s32 bullet_fire256();                            /* extern */

void stage4_boss_fire_4way(void) {
    u32 temp_s0;

    temp_s0 = reg_d1.w;
    reg_d6.b[0] = reg_d1.b[0];
    reg_d1.b[0] += 4;
    bullet_fire256();
    reg_d1.b[0] += 8;
    bullet_fire256();
    reg_d1.b[0] = reg_d6.b[0];
    reg_d1.b[0] -= 4;
    bullet_fire256();
    reg_d1.b[0] -= 8;
    bullet_fire256();
    reg_d1.w = temp_s0;
}

extern s16 g_enemy_signal_e_as_s16;

void stage4_boss_fire_cutters_start(void) {
    CUTTERS(reg_a4)->wait.sh = 0x820;
    CUTTERS(reg_a4)->launched = 0;
    CUTTERS(reg_a4)->unread_06 = 0xC;
    CUTTERS(reg_a4)->unread_09 = 3;
    CUTTERS(reg_a4)->angle = 0x48;
    g_enemy_signal_e_as_s16 = 0;
    CUTTERS(reg_a4)->release_delay = 0x50;
    ENTITY(reg_a6)[12].misc.sh = 0;
    stage4_boss_fire_cutters();
}

extern u8 D_0026ED10[];
extern u16 g_enemy_signal_e;

void stage4_boss_fire_cutters(void) {
    s8 var_a0;
    u8 temp_v1;

    temp_v1 = CUTTERS(reg_a4)->wait.t.count;
    if (temp_v1 != 0) {
        CUTTERS(reg_a4)->wait.t.count = (u8) (temp_v1 - 1);
        if ((s8) CUTTERS(reg_a4)->wait.t.count == 0) {
            rng_next_unsigned();
            reg_a3 = (u8 *)D_0026ED10;
            reg_d0.h[0] &= 7;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a3 += reg_d0.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a3;
            reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d6.b[0] = (u8) (s8) *(s8 *)reg_a3;
            reg_a3 += 1;
            reg_d7.w = 0;
            var_a0 = (s8) *(s8 *)reg_a3;
            reg_d7.b[0] = (u8) var_a0;
            reg_a3 += 1;
            CUTTERS(reg_a4)->launched = (u16) reg_d7.h[0];
            reg_d7.h[0] -= 1;
            do {
                reg_d0.w = ENEMY_STAGE4_BOSS_CUTTER;
                spawn_request_add();
                var_a0 = 0xFF;
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                STAGE4_CUTTER(reg_a0)->at_start.y = (u16) reg_d2.h[1];
                STAGE4_CUTTER(reg_a0)->at_start.x = (u16) reg_d2.h[0];
                STAGE4_CUTTER(reg_a0)->at_start.turn = (u8) reg_d6.b[0];
                STAGE4_CUTTER(reg_a0)->at_start.radius = (s8) *(s8 *)reg_a3;
                reg_a3 += 1;
                reg_tmp.w = (u32) reg_a6;
                STAGE4_CUTTER(reg_a0)->at_start.owner[0] = (u16) reg_tmp.h[1];
                STAGE4_CUTTER(reg_a0)->at_start.owner[1] = (u16) reg_tmp.h[0];
                STAGE4_CUTTER(reg_a0)->at_start.angle = (u8) CUTTERS(reg_a4)->angle;
                STAGE4_CUTTER(reg_a0)->at_start.look = 0xFFU;
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
    reg_d0.h[0] = ENTITY(reg_a6)[12].misc.h;
    if ((CUTTERS(reg_a4)->launched == reg_d0.h[0]) && (g_enemy_signal_e == 0)) {
        CUTTERS(reg_a4)->release_delay -= 1;
        if ((s16) CUTTERS(reg_a4)->release_delay == 0) {
            g_enemy_signal_e = 1;
            CUTTERS(reg_a4)->running = 0;
        }
    }
}

extern u16 g_enemy_signal_c;

void stage4_boss_fire_cutters_b_start(void)
{
    CUTTERS_B(reg_a4)->wait.h = 0x820;
    CUTTERS_B(reg_a4)->unread_04 = 4;
    CUTTERS_B(reg_a4)->unread_06 = 0xC;
    CUTTERS_B(reg_a4)->angle = 0x48;
    CUTTERS_B(reg_a4)->unread_08 = 0xA0;
    g_enemy_signal_c = 0;
    stage4_boss_fire_cutters_b();
}

extern u8 D_0028DC68[];

void stage4_boss_fire_cutters_b(arg1)
    u8 *arg1;
{
    u8 *var_a0;
    u8 *var_a1;
    var_a1 = (u8 *)(arg1);
    var_a0 = (u8 *)(reg_a4);
    (*(u8 *)((u8 *)(var_a0) + (3))) -= 1;
    if ((s8) CUTTERS_B(reg_a4)->wait.t.count == 0) {
        reg_a3 = (u8 *)D_0028DC68;
        reg_tmp.h[1] = *(u16 *)reg_a3;
        reg_tmp.h[0] = *(u16 *)(reg_a3 + 2);
        reg_a3 = (u8 *) reg_tmp.w;
        reg_d6.b[0] = (u8) (s8) *(s8 *)reg_a3;
        reg_a3 += 1;
        reg_d7.w = 0;
        reg_d7.b[0] = (u8) (s8) *(s8 *)reg_a3;
        reg_a3 += 1;
        reg_d7.h[0] -= 1;
        do {
            reg_d0.w = ENEMY_STAGE4_BOSS_CUTTER;
            spawn_request_add();
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
            STAGE4_CUTTER(reg_a0)->at_start.y = (u16) reg_d2.h[1];
            STAGE4_CUTTER(reg_a0)->at_start.x = (u16) reg_d2.h[0];
            STAGE4_CUTTER(reg_a0)->at_start.turn = (u8) reg_d6.b[0];
            STAGE4_CUTTER(reg_a0)->at_start.radius = (s8) *(s8 *)reg_a3;
            var_a1 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a1;
            reg_tmp.w = (u32) reg_a6;
            STAGE4_CUTTER(reg_a0)->at_start.owner[0] = (u16) reg_tmp.h[1];
            STAGE4_CUTTER(reg_a0)->at_start.owner[1] = (u16) reg_tmp.h[0];
            STAGE4_CUTTER(reg_a0)->at_start.angle = (u8) CUTTERS_B(reg_a4)->angle;
            STAGE4_CUTTER(reg_a0)->at_start.look = (s8) *(s8 *)reg_a3;
            var_a0 = (u8 *)(reg_a3 + 1);
            reg_a3 = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        CUTTERS_B(reg_a4)->running = 0;
    }
}


void stage4_boss_fire_cutter_bay_b_start(void) {
    CUTTER_BAY_B(reg_a4)->step = 0;
    CUTTER_BAY_B(reg_a4)->wait.sh = 0x4008;
    CUTTER_BAY_B(reg_a4)->shot.sh = 4;
    CUTTER_BAY_B(reg_a4)->burst.sh = 0xA;
    CUTTER_BAY_B(reg_a4)->speed = 8;
    CUTTER_BAY_B(reg_a4)->aim = 0;
    CUTTER_BAY_B(reg_a4)->muzzle = 0;
    CUTTER_BAY_B(reg_a4)->aimed = 0;
    stage4_boss_fire_cutter_bay_b();
}

extern u8 D_0026ED90[];
s32 enemy_switch_target_player();
extern u16 D_0026ED98[];
extern u8 D_0026EDA0[];
extern u8 D_0026EDA8[];

void stage4_boss_fire_cutter_bay_b(void) {
    s32 aim256_at_player();
    u16 *t1;
    u16 t2;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u8 t8;

    if (CUTTER_BAY_B(reg_a4)->step == 0) {
        if (CUTTER_BAY_B(reg_a4)->burst.t.count == 0) {
            reg_tmp.b[0] = CUTTER_BAY_B(reg_a4)->wait.t.count;
            CUTTER_BAY_B(reg_a4)->wait.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                CUTTER_BAY_B(reg_a4)->wait.t.count = (u8) CUTTER_BAY_B(reg_a4)->wait.t.reload;
                CUTTER_BAY_B(reg_a4)->burst.t.count = (u8) CUTTER_BAY_B(reg_a4)->burst.t.reload;
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += CUTTER_BAY_B(reg_a4)->muzzle;
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d0.h[0] += *(u16 *)reg_a0;
                reg_a0 += 2;
                reg_d1.h[0] += *(u16 *)reg_a0;
                aim256_at_player();
                CUTTER_BAY_B(reg_a4)->aim = (u8) reg_d1.b[0];
                rng_next();
                CUTTER_BAY_B(reg_a4)->aim += reg_d0.b[0];
                CUTTER_BAY_B(reg_a4)->speed = 0U;
                goto next_1;
            }
        } else {
next_1:
            reg_tmp.b[0] = CUTTER_BAY_B(reg_a4)->shot.t.count;
            CUTTER_BAY_B(reg_a4)->shot.t.count -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                CUTTER_BAY_B(reg_a4)->shot.t.count = (u8) CUTTER_BAY_B(reg_a4)->shot.t.reload;
                reg_d0.w = 0;
                reg_d0.b[0] = CUTTER_BAY_B(reg_a4)->speed;
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t5 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t5;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = CUTTER_BAY_B(reg_a4)->aim;
                reg_a0 = (u8 *)D_0026ED90;
                reg_a0 += CUTTER_BAY_B(reg_a4)->muzzle;
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d3.h[1] = *(u16 *)reg_a0;
                reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
                reg_d4.w = 0;
                reg_tmp.h[0] = CUTTER_BAY_B(reg_a4)->muzzle;
                reg_tmp.h[0] += ENTITY(reg_a6)[12].attr.h;
                ((Fn)*(u32 *)((u8 *)D_0026EDA0 + (reg_tmp.h[0] & ~3)))();
                CUTTER_BAY_B(reg_a4)->burst.t.count -= 1;
                if ((s8) CUTTER_BAY_B(reg_a4)->burst.t.count == 0) {
                    CUTTER_BAY_B(reg_a4)->muzzle += 4;
                    CUTTER_BAY_B(reg_a4)->muzzle &= 0xF;
                    if ((s16) CUTTER_BAY_B(reg_a4)->muzzle == 0) {
                        CUTTER_BAY_B(reg_a4)->wait.h = 0x3002;
                        CUTTER_BAY_B(reg_a4)->burst.h = 0xA;
                        CUTTER_BAY_B(reg_a4)->speed = 8U;
                        CUTTER_BAY_B(reg_a4)->step = 1U;
                        reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                        reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                        aim256_at_player();
                        CUTTER_BAY_B(reg_a4)->aim = (u8) reg_d1.b[0];
                        rng_next();
                        CUTTER_BAY_B(reg_a4)->aim += reg_d0.b[0];
                        enemy_switch_target_player();
                    }
                }
            }
        }
    }
    t8 = CUTTER_BAY_B(reg_a4)->step;
    if (t8 == 1) {
        reg_tmp.b[0] = CUTTER_BAY_B(reg_a4)->wait.t.count;
        CUTTER_BAY_B(reg_a4)->wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            CUTTER_BAY_B(reg_a4)->wait.t.count = (u8) CUTTER_BAY_B(reg_a4)->wait.t.reload;
            if (CUTTER_BAY_B(reg_a4)->aimed == 0) {
                enemy_switch_target_player();
                CUTTER_BAY_B(reg_a4)->aimed = 1U;
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                aim256_at_player();
                CUTTER_BAY_B(reg_a4)->aim = (u8) reg_d1.b[0];
            }
            reg_a3 = (u8 *)(D_0026ED98);
            reg_a2 = (u8 *)D_0026EDA8;
            reg_a2 += ENTITY(reg_a6)[12].attr.h;
            reg_d7.w = 1;
            do {
                reg_d0.w = 0;
                reg_d0.b[0] = CUTTER_BAY_B(reg_a4)->speed;
                reg_d1.w = 0;
                reg_d0.h[0] = (u16) (s8) reg_d0.b[0];
                t7 = reg_d0.h[0];
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = t7;
                reg_d0.h[0] = 0x13;
                reg_d1.b[0] = CUTTER_BAY_B(reg_a4)->aim;
                reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
                t6 = ENTITY(reg_a6)[1].x.h;
                reg_d2.h[0] = t6;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d3.h[1] = t3;
                t4 = *(u16 *)reg_a3;
                t1 = (u16 *)(reg_a3 + 2);
                reg_d3.h[0] = t4;
                reg_a3 = (u8 *)(t1);
                reg_d4.w = 0;
                reg_a0 = *(u8 **)reg_a2;
                reg_a2 += 4;
                reg_call_target = (Fn)(reg_a0);
                reg_call_target();
            } while ((s16)(--reg_d7.h[0]) >= 0);
            CUTTER_BAY_B(reg_a4)->burst.h -= 1;
            if (CUTTER_BAY_B(reg_a4)->burst.sh == 0) {
                CUTTER_BAY_B(reg_a4)->running = 0;
                t2 = ENTITY(reg_a6)[12].attr.h;
                if (t2 != 0x10) {
                    ENTITY(reg_a6)[12].attr.h = (u16) (t2 + 8);
                }
            }
        }
    }
}

void stage4_boss_fire_fixed_1(void) {
    void bullet_fire256_fixed(void);
    bullet_fire256_fixed();
}

void stage4_boss_fire_fixed_2way(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] -= 0xA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x14;
    bullet_fire256_fixed();
}

void stage4_boss_fire_fixed_3way(void) {
    s32 bullet_fire256_fixed();
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xE;
    bullet_fire256_fixed();
    reg_d1.b[0] -= 0x1C;
    bullet_fire256_fixed();
}

void stage4_boss_fire_fixed_4way(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] -= 9;
    bullet_fire256_fixed();
    reg_d1.b[0] -= 0x12;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x24;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0x12;
    bullet_fire256_fixed();
}


void stage4_boss_fire_aimed_gun_b_start(void) {
    s32 aim256_at_player(s32);
    AIMED_GUN(reg_a4)->shot.sh = 0xC20;
    AIMED_GUN(reg_a4)->spread = 7;
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim256_at_player(0xC20);
    AIMED_GUN(reg_a4)->aim = (u8) reg_d1.b[0];
    stage4_boss_fire_aimed_gun_b();
}

void stage4_boss_fire_aimed_gun_b(void) {
    s32 aim256_at_player();
    reg_tmp.b[0] = AIMED_GUN(reg_a4)->shot.t.count;
    AIMED_GUN(reg_a4)->shot.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        AIMED_GUN(reg_a4)->shot.t.count = (u8) AIMED_GUN(reg_a4)->shot.t.reload;
        reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
        reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
        aim256_at_player();
        AIMED_GUN(reg_a4)->aim = (u8) reg_d1.b[0];
        reg_d0.w = 0x4000C;
        reg_d2.h[1] = ENTITY(reg_a6)[8].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[8].x.h;
        reg_d3.w = 0;
        reg_d4.w = 0;
        bullet_fire256();
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = AIMED_GUN(reg_a4)->aim;
        reg_d6.w = 7;
        do {
            reg_d1.b[0] += AIMED_GUN(reg_a4)->spread;
            bullet_fire256();
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_d0.w = 0x4000C;
        reg_d1.b[0] = AIMED_GUN(reg_a4)->aim;
        reg_d6.w = 7;
        do {
            reg_d1.b[0] -= AIMED_GUN(reg_a4)->spread;
            bullet_fire256();
        } while ((s16)(--reg_d6.h[0]) >= 0);
    }
}


void stage4_boss_fire_both_sides_start(void)
{
    BOTH_SIDES(reg_a4)->unread_03 = 0;
    BOTH_SIDES(reg_a4)->wait.h = 0x20;
    BOTH_SIDES(reg_a4)->shot.h = 0x808;
    BOTH_SIDES(reg_a4)->burst.h = 1;
    BOTH_SIDES(reg_a4)->pattern = 0;
    BOTH_SIDES(reg_a4)->burst.t.reload = BOTH_SIDES(reg_a4)->burst_shots;
    stage4_boss_fire_both_sides();
}

extern u8 D_0028DC78[];

void stage4_boss_fire_both_sides(void) {
    u16 temp_a3;

    if (BOTH_SIDES(reg_a4)->burst.t.count == 0) {
        reg_tmp.b[0] = BOTH_SIDES(reg_a4)->wait.t.count;
        BOTH_SIDES(reg_a4)->wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            BOTH_SIDES(reg_a4)->wait.t.count = (u8) BOTH_SIDES(reg_a4)->wait.t.reload;
            BOTH_SIDES(reg_a4)->burst.t.count = (u8) BOTH_SIDES(reg_a4)->burst.t.reload;
            goto block_3;
        }
    } else {
block_3:
        reg_tmp.b[0] = BOTH_SIDES(reg_a4)->shot.t.count;
        BOTH_SIDES(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            BOTH_SIDES(reg_a4)->shot.t.count = (u8) BOTH_SIDES(reg_a4)->shot.t.reload;
            reg_d0.h[0] = 8;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0xB;
            reg_d1.w = 0x80;
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            temp_a3 = ENTITY(reg_a6)[1].x.h;
            reg_d2.h[0] = temp_a3;
            reg_d3.w = 0x08000000;
            reg_d7.h[0] = reg_d1.h[0];
            reg_d4.w = 0;
            reg_tmp.h[0] = BOTH_SIDES(reg_a4)->pattern;
            ((Fn)*(u32 *)((u8 *)D_0028DC78 + (reg_tmp.h[0] & ~3)))();
            BOTH_SIDES(reg_a4)->pattern += 4;
            BOTH_SIDES(reg_a4)->pattern &= 7;
            BOTH_SIDES(reg_a4)->burst.t.count -= 1;
            if ((s8) BOTH_SIDES(reg_a4)->burst.t.count == 0) {
                BOTH_SIDES(reg_a4)->running = 0;
            }
        }
    }
}

void stage4_boss_fire_fixed_fan_a(void) {
    s32 bullet_fire256_fixed();
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
}

void stage4_boss_fire_fixed_fan_b(void) {
    s32 bullet_fire256_fixed();
    reg_d1.b[0] += 3;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.b[0] += 6;
    bullet_fire256_fixed();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xFD;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
    reg_d1.b[0] += 0xFA;
    bullet_fire256_fixed();
}


void stage4_boss_fire_rage_wings_start(void)
{
    RAGE_WINGS(reg_a4)->unread_03 = 0;
    RAGE_WINGS(reg_a4)->wait.h = 0x404;
    RAGE_WINGS(reg_a4)->shot.h = 0x303;
    RAGE_WINGS(reg_a4)->burst.h = 5;
    RAGE_WINGS(reg_a4)->muzzle = 0;
    RAGE_WINGS(reg_a4)->aim.h = 0x8000;
    RAGE_WINGS(reg_a4)->speed = 0;
    stage4_boss_fire_rage_wings();
}


extern u8 D_0026EDC0[];

void stage4_boss_fire_rage_wings(void) {
    s32 aim256_at_player();
    if (RAGE_WINGS(reg_a4)->burst.t.count == 0) {
        reg_tmp.b[0] = RAGE_WINGS(reg_a4)->wait.t.count;
        RAGE_WINGS(reg_a4)->wait.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            RAGE_WINGS(reg_a4)->wait.t.count = (u8) RAGE_WINGS(reg_a4)->wait.t.reload;
            RAGE_WINGS(reg_a4)->burst.t.count = (u8) RAGE_WINGS(reg_a4)->burst.t.reload;
            RAGE_WINGS(reg_a4)->burst.t.reload += 1;
            rng_next_unsigned();
            reg_d0.h[0] &= 3;
            RAGE_WINGS(reg_a4)->muzzle = (u16) reg_d0.h[0];
            RAGE_WINGS(reg_a4)->speed = 0U;
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = RAGE_WINGS(reg_a4)->muzzle;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
            reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
            reg_d0.h[0] += *(u16 *)reg_a0;
            reg_d1.h[0] += *(u16 *)(reg_a0 + 2);
            aim256_at_player();
            if (cond_flag == 0) {
                RAGE_WINGS(reg_a4)->aim.b[1] = (u8) reg_d1.b[0];
            }
            goto block_4;
        }
    } else {
block_4:
        reg_tmp.b[0] = RAGE_WINGS(reg_a4)->shot.t.count;
        RAGE_WINGS(reg_a4)->shot.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            RAGE_WINGS(reg_a4)->shot.t.count = (u8) RAGE_WINGS(reg_a4)->shot.t.reload;
            reg_a0 = D_0026EDC0;
            reg_d0.h[0] = RAGE_WINGS(reg_a4)->muzzle;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d3.h[1] = *(u16 *)reg_a0;
            reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d0.h[0] = RAGE_WINGS(reg_a4)->speed;
            reg_d1.w = 0;
            reg_tmp.w = reg_d0.w;
            reg_d0.h[1] = reg_d0.h[0];
            reg_d0.h[0] = 0x13;
            reg_d1.b[0] = RAGE_WINGS(reg_a4)->aim.b[1];
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
            reg_d4.w = 0;
            bullet_fire256_fast();
            RAGE_WINGS(reg_a4)->speed += 2;
            RAGE_WINGS(reg_a4)->burst.t.count -= 1;
            if ((s8) RAGE_WINGS(reg_a4)->burst.t.count == 0) {
                enemy_switch_target_player();
                RAGE_WINGS(reg_a4)->rounds_left -= 1;
                if ((s16) RAGE_WINGS(reg_a4)->rounds_left == 0) {
                    RAGE_WINGS(reg_a4)->running = 0;
                }
            }
        }
    }
}
