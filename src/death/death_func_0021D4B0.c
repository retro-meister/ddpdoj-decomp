#include "common.h"

s32 death_func_0021B180(void);
void death_func_0021D4F0(void);
void death_func_0021D520(void);

void death_func_0021D4B0(void) {
    if (death_func_0021B180()) {
        death_func_0021D520();
    } else {
        death_func_0021D4F0();
    }
}
