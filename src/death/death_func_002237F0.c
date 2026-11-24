#include "common.h"

typedef struct {
    u8 first;
    u8 second;
} Pair;

extern Pair death_D_0028E450[][3][5];
extern u8 death_D_00290854;
extern u8 death_D_00290858;
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];

void death_func_002237F0(u8 phase) {
    u8 type;

    type = D_00684C80[9] / 2 - 1;
    death_D_00290858 = death_D_0028E450[death_D_00290DC0][type][phase].first;
    death_D_00290854 = death_D_0028E450[death_D_00290DC0][type][phase].second;
}
