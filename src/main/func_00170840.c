#include "common.h"

s32 func_0014E290();
s32 func_00170690();
s32 func_0018D9D0();
s32 func_0019D770();
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00170840(void) {
    u16 m;

    if (*(u16 *)(reg_a5 + 0x20) == 0) goto next_20;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 0x1F);
    *(u8 *)(reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_20;
    *(u8 *)(reg_a5 + 0x1F) = *(u8 *)(reg_a5 + 0x1E);
    func_0018D9D0();
    *(u16 *)(reg_a5 + 0x20) -= 1;
next_20:
    *(s16 *)(reg_a6 + 4) = 0x1C00;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    *(u16 *)(reg_a5 + 0x18) -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    m = *(u16 *)(reg_a5 + 0x16);
    if (m != 0) goto next_100;
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0xF0) goto block_objset;
    *(u16 *)(reg_a5 + 0x16) = 1;
    goto block_objset;
next_100:
    if ((m & 0xFFFF) != 1) goto next_200;
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0x128) goto block_objset;
    *(u16 *)(reg_a5 + 0x1A) = 0x100;
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x1C);
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if ((s32) reg_tmp.h[0] > 0) goto block_objset;
    *(u16 *)(reg_a5 + 0x16) = 2;
    goto block_objset;
next_200:
    func_00170690();
    *(u16 *)(reg_a5 + 0x1A) += 8;
    if (*(u16 *)(reg_a5 + 0x1A) != 0x230) goto block_objset;
    func_0014E290();
    return;
block_objset:
    func_0019D770();
    switch (D_0028E3EC) {
    case 0:
        return;
    default:
        break;
    }
    if (D_0028E3F0 & 2) {
        *(u16 *)(reg_a6 + 2) -= 0x40;
        func_0019D770();
        *(u16 *)(reg_a6 + 2) += 0x40;
        return;
    }
    *(u16 *)(reg_a6 + 2) += 0x40;
    func_0019D770();
    *(u16 *)(reg_a6 + 2) -= 0x40;
}
