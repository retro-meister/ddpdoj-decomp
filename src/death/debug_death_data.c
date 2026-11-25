/* A table the debug unit has only in Death Label. */
#include "common.h"

extern u8 D_0026FD60[];
extern u8 D_0026FD70[];
extern u8 D_0026FD80[];

struct DeathD0026fd90Record { void *p0[3]; u16 w1[2]; };
extern struct DeathD0026fd90Record death_D_0026FD90;

struct DeathD0026fd90Record death_D_0026FD90 = {
    {
        D_0026FD60,
        D_0026FD70,
        D_0026FD80,
    },
    { 0x0000, 0x0000 },
};
