#include "common.h"

extern s8 D_0028E408;

s32 func_0012FFE0();
s32 func_00130050();
s32 func_001301B0();
s32 func_00130CC0();
s32 func_00137AD0();
extern u8 D_00251BC0[];
extern u8 D_00251BE0[];
extern u8 D_00251C00[];
extern u8 D_0028C158[];
extern u8 D_0028C15C[];
extern u8 D_0028E390;
extern u8 D_0028E39C;
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_00206690(void) {
    D_0028E408 = 0;
    reg_a4 = (u8 *)D_0028C158;
    if (reg_d7.h[0] != 0) goto next_1;
    reg_a4 = (u8 *)D_0028C15C;
next_1:
    func_001301B0();
    if (reg_d7.h[0] != 0) goto next_2;
    if (D_0028E390 != 1) goto next_2;
    reg_d0.h[0] = reg_d1.h[0];
next_2:
    if (reg_d0.h[0] != 0) goto block_4;
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) goto block_5;
    if (reg_d0.b[0] == 0x11) goto block_7;
    if ((s8) reg_d0.b[0] > 8) goto block_7;
    goto block_6;
block_4:
    reg_d0.h[0] = 4;
    return;
block_5:
    reg_d0.h[0] = 4;
    return;
block_6:
    reg_d0.h[0] = 0;
    return;
block_7:
    if (reg_d7.h[0] != 0) goto next_8;
    func_00130050();
    goto next_9;
next_8:
    func_0012FFE0();
next_9:
    if (reg_d0.h[0] != 1) goto next_10;
    if (reg_d1.h[0] != 0) goto block_4;
    goto block_6;
next_10:
    if (reg_d1.h[0] != 0) goto next_11;
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BC0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    D_0028E408 = 1;
    return;
next_11:
    reg_d0.h[0] -= reg_d1.h[0];
    if (0 >= (s16) reg_d0.h[0]) goto block_4;
    if ((reg_d0.h[0] & 0xFFFF) == 1) goto next_12;
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BE0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    D_0028E408 = 1;
    return;
next_12:
    reg_a0 = (u8 *)D_00251C00;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    D_0028E408 = 1;
}
