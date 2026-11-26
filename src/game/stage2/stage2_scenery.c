#include "common.h"
#include "scenery.h"

extern u16 g_stage2_scenery_05_frames[128];

void stage2_scenery_00_update(void);
void stage2_scenery_01_update(void);
void stage2_scenery_02_update(void);
void stage2_scenery_03_update(void);
void stage2_scenery_04_update(void);
void stage2_scenery_05_update(void);

s32 entity_release();
s32 entity_follow_scroll();
extern u16 g_enemy_signal_1;
extern void sprite_draw_layer2();
extern void sprite_draw_layer3();
s32 sprite_draw_layer4();
s32 sprite_draw_layer4_keep();
extern u8 g_ground_no_draw;
extern u16 g_scroll_line;

void stage2_scenery_00_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BF8);
    SCENERY(reg_a6)->part.size.h = 0x2EE0;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_00_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x13;
}

void stage2_scenery_00_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x5C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage2_scenery_01_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BA0);
    SCENERY(reg_a6)->part.size.h = 0x1F20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_01_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x11;
}

void stage2_scenery_01_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage2_scenery_02_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BA3);
    SCENERY(reg_a6)->part.size.h = 0x2050;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_02_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x12;
}

void stage2_scenery_02_update(void) {
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4000) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage2_scenery_02_setup_alt(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BA3);
    SCENERY(reg_a6)->part.size.h = 0x2050;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_02_update);
    SCENERY(reg_a6)->palette.sh = 0x52;
}

void stage2_scenery_03_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BA4);
    SCENERY(reg_a6)->part.size.h = 0x2A50;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_03_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x12;
}

void stage2_scenery_03_update(void) {
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x5400) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage2_scenery_03_setup_alt(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BA4);
    SCENERY(reg_a6)->part.size.h = 0x2A50;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_03_update);
    SCENERY(reg_a6)->palette.sh = 0x52;
}

void stage2_scenery_04_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BF9);
    SCENERY(reg_a6)->part.size.h = 0x1220;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_04_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x15;
}

void stage2_scenery_04_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2400) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage2_scenery_05_setup(void) {
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage2_scenery_05_update);
    SCENERY(reg_a6)->frame.sh = 0xF8;
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1BB7);
    STORE_LONG(SCENERY(reg_a6)->part.second_sprite, 0x1BC7);
    SCENERY(reg_a6)->frame_countdown = 2;
    SCENERY(reg_a6)->frame_time = 2;
}

