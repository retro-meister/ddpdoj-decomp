#include "common.h"

s32 death_func_001271E0(void);
void pickup_spawn_here(void);

void death_func_00128A90(void) {
    if (death_func_001271E0() == 0) {
        pickup_spawn_here();
    }
}
