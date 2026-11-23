#include "common.h"

s32 func_0018D4D0();
extern u16 D_0028E31C;
extern s8 D_0028EBD0;
extern u8 D_0028ED80;
extern u8 D_0057CC60[];
s32 func_00223BE0(void) {
    s32 temp_s0;
    s32 temp_v1;
    s32 temp_v1_2;

    if (D_0028ED80 == 0) { temp_s0 = 8; } else { temp_s0 = 8; }
    if (D_0028ED80 == 0) {
        temp_v1 = *(u32 *)(D_0057CC60 + (D_0028E31C * 4));
        if (temp_v1 & 0x1000) {
            func_0018D4D0();
            D_0028EBD0 -= 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 -= 1;
            }
            if (D_0028EBD0 <= 0) {
                D_0028EBD0 = temp_s0 - 1;
            }
            return 1;
        }
        if (temp_v1 & 0x4000) {
            func_0018D4D0();
            D_0028EBD0 += 1;
            if (D_0028EBD0 == 6) {
                D_0028EBD0 += 1;
            }
            if (D_0028EBD0 >= temp_s0) {
                D_0028EBD0 = 1;
            }
            return 1;
        }
        goto block_21;
    }
    temp_v1_2 = *(u32 *)(D_0057CC60 + (D_0028E31C * 4));
    if (temp_v1_2 & 0x1000) {
        func_0018D4D0();
        D_0028EBD0 -= 1;
        if (D_0028EBD0 <= 0) {
            D_0028EBD0 = temp_s0 - 1;
        }
        return 1;
    }
    if (temp_v1_2 & 0x4000) {
        func_0018D4D0();
        D_0028EBD0 += 1;
        if (D_0028EBD0 >= temp_s0) {
            D_0028EBD0 = 1;
        }
        return 1;
    }
block_21:
    return 0;
}
