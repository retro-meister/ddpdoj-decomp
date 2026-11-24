#include "common.h"

extern s8 D_0028E408;

s32 func_001AD580();
s32 printf();
extern s8 D_0025F6B0[];
extern u8 D_0027D910[];
extern u8 D_0027D930[];
extern u8 D_0027D948[];
extern u8 D_0028E290;
extern Reg32 D_0028E480;
extern s32 D_0028EAFC;
extern u8 D_0028ED7C;
extern u8 D_002BB060[5][30];
extern u8 D_002BB100[5][30];
extern u8 D_002BB352[];
extern u8 D_002BB362[];
extern u8 D_002BB372[];
extern u8 D_002BB382[];
extern u8 D_002BB392[];
extern u8 D_002BB3A2[];
extern u8 D_002BB3EC[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001ACF80(void) {
    u8 *save_a5;
    u8 *save_a6;
    s32 i;
    s32 j;
    u8 *p;

    save_a5 = reg_a5;
    save_a6 = reg_a6;
    D_0028E408 = 0;
    if (D_0028ED7C == 2) {
        printf(D_0027D910);
        D_0028E408 = 1;
        goto block_rts;
    }
    func_001AD580();
    if ((s16) reg_d1.h[0] < 0) {
        D_0028E408 = 1;
        goto block_rts;
    }
    D_0028E408 = 0;
    if (D_0028E290 == 2) {
        D_0028EAFC = 4 - reg_d1.w;
        printf(D_0027D930, D_0028EAFC);
        if (D_0028EAFC != 4) {
            for (i = 4; D_0028EAFC < i; i--) {
                for (j = 0; j < 30; j++) {
                    D_002BB060[i][j] = D_002BB060[i - 1][j];
                }
            }
        }
    } else {
        D_0028EAFC = 4 - reg_d1.w;
        printf(D_0027D948, D_0028EAFC);
        if (D_0028EAFC != 4) {
            for (i = 4; D_0028EAFC < i; i--) {
                for (j = 0; j < 30; j++) {
                    D_002BB100[i][j] = D_002BB100[i - 1][j];
                }
            }
        }
        for (j = 0; j < 30; j++) {
            D_002BB100[D_0028EAFC][j] = D_0025F6B0[j];
        }
    }
    reg_d2.w = reg_d1.w;
    if (reg_d2.w == 0) goto next_60;
    reg_d1.h[0] -= 1;
loop_50:
    reg_a2 -= 4;
    *(u16 *)(reg_a2 + 0) = *(u16 *)(reg_a2 - 4);
    *(u16 *)(reg_a2 + 2) = *(u16 *)(reg_a2 - 2);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a5 - 2);
    if ((s16) --reg_d1.h[0] >= 0) goto loop_50;
next_60:
    reg_a2 -= 4;
    *(u32 *)reg_a2 = reg_d7.w;
    reg_a5 -= 2;
    *(u16 *)reg_a5 = reg_d5.h[0];
    reg_a1 = (u8 *)D_002BB3EC;
    reg_d1.w = reg_d2.w;
    if (reg_d1.w == 0) goto next_80;
    reg_d1.h[0] -= 1;
loop_70:
    p = reg_a1;
    *(u32 *)(p - 4) = *(u32 *)(p - 0x10);
    *(u32 *)(p - 8) = *(u32 *)(p - 0x14);
    *(u32 *)(p - 0xC) = *(u32 *)(p - 0x18);
    reg_a1 = p - 0xC;
    if ((s16) --reg_d1.h[0] >= 0) goto loop_70;
next_80:
    reg_a1 -= 0xC;
    reg_tmp.w = (u32) reg_a1;
    *(u16 *)(reg_a4 + 0xC) = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xE) = reg_tmp.h[0];
    reg_a1 = (u8 *)D_002BB3A2;
    reg_a2 = (u8 *)D_002BB392;
    reg_a3 = (u8 *)D_002BB382;
    reg_a0 = (u8 *)D_002BB372;
    reg_a5 = (u8 *)D_002BB362;
    reg_a6 = (u8 *)D_002BB352;
    reg_d3.h[0] = reg_d2.h[0];
    D_0028E480.w = reg_d2.h[0];
    D_0028E480.w -= 1;
    reg_d2.h[0] = D_0028E480.h[0];
    if (D_0028E480.h[1] != 0) goto next_98;
loop_90:
    reg_a1 -= 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a1 - 2);
    reg_a2 -= 2;
    *(u16 *)reg_a2 = *(u16 *)(reg_a2 - 2);
    reg_a3 -= 2;
    *(u16 *)reg_a3 = *(u16 *)(reg_a3 - 2);
    reg_a0 -= 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a0 - 2);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a5 - 2);
    reg_a6 -= 2;
    *(u16 *)reg_a6 = *(u16 *)(reg_a6 - 2);
    if ((s16) --reg_d2.h[0] >= 0) goto loop_90;
next_98:
    reg_a1 -= 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a4 + 0);
    reg_a2 -= 2;
    *(u16 *)reg_a2 = *(u16 *)(reg_a4 + 2);
    reg_a3 -= 2;
    *(u16 *)reg_a3 = *(u16 *)(reg_a4 + 4);
    reg_a0 -= 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a4 + 6);
    reg_a5 -= 2;
    *(u16 *)reg_a5 = *(u16 *)(reg_a4 + 8);
    reg_a6 -= 2;
    *(u16 *)reg_a6 = *(u16 *)(reg_a4 + 0xA);
block_rts:
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}
