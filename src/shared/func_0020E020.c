#include "common.h"

extern s8 D_0028E408;

s32 func_0020B6A0();
extern u8 D_002962E0[];
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_0020E020(void) {
    reg_d0.h[0] = *(u16 *) (reg_a4 + 2);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] += *(u16 *) (reg_a4 + 0x10);
    reg_d1.h[0] -= *(u16 *) (reg_a4 + 0x12);
    reg_d2.h[0] = *(u16 *) (reg_a4 + 4);
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.h[0] += *(u16 *) (reg_a4 + 0x14);
    reg_d3.h[0] -= *(u16 *) (reg_a4 + 0x16);
    reg_a6 = (u8 *)D_002962E0 + 2;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(6, 34);
    if (D_00299768_as_u16_a[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0xA, 54);
    if (D_0029976A_as_u16_a[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0xF, 79);
    if (D_0029976C[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0x12, 94);
    if (D_0029976E[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0x14, 104);
loop_5:
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (D_0028E408 != 0) return;
    reg_a6 += 0x3E;
    if ((s16) --reg_d6.h[0] >= 0) goto loop_5;
}
