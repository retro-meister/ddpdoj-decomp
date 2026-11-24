#include "common.h"
#include "entity.h"

void func_0011FA90(void);
void func_00120770();
void func_00121B60(void);
void func_00122070(void);
void func_00122420(void);
void func_001224F0(void);
void func_00122500(void);
void func_00122650(void);
void func_00122A60(void);
void func_00122B00(void);
void func_00122B20(void);

extern u16 D_0028DFC8;
extern u16 D_0029CEA0[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
extern u8 D_0029F1F0_as_u8_a[];
extern u8 D_0029F260_as_u8_a[];

void func_0011F980(void) {
    u8 *sa5;

    reg_a6 = (u8 *)(D_0029CEA0);
    reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
    if ((s16) reg_d0.h[0] >= 0) {
        if (D_0028DFC8 != 0) {
            D_0028DFC8 -= 1;
            if (D_0028DFC8 == 0) {
                func_00122B00();
            }
        }
    } else {
        sa5 = (u8 *)(reg_a5);
        reg_a4 = (u8 *)D_0029F180;
        reg_a5 = (u8 *)D_0029F260_as_u8_a;
        if (ENTITY(reg_a6)->flags.sb[0] < 0) {
            reg_a4 = (u8 *)D_0029F110;
            reg_a5 = (u8 *)D_0029F1F0_as_u8_a;
        }
        reg_d0.h[0] &= 7;
        switch (reg_d0.h[0]) {
        case 3:
            goto block_1;
        }
        switch (reg_d0.h[0]) {
        case 0:
        case 2:
            func_0011FA90();
            break;
        case 1:
        block_1:
            func_00120770();
            break;
        }
        reg_a5 = sa5;
    }
}

typedef void (*Fn)();

extern u8 D_00241720[];
extern u8 D_002417C0[];
extern u8 D_00241830[];
s32 func_0018D890();
s32 func_0018D8B0();
s32 func_0019D990();
s32 func_0019D9C0();
s32 func_0019DA10();
s32 func_002011D0();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00241780[];
extern u8 D_00241810[];
extern u8 D_00241870[];
extern u16 D_0028E3EC;
extern u16 D_0029C06C[];
extern u8 D_0029CEA0_as_u8_a[];
extern void (*jtbl_0028E3F4)();

void func_0011FA90(void) {
    u8 temp;

    reg_d1.h[0] = D_0029C06C[0];
    ENTITY(reg_a6)->x.h -= reg_d1.h[0];
    temp = ENTITY(reg_a6)->flags.b[1];
    if (temp & 1) goto block_a;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 1);
    reg_a0 = (u8 *)D_00241720;
    reg_a1 = (u8 *)(reg_a6 + 2);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 0xC;
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
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 = (u8 *)func_0018D890;
    reg_a1 += 2;
    switch (ENTITY(reg_a6)->flags.b[0] & 2) { case 0: goto next_1; }
    reg_tmp.w = (u32) D_00241780;
    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)func_0018D8B0;
next_1:
    jtbl_0028E3F4 = (Fn)(reg_a0);
    jtbl_0028E3F4();
    if (reg_a5 != D_0029F260_as_u8_a) goto next_2;
    vibration_start_pad1(0xC8, 0x64);
    goto block_a;
next_2:
    vibration_start_pad2(0xC8, 0x64);
block_a:
    if (*(u16 *)(reg_a6 + 0x28) != 0) goto block_c;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d4.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    func_0019DA10();
    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x23);
    *(u8 *)(reg_a6 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts_2;
    *(u8 *)(reg_a6 + 0x23) = (u8) *(u8 *)(reg_a6 + 0x22);
    if (*(u16 *)reg_a0 == 0xFFFF) goto block_b;
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_rts_2:
    return;
block_b:
    reg_a0 = (u8 *)D_002417C0;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
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
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_c;
    reg_tmp.w = (u32) D_00241810;
    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_c:
    if (*(u16 *)(reg_a6 + 0x28) != 1) goto block_e;
    reg_d1.w = 0x40;
    func_002011D0();
    if (reg_d0.b[0] != 0) goto next_3;
    reg_d1.h[0] *= 0xFFFF;
next_3:
    ENTITY(reg_a6)->x.h += reg_d1.h[0];
    if (D_0028E3EC != 0) goto block_rts;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!((s32) reg_tmp.h[0] < 4)) goto next_4;
    *(u16 *)(reg_a6 + 0x2A) -= 1;
    if (*(u16 *)(reg_a6 + 0x2A) == 0) goto block_d;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
