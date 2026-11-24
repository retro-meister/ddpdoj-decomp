#include "common.h"

extern u16 death_D_0068FFB2[];
extern u16 death_D_0068FFB4[];
extern u16 death_D_006901D2[];
extern u16 death_D_006901D4[];

void death_func_0021D520(void) {
    death_D_006901D2[0] = death_D_0068FFB2[0];
    death_D_006901D4[0] = death_D_0068FFB4[0];
}
