#include "common.h"

s32 func_0013D470(u16);                         /* extern */
extern s32 D_0028E050_as_s32;
extern s32 D_0028E054_as_s32;
extern s32 D_0028E058;
extern s32 D_0028E05C;
extern u16 D_0028E3B4;
extern u16 D_0028E3E4;
extern u16 D_0028E3F0;
extern u16 D_0028E5BC;
extern u16 D_0028E5C0;
extern u16 D_0029CD80[];
extern u16 D_0029CD90[];
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];
extern s32 *reg_a0_as_s32_p;
extern s32 *reg_a1_as_s32_p;

void func_0013D560(void) {
    if (D_0028E3B4 == 0) {
        reg_d0.h[0] = D_0029F260_as_u16_a[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (D_0028E5C0 != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (D_0029CD90[0] == 0) || (D_0028E3E4 != 0))) {
            reg_a0_as_s32_p = &D_0028E054_as_s32;
            reg_a1_as_s32_p = &D_0028E05C;
            reg_d1.w = 0x810000;
            func_0013D470(reg_d0.h[0]);
        }
        reg_d0.h[0] = D_0029F1F0_as_u16_a[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (D_0028E5BC != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (D_0029CD80[0] == 0) || (D_0028E3F0 & 2))) {
            reg_a0_as_s32_p = &D_0028E050_as_s32;
            reg_a1_as_s32_p = &D_0028E058;
            reg_d1.w = 0x811C00;
            func_0013D470(reg_d0.h[0]);
        }
    }
}
