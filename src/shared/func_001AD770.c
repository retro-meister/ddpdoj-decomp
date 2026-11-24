#include "common.h"

extern s32 D_0026B920[];
extern u16 D_0026B938[];
extern u8 D_0026B950[];
extern u16 D_0026B990[];
extern u16 D_0026B9A0[];
extern u16 D_0026B9B0[];
extern u16 D_0026B9C0[];
extern u16 D_0026B9D0[];
extern s32 D_0026B9E0[];
extern u16 D_0026B9F8[];
extern u16 D_0026BA08[];
extern u8 D_0026BA20[];
extern u16 D_0026BA60[];
extern s8 D_0025F6D0[5][30];
extern u8 D_0028E290;
extern s32 D_0028E760;
extern s8 D_002BB060[5][30];
extern s8 D_002BB100[5][30];
extern u16 D_002BB198[];
extern u16 D_002BB1A8[];
extern u16 D_002BB1B8[];
extern u16 D_002BB1C8[];
extern u16 D_002BB1D8[];
extern u16 D_002BB1E8[];
extern u16 D_002BB1F8[];
extern s32 D_002BB210[];
extern s32 D_002BB250[];
extern u16 D_002BB268[];
extern u16 D_002BB278[];
extern u16 D_002BB288[];
extern u16 D_002BB298[];
extern u16 D_002BB2A8[];
extern u16 D_002BB2B8[];
extern u16 D_002BB2C8[];
extern s32 D_002BB2E0[];
extern s32 D_002BB320[];
extern u16 D_002BB338[];
extern u16 D_002BB348[];
extern u16 D_002BB358[];
extern u16 D_002BB368[];
extern u16 D_002BB378[];
extern u16 D_002BB388[];
extern u16 D_002BB398[];
extern s32 D_002BB3B0[];
extern s32 D_002BB3F0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001AD770(void) {
    s32 *dst;
    s32 *src;
    s32 i;
    s32 j;

    dst = D_002BB3F0;
    src = D_0026B920;
    reg_d0.w = 4;
    do {
        *dst = *src;
        src++;
        dst++;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    D_0028E760 = D_002BB3F0[0];
    reg_a0 = (u8 *) D_002BB338;
    reg_a1 = (u8 *) D_0026B938;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB3B0;
    reg_a1 = (u8 *)D_0026B950;
    reg_d0.w = 4;
    do {
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB358;
    reg_a1 = (u8 *) D_0026B990;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB378;
    reg_a1 = (u8 *) D_0026B9A0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB368;
    reg_a1 = (u8 *) D_0026B9B0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB348;
    reg_a1 = (u8 *) D_0026B9C0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB398;
    reg_a1 = (u8 *) D_0026B9D0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB388;
    reg_a1 = (u8 *) D_0026BA60;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    for (i = 0; i < 5; i++) {
        D_002BB2A8[i] = D_002BB378[i];
        D_002BB298[i] = D_002BB368[i];
        D_002BB2C8[i] = D_002BB398[i];
        D_002BB2B8[i] = D_002BB388[i];
        D_002BB288[i] = D_002BB358[i];
        D_002BB320[i] = D_002BB3F0[i];
        D_002BB268[i] = D_002BB338[i];
        D_002BB278[i] = D_002BB348[i];
        D_002BB1D8[i] = D_002BB378[i];
        D_002BB1C8[i] = D_002BB368[i];
        D_002BB1F8[i] = D_002BB398[i];
        D_002BB1E8[i] = D_002BB388[i];
        D_002BB1B8[i] = D_002BB358[i];
        D_002BB250[i] = D_002BB3F0[i];
        D_002BB198[i] = D_002BB338[i];
        D_002BB1A8[i] = D_002BB348[i];
    }
    for (i = 0; i < 15; i++) {
        D_002BB2E0[i] = D_002BB3B0[i];
        D_002BB210[i] = D_002BB3B0[i];
    }
    for (i = 0; i < 5; i++) {
        D_002BB320[i] = D_0026B9E0[i];
        D_002BB278[i] = 0;
        D_002BB2C8[i] = 0;
        D_002BB288[i] = 0x99;
        for (j = 0; j < 30; j++) {
            D_002BB100[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB100[i][j] = 0;
        }
        for (j = 0; j < 30; j++) {
            D_002BB060[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB060[i][j] = 0;
        }
    }
    reg_a0 = (u8 *) D_002BB2E0;
    reg_a1 = (u8 *)D_0026BA20;
    reg_d0.w = 4;
    do {
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
        *(s32 *) reg_a0 = *(s32 *) reg_a1;
        reg_a1 += 4;
        reg_a0 += 4;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB2A8;
    reg_a1 = (u8 *) D_0026B9F8;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB298;
    reg_a1 = (u8 *) D_0026BA08;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    if (D_0028E290 == 2) {
        for (i = 0; i < 5; i++) {
            D_002BB348[i] = 0;
            D_002BB398[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            D_002BB3F0[i] = D_002BB320[i];
            D_002BB358[i] = D_002BB288[i];
            D_002BB378[i] = D_002BB2A8[i];
            D_002BB368[i] = D_002BB298[i];
        }
        for (i = 0; i < 15; i++) {
            D_002BB3B0[i] = D_002BB2E0[i];
        }
    }
}
