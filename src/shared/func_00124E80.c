#include "common.h"

extern s16 D_00295EA0_as_s16_a[];
extern s16 *reg_a0_as_s16_p;

void func_00124E80(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;
    s32 entryFlags;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = reg_a0_as_s16_p;
    reg_a0_as_s16_p = D_00295EA0_as_s16_a;
    reg_d0.h[0] = 0x13;

    do {
        entryFlags = *reg_a0_as_s16_p;
        if (0 <= entryFlags) {
            goto nextEntry;
        }
        *reg_a0_as_s16_p = entryFlags & ~1;

    nextEntry:
        reg_a0_as_s16_p += 4;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_a0_as_s16_p = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}
