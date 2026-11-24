#include "common.h"

s32 func_00129280();
extern u8 D_002641C0[];

void func_001E9150(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a1 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a1;
    temp_a0 = reg_d3.w;
    temp_a1_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a1_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a0 + reg_tmp.w;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00129280();
}

void func_001E9220(void) {
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_a2_2;
    u32 temp_a1;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    temp_a1 = reg_d3.w;
    temp_a2_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a2_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a1 + reg_tmp.w;
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[1] = temp_a0;
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d1.h[0] += 0xC;
    func_00129280();
    reg_d1.h[0] -= 0x18;
    func_00129280();
}

void func_001E9320(void) {
    u16 temp_a1;
    u16 temp_a1_2;
    u32 temp_a0;

    reg_a2 = (u8 *)D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d2.b[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a1 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a1;
    temp_a0 = reg_d3.w;
    temp_a1_2 = *(u16 *)reg_a3;
    reg_tmp.h[0] = temp_a1_2;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w = temp_a0 + reg_tmp.w;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_00129280();
    reg_d1.h[0] += 0x18;
    func_00129280();
    reg_d1.h[0] -= 0x30;
    func_00129280();
}

s32 func_002010A0();                            /* extern */

void func_001E9420(void) {
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1A))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1D))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1C))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1F))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1E))) = (u8) reg_d0.b[0];
}

extern u16 D_00264140[];
extern u32 D_0028D9CC;

void func_001E94A0(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264140);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9CC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_001E9420();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C9)));
    (*(u8 *)((u8 *)(reg_a4) + (9))) -= reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1C8)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1CA)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
}

s32 func_00125310();
extern u16 D_00262A50_as_u16_a[];
extern u16 D_00264160_as_u16_a[];
extern u16 D_00264180[];
extern u16 D_0028E89C;

void func_001E95D0(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;

    if (D_0028E89C != 0) {
        func_001E94A0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
        reg_a3 = (u8 *)(D_00264160_as_u16_a);
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        func_001E9320();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
        func_001E9220();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1D)));
        func_001E9150();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1C)));
        func_001E9320();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1F)));
        func_001E9220();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1E)));
        func_001E9150();
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 0) {
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)(D_00262A50_as_u16_a);
            reg_a3 = (u8 *)(D_00264180);
            reg_d6.w = 5;
            do {
                reg_d7.w = 8;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D8)));
                reg_d0.h[0] += *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                t2 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d0.h[0] = t2;
                reg_d1.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] -= 0x20;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d5.h[1] = t3;
                reg_d5.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
loop_6:
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                if (reg_d7.w & 1) {
                    func_00129280();
                } else {
                    func_00129280();
                }
                reg_d1.h[0] += 8;
                t4 = reg_d7.h[0] - 1;
                reg_d7.h[0] = t4;
                if (((s64) ((s64) (t4 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                    goto loop_6;
                }
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            func_001E9420();
            t1 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if ((s16)(t1) < 0x10) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (t1 + 1);
            }
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
                t7 = (*(u8 *)((u8 *)(reg_a6) + (0x1C7)));
                if ((s32) t7 < 6) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C7))) = (u8) (t7 + 2);
                }
                t8 = (*(u8 *)((u8 *)(reg_a6) + (0x1C9)));
                if ((s32) t8 < 3) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C9))) = (u8) (t8 + 1);
                }
                t9 = (*(u8 *)((u8 *)(reg_a6) + (0x1C8)));
                if ((s32) t9 < 0x20) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C8))) = (u8) (t9 + 8);
                }
                t5 = (*(u16 *)((u8 *)(reg_a6) + (0x1CA)));
                if ((s16)(t5) < 0x10) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1CA))) = (u16) (t5 + 1);
                }
                t6 = (*(u16 *)((u8 *)(reg_a6) + (0x1D8)));
                if ((s16)(t6) < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D8))) = (u16) (t6 + 1);
                }
                reg_d0.w = 0;
                func_00125310();
            }
        }
    }
}

s32 func_002011A0();
s32 func_00201270();
extern u16 D_002642C0[];
extern u32 D_0028D9D0;

void func_001E9AA0(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_002642C0);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0x1F))) *= -1;
        (*(u8 *)((u8 *)(reg_a4) + (0x1E))) *= -1;
        func_00201270();
        (*(u8 *)((u8 *)(reg_a4) + (0x1F))) += reg_d0.b[0];
        func_00201270();
        (*(u8 *)((u8 *)(reg_a4) + (0x1E))) += reg_d0.b[0];
    }
    (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
    (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1CD)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1CE)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D0)));
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x16))) += reg_d0.h[0];
}

