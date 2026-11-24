#include "common.h"

void func_0013CA90(void);
void func_0013DFE0(void);
extern u8 D_002555E0[];
extern u8 D_0028E078[];
extern s8 D_0028E408;
extern s16 D_0029F160[];
extern u16 D_0029F210[];
extern u16 D_0029F212[];
extern u16 D_0029F248[];
extern u16 D_0029F24A[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0013DFF0(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F210;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F212;
    if (reg_d0.h[0] == 0x10) {
        func_0013DFE0();
        return;
    }
    if (*(u16 *)(u32)D_0029F212 != 8) {
        *(u16 *)(u32)D_0029F212 = 8;
        func_0013CA90();
        D_0029F160[0] = 0;
        if (*(u16 *)(u32)D_0029F210 == 8) goto block_end;
    }
    *(u16 *)(u32)D_0029F210 = 8;
    reg_a0 = (u8 *)D_002555E0;
    reg_a1 = (u8 *)D_0028E078;
    reg_d0.h[0] = D_0029F24A[0];
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += D_0029F248[0];
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
block_end:
    D_0028E408 = 0;
}
