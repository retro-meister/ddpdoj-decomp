#include "common.h"

extern s16 D_00295EA0_as_s16_a[];
extern s16 *reg_a0_as_s16_p;

void func_00124E10(void)
{
    s16 *savedAddress;
    u32 savedData;
    s16 *table;

    savedData = reg_d0.w;
    table = D_00295EA0_as_s16_a;
    savedAddress = reg_a0_as_s16_p;
    reg_a0_as_s16_p = table;
    reg_d0.h[0] = 0x13;

    do {
        s16 flags = *reg_a0_as_s16_p;

        if (0 > (s64)flags) {
            *reg_a0_as_s16_p = flags | 1;
        }
        reg_a0_as_s16_p += 4;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_a0_as_s16_p = savedAddress;
    reg_d0.w = savedData;
}