s32 func_00129370();
s32 func_00171400();
s32 func_002010A0();
s32 func_002027A0();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001E9C60(s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u32 temp_v1;
    u32 temp_v1_2;
    u8 temp_v0;

    var_a1 = (s16 *)(arg1);
    if (D_0028E89C != 0) {
        func_001E9AA0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            temp_a0 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                var_a1 = (s16 *)(reg_a1);
                if (0 > *var_a1) {
                    reg_a0 = (u8 *)(var_a1);
                    reg_atmp = (u8 *)(temp_a0);
                    reg_a1 = (u8 *)(temp_a0);
                    goto block_9;
                }
            } else {
block_9:
                reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                func_002010A0();
                reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
                reg_d1.b[0] += reg_d0.b[0];
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                func_00129280();
                func_00171400();
                reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
                if ((*(u8 *)((u8 *)(reg_a4) + (4))) == reg_d0.b[0]) {
                    reg_d1.b[0] += 0x40;
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) reg_d1.b[0];
                    reg_d1.b[0] += 0x80;
                    reg_d1.b[0] *= -1;
                    (*(u8 *)((u8 *)(reg_a4) + (8))) = (u8) reg_d1.b[0];
                }
                goto block_11;
            }
        } else {
block_11:
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.w = 0xF2C0FC00;
            reg_d4.w = 0;
            func_00129370();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            func_00129370();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d1.b[0] += 0x20;
                reg_d0.w = 0x10003;
                func_00129280();
            }
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d3.h[0] = 0x400;
            reg_d4.w = 0;
            func_00129370();
            reg_d1.b[0] += 0x20;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
            func_00129370();
            reg_d1.b[0] += 0x60;
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x16)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d0.w = 0x10003;
                func_00129280();
            }
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1F)));
            (*(u8 *)((u8 *)(reg_a4) + (9))) += reg_d0.b[0];
            var_a1 = (s16 *)(reg_a4);
            reg_d0.b[0] = (*(u8 *)((u8 *)(var_a1) + (0x1E)));
            (*(u8 *)((u8 *)(var_a1) + (8))) += reg_d0.b[0];
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            (*(u8 *)((u8 *)(reg_a4) + (0x1F))) *= -1;
            (*(u8 *)((u8 *)(reg_a4) + (0x1E))) *= -1;
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1CD)));
            if ((s32) temp_v0 < 0x3C) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1CD))) = (u8) (temp_v0 + 0x14);
            }
            temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x1CE)));
            if ((s16)(temp_v1) < 4) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1CE))) = (u16) (temp_v1 + 1);
            }
            temp_v1_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1D0)));
            if ((s16)(temp_v1_2) < 0x1A) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1D0))) = (u16) (temp_v1_2 + 1);
            }
            (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
            reg_d0.w = 1;
            func_00125310();
        }
    }
}

void func_001EA0E0(void) {
    u16 temp_a2;

    reg_a2 = D_002641C0;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.w = 0;
    reg_d1.b[0] += reg_d1.b[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_a2 += reg_d3.h[0];
    reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    temp_a2 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.h[1] = temp_a2;
    reg_tmp.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d3.w += reg_tmp.w;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
}

extern u16 D_002642E0[];
extern u32 D_0028D9D4;
extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void func_001EA1A0(void) {
    reg_a0_as_u16_p = D_002642E0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    if ((*(u8 *)((u8 *)(reg_a6) + (0x13D))) != 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x13))) *= -1;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D3)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D4)));
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) += reg_d0.h[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x15))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x14))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x16))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x19))) = (u8) reg_d0.b[0];
    func_002010A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x18))) = (u8) reg_d0.b[0];
}

s32 func_00201100();
extern u8 D_00264160[];

void func_001EA300(void) {
    s16 *temp_a0;
    s16 *var_a1;
    u16 temp_a0_2;
    u16 temp_v0;
    u16 temp_v0_2;

    if (D_0028E89C != 0) {
        func_001EA1A0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (s16 *)(reg_a4);
        (*(u8 *)((u8 *)(var_a1) + (3))) = (u8) (*(u8 *)((u8 *)(var_a1) + (9)));
        (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            temp_a0 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                var_a1 = (s16 *)(reg_a1);
                if (0 > *var_a1) {
                    reg_a0 = (u8 *)(var_a1);
                    reg_atmp = (u8 *)(temp_a0);
                    reg_a1 = (u8 *)(temp_a0);
                    goto block_9;
                }
            } else {
block_9:
                reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                reg_d7.h[0] = reg_d2.h[0];
                reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x10)));
                reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
                reg_d2.h[0] = temp_a0_2;
                reg_d3.w = 0xF0C00000;
                reg_d4.w = 0;
                reg_d5.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
                reg_d5.h[0] += 0x7FFF + 0x7601;
                if ((s32) reg_d5.h[0] <= (s32) reg_d7.h[0]) {
                    reg_d0.w += 0x100000;
                    func_00201100();
                    reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                    reg_d1.b[0] += reg_d5.b[0];
                    func_00129280();
                    reg_d0.w += 0x40000;
                    func_00129280();
                    reg_d0.w += 0x40000;
                }
                func_00129280();
                func_00171400();
                goto block_12;
            }
        } else {
block_12:
            reg_a3 = (u8 *)D_00264160;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x70;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xC0;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x15)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x7C;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x14)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB8;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x14)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x98;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x17)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0xB0;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x17)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
            func_001EA0E0();
            reg_d1.h[0] = 0x90;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x16)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x40;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x16)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
            func_001EA0E0();
            reg_d1.h[0] = 0x84;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x19)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x48;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x19)));
            func_00129280();
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
            func_001EA0E0();
            reg_d1.h[0] = 0x68;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
            reg_d0.w += 0xC0000;
            reg_d1.h[0] = 0x50;
            reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0x18)));
            func_00129280();
        }
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        (*(u8 *)((u8 *)(reg_a6) + (0x3A))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x5A))) -= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7A))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x9A))) -= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xBA))) += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xDA))) -= reg_d0.b[0];
        reg_d0.h[0] = 0x3F;
        (*(u8 *)((u8 *)(reg_a6) + (0x3A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x5A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x7A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0x9A))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xBA))) &= reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a6) + (0xDA))) &= reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_002010A0();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
            reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) reg_d0.b[0];
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
                (*(s8 *)((u8 *)(reg_a6) + (0x13D))) = (s8) ~(*(s8 *)((u8 *)(reg_a6) + (0x13D)));
                temp_v0 = (*(u16 *)((u8 *)(reg_a6) + (0x1D2)));
                if ((s32) temp_v0 < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D2))) = (u16) (temp_v0 + 1);
                }
                temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1D4)));
                if ((s32) temp_v0_2 < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D4))) = (u16) (temp_v0_2 + 1);
                }
                (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
                (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
                reg_d0.w = 2;
                func_00125310();
            }
        }
    }
}

