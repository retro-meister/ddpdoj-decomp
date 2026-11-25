#include "common.h"
#include "entity.h"

/*
 * Debug enemy: moved with the second player's stick, it leaves a wreck of the kind chosen by the debug number
 * when the second player presses a button. This is its own part of the enemy work block (reg_a5).
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyWork */
    /* 0x16 */ u8 unused;
    /* 0x17 */ u8 seen_on_screen;
    /* 0x18 */ u16 start_delay;   /* frames before the button is looked at */
} WreckTestWork;

#define WRECK_TEST(pointer) ((WreckTestWork *)(pointer))

void enemy_set_entity_count(s32);

void wreck_test_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_work();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 g_wreck_test_entities[];
extern s32 g_wreck_test_work;

void wreck_test_setup(void) {
    reg_a0 = (u8 *)g_wreck_test_entities;
    enemy_init_entities();
    reg_a0 = (u8 *)(&g_wreck_test_work);
    reg_d0.w = 1;
    enemy_set_task_work();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 debug_number_get();                            /* extern */
s32 input_get_p2_pressed();                            /* extern */
s32 entity_draw();                            /* extern */
s32 entity_move_by_p2_stick();                            /* extern */
s32 wreck_spawn();                            /* extern */

void wreck_test_main(void) {
    s64 number;
    u16 delay;

    entity_move_by_p2_stick();
    delay = WRECK_TEST(reg_a5)->start_delay;
    if (delay != 0) {
        WRECK_TEST(reg_a5)->start_delay = (u16) (delay - 1);
    } else {
        input_get_p2_pressed();
        if (reg_d0.w & 0x40) {
            debug_number_get();
            number = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((number < 4) && (number >= 0)) {
                reg_d1.w = 0;
                reg_d0.h[0] *= 4;
                wreck_spawn();
            }
        }
    }
    entity_draw();
}

s32 g_wreck_test_entities[8] = {
    -33521664, 65024, 34603243, 0, 0, 268435456, 0, 0,
};

s32 g_wreck_test_work = 262144;
