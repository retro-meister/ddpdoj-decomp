#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "stage4_boss.h"

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ u8 unused_02;
    /* 0x03 */ u8 step;
    /* 0x04 */ u16 wait;
    /* 0x06 */ SlotTimer burst_a;     /* count 0xFF: off */
    /* 0x08 */ SlotTimer burst_b;
    /* 0x0A */ u16 blast;
    /* 0x0C */ SlotTimer blast_timer;
    /* 0x0E */ u16 blast_rounds;
    /* 0x10 */ SlotTimer cycle_timer;
    /* 0x12 */ u16 cycle;
} ExplodingMode;

#define EXPLODING(pointer) ((ExplodingMode *)(pointer))


void stage4_boss_mode_enter_start(void);
void stage4_boss_mode_enter(void);
void stage4_boss_mode_second_form_start(void);
void stage4_boss_mode_second_form(void);
void stage4_boss_mode_final_explosion_start(void);
void stage4_boss_mode_final_explosion(void);
void stage4_boss_mode_attack_a_start(void);
void stage4_boss_mode_attack_a(void);
void stage4_boss_mode_attack_b_start(void);
void stage4_boss_mode_attack_b(void);
void stage4_boss_mode_attack_c_start(void);
void stage4_boss_mode_attack_c(void);
void stage4_boss_mode_rage_start(void);
void stage4_boss_mode_rage(void);

/* The set-up routine and the per-frame routine of every mode, by mode number. */
void (*stage4_boss_mode_routines[])(void) = {
    stage4_boss_mode_enter_start,
    stage4_boss_mode_enter,
    stage4_boss_mode_second_form_start,
    stage4_boss_mode_second_form,
    stage4_boss_mode_final_explosion_start,
    stage4_boss_mode_final_explosion,
    stage4_boss_mode_attack_a_start,
    stage4_boss_mode_attack_a,
    stage4_boss_mode_attack_b_start,
    stage4_boss_mode_attack_b,
    stage4_boss_mode_attack_c_start,
    stage4_boss_mode_attack_c,
    stage4_boss_mode_rage_start,
    stage4_boss_mode_rage,
    0,
    0,
};

void stage4_boss_mode_enter(void);
void stage4_boss_mode_second_form();
void stage4_boss_mode_final_explosion();
void stage4_boss_final_explosion_step();
void stage4_boss_final_explosion_cycle(void);

s32 explosion_spawn();

void stage4_boss_explosions_from_table(void) {
    u16 *temp_a1_2;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        temp_a1_2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(temp_a1_2);
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d0.b[0] += reg_d0.b[0];
        reg_d0.b[0] += reg_d0.b[0];
        EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
        reg_a1 += 2;
        stage4_boss_explosions_from_table();
    }
}

s32 rng_next();
s32 rng_next_unsigned();
s32 rng_next_word();

void stage4_boss_explosions_scattered(void) {
    u16 temp_a0;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        temp_a0 = *(u16 *)reg_a1;
        reg_d0.h[0] = temp_a0;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
        EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
        EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        EXPLOSION(reg_a0)->start_y += reg_d0.h[0];
        rng_next_word();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        EXPLOSION(reg_a0)->start_x += reg_d0.h[0];
        EXPLOSION(reg_a0)->y = (u16) reg_d2.h[1];
        EXPLOSION(reg_a0)->x = (u16) reg_d2.h[0];
        EXPLOSION(reg_a0)->draw_layer = 0x10;
        EXPLOSION(reg_a0)->debris = 0;
        EXPLOSION(reg_a0)->debris_arg = 0;
        rng_next();
        reg_d0.b[0] += 0x10;
        EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
        rng_next_unsigned();
        EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
        reg_a1 += 2;
        stage4_boss_explosions_scattered();
    }
}

s32 boss_movement_start();                            /* extern */
s32 boss_part_show();                            /* extern */
s32 sprite_palette_load();                            /* extern */
extern s32 D_0025FF30_as_s32_a[];

