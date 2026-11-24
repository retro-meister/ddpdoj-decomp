#include "common.h"

void func_0012FFE0(void);
void func_00130050(void);
void func_001301B0(void);
void func_00130CC0(void);
void func_00137AD0(void);
void func_001A3520(void);
extern u8 D_00251B60[];
extern u8 D_00251B80[];
extern u8 D_00251BA0[];
extern u8 D_00251BC0[];
extern u8 D_00251BE0[];
extern u8 D_00251C00[];
extern u8 D_0028E390;
extern u8 D_0028E39C;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_001B0160(void) {
    func_001301B0();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_1;
    }
    if (D_0028E390 != 1) {
        goto next_1;
    }
    reg_d0.h[0] = reg_d1.h[0];
next_1:
    if (reg_d0.h[0] != 0) {
        goto block_50;
    }
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        goto block_51;
    }
    if (reg_d0.b[0] == 0x11) {
        goto block_52;
    }
    if ((s8) reg_d0.b[0] >= 9) {
        goto block_52;
    }
    goto block_53;
block_50:
    reg_a0 = (u8 *)D_00251B60;
    goto block_54;
block_51:
    reg_a0 = (u8 *)D_00251B80;
    goto block_54;
block_53:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3520();
    if (reg_d0.h[0] == 0xC) {
        return;
    }
    reg_a0 = (u8 *)D_00251BA0;
    goto block_54;
block_52:
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_2;
    }
    func_00130050();
    goto next_3;
next_2:
    func_0012FFE0();
next_3:
    if (reg_d0.h[0] != 1) {
        goto next_4;
    }
    if (reg_d1.h[0] != 0) {
        goto block_50;
    }
    goto block_53;
next_4:
    if (reg_d1.h[0] != 0) {
        goto next_5;
    }
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
    return;
next_5:
    reg_d0.h[0] -= reg_d1.h[0];
    if (!(0 < (s16) reg_d0.h[0])) {
        goto block_50;
    }
    if ((reg_d0.h[0] & 0xFFFF) == 1) {
        goto next_6;
    }
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
    return;
next_6:
    reg_a0 = (u8 *)D_00251C00;
block_54:
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
