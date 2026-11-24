#include "common.h"

s32 func_0020EC90();
extern u8 D_00269360[];
extern u8 D_00269380[];
extern u8 D_00269398[];
extern u8 D_002693A8[];
extern u16 D_0028DFE4;
extern u16 D_0028DFE8;
extern u8 D_0028E21C;
extern u8 D_0028E36C;
extern u8 D_0028E378;
extern u16 D_0028E3A0;
extern u16 D_0028E3A4;
extern u16 D_0028E3A8;
extern u16 D_0028E3AC;
extern u16 D_0028E3B0;
extern u16 D_0028E3E8;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u16 D_0028E7E4;
extern u16 D_0028E910;
extern u16 D_0028E914;
extern u16 D_0028E918;
extern u16 D_00299760[];
extern u16 D_0029976A[];
void func_0020EAB0(void) {
    u8 *tbl;

    func_0020EC90();
    if (D_0028E36C != 0) return;
    D_0028E21C = 1;
    if (D_0028E3E8 != 0) return;
    if (D_0028E3B0 != 0) {
        D_0028E3B0 -= 1;
        goto next_20;
    }
    if (D_0028E3A4 != 0) return;
    reg_d0.h[0] = D_00299760[0];
    if (D_0028E7E4 == 0) goto next_5;
    if (D_0028E3A8 == 0) return;
next_5:
    reg_d0.h[0] += D_0028DFE8;
    reg_d0.h[0] += D_0028DFE4;
    reg_d0.h[0] += D_0028DFE4;
    reg_d1.w = 0;
    tbl = D_00269360;
    if (D_0028E910 == 0) goto next_8;
    tbl = D_00269380;
    if (D_0028E3A0 == 0) return;
    reg_d1.h[0] += 0x28;
next_8:
    reg_d2.h[0] = D_0028E914;
    tbl += reg_d2.h[0] & ~1;
    reg_d1.h[0] += *(s16 *) (tbl + 0);
    if (D_0029976A[0] == 0) goto next_10;
    reg_d1.h[0] += *(s16 *) (tbl + 2);
next_10:
    reg_d2.h[0] = D_0028E5FC;
    reg_d2.h[0] |= D_0028E5F8;
    if (reg_d2.h[0] == 0) goto next_12;
    reg_d1.h[0] += 0x1E;
next_12:
    if (!((s32) reg_d1.h[0] > (s32) reg_d0.h[0])) goto next_15;
    if (D_0028E3AC == 0) return;
    D_0028E3AC -= 1;
    goto next_20;
next_15:
    tbl = D_00269398;
    if (D_0028E910 == 0) goto next_17;
    tbl = D_002693A8;
next_17:
    reg_d2.h[0] = (s32) D_0028E918 >> 1;
    reg_d2.h[0] = ((s16 *) tbl)[reg_d2.h[0]];
    if (!((s32) D_0028E3AC < (s32) reg_d2.h[0])) goto next_20;
    D_0028E3AC += 2;
next_20:
    D_0028E21C = 2;
    if (D_0028E378 == 0xFF) {
        D_0028E21C = 0;
    }
}
