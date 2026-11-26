#include "common.h"
#include "entity.h"
#include "stage4_boss.h"

typedef struct {
    /* 0x00 */ s16 running;
    /* 0x02 */ SlotTimer frame;
} FrameStep;

#define STEP(pointer) ((FrameStep *)(pointer))


void stage4_boss_form2_spin_start(void);
void stage4_boss_form2_spin(void);
void stage4_boss_center_hatch_open_start(void);
void stage4_boss_center_hatch_open(void);
void stage4_boss_center_hatch_close_start(void);
void stage4_boss_center_hatch_close(void);
void stage4_boss_cutter_bay_open_start(void);
void stage4_boss_cutter_bay_open(void);
void stage4_boss_cutter_bay_close_start(void);
void stage4_boss_cutter_bay_close(void);
void stage4_boss_right_pod_open_start(void);
void stage4_boss_right_pod_open(void);
void stage4_boss_right_pod_close_start(void);
void stage4_boss_right_pod_close(void);
void stage4_boss_left_pod_open_start(void);
void stage4_boss_left_pod_open(void);
void stage4_boss_left_pod_close_start(void);
void stage4_boss_left_pod_close(void);
void stage4_boss_aimed_gun_track_start(void);
void stage4_boss_aimed_gun_track(void);
void stage4_boss_body_anim_start(void);
void stage4_boss_body_anim(void);

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage4_boss_anim_routines[])(void) = {
    stage4_boss_form2_spin_start,
    stage4_boss_form2_spin,
    stage4_boss_center_hatch_open_start,
    stage4_boss_center_hatch_open,
    stage4_boss_center_hatch_close_start,
    stage4_boss_center_hatch_close,
    stage4_boss_cutter_bay_open_start,
    stage4_boss_cutter_bay_open,
    stage4_boss_cutter_bay_close_start,
    stage4_boss_cutter_bay_close,
    stage4_boss_right_pod_open_start,
    stage4_boss_right_pod_open,
    stage4_boss_right_pod_close_start,
    stage4_boss_right_pod_close,
    stage4_boss_left_pod_open_start,
    stage4_boss_left_pod_open,
    stage4_boss_left_pod_close_start,
    stage4_boss_left_pod_close,
    stage4_boss_aimed_gun_track_start,
    stage4_boss_aimed_gun_track,
    stage4_boss_body_anim_start,
    stage4_boss_body_anim,
    0,
    0,
};

void stage4_boss_center_hatch_open(void);
void stage4_boss_center_hatch_close(void);
void stage4_boss_cutter_bay_open(void);
void stage4_boss_cutter_bay_close(void);
void stage4_boss_right_pod_open(void);
void stage4_boss_right_pod_close(void);
void stage4_boss_left_pod_open(void);
void stage4_boss_left_pod_close(void);
void stage4_boss_aimed_gun_track(void);
void stage4_boss_body_anim(void);


void stage4_boss_anim_end(void) {
    *(*(s16 **)&reg_a4) = 0;
}

s32 boss_part_show();                            /* extern */
s32 boss_part_hide();                            /* extern */

void stage4_boss_form2_spin_start(void) {
    ENTITY(reg_a6)[8].offset_y.sh = 0;
    reg_d0.w = 0;
    boss_part_hide();
    reg_d0.w = 6;
    boss_part_show();
    STEP(reg_a4)->frame.sh = 0x202;
}

s32 boss_part_show();
s32 boss_part_hide();
s32 stage4_boss_shield_off();
s32 stage4_boss_part_take_hits();

