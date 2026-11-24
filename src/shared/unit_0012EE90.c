#include "common.h"

s32 func_0012E3D0();
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u8 *reg_a6;

void func_0012EE90(void) {
    func_0012E3D0();
    reg_tmp.w = 0x19D;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = D_0028E3F0;
    reg_d0.h[0] >>= 2;
    reg_d0.h[0] &= 3;
    do {
        reg_tmp.w = 1;
        D_0028E484.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
        D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xC)));
        D_0028E484.w = (s32) ((s32) D_0028E484.w + reg_tmp.w);
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) D_0028E484.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = D_0028E484.h[0];
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_tmp.w = 0x1B;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x30))) = 0x20;
}

void func_0012EF80(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 0x1410;
    reg_tmp.w = 0x1C;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x283;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
}

void func_0012F020(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
    reg_tmp.w = 0x1D;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x283;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
}

s32 func_0012DA30();
s32 func_0012E350();

void func_0012F0C0() {
    func_0012E350();
    reg_tmp.w = 0x220;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    reg_tmp.w = 0x1E;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x36)));
    func_0012DA30();
    reg_d2.w = (u32) ((s32) reg_d2.w >> 3);
    reg_d3.w = (u32) ((s32) reg_d3.w >> 3);
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d3.h[0];
}

void func_0012F1B0() {
    func_0012E350();
    reg_tmp.w = 0x220;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    reg_tmp.w = 0x1F;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x36)));
    func_0012DA30();
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 3);
    reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 3);
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d3.h[0];
}

s32 func_0012E350();                            /* extern */

void func_0012F2A0(void) {
    func_0012E350();
    reg_tmp.w = 0x1E6;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    reg_tmp.w = 0x20;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}

void func_0012F330(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x1B4;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x14;
    (*(s16 *)((u8 *)(reg_a6) + (0x2E))) = 0x101;
    reg_tmp.w = 0x21;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}

void func_0012F3B0(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
    reg_tmp.w = 0x22;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x283;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
}

s32 func_0012E3D0();                            /* extern */

void func_0012F450(void) {
    func_0012E3D0();
    reg_tmp.w = 0x23;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0x1A6;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 0x404;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
}

extern u16 D_0024EC80[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0012F4C0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x210;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a1 = (u8 *)(D_0024EC80);
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_tmp.h[0];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) -= 4;
}

#ifdef DEATH_LABEL
void death_func_0012E5B0(void) {
    *(u16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x24;
    *(u16 *)(reg_a6 + 0x22) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_tmp.h[0];
    *(u8 *)(reg_a6 + 1) &= 0xFE;
    reg_tmp.w = 0x283;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    *(u16 *)(reg_a6 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 8) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0xE) = 0;
    *(u8 *)(reg_a6 + 0x1C) = 0x1A;
}
#endif

s32 func_0013B350();
s32 func_0015B930();
extern u8 D_00269800[];
extern u32 D_0028E964;
extern s16 D_0028E968_as_s16;
extern s16 D_0028E96C_as_s16;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_0012F6A0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;

    D_0028E968_as_s16 = 0xF0;
    save_d0 = reg_d0.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a0 = (u8 *)D_00269800;
    save_d1 = reg_d1.w;
    D_0028E964 = 0;
    D_0028E96C_as_s16 = 0;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    func_0013B350();
    D_0028E964 = reg_d0.w;
    func_0015B930();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

void func_0012F9F0(void);
void func_0013BE50(void);
void func_0013C300(void);
void func_0013C350(void);
void func_0018DD80(void);
extern u8 D_00269820[];
extern s8 D_0028E408;
extern u16 D_0028E968;
extern u16 D_0028E96C;

void func_0012F7D0(void) {
    u32 sd0, sd1, sd2, sd3, sd4, sd5, sd6, sd7;
    u8 *sa0, *sa1, *sa2, *sa3, *sa4, *sa5, *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    if (D_0028E96C == 0) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            D_0028E96C = 1;
            func_0018DD80();
        }
    }
    if (D_0028E96C == 1) {
        D_0028E968 -= 1;
        if (D_0028E968 == 0) {
            reg_a0 = (u8 *)D_00269820;
            func_0013BE50();
            D_0028E964 = reg_d0.w;
            D_0028E96C = 2;
        }
    }
    if (D_0028E96C == 2) {
        reg_d0.w = D_0028E964;
        func_0013C350();
        if (D_0028E408 == 0) {
            func_0013C300();
            goto block_1;
        }
    }
    func_0012F9F0();
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    D_0028E408 = 1;
    return;
block_1:
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    D_0028E408 = 0;
}