next_4:
    func_0019D990();
    return;
block_d:
    reg_a0 = (u8 *)D_00241830;
    reg_a1 = (u8 *)(reg_a6 + 6);
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
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
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if (!(ENTITY(reg_a6)->flags.b[0] & 2)) goto block_e;
    reg_tmp.w = (u32) D_00241870;
    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
block_e:
    temp = ENTITY(reg_a6)->flags.b[1];
    if (!(temp & 2)) goto next_5;
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp & 0xFD);
    goto block_f;
next_5:
    ENTITY(reg_a6)->flags.b[1] = (u8) (temp | 2);
    return;
block_f:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    func_0019D9C0();
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w == -1U) goto block_g;
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
    return;
block_g:
    reg_a0 = (u8 *)D_0029F260_as_u8_a;
    reg_d1.w = 0;
    reg_a6 = (u8 *)D_0029CEA0_as_u8_a;
    if (ENTITY(reg_a6)->flags.sb[0] >= 0) goto next_6;
    reg_a0 = (u8 *)D_0029F1F0_as_u8_a;
    reg_d1.w = 2;
next_6:
    reg_d0.b[0] = *(u8 *)(reg_a0 + 0x38);
    if ((s32) *(u8 *)(reg_a0 + 0x1B) <= (s32) reg_d0.b[0]) goto next_7;
    *(u8 *)(reg_a0 + 0x1B) = (u8) reg_d0.b[0];
next_7:
    D_0028DFC8 = 0x28;
    func_00122B20();
block_rts:
    return;
}

extern u8 D_00241F50[];
s32 func_0018D850();
s32 func_0018D870();
s32 func_0020A270();
extern u8 D_00241BF0[];
extern u8 D_00241C00[];
extern u8 D_00241C10[];
extern u8 D_00241C20[];
extern u8 D_00241C30[];
extern u8 D_00241CD0[];
extern s16 D_0028DFC8_as_s16;
extern u16 D_0028DFD0;

void func_00120770(arg3)
    u16 arg3;
{
    u8 *temp_a1;
    u8 *var_a2;
    s64 temp_v0;
    s64 temp_v0_2;
    s64 temp_v0_3;
    s64 temp_v0_4;
    u16 *var_a1;
    u16 var_a0;
    u16 var_a3;
    var_a3 = arg3;
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 1;
    if (!(reg_tmp.b[0] & 1)) {
        reg_a0 = D_00241F50;
        reg_a1 = (u8 *)(reg_a6 + 6);
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
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
        reg_a1 += 0x7B0;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
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
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
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
        reg_a1 += 4;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
        reg_a1 += 4;
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
        var_a2 = (u8 *)(reg_a0 + 2);
        var_a1 = (u16 *)(reg_a1 + 2);
        reg_a0 = var_a2;
        reg_a1 = (u8 *)(var_a1);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d0.h[0] += 0x7FFF + 0x7E01;
        *(u16 *)(reg_a6 + 0x7E2) = reg_d0.h[0];
        reg_a0 = (u8 *)func_0018D850;
        reg_d0.w = 0;
        D_0028DFD0 = reg_d0.h[0];
        if (ENTITY(reg_a6)->flags.b[0] & 2) {
            reg_tmp.w = (u32) D_00241BF0;
            *(u16 *)(reg_a6 + 0x1E) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x20) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) D_00241CD0;
            *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) D_00241C30;
            *(u16 *)(reg_a6 + 0x2C) = (u16) reg_tmp.h[1];
            var_a3 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x2E) = var_a3;
            reg_tmp.w = (u32) D_00241C10;
            *(u16 *)(reg_a6 + 0x7FE) = (u16) reg_tmp.h[1];
            var_a2 = (u8 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x800) = (u16) var_a2;
            reg_tmp.w = (u32) D_00241C00;
            *(u16 *)(reg_a6 + 0x82E) = (u16) reg_tmp.h[1];
            var_a1 = (u16 *) reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x830) = (u16) var_a1;
            reg_tmp.w = (u32) D_00241C20;
            *(u16 *)(reg_a6 + 0x85E) = (u16) reg_tmp.h[1];
            var_a0 = reg_tmp.h[0];
            *(u16 *)(reg_a6 + 0x860) = var_a0;
            reg_a0 = (u8 *)func_0018D870;
        }
        jtbl_0028E3F4 = (Fn)(reg_a0);
        jtbl_0028E3F4();
        if (reg_a5 == D_0029F260_as_u8_a) {
            vibration_start_pad1(0xC8, 0x78);
        } else {
            vibration_start_pad2(0xC8, 0x78);
        }
    }
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x7E4) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x812) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x814) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x844) = (u16) reg_d0.h[0];
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        *(u16 *)(reg_a6 + 0x24) = (u16) *(u16 *)(reg_a6 + 0x26);
    }
    if (ENTITY(reg_a6)->hp.h == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
        reg_a0 = (u8 *) reg_tmp.w;
        ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x7FE);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x800);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x7EA) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x7EC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x82E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x830);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x81A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x81C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x85E);
        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x860);
        reg_a0 = (u8 *) reg_tmp.w;
        *(u16 *)(reg_a6 + 0x84A) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        *(u16 *)(reg_a6 + 0x84C) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)->move.h -= 1;
        if (ENTITY(reg_a6)->move.h == 0) {
            ENTITY(reg_a6)->hp.h = 1U;
            goto block_40;
        }
