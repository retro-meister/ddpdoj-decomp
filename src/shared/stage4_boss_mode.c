#include "common.h"
#include "entity.h"

void func_001E5BE0(void);
void func_001E5C60();
void func_001E62B0();
void func_001E6540();
void func_001E6B40(void);

s32 func_0013A780();

void func_001E58E0(void) {
    u16 *temp_a1_2;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0013A780();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        temp_a1_2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(temp_a1_2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
        reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
        reg_d0.b[0] += reg_d0.b[0];
        reg_d0.b[0] += reg_d0.b[0];
        *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
        reg_a1 += 2;
        func_001E58E0();
    }
}

s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();

void func_001E5A20(void) {
    u16 temp_a0;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        func_0013A780();
        temp_a0 = *(u16 *)reg_a1;
        reg_d0.h[0] = temp_a0;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        *(u16 *)(reg_a0 + 0x26) += reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        *(u16 *)(reg_a0 + 0x28) += reg_d0.h[0];
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 0x10;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        func_002010A0();
        reg_d0.b[0] += 0x10;
        *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
        func_002011A0();
        *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
        reg_a1 += 2;
        func_001E5A20();
    }
}

s32 func_00124D90();                            /* extern */
s32 func_00124DC0();                            /* extern */
s32 func_001A3020();                            /* extern */
extern s32 D_0025FF30_as_s32_a[];
extern s32 *reg_a0_as_s32_p;

void func_001E5B90(void) {
    reg_d0.h[0] = 0x15;
    reg_a0_as_s32_p = D_0025FF30_as_s32_a;
    func_001A3020();
    reg_d0.w = 0;
    func_00124D90();
    reg_d0.w = 0xA;
    func_00124DC0();
    func_001E5BE0();
}

extern u16 *reg_a4_as_u16_p;

void func_001E5BE0(void) {
    *reg_a4_as_u16_p = 0;
}

s32 func_00124D90();
s32 func_001E8700();
s32 func_001E8760();

void func_001E5BF0(void) {
    func_001E8700();
    reg_d0.h[0] = 0x40;
    func_001E8760();
    reg_d0.h[0] = 0x60;
    func_001E8760();
    reg_d0.w = 2;
    func_00124D90();
    *(s8 *)(reg_a4 + 3) = 0;
    *(u16 *)(reg_a4 + 4) = 1;
    *(u16 *)(reg_a4 + 6) = 0xFF02;
    *(u16 *)(reg_a4 + 8) = 0xFF04;
    func_001E5C60(0xFF02, 1);
}

s32 func_00124F00();
s32 func_0013AB50();
s32 func_0018D4E0();
s32 func_0018D500();
s32 func_0018D560();
s32 func_0018D580();
extern u8 D_0026F260[];
extern u8 D_0026F280[];
extern u8 D_0026F290[];
extern u8 D_0026F2D0[];

void func_001E5C60() {
    u16 temp_a0_4;
    u16 temp_a0_5;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;

    temp_a0 = *(u8 *)(reg_a4 + 7);
    if (temp_a0 != -1) {
        reg_tmp.b[0] = temp_a0;
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 1;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x102);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0x104);
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) -= 0x200;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 9);
    if (temp_a0_2 != -1U) {
        reg_tmp.b[0] = temp_a0_2;
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0xC2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0xC4);
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) -= 0x400;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0xE2);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0xE4);
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) -= 0x400;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) < 0) {
            *(u8 *)(reg_a4 + 7) = 0U;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x102);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x104);
            reg_a1 = (u8 *)D_0026F260;
            func_001E58E0();
            reg_d0.w = 5;
            func_00124F00();
            func_0018D560();
            *(u16 *)(reg_a4 + 4) = 8U;
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) < 0) {
            *(u8 *)(reg_a4 + 9) = 0U;
            func_002011A0();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0xC2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC4);
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0xC2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0xC4);
            reg_a1 = (u8 *)D_0026F280;
            func_001E58E0();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0xE2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0xE4);
            reg_a1 = (u8 *)D_0026F280;
            func_001E58E0();
            reg_d0.w = 3;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            func_0018D4E0();
            *(u16 *)(reg_a4 + 4) = 8U;
            *(u8 *)(reg_a4 + 3) = 2U;
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 2) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) < 0) {
            func_0018D500();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x64);
            reg_a1 = (u8 *)D_0026F290;
            func_001E58E0();
            reg_d0.w = 2;
            func_00124F00();
            *(u16 *)(reg_a4 + 4) = 0x60U;
            *(u8 *)(reg_a4 + 3) = 3U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 3) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) < 0) {
            *(u8 *)(reg_a4 + 7) = 0xFFU;
            *(u8 *)(reg_a4 + 9) = 0xFFU;
            func_002010A0();
            reg_d0.b[0] = (s8) reg_d0.b[0] * 2;
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0x30;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
            temp_a0_4 = *(u16 *)(reg_a6 + 0x64);
            reg_d2.h[0] = temp_a0_4;
            reg_d2.w += 0xF0000400;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            func_002010A0();
            reg_d1.b[0] = reg_d0.b[0];
            reg_d1.b[0] += 0xD0;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x62);
            temp_a0_5 = *(u16 *)(reg_a6 + 0x64);
            reg_d2.h[0] = temp_a0_5;
            reg_d2.w += 0xEBFFFC00;
            reg_d3.h[0] = 0x10;
            reg_d0.h[0] = 0;
            func_0013AB50();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x42);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x44);
            reg_a1 = (u8 *)D_0026F2D0;
            func_001E58E0();
            reg_d0.w = 1;
            func_00124F00();
            reg_d0.w = 3;
            func_00124D90();
            func_0018D580();
            *(s16 *)reg_a4 = 0;
        }
    }
}