void func_00129320(void);

void func_001EA990(void) {
    func_00129320();
}

extern u16 D_00264300[];
extern u32 D_0028D9D8;

void func_001EA9A0(void) {
    reg_a0_as_u16_p = D_00264300;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9D8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x13E)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1D6)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (3))) += 2;
}

extern u16 D_00264320[];

void func_001EAAB0(void) {
    s16 *t1;
    s8 t2;
    s8 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u32 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;

    if (D_0028E89C != 0) {
        func_001EA9A0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        t8 = *(u8 *)(reg_a4 + 4);
        if (t8 == reg_d0.b[0]) {
            func_00201270();
            *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
        }
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        if (0 > *(s16 *)reg_a0) {
            goto next_1;
        }
        if (!(0 > *(s16 *)reg_a1)) {
            goto next_2;
        }
        t1 = (s16 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        reg_atmp = (u8 *)(t1);
        reg_a1 = (u8 *)(t1);
next_1:
#ifdef DEATH_LABEL
            reg_d2.w = *(u16 *)(reg_a0 + 2);
            reg_d3.w = *(u16 *)(reg_a0 + 4);
#else
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
#endif
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
#ifdef DEATH_LABEL
            reg_d0.w = *(u16 *)(reg_a6 + 2);
            reg_d1.w = *(u16 *)(reg_a6 + 4);
#else
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
#endif
            reg_a3 = (u8 *)(D_00264320);
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_a3 += reg_d4.h[0];
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0xD00;
            func_002027A0();
            t7 = reg_d1.w;
            reg_d2.h[0] = reg_d6.h[0];
            reg_d3.h[0] = reg_d7.h[0];
#ifdef DEATH_LABEL
            reg_d0.w = *(u16 *)(reg_a6 + 2);
            reg_d1.w = *(u16 *)(reg_a6 + 4);
#else
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
#endif
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0x7FFF + 0x7301;
            func_002027A0();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            t5 = *(u16 *)(reg_a6 + 4);
            reg_d2.h[0] = t5;
            t4 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = t4;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t2 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t2 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            func_001EA990();
            reg_d1.w = t7;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t3 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t3 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            func_001EA990();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                *(u16 *)(reg_a4 + 0xE) = 0x30U;
            }
next_2:
        *(u16 *)(reg_a4 + 0xA) += 1;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_00171400();
            t11 = *(u8 *)(reg_a4 + 4);
            if ((s32) t11 < 0x1E) {
                *(u8 *)(reg_a4 + 4) = (u8) (t11 + 0xF);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 3) += 4;
            *(u16 *)(reg_a4 + 0x12) += 1;
            *(u16 *)(reg_a4 + 0xA) = (u16) *(u16 *)(reg_a4 + 0x12);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t9 = *(u8 *)(reg_a6 + 0x1D7);
                if ((s32) t9 < 2) {
                    *(u8 *)(reg_a6 + 0x1D7) = (u8) (t9 + 1);
                }
                t6 = *(u16 *)(reg_a6 + 0x13E);
                if ((s32) t6 < 6) {
                    *(u16 *)(reg_a6 + 0x13E) = (u16) (t6 + 1);
                }
                t10 = *(u8 *)(reg_a6 + 0x1D6);
                if ((s32) t10 < 0x18) {
                    *(u8 *)(reg_a6 + 0x1D6) = (u8) (t10 + 2);
                }
                reg_d0.w = 3;
                func_00125310();
            }
        }
    }
}

void func_001EAF20(void) {
    s32 func_00129450();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xF0C00000;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    var_a1 = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d2.h[0] = var_a1;
    reg_d5.w = 0xF0C00000;
    reg_d6.b[0] = 0x10;
    reg_d7.w = 3;
    reg_d4.w = 0;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        reg_d3.w += reg_d5.w;
        func_00129450();
        var_a1 = (u16) reg_d1.b[0];
        var_a0 = var_a1 + reg_d6.b[0];
        reg_d1.b[0] = var_a0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264360[];
extern u32 D_0028D9DC;
extern s32 reg_a4_as_s32;

void func_001EB060(void) {
    reg_a0_as_u16_p = D_00264360;
    reg_a1_as_u16_p = (u16 *)(reg_a4_as_s32 + 2);
    reg_d0.w = ((u32) D_0028D9DC >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u8 D_00262A50_as_u8_a[];

void func_001EB0E0(void) {
    u32 temp_a0;
    u8 temp_v1;
    u8 temp_v1_2;

    if (D_0028E89C != 0) {
        func_001EB060();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (9)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] -= 4;
        }
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d0.b[0];
        reg_a1 = (u8 *)D_00262A50_as_u8_a;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        func_001EAF20();
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x12)));
        reg_d1.b[0] += 0x80;
        func_001EAF20();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x13)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x16)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
        if ((u32) reg_tmp.w < 0x15000U) {
            reg_d0.b[0] = (s8) reg_d0.b[0] * 4;
        }
        (*(u8 *)((u8 *)(reg_a4) + (0x12))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(u8 *)((u8 *)(reg_a4) + (0x13))) *= -1;
            temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if ((s16)(temp_a0) < 8) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (temp_a0 + 2);
            }
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (9)));
                if ((s32) temp_v1 > 5) {
                    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) (temp_v1 - 2);
                }
                temp_v1_2 = (*(u8 *)((u8 *)(reg_a4) + (4)));
                if ((s32) temp_v1_2 < 0xC7) {
                    (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1_2 + 0x14);
                }
                (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            }
        }
    }
}

