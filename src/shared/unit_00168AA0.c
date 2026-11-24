#include "common.h"

void func_001713F0(s32 mode);

void func_00168AA0(void) {
    func_001713F0(0);
}

extern s32 D_0025B0C0[];
extern s32 *reg_a0_as_s32_p;

void func_0014E370(void);

void func_00168AB0(void) {
    reg_a0_as_s32_p = D_0025B0C0;
    func_0014E370();
}

s32 func_0014E290();
extern u16 D_0028DFFC;
extern u16 D_0028E890;
extern u16 D_0028E8A0;
extern u16 D_0028E8A8;
extern u8 *reg_a6;

void func_00168AC0(void) {
    u8 t;

    if ((s32) D_0028E8A8 < 0x2E0) goto next_1;
    func_0014E290();
    return;
next_1:
    if (D_0028E8A0 != 0) goto block_rts;
    D_0028E890 = 0;
    *(u16 *)(reg_a6 + 6) -= 1;
    if ((s16) *(u16 *)(reg_a6 + 6) >= 0) goto block_rts;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = D_0028DFFC;
    if (reg_d1.h[0] == 0) goto next_2;
loop_1:
    reg_d0.h[0] -= 1;
    reg_d1.h[0] -= 7;
    if ((s16) reg_d1.h[0] >= 0) goto loop_1;
next_2:
    *(u16 *)(reg_a6 + 6) = reg_d0.h[0];
    D_0028E890 = 1;
    t = *(u8 *)(reg_a6 + 0);
    if (t & 0x40) goto next_3;
    *(u8 *)(reg_a6 + 0) = t | 0x40;
    return;
next_3:
    *(u8 *)(reg_a6 + 0) = t & 0xBF;
    D_0028E890 = 0xFFFF;
block_rts:
    return;
}
