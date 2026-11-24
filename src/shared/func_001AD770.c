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
extern s8 D_002BB060_as_s8_a5_a30[5][30];
extern s8 D_002BB100_as_s8_a5_a30[5][30];
extern u16 D_002BB198_as_u16_a[];
extern u16 D_002BB1A8_as_u16_a[];
extern u16 D_002BB1B8_as_u16_a[];
extern u16 D_002BB1C8_as_u16_a[];
extern u16 D_002BB1D8_as_u16_a[];
extern u16 D_002BB1E8_as_u16_a[];
extern u16 D_002BB1F8_as_u16_a[];
extern s32 D_002BB210_as_s32_a[];
extern s32 D_002BB250_as_s32_a[];
extern u16 D_002BB268_as_u16_a[];
extern u16 D_002BB278_as_u16_a[];
extern u16 D_002BB288_as_u16_a[];
extern u16 D_002BB298_as_u16_a[];
extern u16 D_002BB2A8_as_u16_a[];
extern u16 D_002BB2B8_as_u16_a[];
extern u16 D_002BB2C8_as_u16_a[];
extern s32 D_002BB2E0_as_s32_a[];
extern s32 D_002BB320_as_s32_a[];
extern u16 D_002BB338_as_u16_a[];
extern u16 D_002BB348_as_u16_a[];
extern u16 D_002BB358_as_u16_a[];
extern u16 D_002BB368_as_u16_a[];
extern u16 D_002BB378_as_u16_a[];
extern u16 D_002BB388_as_u16_a[];
extern u16 D_002BB398_as_u16_a[];
extern s32 D_002BB3B0_as_s32_a[];
extern s32 D_002BB3F0_as_s32_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001AD770(void) {
    s32 *dst;
    s32 *src;
    s32 i;
    s32 j;

    dst = D_002BB3F0_as_s32_a;
    src = D_0026B920;
    reg_d0.w = 4;
    do {
        *dst = *src;
        src++;
        dst++;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    D_0028E760 = D_002BB3F0_as_s32_a[0];
    reg_a0 = (u8 *) D_002BB338_as_u16_a;
    reg_a1 = (u8 *) D_0026B938;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB3B0_as_s32_a;
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
    reg_a0 = (u8 *) D_002BB358_as_u16_a;
    reg_a1 = (u8 *) D_0026B990;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB378_as_u16_a;
    reg_a1 = (u8 *) D_0026B9A0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB368_as_u16_a;
    reg_a1 = (u8 *) D_0026B9B0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB348_as_u16_a;
    reg_a1 = (u8 *) D_0026B9C0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB398_as_u16_a;
    reg_a1 = (u8 *) D_0026B9D0;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB388_as_u16_a;
    reg_a1 = (u8 *) D_0026BA60;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    for (i = 0; i < 5; i++) {
        D_002BB2A8_as_u16_a[i] = D_002BB378_as_u16_a[i];
        D_002BB298_as_u16_a[i] = D_002BB368_as_u16_a[i];
        D_002BB2C8_as_u16_a[i] = D_002BB398_as_u16_a[i];
        D_002BB2B8_as_u16_a[i] = D_002BB388_as_u16_a[i];
        D_002BB288_as_u16_a[i] = D_002BB358_as_u16_a[i];
        D_002BB320_as_s32_a[i] = D_002BB3F0_as_s32_a[i];
        D_002BB268_as_u16_a[i] = D_002BB338_as_u16_a[i];
        D_002BB278_as_u16_a[i] = D_002BB348_as_u16_a[i];
        D_002BB1D8_as_u16_a[i] = D_002BB378_as_u16_a[i];
        D_002BB1C8_as_u16_a[i] = D_002BB368_as_u16_a[i];
        D_002BB1F8_as_u16_a[i] = D_002BB398_as_u16_a[i];
        D_002BB1E8_as_u16_a[i] = D_002BB388_as_u16_a[i];
        D_002BB1B8_as_u16_a[i] = D_002BB358_as_u16_a[i];
        D_002BB250_as_s32_a[i] = D_002BB3F0_as_s32_a[i];
        D_002BB198_as_u16_a[i] = D_002BB338_as_u16_a[i];
        D_002BB1A8_as_u16_a[i] = D_002BB348_as_u16_a[i];
    }
    for (i = 0; i < 15; i++) {
        D_002BB2E0_as_s32_a[i] = D_002BB3B0_as_s32_a[i];
        D_002BB210_as_s32_a[i] = D_002BB3B0_as_s32_a[i];
    }
    for (i = 0; i < 5; i++) {
        D_002BB320_as_s32_a[i] = D_0026B9E0[i];
        D_002BB278_as_u16_a[i] = 0;
        D_002BB2C8_as_u16_a[i] = 0;
        D_002BB288_as_u16_a[i] = 0x99;
        for (j = 0; j < 30; j++) {
            D_002BB100_as_s8_a5_a30[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB100_as_s8_a5_a30[i][j] = 0;
        }
        for (j = 0; j < 30; j++) {
            D_002BB060_as_s8_a5_a30[i][j] = D_0025F6D0[i][j];
        }
        for (j = 23; j < 30; j++) {
            D_002BB060_as_s8_a5_a30[i][j] = 0;
        }
    }
    reg_a0 = (u8 *) D_002BB2E0_as_s32_a;
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
    reg_a0 = (u8 *) D_002BB2A8_as_u16_a;
    reg_a1 = (u8 *) D_0026B9F8;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    reg_a0 = (u8 *) D_002BB298_as_u16_a;
    reg_a1 = (u8 *) D_0026BA08;
    reg_d0.w = 4;
    do {
        *(u16 *) reg_a0 = *(u16 *) reg_a1;
        reg_a1 += 2;
        reg_a0 += 2;
    } while ((s16) (--reg_d0.h[0]) >= 0);
    if (D_0028E290 == 2) {
        for (i = 0; i < 5; i++) {
            D_002BB348_as_u16_a[i] = 0;
            D_002BB398_as_u16_a[i] = 0;
        }
        for (i = 0; i < 5; i++) {
            D_002BB3F0_as_s32_a[i] = D_002BB320_as_s32_a[i];
            D_002BB358_as_u16_a[i] = D_002BB288_as_u16_a[i];
            D_002BB378_as_u16_a[i] = D_002BB2A8_as_u16_a[i];
            D_002BB368_as_u16_a[i] = D_002BB298_as_u16_a[i];
        }
        for (i = 0; i < 15; i++) {
            D_002BB3B0_as_s32_a[i] = D_002BB2E0_as_s32_a[i];
        }
    }
}
