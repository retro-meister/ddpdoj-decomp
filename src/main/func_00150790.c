#include "common.h"

s32 enemy_end_task(u16);                        /* extern */
extern s8 D_0028E408;
extern u16 D_0028E858;
extern u16 D_0028E91C;

void func_00150790(void) {
    if ((D_0028E91C == 2) && (D_0028E858 != 0)) {
        enemy_end_task(D_0028E91C);
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