s32 func_0013B8B0();
extern u8 D_0026F340[];

void func_001E6210(void) {
    reg_d0.w = 5;
    func_00124D90();
    reg_a0 = D_0026F340;
    func_0013B8B0();
    *(s8 *)(reg_a4 + 3) = 0;
    *(u16 *)(reg_a4 + 4) = 0x10;
    *(u16 *)(reg_a4 + 6) = 0xFF02;
    *(u16 *)(reg_a4 + 8) = 0xFF04;
    *(u16 *)(reg_a4 + 0xA) = 0;
    *(u16 *)(reg_a4 + 0xC) = 0xC0C;
    *(u16 *)(reg_a4 + 0xE) = 3;
    *(u16 *)(reg_a4 + 0x10) = 4;
    *(u16 *)(reg_a4 + 0x12) = 0;
    func_001E62B0(3, 0xC0C, 0xFF04, 0xFF02);
}

s32 func_00124510();

void func_001E62B0() {
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a1_2;

    temp_a1 = *(u8 *)(reg_a4 + 7);
    if (((s64) ((s64) temp_a1 << 0x38) >> 0x38) != -1) {
        reg_tmp.b[0] = temp_a1;
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 1;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x22);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0x24);
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) -= 0x200;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) += 0x7FFF + 0x7801;
            *(u16 *)(reg_a0 + 0x28) += 0x400;
        }
    }
    temp_a1_2 = *(u8 *)(reg_a4 + 9);
    if (((s64) ((s64) temp_a1_2 << 0x38) >> 0x38) != -1) {
        reg_tmp.b[0] = temp_a1_2;
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.w = 0x10;
            func_0013A780();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            func_002010A0();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x22);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0x24);
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) -= 0x400;
            func_002012F0();
            reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 3);
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_d0.h[0];
            *(u16 *)(reg_a0 + 0x26) += 0x7FFF + 0x7801;
            *(u16 *)(reg_a0 + 0x28) += 0x7FFF + 0x7A01;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 != 5) {
        func_001E6540();
        return;
    }
    *(u16 *)(reg_a4 + 4) -= 1;
    if (*(u16 *)(reg_a4 + 4) == 0) {
        func_00124510();
        *(s16 *)reg_a4 = 0;
    }
}


s32 func_00125410();
s32 func_00125440();
s32 func_0013B2E0();
s32 func_0018D660();
extern u8 D_0026F320[];
extern u16 D_0026F350[];
extern u16 D_0026F3A0[];

