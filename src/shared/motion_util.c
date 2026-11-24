#include "common.h"

void func_00201920(void);
void func_00201A00(void);
void func_00201B30(void);
void func_00201CC0(void);
void func_00201D10(void);
void func_00201F70();
void func_00201FE0(void);
void func_00202040(void);
void func_002021B0(void);
void func_002021D0(void);
void func_002021F0(void);
void func_002024C0(void);
void func_002024F0(void);
void func_00202500(void);
void func_00202760(void);
void func_00202780(void);
void func_002027A0(void);
void func_00202AE0(void);
void func_00202B30(void);
void func_00202B50(void);
void func_00202B70(void);
void func_00202C40(void);
void func_00202D00(void);
void func_002032A0(void);
void func_002032F0(void);
void func_00203630(void);
void func_00203660(void);
void func_002037B0(void);
void func_002037E0(void);

extern s8 D_0028E408;

s32 func_00201450();
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern u8 *D_0028E42C;
extern u8 *D_0028E430;
extern u8 *D_0028E434_as_u8_p;
extern u8 *D_0028E438_as_u8_p;
extern u8 *D_0028E43C;
extern u8 *D_0028E440;
extern u8 *D_0028E444_as_u8_p;
extern u8 D_0028E855;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00201710(void) {
    func_00201450();
    if (D_0028E408 == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        if (D_0028E855 & 2) {
            func_00201B30();
            return;
        }
        D_0028E428 = reg_d0.w;
        D_0028E424 = reg_d1.w;
        D_0028E420 = reg_d2.w;
        D_0028E41C = reg_d3.w;
        D_0028E418 = reg_d4.w;
        D_0028E414 = reg_d5.w;
        D_0028E410 = reg_d6.w;
        D_0028E40C = reg_d7.w;
        D_0028E444_as_u8_p = reg_a0;
        D_0028E440 = reg_a1;
        D_0028E43C = reg_a2;
        D_0028E438_as_u8_p = reg_a3;
        D_0028E434_as_u8_p = reg_a4;
        D_0028E430 = reg_a5;
        D_0028E42C = reg_a6;
        reg_d1.h[0] |= 0x8000;
        func_00201A00();
    }
}

extern s16 D_00299764_as_s16_a[];
extern s16 D_00299766_as_s16_a[];

void func_00201800(void) {
    func_00201450();
    if (D_0028E408 == 0) {
        D_00299766_as_s16_a[0] = 0;
        D_00299764_as_s16_a[0] = 1;
        if (D_0028E855 & 2) {
            func_00201B30();
            return;
        }
        D_0028E428 = reg_d0.w;
        D_0028E424 = reg_d1.w;
        D_0028E420 = reg_d2.w;
        D_0028E41C = reg_d3.w;
        D_0028E418 = reg_d4.w;
        D_0028E414 = reg_d5.w;
        D_0028E410 = reg_d6.w;
        D_0028E40C = reg_d7.w;
        D_0028E444_as_u8_p = reg_a0;
        D_0028E440 = reg_a1;
        D_0028E43C = reg_a2;
        D_0028E438_as_u8_p = reg_a3;
        D_0028E434_as_u8_p = reg_a4;
        D_0028E430 = reg_a5;
        D_0028E42C = reg_a6;
        reg_d1.h[0] |= 0x8000;
        func_00201A00();
    }
}


void func_002018E0(void) {
    if (!(D_0028E855 & 2)) {
        func_00201920();
        return;
    }
    func_00201B30();
}

extern s16 D_0029F1F0[];
extern u8 D_0029F1F1[];
extern s16 D_0029F260[];
extern u8 D_0029F261[];

void func_00201920(void) {
    D_0028E428 = reg_d0.w;
    D_0028E424 = reg_d1.w;
    D_0028E420 = reg_d2.w;
    D_0028E41C = reg_d3.w;
    D_0028E418 = reg_d4.w;
    D_0028E414 = reg_d5.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E444_as_u8_p = reg_a0;
    D_0028E440 = reg_a1;
    D_0028E43C = reg_a2;
    D_0028E438_as_u8_p = reg_a3;
    D_0028E434_as_u8_p = reg_a4;
    D_0028E430 = reg_a5;
    D_0028E42C = reg_a6;
    reg_d1.h[0] = 0x8000;
    if ((D_0029F260[0] < 0) && !(D_0029F261[0] & 1)) {
        reg_d1.h[0] |= 0x10;
    }
    if ((D_0029F1F0[0] < 0) && !(D_0029F1F1[0] & 1)) {
        reg_d1.h[0] |= 8;
    }
    func_00201A00();
}

