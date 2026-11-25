/* Small data the enemy common unit has only in Death Label. */
#include "common.h"

extern u8 D_00270360[];
extern u8 death_D_00270340[];

extern void *death_D_002901F0[2];

void *death_D_002901F0[2] = {
    death_D_00270340,
    D_00270360,
};
