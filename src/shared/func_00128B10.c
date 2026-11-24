#include "common.h"

extern s8 D_0028E408;

s32 func_00128F70();
extern u16 D_0024E7D0[];
extern u32 D_0028DEA4;
extern u32 D_0028DEA8;
extern u16 *D_0028DEB0;
extern u8 *D_0028DEB4;
extern u16 D_0028DFFC;
extern u8 D_0028E2E4;
extern u16 D_0028E7F0;
extern u16 D_0028E89C;
extern u16 D_0028E8A0;
extern u8 D_002962E0[];
extern u16 D_00299768[];
extern u16 D_0029976A[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u16 D_0029CEA0[];
#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00128B10(void) {
    s16 hi;

#ifdef DEATH_LABEL
    if ((D_0028E3C0 == 0) && (D_0028E2E4 != 0)) {
        return;
    }
#else
    if (D_0028E2E4 != 0) {
        return;
    }
#endif
    D_0028DEA4 = reg_d7.w;
    D_0028DEB4 = reg_a0;
    D_0028DEB0 = (u16 *) reg_a1;
    reg_d7.h[0] = D_0028E89C;
    reg_d7.h[0] += D_0028E8A0;
    reg_d7.h[0] += D_0029CEA0[0];
    if (reg_d7.h[0] != 0) {
        goto next_3;
    }
next_1:
    reg_a0 = (u8 *)D_002962E0;
    reg_d7.w = MAIN_OR_DEATH_LABEL(0xD, 0x45);
    if (D_00299768[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x15, 0x6D);
    if (D_0029976A[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x1F, 0x9F);
    if (D_0029976C[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x25, 0xBD);
    if (D_0029976E[0] == 0) {
        goto loop_2;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x29, 0xD1);
loop_2:
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if (*(u16 *) reg_a0 == 0) {
        goto next_5;
    }
    reg_a0 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_2;
    }
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4;
    reg_a1 = (u8 *) D_0028DEB0;
    D_0028E408 = 1;
    return;
next_3:
    if (0 <= (s64) (s16) D_0029CEA0[0]) {
        goto next_4;
    }
    if (*(u8 *) D_0029CEA0 & 1) {
        goto next_1;
    }
next_4:
    reg_d7.w = D_0028DEA4;
    reg_a0 = (u8 *)D_0028DEB4;
    reg_a1 = (u8 *) D_0028DEB0;
    D_0028E408 = 0;
    return;
next_5:
    D_0028DEA8 = reg_d0.w;
    hi = reg_d0.h[1];
    reg_d0.h[0] &= 0x3F;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *) D_0024E7D0;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *) reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) (reg_a0 + 0xC) = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d7.h[0] += hi;
    reg_d7.h[0] += D_0028E7F0;
    reg_d7.h[0] += D_0028DFFC;
#ifdef DEATH_LABEL
    if ((death_D_0029085C == 2) && (reg_d7.h[0] > death_D_00290858)) {
        reg_d7.h[0] = death_D_00290858;
    }
#endif
    reg_d1.b[0] += reg_d1.b[0];
    reg_d1.b[0] += reg_d1.b[0];
    *(u8 *) (reg_a0 + 0xB) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0xA) = reg_d1.b[0];
    *(u8 *) (reg_a0 + 0x2B) = reg_d7.b[0];
    *(u8 *) (reg_a0 + 0x2A) = reg_d1.b[0];
    reg_d1.b[0] >>= 2;
    func_00128F70();
}