s32 func_001A9180();
s32 func_001A9190();
extern s32 D_0028E42C_as_s32;
extern s32 D_0028E430_as_s32;
extern s32 D_0028E434;
extern s32 D_0028E438;
extern u16 *D_0028E43C_as_u16_p;
extern s32 D_0028E440_as_s32;
extern s32 D_0028E444;
extern u16 D_002962E0_as_u16_a[];

void func_00201A00(void) {
    u16 *var_a0;
    var_a0 = (u16 *)(D_002962E0_as_u16_a);
    reg_d2.w = 0;
    reg_a2 = (u8 *)(D_002962E0_as_u16_a);
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        reg_d0.h[0] = *(u16 *)reg_a2;
        if ((s16) reg_d0.h[0] < 0) {
            if (reg_d1.h[0] & 0x10) {
                reg_d0.w = 0x23;
                func_001A9180();
            }
            if (reg_d1.h[0] & 8) {
                reg_d0.w = 0x23;
                func_001A9190();
            }
        }
        var_a0 = (u16 *)(reg_a2 + 0x40);
        reg_a2 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = D_0028E428;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0 = (u8 *)D_0028E444;
    reg_a1 = (u8 *)D_0028E440_as_s32;
    reg_a2 = (u8 *)(D_0028E43C_as_u16_p);
    reg_a3 = (u8 *)D_0028E438;
    reg_a4 = (u8 *)D_0028E434;
    reg_a5 = (u8 *)D_0028E430_as_s32;
    reg_a6 = (u8 *)D_0028E42C_as_s32;
}

#pragma push
#pragma opt_propagation off

extern Reg32 reg_d0;
extern Reg32 reg_d1;
extern Reg32 reg_d2;
extern Reg32 reg_d3;
extern Reg32 reg_d4;
extern Reg32 reg_d5;
extern Reg32 reg_d6;
extern Reg32 reg_d7;

void func_00201B30(void) {
    u32 d5, d4, d3, d2, d1, d0, d7, d6;

    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    reg_d4.w = d4;
    reg_d5.w = d5;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d6.w = d6;
    reg_d7.w = d7;
}
#pragma pop

extern u16 D_0028E0E4[];
extern u16 D_0028E0E6[];
extern u16 D_0028E4AA;
extern u16 D_0028E8A0;

void func_00201B80(void) {
    if (D_0028E8A0 == 0) {
        D_0028E4AA = D_0028E0E4[0];
        reg_d0.h[0] = D_0028E0E6[0];
        reg_tmp.h[0] = reg_d0.h[0];
        reg_d0.h[0] = D_0028E4AA;
        D_0028E4AA = reg_tmp.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
    }
}

