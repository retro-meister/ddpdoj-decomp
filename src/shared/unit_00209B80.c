#include "common.h"
#include "sdk/ps2sdk.h"

void func_0020A370(void);
void func_0020A3B0(void);
void func_0020AAA0(void);
void func_0020B5F0(void);
void func_0020B640(void);


s32 func_0016A8D0();
s32 func_0018DA30();
s32 func_0018DA50();
s32 func_002093F0();
s32 func_00209710();
s32 func_00209790();
s32 func_00209880();
s32 func_00209AF0();
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern u8 D_0028E390;
extern u8 D_0028E394;
extern u8 D_0028E398;
extern u8 D_0028E39C;

void func_00209B80(void) {
    s64 temp_v1;
    s64 temp_v1_2;

    func_0016A8D0();
    if (reg_d0.w & 1) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_00209710();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 4;
        }
        func_00209790();
    }
    func_0016A8D0();
    if (reg_d0.w & 2) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_00209710();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 4) {
            D_0028DFA0 = 0;
        }
        func_00209790();
    }
    func_0016A8D0();
    if (reg_d0.w & 4) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E39C -= 1;
            if (0 > (s8) D_0028E39C) {
                D_0028E39C = 0x12;
            }
        }
        temp_v1 = D_0028DFA0;
        if (temp_v1 == 1) {
            D_0028E398 -= 1;
            D_0028E398 &= 1;
        }
        if (temp_v1 == 2) {
            D_0028E394 -= 1;
            D_0028E394 &= 1;
        }
        if (temp_v1 == 3) {
            D_0028E390 -= 1;
            if (0 > (s8) D_0028E390) {
                D_0028E390 = 2;
            }
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 8) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E39C += 1;
            if ((s8) D_0028E39C >= 0x13) {
                D_0028E39C = 0;
            }
        }
        temp_v1_2 = D_0028DFA0;
        if (temp_v1_2 == 1) {
            D_0028E398 += 1;
            D_0028E398 &= 1;
        }
        if (temp_v1_2 == 2) {
            D_0028E394 += 1;
            D_0028E394 &= 1;
        }
        if (temp_v1_2 == 3) {
            D_0028E390 += 1;
            if ((s8) D_0028E390 >= 3) {
                D_0028E390 = 0;
            }
        }
    }
    func_0016A8D0();
    if ((reg_d0.w & 0x10) && (D_0028DFA0 == 4)) {
        func_0018DA30();
        reg_d0.w = 0;
        func_002093F0();
    } else if (D_0028DF9C != 0) {
        D_0028DF9C = 0;
        func_00209880();
        func_00209AF0();
    }
    cond_flag = 0;
}

extern u8 D_00299D30[];

void func_00209E60(void) {
    memset(&D_00299D30[0], 0, 0x7FC);
}

extern u16 D_0029A528[];

void func_00209E80(void) {
    *(u16 *)((u8 *)reg_a6 - 2) = 0;
    D_0029A528[0] -= 1;
}

extern void *reg_a6_as_void_p;

void func_00209EA0(void) {
    *(u16 *)((u8 *)reg_a6_as_void_p - 4) = 0;
    D_0029A528[0] -= 1;
}

void func_00209EC0(void) {
    *(u16 *)(reg_a6 - 8) = 0;
    D_0029A528[0] -= 1;
}

extern s32 reg_a4_as_s32;
extern s32 D_0028E570_as_s32;
extern u16 D_0028E160;

void func_00209EE0(void) {
    reg_a4_as_s32 -= D_0028E570_as_s32;
    reg_tmp.sw = reg_a4_as_s32;
    D_0028E160 = reg_tmp.h[0];
}


