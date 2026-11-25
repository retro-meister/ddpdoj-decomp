/* Data of the difficulty unit, still to be merged into it. */
#include "common.h"

extern u8 D_0028DA98[];
extern u8 D_0028DAA0[];
extern u8 D_0028DAA8[];
extern u8 D_0028DAB0[];

extern void *D_0026A2A0[4];
extern u16 D_0028DAB8[4];

void *D_0026A2A0[4] = {
    D_0028DA98,
    D_0028DAA0,
    D_0028DAA8,
    D_0028DAB0,
};

u16 D_0028DAB8[4] = {
    0xFFFF, 0x0000, 0x0001, 0x0002,
};
