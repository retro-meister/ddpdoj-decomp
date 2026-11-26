#include "common.h"
#include "entity.h"
#include "stage5_boss.h"

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
} FrameStep;

#define STEP(pointer) ((FrameStep *)(pointer))


void stage5_boss_head_anim_start(void);
void stage5_boss_head_anim(void);
void stage5_boss_belly_anim_start(void);
void stage5_boss_belly_anim(void);
void stage5_boss_arm_guns_track_start(void);
void stage5_boss_arm_guns_track(void);
void stage5_boss_form2_exhaust_anim_start(void);
void stage5_boss_form2_exhaust_anim(void);
void stage5_boss_form2_wings_anim_start(void);
void stage5_boss_form2_wings_anim(void);
void stage5_boss_form3_tail_track_start(void);
void stage5_boss_form3_tail_track(void);
void stage5_boss_form3_body_anim_start(void);
void stage5_boss_form3_body_anim(void);
void stage5_boss_form3_bomb_barrier_anim_start(void);
void stage5_boss_form3_bomb_barrier_anim(void);

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage5_boss_anim_routines[])(void) = {
    stage5_boss_head_anim_start,
    stage5_boss_head_anim,
    stage5_boss_belly_anim_start,
    stage5_boss_belly_anim,
    stage5_boss_arm_guns_track_start,
    stage5_boss_arm_guns_track,
    stage5_boss_form2_exhaust_anim_start,
    stage5_boss_form2_exhaust_anim,
    stage5_boss_form2_wings_anim_start,
    stage5_boss_form2_wings_anim,
    stage5_boss_form3_tail_track_start,
    stage5_boss_form3_tail_track,
    stage5_boss_form3_body_anim_start,
    stage5_boss_form3_body_anim,
    stage5_boss_form3_bomb_barrier_anim_start,
    stage5_boss_form3_bomb_barrier_anim,
};

void stage5_boss_head_anim(void);
void stage5_boss_belly_anim(void);
void stage5_boss_arm_guns_track(void);
void stage5_boss_form2_exhaust_anim(void);
void stage5_boss_form2_wings_anim(void);
void stage5_boss_form3_tail_track(void);
void stage5_boss_form3_body_anim(void);
void stage5_boss_form3_bomb_barrier_anim(void);
void stage5_boss_direction_turn_limited(void);



void stage5_boss_head_anim_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    STAGE5_EXTRA(reg_a6)->head_anim = 0;
    stage5_boss_head_anim();
}

void stage5_boss_head_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->head_anim += 4;
        if (STAGE5_EXTRA(reg_a6)->head_anim == 0x18) {
            STAGE5_EXTRA(reg_a6)->head_anim = 0U;
        }
    }
}


void stage5_boss_belly_anim_start(void) {
    STEP(reg_a4)->frame.sh = 2;
    STAGE5_EXTRA(reg_a6)->belly_anim = 0;
    stage5_boss_belly_anim();
}

void stage5_boss_belly_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->belly_anim += 4;
        if (STAGE5_EXTRA(reg_a6)->belly_anim == 0x18) {
            STAGE5_EXTRA(reg_a6)->belly_anim = 0U;
        }
    }
}


void stage5_boss_arm_guns_track_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage5_boss_arm_guns_track();
}

s32 enemy_switch_target_player();
s32 direction_between();
s32 direction_turn_toward();
extern s16 g_player2[];
extern s16 g_player1[];