void stage4_boss_mode_enter_start(void) {
    reg_d0.h[0] = 0x15;
    reg_a0 = (u8 *)D_0025FF30_as_s32_a;
    sprite_palette_load();
    reg_d0.w = 0;
    boss_movement_start();
    reg_d0.w = 0xA;
    boss_part_show();
    stage4_boss_mode_enter();
}

extern u16 *reg_a4_as_u16_p;

void stage4_boss_mode_enter(void) {
    *reg_a4_as_u16_p = 0;
}

s32 boss_movement_start();
s32 stage4_boss_shield_on();
s32 stage4_boss_part_stop_hits();

void stage4_boss_mode_second_form_start(void) {
    stage4_boss_shield_on();
    reg_d0.h[0] = 0x40;
    stage4_boss_part_stop_hits();
    reg_d0.h[0] = 0x60;
    stage4_boss_part_stop_hits();
    reg_d0.w = 2;
    boss_movement_start();
    EXPLODING(reg_a4)->step = 0;
    EXPLODING(reg_a4)->wait = 1;
    EXPLODING(reg_a4)->burst_a.h = 0xFF02;
    EXPLODING(reg_a4)->burst_b.h = 0xFF04;
    stage4_boss_mode_second_form(0xFF02, 1);
}

s32 boss_part_hide();
s32 explosion_burst_small();
s32 sfx_explosion_air_small();
s32 sfx_explosion_air_medium();
s32 sfx_explosion_ground_medium();
s32 sfx_explosion_ground_large();
extern u8 D_0026F260[];
extern u8 D_0026F280[];
extern u8 D_0026F290[];
extern u8 D_0026F2D0[];

void stage4_boss_mode_second_form() {
    u16 temp_a0_4;
    u16 temp_a0_5;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    temp_a0 = EXPLODING(reg_a4)->burst_a.t.count;
    if (temp_a0 != -1) {
        reg_tmp.b[0] = temp_a0;
        EXPLODING(reg_a4)->burst_a.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->burst_a.t.count = (u8) EXPLODING(reg_a4)->burst_a.t.reload;
            reg_d0.w = 1;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[8].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[8].x.h;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y -= 0x200;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
        }
    }
    temp_a0_2 = EXPLODING(reg_a4)->burst_b.t.count;
    if (temp_a0_2 != -1U) {
        reg_tmp.b[0] = temp_a0_2;
        EXPLODING(reg_a4)->burst_b.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->burst_b.t.count = (u8) EXPLODING(reg_a4)->burst_b.t.reload;
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[6].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[6].x.h;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y -= 0x400;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[7].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[7].x.h;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y -= 0x400;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
        }
    }
    if (EXPLODING(reg_a4)->step == 0) {
        EXPLODING(reg_a4)->wait -= 1;
        if ((s16) EXPLODING(reg_a4)->wait < 0) {
            EXPLODING(reg_a4)->burst_a.t.count = 0U;
            reg_d2.h[1] = ENTITY(reg_a6)[8].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[8].x.h;
            reg_a1 = (u8 *)D_0026F260;
            stage4_boss_explosions_from_table();
            reg_d0.w = 5;
            boss_part_hide();
            sfx_explosion_ground_medium();
            EXPLODING(reg_a4)->wait = 8U;
            EXPLODING(reg_a4)->step = 1U;
        }
    }
    if (EXPLODING(reg_a4)->step == 1) {
        EXPLODING(reg_a4)->wait -= 1;
        if ((s16) EXPLODING(reg_a4)->wait < 0) {
            EXPLODING(reg_a4)->burst_b.t.count = 0U;
            rng_next_unsigned();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d2.h[1] = ENTITY(reg_a6)[6].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[6].x.h;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            explosion_burst_small();
            reg_d2.h[1] = ENTITY(reg_a6)[6].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[6].x.h;
            reg_a1 = (u8 *)D_0026F280;
            stage4_boss_explosions_from_table();
            reg_d2.h[1] = ENTITY(reg_a6)[7].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[7].x.h;
            reg_a1 = (u8 *)D_0026F280;
            stage4_boss_explosions_from_table();
            reg_d0.w = 3;
            boss_part_hide();
            reg_d0.w = 4;
            boss_part_hide();
            sfx_explosion_air_small();
            EXPLODING(reg_a4)->wait = 8U;
            EXPLODING(reg_a4)->step = 2U;
        }
    }
    temp_a0_3 = EXPLODING(reg_a4)->step;
    if (temp_a0_3 == 2) {
        EXPLODING(reg_a4)->wait -= 1;
        if ((s16) EXPLODING(reg_a4)->wait < 0) {
            sfx_explosion_air_medium();
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
            reg_a1 = (u8 *)D_0026F290;
            stage4_boss_explosions_from_table();
            reg_d0.w = 2;
            boss_part_hide();
            EXPLODING(reg_a4)->wait = 0x60U;
            EXPLODING(reg_a4)->step = 3U;
        }
    }
    if (EXPLODING(reg_a4)->step == 3) {
        EXPLODING(reg_a4)->wait -= 1;
        if ((s16) EXPLODING(reg_a4)->wait < 0) {
            EXPLODING(reg_a4)->burst_a.t.count = 0xFFU;
            EXPLODING(reg_a4)->burst_b.t.count = 0xFFU;
            rng_next();
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0x30;
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            temp_a0_4 = ENTITY(reg_a6)[3].x.h;
            reg_d2.h[0] = temp_a0_4;
            reg_d2.w += 0xF0000400;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            explosion_burst_small();
            rng_next();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0xD0;
            reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
            temp_a0_5 = ENTITY(reg_a6)[3].x.h;
            reg_d2.h[0] = temp_a0_5;
            reg_d2.w += 0xEBFFFC00;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            explosion_burst_small();
            reg_d2.h[1] = ENTITY(reg_a6)[2].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[2].x.h;
            reg_a1 = (u8 *)D_0026F2D0;
            stage4_boss_explosions_from_table();
            reg_d0.w = 1;
            boss_part_hide();
            reg_d0.w = 3;
            boss_movement_start();
            sfx_explosion_ground_large();
            EXPLODING(reg_a4)->running = 0;
        }
    }
}

