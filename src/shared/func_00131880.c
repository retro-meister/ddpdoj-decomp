#include "common.h"

s32 func_00125E80();
s32 func_00131700();
s32 func_001317D0();
s32 func_00131840();
s32 func_00132420();
s32 func_00134FE0();
s32 func_00135070();
s32 func_0013AFF0();
s32 func_0013B2E0();
s32 func_0013C300();
s32 func_0013C350();
s32 func_0013E7C0();
s32 func_0013E850();
s32 func_00171990();
s32 func_001719A0();
s32 func_001719B0();
s32 func_001719D0();
s32 func_001720E0();
s32 func_00172250();
s32 func_00172260();
s32 func_001A3020();
s32 func_001AD720();
s32 func_00237790();
s32 printf();
extern u16 D_00269840[];
extern u8 D_00273EC0[];
extern u8 D_00273EE0[];
extern u8 D_00273F00[];
extern u8 D_00273F20[];
extern u8 D_00273F40[];
extern u8 D_00273F60[];
extern u8 D_00273F80[];
extern u8 D_00273FA0[];
extern u8 D_00273FC0[];
extern u8 D_00273FE0[];
extern u8 D_00274000[];
extern u8 D_00274020[];
extern s16 D_0028DFBC_as_s16;
extern s16 D_0028DFC0_as_s16;
extern s16 D_0028DFC4_as_s16;
extern u8 D_0028E370;
extern s8 D_0028E408;
extern u16 D_0028E748;
extern u16 D_0028E750;
extern u16 D_0028E758;
extern u16 D_0028E75C;
extern s32 D_0028E764_as_s32;
extern s32 D_0028E768_as_s32;
extern s16 D_0028E854_as_s16;
extern s16 D_0028E958;
extern u8 D_0028E961;
extern s8 D_0028EC58;
extern u8 D_0028ED60;
extern s8 D_0028ED6C_as_s8;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u16 D_002B3150_as_u16_a[];
extern u16 D_002BF410_as_u16_a[];
extern u16 D_002BF450_as_u16_a[];
extern u8 D_002BF490[];
#ifdef DEATH_LABEL
s32 func_0013B920();
s32 func_0018DED0();
extern u8 D_00269920[];
extern u8 D_002698B0[];
extern u8 D_0028E290;
extern u16 D_0028E8C0;
extern u16 D_0028E8C4;
extern u16 death_D_00290434;
extern u16 death_D_00290438;
extern s8 death_D_00290568_as_s8;
#endif
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00131880(void) {
    s8 var_a0;
    u16 temp_a0_3;
    u16 temp_v1_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_v1;
    u8 temp_v1_2;

    temp_v1 = (*(u8 *)((u8 *)(reg_a5) + (3)));
    if (temp_v1 == 0) {
        func_00131700();
        return;
    }
    if (temp_v1 == 2) {
        func_001317D0();
        return;
    }
    func_00172260();
    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (7)));
    if (temp_a0 == 4) {
        func_001719B0();
        if (D_0028E408 == 0) {
            (*(u8 *)((u8 *)(reg_a5) + (3))) = 2U;
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a5) + (7)));
    if (temp_a0_2 == 3) {
        if ((D_0028ED7C == 2) && (D_0028ED60 == 0)) {
            func_00237790(temp_a0_2);
            (*(u8 *)((u8 *)(reg_a5) + (3))) = 2U;
            return;
        }
        printf(D_00273EC0, D_0028E768_as_s32);
        printf(D_00273EE0, (s32) D_0028E750);
        printf(D_00273F00, (s32) D_0028E75C);
        printf(D_00273F20, D_0028E764_as_s32);
        printf(D_00273F40, (s32) D_0028E748);
        printf(D_00273F60, (s32) D_0028E758);
        D_0028E370 = 0;
        func_00135070();
        (*(s8 *)((u8 *)(reg_a5) + (7))) = 0x1E;
        goto block_after;
    }
    if (temp_a0_2 == 0x1E) {
        if (D_0028EC58 != 0) {
            if (D_0028ED7C == 1) {
                D_0028ED6C_as_s8 = 1;
            }
            D_0028DFBC_as_s16 = 0;
            D_0028E961 &= 0xFC;
        }
        if (D_0028E370 != 0) {
            printf(D_00273F80, D_0028E768_as_s32);
            printf(D_00273FA0, (s32) D_0028E750);
            printf(D_00273FC0, (s32) D_0028E75C);
            printf(D_00273FE0, D_0028E764_as_s32);
            printf(D_00274000, (s32) D_0028E748);
            printf(D_00274020, (s32) D_0028E758);
            (*(s8 *)((u8 *)(reg_a5) + (7))) = 4;
        }
    }