void stage5_boss_arm_guns_track(void) {
    s16 *temp_a0;
    u16 temp_a1;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            temp_a1 = *(u16 *)(reg_a0 + 4);
            reg_d3.w = (u32) temp_a1;
            STAGE5_EXTRA(reg_a6)->arm_guns_target_y = (u16) reg_d2.h[0];
            STAGE5_EXTRA(reg_a6)->arm_guns_target_x = (u16) reg_d3.h[0];
            if ((ENTITY(reg_a6)[1].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[1].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[1].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[1].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[1].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[1].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_y;
            reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_x;
            if ((ENTITY(reg_a6)[2].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[2].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[2].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[2].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[2].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[2].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_y;
            reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_x;
            if ((ENTITY(reg_a6)[3].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[3].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[3].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[3].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[3].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[3].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_y;
            reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_x;
            if ((ENTITY(reg_a6)[4].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[4].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[4].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[4].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[4].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[4].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_y;
            reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_x;
            if ((ENTITY(reg_a6)[5].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[5].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[5].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[5].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[5].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[5].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_y;
            reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->arm_guns_target_x;
            if ((ENTITY(reg_a6)[6].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[6].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[6].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[6].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[6].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[6].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
        }
    }
}


void stage5_boss_form2_exhaust_anim_start(void) {
    STEP(reg_a4)->frame.h = 0;
    STAGE5_EXTRA(reg_a6)->exhaust_anim = 0;
    stage5_boss_form2_exhaust_anim();
}

void stage5_boss_form2_exhaust_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->exhaust_anim += 4;
        if (STAGE5_EXTRA(reg_a6)->exhaust_anim == 0xC) {
            STAGE5_EXTRA(reg_a6)->exhaust_anim = 0U;
        }
    }
}


void stage5_boss_form2_wings_anim_start(void) {
    STEP(reg_a4)->frame.h = 1;
    STAGE5_EXTRA(reg_a6)->wings_anim = 0;
    stage5_boss_form2_wings_anim();
}

void stage5_boss_form2_wings_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->wings_anim += 6;
        if (STAGE5_EXTRA(reg_a6)->wings_anim == 0x90) {
            STAGE5_EXTRA(reg_a6)->wings_anim = 0x5AU;
        }
    }
}


void stage5_boss_form3_tail_track_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage5_boss_form3_tail_track();
}



void stage5_boss_form3_tail_track(void) {
    s16 *temp_a0;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (ENEMY_STATE(reg_a5)->target_player != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            if (STAGE5_EXTRA(reg_a6)->tail_track_stop == 0) {
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x77C1;
                direction_between();
                reg_d3.h[0] = STAGE5_EXTRA(reg_a6)->tail_direction;
                stage5_boss_direction_turn_limited();
                if (cond_flag == 0) {
                    STAGE5_EXTRA(reg_a6)->tail_direction = (u16) reg_d1.h[0];
                }
            }
        }
    }
}

typedef struct PartReg {
    s16 unk0;
    s16 unk2;
} PartReg;


void stage5_boss_form3_body_anim_start(void) {
    ((PartReg *)reg_a4)->unk2 = 1;
    STAGE5_EXTRA(reg_a6)->form3_body_anim = 0;
    stage5_boss_form3_body_anim();
}

void stage5_boss_form3_body_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->form3_body_anim += 4;
        if (STAGE5_EXTRA(reg_a6)->form3_body_anim == 0x20) {
            STAGE5_EXTRA(reg_a6)->form3_body_anim = 0U;
        }
    }
}


void stage5_boss_form3_bomb_barrier_anim_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    STAGE5_EXTRA(reg_a6)->barrier_anim = 0;
    stage5_boss_form3_bomb_barrier_anim();
}

void stage5_boss_form3_bomb_barrier_anim(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE5_EXTRA(reg_a6)->barrier_anim += 4;
        if (STAGE5_EXTRA(reg_a6)->barrier_anim == 0x40) {
            STAGE5_EXTRA(reg_a6)->barrier_anim = 0U;
        }
    }
}

void stage5_boss_direction_turn_limited(void) {
    if (reg_d3.b[0] != reg_d1.b[0]) {
        reg_d6.w = 0x3F;
        if (((s32) reg_d1.b[0] < 0x18) || ((s32) reg_d1.b[0] > 0x28)) {
            reg_d4.b[0] = reg_d1.b[0];
            reg_d5.b[0] = reg_d3.b[0];
            reg_d4.b[0] -= 0x20;
            reg_d5.b[0] -= reg_d1.b[0];
            reg_d4.h[0] &= reg_d6.h[0];
            reg_d5.h[0] &= reg_d6.h[0];
            if ((s32) reg_d4.b[0] >= 0x20) {
                if ((s32) reg_d5.b[0] <= 0x20) {
                    goto block_7;
                }
                goto block_9;
            }
            if ((s32) reg_d5.b[0] <= 0x20) {
                goto block_9;
            }
        }
block_7:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_11;
        }
        goto block_13;
block_9:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_13;
        }
block_11:
        if (reg_d3.b[0] != 0x28) {
            reg_d3.b[0] += 1;
            goto block_15;
        }
        goto block_16;
block_13:
        if (reg_d3.b[0] != 0x18) {
            reg_d3.b[0] -= 1;
block_15:
            cond_flag = 0;
            reg_d3.h[0] &= reg_d6.h[0];
            reg_d1.b[0] = reg_d3.b[0];
            return;
        }
    }
block_16:
    cond_flag = 1;
}
