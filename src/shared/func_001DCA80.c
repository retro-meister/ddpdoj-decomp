#include "common.h"

extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0019D710();
s32 func_001D27A0();
s32 func_00201C60();
s32 func_00202180();
s32 func_00203060();
extern u8 D_0024EBC0[];
extern u8 D_0024EC80_as_u8_a[];
extern u8 D_0024EEF0_as_u8_a[];
extern u8 D_0028E2E4;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001DCA80(void) {
    u16 temp_a0;
    u16 temp_a1;
    u8 temp_v1;
    if (D_0028E2E4 == 0) {
        reg_d1.w = 0x5C;
        reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
        if (reg_d1.b[0] != 0) {
            reg_d0.b[0] = 0xA3;
            (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFF;
        }
        func_001D27A0();
        if (D_0028E408 == 0) {
            func_00203060();
            if (D_0028E408 != 0) {
                if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
block_6:
                    func_0014E290();
                    return;
                }
                goto block_8;
            }
            (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_8:
            func_00201C60();
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) += 4;
                (*(u8 *)((u8 *)(reg_a5) + (0x1B))) &= 0x3F;
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
                    (*(u8 *)((u8 *)(reg_a6) + (0x1B))) -= 1;
                    if ((*(u8 *)((u8 *)(reg_a6) + (0x1B))) == 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                        (*(u16 *)((u8 *)(reg_a5) + (0x18))) = 0;
                        func_00202180();
                        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) reg_d1.b[0];
                        (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
                    }
                }
            }
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 1) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
                (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
                    temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
                    if (temp_v1 != 0x24) {
                        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_v1 + 1);
                    }
                }
            }
            reg_d1.w = 0;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
            reg_a0 = (u8 *)D_0024EEF0_as_u8_a;
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
            (*(u8 *)((u8 *)(reg_a6) + (0x1D))) = (u8) reg_d0.b[0];
            reg_a0 = (u8 *)D_0024EC80_as_u8_a;
            reg_d1.h[0] += reg_d1.h[0];
            reg_d1.h[0] += reg_d1.h[0];
            reg_d0.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_a0 = (u8 *)D_0024EBC0;
            reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
            reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_a0 = (u8 *) reg_tmp.w;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d2.h[0] = temp_a1;
            reg_d3.h[0] = 0x210;
            reg_d4.w = 0;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFE00FE00;
            reg_d6.w = 0xF800F800;
            func_0019D710();
            return;
        }
        goto block_6;
    }
    goto block_6;
}
