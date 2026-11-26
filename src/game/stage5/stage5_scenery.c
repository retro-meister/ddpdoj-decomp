#include "common.h"
#include "scenery.h"

void stage5_scenery_00_update(void);
void stage5_scenery_01_update(void);
void stage5_scenery_02_update(void);
void stage5_scenery_03_update(void);

s32 entity_release();
s32 entity_follow_scroll();
extern u16 g_enemy_signal_1;
extern void sprite_draw_layer2();
extern void sprite_draw_layer3();

void stage5_scenery_00_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1F1F);
    SCENERY(reg_a6)->part.size.h = 0x1EA0;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage5_scenery_00_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage5_scenery_00_update(void) {
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

void stage5_scenery_01_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1F20);
    SCENERY(reg_a6)->part.size.h = 0x2920;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage5_scenery_01_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage5_scenery_01_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x5000) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage5_scenery_02_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1F21);
    SCENERY(reg_a6)->part.size.h = 0x1250;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage5_scenery_02_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage5_scenery_02_update(void) {
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
    scenery_draw((void *)sprite_draw_layer2);
}

void stage5_scenery_03_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1F5E);
    SCENERY(reg_a6)->part.size.h = 0x1B20;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage5_scenery_03_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x17;
}

void stage5_scenery_03_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3400) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}
