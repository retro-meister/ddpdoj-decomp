#include "black_label.h"
#include "common.h"
#include "entity.h"
#include "stage3_boss.h"

void stage3_boss_legs_walk_start(void);
void stage3_boss_legs_walk(void);
void stage3_boss_side_turrets_track_start(void);
void stage3_boss_side_turrets_track(void);
void stage3_boss_lid_open_start(void);
void stage3_boss_lid_open(void);
void stage3_boss_lid_close_start(void);
void stage3_boss_lid_close(void);
void stage3_boss_six_gun_open_start(void);
void stage3_boss_six_gun_open(void);
void stage3_boss_six_gun_close_start(void);
void stage3_boss_six_gun_close(void);
void stage3_boss_lid_idle_start(void);
void stage3_boss_lid_idle(void);
void stage3_boss_entrance_anim_start(void);
void stage3_boss_entrance_anim(void);

/*
 * The animation part of the boss slot (reg_a4). `running` is cleared when the animation is over. Every animation
 * here is one step every few frames.
 */
typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
} FrameStep;

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
    /* 0x04 */ SlotTimer pace;
    /* 0x06 */ u16 delay;
} EntranceAnim;

#define STEP(pointer) ((FrameStep *)(pointer))
#define ENTRANCE(pointer) ((EntranceAnim *)(pointer))

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage3_boss_anim_routines[])(void) = {
    stage3_boss_legs_walk_start,
    stage3_boss_legs_walk,
    stage3_boss_side_turrets_track_start,
    stage3_boss_side_turrets_track,
    stage3_boss_lid_open_start,
    stage3_boss_lid_open,
    stage3_boss_lid_close_start,
    stage3_boss_lid_close,
    stage3_boss_six_gun_open_start,
    stage3_boss_six_gun_open,
    stage3_boss_six_gun_close_start,
    stage3_boss_six_gun_close,
    stage3_boss_lid_idle_start,
    stage3_boss_lid_idle,
    stage3_boss_entrance_anim_start,
    stage3_boss_entrance_anim,
};

u16 stage3_boss_lid_frames[] = {
    0x0000, 0x0000, 0x0040, 0x0000, 0x0038, 0xFFE0, 0x0030, 0xFFC0,
    0x0028, 0xFFA0, 0x0020, 0xFF80, 0x0018, 0xFF60, 0x0010, 0xFF40,
    0x0008, 0xFF20, 0x0000, 0xFF00, 0xFFE0, 0xFEC0, 0xFFC0, 0xFE80,
    0xFFA0, 0xFE40, 0xFF80, 0xFE00, 0xFF60, 0xFDC0, 0xFF40, 0xFD80,
    0xFF20, 0xFD40, 0xFF00, 0xFD00, 0xFEE0, 0xFCC0, 0xFEC0, 0xFC80,
    0xFEA0, 0xFC40, 0xFE80, 0xFC00, 0xFE60, 0xFBC0, 0xFE40, 0xFB80,
    0xFE20, 0xFB40, 0xFE00, 0xFB00, 0xFDE0, 0xFAC0, 0xFDC0, 0xFA80,
    0xFDA0, 0xFA40, 0xFD80, 0xFA00, 0xFD60, 0xF9C0, 0xFD40, 0xF980,
    0xFD20, 0xF940, 0xFD00, 0xF900, 0xFCE0, 0xF8C0, 0xFCC0, 0xF880,
    0xFCE0, 0xF8C0, 0xFD00, 0xF900,
};

u16 stage3_boss_enter_flash[] = {
    0x0003, 0x7FFF, 0x0000, 0x0400, 0x0004, 0x0005, 0x001F, 0x0003,
    0x7FFF, 0x0000, 0x0440, 0x000B, 0x000C, 0x001F, 0x0003, 0x7FFF,
    0x0000, 0x0480, 0x0012, 0x0013, 0x001F, 0x0003,
};

void stage3_boss_legs_walk(void);
void stage3_boss_side_turrets_track(void);
void stage3_boss_lid_open();
void stage3_boss_lid_close();
void stage3_boss_six_gun_open(void);
void stage3_boss_six_gun_close(void);
void stage3_boss_lid_idle(void);
void stage3_boss_entrance_anim();



void stage3_boss_legs_walk_start(void) {
    STEP(reg_a4)->frame.h = 1;
    STAGE3_EXTRA(reg_a6)->legs_anim = 0;
    stage3_boss_legs_walk();
}