void func_00201BE0(void) {
    if (D_0028E8A0 == 0) {
        reg_d2.h[0] = D_0028E0E4[0];
        reg_d3.h[0] = D_0028E0E6[0];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}


void func_00201C20(void) {
    if (D_0028E8A0 == 0) {
        func_00201CC0();
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}


void func_00201C60(void)
{
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a6[0x1B];
    reg_d1.w = 0x3F;
    reg_d1.b[0] &= reg_a6[0x1A];

    if (D_0028E8A0 != 0) {
        reg_d2.w = 0;
        reg_d3.w = 0;
    } else {
        func_00201CC0();
    }
}


void func_00201CC0(void) {
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
}

extern u8 D_00262570[];
extern u8 D_00262572[];
extern u8 D_002671E0[];

void func_00201D10(void) {
    s32 t;

    reg_d1.h[0] *= 4;
    reg_d3.h[0] = *(s16 *)(D_002671E0 + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d3.w = (s32) reg_d3.w >> 4;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}

extern u8 D_00267660[];

void func_00201E20(void) {
    s32 t;

    reg_d3.h[0] = *(s16 *)(D_00267660 + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> 4;
    reg_d3.w = (s32) reg_d3.w >> 4;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}


void func_00201F20(void) {
    extern void func_00201F70(u8, void *);
    u8 temp_a0;

    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.w = 0;
    temp_a0 = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] = temp_a0;
    if (D_0028E8A0 != 0) {
        reg_d3.w = 0;
        reg_d2.w = 0;
        return;
    }
    func_00201F70(temp_a0, reg_a6);
}


void func_00201F70() {
    func_00201E20();
    (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
}

extern void *reg_a6_as_void_p;


void func_00201FC0(void) {
    u8 *base = (u8 *)reg_a6_as_void_p;

    reg_d0.w = 0;
    reg_d0.b[0] = base[0x1B];
    reg_d1.w = 0;
    reg_d1.b[0] = base[0x1A];
    func_00201FE0();
}


void func_00201FE0(void) {
    if (D_0028E8A0 == 0) {
        func_00202040();
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d2.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) += reg_d3.h[0];
        return;
    }
    reg_d2.w = 0;
    reg_d3.w = 0;
}

void func_00202040(void) {
    s32 t;

    reg_d3.h[0] = *(s16 *)(D_00267660 + reg_d1.h[0] * 2);
    t = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + t);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + t);
    reg_d2.w = (s32) reg_d2.w >> reg_d4.w;
    reg_d3.w = (s32) reg_d3.w >> reg_d4.w;
    reg_d1.h[0] &= 0xC0;
    switch (reg_d1.h[0]) {
    case 0x0:
        break;
    case 0x40:
        reg_d2.h[0] *= 0xFFFF;
        break;
    case 0x80:
        reg_d2.h[0] *= -1;
        reg_d3.h[0] *= 0xFFFF;
        break;
    case 0xC0:
        reg_d3.h[0] *= 0xFFFF;
        break;
    }
}


void func_00202140(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
        func_002021F0();
    }
}


void func_00202180(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        func_002021B0();
    }
}

extern void *reg_a0_as_void_p;


void func_002021B0(void) {
    u8 *base = (u8 *)reg_a0_as_void_p;
    reg_d2.h[0] = *(u16 *)(base + 0x2);
    reg_d3.h[0] = *(u16 *)(base + 0x4);
    func_002021D0();
}

extern u16 *reg_a6_as_u16_p;

void func_002021D0(void) {
    reg_d0.h[0] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    func_002021F0();
}

#pragma push
#pragma divbyzerocheck on
typedef void (*Fn)();

extern u8 D_00267120[];
extern u8 D_00267140[];
extern u8 D_00267150[];
extern u16 D_0028E484_as_u16;

void func_002021F0(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) D_0028E484_as_u16 < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 6;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d2.h[0] *= 2;
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d1.h[0] < (s32) reg_d2.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(D_00267150 + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(D_00267140 + (reg_d4.h[0] & ~1));
    ((Fn)*(u32 *)((u8 *)D_00267120 + (((s32) reg_d4.h[0] >> 1) * 4)))();
block_rts:
    return;
}
#pragma pop

void func_00202410(void) {
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] &= 0x3F;
}

void func_00202450(void) {
    reg_d1.h[0] += reg_d0.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] &= 0x3F;
}


void func_00202490(void) {
    func_00202180();
    if (D_0028E408 == 0) {
        func_002024C0();
    }
}


void func_002024C0(void) {
    func_002024F0();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
}


void func_002024F0(void) {
    *(u8 *)&reg_d0 = reg_a6[0x1A];
    func_00202500();
}

void func_00202500(void) {
    reg_d2.w = 0x3F;
    reg_d0.h[0] &= reg_d2.h[0];
    reg_d1.h[0] &= reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        reg_d1.h[0] &= reg_d2.h[0];
        if ((s32) reg_d1.h[0] >= 0x20) {
            reg_d0.b[0] -= 2;
        }
        reg_d0.h[0] &= reg_d2.h[0];
    }
    reg_d1.h[0] = reg_d0.h[0];
}

void func_00202590(void) {
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        if ((s32) reg_d1.b[0] >= 0x80) {
            reg_d0.b[0] -= 2;
        }
    }
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) reg_d1.b[0];
}

