#include "common.h"

extern s8 D_0028E408;

s32 func_00128A20();
s32 func_00202140();
extern u16 D_00259970[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00155920(void) {
    u16 temp_a0;
    if ((*(u8 *)((u8 *)(reg_a6) + (0xD9))) == 0) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (2)));
        if ((s16)(temp_a0) > 0x1000) {
            reg_d0.h[0] = temp_a0;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.h[0] += 0x400;
            func_00202140();
            if (D_0028E408 == 0) {
                reg_d0.w = 0x40004;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d5.w = 0x04000000;
                reg_d4.w = 0;
                reg_d7.b[0] = reg_d1.b[0];
                reg_a0 = (u8 *)(D_00259970);
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] += 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
                reg_d1.b[0] -= 2;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] &= 0x3F;
                reg_d3.h[0] *= 4;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                reg_d3.w += reg_d5.w;
                func_00128A20();
            }
        }
    }
}
