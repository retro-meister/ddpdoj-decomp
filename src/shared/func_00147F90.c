#include "common.h"

s32 func_001480C0();
s32 func_00148110();
extern u16 D_0028DFD4;
extern u16 D_0028DFD8;
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029F1F0[];
extern u8 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00147F90(void) {
    reg_d1.h[0] = D_0028DFD8;
    reg_a0 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)D_0029D770;
    reg_a5 = (u8 *)D_0029F260;
    if (*(u16 *)(reg_a6 + 0x1A) != 0) goto block_1;
    reg_d1.h[0] = D_0028DFD4;
    reg_a0 = (u8 *)D_0029D710;
    reg_a2 = (u8 *)D_0029D750;
    reg_a5 = (u8 *)D_0029F1F0;
block_1:
    switch (*(u8 *)(reg_a2 + 1) & 0x10) {
    case 0:
        goto block_4;
    }
    *(u16 *)(reg_a0 + 0x16) = 9;
block_2:
    if ((s32)reg_d1.h[0] <= (s32)reg_d0.h[0]) goto block_3;
    if ((s32)reg_d0.h[0] >= (s32)*(u16 *)(reg_a0 + 2)) goto next_1;
    func_001480C0();
    return;
next_1:
    reg_d1.h[0] = reg_d0.h[0];
    func_00148110();
    func_001480C0();
    return;
block_3:
    *(u16 *)reg_a6 = 0;
    if (*(s16 *)reg_a0 < 0) return;
    func_00148110();
    return;
block_4:
    if (*(u16 *)(reg_a0 + 0x16) != 0) goto block_2;
    *(u16 *)reg_a0 = 0;
    func_001480C0();
}
