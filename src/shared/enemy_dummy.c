#include "common.h"

void enemy_set_entity_count(s32);

void dummy_enemy_first(void) {
    enemy_set_entity_count(0);
}

extern void enemy_remove(void);

void dummy_enemy_main(void) {
    enemy_remove();
}

void dummy_enemy_main_b(void) {
    enemy_remove();
}
