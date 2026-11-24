#include "common.h"

extern u8 D_0028E1E8;
extern u8 D_0028E1EC;
extern u8 D_0028E39C;
extern u8 *reg_a0;

void func_001305E0(void) {
    u32 s0;
    u32 s1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    reg_d0.b[0] = *(s8 *)(reg_a0 + 2);
    if (reg_d0.b[0] == 9) goto block_end;
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) goto block_end;
    if (reg_d0.b[0] == 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        if (*(s8 *)(reg_a0 + 0) > 9) {
            *(s8 *)(reg_a0 + 0) = 9;
        }
    }
    if ((s8)reg_d0.b[0] >= 9 && (s8)reg_d0.b[0] < 0x11) {
        *(s8 *)(reg_a0 + 0) += 1;
        reg_d1.b[0] = D_0028E1EC;
        if (*(s8 *)(reg_a0 + 0) == reg_d1.b[0]) {
            *(s8 *)(reg_a0 + 0) = 0;
            *(s8 *)(reg_a0 + 2) += 1;
            if (*(s8 *)(reg_a0 + 2) > 9) {
                *(s8 *)(reg_a0 + 2) = 9;
            }
        }
    }
    if (0 <= (s8)reg_d0.b[0] && (s8)reg_d0.b[0] < 9) {
        reg_d1.b[0] = D_0028E1E8;
        *(s8 *)(reg_a0 + 2) += (s8)reg_d1.b[0];
        if (*(s8 *)(reg_a0 + 2) > 9) {
            *(s8 *)(reg_a0 + 2) = 9;
        }
    }
block_end:
    reg_d1.w = s1;
    reg_d0.w = s0;
}