void func_001E6540(arg1)
    s32 arg1;
{
    s32 var_a1;
    u16 *temp_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_5;
    u16 temp_v1;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u32 var_a0;

    var_a1 = arg1;
    if (*(u8 *)(reg_a4 + 3) == 4) {
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_a1 = (u8 *)(D_0026F350);
        func_001E58E0();
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_a1 = (u8 *)(D_0026F350);
        func_001E5A20();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x10;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        temp_a0 = *(u16 *)(reg_a6 + 0x24);
        reg_d2.h[0] = temp_a0;
        reg_d2.w += 0xF8000400;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013AB50();
        func_002010A0();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 2;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xF0;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
        temp_a0_2 = *(u16 *)(reg_a6 + 0x24);
        reg_d2.h[0] = temp_a0_2;
        reg_d2.w += 0x01FFFA00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        func_0013AB50();
        func_0018D660();
        var_a1 = 5;
        *(u8 *)(reg_a4 + 3) = 5U;
        *(u16 *)(reg_a4 + 4) = 0x80U;
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 3) {
        func_00125440();
        if (cond_flag == 0) {
            reg_a0 = (u8 *)D_0026F320;
            func_0013B2E0();
            *(u8 *)(reg_a4 + 3) = 4U;
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 2) {
        func_001E6B40();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += *(u16 *)(reg_a4 + 0xA);
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
            temp_a1 = (u16 *)(reg_a1 + 2);
            reg_a1 = (u8 *)(temp_a1);
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x22);
            temp_a0_5 = *(u16 *)(reg_a6 + 0x24);
            *(u16 *)(reg_a0 + 4) = temp_a0_5;
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            func_002010A0();
            reg_d0.b[0] += 0x10;
            *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
            func_002011A0();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a4 + 0xA) += 0xC;
            if (*(u16 *)(reg_a4 + 0xA) == 0x48) {
                *(u16 *)(reg_a4 + 0xA) = 0U;
                *(u16 *)(reg_a4 + 0xE) -= 1;
                if (*(u16 *)(reg_a4 + 0xE) == 0) {
                    *(u8 *)(reg_a4 + 3) = 3U;
                    reg_d0.w = 9;
                    func_00124F00();
                    reg_d0.h[0] = 0x12;
                    func_00125410();
                    *(u8 *)(reg_a4 + 7) = 0xFF;
                    *(u8 *)(reg_a4 + 9) = 0xFF;
                }
            }
        }
    }
    var_a0 = *(u8 *)(reg_a4 + 3);
    if ((var_a0 == 1) && ((temp_v1 = *(u16 *)(reg_a4 + 4), var_a0 = (u32) (reg_a4 + 4), (temp_v1 == 0)) || (*(u16 *)var_a0 = (s16) (temp_v1 - 1), (*(u16 *)(reg_a4 + 4) == 0)))) {
        func_001E6B40();
        var_a0 = (u32) (reg_a4);
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0) + (0xD)));
        (*(u8 *)((u8 *)(var_a0) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            reg_a1 = (u8 *)(D_0026F3A0);
            reg_a1 += *(u16 *)(reg_a4 + 0xA);
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            func_0013A780();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a6 + 0x22);
            *(u16 *)(reg_a0 + 4) = (u16) *(u16 *)(reg_a6 + 0x24);
            *(s16 *)(reg_a0 + 0x1E) = 0x10;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0;
            *(u8 *)(reg_a0 + 0x1B) = (u8) ENTITY(reg_a6)->move.b.speed;
            reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
            reg_d0.b[0] += reg_d0.b[0];
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a4 + 0xA) += 0xC;
            var_a0 = *(u16 *)(reg_a4 + 0xA);
            if (var_a0 == 0x48) {
                *(u16 *)(reg_a4 + 0xA) = 0U;
                var_a0 = 8;
                *(u16 *)(reg_a4 + 0xC) = 0x606;
                *(u8 *)(reg_a4 + 3) = 2U;
                *(s16 *)(reg_a4 + 0x10) = 8;
                *(s16 *)(reg_a4 + 0x12) = 0;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        func_001E6B40();
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) < 0) {
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x22);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x24);
            reg_a1 = (u8 *)(D_0026F350);
            func_001E58E0();
            *(s8 *)(reg_a4 + 7) = 0;
            *(s8 *)(reg_a4 + 9) = 0;
            *(u16 *)(reg_a4 + 4) = 0x50U;
            *(u8 *)(reg_a4 + 3) = 1U;
            *(s16 *)(reg_a4 + 0x10) = 0x10;
            *(s16 *)(reg_a4 + 0x12) = 0;
        }
    }
}

typedef void (*Fn)();

extern u8 D_0026F240[];

void func_001E6B40(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x11);
    *(u8 *)(reg_a4 + 0x11) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 0x11) = (u8) *(u8 *)(reg_a4 + 0x10);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
        ((Fn)*(u32 *)((u8 *)D_0026F240 + (reg_tmp.h[0] & ~3)))();
        *(u16 *)(reg_a4 + 0x12) += 4;
        *(u16 *)(reg_a4 + 0x12) &= 0x1F;
    }
}
