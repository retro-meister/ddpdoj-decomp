#include "common.h"
#include "scenery.h"

void stage4_scenery_00_update(void);
void stage4_scenery_01_update(void);
void stage4_scenery_02_update(void);
void stage4_scenery_03_update(void);
void stage4_scenery_04_update(void);
void stage4_scenery_05_update(void);

s32 entity_release();
s32 entity_follow_scroll();
extern u16 g_enemy_signal_1;
extern void sprite_draw_layer2();
extern void sprite_draw_layer3();

void stage4_scenery_00_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1D84);
    SCENERY(reg_a6)->part.size.h = 0x3520;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_00_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage4_scenery_00_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6800) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage4_scenery_00_setup_alt(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1D84);
    SCENERY(reg_a6)->part.size.h = 0x3520;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_00_update);
    SCENERY(reg_a6)->palette.sh = 0x56;
}

void stage4_scenery_01_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1DBE);
    SCENERY(reg_a6)->part.size.h = 0xF20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_01_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage4_scenery_01_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage4_scenery_02_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1DBF);
    SCENERY(reg_a6)->part.size.h = 0xF20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_02_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage4_scenery_02_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage4_scenery_03_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1DC0);
    SCENERY(reg_a6)->part.size.h = 0xF20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_03_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage4_scenery_03_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage4_scenery_04_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1DC1);
    SCENERY(reg_a6)->part.size.h = 0xF20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_04_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage4_scenery_04_update(void) {
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1C00) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage4_scenery_05_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1DBD);
    SCENERY(reg_a6)->part.size.h = 0x2F20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage4_scenery_05_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage4_scenery_05_update(void) {
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
