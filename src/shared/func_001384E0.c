#include "common.h"

s32 func_00138470();
extern u8 D_00251A80[];
extern u8 D_00251A90[];
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001384E0(void) {
    if (reg_d7.h[0] == 0) {
        goto next_3;
    }
    reg_d0.w = 0;
    reg_a4 = (u8 *)D_00251A80;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 6);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 0;
        *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    func_00138470();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 7) = *(u8 *) (reg_a6 + 4);
    goto next_5;
next_3:
    reg_d0.w = 0;
    reg_a4 = (u8 *)D_00251A90;
    reg_d0.b[0] = *(u8 *) (reg_a5 + 7);
    if (0 > (s64) reg_d0.sb[0]) {
        *(u16 *) (reg_a6 + 4) = 2;
        *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
        goto next_5;
    }
    func_00138470();
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    *(u8 *) (reg_a5 + 6) = *(u8 *) (reg_a6 + 4);
next_5:
    *(s16 *) (reg_a6 + 0x16) = 0x60;
    *(s16 *) (reg_a6 + 0x18) = 0xC00;
    *(s16 *) (reg_a6 + 0x1C) = 0x60;
    *(s16 *) (reg_a6 + 0x1E) = 0xC00;
    *(s16 *) (reg_a6 + 0x22) = 0x60;
    *(s16 *) (reg_a6 + 0x24) = 0xC00;
    *(s16 *) (reg_a6 + 0x2A) = 0xB4;
    *(s16 *) (reg_a6 + 0x2E) = 0x599;
    *(s8 *) (reg_a6 + 0x30) = 2;
    *(s8 *) (reg_a6 + 0x31) = 0;
    *(s8 *) reg_a6 = 4;
}
