#include "common.h"

extern s8 D_0028E408;

s32 func_00125EE0();
extern u16 D_0028E854;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern u16 D_0029CEA0[];
extern u8 *reg_a6;

void func_001D27A0(void) {
    u32 temp_v1;

    reg_d0.h[0] = D_0029CEA0[0];
    reg_d0.h[0] |= D_0028E854;
    if ((s16) reg_d0.h[0] < 0) {
        reg_d0.h[0] = D_0029CEA0[0];
        if ((D_0029CEA0[0] & 0xFFFF) && (reg_d0.w & 1)) {
            temp_v1 = reg_d1.b[0] & 0x5C;
            reg_d1.b[0] = temp_v1;
            if (!(temp_v1 & 0xFF)) {
                if ((s16)(D_0028E854) < 0) {
                    goto block_5;
                }
                goto block_6;
            }
            goto block_11;
        }
block_5:
        reg_d0.w = 0;
        goto block_9;
    }
block_6:
    if (D_00299764[0] != 0) {
        reg_d0.h[0] = D_00299766[0];
        if ((s16) reg_d0.h[0] < 0) {
            *reg_a6 = 0x80;
        } else {
block_9:
            func_00125EE0();
        }
block_11:
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