void func_002025E0(void) {
    u32 tmp;

    reg_d0.h[0] = reg_d0.b[0];
    reg_d1.h[0] = reg_d1.b[0];
    reg_d2.h[0] = reg_d1.h[0];
    reg_d5.h[0] -= 1;
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
    if (reg_d1.b[0] < 0x80) goto next_2;
    goto next_4;
loop_1:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_2:
    reg_d0.b[0] += 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d1.h[0] = reg_d0.h[0];
    return;
loop_3:
    reg_d1.h[0] = reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] == 0) goto block_5;
next_4:
    reg_d0.b[0] -= 1;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
block_5:
    reg_d1.h[0] = reg_d0.h[0];
}


void func_002026F0(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
        reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
        func_002027A0();
    }
}


void func_00202730(void) {
    func_002032A0();
    if (D_0028E408 == 0) {
        func_00202760();
    }
}

extern u16 *reg_a0_as_u16_p;


void func_00202760(void) {
    reg_d2.h[0] = reg_a0_as_u16_p[1];
    reg_d3.h[0] = reg_a0_as_u16_p[2];
    func_00202780();
}


void func_00202780(void) {
    reg_d0.h[0] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    func_002027A0();
}

#pragma push
#pragma divbyzerocheck on
extern u8 D_002670C0[];
extern u8 D_002670D0[];

void func_002027A0(void) {
    reg_d4.h[0] = 0x1800;
    reg_d0.h[0] += reg_d4.h[0];
    reg_d1.h[0] += reg_d4.h[0];
    reg_d2.h[0] += reg_d4.h[0];
    reg_d3.h[0] += reg_d4.h[0];
    reg_d4.w = 8;
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] -= reg_d3.h[0];
    if ((s32) D_0028E484_as_u16 < (s32) reg_d3.h[0]) {
        reg_d4.w = 0;
        reg_d1.h[0] *= 0xFFFF;
    }
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) {
        reg_d0.h[0] *= 0xFFFF;
        reg_d4.h[0] += 4;
    }
    reg_d2.h[0] = reg_d1.h[0];
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
    reg_d1.h[0] += reg_d2.h[0];
    if (!((s32) reg_d0.h[0] > (s32) reg_d1.h[0])) goto next_1;
    reg_d4.h[0] += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.w = reg_d1.w;
    reg_d1.w = reg_tmp.w;
next_1:
    reg_d0.h[1] = 0;
    if (reg_d1.h[0] == 0) goto block_rts;
    reg_d0.w <<= 5;
    reg_d2.h[0] = reg_d0.w % reg_d1.h[0];
    reg_d0.w = reg_d0.w / (u32) (u16) reg_d1.h[0];
    reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
    reg_d0.h[0] *= 2;
    if (!((s32) reg_d2.h[0] > (s32) reg_d1.h[0])) goto next_2;
    reg_d0.h[0] += 1;
next_2:
    reg_d0.b[0] = *(s8 *)(D_002670D0 + reg_d0.h[0]);
    reg_d1.h[0] = *(s16 *)(D_002670C0 + (reg_d4.h[0] & ~1));
    switch ((s32) reg_d4.h[0] >> 1) {
    case 0:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 1:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 2:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 3:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 4:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 5:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 6:
        reg_d1.h[0] += reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    case 7:
        reg_d1.h[0] -= reg_d0.h[0];
        reg_d1.h[0] = reg_d1.b[0];
        break;
    }
block_rts:
    return;
}
#pragma pop

extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];


void func_00202A80(void)
{
    s16 firstResult;

    reg_a0 = D_0029F260_as_u8_a;
    func_00202AE0();
    firstResult = (s16)reg_d0.h[0];

    reg_a0 = D_0029F1F0_as_u8_a;
    func_00202AE0();
    reg_d1.h[0] = (u16)firstResult;

    if (reg_d0.h[0] > reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
    }
}

extern s16 *reg_a0_as_s16_p;

void func_00202AE0(void) {
    reg_d0.h[0] = 0x7FFF;
    if (*reg_a0_as_s16_p >= 0) {
        func_00202C40();
        return;
    }
    func_00202B30();
}


void func_00202B30(void) {
    reg_d2.h[0] = reg_a0_as_u16_p[1];
    reg_d3.h[0] = reg_a0_as_u16_p[2];
    func_00202B50();
}