block_36:
        func_00121B60();
        func_00122420();
        func_001224F0();
        func_00122500();
        func_0019D990();
        reg_a6 += 0x7E0;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            func_0019D990();
        }
        reg_a6 += 0x30;
        func_0019D990();
        reg_a6 += 0x30;
        if (!(ENTITY(reg_a6)->flags.b[1] & 2)) {
            func_0019D990();
            reg_d0.w = 2;
            func_0020A270();
        }
        return;
    }
block_40:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    if (reg_tmp.w != -1U) {
        ENTITY(reg_a6)->draw.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EA) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x7EC) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x81C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84A) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x84C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2C) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        *(u16 *)(reg_a6 + 0x2E) = (u16) *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.w = (u32) reg_a0;
        *(u16 *)(reg_a6 + 0x28) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a6 + 0x2A) = (u16) reg_tmp.h[0];
        func_00122650();
        goto block_36;
    } else {
        D_0028DFC8_as_s16 = 0x28;
        func_00122A60();
        func_00122B20();
    }
}

extern u16 D_00241FF0[];
extern s32 D_0028DFF4;
extern u16 D_0028DFF8;
extern u16 D_0029CED0[];

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00121B60(void) {
    reg_tmp.h[0] = W(0x80A);
    W(0x80A) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_20;
    W(0x80A) = 0x1C;
next_20:
    reg_a3 = reg_a6;
    if (W(0x18) != 0) {
        func_00122070();
        return;
    }
    reg_d0.h[0] = W(0x80A);
    reg_tmp.h[1] = W(0x2C);
    reg_tmp.h[0] = W(0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d5.w = (u32) reg_a0;
    reg_d4.h[0] = W(0x24);
    reg_a0 += reg_d4.h[0];
    reg_d7.w = 0x28;
    reg_d6.w = 0;
    reg_a6 = (u8 *) D_0029CED0;
    reg_a2 = (u8 *) D_00241FF0;
loop_40:
    if ((s16) W(0) < 0) goto next_100;
    if (reg_d6.h[0] != 0) goto next_190;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d5.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d6.w = 1;
    goto next_180;
next_100:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_a1 = (u8 *) reg_tmp.w;
    W(0xA) = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a1;
    W(0xC) = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    reg_d0.h[0] = W(2);
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (D_0028DFF4 == 0) goto next_120;
    if (D_0028DFF8 < reg_d0.h[0]) goto next_140;
next_120:
    if ((s32) reg_d0.h[0] < 0x7800) goto next_160;
next_140:
    W(0) = 0;
    goto next_190;
next_160:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    W(2) = reg_d0.h[1];
    W(4) = reg_d0.h[0];
next_180:
    func_0019D9C0();
next_190:
    reg_a6 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_40;
    reg_a6 = reg_a3;
}

void func_00122070(void) {
    u32 base;

    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2E);
    reg_a0 = (u8 *)reg_tmp.w;
    base = (u32)(reg_a0 + *(u16 *)(reg_a6 + 0x80A));
    reg_d7.w = 0x28;
    reg_a6 = (u8 *)D_0029CED0;
    reg_a0 = (u8 *)base;
    reg_a2 = (u8 *)D_00241FF0;
    reg_d6.w = 0;
loop_0:
    if ((s16)ENTITY(reg_a6)->flags.h < 0) goto next_0;
    if (reg_d6.h[0] != 0) goto next_6;
    reg_a1 = reg_a6;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    reg_d0.w += 0x06000000;
    *(u16 *)reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a0;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)(reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *)reg_a1 = *(u16 *)reg_a2;
    reg_d6.w = 1;
    reg_a2 += 2;
    reg_a1 += 2;
    goto next_5;
