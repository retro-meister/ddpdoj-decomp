#include "common.h"

s32 func_002011A0();
extern s8 D_0026B210[];
extern u16 D_0028E3F0;
extern s8 D_002BB430[];
extern s8 *reg_a0_as_s8_p;
extern s8 *reg_a3_as_s8_p;
extern s8 *reg_a4_as_s8_p;

void func_00171ED0(void) {
    reg_d6.w = 0;
    reg_a4_as_s8_p = (s8 *)D_002BB430;
    reg_d7.w = 4;
    do {
loop_1:
        func_002011A0();
        reg_a0_as_s8_p = (s8 *)D_0026B210;
        reg_d0.h[0] += D_0028E3F0;
        reg_d0.h[0] &= 0x1F;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        reg_d0.w = 0;
        reg_d0.b[0] = *reg_a0_as_s8_p;
        if ((1 << reg_d0.b[0]) & reg_d6.w) goto loop_1;
        reg_d6.w = reg_d6.w | (1 << reg_d0.w);
        reg_a4_as_s8_p[7] = reg_d0.b[0];
        reg_a4_as_s8_p += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.w = 4;
    reg_a4_as_s8_p = (s8 *)D_002BB430;
    do {
        reg_a3_as_s8_p = reg_a4_as_s8_p;
        reg_a3_as_s8_p += 7;
        reg_d5.b[0] = *reg_a3_as_s8_p;
        reg_d6.w = 4;
        do {
            reg_a3_as_s8_p -= 1;
            reg_d5.b[0] -= 1;
            if (0 > (s8) reg_d5.b[0]) {
                reg_d5.b[0] = 4;
            }
            *reg_a3_as_s8_p = reg_d5.b[0];
        } while ((s16)(--reg_d6.h[0]) >= 0);
        reg_a4_as_s8_p += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_0028E29C;
extern s16 D_0028E784;
extern s16 D_0028E788_as_s16;
extern s16 D_0028E78C_as_s16;
extern s16 D_0028E790_as_s16;
extern s16 D_0028E794_as_s16;
extern u16 D_0028E914;

void func_00172060(void) {
    D_0028E784 = 0;
    D_0028E790_as_s16 = 0x707;
    D_0028E794_as_s16 = 0;
    D_0028E78C_as_s16 = 7;
    D_0028E788_as_s16 = 4;
    D_0028E29C = D_0028E914;
}

extern s8 *D_0026B230[];
extern u16 D_0028E788;

void func_00172090(void)
{
    reg_d0.w = 0;
    reg_a0_as_s8_p = *(s8 **)((u8 *)D_0026B230 + (D_0028E29C & ~3));
    reg_a0_as_s8_p += 7;
    reg_a0_as_s8_p -= D_0028E788;
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
}

extern s8 D_0028E408;

s32 func_001A3020();
extern u8 D_0026B250[];
extern u16 D_0028E78C;
extern u8 D_0028E790;
extern u8 D_0028E791;
extern u16 D_0028E794;
extern u8 *reg_a0;

void func_001720E0(void) {
    s32 temp_a0;
    s32 temp_a0_3;

    if (D_0028E794 == 0) {
        D_0028E794 = 1;
        func_00172090();
        reg_d0.h[0] *= 2;
        reg_d0.h[0] += 1;
        temp_a0 = reg_d0.h[0] * 4;
        reg_a0 = *(u8 **)((u8 *)D_0026B250 + temp_a0);
        reg_d0.h[0] = 0x17;
        func_001A3020();
    }
    if (D_0028E794 == 1) {
        D_0028E78C -= 1;
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E78C = 7;
            D_0028E791 = D_0028E790;
            D_0028E788 -= 1;
            func_00172090();
            reg_d0.h[0] *= 2;
            reg_d0.h[0] += 1;
            temp_a0_3 = reg_d0.h[0] * 4;
            reg_a0 = *(u8 **)((u8 *)D_0026B250 + temp_a0_3);
            reg_d0.h[0] = 0x17;
            func_001A3020();
            if (D_0028E788 == 0) {
                D_0028E791 = 0x20;
                D_0028E794 = 2;
            }
        }
    }
    if (D_0028E794 == 2) {
        if (D_0028E78C != 0) {
            D_0028E78C -= 1;
        }
        D_0028E791 -= 1;
        if ((s8) D_0028E791 < 0) {
            D_0028E784 = 1;
            goto block_z;
        }
    }
    D_0028E408 = 1;
    return;
block_z:
    D_0028E408 = 0;
}

extern u16 D_0028E784_as_u16;

void func_00172250(void) {
    D_0028E784_as_u16 = 0xFFFF;
}

s32 func_0019C470();
s32 func_0019D710();
extern u8 D_0026B280[];

void func_00172260(void) {
    u32 temp_a3;

    if (D_0028E784 != -1) {
        func_00172090();
        reg_d0.h[0] *= 2;
        temp_a3 = *(u32 *)(D_0026B250 + (reg_d0.h[0] * 4));
        reg_d1.w = 0x38001C00;
        reg_d1.w += 0xC800E400;
        reg_d2.w = temp_a3;
        reg_d3.h[0] = 0x38E0;
        reg_d4.h[0] = 0x17;
        if ((u16) D_0028E784 == 0) {
            reg_d6.w = *(u32 *)(D_0026B280 + (D_0028E78C * 4));
            func_0019D710();
            return;
        }
        func_0019C470();
    }
}
