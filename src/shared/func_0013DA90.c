#include "common.h"

void func_0013CA90(void);
void func_0013DA80(void);
extern u8 D_002555E0[];
extern u8 D_0028E078[];
extern u8 D_0028E07C_as_u8_a[];
extern s8 D_0028E408;
extern s16 D_0029F160[];
extern u16 D_0029F210[];
extern u16 D_0029F212[];
extern u16 D_0029F248[];
extern u16 D_0029F24A[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0013DA90(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F210;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F212;
    if (reg_d0.h[0] == 0x10) {
        func_0013DA80();
        return;
    }
    if (*(u16 *)(u32)D_0029F212 != 8) {
        *(u16 *)(u32)D_0029F212 += 2;
        func_0013CA90();
        D_0029F160[0] = 0;
    }
    if (*(u16 *)(u32)D_0029F210 != 8) {
        *(u16 *)(u32)D_0029F210 += 2;
        reg_a0 = (u8 *)D_002555E0;
        reg_d0.h[0] = D_0029F24A[0];
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F248[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)D_0028E078;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d0.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
        }
        reg_a2 = (u8 *)D_0028E07C_as_u8_a;
        reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d1.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
        }
    }
    D_0028E408 = 0;
}
