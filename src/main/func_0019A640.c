#include "common.h"

void func_0019A870(void);
extern u8 *reg_a4;

void func_0019A640(void) {
    if (*(u8 *)(reg_a4 + 0x21) == 1) {
        goto block_2;
    }
    if (!(reg_d0.w & 1)) {
        goto next_1;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 1;
    goto next_2;
next_1:
    if (!(reg_d0.w & 2)) {
        goto next_2;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 2;
next_2:
    if (!(reg_d0.w & 4)) {
        goto next_3;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    goto next_4;
next_3:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
next_4:
    if (*(u8 *)(reg_a4 + 0x21) == 2) {
        func_0019A870();
        return;
    }
    *(u8 *)(reg_a4 + 0x20) = 4;
    return;
block_2:
    *(u8 *)(reg_a4 + 0x20) -= 1;
    if (*(u8 *)(reg_a4 + 0x20) == 0) {
        func_0019A870();
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x2A);
    if (reg_d1.h[0] == 1) {
        goto next_5;
    }
    if (reg_d1.h[0] != 2) {
        goto next_7;
    }
next_5:
    if (!(reg_d0.w & 4)) {
        goto next_6;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    func_0019A870();
    return;
next_6:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
    func_0019A870();
    return;
next_7:
    if (reg_d1.h[0] == 4) {
        goto next_8;
    }
    if (reg_d1.h[0] == 8) {
        goto next_8;
    }
block_rts:
    return;
next_8:
    if (!(reg_d0.w & 1)) {
        goto next_9;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 1;
    func_0019A870();
    return;
next_9:
    if (!(reg_d0.w & 2)) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 2;
    func_0019A870();
}
