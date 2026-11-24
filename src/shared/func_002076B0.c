#include "common.h"

extern s32 D_00267950[];
extern u16 D_0028E230;
extern s32 D_002B2710[];

void func_002076B0(void)
{
    s32 *destination;
    s32 *source;

    destination = D_002B2710;
    source = D_00267950;
    reg_d0.h[0] = 0xF;
    do {
        *destination = *source;
        source++;
        destination++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.h[0] = 0x10;
    reg_d0.h[0] |= 0x200;
    D_0028E230 = reg_d0.h[0];
}
