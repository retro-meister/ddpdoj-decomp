#include "common.h"
#include "entity.h"

/*
 * Debug enemy: moved with the second player's stick, it throws out debris of the kind chosen by the debug number
 * (the button test compares the whole input word with one value, so it does so on nearly every frame). This is its own part of the enemy state block (reg_a5).
 */
typedef struct {
    /* 0x00 */ u8 common[0x16];   /* EnemyState */
    /* 0x16 */ u8 unused;
    /* 0x17 */ u8 seen_on_screen;
    /* 0x18 */ u16 start_delay;   /* frames before the button is looked at */
} DebrisTestState;

#define DEBRIS_TEST(pointer) ((DebrisTestState *)(pointer))

extern void enemy_set_entity_count(s32);

void debris_test_first(void) {
    enemy_set_entity_count(0);
}

s32 enemy_set_task_state();                            /* extern */
s32 enemy_init_entities();                            /* extern */
extern s32 g_debris_test_entities[];
extern s32 g_debris_test_state;

void debris_test_setup(void) {
    reg_a0 = (u8 *)g_debris_test_entities;
    enemy_init_entities();
    reg_a0 = (u8 *)(&g_debris_test_state);
    reg_d0.w = 1;
    enemy_set_task_state();
    reg_tmp.w = 0x38001C00;
    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[0];
}

s32 debug_number_get();                            /* extern */
s32 input_get_p2_pressed();                            /* extern */
s32 entity_draw();                            /* extern */
s32 debris_spawn();                            /* extern */
s32 entity_move_by_p2_stick();                            /* extern */

void debris_test_main(void) {
    s64 number;
    u16 delay;

    entity_move_by_p2_stick();
    delay = DEBRIS_TEST(reg_a5)->start_delay;
    if (delay != 0) {
        DEBRIS_TEST(reg_a5)->start_delay = (u16) (delay - 1);
    } else {
        input_get_p2_pressed();
        if (reg_d0.w != 6) {
            debug_number_get();
            number = (s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30;
            if ((number < 5) && (number >= 0)) {
                reg_d0.h[0] *= 4;
                reg_d0.h[0] <<= 8;
                reg_d0.w = (u32) reg_d0.h[0];
                reg_d0.w |= 0x20000;
                debris_spawn();
            }
        }
    }
    entity_draw();
}