void func_00202B50(void) {
    reg_d0.h[0] = reg_a6_as_u16_p[1];
    reg_d1.h[0] = reg_a6_as_u16_p[2];
    func_00202B70();
}

void func_00202B70(void) {
    u32 temp_a0;
    u32 temp_a1;

    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    temp_a1 = reg_d0.h[0];
    reg_d4.h[0] = temp_a1;
    reg_d4.h[0] >>= 2;
    reg_d1.h[0] -= reg_d3.h[0];
    temp_a0 = temp_a1 - reg_d4.h[0];
    reg_d0.h[0] = temp_a0;
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
        reg_tmp.w = reg_d0.w;
        reg_d0.w = reg_d1.w;
        reg_d1.w = reg_tmp.w;
    }
    reg_d1.h[0] >>= 1;
    reg_d0.h[0] += reg_d1.h[0];
    func_00202C40();
}

extern u8 D_0028E408_as_u8;

void func_00202C40(void) {
    D_0028E408_as_u8 = 0;
}


void func_00202C50(void) {
    s16 *temp_s0;

    reg_d0.h[0] = 0x7FFF;
    reg_a0 = (u8 *)(D_0029F260);
    reg_d1.h[0] = reg_d0.h[0];
    if (*(s16 *)reg_a0 < 0) {
        func_00202D00();
    }
    temp_s0 = (s16 *)(reg_a0);
    reg_a0 = (u8 *)(D_0029F1F0);
    if (*(s16 *)reg_a0 < 0) {
        reg_d1.h[0] = reg_d0.h[0];
        func_00202D00();
        reg_a1 = (u8 *)(reg_a0);
    }
    reg_a0 = (u8 *)(temp_s0);
    if ((s32) reg_d0.h[0] > (s32) reg_d1.h[0]) {
        reg_d0.h[0] = reg_d1.h[0];
        reg_a0 = (u8 *)(reg_a1);
    }
}

