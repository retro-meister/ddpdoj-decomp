#include "common.h"

extern s16 D_00295EA0[];
extern s16 *reg_a0;

void func_00124E10(void)
{
    s16 *savedAddress;
    u32 savedData;
    s16 *table;
    s32 hasMoreEntries;

    savedData = reg_d0.w;
    table = D_00295EA0;
    savedAddress = reg_a0;
    reg_a0 = table;
    reg_d0.h[0] = 0x13;

    do {
        s16 flags = *reg_a0;
        s16 *entry;
        u32 remaining;

        if (0 > (s64)flags) {
            *reg_a0 = flags | 1;
        }

        remaining = (u16)reg_d0.h[0];
        entry = reg_a0;
        remaining -= 1;
        reg_d0.h[0] = (u16)remaining;
        hasMoreEntries = (s16)remaining >= 0;
        reg_a0 = entry + 4;
    } while (hasMoreEntries);

    reg_a0 = savedAddress;
    reg_d0.w = savedData;
}
