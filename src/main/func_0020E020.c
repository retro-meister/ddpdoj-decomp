#include "common.h"

extern s8 D_0028E408;

s32 func_0020B6A0();
extern u8 D_002962E0[];
extern u16 D_00299768[];
extern u16 D_0029976A[];
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
    reg_d6.h[0] = 6;
    if (D_00299768[0] == 0) goto loop_5;
    reg_d6.h[0] = 0xA;
    if (D_0029976A[0] == 0) goto loop_5;
    reg_d6.h[0] = 0xF;
    if (D_0029976C[0] == 0) goto loop_5;
    reg_d6.h[0] = 0x12;
    if (D_0029976E[0] == 0) goto loop_5;
    reg_d6.h[0] = 0x14;
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