void func_00209F10(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u8 D_00251120[];
extern u32 reg_save4_d7;
extern u32 reg_save4_d6;
extern u32 reg_save4_d5;
extern u32 reg_save4_d4;
extern u32 reg_save4_d3;
extern u32 reg_save4_d2;
extern u32 reg_save4_d1;
extern u32 reg_save4_d0;
extern u8 *reg_save4_a6;
extern u8 *reg_save4_a5;
extern u8 *reg_save4_a4;
extern u8 *reg_save4_a3;
extern u8 *reg_save4_a2;
extern u8 *reg_save4_a1;
extern u8 *reg_save4_a0;
extern u16 D_0028E910;
extern u8 D_0029A12C[];
extern u8 D_0029F260_as_u8_a[];

void func_00209F20(void) {
    if (D_0028E910 != 0) {
        func_00209F10();
        return;
    }
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    *(u8 *)&rng_cursor += 1;
    reg_d5.h[0] = rng_cursor;
    reg_d1.w = 0;
    reg_a2 = *(u8 **)(D_00251120 + reg_d5.h[0] * 4);
    reg_a0 = (u8 *)D_00299D30;
    if (D_0029F260_as_u8_a == reg_a4) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

extern u8 D_00250E00[];
extern void *reg_save4_a6_as_void_p;

void func_0020A040(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6_as_void_p = reg_a6;
    reg_d7.w = 0;
    reg_d1.w = 1;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_00299D30;
    reg_d0.w = 0;
    if (*(u16 *)(reg_a6 + 0x1A) != 0) {
        func_0020A370();
        return;
    }
    reg_d7.w = 1;
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

void func_0020A120(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_00299D30;
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d7.w = 0;
    func_0020A370();
}

void func_0020A1C0(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_0029A12C;
    reg_d7.w = 1;
    reg_d1.w = 0;
    reg_d0.w = 0;
    func_0020A370();
}

s32 func_00201230();
extern u8 D_00250D88[];
extern u8 D_0029CEA0_as_u8_a[];

void func_0020A270(void) {
    s32 temp_a1;
    s32 temp_a2;

    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = (u8 *)(reg_a0);
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_d1.w = 0;
    func_00201230();
    temp_a2 = reg_d0.h[0] * 4;
    temp_a1 = *(u32 *)(D_00250D88 + temp_a2);
    reg_a2 = (u8 *)temp_a1;
    reg_d7.h[0] = 0xFFFF;
    reg_a0 = (u8 *)D_00299D30;
    reg_d0.w = 0;
    if (!(D_0029CEA0_as_u8_a[0] & 0x80)) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

extern u16 D_0028E928;

void func_0020A370(void) {
    reg_d2.w = 0x1D;
    if (D_0028E928 != 0) {
        func_0020A3B0();
        return;
    }
    reg_d2.w = 0xE;
    func_0020A3B0();
}

extern s32 reg_save4_a6_as_s32;
extern s32 reg_save4_a5_as_s32;
extern s32 reg_save4_a4_as_s32;
extern s32 reg_save4_a3_as_s32;
extern s32 reg_save4_a2_as_s32;
extern s32 reg_save4_a1_as_s32;
extern u16 *reg_save4_a0_as_u16_p;

void func_0020A3B0(void) {
    u32 t;

loop_1:
    if (*(u16 *)reg_a0 == 0) goto next_2;
    reg_a0 += 0x22;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    cond_flag = 1;
    reg_d0.w = reg_save4_d0;
    reg_d1.w = reg_save4_d1;
    reg_d2.w = reg_save4_d2;
    reg_d3.w = reg_save4_d3;
    reg_d4.w = reg_save4_d4;
    reg_d5.w = reg_save4_d5;
    reg_d6.w = reg_save4_d6;
    reg_d7.w = reg_save4_d7;
    reg_a0 = (u8 *)reg_save4_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save4_a1_as_s32;
    reg_a2 = (u8 *)reg_save4_a2_as_s32;
    reg_a3 = (u8 *)reg_save4_a3_as_s32;
    reg_a4 = (u8 *)reg_save4_a4_as_s32;
    reg_a5 = (u8 *)reg_save4_a5_as_s32;
    reg_a6 = (u8 *)reg_save4_a6_as_s32;
    return;
next_2:
    func_0020AAA0();
    reg_tmp.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= 1;
    if (reg_tmp.h[0] == 0) goto next_3;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_3:
    cond_flag = 0;
    reg_d0.w = reg_save4_d0;
    reg_d1.w = reg_save4_d1;
    reg_d2.w = reg_save4_d2;
    reg_d3.w = reg_save4_d3;
    reg_d4.w = reg_save4_d4;
    reg_d5.w = reg_save4_d5;
    reg_d6.w = reg_save4_d6;
    reg_d7.w = reg_save4_d7;
    reg_a0 = (u8 *)reg_save4_a0_as_u16_p;
    reg_a1 = (u8 *)reg_save4_a1_as_s32;
    reg_a2 = (u8 *)reg_save4_a2_as_s32;
    reg_a3 = (u8 *)reg_save4_a3_as_s32;
    reg_a4 = (u8 *)reg_save4_a4_as_s32;
    reg_a5 = (u8 *)reg_save4_a5_as_s32;
    reg_a6 = (u8 *)reg_save4_a6_as_s32;
}

extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u8 *D_0028E570;
extern u16 D_0029A52A[];
extern u8 D_002A5A30[];

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void func_0020A540(void) {
    reg_d0.w = 0;
    D_0029A52A[0] = 0xD0;
    D_0029A52A[0] -= reg_d0.h[0];
    if (0 > (s16) D_0029A52A[0]) {
        D_0029A52A[0] = 0;
    }
    reg_d7.h[0] = D_0029A528[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_d6.h[0] = D_0028E3E0;
    reg_d6.h[0] = -reg_d6.sh[0];
    reg_tmp.w = reg_d6.w;
    reg_d6.h[1] = reg_tmp.h[0];
    reg_d6.h[0] = D_0028E3EC;
    reg_d5.h[0] = 0x7000;
    reg_tmp.w = reg_d5.w;
    reg_d5.h[1] = reg_tmp.h[0];
    reg_d5.h[0] = D_0029A52A[0];
    reg_d4.w = 6;
    reg_d3.w = 0x07FF03FF;
    reg_d2.w = 0x80008000;
    reg_d1.w = 0x1A;
    reg_a6 = (u8 *)D_00299D30;
    reg_a4 = (u8 *)D_002A5A30;
    D_0028E570 = reg_a4;
    goto loop_2;
loop_1:
    reg_a6 += 0x20;
loop_2:
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    if (reg_d0.h[0] == 0) goto loop_1;
    if (reg_d5.h[0] == 0) goto block_clr2;
    reg_d5.h[0] -= 1;
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    switch (reg_d0.h[0]) {
    default:
    block_clr2:
        func_00209E80();
        reg_a6 += 0x20;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 0:
    block_a:
        reg_a6[0xF] -= 1;
        if (0 > (s8) reg_a6[0xF]) goto next_4;
        goto block_move;
    next_4:
        reg_a6[0xF] = reg_a6[0xE];
        goto block_anim;
    block_d:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_5;
        goto block_a;
    next_5:
        reg_a6[0x17] = reg_a6[0x16];
    case 4:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_6;
        goto block_a;
    next_6:
        reg_a6[0x17] = reg_a6[0x16];
    case 8:
    block_anim:
        reg_d0.h[0] = W(0x10);
        reg_tmp.h[0] = W(0x10);
        W(0x10) -= 4;
        if (reg_tmp.h[0] < 4) goto block_clr4;
        reg_tmp.h[1] = W(0x12);
        reg_tmp.h[0] = W(0x14);
        reg_a0 = (u8 *) reg_tmp.w;
        W(4) = LOOKUP(reg_d0.h[0]);
        W(6) = LOOKUP(reg_d0.h[0] + 2);
    block_move:
        reg_d0.h[1] = W(0x18);
        reg_d0.h[0] = W(0x1A);
        reg_tmp.h[1] = W(0);
        reg_tmp.h[0] = W(2);
        reg_d0.w += reg_tmp.w;
        W(0) = reg_d0.h[1];
        reg_a6 += 2;
        W(0) = reg_d0.h[0];
        reg_a6 += 2;
        if (0 > reg_d6.sh[0]) goto next_3;
        if (!(reg_d5.w > reg_d0.w)) goto block_clr8;
    next_3:
        reg_d0.w = reg_d0.sw >> reg_d4.w;
        reg_d0.w &= reg_d3.w;
        reg_d0.w |= reg_d2.w;
        *(u16 *)reg_a4 = reg_d0.h[1];
        reg_a4 += 2;
        *(u16 *)reg_a4 = reg_d0.h[0];
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a4 += 2;
        reg_a6 += 0x14;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 12:
        goto block_d;
    }
block_clr4:
    func_00209EA0();
    reg_a6 += 0x1E;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
    return;
block_clr8:
    func_00209EC0();
    reg_a6 += 0x1A;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
}

typedef void (*Fn)();

s32 func_00201200();
extern u8 D_00250D00[];
extern u16 *D_0028E530_as_u16_p;

void func_0020AAA0(void) {
    u16 *temp_a2;
    u16 *temp_a3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;

    D_0028E530_as_u16_p = (u16 *)(reg_a2);
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)(reg_a6 + 2);
    temp_a0 = reg_d3.h[0] + *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[0] = temp_a0;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)(reg_a6 + 4);
    temp_a0_2 = *(u16 *)reg_a2;
    temp_a1 = reg_d3.h[0];
    reg_d3.h[0] = temp_a1 + temp_a0_2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d3.h[0]) {
        reg_d3.w = 0;
        reg_d3.b[0] = *(u8 *)(reg_a6 + 0x1C);
    }
    func_00201200();
    if (reg_d5.h[0] == 0) {
        reg_d3.h[0] |= 0x2000;
    }
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    temp_a3 = (u16 *)(reg_a2 + 2);
    temp_a2 = (u16 *)(reg_a0 + 2);
    reg_a2 = (u8 *)(temp_a3);
    reg_a0 = (u8 *)(temp_a2);
    D_0029A528[0] += 1;
    ((Fn)*(u32 *)((u8 *)D_00250D00 + (reg_d0.h[0] & ~3)))();
}

s32 func_00201160();
s32 func_002011A0();
s32 func_00201D10();
extern u16 D_00250D20[];
extern u16 D_0029F212[];
extern u16 D_0029F282[];

void func_0020AD50(void) {
    u32 temp_a0;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;

    temp_s1 = reg_d0.w;
    temp_s2 = reg_d1.w;
    temp_s3 = reg_d2.w;
    reg_d3.w = 0x18;
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        reg_d3.w = 0x28;
    }
    func_0020B5F0();
    reg_d1.b[0] += reg_d3.b[0];
    reg_d1.b[0] &= 0x3F;
    func_00201160();
    temp_s0 = reg_d1.w;
    reg_d0.b[0] += 4;
    func_00201D10();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (-0x1C)));
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.h[0] = 0xC0;
    if (0 <= (s16)(reg_d7.h[0])) {
        if (reg_d7.h[0] & 0xFFFF) {
            reg_d1.h[0] = D_0029F212[0];
        } else {
            reg_d1.h[0] = D_0029F282[0];
        }
        reg_a2 = (u8 *)(D_00250D20);
        reg_a2 += reg_d1.h[0];
        reg_d0.h[0] = *(u16 *)reg_a2;
    } else {
        reg_d3.h[0] = 2;
        if (D_0029CEA0_as_u8_a[0] & 0x80) {
            reg_d3.h[0] = 3;
        }
        (*(u8 *)((u8 *)(reg_a0) + (-0x12))) = (u8) reg_d3.b[0];
    }
    reg_d1.w = temp_s0;
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a0) + (-0x1A))) += reg_d3.h[0];
    reg_d0.w = temp_s1;
    reg_d1.w = temp_s2;
    reg_d2.w = temp_s3;
    reg_a0 += 2;
    reg_a2 = (u8 *)(D_0028E530_as_u16_p);
}

