#include "common.h"

extern s16 D_00295EA0[];
extern s16 *reg_a0;

void func_00124E80(void)
{
    s16 *savedAddressRegister;
    u32 savedDataRegister;
    s32 entryFlags;

    savedDataRegister = reg_d0.w;
    savedAddressRegister = reg_a0;
    reg_a0 = D_00295EA0;
    reg_d0.h[0] = 0x13;

    do {
        entryFlags = *reg_a0;
        if (0 <= entryFlags) {
            goto nextEntry;
        }
        *reg_a0 = entryFlags & ~1;

    nextEntry:
        reg_a0 += 4;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_a0 = savedAddressRegister;
    reg_d0.w = savedDataRegister;
}