void stage3_boss_legs_walk(void) {
    if (STAGE3_DAMAGE(reg_a6)->second_form == 0) {
        reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
        STEP(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
            goto block_3;
        }
    } else {
block_3:
        STAGE3_EXTRA(reg_a6)->legs_anim += 4;
        if (STAGE3_EXTRA(reg_a6)->legs_anim == 0x40) {
            STAGE3_EXTRA(reg_a6)->legs_anim = 0U;
        }
    }
}


void stage3_boss_side_turrets_track_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage3_boss_side_turrets_track();
}

s32 direction_between();
s32 direction_turn_toward();
extern s16 g_player2[];
extern s16 g_player1[];

void stage3_boss_side_turrets_track(void) {
    s16 *temp_a0;
    u32 temp_s0;
    u32 temp_s1;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
            if (*(s16 *)reg_a1 < 0) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            temp_s1 = reg_d3.w;
            temp_s0 = reg_d2.w;
            if (STAGE3_EXTRA(reg_a6)->left_turret_track_stop == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x80;
                direction_between();
                reg_d0.h[0] = STAGE3_EXTRA(reg_a6)->left_turret_direction;
                direction_turn_toward();
                STAGE3_EXTRA(reg_a6)->left_turret_direction = (u16) reg_d1.h[0];
            }
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            if (STAGE3_EXTRA(reg_a6)->right_turret_track_stop == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x7FFF + 0x7F81;
                direction_between();
                reg_d0.h[0] = STAGE3_EXTRA(reg_a6)->right_turret_direction;
                direction_turn_toward();
                STAGE3_EXTRA(reg_a6)->right_turret_direction = (u16) reg_d1.h[0];
            }
        }
    }
}


void stage3_boss_lid_open_start(void) {
    u16 flag = 0x8001;
    STEP(reg_a4)->frame.h = flag;
    reg_d0.w = 4;
    ENTITY(reg_a6)[1].draw.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].draw.h = (u16) reg_d0.h[0];
    ARCADE_REGISTER_CALL(stage3_boss_lid_open, flag);
}

s32 boss_animation_start();
s32 boss_attack_start();

void stage3_boss_lid_open() {
    u16 temp_a0;
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_a0 = (u8 *)(stage3_boss_lid_frames);
        reg_d0.h[0] = ENTITY(reg_a6)[1].draw.h;
        ENTITY(reg_a6)[1].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ENTITY(reg_a6)[2].draw.h;
        ENTITY(reg_a6)[2].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = (u16) -(s16) ENTITY(reg_a6)[2].offset_x.h;
        ENTITY(reg_a6)[1].draw.h += 4;
        temp_a0 = ENTITY(reg_a6)[1].draw.h;
        if (temp_a0 == 0x94) {
            STEP(reg_a4)->running = 0;
            reg_d0.w = 0;
            boss_attack_start();
            reg_d0.w = 3;
            boss_animation_start();
        }
        ENTITY(reg_a6)[2].draw.h = (u16) ENTITY(reg_a6)[1].draw.h;
    }
}


void stage3_boss_lid_close_start(void) {
    STEP(reg_a4)->frame.h = 0x6001;
    reg_d0.h[0] = 0x84;
    ENTITY(reg_a6)[1].draw.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].draw.h = reg_d0.h[0];
    ARCADE_REGISTER_CALL(stage3_boss_lid_close, 0x6001);
}

s32 boss_part_show();

void stage3_boss_lid_close() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        reg_a0 = (u8 *)(stage3_boss_lid_frames);
        reg_d0.h[0] = ENTITY(reg_a6)[1].draw.h;
        ENTITY(reg_a6)[1].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ENTITY(reg_a6)[2].draw.h;
        ENTITY(reg_a6)[2].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = (u16) -(s16) ENTITY(reg_a6)[2].offset_x.h;
        ENTITY(reg_a6)[1].draw.h -= 4;
        if ((s16) ENTITY(reg_a6)[1].draw.h < 0) {
            STEP(reg_a4)->running = 0;
            reg_d0.w = 2;
            boss_animation_start();
            reg_d0.w = 2;
            boss_part_show();
            reg_d0.w = 3;
            boss_part_show();
        }
        ENTITY(reg_a6)[2].draw.h = (u16) ENTITY(reg_a6)[1].draw.h;
    }
}


void stage3_boss_six_gun_open_start(void) {
    stage3_boss_six_gun_open();
}

void stage3_boss_six_gun_open(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE3_EXTRA(reg_a6)->six_gun_anim += 4;
        if (STAGE3_EXTRA(reg_a6)->six_gun_anim == 0x18) {
            STEP(reg_a4)->running = 0;
        }
    }
}


void stage3_boss_six_gun_close_start(void) {
    STEP(reg_a4)->frame.h = 1;
    stage3_boss_six_gun_close();
}

