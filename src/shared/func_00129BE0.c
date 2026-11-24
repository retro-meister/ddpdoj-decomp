#include "common.h"

s32 func_00125EE0();
s32 func_00128640();
extern u32 D_0028DEA4;
extern u8 D_002962E0[];
extern u16 D_00299764[];
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u8 *reg_a6;

#ifdef DEATH_LABEL
s32 death_func_00128A90();
#endif

void func_00129BE0(void) {
    u32 t;

    if (D_00299764[0] == 0) {
        return;
    }
    reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
    if ((s16) reg_d0.h[0] < 0) {
        goto next_3;
    }
    reg_a6 = (u8 *)D_002962E0;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_1;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_1:
    if (0 > (s64) *(s8 *) (reg_a6 + 1)) {
        D_0028DEA4 = reg_d7.w;
        reg_d0.h[0] = *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686));
        MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
        reg_d7.w = D_0028DEA4;
        func_00128640();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_3:
    reg_a6 = (u8 *)D_002962E0;
    reg_d2.w = 0x40;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    if (D_00299768_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
    if (D_0029976A_as_u16_a[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
    if (D_0029976C[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
    if (D_0029976E[0] == 0) {
        goto loop_4;
    }
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_4:
    t = *(u8 *) (reg_a6 + 1);
    if (0 > (s8) t) {
        *(u8 *) (reg_a6 + 1) = t | reg_d2.b[0];
        *(u16 *) (reg_a6 + 0x3C) = 0xFFFF;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_4;
    }
}
