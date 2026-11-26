#include "common.h"
#include "scenery.h"

void stage1_scenery_00_update(void);
void stage1_scenery_01_update(void);
void stage1_scenery_02_update(void);
void stage1_scenery_03_update(void);
void stage1_scenery_04_update(void);
void stage1_scenery_05_update(void);
void stage1_scenery_06_update(void);
void stage1_scenery_07_update(void);
void stage1_scenery_08_update(void);
void stage1_scenery_09_update(void);
void stage1_scenery_10_update(void);
void stage1_scenery_11_update(void);
void stage1_scenery_12_update(void);

s32 entity_release();
s32 entity_follow_scroll();
extern u16 g_enemy_signal_1;
extern void sprite_draw_layer2();
extern void sprite_draw_layer3();

void stage1_scenery_00_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC0);
    SCENERY(reg_a6)->part.size.h = 0x24D0;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_00_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x14;
}

void stage1_scenery_00_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    if ((g_enemy_signal_1 != 0) || (reg_d0.h[0] = SCENERY(reg_a6)->y.h, (((s16) reg_d0.h[0] < -0x4800) != 0))) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_01_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC1);
    SCENERY(reg_a6)->part.size.h = 0x1470;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_01_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x13;
}

void stage1_scenery_01_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2800) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_02_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC2);
    SCENERY(reg_a6)->part.size.h = 0x1690;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_02_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x13;
}

void stage1_scenery_02_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x2BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_03_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC3);
    SCENERY(reg_a6)->part.size.h = 0x26A8;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_03_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage1_scenery_03_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_04_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC4);
    SCENERY(reg_a6)->part.size.h = 0x26B0;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_04_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage1_scenery_04_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_05_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC5);
    SCENERY(reg_a6)->part.size.h = 0x2860;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_05_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x12;
}

void stage1_scenery_05_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_06_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC6);
    SCENERY(reg_a6)->part.size.h = 0x28C0;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_06_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x12;
}

void stage1_scenery_06_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_07_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC7);
    SCENERY(reg_a6)->part.size.h = 0x2660;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_07_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x12;
}

void stage1_scenery_07_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x4BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_08_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC8);
    SCENERY(reg_a6)->part.size.h = 0x2A70;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_08_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x13;
}

void stage1_scenery_08_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x53FF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_09_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1AC9);
    SCENERY(reg_a6)->part.size.h = 0x2A70;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_09_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x13;
}

void stage1_scenery_09_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x53FF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_10_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1ACA);
    SCENERY(reg_a6)->part.size.h = 0x1E80;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_10_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x14;
}

void stage1_scenery_10_update(void) {
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_11_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1ACB);
    SCENERY(reg_a6)->part.size.h = 0x2090;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_11_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x14;
}

void stage1_scenery_11_update(void) {
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}

void stage1_scenery_12_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1ACC);
    SCENERY(reg_a6)->part.size.h = 0xA50;
    STORE_ARCADE_ADDRESS(SCENERY(reg_a6)->routine, stage1_scenery_12_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x15;
}

void stage1_scenery_12_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x13FF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer3);
}