void stage3_boss_six_gun_close(void) {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        STAGE3_EXTRA(reg_a6)->six_gun_anim -= 4;
        if (STAGE3_EXTRA(reg_a6)->six_gun_anim == 0) {
            STEP(reg_a4)->running = 0;
        }
    }
}



void stage3_boss_lid_idle_start(void) {
    STEP(reg_a4)->frame.sh = 0;
    *(s16 *)((u8 *)((void *)reg_a6) + 0xBE) = 0;
    stage3_boss_lid_idle();
}

void stage3_boss_lid_idle(void) {
    if (STAGE3_DAMAGE(reg_a6)->second_form == 0) {
        reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
        STEP(reg_a4)->frame.t.count -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
            goto block_3;
        }
    } else {
block_3:
        STAGE3_EXTRA(reg_a6)->lid_anim += 4;
        if (STAGE3_EXTRA(reg_a6)->lid_anim == 0x20) {
            STAGE3_EXTRA(reg_a6)->lid_anim = 0U;
        }
    }
}


typedef struct PartRegBC {
    u8 pad0[0xBC];
    s16 unkBC;
} PartRegBC;



void stage3_boss_entrance_anim_start(void) {
    ENTRANCE(reg_a4)->frame.sh = 1;
    ENTRANCE(reg_a4)->pace.sh = 0x202;
    ENTRANCE(reg_a4)->delay = 0xC0;
    ((PartRegBC *)reg_a6)->unkBC = 0;
    ARCADE_REGISTER_CALL(stage3_boss_entrance_anim, 0x202, 1);
}

s32 boss_part_hide();
s32 fade_in_and_release();
s32 stage3_boss_shield_off();
s32 stage3_boss_parts_flags_set();
extern u8 g_boss_present_b1;
extern u16 g_boss_hyper_wait;

void stage3_boss_entrance_anim() {
    u16 t1;

    if (ENTRANCE(reg_a4)->delay == 0) goto next_40;
    ENTRANCE(reg_a4)->delay -= 1;
    if (ENTRANCE(reg_a4)->delay == 0) {
        STAGE3_EXTRA(reg_a6)->start_anim = 0xC0;
        goto next_40;
    }
    reg_tmp.b[0] = ENTRANCE(reg_a4)->pace.t.count;
    ENTRANCE(reg_a4)->pace.t.count -= 1;
    if ((s32) reg_tmp.b[0] > 0) return;
    ENTRANCE(reg_a4)->pace.t.count = (u8) ENTRANCE(reg_a4)->pace.t.reload;
    STAGE3_EXTRA(reg_a6)->start_anim += 0xC;
    if (STAGE3_EXTRA(reg_a6)->start_anim != 0xC0) return;
    STAGE3_EXTRA(reg_a6)->start_anim = 0U;
    ENTRANCE(reg_a4)->delay -= 1;
    if (ENTRANCE(reg_a4)->delay != 0) return;
    STAGE3_EXTRA(reg_a6)->start_anim = 0x60;
next_40:
    reg_tmp.b[0] = ENTRANCE(reg_a4)->frame.t.count;
    ENTRANCE(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        ENTRANCE(reg_a4)->frame.t.count = (u8) ENTRANCE(reg_a4)->frame.t.reload;
        STAGE3_EXTRA(reg_a6)->start_anim += 0xC;
        t1 = STAGE3_EXTRA(reg_a6)->start_anim;
        if (t1 == 0x1E0) {
            ENTRANCE(reg_a4)->running = 0;
            g_boss_present_b1 |= 2;
            g_boss_present_b1 |= 0x10;
            if (GAME_RULE(0, 1)) g_boss_hyper_wait = 1;
            stage3_boss_shield_off();
            stage3_boss_parts_flags_set();
            reg_d0.w = 9;
            boss_part_hide();
            reg_d0.w = 0;
            boss_part_show();
            reg_d0.w = 1;
            boss_part_show();
            reg_d0.w = 2;
            boss_part_show();
            reg_d0.w = 3;
            boss_part_show();
            reg_d0.w = 4;
            boss_part_show();
            reg_d0.w = 5;
            boss_part_show();
            reg_d0.w = 6;
            boss_part_show();
            reg_d0.w = 7;
            boss_part_show();
            reg_d0.w = 8;
            boss_part_show();
            reg_d0.w = 0;
            boss_animation_start();
            reg_d0.w = 1;
            boss_animation_start();
            reg_d0.w = 6;
            boss_animation_start();
            reg_a0 = (u8 *)stage3_boss_enter_flash;
            fade_in_and_release();
        }
    }
    }
