#include "common.h"

extern s8 D_0028E408;

s32 func_00129280();
s32 func_002010A0();
s32 func_00202140();
extern u16 D_00259770[];
extern u16 D_0028E47C;
extern u16 D_0028E47E;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BF730(void) {
    u8 t1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        t1 = *(u8 *)(reg_a4 + 9);
        reg_d7.b[0] = t1;
        if ((s8)(t1) < 0) {
            *(u8 *)(reg_a4 + 8) += reg_d7.b[0];
            if (0 >= (s8) *(u8 *)(reg_a4 + 8)) {
                *(u8 *)(reg_a4 + 9) *= -1;
            }
        } else {
            *(u8 *)(reg_a4 + 8) += reg_d7.b[0];
            if (0 <= (s64)*(s8 *)(reg_a4 + 8)) {
                *(u8 *)(reg_a4 + 9) *= -1;
            }
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d0.h[0] += 0x800;
        func_00202140();
        if (D_0028E408 == 0) {
            reg_d1.b[0] += *(u8 *)(reg_a4 + 8);
            reg_d5.w = 0x08000100;
            if (*(s8 *)(reg_a4 + 5) < 0) {
                reg_d5.w = 0x07FFFF00;
            }
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d1.h[0] += reg_d1.h[0];
            reg_d4.w = 0;
            reg_d1.h[0] += reg_d1.h[0];
            func_002010A0();
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.w = 0x80013;
            reg_a0 = (u8 *)(D_00259770);
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&D_0028E47C;
            reg_d3.w += reg_d5.w;
            func_00129280();
            reg_d1.b[0] += 0xC;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&D_0028E47C;
            reg_d3.w += reg_d5.w;
            func_00129280();
            reg_d1.b[0] -= 0x18;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] &= 0x3F;
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d3.w = *(u32 *)&D_0028E47C;
            reg_d3.w += reg_d5.w;
            func_00129280();
            if (D_0028E910 != 0) {
                reg_d1.b[0] -= 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&D_0028E47C;
                reg_d3.w += reg_d5.w;
                func_00129280();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&D_0028E47C;
                reg_d3.w += reg_d5.w;
                func_00129280();
                reg_d1.b[0] += 8;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&D_0028E47C;
                reg_d3.w += reg_d5.w;
                func_00129280();
                reg_d1.b[0] += 0x10;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] += reg_d3.h[0];
                reg_d3.h[0] += reg_d3.h[0];
                D_0028E47E = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                D_0028E47C = ((((u16)reg_d3.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u16)reg_d3.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w = *(u32 *)&D_0028E47C;
                reg_d3.w += reg_d5.w;
                func_00129280();
            }
        }
        *(u16 *)(reg_a4 + 6) -= 1;
        if (*(u16 *)(reg_a4 + 6) == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}
