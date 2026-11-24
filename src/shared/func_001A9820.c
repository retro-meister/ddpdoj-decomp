#include "common.h"

void func_001ABF90(void);
extern u16 D_0026B898[];
extern u16 D_0026B8A8[];
extern u16 D_0026B8B8[];
extern u16 D_0028E5C0;
extern u16 D_0028E5E4;
extern u16 D_0028E5FC;
extern u16 D_0028E694;
extern u16 D_0028E6C8;
extern u16 D_0028E6DC;
extern u16 D_0028E910;
extern u16 D_0028E918;
extern u8 D_0028ED80;
extern u8 *reg_a0;

void func_001A9820(void) {
    u32 bits;
    u16 idx;
    u16 val;
    u32 add;

    bits = reg_d1.w & 4;
    reg_d0.h[0] = D_0028E694;
    if ((bits != 0) || (D_0028E910 == 0)) {
        D_0028E6C8 += reg_d0.h[0];
        reg_d0.h[0] = D_0028E6DC;
        if ((s32) D_0028E6C8 < (s32) reg_d0.h[0]) {
        block_rts:
            return;
        }
    }
    D_0028E6C8 = D_0028E6DC;
    if ((s16) reg_d1.h[0] < 0) {
        goto block_rts;
    }
    reg_a0 = (u8 *)D_0026B8A8;
    reg_d0.h[0] = D_0028E918;
    idx = reg_d0.h[0];
    reg_a0 += idx;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_d2.h[0] = D_0028E5C0;
    if (D_0028E5FC != 0) {
        reg_d0.h[0] = D_0028E918;
        reg_a0 = (u8 *)D_0026B8B8;
        reg_a0 += idx;
        reg_d0.h[0] = *(u16 *)reg_a0;
    } else {
        reg_d2.h[0] += reg_d2.h[0];
        reg_a0 = (u8 *)D_0026B898;
        switch (reg_d2.h[0]) {
        case 0:
            goto skip_1;
        }
        val = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1));
        goto next_1;
    skip_1:
        val = *(u16 *)reg_a0;
    next_1:
        reg_d0.h[0] += val;
    }
    if ((D_0028E5C0 != 5) && (bits == 0)) {
        reg_d0.h[0] += reg_d0.h[0];
    }
    if (D_0028ED80 != 0) {
        add = reg_d0.h[0];
        D_0028E5E4 += add;
    } else {
        D_0028E5E4 += reg_d0.h[0];
    }
    func_001ABF90();
}
