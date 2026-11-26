#include "common.h"
#include "enemy.h"
#include "entity.h"

typedef struct {
    /* 0x00 */ u8 turning;
    /* 0x01 */ u8 target_dir;
} MoveWander;

#define WANDER(pointer) ((MoveWander *)(pointer))

void twin_boss_wander_a(u8 boss);
void twin_boss_wander_b(u8 boss);
void twin_boss_wander_c(u8 boss);
void twin_boss_wander_d(u8 boss);
void twin_boss_wander_e(u8 boss);


void twin_boss_wander_a_start(u8 boss) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 6;
    twin_boss_wander_a(boss);
}

typedef struct {
    s32 low;
    s32 high;
} Range;

s32 rng_next();
s32 entity_velocity();
s32 func_002024C0();
const Range twin_boss_wander_a_ranges[2] = { { 13312, 16384 }, { 18432, 21504 } };
const Range twin_boss_wander_b_ranges[2] = { { 12288, 15360 }, { 19456, 22528 } };
const Range twin_boss_wander_c_ranges[2] = { { 11264, 16384 }, { 18432, 23552 } };
const Range twin_boss_wander_d_ranges[2] = { { 12288, 15872 }, { 18944, 22528 } };
const Range twin_boss_wander_e_ranges[2] = { { 12288, 14848 }, { 19968, 22528 } };

void twin_boss_wander_a(u8 boss) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < twin_boss_wander_a_ranges[boss].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (twin_boss_wander_a_ranges[boss].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5e00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
        WANDER(reg_a4)->turning = 1U;
    }
}


void twin_boss_wander_b_start(u8 boss) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 2;
    twin_boss_wander_b(boss);
}


void twin_boss_wander_b(u8 boss) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < twin_boss_wander_b_ranges[boss].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (twin_boss_wander_b_ranges[boss].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5200) {
        if ((s32) reg_d1.h[0] >= 0x5600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
        WANDER(reg_a4)->turning = 1U;
    }
}


void twin_boss_wander_c_start(u8 boss) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    twin_boss_wander_c(boss);
}


void twin_boss_wander_c(u8 boss) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < twin_boss_wander_c_ranges[boss].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (twin_boss_wander_c_ranges[boss].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6200) {
        if ((s32) reg_d1.h[0] >= 0x6600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
        WANDER(reg_a4)->turning = 1U;
    }
}


void twin_boss_wander_d_start(u8 boss) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 4;
    twin_boss_wander_d(boss);
}


void twin_boss_wander_d(u8 boss) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < twin_boss_wander_d_ranges[boss].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (twin_boss_wander_d_ranges[boss].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5e00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
        WANDER(reg_a4)->turning = 1U;
    }
}

s32 rng_next_masked();

void twin_boss_wander_e_start(u8 boss) {
    reg_d0.w = 0;
    WANDER(reg_a4)->target_dir = reg_d0.b[0];
    WANDER(reg_a4)->turning = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 4;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = reg_d0.b[0];
    twin_boss_wander_e(boss);
}


void twin_boss_wander_e(u8 boss) {
    entity_velocity();
    if (WANDER(reg_a4)->turning != 0) {
        reg_d1.b[0] = WANDER(reg_a4)->target_dir;
        func_002024C0();
        if (WANDER(reg_a4)->target_dir == reg_d1.b[0]) {
            WANDER(reg_a4)->turning = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < twin_boss_wander_e_ranges[boss].low) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if (twin_boss_wander_e_ranges[boss].high <= (s32) reg_d1.h[0]) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x4800) {
        if ((s32) reg_d1.h[0] >= 0x5000) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        WANDER(reg_a4)->target_dir = (u8) reg_d0.b[0];
        WANDER(reg_a4)->turning = 1U;
    }
}


void twin_boss_first_wander_a_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_a_start(0);
    reg_a6 = save_a6;
}

void twin_boss_first_wander_a(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_a(0);
    reg_a6 = save_a6;
}

extern u16 g_side_scroll_step[];
extern u8 g_twin_boss_second[];

void twin_boss_second_wander_a_start(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_a_start(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void twin_boss_second_wander_a(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_a(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void twin_boss_first_wander_b_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_b_start(0);
    reg_a6 = save_a6;
}

void twin_boss_first_wander_b(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_b(0);
    reg_a6 = save_a6;
}

void twin_boss_second_wander_b_start(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_b_start(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void twin_boss_second_wander_b(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_b(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void twin_boss_first_wander_c_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_c_start(0);
    reg_a6 = save_a6;
}

void twin_boss_first_wander_c(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_c(0);
    reg_a6 = save_a6;
}

void twin_boss_second_wander_c_start(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_c_start(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void twin_boss_second_wander_c(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_c(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void twin_boss_first_wander_d_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_d_start(0);
    reg_a6 = save_a6;
}

void twin_boss_first_wander_d(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_d(0);
    reg_a6 = save_a6;
}

void twin_boss_second_wander_d_start(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_d_start(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void twin_boss_second_wander_d(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_d(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}


void twin_boss_first_wander_e_start(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_e_start(0);
    reg_a6 = save_a6;
}

void twin_boss_first_wander_e(void) {
    u8 *save_a6;

    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_enemy_entities_second;
    twin_boss_wander_e(0);
    reg_a6 = save_a6;
}

void twin_boss_second_wander_e_start(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_e_start(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

void twin_boss_second_wander_e(void) {
    u8 *save_a6;
    u8 *save_a4;

    save_a6 = reg_a6;
    save_a4 = reg_a4;
    reg_a6 = g_twin_boss_second;
    reg_a4 += 0x10;
    ENTITY(reg_a6)->x.h -= g_side_scroll_step[0];
    twin_boss_wander_e(1);
    reg_a6 = save_a6;
    reg_a4 = save_a4;
}

s32 stage5_boss_parts_follow();

void twin_boss_move_wander_a_start(void) {
    twin_boss_first_wander_a_start();
    twin_boss_second_wander_a_start();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_a(void) {
    twin_boss_first_wander_a();
    twin_boss_second_wander_a();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_b_start(void) {
    twin_boss_first_wander_b_start();
    twin_boss_second_wander_b_start();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_b(void) {
    twin_boss_first_wander_b();
    twin_boss_second_wander_b();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_c_start(void) {
    twin_boss_first_wander_c_start();
    twin_boss_second_wander_c_start();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_c(void) {
    twin_boss_first_wander_c();
    twin_boss_second_wander_c();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_d_start(void) {
    twin_boss_first_wander_d_start();
    twin_boss_second_wander_d_start();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_d(void) {
    twin_boss_first_wander_d();
    twin_boss_second_wander_d();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_e_start(void) {
    twin_boss_first_wander_e_start();
    twin_boss_second_wander_e_start();
    stage5_boss_parts_follow();
}


void twin_boss_move_wander_e(void) {
    twin_boss_first_wander_e();
    twin_boss_second_wander_e();
    stage5_boss_parts_follow();
}
