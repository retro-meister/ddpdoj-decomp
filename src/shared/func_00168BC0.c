#include "common.h"

typedef void (*Fn)();

s32 func_0012FAB0();
s32 func_0012FB00();
s32 func_001301B0();
s32 func_00130200();
s32 func_00131200();
s32 func_00137C50();
s32 func_0013B190();
s32 func_00168E30();
s32 func_00169C60();
s32 func_00169D30();
s32 func_0018D8F0();
s32 func_0018DE90();
s32 func_001A2FA0();
s32 func_00206D70();
s32 func_002071C0();
s32 func_00224B50();
s32 func_00236D50();
extern u8 D_00269160[];
extern u8 D_0026A830[];
extern s8 D_0028DF84;
extern u8 D_0028E350;
extern u8 D_0028E39C;
extern u16 D_0028E3C0;
extern u16 D_0028E7B8;
extern u16 D_0028E7BC;
extern s8 D_0028E9B8;
extern s8 D_0028ED74;
extern s8 D_0028ED7C;
extern s8 D_0028ED80;
extern s32 D_0057CC78[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_00168BC0(void) {
#ifndef DEATH_LABEL
    u32 t;
#endif

    if (*(u8 *)(reg_a5 + 3) == 0) {
        func_00168E30();
        return;
    }
#ifndef DEATH_LABEL
    reg_d0.h[0] = D_0028E7BC;
    if (D_0028E3C0 != 0) goto next_1;
    if (D_0028E350 != 0) goto block_3;
    goto next_2;
next_1:
    if (D_0028E9B8 != 0) goto next_3;
next_2:
    if (reg_d0.h[0] == 14) goto block_2;
    if (reg_d0.h[0] == 3) goto block_2;
    if (reg_d0.h[0] == 13) goto block_2;
    if (reg_d0.h[0] == 17) goto block_2;
    if (reg_d0.h[0] == 18) goto block_2;
    if (reg_d0.h[0] == 15) goto block_3;
    if (reg_d0.h[0] == 16) goto block_3;
    if (reg_d0.h[0] == 19) goto block_3;
    if (D_0028E39C != 0x12) goto next_3;
    if (D_0028E350 != 0) goto next_3;
    if (D_0057CC78[0] & 0x800) goto block_1;
next_3:
    func_00130200();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] != 0) goto block_1;
    func_001301B0();
    reg_d0.h[0] += reg_d1.h[0];
    if (reg_d0.h[0] == 0) goto block_2;
block_1:
    D_0028DF84 = 1;
    func_00206D70();
    func_0013B190();
    func_00137C50();
    if (D_0028E3C0 == 0) goto next_4;
    D_0028E3C0 = 0;
    func_00236D50();
    D_0028ED80 = 0;
    D_0028ED7C = 0;
    D_0028ED74 = 0;
    func_0018DE90();
    func_0018D8F0();
    func_00224B50();
next_4:
    if (D_0028E7BC != 0xC) goto next_5;
    func_0018DE90();
next_5:
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_00269160;
    func_001A2FA0();
    func_0012FAB0();
    func_0012FB00();
    reg_d0.h[0] = 8;
    func_002071C0();
    *(s16 *)(reg_a0 + 4) = 3;
    return;
block_2:
    if (D_0028E7BC == 0xD) goto block_3;
    if (reg_d0.h[0] == 0x11) goto block_3;
    if (reg_d0.h[0] == 0x12) goto block_3;
    D_0028E7B8 += 1;
    reg_d0.h[0] = D_0028E7B8;
    t = reg_d0.h[0] & 0x10;
    reg_d0.h[0] = t;
    if (!(t & 0xFFFF)) goto next_6;
    func_00169C60();
    goto next_7;
next_6:
    func_00169D30();
next_7:
    func_00131200();
block_3:
#endif
    reg_d0.h[0] = D_0028E7BC;
    ((Fn)*(u32 *)((u8 *)D_0026A830 + (reg_d0.h[0] * 4)))();
}