next_0:
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x200;
    reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
    if (D_0028DFF4 != 0) goto next_1;
    if (*(u16 *)(reg_a3 + 0x868) == 0) goto next_2;
    if (*(u8 *)(reg_a3 + 1) & 0x40) goto next_2;
    if ((s32)*(u16 *)(reg_a3 + 0x842) < (s32)reg_d0.h[0]) goto next_3;
    goto next_2;
next_1:
    if ((s32)D_0028DFF8 < (s32)reg_d0.h[0]) goto next_3;
next_2:
    if ((s32)reg_d0.h[0] < 0x7800) goto next_4;
next_3:
    ENTITY(reg_a6)->flags.h = 0;
    goto next_6;
next_4:
    reg_d0.h[0] += 0x200;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    ENTITY(reg_a6)->y.h = reg_d0.h[1];
    ENTITY(reg_a6)->x.h = reg_d0.h[0];
next_5:
    func_0019D9C0();
next_6:
    reg_a6 += 0x30;
    if ((s16)(reg_d7.h[0] -= 1) >= 0) goto loop_0;
    reg_a6 = reg_a3;
}

void func_00122420(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x7E0;
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        if ((D_0028DFF4 == 0) && ((*(u16 *)(reg_a0 + 0x868) == 0) || (*(u8 *)(reg_a0 + 1) & 0x40))) {
            ENTITY(reg_a6)->flags.b[1] &= 0xFD;
            reg_d0.h[0] = ENTITY(reg_a6)->y.h;
            reg_d0.h[0] += 0x400;
            reg_d0.h[0] += *(u16 *)(reg_a5 + 0x30);
            ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
            if ((s32) reg_d0.h[0] >= 0x7E00) {
                *(u16 *)(reg_a6 + 0x28) = 1U;
                goto block_6;
            }
        } else {
block_6:
            ENTITY(reg_a6)->flags.b[1] |= 2;
        }
    }
    reg_a6 -= 0x7E0;
}

void func_001224F0(void) {
}

void func_00122500(void) {
    reg_a0 = reg_a6;
    reg_a6 += 0x840;
    reg_d1.h[0] = D_0028DFF8;
    if (D_0028DFF4 != 0) goto block_1;
    if (*(u16 *)(reg_a6 + 0x28) == 0) goto block_3;
    reg_d1.h[0] = ENTITY(reg_a6)->y.h;
    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) |= 0x20;
    if (reg_tmp.b[0] & 0x20) goto block_3;
    goto block_2;
block_1:
    *(u8 *)(reg_a0 + 1) &= 0xDF;
block_2:
    *(u8 *)(reg_a0 + 1) &= 0xBF;
    ENTITY(reg_a6)->flags.b[1] &= 0xFD;
    ENTITY(reg_a6)->y.h = reg_d1.h[0];
    *(u16 *)(reg_a6 + 0x28) = 1;
    goto block_4;
block_3:
    reg_tmp.b[0] = ENTITY(reg_a6)->flags.b[1];
    ENTITY(reg_a6)->flags.b[1] |= 2;
    if (reg_tmp.b[0] & 2) goto block_4;
    *(u8 *)(reg_a0 + 0x7E1) &= 0xFD;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += 0x400;
    if (*(u16 *)(reg_a0 + 0x18) == 0) goto skip_1;
    reg_d0.h[0] -= 0x800;
skip_1:
    *(u16 *)(reg_a0 + 0x7E2) = reg_d0.h[0];
    *(s16 *)(reg_a0 + 0x808) = 0;
    *(u8 *)(reg_a0 + 1) |= 0x40;