void stage2_scenery_05_update(void) {
    u16 first_low;
    u16 second_low;
    u32 position;

    if ((s32) g_scroll_line >= 0x22F) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    if (((s32) g_scroll_line >= 0x1F4) && (0 <= (s64)SCENERY(reg_a6)->frame.sh)) {
        reg_tmp.b[0] = SCENERY(reg_a6)->frame_countdown;
        SCENERY(reg_a6)->frame_countdown -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            SCENERY(reg_a6)->frame_countdown = (u8) SCENERY(reg_a6)->frame_time;
            reg_d0.h[0] = SCENERY(reg_a6)->frame.h;
            reg_a0 = (u8 *)(g_stage2_scenery_05_frames);
            reg_a0 += reg_d0.h[0];
            SCENERY(reg_a6)->sprite[0] = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            SCENERY(reg_a6)->sprite[1] = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            SCENERY(reg_a6)->part.second_sprite[0] = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            SCENERY(reg_a6)->part.second_sprite[1] = (u16) *(u16 *)reg_a0;
            reg_a0 += 2;
            SCENERY(reg_a6)->frame.h -= 8;
        }
    }
    if (((s32) g_scroll_line < 0x21A) && ((reg_d1.h[1] = SCENERY(reg_a6)->y.h, reg_d1.h[0] = SCENERY(reg_a6)->x.h, position = reg_d1.w, reg_d1.w = position + 0xFE00DC00, reg_d2.h[1] = SCENERY(reg_a6)->sprite[0], first_low = SCENERY(reg_a6)->sprite[1], reg_d2.h[0] = first_low, reg_d3.h[0] = 0x2720, reg_d4.h[0] = 0x15, (g_simulation_active == 0)) || (g_simulation_boss_start == 0) || (g_ground_no_draw == 0)) && ((g_game_mode != GAME_MODE_BOSS_RUSH) || (g_ground_no_draw == 0))) {
        sprite_draw_layer4_keep();
    }
    reg_d1.h[0] = SCENERY(reg_a6)->y.h;
    reg_d1.h[0] += 0x4C00;
    reg_tmp1.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = reg_tmp1.h[1];
    reg_d1.h[0] = SCENERY(reg_a6)->x.h;
    reg_d1.w += 0xFE00DC00;
    reg_d2.h[1] = SCENERY(reg_a6)->part.second_sprite[0];
    second_low = SCENERY(reg_a6)->part.second_sprite[1];
    reg_d2.h[0] = second_low;
    reg_d3.h[0] = 0x2320;
    reg_d4.h[0] = 0x15;
    if (((g_simulation_active == 0) || (g_simulation_boss_start == 0) || (g_ground_no_draw == 0)) && ((g_game_mode != GAME_MODE_BOSS_RUSH) || (g_ground_no_draw == 0))) {
        sprite_draw_layer4();
    }
}

/* The frames of piece 5: sixty-four sprite numbers as 32-bit values, high word first. */
u16 g_stage2_scenery_05_frames[128] = {
    0x0000, 0x1BC6, 0x0000, 0x1BE6, 0x0000, 0x1BC6, 0x0000, 0x1BE5,
    0x0000, 0x1BC6, 0x0000, 0x1BE4, 0x0000, 0x1BC6, 0x0000, 0x1BE3,
    0x0000, 0x1BC6, 0x0000, 0x1BE2, 0x0000, 0x1BC6, 0x0000, 0x1BE1,
    0x0000, 0x1BC6, 0x0000, 0x1BE0, 0x0000, 0x1BC6, 0x0000, 0x1BDF,
    0x0000, 0x1BC6, 0x0000, 0x1BDE, 0x0000, 0x1BC6, 0x0000, 0x1BDD,
    0x0000, 0x1BC6, 0x0000, 0x1BDC, 0x0000, 0x1BC6, 0x0000, 0x1BDB,
    0x0000, 0x1BC6, 0x0000, 0x1BDA, 0x0000, 0x1BC6, 0x0000, 0x1BD9,
    0x0000, 0x1BC6, 0x0000, 0x1BD8, 0x0000, 0x1BC6, 0x0000, 0x1BD7,
    0x0000, 0x1BC6, 0x0000, 0x1BD6, 0x0000, 0x1BC5, 0x0000, 0x1BD5,
    0x0000, 0x1BC4, 0x0000, 0x1BD4, 0x0000, 0x1BC3, 0x0000, 0x1BD3,
    0x0000, 0x1BC2, 0x0000, 0x1BD2, 0x0000, 0x1BC1, 0x0000, 0x1BD1,
    0x0000, 0x1BC0, 0x0000, 0x1BD0, 0x0000, 0x1BBF, 0x0000, 0x1BCF,
    0x0000, 0x1BBE, 0x0000, 0x1BCE, 0x0000, 0x1BBD, 0x0000, 0x1BCD,
    0x0000, 0x1BBC, 0x0000, 0x1BCC, 0x0000, 0x1BBB, 0x0000, 0x1BCB,
    0x0000, 0x1BBA, 0x0000, 0x1BCA, 0x0000, 0x1BB9, 0x0000, 0x1BC9,
    0x0000, 0x1BB8, 0x0000, 0x1BC8, 0x0000, 0x1BB7, 0x0000, 0x1BC7,
};
