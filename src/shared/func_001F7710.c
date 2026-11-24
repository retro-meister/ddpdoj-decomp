#include "common.h"

s32 func_00129370();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D580();
s32 func_0019C470();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F61B0();
s32 func_001F71A0();
s32 func_00201B80();
s32 func_002026F0();
extern u8 D_00265550[];
extern u8 D_00265570[];
extern u8 D_0028DA20;
extern u8 D_0028DA24;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F7710(void) {
    u32 temp_a0_3;
    u8 var_a0;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        if ((*(s16 *)((u8 *)(reg_a6) + (2))) < 0x2801) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) == 0) {
                goto block_4;
            }
            goto block_7;
        }
block_4:
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
                reg_d0.w = 0x280;
                func_001A91A0();
block_7:
                (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_a1 = (u8 *)D_00265570;
                func_001F61B0();
                func_0018D580();
                (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 1U;
                goto block_8;
            }
        } else {
            goto block_8;
        }
    } else {
block_8:
        var_a0 = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = var_a0;
    }
    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x1C01) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_13;
    }
    var_a0 = 1;
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_13:
    if (D_0028E8A0 == 0) {
        func_00201B80();
        func_001F71A0();
        if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0) {
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                    goto block_18;
                }
            } else {
block_18:
                reg_a1 = &D_0028DA20;
                if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                    reg_a1 = &D_0028DA24;
                }
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0)));
                reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (2)));
                func_002026F0();
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) reg_d1.b[0];
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                    reg_d0.w = 0xFFFF000B;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_a1 = &D_0028DA20;
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                        reg_a1 = &D_0028DA24;
                    }
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 9;
                    reg_d7.h[0] = 6;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        func_00129370();
                        reg_d1.b[0] += 3;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) += reg_d0.b[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                }
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x1B))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1A)));
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) += 4;
            (*(u16 *)((u8 *)(reg_a5) + (0x1C))) &= 0x1F;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        reg_a0 = (u8 *)D_00265550;
        reg_a0 += (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        temp_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d1.h[0] = temp_a0_3;
        reg_d1.w += 0xEE00EC00;
        reg_d3.h[0] = 0x12A0;
        reg_d4.w = 0;
        reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1C)));
        func_0019C470();
        reg_a0 = reg_a6;
        func_0014D220();
    }
}
