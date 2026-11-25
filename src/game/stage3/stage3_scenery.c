#include "common.h"
#include "scenery.h"

void stage3_scenery_00_update(void);
void stage3_scenery_01_update(void);
void stage3_scenery_02_update(void);
void stage3_scenery_03_update(void);
void stage3_scenery_04_update(void);
void stage3_scenery_05_update(void);
void stage3_scenery_06_update(void);
void stage3_scenery_07_update(void);
void stage3_scenery_08_update(void);
void stage3_scenery_09_update(void);
void stage3_scenery_10_update(void);
void stage3_scenery_11_update(void);
void stage3_scenery_12_update(void);
void stage3_scenery_13_update(void);

s32 entity_release();
s32 entity_follow_scroll();
extern u16 g_enemy_signal_1;
extern void sprite_draw_layer2();
extern void sprite_draw_layer3();

void stage3_scenery_00_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CBF);
    SCENERY(reg_a6)->part.size.h = 0x38A0;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_00_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_00_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_01_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC0);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_01_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_01_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_02_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC1);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_02_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_02_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_03_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC2);
    SCENERY(reg_a6)->part.size.h = 0x1040;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_03_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_03_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x1FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_04_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC3);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_04_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_04_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_05_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC4);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_05_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_05_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_06_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC5);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_06_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_06_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_07_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC6);
    SCENERY(reg_a6)->part.size.h = 0x1720;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_07_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_07_update(void) {
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
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_08_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC7);
    SCENERY(reg_a6)->part.size.h = 0x3890;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_08_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_08_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_09_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC8);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_09_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_09_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_10_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CC9);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_10_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_10_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_11_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CCA);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_11_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_11_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_12_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CCB);
    SCENERY(reg_a6)->part.size.h = 0x3920;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_12_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_12_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x6FFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}

void stage3_scenery_13_setup(void) {
    STORE_LONG(SCENERY(reg_a6)->sprite, 0x1CCC);
    SCENERY(reg_a6)->part.size.h = 0x1E70;
    STORE_POINTER(SCENERY(reg_a6)->routine, stage3_scenery_13_update);
    SCENERY(reg_a6)->palette.sb[0] = 0x16;
}

void stage3_scenery_13_update(void) {
    if (NO_SCENERY_IN_THIS_PLAY()) {
        entity_release();
        return;
    }
    reg_d0.h[0] = SCENERY(reg_a6)->y.h;
    if ((s16) reg_d0.h[0] < -0x3BFF) {
        entity_release();
        return;
    }
    entity_follow_scroll();
    scenery_draw((void *)sprite_draw_layer2);
}
