#include "common.h"

void func_0013E260(void);
void func_0013E2E0(void);
void func_0013E8E0(void);
void func_0013E970(void);
extern u8 D_0028C608[];
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern s16 D_0028E070_as_s16;
extern s16 D_0028E074_as_s16;
extern u8 D_0028E2C4;
extern s16 D_0029CD80_as_s16_a[];
extern s16 D_0029CD8C_as_s16_a[];
extern s16 D_0029CD90_as_s16_a[];
extern s16 D_0029CD9C_as_s16_a[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F1F1[];
extern u8 D_0029F260_as_u8_a[];
extern u8 D_0029F261[];
extern u16 D_006E5BF4[];
extern u16 D_006E5BF6[];
extern u16 D_006E5C0E[];
extern u16 D_006E5C10[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00141300(void) {
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u32 sd0;
    u32 v1;
    u32 v2;
    u32 sd1;
    u32 sd2;
    u32 sd3;
    u32 sd4;
    u32 sd5;
    u32 sd6;
    u32 sd7;
    u8 *sa6;

    if (reg_d6.h[0] == 0 || D_0028E2C4 != 0) {
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
        reg_d5.h[0] = *(u16 *)(sa6 + 0x5A);
        reg_a0 = (u8 *)D_0028C608;
        reg_d5.h[0] -= 2;
        reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + (!(reg_d5.h[0] & 1) ? 1 : -1));
        reg_d5.b[0] *= 2;
        if (D_006E5BF4[0] == 6) {
            *(u8 *)(sa6 + 0x24) = (s32)reg_d5.b[0] / 2;
        } else if ((s32)reg_d5.b[0] < (s32)(D_006E5BF4[0] + 1)) {
            *(u8 *)(sa6 + 0x24) = reg_d5.b[0];
        } else {
            *(u8 *)(sa6 + 0x24) = D_006E5BF4[0] + 1;
        }
        if (D_006E5BF6[0] == 8) {
            *(u8 *)(reg_a6 + 0x25) = *(u8 *)(reg_a6 + 0x24);
        } else if (D_006E5BF6[0] == 7) {
            *(u8 *)(reg_a6 + 0x25) = *(u8 *)(reg_a6 + 0x24);
            if (reg_a6 == D_0029F260_as_u8_a) {
                D_0029F261[0] &= 0xBF;
                D_0029F260_as_u8_a[0] |= 2;
                D_0029CD9C_as_s16_a[0] = D_006E5C10[0] + 1;
                D_0029CD90_as_s16_a[0] = (D_006E5C10[0] + 1) * 0x16;
                func_0013E260();
                v1 = D_006E5C0E[0];
                D_0028E074_as_s16 = v1 * 4;
                func_0013E8E0();
                D_0028E068 = 2 - v1;
                D_0028E06C = D_0028E068;
            } else {
                D_0029F1F1[0] &= 0xBF;
                D_0029F1F0_as_u8_a[0] |= 2;
                D_0029CD8C_as_s16_a[0] = D_006E5C10[0] + 1;
                D_0029CD80_as_s16_a[0] = (D_006E5C10[0] + 1) * 0x16;
                func_0013E2E0();
                v2 = D_006E5C0E[0];
                D_0028E070_as_s16 = v2 * 4;
                func_0013E970();
                D_0028E060 = 2 - v2;
                D_0028E064 = D_0028E060;
            }
        } else if ((s32)*(u8 *)(reg_a6 + 0x24) < (s32)D_006E5BF6[0]) {
            *(u8 *)(reg_a6 + 0x25) = *(u8 *)(reg_a6 + 0x24);
        } else {
            *(u8 *)(reg_a6 + 0x25) = D_006E5BF6[0];
        }
        reg_a6 = sa6;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        reg_d3.w = sd3;
        reg_d4.w = sd4;
        reg_a0 = sa0;
        reg_d5.w = sd5;
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        reg_a1 = sa1;
        reg_a2 = sa2;
        reg_a3 = sa3;
        reg_a4 = sa4;
        reg_a5 = sa5;
        reg_d0.w = sd0;
    }
}