s32 func_00201160();
extern u16 D_00264380[];
extern u32 D_0028D9E0;

void func_001EB300(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264380);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_00201160();
    reg_d0.b[0] += 0x60;
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) reg_d0.b[0];
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) *= -1;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1DB)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1DC)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1DE)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
}

extern s16 D_00262A50[];

void func_001EB440(s16 *arg1) {
    s32 func_00129450();
    s16 *t1;
    s16 *t2;
    u32 t3;
    u32 t4;
    u16 t5;
    u8 t6;

    t2 = (s16 *)(arg1);
    if (D_0028E89C != 0) {
        func_001EB300();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        if (*(u8 *)(reg_a4 + 5) & 1) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if (*(u8 *)(reg_a5 + 2) != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)t1) {
                t2 = (s16 *)(reg_a1);
                if (0 > *t2) {
                    reg_a0 = (u8 *)(t2);
                    reg_atmp = (u8 *)(t1);
                    reg_a1 = (u8 *)(t1);
                    goto next_1;
                }
            } else {
next_1:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 2);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d5.w = 0xF0C00000;
                reg_d7.w = 6;
                reg_d1.h[0] -= 0x36;
                reg_a1 = (u8 *)(D_00262A50);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                    reg_d3.w += reg_d5.w;
                    func_00129450();
                    reg_d1.h[0] += 0x12;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                func_00171400();
                goto next_2;
            }
        } else {
next_2:
            t5 = 0xC;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d5.w = 0xF0C00000;
            reg_d7.w = 0xC;
            reg_d1.h[0] -= 0x3C;
            reg_a1 = (u8 *)(D_00262A50);
            reg_d4.w = 0;
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                func_00129450();
                t5 = (u32)reg_d1.h[0] + 0xA;
                reg_d1.h[0] = t5;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = reg_a4[0x10];
            if (!(0 > (s8) reg_d1.b[0])) {
                goto next_31;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] < 0x50) {
                goto next_32;
            }
            goto next_33;
next_31:
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] <= 0xB0) {
                goto next_33;
            }
next_32:
            reg_a4[0x10] *= -1;
next_33:;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t6 = *(u8 *)(reg_a6 + 0x1DB);
            if ((s32) t6 < 0x28) {
                *(u8 *)(reg_a6 + 0x1DB) = (u8) (t6 + 0xA);
            }
            t3 = *(u16 *)(reg_a6 + 0x1DC);
            if ((s16)(t3) < 4) {
                *(u16 *)(reg_a6 + 0x1DC) = (u16) (t3 + 1);
            }
            t4 = *(u16 *)(reg_a6 + 0x1DE);
            if ((s16)(t4) < 0x1A) {
                *(u16 *)(reg_a6 + 0x1DE) = (u16) (t4 + 1);
            }
            reg_d0.w = 5;
            func_00125310();
        }
    }
}

void func_001EB8E0(void) {
    s32 func_00129450();
    u32 temp_a0;

    reg_d7.h[0] = reg_d1.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d1.b[0] -= 1;
    func_00129450();
    reg_d1.b[0] += 2;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d1.b[0] -= 2;
    func_00129450();
    reg_d1.b[0] += 4;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 + 0x40000;
    reg_d1.b[0] -= 1;
    func_00129450();
    reg_d1.b[0] += 2;
    func_00129450();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    reg_d0.w += 0x40000;
    func_00129450();
    reg_d1.b[0] -= 2;
    func_00129450();
    reg_d1.b[0] += 4;
    func_00129450();
}

extern u16 D_00264390[];
extern u32 D_0028D9E4;

void func_001EBA00(void) {
    reg_a0_as_u16_p = D_00264390;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1E8)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E7)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
}

extern u8 D_002643A0[];

void func_001EBAD0(void) {
    s16 *temp_v1;
    u16 temp_v0_2;
    u8 temp_v0;

    if (D_0028E89C != 0) {
        func_001EBA00();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_v1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_v1) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            func_00201160();
            reg_d0.b[0] -= 0x20;
            reg_d1.b[0] += reg_d0.b[0];
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a3 = (u8 *)D_002643A0;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            reg_a3 += reg_d4.h[0];
            reg_d3.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_d4.w = 0;
            func_001EB8E0();
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) -= 4;
            if ((s32) reg_tmp.h[0] < 4) {
                (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 0x14U;
            }
        }
        func_00171400();
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1E7)));
            if ((s32) temp_v0 < 0x14) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1E7))) = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1E8)));
            if ((s32) temp_v0_2 < 6) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1E8))) = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 6;
            func_00125310();
        }
    }
}

