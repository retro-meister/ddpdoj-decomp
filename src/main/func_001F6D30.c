#include "common.h"

extern s8 D_0028E408;

s32 func_00129320();
s32 func_0014E290();
s32 func_0018D580();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F61B0();
s32 func_001F7100();
s32 func_001F71A0();
s32 func_00201B80();
s32 func_002026F0();
extern u8 D_00265240[];
extern u8 D_0028DA18;
extern u8 D_0028DA1C;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F6D30(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        if ((*(s16 *)((u8 *)(reg_a6) + (2))) > 0x2800) {
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
                    reg_d0.w = 0x230;
                    func_001A91A0();
                    goto block_5;
                }
            } else {
                goto block_6;
            }
        } else {
block_5:
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0x8000;
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)D_00265240;
            func_001F61B0();
            func_0018D580();
            (*(u8 *)((u8 *)(reg_a6) + (0x3E))) = 1U;
            goto block_6;
        }
    } else {
block_6:
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    }
    reg_d0.w = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_tmp.w = (u32) (s16) reg_d0.h[0];
    reg_d0.w = reg_tmp.w;
    reg_d0.w += 0x4000;
    if ((s32) reg_d0.w < 0x2C01) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_11;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_11:
    func_00201B80();
    func_001F71A0();
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x25))) == 0) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x1F)));
            (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x1F))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x1E)));
                (*(u8 *)((u8 *)(reg_a5) + (0x25))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x24)));
                goto block_15;
            }
        } else {
block_15:
            reg_a1 = &D_0028DA18;
            if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                reg_a1 = &D_0028DA1C;
            }
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a1) + (2)));
            func_002026F0();
            if (D_0028E408 == 0) {
                (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) reg_d1.b[0];
                reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x27)));
                (*(u8 *)((u8 *)(reg_a5) + (0x27))) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    (*(u8 *)((u8 *)(reg_a5) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x26)));
                    reg_d1.w = 0;
                    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x21)));
                    reg_d0.w = 0xFFFE000B;
                    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_a1 = &D_0028DA18;
                    if ((*(u8 *)((u8 *)(reg_a5) + (0x16))) == 0) {
                        reg_a1 = &D_0028DA1C;
                    }
                    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
                    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
                    reg_d2.w += reg_tmp.w;
                    reg_d1.h[0] -= 0xA;
                    reg_d7.h[0] = 4;
                    reg_d4.w = 0;
                    reg_d3.w = 0;
                    do {
                        func_00129320();
                        reg_d1.b[0] += 5;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x23)));
                    (*(u8 *)((u8 *)(reg_a5) + (0x21))) += reg_d0.b[0];
                    (*(u8 *)((u8 *)(reg_a5) + (0x25))) -= 1;
                }
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
    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) == 0) {
        func_001F7100();
    }
}
