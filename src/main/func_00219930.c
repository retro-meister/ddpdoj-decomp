#include "common.h"

extern u32 D_002B4D50[];

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

void func_00219930(void) {
    s32 i;
    u32 *p;
    s32 row;
    s32 x1;
    s32 x2;
    s32 idx;

    i = 0;
    row = 0;
    do {
        x1 = 54;
        p = D_002B4D50;
        p += x1 + row;
        *p = 0;
        x2 = 55;
        idx = x2 + row;
        i++;
        row += 64;
        p = D_002B4D50;
        p += idx;
        *p = 0;
    } while (i < 14);
}

#pragma pop
