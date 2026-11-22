#include "common.h"

s32 enemy_end_task(u16);                        /* extern */
extern s8 D_0028E408;
extern u16 D_0028E894;
extern u16 D_0028E91C;

void func_00150740(void) {
    if ((D_0028E91C == 1) && (D_0028E894 != 0)) {
        enemy_end_task(D_0028E91C);
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
