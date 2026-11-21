#include "common.h"

extern u8 enemy_move_end_requested;

void enemy_end_task(void);

void func_0014EFD0(void) {
    enemy_move_end_requested = 1;
    enemy_end_task();
}
