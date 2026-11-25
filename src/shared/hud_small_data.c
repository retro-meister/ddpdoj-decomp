/* Data of the hud unit, still to be merged into it. */
#include "common.h"

extern u8 D_0026BCA0[];
extern u8 D_0026BD20[];

extern u16 D_0028DAD0[4];
extern u16 D_0028DAD8[2];
extern u16 D_0028DADC[2];
extern void *D_0028DAE0[2];
extern u16 D_0028DAE8[4];
extern u16 D_0028DAF0[4];
extern u16 D_0028DAF8[4];
extern u16 D_0028DB00[4];

u16 D_0028DAD0[4] = {
    0x0000, 0x0014, 0x000A, 0x0014,
};

u16 D_0028DAD8[2] = {
    0x0038, 0x005A,
};

u16 D_0028DADC[2] = {
    0x0014, 0x0012,
};

void *D_0028DAE0[2] = {
    D_0026BCA0,
    D_0026BD20,
};

u16 D_0028DAE8[4] = {
    0x0A4C, 0x0000, 0x0A4E, 0x0000,
};

u16 D_0028DAF0[4] = {
    0x0A4D, 0x0000, 0x0A4F, 0x0000,
};

u16 D_0028DAF8[4] = {
    0x0627, 0x0012, 0x062B, 0x0012,
};

u16 D_0028DB00[4] = {
    0x0629, 0x0014, 0x062D, 0x0014,
};