void func_00202D00(void) {
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[0] -= reg_d2.h[0];
    if (((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    D_0028E408 = 0;
}

extern u8 D_00267030[];
extern u8 D_00267050[];
extern u8 D_00267070[];
extern u8 D_00267090[];
extern Reg32 D_0028E484;
extern u16 D_0028E910;
extern u16 D_0028E914;


void func_00202D50(void) {
    u8 *save_a0;
    u32 save_d0;
    u32 save_d1;

    save_d1 = reg_d1.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267030;
    if (D_0028E910 == 0) goto next_1;
    reg_a0 = (u8 *)D_00267070;
next_1:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
    if (D_0028E484.h[1] != 0) goto next_3;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267050;
    if (D_0028E910 == 0) goto next_2;
    reg_a0 = (u8 *)D_00267090;
next_2:
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
next_3:
    D_0028E408 = 0;
    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
}

void func_00202F50(void) {
    u8 *save_a0;
    u32 save_d0;
    u32 save_d1;

    save_d1 = reg_d1.w;
    save_d0 = reg_d0.w;
    save_a0 = reg_a0;
    reg_d0.h[0] = D_0028E914;
    reg_a0 = (u8 *)D_00267030;
    reg_d0.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.h[0] = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
    reg_tmp.w = 0;
    D_0028E484.w = 0;
    reg_d1.h[0] -= reg_d0.h[0];
    reg_tmp.h[0] = reg_d0.h[1];
    D_0028E484.h[0] = reg_d1.h[0];
    D_0028E484.w += reg_tmp.w;
    reg_d1.h[0] += reg_d0.h[1];
    D_0028E408 = 0;
    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_a0 = save_a0;
}

extern u16 D_0029C068[];


void func_00203060(void) {
    reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x9000;
    D_0028E484.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += (s16) D_0029C068[0];
    D_0028E484.h[0] = reg_d0.h[0];
    D_0028E484.w += reg_tmp.w;
    if (D_0028E484.h[1] == 0) {
        reg_tmp.w = 0;
        reg_tmp.h[0] = 0x8000;
        D_0028E484.w = 0;
        reg_d0.h[1] += 0x800;
        D_0028E484.h[0] = reg_d0.h[1];
        D_0028E484.w += reg_tmp.w;
    }
    D_0028E408 = 0;
    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
    }
}

void func_00203120(void) {
    reg_d0.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x9000;
    D_0028E484.w = 0;
    reg_d0.h[0] += 0x1C00;
    reg_d0.h[0] += (s16) D_0029C068[0];
    D_0028E484.h[0] = reg_d0.h[0];
    D_0028E484.w += reg_tmp.w;
    if (D_0028E484.h[1] != 0) goto next_1;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x7000;
    D_0028E484.w = 0;
    reg_d0.h[1] += 0x1000;
    D_0028E484.h[0] = reg_d0.h[1];
    D_0028E484.w += reg_tmp.w;
next_1:
    D_0028E408 = 0;
    if (D_0028E484.h[1] == 0) return;
    D_0028E408 = 1;
}

void func_002031E0(void) {
    reg_d0.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 4);
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xB000;
    D_0028E484.w = 0;
    reg_d0.h[0] += 0xC00;
    reg_d0.h[0] += (s16) D_0029C068[0];
    D_0028E484.h[0] = reg_d0.h[0];
    D_0028E484.w += reg_tmp.w;
    if (D_0028E484.h[1] != 0) goto next_1;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x8400;
    D_0028E484.w = 0;
    reg_d0.h[1] += 0x600;
    D_0028E484.h[0] = reg_d0.h[1];
    D_0028E484.w += reg_tmp.w;
next_1:
    D_0028E408 = 0;
    if (D_0028E484.h[1] == 0) return;
    D_0028E408 = 1;
}


extern u32 D_0028E448_as_u32;
extern u32 reg_a0_as_u32;
extern u32 reg_a1_as_u32;
extern u32 reg_a5_as_u32;

void func_002032A0(void)
{
    reg_a0_as_u32 = (u32)D_0029F260_as_u8_a;
    D_0028E408 = 0;
    reg_a1_as_u32 = (u32)D_0029F1F0_as_u8_a;

    if (((u8 *)reg_a5_as_u32)[2] != 0) {
        D_0028E448_as_u32 = reg_a1_as_u32;
        reg_a1_as_u32 = reg_a0_as_u32;
        reg_a0_as_u32 = D_0028E448_as_u32;
    }

    func_002032F0();
}

extern s16 *D_0028E44C;
extern s16 *reg_a1_as_s16_p;

void func_002032F0(void) {
    s16 *temp_a0;

    temp_a0 = reg_a0_as_s16_p;
    if (*temp_a0 >= 0) {
        if (*reg_a1_as_s16_p >= 0) {
            D_0028E408 = 1;
            return;
        }
        reg_a0_as_s16_p = reg_a1_as_s16_p;
        D_0028E44C = temp_a0;
        reg_a1_as_s16_p = temp_a0;
        goto block_4;
    }
block_4:
    D_0028E408 = 0;
}

extern s32 *D_0028E448_as_s32_p;
extern s32 D_0029F1F0_as_s32_a[];
extern s32 D_0029F260_as_s32_a[];
extern s32 *reg_a0_as_s32_p;
extern s32 *reg_a1_as_s32_p;

void func_00203330(void) {
    reg_a0_as_s32_p = D_0029F260_as_s32_a;
    reg_a1_as_s32_p = D_0029F1F0_as_s32_a;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x2B))) != 0) {
        D_0028E448_as_s32_p = reg_a1_as_s32_p;
        reg_a1_as_s32_p = reg_a0_as_s32_p;
        reg_a0_as_s32_p = D_0028E448_as_s32_p;
    }
    func_002032F0();
}

void func_00203380(void) {
    reg_d1.b[0] = D_0029F261[0];
    reg_d0.w = 0;
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & (1 << reg_d0.h[0]))) {
        reg_d0.w = 1;
    }
    reg_d1.b[0] = D_0029F1F1[0];
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & 1)) {
        reg_d0.h[0] += 2;
    }
}

void func_00203400(void) {
    reg_d0.w = 0;
    if ((D_0029F260[0] < 0) && !(D_0029F261[0] & 1)) {
        reg_d0.w = 0x10;
    }
    if ((D_0029F1F0[0] < 0) && !(D_0029F1F1[0] & 1)) {
        reg_d0.h[0] += 8;
    }
}