void stage4_boss_form2_spin() {
    u16 temp_a0;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[8].offset_y.h += 4;
        temp_a0 = ENTITY(reg_a6)[8].offset_y.h;
        if (temp_a0 == 0x3C) {
            ENTITY(reg_a6)[8].offset_y.h = 0U;
            reg_d0.w = 6;
            boss_part_hide();
            reg_d0.w = 9;
            boss_part_show();
            reg_d0.w = 7;
            boss_part_show();
            reg_d0.w = 8;
            boss_part_show();
            ENTITY(reg_a6)[1].hit_y_plus.sh = 0xC00;
            ENTITY(reg_a6)[1].hit_y_minus.sh = 0xD80;
            ENTITY(reg_a6)[1].hit_x_plus.sh = 0x900;
            ENTITY(reg_a6)[1].hit_x_minus.sh = 0x900;
            reg_d0.h[0] = 0x80;
            stage4_boss_part_take_hits();
            reg_d0.h[0] = 0xA0;
            stage4_boss_part_take_hits();
            stage4_boss_shield_off();
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_center_hatch_open_start(void) {
    STEP(reg_a4)->frame.sh = 0x202;
    stage4_boss_center_hatch_open();
}

void stage4_boss_center_hatch_open() {
    u16 temp_a0;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[3].offset_y.h += 4;
        temp_a0 = ENTITY(reg_a6)[3].offset_y.h;
        if (temp_a0 == 0x1C) {
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_center_hatch_close_start(void) {
    STEP(reg_a4)->frame.h = 0x202;
    stage4_boss_center_hatch_close();
}

void stage4_boss_center_hatch_close() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[3].offset_y.h -= 4;
        if (ENTITY(reg_a6)[3].offset_y.h == 0) {
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_cutter_bay_open_start(void) {
    STEP(reg_a4)->frame.h = 1;
    stage4_boss_cutter_bay_open();
}

void stage4_boss_cutter_bay_open() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[8].offset_y.h += 4;
        if ((s16) ENTITY(reg_a6)[8].offset_y.h >= 0x3C) {
            ENTITY(reg_a6)[8].offset_y.h = 0x3CU;
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_cutter_bay_close_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage4_boss_cutter_bay_close();
}


void stage4_boss_cutter_bay_close(void)
{
    s32 remainingIsPositive;

    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;

    if ((s32)reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[8].offset_y.h -= 4;

        remainingIsPositive = 0 < ENTITY(reg_a6)[8].offset_y.sh;
        if (remainingIsPositive == 0) {
            ENTITY(reg_a6)[8].offset_y.h = 0;
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_right_pod_open_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage4_boss_right_pod_open();
}

void stage4_boss_right_pod_open() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[4].offset_x.h += 4;
        if ((s16) ENTITY(reg_a6)[4].offset_x.h >= 0x20) {
            ENTITY(reg_a6)[4].offset_x.h = 0x20U;
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_right_pod_close_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage4_boss_right_pod_close();
}

void stage4_boss_right_pod_close(void)
{
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count--;

    if ((s32)reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[4].offset_x.h -= 4;

        if (0 < ENTITY(reg_a6)[4].offset_x.sh) {
            return;
        }

        ENTITY(reg_a6)[4].offset_x.h = 0;
        stage4_boss_anim_end();
    }
}


void stage4_boss_left_pod_open_start(void) {
    STEP(reg_a4)->frame.sh = 1;
    stage4_boss_left_pod_open();
}

void stage4_boss_left_pod_open() {
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        STEP(reg_a4)->frame.t.count = (u8) STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[5].offset_x.h += 4;
        if ((s16) ENTITY(reg_a6)[5].offset_x.h >= 0x20) {
            ENTITY(reg_a6)[5].offset_x.h = 0x20U;
            stage4_boss_anim_end();
        }
    }
}


void stage4_boss_left_pod_close_start(void) {
    STEP(reg_a4)->frame.h = 1;
    stage4_boss_left_pod_close();
}

void stage4_boss_left_pod_close(void)
{
    reg_tmp.b[0] = STEP(reg_a4)->frame.t.count;
    STEP(reg_a4)->frame.t.count -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        s16 *remaining;

        STEP(reg_a4)->frame.t.count = STEP(reg_a4)->frame.t.reload;
        ENTITY(reg_a6)[5].offset_x.h -= 4;
        remaining = (s16 *)(reg_a6 + 0xA8);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        stage4_boss_anim_end();
    }
}


void stage4_boss_aimed_gun_track_start(void) {
    stage4_boss_aimed_gun_track();
}

s32 aim_at_player();                            /* extern */
s32 direction_turn_toward();                            /* extern */

void stage4_boss_aimed_gun_track(void) {
    reg_d0.h[0] = ENTITY(reg_a6)[8].y.h;
    reg_d1.h[0] = ENTITY(reg_a6)[8].x.h;
    aim_at_player();
    if (cond_flag == 0) {
        reg_d0.b[0] = ENTITY(reg_a6)[8].move.b.dir;
        direction_turn_toward();
        ENTITY(reg_a6)[8].move.b.dir = (u8) reg_d1.b[0];
    }
}


void stage4_boss_body_anim_start(void) {
    stage4_boss_body_anim();
}

void stage4_boss_body_anim(void) {
    ENTITY(reg_a6)[1].offset_y.h += 4;
    ENTITY(reg_a6)[1].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[2].offset_y.h += 4;
    ENTITY(reg_a6)[2].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[4].offset_y.h += 4;
    ENTITY(reg_a6)[4].offset_y.h &= 0x1F;
    ENTITY(reg_a6)[5].offset_y.h += 4;
    ENTITY(reg_a6)[5].offset_y.h &= 0x1F;
}