s32 func_0013B8B0();
extern u8 D_0026F340[];

void stage4_boss_mode_final_explosion_start(void) {
    reg_d0.w = 5;
    boss_movement_start();
    reg_a0 = D_0026F340;
    func_0013B8B0();
    EXPLODING(reg_a4)->step = 0;
    EXPLODING(reg_a4)->wait = 0x10;
    EXPLODING(reg_a4)->burst_a.h = 0xFF02;
    EXPLODING(reg_a4)->burst_b.h = 0xFF04;
    EXPLODING(reg_a4)->blast = 0;
    EXPLODING(reg_a4)->blast_timer.h = 0xC0C;
    EXPLODING(reg_a4)->blast_rounds = 3;
    EXPLODING(reg_a4)->cycle_timer.h = 4;
    EXPLODING(reg_a4)->cycle = 0;
    stage4_boss_mode_final_explosion(3, 0xC0C, 0xFF04, 0xFF02);
}

s32 boss_slots_end();

void stage4_boss_mode_final_explosion() {
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a1_2;

    temp_a1 = EXPLODING(reg_a4)->burst_a.t.count;
    if (((s64) ((s64) temp_a1 << 0x38) >> 0x38) != -1) {
        reg_tmp.b[0] = temp_a1;
        EXPLODING(reg_a4)->burst_a.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->burst_a.t.count = (u8) EXPLODING(reg_a4)->burst_a.t.reload;
            reg_d0.w = 1;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[1].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[1].x.h;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y -= 0x200;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y += 0x7FFF + 0x7801;
            EXPLOSION(reg_a0)->start_x += 0x400;
        }
    }
    temp_a1_2 = EXPLODING(reg_a4)->burst_b.t.count;
    if (((s64) ((s64) temp_a1_2 << 0x38) >> 0x38) != -1) {
        reg_tmp.b[0] = temp_a1_2;
        EXPLODING(reg_a4)->burst_b.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->burst_b.t.count = (u8) EXPLODING(reg_a4)->burst_b.t.reload;
            reg_d0.w = 0x10;
            explosion_spawn();
            EXPLOSION(reg_a0)->draw_layer = 0xC;
            EXPLOSION(reg_a0)->move.b.speed = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[1].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[1].x.h;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_y = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y -= 0x400;
            rng_next_word();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            EXPLOSION(reg_a0)->start_x = (u16) reg_d0.h[0];
            EXPLOSION(reg_a0)->start_y += 0x7FFF + 0x7801;
            EXPLOSION(reg_a0)->start_x += 0x7FFF + 0x7A01;
        }
    }
    temp_a0 = EXPLODING(reg_a4)->step;
    if (temp_a0 != 5) {
        stage4_boss_final_explosion_step();
        return;
    }
    EXPLODING(reg_a4)->wait -= 1;
    if (EXPLODING(reg_a4)->wait == 0) {
        boss_slots_end();
        EXPLODING(reg_a4)->running = 0;
    }
}