s32 func_0018DEE0();
extern s16 D_0028DFC4_as_s16;
extern u8 D_0029F22F[];
extern u8 D_0029F29F[];
void func_00203460(void) {
    func_0018DEE0();
    D_0028DFC4_as_s16 = 1;
    if (D_0029F260[0] < 0) {
        D_0029F29F[0] = 0xFF;
    }
    if (D_0029F1F0[0] < 0) {
        D_0029F22F[0] = 0xFF;
    }
}

s32 func_0018D390();
s32 func_0020ECE0();
extern s16 D_0028DFBC_as_s16;
void func_002034C0(void) {
    func_0020ECE0();
    func_0018D390();
    D_0028DFBC_as_s16 = 1;
    D_0028E855 |= 8;
    D_0028E855 &= 0xEF;
    if (*(s16 *)D_0029F260 < 0) goto block_1;
    if (!(D_0029F261[0] & 1)) goto next_1;
    if (*(u8 *)D_0029F260 & 0x80) goto next_1;
block_1:
    D_0029F261[0] |= 0x20;
next_1:
    if (*(s16 *)D_0029F1F0 < 0) goto block_2;
    if (!(D_0029F1F1[0] & 1)) goto next_2;
    if (*(u8 *)D_0029F1F0 & 0x80) goto next_2;
block_2:
    D_0029F1F1[0] |= 0x20;
next_2:
    return;
}

extern u16 g_stage;

void func_002035A0(void) {
    func_002034C0();
    reg_d7.h[0] = g_stage;
    reg_d7.h[0] += 1;
    if ((s32) reg_d7.h[0] >= 5) {
        reg_d7.w = 0;
    }
    func_00203630();
}

s32 func_00125DE0();                            /* extern */

void func_002035F0(void) {
    func_00203660();
    func_00125DE0();
    func_002034C0();
    func_00203630();
}

s32 func_002071C0();                            /* extern */

void func_00203630(void) {
    reg_d0.h[0] = 6;
    func_002071C0();
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d7.h[0];
}

void func_0014DBF0(void);

void func_00203660(void) {
    func_0014DBF0();
}

s32 func_0016A8C0();
extern s8 D_002670B0[];

void func_00203670(void) {
    func_0016A8C0();
    reg_d0.h[0] &= 0xF;
    *(s8 *)(reg_a6 + 0x1A) = D_002670B0[reg_d0.h[0]];
    if (*(s8 *)(reg_a6 + 0x1A) >= 0) {
        func_00201C60();
        return;
    }
    *(s8 *)(reg_a6 + 0x1A) = 0x40;
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
}


void func_002036F0(void) {
    u16 temp_a0;

    D_0028E408 = 0;
    reg_a0 = D_0029F260_as_u8_a;
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) & 1) {
        reg_a0 = D_0029F1F0_as_u8_a;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (4)));
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] -= 0x1C00;
    temp_a0 = (u32)reg_d6.h[0] + 0x800;
    reg_d6.h[0] = temp_a0;
    if ((s32) reg_tmp.h[0] >= 0x1C00) {
        func_002037E0();
        return;
    }
    reg_tmp.h[0] = reg_d6.h[0];
    reg_d6.h[0] -= 0x2400;
    if ((s32) reg_tmp.h[0] < 0x2400) {
        func_002037B0();
    }
}

void func_002037B0(void) {
    u32 scaled = (u32)reg_d6.h[0] << 16;
    reg_d6.h[0] = (u16)(scaled - reg_d6.h[0]);
    reg_d6.h[0] += 0x1C00;
    *(u16 *)((u8 *)reg_a6_as_void_p + 4) = reg_d6.h[0];
}


void func_002037E0(void) {
    Reg32 *temporaryRegister = &reg_tmp;
    Reg32 *dataRegister6 = &reg_d6;
    u32 originalD6;
    u32 adjustment;

    temporaryRegister->w = 0;
    temporaryRegister->h[0] = 0x2400;
    D_0028E484.w = 0;
    originalD6 = dataRegister6->h[0];
    adjustment = temporaryRegister->w;
    D_0028E484.h[0] = originalD6;
    D_0028E484.w -= adjustment;
    dataRegister6->h[0] = originalD6 - 0x2400;

    if (D_0028E484.h[1] != 0) {
        D_0028E408 = 1;
        return;
    }

    func_002037B0();
    reg_d0.w = -1;
    D_0028E408 = 1;
}