void func_001EBD30(void) {
    s32 func_00129450();
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d4.w = 0;
    reg_d1.h[0] += reg_d5.h[0];
    func_00129450();
    reg_d4.h[0] = reg_d5.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 1;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d5.h[0] += reg_d4.h[0];
    reg_d4.h[0] = (s16) reg_d4.h[0] >> 2;
    reg_d5.h[0] += reg_d4.h[0];
    reg_d1.h[0] -= reg_d5.h[0];
    reg_d0.h[0] += *(u16 *)(reg_a4 + 0xE);
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d4.w = 0;
    func_00129450();
}

extern u16 D_002643C0[];
extern u32 D_0028D9E8;

void func_001EBE90(void) {
    reg_a0_as_u16_p = D_002643C0;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1EC)));
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1EB)));
    (*(u8 *)((u8 *)(reg_a4) + (8))) -= reg_d0.b[0];
}

extern u8 D_002643E0[];

void func_001EBF40(void) {
    s16 *temp_a0;
    u16 temp_a0_2;
    u16 temp_v0_2;
    u8 temp_v0;
    u8 temp_v1;
    u8 *var_a1;

    if (D_0028E89C != 0) {
        func_001EBE90();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        var_a1 = (unsigned char *)((*(u8 *)((u8 *)(reg_a4) + (9))));
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (unsigned char)var_a1;
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            var_a1 = (unsigned char *)reg_a1;
            if (0 > (s64)*(s16 *)var_a1) {
                reg_a0 = (u8 *) var_a1;
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_8;
            }
        } else {
block_8:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_d2.h[0] = temp_a0_2;
            reg_d7.h[0] = reg_d1.h[0];
            reg_a3 = (u8 *)D_002643E0;
            reg_d4.w = 0;
            reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_a3 += reg_d4.h[0];
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
            reg_a3 = (u8 *) reg_tmp.w;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            reg_a3 += reg_d4.h[0];
            func_001EBD30();
            reg_d1.h[0] = reg_d7.h[0];
            reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
            func_001EBD30();
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
            (*(u16 *)((u8 *)(reg_a4) + (0x12))) -= 0x10;
            if ((s32) reg_tmp.h[0] < 0x10) {
                (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0x40U;
            }
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_00171400();
            temp_v1 = (*(u8 *)((u8 *)(reg_a4) + (4)));
            if ((s32) temp_v1 < 0x3B) {
                (*(u8 *)((u8 *)(reg_a4) + (4))) = (u8) (temp_v1 + 0xF);
            }
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(u16 *)((u8 *)(reg_a4) + (0xA))) += 2;
            (*(u16 *)((u8 *)(reg_a4) + (0xE))) += 1;
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1EB)));
                if ((s32) temp_v0 < 0x10) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1EB))) = (u8) (temp_v0 + 8);
                }
                temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1EC)));
                if ((s32) temp_v0_2 < 0xB) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1EC))) = (u16) (temp_v0_2 + 2);
                }
                reg_d0.w = 7;
                func_00125310();
            }
        }
    }
}

extern u16 D_00264530[];
extern u32 D_0028D9EC;

void func_001EC230(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264530);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9EC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_00201160();
    reg_d0.b[0] -= 0x20;
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) reg_d0.b[0];
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) *= -1;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1EF)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
}


void func_001EC330(void) {
    s32 func_00129450();
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u8 t5;
    u8 t6;

    if (D_0028E89C != 0) {
        func_001EC230();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        t1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
            t2 = (s16 *)(reg_a1);
            if (0 > *t2) {
                reg_a0 = (u8 *)(t2);
                reg_atmp = (u8 *)(t1);
                reg_a1 = (u8 *)(t1);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d0.w = (u32) *(u16 *)(reg_a6 + 2);
            t3 = *(u16 *)(reg_a6 + 4);
            reg_d0.h[0] += 0x7FFF + 0x5801;
            reg_d1.w = (u32) t3;
            if ((s32) reg_d0.h[0] <= (s32) reg_d2.h[0]) {
                func_002027A0();
                reg_d0.w = 0x80013;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d3.w = 0xD8000000;
                reg_d4.w = 0;
                func_00201100();
                reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                reg_d1.b[0] += reg_d5.b[0];
                func_00129450();
                reg_d1.b[0] -= 2;
                reg_d0.w += 0x40000;
                func_00129450();
                reg_d1.b[0] += 4;
                reg_d0.w += 0x40000;
                func_00129450();
            }
            t6 = 6;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d6.w = 0xD8000000;
            reg_d7.w = 6;
            reg_d1.h[0] -= 0x2D;
            reg_a1 = (u8 *)(D_00262A50);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d4.w = 0x02020020;
                reg_d3.w += reg_d6.w;
                reg_d5.h[0] = 0x42;
                func_00129450();
                t4 = reg_d0.h[0];
                reg_d4.w = 0x2C03FFE0;
                reg_d0.h[0] += 1;
                reg_d1.b[0] += 0x80;
                reg_d5.h[0] = 0x2E;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] -= 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                func_00129450();
                reg_d1.b[0] += 0x80;
                reg_d0.h[0] -= 1;
                reg_d1.h[0] += 0xF;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = reg_a4[0x10];
            if (0 > (s8) reg_d1.b[0]) {
                goto next_21;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) > 0x30) {
                goto next_22;
            }
            goto next_23;
next_21:
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) >= -0x30) {
                goto next_23;
            }
next_22:
            reg_a4[0x10] *= -1;
