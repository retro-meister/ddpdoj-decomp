#include "common.h"

s32 func_00171400();
s32 func_001CEC30();
extern u16 D_002594F0[];
extern u16 D_0028E910;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CEF00(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x8C00U) {
            (*(u8 *)((u8 *)(reg_a4) + (0x16))) = 5U;
            (*(u8 *)((u8 *)(reg_a4) + (0x18))) = 0xFBU;
            (*(u8 *)((u8 *)(reg_a4) + (2))) = 3U;
            if (D_0028E910 != 0) {
                (*(u8 *)((u8 *)(reg_a4) + (2))) = 3U;
            }
        }
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d0.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d0.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d4.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x16)));
        (*(u8 *)((u8 *)(reg_a4) + (0x17))) += reg_d0.b[0];
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x17)));
        func_001CEC30();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB2)));
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d3.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = ((((u16)reg_d5.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)(((u16)reg_d5.h[0]) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x1100FF80;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d4.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x18)));
        (*(u8 *)((u8 *)(reg_a4) + (0x19))) += reg_d0.b[0];
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x19)));
        func_001CEC30();
        func_00171400();
    }
}
