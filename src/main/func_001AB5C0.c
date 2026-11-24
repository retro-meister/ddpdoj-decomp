#include "common.h"

extern u16 D_0028E598;
extern u16 D_002BAF30[];
extern u16 D_002BAF3A[];
extern u16 D_002BAF50[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_001AB5C0(void) {
    u32 tmp;

    switch (D_0028E598) {
    case 0:
        break;
    default:
        reg_a0 = (u8 *)D_002BAF50;
        reg_d0.w = 0x11;
loop_1:
        if (*(u16 *)reg_a0 != 0) {
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
            tmp = reg_d0.h[0] - 1;
            reg_d0.h[0] = tmp;
            if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                goto loop_1;
            }
            return;
        }
        reg_a0 += 0xA;
        tmp = reg_d0.h[0] - 1;
        reg_d0.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        if (D_002BAF30[0] != 0) {
            reg_a0 = (u8 *)D_002BAF30;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
        if (D_002BAF3A[0] != 0) {
            reg_a0 = (u8 *)D_002BAF3A;
            *(u16 *)reg_a0 = 0;
            reg_a0 += 2;
            reg_tmp.h[1] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_tmp.h[0] = *(u16 *)reg_a0;
            reg_a0 += 2;
            reg_a1 = (u8 *)reg_tmp.w;
            *(u16 *)(reg_a1 + 2) = *(u16 *)reg_a0;
            reg_a0 += 2;
            *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
            reg_a0 += 2;
        }
    }
}