next_23:;
        }
        func_00171400();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_001EC230();
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t5 = *(u8 *)(reg_a6 + 0x1EF);
            if ((s32) t5 < 0x28) {
                *(u8 *)(reg_a6 + 0x1EF) = (u8) (t5 + 0x14);
            }
            reg_d0.w = 8;
            func_00125310();
        }
    }
}

void func_001EC790(void) {
    extern void func_00129450(void);
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d3.w = 0xFA000000;
    reg_d6.h[0] = 5;
    reg_d7.h[0] = 0xF;
    reg_d4.w = 0;
    do {
        func_00129450();
        reg_d1.b[0] += reg_d6.b[0];
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264540[];
extern u32 D_0028D9F0;

void func_001EC810(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264540);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    (*(s8 *)((u8 *)(reg_a4) + (0xF))) = 0x20;
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xE))) *= -1;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F8)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F7)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
}


void func_001EC920(void) {
    s16 *temp_v1;
    s16 *var_a0;
    u16 temp_v0_2;
    u8 temp_v0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_v1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(temp_v1) + (0))) {
            var_a0 = (s16 *)(reg_a1);
            if (0 > *var_a0) {
                reg_a0 = (u8 *)(var_a0);
                reg_atmp = (u8 *)(temp_v1);
                reg_a1 = (u8 *)(temp_v1);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
            reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
            func_002027A0();
            reg_d5.h[0] = reg_d1.h[0];
            if ((*(u8 *)((u8 *)(reg_a4) + (5))) & 1) {
                reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a4) + (0xF)));
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                func_001EC790();
            } else {
                reg_d1.h[0] = reg_d5.h[0];
                reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a4) + (0xF)));
                reg_d1.h[0] -= 0x23;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                func_001EC790();
            }
            var_a0 = (s16 *)(reg_a4);
            reg_d1.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xE)));
            if (0 <= (s8)(reg_d1.b[0])) {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) > 0x10) {
                    goto block_13;
                }
                goto block_end;
            } else {
                (*(u8 *)((u8 *)(var_a0) + (0xF))) += reg_d1.b[0];
                if ((s8) (*(u8 *)((u8 *)(reg_a4) + (0xF))) < -0x10) {
block_13:
                    var_a0 = (s16 *)(reg_a4);
                    (*(u8 *)((u8 *)(var_a0) + (0xE))) *= -1;
                }
            }
        }
block_end:
        func_00171400();
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1F7)));
            if ((s32) temp_v0 < 0x1E) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1F7))) = (u8) (temp_v0 + 0x14);
            }
            temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1F8)));
            if ((s32) temp_v0_2 < 2) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F8))) = (u16) (temp_v0_2 + 1);
            }
            reg_d0.w = 9;
            func_00125310();
        }
    }
}

void func_001ECBD0(void) {
    s32 func_00129450();
    u32 var_a1;
    u8 var_a0;

    var_a0 = 0xFA000000;
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d4.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
    var_a1 = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
    reg_d4.h[0] = var_a1;
    reg_d5.w = 0xFA000000;
    reg_d6.b[0] = 0x15;
    reg_d7.w = 0xB;
    do {
        reg_d3.h[0] = reg_d1.h[0];
        reg_d3.h[0] += 2;
        reg_d3.h[0] &= 0xFC;
        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        reg_d3.w += reg_d5.w;
        func_00129450();
        var_a1 = (u16) reg_d1.b[0];
        var_a0 = var_a1 + reg_d6.b[0];
        reg_d1.b[0] = var_a0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

extern u16 D_00264550[];
extern u32 D_0028D9F4;

void func_001ECD10(void) {
    reg_a0_as_u16_p = D_00264550;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F4 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F0)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F2)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F4)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x10))) = (u8) reg_d0.b[0];
    if ((*(u8 *)((u8 *)(reg_a6) + (0x1F1))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) *= -1;
    }
}

s32 func_00202A80();
extern s16 D_0028E88C_as_s16;

void func_001ECE40() {
    u16 temp_v0_2;
    u16 temp_v0_3;
    u8 temp_v0;

    D_0028E88C_as_s16 = 0;
    func_00202A80();
    if ((s32) reg_d0.h[0] < 0x2000) {
        D_0028E88C_as_s16 = 1;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
        reg_a1 = D_00262A50_as_u8_a;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x10)));
        func_001ECBD0();
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x11)));
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) += reg_d0.b[0];
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            (*(s8 *)((u8 *)(reg_a6) + (0x1F1))) = (s8) ~(*(s8 *)((u8 *)(reg_a6) + (0x1F1)));
            temp_v0 = (*(u8 *)((u8 *)(reg_a6) + (0x1F0)));
            if ((s32) temp_v0 < MAIN_OR_DEATH_LABEL(0x95, 0x81)) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1F0))) = (u8) (temp_v0 + 0xA);
            }
            temp_v0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x1F2)));
            if ((s32) temp_v0_2 < 2) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F2))) = (u16) (temp_v0_2 + 1);
            }
            temp_v0_3 = (*(u16 *)((u8 *)(reg_a6) + (0x1F4)));
            if ((s32) temp_v0_3 < 3) {
                (*(u16 *)((u8 *)(reg_a6) + (0x1F4))) = (u16) (temp_v0_3 + 1);
            }
            reg_d0.w = 0xA;
            func_00125310();
        }
    }
}

void func_001ECF90(void) {
    s32 func_00129450();
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d3.w = 0xFA000000;
    reg_d4.w = 0;
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] -= 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
    reg_d0.h[0] += 1;
    reg_d0.w += 0x30000;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129450();
}

