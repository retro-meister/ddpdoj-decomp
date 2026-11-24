#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_unroll_loops off
#include "common.h"

extern u32 D_002B4D50[];

void func_00219990(void) {
    s32 i = 14;
    u32 *p;
    s32 row = 0x380;

    do {
        s32 c1 = 54;
        p = D_002B4D50;
        p += c1 + row;
        *p = 0;
        {
            s32 c2 = 55;
            s32 idx2 = c2 + row;
            i++;
            row += 64;
            p = D_002B4D50;
            p += idx2;
            *p = 0;
        }
    } while (i < 27);
}