block_after:
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) == 2) {
        if ((D_0028ED7C == 2) && (D_0028ED60 == 0)) {
            (*(u8 *)((u8 *)(reg_a5) + (7))) = 3U;
            return;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (4)));
        func_00134FE0();
        func_00125E80();
        D_0028E958 = 0;
        func_00172250();
        D_0028E370 = 0;
        func_001719A0();
        func_001AD720();
        D_0028DFC0_as_s16 = 0;
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 3U;
        goto block_25;
    }
block_25:
    temp_v1_2 = (*(u8 *)((u8 *)(reg_a5) + (7)));
#ifdef DEATH_LABEL
    if (temp_v1_2 == 0x16) {
        reg_a6 = D_002BF490;
        func_00132420();
        if ((D_0028E290 == 2) && (death_D_00290568_as_s8 == 1)) {
            death_D_00290568_as_s8 = 0;
            D_0028E8C4 = death_D_00290434;
            D_0028E8C0 = death_D_00290438;
            if ((D_0028ED80 != 0) || (D_0028ED7C == 2)) {
                reg_a0 = (u8 *)D_00269920;
            } else {
                reg_a0 = (u8 *)D_002698B0;
            }
            (*(u8 *)((u8 *)(reg_a5) + (7))) = 0xB;
            func_0013B920();
            (*(u16 *)((u8 *)(reg_a5) + (8))) = reg_d0.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0xA))) = reg_d0.h[0];
            reg_d1.w = 0;
            func_0018DED0();
        }
        return;
    }
#endif
    if (temp_v1_2 == 0x15) {
        reg_a6 = D_002BF490;
        func_00132420();
        return;
    }
    if (temp_v1_2 == 0xB) {
        reg_a6 = D_002BF490;
        func_00132420();
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        func_0013C350();
        if (D_0028E408 == 0) {
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a5) + (8)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
            if (D_0028ED80 != 0) {
                func_00131840();
                (*(u8 *)((u8 *)(reg_a5) + (3))) = 2U;
                return;
            }
            func_0013C300();
            func_0013E7C0();
            func_0013E850();
            D_0028E854_as_s16 = 0;
            D_0028DFC4_as_s16 = 0;
            D_0028E961 &= 0xF7;
            (*(u8 *)((u8 *)(reg_a5) + (7))) = 2U;
            return;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) == 1) {
        reg_a6 = D_002BF490;
        func_00132420();
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) == 0xA) {
        reg_a6 = D_002BF490;
        func_00132420();
        (*(u8 *)((u8 *)(reg_a5) + (6))) -= 1;
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            func_00171990();
            reg_a0 = (u8 *)(D_00269840);
            func_0013B2E0();
            (*(u8 *)((u8 *)(reg_a5) + (7))) = 1U;
            reg_a0 = (u8 *)(D_002B3150_as_u16_a);
            reg_a1 = (u8 *)(D_002BF450_as_u16_a);
            reg_a0 += 0x5C0;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 += 2;
            *(u16 *)reg_a1 = *(u16 *)reg_a0;
            reg_a0 = (u8 *)(D_002BF450_as_u16_a);
            reg_a1 = (u8 *)(D_002BF410_as_u16_a);
            reg_d7.w = 0x1F;
            do {
                temp_a0_3 = *(u16 *)reg_a0;
                reg_d0.h[0] = temp_a0_3;
                reg_a0 += 2;
                reg_d1.h[0] = 0x10;
                func_0013AFF0();
                *(u16 *)reg_a1 = reg_d0.h[0];
                reg_a1 += 2;
            } while ((s16)(reg_d7.h[0]--) >= 0);
            reg_a0 = (u8 *)(D_002BF410_as_u16_a);
            reg_d0.h[0] = 0x17;
            func_001A3020();
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) == 0) {
        func_001720E0();
        if (D_0028E408 == 0) {
            (*(u8 *)((u8 *)(reg_a5) + (7))) = 0xAU;
        }
    }
    func_001719D0();
}