extern u16 D_00264560[];
extern u32 D_0028D9F8;

void func_001ED160(void) {
    reg_a0_as_u16_p = D_00264560;
    reg_a1_as_u16_p = (u16 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F8 >> 1) - 1;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x404;
}

extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_0029F260_as_u16_a[];

void func_001ED1E0(u8 *arg0, s16 *arg1) {
    s16 *temp_a0;
    s16 *var_a1;
    u8 temp_a1;
    u8 temp_a2;
    u8 *var_a0;

    var_a0 = (u8 *)(arg0);
    var_a1 = (s16 *)(arg1);
    if (D_0028E89C == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if (reg_tmp.b[0] == 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (7)));
            reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
            if ((*(u8 *)((u8 *)(reg_a4) + (4))) == reg_d2.b[0]) {
                reg_a0 = (u8 *)(D_0029F260_as_u16_a);
                reg_a1 = (u8 *)(D_0029F1F0_as_u16_a);
                if ((*(u8 *)((u8 *)(reg_a5) + (2))) != 0) {
                    reg_atmp = (u8 *)(reg_a0);
                    reg_a0 = (u8 *)(reg_a1);
                    reg_a1 = (u8 *)(reg_atmp);
                }
                temp_a0 = (s16 *)(reg_a0);
                if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
                    var_a1 = (s16 *)(reg_a1);
                    if (0 > *var_a1) {
                        reg_a0 = (u8 *)(var_a1);
                        reg_atmp = (u8 *)(temp_a0);
                        reg_a1 = (u8 *)(temp_a0);
                        goto block_8;
                    }
                } else {
block_8:
                    reg_d2.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (2)));
                    reg_d3.w = (u32) (*(u16 *)((u8 *)(reg_a0) + (4)));
                    reg_d0.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (2)));
                    reg_d1.w = (u32) (*(u16 *)((u8 *)(reg_a6) + (4)));
                    reg_d0.h[0] += 0x7FFF + 0x7A01;
                    func_002027A0();
                    reg_d1.h[0] = 0x80;
                    (*(u8 *)((u8 *)(reg_a4) + (6))) = (u8) reg_d1.b[0];
                    goto block_9;
                }
            } else {
block_9:
                reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (6)));
                reg_d6.b[0] = 0xB7;
                reg_d7.h[0] = reg_d1.h[0];
                temp_a1 = (*(u8 *)((u8 *)(reg_a4) + (5)));
                reg_d6.b[0] -= temp_a1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0x16;
                func_001ECF90();
                reg_d6.b[0] = 0xB7;
                reg_d1.h[0] = reg_d7.h[0];
                temp_a2 = (*(u8 *)((u8 *)(reg_a4) + (5)));
                reg_d6.b[0] -= temp_a2;
                reg_d6.b[0] *= -1;
                reg_d1.b[0] += reg_d6.b[0];
                reg_d6.h[0] = 0xFFEA;
                func_001ECF90();
            }
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
            var_a1 = (s16 *)(reg_a4 + 0xD);
            if ((*(u8 *)((u8 *)(reg_a4) + (0xD))) == 0) {
                (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
            }
            var_a0 = (u8 *)(reg_a4);
            reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (5)));
            (*(u8 *)((u8 *)(var_a0) + (5))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                goto block_13;
            }
        }
    } else {
block_13:
        func_00171400();
        reg_d0.w = 0xB;
        func_00125310();
    }
}

s32 func_00201230();
extern u16 D_00264570[];
extern u32 D_0028D9FC;

void func_001ED410(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264570);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9FC >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_00201160();
    reg_d0.b[0] += 0x60;
    (*(u8 *)((u8 *)(reg_a4) + (0xF))) = (u8) reg_d0.b[0];
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xE))) *= -1;
    }
    func_00201230();
    reg_d0.w = (u32) (s16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0x1C))) = (u16) reg_d0.h[0];
    reg_d0.h[0] += 2;
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = (u16) reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1EE)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
}

s32 func_00201E20();
extern u16 D_0028E890;
extern u16 D_0028E894;

void func_001ED550(void) {
    s32 func_00129450();
    s16 *t1;
    u8 t2;
    u8 t3;

    reg_d0.w = 0xC;
    func_00125310();
    if (D_0028E89C != 0) {
        func_001ED410();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if (*(u8 *)(reg_a5 + 2) != 0) {
                reg_atmp = (u8 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(reg_atmp);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
                if (0 > *(s16 *)reg_a1) {
                    reg_a0 = (u8 *)(reg_a1);
                    reg_atmp = (u8 *)(t1);
                    reg_a1 = (u8 *)(t1);
                    goto next_1;
                }
            } else {
next_1:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 2);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                func_002027A0();
                *(u8 *)(reg_a4 + 0x1B) = (u8) reg_d1.b[0];
                goto next_2;
            }
        } else {
next_2:
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            func_00201E20();
            D_0028E894 = reg_d2.h[0];
            D_0028E890 = reg_d3.h[0];
            func_00171400();
            t3 = 0xFA000000;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xF);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_tmp.w = reg_d4.w;
            reg_d4.h[1] = reg_tmp.h[0];
            reg_d4.h[0] = reg_tmp.h[1];
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x14);
            reg_tmp.w = reg_d5.w;
            reg_d5.h[1] = reg_tmp.h[0];
            reg_d5.h[0] = reg_tmp.h[1];
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x16);
            reg_d6.w = 0xFA000000;
            reg_d7.w = 7;
            reg_a1 = (u8 *)(D_00262A50);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d6.w;
                func_00129450();
                reg_d1.b[0] += 0x20;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xE);
            *(u8 *)(reg_a4 + 0xF) += reg_d1.b[0];
            *(u16 *)(reg_a4 + 0x18) += 1;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 4) += 1;
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 0xE) *= -1;
            *(u16 *)(reg_a4 + 0x18) = 0x12U;
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 8) -= 4;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
            reg_d0.h[0] += 1;
            if ((s32) reg_d0.h[0] > 2) {
                reg_d0.h[0] = 0;
            }
            *(u16 *)(reg_a4 + 0x1C) = (u16) reg_d0.h[0];
            reg_d0.h[0] += 2;
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                t2 = *(u8 *)(reg_a6 + 0x1EE);
                if ((s32) t2 < 4) {
                    *(u8 *)(reg_a6 + 0x1EE) = (u8) (t2 + 2);
                }
                reg_d0.w = 0xC;
                func_00125310();
            }
        }
    }
}