block_4:
    reg_a6 -= 0x840;
}


void func_00122650(void) {
    reg_d7.w = 0x28;
    reg_a1 = (u8 *) D_0029CED0;
    reg_d6.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d6.h[0] = *(u16 *) (reg_a5 + 4);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x600;
    reg_d6.h[0] -= *(u16 *) (reg_a5 + 0x30);
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d5.w = 0;
loop_20:
    if (reg_d5.h[0] == 0) goto next_40;
    *(u16 *) reg_a1 = 0;
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    goto next_160;
next_40:
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2C);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2E);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a0 += *(u16 *) (reg_a6 + 0x80A);
    reg_a2 = (u8 *) D_00241FF0;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d6.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    reg_d6.h[0] += 0x400;
    if (D_0028DFF4 != 0) goto next_80;
    if (*(u8 *) (reg_a6 + 0x841) & 2) goto next_60;
    if ((s32) *(u16 *) (reg_a6 + 0x842) > (s32) reg_d6.h[0]) goto next_120;
    *(u16 *) (reg_a6 + 0x842) = reg_d6.h[0];
    goto next_100;
next_60:
    if (*(u8 *) (reg_a6 + 0x7E1) & 2) goto next_80;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x7E2);
    reg_d0.h[0] += 0x800;
    if ((s32) reg_d0.h[0] > (s32) reg_d6.h[0]) goto next_120;
    goto next_100;
next_80:
    if (reg_d6.h[0] < 0x7800) goto next_120;
next_100:
    reg_d5.w = 1;
next_120:
    reg_tmp6.h[0] = reg_d6.h[0];
    reg_d6.h[0] = reg_d6.h[1];
    reg_d6.h[1] = reg_tmp6.h[0];
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 0);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) (reg_a0 + 2);
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a2;
    reg_a2 += 2;
    reg_a1 += 2;
    reg_a1 -= 0x1E;
    *(u16 *) (reg_a6 + 0x80A) += 4;
    if (*(u16 *) (reg_a6 + 0x80A) != 0x20) goto next_140;
    *(u16 *) (reg_a6 + 0x80A) = 0;
next_140:
    reg_a1 += 0x30;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
next_160:
    *(u16 *) (reg_a6 + 0x80A) = 0x1C;
}

s32 func_0013C980();                            /* extern */
s32 func_0013CA90();                            /* extern */
extern s16 D_0028E000_as_s16;
extern s16 D_0028E004_as_s16;
extern s8 D_0029CEA0_as_s8_a[];
extern s8 *reg_a6_as_s8_p;

void func_00122A60(void) {
    reg_a6_as_s8_p = D_0029CEA0_as_s8_a;
    if (*reg_a6_as_s8_p >= 0) {
        reg_a0 = D_0029F260_as_u8_a;
        func_0013C980();
        D_0028E004_as_s16 = 0;
        D_0029F260_as_u8_a[0] &= 0xBF;
    } else {
        reg_a0 = D_0029F1F0_as_u8_a;
        func_0013CA90();
        D_0028E000_as_s16 = 0;
        D_0029F1F0_as_u8_a[0] &= 0xBF;
    }
    *reg_a0 &= 0x7F;
    reg_d0.w = 0;
    D_0028DFF4 = 0;
}

extern u8 D_0029F22F[];
extern u8 D_0029F29F[];

void func_00122B00(void) {
    reg_d0.w = 0;
    D_0029F29F[0] = reg_d0.b[0];
    D_0029F22F[0] = reg_d0.b[0];
}

s32 func_001AC340();
s32 func_001AC370();
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;

void func_00122B20(void) {
    reg_d0.w = 0;
    if (D_0028E6E4 != 0) {
        func_001AC340();
    }
    if (D_0028E6E0 != 0) {
        func_001AC370();
    }
    reg_d7.w = 0x2C;
    D_0028E004_as_s16 = 0;
    D_0028E000_as_s16 = 0;
    reg_a0 = (u8 *)(D_0029CEA0);
    reg_d0.w = 0;
    D_0029F260_as_u8_a[0] &= 0xBF;
    D_0029F1F0_as_u8_a[0] &= 0xBF;
    do {
        *(u16 *)reg_a0 = reg_d0.h[0];
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
