#include "common.h"

void func_0013C980(void);
void func_0013DA80(void);
extern u8 D_002555E0[];
extern u8 D_0028E080[];
extern u8 D_0028E084_as_u8_a[];
extern s8 D_0028E408;
extern s16 D_0029F1D0[];
extern u16 D_0029F280[];
extern u16 D_0029F282[];
extern u16 D_0029F2B8[];
extern u16 D_0029F2BA[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_0013D7A0(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F280;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F282;
    if (reg_d0.h[0] == 0x10) {
        func_0013DA80();
        return;
    }
    if (*(u16 *)(u32)D_0029F282 != 8) {
        *(u16 *)(u32)D_0029F282 += 2;
        func_0013C980();
        D_0029F1D0[0] = 0;
    }
    if (*(u16 *)(u32)D_0029F280 != 8) {
        *(u16 *)(u32)D_0029F280 += 2;
        reg_a0 = (u8 *)D_002555E0;
        reg_d0.h[0] = D_0029F2BA[0];
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F2B8[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)D_0028E080;
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
        reg_a2 = (u8 *)D_0028E084_as_u8_a;
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
