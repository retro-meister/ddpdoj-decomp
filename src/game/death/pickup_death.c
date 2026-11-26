#include "common.h"

s32 death_func_001271E0(void);
void func_00125EE0(void);

void death_func_00128A90(void) {
    if (death_func_001271E0() == 0) {
        func_00125EE0();
    }
}
