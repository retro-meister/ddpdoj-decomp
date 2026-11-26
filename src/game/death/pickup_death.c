#include "common.h"

s32 bullet_is_type_24(void);
void pickup_spawn_here(void);

void bullet_cancel_to_pickup(void) {
    if (bullet_is_type_24() == 0) {
        pickup_spawn_here();
    }
}
