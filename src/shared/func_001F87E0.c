#include "common.h"

s32 func_00129280();
s32 func_00129320();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D580();
s32 func_0019C570();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F61B0();
s32 func_00201B80();
s32 func_00201E20();
s32 func_002026F0();
extern u8 D_00259870_as_u8_a[];
extern u8 D_002658B0[];
extern u8 D_002659B0[];
extern s8 D_0028E408;
extern Reg32 D_0028E484;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F87E0(void) {
    s64 temp_v0_10;
    s64 temp_v0_11;
    s64 temp_v0_3;
    s64 temp_v0_4;
    s64 temp_v0_5;
    s64 temp_v0_7;
    s64 temp_v0_8;
    s64 temp_v0_9;
    u16 temp_v0;
    if (((*(u8 *)((u8 *)(reg_a5) + (0x16))) != 0) && ((*(u16 *)((u8 *)(reg_a5) + (0x30))) != 0)) {
        (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x7FFF;
        (*(u16 *)((u8 *)(reg_a5) + (0x30))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a5) + (0x30))) == 0) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x1100;
        }
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] = 0xA3;
        (*(u8 *)((u8 *)(reg_a6) + (1))) &= reg_d0.b[0];
        func_001A9000();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_d0.b[0] ^= reg_d2.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
        if ((*(s16 *)((u8 *)(reg_a6) + (0x18))) < 0) {
            reg_d0.w = 0x213;
            func_001A91A0();
            func_0018D580();
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = D_002659B0;
            func_001F61B0();
            func_0014E290();
            return;
        }
        goto block_8;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
block_8:
    if (D_0028E8A0 == 0) {
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] -= (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
        func_00201B80();
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x7400;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x1400;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] += 0x7400;
        reg_tmp.w += D_0028E484.w;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_13;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_13:
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 0x10;
                if ((*(u16 *)((u8 *)(reg_a5) + (0x1E))) == 0x80) {
                    (*(u16 *)((u8 *)(reg_a6) + (0))) = 0xA001;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 1U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 2U;
                    (*(s16 *)((u8 *)(reg_a5) + (0x20))) = 4;
                    (*(u16 *)((u8 *)(reg_a5) + (0x22))) = 0xFFFD;
                    (*(s16 *)((u8 *)(reg_a5) + (0x26))) = 0x1060;
                    (*(s8 *)((u8 *)(reg_a5) + (0x28))) = 0x10;
                    (*(s16 *)((u8 *)(reg_a5) + (0x24))) = 0x606;
                }
            }
        }
        if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0x16))) >= 2) {
            reg_d1.w = 0;
            reg_d0.w = 0;
            reg_d0.b[0] = 0x28;
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x2D))) += 2;
            func_00201E20();
            (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) reg_d2.h[0];
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a5) + (0x2A)));
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_d1.h[0];
            temp_v0 = (*(u16 *)((u8 *)(reg_a5) + (0x32)));
            if ((s32) temp_v0 < 0x600) {
                (*(u16 *)((u8 *)(reg_a5) + (0x32))) = (u16) (temp_v0 + 0x40);
                (*(u16 *)((u8 *)(reg_a6) + (0x10))) += 0x40;
                (*(u16 *)((u8 *)(reg_a6) + (0x12))) -= 0x40;
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1D)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1C)));
                (*(u16 *)((u8 *)(reg_a5) + (0x1E))) += 0x10;
                if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) >= 0xF0) {
                    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0xF0U;
                    (*(u8 *)((u8 *)(reg_a5) + (0x16))) = 3U;
                }
            }
        }
        if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 3) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
            (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) = 0x10U;
                if ((D_0028E89C == 0) && ((s16) (*(u16 *)((u8 *)(reg_a6) + (2))) > 0x2000)) {
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x2E))) == reg_d0.b[0]) {
                        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                        reg_d0.h[0] += 0x7FFF + 0x7A01;
                        func_002026F0();
                        if (D_0028E408 != 0) {
                            reg_d1.h[0] = 0x80;
                        }
                        (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) reg_d1.b[0];
                    }
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x29)));
                    reg_d0.w = 0xFFFF0005;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d5.w = 0x02000000;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x2F))) != 0) {
                        reg_d1.h[0] -= 0x34;
                        reg_d7.h[0] = 4;
                        reg_a0 = D_00259870_as_u8_a;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129280();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129280();
                            reg_d1.b[0] += 4;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129280();
                            reg_d1.b[0] += 0x10;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    } else {
                        reg_d0.w = 0xFFFF0004;
                        reg_d1.h[0] -= 0x22;
                        reg_d7.h[0] = 3;
                        reg_a0 = D_00259870_as_u8_a;
                        do {
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129320();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129320();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129320();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129320();
                            reg_d1.b[0] += 2;
                            reg_d3.h[0] = reg_d1.h[0];
                            reg_d3.h[0] += 2;
                            reg_d3.h[0] &= 0xFC;
                            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a0) + (0)));
                            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                            reg_d3.w += reg_d5.w;
                            func_00129320();
                            reg_d1.b[0] += 0xC;
                        } while ((s16)(--reg_d7.h[0]) >= 0);
                    }
                    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x2F)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x2F))) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        (*(u8 *)((u8 *)(reg_a5) + (0x2F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2E)));
                        (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                    }
                }
            }
        }
        goto block_88;
    }
block_88:
    reg_a0 = D_002658B0;
    reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a0) + (6)));
    reg_d1.w += reg_tmp.w;
    reg_d1.h[1] += (*(u16 *)((u8 *)(reg_a5) + (0x32)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (8)));
    reg_d4.w = 0;
    reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C)));
    func_0019C570();
    reg_a0 = reg_a6;
    func_0014D220();
}