extern u16 D_00259770[];

void func_001ED980(void) {
    s32 func_00129450();
    u16 var_a0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x17)));
        reg_d4.w = 0;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(D_00259770);
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d3.w += reg_d6.w;
            func_00129450();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x16)));
        (*(u8 *)((u8 *)(reg_a4) + (0x17))) += reg_d1.b[0];
    }
}

extern u16 D_00259970[];

void func_001EDB00(void) {
    s32 func_00129450();
    u16 var_a0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
    (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0xFE000000;
        (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0x12)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x14)));
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d6.w = 0xFE000000;
        reg_d7.w = 3;
        reg_a1 = (u8 *)(D_00259970);
        reg_d4.w = 0;
        do {
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += 2;
            reg_d3.h[0] &= 0xFC;
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d3.w += reg_d6.w;
            func_00129450();
            var_a0 = (u32)reg_d1.h[0] + 0x40;
            reg_d1.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
        (*(u8 *)((u8 *)(reg_a4) + (0x1B))) += reg_d1.b[0];
    }
}

extern u16 D_00264590[];
extern u32 D_0028DA00;

void func_001EDC80(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264590);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028DA00 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x17))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x19))) = (u8) reg_d0.b[0];
    func_002011A0();
    (*(u8 *)((u8 *)(reg_a4) + (0x1B))) = (u8) reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x1FE))) = 5;
    (*(s8 *)((u8 *)(reg_a6) + (0x1FC))) = 8;
}

extern u16 D_00259870[];
extern s16 D_0028E890_as_s16;
extern s16 D_0028E894_as_s16;

void func_001EDD50(void) {
    s32 func_00129450();
    u8 *p;
    u8 t;

    func_001ED980();
    p = reg_a4 + 0x1C;
    switch (*(u16 *)p) { case 0: goto next_0; }
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1F800U) goto next_2;
next_0:
    func_001EDB00();
    p = reg_a4 + 0x1E;
    if (*(u16 *)p == 0) goto next_1;
    *(u16 *)p -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if ((u32)reg_tmp.w >= 0x1C000U) goto next_9;
next_1:
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_2;
    reg_a4[5] = reg_a4[4];
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x10);
    reg_d1.b[0] = reg_a4[0x19];
    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
    D_0028E894_as_s16 = 0;
    D_0028E890_as_s16 = 0;
    reg_d4.h[0] = 0x101;
    reg_tmp.w = reg_d4.w;
    reg_d4.h[1] = reg_tmp.h[0];
    reg_d4.h[0] = reg_tmp.h[1];
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1FE);
    reg_d5.w = 0x01010001;
    reg_d6.w = 0xFE000000;
    reg_d7.w = 9;
    reg_a1 = (u8 *)D_00259870;
loop_0:
    reg_d3.h[0] = reg_d1.h[0];
    reg_d3.h[0] += 2;
    reg_d3.h[0] &= 0xFC;
    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d3.w += reg_d6.w;
    func_00129450();
    reg_d1.h[0] += 0x19;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.b[0] = reg_a4[0x18];
    reg_a4[0x19] += reg_d1.b[0];
next_2:
    reg_tmp.b[0] = reg_a6[0x1FC];
    reg_a6[0x1FC] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a6[0x1FC] = 8;
    if (reg_a6[0x1FD] & 1) goto next_4;
    if ((s8)reg_a4[0x18] == -6) goto next_3;
    reg_a4[0x18] -= 1;
    goto next_7;
next_3:
    if (*(u16 *)(reg_a6 + 0x1FE) == 5) goto next_8;
    *(u16 *)(reg_a6 + 0x1FE) += 1;
    goto next_7;
next_4:
    if (reg_a4[0x18] == 6) goto next_5;
    reg_a4[0x18] += 1;
    goto next_7;
next_5:
    if ((s16)*(u16 *)(reg_a6 + 0x1FE) == -5) goto next_8;
    *(u16 *)(reg_a6 + 0x1FE) -= 1;
next_7:
    return;
next_8:
    reg_tmp.b[0] = reg_a4[9];
    reg_a4[9] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_9;
    reg_a4[9] = reg_a4[8];
    t = reg_a6[0x1FD];
    if (t & 1) {
        reg_a6[0x1FD] = t & 0xFE;
        goto next_9;
    }
    reg_a6[0x1FD] = t | 1;
next_9:
    return;
}
