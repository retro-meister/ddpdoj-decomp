#include "common.h"

void func_00146690(void);
void func_00147F30(void);
void func_0020A040(void);
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u16 D_0028E928;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_00146A90(void) {
    reg_d1.h[0] += 0x800;
    *(u16 *)(reg_a6 + 2) += reg_d1.h[0];
    *(u16 *)(reg_a6 + 4) = reg_d2.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if ((s32)reg_tmp.h[0] < 4) {
        *(u16 *)(reg_a6 + 0x24) = 4;
    }
    if (*(u8 *)(reg_a6 + 1) & 1) goto block_1;
    if (*(s8 *)(reg_a6 + 0) >= 0) {
        switch (D_0028E928) {
            case 0:
                break;
            default:
                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x27);
                *(u8 *)(reg_a6 + 0x27) -= 1;
                if ((s32)reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a6 + 0x27) = *(u8 *)(reg_a6 + 0x26);
                    func_0020A040();
                }
                break;
        }
    }
    if ((s32)*(u16 *)(reg_a6 + 2) >= 0x7800) goto block_4;
    if (!(*(u8 *)(reg_a0 + 1) & 0x10)) goto block_2;
block_1:
    if (*(s16 *)reg_a1 < 0) goto block_3;
    *(u8 *)(reg_a6 + 1) |= 1;
block_2:
    reg_a0 = (u8 *)&D_0028E004;
    if (*(u16 *)(reg_a6 + 0x1A) == 0) goto block_5;
    if (D_0028E004 == 0) goto block_6;
    return;
block_3:
    *(u16 *)(reg_a6 + 0) = 0;
    return;
block_4:
    func_00147F30();
    return;
block_5:
    if (D_0028E000 != 0) return;
block_6:
    func_00146690();
}