s32 boss_flash_start();
s32 boss_flash_running();
s32 func_0013B2E0();
s32 sfx_explosion_boss();
extern u8 D_0026F320[];
extern u16 D_0026F350[];
extern u16 D_0026F3A0[];

void stage4_boss_final_explosion_step(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 *temp_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_5;
    u16 temp_v1;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u32 var_a0;

    var_a1 = arg1;
    if (EXPLODING(reg_a4)->step == 4) {
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)(D_0026F350);
        stage4_boss_explosions_from_table();
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)(D_0026F350);
        stage4_boss_explosions_scattered();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x10;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a0 = ENTITY(reg_a6)[1].x.h;
        reg_d2.h[0] = temp_a0;
        reg_d2.w += 0xF8000400;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_small();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xF0;
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        temp_a0_2 = ENTITY(reg_a6)[1].x.h;
        reg_d2.h[0] = temp_a0_2;
        reg_d2.w += 0x01FFFA00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_small();
        sfx_explosion_boss();
        var_a1 = 5;
        EXPLODING(reg_a4)->step = 5U;
        EXPLODING(reg_a4)->wait = 0x80U;
    }
    temp_a0_3 = EXPLODING(reg_a4)->step;
    if (temp_a0_3 == 3) {
        boss_flash_running();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)D_0026F320;
            func_0013B2E0();
            EXPLODING(reg_a4)->step = 4U;
        }
    }
    temp_a0_4 = EXPLODING(reg_a4)->step;
    if (temp_a0_4 == 2) {
        stage4_boss_final_explosion_cycle();
        reg_tmp.b[0] = EXPLODING(reg_a4)->blast_timer.t.count;
        EXPLODING(reg_a4)->blast_timer.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->blast_timer.t.count = (u8) EXPLODING(reg_a4)->blast_timer.t.reload;
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += EXPLODING(reg_a4)->blast;
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            explosion_spawn();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
            EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
            temp_a1 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a1);
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[1].y.h;
            temp_a0_5 = ENTITY(reg_a6)[1].x.h;
            EXPLOSION(reg_a0)->x = temp_a0_5;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            rng_next();
            reg_d0.b[0] += 0x10;
            EXPLOSION(reg_a0)->move.b.speed = (u8) reg_d0.b[0];
            rng_next_unsigned();
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLODING(reg_a4)->blast += 0xC;
            if (EXPLODING(reg_a4)->blast == 0x48) {
                EXPLODING(reg_a4)->blast = 0U;
                EXPLODING(reg_a4)->blast_rounds -= 1;
                if (EXPLODING(reg_a4)->blast_rounds == 0) {
                    EXPLODING(reg_a4)->step = 3U;
                    reg_d0.w = 9;
                    boss_part_hide();
                    reg_d0.h[0] = 0x12;
                    boss_flash_start();
                    EXPLODING(reg_a4)->burst_a.t.count = 0xFF;
                    EXPLODING(reg_a4)->burst_b.t.count = 0xFF;
                }
            }
        }
    }
    var_a0 = EXPLODING(reg_a4)->step;
    if ((var_a0 == 1) && ((temp_v1 = EXPLODING(reg_a4)->wait, var_a0 = (u32) (reg_a4 + 4), (temp_v1 == 0)) || (*(u16 *)var_a0 = (s16) (temp_v1 - 1), (EXPLODING(reg_a4)->wait == 0)))) {
        stage4_boss_final_explosion_cycle();
        var_a0 = (u32) (reg_a4);
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xD)));
        (*(u8 *)((u8 *)(var_a0) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            EXPLODING(reg_a4)->blast_timer.t.count = (u8) EXPLODING(reg_a4)->blast_timer.t.reload;
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += EXPLODING(reg_a4)->blast;
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            explosion_spawn();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->attr.b.flip = (u8) reg_d0.b[0];
            EXPLOSION(reg_a0)->delay = (u16) reg_d1.h[0];
            EXPLOSION(reg_a0)->start_y = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->start_x = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a0)->y = (u16) ENTITY(reg_a6)[1].y.h;
            EXPLOSION(reg_a0)->x = (u16) ENTITY(reg_a6)[1].x.h;
            EXPLOSION(reg_a0)->draw_layer = 0x10;
            EXPLOSION(reg_a0)->debris = 0;
            EXPLOSION(reg_a0)->debris_arg = 0;
            EXPLOSION(reg_a0)->move.b.speed = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] += reg_d0.b[0];
            reg_d0.b[0] += reg_d0.b[0];
            EXPLOSION(reg_a0)->move.b.dir = (u8) reg_d0.b[0];
            EXPLODING(reg_a4)->blast += 0xC;
            var_a0 = EXPLODING(reg_a4)->blast;
            if (var_a0 == 0x48) {
                EXPLODING(reg_a4)->blast = 0U;
                var_a0 = 8;
                EXPLODING(reg_a4)->blast_timer.h = 0x606;
                EXPLODING(reg_a4)->step = 2U;
                EXPLODING(reg_a4)->cycle_timer.sh = 8;
                EXPLODING(reg_a4)->cycle = 0;
            }
        }
    }
    if (EXPLODING(reg_a4)->step == 0) {
        stage4_boss_final_explosion_cycle();
        EXPLODING(reg_a4)->wait -= 1;
        if ((s16) EXPLODING(reg_a4)->wait < 0) {
            reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
            reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
            reg_a1 = (u8 *)(D_0026F350);
            stage4_boss_explosions_from_table();
            EXPLODING(reg_a4)->burst_a.t.count = 0;
            EXPLODING(reg_a4)->burst_b.t.count = 0;
            EXPLODING(reg_a4)->wait = 0x50U;
            EXPLODING(reg_a4)->step = 1U;
            EXPLODING(reg_a4)->cycle_timer.sh = 0x10;
            EXPLODING(reg_a4)->cycle = 0;
        }
    }
}

typedef void (*Fn)();

extern u8 D_0026F240[];

void stage4_boss_final_explosion_cycle(void) {
    reg_tmp.b[0] = EXPLODING(reg_a4)->cycle_timer.t.count;
    EXPLODING(reg_a4)->cycle_timer.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        EXPLODING(reg_a4)->cycle_timer.t.count = (u8) EXPLODING(reg_a4)->cycle_timer.t.reload;
        reg_tmp.h[0] = EXPLODING(reg_a4)->cycle;
        ((Fn)*(u32 *)((u8 *)D_0026F240 + (reg_tmp.h[0] & ~3)))();
        EXPLODING(reg_a4)->cycle += 4;
        EXPLODING(reg_a4)->cycle &= 0x1F;
    }
}
