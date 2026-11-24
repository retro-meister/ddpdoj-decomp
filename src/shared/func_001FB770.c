#include "common.h"

extern s8 D_0028E408;

s32 func_00129370();
s32 func_00129410();
s32 func_001FAD00();
s32 func_001FB6C0();
s32 func_00202730();
extern u16 D_00259870[];
extern u16 D_00259970[];
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001FB770(void) {
    u16 temp_a1;

    if ((*(u16 *)((u8 *)(reg_a6) + (0x88))) == 0) {
        reg_d0.w = 0;
        func_001FAD00();
        (*(u16 *)((u8 *)(reg_a6) + (0x88))) = 1U;
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0x124;
        (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x120;
        (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x80U;
        (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x100U;
        if ((*(u8 *)((u8 *)(reg_a6) + (0x9E))) != 0) {
            (*(u16 *)((u8 *)(reg_a4) + (6))) = 0x140U;
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0x112;
        }
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
    (*(u8 *)((u8 *)(reg_a4) + (1))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (*(u8 *)((u8 *)(reg_a4) + (0)));
        if (D_0028E89C == 0) {
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
            D_0028E484.w = 0;
            reg_tmp.w = 0;
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (4)));
            D_0028E484.h[0] = 0xE;
            reg_tmp.w += D_0028E484.w;
            (*(u16 *)((u8 *)(reg_a4) + (4))) += 0xE;
            if (reg_tmp.h[1] == 0) {
                reg_d0.w = 0xFFFF000B;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d1.b[0] -= 0x79;
                reg_d7.h[0] = 0x16;
                reg_a0 = (u8 *)(D_00259970);
                reg_d4.w = 0;
                reg_d3.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                    func_00129370();
                    reg_d1.b[0] += 0xB;
                } while ((s16)(--reg_d7.h[0]) >= 0);
            }
        }
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (*(u8 *)((u8 *)(reg_a4) + (2)));
        if (D_0028E89C == 0) {
            func_00202730();
            if (D_0028E408 == 0) {
                reg_d0.w = 0x30004;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0;
                reg_d2.h[0] = temp_a1;
                reg_a0 = (u8 *)(D_00259870);
                reg_d7.b[0] = reg_d1.b[0];
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d4.w = 0;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                func_00129410();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                func_00129410();
                reg_d1.b[0] += 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                func_00129410();
                reg_d1.b[0] = reg_d7.b[0];
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                func_00129410();
                reg_d1.b[0] -= 6;
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                func_00129410();
            }
        }
    }
    (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a4) + (6))) == 0) {
        func_001FB6C0();
        reg_d0.w = 1;
        func_001FAD00();
    }
}