extern s32 reg_a0_as_s32;

void func_0020AF10(void) {
    reg_a0_as_s32 += 6;
}

extern s32 D_0028E530;

void func_0020AF20(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.h[0] &= 0x3F;
    func_00201D10();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

s32 func_00201E20();

void func_0020B030(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    func_00201E20();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B140(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.b[0] += *(u8 *)(reg_a6 + 0x1A);
    reg_d1.h[0] &= 0x3F;
    func_00201D10();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B270(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.b[0] += 8;
    if ((s32) reg_d0.b[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    reg_d1.b[0] += *(u8 *)(reg_a6 + 0x1A);
    func_00201E20();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B390(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.b[0] = *(u8 *)(reg_a6 + 0x1A);
    reg_d1.b[0] += 0x20;
    reg_d1.h[0] &= 0x3F;
    func_00201D10();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B4C0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    reg_d1.b[0] += *(u8 *)(reg_a6 + 0x1A);
    reg_d1.b[0] += 0x80;
    func_00201E20();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

extern s8 D_00251520[];
extern s8 *reg_a2_as_s8_p;

void func_0020B5F0(void)
{
    u32 cursor = *(u8 *)&rng_cursor;

    reg_d1.w = 0x3F;
    reg_a2_as_s8_p = D_00251520;
    *(u8 *)&rng_cursor = cursor + 1U;
    reg_d1.h[0] &= rng_cursor;
    reg_a2_as_s8_p += reg_d1.h[0];
    reg_d1.b[0] = (u8)*reg_a2_as_s8_p;
}

extern s8 D_00251560[];

void func_0020B640(void)
{
    u32 cursor = *(u8 *)&rng_cursor;
    s8 *table;
    u32 mask;

    reg_d1.w = 0x3F;
    table = D_00251560;
    mask = reg_d1.h[0];
    reg_a2_as_s8_p = table;
    *(u8 *)&rng_cursor = (u8)(cursor + 1U);
    reg_d1.h[0] = (u16)(mask & (u32)rng_cursor);
    reg_a2_as_s8_p += reg_d1.h[0];
    reg_d1.b[0] = (u8)*reg_a2_as_s8_p;
}
